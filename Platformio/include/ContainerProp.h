#ifndef __CONTAINERPROP__
#define __CONTAINERPROP__

#include "Costants.h"

class ContainerProp {
 
public: 
  ContainerProp();
  virtual bool setWasteLevel(int level) = 0;
  virtual bool setAllarm(bool state) = 0;
  virtual int getWasteLevel() = 0;
  virtual bool isFull() = 0;
  virtual bool isAllarmOn() = 0;
private:
  int contLevel;
  bool allarm;
};

#endif
