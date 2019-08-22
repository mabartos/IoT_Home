#include <string>
#include "Device.h"

using namespace std;
unsigned int Device::id_counter = 0;

Device::Device(string name, int pin, int virtualPin) : name(move(name)), pin(pin), virtualPin(virtualPin) {
    init();
    id_counter++;
    this->id = id_counter;
    turnedOn = false;
}

Device::~Device() {}

int Device::getId() {
    return id;
}

string Device::getName() {
    return name;
}

bool Device::isTurnedOn() {
    return turnedOn;
}

unsigned int Device::getPin() {
    return pin;
}

unsigned int Device::getVirtualPin() {
    return virtualPin;
}

DeviceType Device::getType() {
    return DeviceType::None;
}
