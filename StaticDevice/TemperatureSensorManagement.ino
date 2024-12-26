void SetupTemperatureSensor(){
  pinMode(INPUTPIN_TEMPERATURE, INPUT_PULLUP);
  oneWire = OneWire(INPUTPIN_TEMPERATURE);
  sensors = DallasTemperature(&oneWire);
}