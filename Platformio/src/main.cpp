#include "Arduino.h"
#include "Scheduler.h"
#include "GateTask.h"
#include "LCDTask.h"
#include "Costants.h"
#include "LedTask.h"
#include "ProximityTask.h"
#include "SerialCommTask.h"
#include "ContainerProp.h"
#include "WasteLevelTask.h"
#include "AllarmTask.h"
#include "LCDManager.h"

int currentState;


Scheduler scheduler;

void setup() {
  currentState = GATE_AVAILABLE;
  Serial.begin(9600);
  scheduler.init(50);

  LCDManager lcdManager = LCDManager();
  ContainerProp container = ContainerProp(lcdManager);


  /* Tasks initialization*/
  Task* gateTask = new GateTask(7, 8, 5, container, lcdManager);
  gateTask->init(100);

  Task* lcdTask = new LCDTask(lcdManager);
  lcdTask->init(150);

  Task* ledTask = new LedTask(3, 4, container);
  ledTask->init(200);

  Task* proxTask = new ProximityTask(2);
  proxTask->init(200);

  Task* serialCommTask = new SerialCommTask(container);
  serialCommTask->init(250);
  
  Task* wasteLevelTast = new WasteLevelTask(12, 11, container);
  wasteLevelTast->init(100);

  Task* allarmTask = new AllarmTask(A5, container);
  wasteLevelTast->init(100);

  scheduler.addTask(gateTask);
  scheduler.addTask(lcdTask);
  scheduler.addTask(ledTask);
  scheduler.addTask(proxTask);
  scheduler.addTask(serialCommTask);
  scheduler.addTask(wasteLevelTast);
  scheduler.addTask(allarmTask);
}

void loop() {
  scheduler.schedule();
}

