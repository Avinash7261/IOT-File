#include<SoftwareSerial.h>
SoftwareSerial bt(10,11);
void setup() {
  Serial.begin(9600);
  bt.begin(9600);
}

void loop() {
  char data;
 if(bt.available()>0)
 {
  data=bt.read();
  Serial.print(data);
  }
}
