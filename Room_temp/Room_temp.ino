#include <LiquidCrystal.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

int DHTPIN = 8;
int thermistorPin = A0; // Thermistor pin
int buttonPin = 7;

int delayTime = 500;

DHT dht (DHTPIN,DHT11);

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int buttonState;

void blinkLED() {
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(100);
}

void setup() {
  Serial.begin(9600);

  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(13, OUTPUT);

  // Initialize the DHT sensor
  dht.begin();
  Serial.println("DHT sensor initialized");

  // Initialize the LCD
  lcd.begin(16, 2);
  //lcd.print("hello, world!");

  lcd.setCursor(0, 0);
  lcd.print("Welcome!");
  
  lcd.setCursor(0, 1);
  lcd.print("All systems on");

  delay(1000);

  lcd.clear();
}

void loop() {

  float tempDHT = dht.readTemperature();
  int tempThermistorinit = analogRead(thermistorPin);

  double tempK = log(10000.0 * ((1024.0 / tempThermistorinit - 1)));
  tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK )) * tempK );
  float tempC = tempK - 273.15;

  //float temperature = dht.readTemperature();

  float temperature = (tempDHT + tempC) / 2; // Average temperature from DHT and thermistor
  float humidity = dht.readHumidity();

  buttonState = digitalRead(buttonPin);

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(delayTime);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp: Error");
    lcd.setCursor(0, 1);
    lcd.print("Humid: Error");
    blinkLED();
    return;
  }

  Serial.print("Temperature: "); Serial.print(temperature); Serial.println(" °C");
  Serial.print("TemperatureDHT: "); Serial.print(tempDHT); Serial.println(" °C");
  Serial.print("TemperatureThermistor: "); Serial.print(tempC); Serial.println(" °C");
  
  Serial.print("Humidity: "); Serial.print(humidity); Serial.println(" %");

  Serial.print("Button state: "); Serial.println(buttonState);

  lcd.setCursor(0, 0);
  lcd.print("Temp: " + String(temperature) + " " + char(223) + "C");
  
  lcd.setCursor(0, 1);
  lcd.print("Humid: " + String(humidity) + " %");

  delay(delayTime);
}