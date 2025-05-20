#include <ctype.h>
#include "esp_bt.h"
#include "esp_log.h"
#include <stdbool.h>
#include "nvs_flash.h"
#include "nimble/ble.h"
#include "host/ble_hs.h"
#include "host/util/util.h"
#include "nimble/nimble_port.h"
#include "services/gap/ble_svc_gap.h"
#include "services/gatt/ble_svc_gatt.h"
#include "nimble/nimble_port_freertos.h"

#define TAG "SERVER"
#define DEVICE_NAME "SERV_FUMOES"
#define CLIENT_ADDRESS "f0:f5:bd:01:7d:26"

#define BLE_SVC_UUID16 0xABF0     /* 16 Bit Service UUID */
#define BLE_SVC_CHR_UUID16 0xABF1 /* 16 Bit Service Characteristic UUID */

int gatt_svr_register(void);
static int ble_server_gap_event(struct ble_gap_event *event, void *arg);
static int ble_svc_gatt_handler(uint16_t conn_handle, uint16_t attr_handle, struct ble_gatt_access_ctxt *ctxt, void *arg);

static uint8_t own_addr_type;
static uint16_t ble_svc_gatt_read_val_handle;
static const struct ble_gatt_svc_def new_ble_svc_gatt_defs[] = {
    {
        /* The Service */
        .type = BLE_GATT_SVC_TYPE_PRIMARY,
        .uuid = BLE_UUID16_DECLARE(BLE_SVC_UUID16),
        .characteristics = (struct ble_gatt_chr_def[]){{
                                                           /* The characteristic */
                                                           .uuid = BLE_UUID16_DECLARE(BLE_SVC_CHR_UUID16),
                                                           .access_cb = ble_svc_gatt_handler,
                                                           .val_handle = &ble_svc_gatt_read_val_handle,
                                                           .flags = BLE_GATT_CHR_F_READ | BLE_GATT_CHR_F_WRITE | BLE_GATT_CHR_F_NOTIFY,
                                                       },
                                                       {
                                                           0, /* No more characteristics */
                                                       }},
    },
    {
        0, /* No more services. */
    },
};

// Logs information about a connection to the console.
static void ble_server_print_conn_desc(struct ble_gap_conn_desc *desc)
{
    char addr[18];

    sprintf(addr, "%02x:%02x:%02x:%02x:%02x:%02x", desc->our_ota_addr.val[5], desc->our_ota_addr.val[4],
            desc->our_ota_addr.val[3], desc->our_ota_addr.val[2], desc->our_ota_addr.val[1], desc->our_ota_addr.val[0]);
    ESP_LOGI(TAG, "handle=%d our_ota_addr_type=%d our_ota_addr=%s", desc->conn_handle, desc->our_ota_addr.type, addr);

    sprintf(addr, "%02x:%02x:%02x:%02x:%02x:%02x", desc->our_id_addr.val[5], desc->our_id_addr.val[4],
            desc->our_id_addr.val[3], desc->our_id_addr.val[2], desc->our_id_addr.val[1], desc->our_id_addr.val[0]);
    ESP_LOGI(TAG, " our_id_addr_type=%d our_id_addr=%s", desc->our_id_addr.type, addr);

    sprintf(addr, "%02x:%02x:%02x:%02x:%02x:%02x", desc->peer_ota_addr.val[5], desc->peer_ota_addr.val[4],
            desc->peer_ota_addr.val[3], desc->peer_ota_addr.val[2], desc->peer_ota_addr.val[1], desc->peer_ota_addr.val[0]);
    ESP_LOGI(TAG, " peer_ota_addr_type=%d peer_ota_addr=%s", desc->peer_ota_addr.type, addr);

    sprintf(addr, "%02x:%02x:%02x:%02x:%02x:%02x", desc->peer_id_addr.val[5], desc->peer_id_addr.val[4],
            desc->peer_id_addr.val[3], desc->peer_id_addr.val[2], desc->peer_id_addr.val[1], desc->peer_id_addr.val[0]);
    ESP_LOGI(TAG, " peer_id_addr_type=%d peer_id_addr=%s", desc->peer_id_addr.type, addr);

    ESP_LOGI(TAG, " conn_itvl=%d conn_latency=%d supervision_timeout=%d encrypted=%d authenticated=%d bonded=%d\n",
             desc->conn_itvl, desc->conn_latency, desc->supervision_timeout, desc->sec_state.encrypted,
             desc->sec_state.authenticated, desc->sec_state.bonded);
}

