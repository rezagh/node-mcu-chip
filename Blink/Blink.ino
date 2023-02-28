int pin = BUILTIN_LED;

void setup() {
  pinMode(pin, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
}

void loop() {
  digitalWrite(pin, LOW);   
  delay(50);                      
  digitalWrite(pin, HIGH); 
  delay(50);                     
}
