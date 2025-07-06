const int Led1 = 3;
const int Led2 = 5;
const int Led3 = 6;
const int Led4 = 9;

const int PotPin = A2;
const int buttonPin = 11;

//int val;
//int pwm;

void setup() {
  // put your setup code here, to run once:
  pinMode (Led1,OUTPUT);
  pinMode (Led2,OUTPUT);
  pinMode (Led3,OUTPUT);
  pinMode (Led4,OUTPUT);
  pinMode (buttonPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead (PotPin);
  int pwm = map(val,0,1023,0,255);
  int LedQuant = map(val,0,1023,0,4);
  //analogWrite(Led1,pwm);
  //analogWrite(Led2,pwm);
  //analogWrite(Led3,pwm);
  //analogWrite(Led4,pwm);
  Serial.println(pwm);
  if (LedQuant == 0) {
  digitalWrite(Led1,LOW);
  digitalWrite(Led2,LOW);
  digitalWrite(Led3,LOW);
  digitalWrite(Led4,LOW);
  }
  if (LedQuant == 1) {
  digitalWrite(Led1,HIGH);
  digitalWrite(Led2,LOW);
  digitalWrite(Led3,LOW);
  digitalWrite(Led4,LOW);
  }
  if (LedQuant == 2) {
  digitalWrite(Led1,HIGH);
  digitalWrite(Led2,HIGH);
  digitalWrite(Led3,LOW);
  digitalWrite(Led4,LOW);
  }
  if (LedQuant == 3) {
  digitalWrite(Led1,HIGH);
  digitalWrite(Led2,HIGH);
  digitalWrite(Led3,HIGH);
  digitalWrite(Led4,LOW);
  }
  if (LedQuant == 4) {
  digitalWrite(Led1,HIGH);
  digitalWrite(Led2,HIGH);
  digitalWrite(Led3,HIGH);
  digitalWrite(Led4,HIGH);
  }
}
