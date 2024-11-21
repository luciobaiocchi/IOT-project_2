#include "ContainerProp.h"
#include "Arduino.h"
#include "Costants.h"

ContainerProp :: ContainerProp(LCDManager lcdManager){
    this->allarm = false;
    this->contLevel = 0;
    this->lcdManager = lcdManager;
}

bool ContainerProp :: setWasteLevel(int level){
    if ((this->contLevel +  level) <= MAX_CONT_LEVEL){
        this->contLevel = level;
        return true;
    }
    return false;
}

bool ContainerProp ::  setAllarm(bool state){
    if(this->isAllarmOn() == state){
        return false;
    }
    this->allarm = state;
}

int ContainerProp ::  getWasteLevel(){
    return this->contLevel;
}

bool ContainerProp :: isFull(){
    if (this->contLevel <= MAX_CONT_LEVEL){
        
        return true;
    }
}

bool ContainerProp :: isAllarmOn(){
    return this->allarm;
}

bool ContainerProp :: genericAllarm(){
    return(this->isAllarmOn() || this->isFull());
}