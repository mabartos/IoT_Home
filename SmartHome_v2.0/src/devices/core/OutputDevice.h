
#include "devices/core/Device.h"

class OutputDevice : public Device {
private:
    bool state;

public:
    OutputDevice(string name, int pin);

    OutputDevice();

    ~OutputDevice();

    virtual void changeState();

    bool getState();
};
