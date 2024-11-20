#ifndef __GATE__
#define __GATE__
#include <ServoTimer2.h>  
#include "Costants.h"
#include "Arduino.h"


class Gate{
private:
    ServoTimer2 servo;
    enum State{ CLOSE, OPEN } currentState;
    int pinServo;
    long timeGateOpen;
    long waitTheT2;
    
public:
    Gate(int pinServo);
    int getState();
    void closeGate();
    void openGateButton();
    void openGateUser();
    bool timeOpenElapsed();
    bool timeAfterCloseElapsed();

};

#endif