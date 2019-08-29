#include "Devices.h"

Devices::Devices() {
}

Devices::~Devices() {}

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

Device *Devices::findById(int id) {
    vector<Device>::iterator it;

    for (it = devicesVect.begin(); it != devicesVect.end(); it++) {
        if (it.base()->getId() == id)
            return it.base();
    }
    return nullptr;
}

Device *Devices::findByName(const string &name) {
    vector<Device>::iterator it;

    for (it = devicesVect.begin(); it != devicesVect.end(); it++) {
        if (it.base()->getName() == name)
            return it.base();
    }
    return nullptr;
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


