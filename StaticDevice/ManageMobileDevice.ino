void procesMobileDeviceData(){
  Serial.println("Setting input: " + String(mobileDeviceData["resetAlarm"]));
  delay(2000);
  if (mobileDeviceData["resetAlarm"]) {
    Serial.println("resetAlarm");
    resetAlarm = true;
    alarmNoMovement = false;
    alarmDelayStarted = false;
    contactBroken = false;
    flagActivateAlarm = false;
    flagPanicButtonTriggered = false;
    flagIntrusionDetected = false;
  }
  else if(mobileDeviceData["panicButtonPressed"]){
    flagPanicButtonTriggered = true;
    Serial.println("Setting button: " + String(flagPanicButtonTriggered));
  }
}