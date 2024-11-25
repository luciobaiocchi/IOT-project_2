#include "Arduino.h"
#include "AllarmTask.h"
#include "DHT.h"
#include "Costants.h"
#include "Task.h"
#include "ContainerProp.h"

#define DHTPIN 6
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

AllarmTask :: AllarmTask(int pinTemp, ContainerProp container){
    Serial.begin(9600);
    this->pinTemp = pinTemp;
    this->container = container;
    pinMode(pinTemp, INPUT);
}

void AllarmTask::init(int period){
    Task::init(period);
    dht.begin(); 
}

void AllarmTask::tick(){
    float t = dht.readTemperature();
    if (isnan(t)) {
        Serial.println("Failed to read from DHT sensor!");
    } else {
        Serial.print("Temperature: ");
        Serial.println(t);
        this->container.setTempLevel(t);
    }
    Serial.println("tick");
}


