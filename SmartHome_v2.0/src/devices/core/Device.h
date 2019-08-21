#ifndef DEVICE_H
#define DEVICE_H

using namespace std;

class Device {

private:
    string name;
    unsigned int id = 0;
    unsigned int pin = 0;
    unsigned int virtualPin = 0;

protected:
    bool turnedOn;
  
public:
    static unsigned int id_counter;

    Device(string name, int pin, int virtualPin);

    ~Device();

    virtual void init();

    virtual void execute();

    int getId();

    string getName();

    virtual bool isTurnedOn();

    unsigned int getPin();

    unsigned int getVirtualPin();
};

#endif //DEVICE_H
