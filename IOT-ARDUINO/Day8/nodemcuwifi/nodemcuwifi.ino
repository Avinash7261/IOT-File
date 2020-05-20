#include<ESP8266WiFi.h>
#define ssid "Avinash"
#define pass "Sumit#$130"
void setup() {
Serial.begin(9600);
Serial.println("Connecting to");
Serial.print(ssid);
WiFi.begin(ssid,pass);
while(WiFi.status()!=WL_CONNECTED)
{
  delay(500);
  Serial.print("...");

Serial.println("WiFi Connected");
Serial.println(WiFi.localIP());
}
}


void loop() {
  

}
