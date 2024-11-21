#ifndef __CONTAINERPROP__
#define __CONTAINERPROP__
#include "Arduino.h"
#include "Costants.h"
#include "LCDManager.h"

class ContainerProp {
public: 
  ContainerProp();
  ContainerProp(LCDManager lcdManager);
  bool genericAllarm();
  void setWasteLevel(int level);
  void setTempLevel(int level);
  void setAllarm(bool state);
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
