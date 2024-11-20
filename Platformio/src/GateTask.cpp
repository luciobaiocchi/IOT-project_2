#include "GateButton.h"
#include "Arduino.h"
#include "GateTask.h"

GateTask::GateTask(int button1Pin, int button2Pin, Gate gate){
    open = new GateButton(button1Pin);
    close = new GateButton(button2Pin);
    gate = gate;
}

void GateTask::init(int period){
    Task::init(period);
    gate->closeGate();
}

void GateTask::tick(){
    case GATE_AVAILABLE:{
        if (open->isPressed()){
            openGate();
        }
        break;
    }
    case GATE_IS_OPEN:{
        if (close->isPressed() || ){
            closeGate();
            timeGateOpen = 0;
        }
        break;
    }
    case GATE_AFTER_CLOSURE:{
        if ((){
            currentState = GATE_AVAILABLE;
            waitTheT2 = 0;
        }
    }
    default:
        break;
    }
    if (open->isPressed() && !container.genericAlarm() && gate->timeAfterCloseElapsed()){
        gate->openGateButton();
    }else if (close->isPressed() || gate->timeOpenElapsed()){
        gate->closeGate();
    }
    
    
}

void GateTask::openGate()
{
    currentState = GATE_IS_OPEN;
    Serial.println("OPEN");
    timeGateOpen = millis();
    //servo.attach(servoPin);
    servo.write(2250);
    //servo.detach();
}

void GateTask::closeGate()
{
    currentState = GATE_AFTER_CLOSURE;

    Serial.println("CLOSE");
    //delay(1000);
    //servo.attach(servoPin);
    servo.write(750);
    //servo.detach();
    waitTheT2 = millis();
}

