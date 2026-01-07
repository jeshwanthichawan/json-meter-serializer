#include <stdio.h>
#include "json_serializer.h"

int main(void) {
    gateway_data_t data = {0};

    snprintf(data.gateway_id, MAX_STR_LEN, "gateway_1234");
    snprintf(data.date, 11, "1970-01-01");
    snprintf(data.device_type, MAX_STR_LEN, "stromleser");
    data.interval_minutes = 15;
    data.total_readings = 1;
    data.device_count = 1;

    device_reading_t *dev = &data.devices[0];
    snprintf(dev->media, MAX_STR_LEN, "water");
    snprintf(dev->meter, MAX_STR_LEN, "waterstarm");
    snprintf(dev->device_id, MAX_STR_LEN, "stromleser_50898527");
    snprintf(dev->unit, MAX_STR_LEN, "m3");
    dev->data_count = 1;

    meter_data_t *m = &dev->data[0];
    snprintf(m->timestamp, 17, "1970-01-01 00:00");
    snprintf(m->meter_datetime, 17, "1970-01-01 00:00");
    m->total_value = 107.752;
    snprintf(m->status, 8, "OK");

    char json_buffer[512];
    size_t written;

    if (serialize_to_json(&data, json_buffer, sizeof(json_buffer), &written) == JSON_OK) {
        printf("%s\n", json_buffer);
    } else {
        printf("Serialization failed\n");
    }

    return 0;
}

