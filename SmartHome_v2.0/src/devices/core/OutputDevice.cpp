#include "OutputDevice.h"

OutputDevice::OutputDevice(string name, int pin, int virtualPin) : Device(move(name), pin, virtualPin) {
    state = false;
}

OutputDevice::~OutputDevice() {}

bool OutputDevice::getState() {
    return state;
}
