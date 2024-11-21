#ifndef __LCDTASK__
#define __LCDTASK__

#include "Arduino.h"
#include "Task.h"
#include <LiquidCrystal_I2C.h>
#include <WString.h>
#include "ContainerProp.h"
#include "LCDManager.h"

class LCDTask : public Task {
public:
    LCDTask(LCDManager& manager); // Passaggio per riferimento
    void init(int period);
    void tick();
    void modifiedPrint(String msg);

private:
    String messageDisplayed;
    LiquidCrystal_I2C* lcd;
    LCDManager& lcdManager; // Campo membro come riferimento
};

#endif
