#ifndef LIGHTS_DEVICE_H
#define LIGHTS_DEVICE_H

#include <devices/core/OutputDevice.h>
#include "main.hpp"
#include "devices/core/Device.h"

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
