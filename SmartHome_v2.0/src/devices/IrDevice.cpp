#include "IrDevice.h"


IrDevice::IrDevice(string name, int pin, int virtualPin, OutputDevice device) : Device(name, pin, virtualPin) {
    type = DeviceType::Ir;
    irrecv.enableIRIn();
}

IrDevice::~IrDevice() {}

void IrDevice::execute() {
    if (irrecv.decode(&results)) {
        decodeIR(results.value);
        irrecv.resume(); // Receive the next value
    }
}

void IrDevice::decodeIR(int value) {
    switch (value) {
        case IrController::LG_GREEN:
            if (*ledUnderOn) {
                Blynk.virtualWrite(V_LED_UNDER, 0);
                changeStateLed(LED_UNDER, 0, ledUnderIntensity, ledUnderOn);
            } else {
                Blynk.virtualWrite(V_LED_UNDER, 1);
                changeStateLed(LED_UNDER, 1, ledUnderIntensity, ledUnderOn);
            }
            break;
        case LG_YELLOW:
            if (*ledMainOn) {
                Blynk.virtualWrite(V_LED_MAIN, 0);
                changeStateLed(LED_MAIN, 0, ledMainIntensity, ledMainOn);
            } else {
                Blynk.virtualWrite(V_LED_MAIN, 1);
                changeStateLed(LED_MAIN, 1, ledMainIntensity, ledMainOn);
            }
            break;
        default:
            break;
    }
}
