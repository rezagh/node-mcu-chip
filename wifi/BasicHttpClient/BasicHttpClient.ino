#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>



ESP8266WiFiMulti WiFiMulti;

void setup() {

  Serial.begin(9600);
  // Serial.setDebugOutput(true);

  Serial.println();
  Serial.println();
  Serial.println();

  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP("Galaxy2", "aghareza123");

}

void loop() {
  // wait for WiFi connection
  if ((WiFiMulti.run() == WL_CONNECTED)) {

    WiFiClient client;

    HTTPClient http;

    Serial.printf("[HTTP] begin...\n");
    if (http.begin(client, "https://www.djxmmx.net")) {  // HTTP

      Serial.printf("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();
      Serial.printf("[HTTP] GET... code: %d\n", httpCode);

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled

          String payload = http.getString();
          Serial.printf("payload:",payload);

        // file found at server
        //if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
        //  String payload = http.getString();
        //  Serial.printf("payload:",payload);
        //}
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
  }

  delay(10000);
}