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
  void setTempLevel(int level);
  bool setAllarm(bool state);
  int getWasteLevel();
  int getTempLevel();
  bool isFull();
  bool isAllarmOn();
private:
  int contLevel;
  int tempLevel;
  bool allarm;
  LCDManager lcdManager;
};

#endif
