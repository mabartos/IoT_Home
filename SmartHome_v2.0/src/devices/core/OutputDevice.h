
#include "devices/core/Device.h"

class OutputDevice : public Device {
private:
    bool state;

public:
    OutputDevice(string name, int pin, int virtualPin);

    OutputDevice();

    ~OutputDevice();

    virtual void changeState();

    bool getState();
};
