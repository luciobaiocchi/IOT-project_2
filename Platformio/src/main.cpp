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



Scheduler scheduler;

void setup() {
  Serial.begin(9600);
  scheduler.init(50);

  LCDManager lcdManager;
  ContainerProp container(lcdManager);


  /* Tasks initialization*/
  Task* gateTask = new GateTask(8, 9, 5, container, lcdManager);
  gateTask->init(150);

  Task* lcdTask = new LCDTask(lcdManager);
  lcdTask->init(200);

  Task* ledTask = new LedTask(4, 5, container);
  ledTask->init(300);
/* 
  Task* proxTask = new ProximityTask(2);
  proxTask->init(200);

  Task* serialCommTask = new SerialCommTask(container);
  serialCommTask->init(250);
  
  Task* wasteLevelTast = new WasteLevelTask(12, 11, container);
  wasteLevelTast->init(400);

  Task* allarmTask = new AllarmTask(A5, container);
  wasteLevelTast->init(300);

  
  scheduler.addTask(proxTask);
  scheduler.addTask(serialCommTask);
  scheduler.addTask(wasteLevelTast);
  scheduler.addTask(allarmTask); */
  scheduler.addTask(gateTask);
  scheduler.addTask(lcdTask);
  scheduler.addTask(ledTask);

}

void loop() {
  scheduler.schedule();
}

