#ifndef __GATE__
#define __GATE__

#include "Arduino.h"
#include "Servo.h"
#include "Costants.h"
#include "LCDManager.h"
#include "TickCounter.h"

class Gate {
private:
    Servo servo;
    int pinServo;
    LCDManager& lcdManager; // Campo membro come riferimento
    int currentDir;
    void move(int dir);
    int currentState;
public:
    Gate(int pinServo, LCDManager& lcdManager); // Costruttore accetta riferimento
    int getState();
    void openGate();
    void closeGate();
    void allarmClosure();
    void setState(int gateState);
};

#endif
