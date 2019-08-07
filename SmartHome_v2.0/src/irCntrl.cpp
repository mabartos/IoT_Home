#include "main.hpp"

decode_results results;
IRrecv irrecv(RECV_PIN);

void decodeIR(int value) {
    switch (value) {
        case 0x20DF8E71:
            if (*ledUnderOn) {
                Blynk.virtualWrite(V_LED_UNDER, 0);
                changeStateLed(LED_UNDER, 0, ledUnderIntensity, ledUnderOn);
            } else {
                Blynk.virtualWrite(V_LED_UNDER, 1);
                changeStateLed(LED_UNDER, 1, ledUnderIntensity, ledUnderOn);
            }
            break;
        case 0x20DFC639:
            if (*ledMainOn) {
                Blynk.virtualWrite(V_LED_MAIN, 0);
                changeStateLed(LED_MAIN, 0, ledMainIntensity, ledMainOn);
            } else {
                Blynk.virtualWrite(V_LED_MAIN, 1);
                changeStateLed(LED_MAIN, 1, ledMainIntensity, ledMainOn);
            }
            break;
        default:
            break;
    }
}

void irInit() {
    static bool tmpTrigger = false;
    if (!tmpTrigger) {
        tmpTrigger = true;
        irrecv.enableIRIn();
    }
    if (irrecv.decode(&results)) {
        decodeIR(results.value);
        irrecv.resume(); // Receive the next value
    }
}
