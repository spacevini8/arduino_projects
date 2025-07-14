int ledPin = 13;                // choose the pin for the LED
int inputPin = 9;               // Connect sensor to input pin 3
int buzzer = 10;                //the pin of the active buzzer
int val = 0;                    // variable for reading the pin status
 
void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare push button as input
  pinMode(buzzer, OUTPUT); //initialize the buzzer pin as an output
  Serial.begin(9600);           // initialize serial communication at 9600 bps
}
 
void loop(){
  val = digitalRead(inputPin);  // read input value
  Serial.println(val);          // print the value to the serial monitor
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, LOW);  // turn LED OFF
    digitalWrite(buzzer, LOW);  // turn buzzer OFF
  } else {
    digitalWrite(ledPin, HIGH); // turn LED ON
    digitalWrite(buzzer, HIGH); // turn buzzer ON
  }
}