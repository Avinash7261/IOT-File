#include<ThingSpeak.h>
#include<ESP8266WiFi.h>
#include<WiFiClient.h>

const char*ssid="SAHIL";
const char*pass="iamsahil@cr7";

unsigned long channelID = 812044;
const char*WriteAPIKey="AW5ACW2SU58V65XE"; 

WiFiClient client;
void setup(){
  WiFi.begin(ssid,pass);
  Serial.begin(115200);
  ThingSpeak.begin(client);
  
}
void loop()
{
  Serial.println("8");
  ThingSpeak.writeField(channelID,1,8,WriteAPIKey);
  delay(5000);
  }

