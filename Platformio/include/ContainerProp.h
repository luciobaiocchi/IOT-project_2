#ifndef __CONTAINERPROP__
#define __CONTAINERPROP__
#include "Arduino.h"
#include "Costants.h"
#include "LCDManager.h"

class ContainerProp {
public: 
  ContainerProp(LCDManager lcdManager);
  bool genericAllarm();
  bool setWasteLevel(int level);
  bool setAllarm(bool state);
  int getWasteLevel();
  bool isFull();
  bool isAllarmOn();
private:
  int contLevel;
  bool allarm;
  LCDManager lcdManager;
};

#endif
