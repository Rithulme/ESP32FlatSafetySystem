void manageLeds(){
  if(alarmState == 0){
    digitalWrite(OUTPUTPIN_GREENLED, true);
    digitalWrite(OUTPUTPIN_ORANGELED, false);
    digitalWrite(OUTPUTPIN_REDLED, false);
  }
  else if(alarmState == 1){
    digitalWrite(OUTPUTPIN_GREENLED, false);
    digitalWrite(OUTPUTPIN_ORANGELED, true);
    digitalWrite(OUTPUTPIN_REDLED, false);
  }
  else if (alarmState == 2) {
    digitalWrite(OUTPUTPIN_GREENLED, false);
    digitalWrite(OUTPUTPIN_ORANGELED, false);
    digitalWrite(OUTPUTPIN_REDLED, true);
  }
  else{
    manageBlinkingAlarm();
  }
}

void manageBlinkingAlarm(){
  static unsigned long lastSwitch;
  static bool blinkState = false;

  if ((millis() - lastSwitch) > 1500) {
    blinkState = !blinkState;
    digitalWrite(OUTPUTPIN_GREENLED, blinkState);
    digitalWrite(OUTPUTPIN_ORANGELED, blinkState);
    digitalWrite(OUTPUTPIN_REDLED, blinkState);
  }
}