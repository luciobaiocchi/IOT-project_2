#include "Gate.h"

Gate::Gate(int pinServo){
    this->pinServo = pinServo;
}

void Gate::closeGate(){
    if (currentState == OPEN){
        servo.attach(pinServo);
        servo.write(1500);
        servo.detach();
        waitTheT2 = millis();
    }
    
}

void Gate::openGateButton(){
    if (currentState == CLOSE){
        servo.attach(pinServo);
        servo.write(750);
        servo.detach();
        timeGateOpen = millis();
        waitTheT2 = 0;
    }
    
}

void Gate::openGateUser(){
    if (currentState == CLOSE){
        servo.attach(pinServo);
        servo.write(2250);
        servo.detach();
        timeGateOpen = millis();
    }

}

bool Gate::timeOpenElapsed(){
    return (millis() - timeGateOpen) >= MAX_TIME_OPEN;
}

bool Gate::timeAfterCloseElapsed(){
    return (millis() - waitTheT2) >= T2;
}

int Gate::getState(){
    return currentState;
}
