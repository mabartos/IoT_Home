#include <string>
#include "Device.h"

using namespace std;
unsigned int Device::id_counter = 0;

void Device::init(){
}

void Device::execute(){}

Device::Device(string name, int pin) : name(move(name)), pin(pin) {
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

DeviceType Device::getType() {
    return DeviceType::None;
}
