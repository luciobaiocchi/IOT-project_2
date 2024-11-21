#include "GateButton.h"
#include "Arduino.h"
#include "GateTask.h"

GateTask::GateTask(int button1Pin, int button2Pin, int pinServo, ContainerProp container, LCDManager lcdManager){
    open = new GateButton(button1Pin);
    close = new GateButton(button2Pin);
    gate = new Gate(pinServo, lcdManager);
    this->container = container;
}

void GateTask::init(int period){
    Task::init(period);
    gate->closeGate();
}

void GateTask::tick(){
    if (open->isPressed() && !container.genericAllarm() && gate->timeAfterCloseElapsed()){
        gate->openGateButton();
    }else if (close->isPressed() || gate->timeOpenElapsed()){
        gate->closeGate();
    }
    
}

