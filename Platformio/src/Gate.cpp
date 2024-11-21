#include "Gate.h"

Gate::Gate(int pinServo, LCDManager lcdManager){
    this->pinServo = pinServo;
    this->lcdManager = lcdManager;
}

void Gate::closeGate(){
    if (currentState == OPEN){
        servo->attach(pinServo);
        servo->write(1500);
        servo->detach();
        waitTheT2 = millis();
        lcdManager.setMessage(LCD_3);
    }
    
}

void Gate::openGateButton(){
    if (currentState == CLOSE){
        servo->attach(pinServo);
        servo->write(750);
        servo->detach();
        timeGateOpen = millis();
        waitTheT2 = 0;
        lcdManager.setMessage(LCD_2);
    }
    
}

void Gate::openGateUser(){
    if (currentState == CLOSE){
        servo->attach(pinServo);
        servo->write(2250);
        servo->detach();
        timeGateOpen = millis();
    }

}

bool Gate::timeOpenElapsed(){
    return (millis() - timeGateOpen) >= MAX_TIME_OPEN;
}

bool Gate::timeAfterCloseElapsed(){
    if ((millis() - waitTheT2) >= T2){
        lcdManager.setMessage(LCD_1);
        return true;
    }
    return false;
}

int Gate::getState(){
    return currentState;
}
