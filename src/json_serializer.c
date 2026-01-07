#include "json_serializer.h"
#include <stdio.h>

#define APPEND(...) do { \
    int n = snprintf(output + used, output_size - used, __VA_ARGS__); \
    if (n < 0 || (size_t)n >= output_size - used) return JSON_ERR_BUFFER_TOO_SMALL; \
    used += (size_t)n; \
} while (0)

json_status_t serialize_to_json(
    const gateway_data_t *input,
    char *output,
    size_t output_size,
    size_t *bytes_written
) {
    if (!input || !output || output_size == 0)
        return JSON_ERR_INVALID_INPUT;

    size_t used = 0;

    APPEND("[{");
    APPEND("\"gatewayId\":\"%s\",", input->gateway_id);
    APPEND("\"date\":\"%s\",", input->date);
    APPEND("\"deviceType\":\"%s\",", input->device_type);
    APPEND("\"interval_minutes\":%u,", input->interval_minutes);
    APPEND("\"total_readings\":%u,", input->total_readings);

    APPEND("\"values\":{");
    APPEND("\"device_count\":%u,", input->device_count);
    APPEND("\"readings\":[");

    for (uint8_t i = 0; i < input->device_count; i++) {
        const device_reading_t *d = &input->devices[i];
        APPEND("{");
        APPEND("\"media\":\"%s\",", d->media);
        APPEND("\"meter\":\"%s\",", d->meter);
        APPEND("\"deviceId\":\"%s\",", d->device_id);
        APPEND("\"unit\":\"%s\",", d->unit);
        APPEND("\"data\":[");

        for (uint8_t j = 0; j < d->data_count; j++) {
            const meter_data_t *m = &d->data[j];
            APPEND("{");
            APPEND("\"timestamp\":\"%s\",", m->timestamp);
            APPEND("\"meter_datetime\":\"%s\",", m->meter_datetime);
            APPEND("\"total_m3\":%.3f,", m->total_value);
            APPEND("\"status\":\"%s\"", m->status);
            APPEND("}");
            if (j + 1 < d->data_count) APPEND(",");
        }

        APPEND("]}");
        if (i + 1 < input->device_count) APPEND(",");
    }

    APPEND("]}}]");
    
    if (bytes_written)
        *bytes_written = used;

    return JSON_OK;
}

