#include "functions.h"


//bool role = true;
//char test[SIZE];
//oldLocation.toCharArray(texts,SIZE);

/*int texts_len=oldLocation.length()+1;
char texts_array[texts_len];
oldLocation.toCharArray(texts_array, texts_len);*/
//char testo[]="Selamqe Dünya";
void transmitterFunction()
{ 
  //while (!Serial) {
    // some boards need to wait to ensure access to serial over USB
  //}

  // initialize the transceiver on the SPI bus
  char test[100];
  oldLocation.toCharArray(test,100);

  Serial.println(test);
  radio.flush_tx();
  radio.write(test, sizeof(test));
}