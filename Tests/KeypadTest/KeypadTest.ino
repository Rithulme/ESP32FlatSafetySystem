const int inputRows[] = {18, 17, 16, 4};
const int inputColumns[] = {19, 23, 32, 33};

String inputString;

void setup() {
  Serial.begin(115200);
  setupKeypad();

}

void loop() {
  manageKeyPad();
}
