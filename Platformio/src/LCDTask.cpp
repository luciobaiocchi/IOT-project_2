#include "LCDTask.h"

LCDTask::LCDTask(LCDManager& manager) : lcdManager(manager) { 
    lcd = new LiquidCrystal_I2C(0x27, 16, 2);
    lcd->init();
    lcd->setCursor(0, 0);
    lcd->backlight();
    lcdManager.setLcd(lcd);
    messageDisplayed = "";
}

void LCDTask::init(int period) {
    Task::init(period);
}

void LCDTask::tick() {
    /*bool lcdOn = lcdManager.isLcdOn();
    Serial.println(lcdOn);
    //Serial.print("LCD On: ");
    //Serial.println(lcdOn);
    if (!lcdOn){  //spento
        // non entra mai qua 
        //Serial.println("off");
        lcd->clear();
        //Serial.println("LCD cleared");
        lcd->noBacklight();
        //Serial.println("LCD backlight off");
    }else {                      //acceso
        //Serial.println("on");
        messageDisplayed = lcdManager.getMessage();
        modifiedPrint(messageDisplayed);
        lcd->backlight();  
        //Serial.println("LCD backlight on");
    }*/
    if (messageDisplayed != lcdManager.getMessage()) {
        messageDisplayed = lcdManager.getMessage();
        modifiedPrint(messageDisplayed);
    }
}

void LCDTask::modifiedPrint(String msg) {
    lcd->clear(); 
    lcd->print(msg.substring(0, 16));
    lcd->setCursor(0, 1);
    lcd->print(msg.substring(16, msg.length())); 
    lcd->setCursor(0, 0);
    delay(50);
}
