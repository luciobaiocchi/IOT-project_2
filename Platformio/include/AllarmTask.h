#ifndef __GATETASK__
#define __ALLARMTASK__
#define DHTPIN A5
#define DHTTYPE DHT11

#include "Task.h"
#include "Costants.h"
#include "DHT.h"
#include "ContainerProp.h"

extern int currentState;
DHT dht(DHTPIN, DHTTYPE);

class AllarmTask: public Task {
public:
    AllarmTask(int pinTemp, ContainerProp container);  
    void init(int period);  
    void tick();
    bool isTempOverMax();
private:
    long timeGateOpen;
    int pinTemp;
    ContainerProp container;
};

#endif
