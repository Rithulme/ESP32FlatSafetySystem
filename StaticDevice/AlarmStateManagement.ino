//Alarm states
//0 no alarm: only movement detection
//1 alarm active, movement allowed not when contact broken
//2 alarm active, no movement allowed
//3 alarm triggered, delay started;
//4 alarm sounding

void managAlarmState(){
  static unsigned long intrusionTriggerTime; 
  if (alarmState == 0) {
    if(flagPanicButtonTriggered){
      previousAlarmState = 0;
      alarmState = 4;
      flagPanicButtonTriggered = false;
    }
    else if(flagActivateAlarm)
    {
      previousAlarmState = 0;
      alarmState = 1;
      flagActivateAlarm = false;
    }
    else if (alarmNoMovement) {
      previousAlarmState = 0;
      alarmState = 4;
      alarmNoMovement = false;
    }
  }
  else if (alarmState == 1) {
    if(flagPanicButtonTriggered){
      previousAlarmState = 1;
      alarmState = 4;
      flagPanicButtonTriggered = false;
    }
    else if (alarmNoMovement) {
      previousAlarmState = 1;
      alarmState = 4;
      alarmNoMovement = false;
    }
  }
  else if (alarmState == 2) {
    if(flagPanicButtonTriggered){
      previousAlarmState = 2;
      alarmState = 4;
      flagPanicButtonTriggered = false;
    }
    else if (flagIntrusionDetected) {
      previousAlarmState = 1;
      alarmState = 2;
      flagIntrusionDetected = false;
      intrusionTriggerTime = millis();
    }
  }
  else if (alarmState == 3) {
    bool shouldAlarmActivate = checkTimerElapsed(intrusionTriggerTime);
    if(flagPanicButtonTriggered){
      previousAlarmState = 3;
      alarmState = 4;
      flagPanicButtonTriggered = false;
    }
    else if(shouldAlarmActivate){
      previousAlarmState = 2;
      alarmState = 3;
    }
  }
  else if (alarmState == 4) {
    if(resetAlarm){
      Serial.println("resetting alarm");
      delay(2000);
      alarmState = 0;
      previousAlarmState = 4;
      resetAlarm = false;
    }
  }
}

bool checkTimerElapsed(unsigned long intrusionTriggerTime){
  if((millis() - intrusionTriggerTime) > alarmTriggerDelay){
    return true;
  }
  else{
    return false;
  }
}