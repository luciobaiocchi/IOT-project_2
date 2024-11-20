#ifndef __ALLARMTASK__
#define __ALLARMTASK__


#include "Task.h"
#include "Costants.h"
#include "ContainerProp.h"



class AllarmTask: public Task {
public:
    AllarmTask(int pinTemp, ContainerProp container);  
    void init(int period);  
    void tick();
    bool isTempOverMax();
private:
    int pinTemp;
    ContainerProp container;
};

#endif
