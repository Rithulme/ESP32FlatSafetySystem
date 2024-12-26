const int OUTPUTPIN_GREENLED;
const int OUTPUTPIN_ORANGELED;
const int OUTPUTPIN_REDLED;

const int INPUTPIN_ALARMOFF;
const int INPUTPIN_ALARMARMED;
const int INPUTPIN_ALARMARMEDEXT;
const int INPUTPIN_PANICBUTTON;

const int inputRows[] = {18, 17, 16, 4};
const int inputColumns[] = {19, 23, 32, 33};

int alarmState = 0;

bool flagTryAlarmOff = false;
bool flagTryAlarmArmed = false;
bool flagTryAlarmArmedExt = false;
bool flagAlarmOff = false;
bool flagAlarmArmed = false;
bool flagAlarmArmedExt = false;

bool panicTriggered = false;

String inputString;


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