static void ble_server_advertise(void)
{
    struct ble_hs_adv_fields fields = {0};
    const char *name = ble_svc_gap_device_name();

    // General discoverability and BLE-only (BR/EDR unsupported)
    fields.flags = BLE_HS_ADV_F_DISC_GEN | BLE_HS_ADV_F_BREDR_UNSUP;

    /* Set device name */
    fields.name = (uint8_t *)name;
    fields.name_len = strlen(name);
    fields.name_is_complete = 1;

    /* Set device tx power */
    fields.tx_pwr_lvl = BLE_HS_ADV_TX_PWR_LVL_AUTO;
    fields.tx_pwr_lvl_is_present = 1;

    /* 16-bit service UUIDs (alert notifications) */
    fields.uuids16 = (ble_uuid16_t[]){BLE_UUID16_INIT(BLE_SVC_UUID16)};
    fields.uuids16_is_complete = 1;
    fields.num_uuids16 = 1;

    /* Set device LE role */
    fields.le_role = BLE_GAP_ROLE_MASTER;
    fields.le_role_is_present = 1;

    int status = ble_gap_adv_set_fields(&fields);
    if (status == 0)
    {
        struct ble_gap_adv_params adv_params = {0};

        /* Set connetable and general discoverable mode */
        adv_params.conn_mode = BLE_GAP_CONN_MODE_UND;
        adv_params.disc_mode = BLE_GAP_DISC_MODE_GEN;
        adv_params.filter_policy = BLE_HCI_ADV_FILT_BOTH;

        /* Start advertising */
        status = ble_gap_adv_start(own_addr_type, NULL, BLE_HS_FOREVER, &adv_params, ble_server_gap_event, NULL);
        if (status == 0)
        {
            ESP_LOGI(TAG, "Advertising started!");
        }
        else
        {
            ESP_LOGE(TAG, "Failed to start advertising, error code: %d", status);
        }
    }
    else
    {
        ESP_LOGE(TAG, "Error setting advertisement data; status = %d\n", status);
    }
}

static int ble_server_gap_event(struct ble_gap_event *event, void *)
{
    struct ble_gap_conn_desc desc;

    switch (event->type)
    {
    case BLE_GAP_EVENT_CONNECT: /* A new connection was established or a connection attempt failed. */
        ESP_LOGI(TAG, "connection %s; status=%d ", event->connect.status == 0 ? "established" : "failed", event->connect.status);
        if (event->connect.status == 0)
        {
            assert(0 == ble_gap_conn_find(event->connect.conn_handle, &desc));
            ble_server_print_conn_desc(&desc);
        }
        else
        {
            /* Connection failed; resume advertising. */
            ble_server_advertise();
        }
        break;

    case BLE_GAP_EVENT_DISCONNECT:
        ESP_LOGI(TAG, "disconnect; reason=%d ", event->disconnect.reason);
        ble_server_print_conn_desc(&event->disconnect.conn);
        ble_server_advertise(); /* Connection terminated; resume advertising. */
        break;

    case BLE_GAP_EVENT_CONN_UPDATE: /* The central has updated the connection parameters. */
        ESP_LOGI(TAG, "connection updated; status=%d ", event->conn_update.status);
        assert(0 == ble_gap_conn_find(event->conn_update.conn_handle, &desc));
        ble_server_print_conn_desc(&desc);
        break;

    case BLE_GAP_EVENT_ADV_COMPLETE:
        ESP_LOGI(TAG, "advertise complete; reason=%d", event->adv_complete.reason);
        ble_server_advertise();
        break;

    case BLE_GAP_EVENT_MTU:
        /* Maximum Transmission Unit defines the maximum size of a single ATT (Attribute Protocol) payload,
         i.e., how much data can be sent in a single BLE GATT read/write/notify/indication operation. */
        ESP_LOGI(TAG, "MTU update event; conn_handle=%d cid=%d mtu=%d\n",
                 event->mtu.conn_handle, event->mtu.channel_id, event->mtu.value);
        break;

    case BLE_GAP_EVENT_SUBSCRIBE:
        ESP_LOGI(TAG, "subscribe event; conn_handle=%d attr_handle=%d  reason=%d prevn=%d curn=%d previ=%d curi=%d\n",
                 event->subscribe.conn_handle, event->subscribe.attr_handle, event->subscribe.reason, event->subscribe.prev_notify,
                 event->subscribe.cur_notify, event->subscribe.prev_indicate, event->subscribe.cur_indicate);
        break;

    default:
        break;
    }

    return 0;
}

static void ble_server_on_reset(int reason)
{
    ESP_LOGE(TAG, "Resetting state; reason=%d\n", reason);
}

