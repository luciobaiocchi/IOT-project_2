#ifndef __SERIALCOMMUNICATION__
#define __SERIALCOMMUNICATION__

#include "Task.h"
#include "Costants.h"
#include "MsgService.h"
#include "ContainerProp.h"

extern int currentState;

class SerialCommTask : public Task {

public:
  SerialCommTask(ContainerProp container);  
  void init(int period);  
  void tick();
  void receive();
  void send();
private:
  ContainerProp container;
};


#endif