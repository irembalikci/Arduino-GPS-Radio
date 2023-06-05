#include "functions.h"

void staticMenu() {
  //Serial.println("ana menusu");
  // change text display here
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(10, 0);
  // menu title
  display.println("Menu");

  display.setCursor(80, 0);
  // menu title
  display.println(timeSettings());
  //---------------------------------
  display.setTextSize(1);
  display.setCursor(10, 11);
  // edit menu item here
  display.println("Konum");
  display.setCursor(60, 20);

  display.setCursor(10, 21);
  // edit menu item here
  display.println("Radio");
  display.setCursor(60, 30);

  // prints the cursor to highlight menu items
  display.setCursor(2, (menuCount * 10) + 1);
  display.println(">");

  display.display();
}