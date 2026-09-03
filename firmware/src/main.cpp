#include <stdint.h>

// Portfolio skeleton only.
// Replace these stubs with ESP32, PN532 and networking libraries during implementation.

enum class DeviceState {
    Booting,
    Ready,
    Scanning,
    Sending,
    Offline,
    Retrying,
    Error
};

struct NfcEvent {
    const char* tagIdHash;
    uint32_t retryCount;
    bool sent;
};

static DeviceState state = DeviceState::Booting;

static bool readNfcTag(NfcEvent& event) {
    (void)event;
    return false;
}

static bool sendEvent(const NfcEvent& event) {
    (void)event;
    return false;
}

static void updateStatus(DeviceState nextState) {
    state = nextState;
}

int main() {
    updateStatus(DeviceState::Ready);

    while (true) {
        NfcEvent event = {"demo-hash-only", 0, false};

        updateStatus(DeviceState::Scanning);
        if (!readNfcTag(event)) {
            updateStatus(DeviceState::Ready);
            continue;
        }

        updateStatus(DeviceState::Sending);
        if (!sendEvent(event)) {
            updateStatus(DeviceState::Offline);
            // Next step: push event into a bounded retry queue.
        } else {
            updateStatus(DeviceState::Ready);
        }
    }

    return 0;
}
