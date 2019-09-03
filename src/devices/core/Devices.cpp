#include "Devices.h"

// Add all devices here
void createDevices() {
    //LIGHTS
    LightsDevice mainLights(DeviceNames::MAIN_LIGHTS, DevicePins::LED_MAIN);
    LightsDevice underLights(DeviceNames::UNDER_LIGHTS, DevicePins::LED_UNDER);

    Devices::addDevice(mainLights);
    Devices::addDevice(underLights);

    //External buttons
    Devices::addDevice(ExtBtnDevice(DeviceNames::EXT_BTN_LEFT, DevicePins::EXT_BTN_L, mainLights));
    Devices::addDevice(ExtBtnDevice(DeviceNames::EXT_BTN_RIGHT, DevicePins::EXT_BTN_R, underLights));
}

Devices::Devices() {
    createDevices();
}

Devices::~Devices() = default;

vector<Device> Devices::getAllDevices() {
    return devicesVect;
}

vector<ExtBtnDevice> Devices::getExtBtns() {
    return extBtnVect;
}

vector<LightsDevice> Devices::getLights() {
    return lightsVect;
}

vector<IrDevice> Devices::getIR() {
    return IrVect;
}

Device &Devices::findById(int id) {
    for (auto &device:devicesVect) {
        if (device.getId() == id)
            return device;
    }
}

Device &Devices::findByName(const string &name) {
    for (auto &device:devicesVect) {
        if (device.getName() == name)
            return device;
    }
}

void Devices::addDevice(const Device &device) {
    devicesVect.push_back(device);
}

void Devices::removeDevice(Device device) {
    int i = 0;
    for (auto deviceItem:devicesVect) {
        if (deviceItem.getId() == device.getId())
            devicesVect.erase(devicesVect.begin() + i);
        i++;
    }
}

int Devices::getSize() {
    return devicesVect.size();
}

void Devices::initAll() {
    for (auto device:devicesVect) {
        device.init();
    }
}

void Devices::execAll() {
    for (auto device:devicesVect) {
        device.execute();
    }
}




