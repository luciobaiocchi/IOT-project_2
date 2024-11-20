#ifndef __GATETASK__
#define __GATETASK__

#include "Task.h"
#include "Button.h"
#include "Costants.h"
#include "Gate.h"
#include "ContainerProp.h"



class GateTask: public Task {
public:
  GateTask::GateTask(int button1Pin, int button2Pin, int pinServo, ContainerProp container);  
  void init(int period);  
  void tick();
private:
  Gate* gate;
  ContainerProp container;
  Button* open;
  Button* close;
};

#endif
