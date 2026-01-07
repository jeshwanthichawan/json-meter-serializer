# Embedded JSON Serializer for Smart Meter Data

## Overview
This project implements a lightweight, embedded-friendly JSON serialization library
for smart-meter / w-M-Bus gateway data. The library converts structured meter readings
into a predefined JSON format suitable for gateway-to-backend communication.

## Platform & Language
- **Language:** C (ANSI C)
- **Platform:** STM32 / Generic Embedded Systems  

C was chosen to ensure deterministic memory usage, high portability, and suitability
for resource-constrained embedded firmware environments.

## Features
- No dynamic memory allocation
- No external JSON libraries
- Caller-provided output buffer
- Strict buffer overflow protection
- Transport-agnostic core logic
- Clear and minimal public API

## Project Structure
/
├── include/
│   └── json_serializer.h
├── src/
│   └── json_serializer.c
├── examples/
│   └── example_main.c
└── README.md


## Public API
```c
json_status_t serialize_to_json(
    const gateway_data_t *input,
    char *output,
    size_t output_size,
    size_t *bytes_written
);


- input: Pointer to populated gateway data structure
- output: Caller-provided buffer for JSON output
- output_size: Size of the output buffer in bytes
- bytes_written: Number of bytes written to the output buffer

Build & Run Instructions

To build and run the example application on a desktop system:

gcc examples/example_main.c src/json_serializer.c -Iinclude -o demo
./demo

The generated JSON will be printed to the console or serial output.

Example JSON Output

[
  {
    "gatewayId":"gateway_1234",
    "date":"1970-01-01",
    "deviceType":"stromleser",
    "interval_minutes":15,
    "total_readings":1,
    "values":{
      "device_count":1,
      "readings":[
        {
          "media":"water",
          "meter":"waterstarm",
          "deviceId":"stromleser_50898527",
          "unit":"m3",
          "data":[
            {
              "timestamp":"1970-01-01 00:00",
              "meter_datetime":"1970-01-01 00:00",
              "total_m3":107.752,
              "status":"OK"
            }
          ]
        }
      ]
    }
  }
]

Design Decisions & Assumptions

- Fixed-size arrays are used to avoid dynamic memory allocation
- All memory is provided by the caller
- JSON is constructed manually using snprintf() to ensure safety
- The library does not include any transport or hardware-specific code
- Field names and structure strictly follow the assignment specification

Limits

- Maximum devices supported: 4
- Maximum data points per device: 8
- Recommended JSON output buffer size: 1024 bytes

Possible Extensions

- Streaming JSON generation for very large payloads
- Support for multiple gateways per payload
- Configurable floating-point precision
- Unit testing and CI integration
