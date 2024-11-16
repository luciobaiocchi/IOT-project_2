#ifndef __BUTTON__
#define __BUTTON__

class Button {
    int pin;
 
public: 
    bool isPressed();
    bool canBePressed();

};

#endif