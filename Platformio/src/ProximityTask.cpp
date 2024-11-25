#include "ProximityTask.h"
#include "Arduino.h"
#include "Costants.h"
#include <EnableInterrupt.h>
#include <avr/sleep.h>


ProximityTask::ProximityTask(int pinSensor){
    this->pinSensor = pinSensor;
    pinMode(pinSensor, INPUT);
    this->initTime = 0;
}

void ProximityTask::init(int period){
    Task::init(period);
}

void ProximityTask::tick(){
    val = digitalRead(pinSensor);  // read input value
    if (val == HIGH) {            // check if the input is HIGH
    Serial.println("RILEVATO");
        this->initTime = millis();
    }else if (val == LOW && checkEndTime(millis())) {
        enableInterrupt(pinSensor, NULL, RISING);
        set_sleep_mode(SLEEP_MODE_PWR_DOWN); 
        sleep_enable(); 
        sleep_mode();   
        sleep_disable();
    }
}

boolean ProximityTask::checkEndTime(int actualTime){
    if ((this->initTime + TIME_DEEPSLEEP) >= actualTime ){
        return true;
    }
    return false;
}
