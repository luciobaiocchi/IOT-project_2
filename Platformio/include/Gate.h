#ifndef __GATE__
#define __GATE__
#include "Arduino.h"
#include <ServoTimer2.h>  
#include "Costants.h"
#include "Arduino.h"
#include "LCDManager.h"


class Gate{
private:
    ServoTimer2* servo;
    enum State{ CLOSE, OPEN } currentState;
    int pinServo;
    long timeGateOpen;
    long waitTheT2;
    LCDManager lcdManager;
public:
    Gate(int pinServo, LCDManager lcdManager);
    int getState();
    void closeGate();
    void openGateButton();
    void openGateUser();
    bool timeOpenElapsed();
    bool timeAfterCloseElapsed();

};

#endif