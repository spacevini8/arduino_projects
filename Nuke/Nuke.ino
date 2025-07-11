#include <LiquidCrystal.h>

int nukebutton = 7; // Pin for the nuke button
int NukeLedPin = 6; // Pin for the LED
int buzzerPin = 10; // Pin for the buzzer

int currentButton;

bool ledState = false;
int lastButtonState = HIGH;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {

    lcd.begin(16, 2);

    pinMode(nukebutton, INPUT_PULLUP);
    pinMode(NukeLedPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    
    lcd.setCursor(0, 0);
    lcd.print("Nuke Time!");
  
    lcd.setCursor(0, 1);
    lcd.print("All systems on");

    digitalWrite(NukeLedPin, LOW);

    Serial.begin(115200);
    
}

void playEnableTones() {
    tone(buzzerPin, 1000, 150);
    delay(200);
    tone(buzzerPin, 1500, 150);
    delay(200);
    noTone(buzzerPin);

    while (ledState) {
        tone(buzzerPin, 2000, 100);
        delay(250);
        tone(buzzerPin, 1500, 100);
        delay(250);
        tone(buzzerPin, 1000, 100);
        delay(250);
        tone(buzzerPin, 1500, 100);
        delay(250);
        noTone(buzzerPin);

        currentButton = digitalRead(nukebutton);
        if (lastButtonState == HIGH && currentButton == LOW) {
            ledState = false;
            digitalWrite(NukeLedPin, LOW);
            playOffTones();
            delay(200);
            break;
        }
        lastButtonState = currentButton;
    }
}

void playOffTones() {
    tone(buzzerPin, 1500, 150);
    delay(200);
    tone(buzzerPin, 1000, 150);
    delay(200);
    noTone(buzzerPin);
    configureLCDOff();
    delay(1000);
    lcd.clear();
    LCDReset();
}

void configureLCD() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Nuke System");
    lcd.setCursor(0, 1);
    lcd.print("Ready");
}

void configureLCDOff() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Nuke System");
    lcd.setCursor(0, 1);
    lcd.print("Off, goodbye");
}

void LCDReset() {
    lcd.setCursor(0, 0);
    lcd.print("Nuke Time!");
  
    lcd.setCursor(0, 1);
    lcd.print("All systems on");
}

void countdown() {
    for (int i = 10; i >= 0; i--) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Countdown:");
        lcd.setCursor(0, 1);
        lcd.print(i);
        tone(buzzerPin, 1000, 150);
        delay(200);
        tone(buzzerPin, 1500, 150);
        delay(200);
        noTone(buzzerPin);
        delay(600);
    }
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Nuke Launched");
}

void loop() {

    currentButton = digitalRead(nukebutton);

    //Serial.print("Button State: ");
    //Serial.println(currentButton);

    if (currentButton != lastButtonState) {
        delay(20); // debounce
        if (currentButton == LOW) {
            ledState = !ledState;
            digitalWrite(NukeLedPin, ledState ? HIGH : LOW);

            if (ledState) {
                configureLCD();
                delay(1000);
                countdown();
                playEnableTones();
            } else {
                //configureLCDOff();
                playOffTones();
            }
        }
    }
    lastButtonState = currentButton;
}