#ifndef MAIN_HPP
#define MAIN_HPP

using namespace std;

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "Adafruit_Sensor.h"
#include "BlynkSimpleEsp8266MY.h"
#include <IRremoteESP8266.h>

#include "blynkCredentials.h"
#include "DHT.h"

#define BLYNK_PRINT Serial

const uint16_t RECV_PIN = IR;

void checkExternBtn();

bool changeStateRelay(int value, int blynkPort, int device);

void irInit();

void decodeIR(int value);

void changeIntensity(int device, float intensity, int *deviceIntensity);

void changeStateLed(int device, int state, int *deviceIntensity, bool *deviceState);

BLYNK_CONNECTED();

BLYNK_WRITE(V_RELE1);
BLYNK_WRITE(V_RELE2);

#endif
