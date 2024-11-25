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
    if (messageDisplayed != lcdManager.getMessage()) {
        messageDisplayed = lcdManager.getMessage();
        modifiedPrint(messageDisplayed);
    }
}

void LCDTask::modifiedPrint(String msg) {
    //Serial.println("modifiedMessge");
    lcd->clear(); 
    lcd->print(msg.substring(0, 16));
    lcd->setCursor(0, 1);
    lcd->print(msg.substring(16, msg.length())); 
    lcd->setCursor(0, 0);
    delay(50);
}
