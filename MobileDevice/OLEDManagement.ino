void writeMessage(String message){
  u8g2.clearBuffer();
  String remainingString = message;
  String part1;

  int counter = 1;

  while (remainingString.length() > 20) {
    int splitPoint = lastIndexUntil(remainingString, " ", 20);
    if (splitPoint < 0) {
      splitPoint = 19;
    }
    part1 = remainingString.substring(0, splitPoint);
    remainingString = remainingString.substring(splitPoint + 1);

    u8g2.drawStr( 0, (counter) * 10, part1.c_str());
    counter++;
  }

  u8g2.drawStr( 0, (counter) * 10, remainingString.c_str());
  u8g2.sendBuffer();
}

void writeTemperture(double requested, double measured){
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_profont17_tf);

  String toPrint = String(measured) + " °C"
  char stringToArray[15];
  toPrint.toCharArray(stringToArray, 15);

  u8g2.drawUTF8(28, 20, stringToArray);

  u8g2.setFont(u8g2_font_profont12_tf);
  u8g2.setCursor(0, 50);

  toPrint = "Gevraagde temperatuur: " + String(requested);

  u8g2.print(toPrint);
  u8g2.sendBuffer();
}

int lastIndexUntil(String input, String searchString, int until){
  int lastIndex = -1;
  int returnIndex = -1;

  if (input.indexOf(searchString) < 0) {
    return returnIndex;
  }

  while(lastIndex < until){
    returnIndex = lastIndex;
    lastIndex = input.indexOf(searchString, lastIndex + 1);

    if(lastIndex < 0){
      return returnIndex;
    }
  }

  return returnIndex;
}

