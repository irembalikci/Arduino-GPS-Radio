#include "functions.h"



void function_konum() {
  //Serial.println("konum menusu");
  // insert fuction code form menu item 1 here
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(10, 0);
  // menu title
  display.println("Konum");

  display.setCursor(80, 0);
  // menu title
  display.println(timeSettings());
  //---------------------------------
  // edit menu item here
  gpsFunction();
  display.setCursor(5, 11);
  display.println(oldLocation);

  display.setCursor(10, 21);
  // edit menu item here
  display.println("Gonder");

  // prints the cursor to highlight menu items
  display.setCursor(0, 21);
  display.println(">");
  menuCount = 3;
  display.display();
}