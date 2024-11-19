#include "Arduino.h"
#include "Scheduler.h"
#include "GateTask.h"
#include "LCDTask.h"
#include "Costants.h"
#include "LedTask.h"
#include "ProximityTask.h"
#include "SerialCommTask.h"


int currentState;


Scheduler scheduler;

void setup() {
  currentState = GATE_AVAILABLE;
  Serial.begin(9600);
  scheduler.init(50);


  /* Tasks initialization*/
  Task* gateTask = new GateTask(5, 8, 9);
  gateTask->init(100);

  Task* lcdTask = new LCDTask();
  lcdTask->init(150);

  Task* ledTask = new LedTask(3, 4);
  ledTask->init(200);

  Task* proxTask = new ProximityTask(2);
  proxTask->init(200);

  Task* serialCommTask = new SerialCommTask();
  serialCommTask->init(250);
  

  scheduler.addTask(gateTask);
  scheduler.addTask(lcdTask);
  scheduler.addTask(ledTask);
  scheduler.addTask(proxTask);
  scheduler.addTask(serialCommTask);
  
}

void loop() {
  scheduler.schedule();
}

