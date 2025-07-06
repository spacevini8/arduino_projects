#include <LiquidCrystal.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

int DHTPIN = 8;
int buttonPin = 7;

int delayTime = 250;

DHT dht (DHTPIN,DHT11);

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int buttonState;

void setup() {
  Serial.begin(9600);

  pinMode(buttonPin, INPUT_PULLUP);

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
  // Read temperature and humidity
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  buttonState = digitalRead(buttonPin);

  // Check if any reads failed and exit early (to try again).
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(delayTime);
    return;
  }

  // Print the values to the Serial Monitor
  Serial.print("Temperature: "); Serial.print(temperature); Serial.println(" °C");
  
  Serial.print("Humidity: "); Serial.print(humidity); Serial.println(" %");

  Serial.print("Button state: "); Serial.println(buttonState);
  // Display on LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: " + String(temperature) + " " + char(223) + "C");
  
  lcd.setCursor(0, 1);
  lcd.print("Humid: " + String(humidity) + " %");

  delay(delayTime); // Wait a few seconds between readings
}