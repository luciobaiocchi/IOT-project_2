#include "LCDManager.h"

LCDManager::LCDManager(){
    messageToDisplay = LCD_1;
}

void LCDManager::setMessage(String msg){
    messageToDisplay = msg;
}

String LCDManager::getMessage(){
    return messageToDisplay;
}
