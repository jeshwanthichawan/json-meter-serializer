#ifndef JSON_SERIALIZER_H
#define JSON_SERIALIZER_H

#include <stddef.h>
#include <stdint.h>

#define MAX_DEVICES        4
#define MAX_DATA_POINTS    8
#define MAX_STR_LEN        32


typedef enum {
    JSON_OK = 0,
    JSON_ERR_BUFFER_TOO_SMALL,
    JSON_ERR_INVALID_INPUT
} json_status_t;


typedef struct {
    char timestamp[17];       
    char meter_datetime[17];   
    double total_value;
    char status[8];           
} meter_data_t;

typedef struct {
    char media[MAX_STR_LEN];
    char meter[MAX_STR_LEN];
    char device_id[MAX_STR_LEN];
    char unit[MAX_STR_LEN];
    uint8_t data_count;
    meter_data_t data[MAX_DATA_POINTS];
} device_reading_t;

typedef struct {
    char gateway_id[MAX_STR_LEN];
    char date[11];             
    char device_type[MAX_STR_LEN];
    uint16_t interval_minutes;
    uint16_t total_readings;
    uint8_t device_count;
    device_reading_t devices[MAX_DEVICES];
} gateway_data_t;


json_status_t serialize_to_json(
    const gateway_data_t *input,
    char *output,
    size_t output_size,
    size_t *bytes_written
);

#endif

