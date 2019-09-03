#ifndef IR_DEVICE_H
#define IR_DEVICE_H

#include "IrDevice.h"

IrDevice::IrDevice(string name, int pin, OutputDevice &device) : Device(name, pin),controlledDevice(device) {
    type = DeviceType::Ir;
}

IrDevice::~IrDevice() {}

void IrDevice::execute() {
    decode_results results;
    int val = DevicePins::IR;
    IRrecv irrecv(val);
    if (!isInitialized) {
        irrecv.enableIRIn();
        isInitialized = true;
    }
    if (irrecv.decode(&results)) {
        decodeIR(results.value);
        irrecv.resume(); // Receive the next value
    }
}

void IrDevice::decodeIR(int value) {
    switch (value) {
        case (int) IrController::LG_GREEN:

            break;
        case (int) IrController::LG_YELLOW:

            break;
        default:
            break;
    }
}

void IrDevice::setEvent(IrController code, OutputDevice device) {

}

#endif
