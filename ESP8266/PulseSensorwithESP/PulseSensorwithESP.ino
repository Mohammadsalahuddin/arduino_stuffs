//Works with NodeMcu Version 01

#include <Wire.h>
#include "MAX30100_PulseOximeter.h"


#define REPORTING_PERIOD_MS     1000


// PulseOximeter is the higher level interface to the sensor. Let's create the object here
PulseOximeter pox;

uint32_t tsLastReport = 0;
volatile boolean heartBeatDetected = false;

// Callback method will be fired when a pulse is detected
void onBeatDetected()
{
    heartBeatDetected = true;
    Serial.println("Beat!");
}

void setup()
{

  // Initializing serial port for debugging purposes
  Serial.begin(115200);
  delay(10);
  //Wire.begin(D3, D4);  //SDA   SCL
  //Wire.setClock(100000);

    // Initialize the PulseOximeter instance and register a beat-detected callback
    pox.begin();
    pox.setOnBeatDetectedCallback(onBeatDetected);
}

void loop()
{
    // Make sure to call update as soon as possible
    pox.update();

    // Asynchronously dump heart rate and oxidation levels to the serial, and publish to Firebase
    // For both, a value of 0 means "invalid"
    if (millis() - tsLastReport > REPORTING_PERIOD_MS) {

        float bpm = pox.getHeartRate();
        float spO2 = pox.getSpO2();

        Serial.print("Heart rate:");
        Serial.print(bpm);
        Serial.print("bpm / SpO2:");
        Serial.print(spO2);
        Serial.println("%");

        tsLastReport = millis();

    }
}
