#define SERVO_DX 11
#define SERVO_SX 10
#define IR_ANT_SX 8      // left sensor
#define IR_ANT_DX 9      // right sensor
#define IR_POST_SX A3      // left sensor 2 post
#define IR_POST_DX A2      // right sensor 2 post
#define RDR_SX A5      // left sensor 2 front  
#define RDR_DX A4      // right sensor 2 front

#include <Servo.h>

Servo servoSx;          
Servo servoDx; 
int detection;

void setup()
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  detection = HIGH;
  servoSx.attach(SERVO_DX);  // Set left servo to digital pin 10
  servoDx.attach(SERVO_SX);  // Set right servo to digital pin 9
  pinMode(IR_ANT_SX, INPUT);
  pinMode(IR_ANT_DX, INPUT);
  pinMode(IR_POST_SX, INPUT);
  pinMode(IR_POST_DX, INPUT);
  pinMode(RDR_SX, INPUT);
  pinMode(RDR_DX, INPUT);
}
void ferma(void)
{
  servoSx.detach();
  servoDx.detach();
}


//vel varia tra 0 e 100%
void avanti(int vel)
{
  servoDx.attach(SERVO_DX);
  servoSx.attach(SERVO_SX);
  int angolo;
  if(vel<0)
    vel=0;
  if(vel>100)
    vel=100;

    
  //vel = 90;
  angolo=map(vel,0, 100, 90, 170);
  servoDx.write(angolo);
  servoSx.write(180-angolo);  
}


void indietro(int vel)
{
  servoDx.attach(SERVO_DX);
  servoSx.attach(SERVO_SX);
  int angolo;
  if(vel<0)
    vel=0;
   if(vel>100)
    vel=100;

    angolo=map(vel,0, 100, 90, 10);
    servoDx.write(angolo);
    servoSx.write(180-angolo);
}


void giraDx(int vel)
{
  servoDx.attach(SERVO_DX);
  servoSx.attach(SERVO_SX);
  
  int angolo;
  if(vel<0)
    vel=0;
   if(vel>100)
    vel=100;
   angolo=map(vel,0, 100, 90, 170);
   
   servoDx.write(angolo);
   servoSx.write(angolo);
}

void giraSx(int vel)
{
  servoDx.attach(SERVO_DX);
  servoSx.attach(SERVO_SX);
  int angolo;
  if(vel<0)
    vel=0;
   if(vel>100)
    vel=100;
  angolo=map(vel,0, 100, 90, 10);
    servoDx.write(angolo);
    servoSx.write(angolo);
}

void loop()
{
  if((digitalRead(IR_ANT_SX) !=detection) || (digitalRead(IR_ANT_DX) != detection)||(digitalRead(IR_POST_SX) != detection) || (digitalRead(IR_POST_DX) != detection) )
  {
    digitalWrite (13,HIGH);
    Serial.print("IR_ANT_SX = ");
    Serial.println(IR_ANT_SX);
    Serial.print("IR_ANT_SX = ");
    Serial.println(IR_ANT_DX);
    Serial.print("IR_ANT_SX = ");
    Serial.println(IR_POST_SX);
    Serial.print("IR_ANT_SX = ");
    Serial.println(IR_POST_DX);
    
   }
  if(digitalRead(IR_ANT_SX) && digitalRead(IR_ANT_DX != detection))     // avanti
  {
      avanti(80);
      delay(2500);
  }
  
  if((digitalRead(IR_ANT_SX) == detection) && (digitalRead(IR_ANT_DX)!= detection))     // gira destra
  {
       giraDx(30);
       delay(1000);
  }
  
  if((digitalRead(IR_ANT_SX) != detection) && (digitalRead(IR_ANT_DX) == detection))     // gira sinistra
  {
        giraSx(30);
        delay(1000);
  }
  
  if((digitalRead(IR_ANT_SX) == detection) && (digitalRead(IR_ANT_DX) == detection))     // ferma
  {
       ferma();
       delay(500);

  }
    if((digitalRead(IR_POST_SX) != detection) && (digitalRead(IR_POST_DX) != detection))     // avanti
  {
      avanti(80);
      delay(2500);
  }
  if((digitalRead(IR_POST_SX) != detection) && (digitalRead(IR_POST_DX) == detection))     // gira sinistra
  {
        giraSx(30);
        delay(1000);
  }
    if((digitalRead(IR_POST_SX) == detection) && (digitalRead(IR_POST_DX) != detection))     // gira destra
  {
        giraDx(30);
        delay(1000);
  }
  
   if((digitalRead(IR_POST_SX) == detection) && (digitalRead(IR_POST_DX) == detection))     // ferma
  {
       ferma();
       delay(500);
  }
  
}

