#include <Arduino.h>
#include "Scheduler.h"
#include "GateTask.h"


bool allarm;
bool gateIsOpening;


Scheduler scheduler;

void setup() {
  scheduler.init(50);

  allarm = false;

  /* Tasks initialization*/
  Task* gateTask = new GateTask(9, 8);
  gateTask->init(100);



  scheduler.addTask(gateTask);
  
}

void loop() {
  scheduler.schedule();
}

