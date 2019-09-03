#ifndef DEVICES_H
#define DEVICES_H

#include "Device.h"
#include <array>
#include <tuple>
#include <vector>
#include <devices/LightsDevice.h>
#include <devices/IrDevice.h>
#include <devices/ExtBtnDevice.h>
#include "devices/constants/DeviceNames.h"
#include "devices/constants/DevicePins.h"

class Devices {
private:
    static vector<Device> devicesVect;
    static vector<LightsDevice> lightsVect;
    static vector<IrDevice> IrVect;
    static vector<ExtBtnDevice> extBtnVect;

public:
    Devices();

    ~Devices();

    static Device &findById(int id);

    static Device &findByName(const string &name);

    static void addDevice(const Device &device);

    static void removeDevice(Device device);

    static int getSize();

    static void initAll();

    static void execAll();

    static vector<Device> getAllDevices();

    static vector<LightsDevice> getLights();

    static vector<IrDevice> getIR();

    static vector<ExtBtnDevice> getExtBtns();
};

#endif //DEVICES_H
