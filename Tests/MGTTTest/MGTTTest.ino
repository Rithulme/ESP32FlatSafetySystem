#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "thosar";
const char* password = "BogVer88";

//const char* mqtt_server = "mqtt://192.168.0.183";
IPAddress mqtt_server(192, 168, 0, 183);
const char* topic = "mqttTest/inputSwitch";

WiFiClient espClient;
PubSubClient client(espClient);
String client_id="";

void setup() {
  Serial.begin(115200);

  setup_wifi();
  client_id = generateClientID();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
