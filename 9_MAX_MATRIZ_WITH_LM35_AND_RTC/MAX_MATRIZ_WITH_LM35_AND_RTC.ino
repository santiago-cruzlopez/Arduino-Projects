/* Matriz de Desplazamiento LED 8x8 
 
Usando Arduino UNO 
Libreria: MaxMatrix

Conexiones del Arduino al Modulo MAX7219:
ARDUINIO    MAX7219
 10          CLK
 9           CS
 8           DIN
 GND         GND
 5V          VCC
 
Conexion  de la cascada de MAX7219(1)  al MAX7219(2)
MAX7219(1)   MAX7219(2)  
  CLK          CLK
  CS           CS
  DOUT         DIN
  GND          GND
  VCC          VCC
La cascada se hace conectano de los pines Superiores a los inferiores del modulo MAX7219
y los modulos se instalan de derecha a izquierda				
*/

#include <MaxMatrix.h>
#include <avr/pgmspace.h>
#include <DS3231.h>
#include <Wire.h>

PROGMEM unsigned char const CH[] = {
3, 8, B00000000, B00000000, B00000000, B00000000, B00000000, // space
1, 8, B01011111, B00000000, B00000000, B00000000, B00000000, // !
3, 8, B00000011, B00000000, B00000011, B00000000, B00000000, // "
5, 8, B00010100, B00111110, B00010100, B00111110, B00010100, // #
4, 8, B00100100, B01101010, B00101011, B00010010, B00000000, // $
5, 8, B01100011, B00010011, B00001000, B01100100, B01100011, // %
5, 8, B00110110, B01001001, B01010110, B00100000, B01010000, // &
1, 8, B00000011, B00000000, B00000000, B00000000, B00000000, // '
3, 8, B00011100, B00100010, B01000001, B00000000, B00000000, // (
3, 8, B01000001, B00100010, B00011100, B00000000, B00000000, // )
5, 8, B00101000, B00011000, B00001110, B00011000, B00101000, // *
5, 8, B00001000, B00001000, B00111110, B00001000, B00001000, // +
2, 8, B10110000, B01110000, B00000000, B00000000, B00000000, // ,
4, 8, B00001000, B00001000, B00001000, B00001000, B00000000, // -
2, 8, B01100000, B01100000, B00000000, B00000000, B00000000, // .
4, 8, B01100000, B00011000, B00000110, B00000001, B00000000, // /
4, 8, B00111110, B01000001, B01000001, B00111110, B00000000, // 0
3, 8, B01000010, B01111111, B01000000, B00000000, B00000000, // 1
4, 8, B01100010, B01010001, B01001001, B01000110, B00000000, // 2
4, 8, B00100010, B01000001, B01001001, B00110110, B00000000, // 3
4, 8, B00011000, B00010100, B00010010, B01111111, B00000000, // 4
4, 8, B00100111, B01000101, B01000101, B00111001, B00000000, // 5
4, 8, B00111110, B01001001, B01001001, B00110000, B00000000, // 6
4, 8, B01100001, B00010001, B00001001, B00000111, B00000000, // 7
4, 8, B00110110, B01001001, B01001001, B00110110, B00000000, // 8
4, 8, B00000110, B01001001, B01001001, B00111110, B00000000, // 9
2, 8, B01010000, B00000000, B00000000, B00000000, B00000000, // :
2, 8, B10000000, B01010000, B00000000, B00000000, B00000000, // ;
3, 8, B00010000, B00101000, B01000100, B00000000, B00000000, // <
3, 8, B00010100, B00010100, B00010100, B00000000, B00000000, // =
3, 8, B01000100, B00101000, B00010000, B00000000, B00000000, // >
4, 8, B00000010, B01011001, B00001001, B00000110, B00000000, // ?
5, 8, B00111110, B01001001, B01010101, B01011101, B00001110, // @
4, 8, B01111110, B00010001, B00010001, B01111110, B00000000, // A
4, 8, B01111111, B01001001, B01001001, B00110110, B00000000, // B
4, 8, B00111110, B01000001, B01000001, B00100010, B00000000, // C
4, 8, B01111111, B01000001, B01000001, B00111110, B00000000, // D
4, 8, B01111111, B01001001, B01001001, B01000001, B00000000, // E
4, 8, B01111111, B00001001, B00001001, B00000001, B00000000, // F
4, 8, B00111110, B01000001, B01001001, B01111010, B00000000, // G
4, 8, B01111111, B00001000, B00001000, B01111111, B00000000, // H
3, 8, B01000001, B01111111, B01000001, B00000000, B00000000, // I
4, 8, B00110000, B01000000, B01000001, B00111111, B00000000, // J
4, 8, B01111111, B00001000, B00010100, B01100011, B00000000, // K
4, 8, B01111111, B01000000, B01000000, B01000000, B00000000, // L
5, 8, B01111111, B00000010, B00001100, B00000010, B01111111, // M
5, 8, B01111111, B00000100, B00001000, B00010000, B01111111, // N
4, 8, B00111110, B01000001, B01000001, B00111110, B00000000, // O
4, 8, B01111111, B00001001, B00001001, B00000110, B00000000, // P
4, 8, B00111110, B01000001, B01000001, B10111110, B00000000, // Q
4, 8, B01111111, B00001001, B00001001, B01110110, B00000000, // R
4, 8, B01000110, B01001001, B01001001, B00110010, B00000000, // S
5, 8, B00000001, B00000001, B01111111, B00000001, B00000001, // T
4, 8, B00111111, B01000000, B01000000, B00111111, B00000000, // U
5, 8, B00001111, B00110000, B01000000, B00110000, B00001111, // V
5, 8, B00111111, B01000000, B00111000, B01000000, B00111111, // W
5, 8, B01100011, B00010100, B00001000, B00010100, B01100011, // X
5, 8, B00000111, B00001000, B01110000, B00001000, B00000111, // Y
4, 8, B01100001, B01010001, B01001001, B01000111, B00000000, // Z
2, 8, B01111111, B01000001, B00000000, B00000000, B00000000, // [
4, 8, B00000001, B00000110, B00011000, B01100000, B00000000, // \ backslash
2, 8, B01000001, B01111111, B00000000, B00000000, B00000000, // ]
3, 8, B00000010, B00000001, B00000010, B00000000, B00000000, // hat
4, 8, B01000000, B01000000, B01000000, B01000000, B00000000, // _
2, 8, B00000001, B00000010, B00000000, B00000000, B00000000, // `
4, 8, B00100000, B01010100, B01010100, B01111000, B00000000, // a
4, 8, B01111111, B01000100, B01000100, B00111000, B00000000, // b
4, 8, B00111000, B01000100, B01000100, B00101000, B00000000, // c
4, 8, B00111000, B01000100, B01000100, B01111111, B00000000, // d
4, 8, B00111000, B01010100, B01010100, B00011000, B00000000, // e
3, 8, B00000100, B01111110, B00000101, B00000000, B00000000, // f
4, 8, B10011000, B10100100, B10100100, B01111000, B00000000, // g
4, 8, B01111111, B00000100, B00000100, B01111000, B00000000, // h
3, 8, B01000100, B01111101, B01000000, B00000000, B00000000, // i
4, 8, B01000000, B10000000, B10000100, B01111101, B00000000, // j
4, 8, B01111111, B00010000, B00101000, B01000100, B00000000, // k
3, 8, B01000001, B01111111, B01000000, B00000000, B00000000, // l
5, 8, B01111100, B00000100, B01111100, B00000100, B01111000, // m
4, 8, B01111100, B00000100, B00000100, B01111000, B00000000, // n
4, 8, B00111000, B01000100, B01000100, B00111000, B00000000, // o
4, 8, B11111100, B00100100, B00100100, B00011000, B00000000, // p
4, 8, B00011000, B00100100, B00100100, B11111100, B00000000, // q
4, 8, B01111100, B00001000, B00000100, B00000100, B00000000, // r
4, 8, B01001000, B01010100, B01010100, B00100100, B00000000, // s
3, 8, B00000100, B00111111, B01000100, B00000000, B00000000, // t
4, 8, B00111100, B01000000, B01000000, B01111100, B00000000, // u
5, 8, B00011100, B00100000, B01000000, B00100000, B00011100, // v
5, 8, B00111100, B01000000, B00111100, B01000000, B00111100, // w
5, 8, B01000100, B00101000, B00010000, B00101000, B01000100, // x
4, 8, B10011100, B10100000, B10100000, B01111100, B00000000, // y
3, 8, B01100100, B01010100, B01001100, B00000000, B00000000, // z
3, 8, B00001000, B00110110, B01000001, B00000000, B00000000, // {
1, 8, B01111111, B00000000, B00000000, B00000000, B00000000, // |
3, 8, B01000001, B00110110, B00001000, B00000000, B00000000, // }
4, 8, B00001000, B00000100, B00001000, B00000100, B00000000, // ~
};

