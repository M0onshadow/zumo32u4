#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4LineSensors lineSensors;
Zumo32U4ProximitySensors proxSensors;
Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;
bool Inter = LOW;

int lineSensorsValue[3];
int proxSensorsValue[2];

void setup(){
  Serial.begin(9600);
  proxSensors.initFrontSensor();
  lineSensors.initThreeSensors();
}

void loop(){

lineSensors.read(lineSensorsValue, QTR_EMITTERS_ON);
  
if (lineSensorsValue[0] > 700){ /* Here, if the robot encounter a black line, he will rotate until it's again on a white area */
   motors.setRightSpeed(200);
   motors.setLeftSpeed(-200);
   ledRed(1);
   delay(100);
   ledRed(0);
   }

if (lineSensorsValue[1] > 700){
   motors.setRightSpeed(200);
   motors.setLeftSpeed(-200);
   ledRed(1);
   delay(100);
   ledRed(0);
   }

if (lineSensorsValue[2] > 700){
   motors.setRightSpeed(200);
   motors.setLeftSpeed(-200);
   ledRed(1);
   delay(100);
   ledRed(0);
   }

proxSensors.read();
proxSensorsValue[0] = proxSensors.countsFrontWithLeftLeds();
proxSensorsValue[1] = proxSensors.countsFrontWithRightLeds();

if (proxSensorsValue[0] >= 2 && proxSensorsValue[1] >= 2){
  motors.setRightSpeed(400);
  motors.setLeftSpeed(400);
  ledGreen(1);
  delay(10);
  ledGreen(0);
  }

  if (lineSensorsValue[0] < 700 && lineSensorsValue[1] < 700 && lineSensorsValue[2] < 700 && proxSensorsValue[0] < 4 && proxSensorsValue[1] < 4){ //If there is a white line and nothing in front of the robot, it start to make circles, to search another robot
  motors.setRightSpeed(200);
  motors.setLeftSpeed(-200);
  ledYellow(1);
  delay(10);
  ledYellow(0);
  }

if (buttonA.isPressed()){ //Stop button
  motors.setRightSpeed(0);
  motors.setLeftSpeed(0);
  delay(2000);
  }
}
