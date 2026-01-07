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
