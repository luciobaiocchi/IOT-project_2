#include "LCDTask.h"
#include "Arduino.h"
#include "Costants.h"
#include "Led.h"



LCDTask::LCDTask(){
    lcd = new LiquidCrystal_I2C(0x27, 16, 2);
    lcd->init();
    lcd->setCursor(0, 0);
    lcd->backlight();


}

void LCDTask::init(int period){
    Task::init(period);
    LCD_state = -1;
}

void LCDTask::tick(){
    
    if (LCD_state != currentState){
        LCD_state = currentState;
        lcd->clear();  
        modifiedPrint();
    }
    
}

void LCDTask::modifiedPrint() {
    String msg = LCD_Strings[currentState-1];
    lcd->print(msg.substring(0, 16));
    lcd->setCursor(0, 1);
    lcd->print(msg.substring(16, msg.length()));
    lcd->setCursor(0, 0);
}
