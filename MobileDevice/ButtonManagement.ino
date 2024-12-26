void manageInputButtons(){
  manageAlarmOffButton();
  manageAlarmArmedButton();
  manageAlarmArmedExtButton();
  managePanicButton();
}

void manageAlarmOffButton(){
  static bool previousState = false;
  
  bool input = digitalRead(INPUTPIN_ALARMOFF);

  if(input && input != previousState){
    flagTryAlarmOff = true;
    delay(20);
  }

  previousState = input;
}

void manageAlarmArmedButton(){
  static bool previousState = false;
  
  bool input = digitalRead(INPUTPIN_ALARMARMED);

  if(input && input != previousState){
    flagTryAlarmArmed = true;
    delay(20);
  }

  previousState = input;
}

void manageAlarmArmedExtButton(){
  static bool previousState = false;
  
  bool input = digitalRead(INPUTPIN_ALARMARMEDEXT);

  if(input && input != previousState){
    flagTryAlarmArmedExt = true;
    delay(20);
  }

  previousState = input;
}

void managePanicButton(){
  static bool previousState = false;
  
  bool input = digitalRead(INPUTPIN_PANICBUTTON);

  if(input && input != previousState){
    panicTriggered = true;
    delay(20);
  }

  previousState = input;
}