#ifndef __GATETASK__
#define __GATETASK__

#include "Task.h"
#include "Button.h"
#include "Costants.h"
#include "Gate.h"
#include "ContainerProp.h"
#include "LCDManager.h"
#include "TickCounter.h"

class GateTask : public Task {
public:
    GateTask(int button1Pin, int button2Pin, int pinServo, ContainerProp& container, LCDManager& lcdManager);  
    void init(int period);  
    void tick();
    TickCounter timer;
private:
    Gate* gate;
    ContainerProp& container;  
    LCDManager& lcdManager;
    Button* open;
    Button* close;
};

#endif
