#include <Arduino.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(PB0, PB1, PB2, PB4, PB5, PB6, PB7);



void setup() {
  Serial.begin(9600);
  Serial.println("Init");
  lcd.begin(16,2);
  lcd.backlight();
  lcd.home();
  lcd.print("AP Winter 2021");
  lcd.setCursor(0,1);
  lcd.print("Demo");
  delay(2000);
  lcd.clear();
}

void loop() {

  lcd.home();
  lcd.print("PA0: ");
  lcd.print(analogRead(PA0)*0.004882813);
  lcd.print("V   ");
  lcd.setCursor(0,1);
  lcd.print("PA1: ");
  lcd.print(analogRead(PA1)*0.004882813);
  lcd.print("V   ");

}
