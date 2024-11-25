#ifndef __LCDMANAGER__
#define __LCDMANAGER__

#include "Arduino.h"
#include "Costants.h"
#include "LiquidCrystal_I2C.h"

class LCDManager {
private:
    bool lcdStatus;
    LiquidCrystal_I2C* lcd; 
    String currentMessage;
public:
    LCDManager();
    void setMessage(String msg);
    String getMessage();
    void sleep();
    void wakeUp();
};

#endif