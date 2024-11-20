#ifndef __CONTAINERPROP__
#define __CONTAINERPROP__

#include "Costants.h"

class ContainerProp {
public: 
  ContainerProp();
  bool genericAllarm();
  bool setWasteLevel(int level);
  bool setAllarm(bool state);
  int getWasteLevel();
  bool isFull();
  bool isAllarmOn();
private:
  int contLevel;
  bool allarm;
};

#endif
