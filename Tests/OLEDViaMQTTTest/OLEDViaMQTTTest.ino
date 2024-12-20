#include <U8g2lib.h>
#include <Wire.h>

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup() {
  Serial.begin(115200);

  u8g2.begin();
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);	
  u8g2.drawStr( 0, 10, "Test");
  u8g2.sendBuffer();

  String test = "azertyu iopqsd fghjklmw xcvbn azerty uiopqs dfghjk lmwxcvbn";
  
  Serial.println(test);
  writeMessage(test);
  
  Serial.println(lastIndexUntil(test, " ", 20));
}

void loop() {
  // put your main code here, to run repeatedly:

}
