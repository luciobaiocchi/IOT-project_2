#include "GateTask.h"
#include "Arduino.h"
#include "GateButton.h"
#include "Gate.h"

GateTask::GateTask(int button1Pin, int button2Pin, ContainerProp& container, LCDManager& lcdManager, Gate& gate) 
    : container(container), lcdManager(lcdManager), gate(gate) {  
    open = new GateButton(button1Pin);
    close = new GateButton(button2Pin);
    timer = TickCounter();
}

void GateTask::init(int period) {
    Task::init(period);
}

void GateTask::tick() {
    if (!container.genericAllarm()){
        switch (gate.getState()){
        case AVAILABLE:
            handleAvailableState();
            break;
        case OPEN:
            handleOpenState();
            break;
        case NOT_AVAILABLE:
            handleNotAvaiableState();
            break;
        }
    } else {
        gate.closeGate();
    }
    
}

void GateTask::handleAvailableState(){
    lcdManager.setMessage(LCD_1);
    if (open->isPressed()){
        lcdManager.setMessage(LCD_2);
        timer.startTimer(30);
        gate.openGate();
    }
}

void GateTask::handleOpenState(){
    timer.dec();
    if (timer.isTimeElapsed() || close->isPressed()){
        lcdManager.setMessage(LCD_3);
        gate.closeGate();
        timer.startTimer(50);
    }
}

void GateTask::handleNotAvaiableState(){
    timer.dec();
    if (timer.isTimeElapsed()){
        lcdManager.setMessage(LCD_1);
        gate.setState(1);
    }
}
