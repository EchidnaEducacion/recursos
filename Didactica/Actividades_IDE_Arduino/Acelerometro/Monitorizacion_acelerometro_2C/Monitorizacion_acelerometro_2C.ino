/*
  Programa para monitorizar el acelerómetro LIS3DH por I2C
  en EchidnaBlack2C y mostrar sus ejes en el serial plotter.
*/

#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_LIS3DH lis = Adafruit_LIS3DH();
float xValue = 0.0;
float yValue = 0.0;

void setup() {
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

  xValue = event.acceleration.x;
  yValue = event.acceleration.y;

  Serial.print(xValue);
  Serial.print("\t");
  Serial.println(yValue);
  delay(100);
}
