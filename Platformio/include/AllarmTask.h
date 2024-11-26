#ifndef __ALLARMTASK__
#define __ALLARMTASK__


#include "Task.h"
#include "Costants.h"
#include "ContainerProp.h"
#include "LCDManager.h"


class AllarmTask: public Task {
public:
    AllarmTask(int pinTemp, ContainerProp container, LCDManager& lcdManager);  
    void init(int period);  
    void tick();
private:
    int pinTemp;
    ContainerProp container;
    LCDManager& lcdManager;
};

#endif
