#include <Joystick.h>

Joystick_ Joystick;

void setup() 
{
  Serial.begin(9600);
  pinMode(A2, INPUT); //Button 3, ring finger
  pinMode(11, OUTPUT); //Button 3, ring finger
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
  if(flex0 < 340) {
    Joystick.setButton(0, true);
    digitalWrite(9, HIGH);
  } else if (flex0 > 410) {
    Joystick.setButton(0, false);
    digitalWrite(9, LOW);
  }//760, 625
  //flex0 < 350
  //flex0 > 450
  // aiden: 330, 430
  
  

//MIDDLE FINGER
  int flex1 = analogRead(A1);
  Serial.println(flex1);
  if(flex1 < 375) {
    Joystick.setButton(1, true);
    digitalWrite(10, HIGH);
  } else if (flex1 > 410) {
    Joystick.setButton(1, false);
    digitalWrite(10, LOW);
   }//690, 800
   //aiden: 360, 450n
   
   
   
   //RING FINGER
  int flex2= analogRead(A2);
  Serial.println(flex2);
  if(flex2 < 390) {
    Joystick.setButton(2, true);
    digitalWrite(11, HIGH);
  } else if (flex2 > 420){
    Joystick.setButton(2, false);
    digitalWrite(11, LOW);
  }//700, 800
  //aiden: 370, 440
  delay(50);
}
