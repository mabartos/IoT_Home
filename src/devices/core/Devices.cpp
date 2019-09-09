#include <main.h>
#include "Devices.h"

#include "Device.h"
#include "../LightsDevice.h"
#include "../IrDevice.h"
#include "../ExtBtnDevice.h"


// Add all devices here
struct CreateDevicesBlock {
    CreateDevicesBlock() {

        //LIGHTS
        /*  auto mainLights = make_unique<LightsDevice>(DeviceNames::MAIN_LIGHTS, DevicePins::LED_MAIN);
          auto underLights = make_unique<LightsDevice>(DeviceNames::UNDER_LIGHTS, DevicePins::LED_UNDER);
          unique_ptr<LightsDevice> devi = make_unique<LightsDevice>(new LightsDevice("SS", 3));

          Devices::addDevice(mainLights);
          Devices::addDevice(devi);

          //External buttons
          Devices::addDevice(make_unique<ExtBtnDevice>(DeviceNames::EXT_BTN_LEFT, DevicePins::EXT_BTN_L, mainLights));
          Devices::addDevice(make_unique<ExtBtnDevice>(DeviceNames::EXT_BTN_RIGHT, DevicePins::EXT_BTN_R, underLights));
          */
    }
};

static CreateDevicesBlock devicesBlock;


vector<unique_ptr<Device>> Devices::getAllDevices() {
    return devicesVect;
}

vector<unique_ptr<ExtBtnDevice>> Devices::getExtBtns() {
    return extBtnVect;
}

vector<unique_ptr<LightsDevice>> Devices::getLights() {
    return lightsVect;
}

vector<unique_ptr<IrDevice>> Devices::getIR() {
    return IrVect;
}

Device &Devices::findById(int id) {
    for (auto &device:devicesVect) {
        if (device->getId() == id)
            return *device;
    }
}

Device &Devices::findByName(const string &name) {
    for (auto &device:devicesVect) {
        if (device.get()->getName() == name)
            return *device;
    }
}

template<class T>
void Devices::addDevice(const unique_ptr<T> &device) {
    devicesVect.push_back(move(device));
}

void Devices::removeDevice(unique_ptr<Device> &device) {
    device.reset();
    /*
    for (unique_ptr<Device> &deviceItem:devicesVect) {
        if (deviceItem->getId() == device->getId())
            deviceItem.reset();
    }
    */
}

int Devices::getSize() {
    return devicesVect.size();
}

void Devices::initAll() {
    for (auto &device:devicesVect) {
        device->init();
    }
}

void Devices::execAll() {
    for (auto &device:devicesVect) {
        device->execute();
    }
}