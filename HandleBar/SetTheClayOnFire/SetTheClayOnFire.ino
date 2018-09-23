/*

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

/********************************************************************/
// First we include the libraries
#include <OneWire.h> 
#include <DallasTemperature.h>
/********************************************************************/
// Data wire is plugged into pin 2 on the Arduino 
#define ONE_WIRE_BUS 7 
/********************************************************************/
// Setup a oneWire instance to communicate with any OneWire devices  
// (not just Maxim/Dallas temperature ICs) 
OneWire oneWire(ONE_WIRE_BUS); 
/********************************************************************/
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
/********************************************************************/ 

#include <math.h>
int pinOut = 10;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(10, OUTPUT);
  
  // Print a message to the LCD.
  sensors.begin(); 
  delay(2000); 

}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  sensors.requestTemperatures();
  if(sensors.getTempCByIndex(0) >= 50.0){
    digitalWrite(pinOut, LOW);
    lcd.setCursor(0,0);
    lcd.print("Temperature: %f", sensors.getTempCByIndex(0));
    lcd.setCursor(0,1);
    lcd.print("STOP heating");
  }
  else{
    digitalWrite(pinOut, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Temperature: %f", sensors.getTempCByIndex(0));
    lcd.setCursor(0,1);
    lcd.print("SET THE SHIT ON FIRE");
  }
  delay(500); 
  
}
