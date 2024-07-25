#define RELAY1_PIN 7
#define RELAY2_PIN 6
#define BUTTON1_PIN 8
#define BUTTON2_PIN 9

void setup() {
  // Röle pinlerini çıkış olarak ayarlama
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);

  // Buton pinlerini giriş olarak ayarlama
  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);

  // Röleleri başlangıçta kapalı tutma
  digitalWrite(RELAY1_PIN, HIGH);
  digitalWrite(RELAY2_PIN, HIGH);
}

void loop() {
  // Buton durumlarını okuma
  int button1State = digitalRead(BUTTON1_PIN);
  int button2State = digitalRead(BUTTON2_PIN);

  // Buton 1'e basıldığında Röle 1'i açma/kapama
  if (button1State == LOW) {
    digitalWrite(RELAY1_PIN, LOW); // Röle 1'i aç
  } else {
    digitalWrite(RELAY1_PIN, HIGH); // Röle 1'i kapat
  }

  // Buton 2'ye basıldığında Röle 2'yi açma/kapama
  if (button2State == LOW) {
    digitalWrite(RELAY2_PIN, LOW); // Röle 2'yi aç
  } else {
    digitalWrite(RELAY2_PIN, HIGH); // Röle 2'yi kapat
  }
}
