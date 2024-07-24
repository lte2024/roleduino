#define RELAY1 28
#define RELAY2 53

void setup() {
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  // Röleler başlangıçta kapalı olacak şekilde ayarlanır
  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');

    if (command == "1. lamba aç") {
      digitalWrite(RELAY1, LOW); // Röle tetiklenir (aktif)
    } else if (command == "1. lamba kapat") {
      digitalWrite(RELAY1, HIGH); // Röle kapatılır (pasif)
    } else if (command == "2. lamba aç") {
      digitalWrite(RELAY2, LOW); // Röle tetiklenir (aktif)
    } else if (command == "2. lamba kapat") {
      digitalWrite(RELAY2, HIGH); // Röle kapatılır (pasif)
    }
  }
}
