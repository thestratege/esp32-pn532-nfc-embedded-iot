# Architecture Notes

## Design Intent

The project separates hardware interaction, device state, event handling and communication so that each part can be tested or replaced independently.

## Layers

```text
Hardware layer
  PN532 reader, LEDs, optional buttons

Driver layer
  NFC reader wrapper, LED/status wrapper

Core layer
  event validation, duplicate handling, device state, retry queue

Connectivity layer
  Wi-Fi state, REST client, WebSocket-style stream

Diagnostics layer
  serial logs, status LED, error codes
```

## Reliability Questions

- What happens when the same tag is scanned repeatedly?
- What happens when Wi-Fi disappears after a valid scan?
- How many events can be queued before memory becomes a concern?
- How does the user know whether the device is ready, offline or failing?
- Which errors should be retried, ignored or surfaced?
