#include "main.hpp"
#include "devices/LightsDevice.h"

LightsDevice::LightsDevice(string name, int pin, int virtualPin) : Device(name, pin, virtualPin) {
    Device::init();
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
    unsigned long difference = (unsigned long) (actualIntensity - reqIntensity);

    LightsDevice::intensity = reqIntensity;

    //Difference for computing delay
    if (difference != 0) {
        unsigned long delayPerIteration = delayMs / difference;

        if (reqIntensity < actualIntensity) {
            for (int i = actualIntensity; i >= reqIntensity; i--) {
                analogWrite(LightsDevice::getPin(), i);
                delay(delayPerIteration);
            }
        } else {
            for (int i = actualIntensity; i <= reqIntensity; i++) {
                analogWrite(LightsDevice::getPin(), i);
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

void LightsDevice::changeStateLed() {
    if (isTurnedOn()) {
        LightsDevice::turnedOn=false;
        changeIntensity(0);
    } else {
        LightsDevice::turnedOn=true;
        changeIntensity(1);
    }
}
