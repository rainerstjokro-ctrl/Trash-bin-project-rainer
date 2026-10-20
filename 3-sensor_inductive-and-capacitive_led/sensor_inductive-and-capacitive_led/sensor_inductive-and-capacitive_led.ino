#define SENSOR1 8 // define pint 7 for sensor capacitive
#define ACTION1 9 // define pin 6 as for ACTION led capacitive

#define SENSOR2 10 // define pint 7 for sensor inductive
#define ACTION2 11 // define pin 6 as for ACTION led inductive 



void setup() {
  Serial.begin(9600);// setup Serial Monitor to display information
  pinMode(SENSOR1, INPUT_PULLUP);// define pin as Input  sensor
  pinMode(ACTION1, OUTPUT);// define pin as OUTPUT for ACTION
  pinMode(SENSOR2, INPUT_PULLUP);// define pin as Input  sensor
  pinMode(ACTION2, OUTPUT);// define pin as OUTPUT for ACTION
}

void loop() {
  int L1 =digitalRead(SENSOR1);// read the sensor 
  
      if(L1 == 0){
    Serial.println(" All Clear");
    digitalWrite(ACTION1,LOW);// send singal
    
     }else{

     Serial.println("  === Obstacle detacted");
     digitalWrite(ACTION1,HIGH);// turn the relay ON
     }

  int L2 =digitalRead(SENSOR2);// read the sensor 
  
      if(L2 == 0){
    Serial.println(" All Clear");
    digitalWrite(ACTION2,LOW);// send singal
    
     }else{

     Serial.println("  === Logam detacted");
     digitalWrite(ACTION2,HIGH);// turn the relay ON
     }
  delay(100);
 
}