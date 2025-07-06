int Led1 = 3;
int Led2 = 5;
int Led3 = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode (Led1,OUTPUT);
  pinMode (Led2,OUTPUT);
  pinMode (Led3,OUTPUT);
}

int time = 500;

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (Led1,HIGH);
  digitalWrite (Led2,LOW);
  digitalWrite (Led3,LOW);
  delay (time);
  digitalWrite (Led1,LOW);
  digitalWrite (Led2,HIGH);
  digitalWrite (Led3,HIGH);
  delay (time);
}
