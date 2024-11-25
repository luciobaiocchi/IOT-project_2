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
    //Serial.println("LCD cleared");
    lcd->noBacklight();
    this->lcdStatus = false;
    //Serial.println("msleep");
}

void LCDManager::wakeUp(){
    lcd->backlight();  
    //Serial.println("mwake");
    lcd->clear(); 
    lcd->print(this->messageToDisplay.substring(0, 16));
    lcd->setCursor(0, 1);
    lcd->print(this->messageToDisplay.substring(16, this->messageToDisplay.length())); 
    lcd->setCursor(0, 0);
    delay(50);
    this->lcdStatus = true;
}

bool LCDManager::isLcdOn(){
    return this->lcdStatus;
}

void LCDManager::setLcd(LiquidCrystal_I2C* lcd){
    this->lcd = lcd;
}





