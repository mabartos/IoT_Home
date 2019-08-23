#ifndef EXT_BTN_H
#define EXT_BTN_H

#include "main.hpp"
#include "devices/core/Device.h"
#include <devices/core/OutputDevice.h>


class ExtBtnDevice : public Device {
private:
    bool current;
    bool previous;
    OutputDevice outDevice;

public:
    ExtBtnDevice(string name, int pin, int virtualPin, OutputDevice device);

    ~ExtBtnDevice();

    void init() override;

    void execute() override;

    OutputDevice getDevice();
};

#endif EXT_BTN_H
