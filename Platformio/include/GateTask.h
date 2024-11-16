#ifndef __GATETASK__
#define __GATETASK__

#include "Task.h"
#include "Servo.h"
#include "Button.h"

class GateTask: public Task {

Servo servo;
Button button1;
Button button2;
int servoPin;


public:
  GateTask(int servo, int button1Pin, int button2Pin);  
  void init(int period);  
  void tick();
};

#endif
