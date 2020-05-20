#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

#define WLAN_SSID       "Avinash"
#define WLAN_PASS       "sumit#&130"

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                  
#define AIO_USERNAME    "avinash7719"
#define AIO_KEY         "6193e24c4c5d4a45b7ec8ac7aeff05ff"

WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);
Adafruit_MQTT_Publish pubg1 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/pubg1");
void MQTT_connect();
void setup() {
Serial.begin(9600);
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
}
void loop() {
  MQTT_connect();
   Serial.print(F("\nSending pubg1 val "));
  Serial.print("hello avinash");
  Serial.print("...");
  if (! pubg1.publish("hello avinash")) {
    Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
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


