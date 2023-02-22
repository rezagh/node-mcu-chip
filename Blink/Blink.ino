/*
  Blink the blue LED on the ESP-01 module
   The blue LED on the ESP-01 module is connected to GPIO1
  (which is also the TXD pin; so we cannot use Serial.print() at the same time)
 Note that this sketch uses LED_BUILTIN to find the pin with the internal LED
*/
int pin = 0;

void setup() {
  pinMode(pin, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(pin, LOW);   // Turn the LED on (Note that LOW is the voltage level
  // but actually the LED is on; this is because
  // it is active low on the ESP-01)
  delay(50);                      // Wait for a second
  digitalWrite(pin, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(50);                      // Wait for two seconds (to demonstrate the active low LED)
}
