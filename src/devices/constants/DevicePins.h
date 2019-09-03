//
// Created by mabartos on 9/3/19.
//

#ifndef SMARTHOME_V2_0_DEVICEPINS_H
#define SMARTHOME_V2_0_DEVICEPINS_H

inline namespace DevicePins {
    const int
            EXT_BTN_L = 1,
            IR = 2,
            LED_MAIN = 5,
            LED_UNDER = 6,
            EXT_BTN_R = 7,
            TEMP_PIN = 8;

    void init(){
        pinMode(EXT_BTN_L, INPUT_PULLUP);
        pinMode(EXT_BTN_R, INPUT_PULLUP);

        pinMode(LED_UNDER, OUTPUT);
        pinMode(LED_MAIN, OUTPUT);
    }
}

#endif //SMARTHOME_V2_0_DEVICEPINS_H