int data = 8;    // DIN pin del modulo MAX7219
int load = 9;    // CS pin del modulo MAX7219
int clock = 10;  // CLK pin del modulo MAX7219 
int maxInUse = 5;    //Cambie este valor dependiendo del numero de matrices que use

MaxMatrix m(data, load, clock, maxInUse); // Define el modulo

byte buffer[10];

char mensaje1[] = " BIENVENIDOS ... temperatura "; //Escriba el mensaje a desplegar 
char mensaje2[] = "Centigrados";
char mensajeTemp[10];
char mensajeHora[20];

/**VALORES PARA TEMPERATURA***/
int val;
int tempPin = 1; //A1
String convertir="";
/*****/

/**VALORES PARA RELOJ***/
DS3231 Clock;
byte hour, minute;
bool h12,PM;
/*****/

void setup(){
  pinMode(8,OUTPUT);       //Conexion a DIN
  pinMode(9,OUTPUT);       //Conexion a CS
  pinMode(10,OUTPUT);      //Conexion a CLK
  m.init();               // inicializa el modulo
  m.setIntensity(4);      // intencidad de los puntos de la matriz, entre 1-5
  Serial.begin(9600);     // inicializa el puerto serial
  //HORA
  Wire.begin();
  Clock.setClockMode(false);	// set to 24h
  //modificarHora(); //DESCOMENTA O COMENTA´PARA MODIFICAR HORA
}


