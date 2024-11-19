#ifndef __PROXIMITYTASK__
#define __PROXIMITYTASK__
#include "Task.h"

class ProximityTask : public Task {
private:
    int pirState; 
    int pinSensor;
    int initTime;
    int val;
    bool checkEndTime(int actualTime);
public:
    ProximityTask(int pinSensor);
    void init(int period);
    void tick();
};

#endif