#include <Joystick.h>

Joystick_ Joystick;

void setup() 
{
  Serial.begin(9600);
 // pinMode(A2, INPUT); //Button 3, ring finger
  //pinMode(11, OUTPUT); //Button 3, ring finger
  pinMode(A1, INPUT);//Button 2, middle finger
  pinMode(10, OUTPUT); //Button 2, middle finger
  pinMode(A0, INPUT);//Button 1, index finger
  pinMode(9, OUTPUT);//Button 1, index finger
  Joystick.begin();
}

void loop() 
{
  //INDEX FINGER
  int flex0 = analogRead(A0);
  Serial.println(flex0);
  if(flex0 < 350) {
    Joystick.setButton(0, true);
    digitalWrite(9, HIGH);
  } else if (flex0 > 450) {
    Joystick.setButton(0, false);
    digitalWrite(9, LOW);
    //this is me placing the sensor on the glove and bending my finger, varies a little bit on placement so it's a very rough estimate
  } // lowest value, finger bent, me: 450
  
  

//MIDDLE FINGER

  int flex1 = analogRead(A1);
  Serial.println(flex1);
  if(flex1 < 350) {
    Joystick.setButton(1, true);
    digitalWrite(10, HIGH);
  } else if (flex1 > 450) {
    Joystick.setButton(1, false);
    digitalWrite(10, LOW);
   }
   
  //lowest value, finger bent, me: 375
   
   //RING FINGER
   int flex2= analogRead(A2);
  Serial.println(flex2);
  if(flex2 < 350) {
    Joystick.setButton(2, true);
    digitalWrite(11, HIGH);
  } else if (flex2 > 450) {
    Joystick.setButton(2, false);
    digitalWrite(11, LOW);
  }// lowest value, finger bent, me: kinda janky, around 450
  delay(50);
}

/*
 * This is the arduino in the main code:
 * 
 * 
 * arduinoLeonardo = new Joystick(2);
 * 
 * if (gamepad.getName().equals("Arduino Leonardo")) {
 * int newglove = gamepad.getPort();
 * int newcon = arduinoLeonardo.getPort();
 * gamepad = new Joystick(newcon);
 * arduinoLeonardo = new Joystick(newglove);
 * }
 * 
 * if (extremeJoystick.getName().equals("Arduino Leonardo")){
 * int newjoy = arduinoLeonardo.getPort();
 * int newglove = extremeJoystick.getPort();
 * extremeJoystick = new Joystick(newjoy);
 * arduinoLeonardo = new Joystick(newglove);
 * }
 * //extremejoystick is logitech joystick extreme 3dpro
 * //gamepad = logitech controller (looks like xbox controller)
 * 
 * 
 * 
 * 
 * */
 */
