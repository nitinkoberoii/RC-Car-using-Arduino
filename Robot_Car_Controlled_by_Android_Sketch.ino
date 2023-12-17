/*
Code Name: Arduino Bluetooth Car with Front and Back Light Control 
Code URI: https://circuitbest.com/category/arduino-projects/
Before uploading the code you have to install the "Adafruit Motor Shield" 
library
Open Arduino IDE >> Go to sketch >> Include Libray >> Manage Librariess... >> 
Search "Adafruit Motor Shield" >> Install the Library
AFMotor Library: https://learn.adafruit.com/adafruit-motor-shield/library install
Author: Make DIY
Author URL: https://circuitbest.com/author/admin/
Description: This program is used to control a robot using an app that 
communicates with Arduino through an HC-05 Bluetooth Module.
App URL: https://bit.ly/3mn6LuZ
Version: 1.0
License: Remixing or Changing this Thing is allowed. Commercial use is not 
allowed.
*/

#include <AFMotor.h>
#include <SoftwareSerial.h>
//initial motors pin
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
int cval;
int Speeed = 255;
void setup()
{
Serial.begin(9600); //Set the baud rate to your Bluetooth module.
}
void loop(){
if(Serial.available() > 0){
cval = Serial.read();
 char val = static_cast<char>(cval);
Serial.print("Received command: ");
Serial.println(val);
Stop(); //initialize with motors stoped

if (val == 'F'){
forward();
}
if (val == 'B'){
back();
}
if (val == 'L'){
left();
}
if (val == 'R'){
right();
}
if (val == 'I'){
topright();
}
if (val == 'J'){
topleft();
}
if (val == 'K'){
bottomright();
}
if (val == 'M'){
bottomleft();
}
if (val == 'T'){
Stop();
}
}
}
void forward()
{
motor1.setSpeed(Speeed); //Define maximum velocity
motor1.run(FORWARD); //rotate the motor clockwise
motor2.setSpeed(Speeed); //Define maximum velocity
motor2.run(FORWARD); //rotate the motor clockwise
motor3.setSpeed(Speeed);//Define maximum velocity
motor3.run(FORWARD); //rotate the motor clockwise
motor4.setSpeed(Speeed);//Define maximum velocity
motor4.run(FORWARD); //rotate the motor clockwise
}
void back()
{
motor1.setSpeed(Speeed); //Define maximum velocity
motor1.run(BACKWARD); //rotate the motor anti-clockwise
motor2.setSpeed(Speeed); //Define maximum velocity
motor2.run(BACKWARD); //rotate the motor anti-clockwise
motor3.setSpeed(Speeed); //Define maximum velocity
motor3.run(BACKWARD); //rotate the motor anti-clockwise
motor4.setSpeed(Speeed); //Define maximum velocity
motor4.run(BACKWARD); //rotate the motor anti-clockwise
}
void left()
{
motor1.setSpeed(Speeed); //Define maximum velocity
motor1.run(BACKWARD); //rotate the motor anti-clockwise
motor2.setSpeed(Speeed); //Define maximum velocity
motor2.run(BACKWARD); //rotate the motor anti-clockwise
motor3.setSpeed(Speeed); //Define maximum velocity
motor3.run(FORWARD); //rotate the motor clockwise
motor4.setSpeed(Speeed); //Define maximum velocity
motor4.run(FORWARD); //rotate the motor clockwise
}
void right()
{
motor1.setSpeed(Speeed); //Define maximum velocity
motor1.run(FORWARD); //rotate the motor clockwise
motor2.setSpeed(Speeed); //Define maximum velocity
motor2.run(FORWARD); //rotate the motor clockwise
motor3.setSpeed(Speeed); //Define maximum velocity
motor3.run(BACKWARD); //rotate the motor anti-clockwise
motor4.setSpeed(Speeed); //Define maximum velocity
motor4.run(BACKWARD); //rotate the motor anti-clockwise
}
void topleft(){
motor1.setSpeed(Speeed); //Define maximum velocity
motor1.run(FORWARD); //rotate the motor clockwise
motor2.setSpeed(Speeed); //Define maximum velocity
motor2.run(FORWARD); //rotate the motor clockwise
motor3.setSpeed(Speeed/3.1);//Define maximum velocity
motor3.run(FORWARD); //rotate the motor clockwise
motor4.setSpeed(Speeed/3.1);//Define maximum velocity
motor4.run(FORWARD); //rotate the motor clockwise
}
void topright()
{
motor1.setSpeed(Speeed/3.1); //Define maximum velocity
motor1.run(FORWARD); //rotate the motor clockwise
motor2.setSpeed(Speeed/3.1); //Define maximum velocity
motor2.run(FORWARD); //rotate the motor clockwise
motor3.setSpeed(Speeed);//Define maximum velocity
motor3.run(FORWARD); //rotate the motor clockwise
motor4.setSpeed(Speeed);//Define maximum velocity
motor4.run(FORWARD); //rotate the motor clockwise
}
void bottomleft()
{
motor1.setSpeed(Speeed); //Define maximum velocity
motor1.run(BACKWARD); //rotate the motor anti-clockwise
motor2.setSpeed(Speeed); //Define maximum velocity
motor2.run(BACKWARD); //rotate the motor anti-clockwise
motor3.setSpeed(Speeed/3.1); //Define maximum velocity
motor3.run(BACKWARD); //rotate the motor anti-clockwise
motor4.setSpeed(Speeed/3.1); //Define maximum velocity
motor4.run(BACKWARD); //rotate the motor anti-clockwise
}
void bottomright()
{
motor1.setSpeed(Speeed/3.1); //Define maximum velocity
motor1.run(BACKWARD); //rotate the motor anti-clockwise
motor2.setSpeed(Speeed/3.1); //Define maximum velocity
motor2.run(BACKWARD); //rotate the motor anti-clockwise
motor3.setSpeed(Speeed); //Define maximum velocity
motor3.run(BACKWARD); //rotate the motor anti-clockwise
motor4.setSpeed(Speeed); //Define maximum velocity
motor4.run(BACKWARD); //rotate the motor anti-clockwise
}
void Stop()
{
motor1.setSpeed(0); //Define minimum velocity
motor1.run(RELEASE); //stop the motor when release the button
motor2.setSpeed(0); //Define minimum velocity
motor2.run(RELEASE); //rotate the motor clockwise
motor3.setSpeed(0); //Define minimum velocity
motor3.run(RELEASE); //stop the motor when release the button
motor4.setSpeed(0); //Define minimum velocity
motor4.run(RELEASE); //stop the motor when release the button
}
