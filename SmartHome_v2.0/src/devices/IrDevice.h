#ifndef IRDEVICE_H
#define IRDEVICE_H

#include <IRrecv.h>
#include <IRutils.h>
#include "constants/IrCodes.h"
#include "devices/core/OutputDevice.h"

class IrDevice : public Device {
private:
    decode_results results;

    IRrecv irrecv(RECV_PIN);

    void decodeIR(int value);

public:
    IrDevice(string name, int pin, int virtualPin, OutputDevice device);

    ~IrDevice();

    void init();

    void execute() override;
};

#endif //IRDEVICE_H
