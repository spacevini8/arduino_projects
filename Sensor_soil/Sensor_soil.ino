int soilPin = A5;

void setup() {
  // put your setup code here, to run once:
  pinMode(soilPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(soilPin));
  delay(500);
}
