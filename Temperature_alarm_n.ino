#include <DHT.h>

#define DHTPIN 8
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

int greenLED = 6;
int redLED = 7;
int buzzer = 5;

void setup() {
  dht.begin();
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float temp = dht.readTemperature();

  Serial.println(temp);

  if (temp < 30) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
    digitalWrite(buzzer, LOW);
  } 
  else {
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
    digitalWrite(buzzer, HIGH);
  }

  delay(1000);
}