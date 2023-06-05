#include "functions.h"

void function_radio() {
  //Serial.println("radio menusu");
  
  // insert fuction code form menu item 2 here
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(10, 0);
  // menu title
  display.println("Radio");

  display.setCursor(80, 0);
  // menu title
  display.println(timeSettings());
  //---------------------------------

  display.setCursor(5, 11);
  display.println("FM 100.00");

  display.setCursor(10, 21);
  // edit menu item here
  display.println("Radyoyu Kapat");

  // prints the cursor to highlight menu items
  display.setCursor(0, 21);
  display.println(">");
  menuCount = 4;

  display.display();
}