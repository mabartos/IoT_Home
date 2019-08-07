#include "main.hpp"
#include "BlynkSimpleEsp8266MY.h"

void checkExternBtn() {
    bool lExtBtn = digitalRead(EXT_BTN_L);
    bool rExtBtn = digitalRead(EXT_BTN_R);
    static bool prevLeft = lExtBtn;
    static bool prevRight = rExtBtn;

    if (lExtBtn != prevLeft) {
        if (*ledUnderOn) {
            Blynk.virtualWrite(V_LED_UNDER, 0);
            changeStateLed(LED_UNDER, 0, ledUnderIntensity, ledUnderOn);
        } else {
            Blynk.virtualWrite(V_LED_UNDER, 1);
            changeStateLed(LED_UNDER, 1, ledUnderIntensity, ledUnderOn);
        }
        prevLeft = lExtBtn;
    }

    if (rExtBtn != prevRight) {
        if (*ledMainOn) {
            Blynk.virtualWrite(V_LED_MAIN, 0);
            changeStateLed(LED_MAIN, 0, ledMainIntensity, ledMainOn);
        } else {
            Blynk.virtualWrite(V_LED_MAIN, 1);
            changeStateLed(LED_MAIN, 1, ledMainIntensity, ledMainOn);
        }
        prevRight = rExtBtn;
    }
}
