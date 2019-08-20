#ifndef MAIN_HPP
#define MAIN_HPP

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "Adafruit_Sensor.h"
#include "BlynkSimpleEsp8266MY.h"
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
#include "blynkCredentials.h"
#include "DHT.h"
#include "Device.h"

#define BLYNK_PRINT Serial
#define TRUE 1
#define FALSE 0

//DIGITAL PINS
#define EXT_BTN_L D1
#define IR D2
#define LED_MAIN D5
#define LED_UNDER D6
#define EXT_BTN_R D7
#define DHT_PIN D8

//VIRTUAL PINS
#define V_RELE1 V0
#define V_RELE2 V1
#define V_INTENSITY_UNDER_SWITCH V3
#define V_LED_UNDER V4
#define V_LED_MAIN V5
#define V_TEMPERATURE V6
#define V_HUMIDITY V7

const uint16_t RECV_PIN = IR;

extern bool *ledUnderOn,
            *ledMainOn;
extern int *ledUnderIntensity,
           *ledMainIntensity;

void checkExternBtn();

bool changeStateRelay(int value, int blynkPort, int device);

void irInit();

void decodeIR(int value);

void changeIntensity(int device, float intensity,int *deviceIntensity);

void changeStateLed(int device, int state,int *deviceIntensity,bool *deviceState);

BLYNK_CONNECTED();
BLYNK_WRITE(V_RELE1);
BLYNK_WRITE(V_RELE2);

#endif
