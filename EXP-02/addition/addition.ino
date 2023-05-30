#include <Wire.h>
#include <LiquidCrystal_I2C.h>

char array1[]="Sound Level: "; //the string to print on the LCD
int tim = 500; //the value of the delay time
int soundPin = A0; //assuming the sound signal is connected to analog pin A0
LiquidCrystal_I2C lcd(0x27, 16, 2); //set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init(); //initialize the led
  lcd.backlight(); //open the backlight
  Serial.begin(9600);
}

void loop()
{
  lcd.clear(); //Clears the LCD screen and positions the cursor in the upper-left corner.
  lcd.setCursor(0, 0); //set the cursor to column 0, line 0
  lcd.print(array1); //print the string to LCD

  int value = analogRead(soundPin); //read the value from the sound sensor
  value = (value - 80) * 10;
  if(value < 0)
  value = 0;
  lcd.setCursor(0, 1); //set the cursor to column 0, line 1
  lcd.print(value); //print the value to the LCD
  
  Serial.println(value); //also print the value to the Serial monitor
  delay(tim); //wait for 500 milliseconds
}
