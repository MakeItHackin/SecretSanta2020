# SecretSanta2020
Overview of Reddit Secret Santa gift from 2020

Watch the Demo Here:
https://youtu.be/uKTaNg_Iy-Q

Review the User Guide PDF for details


BACKGROUND

I was randomly matched with Reddit user “essjane.”  The following is a screenshot of her questions and answers for the gift exchange.  

I only realized the morning of December 7, 2020 that Reddit Secret Santa sign-ups were ending.  I went ahead and quickly signed up, and was able to make the cut-off before sign-ups closed in the afternoon.  Matching on Reddit Secret Santa 2020 occured on December 7, 2020.  Gifts are required to ship by December 21, 2020.  I’ve created printed circuit boards (PCB) for projects before, so I wanted to make a custom PCB for essjane in a theme of her interests.  

Since ordering PCBs from China usually has a 10 day turn-around from when I place the order to when I receive the item, I didn’t have too much time to develop a new circuit.  Luckily, I developed a similar circuit board for the Hudson Alpha Tech Challenge in February 2020.  I used most of the same components and remixed that project into the Reddit Secret Santa gift.
I decided to make a cat from the outline of the circuit board.  I also wanted to try something new and make the eyes of the cat translucent and shine a light behind them. I have seen this done on other circuit boards before and it is acheived by removing copper on both sides and removing the solder mask as well.  

I added the remaining of essjane’s interests on the silk screen layer of the circuit board.  I started off with a poem, which reminded me of Christmas time and included some of essjane’s interests...

Teal and grey colors and whiskers on kittens,
The chemistry between Apex heros and villains,
Hi-Chew, Brand New, and Sudoku playing,
These are a few of my favorite things.

