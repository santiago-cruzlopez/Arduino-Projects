#include <Time.h>
#include <TimeLib.h>

int EVpin = 9;  // pin al que conectamos la electroválvula de riego
//Defino horas de riego Inicio a las 00:01 y termina a las 00:02
//(poned las horas a las que hagais las pruebas)
byte horaInicio = 13, minutoInicio = 11;
byte horaFin = 13, minutoFin = 12;

boolean esHoraRiego(){

  //Para hacer las comparaciones de cuando empezar y cuando terminar, lo paso todo a minutos.
  //Por eso momentoInicio = 13*60 + 11 = 791 y de fin = 13*60 + 12 = 792
  //También se podría hacer una doble comparación de horaActual con horaInicio y horaFin
  //y de minutoActual con minutoInicio y minutoFin
  int momentoInicio = (horaInicio * 60) + minutoInicio;
  int momentoFin = (horaFin * 60) + minutoFin;
  int momentoAhora = (hour() * 60) + minute();

  //Esto es que si hemos pasado o estamos en el momento de inicio , pero antes del momento del fin… 
  if((momentoInicio<=momentoAhora) && (momentoAhora<momentoFin)){
    return true;    // estamos en período de riego: devolver “true” 
  } 
  else {
    return false;  // no estamos en período de riego: devolver “false” 
  }
}


void setup()
{
  pinMode (EVpin, OUTPUT);
  Serial.begin(9600);
  //Pongo el reloj en la hora actual (en mi caso las 13:10:00 del 21/11/2013)
  //con setTime(hours, minutes, seconds, days, months, years);
  setTime(13, 10, 00, 21, 11, 2013);
}

void loop()
{
  Serial.print("Son las: ");  //Muestro por el puerto serie la hora
  Serial.print(String(hour()) + ":" + String(minute()) + ":" + String(second()));
  if(esHoraRiego()){    //comprobamos si es la hora del riego
    Serial.println(" --> Es hora riego!!");  // es hora de riego: informo por serie
    digitalWrite (EVpin, HIGH);              // activo la EV
  } 
  else {
    Serial.println(" --> No es hora riego");  // no es hora de riego: informo por serie
    digitalWrite (EVpin, LOW);                // cierro la EV
  }
  delay(1000);   // espero 1s
}


