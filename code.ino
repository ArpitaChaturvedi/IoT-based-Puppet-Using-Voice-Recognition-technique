
#include <SoftwareSerial.h>
#include <Servo.h>
#include<Arduino.h>

Servo s1,s2,s3,s4;  //declare s1 as right hand motor, s2 as right leg motor, s3 as left leg motor and s4 as left hand
int servoPos=0; 
String value;
int i=0;
int TxD = 11;
int RxD = 10;
SoftwareSerial bluetooth(TxD, RxD);

void setup() {
  s1.attach(4);
  s2.attach(5);
  s3.attach(6);
  s4.attach(9);

  
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
 
 if (bluetooth.available())
   {
    value = bluetooth.readString();
     Serial.println(value);
     s1.write(0);
  s2.write(0);
  s3.write(0);
  s4.write(0);
 

    if(value == "hi"){
  s4.write(130);
  delay(500);
  s4.write(0);
  delay(500);
    }
    
     else if(value == "hands up")
    {
   
  s1.write(180);
  s4.write(180);
  delay(500);


    }
    else if(value == "hands down")
    {
   
    s1.write(0);
    s4.write(0);
    }
    else if(value == "walk")
    {
       for(i=0;i<6;i++){
 
   for(servoPos=0;servoPos<=90;servoPos++)
  
  {
    s3.write(servoPos);
    s1.write(servoPos);
    
    
  } delay(500);
  
   for(servoPos=90;servoPos>=0;servoPos--)
  {
    s1.write(servoPos);
    s3.write(servoPos);
    
  }
 
 delay(500);
  for(servoPos=0;servoPos<=90;servoPos++)
  {
    s2.write(servoPos);
    s4.write(servoPos);
  }
 
  delay(500);
   for(servoPos=90;servoPos>=0;servoPos--)
  {
    s2.write(servoPos);
    s4.write(servoPos);
   
  }
 
  delay(500);
   } 
    }
    
    
      else if(value == "jump")
      {
           for(servoPos=0;servoPos<=90;servoPos++)
  
  {
    s2.write(servoPos);
    s3.write(servoPos);
    
    
  } delay(500);
  
   for(servoPos=90;servoPos>=0;servoPos--)
  {
    s2.write(servoPos);
    s3.write(servoPos);
    
  }
      }
  
   }
}
