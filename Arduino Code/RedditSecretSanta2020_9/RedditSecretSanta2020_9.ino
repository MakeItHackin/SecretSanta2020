//////////////////////////////////////////////////////////////////////////////////////////////////
//////////  REDDIT SECRET SANTA 2020  DEMO CODE - BY ANDREW DENIO 
//////////////////////////////////////////////////////////////////////////////////////////////////

/*
  THIS CODE WAS USED TO DEMO THE TROPHY FOR THE AWARD CEREMONY ON SUNDAY, MARCH 8, 2020.
  THERE WERE A LOT OF LESSONS LEARNED DURING THIS PROCESS.

  THE 'A' AND 'B' BUTTONS ARE PRIMARILY USED FOR SCROLLING.  
  THE 'C' BUTTON IS USED AS A SELECT BUTTON.
  THE 'D' BUTTON IS USED AS A SELECT BUTTON WHEN CHANGING THE TIME UNDER THE 'SET CLOCK' FUNCTION.
  
  IF YOU HAVE ANY QUESTIONS OR COMMENTS, FEEL FREE TO INITIATE AN ISSUE ON GITHUB.  I PLAN TO ADD ADDITIONAL COMMENTS IN THE CODE, AND MAYBE SOME MORE FEATURES!
  
  ALL LIBRARIES FOR COMPONENTS WILL BE INCLUDED IN GITHUB LINK, SO FEEL FREE TO TINKER AROUND!
  https://github.com/MakeItHackin/SecretSanta2020
 */



/*
 * future things to do:
 * add multiple songs to buzzer
 * add pong game.  is there room for this?
 * 
 * add ability to choose which functions are in demo mode
 * 
 * give menu for neopixels
 *  
 * remove duplicate neopixel functions
 *
 * 
 * 
 */

 
/*

PINOUT

ARDUINO NANO CLONE



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


*/



