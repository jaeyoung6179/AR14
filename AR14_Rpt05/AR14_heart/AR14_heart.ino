#include "LedControlMS.h"

// pin 4 is connected to the DataIn
// pin 3 is connected to the CLK
// pin 2 is connected to LOAD

#define NBR_MTX 1 //number of matrices attached is one
LedControl lc=LedControl(4,3,2, NBR_MTX);//
unsigned long delayTime = 1200;
byte k1[]=
{
  B00100100,
  B01011010,
  B10000001,
  B10000001,
  B10000001,
  B01000010,
  B00100100,
  B00011000
};
byte k2[]=
{
  B00000000,
  B01100110,
  B11111111,
  B11111111,
  B11111111,
  B01111110,
  B00111100,
  B00011000,
};
 void setup()
{
    lc.shutdown(0,false);
    /* Set the brightness to a medium values */
    lc.setIntensity(0,5);
    /* and clear the display */
    lc.clearDisplay(0);

    delay(100);
  
}

void k()
{
  for(int i=0;i<8;i++)
  {
  lc.setRow(0,i,k1[i]);
  }
}

void k3()
{
  for(int i=0;i<8;i++)
  {
  lc.setRow(0,i,k2[i]);
  }
}
void loop()
{
  //sending characters to display
  k();
  delay(delayTime);
  //clearing the display
  k3();
  delay(delayTime);

  delay(3000);
}
