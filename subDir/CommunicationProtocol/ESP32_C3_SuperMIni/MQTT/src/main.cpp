
#include <driver/temperature_sensor.h>
#include <mqtt_client.h>
#include <driver/gpio.h>
#include <esp_system.h>
#include <esp_event.h>
#include <nvs_flash.h>
#include <esp_netif.h>
#include <esp_wifi.h>
#include <esp_log.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

static const char *WIFI_SSID{"YA-OPEN"};
static const char *WIFI_PASS{"REDACTED"};

static uint32_t MQTT_PORT{8883};
static esp_mqtt_client_handle_t client;
static const char *MQTT_CLIENTID{"SuperMini2"};
static const char *MQTT_USERNAME{"fumo_numer2"};
static const char *MQTT_PASSWORD{"NotEuallylong333"};
static const char *MQTT_SERVER{"REDEACTED"};
static const char *TOPIC_LED{"actuator/led"};
static const char *TOPIC_TEMP{"sensor/temp"};
static const char *TAG{"mqtt_client"};
static volatile bool connected{false};
static const char *cert = R"EOF(
-----BEGIN CERTIFICATE-----
MIIFazCCA1OgAwIBAgIRAIIQz7DSQONZRGPgu2OCiwAwDQYJKoZIhvcNAQELBQAw
TzELMAkGA1UEBhMCVVMxKTAnBgNVBAoTIEludGVybmV0IFNlY3VyaXR5IFJlc2Vh
cmNoIEdyb3VwMRUwEwYDVQQDEwxJU1JHIFJvb3QgWDEwHhcNMTUwNjA0MTEwNDM4
WhcNMzUwNjA0MTEwNDM4WjBPMQswCQYDVQQGEwJVUzEpMCcGA1UEChMgSW50ZXJu
ZXQgU2VjdXJpdHkgUmVzZWFyY2ggR3JvdXAxFTATBgNVBAMTDElTUkcgUm9vdCBY
MTCCAiIwDQYJKoZIhvcNAQEBBQADggIPADCCAgoCggIBAK3oJHP0FDfzm54rVygc
h77ct984kIxuPOZXoHj3dcKi/vVqbvYATyjb3miGbESTtrFj/RQSa78f0uoxmyF+
0TM8ukj13Xnfs7j/EvEhmkvBioZxaUpmZmyPfjxwv60pIgbz5MDmgK7iS4+3mX6U
A5/TR5d8mUgjU+g4rk8Kb4Mu0UlXjIB0ttov0DiNewNwIRt18jA8+o+u3dpjq+sW
T8KOEUt+zwvo/7V3LvSye0rgTBIlDHCNAymg4VMk7BPZ7hm/ELNKjD+Jo2FR3qyH
B5T0Y3HsLuJvW5iB4YlcNHlsdu87kGJ55tukmi8mxdAQ4Q7e2RCOFvu396j3x+UC
B5iPNgiV5+I3lg02dZ77DnKxHZu8A/lJBdiB3QW0KtZB6awBdpUKD9jf1b0SHzUv
KBds0pjBqAlkd25HN7rOrFleaJ1/ctaJxQZBKT5ZPt0m9STJEadao0xAH0ahmbWn
OlFuhjuefXKnEgV4We0+UXgVCwOPjdAvBbI+e0ocS3MFEvzG6uBQE3xDk3SzynTn
jh8BCNAw1FtxNrQHusEwMFxIt4I7mKZ9YIqioymCzLq9gwQbooMDQaHWBfEbwrbw
qHyGO0aoSCqI3Haadr8faqU9GY/rOPNk3sgrDQoo//fb4hVC1CLQJ13hef4Y53CI
rU7m2Ys6xt0nUW7/vGT1M0NPAgMBAAGjQjBAMA4GA1UdDwEB/wQEAwIBBjAPBgNV
HRMBAf8EBTADAQH/MB0GA1UdDgQWBBR5tFnme7bl5AFzgAiIyBpY9umbbjANBgkq
hkiG9w0BAQsFAAOCAgEAVR9YqbyyqFDQDLHYGmkgJykIrGF1XIpu+ILlaS/V9lZL
ubhzEFnTIZd+50xx+7LSYK05qAvqFyFWhfFQDlnrzuBZ6brJFe+GnY+EgPbk6ZGQ
3BebYhtF8GaV0nxvwuo77x/Py9auJ/GpsMiu/X1+mvoiBOv/2X/qkSsisRcOj/KK
NFtY2PwByVS5uCbMiogziUwthDyC3+6WVwW6LLv3xLfHTjuCvjHIInNzktHCgKQ5
ORAzI4JMPJ+GslWYHb4phowim57iaztXOoJwTdwJx4nLCgdNbOhdjsnvzqvHu7Ur
TkXWStAmzOVyyghqpZXjFaH3pO3JLF+l+/+sKAIuvtd7u+Nxe5AW0wdeRlN8NwdC
jNPElpzVmbUq4JUagEiuTDkHzsxHpFKVK7q4+63SM1N95R1NbdWhscdCb+ZAJzVc
oyi3B43njTOQ5yOf+1CceWxG1bQVs5ZufpsMljq4Ui0/1lvh+wjChP4kqKOJ2qxq
4RgqsahDYVvTH9w7jXbyLeiNdd8XM2w9U/t7y0Ff/9yi0GE44Za4rF2LN9d11TPA
mRGunUHBcnWEvgJBQl9nJEiU0Zsnvgc/ubhPgXRR4Xq37Z0j4r7g1SgEEzwxA57d
emyPxgcYxn/eR44/KJ4EBs+lVDR3veyJm+kXQ99b21/+jh5Xos1AnX5iItreGCc=
-----END CERTIFICATE-----
)EOF";

