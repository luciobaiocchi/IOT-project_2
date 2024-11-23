#include "LCDManager.h"

LCDManager::LCDManager(){
    Serial.begin(9600);
    this->lcdStatus = true;
    messageToDisplay = LCD_1;
}

void LCDManager::setMessage(String msg){
    messageToDisplay = msg;
}

String LCDManager::getMessage(){
    return messageToDisplay;
}

void LCDManager::sleep(){
    lcd->clear();
    Serial.println("LCD cleared");
    lcd->noBacklight();
    this->lcdStatus = false;
    Serial.println("msleep");
}

void LCDManager::wakeUp(){
    lcd->backlight();  
    Serial.println("mwake");
    this->lcdStatus = true;
}

bool LCDManager::isLcdOn(){
    return this->lcdStatus;
}

void LCDManager::setLcd(LiquidCrystal_I2C* lcd){
    this->lcd = lcd;
}





