#include <ESP8266WiFi.h>

void setup()
{
  Serial.begin(9600);
  Serial.println();

  WiFi.begin("Galaxy2Guest", "123456789");

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(5000);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {}