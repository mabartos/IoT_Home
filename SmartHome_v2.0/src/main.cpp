#include "main.hpp"
#include <stdio.h>

BlynkWifi Blynk(_blynkTransport);
DHT dht(DHT_PIN,DHT11);

int *ledUnderIntensity = (int *) malloc(sizeof(int));
int *ledMainIntensity = (int *) malloc(sizeof(int));
bool *ledUnderOn = (bool *) malloc(1);
bool *ledMainOn = (bool *) malloc(1);

Device test("test",3,3);

BLYNK_CONNECTED() {
    Blynk.syncAll();
}

BLYNK_WRITE(V_RELE1){
        int pinValue = param.asInt();
        //*releOn1=changeStateRelay(pinValue, V_RELE1, RELE1);
}

BLYNK_WRITE(V_RELE2){
        int pinValue = param.asInt();
        //*releOn2=changeStateRelay(pinValue, V_RELE2, RELE2);
}

BLYNK_WRITE(V_LED_UNDER){
        int pinValue = param.asInt();
        Blynk.virtualWrite(V_INTENSITY_UNDER_SWITCH, 3);
        changeStateLed(LED_UNDER, pinValue, ledUnderIntensity, ledUnderOn);
}

BLYNK_WRITE(V_LED_MAIN){
        int pinValue = param.asInt();
        changeStateLed(LED_MAIN, pinValue, ledMainIntensity, ledMainOn);
}


BLYNK_WRITE(V_INTENSITY_UNDER_SWITCH){
        float intensity=0;
        switch (param.asInt()) {
            case 1:
                intensity = 0.25;
            break;
            case 2:
                intensity = 0.5;
            break;
            case 3:
                intensity = 1;
            break;
        }

        if (*ledUnderOn){
            changeIntensity(LED_UNDER, intensity, ledUnderIntensity);
        }
}

BLYNK_READ(V_TEMPERATURE){
        //float temp = (3.3 * analogRead(A0) * 100.0) / 1024;
        float temp=dht.readTemperature();
        if(!isnan(temp))
        Blynk.virtualWrite(V_TEMPERATURE, (int)temp);
}

BLYNK_READ(V_HUMIDITY){
        //float temp = (3.3 * analogRead(A0) * 100.0) / 1024;
        float hum=dht.readHumidity();
        if(!isnan(hum))
        Blynk.virtualWrite(V_HUMIDITY, (int)hum);
}


void setup() {
    Serial.begin(9600);
    Blynk.begin(AUTH_TOKEN,SSID,PASS);
    dht.begin();

    //pinMode(RELE1, OUTPUT);
    //pinMode(RELE2, OUTPUT);

    pinMode(EXT_BTN_L, INPUT_PULLUP);
    pinMode(EXT_BTN_R, INPUT_PULLUP);

    pinMode(LED_UNDER, OUTPUT);
    pinMode(LED_MAIN, OUTPUT);




    //*releOn1 = changeStateRelay(0, V_RELE1, RELE1);
    //*releOn2 = changeStateRelay(0, V_RELE2, RELE2);
}

void loop() {
    Blynk.run();
    Serial.println(test.getId());

    Serial.println(test.getName().c_str());
    Serial.println(Device::id_counter);
    Serial.println("___");


    checkExternBtn();
    irInit();
    delay(10);
}
