int led1 = 6;    //pin de salida en el arduino
int led2 = 7; 
int led3 = 8; 
int led4 = 9;
int led5 = 10;
int led6 = 11;
int led7= 12;

int pot = 0;
int lectura = 0;
int intensidad = 0;

void setup() {
  Serial.begin(9600);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);
pinMode(led5,OUTPUT);
pinMode(led6,OUTPUT);
pinMode(led7,OUTPUT);
}

void loop() {
  lectura = analogRead(pot);  // pot= potenciometro
  intensidad = map(lectura,0,1023,0,6);
  Serial.println(intensidad); 
  switch (intensidad)
  {
    case 0:
       digitalWrite(led1,HIGH);
       digitalWrite(led2,LOW);
       digitalWrite(led3,LOW);
       digitalWrite(led4,LOW);
       digitalWrite(led5,LOW);
       digitalWrite(led6,LOW);
       digitalWrite(led7,LOW);
       break;
     case 1:
       digitalWrite(led1,HIGH);
       digitalWrite(led2,LOW);
       digitalWrite(led3,LOW);
       digitalWrite(led4,LOW);
       digitalWrite(led5,LOW);
       digitalWrite(led6,LOW);
       digitalWrite(led7,LOW);
       break;
      case 2:
       digitalWrite(led1,HIGH);
       digitalWrite(led2,HIGH);
       digitalWrite(led3,LOW);
       digitalWrite(led4,LOW);
       digitalWrite(led5,LOW);
       digitalWrite(led6,LOW);
       digitalWrite(led7,LOW); 
       break;
      case 3:
       digitalWrite(led1,HIGH);
       digitalWrite(led2,HIGH);
       digitalWrite(led3,HIGH);
       digitalWrite(led4,LOW);
       digitalWrite(led5,LOW);
       digitalWrite(led6,LOW);
       digitalWrite(led7,LOW); 
       break;
        case 4:
       digitalWrite(led1,HIGH);
       digitalWrite(led2,HIGH);
       digitalWrite(led3,HIGH);
       digitalWrite(led4,HIGH);
       digitalWrite(led5,LOW);
       digitalWrite(led6,LOW);
       digitalWrite(led7,LOW);
       break; 
       case 5:
       digitalWrite(led1,HIGH);
       digitalWrite(led2,HIGH);
       digitalWrite(led3,HIGH);
       digitalWrite(led4,HIGH);
       digitalWrite(led5,HIGH);
       digitalWrite(led6,LOW);
       digitalWrite(led7,LOW);
       break;     
       case 6:
       digitalWrite(led1,HIGH);
       digitalWrite(led2,HIGH);
       digitalWrite(led3,HIGH);
       digitalWrite(led4,HIGH);
       digitalWrite(led5,HIGH);
       digitalWrite(led6,HIGH);
       digitalWrite(led7,LOW);
       break;     
       case 7:
       digitalWrite(led1,HIGH);
       digitalWrite(led2,HIGH);
       digitalWrite(led3,HIGH);
       digitalWrite(led4,HIGH);
       digitalWrite(led5,HIGH);
       digitalWrite(led6,HIGH);
       digitalWrite(led7,HIGH);
       break;         
  }
}
