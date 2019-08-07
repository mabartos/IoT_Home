#include "main.hpp"
#include "BlynkSimpleEsp8266MY.h"

bool changeStateRelay(int value, int blynkPort, int device) {
    bool releOn = false;
    if (value == 0) {
        Blynk.virtualWrite(blynkPort, 0);
        digitalWrite(device, HIGH);
        releOn = false;
    } else {
        Blynk.virtualWrite(blynkPort, 1);
        digitalWrite(device, LOW);
        releOn = true;
    }
    return releOn;
}
