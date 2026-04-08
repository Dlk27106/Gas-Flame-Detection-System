#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define GAS_SENSOR 27
#define FLAME_SENSOR 26
#define BUZZER 25

int gasCount = 0;
int flameCount = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

// ---------- Smooth scrolling function ----------
void smoothScroll(String message) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(message);

  // scroll left smoothly
  for (int i = 0; i < message.length(); i++) {
    delay(300);
    lcd.scrollDisplayLeft();
  }
}

// ---------- Safe screen ----------
void showSafe() {
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("System Safe");
  lcd.setCursor(1, 1);
  lcd.print("Monitoring...");
}

void setup() {
  Serial.begin(115200);

  pinMode(GAS_SENSOR, INPUT);
  pinMode(FLAME_SENSOR, INPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(BUZZER, LOW);

  Wire.begin(21, 22);
  lcd.begin(16, 2);
  lcd.backlight();

  lcd.setCursor(1, 0);
  lcd.print("Gas & Flame");
  lcd.setCursor(3, 1);
  lcd.print("System");
  delay(2000);

  showSafe();

  Serial.println("STATUS: SAFE");
}

void loop() {
  int gasValue = digitalRead(GAS_SENSOR);
  int flameValue = digitalRead(FLAME_SENSOR);

  Serial.print("Gas: ");
  Serial.print(gasValue);
  Serial.print(" | Flame: ");
  Serial.println(flameValue);

  // Count repeated detections
  if (gasValue == LOW) gasCount++;
  else gasCount = 0;

  if (flameValue == LOW) flameCount++;
  else flameCount = 0;

  // ---------- Detection logic ----------
  if (gasCount >= 3 && flameCount >= 3) {
    digitalWrite(BUZZER, HIGH);
    Serial.println("ALERT! Gas and Flame Detected!");

    smoothScroll("ALERT! Gas & Flame!");
  }
  else if (gasCount >= 3) {
    digitalWrite(BUZZER, HIGH);
    Serial.println("ALERT! GAS DETECTED!");

    smoothScroll("ALERT! GAS DETECTED!");
  }
  else if (flameCount >= 3) {
    digitalWrite(BUZZER, HIGH);
    Serial.println("ALERT! FLAME DETECTED!");

    smoothScroll("ALERT! FLAME DETECTED!");
  }
  else {
    digitalWrite(BUZZER, LOW);
    Serial.println("Safe");

    showSafe();
    delay(1000);
  }

  Serial.println();
}
