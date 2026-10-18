#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
// Set alamat I2C LCD (biasanya 0x27 atau 0x3F) dengan ukuran 16x2
// LiquidCrystal_I2C lcd(0x27, 16, 2);

#define SENSOR1 8 // Pin sensor kapasitif
servo MOTOR1 5
servo MOTOR2 6
#define SENSOR2 10 // Pin sensor induktif

void setup() {
  Serial.begin(9600); // Setup Serial Monitor
  
  // Inisialisasi LCD
  // lcd.init();                      
  // lcd.backlight(); // Nyalakan lampu latar LCD
  
  pinMode(SENSOR1, INPUT_PULLUP); // Define pin sebagai input sensor    // Define pin sebagai output
  pinMode(SENSOR2, INPUT_PULLUP); // Define pin sebagai input senso       // Define pin sebagai output
  pinMode(MOTOR1, OUTPUT); // Define pin sebagai input sensor    // Define pin sebagai output
  pinMode(MOTOR2, OUTPUT);
  pinMode

  // Tampilan awal LCD
  // lcd.setCursor(0, 0);
  // lcd.print("Sistem Siap");
  // delay(2000);
  // lcd.clear();
}

void loop() {
  int L1 = digitalRead(SENSOR1); // Baca sensor 1
  int L2 = digitalRead(SENSOR2); // Baca sensor 2

  // lcd.setCursor(0, 0);
  if (L1 == 0) {
    Serial.println(" S1: All Clear");
    //lcd.print("S1: Aman       ");
  } else {
    Serial.println(" S1 === Obstacle detected");
    MOTOR1.
    //lcd.print("S1: Obstacle!  ");
  }

  // Baris 2 untuk Sensor 2 (Induktif)
  //lcd.setCursor(0, 1);
  if (L2 == 0) {
    Serial.println(" S2: All Clear");
    //lcd.print("S2: Aman       ");
  } else {
    Serial.println(" S2 === Logam detected");
    //lcd.print("S2: Logam!     ");
  }
  
  delay(100);
}
