const int PhotoPin = A3;

void setup() {
  // put your setup code here, to run once:
  pinMode(PhotoPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Photo Sensor: ");
  Serial.println(analogRead(PhotoPin));
  delay(200);
}
