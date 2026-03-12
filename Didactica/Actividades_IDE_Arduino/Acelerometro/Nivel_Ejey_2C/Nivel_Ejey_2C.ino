/*
  Nivel eje Y con el acelerómetro LIS3DH por I2C para EchidnaBlack2C.
*/

#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

// constantes que no varian
const int ledGPin = 11; // establece el pin del LED verde
const int ledOPin = 12; // establece el pin del LED naranja
const int ledRPin = 13; // establece el pin del LED rojo
const int ledBPin = 6; // establece el pin del LED azul

const float slightTilt = 2.0;
const float strongTilt = 6.0;

Adafruit_LIS3DH lis = Adafruit_LIS3DH();
float yAcelValue = 0.0;

void setup() {
  // establece los LEDs como salidas
  pinMode(ledGPin, OUTPUT);
  pinMode(ledOPin, OUTPUT);
  pinMode(ledRPin, OUTPUT);
  pinMode(ledBPin, OUTPUT);
  Serial.begin(9600);

  if (!lis.begin(0x18)) {
    Serial.println("No se encuentra el LIS3DH");
    while (true) {
      delay(100);
    }
  }

  lis.setRange(LIS3DH_RANGE_2_G);
}

void loop() {
  sensors_event_t event;
  lis.getEvent(&event);
  yAcelValue = event.acceleration.y;

  Serial.println(yAcelValue);

  if (yAcelValue < -strongTilt) {
    digitalWrite(ledGPin, HIGH);
    digitalWrite(ledOPin, LOW);
    digitalWrite(ledRPin, LOW);
    digitalWrite(ledBPin, LOW);
  }
  else if (yAcelValue < -slightTilt) {
    digitalWrite(ledGPin, LOW);
    digitalWrite(ledOPin, HIGH);
    digitalWrite(ledRPin, LOW);
    digitalWrite(ledBPin, LOW);
  }
  else if (yAcelValue < slightTilt) {
    digitalWrite(ledGPin, LOW);
    digitalWrite(ledOPin, LOW);
    digitalWrite(ledRPin, LOW);
    digitalWrite(ledBPin, LOW);
  }
  else if (yAcelValue < strongTilt) {
    digitalWrite(ledGPin, LOW);
    digitalWrite(ledOPin, LOW);
    digitalWrite(ledRPin, HIGH);
    digitalWrite(ledBPin, LOW);
  }
  else {
    digitalWrite(ledGPin, LOW);
    digitalWrite(ledOPin, LOW);
    digitalWrite(ledRPin, LOW);
    digitalWrite(ledBPin, HIGH);
  }
}
