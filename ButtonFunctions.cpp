#include "functions.h"

void getButtonInput() {
  // read analog X and Y analog values
  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);
  // handles select button input when a menu item is highlighted

  button.loop();  // MUST call the loop() function first
    // Read the button value
  bValue = button.getState();
  if (button.isPressed()) {
    Serial.println("The button is pressed");
    // TODO do something here
  }
  if (button.isReleased()) {
    Serial.println("The button is released");
    // TODO do something here
  }


  // handles menu scrolling
  if (yValue > 800) {
    if (menuCount <= 1)
      menuCount = 2;
    else
      menuCount--;
  }

  if (yValue < 400) {
    if (menuCount >= 2)
      menuCount = 1;
    else
      menuCount++;
  }

  if (xValue < 400 || xValue > 800) {
    if (menuSelect == 2 || menuSelect == 3) {
      staticMenu();
      menuSelect = 1;
      menuCount=1;
    } else if (menuSelect == 4) {
      oldLocation="Konum Araniyor";
      function_konum();
      menuSelect = 2;
    }
    else if (menuSelect == 5) {
      staticMenu();
      menuSelect = 1;
      menuCount=1;
    }
  }
  delay(200);
}


void menuInteract() {
  if (menuCount == 1 && button.isPressed())
  // menu item 1 clicked
  {
    menuSelect = 2;
  } else if (menuCount == 2 && button.isPressed())
  // menu item 2 clicked
  {
    menuSelect = 3;
  } else if (menuCount == 3 && button.isPressed()) {
    menuSelect = 4;
    menuCount = 1;
  }
  else if (menuCount == 4 && button.isPressed()) {
    menuSelect = 5;
    menuCount = 1;
  }
}


void getMenu() {
  if (menuSelect == 1) {
    staticMenu();
  } else if (menuSelect == 2) {
    function_konum();
  } else if (menuSelect == 4) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(10, 11);
    display.println("Gonderiliyor");
    display.display();
    
    transmitterFunction();
    delay(1000);
    function_konum();
    menuSelect = 2;
  }else if (menuSelect == 5) {
    stopRadio();
    staticMenu();
    menuSelect = 1;
    menuCount=1;
  }
  else {
    playRadio();
    function_radio();
  }
}