void setupPir(){
  pinMode(INPUTPIN_PIR, INPUT_PULLDOWN);
}

void managePir(){
  static unsigned long lastDetection;
  if(digitalRead(INPUTPIN_PIR)){
    lastDetection = millis();
    checkMovement();
    //Serial.println("Detected PIR signal");
  }

  checkNoMovement(lastDetection);
  
}

void checkNoMovement(unsigned long lastDetection){
  if((millis() - lastDetection) > delayNoMovement){
    //Serial.println("Too long no movement");
    alarmNoMovement = true;
  }
}

void checkMovement(){
  if(contactBroken){
    Serial.println("Alarm Movement");
    alarmDelayStarted = true;
  }
}