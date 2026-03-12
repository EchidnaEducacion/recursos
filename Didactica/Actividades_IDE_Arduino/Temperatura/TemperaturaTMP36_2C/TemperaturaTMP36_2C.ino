/*
 Medida de temperatura con sensor TMP36
 Mostramos la temperatura por el monitor serie
 JA. Vacas

 Descripción

 Sensor TMP36 
 pin V del sensor conectado a 5V de Arduino
 pin central del sensor Vout a A0 de Arduino
 pin GND a GND de Arduino
 
 */

// constantes que no cambian
// se usan para establecer los pines
const int TMP36Pin = A6;     // pin de temperatura en EchidnaBlack2C

// variables globales que cambian
float temperatura = 0;         // variable para almacenar la temperatura medida

// Configuración
void setup() {
  Serial.begin(9600); // Configuramos la conexion con el PC

}

// Bucle que se repite
void loop() {
  int lectura = analogRead(TMP36Pin); // Valor entre 0 y 1023
  temperatura = (lectura * 0.4658) - 50.0; // Conversión ajustada a EchidnaBlack2C

  Serial.print("Temperatura:");  
  Serial.print(temperatura);  // Mostramos el valor de la temperatura 
  Serial.println("C");

}
