#include "Ultrasonic.h"

// sensor connected to:
// Trig - 12, Echo - 13
Ultrasonic ultrasonic(8, 9);
int E1 = 5;     //M1 Speed Control
int E2 = 6;     //M2 Speed Control
int M1 = 4;     //M1 Direction Control
int M2 = 7;     //M2 Direction Control
void setup()
{
  Serial.begin(9600);		// start the serial port
}

void drive(int speed, int direct1, int direct2)
{
      analogWrite (E1,speed);      //PWM Speed Control
      digitalWrite(M1,direct1);   
      analogWrite (E2,speed);   
      digitalWrite(M2,direct2);
}
void run(float des){
  int a=200;
  if(des <= 20 && des >= 13){
      drive(0,HIGH,LOW);
  }
  if(des>20){
    for(int i = 0; i < 10; i++)
      drive(a,HIGH,LOW);
  }
  if(des<13){
     for(int i = 0; i < 10; i++)
      drive(a,LOW,HIGH);
  }
}

void loop()
{
  float dist_cm = ultrasonic.Ranging(CM);//READ
  if(dist_cm<60)
    run(dist_cm);
  Serial.println(dist_cm); 					// print the distance
  
  delay(100); 								// arbitary wait time.
}
