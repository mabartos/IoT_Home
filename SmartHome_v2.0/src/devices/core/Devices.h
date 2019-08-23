#ifndef DEVICES_H
#define DEVICES_H

#include "Device.h"
#include <array>
#include <tuple>
#include <vector>
#include <devices/LightsDevice.h>
#include <devices/IrDevice.h>
#include <devices/ExtBtnDevice.h>

class Devices {
private:
    vector<Device> devicesVect;
    vector<LightsDevice> lightsVect;
    vector<IrDevice> IrVect;
    vector<ExtBtnDevice> extBtnVect;

public:
    Devices();

    ~Devices();

    Device *findById(int id);

    Device *findByName(const string &name);

    void addDevice(const Device &device);

    void removeDevice(Device device);

    int getSize();

    void initAll();

    void execAll();

    vector<Device> getAllDevices();

    vector<LightsDevice> getLights();

    vector<IrDevice> getIR();

    vector<ExtBtnDevice> getExtBtns();
};

#endif //DEVICES_H
