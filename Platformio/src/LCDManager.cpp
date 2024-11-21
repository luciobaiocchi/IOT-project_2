#include "LCDManager.h"

LCDManager::LCDManager(){
    messageToDisplay = "";
}

void LCDManager::setMessage(String msg){
    messageToDisplay = msg;
}

String LCDManager::getMessage(){
    return messageToDisplay;
}