const unsigned char RedditBitmap [] PROGMEM =  {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x0f, 0x9f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x03, 0x87, 0xc0, 0x00, 
0x00, 0x00, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x03, 0xcc, 0xc0, 0x00, 
0x00, 0x00, 0x1f, 0xf9, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x03, 0xc8, 0x60, 0x40, 
0x00, 0x00, 0x1c, 0xf9, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x03, 0xc8, 0x61, 0xe0, 
0x00, 0x00, 0x3c, 0x3f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x03, 0xcc, 0x41, 0xe0, 
0x00, 0x00, 0x38, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x03, 0xc7, 0xc1, 0xe0, 
0x00, 0x00, 0x38, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x03, 0xc3, 0x01, 0xe0, 
0x00, 0x03, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x03, 0xc0, 0x01, 0xe0, 
0x00, 0x1f, 0xff, 0xc0, 0x01, 0x87, 0x01, 0xf0, 0x00, 0x3e, 0x78, 0x03, 0xe3, 0xc3, 0x07, 0xf8, 
0x1f, 0xff, 0xff, 0xff, 0xc3, 0xdf, 0x07, 0xfc, 0x00, 0xff, 0xf8, 0x0f, 0xfb, 0xc7, 0x8f, 0xfc, 
0x3f, 0xfe, 0x03, 0xff, 0xe3, 0xff, 0x8f, 0xfe, 0x01, 0xff, 0xf8, 0x1f, 0xff, 0xc7, 0x8f, 0xfc, 
0x3f, 0xe0, 0x00, 0x7f, 0xe3, 0xff, 0x1f, 0xff, 0x03, 0xff, 0xf8, 0x3f, 0xff, 0xc7, 0x87, 0xfc, 
0x7f, 0xc0, 0x00, 0x1f, 0xf3, 0xfc, 0x3e, 0x0f, 0x87, 0xe1, 0xf8, 0x3e, 0x1f, 0xc7, 0x81, 0xe0, 
0x7f, 0x0f, 0x03, 0x87, 0xf3, 0xf0, 0x3c, 0x07, 0x87, 0x80, 0xf8, 0x7c, 0x0f, 0xc7, 0x81, 0xe0, 
0x7e, 0x1f, 0x87, 0xc3, 0xf3, 0xe0, 0x78, 0x03, 0xcf, 0x80, 0x78, 0x78, 0x07, 0xc7, 0x81, 0xe0, 
0x7e, 0x1f, 0x8f, 0xe3, 0xf3, 0xe0, 0x78, 0x03, 0xcf, 0x00, 0x78, 0xf8, 0x07, 0xc7, 0x81, 0xe0, 
0x3c, 0x3f, 0x8f, 0xe1, 0xe3, 0xc0, 0x78, 0x03, 0xcf, 0x00, 0x78, 0xf0, 0x03, 0xc7, 0x81, 0xe0, 
0x1c, 0x1f, 0x87, 0xc1, 0xc3, 0xc0, 0x7f, 0xff, 0xcf, 0x00, 0x38, 0xf0, 0x03, 0xc7, 0x81, 0xe0, 
0x1c, 0x1f, 0x07, 0xc1, 0xc3, 0xc0, 0x7f, 0xff, 0xcf, 0x00, 0x38, 0xf0, 0x03, 0xc7, 0x81, 0xe0, 
0x1c, 0x04, 0x01, 0x01, 0xc3, 0xc0, 0x7f, 0xff, 0xcf, 0x00, 0x38, 0xf0, 0x03, 0xc7, 0x81, 0xe0, 
0x1e, 0x00, 0x00, 0x03, 0xc3, 0xc0, 0x78, 0x00, 0x0f, 0x00, 0x78, 0xf0, 0x03, 0xc7, 0x81, 0xe0, 
0x0e, 0x0e, 0x03, 0x83, 0x83, 0xc0, 0x78, 0x00, 0x0f, 0x00, 0x78, 0xf8, 0x07, 0xc7, 0x81, 0xe0, 
0x0f, 0x0f, 0xff, 0x87, 0x83, 0xc0, 0x78, 0x00, 0x0f, 0x80, 0x78, 0x78, 0x07, 0xc7, 0x81, 0xe0, 
0x07, 0xc7, 0xff, 0x9f, 0x03, 0xc0, 0x7c, 0x01, 0xc7, 0x80, 0xf8, 0x7c, 0x07, 0xc7, 0x81, 0xe0, 
0x03, 0xf3, 0xfe, 0x7e, 0x03, 0xc0, 0x3e, 0x07, 0xc7, 0xc1, 0xf8, 0x7c, 0x0f, 0xc7, 0x81, 0xe0, 
0x01, 0xfe, 0x03, 0xfc, 0x03, 0xc0, 0x1f, 0xff, 0xc3, 0xff, 0xf8, 0x3f, 0xff, 0xc7, 0x81, 0xe0, 
0x00, 0xff, 0xff, 0xf8, 0x03, 0xc0, 0x1f, 0xff, 0x81, 0xff, 0xf8, 0x1f, 0xff, 0xc7, 0x81, 0xe0, 
0x00, 0x1f, 0xff, 0xc0, 0x03, 0xc0, 0x07, 0xff, 0x00, 0xff, 0xf8, 0x0f, 0xff, 0xc7, 0x81, 0xe0, 
0x00, 0x03, 0xfe, 0x00, 0x01, 0xc0, 0x03, 0xf8, 0x00, 0x3f, 0x38, 0x03, 0xf3, 0x83, 0x80, 0xe0, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

////////////////////////////////////////////////////////////////
//////////  VARIABLES AND LIBRARIES
////////////////////////////////////////////////////////////////

// Music Notes for the Super Mario Bros Theme music
#define NOTE_G6  1568
#define NOTE_C7  2093
#define NOTE_E7  2637
#define NOTE_G7  3136

// Music Notes for the Apex Legends Theme music
#define NOTE_D4  294
#define NOTE_C4  262
#define NOTE_G4  392
#define NOTE_G3  196


#include <Wire.h>
//#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h> //#define SSD1306_I2C_ADDRESS   0x3C    #define SSD1306_128_64
#define OLED_RESET -1
Adafruit_SSD1306 display(OLED_RESET);


//NEOPIXEL SETUP
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN 6
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      8
#define PIN_EYES 7
// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel stripEyes = Adafruit_NeoPixel(2, 7, NEO_GRB + NEO_KHZ800);
// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

// Assign Input Pins (Buttons and Light sensor)
#define BUTTON_A_PIN 2
#define BUTTON_B_PIN 5
#define BUTTON_C_PIN 3
#define BUTTON_D_PIN 4
#define BATTERY_VOLTAGE_PIN A6
#define LIGHT_SENSOR_PIN A7
#define BUZZER_PIN 8

// LED Pin Assignments
//int RX_LED_PIN = 0;
//int TX_LED_PIN = 1;
//int OnBoardLED_PIN = 13;

int LED_1_PIN = 10;
int LED_2_PIN = 11;
int LED_3_PIN = 12;
int LED_4_PIN = A3;
int LED_5_PIN = A2;
int LED_6_PIN = A1;
int LED_7_PIN = A0;
int LED_8_PIN = 13;
int LED_9_PIN = 9;

int NewLEDArray[] = {LED_1_PIN, LED_2_PIN, LED_3_PIN, LED_4_PIN, LED_5_PIN, LED_6_PIN, LED_7_PIN, LED_8_PIN, LED_9_PIN}; //, OnBoardLED_PIN, RX_LED_PIN, TX_LED_PIN};
const int NewLEDArrayLength = sizeof(NewLEDArray) / sizeof(NewLEDArray[0]);


// New and Old state variables used for Buttons
bool buttonAOldState = HIGH;
bool buttonBOldState = HIGH;
bool buttonCOldState = HIGH;
bool buttonDOldState = HIGH;
bool buttonANewState;
bool buttonBNewState;
bool buttonCNewState;
bool buttonDNewState;

// Variables Used for menu options
bool oledMainMenu = 0;
bool NeoPixelMenuSelected = 0;
bool LEDMenuSelected = 0;
bool LightSensorMenuSelected = 0;
bool TemperatureMenuSelected = 0;
bool BuzzerMenuSelected = 0;
bool SAOMenuSelected = 0;
bool DemoMenuSelected = 0;

int NewEyes = 0;
int NewCollar = 0;
int NewSong = 0;

// Variables used for scrolling through menus.  
byte NewMenuVar = 12;  // clock
byte NewerMenuVar = 0;
byte MenuCount = 12;
byte OldMenuVar = MenuCount + 1; 

int OnOffBool = 0;
int OnOffBool1 = 0;
int OnOffBool2 = 0;
int OnOffBool3 = 0;
int OnOffBool4 = 0;
int OnOffBool5 = 0;
int OnOffBool6 = 0;
int OnOffBool7 = 0;
int OnOffBool8 = 0;
int OnOffBool9 = 0;
int OnOffBool10 = 0;
int OnOffBool11 = 0;
int OnOffBool12 = 0;

// Date and time functions using a DS3231 RTC connected via I2C and Wire lib
#include "RTClib.h"

RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// Variables used to set the time manually on the trophy
int NewHour = 0;
int NewMinute = 0;
int NewSecond = 0;
int NewDate = 1;
int NewMonth = 1;
int NewYear = 2020;
double LeapYear = 1;

// Temperature Variables
float TempC = 0;
float TempF = 0;



////////////////////////////////////////////////////////////////
//////////  SETUP LOOP
////////////////////////////////////////////////////////////////


void setup () {
  
  //Start Serial for feedback on Serial Monitor
  Serial.begin(9600);

  //Serial.println("Starting setup");

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // Uncomment to set clock to the computer's time at time of compile
  /*
  else {
    DateTime now = rtc.now();
    rtc.adjust(DateTime(now.year(), now.month(), now.day(), now.hour(), now.minute(), now.second()));
  }
*/
  DateTime now = rtc.now();

  
  //begin neopixels
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  colorWipe(strip.Color(0, 0, 0), 0); // Turn Off

  stripEyes.begin();
  stripEyes.show(); // Initialize all pixels to 'off'
  colorWipeEyes(stripEyes.Color(0, 0, 0), 0); // Turn Off
  
  //Setup input pins
  pinMode(BUTTON_A_PIN, INPUT_PULLUP);
  pinMode(BUTTON_B_PIN, INPUT_PULLUP);
  pinMode(BUTTON_C_PIN, INPUT_PULLUP);
  pinMode(BUTTON_D_PIN, INPUT_PULLUP);
  pinMode(BATTERY_VOLTAGE_PIN, INPUT);
  pinMode(LIGHT_SENSOR_PIN, INPUT);

  //Setup output pins
  pinMode(BUZZER_PIN,OUTPUT);
  
  for (int i = 0; i <= NewLEDArrayLength-1; i++) {
    pinMode(NewLEDArray[i],OUTPUT);
  }

  TurnOffAllLEDs();

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  // Show image buffer on the display hardware.
  //display.display();
  display.setTextColor(WHITE, BLACK);
  display.setTextSize(1);
  display.clearDisplay();
  display.drawBitmap(0, 0, RedditBitmap, 128, 32, WHITE);
  display.display();

  colorWipeEyes(stripEyes.Color(200, 200, 0), 0); // Yellow
  
  playApexSong();

  //DisplayClockAndTemp();

  //Serial.println("Done with setup");
  
}


////////////////////////////////////////////////////////////////
//////////  MAIN LOOP
////////////////////////////////////////////////////////////////


void loop () {

  // Check Each button to see if they have been pressed
  CheckButtons(); 
  MenuChange();

  //Asssignment needed for menu
  OldMenuVar = NewMenuVar; 
  
}





////////////////////////////////////////////////////////////////
//////////  OTHER FUNCTIONS
////////////////////////////////////////////////////////////////

void MenuChange() {
  if (NewMenuVar == MenuCount+1) {
     NewMenuVar = 1;
   }
  if (NewMenuVar == 0) {
     NewMenuVar = MenuCount;
   }
  if (NewMenuVar == 1){
     OnOffBool = OnOffBool1;
     display.clearDisplay();
     display.setTextSize(2);
     display.setCursor(0,0);  
     if (OnOffBool1 == 0) {
        display.println("CLOCK ");
        display.setTextSize(1);
        display.println("PRESS C TO VIEW  ");
     }
     else{
        DisplayClockAndTemp();
     }
     display.display();
  }
  else if (NewMenuVar == 2){
      OnOffBool = OnOffBool2;  
      display.clearDisplay();
      display.setTextSize(2);
      display.setCursor(0,0);
      if (OnOffBool2 == 0) {
        display.println("SET CLOCK ");
        display.setTextSize(1);
        display.println("PRESS C TO CHANGE  ");
      }
      else{
        GoSetTime();
      }
      display.display(); 
  }
  else if (NewMenuVar == 3){
      OnOffBool = OnOffBool3;  
      display.clearDisplay();
      display.setTextSize(2);
      display.setCursor(0,0);
      if (OnOffBool3 == 0) {
          display.println("VIEW TEMP ");
          display.setTextSize(1);
          display.println("PRESS C TO VIEW  ");
      }
      else {
          GetTemperature();
          DisplayTempOnScreen();
      }
      display.display();   
  }
  else if (NewMenuVar == 4){
      OnOffBool = OnOffBool4; 
      display.clearDisplay();
      display.setTextSize(2);
      display.setCursor(0,0);
      if (OnOffBool4 == 0) {
          display.println("LITE SENSE");
          display.setTextSize(1);
          display.println("PRESS C TO VIEW ");
      }
      else{
          DisplayLightSensor();
      }
    display.display();
  }
  else if (NewMenuVar == 5){
      OnOffBool = OnOffBool5;  
      display.clearDisplay();
      display.setTextSize(2);
      display.setCursor(0,0);
      if (OnOffBool5 == 0) {
          display.println("COLLAR ");
          display.setTextSize(1);
          display.println("PRESS C TO VIEW  ");
      }
      else{
          display.println("COLLAR ");
          display.setTextSize(1);
          display.println("WOW... LEDs..."); 
          //display.display();
          //StartNeoPixels();
          changeCatCollar();
      }
      display.display();
  }
  else if (NewMenuVar == 6){
      OnOffBool = OnOffBool6;  
      display.clearDisplay();
      display.setTextSize(2);
      display.setCursor(0,0);
      if (OnOffBool6 == 0) {
          display.println("PLAY SONGS ");
          display.setCursor(0,15);
          //display.setTextSize(2);
          display.setTextSize(1);
          display.println("PRESS C TO VIEW  ");
      }
      else{
          display.println("PLAY SONGS ");
          display.setTextSize(1);
          //display.println("APEX LEGENDS");
          playApexSong();
          //chooseBuzzerSong();
      }
      display.display();
  }
  else if (NewMenuVar == 7){
      OnOffBool = OnOffBool7;        
      display.clearDisplay();
      display.setTextSize(2);
      display.setCursor(0,0);
      if (OnOffBool7 == 0) {
          display.println("LEDs");
          display.setTextSize(1);
          display.println("PRESS C TO VIEW ");  
          //display.println("PRESS D TO EXIT ");  
      }
      else {
          display.println("LEDs");
          //StartLEDSequence();
          TricorderLEDSequence();
      }
      display.display();
  }
  else if (NewMenuVar == 8){
      OnOffBool = OnOffBool8;
      display.clearDisplay();
      display.setCursor(0,0);
      display.setTextSize(2);
      if (OnOffBool8 == 0) {
          display.println("BATTERY");
          display.setTextSize(1);
          display.println("PRESS C TO VIEW  ");
      }
      else{
          goViewBattery();
      }
      display.display();
  }
  else if (NewMenuVar == 9){
      OnOffBool = OnOffBool9;     
      display.clearDisplay();
      display.setTextSize(2);
      display.setCursor(0,0);
      if (OnOffBool9 == 0) {
          display.println("DEMO MODE");
          display.setTextSize(1);
          display.println("PRESS C TO ACTIVATE"); 
          display.println("PRESS RESET TO EXIT");
      }
      else{
          display.println("DEMO MODE");
          display.setTextSize(1);
          display.println("PRESS RESET TO EXIT");
          StartDemoMode();
      }
      display.display();
  }
  else if (NewMenuVar == 10){
      OnOffBool = OnOffBool10;
      if (OnOffBool10 == 0) {
          goToRedditLogo();
      }
      else{
          goToRedditLogo();
      }
  }
  else if (NewMenuVar == 11){
      OnOffBool = OnOffBool11;      
      display.clearDisplay();
      display.setTextSize(2);
      display.setCursor(0,0);
      if (OnOffBool11 == 0) {
          display.println("CAT EYES ");
          display.setTextSize(1);
          display.println("PRESS C TO CHANGE  "); 
      }
      else {
          display.println("CAT EYES  ");
          display.setTextSize(1);
          changeCatEyes();
      }
      display.display();
  }
  else if (NewMenuVar == 12){
      OnOffBool = OnOffBool12;  
      /*    
      display.clearDisplay();
      display.setTextSize(2);
      display.setCursor(0,0);
      display.display();
      */
      DisplayClockForDemo();
  }
  else {
    // nothing here
  }
}

///////////////////////////////////////////
///////////////////////////////////////////

//Check Each Button
void CheckButtons(){
  CheckbuttonA();
  CheckbuttonB();
  CheckbuttonC();
  CheckbuttonD();
}


////////////////////////////////////////////////////////////////

void CheckbuttonA(){

    // Get current button state.
  buttonANewState = digitalRead(BUTTON_A_PIN);

  // Check if state changed from high to low (button press).
  if (buttonANewState == LOW && buttonAOldState == HIGH) {
    // Short delay to debounce button.
    delay(20);
    // Check if button is still low after debounce.
    buttonANewState = digitalRead(BUTTON_A_PIN);
    if (buttonANewState == LOW) {
      // BUTTON PRESSED
     Serial.println("BUTTON A PRESSED");
     
      ////if (oledMainMenu == 1 || NeoPixelMenuSelected == 1 || TemperatureMenuSelected == 1 || LEDMenuSelected == 1 || DemoMenuSelected == 1){
        NewMenuVar = OldMenuVar + 1;
          if (NewMenuVar == MenuCount+1) {
              NewMenuVar = 1;
          }
         
          ////startQuadMenuCounter();
        ////}
     Serial.println("button done");
    }
    else {
      // BUTTON NOT PRESSED 
    }
  }

  // Set the last button state to the old state.
  buttonAOldState = buttonANewState;

}


////////////////////////////////////////////////////////////////

void CheckbuttonB(){

    // Get current button state.
  buttonBNewState = digitalRead(BUTTON_B_PIN);

  // Check if state changed from high to low (button press).
  if (buttonBNewState == LOW && buttonBOldState == HIGH) {
    // Short delay to debounce button.
    delay(20);
    // Check if button is still low after debounce.
    buttonBNewState = digitalRead(BUTTON_B_PIN);
    if (buttonBNewState == LOW) {
      // BUTTON PRESSED
     Serial.println("BUTTON B PRESSED");
   
     //// if (oledMainMenu == 1 || NeoPixelMenuSelected == 1 || LEDMenuSelected ==1 || TemperatureMenuSelected == 1 || DemoMenuSelected == 1){        
        NewMenuVar = OldMenuVar - 1;
          if (NewMenuVar == 0) {
              NewMenuVar = MenuCount;
          }

     ////     startQuadMenuCounter();
     ////   }
     Serial.println("button done");
    }
    else {
      // BUTTON NOT PRESSED 
    }
  }

  // Set the last button state to the old state.
  buttonBOldState = buttonBNewState;

}

////////////////////////////////////////////////////////////////

void CheckbuttonC(){

    // Get current button state.
  buttonCNewState = digitalRead(BUTTON_C_PIN);

  // Check if state changed from high to low (button press).
  if (buttonCNewState == LOW && buttonCOldState == HIGH) {
    // Short delay to debounce button.
    delay(20);
    // Check if button is still low after debounce.
    buttonCNewState = digitalRead(BUTTON_C_PIN);
    if (buttonCNewState == LOW) {
      // BUTTON PRESSED
     Serial.println("BUTTON C PRESSED");
     ////selectMenuItem();
     //oledMainMenu = 0;
     GoButtonC();
     Serial.println("button done"); 
    }
    else {
      // BUTTON NOT PRESSED 
    }
  }

  // Set the last button state to the old state.
  buttonCOldState = buttonCNewState;

}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

void GoButtonC(){
        if (NewMenuVar == 1) {
            if (OnOffBool1 == 0) {
                OnOffBool2 = 0; OnOffBool1 = 1; OnOffBool3 = 0; OnOffBool4 = 0; OnOffBool5 = 0; OnOffBool6 = 0; OnOffBool7 = 0; OnOffBool8 = 0; OnOffBool9 = 0; OnOffBool10 = 0; OnOffBool11 = 0; OnOffBool12 = 0;
              }
            else  {
                OnOffBool1 = 0;
              }   
          }
        else if (NewMenuVar == 2) {
            if (OnOffBool2 == 0) {
                OnOffBool2 = 1; OnOffBool1 = 0; OnOffBool3 = 0; OnOffBool4 = 0; OnOffBool5 = 0; OnOffBool6 = 0; OnOffBool7 = 0; OnOffBool8 = 0; OnOffBool9 = 0; OnOffBool10 = 0; OnOffBool11 = 0; OnOffBool12 = 0;
              }
            else {
                OnOffBool2 = 0;
              }   
          } 
        else if (NewMenuVar == 3)
          {
            if (OnOffBool3 == 0) {
                OnOffBool2 = 0; OnOffBool1 = 0; OnOffBool3 = 1; OnOffBool4 = 0; OnOffBool5 = 0; OnOffBool6 = 0; OnOffBool7 = 0; OnOffBool8 = 0; OnOffBool9 = 0; OnOffBool10 = 0; OnOffBool11 = 0; OnOffBool12 = 0;
              }
            else 
              {
                OnOffBool3 = 0;
              }   
          } 
        else if (NewMenuVar == 4) {
            if (OnOffBool4 == 0) {
                OnOffBool2 = 0; OnOffBool1 = 0; OnOffBool3 = 0; OnOffBool4 = 1; OnOffBool5 = 0; OnOffBool6 = 0; OnOffBool7 = 0; OnOffBool8 = 0; OnOffBool9 = 0; OnOffBool10 = 0; OnOffBool11 = 0; OnOffBool12 = 0;
              }
            else {
                OnOffBool4 = 0;
              }   
          } 
        else if (NewMenuVar == 5) {
            if (OnOffBool5 == 0) {
                OnOffBool2 = 0; OnOffBool1 = 0; OnOffBool3 = 0; OnOffBool4 = 0; OnOffBool5 = 1; OnOffBool6 = 0; OnOffBool7 = 0; OnOffBool8 = 0; OnOffBool9 = 0; OnOffBool10 = 0; OnOffBool11 = 0; OnOffBool12 = 0;
              }
            else {
                OnOffBool5 = 0;
              }   
          } 
        else if (NewMenuVar == 6) {
            if (OnOffBool6 == 0) {
                OnOffBool2 = 0; OnOffBool1 = 0; OnOffBool3 = 0; OnOffBool4 = 0; OnOffBool5 = 0; OnOffBool6 = 1; OnOffBool7 = 0; OnOffBool8 = 0; OnOffBool9 = 0; OnOffBool10 = 0; OnOffBool11 = 0; OnOffBool12 = 0;
              }
            else {
                OnOffBool6 = 0;
              }   
          }
        else if (NewMenuVar == 7) {
            if (OnOffBool7 == 0) {
                OnOffBool2 = 0; OnOffBool1 = 0; OnOffBool3 = 0; OnOffBool4 = 0; OnOffBool5 = 0; OnOffBool6 = 0; OnOffBool7 = 1; OnOffBool8 = 0; OnOffBool9 = 0; OnOffBool10 = 0; OnOffBool11 = 0; OnOffBool12 = 0;
              }
            else {
                OnOffBool7 = 0;
              }   
          }        
        else if (NewMenuVar == 8) {
            if (OnOffBool8 == 0) {
                OnOffBool2 = 0; OnOffBool1 = 0; OnOffBool3 = 0; OnOffBool4 = 0; OnOffBool5 = 0; OnOffBool6 = 0; OnOffBool7 = 0; OnOffBool8 = 1; OnOffBool9 = 0; OnOffBool10 = 0; OnOffBool11 = 0; OnOffBool12 = 0;
              }
            else {
                OnOffBool8 = 0;
              }   
          }        
        else if (NewMenuVar == 9) {
            if (OnOffBool9 == 0) {
                OnOffBool2 = 0; OnOffBool1 = 0; OnOffBool3 = 0; OnOffBool4 = 0; OnOffBool5 = 0; OnOffBool6 = 0; OnOffBool7 = 0; OnOffBool8 = 0; OnOffBool9 = 1; OnOffBool10 = 0; OnOffBool11 = 0; OnOffBool12 = 0;
              }
            else {
                OnOffBool9 = 0;
              }   
          }        
        else if (NewMenuVar == 10) {
            if (OnOffBool10 == 0) {
                OnOffBool2 = 0; OnOffBool1 = 0; OnOffBool3 = 0; OnOffBool4 = 0; OnOffBool5 = 0; OnOffBool6 = 0; OnOffBool7 = 0; OnOffBool8 = 0; OnOffBool9 = 0; OnOffBool10 = 1; OnOffBool11 = 0; OnOffBool12 = 0;
              }
            else {
                OnOffBool10 = 0;
              }   
          }   
        else if (NewMenuVar == 11) {
            if (OnOffBool11 == 0) {
                OnOffBool2 = 0; OnOffBool1 = 0; OnOffBool3 = 0; OnOffBool4 = 0; OnOffBool5 = 0; OnOffBool6 = 0; OnOffBool7 = 0; OnOffBool8 = 0; OnOffBool9 = 0; OnOffBool10 = 0; OnOffBool11 = 1; OnOffBool12 = 0;
              }
            else {
                OnOffBool11 = 0;
              }   
          }
         else if (NewMenuVar == 12) {
            if (OnOffBool12 == 0) {
                OnOffBool2 = 0; OnOffBool1 = 0; OnOffBool3 = 0; OnOffBool4 = 0; OnOffBool5 = 0; OnOffBool6 = 0; OnOffBool7 = 0; OnOffBool8 = 0; OnOffBool9 = 0; OnOffBool10 = 0; OnOffBool11 = 0; OnOffBool12 = 1;
              }
            else {
                OnOffBool12 = 0;
              }   
          }     
        else {
                OnOffBool2 = 0; OnOffBool1 = 0; OnOffBool3 = 0; OnOffBool4 = 0; OnOffBool5 = 0; OnOffBool6 = 0; OnOffBool7 = 0; OnOffBool8 = 0; OnOffBool9 = 0; OnOffBool10 = 0; OnOffBool11 = 0; OnOffBool12 = 0;
              }
}


////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////


void CheckbuttonD(){

    // Get current button state.
  buttonDNewState = digitalRead(BUTTON_D_PIN);

  // Check if state changed from high to low (button press).
  if (buttonDNewState == LOW && buttonDOldState == HIGH) {
    // Short delay to debounce button.
    delay(20);
    // Check if button is still low after debounce.
    buttonDNewState = digitalRead(BUTTON_D_PIN);
    if (buttonDNewState == LOW) {
      // BUTTON PRESSED
     Serial.println("BUTTON D PRESSED");
    oledMainMenu = 1;
    //changeEPDToMainMenu();
    ////printEPDMenu("MAIN", "NEOPIXELS", "LIGHT SENSOR", "TEMPERATURE SENSOR", "ACCELEROMETER", "DEMO MODE", " ", 1);
    ////startQuadMenuCounter();
    Serial.println("button done");
    }
    else {
      // BUTTON NOT PRESSED 
    }
  }

  // Set the last button state to the old state.
  buttonDOldState = buttonDNewState;

}


////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////



void changeCatCollar(){

  byte collarBrightness = 20;
  
  while (digitalRead(BUTTON_D_PIN) == HIGH) {
        if (digitalRead(BUTTON_B_PIN) == LOW) {
          ////display.setCursor(0,35);
          ////display.print("    ");
        NewCollar++;
        if (NewCollar > 7) {
       // delay(1000);
       NewCollar = 0;
       //Serial.println(NewEyes);
       delay(50);
        }
      }
        if (digitalRead(BUTTON_A_PIN) == LOW) {
          ////display.setCursor(0,35);
          ////display.print("    ");
        NewCollar--;
        if (NewCollar < 0) {
       // delay(1000);
       NewCollar = 7;
       //Serial.println(NewEyes);
       delay(50);
        }
      }
    display.setCursor(0,15);
    display.setTextSize(2);
    //display.println(print2digitsDisplay(NewHour));

    if (NewCollar == 0){
      colorWipe(strip.Color(collarBrightness, collarBrightness, 0), 0); // Yellow
      display.print("Yellow");
      display.print("       ");
    }
    else if (NewCollar == 1){
      colorWipe(strip.Color(collarBrightness, 0, 0), 0); // Red
      display.print("Red");
      display.print("       ");
    } 
    else if (NewCollar == 2){
      colorWipe(strip.Color(0, collarBrightness, 0), 0); // Green
      display.print("Green");
      display.print("       ");
    } 
    else if (NewCollar == 3){
      colorWipe(strip.Color(0, 0, collarBrightness), 0); // Blue
      display.print("Blue");
      display.print("       ");
    } 
    else if (NewCollar == 4){
      colorWipe(strip.Color(0, collarBrightness, collarBrightness), 0); // Cyan
      display.print("Cyan");
      display.print("       ");
    } 
    else if (NewCollar == 5){
      colorWipe(strip.Color(collarBrightness, 0, collarBrightness), 0); // Magenta
      display.print("Magenta");
      display.print("       ");
    } 
    else if (NewCollar == 6){
      colorWipe(strip.Color(collarBrightness, collarBrightness, collarBrightness), 0); // White
      display.print("White");
      display.print("       ");
    } 
    else if (NewCollar == 7){
      colorWipe(strip.Color(0, 0, 0), 0); // Off
      display.print("Off");
      display.print("       ");
    } 
    
    else {
      
    }

    
    //print2digitsDisplay(NewHour);
    display.println("");
    ////display.print("    ");
    //delay(1000);
    display.display();
    
    delay(100); //DEBOUNCE
  }
  
  OnOffBool5 = 0;
}



/////////////////////////////////////////////////////
/////////////////////////////////////////////////////

void chooseBuzzerSong(){
  delay(100); // debounce
  
  while (digitalRead(BUTTON_D_PIN) == HIGH) {
    
        if (digitalRead(BUTTON_B_PIN) == LOW) {
          ////display.setCursor(0,35);
          ////display.print("    ");
        NewSong++;
        Serial.println(NewSong);
        /*
        if (NewSong > 2) {
           // delay(1000);
           NewSong = 0;
           //Serial.println(NewSong);
           delay(50);
        }
        */
      }
      
        if (digitalRead(BUTTON_A_PIN) == LOW) {
          ////display.setCursor(0,35);
          ////display.print("    ");
        NewSong--;
        Serial.println(NewSong);
        /*
        if (NewSong < 0) {
           // delay(1000);
           NewSong = 2;
           delay(50);
        }
        */
      }
      
    display.setCursor(0,15);
    display.setTextSize(1);
    //display.println(print2digitsDisplay(NewHour));

    if (NewSong == 0){
      //colorWipeEyes(stripEyes.Color(150, 150, 0), 0); // Yellow
      display.print("Mario ");
      display.println("");
      display.display();
      if (digitalRead(BUTTON_C_PIN) == LOW) {
          PlayMarioSong();
          delay(50);
      }
    }
    else if (NewSong == 2){
      //colorWipeEyes(stripEyes.Color(150, 0, 0), 0); // Red
      //display.print("Apex ");
      //display.println("Ape");
      display.display(); 
      if (digitalRead(BUTTON_C_PIN) == LOW) {
          playApexSong();
          delay(50);
      }
    } 
   
    delay(100); //DEBOUNCE
    
  }
  
  OnOffBool6 = 0;
  
}


/////////////////////////////////////////////////////
/////////////////////////////////////////////////////

void playApexSong(){
  
  int toneduration = 250;
  int tonedelay = toneduration * 1.3;

  tone(8, NOTE_D4, toneduration);
  delay(tonedelay);
  tone(8, NOTE_C4, toneduration);
  delay(tonedelay);
  tone(8, NOTE_D4, toneduration);
  delay(tonedelay);
  tone(8, NOTE_G4, toneduration);
  delay(tonedelay);
  tone(8, NOTE_D4, toneduration);
  delay(tonedelay);
  tone(8, NOTE_C4, toneduration);
  delay(tonedelay);
  tone(8, NOTE_D4, toneduration);
  delay(tonedelay);
  tone(8, NOTE_G3, toneduration);
  delay(tonedelay);

  tone(8, NOTE_D4, toneduration);
  delay(tonedelay);
  tone(8, NOTE_C4, toneduration);
  delay(tonedelay);
  tone(8, NOTE_D4, toneduration);
  delay(tonedelay);
  tone(8, NOTE_G4, toneduration);
  delay(tonedelay);
  tone(8, NOTE_D4, toneduration);
  delay(tonedelay);
  tone(8, NOTE_C4, toneduration);
  delay(tonedelay);
  tone(8, NOTE_D4, toneduration);
  delay(tonedelay);
  tone(8, NOTE_G3, toneduration);
  delay(tonedelay);

  //noTone(8);  
  
  OnOffBool6 = 0;
  
}


/////////////////////////////////////////////////////
/////////////////////////////////////////////////////




void changeCatEyes(){

  byte eyeBrightness = 200;
  
  while (digitalRead(BUTTON_D_PIN) == HIGH) {
        if (digitalRead(BUTTON_B_PIN) == LOW) {
          ////display.setCursor(0,35);
          ////display.print("    ");
        NewEyes++;
        if (NewEyes > 7) {
       // delay(1000);
       NewEyes = 0;
       //Serial.println(NewEyes);
       delay(50);
        }
      }
        if (digitalRead(BUTTON_A_PIN) == LOW) {
          ////display.setCursor(0,35);
          ////display.print("    ");
        NewEyes--;
        if (NewEyes < 0) {
       // delay(1000);
       NewEyes = 7;
       //Serial.println(NewEyes);
       delay(50);
        }
      }
    display.setCursor(0,15);
    display.setTextSize(2);
    //display.println(print2digitsDisplay(NewHour));

    if (NewEyes == 0){
      colorWipeEyes(stripEyes.Color(eyeBrightness, eyeBrightness, 0), 0); // Yellow
      display.print("Yellow");
      display.print("       ");
    }
    else if (NewEyes == 1){
      colorWipeEyes(stripEyes.Color(eyeBrightness, 0, 0), 0); // Red
      display.print("Red");
      display.print("       ");
    } 
    else if (NewEyes == 2){
      colorWipeEyes(stripEyes.Color(0, eyeBrightness, 0), 0); // Green
      display.print("Green");
      display.print("       ");
    } 
    else if (NewEyes == 3){
      colorWipeEyes(stripEyes.Color(0, 0, eyeBrightness), 0); // Blue
      display.print("Blue");
      display.print("       ");
    } 
    else if (NewEyes == 4){
      colorWipeEyes(stripEyes.Color(0, eyeBrightness, eyeBrightness), 0); // Cyan
      display.print("Cyan");
      display.print("       ");
    } 
    else if (NewEyes == 5){
      colorWipeEyes(stripEyes.Color(eyeBrightness, 0, eyeBrightness), 0); // Magenta
      display.print("Magenta");
      display.print("       ");
    } 
    else if (NewEyes == 6){
      colorWipeEyes(stripEyes.Color(eyeBrightness, eyeBrightness, eyeBrightness), 0); // White
      display.print("White");
      display.print("       ");
    } 
    else if (NewEyes == 7){
      colorWipeEyes(stripEyes.Color(0, 0, 0), 0); // Off
      display.print("Off");
      display.print("       ");
    } 
    
    else {
      
    }

    
    //print2digitsDisplay(NewHour);
    display.println("");
    ////display.print("    ");
    //delay(1000);
    display.display();
    
    delay(100); //DEBOUNCE
  }
  
  OnOffBool11 = 0;
}



/////////////////////////////////////////////////////
/////////////////////////////////////////////////////

void StartDemoMode(){
  int demodelay = 2000;
  int theaterChaseDelay = 100;
  int neoPixelIntensity = 64; // (255 is max, 0 is min)

  TricorderLEDDemo();
  //StartLEDSequence();
  display.clearDisplay(); // Make sure the display is cleared
  display.drawBitmap(0, 0, RedditBitmap, 128, 32, WHITE);
  display.display();
  
  theaterChase(strip.Color(0, 0, neoPixelIntensity), theaterChaseDelay); // blue
  colorWipe(strip.Color(0, 0, 0), 0);    // Black/off

  StartLEDSequence();
  //display.clearDisplay(); // Make sure the display is cleared
  //display.drawBitmap(0, 0, UrbanEngineBitmap, 128, 32, WHITE);
  //display.display();

  theaterChase(strip.Color(0, neoPixelIntensity, 0), theaterChaseDelay); // blue
  colorWipe(strip.Color(0, 0, 0), 0);    // Black/off
  

  //StartLEDSequence();
  TricorderLEDDemo();
  //display.clearDisplay(); // Make sure the display is cleared
  //display.drawBitmap(0, 0, AcclinateBitmap, 128, 32, WHITE);
  //display.display();

  theaterChase(strip.Color(neoPixelIntensity, 0, 0), theaterChaseDelay); // red
  colorWipe(strip.Color(0, 0, 0), 0);    // Black/off

  StartLEDSequence();
  /*
  display.clearDisplay();
  display.setCursor(1,10);
  display.setTextSize(3);
  display.println("PRESENT");
  display.display();
*/
  theaterChase(strip.Color(neoPixelIntensity, neoPixelIntensity, neoPixelIntensity), theaterChaseDelay); // white
  colorWipe(strip.Color(0, 0, 0), 0);    // Black/off

  //StartLEDSequence();
  TricorderLEDDemo();
  //display.clearDisplay(); // Make sure the display is cleared// drawBitmap(x position, y position, bitmap data, bitmap width, bitmap height, color)
  //display.drawBitmap(0, 0, HATCH2020Bitmap, 128, 32, WHITE);
  //display.display();

  theaterChase(strip.Color(0, 0, neoPixelIntensity), theaterChaseDelay); // Blue
  colorWipe(strip.Color(0, 0, 0), 0);    // Black/off

  StartLEDSequence();
  display.clearDisplay();
  display.setCursor(5,0);
  display.setTextSize(2);
  display.println("HACK THIS");
  display.println("KITTY !!!");
  display.display();

  theaterChase(strip.Color(neoPixelIntensity, neoPixelIntensity, neoPixelIntensity), theaterChaseDelay); // white
  colorWipe(strip.Color(0, 0, 0), 0);    // Black/off


  //StartLEDSequence();
  TricorderLEDDemo();
  
  goToRedditLogo();
  //delay(demodelay);

  //StartLEDSequence();
  rainbow2(100);
  colorWipe(strip.Color(0, 0, 0), 0);    // Black/off

  //StartLEDSequence();
  TricorderLEDDemo();
  //PlaySong();
  PlayMarioSong();
  //delay(demodelay);
  
  StartLEDSequence();
  DisplayLightSensorForDemo();

  //StartLEDSequence();
  TricorderLEDDemo();
  display.clearDisplay();
  display.setCursor(5,0);
  display.setTextSize(2);
  display.println("HACK THIS");
  display.println("KITTY !!!");
  display.display();

  //delay(demodelay);

  //StartLEDSequence();
  rainbowCycle2(20); //20
  colorWipe(strip.Color(0, 0, 0), 0);    // Black/off

  //StartLEDSequence();
  TricorderLEDDemo();
  DisplayClockForDemo();
  delay(demodelay);

  StartLEDSequence();
  theaterChaseRainbow2(50); //50
  colorWipe(strip.Color(0, 0, 0), 0);    // Black/off

  //StartLEDSequence();
  TricorderLEDDemo();
  DisplayTempForDemo();
  delay(demodelay);

  StartLEDSequence();

  //OnOffBool9 = 0;
}

/////////////////////////////////////////////////////
/////////////////////////////////////////////////////



void goViewBattery(){

    display.clearDisplay();
    display.setCursor(0,0);
    display.setTextSize(1);
    display.println("BATTERY VOLTAGE");
    
  for(int i=0; i<20; i++){
    display.setCursor(0,10);
    display.setTextSize(3);
    display.print(getBatteryVoltage());
    display.println(" V  ");
    display.display();
    delay(100);
  }
  OnOffBool8 = 0;
}


/////////////////////////////////////////////////////
/////////////////////////////////////////////////////




float getBatteryVoltage() {
    float measuredvbat = analogRead(BATTERY_VOLTAGE_PIN);

    measuredvbat *= 2;    // we divided by 2, so multiply back
    measuredvbat *= 5;  // Multiply by 5V, our reference voltage
    measuredvbat /= 1024; // convert to voltage

    return measuredvbat;
}  

/////////////////////////////////////////////////////
/////////////////////////////////////////////////////



void StartNeoPixels(){
  colorWipe(strip.Color(255, 0, 0), 50);  // Red
  colorWipe(strip.Color(0, 0, 0), 50);    // Black/off
  colorWipe(strip.Color(0, 255, 0), 50);  // Green
  colorWipe(strip.Color(0, 0, 0), 50);    // Black/off
  colorWipe(strip.Color(0, 0, 255), 50);  // Blue
  colorWipe(strip.Color(0, 0, 0), 50);    // Black/off
  
  OnOffBool5 = 0;
}


/////////////////////////////////////////////////////
/////////////////////////////////////////////////////


void PlaySong(){
  tone(8, 400, 200);
  //delay(1000);
  //noTone(8);
  OnOffBool6 = 0;
}


/////////////////////////////////////////////////////
/////////////////////////////////////////////////////



void PlayMarioSong(){
  
  byte toneduration = 120;
  byte tonedelay = toneduration * 1.3;
  
  tone(8, NOTE_E7, toneduration);
  delay(tonedelay);
  tone(8, NOTE_E7, toneduration);
  delay(tonedelay);
  tone(8, 0, toneduration);
  delay(tonedelay);
  tone(8, NOTE_E7, toneduration);
  delay(tonedelay);
  tone(8, 0, toneduration);
  delay(tonedelay);
  tone(8, NOTE_C7, toneduration);
  delay(tonedelay);
  tone(8, NOTE_E7, toneduration);
  delay(tonedelay);
  tone(8, 0, toneduration);
  delay(tonedelay);
  tone(8, NOTE_G7, toneduration);
  delay(tonedelay);
  tone(8, 0, toneduration);
  delay(tonedelay);
  tone(8, 0, toneduration);
  delay(tonedelay);
  tone(8, 0, toneduration);
  delay(tonedelay);
  tone(8, NOTE_G6, toneduration);
  delay(tonedelay);
  tone(8, 0, toneduration);
  delay(tonedelay);
  tone(8, 0, toneduration);
  delay(tonedelay);
  tone(8, 0, toneduration);
  delay(tonedelay);
  OnOffBool6 = 0;
  
}


////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

void TurnOffAllLEDs() {
  for (int i = 0; i <= NewLEDArrayLength; i++) {
    digitalWrite(NewLEDArray[i],LOW);
  }
}



////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

void StartLEDSequence(){
  TurnOffAllLEDs();
  delay(200);
  for (int i = 0; i <= NewLEDArrayLength-1; i++) {
    digitalWrite(NewLEDArray[i],HIGH);
    delay(100);
  }
  TurnOffAllLEDs();
  OnOffBool7 = 0;
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
/*
int LED_1_PIN = 10;
int LED_2_PIN = 11;
int LED_3_PIN = 12;
int LED_4_PIN = A3;
int LED_5_PIN = A2;
int LED_6_PIN = A1;
int LED_7_PIN = A0;
int LED_8_PIN = 13;
int LED_9_PIN = 9;
*/
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

void TricorderLEDDemo(){
    byte delaytri = 150;
      
    TurnOffAllLEDs();
    
    digitalWrite(LED_5_PIN,HIGH);
    delay(delaytri);
    TurnOffAllLEDs();
  
    digitalWrite(LED_4_PIN,HIGH);
    digitalWrite(LED_6_PIN,HIGH);
    delay(delaytri);
    TurnOffAllLEDs();
  
    digitalWrite(LED_3_PIN,HIGH);
    digitalWrite(LED_7_PIN,HIGH);
    delay(delaytri);
    TurnOffAllLEDs();
  
    digitalWrite(LED_2_PIN,HIGH);
    digitalWrite(LED_8_PIN,HIGH);
    delay(delaytri);  
    TurnOffAllLEDs();
  
    digitalWrite(LED_1_PIN,HIGH);
    digitalWrite(LED_9_PIN,HIGH);
    delay(delaytri);
    TurnOffAllLEDs();
}


////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

void TricorderLEDSequence(){

  while (digitalRead(BUTTON_D_PIN) == HIGH) {

      byte delaytri = 150;
      
      TurnOffAllLEDs();
      
      digitalWrite(LED_5_PIN,HIGH);
      delay(delaytri);
      TurnOffAllLEDs();
    
      digitalWrite(LED_4_PIN,HIGH);
      digitalWrite(LED_6_PIN,HIGH);
      delay(delaytri);
      TurnOffAllLEDs();
    
      digitalWrite(LED_3_PIN,HIGH);
      digitalWrite(LED_7_PIN,HIGH);
      delay(delaytri);
      TurnOffAllLEDs();
    
      digitalWrite(LED_2_PIN,HIGH);
      digitalWrite(LED_8_PIN,HIGH);
      delay(delaytri);  
      TurnOffAllLEDs();
    
      digitalWrite(LED_1_PIN,HIGH);
      digitalWrite(LED_9_PIN,HIGH);
      delay(delaytri);
      TurnOffAllLEDs();
  }
  
  OnOffBool7 = 0;
  
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

void DisplayTempOnScreen(){
  display.setTextSize(2);
  display.print(TempF);
  display.println(" F");
  display.setTextSize(2);
  display.print(TempC);
  display.println(" C     ");
}


/////////////////////////////////////////////////////
/////////////////////////////////////////////////////




void DisplayLightSensor(){
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0,0);
  //display.setTextSize(2);
  display.print("VALUE: ");
  display.print(analogRead(LIGHT_SENSOR_PIN));
  display.println(" ");
  //display.println("             ");
  //display.println("             ");
  display.setCursor(0,17);
  display.setTextSize(1);
  display.println("MIN (DARK): 0   ");
  display.println("MAX (BRIGHT): 1023     ");
  display.display();
}


/////////////////////////////////////////////////////
/////////////////////////////////////////////////////


void DisplayLightSensorForDemo(){
  
  for (int i=0; i < 100; i++){
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(10,0);
    display.println("LIGHT SENSOR VALUE");
    display.setCursor(35,10);
    display.setTextSize(3);
    display.print(analogRead(LIGHT_SENSOR_PIN));
    display.println("      ");
    display.display();
    delay(50);
  }
}

/////////////////////////////////////////////////////
/////////////////////////////////////////////////////




void GoSetTime() {

  delay(100);
  
  DateTime now = rtc.now();

  NewHour = now.hour();
  NewMinute = now.minute();
  NewSecond = now.second();
  NewDate = now.day();
  NewMonth = now.month();
  NewYear = now.year();

  display.clearDisplay();
  display.setCursor(0,0);
  display.setTextSize(2);
  display.println("HOUR: ");
  display.display();

  //delay(50);

  while (digitalRead(BUTTON_D_PIN) == HIGH) {
        if (digitalRead(BUTTON_B_PIN) == LOW) {
          ////display.setCursor(0,35);
          ////display.print("    ");
        NewHour++;
        if (NewHour > 23) {
       // delay(1000);
       NewHour = 0;
       Serial.println(NewHour);
       delay(50);
        }
      }
            if (digitalRead(BUTTON_A_PIN) == LOW) {
          ////display.setCursor(0,35);
          ////display.print("    ");
        NewHour--;
        if (NewHour < 0) {
       // delay(1000);
       NewHour = 23;
       Serial.println(NewHour);
       delay(50);
        }
      }
    display.setCursor(0,15);
    display.setTextSize(2);
    //display.println(print2digitsDisplay(NewHour));
    print2digitsDisplay(NewHour);
    display.println("");
    ////display.print("    ");
    //delay(1000);
    display.display();
    
    delay(100); //DEBOUNCE
  }

  display.clearDisplay();
 display.setCursor(0,0);
 display.setTextSize(2);
 display.print("MINUTE:           ");

delay(500);

  while (digitalRead(BUTTON_D_PIN) == HIGH) {
        if (digitalRead(BUTTON_B_PIN) == LOW) {
          //display.setCursor(0,35);
          //display.print("    ");
        NewMinute++;
        if (NewMinute > 59) {
       // delay(1000);
       NewMinute = 0;
       delay(50);
        }
      }
        if (digitalRead(BUTTON_A_PIN) == LOW) {
          //display.setCursor(0,35);
          //display.print("    ");
        NewMinute--;
        if (NewMinute < 0) {
       // delay(1000);
       NewMinute = 59;
       delay(50);
        }
      }
    display.setCursor(0,15);
    display.setTextSize(2);
    //display.println(print2digitsDisplay(NewMinute));
    print2digitsDisplay(NewMinute);
    display.println("");
    //delay(1000);
    display.display();

    delay(100);  // DEBOUNCE
  }

  display.clearDisplay();
 display.setCursor(0,0);
 display.setTextSize(2);
 display.print("SECOND:           ");

delay(500);

  while (digitalRead(BUTTON_D_PIN) == HIGH) {
        if (digitalRead(BUTTON_B_PIN) == LOW) {
         //// display.setCursor(0,35);
        ////  display.print("    ");
        NewSecond++;
        if (NewSecond > 59) {
       // delay(1000);
       NewSecond = 0;
       delay(50);
        }
      }
        if (digitalRead(BUTTON_A_PIN) == LOW) {
         //// display.setCursor(0,35);
        ////  display.print("    ");
        NewSecond--;
        if (NewSecond < 0) {
       // delay(1000);
       NewSecond = 59;
       delay(50);
        }
      }
    display.setCursor(0,15);
    display.setTextSize(2);
    //display.println(print2digitsDisplay(NewSecond));
    print2digitsDisplay(NewSecond);
    display.println("");
    display.display();

    delay(100);
  }
  
  display.clearDisplay();
 display.setCursor(0,0);
 display.setTextSize(2);
 display.print("YEAR:");

delay(500);

 
  
if (NewYear < 2021) {
  NewYear = 2020;
}

  while (digitalRead(BUTTON_D_PIN) == HIGH) {
        if (digitalRead(BUTTON_B_PIN) == LOW) {
          //display.setCursor(0,35);
          //display.print("    ");
        NewYear++;
        if (NewYear > 2030) {
       // delay(1000);
       NewYear = 2020;
       delay(50);
        }
      }
        if (digitalRead(BUTTON_A_PIN) == LOW) {
          //display.setCursor(0,35);
          //display.print("    ");
        NewYear--;
        if (NewYear < 2020) {
       // delay(1000);
       NewYear = 2030;
       delay(50);
        }
      }
    display.setCursor(0,15);
    display.setTextSize(2);
    //display.println(print2digitsDisplay(NewYear));
    print2digitsDisplay(NewYear);
    display.println("");
    display.display();

    delay(100);
  }

 display.clearDisplay();
 display.setCursor(0,0);
 display.setTextSize(2);
 display.print("MONTH:");

delay(500);

  while (digitalRead(BUTTON_D_PIN) == HIGH) {
        if (digitalRead(BUTTON_B_PIN) == LOW) {
         // display.setCursor(0,35);
         // display.print("    ");
        NewMonth++;
        if (NewMonth > 12) {
       // delay(1000);
       NewMonth = 1;
       delay(50);
        }
      }
        if (digitalRead(BUTTON_A_PIN) == LOW) {
         // display.setCursor(0,35);
         // display.print("    ");
        NewMonth--;
        if (NewMonth < 1) {
       // delay(1000);
       NewMonth = 12;
       delay(50);
        }
      }
    display.setCursor(0,15);
    display.setTextSize(2);
    //display.println(print2digitsDisplay(NewMonth));
    print2digitsDisplay(NewMonth);
    display.println("");
    display.display();

    delay(100);
  }

 display.clearDisplay();
 display.setCursor(0,0);
 display.setTextSize(2);
 display.print("DATE:");

delay(500);

  while (digitalRead(BUTTON_D_PIN) == HIGH) {
        if (digitalRead(BUTTON_B_PIN) == LOW) {
          //display.setCursor(0,35);
          //display.print("    ");
        NewDate++;
        if (NewMonth == 1 || NewMonth == 3 || NewMonth == 5 || NewMonth == 7 || NewMonth == 8 || NewMonth == 10 || NewMonth == 12 ) {

             if (NewDate > 31) {
             NewDate = 1;
       delay(50);
            }
        }
        else if (NewMonth == 4 || NewMonth == 6 || NewMonth == 9 || NewMonth == 11) {
             
             if (NewDate > 30) {
             NewDate = 1;
       delay(50);
            }
        }
        else if (NewMonth == 2) {

             LeapYear = NewYear % 4;

             if (LeapYear == 0) {
                   if (NewDate > 29) {
                   NewDate = 1;
       delay(50);
                  }
             }
            else {

                   if (NewDate > 28) {
                   NewDate = 1;
       delay(50);
                  }
            }
        }
        else {
          //
        }

      }
if (digitalRead(BUTTON_A_PIN) == LOW) {
          //display.setCursor(0,35);
          //display.print("    ");
        NewDate--;
        if (NewMonth == 1 || NewMonth == 3 || NewMonth == 5 || NewMonth == 7 || NewMonth == 8 || NewMonth == 10 || NewMonth == 12 ) {

             if (NewDate < 1) {
             NewDate = 31;
       delay(50);
            }
        }
        else if (NewMonth == 4 || NewMonth == 6 || NewMonth == 9 || NewMonth == 11) {
             
             if (NewDate < 1) {
             NewDate = 30;
       delay(50);
            }
        }
        else if (NewMonth == 2) {

             LeapYear = NewYear % 4;

             if (LeapYear == 0) {
                   if (NewDate < 1) {
                   NewDate = 29;
       delay(50);
                  }
             }
            else {

                   if (NewDate < 1) {
                   NewDate = 28;
       delay(50);
                  }
            }
        }
        else {
          //
        }

      }
    display.setCursor(0,15);
    display.setTextSize(2);
    //display.println(print2digitsDisplay(NewDate));
    print2digitsDisplay(NewDate);
    display.println("");
    display.display();

    delay(100);
  }

delay(100);
  
////setTime(NewHour, NewMinute, NewSecond, NewDate, NewMonth, NewYear);
////delay(100);
rtc.adjust(DateTime(NewYear, NewMonth, NewDate, NewHour, NewMinute, NewSecond));

delay(100);

display.clearDisplay();
display.setCursor(0,0);
display.setTextSize(2);
display.println("CLOCK SET!");
display.display();

delay(500);

////BlueEnding();

OnOffBool2 = 0;

}


/////////////////////////////////////////////////////
/////////////////////////////////////////////////////




void selectMenuItem(){

  if (oledMainMenu == 1){
          if (NewMenuVar == 1) {
            NeoPixelMenuSelected = 1;
            LightSensorMenuSelected = 0;
            TemperatureMenuSelected = 0;
            //AccelMenuSelected = 0;
            DemoMenuSelected = 0;
            
            //goToNeoPixelMenu();
            ////printEPDMenu("NEOPIXEL", "COLOR WIPE", "RAINBOW", "RAINBOW CYCLE", "THEATER CHASE", "RAINBOW CHASE", "SHOW MODE", 1);
          } 
        else if (NewMenuVar == 2) {
            NeoPixelMenuSelected = 0;
            LightSensorMenuSelected = 1;
            TemperatureMenuSelected = 0;
            //AccelMenuSelected = 0;
            DemoMenuSelected = 0;
            
            //goToLightSensorMenu();
            ////printEPDMenu("LIGHT SENSOR", "SEE DISPLAY BELOW", "FOR SENSOR VALUE", " ", "0 IS MIN", "1024 IS MAX", " ", 0);
          }     
        else if (NewMenuVar == 3) {
            NeoPixelMenuSelected = 0;
            LightSensorMenuSelected = 0;
            TemperatureMenuSelected = 1;
            //AccelMenuSelected = 0;
            //QuadMenuSelected = 0;
            DemoMenuSelected = 0;

            //goToTemperatureMenu();
            ////printEPDMenu("TEMPERATURE", "SEE DISPLAY BELOW", "FOR TEMPERATURE", " ", "(IN DEGREES F)", " ", " ", 0);
          }  
         else if (NewMenuVar == 4) {

            NeoPixelMenuSelected = 0;
            LightSensorMenuSelected = 0;
            TemperatureMenuSelected = 0;
            //AccelMenuSelected = 1;
            //QuadMenuSelected = 0;
            DemoMenuSelected = 0;
            
            //goToAccelMenu();
            ////printEPDMenu("ACCELEROMETER", "X ACCELERATION", "Y ACCELERATION", "Z ACCELERATION", " ", " ", " ", 1);
          }              
          else if (NewMenuVar == 5) {
            NeoPixelMenuSelected = 0;
            LightSensorMenuSelected = 0;
            TemperatureMenuSelected = 0;
            //AccelMenuSelected = 0;
            //QuadMenuSelected = 0;
            DemoMenuSelected = 1;
            
           // goToAwardMenu2(1);
          }   
          
          else if (NewMenuVar == 6) {
              return;
          }               
           else  {
               // done
          }  
     oledMainMenu = 0;
  }
   
  if (NeoPixelMenuSelected == 1){
          if (NewMenuVar == 1) {
              colorWipe(strip.Color(255, 0, 0), 50);  // Red
              colorWipe(strip.Color(0, 0, 0), 50);    // Black/off
              colorWipe(strip.Color(0, 255, 0), 50);  // Green
              colorWipe(strip.Color(0, 0, 0), 50);    // Black/off
              colorWipe(strip.Color(0, 0, 255), 50);  // Blue
              colorWipe(strip.Color(0, 0, 0), 50);    // Black/off
              colorWipe(strip.Color(255, 255, 255), 50);  // Blue
              colorWipe(strip.Color(0, 0, 0), 0);    // Black/off
          } 
        else if (NewMenuVar == 2) {
              rainbow(20);
              colorWipe(strip.Color(0, 0, 0), 0);    // Black/off
          }     
        else if (NewMenuVar == 3) {
              rainbowCycle(20);
              colorWipe(strip.Color(0, 0, 0), 0);    // Black/off
          }  
         else if (NewMenuVar == 4) {
              theaterChase(strip.Color(127, 127, 127), 50); // White
              colorWipe(strip.Color(0, 0, 0), 0);    // Black/off
              theaterChase(strip.Color(127,   0,   0), 50); // Red
              colorWipe(strip.Color(0, 0, 0), 0);    // Black/off
              theaterChase(strip.Color(  0,   0, 127), 50); // Blue
              colorWipe(strip.Color(0, 0, 0), 0);    // Black/off
          }              
          else if (NewMenuVar == 5) {
              theaterChaseRainbow(50);
              colorWipe(strip.Color(0, 0, 0), 0);    // Black/off
          }   
          else if (NewMenuVar == 6) {
              ////showModeAndQuad(50,0);
              colorWipe(strip.Color(0, 0, 0), 0);    // Black/off
          }                      
           else  {
               // done
          }  
////    quadDisplayString("----");    
  }
  if (LightSensorMenuSelected == 1){
    for (int i = 0; i < 100; i++)  {
////       printLEDNumber(analogRead(LIGHT_SENSOR_PIN)); 
       delay(150);     
    }
////    quadDisplayString("----");   
  }
  if (TemperatureMenuSelected == 1){
    for (int i = 0; i < 100; i++)  {
////       printLEDNumber(checkTempF()); 
       delay(150);     
    }
////    quadDisplayString("----");   
  }

    /*
    if (AccelMenuSelected == 1){
          if (NewMenuVar == 1) {
               for (int i = 0; i < 100; i++)  {
                 printLEDNumber(checkXaccel()); 
                 delay(150);     
              }
          } 
        else if (NewMenuVar == 2) {
               for (int i = 0; i < 100; i++)  {
                 printLEDNumber(checkYaccel()); 
                 delay(150);     
              }
          }     
        else if (NewMenuVar == 3) {
              for (int i = 0; i < 100; i++)  {
                 printLEDNumber(checkZaccel()); 
                 delay(150);     
              }
          }
        else if (NewMenuVar == 4) {
          }  
        else if (NewMenuVar == 5) {
          }  
        else if (NewMenuVar == 6) {
          }                        
           else  {
               // done
          }  
    quadDisplayString("----");    
  }

  */
}

////////////////////////////////////////////////////////////////

void print2digitsDisplay(int number) {
  if (number >= 0 && number < 10) {
    display.print('0');
  }
  display.print(number);
}



////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

void GetTemperature(){
  TempC = rtc.getTemperature();
  TempF = (TempC*1.8)+32;
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////



void DisplayClockForDemo(){
  
  DateTime now = rtc.now();
  display.clearDisplay();
  display.setCursor(0, 7);
  display.setTextSize(3); 
  display.print(" ");
  //display.print(print2digitsDisplay(now.hour()));
  print2digitsDisplay(now.hour());
  display.print(":");
  //display.println(print2digitsDisplay(now.minute()));
  print2digitsDisplay(now.minute());
  display.println("  ");
  display.setTextSize(2); 
  display.println("           ");
  display.println("           ");
  display.display();
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////


void DisplayTempForDemo(){
    GetTemperature();
    display.clearDisplay();
    display.setCursor(0, 7);
    display.setTextSize(3);
    //display.println(TempC); display.setCursor(105, 7); display.print("C");// Uncomment to display Celsius
    display.print(TempF); display.setCursor(105, 7); display.print("F"); // Uncomment to display Fahrenheit
    display.drawCircle(95, 9, 3, WHITE); //OFF
    display.display();
  }
  
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////



void DisplayClockAndTemp(){

  GetTemperature();
  
  DateTime now = rtc.now();
    
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.print(daysOfTheWeek[now.dayOfTheWeek()]);
  display.print(" Temp: ");
  //display.println(TempC); // Uncomment to display Celsius
  display.println(TempF); // Uncomment to display Fahrenheit
  
  //second row
  display.setTextSize(2); 
  //display.print(print2digitsDisplay(now.hour()));
  print2digitsDisplay(now.hour());
  display.print(":");
  //display.print(print2digitsDisplay(now.minute()));
  print2digitsDisplay(now.minute());
  display.print(":");
  //display.println(print2digitsDisplay(now.second()));
  print2digitsDisplay(now.second());
  display.println("");
  
  //third row
  display.setTextSize(1);
  //display.print(print2digitsDisplay(now.month()));
  print2digitsDisplay(now.month());
  display.print("/");
  //display.print(print2digitsDisplay(now.day()));
  print2digitsDisplay(now.day());
  display.print("/");
  display.print(now.year(), DEC);
  display.println("           ");
  display.display();
}

/////////////////////////////////////////////////////
/////////////////////////////////////////////////////


void goToRedditLogo(){
  display.clearDisplay();
  display.drawBitmap(0, 0, RedditBitmap, 128, 32, WHITE);
  display.display();  
}



////////////////////////////////////////////////////////////////
//      NEOPIXEL FUNCTIONS
////////////////////////////////////////////////////////////////

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void colorWipeEyes(uint32_t d, uint8_t wait) {
  for(uint16_t i=0; i<stripEyes.numPixels(); i++) {
    stripEyes.setPixelColor(i, d);
    stripEyes.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

void rainbow2(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<60; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel2((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}


// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle2(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<60*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel2(((i * 60 / strip.numPixels()) + j) & 60));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}


//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow2(uint8_t wait) {
  for (int j=0; j < 60; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, Wheel2( (i+j) % 60));    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel2(byte WheelPos) {
  WheelPos = 60 - WheelPos;
  if(WheelPos < 20) {
    return strip.Color(60 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 40) {
    WheelPos -= 20;
    return strip.Color(0, WheelPos * 3, 60 - WheelPos * 3);
  }
  WheelPos -= 40;
  return strip.Color(WheelPos * 3, 60 - WheelPos * 3, 0);
}
