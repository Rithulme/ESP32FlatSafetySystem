#include <OneWire.h>
#include <DallasTemperature.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

TaskHandle_t TaskOtherThread;

//Pin settings
const int INPUTPIN_PIR = 13;
const int INPUTPIN_TEMPERATURE = 20;

const int OUTPUTPIN_BUZZER = 18;

//device settings
const char* ssid = "thosar";
const char* password = "BogVer88";
const unsigned long delayNoMovement = 10000;
const unsigned long alarmTriggerDelay = 3000;
IPAddress mqtt_server(192, 168, 0, 183);
const char* mobileDeviceTopic = "mqttFlatSafetySystem/inputMobileDevice";

//Sensor and communication objects
OneWire oneWire;
DallasTemperature sensors;
String clientId;
WiFiClient espClient;
PubSubClient client(espClient);

//bools managing actions
bool alarmNoMovement = false;
bool alarmDelayStarted = false;
bool contactBroken = false;
bool flagActivateAlarm = false;
bool flagPanicButtonTriggered = false;
bool flagIntrusionDetected = false;
bool resetAlarm = false;

JsonDocument mobileDeviceData;

//alarm State
int alarmState = 0;
int previousAlarmState = 0;

void setup() {
  Serial.begin(115200);
  pinMode(OUTPUTPIN_BUZZER, OUTPUT);
  //todo make setup method for mqtt
  clientId = generateClientID();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  setup_wifi();
  setupPir();
  setupMultithreading();
  SetupTemperatureSensor();

}

void loop() {
  reconnect();
  client.loop();
  managePir();

  managAlarmState();
  outputmanagement();
}
