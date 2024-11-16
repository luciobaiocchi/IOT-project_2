#include <Arduino.h>
#include "Button.h"


export bool allarm;

Button::Button(int pin){
    this->pin = pin;
    pinMode(pin, INPUT);     
} 
  
bool Button::isPressed(){
    return digitalRead(pin) == HIGH;
}

bool Button::canBePressed(){
    if (allarm == false) {                
        return true;
    } else {
        return false;
    }
}

