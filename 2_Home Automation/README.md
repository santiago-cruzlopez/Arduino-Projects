:Author: santiago-cruzlopez
:Email:
:Date: 04/04/2024
:Revision: version#
:License: Public Domain

= Project: Home Automation

Describe your project

== Step 1: Installation
1. Download this repository containing all the project files.
2. Extract the downloaded files.
3. Open the Arduino IDE software (https://support.arduino.cc/hc/en-us/articles/360019833020-Download-and-install-Arduino-IDE).
4. Create an Arduino Cloud account
5. Connect the Arduino UNO R3 WiFi to the Arduino Cloud, make sure the board is in the same LAN as the desktop or laptop.

== Step 2: Assemble the circuit

Open the "Home Automation Document.pdf" to see the simulation, connections and electronic components.

== Step 3: Load the code

Upload the code contained in this sketch on to your board

=== Folder structure

....
 Home Automation                => Arduino sketch folder
  ├── home_automation.ino       => main Arduino file
  ├── thinProperties.h
  ├── Home Automation Document  => An image of the layout and instructions
  └── ReadMe.adoc               => this file
....

=== License
This project is released under a Public Domain License. You are free to use, modify and distribute this project without restrictions.

=== Contributing
If you'd like to contribute to this project with improvements or additional features, please contact trough my LinkedIn: https://www.linkedin.com/in/santi-cruz/ 

=== Electronic Materials

| ID  | Part name           | Description                     | Quantity     |
|:---:|:-------------------:|:-------------------------------:|:------------:|
| R1  | 1k Resistor         | Look for a 1k ohm resistor      | 3            | 
| R2  | 220 Ohm Resistor    | Look for a 220 ohm resistor     | 1            |
| D1  | RGB LED             | Common cathode or anode         | 1            |  
| D2	| Blue LED		        | Regular Led                     | 4            |
| D3	| White LED		        | Regular Led                     | 1            |
| D4	| Red LED		          | Regular Led                     | 1            |  
| IC1 |	DHT11 Sensor	      | Temperature and Humidity Sensor |	1            |  
| IC2	| HC-SR501            | PIR Motion Sensor	              |	1            |
| DIS	| LCD Display (I2C)	  | Look for a compatible I2C LCD   |	1            |
| UNO	| Arduino UNO R3 WIFI | Microcontroller                 |	1            |


=== Help
This document is written in the _AsciiDoc_ format, a markup language to describe documents. 
If you need help you can search the http://www.methods.co.nz/asciidoc[AsciiDoc homepage]
or consult the http://powerman.name/doc/asciidoc[AsciiDoc cheatsheet]
