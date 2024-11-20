#ifndef __WASTELEVEL__
#define __WASTELEVEL__
#define DHTPIN A5
#define DHTTYPE DHT11

#include "Task.h"
#include "Costants.h"

extern int currentState;

class WasteLevelTask: public Task {
public:
    WasteLevelTask(int pinSensor);  
    void init(int period);  
    void tick();
private:
    long timeGateOpen;
    int pinSensor;
};

#endif
