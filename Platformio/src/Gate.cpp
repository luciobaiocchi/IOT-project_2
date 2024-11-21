#include "Gate.h"

Gate::Gate(int pinServo, LCDManager& lcdManager) 
    : pinServo(pinServo), lcdManager(lcdManager) { // Inizializzazione del riferimento
    currentState = CLOSE;
}

void Gate::closeGate() {
    if (currentState == OPEN) {
        // Serial.println("CLOSE");
        /* servo->attach(pinServo);
        servo->write(1500);
        servo->detach(); */
        currentState = CLOSE;
        timeAfterClose = millis();
        lcdManager.setMessage(LCD_3);
    }
    if (timeAfterCloseElapsed()){
        lcdManager.setMessage(LCD_1);
    }
    
}

void Gate::openGateButton() {
    if (currentState == CLOSE) {
        // Serial.println("OPEN");
        currentState = OPEN;
        /* servo->attach(pinServo);
        servo->write(750);
        servo->detach(); */
        timeGateOpen = millis();
        lcdManager.setMessage(LCD_2);
        // Serial.println(lcdManager.getMessage());
    }
}

void Gate::openGateUser() {
    if (currentState == CLOSE) {
        currentState = OPEN;
        servo->attach(pinServo);
        servo->write(2250);
        servo->detach();
        timeGateOpen = millis();
    }
}

bool Gate::timeOpenElapsed() {
    return (millis() - timeGateOpen) >= MAX_TIME_OPEN;
}

bool Gate::timeAfterCloseElapsed() {
    return (millis() - timeAfterClose) >= T2;
}

int Gate::getState() {
    return currentState;
}
