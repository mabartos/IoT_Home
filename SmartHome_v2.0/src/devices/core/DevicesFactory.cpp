//
// Created by mabartos on 9/3/19.
//

#include "DevicesFactory.h"

void DevicesFactory::createDevices() {
    //LIGHTS
    LightsDevice mainLights(DeviceNames::MAIN_LIGHTS, DevicePins::LED_MAIN);
    LightsDevice underLights(DeviceNames::UNDER_LIGHTS, DevicePins::LED_UNDER);

    Devices::addDevice(mainLights);
    Devices::addDevice(underLights);

    //External buttons
    Devices::addDevice(ExtBtnDevice(DeviceNames::EXT_BTN_LEFT, DevicePins::EXT_BTN_L, mainLights));
    Devices::addDevice(ExtBtnDevice(DeviceNames::EXT_BTN_RIGHT, DevicePins::EXT_BTN_R, underLights));

}