Designs included on silk screen: Hi-Chew, Brand New, Apex Legends, Baby Yoda, sudoku puzzle (with Pi reference, and chemical symbols.





USING THE CAT


How to turn the unit on/off:
There is one switch on the front of the board, to the left of the display.  When the switch is in the LEFT position, the unit is OFF.  When the switch is in the RIGHT position, the unit is ON.  There is an exception.  If the Arduino Nano is powered by a supply other than the on-board battery, then the unit will turn on.  For example, if a person is programming the board through micro usb on the Arduino, the unit will power on despite the power switch.


Programming the Arduino Nano board:
Insert Data Micro USB cable into board and into computer.  Arduino software (IDE) is available here:
https://www.arduino.cc/en/software
It is compatible with Windows, Mac, and Linux.
Download the files from the Github link and use the Arduino IDE to upload to the board.  A user will need to install libraries for the OLED screen, NeoPixels, and Real Time Clock.  A user can get help with this process by searching YouTube.


Charging the Battery:
Insert cable into battery charging unit.  Charging time will depend on size of battery and if unit is currently powered on.  When charging, the red light on the charging board indicates battery is currently charging.  A solid blue light indicates battery is done charging.  


Using the buttons:
Primarily, the buttons function in the following way:
Button “A” (top left button): Scroll up
Button “B” (bottom left button):: Scroll down
Button “C” (top right button):: Select
Button “D” (bottom left button):: Select/Final Select/Exit


Version 9 of the software boots Circuit board with:
Cat Eyes ON and YELLOW
Apex Legends theme plays
Default menu is clock only (not with temperature and date)



MENUS AND FEATURES

Use A and B buttons to scroll through the menu.  Use buttons C and D to access the features.

Cat Eyes
Press C to enter submenu.  Once the color names appear, use buttons A and B to scroll through available colors or to turn off the eye LEDs.  After desired color or state is acheived, press D to exit menu.


Reddit Logo
This menu only displays the Reddit Logo.  Pressing C or D does nothing.


Demo Mode
Press C to enter Demonstration mode.  Once Demo Mode is activated, the unit will stop responding to A,B,C, and D buttons.  To exit Demo Mode, press the RESET button.  Demo Mode will go through all of the components and demonstrate how they work.


Battery 
Press C to view the battery voltage.  Fully charged is around 4.2 volts. Minimum voltage needed is around 3.6 volts.  The voltage will be displayed for about 5 seconds and then return to the main menu.


LEDs
Press C to activate bottom LEDs.  They will repeat a flashing sequence.  To exit, press the D button.


Play Songs
Press C to play Apex Legends theme song.


Collar
Press C to enter submenu.  Once the color names appear, use buttons A and B to scroll through available colors or to turn off the eye LEDs.  After desired color or state is acheived, press D to exit.


Lite Sense
Press C to view the light sensor value.  Fully bright is around 1023. Complete darkness is 0 (zero).  Try putting the light sensor near a bright light or darkness to see value change.  Press C to exit.


View Temp
Press C to view the temperature from the Real Time Clock module.  Temperature will be displayed in fahrenheit and celsius.  Press C to exit.


Set Clock
Press C to change the date or time.  Once in submenu, use A and B buttons to increment and decrement numbers and use D button to go to the next screen.  Submenu order: Hour, Minute, Seconds, Year, Month, Date.  Note:  Current configuration is 24 hour time (no AM or PM).  Pressing D after date, will finish setting the clock.


Clock
Press C to view Date/Time/Temperature.  Time is displayed in 24 hour time (no AM or PM).  Press C to exit.



















COMPONENT LAYOUT AND DIAGRAM

LEGEND
Front:
1:  12mm Passive Piezo Buzzer
2:  Light Sensor
3:  RESET Button
4:  Button A
5:  Button B
6:  Neopixel 1st strip (8 neopixels)
7:  Power Switch
8:  128x32 OLED display
9:  Button C
10:  Button D
11:  LEDs (blue 0805 size)

Back:
12:  DS3231 Real Time Clock
13:  DC-DC Power boost converter
14:  Arduino Nano v3.0 (with micro usb port)
15:  Battery charging circuit
16:  Battery holder and 18650 Battery (with ‘button’)
17:  Neopixel 2nd strip (2 neopixels).  Used for Cat eyes.



















ARDUINO NANO PIN ASSIGNMENT


D1/TX - NOT CONNECTED - DO NOT USE BECAUSE OF USB COMMUNICATION
D0/RX - NOT CONNECTED - DO NOT USE BECAUSE OF USB COMMUNICATION
RST - RESET BUTTON
GND - CONNECTED TO GROUND PLANE
D2 - BUTTON A
D3 - BUTTON C
D4 - BUTTON D
D5 - BUTTON B
D6 - NEOPIXEL STRAND 1 OUT
D7 - NEOPIXEL STRAND 2 OUT
D8 - PIEZO BUZZER
D9 - LED #9
D10 - LED #1
D11/MOSI - LED #2
D12/MISO - LED #3


VIN - CONNECTED TO OUTPUT FROM BOOST CONVERTER
GND - CONNECTED TO GROUND PLANE
RST - WIRED TO PCB RESET BUTTON
5V - CONNECTED TO 5V BUS
A7 -  LIGHT SENSOR / (cannot be used as digital pin)
A6 - battery voltage sensor/divider / (cannot be used as digital pin)
A5 - i2c (SCL)
A4 - i2c (SDA)
A3 - LED #4
A2 - LED #5
A1 - LED #6
A0 - LED #7
AREF - NOT CONNECTED
3V3 - NOT CONNECTED
D13/SCK - LED #8







FUTURE WORK


Include “Pong” game as one of the menu items.

Populate LEFT and RIGHT buttons.  I will need to remove 2 LEDs in order to do this.

Figure out what is going wrong with the OLED library.  May need to use a different library.

Add multiple songs to PLAY SONGS menu.

Add ability to select which fuctions are displayed in Demo Mode.

Add ability to store data from user... like a set of configurations, or custom text menu.

RTC layout is reversed.  Reverse it so I don’t have to spend an hour desoldering the headers. 

Remove duplicate neopixel functions.
