#ifndef __WASTELEVEL__
#define __WASTELEVEL__
#define DHTPIN A5
#define DHTTYPE DHT11

#include "Task.h"
#include "Costants.h"
#include "ContainerProp.h"

extern int currentState;

class WasteLevelTask: public Task {
public:
    WasteLevelTask(int pinSensor, ContainerProp container);  
    void init(int period);  
    void tick();
    bool isFull();
private:
    long timeGateOpen;
    int pinSensor;
    ContainerProp container;
};

#endif
