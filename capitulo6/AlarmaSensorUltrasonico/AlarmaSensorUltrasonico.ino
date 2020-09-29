#include <SoftwareSerial.h>
SoftwareSerial SIM900(7, 8); // Configuracion de los pines serial por software

int foco = 12;
int echoPin = 11;
int trigPin = 10;

float distance;

void setup() {
 
  pinMode(foco, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(foco, HIGH);
  Serial.begin(19200);
  SIM900.begin(19200);  // Arduino se comunica con el SIM900 a una velocidad de 19200bps
  delay(20000);         // Tiempo prudencial para el escudo inicie sesion de red con tu operador
  delay(3000);
}

void loop() {

  distance = getDistanceInCm();
  Serial.print("Distance: ");
  Serial.println(distance);
  
  if (distance>0 && distance <= 10) {
    digitalWrite(foco, LOW); //ENCENDEMOS EL FOCO
    Serial.println("Entro");
    delay(2000);
    hacerLlamada();
    delay(1000);
  }else{
    digitalWrite(foco, HIGH); //APAGAMOS EL FOCO
  }
  Serial.println("Salio");
  delay(1000);
}

void hacerLlamada(){
  SIM900.print("ATD");                  // Comando AT para iniciar una llamada
  SIM900.print("930747034");             // Número de telefono al cual queremos llamar
  SIM900.println(";");                  // El ";" indica llamada de voz y no llamada de datos ej:(FAX)
  Serial.println("Llamando...");        // Leyenda que indica que se inicio el llamado
  delay(25000);                         // Duración del llamado antes de cortar
  SIM900.println("ATH");                // Comando AT cortar llamada
  Serial.println("Llamada finalizada"); // Leyenda que indica que finalizó el llamado
}

float getDistanceInCm() {
  float duration, distance;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.0343) / 2;

  return distance;
}
