# Portfolio technical audit

Audit date: 2026-10-25. Source reviewed: `31931b97507deeea5ec5aa8e2f3f5c678fa674b0` on `main`.

## Current implementation

This repository is a design-stage embedded/IoT project. It currently contains architecture notes, planned demonstration scenarios and a C++ control-loop skeleton. It is not a completed ESP32/PN532 integration.

Evidence in `firmware/src/main.cpp`:

- `DeviceState` names booting, ready, scanning, sending, offline, retrying and error states.
- `NfcEvent` carries a demo tag hash, retry count and delivery flag.
- `readNfcTag` and `sendEvent` are stubs returning false.
- The offline queue is a TODO; no retry mechanism is implemented.

The README's NFC detection, duplicate handling, JSON serialization, network delivery, queueing, LEDs and serial diagnostics describe intended behavior. No driver, backend, build configuration or automated test appears in the reviewed tree.

## Verification

A host compiler syntax check passed:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic -fsyntax-only firmware/src/main.cpp
```

This verifies C++ syntax on the audit host only. No ESP32 build, flash operation, PN532 read, network request, timing measurement or hardware test was performed. No latency, uptime or reliability metric is established.

## Concrete next steps

1. Select and commit an ESP32 toolchain/build configuration and pin driver dependencies.
2. Replace the NFC stub with a PN532 driver and validate a fictional/demo tag.
3. Implement nonblocking event handling, duplicate suppression and a bounded queue.
4. Add explicit tests for queue capacity, retry limits and network recovery.
5. Record hardware wiring, firmware revision and reproducible test observations.

Use fictional tag identifiers and injected credentials. Keep real NFC identifiers and Wi-Fi/API credentials out of the repository.

## Résumé français

Projet de conception avec squelette C++, états explicites et scénarios de fiabilité documentés. La détection matérielle, la communication réseau, la file hors ligne et les essais sur ESP32 restent à réaliser. Le contrôle de syntaxe hôte réussi ne constitue pas une validation matérielle.
