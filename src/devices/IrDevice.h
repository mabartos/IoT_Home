#ifndef IRDEVICE_H
#define IRDEVICE_H

using namespace std;

#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
#include <string>
#include <constants/IrCodes.h>
#include "core/Device.h"
#include "core/OutputDevice.h"

class IrDevice : public Device {
private:
    bool isInitialized = false;

    void decodeIR(int value);

    OutputDevice &controlledDevice;

public:
    IrDevice(string name, int pin, OutputDevice &device);

    ~IrDevice();

    void init();

    void execute() override;

    static void setEvent(IrController code, OutputDevice device);
};

#endif //IRDEVICE_H