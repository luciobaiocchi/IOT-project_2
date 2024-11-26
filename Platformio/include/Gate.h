#ifndef __GATE__
#define __GATE__

#include "Arduino.h"
#include "Servo.h"
#include "Costants.h"
#include "LCDManager.h"

class Gate {
private:
    Servo servo;
    enum State { CLOSE, OPEN } currentState;
    int pinServo;
    int tickGateOpen;
    int tickAfterClose;
    LCDManager& lcdManager; // Campo membro come riferimento

public:
    Gate(int pinServo, LCDManager& lcdManager); // Costruttore accetta riferimento
    int getState();
    void closeGate();
    void openGateButton();
    void openGateUser();
    bool timeOpenElapsed();
    bool timeAfterCloseElapsed();
    void decrementTick();
};

#endif
