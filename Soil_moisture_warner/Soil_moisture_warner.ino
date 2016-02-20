// Soil Moisture Sensor Hygrometer example code
// Code author:  aafent. This code is copy free, if you want please mention the author's name and/or the site
//Interface Description (4-wire)
//VCC: 3.3v-5v
//GND: GND
//DO: Digital output interface (0 and 1) threshold taken from potentiometer
//AO: Analog output interface

const int moistureAO = 0;
const int moistureDO = 13;
const int ledDO = 8;

int hum = 0;
boolean flash = false;

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup (){
  lcd.begin(16, 2);
  // Print a message to the LCD.
  pinMode(moistureAO, INPUT);
  pinMode(ledDO, OUTPUT);
}

void loop ()
{
  hum=analogRead( moistureAO );
  lcd.setCursor(0, 0);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
  lcd.print("sec");
  
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print("A=");

  lcd.setCursor(5, 1);
  lcd.print("           ");
  lcd.setCursor(2, 1);
  lcd.print(hum);
  
  if (hum > 300) {
    flash = true;
  } else {
    flash = false;
  }
  if (flash == true) {
    digitalWrite(ledDO, HIGH);
    lcd.setCursor(6, 1);
    lcd.print("Vatten PLZ");
  }
  delay(150);
  if (flash == true) {
    digitalWrite(ledDO, LOW);
  }
  delay(150);
}
