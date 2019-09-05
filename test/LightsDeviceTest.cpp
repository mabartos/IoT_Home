#include <Arduino.h>
#include <unity.h>
#include "devices/LightsDevice.h"

const uint8_t PIN=1;

LightsDevice device("test",PIN);

void checkInit(){
    TEST_ASSERT_EQUAL(DeviceType::Light,device.getType());
    TEST_ASSERT_EQUAL_INT(0,device.getIntensity());
}

void changeIntensity(){
    device.changeIntensity(1.1);
    TEST_ASSERT_EQUAL_INT(1023,device.getIntensity());
    delay(1000);
    TEST_ASSERT_EQUAL_INT(1023,analogRead(PIN));
    device.changeIntensity(0);
    TEST_ASSERT_EQUAL_INT(0,device.getIntensity());
    delay(1000);
    device.changeIntensity(0.5);
    TEST_ASSERT_EQUAL_INT((int)0.5*1023,device.getIntensity());
}

void setup(){
    delay(2000);
    UNITY_BEGIN();
    pinMode(PIN,OUTPUT);
}

void loop(){
    checkInit();
    changeIntensity();
    UNITY_END();
}