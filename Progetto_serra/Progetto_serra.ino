#include <Servo.h>

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 6
#define DHTTYPE DHT22
#define SERVOFINESTRAPIN 7
#define SERVOTENDAPIN 9 
#define PULSANTEPIN 4
#define FOTORESISTOREPIN A4
#define UMIDITASUOLOPIN A5
#define RELEPIN 2

int statopulsante = digitalRead(PULSANTEPIN), acqua = analogRead(UMIDITASUOLOPIN), luce = analogRead(FOTORESISTOREPIN), caso = 0;
bool pulsantepremuto = false, isArduinoOn = false;

DHT dht(DHTPIN, DHTTYPE);
Servo ServoFinestra;
Servo ServoTenda;

void programma(){
  acqua = analogRead(UMIDITASUOLOPIN);
  luce = analogRead(FOTORESISTOREPIN);
  float t = dht.readTemperature(), h = dht.readHumidity();

  /*if(statopulsante == HIGH && pulsantepremuto == false){
    pulsantepremuto = true;
  }
  */

  /*
  if(service == false){
    if(statopulsante == HIGH){
      service = true;
      delay(2000);
    }
  }
  */

  if(isnan(t)){
    Serial.println("Errore lettura temperatura/umidità");
    return;
  }

  Serial.print("Acqua: ");
  Serial.println(acqua);

  if(acqua >= 500){
    digitalWrite(RELEPIN, HIGH);
  }
  else{
    digitalWrite(RELEPIN, LOW);
  }

  if(t >= 28.0){
    // temperatura alta, luce alta
    if(luce >= 450){
      caso = 0;
    }
    else{
      caso = 1;
    }
  }
  else {
    if(luce >= 450){
      // temperatura bassa, luce alta  
      caso = 2;
    }
    else {
      // temperatura bassa, luce bassa, suolo umido
      if(acqua >= 894){
        caso = 3;
      }
      else{
        caso = 4;
      }
    //caso = 3;
    }
  }

  /*if(t < 28.0 && luce < 450 && acqua < 894){
    // temperatura bassa, luce bassa, suolo secco
    caso = 4;
  }*/
  Serial.println(" ");
  Serial.print("Caso");
  Serial.print(" ");
  Serial.print(caso);
  Serial.println(" ");
  switch(caso){
    
    case 0:
      ServoFinestra.write(90); // finestra aperta
      Serial.println("Tenda chiusa");
      ServoTenda.write(0); // tenda chiusa
      break;
    case 1:
      ServoFinestra.write(90); // finestra aperta
      Serial.println("Tenda aperta");
      ServoTenda.write(180); // tenda aperta
      break;
    case 2:
      ServoFinestra.write(0); // finestra chiusa
      ServoTenda.write(0); // tenda chiusa
      break;
    case 3:
      ServoFinestra.write(0); // finestra chiusa
      ServoTenda.write(180); // tenda aperta
      digitalWrite(RELEPIN, LOW); // chiusura rubinetto
      break;
    case 4:
      ServoFinestra.write(0); // finestra chiusa
      ServoTenda.write(180); // tenda aperta
      digitalWrite(RELEPIN, HIGH); // apertura rubinetto
      break;
  }

  Serial.print("Sensore di luminosità: ");
  Serial.println(analogRead(FOTORESISTOREPIN));

  Serial.print("Umidità del suolo: ");
  Serial.println(analogRead(UMIDITASUOLOPIN));

  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println("°C");

  Serial.print("Umidità: ");
  Serial.print(h);
  Serial.println("%");

  //finestra(t);
  
  /*
  if(t>=28){
    Serial.println("Apro finestra");
  }
  else{
    Serial.println("Chiudo finestra");
  }
  */

  delay(200);
}

void spegnimento(){
  ServoTenda.write(180);
  ServoFinestra.write(0);
  digitalWrite(RELEPIN, LOW);
  Serial.println("Arudino spento");
}

void finestra(float t){
  if(t >= 28.0){
    ServoFinestra.write(0);
  }
  else{
    ServoFinestra.write(180);
  }
  delay(500);
}

void setup() {
  pinMode(FOTORESISTOREPIN, INPUT);
  pinMode(UMIDITASUOLOPIN, INPUT);
  pinMode(RELEPIN, OUTPUT);
  ServoFinestra.attach(SERVOFINESTRAPIN);
  ServoTenda.attach(SERVOTENDAPIN);
  Serial.begin(9600);
  Serial.println("Lettura sensore DHT22...");
  dht.begin();
}

void loop() {
  statopulsante = digitalRead(PULSANTEPIN);
  if(statopulsante != pulsantepremuto){
    if(statopulsante == HIGH){
      isArduinoOn = !isArduinoOn;
      if(isArduinoOn){
        programma();
      }
      else{
        spegnimento();
      }
    
    }
    delay(50);  
  }
  pulsantepremuto = statopulsante;
  if(isArduinoOn){
    programma();
  }
}
