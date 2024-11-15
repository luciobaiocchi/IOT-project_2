#include <Arduino.h>
#include "Scheduler.h"

Scheduler scheduler;

void setup() {
  scheduler.init(50);

  /* Tasks initialization*/
  
}

void loop() {
  scheduler.schedule();
}

