#include "ContainerProp.h"
#include "Arduino.h"
#include "Costants.h"

ContainerProp::ContainerProp(){
    //Serial.begin(9600);
    this->allarm = false;
    this->contLevel = 0;
}

ContainerProp::ContainerProp(LCDManager& lcdManager) : lcdManager(lcdManager){
    this->allarm = false;
    this->contLevel = 0;
}

void ContainerProp::setWasteLevel(int level){
    this->contLevel = level;
    Serial.println(level);
    if (this->isFull()){
        lcdManager.setMessage(LCD_4);
    }
}

void ContainerProp::setTempLevel(int level){
    if (level <= MAX_TEMP){
        this->contLevel = level;
    }else{
        this->setAllarm(true);
        lcdManager.setMessage(LCD_5);
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
    return this->contLevel >= MAX_PERC_LEVEL;
}

bool ContainerProp::isAllarmOn(){
    return this->allarm;
}

bool ContainerProp::genericAllarm(){
    return(this->isAllarmOn() || this->isFull());
}