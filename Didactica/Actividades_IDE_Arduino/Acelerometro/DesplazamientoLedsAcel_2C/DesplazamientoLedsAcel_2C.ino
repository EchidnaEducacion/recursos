/*
  Desplazamiento LEDs con el acelerómetro LIS3DH por I2C para EchidnaBlack2C.
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
const float strongTilt = 8.0;

// variables que cambian
float yAcelValue = 0.0;  // valor del eje Y del acelerómetro
int contador = 1; // contador para encender los leds
int sentido = 0;  // sentido desplazamiento contador
int tiempo = 500; // tiempo- velocidad desplazamiento leds

Adafruit_LIS3DH lis = Adafruit_LIS3DH();

int mapTiltToDelay(float value, float inMin, float inMax) {
  float clamped = constrain(value, inMin, inMax);
  return (int)(500.0 - ((clamped - inMin) * 490.0 / (inMax - inMin)));
}

void setup() {
  // establece los LEDs como salidas
  pinMode(ledGPin, OUTPUT);
  pinMode(ledOPin, OUTPUT);
  pinMode(ledRPin, OUTPUT);
  pinMode(ledBPin, OUTPUT);
  if (!lis.begin(0x18)) {
    while (true) {
      delay(100);
    }
  }

  lis.setRange(LIS3DH_RANGE_2_G);
}

// la funcion loop se ejecuta repetidamente de forma infinita
void loop() {
  sensors_event_t event;
  lis.getEvent(&event);
  yAcelValue = event.acceleration.y;

  if (yAcelValue < -slightTilt) {
    sentido = -1;
    tiempo = mapTiltToDelay(-yAcelValue, slightTilt, strongTilt);
  }
  else if (yAcelValue < slightTilt) {
    sentido = 0;
    tiempo = 500;
  }
  else {
    sentido = 1;
    tiempo = mapTiltToDelay(yAcelValue, slightTilt, strongTilt);
  }

  contar(); // se llama a la función contar

  encenderleds();  // se llama a la funcion encender leds

  delay(tiempo);   // espera tiempo

}

void contar() {
  if (sentido == 1) contador = contador + 1;
  if (sentido == -1) contador = contador - 1;
  if (contador > 4)contador = 1;
  if (contador < 1) contador = 4;
}

void encenderleds() {

  if (contador == 1) {
    digitalWrite(ledGPin, HIGH); // establece 5v en el pin del LED verde
  }
  else {
    digitalWrite(ledGPin, LOW); // establece 0v en el pin del LED verde
  }
  if (contador == 2) {
    digitalWrite(ledOPin, HIGH); // establece 5v en el pin del LED verde
  }
  else {
    digitalWrite(ledOPin, LOW); // establece 0v en el pin del LED verde
  }
  if (contador == 3) {
    digitalWrite(ledRPin, HIGH); // establece 5v en el pin del LED verde
  }
  else {
    digitalWrite(ledRPin, LOW); // establece 0v en el pin del LED verde
  }
  if (contador == 4) {
    digitalWrite(ledBPin, HIGH); // establece 5v en el pin del LED verde
  }
  else {
    digitalWrite(ledBPin, LOW); // establece 0v en el pin del LED verde
  }

}
