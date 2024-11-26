#include "LCDManager.h"

LCDManager::LCDManager(){
    //Serial.begin(9600);
    this->lcdStatus = true;
    currentMessage = "";
    lcd = new LiquidCrystal_I2C(0x27, 16, 2);
    lcd->init();
    lcd->backlight();
}

void LCDManager::setMessage(String msg){
    currentMessage = msg;
    lcd->clear(); 
    lcd->print(msg.substring(0, 16));
    lcd->setCursor(0, 1);
    lcd->print(msg.substring(16, msg.length())); 
    lcd->setCursor(0, 0);
    delay(50);
}

String LCDManager::getMessage(){
    return currentMessage;
}

void LCDManager::sleep(){
    lcd->clear();
    lcd->noBacklight();
}

void LCDManager::wakeUp(){
    setMessage(currentMessage);
}
