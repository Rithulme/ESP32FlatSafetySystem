const char keysSetting[4][4] = {{'7', '8', '9', 'A'},{'4', '5', '6', 'B'},{'1', '2', '3', 'C'},{'*', '0', '#', 'D'}};

void setupKeypad(){
  for (int i = 0; i < 4; i++) {
    pinMode(inputRows[i], OUTPUT);
    digitalWrite(inputRows[i], false);

    pinMode(inputColumns[i], INPUT_PULLDOWN);
  }
}

void manageKeyPad(){
  static char lastKey = ' ';

  char inputChar = ' ';

  for (int i = 0; i < 4; i++) {
    if (inputChar != ' ') { //we lezen het eerste karakter dat we tegenkomen
      break;
    }
    digitalWrite(inputRows[i], true);
    for (int j = 0; j < 4; j++) {
      if(digitalRead(inputColumns[j])){
        inputChar = keysSetting[i][j];
        break;
      }
    }
    digitalWrite(inputRows[i], false);
  }

  if (inputChar != ' ') { //we lezen het eerste karakter dat we tegenkomen
      processInput(inputChar, lastKey);
      delay(20);
  }

  lastKey = inputChar;
}

void processInput(char inputChar, char lastKey){
  if (inputChar == lastKey) {
    return;
  }
  if (inputChar == 'D') {
    Serial.println(inputString);
    inputString = "";
    return;
  }
  inputString += String(inputChar);
}

void verifyAlarmInstruction(){
  if (inputString != "1475") {
    Serial.println("Wrong code");
  }
  else if (flagTryAlarmOff) {
    flagAlarmOff = true;
  }
  else if (flagTryAlarmArmed) {
    flagAlarmArmed = true;
  }
  else if (flagTryAlarmArmedExt) {
    flagAlarmArmedExt = true;
  }

  flagTryAlarmOff = false;
  flagTryAlarmArmed = false;
  flagTryAlarmArmedExt = false;
  inputString = "";
}

