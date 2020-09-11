#include <SoftwareSerial.h>
SoftwareSerial SIM900(7, 8); //TX D7 || RX D8

char caracter; //Caracter que vamos a obtener

void setup() {
  Serial.begin(19200); //Establecemos la comunicación serial del monitor arduino
  SIM900.begin(19200); //Establecemos la comunicación serial del SIM900
}

void loop() {
  
  if(SIM900.available()){ //Si hay caracteres
    caracter = SIM900.read(); //Leer caracteres
    Serial.print(caracter); //Mostrar los caracteres
  }
  if(Serial.available()){
    caracter = Serial.read(); // Leer caracteres en puerto serial por hardware
    SIM900.print(caracter); // Mostrar los caracteres obtenidos
  }
}
