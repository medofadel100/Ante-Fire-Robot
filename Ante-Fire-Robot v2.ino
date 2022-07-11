#define motorpin0 8 // Direction ch1 front right motor
#define motorpin1 6 // Direction ch2 front left motor
#define motorpin2 4 // Direction ch3 back right motor
#define motorpin3 2 // Direction ch4 back left motor
#define speedpin0 9 //Speed Ch1
#define speedpin1 7 //Speed Ch2
#define speedpin2 5 //Speed Ch3
#define speedpin3 3 //Speed Ch4

#define Pump 26 //Motor PUMP
#define FlameR 22 //Flame Right
#define FlameM 23 //Flame Medile
#define FlameL 24 //Flame Left

#define Buzzer 25 //Flame Right

#define echoPin 12
#define trigPin 11
int maximumRange = 100;
long duration , distance ;

int x=0;

#include <Wire.h>
#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 10; 
// Create a servo object 
Servo Servo1;

#include <Wire.h> // Library for I2C communication
#include <LiquidCrystal_I2C.h> // Library for LCD
// Wiring: SDA pin is connected to A4 and SCL pin to A5.
// Connect to LCD via I2C, default address 0x27 (A0-A2 not jumpered)
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); // Change to (0x27,20,4) for 20x4 LCD.

void setup() {

  lcd.init();
  lcd.backlight();

 Servo1.attach(servoPin); 
//the motor control wires are outputs
pinMode (motorpin0, OUTPUT);
pinMode(motorpin1, OUTPUT);
pinMode(motorpin2, OUTPUT);
pinMode(motorpin3, OUTPUT);

//PWM Pins are outputs
pinMode(speedpin0, OUTPUT);
pinMode(speedpin1, OUTPUT);
pinMode(speedpin2, OUTPUT);
pinMode(speedpin3, OUTPUT);

pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

Servo1.write(90); 
      

}

void loop() {
  
    analogWrite(speedpin0,255);
    analogWrite(speedpin1,255);
    analogWrite(speedpin2,255);
    analogWrite(speedpin3,255);
    
  switch (x)
  {
    case 0: //forward
   Forword ();
   delay (1000);
   break;
    
    case 1: //Turn right
    Right() ;
    delay (1000);
    break;
    
    case 2: //backward
    Back();
    delay (1000);
    break;
    
   
    case 3: //Turn left
    Left() ;
    delay(1000);
    break;
}

Flame ();
}

void Flame (){
  if ( FlameR > FlameL && FlameR > FlameM && FlameR  == HIGH ){
    Right();
  lcd.setCursor(0, 0); 
  lcd.print("Fire on Right!"); 
  delay(1000);
    
  }

  else if ( FlameM > FlameL && FlameM > FlameR && FlameM  == HIGH ){
    Forword ();
    lcd.setCursor(0, 0); 
  lcd.print("Fire on Forword!"); 
  delay(1000); 
  }

  else if ( FlameL > FlameM && FlameL > FlameR && FlameL  == HIGH ){
    Left ();
    lcd.setCursor(0, 0); 
  lcd.print("Fire on Left!"); 
  delay(1000); 
  }

}

void des(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);  //measure time 
  distance = duration / 58.2;  //calculate distance 
}

void Right(){
    analogWrite(speedpin0,50);
    analogWrite(speedpin2,50);
    
    digitalWrite(motorpin0,1);
    digitalWrite(motorpin1,1);
    digitalWrite(motorpin2,1);
    digitalWrite(motorpin3,1);
}
void Forword (){
des();
 if (distance >= maximumRange && distance >= 15) {
    digitalWrite(motorpin0,1);
    digitalWrite(motorpin1,1);
    digitalWrite(motorpin2,1);
    digitalWrite(motorpin3,1);
    delay(500);
  }
  else if ( distance <= 15 ) {
    Stop();
     if (  FlameM  == HIGH ){
        digitalWrite(Pump, HIGH); 
        servo(); 
       lcd.setCursor(0, 0); 
       lcd.print("Pump ON"); 
      }
      else {
      digitalWrite(Pump, LOW);  
      }
    
    delay(500);
}}
void Left(){
    analogWrite(speedpin1,50);
    analogWrite(speedpin3,50);
 
    digitalWrite(motorpin0,1);
    digitalWrite(motorpin1,1);
    digitalWrite(motorpin2,1);
    digitalWrite(motorpin3,1);
}

void Back(){
    digitalWrite(motorpin0,0);
    digitalWrite(motorpin1,0);
    digitalWrite(motorpin2,0);
    digitalWrite(motorpin3,0);
}

void Stop(){
    analogWrite(speedpin0,0);
    analogWrite(speedpin1,0);
    analogWrite(speedpin2,0);
    analogWrite(speedpin3,0);
    
    digitalWrite(motorpin0,0);
    digitalWrite(motorpin1,0);
    digitalWrite(motorpin2,0);
    digitalWrite(motorpin3,0);
}

void servo(){
  Servo1.write(0); 
        delay(1000); 
       // Make servo go to 90 degrees 
       Servo1.write(90); 
       delay(1000); 
       // Make servo go to 180 degrees 
       Servo1.write(180); 
       delay(1000);
}
