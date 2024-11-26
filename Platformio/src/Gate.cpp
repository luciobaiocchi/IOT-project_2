#include "Gate.h"

Gate::Gate(int pinServo, LCDManager& lcdManager) 
    : lcdManager(lcdManager) { 
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

void Gate::move(int dir){
    switch (dir){
    case 90:
        currentState = 3;
        break;
    case 180:
        currentState = 2;
    }
    if (dir != currentDir){
        servo.write(dir);
        currentDir = dir;
    }
    
    
}

void Gate::allarmClosure(){
    move(90);
}

void Gate::setState(int gateState){
    currentState = gateState;
}
