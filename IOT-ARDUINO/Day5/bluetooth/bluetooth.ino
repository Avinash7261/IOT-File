#include<SoftwareSerial.h>
SoftwareSerial bt(10,11);
void setup() {
  Serial.begin(9600);
  bt.begin(9600);
}

void loop() {
 
 if(bt.isListening())
 {
  Serial.println("it is listening");
  }
  else
  {
    Serial.println("Error");
  }

}
