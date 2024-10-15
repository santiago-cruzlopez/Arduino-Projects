/*
HC-SR04 conexiones
VCC al arduino 5 V
GND al arduino GND
Echo al Arduino pin 6 
Trig al Arduino pin 7

1602 A conexiones (LCD):
VSS: 0 V
VDD: 5 V
VO: Centro potenciómetro 50K
RS: Pin 12 Arduino
RW: 0 V
E (Enable): Pin 11~ Arduino
D4: Pin 5~ Arduino
D5: Pin 4  Arduino
D6: Pin 3~ Arduino
D7: Pin 2  Arduino
Uno de los pines de los lados del potenciómetro 50 K va a 0 V, el otro a 5 V
*/

#include<LiquidCrystal.h>                // Incluye la librería para el LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);   // Define los pines de Arduino que se van a usar con el LCD
#define Pecho 6                          // Define los pines de Arduino que se van a usar con el Sensor HC-SR04
#define Ptrig 7
long duracion, distancia;   
 
void setup() {                
  pinMode(Pecho, INPUT);               // Define el pin 6 como entrada (echo)
  pinMode(Ptrig, OUTPUT);              // Define el pin 7 como salida  (triger)
   lcd.begin (16, 2);                  // Inicializa el LCD como 2 filas de 16 caracteres
   lcd.setCursor(0,0);                 // Escribir en primera línea
   lcd.print(" ");
   lcd.print("SENSOR HC-SR04");        // Inicio o presentación
   lcd.print("  ");
   lcd.setCursor(0,1);                 // Escribir en segunda línea
   lcd.print("  ");
   lcd.print("ULTRASONIDOS");
   lcd.print("  ");
   delay(2000);
   lcd.setCursor(0,0);
   lcd.print("   ");
   lcd.print("PRECISION");
   lcd.print("    ");
   lcd.setCursor(0,1);
   lcd.print("      ");
   lcd.print("90%");
   lcd.print("       ");
   delay(2000);
   
  }
  
void loop() {
  
  digitalWrite(Ptrig, LOW);
  delayMicroseconds(2);
  digitalWrite(Ptrig, HIGH);   // genera el pulso de triger por 10ms
  delayMicroseconds(10);
  digitalWrite(Ptrig, LOW);
  
  duracion = pulseIn(Pecho, HIGH);          // Recibe señal de Triger
  distancia = (duracion/2) / 29;            // Calcula la distancia en centimetros
  
  if (distancia >= 500 || distancia <= 0){  // Si la distancia es mayor a 500cm o menor a 0cm 
   lcd.setCursor(0,0);                      // Determina dónde escribir (segunda línea)
   lcd.print(" ");
   lcd.print("FUERA DE RANGO");                // No mide nada, envía mensaje de fuera de rango, o no hay sensor
   lcd.print(" ");
   lcd.setCursor(0,1);
   lcd.print("O NO HAY SENSOR!!");
   delay(1500);
   lcd.setCursor(0,0);
   lcd.print("   ");
   lcd.print("ACERQUESE");
   lcd.print("    ");
   lcd.setCursor(0,1);
   lcd.print("O CONECTE SENSOR");
   delay(2000);
   lcd.setCursor(0,0);
   lcd.print(" ");
   lcd.print("LUEGO REINICIE");
   lcd.print("  ");
   lcd.setCursor(0,1);
   lcd.print("                ");
   delay(1500);
  }
  else {
    lcd.setCursor(0,0);             // Determina dónde escribir (primera línea)
    lcd.print("------");            // Decoración
    lcd.print(distancia);           // Envía el valor de la distancia por el LCD
    lcd.print("cm");                // Pone "cm" al lado del valor
    lcd.print("------");            // Decoración
    lcd.setCursor(0,1);
    lcd.print("                ");   // Segunda línea vacía (Necesario, porque sino se quedaría escrito algúno de los textos de más adelante)
    delay(500);
  }
  
   if (distancia <= 20 && distancia >= 15){
    lcd.setCursor(0,1);
    lcd.print("ESTA CERCA");         // envia texto a LCD (segunda línea)
    delay(500);
  }
   if (distancia <= 14 && distancia >= 10){
    lcd.setCursor(0,1);
    lcd.print("ESTA MAS CERCA");         // envia texto a LCD (segunda línea)
    delay(500);
  }
   if (distancia <= 9 && distancia >= 5){
    lcd.setCursor(0,1);
    lcd.print("ESTA MUY CERCA");         // envia texto a LCD (segunda línea)
    delay(500);
  }
   if (distancia <= 4 && distancia >= 1){
    lcd.setCursor(0,1);
    lcd.print("DELANTE SENSOR");         // envia texto a LCD (segunda línea)
    delay(250);
   }

  }
