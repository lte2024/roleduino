// Röle ve Switch pinleri tanımlanıyor
const int relay1Pin = 7;
const int relay2Pin = 6;
const int switch1Pin = 2;
const int switch2Pin = 3;

bool relay1State = LOW;
bool relay2State = LOW;

void setup() {
  // Röle pinleri çıkış olarak ayarlanıyor
  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);

  // Switch pinleri giriş olarak ayarlanıyor
  pinMode(switch1Pin, INPUT_PULLUP);
  pinMode(switch2Pin, INPUT_PULLUP);

  // Rölelerin başlangıç durumu ayarlanıyor
  digitalWrite(relay1Pin, relay1State);
  digitalWrite(relay2Pin, relay2State);
}

void loop() {
  // Switch 1 kontrolü
  if (digitalRead(switch1Pin) == LOW) {
    delay(100); // Debouncing için küçük bir gecikme
    relay1State = !relay1State;
    digitalWrite(relay1Pin, relay1State);
    while (digitalRead(switch1Pin) == LOW); // Düğme bırakılana kadar bekle
  }

  // Switch 2 kontrolü
  if (digitalRead(switch2Pin) == LOW) {
    delay(100); // Debouncing için küçük bir gecikme
    relay2State = !relay2State;
    digitalWrite(relay2Pin, relay2State);
    while (digitalRead(switch2Pin) == LOW); // Düğme bırakılana kadar bekle
  }
}
