#include <ThingSpeak.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <DHT.h>
#define dht_pin 13
#define dht_type DHT11
DHT dht(dht_pin,dht_type);
const char * ssid="IT LABS";
const char * pass="abcd*1234";
unsigned long channelID = 812044;
const char * WriteAPIKey="AW5ACW2SU58V65XE";
WiFiClient client;
void setup() {
  dht.begin(115200);
  pinMode(dht_pin,INPUT);
  Serial.begin(115200);
WiFi.begin(ssid,pass);
ThingSpeak.begin(client);
}
void loop() {
   float temp=dht.readTemperature();
  float humidity=dht.readHumidity();
  Serial.println("Temperature:");
  Serial.print(temp);
  delay(1000);
  Serial.println("Humidity:");
  Serial.print(humidity);
  delay(1000);
  ThingSpeak.writeField(channelID,1,temp,WriteAPIKey);
  delay(500);
  ThingSpeak.writeField(channelID,2,humidity,WriteAPIKey);
  delay(500);
}
