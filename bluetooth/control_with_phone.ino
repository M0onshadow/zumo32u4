#include <Wire.h> 
#include <Zumo32U4.h>

Zumo32U4Motors motors;
Zumo32U4LCD lcd;

String PrgZumo = "";
int Pos1;
int Pos2;
int led13=13;
int led12=12;
int led11=11;
 
#define RxD         10
#define TxD         11
#define PINLED      9
#define LEDON()     digitalWrite(PINLED, HIGH)
#define LEDOFF()    digitalWrite(PINLED, LOW)
#define DEBUG_ENABLED  1
 
void setup() {
  Serial1.begin(9600);
  pinMode(RxD, INPUT);
  pinMode(TxD, OUTPUT);
}
 
void loop() {
   if (Serial1.available()) {
    PrgZumo = Serial1.readStringUntil('\n');
    Serial.println(PrgZumo);
   }

   if (PrgZumo == "Avancer") {
    motors.setRightSpeed(300);
    motors.setLeftSpeed(300);
   }
   
   if (PrgZumo == "Reculer") {
    motors.setRightSpeed(-300);
    motors.setLeftSpeed(-300);
   }

   if (PrgZumo == "Gauche") {
    motors.setRightSpeed(100);
    motors.setLeftSpeed(-100);
    delay(500);
   }

   if (PrgZumo == "Droite") {
    motors.setRightSpeed(-100);
    motors.setLeftSpeed(100);
    delay(500);
   }

   if (PrgZumo == "Stop") {
    motors.setRightSpeed(0);
    motors.setLeftSpeed(0);
   }
}
