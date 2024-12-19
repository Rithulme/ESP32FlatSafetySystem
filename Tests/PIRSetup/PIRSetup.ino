const int INPUTPIN_PIR = 13;
const int delayNoMovement = 20000;
const int detectionAlarmDelay = 10000;

bool alarmNoMovement = false;
bool alarmMovement = false;
bool contactBroken = true;
bool alarmDelayStarted = false;


void setup() {
  Serial.begin(115200);
  setupPir();

  

  
}

void loop() {
    managePir();
}
