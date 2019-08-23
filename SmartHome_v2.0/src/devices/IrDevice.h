#ifndef IRDEVICE_H
#define IRDEVICE_H

#include <IRremote.h>
#include "constants/IrCodes.h"
#include "devices/core/OutputDevice.h"

class IrDevice : public Device {
private:
  bool isInitialized=false;
  void decodeIR(int value);

public:
    IrDevice(string name, int pin, int virtualPin, OutputDevice device);

    ~IrDevice();

    void init();

    void execute() override;

    void setEvent(IrController code,OutputDevice device);
};

#endif //IRDEVICE_H
