#include <Stepper.h>

const int stepsPerRevolution = 200;

Stepper motor1 = Stepper(stepsPerRevolution, 8, 9, 10, 11);
Stepper motor2 = Stepper(stepsPerRevolution, 2, 3, 4, 5);

int LDR1 = A0;
int LDR2 = A1;
int LDR3 = A2;
int LDR4 = A3;

int deger1, deger2, deger3, deger4; 

int yukari, asagi, sag, sol;     
int tolerans = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(LDR1, INPUT);      // LDR resistors
  pinMode(LDR2, INPUT);
  pinMode(LDR3, INPUT);
  pinMode(LDR4, INPUT); 

  Serial.begin(9600);
  motor1.setSpeed(50);
  motor2.setSpeed(50);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  deger1 = analogRead(LDR1);
  deger2 = analogRead(LDR2);
  deger3 = analogRead(LDR3);
  deger4 = analogRead(LDR4);

  yukari = (deger1 + deger2)/2;
  asagi = (deger3 + deger4)/2;
  sag = (deger1 + deger4)/2;
  sol = (deger2 + deger3)/2;

  Serial.print("Deger1: ");
  Serial.println(deger1);
  Serial.print("Deger2: ");
  Serial.println(deger2);
  Serial.print("Deger3: ");
  Serial.println(deger3);
  Serial.print("Deger4: ");
  Serial.println(deger4);
  Serial.println();
  Serial.print("Yukarı: ");
  Serial.println(yukari);
  Serial.print("Aşağı: ");
  Serial.println(asagi);
  //*************** yatay motor **********************
  if(sag == sol) {
     motor1.step(0);
  }
    
  if(sag > sol && (sag-sol) > tolerans) {
    motor1.step(10);
  }
   
  if(sol > sag && (sol-sag) > tolerans) {
    motor1.step(-10);
  }
  
  delay(100);
  
  //************* dikey motor ************************

  if(yukari == asagi) {
     motor2.step(0);
  }
    
  if(yukari > asagi && (yukari-asagi) > tolerans) {
      motor2.step(10);
  }
   
  if(asagi > yukari && (asagi-yukari) > tolerans) {
      motor2.step(-10);
  }
  delay(100);

}