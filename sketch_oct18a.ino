#include <Servo.h>

tes
Servo MOTOR1;
// #define MOTOR2 6
void setup() {
  MOTOR1.attach(5);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  MOTOR1.write(90);
  delay(1000);
  MOTOR1.write(45);
  delay(1000);
  MOTOR1.write(90);
  delay(1000);
  MOTOR1.write(135);
  delay(1000);
}
