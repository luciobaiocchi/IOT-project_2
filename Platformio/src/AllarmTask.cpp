#include "Arduino.h"
#include "AllarmTask.h"
#include "DHT.h"
#include "Costants.h"
#include "Task.h"

AllarmTask :: AllarmTask(int pinTemp){
    this->pinTemp = pinTemp;
    pinMode(pinTemp, INPUT);
}

void AllarmTask::init(int period){
    Task::init(period);
}

void AllarmTask::tick(){
    if (isTempOverMax()){
        currentState = TMP_ALLARM;
    }
}

bool AllarmTask::isTempOverMax(){
    int t = dht.readTemperature();
    return(t > MAX_TEMP);
}
