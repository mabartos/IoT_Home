#ifndef EXT_BTN_H
#define EXT_BTN_H

using namespace std;
#include <Arduino.h>
#include "core/Device.h"

class OutputDevice;

class ExtBtnDevice : public Device {
private:
    bool current;
    bool previous;
    OutputDevice &outDevice;

public:
    ExtBtnDevice(string name, int pin, OutputDevice &device);

    ~ExtBtnDevice();

    void init() override;

    void execute() override;

    OutputDevice &getDevice();
};

#endif
