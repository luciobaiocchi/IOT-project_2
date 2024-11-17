#include "LedTask.h"
#include "Arduino.h"

LedTask::LedTask(int pinGreen, int pinRed){
    greenLed = new Led(pinGreen);
    redLed = new Led(pinRed);
}

void LedTask::init(int period){
    Task::init(period);
}

void LedTask::tick(){
    switch (currentState){
    case GATE_AVAILABLE:{
        greenLed->switchOn();
        redLed->switchOff();
        break;
    }
        
    case CONTAINER_FULL:{
        greenLed->switchOff();
        redLed->switchOn();
        break;
    }
        
    default:
        break;
    }
}
