void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect(client_id.c_str())) {
      Serial.println("connected");
      client.subscribe(topic);
      Serial.print("Subscribed to topic: ");
      Serial.println(topic);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.println(topic);  
}

String generateClientID() {
  // Generate a unique client ID based on the ESP32's MAC address
  uint8_t mac[6];
  WiFi.macAddress(mac);
  String macString = "ESP32_";
  for (int i = 0; i < 6; i++) {
    if (mac[i] < 16) macString += "0"; // Add leading zero if needed
    macString += String(mac[i], HEX);
  }
  macString.toUpperCase();
  return macString;
}