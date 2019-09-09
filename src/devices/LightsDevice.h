#ifndef LIGHTS_DEVICE_H
#define LIGHTS_DEVICE_H

#include <Arduino.h>
#include <string>
#include "core/OutputDevice.h"

class LightsDevice : public OutputDevice {
private:
    int intensity = 0;

    unsigned int checkIntensity(float intensity);

public:

    LightsDevice(string name, int pin);

    ~LightsDevice();

    unsigned int getIntensity();

    void changeIntensity(float intensity);

    void changeState() override;

    bool isTurnedOn();
};

#endif //LIGHTS_DEVICE_H
