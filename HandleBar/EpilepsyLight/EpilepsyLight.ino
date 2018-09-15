#include <math.h>
int pinOut = 10;

int t;
void setup() {
  // put your setup code here, to run once:  
  pinMode(10, OUTPUT);
  t = 2000;
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pinOut, LOW);
  delay(t); 
  digitalWrite(pinOut, HIGH);
  delay(t); 
  t = t*0.9;

}
