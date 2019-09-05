#include "OutputDevice.h"

OutputDevice::OutputDevice(string name, int pin) : Device(move(name), pin) {
    state = false;
}

OutputDevice::~OutputDevice() {}

bool OutputDevice::getState() {
    return state;
}

void OutputDevice::changeState(){
}