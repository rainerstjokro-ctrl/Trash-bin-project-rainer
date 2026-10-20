#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Ultrasonik tempat sampah LOGAM
const int trigPin = 13;
const int echoPin = 12;

// Ultrasonik tempat sampah NONLOGAM
const int trig1Pin = 4;
const int echo1Pin = 3;

const int jumlahBaca = 5;
const float batasPenuh = 3.0;

float bacaJarak(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(3);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long durasi = pulseIn(echo, HIGH, 30000);

  if (durasi == 0) {
    return -1;
  }

  float cm = durasi * 0.0343 / 2.0;

if (cm < 1.0 || cm > 400.0) {
  return -1;
}

  return cm;
}

float bacaRataRata(int trig, int echo) {
  float total = 0;
  int valid = 0;

  for (int i = 0; i < jumlahBaca; i++) {
    float hasil = bacaJarak(trig, echo);

    if (hasil >= 0) {
      total += hasil;
      valid++;
    }

    delay(60);
  }

  if (valid >= 3) {
    return total / valid;
  }

  return -1;
}

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(trig1Pin, OUTPUT);
  pinMode(echo1Pin, INPUT);

  digitalWrite(trigPin, LOW);
  digitalWrite(trig1Pin, LOW);

  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("SISTEM SAMPAH");
  lcd.setCursor(0, 1);
  lcd.print("Memulai...");
  delay(1500);

  lcd.clear();
}

void loop() {
  // Baca jarak kedua tempat sampah
  float jarakLogam = bacaRataRata(trigPin, echoPin);
  float jarakNonlogam = bacaRataRata(trig1Pin, echo1Pin);

  bool logamPenuh =
    (jarakLogam >= 0 && jarakLogam <= batasPenuh);

  bool nonlogamPenuh =
    (jarakNonlogam >= 0 && jarakNonlogam <= batasPenuh);

  // Tampilkan hasil di Serial Monitor
  Serial.print("Logam: ");
  if (jarakLogam >= 0) {
    Serial.print(jarakLogam, 1);
    Serial.print(" cm");
  } else {
    Serial.print("Tidak terbaca");
  }

  Serial.print(" | Nonlogam: ");
  if (jarakNonlogam >= 0) {
    Serial.print(jarakNonlogam, 1);
    Serial.print(" cm");
  } else {
    Serial.print("Tidak terbaca");
  }

  Serial.println();

  // Tampilkan notifikasi LCD
  lcd.clear();

  if (logamPenuh && nonlogamPenuh) {
    lcd.setCursor(0, 0);
    lcd.print("KEDUANYA PENUH!");
    lcd.setCursor(0, 1);
    lcd.print("Kosongkan tong");
  }
  else if (logamPenuh) {
    lcd.setCursor(0, 0);
    lcd.print("LOGAM PENUH!");
    lcd.setCursor(0, 1);
    lcd.print("Kosongkan tong");
  }
  else if (nonlogamPenuh) {
    lcd.setCursor(0, 0);
    lcd.print("NONLOGAM PENUH!");
    lcd.setCursor(0, 1);
    lcd.print("Kosongkan tong");
  }
  else if (jarakLogam < 0 || jarakNonlogam < 0) {
    lcd.setCursor(0, 0);
    lcd.print("Cek sensor!");
    lcd.setCursor(0, 1);
    lcd.print("Baca jarak gagal");
  }
  else {
    lcd.setCursor(0, 0);
    lcd.print("L:");
    lcd.print(jarakLogam, 1);
    lcd.print(" N:");
    lcd.print(jarakNonlogam, 1);

    lcd.setCursor(0, 1);
    lcd.print("Sampah belum full");
  }

  delay(300);
}
