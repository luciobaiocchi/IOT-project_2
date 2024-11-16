#include "GateTask.h"



GateTask::GateTask(int servoPin, int button1Pin, int button2Pin){
    this->servoPin = servoPin;
    button1 = Button(button1Pin);
    button2 = Button(button2Pin);

}


void GateTask::init(int period){
    Task::init(period);
    servo = Servo();
    servo.attach(servoPin);
    servo.write(0);
    servo.detach();
}


void GateTask::tick(){
    if (button1.canBePressed() && !button1.isPressed()){
        servo.attach(servoPin);
        servo.write(90);
        servo.detach();
    }else if(button2.canBePressed() && !button2.isPressed()){
        servo.attach(servoPin);
        servo.write(0);
        servo.detach();

    }
    
}
