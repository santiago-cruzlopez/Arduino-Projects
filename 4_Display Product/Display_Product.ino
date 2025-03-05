//Display Product
#include <Servo.h>
Servo servo1;

int ledPin1 = 7;
int ledPin2 = 2;

#define sensor1 A0

void setup() {
  servo1.attach(3); //PIN DEL SERVOMOTOR #3
  
  pinMode(ledPin1,HIGH);
  pinMode(ledPin2,HIGH);
  
  Serial.begin(9600);
}

void loop() {
  if(sensor1){
    float volts1 = analogRead(sensor1)*0.0048828125;  // valor del sensor * (5/1024)
    int distance = 13*pow(volts1, -1); 
    delay(500);  
  if(distance <= 10){ 
      digitalWrite(ledPin1,HIGH);
      digitalWrite(ledPin2,LOW);
      for (int i = 0; i <= 180; i++){
        // Desplazamos al ángulo correspondiente
        servo1.write(i);
        //Pausa de 25ms
        delay(25);
        }
        // Para el sentido negativo
      for (int i = 179; i > 0; i--){
        // Desplazamos al ángulo correspondiente
        servo1.write(i);
        //Pausa de 25ms
        delay(25);
        }
  }   
  else if(distance >= 10){
    digitalWrite(ledPin1,LOW);
    digitalWrite(ledPin2,HIGH);   
    }    
    delay(250);   
  }  
}
