void setup() {
 pinMode(13,OUTPUT);
 pinMode(12,OUTPUT); 
 pinMode(11,OUTPUT); 

}

void loop() {
 digitalWrite(13,HIGH);
 digitalWrite(12,LOW);
 digitalWrite(11,LOW);
 delay(1000);
 digitalWrite(12,HIGH);
 digitalWrite(13,LOW);
 digitalWrite(11,LOW);
 delay(1000);
  digitalWrite(10,HIGH);
 digitalWrite(13,LOW);
 digitalWrite(12,LOW);
 delay(1000);
}
