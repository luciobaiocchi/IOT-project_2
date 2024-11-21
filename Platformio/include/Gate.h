#ifndef __GATE__
#define __GATE__

#include "Arduino.h"
#include <ServoTimer2.h>
#include "Costants.h"
#include "LCDManager.h"

class Gate {
private:
    ServoTimer2* servo;
    enum State { CLOSE, OPEN } currentState;
    int pinServo;
    long timeGateOpen;
    long timeAfterClose;
    LCDManager& lcdManager; // Campo membro come riferimento

public:
    Gate(int pinServo, LCDManager& lcdManager); // Costruttore accetta riferimento
    int getState();
    void closeGate();
    void openGateButton();
    void openGateUser();
    bool timeOpenElapsed();
    bool timeAfterCloseElapsed();
};

#endif
