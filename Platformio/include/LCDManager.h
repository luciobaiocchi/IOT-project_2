#ifndef __LCDMANAGER__
#define __LCDMANAGER__

#include "Arduino.h"
#include "Costants.h"

class LCDManager {
private:
    String messageToDisplay;
public:
    LCDManager();
    void setMessage(String msg);
    String getMessage();
    
};

#endif