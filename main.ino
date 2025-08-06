#define leftMotorPin 5
#define rightMotorPin 6
#define startButtonPin 2
#define stopSwitchPin 3

int started = 0;

void setup() {
  pinMode(leftMotorPin, OUTPUT);
  pinMode(rightMotorPin, OUTPUT);
  pinMode(startButtonPin, INPUT_PULLUP);  // Triggered with pencil press
  pinMode(stopSwitchPin, INPUT_PULLUP);   // Limit switch or bumper to stop
}

void loop() {
  if (!started && digitalRead(startButtonPin) == LOW) {
    started = 1;
    digitalWrite(leftMotorPin, HIGH);
    digitalWrite(rightMotorPin, HIGH);
  }

  if (started && digitalRead(stopSwitchPin) == LOW) {
    digitalWrite(leftMotorPin, LOW);
    digitalWrite(rightMotorPin, LOW);
    while (1);  // Stop everything permanently
  }
}
