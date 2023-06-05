#include "functions.h"
#include <TinyGPSPlus.h>
TinyGPSPlus gps;

void displayInfo() {
  Serial.print(F("Location: "));
  if (gps.location.isValid()) {
    if (gps.location.isUpdated())
  {
    oldLocation="";
    oldLocation.concat(String(gps.location.lat(),6));
    oldLocation.concat(String(","));
    oldLocation.concat(String(gps.location.lng(),6));

    /*display.setTextSize(1);
    display.setCursor(5, 10);
    // menu title
    display.println(gps.location.lat(),6);
    display.setCursor(5, 17);
    // menu title
    display.println(gps.location.lng(),6);
    display.display();
    */
    //Serial.print(gps.location.lat(), 6);
    //Serial.print(F(","));
    //Serial.print(gps.location.lng(), 6);
    }
  } else {
    Serial.print(F("INVALID"));
  }
  Serial.println();
}

void gpsFunction() {
  //String konum = String("");
  while (Serial1.available() > 0)
    if (gps.encode(Serial1.read()))
      displayInfo();

  if (millis() > 5000 && gps.charsProcessed() < 10) {
    Serial.println(F("No GPS detected: check wiring."));
    while (true)
      ;
  }
}