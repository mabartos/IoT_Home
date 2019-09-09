#ifndef DEVICE_H
#define DEVICE_H


#include <string>
#include <utility>
#include <main.h>
#include "../constants/DeviceTypes.h"

using namespace std;

class Device {

private:
    string name;
    unsigned int id = 0;
    unsigned int pin = 0;

protected:
    bool turnedOn;
    DeviceType type;

public:
    static unsigned int id_counter;

    Device(string name, int pin);

    ~Device();

    virtual void init();

    virtual void execute();

    virtual DeviceType &getType();

    int getId();

    string getName();

    virtual bool isTurnedOn();

    unsigned int getPin();

};

#endif //DEVICE_H
