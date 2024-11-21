#include "ContainerProp.h"
#include "Arduino.h"
#include "Costants.h"

ContainerProp::ContainerProp(){
    this->allarm = false;
    this->contLevel = 0;
}

void ContainerProp::setWasteLevel(int level){
    this->contLevel = level;
}

void ContainerProp::setTempLevel(int level){
    if (level <= MAX_TEMP){
        this->contLevel = level;
    }else{
        this->setAllarm(true);
    }
}

void ContainerProp::setAllarm(bool state){
    if(this->isAllarmOn() == state){
    }else{
        this->allarm = state;
    }
}

int ContainerProp::getWasteLevel(){
    return this->contLevel;
}

int ContainerProp::getTempLevel(){
    return this->tempLevel;
}

bool ContainerProp::isFull(){
    return this->contLevel <= MAX_CONT_LEVEL;
}

bool ContainerProp::isAllarmOn(){
    return this->allarm;
}

bool ContainerProp::genericAllarm(){
    return(this->isAllarmOn() || this->isFull());
}