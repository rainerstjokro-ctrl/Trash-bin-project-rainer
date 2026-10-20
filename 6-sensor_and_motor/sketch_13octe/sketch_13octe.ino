#include <Servo.h>

Servo servo1;
Servo servo2;
#define SENSOR1 8       // Sensor kapasitif
#define ACTION1 9       // Indikator sensor kapasitif

#define SENSOR2 10      // Sensor induktif
#define ACTION2 11      // Indikator sensor induktif

#define LED_LOGAM 12
#define LED_NONLOGAM 13

void setup() {
  Serial.begin(9600);
  servo2.attach(6);
  servo1.attach(5);
  pinMode(SENSOR1, INPUT_PULLUP);
  pinMode(ACTION1, OUTPUT);

  pinMode(SENSOR2, INPUT_PULLUP);
  pinMode(ACTION2, OUTPUT);

  pinMode(LED_LOGAM, OUTPUT);
  pinMode(LED_NONLOGAM, OUTPUT);

  digitalWrite(ACTION1, LOW);
  digitalWrite(ACTION2, LOW);
  digitalWrite(LED_LOGAM, LOW);
  digitalWrite(LED_NONLOGAM, LOW);
  

}

void loop() {
  int L1 = digitalRead(SENSOR1); // Kapasitif
  int L2 = digitalRead(SENSOR2); // Induktif

  // Indikator pembacaan masing-masing sensor
  if (L1 == HIGH) {
    digitalWrite(ACTION1, HIGH);
  } else {
    digitalWrite(ACTION1, LOW);
  }

  if (L2 == HIGH) {
    digitalWrite(ACTION2, HIGH);
  } else {
    digitalWrite(ACTION2, LOW);
  }

  // Klasifikasi sampah
  bool kapasitifON = (L1 == HIGH);
  bool induktifON = (L2 == HIGH);

  if (kapasitifON && induktifON) {
    // Logam terdeteksi
    digitalWrite(LED_LOGAM, HIGH);
    digitalWrite(LED_NONLOGAM, LOW);

    servo1.write(30); 
    delay(2000); 
    
    servo1.write(90); 

    Serial.println("SAMPAH LOGAM");
  }
  else if (kapasitifON && !induktifON) {
    // Sampah nonlogam
    digitalWrite(LED_LOGAM, LOW);
    digitalWrite(LED_NONLOGAM, HIGH);
    
    servo2.write(150); 
    delay(2000);
    
    servo2.write(90);

    Serial.println("SAMPAH NONLOGAM");
  }
  else {
    digitalWrite(LED_LOGAM, LOW);
    digitalWrite(LED_NONLOGAM, LOW);
    
    Serial.println("BELUM ADA KLASIFIKASI");
  }

  delay(100);
}