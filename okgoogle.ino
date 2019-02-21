#include <HCSR04.h>
#include <WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

WiFiClient wiFiClient;
Adafruit_MQTT_Client mqttClient(&wiFiClient, "192.168.0.108", 1883);
Adafruit_MQTT_Subscribe googleSub(&mqttClient, "/google");

void okgoogle(double x){

    if( x == 1){
      
      digitalWrite(26, HIGH);
        }
     
    if( x == 0){
      
      digitalWrite(26, LOW);
        }
      }
  
void setup(){
pinMode(26, OUTPUT);
Serial.begin(115200);
WiFi.begin("createch2019", "createch2019");
delay(4000); 

googleSub.setCallback(okgoogle);
mqttClient.subscribe(&googleSub);
}

void loop() {
  
if (mqttClient.connected()) {
    mqttClient.processPackets(10000);
    mqttClient.ping();
  } else {
    mqttClient.disconnect();
    mqttClient.connect();
  }


}
