#include <SoftwareSerial.h>
SoftwareSerial SIM900(7, 8);//Configuración de los pines serial por software
char caracter=0;// Variable para guardar los caracteres mensajes entrantes
int led=12;
String estado="";
void setup() {
  SIM900.begin(19200);//Arduino se comunica con el SIM900 a una velocidad de 19200bps
  Serial.begin(19200);//Velocidad del puerto serial de arduino 
  delay(20000);//Tiempo prudencial para el escudo inicie sesión de red con tu operador
  pinMode(led, OUTPUT);
  SIM900.print("AT+CMGF=1\r");// comando AT para configurar el SIM900 en modo texto
  delay(200);
  SIM900.print("AT+CNMI=2,2,0,0,0\r");//Configuramos el módulo para que muestre los SMS por el puerto serie.
  delay(200);
}
void loop() {  
  if(SIM900.available() >0) {//Verificamos si hay datos disponibles desde el SIM900
    caracter=SIM900.read(); // Leemos los datos y los almcanamos en la variable mensaje
    Serial.print(caracter); //Imprime los datos entrantes uno a uno en el terminal serial
    if(caracter=='H'){
      Serial.println("-->enviando mensaje");
      digitalWrite(led, HIGH);
      estado="led encendido";
      }
    if(caracter=='L'){
      Serial.println("-->enviando mensaje");
      digitalWrite(led, LOW);
      estado="led apagado";
      }  
  }
}
