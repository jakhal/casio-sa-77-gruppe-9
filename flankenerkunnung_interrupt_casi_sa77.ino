#include <MaxMatrix.h>

const byte InitialInterruptPin = 21;
byte input = 0;

void setup() {
  // put your setup code here, to run once:
  DDRA=B11111111 ;
  DDRC =B00000000;
  pinMode(InitialInterruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(InitialInterruptPin), playtone, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:

}
void timerstart() {
  cli();//stop interrupts
  TCCR2A = 0;// set entire TCCR2A register to 0
  TCCR2B = 0;// same for TCCR2B
  TCNT2  = 0;//initialize counter value to 0
  // set compare match register for 8khz increments
  OCR2A = 34;// = (16*10^6) / (7142,8571428571*64) - 1 (must be <256)
  // turn on CTC mode
  TCCR2A |= (1 << WGM21);
  // Set CS22 bit for 64 prescaler
  TCCR2B |= (1 << CS22);   
  // enable timer compare interrupt
  TIMSK2 |= (1 << OCIE2A);
  sei();
}

ISR(TIMER2_COMPA_vect)
{
    playtone();
}

void playtone() 
{
  input = PINC;
  switch (input) {
  case B01111111:
    PORTA = B11011111;
    break;
  default:
    PORTA = B11111111;
    break;
    
    }
    
}



