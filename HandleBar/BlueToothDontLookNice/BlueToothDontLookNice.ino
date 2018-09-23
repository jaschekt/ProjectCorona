
int ledPin = 8;
int state = 0;
int no_message_printed = true;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()>0){
    state = serial.read();
    no_message_printed = true;
  }
  if (state == 0){
    digitalWrite(ledPin, LOW);
    if (no_message_printed){
      Serial.println("LED: off");
      no_message_printed = false;
    }
  }
  else if (state == 1){
    digitalWrite(ledPin, HIGH);
    Serial.println("LED: on")
  }
}
