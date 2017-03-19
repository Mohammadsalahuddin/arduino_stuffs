#include <Wire.h>
#include "MAX30100_PulseOximeter.h"

#include <ESP8266WiFi.h>
#include <ThingerESP8266.h>



#define USERNAME "Salah_Uddin"
#define DEVICE_ID "linkit"
#define DEVICE_CREDENTIAL "e@Mv@jdKYIRm"

#define SSID "Bangladesh"
#define SSID_PASSWORD "tomarnani"

ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

//pulse

float bpm;
float spo2;


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

//end pulse


void setup() {
  pinMode(BUILTIN_LED, OUTPUT);

  thing.add_wifi(SSID, SSID_PASSWORD);
//pulse

 // Initializing serial port for debugging purposes
  Serial.begin(115200);
  delay(10);
  Wire.begin(D3, D4);  //SDA   SCL
  Wire.setClock(100000);
  delay(10);

    // Initialize the PulseOximeter instance and register a beat-detected callback
    pox.begin();
    pox.setOnBeatDetectedCallback(onBeatDetected);

//end pulse

  

  // digital pin control example (i.e. turning on/off a light, a relay, configuring a parameter, etc)
  thing["led"] << digitalPin(BUILTIN_LED);

  // resource output example (i.e. reading a sensor value)
  thing["millis"] >> outputValue(millis());
  thing["spo2"] >> [](pson& out){out= spo2;};
  thing["bpm"] >> [](pson& out){out =  bpm ;};

  // more details at http://docs.thinger.io/arduino/
}

void loop() {
  thing.handle();
  //pulse
   // Make sure to call update as soon as possible
    pox.update();

    // Asynchronously dump heart rate and oxidation levels to the serial, and publish to Firebase
    // For both, a value of 0 means "invalid"
    if (millis() - tsLastReport > REPORTING_PERIOD_MS) {

        bpm = pox.getHeartRate();
        spo2 = pox.getSpO2();

        //Serial.print("Heart rate:");
        //Serial.print(bpm);
       // Serial.print("bpm / SpO2:");
       // Serial.print(spO2);
       // Serial.println("%");

        tsLastReport = millis();

    }
    //end pulse
}
