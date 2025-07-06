const int buttonPin = 12;

const int Led1 = 3;
const int Led2 = 5;
const int Led3 = 6;
const int Led4 = 9;

int buttonState;

int TimeBlnk = 50;

int presschk = false;

void setup() {
  // put your setup code here, to run once:
  pinMode (buttonPin,INPUT);
  pinMode (Led1,OUTPUT);
  pinMode (Led2,OUTPUT);
  pinMode (Led3,OUTPUT);
  pinMode (Led4,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (presschk == false) {
    if (buttonState == HIGH) {
      presschk = true;
    }
  }

  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  if (buttonState == LOW) {
    digitalWrite (Led4,LOW);
    delay(TimeBlnk);
    digitalWrite (Led3,LOW);
    delay(TimeBlnk);
    digitalWrite (Led2,LOW);
    delay(TimeBlnk);
    digitalWrite (Led1,LOW);
  }
  if (buttonState == HIGH) {
    digitalWrite (Led1,HIGH);
    delay(TimeBlnk);
    digitalWrite (Led2,HIGH);
    delay(TimeBlnk);
    digitalWrite (Led3,HIGH);
    delay(TimeBlnk);
    digitalWrite (Led4,HIGH);
  }
}
