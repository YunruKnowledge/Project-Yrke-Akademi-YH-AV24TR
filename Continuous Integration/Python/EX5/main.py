message = {

    "id":"0x100",

    "signals":[

        {"name":"temperature",                   "type":"float",    "length":10, "comment":"the ambient temperature"},

        {"name":"humidity",                      "type":"uint8_t",  "length":7,  "comment":"the ambient humidity percentage"},

        {"name":"dht_sensor_status",             "type":"uint8_t",  "length":2,  "comment":"the dht sensor status"},

        {"name":"flow_rate",                     "type":"uint16_t", "length":9,  "comment":"the flow rate in milliliter per second"},

        {"name":"flow_meter_sensor_status",      "type":"uint8_t",  "length":2,  "comment":"the flow meter sensor status"},

        {"name":"light_intensity",               "type":"uint8_t",  "length":7,  "comment":"the light intensity percentage"},

        {"name":"light_intensity_sensor_status", "type":"uint8_t",  "length":2,  "comment":"the light intensity sensor status"},

        {"name":"water_level",                   "type":"uint8_t",  "length":7,  "comment":"the water level percentage"},

        {"name":"water_level_sensor_status",     "type":"uint8_t",  "length":2,  "comment":"the water level sensor status"},

        {"name":"soil_moisture",                 "type":"uint8_t",  "length":7,  "comment":"the soil moisture percentage"},

        {"name":"soil_moisture_sensor_status",   "type":"uint8_t",  "length":2,  "comment":"the soil moisture sensor status"}

    ]

}

name_longest = max(message["signals"], key=lambda x: len(x["name"]))["name"]
type_longest = max(message["signals"], key=lambda x: len(x["type"]))["type"]
length_longest = max(message["signals"], key=lambda x: len(str(x["length"])))["length"]
comment_longest = max(message["signals"], key=lambda x: len(x["comment"]))["comment"]

name_count = len(name_longest)
type_count = len(type_longest)
length_count = len(str(length_longest))  
comment_count = len(comment_longest)


print(f"{'Signal':<{name_count}} | {'Type':<{type_count}} | {'Length':<{length_count + len('length')}} | {'Description':<{comment_count}}")
print((name_count + type_count + length_count + comment_count + 30) * "-")
for signal in message["signals"]:
    print(f"{signal['name']:<{name_count}} | {signal['type']:<{type_count}} | {signal['length']:<{length_count + (len('Length'))}} | {signal['comment']:<{comment_count}}")
