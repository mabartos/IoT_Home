#ifndef IRDEVICE_H
#define IRDEVICE_H

class IrDevice:public Device {
private:
    decode_results results;
    IRrecv irrecv(RECV_PIN);
    void decodeIR(int value);
public:
    IrDevice(string name, int pin, int virtualPin, Device device);
    ~IrDevice();
    void init();
    void execute();
};

#endif //IRDEVICE_H
