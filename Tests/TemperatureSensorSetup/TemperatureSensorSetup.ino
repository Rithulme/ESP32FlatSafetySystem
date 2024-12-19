#include <OneWire.h>
#include <DallasTemperature.h>

TaskHandle_t TaskOtherThread;

const int INPUTPIN_TEMPERATURE = 13;
OneWire oneWire;
DallasTemperature sensors;

void setup() {
  Serial.begin(115200);
  SetupTemperatureSensor();
  setupMultithreading();
}

void loop() {

}
