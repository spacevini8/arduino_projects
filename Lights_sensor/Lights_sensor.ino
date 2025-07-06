#include <NewPing.h>

int TrigPin = 11;
int EchoPin = 12;
int MAX_DISTANCE = 1000;

int Led1 = 3;
int Led2 = 7;
int Led3 = 8;
int Led4 = 10;

//long duration;

NewPing sonar(TrigPin, EchoPin, MAX_DISTANCE);

void setup() {
  // put your setup code here, to run once:
  pinMode (TrigPin,OUTPUT);
  pinMode (EchoPin,INPUT);
  pinMode (Led1,OUTPUT);
  pinMode (Led2,OUTPUT);
  pinMode (Led3,OUTPUT);
  pinMode (Led4,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (TrigPin,LOW);
  //digitalWrite (EchoPin,LOW);
  delayMicroseconds (2);
  digitalWrite (TrigPin,HIGH);
  delayMicroseconds (10);
  digitalWrite (TrigPin,LOW);
  long distance = sonar.ping_cm();
  //long duration = pulseIn(EchoPin,HIGH);
  //float distance = (duration * 0.034) / 2;
  //float distance = (duration / 58);
  //delay(500);
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 10) {
    digitalWrite(Led1,HIGH);
    digitalWrite(Led2,HIGH);
    digitalWrite(Led3,HIGH);
    digitalWrite(Led4,HIGH);
  }
  if (distance > 10 && distance < 20) {
    digitalWrite(Led1,HIGH);
    digitalWrite(Led2,HIGH);
    digitalWrite(Led3,HIGH);
    digitalWrite(Led4,LOW);
  }
  if (distance > 20 && distance < 30) {
    digitalWrite(Led1,HIGH);
    digitalWrite(Led2,HIGH);
    digitalWrite(Led3,LOW);
    digitalWrite(Led4,LOW);
  }
  if (distance > 30 && distance < 40) {
    digitalWrite(Led1,HIGH);
    digitalWrite(Led2,LOW);
    digitalWrite(Led3,LOW);
    digitalWrite(Led4,LOW);
  }
  if (distance > 40) {
    digitalWrite(Led1,LOW);
    digitalWrite(Led2,LOW);
    digitalWrite(Led3,LOW);
    digitalWrite(Led4,LOW);
  }

  delay(300);
}
