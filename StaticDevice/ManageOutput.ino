void outputmanagement(){
  manageBuzzer();
}

void manageBuzzer(){
  static unsigned long lastSwitch;
  static bool buzzerState = false;
  if (alarmState == 4) {
    if (millis() - lastSwitch > 3000) {
      if (!buzzerState) {
        Serial.println("buzzer on");
        //tone(OUTPUTPIN_BUZZER, 5000);
        buzzerState = true;
      }
      else{
        Serial.println("buzzer off");
        noTone(OUTPUTPIN_BUZZER);
        buzzerState = false;
      }

      lastSwitch = millis();
    }
  }
  else{
    noTone(OUTPUTPIN_BUZZER);
    buzzerState = false;
  }
}