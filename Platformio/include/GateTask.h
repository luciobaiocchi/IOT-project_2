#ifndef __GATETASK__
#define __GATETASK__

#include "Task.h"
#include "Button.h"
#include "Costants.h"
#include "Gate.h"


extern int currentState;

class GateTask: public Task {
public:
  GateTask(int button1Pin, int button2Pin, Gate gate);  
  void init(int period);  
  void tick();
  void openGate();
  void closeGate();
private:
  Gate* gate;
  Button* open;
  Button* close;
};

#endif
