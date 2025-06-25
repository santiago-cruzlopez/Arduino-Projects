/* 
  CloudDimmedLight red_switch;
  CloudTemperatureSensor temp;
  CloudRelativeHumidity humidity;
  bool blue_led_switch;
  bool motion_thing;
*/

#include <DHT.h>
#include <DHT_U.h>

#include <LCD_I2C.h>

#include "thingProperties.h"

#define dht_sensor_pin 13
#define dht_sensor_type DHT11

DHT dht_sensor(dht_sensor_pin, dht_sensor_type);

LCD_I2C lcd(0x27, 16, 2);

//PIR SENSOR
int pir_sensor_pin = 4;
int led_pir = 3;
int val_pir = 0;

//RGB LED, PWM LED AND BLUE LEDS
int LED_PWM_PIN = 6;
int led_pin1b = 5;
int rgbR = 9;
int rgbG = 10;
int rgbB = 11;

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  pinMode(rgbR, OUTPUT);
  pinMode(rgbG, OUTPUT);
  pinMode(rgbB, OUTPUT);
  pinMode(led_pin1b, OUTPUT);

  //PIR Setup
  pinMode(led_pir, OUTPUT);
  pinMode(pir_sensor_pin, INPUT);
  
  //DHT11 Setup
  pinMode(dht_sensor_pin, INPUT);
  dht_sensor.begin();

  lcd.begin(); // initialize the lcd
  lcd.backlight();
}

void loop() {
  ArduinoCloud.update();

  val_pir = digitalRead(pir_sensor_pin);
  if (val_pir == HIGH) {            // check if the input is HIGH
    digitalWrite(led_pir, HIGH);  // turn LED ON
    if (motion_thing == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      motion_thing = HIGH;
    }
  } else {
    digitalWrite(led_pir, LOW); // turn LED OFF
    if (motion_thing == HIGH){
      // we have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      motion_thing = LOW;
    }
  } 

  humidity = dht_sensor.readHumidity();
  temp = dht_sensor.readTemperature();

  if(isnan(humidity) || isnan(temp)){
    Serial.println("Failed to read from DHT11 Sensor.");
  }
  else{
    //DHT11 Information in the Serial Monitor
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print("%");
    Serial.print("  |  ");
    //Temperature Data
    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.println("°C");
    //LCD Information
    lcd.setCursor(0,0); 
    lcd.print("Temp: ");
    lcd.print(temp);
    lcd.print((char)223);
    lcd.print("C");
    lcd.setCursor(0,1);
    lcd.print("Humidity: ");
    lcd.print(humidity);
    lcd.print("%");
  }
  delay(1250);
  
  if(temp < 10){
    analogWrite(rgbR, HIGH);
    analogWrite(rgbG, HIGH);
    analogWrite(rgbB, LOW);
  }else if(10 <= temp && temp <= 25){
    analogWrite(rgbR, LOW);
    analogWrite(rgbG, HIGH);
    analogWrite(rgbB, HIGH);
  }
  else{
    analogWrite(rgbR, HIGH);
    analogWrite(rgbG, LOW);
    analogWrite(rgbB, HIGH);
  }
}

/*
  Since BlueLedSwitch is READ_WRITE variable, onBlueLedSwitchChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onBlueLedSwitchChange()  {
  // Add your code here to act upon BlueLedSwitch change
  if(blue_led_switch == true){
    digitalWrite(led_pin1b, HIGH);
  }
  else{
    digitalWrite(led_pin1b, LOW);
  }
}

/*
  Since RedSwitch is READ_WRITE variable, onRedSwitchChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onRedSwitchChange()  {
    int brightness = map(red_switch.getBrightness(), 0, 100, 0, 255);
    analogWrite(LED_PWM_PIN, brightness);  // AnalogWrite for PWM control
}
