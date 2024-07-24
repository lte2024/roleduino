#define RELAY1 28
#define RELAY2 53

void setup() {
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
}

void loop() {
digitalWrite(RELAY_PIN, HIGH);
delay(2000);
digitalWrite(RELAY_PIN2, HIGH);
delay(2000);
digitalWrite(RELAY_PIN, LOW);
delay(2000);
digitalWrite(RELAY_PIN2, LOW);
delay(2000);
}
