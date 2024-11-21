#ifndef __LCDTASK__
#define __LCDTASK__

#include "Arduino.h"
#include "Task.h"
#include <LiquidCrystal_I2C.h> 
#include <WString.h>
#include "ContainerProp.h"
#include "LCDManager.h"


extern int currentState; 

class LCDTask: public Task {
public:
    LCDTask(LCDManager manager);
    void init(int period);
    void tick();
    void modifiedPrint(String msg);

private:
    String messageDisplayed;
    LiquidCrystal_I2C* lcd; 
    LCDManager lcdManager;
    
    

};

#endif