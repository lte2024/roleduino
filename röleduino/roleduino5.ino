#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int relay1Pin = 7;
const int relay2Pin = 6;
const int switch1Pin = 2;
const int switch2Pin = 3;

bool relay1State = false;
bool relay2State = false;

void setup() {
  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);
  pinMode(switch1Pin, INPUT_PULLUP);
  pinMode(switch2Pin, INPUT_PULLUP);

  digitalWrite(relay1Pin, HIGH); // Röleleri kapalı tutmak için HIGH
  digitalWrite(relay2Pin, HIGH);

  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Ev Otomasyonu");
  lcd.setCursor(0, 1);
  lcd.print("Hosgeldiniz");
  delay(2000);
  lcd.clear();
}

void loop() {
  if (digitalRead(switch1Pin) == LOW) {
    delay(50); // Titreşimi önlemek için
    relay1State = !relay1State;
    digitalWrite(relay1Pin, relay1State ? LOW : HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Röle 1: ");
    lcd.print(relay1State ? "Acik " : "Kapali");
    delay(1000); // Değişikliği gözlemlemek için
  }

  if (digitalRead(switch2Pin) == LOW) {
    delay(50); // Titreşimi önlemek için
    relay2State = !relay2State;
    digitalWrite(relay2Pin, relay2State ? LOW : HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Röle 2: ");
    lcd.print(relay2State ? "Acik " : "Kapali");
    delay(1000); // Değişikliği gözlemlemek için
  }
}
