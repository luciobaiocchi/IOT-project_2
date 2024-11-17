#ifndef __GATETASK__
#define __GATETASK__

#include "Task.h"
#include "Servo.h"
#include "Button.h"
#include "Costants.h"

extern int currentState;

class GateTask: public Task {
public:
  GateTask(int servo, int button1Pin, int button2Pin);  
  void init(int period);  
  void tick();
  void openGate();
  void closeGate();
private:
  Servo servo;
  Button* open;
  Button* close;
  int servoPin;
  long timeGateOpen;
  long waitTheT2;
};

#endif
