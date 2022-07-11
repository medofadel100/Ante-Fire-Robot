  /*
   * The code for Ante Fire Robot ^_^
   * The Code Writen by :
   *  Ahmed Fadel (Team Work Leader) you can follow me on Facebook from here
   *  www.fb.com/medofadel48
   *  Ahmed El-Gada'
   *  Mohammed Sabri
   *  Hosam Hasen 
   *  Mo'men 
   *  At 25/4/2017
   *  
   *  { Under Support Semi Engineer Team© }
   *  
   *   this code prepared to make Robot Move Back The Fire and make Alarm  Until it be more Close , it will Stop And Put out Fire 
   *   
   *  component
   *  0- Arduino ONU or Nano
   *  1- Robot 4x Wheel 
   *  2- 2x daul H-bridge
   *  3- 3x Flame Sensor
   *  4- puzzer
   *  5- Relay 
   *  6- Motor pump
   *  
   *  
   *  Method 
   *  conect Degital pin (5,7,8,9,10,11,12,13,7) on Arduino to H-bridge ( or Any  DC Motor Driver)
   *  conect Degital pin (2) on Arduino to Relay 
   *  conect Motor pum to Relay And 12V DC 
   *  conect Left  Flame Sensor to Analog Pin (A0)
   *  conect Front Flame Sensor to Analog Pin (A1)
   *  conect Righr Flame Sensor to Analog Pin (A2)
   *  conect Buzzer to Degital pin (3) on Arduino
   *  
   *  We Sorry For Any Error on Write up
   */
  
  
  
  
  
  
  
  
  
  
  // Motor Pin
int IN1=8;              // input 1 for motor 1
int IN2=9 ;            // input 2 for motor 1
int IN3=10;           // input 1 for motor 2
int IN4=11;          // input 2 for motor 2
int IN5=12;         // input 1 for motor 3
int IN6=13;        // input 2 for motor 3
int IN7=7 ;       // input 1 for motor 4
int IN8=5 ;      // input 1 for motor 4
   //        -------------
int IN9=2;      // OUTPUT for Relay ( Motor pump )
int BZ=3;       //  out put for puzzer
   //        -------------
  // Sensor Analog Pin 
int sensorPin0 = A0;  // Flame Sensor0 pin  (Left Flame)
int sensorValue0 = 0; // Flame Sensor0 Value
int sensorPin1 = A1;  // Flame Sensor1 pin  (Front Flame)
int sensorValue1 = 0; // Flame Sensor1 Value
int sensorPin2 = A2;  // Flame Sensor2 pin  (Right Flame)
int sensorValue2 = 0; // Flame Sensor2 Value
  // -----------------------------------------

   
void setup(){
  
  pinMode (IN1,OUTPUT);
  pinMode (IN2,OUTPUT);
  pinMode (IN3,OUTPUT);
  pinMode (IN4,OUTPUT);
  pinMode (IN5,OUTPUT);
  pinMode (IN6,OUTPUT);
  pinMode (IN7,OUTPUT);
  pinMode (IN8,OUTPUT);
  pinMode (IN9,OUTPUT);
  pinMode (BZ,OUTPUT);
  
  Serial.begin(9600);  //To Test on Serial Monitor 

  
}

  // ------------------------------------------



    //robot Move Forward function
  void forward ()
{
  digitalWrite (IN1,HIGH);
  digitalWrite (IN2,LOW);
  digitalWrite (IN3,HIGH);
  digitalWrite (IN4,LOW);
  digitalWrite (IN5,HIGH);
  digitalWrite (IN6,LOW);
  digitalWrite (IN7,HIGH);
  digitalWrite (IN8,LOW); 
  
}

  //robot Move Right function
  void right()
{
  digitalWrite (IN1,HIGH);
  digitalWrite (IN2,LOW);
  digitalWrite (IN3,HIGH);
  digitalWrite (IN4,LOW);
  digitalWrite (IN5,HIGH);
  digitalWrite (IN6,LOW);
  digitalWrite (IN7,LOW);
  digitalWrite (IN8,LOW);
  
}

  //robot Move Left function
  void left()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  digitalWrite(IN5,LOW);
  digitalWrite(IN6,LOW);
  digitalWrite(IN7,HIGH);
  digitalWrite(IN8,LOW);
  
}

  //robot move back function
  void back()
{ 
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  digitalWrite(IN5,LOW);
  digitalWrite(IN6,HIGH);
  digitalWrite(IN7,LOW);
  digitalWrite(IN8,HIGH);
  
}

  //robot Stop function
  void stoop(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  digitalWrite(IN5,LOW);
  digitalWrite(IN6,LOW);
  digitalWrite(IN7,LOW);
  digitalWrite(IN8,LOW);
  
}

  // to Move Back Fire
  void flam(){
  sensorValue0 = analogRead(sensorPin0);
  sensorValue1 = analogRead(sensorPin1);
  sensorValue2 = analogRead(sensorPin2);
   if (sensorValue0 <= 700) 
{
  left ();
  digitalWrite(BZ,HIGH);
 // Serial.println("L"); // for test without conect Motor
  
}

else if (sensorValue1 <= 700) 
{
  forward ();
  digitalWrite(BZ,HIGH);
 Serial.println("F");  // for test without conect Motor
 
}

else if (sensorValue2 <= 700) 
{
  right ();
  digitalWrite(BZ,HIGH);
 Serial.println("R");  // for test without conect Motor
  
}
else
{
  // if there no fire he will stop
  stoop();
 Serial.println("S");  // for test without conect Motor
}

}

  // --------------------------------------------------------------

  
void loop(){
  
  sensorValue0 = analogRead(sensorPin0);
  sensorValue1 = analogRead(sensorPin1);
  sensorValue2 = analogRead(sensorPin2);
  
  
  if (analogRead(sensorPin1)<=45 ) {
    // if robot more close he will stop and put out the Fire
  stoop();
  //pump Action
  digitalWrite(IN9,HIGH);
  Serial.println("pump"); // for test without conect Motor pump
  
  }
  else if(analogRead(sensorPin1)>45)
  {
   // if the fire far robot will move back Fire
    flam();
    digitalWrite(IN9,LOW);
  }
}

/*
............................./´¯/) ..............
...........................,/¯.. /...............
.........................../..../ ...............
....................../´¯/'...'/´¯¯`·¸ ..........
................../'/.../..../......./¨¯\ .......
.................('(...´...´.... ¯~/'...') ......
.................\.................'...../ ......
....................''...\.......... _.·´ .......
.....................\..............(............
......................\.............\............
*/