static void ble_server_on_sync(void)
{
    assert(0 == ble_hs_util_ensure_addr(0));

    /* Figure out address to use while advertising */
    int status = ble_hs_id_infer_auto(0, &own_addr_type);
    if (status == 0)
    {
        /* Printing ADDR */
        uint8_t addr_val[6] = {0};
        assert(0 == ble_hs_id_copy_addr(own_addr_type, addr_val, NULL));

    vTaskDelay(pdMS_TO_TICKS(500));
        

        printf("BLE Device Address: %02x:%02x:%02x:%02x:%02x:%02x\n",
               addr_val[5], addr_val[4], addr_val[3], addr_val[2], addr_val[1], addr_val[0]);

        ble_addr_t client = {.type = BLE_ADDR_PUBLIC};
        sscanf(CLIENT_ADDRESS, "%hhx:%hhx:%hhx:%hhx:%hhx:%hhx",
               &addr_val[5], &addr_val[4], &addr_val[3],
               &addr_val[2], &addr_val[1], &addr_val[0]);
        memcpy(&client.val, addr_val, sizeof(client.val));

        assert(0 == ble_gap_wl_set(&client, 1));

        /* Begin advertising. */
        ble_server_advertise();
    }
    else
    {
        ESP_LOGE(TAG, "Error determining address type; status = %d\n", status);
    }
}

/* Callback function for custom service */
static int ble_svc_gatt_handler(uint16_t conn_handle, uint16_t attr_handle, struct ble_gatt_access_ctxt *ctxt, void *)
{
    switch (ctxt->op)
    {
    case BLE_GATT_ACCESS_OP_READ_CHR:
        ESP_LOGI(TAG, "Callback for read");
        break;

    case BLE_GATT_ACCESS_OP_WRITE_CHR:
    {
        ESP_LOGI(TAG, "Data received in write event, conn_handle = %x, attr_handle = %x", conn_handle, attr_handle);

        char buffer[OS_MBUF_PKTLEN(ctxt->om)];
        memset(buffer, 0, sizeof(buffer));

        // Attribute data is contained in ctxt.om.
        assert(0 == os_mbuf_copydata(ctxt->om, 0, sizeof(buffer), buffer));
        strncpy(buffer, "greatfumo", sizeof(buffer));
        // for (int i = 0; i < sizeof(buffer); i++)
        // {
        //     buffer[i] = toupper(buffer[i]);
        // }

        struct os_mbuf *txom = ble_hs_mbuf_from_flat(buffer, sizeof(buffer));
        if (0 == ble_gatts_notify_custom(conn_handle, ble_svc_gatt_read_val_handle, txom))
        {
            ESP_LOGI(TAG, "Notification sent successfully");
        }
        else
        {
            ESP_LOGE(TAG, "Error in sending notification");
        }
    }
    break;

    default:
        ESP_LOGI(TAG, "\nDefault Callback");
        break;
    }

    return 0;
}

static void gatt_svr_register_cb(struct ble_gatt_register_ctxt *ctxt, void *)
{
    char buf[BLE_UUID_STR_LEN] = {0};

    switch (ctxt->op)
    {
    case BLE_GATT_REGISTER_OP_SVC:
        ESP_LOGI(TAG, "registered service %s with handle=%d\n", ble_uuid_to_str(ctxt->svc.svc_def->uuid, buf), ctxt->svc.handle);
        break;

    case BLE_GATT_REGISTER_OP_CHR:
        ESP_LOGI(TAG, "registering characteristic %s with def_handle=%d val_handle=%d\n",
                 ble_uuid_to_str(ctxt->chr.chr_def->uuid, buf), ctxt->chr.def_handle, ctxt->chr.val_handle);
        break;

    case BLE_GATT_REGISTER_OP_DSC:
        ESP_LOGI(TAG, "registering descriptor %s with handle=%d\n", ble_uuid_to_str(ctxt->dsc.dsc_def->uuid, buf), ctxt->dsc.handle);
        break;

    default:
        assert(0);
        break;
    }
}

int gatt_svr_init(void)
{
    ble_svc_gap_init();
    ble_svc_gatt_init();

    int status = ble_gatts_count_cfg(new_ble_svc_gatt_defs);
    if (status == 0)
    {
        status = ble_gatts_add_svcs(new_ble_svc_gatt_defs);
    }

    return status;
}

void app_main(void)
{
    esp_err_t status = nvs_flash_init();
    if (status == ESP_ERR_NVS_NO_FREE_PAGES || status == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        status = nvs_flash_init();
    }
    ESP_ERROR_CHECK(status);

    ESP_ERROR_CHECK(nimble_port_init());
    ESP_ERROR_CHECK(esp_ble_tx_power_set(ESP_BLE_PWR_TYPE_ADV, ESP_PWR_LVL_P20));

    /* Initialize the NimBLE host configuration. */
    ble_hs_cfg.reset_cb = ble_server_on_reset;
    ble_hs_cfg.sync_cb = ble_server_on_sync;
    ble_hs_cfg.gatts_register_cb = gatt_svr_register_cb;
    ble_hs_cfg.store_status_cb = ble_store_util_status_rr;

    /* Register custom service */
    assert(0 == gatt_svr_init());

    /* Set the default device name. */
    assert(0 == ble_svc_gap_device_name_set(DEVICE_NAME));

    ESP_LOGI(TAG, "BLE Host Task Started");
    nimble_port_run(); /* This function will return only when nimble_port_stop() is executed */
    nimble_port_freertos_deinit();
}