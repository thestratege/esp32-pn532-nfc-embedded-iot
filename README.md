# ESP32 + PN532 NFC Embedded/IoT System

Portfolio project by Gaetan Mpessa  
Target roles: embedded software intern, firmware intern, IoT developer intern

## Overview

This project explores how an ESP32 microcontroller and a PN532 NFC module can connect physical NFC interactions to a reliable software workflow.

The objective is not only to detect a tag. The objective is to design a small embedded/IoT system that handles timing, connectivity, local state, event serialization, retries and diagnostics with the discipline expected from field-oriented software.

```text
NFC tag detected
    -> firmware validates the event
    -> device updates local status
    -> event is serialized as JSON
    -> backend receives the event when connectivity is available
    -> offline events are queued and retried
    -> status feedback is exposed through LEDs and serial logs
```

## Why This Project Exists

Many IoT demonstrations work only in ideal conditions: stable network, clean input, immediate backend response and no repeated user actions.

Real embedded systems have to behave properly when conditions are imperfect. This project focuses on those reliability questions: weak Wi-Fi, duplicated scans, offline behavior, bounded retries, useful logs, limited memory and visible device status.

## Planned Features

- PN532 NFC tag detection from an ESP32.
- Event validation and duplicate-scan handling.
- Device states: booting, ready, scanning, sending, offline, retrying and error.
- JSON payload generation.
- REST endpoint integration for event upload.
- WebSocket-style event streaming for a dashboard.
- Offline event queue with retry logic.
- LED and serial-log diagnostics.
- Public demo data only, with no real credentials or private tag identifiers.

## Architecture

```text
+------------------+       +----------------------+
| NFC Tag / Card   | ----> | PN532 NFC Reader     |
+------------------+       +----------+-----------+
                                      |
                                      v
                           +----------+-----------+
                           | ESP32 Firmware       |
                           | - NFC reader layer   |
                           | - event validation   |
                           | - device state       |
                           | - retry queue        |
                           | - status feedback    |
                           +----------+-----------+
                                      |
                           Wi-Fi / Bluetooth
                                      |
                                      v
                           +----------+-----------+
                           | Backend / Dashboard  |
                           | - REST endpoint      |
                           | - WebSocket stream   |
                           | - event history      |
                           | - diagnostics        |
                           +----------------------+
```

## Repository Structure

```text
firmware/
  src/
    main.cpp
    nfc/
    connectivity/
    core/
  include/
  test/
docs/
  architecture.md
  demo-scenarios.md
```

## Example Event Payload

```json
{
  "deviceId": "esp32-nfc-demo-01",
  "eventType": "nfc_tag_detected",
  "tagIdHash": "demo-hash-only",
  "timestamp": "2026-09-03T12:00:00Z",
  "networkState": "online",
  "firmwareVersion": "0.1.0",
  "retryCount": 0
}
```

## Reliability Behaviors

- Debounce repeated scans.
- Avoid blocking loops during network failure.
- Queue events locally when the backend is unreachable.
- Retry failed transmissions with bounded logic.
- Keep device state observable through LEDs and serial logs.
- Separate hardware access, business logic and communication logic.

## Security and Privacy Notes

- Do not commit Wi-Fi credentials, API keys or production endpoints.
- Do not publish raw NFC identifiers.
- Use demo values for public screenshots, payloads and logs.
- Treat updates, configuration and vulnerability handling as part of the system design.

## Demo Scenarios

1. Device boots and enters ready state.
2. NFC tag is detected and converted into a structured event.
3. Online event is sent to a backend endpoint.
4. Network is unavailable and the event is queued locally.
5. Network returns and queued events are retried.
6. Duplicate scans are ignored or grouped.
7. Error state is displayed through logs and LED feedback.

## Technologies

- ESP32
- PN532 NFC module
- C/C++
- Wi-Fi and Bluetooth concepts
- JSON
- REST API concepts
- WebSocket concepts
- Offline queue and retry logic
- Embedded diagnostics

## Current Status

This repository is prepared as a portfolio-ready project skeleton. The next implementation step is to add the first firmware loop for PN532 detection, device status feedback and serial diagnostics.
