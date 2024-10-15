//medir el potenciometro
int lectura = 0;
int muestra = 0;
void setup() {
Serial.begin(9600);

}

void loop() {
muestra = analogRead(lectura);
Serial.println(muestra);
delay(500); 
}
