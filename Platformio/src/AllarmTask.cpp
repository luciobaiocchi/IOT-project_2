#include "Arduino.h"
#include "AllarmTask.h"
#include "DHT.h"
#include "Costants.h"
#include "Task.h"
#include "ContainerProp.h"

#define DHTPIN A5
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

AllarmTask :: AllarmTask(int pinTemp, ContainerProp container){
    this->pinTemp = pinTemp;
    this->container = container;
    pinMode(pinTemp, INPUT);
}

void AllarmTask::init(int period){
    Task::init(period);
}

void AllarmTask::tick(){
    int t = dht.readTemperature();
    this->container.setTempLevel(t);
}


