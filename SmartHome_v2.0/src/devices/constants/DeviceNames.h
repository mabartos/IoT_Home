//
// Created by mabartos on 9/3/19.
//

#ifndef SMARTHOME_V2_0_DEVICENAMES_H
#define SMARTHOME_V2_0_DEVICENAMES_H

#include <string>

using namespace std;

inline namespace DeviceNames {
    // Lights
    const string
            MAIN_LIGHTS = "main_lights",
            UNDER_LIGHTS = "under_lights",
            RGB_LIGHTS = "rgb_lights",
            TV_LIGHTS = "tv_lights",
    // Buttons
            EXT_BTN_LEFT = "ext_btn_left",
            EXT_BTN_RIGHT = "ext_btn_right",
    // IR
            MAIN_IR = "main_ir",
    // RELAYS
            RELAY_1 = "relay_1",
            RELAY_2 = "relay_2",
            RELAY_FAN = "relay_fan",
    // Measurement of environment
            TEMP_ROOM = "temp_room",
            HUMIDITY_ROOM = "humidity_room";
};

#endif //SMARTHOME_V2_0_DEVICENAMES_H
