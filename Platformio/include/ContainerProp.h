#ifndef __CONTAINERPROP__
#define __CONTAINERPROP__
#include "Arduino.h"
#include "Costants.h"
#include "LCDManager.h"

class ContainerProp {
public: 
  ContainerProp(LCDManager& lcdManager);
  bool genericAllarm();
  void setWasteLevel(int level);
  void setTempLevel(int level);
  void setAllarm(bool state);
  int getWasteLevel();
  int getTempLevel();
  void restoreAllarm();
  void emptyContainer();
  bool isFull();
  bool isAllarmOn();
  bool gateToBeEmptied();
private:
  LCDManager& lcdManager;
  int contLevel;
  int tempLevel;
  bool full;
  bool allarm;
  bool toBeEmptied;
};

#endif
