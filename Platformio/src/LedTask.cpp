#include "LedTask.h"
#include "Arduino.h"

LedTask::LedTask(int pinGreen, int pinRed, ContainerProp container){
    greenLed = new Led(pinGreen);
    redLed = new Led(pinRed);
    this->container = container;
}

void LedTask::init(int period){
    Task::init(period);
}

void LedTask::tick(){
    if (container.genericAllarm()){
        greenLed->switchOff();
        redLed->switchOn();
    }else{
        greenLed->switchOn();
        redLed->switchOff();
    }
    
    
}
