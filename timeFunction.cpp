#include "functions.h"

String timeSettings(){
  if (RTC.read(tm)) {
    String saat=String(tm.Hour);
    saat.concat(":");
    saat.concat(String(tm.Minute));
    saat.concat(":");
    saat.concat(String(tm.Second));
    //Serial.println(saat);
    return saat;
  }
}

void print2digits(int number) {
  if (number >= 0 && number < 10) {
    display.write('0');
  }
  display.print(number);
}

