#ifndef __CONTAINERPROP__
#define __CONTAINERPROP__

#include "Costants.h"

class ContainerProp {
public: 
  ContainerProp();
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
};

#endif
