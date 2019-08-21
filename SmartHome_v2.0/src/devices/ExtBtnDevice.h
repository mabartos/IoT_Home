#ifndef EXT_BTN_H
#define EXT_BTN_H

#include "main.hpp"
#include "devices/core/Device.h"

class ExtBtnDevice : public Device {
private:
    bool current;
    static bool previous;
    LightsDevice lights;

public:
    ExtBtnDevice(string name, int pin, int virtualPin);

    ~ExtBtnDevice();

    void init();

    void execute();

    LightsDevice getLights();
};

#endif EXT_BTN_H
