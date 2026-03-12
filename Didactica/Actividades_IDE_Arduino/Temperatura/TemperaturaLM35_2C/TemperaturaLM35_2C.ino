/*
 Medida de temperatura con sensor LM35
 Mostramos la temperatura por el monitor serie
 Usamos analogReference para aumentar la precision de la medida del sensor
 Referencia 1.1 valido para micro Atmega328= Arduino UNO

 Sensor LM35: 
 pin V del sensor conectado a 5V de Arduino
 pin central del sensor Vout a A6 de Arduino
 pin GND a GND de Arduino
 
 */

// constantes que no cambian
const int LM35Pin = A6;     // pin de temperatura en EchidnaBlack2C

// variables globales que cambian
float temperatura = 0;         // variable para almacenar la temperatura medida

// Configuración
void setup() {
  
  Serial.begin(9600); // configuramos la velocidad de conexion con el puerto serie del PC

}

// Bucle que se repite
void loop() {
  int lectura = analogRead(LM35Pin); // valor entre 0 y 1023
  temperatura = (lectura * 0.4658) - 50.0; // Conversión ajustada a EchidnaBlack2C

  Serial.print("Temperatura: ");  
  Serial.print(temperatura);  // mostramos el valor de la temperatura 
  Serial.println(" ºC");
  delay(1000);              // tiempo de espera de 1s
}
