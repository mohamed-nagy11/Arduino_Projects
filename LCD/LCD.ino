#include <LiquidCrystal.h>
int i;
int j;
const int rs = A0, en = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
}
 
void loop() {
  for(j=0;j<=1;j++){
    for(i=0;i<=15;i++){
      lcd.setCursor(i, j);
      lcd.print("Mohamed Nagy");
      delay(300);
      lcd.clear();
    }
  }
  
}
