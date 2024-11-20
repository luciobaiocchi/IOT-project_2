#include "Arduino.h"
#include "AllarmTask.h"
#include "DHT.h"
#include "Costants.h"
#include "Task.h"
#include "ContainerProp.h"

AllarmTask :: AllarmTask(int pinTemp, ContainerProp container){
    this->pinTemp = pinTemp;
    this->container = container;
    pinMode(pinTemp, INPUT);
}

void AllarmTask::init(int period){
    Task::init(period);
}

void AllarmTask::tick(){
    if (isTempOverMax()){
        this->container.setAllarm(true);
    }
}

bool AllarmTask::isTempOverMax(){
    int t = dht.readTemperature();
    return(t > MAX_TEMP);
}
