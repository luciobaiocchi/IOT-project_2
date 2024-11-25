#ifndef __PROXIMITYTASK__
#define __PROXIMITYTASK__
#include "Task.h"
#include "LCDManager.h"

class ProximityTask : public Task {
private:
    LCDManager lcdManager;
    int pirState; 
    int pinSensor;
    unsigned long initTime;
    bool detectedStatus;
    int val;
    volatile bool interruptFlag;
    bool checkEndTime(unsigned long actualTime);
    void sleep();
public:
    ProximityTask(int pinSensor, LCDManager& lcdManager);
    void init(int period);
    void tick();
};

#endif