#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ezButton.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
#include <SoftwareSerial.h>
//#include "printf.h"
#include "RF24.h"
#include <radio.h>
#include <RDA5807M.h>
//#include <TinyGPSPlus.h>
//#include <AltSoftSerial.h>

#define SCREEN_WIDTH 128     // OLED display width, in pixels
#define SCREEN_HEIGHT 32     // OLED display height, in pixels
#define OLED_RESET -1        // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C  ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
extern Adafruit_SSD1306 display;

extern byte menuCount;
extern byte menuSelect;

#define VRX_PIN A0  // Arduino pin connected to VRX pin
#define VRY_PIN A1  // Arduino pin connected to VRY pin
#define SW_PIN 7    // Arduino pin connected to SW  pin

extern ezButton button;

extern int xValue;  // To store value of the X axis
extern int yValue;  // To store value of the Y axis
extern int bValue;  // To store value of the button

extern tmElements_t tm;
extern String oldLocation;

//static const int RXPin = 5, TXPin = 6;
//static const uint32_t GPSBaud = 9600;

//extern TinyGPSPlus gps;

//extern SoftwareSerial ss;

#define CE_PIN 9
#define CSN_PIN 10
#define SIZE 32  
// instantiate an object for the nRF24L01 transceiver 
extern RF24 radio;
extern uint8_t address[][6];
extern bool radioNumber;

//extern char test[32];

extern RDA5807M fmRadio;
#define FIX_BAND RADIO_BAND_FM  ///< The band that will be tuned by this sketch is FM.
#define FIX_STATION 8930        ///< The station that will be tuned by this sketch is 89.30 MHz.
#define FIX_VOLUME 5          ///< The volume that will be set by this sketch is level 4.
extern bool playing;

void staticMenu();
void getButtonInput();
void menuInteract();
void getMenu();
void function_konum();
void function_radio();
String timeSettings();
void print2digits(int number);
void gpsFunction();
void transmitterFunction();
void playRadio();
void stopRadio();

#endif