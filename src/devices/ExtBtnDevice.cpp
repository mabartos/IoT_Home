#include <utility>


#include "devices/ExtBtnDevice.h"


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

