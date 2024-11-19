#ifndef __SERIALCOMMUNICATION__
#define __SERIALCOMMUNICATION__

#include "Task.h"
#include "Costants.h"
#include "MsgService.h"

extern int currentState;

class SerialCommTask : public Task {

public:
  SerialCommTask();  
  void init(int period);  
  void tick();
  void receive();
  void send();

};


#endif