static void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data);

static void event_handler(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data)
{
    if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START)
    {
        esp_wifi_connect();
    }
    else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED)
    {
        ESP_LOGI(TAG, "Retrying to connect to the AP");
        esp_wifi_connect();
    }
    else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP)
    {
        ip_event_got_ip_t *event = (ip_event_got_ip_t *)event_data;
        ESP_LOGI(TAG, "got ip:" IPSTR, IP2STR(&event->ip_info.ip));

        esp_mqtt_client_config_t config;
        memset(&config, 0, sizeof(config));
        config.broker.address.port = MQTT_PORT;
        config.broker.address.uri = MQTT_SERVER;
        config.broker.verification.certificate = (const char *)cert;
        config.credentials.authentication.password = MQTT_PASSWORD;
        config.credentials.client_id = MQTT_CLIENTID;
        config.credentials.username = MQTT_USERNAME;

        client = esp_mqtt_client_init(&config);
        ESP_ERROR_CHECK(esp_mqtt_client_register_event(client, (esp_mqtt_event_id_t)ESP_EVENT_ANY_ID, mqtt_event_handler, NULL));
        ESP_ERROR_CHECK(esp_mqtt_client_start(client));
    }
    else
    {
        ;
    }
}

static void wifi_init(void)
{
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    assert(NULL != esp_netif_create_default_wifi_sta());

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &event_handler, NULL, NULL));
    ESP_ERROR_CHECK(esp_event_handler_instance_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &event_handler, NULL, NULL));

    wifi_config_t config;
    memset(&config, 0, sizeof(config));
    strcpy((char *)config.sta.ssid, WIFI_SSID);
    strcpy((char *)config.sta.password, WIFI_PASS);

    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_set_config((wifi_interface_t)ESP_IF_WIFI_STA, &config));
    ESP_ERROR_CHECK(esp_wifi_start());

    ESP_LOGI(TAG, "wifi_init finished.");
}

static void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data)
{
    ESP_LOGD(TAG, "Event dispatched from event loop base=%s, event_id=%ld", base, event_id);
    esp_mqtt_event_handle_t event = (esp_mqtt_event_handle_t)event_data;
    int msg_id;

    switch ((esp_mqtt_event_id_t)event_id)
    {
    case MQTT_EVENT_CONNECTED:
        ESP_LOGI(TAG, "MQTT_EVENT_CONNECTED");
        connected = true;

        msg_id = esp_mqtt_client_subscribe_single(client, TOPIC_LED, 0);
        ESP_LOGI(TAG, "sent subscribe successful, msg_id=%d", msg_id);
        break;

    case MQTT_EVENT_DISCONNECTED:
        ESP_LOGI(TAG, "MQTT_EVENT_DISCONNECTED");
        connected = false;
        break;

    case MQTT_EVENT_SUBSCRIBED:
        ESP_LOGI(TAG, "MQTT_EVENT_SUBSCRIBED, msg_id=%d", event->msg_id);
        break;

    case MQTT_EVENT_PUBLISHED:
        ESP_LOGI(TAG, "MQTT_EVENT_PUBLISHED, msg_id=%d", event->msg_id);
        break;

    case MQTT_EVENT_DATA:
        ESP_LOGI(TAG, "MQTT_EVENT_DATA");
        printf("TOPIC=%.*s\r\n", event->topic_len, event->topic);
        printf("DATA=%.*s\r\n", event->data_len, event->data);
        if (0 == strncmp(event->topic, TOPIC_LED, event->topic_len))
        {
            event->data[event->data_len] = 0;
            if (0 == strcmp("on", event->data))
            {
                ESP_ERROR_CHECK(gpio_set_level(GPIO_NUM_4, 1));
            }
            else if (0 == strcmp("off", event->data))
            {
                ESP_ERROR_CHECK(gpio_set_level(GPIO_NUM_4, 0));
            }
            else
            {
                printf("Invalid LED state\r\n");
            }
        }
        break;

    case MQTT_EVENT_ERROR:
        ESP_LOGI(TAG, "MQTT_EVENT_ERROR");
        break;

    default:
        ESP_LOGI(TAG, "Other event id:%d", event->event_id);
        break;
    }
}

extern "C" void app_main(void)
{
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    ESP_LOGI(TAG, "ESP_IDF Version: %s", esp_get_idf_version());

    wifi_init();

    ESP_ERROR_CHECK(gpio_reset_pin(GPIO_NUM_4));
    ESP_ERROR_CHECK(gpio_set_direction(GPIO_NUM_4, GPIO_MODE_OUTPUT)); // Configure pin 4 as a digital output pin

    temperature_sensor_handle_t handle = NULL;
    temperature_sensor_config_t config;
    memset(&config, 0, sizeof(config));
    config.clk_src = TEMPERATURE_SENSOR_CLK_SRC_DEFAULT;
    config.range_min = 10;
    config.range_max = 50;

    ESP_ERROR_CHECK(temperature_sensor_install(&config, &handle));

    float temperature;
    char temp[16] = {0};

    while (1)
    {
        if (connected)
        {
            ESP_ERROR_CHECK(temperature_sensor_enable(handle)); // Enable temperature sensor

            ESP_ERROR_CHECK(temperature_sensor_get_celsius(handle, &temperature)); // Get converted sensor data

            ESP_ERROR_CHECK(temperature_sensor_disable(handle)); // Disable the temperature sensor to save power

            sprintf(temp, "%.02f °C\n", temperature);

            assert(0 <= esp_mqtt_client_publish(client, TOPIC_TEMP, temp, 0, 1, 0));
        }

        sleep(5);
    }
}
