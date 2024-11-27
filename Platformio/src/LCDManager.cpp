#include "LCDManager.h"

LCDManager::LCDManager(){
    //Serial.begin(9600);
    currentMessage[0] = '\0';
    lcd = new LiquidCrystal_I2C(0x27, 16, 2);
    lcd->init();
    lcd->backlight();
}

void LCDManager::setMessage(const char* msg) {
    if (strcmp(currentMessage, msg) != 0)
    {
        // Copia massimo 32 caratteri (16 per riga) con terminatore
    strncpy(currentMessage, msg, sizeof(currentMessage) - 1);
    currentMessage[sizeof(currentMessage) - 1] = '\0'; // Assicura il terminatore

    lcd->clear();

    // Prepara righe per LCD
    char line1[17] = {'\0'}; // Riga 1 (16 caratteri + terminatore)
    char line2[17] = {'\0'}; // Riga 2 (16 caratteri + terminatore)

    // Copia la prima e la seconda riga
    strncpy(line1, msg, 16);
    if (strlen(msg) > 16) {
        strncpy(line2, msg + 16, 16);
    }

    // Stampa sulle due righe dell'LCD
    lcd->setCursor(0, 0);
    lcd->print(line1);
    lcd->setCursor(0, 1);
    lcd->print(line2);

    // Stampa su Serial Monitor
    Serial.println(currentMessage);
    }
    
    
}


String LCDManager::getMessage(){
    return currentMessage;
}

void LCDManager::sleep(){
    lcd->clear();
    lcd->noBacklight();
}

void LCDManager::wakeUp(){
    setMessage(currentMessage);
}
