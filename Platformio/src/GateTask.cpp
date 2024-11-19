#include "GateButton.h"
#include "Arduino.h"
#include "GateTask.h"

GateTask::GateTask(int servoPin, int button1Pin, int button2Pin)
{
    this->servoPin = servoPin;
    open = new GateButton(button1Pin);
    close = new GateButton(button2Pin);
}

void GateTask::init(int period)
{
    Task::init(period);
    waitTheT2 = 0;
    timeGateOpen = 0;
    /* Manca da testare con il servo ma non lo avevo: forse ho importato la libreria sbagliata perchè si bloccava il programma */
    // servo = Servo();
    // servo.attach(servoPin);
    // servo.write(0);
    // servo.detach();
}

void GateTask::tick()
{
    switch (currentState){
    case GATE_AVAILABLE:{
        if (open->isPressed()){
            openGate();
        }
        break;
    }
    case GATE_IS_OPEN:{
        if (close->isPressed() || (millis() - timeGateOpen) >= MAX_TIME_OPEN){
            closeGate();
            timeGateOpen = 0;
        }
        break;
    }
    case GATE_AFTER_CLOSURE:{
        if ((millis() - waitTheT2) >= T2){
            currentState = GATE_AVAILABLE;
            waitTheT2 = 0;
        }
    }
    default:
        break;
    }
}

void GateTask::openGate()
{
    currentState = GATE_IS_OPEN;
    // Serial.println("OPEN");
    timeGateOpen = millis();
    // servo.attach(servoPin);
    // servo.write(90);
    // servo.detach();
}

void GateTask::closeGate()
{
    currentState = GATE_AFTER_CLOSURE;

    Serial.println("CLOSE");
    delay(1000);
    // servo.attach(servoPin);
    // servo.write(0);
    // servo.detach();
    waitTheT2 = millis();
}
