#include "Gate.h"

Gate::Gate(int pinServo, LCDManager& lcdManager) 
    : lcdManager(lcdManager) { 
    currentState = CLOSE;
    this->pinServo = pinServo;
    servo.attach(pinServo);
    servo.write(90);

}

void Gate::closeGate() {
    
    
}

void Gate::openGateButton() {

    
}

void Gate::openGateUser() {

}

bool Gate::timeOpenElapsed() {
    return tickGateOpen <= 0;
}

bool Gate::timeAfterCloseElapsed() {
    return tickGateOpen <= 0;
}

void Gate::decrementTick(){
    tickAfterClose--;
    tickGateOpen--;
}

int Gate::getState() {
    return currentState;
}
