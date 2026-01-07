# Embedded JSON Serializer for Smart Meter Data

## Overview
This project implements a lightweight, embedded-friendly JSON serialization library
for smart-meter / w-M-Bus gateway data.

## Platform & Language
- Language: C (ANSI C)
- Platform: STM32 / generic embedded
Chosen for deterministic memory usage and firmware suitability.

## Features
- No dynamic memory allocation
- No external JSON libraries
- Caller-provided output buffer
- Strict buffer overflow protection
- Transport-agnostic

## Public API
```c
json_status_t serialize_to_json(
    const gateway_data_t *input,
    char *output,
    size_t output_size,
    size_t *bytes_written
);
