#ifndef DEVICE_H
#define DEVICE_H

#include "devices/core/types.h"
#include <string>
#include <utility>

using namespace std;

class Device {

private:
    string name;
    unsigned int id = 0;
    unsigned int pin = 0;
    unsigned int virtualPin = 0;

protected:
    bool turnedOn;
    DeviceType type;

public:
    static unsigned int id_counter;

    Device(string name, int pin, int virtualPin);

    ~Device();

    virtual void init();

    virtual void execute();

    virtual DeviceType getType();

    int getId();

    string getName();

    virtual bool isTurnedOn();

    unsigned int getPin();

    unsigned int getVirtualPin();
};

#endif //DEVICE_H
