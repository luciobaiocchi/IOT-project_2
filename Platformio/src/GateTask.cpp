#include "GateTask.h"
#include "Arduino.h"
#include "GateButton.h"

GateTask::GateTask(int button1Pin, int button2Pin, int pinServo, ContainerProp& container, LCDManager& lcdManager) 
    : container(container) {  
    open = new GateButton(button1Pin);
    close = new GateButton(button2Pin);
    gate = new Gate(pinServo, lcdManager); 
}

void GateTask::init(int period) {
    Task::init(period);
    gate->closeGate();
}

void GateTask::tick() {
    
}
