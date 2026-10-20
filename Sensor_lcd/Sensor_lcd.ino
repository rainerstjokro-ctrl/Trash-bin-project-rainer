
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define SENSOR1 8   // Sensor kapasitif
#define SENSOR2 10  // Sensor induktif

void setup() {
  pinMode(SENSOR1, INPUT_PULLUP);
  pinMode(SENSOR2, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("JENIS SAMPAH:");
}

void loop() {
  int kapasitif = digitalRead(SENSOR1);
  int induktif = digitalRead(SENSOR2);

  lcd.setCursor(0, 1);

  if (kapasitif == HIGH && induktif == HIGH) {
    lcd.print("LOGAM           ");
  }
  else if (kapasitif == HIGH && induktif == LOW) {
    lcd.print("NONLOGAM        ");
  }
  else {
    lcd.print("BELUM ADA       ");
  }

  delay(200);
}
