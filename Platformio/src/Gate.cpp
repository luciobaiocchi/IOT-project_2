#include "Gate.h"

Gate::Gate(int pinServo) { 
    currentState = 1;
    this->pinServo = pinServo;
    servo.attach(pinServo);
    servo.write(90);
    currentDir = 12002;
}

int Gate::getState() {
    return currentState;
}

void Gate::openGate(){
    move(180);
}

void Gate::closeGate(){
    move(90);
}


void Gate::emptyGate(){
    move(0);
}

void Gate::move(int dir){
    switch (dir){
        case 0:
            currentState = AVAILABLE;
            break;
        case 90:
            currentState = NOT_AVAILABLE;
            break;
        case 180:
            currentState = OPEN;
    }
    if (dir != currentDir){
        servo.write(dir);
        currentDir = dir;
    }
    
    
}

void Gate::setState(int gateState){
    currentState = gateState;
}


