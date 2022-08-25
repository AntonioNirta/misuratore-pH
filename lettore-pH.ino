#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);
}

float misura;

void loop() {
  for(int i=0; i<10; i++) { 
    misura += analogRead(A0);
    delay(10);
  }

  misura = misura / 10.0;  
  float ph = (float)misura * (5.0/1024);
  //lcd.print(ph);
  ph = 6.1 * ph;  
  lcd.print("pH:");  
  lcd.print(ph);
  //lcd.println(" ");
  delay(1000);
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  //lcd.print(millis() / 1000);
} 
