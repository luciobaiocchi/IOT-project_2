#include "ProximityTask.h"
#include "Arduino.h"
#include "Costants.h"
#include <EnableInterrupt.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include "LCDManager.h"

void interruptHandler();
volatile bool interruptFlag = false;

ProximityTask::ProximityTask(int pinSensor, LCDManager& lcdManager) : lcdManager(lcdManager) {
    interruptFlag = false;
    this->lcdManager = lcdManager;
    this->pinSensor = pinSensor;
    this->detectedStatus = false;
    this->initTime = millis();
    pinMode(pinSensor, INPUT);
}

void ProximityTask::init(int period){
    Task::init(period);
}

void ProximityTask::tick(){
    val = digitalRead(pinSensor);  // read input value
    //Serial.println("tick");
    if (val != detectedStatus) {  
        detectedStatus = val;          // check if the input is HIGH
        if (detectedStatus){
            this->initTime = millis();
            //Serial.println("m");
            //delay(10);
        }/*else{
            Serial.println("f");
            delay(10);
        }*/
    }
    if (checkEndTime(millis())){
        this->sleep();
    }
}

boolean ProximityTask::checkEndTime(unsigned long actualTime){
    int timeRemanining = TIME_DEEPSLEEP - (actualTime - initTime);
    //Serial.println(timeRemanining);
    if (timeRemanining <= 0){
        return true;
    }
    return false;
}

void interruptHandler() {
    interruptFlag = true;
}

void ProximityTask::sleep(){
    // Abilita l'interrupt sul pin specifico
    enableInterrupt(pinSensor, interruptHandler, RISING);
    lcdManager.sleep();
    Serial.println("sleep");
    delay(20);
    set_sleep_mode(SLEEP_MODE_PWR_DOWN); 
    sleep_enable(); 
    sleep_mode();   
    sleep_disable();
    lcdManager.wakeUp();
    // Disabilita l'interrupt sul pin specifico
    disableInterrupt(pinSensor);
}
