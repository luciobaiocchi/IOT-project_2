#include "Arduino.h"
#include "WasteLevelTask.h"
#include "ContainerProp.h"
#include "Costants.h"

WasteLevelTask :: WasteLevelTask (int pinTrig, int pinEcho, ContainerProp container){
    this->pinTrig = pinTrig;
    this->pinEcho = pinEcho;
    this->container = container;
}

void WasteLevelTask :: init(int period){
    Task::init(period);
}

void WasteLevelTask :: tick(){
    this->container.setWasteLevel(this->readLevel());
}

bool WasteLevelTask :: isFull(){
    return this->container.isFull();
}

int WasteLevelTask:: readLevel(){
    digitalWrite(this->pinTrig, HIGH);
    delayMicroseconds(10);
    digitalWrite(this->pinTrig, LOW);

    // Read the result:
    int duration = pulseIn(pinEcho, HIGH);
    int dist = duration / 58;
    return map(dist , 0, MAX_CONT_LEVEL, 100, 0);
}