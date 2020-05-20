
#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include<DHT.h>
#define dht_pin 13
#define dht_type DHT11
DHT dht(dht_pin,dht_type);



#define WLAN_SSID       "IT LABS"
#define WLAN_PASS       "abcd*1234"



#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                   // use 8883 for SSL
#define AIO_USERNAME    "avinash7719"
#define AIO_KEY         "6193e24c4c5d4a45b7ec8ac7aeff05ff"


WiFiClient client;

Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);



Adafruit_MQTT_Publish pubg1 = Adafruit_MQTT_Publish(&mqtt,AIO_USERNAME "/feeds/pubg1");




void MQTT_connect();

void setup() {
  pinMode(dht_pin,INPUT);
  Serial.begin(9600);
  dht.begin();
  delay(10);

  Serial.println(F("Adafruit MQTT demo"));

  // Connect to WiFi access point.
  Serial.println(); Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.println("WiFi connected");
  Serial.println("IP address: "); Serial.println(WiFi.localIP());

  
}


void loop() {
  float temp=dht.readTemperature();
  float humidity=dht.readHumidity();
  MQTT_connect();

    
  Serial.println(F("temeraturedata:"));
  Serial.println("temperature:");
  Serial.print(temp);
   Serial.println("humidity:");
  Serial.print(humidity);
  Serial.print("...");
  if (! pubg1.publish(temp)) {
    Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
    delay(500);
  }
  if (! pubg1.publish(humidity)){
     Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
    delay(500);
  }

  delay(10000);
  
}

void MQTT_connect() {
  int8_t ret;

 
  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       delay(500);  // wait 5 seconds
       retries--;
       if (retries == 0) {
         // basically die and wait for WDT to reset me
         while (1);
       }
  }
  Serial.println("MQTT Connected!");
  delay(500);
}
