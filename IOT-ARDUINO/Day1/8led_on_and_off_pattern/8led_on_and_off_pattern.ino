void setup() {
for(int i=13;i>=6;i--)
{
  pinMode(i,OUTPUT);
  }  

}

void loop() {
for(int i=13,j=6;i>=10,j<=9;i--,j++)
{
 digitalWrite(i,HIGH);
 digitalWrite(j,HIGH);
 delay(500);
 digitalWrite(i,LOW);
 digitalWrite(j,LOW);
 delay(500);
 
  }  

}
