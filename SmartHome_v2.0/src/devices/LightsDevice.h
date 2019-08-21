#include "main.hpp"
#include "devices/Device.h"

class LightsDevice : public Device {
private:
    int intensity = 0;

    unsigned int checkIntensity(float intensity);

public:

    LightsDevice(string name, int pin, int virtualPin);

    ~LightsDevice();

    unsigned int getIntensity();

    void changeIntensity(float intensity);

    void changeStateLed();

    bool isTurnedOn();
};
