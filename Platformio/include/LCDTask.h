#ifndef __LCDTASK__
#define __LCDTASK__

#include "Task.h"
#include <LiquidCrystal_I2C.h> 
#include <WString.h>


extern int currentState; 

class LCDTask: public Task {
private:
    int LCD_state;
    LiquidCrystal_I2C* lcd; 
    const String LCD_Strings[5] = {
        "PRESS OPEN TO ENTER WASTE",
        "PRESS CLOSE WHEN DONE",
        "WASTE RECEIVED",
        "CONTAINER FULL",
        "PROBLEM DETECTED"
    };

    
public:
    LCDTask();
    void init(int period);
    void tick();
    void modifiedPrint();
};

#endif