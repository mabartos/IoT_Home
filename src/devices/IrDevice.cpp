#include "IrDevice.h"
#include "core/Devices.h"
#include "core/Device.h"
#include "core/OutputDevice.h"
#include "constants/DeviceTypes.h"
#include "constants/IrCodes.h"
#include "constants/DevicePins.h"

IrDevice::IrDevice(string name, int pin, OutputDevice &device) : Device(name, pin),controlledDevice(device) {
    type = DeviceType::Ir;
}

IrDevice::~IrDevice() = default;

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
            Devices::getLights()[0]->changeState();
            break;
        case (int) IrController::LG_YELLOW:
            Devices::getLights().at(0)->changeState();
            break;
        default:
            break;
    }
}

void IrDevice::setEvent(IrController code, OutputDevice device) {

}

void IrDevice::init() {
    Device::init();
}
