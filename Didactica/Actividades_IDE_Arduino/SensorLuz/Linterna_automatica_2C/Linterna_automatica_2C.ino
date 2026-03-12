/*
   Linterna automática
   Sistema para controlar el encendido de un LED RGB
   en funcion de la intensidad luminosa
   Con poca luz ilumina de color blanco, con mucha lu se apaga

   LDR pin A3 para EchidnaBlack2C
   LED RGB pines 9, 5, 6 

   Noviembre 207
   Jose Pujol
*/

// variables constantes para los pines
const int ldrPin = A3;    // pin de la LDR en EchidnaBlack2C
// pines del LED RGB
const int ledRPin = 9; // establece el pin del LED rojo
const int ledGPin = 5; // establece el pin del LED verde
const int ledBPin = 6; // establece el pin del LED azul


// variables que pueden cambiar
int ldrValue = 0; // variable para almacenar el valor de la LDR
int ldrlevel = 200; // nivel de cambio del valor de la LDR

void setup() {
  // establece el LED como una salida
  pinMode(ledRPin, OUTPUT);
  pinMode(ledGPin, OUTPUT);
  pinMode(ledBPin, OUTPUT);
}

void loop() {
  // lee el valor del sensor
  ldrValue = analogRead(ldrPin);
  // si el valor es menor enciende los LEDs
  if (ldrValue < ldrlevel) {
    digitalWrite(ledRPin, HIGH);
    digitalWrite(ledGPin, HIGH);
    digitalWrite(ledBPin, HIGH);
  }
  // sino los apaga
  else {
    digitalWrite(ledRPin, LOW);
    digitalWrite(ledGPin, LOW);
    digitalWrite(ledBPin, LOW);
  }
}
