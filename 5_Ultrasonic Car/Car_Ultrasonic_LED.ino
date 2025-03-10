#define led 7
#define led2 8

int izqA = 5; 
int izqB = 6; 
int derA = 9; 
int derB = 10; 
int vel = 255;            // Velocidad de los motores (0-255)
int estado = 'g';         // inicia detenido

int pecho = 2;            // define el pin 2 como (pecho) para el Ultrasonido
int ptrig = 3;            // define el pin 3 como (ptrig) para el Ultrasonido
long duracion, distancia;  // para Calcular distacia

void setup()  { 
  Serial.begin(9600);    // inicia el puerto serial para comunicacion con el Bluetooth
  pinMode(derA, OUTPUT);
  pinMode(derB, OUTPUT);
  pinMode(izqA, OUTPUT);
  pinMode(izqB, OUTPUT);
  
  pinMode(pecho, INPUT);   // define el pin 2 como entrada (pecho) 
  pinMode(ptrig,OUTPUT);   // define el pin 3 como salida  (ptrig) 
  pinMode(13,OUTPUT);
    pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
} 

void loop()  { 

  if(Serial.available()>0){        // lee el bluetooth y almacena en estado
    estado = Serial.read();
  }
  if(estado=='a'){           // Boton desplazar al Frente
    analogWrite(derB, 0);     
    analogWrite(izqB, 0); 
    analogWrite(derA, vel);  
    analogWrite(izqA, vel);       
  }
  if(estado=='b'){          // Boton IZQ 
    analogWrite(derB, 0);     
    analogWrite(izqB, 0); 
    analogWrite(derA, 0);  
    analogWrite(izqA, vel);      
  }
  if(estado=='c'){         // Boton Parar
    analogWrite(derB, 0);     
    analogWrite(izqB, 0); 
    analogWrite(derA, 0);    
    analogWrite(izqA, 0); 
  }
  if(estado=='d'){          // Boton DER
    analogWrite(derB, 0);     
    analogWrite(izqB, 0);
    analogWrite(izqA, 0);
    analogWrite(derA, vel);  
  } 

  if(estado=='e'){          // Boton Reversa
    analogWrite(derA, 0);    
    analogWrite(izqA, 0);
    analogWrite(derB, vel);  
    analogWrite(izqB, vel);      
  }
  
  if (estado =='f'){          // Boton ON,  se mueve sensando distancia 
  
      digitalWrite(ptrig, LOW);  // Added this line
      delayMicroseconds(2); // Added this line
      digitalWrite(ptrig, HIGH);
      delay(10);
     digitalWrite(ptrig, LOW); 
     duracion = pulseIn(pecho, HIGH);              // Lee el tiempo del Echo
     distancia = (duracion/2) / 29;            // calcula la distancia en centimetros
     
      if (distancia < 4) {  // This is where the LED On/Off happens
            digitalWrite(led,HIGH); // When the Red condition is met, the Green LED should turn off
          digitalWrite(led2,LOW);
        }
      else {
            digitalWrite(led,LOW);
            digitalWrite(led2,HIGH);
      }
     
     
     if (distancia <= 15 && distancia >=2){    // si la distancia es menor de 15cm
        digitalWrite(13,HIGH);                 // Enciende LED
        
        analogWrite(derB, 0);                  // Parar los motores por 200 mili segundos
        analogWrite(izqB, 0); 
        analogWrite(derA, 0);    
        analogWrite(izqA, 0); 
        delay (200);
        
        analogWrite(derB, vel);               // Reversa durante 500 mili segundos
        analogWrite(izqB, vel); 
        delay(500);           
        
        analogWrite(derB, 0);                // Girar durante 1100 milisegundos   
        analogWrite(izqB, 0); 
        analogWrite(derA, 0);  
        analogWrite(izqA, vel);  
        delay(1100);
        
        digitalWrite(13,LOW);
     }
     else{                   // Si no hay obstaculos se desplaza al frente  
         analogWrite(derB, 0);     
         analogWrite(izqB, 0); 
         analogWrite(derA, vel);  
         analogWrite(izqA, vel); 
     }
  } //fin estado F
  if(estado=='g'){          // Boton OFF, detiene los motores no hace nada 
     analogWrite(derB, 0);     
     analogWrite(izqB, 0); 
     analogWrite(derA, 0);    
     analogWrite(izqA, 0);
  }
}
