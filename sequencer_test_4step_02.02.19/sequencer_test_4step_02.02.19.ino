//We always have to include the library
#include "LedControl.h"
#include "TimerOne.h"
/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(12,11,10,1);
//Pin connected to latch pin (ST_CP) of 74HC595
const int latchPin = 8;
//Pin connected to clock pin (SH_CP) of 74HC595
const int clockPin = 9;
////Pin connected to Data in (DS) of 74HC595
const int dataPin = 7;
/* we always wait a bit between updates of the display */
const int buttonpin1 = 2;
const int buttonpin2 = 3;
const int buttonpin3 = 4;
const int buttonpin4 = 5;
const int ledpin = 6;
boolean buttonstate1 = 0;
boolean buttonstate2 = 0;
boolean buttonstate3 = 0;
boolean buttonstate4 = 0;
int row1 = 0;
int rownr1 =0;
int row2 = 0;
int rownr2 =0;
int row3 = 0;
int rownr3 =0;
int row4 = 0;
int rownr4 =0;
int stepcol = 0;
int instrow1 = 0;
int instrow2 = 0;
int instrow3 = 0;
int instrow4 = 0;
int pitchtune = 0;
int ledstate = LOW;

void setup() {  
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  pinMode(buttonpin1, INPUT);
  pinMode(buttonpin2, INPUT);
  pinMode(buttonpin3, INPUT);
  pinMode(buttonpin4, INPUT);
  pinMode(ledpin, OUTPUT);
  
  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0);
  
  Serial.begin(31250);
  pitchtune = 10;
  Timer1.initialize(500000); // set a timer of length 100000 microseconds (or 0.1 sec - or 10Hz => the led will blink 5 times, 5 cycles of on-and-off, per second)
  Timer1.attachInterrupt( timerIsr ); // attach the service routine here
}
void timerIsr()
{

    if (ledstate == HIGH)
      {
      ledstate = LOW;
      }
    else
    {
    ledstate = HIGH;  
    }
    if (stepcol == 0)
    {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B01100000);
    digitalWrite(latchPin, HIGH);
    noteOn(0x90, row1*pitchtune, 0x45);
    noteOn(0x90, row4*pitchtune, 0x00);
    lc.setLed(0,0, 7,false);
    lc.setLed(0,0, 6,false);
    }
    lc.setLed(0,0, stepcol,true);
    lc.setLed(0,0, stepcol+1,true);
    if (stepcol != 0)
    {
    lc.setLed(0,0, stepcol-1,false);
    lc.setLed(0,0, stepcol-2,false);
      if (stepcol ==2){
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, LSBFIRST, B11011010);
        digitalWrite(latchPin, HIGH);
        noteOn(0x90, row2*pitchtune, 0x45);
        noteOn(0x90, row1*pitchtune, 0x00);
      }
      if (stepcol == 4){
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, LSBFIRST, B11110010);
        digitalWrite(latchPin, HIGH);
        noteOn(0x90, row3*pitchtune, 0x45);
        noteOn(0x90, row2*pitchtune, 0x00);
      }
    }
    if (stepcol == 6)
    {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B01100110);
    digitalWrite(latchPin, HIGH);
    noteOn(0x90, row4*pitchtune, 0x45);
    noteOn(0x90, row3*pitchtune, 0x00);
    stepcol = 0;  
    }
    else {
      stepcol = stepcol+2;
    }
  
}
void noteOn(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}
void buttontest() {
  delay(10);
  buttonstate1 = digitalRead(buttonpin1);
  buttonstate2 = digitalRead(buttonpin2);
  buttonstate3 = digitalRead(buttonpin3);
  buttonstate4 = digitalRead(buttonpin4);
  
  
  //Abfrage Button 1
  if (buttonstate1 == true)
    {
      row1 = analogRead(A0)/128;
      lc.setColumn(0,0,rownr1);
      lc.setColumn(0,1,rownr1);

  if (row1 == 7)
    {
    rownr1 = B00000001;
    instrow1= 7;
    }
  if (row1 == 6)
    {
    rownr1 = B00000010;
    instrow1= 6;
    }
  if ( row1 == 5)
    {
    rownr1 = B00000100;
    instrow1= 5;
    }
  if (row1 == 4)
    {
    rownr1 = B00001000;
    instrow1= 4;
    }
  if (row1 == 3)
    {
    rownr1 = B00010000;
    instrow1= 3;
    }
  if (row1 == 2)
    {
    rownr1 = B00100000;
    instrow1= 2;
    }
  if (row1 == 1)
    {
    rownr1 = B01000000;
    instrow1= 1;
    }
  if (row1 == 0)
    {
    rownr1 = B10000000;
    instrow1= 0;
    }
    } 
  else
    {
    //lc.setColumn(0,0,0);
    //lc.setColumn(0,1,0);
    }
    
  //Abfrage Button 2
  if (buttonstate2 == true)
    {
      row2 = analogRead(A0)/128;
      lc.setColumn(0,2,rownr2);
      lc.setColumn(0,3,rownr2);
      
  if (row2 == 7)
    {
    rownr2 = B00000001;
    instrow2= 7;
    }
  if (row2 == 6)
    {
    rownr2 = B00000010;
    instrow2= 6;
    }
  if ( row2 == 5)
    {
    rownr2 = B00000100;
    instrow2= 5;
    }
  if (row2 == 4)
    {
    rownr2 = B00001000;
    }
  if (row2 == 3)
    {
    rownr2 = B00010000;
    }
  if (row2 == 2)
    {
    rownr2 = B00100000;
    }
  if (row2 == 1)
    {
    rownr2 = B01000000;
    }
  if (row2 == 0)
    {
    rownr2 = B10000000;
    }
    } 
  else
    {
    //lc.setColumn(0,2,0);
    //lc.setColumn(0,3,0);
    }
    
  //Abfrage Button 3
  if (buttonstate3 == true)
   {
    row3 = analogRead(A0)/128;
      lc.setColumn(0,4,rownr3);
      lc.setColumn(0,5,rownr3);

  if (row3 == 7)
    {
    rownr3 = B00000001;
    }
  if (row3 == 6)
    {
    rownr3 = B00000010;
    }
  if ( row3 == 5)
    {
    rownr3= B00000100;
    }
  if (row3 == 4)
    {
    rownr3 = B00001000;
    }
  if (row3 == 3)
    {
    rownr3 = B00010000;
    }
  if (row3 == 2)
    {
    rownr3 = B00100000;
    }
  if (row3 == 1)
    {
    rownr3 = B01000000;
    }
  if (row3 == 0)
    {
    rownr3 = B10000000;
    }
   } 
  else
    {
    //lc.setColumn(0,4,0);
    //lc.setColumn(0,5,0);
    }
    
  //Abfrage Button 4
  if (buttonstate4 == true)
       {
    row4 = analogRead(A0)/128;
      lc.setColumn(0,6,rownr4);
      lc.setColumn(0,7,rownr4);

  if (row4 == 7)
    {
    rownr4 = B00000001;
    }
  if (row4 == 6)
    {
    rownr4 = B00000010;
    }
  if ( row4 == 5)
    {
    rownr4= B00000100;
    }
  if (row4 == 4)
    {
    rownr4 = B00001000;
    }
  if (row4 == 3)
    {
    rownr4 = B00010000;
    }
  if (row4 == 2)
    {
    rownr4 = B00100000;
    }
  if (row4 == 1)
    {
    rownr4 = B01000000;
    }
  if (row4 == 0)
    {
    rownr4 = B10000000;
    }
   } 
  else
    {
    //lc.setColumn(0,6,0);
    //lc.setColumn(0,7,0);
    } 
 
}

 
void photomidi() {
  int photoread = 0;
  int multiplier = 0;
  multiplier = analogRead(A1);
  photoread = analogRead(A2);
  map(multiplier, 0, 1023, 0x3C, 0x5A);
  if (photoread > 300) {
  noteOn(0x90, multiplier, 0x45); 
  }
  else {
  noteOn(0x90, multiplier, 0x00);
  }
  delay(50);
  }


void loop() { 
  buttontest();
  //photomidi();
  if(digitalRead(A2))
  {
    timerIsr();
    while(digitalRead(A2)){
    }
  }
  /*if (digitalRead(13))
  {
  Timer1.detachInterrupt();
  //Timer1.initialize(map(analogRead(A1),0,1023,100000,10000000)); // set a timer of length 100000 microseconds (or 0.1 sec - or 10Hz => the led will blink 5 times, 5 cycles of on-and-off, per second)
  Timer1.attachInterrupt( timerIsr,map(analogRead(A1),0,1023,100000,10000000)); // attach the service routine here  
  //Timer1.setPeriod(map(analogRead(A1),0,1023,100000,10000000));
  while(!digitalRead(13)){}
  }*/
}
