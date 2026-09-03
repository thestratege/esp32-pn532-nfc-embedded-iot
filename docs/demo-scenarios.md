# Demo Scenarios

## Scenario 1 - Normal Scan

The device is online, a demo NFC tag is detected, and the event is sent to the backend.

Expected behavior:

- Tag is read once.
- JSON payload is generated.
- Serial log shows event status.
- LED returns to ready state.

## Scenario 2 - Offline Scan

The network is unavailable when a tag is scanned.

Expected behavior:

- Event is accepted locally.
- Payload is added to the retry queue.
- LED shows offline or retrying state.
- Firmware does not freeze while waiting for the network.

## Scenario 3 - Duplicate Scan

The same tag is scanned several times in a short interval.

Expected behavior:

- Duplicate events are ignored or grouped.
- Serial log explains why the repeated scan was not sent.
- Device remains responsive.

## Scenario 4 - Recovery

The network comes back after offline events were queued.

Expected behavior:

- Queued events are retried.
- Retry count is tracked.
- Successful events are removed from the queue.
- Remaining failures are logged with useful diagnostics.
