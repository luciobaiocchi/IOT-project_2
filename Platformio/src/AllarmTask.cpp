#include "Arduino.h"
#include "AllarmTask.h"
#include "DHT.h"
#include "Costants.h"
#include "Task.h"
#include "ContainerProp.h"

AllarmTask::AllarmTask(int pinTemp, ContainerProp& container, LCDManager& lcdManager) : container(container), lcdManager(lcdManager) {
    this->pinTemp = pinTemp;
}

void AllarmTask::init(int period){
    Task::init(period);
}

void AllarmTask::tick(){
    int temp_adc_val;
    float temp_val;
    float referenceVoltage = 5.0; // Cambia a 3.3V se il tuo Arduino usa 3.3V come riferimento

    // Leggi più campioni per ridurre il rumore
    long sum_adc = 0;
    const int samples = 10; // Numero di campioni
    for (int i = 0; i < samples; i++) {
        sum_adc += analogRead(pinTemp);
        //delay(10); // Breve ritardo tra letture per evitare rumore
    }

    temp_adc_val = sum_adc / samples; // Media dei campioni

    // Conversione in tensione e calcolo della temperatura
    temp_val = (temp_adc_val * referenceVoltage) / 1023.0; // Converti in tensione
    temp_val = temp_val * 100.0; // LM35: 10mV per grado Celsius
    this->container.setTempLevel(temp_val);
    // Stampa temperatura
    Serial.print("Temperatura = ");
    Serial.print(temp_val, 2); // Stampa con 2 decimali
    Serial.println(" °C");
}