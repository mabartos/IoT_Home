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
    vector<Device>::iterator it;
    int i = 0;
    for (it = devicesVect.begin(); it != devicesVect.end(); it++, i++) {
        if (it.base()->getId() == device.getId())
            devicesVect.erase(devicesVect.begin() + i);
    }
}

int Devices::getSize() {
    return devicesVect.size();
}

void Devices::initAll() {
    vector<Device>::iterator it;
    for (it = devicesVect.begin(); it != devicesVect.end(); it++) {
        it.base()->init();
    }
}

void Devices::execAll() {
    vector<Device>::iterator it;
    for (it = devicesVect.begin(); it != devicesVect.end(); it++) {
        it.base()->execute();
    }
}


