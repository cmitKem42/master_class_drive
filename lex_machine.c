//
// Ultrasonic HR-SC04 sensor test
//
// http://robocraft.ru
//

#include "Ultrasonic.h"

// sensor connected to:
// Trig - 12, Echo - 13
Ultrasonic ultrasonic(8, 9);
int E1 = 5;     //M1 Speed Control
int E2 = 6;     //M2 Speed Control
int M1 = 4;     //M1 Direction Control
int M2 = 7;     //M1 Direction Control
void setup()
{
  Serial.begin(9600);		// start the serial port
  pinMode(10, OUTPUT);
}
void mel(void){
 
tone(10, 1000, 300);
delay(50);
tone(10, 10, 300);
delay(50);
tone(10, 50, 300);
delay(1000);
tone(10, 10, 300);
delay(50);


}




void run(float des){
  int a=100;
  if (des<10){
   analogWrite (E1,a);      //PWM Speed Control
   digitalWrite(M1,HIGH);   
   analogWrite (E2,a);   
   digitalWrite(M2,LOW);
   mel();
   
  }else
  {
   analogWrite (E1,0);      //PWM Speed Control
   digitalWrite(M1,HIGH);   
   analogWrite (E2,0);   
   digitalWrite(M2,HIGH);
   digitalWrite(10, LOW);
  }
  

}

void loop()
{
  float dist_cm = ultrasonic.Ranging(CM); 
  run(dist_cm);
  Serial.println(dist_cm); 					// print the distance
  
  delay(100); 								// arbitary wait time.
}
