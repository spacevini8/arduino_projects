int pin1 = 4;
int pin2 = 7;
int pin3 = 8;
int pin4 = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode (pin1,OUTPUT);
  pinMode (pin2,OUTPUT);
  pinMode (pin3,OUTPUT);
  pinMode (pin4,OUTPUT);
}

int time = 200;
int time2 = 500;
int time3 = 100;

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (pin1,HIGH);
  digitalWrite (pin2,LOW);
  digitalWrite (pin3,HIGH);
  digitalWrite (pin4,LOW);
  delay(time);
  digitalWrite (pin1,LOW);
  digitalWrite (pin2,HIGH);
  digitalWrite (pin3,LOW);
  digitalWrite (pin4,HIGH);
  delay(time);
  digitalWrite (pin1,HIGH);
  digitalWrite (pin2,LOW);
  digitalWrite (pin3,HIGH);
  digitalWrite (pin4,LOW);
  delay(time);
  digitalWrite (pin1,LOW);
  digitalWrite (pin2,LOW);
  digitalWrite (pin3,LOW);
  digitalWrite (pin4,LOW);
  delay(time);
  digitalWrite (pin1,HIGH);
  digitalWrite (pin2,HIGH);
  digitalWrite (pin3,HIGH);
  digitalWrite (pin4,HIGH);
  delay(time2);
  digitalWrite (pin1,LOW);
  digitalWrite (pin2,LOW);
  digitalWrite (pin3,LOW);
  digitalWrite (pin4,LOW);
  delay(time);
  digitalWrite (pin1,HIGH);
  delay(time3);
  digitalWrite (pin2,HIGH);
  delay(time3);
  digitalWrite (pin3,HIGH);
  delay(time3);
  digitalWrite (pin4,HIGH);
  delay(time2);
  digitalWrite (pin1,LOW);
  digitalWrite (pin2,LOW);
  digitalWrite (pin3,LOW);
  digitalWrite (pin4,LOW);
  delay(time2);
}
