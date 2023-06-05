#include "functions.h"
//SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET
Adafruit_SSD1306 display(4);

byte menuCount = 1;
byte menuSelect = 1;
String oldLocation="Konum Araniyor";

ezButton button(SW_PIN);

int xValue = 0;  // To store value of the X axis
int yValue = 0;  // To store value of the Y axis
int bValue = 0;  // To store value of the button

tmElements_t tm;

//TinyGPSPlus gps;
//SoftwareSerial ss(2, 3);
uint8_t address[][6]= { "1Node", "2Node" };
RF24 radio(CE_PIN, CSN_PIN);
bool radioNumber=0;
bool playing=false;

RDA5807M fmRadio;



void setup() {
  Wire.begin(); 
  Serial.begin(115200);
  Serial1.begin(9600);
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)  // Don't proceed, loop forever
      ;
  }

  if (!radio.begin()) {
    Serial.println(F("radio hardware is not responding!!"));
    while (1) {}  // hold in infinite loop
  }
    Serial.println(F("RF24/examples/StreamingData"));
  radio.setPALevel(RF24_PA_LOW);
  radio.setPayloadSize(SIZE); 
  radio.openWritingPipe(address[radioNumber]);
  radio.openReadingPipe(1, address[!radioNumber]); 
  radio.stopListening();
  

  //Start screen
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(50, 10);
  display.print(timeSettings());
  display.display();
  delay(2000);

 

  fmRadio.setup(RADIO_FMSPACING, RADIO_FMSPACING_100);   // for EUROPE
  fmRadio.setup(RADIO_DEEMPHASIS, RADIO_DEEMPHASIS_50);  // for EUROPE

  // Initialize the Radio

  // Set all radio setting to the fixed values.
  playRadio();
  stopRadio();
}

void loop() {
  getMenu();
  getButtonInput();
  menuInteract();
  //gpsFunction();
}
