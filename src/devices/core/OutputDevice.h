#ifndef OUTPUT_DEVICE
#define OUTPUT_DEVICE

#include <string>
#include "Device.h"

class OutputDevice : public Device {
private:
    bool state;

public:
    OutputDevice(const string& name, int pin);

    OutputDevice()= default;

    ~OutputDevice();

    virtual void changeState();

    bool getState();
};

#endif
