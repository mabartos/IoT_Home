//
// Created by mabartos on 9/3/19.
//

#ifndef SMARTHOME_V2_0_DEVICESFACTORY_H
#define SMARTHOME_V2_0_DEVICESFACTORY_H

#include <string>
#include "devices/constants/DeviceTypes.h"
#include "devices/constants/DeviceNames.h"
#include "devices/constants/DevicePins.h"
#include "Devices.h"

using namespace std;

class DevicesFactory {
public:
    static void createDevices();
};


#endif //SMARTHOME_V2_0_DEVICESFACTORY_H
