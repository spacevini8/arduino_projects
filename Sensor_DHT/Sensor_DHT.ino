#include <Servo.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

const int DHTpin = 11;
const int servoPin = 10;

float Temp;
float Humid;

DHT dht (DHTpin,DHT11);
Servo WindowServo;

void finestra(float Temp);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  Serial.println("Begin DHT");
  WindowServo.attach(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  Temp = dht.readTemperature();
  Humid = dht.readHumidity();

  /*
  if (isnan(Temp)) {
    Serial.println("Read Error");
    delay(200);
    return;
  }
  */

  Serial.print("Temperature: "); Serial.print(Temp); Serial.println(" °C");

  Serial.print("Humidity: "); Serial.print(Humid); Serial.println(" %");

  //finestra(Temp);

  delay(500);
}

/*
void finestra(float Temp) {
  if (Temp >= 27) {
    Serial.println("Window Open");
    WindowServo.write(90);
  }
  else {
    Serial.println("Window Closed");
    WindowServo.write(0);
  }
}
*/