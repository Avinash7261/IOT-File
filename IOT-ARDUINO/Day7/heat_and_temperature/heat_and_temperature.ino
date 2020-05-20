#include<ESP8266WiFi.h>
#include<DHT.h>

#define dht_pin 13
#define dht_type DHT11
DHT dht(dht_pin,dht_type);
void setup(){
  pinMode(dht_pin,INPUT);
  Serial.begin(9600);
  dht.begin();
}
void loop() {
  
    float temp=dht.readTemperature();
  float humidity=dht.readHumidity();
  Serial.println("Temperature:");
  Serial.println(temp);
  Serial.println("humidity:");
  Serial.println(humidity);
  delay(1000);}
 