/*******************FUNCION PRINCIPAL******************************/
void loop(){
  byte c;
  convertir="";
  // Lee el mensaje que llega por el puerto serial
  while (Serial.available() > 0){
    byte c = Serial.read();
    Serial.println(c, DEC);
    printCharWithShift(c, 100);
  }
  delay(100);                 // Tiempo de inicio de un nuevo Ciclo de mensajes
  m.shiftLeft(false, true);
  
  obtenerHora();
  
  // Despliega los mensajes almacenados en las variables 
  printStringWithShift(mensaje1, 40);       // El ultimo termino se usa para la velocidad del mensaje 
  
  
  /*************************************************/
  val = analogRead(tempPin);
  int mv = ( val/1024.0)*5000; 
  int cel = mv/10;
  convertir +=cel;
  convertir.toCharArray(mensajeTemp, 10);
  printStringWithShift(mensajeTemp, 40);
  /*************************************************/
  printStringWithShift(mensaje2, 40);
  
  convertir="  Hora ";
  convertir +=hour;
  convertir +=":";
  convertir +=minute;
  convertir.toCharArray(mensajeHora, 20);
  printStringWithShift(mensajeHora, 40);
  
}/************************FIN FUNCION PRINCIPAL ************************/

void printCharWithShift(char c, int shift_speed){    // Imprime caracteres
  if (c < 32) return;
  c -= 32;
  memcpy_P(buffer, CH + 7*c, 7);
  m.writeSprite(maxInUse*8, 0, buffer);
  m.setColumn(maxInUse*8 + buffer[0], 0);
  
  for (int i=0; i<buffer[0]+1; i++) 
  {
    delay(shift_speed);
    m.shiftLeft(false, false);
  }
}

void printStringWithShift(char* s, int shift_speed){        // Imprime cadena de caracteres
  while (*s != 0){
    printCharWithShift(*s, shift_speed);
    s++;
  }
}

void printString(char* s)                            // Imprime cadena
{
  int col = 0;
  while (*s != 0)
  {
    if (*s < 32) continue;
    char c = *s - 32;
    memcpy_P(buffer, CH + 7*c, 7);
    m.writeSprite(col, 0, buffer);
    m.setColumn(col + buffer[0], 0);
    col += buffer[0] + 1;
    s++;
  }
}

void modificarHora(){  //ESTE CAMBIA LA HORA
  Clock.setYear(17);
  Clock.setMonth(02);
  Clock.setDate(19);
  Clock.setDoW(7);
  Clock.setHour(19);
  Clock.setMinute(46);
  Clock.setSecond(00);
}

void obtenerHora(){
  hour=Clock.getHour(h12, PM);
  minute=Clock.getMinute();
}

