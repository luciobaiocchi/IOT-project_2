#include "GateTask.h"
#include "Arduino.h"
#include "GateButton.h"
#include "Gate.h"

GateTask::GateTask(int button1Pin, int button2Pin, int pinServo, ContainerProp& container, LCDManager& lcdManager) 
    : container(container) {  
    open = new GateButton(button1Pin);
    close = new GateButton(button2Pin);
    gate = new Gate(pinServo, lcdManager); 
    timer = TickCounter();
}

void GateTask::init(int period) {
    Task::init(period);
}

void GateTask::tick() {
    if (!container.genericAllarm()){
        switch (gate->getState()){
        case 1:
            if (open->isPressed()){
                timer.startTimer(30);
                gate->openGate();
            }
            break;
        case 3:
            timer.dec();
            if (timer.isTimeElapsed()){
                gate->setState(1);
            }
            break;
        case 2:
            timer.dec();
            if (timer.isTimeElapsed() || close->isPressed()){
                gate->closeGate();
                timer.startTimer(50);
            }
            break;
            
        default:
            break;
        }
    } else{
        gate->allarmClosure();
    }
    
}
