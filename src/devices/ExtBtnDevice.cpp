#include <utility>
#include <string>

#include "devices/ExtBtnDevice.h"
#include "core/OutputDevice.h"
#include "constants/DeviceTypes.h"

ExtBtnDevice::ExtBtnDevice(string name, int pin, OutputDevice &device) : Device(move(name), pin),outDevice(device){
    type = DeviceType::ExtBtn;
}

ExtBtnDevice::~ExtBtnDevice() {}

void ExtBtnDevice::init() {
    previous = digitalRead(getPin());
}

void ExtBtnDevice::execute() {
    bool extBtn = digitalRead(getPin());
    current = extBtn;

    if (extBtn != previous) {
        outDevice.changeState();
        previous = extBtn;
    }
}

