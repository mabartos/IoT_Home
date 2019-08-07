#include "main.hpp"

void changeStateLed(int device, int state,int *deviceIntensity,bool *deviceState) {
    if (state == 0){
        *deviceState=false;
        changeIntensity(device, 0,deviceIntensity);
      }
    else{
      *deviceState=true;
        changeIntensity(device, 1,deviceIntensity);
      }
}

void changeIntensity(int device, float intensity,int *deviceIntensity) {
    unsigned long delayMs = 1500;               //Time for speed turning on/off
    int actualIntensity = (*deviceIntensity); //Actual Intensity
    int reqIntensity = 1023 * intensity;          //Required Intensity

    *deviceIntensity = reqIntensity;

    //Difference for computing delay
    unsigned long difference = (unsigned long) abs(actualIntensity - reqIntensity);
    if (difference != 0) {
        unsigned long delayPerIteration = delayMs / difference;

        if (reqIntensity < actualIntensity) {
            for (int i = actualIntensity; i >= reqIntensity; i--) {
                analogWrite(device, i);
                delay(delayPerIteration);
            }
        } else {
            for (int i = actualIntensity; i <= reqIntensity; i++) {
                analogWrite(device, i);
                delay(delayPerIteration);
            }
        }
    }
}
