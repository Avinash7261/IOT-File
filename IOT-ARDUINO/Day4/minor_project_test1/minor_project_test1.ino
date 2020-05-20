#include<LiquidCrystal.h>
const int rs=8,en=9,d4=5,d5=4,d6=3,d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int Count=0;
void setup() {
  lcd.begin(16,2);
  pinMode(0,INPUT);
  pinMode(1,INPUT);

}
void loop() {
  lcd.clear();
  lcd.noBlink();
 
 int data=digitalRead(0);
 int data2=digitalRead(1);
  if(data==HIGH)
  {
    
    Count++;
    }
  if(data2==HIGH)
  {
   
    Count--;
    }
    lcd.print(Count);
    delay(200);
   }
