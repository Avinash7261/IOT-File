#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

#define WLAN_SSID       "Avinash"
#define WLAN_PASS       "Sumit$130"

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                  
#define AIO_USERNAME    "avinash7719"
#define AIO_KEY         "6193e24c4c5d4a45b7ec8ac7aeff05ff"

WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);
Adafruit_MQTT_Subscribe pubg1 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/pubg1");
void MQTT_connect();
void setup() {
Serial.begin(9600);
delay(10);
Serial.println(F("Adafruit MQTT demo"));
Serial.println("Connecting to");
 Serial.println(WLAN_SSID);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
while(WiFi.status()!=WL_CONNECTED)
{
  delay(500);
  Serial.print("...");
}
Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  mqtt.subscribe(&pubg1);
}
void loop() {
  MQTT_connect();
   Adafruit_MQTT_Subscribe *subscription;
  while ((subscription = mqtt.readSubscription(5000))) {
    if (subscription == &pubg1) {
      Serial.print(F("Got: "));
      Serial.println((char *)pubg1.lastread);
    }
  }
  delay(5000);
}
void MQTT_connect() {
  int8_t ret;
  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { 
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       delay(5000); 
       retries--;
       if (retries == 0) {
         while (1);
       }
        }
  Serial.println("MQTT Connected!");
}


