#include "Arduino.h"
#include "WasteLevelTask.h"
#include "ContainerProp.h"


WasteLevelTask :: WasteLevelTask (int pinSensor, ContainerProp container){
    this->pinSensor = pinSensor;
    this->container = container;
}

void WasteLevelTask :: init(int period){
    Task::init(period);
}

void WasteLevelTask :: tick(){
    if (this->isFull()){
        this->container.setWasteLevel(0);
    }
}

bool WasteLevelTask :: isFull(){

}