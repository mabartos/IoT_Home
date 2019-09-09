#include "OutputDevice.h"

OutputDevice::OutputDevice(const string& name, int pin) : Device(name, pin) {
    state = false;
}

OutputDevice::~OutputDevice() {}

bool OutputDevice::getState() {
    return state;
}

void OutputDevice::changeState(){
}