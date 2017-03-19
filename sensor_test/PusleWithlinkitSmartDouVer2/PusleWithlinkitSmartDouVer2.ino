//use two IIC sensor together Pulse sensor and BME 208 sensor



#include <Wire.h>
#include <MAX30100_PulseOximeter.h>

#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define REPORTING_PERIOD_MS     1000

// PulseOximeter is the higher level interface to the sensor. Let's create the object here
PulseOximeter pox;

int bpm;
int spo2;
float temp;





uint32_t tsLastReport = 0;
volatile boolean heartBeatDetected = false;

// Callback (registered below) fired when a pulse is detected
void onBeatDetected()
{
    heartBeatDetected = true;
    Serial.println("Beat!");
}

//pulse sensor callback function
void measured_pulse(){
    // Make sure to call update as fast as possible
    pox.update();
    if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
      bpm = pox.getHeartRate();
      spo2 = pox.getSpO2();
      temp = pox.getTemperature();
      tsLastReport = millis();
    }
    
}



void setup() {
  Serial.begin(115200);
  delay(10);
  // Initialize the PulseOximeter instance and register a beat-detected callback
  pox.begin();
  pox.setOnBeatDetectedCallback(onBeatDetected);
  

}

void loop() {
  measured_pulse();
  Serial.println("The pulse sensor data :");
  Serial.println (bpm);
  Serial.println(spo2);
  Serial.println(temp);
  
}

