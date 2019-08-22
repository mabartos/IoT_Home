#include "devices/LightsDevice.h"

LightsDevice::LightsDevice(string name, int pin, int virtualPin) : OutputDevice(name, pin, virtualPin) {
    type = DeviceType::Light;
}

LightsDevice::~LightsDevice() {}

unsigned int LightsDevice::getIntensity() {
    return intensity;
}

// Parameter intensity
void LightsDevice::changeIntensity(float intensity) {
    unsigned long delayMs = 1500;               //Time for speed turning on/off
    unsigned int reqIntensity = checkIntensity(intensity);    // Required Intensity
    unsigned int actualIntensity = LightsDevice::intensity; //Actual Intensity
    auto difference = (unsigned long) (actualIntensity - reqIntensity);

    LightsDevice::intensity = reqIntensity;

    //Difference for computing delay
    if (difference != 0) {
        unsigned long delayPerIteration = delayMs / difference;

        if (reqIntensity < actualIntensity) {
            for (unsigned int i = actualIntensity; i >= reqIntensity; i--) {
                analogWrite(getPin(), i);
                delay(delayPerIteration);
            }
        } else {
            for (unsigned int i = actualIntensity; i <= reqIntensity; i++) {
                analogWrite(getPin(), i);
                delay(delayPerIteration);
            }
        }
    }
}

unsigned int LightsDevice::checkIntensity(float intensity) {
    unsigned int reqIntensity;
    if (intensity > 1)
        reqIntensity = 1023;
    else if (intensity < 0)
        reqIntensity = 0;
    else
        reqIntensity = 1023 * intensity;

    return reqIntensity;
}

void LightsDevice::changeState() {
    if (isTurnedOn()) {
        Device::turnedOn = false;
        changeIntensity(0);
    } else {
        LightsDevice::turnedOn = true;
        changeIntensity(1);
    }
}

bool LightsDevice::isTurnedOn() {
    return OutputDevice::getState();
}
