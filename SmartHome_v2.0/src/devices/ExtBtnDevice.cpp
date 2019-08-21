#include "main.hpp"
#include "devices/ExtBtnDevice.h"
#include "devices/LightsDevice.h"


ExtBtnDevice::ExtBtnDevice(string name, int pin, int virtualPin, LightsDevice lights) : Device(name, pin, virtualPin) {
    ExtBtnDevice::init();
}

ExtBtnDevice::~ExtBtnDevice() {}

void ExtBtnDevice::init() {
    previous = digitalRead(getPin());
}

void ExtBtnDevice::execute() {
    bool extBtn = digitalRead(getPin());
    LightsDevice device = lights;
    previous = extBtn;

    if (extBtn != previous) {
        if (device.isTurnedOn()) {
            Blynk.virtualWrite(getVirtualPin(), 0);
            changeStateLed(0);
        } else {
            Blynk.virtualWrite(getVirtualPin(), 1);
            changeStateLed(1);
        }
        previous = extBtn;
    }
}
