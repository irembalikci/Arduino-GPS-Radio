#include "functions.h"

void playRadio()
{
  if(!playing)
  {
  if (!fmRadio.initWire(Wire)) {
  Serial.println("no radio chip found.");
  delay(4000);
  //ESP.restart();
};
  
fmRadio.setBandFrequency(FIX_BAND, FIX_STATION);
  fmRadio.setVolume(FIX_VOLUME);
  fmRadio.setMono(false);
  fmRadio.setMute(false);
  fmRadio.setBassBoost(false);
  playing=true;
}
}

void stopRadio()
{
  fmRadio.term();
  playing=false;
}