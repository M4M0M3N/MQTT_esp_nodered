#include "EspMQTTClient.h"

EspMQTTClient client(
  "SSID wify",
  "PASS wify",
  "IP broker",               // MQTT Broker server ip
  "MQTTUsername",            // Can be omitted if not needed
  "MQTTPassword",            // Can be omitted if not needed
  "NAME esp in mqtt",        // Client name that uniquely identify your device
  1883                       // The MQTT port, default to 1883. this line can be omitted
);

void ICACHE_RAM_ATTR pippo() {
  Serial.println("Allarme");
  client.publish("allarme","true");
}

void setup()
{
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(0), pippo, RISING);

  //Optional functionalities of EspMQTTClient
  client.enableDebuggingMessages(); // Enable debugging messages sent to serial output
  client.enableHTTPWebUpdater(); // Enable the web updater. User and password default to values of MQTTUsername and MQTTPassword. These can be overridded with enableHTTPWebUpdater("user", "password").
  client.enableOTA(); // Enable OTA (Over The Air) updates. Password defaults to MQTTPassword. Port is the default OTA port. Can be overridden with enableOTA("password", port).
  client.enableLastWillMessage("TestClient/lastwill", "I am going offline");  // You can activate the retain flag by setting the third parameter to true
}

void onConnectionEstablished()
{

}

void loop()
{ 
  client.loop();
}
