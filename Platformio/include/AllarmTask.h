#ifndef __GATETASK__
#define __GATETASK__
#define DHTPIN A5
#define DHTTYPE DHT11

#include "Task.h"
#include "Costants.h"
#include "DHT.h"

extern int currentState;
DHT dht(DHTPIN, DHTTYPE);

class AllarmTask: public Task {
public:
    AllarmTask(int pinTemp);  
    void init(int period);  
    void tick();
    bool isTempOverMax();
private:
    long timeGateOpen;
    int pinTemp;
};

#endif
