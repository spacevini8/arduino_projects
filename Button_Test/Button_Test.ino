const int  buttonPin = 7;       
const int ledPin = 13; 

bool onAndOff = false;            

int buttonState = 0;  

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
    buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) {
        if (onAndOff == false) {
            onAndOff = true;
            digitalWrite(ledPin, HIGH);     
        } else {
            onAndOff = false;
            digitalWrite(ledPin, LOW);
        }
    }
}