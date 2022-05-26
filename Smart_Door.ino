#include <Servo.h>
#define MAX_DISTANCE 500
Servo servo, servo1;

int pinTrigger = 12;
int pinEcho = 13;
int pinHijau = 10;
int pinMerah = 11;
float durasi,jarak;

void setup ()
{
  pinMode(pinTrigger, OUTPUT);
  pinMode(pinEcho, INPUT);
  pinMode(pinHijau, OUTPUT);
  pinMode(pinMerah, OUTPUT);
  
  Serial.begin(9600);
  servo.attach(9);
  servo1.attach(5);
}

void loop()
{
  digitalWrite(pinTrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(pinTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrigger, LOW);
  
  durasi = pulseIn(pinEcho, HIGH);
  jarak = (durasi * 0.034 / 2);
  
  Serial.print(jarak);
  Serial.println("cm");
  if (jarak <= 200)
  {
    digitalWrite (pinHijau, LOW);
    digitalWrite (pinMerah, HIGH);
    servo.write(90);
    servo1.write(90);
  }
  else
  {
    digitalWrite(pinMerah, LOW);
    digitalWrite(pinHijau, HIGH);
    servo.write(0);
    servo1.write(0);
  }
  delay(1000);
}
