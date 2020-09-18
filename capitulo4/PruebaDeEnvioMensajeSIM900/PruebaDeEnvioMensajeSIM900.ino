#include <SoftwareSerial.h>
SoftwareSerial SIM900(7, 8); // Configuración de los pines serial por software

void setup() {
  SIM900.begin(19200);  // Arduino se comunica con el SIM900 a una velocidad de 19200bps
  delay(20000);         // Tiempo prudencial para el escudo inicie sesion de red con tu operador
  enviarSMS();       // Llama a la función enviarSMS()
}

void loop() {
}

void enviarSMS(){
  SIM900.print("AT+CMGF=1\r");                // Comando AT para configurar el SIM900 en modo texto
  delay(200);
  SIM900.println("AT + CMGS = \"930747034\"");    // Reemplazar por el número a enviar el mensaje
  delay(200);
  SIM900.println("visita https://d2magicos.com/"); // Reemplazar por el texto a enviar
  delay(200);
  // Finalizamos este comando con el caracter de sustitución (->) código ASCII 26 para el envio del SMS
  delay(25000);                         // Duración del llamado antes de cortar
  SIM900.println((char)26);
  delay(200);
  SIM900.println();
}
