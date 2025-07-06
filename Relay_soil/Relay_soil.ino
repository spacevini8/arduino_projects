const int relayPin = 2;
int soilPin = A5;

int Acqua;

void setup() {
  // put your setup code here, to run once:
  pinMode(relayPin,OUTPUT);
  pinMode(soilPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(soilPin));
  delay(500);
  Acqua = analogRead(soilPin);
  
  if (Acqua >= 500) {
    digitalWrite(relayPin,HIGH);
  }
  else {
    digitalWrite(relayPin,LOW);
  }
}
