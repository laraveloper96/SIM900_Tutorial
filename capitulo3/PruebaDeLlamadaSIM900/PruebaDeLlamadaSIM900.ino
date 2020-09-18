#include <SoftwareSerial.h>
SoftwareSerial SIM900(7, 8); // Configuracion de los pines serial por software

void setup() {
  SIM900.begin(19200);  // Arduino se comunica con el SIM900 a una velocidad de 19200bps
  Serial.begin(19200);  // Velocidad del puerto serial de arduino
  delay(20000);         // Tiempo prudencial para que el SIM900 inicie sesion de red con tu operador
  llamar();       // Llama a la función llamar()
}

void loop() {
}

void llamar(){
  SIM900.print("ATD");                  // Comando AT para iniciar una llamada
  SIM900.print("930747034");             // Número de telefono al cual queremos llamar
  SIM900.println(";");                  // El ";" indica llamada de voz y no llamada de datos ej:(FAX)
  Serial.println("Llamando...");        // Leyenda que indica que se inicio el llamado
  delay(25000);                         // Duración del llamado antes de cortar
  SIM900.println("ATH");                // Comando AT cortar llamada
  Serial.println("Llamada finalizada"); // Leyenda que indica que finalizó el llamado
}
