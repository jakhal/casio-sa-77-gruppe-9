const int InterruptPin = 2;
void setup() {
  // put your setup code here, to run once:
  DDRA=B11111111 ;
  DDRC =B00000000;
  PORTA=B11111111;
}
void loop() {
  // put your main code here, to run repeatedly:
attachInterrupt(digitalPinToInterrupt(InterruptPin), playnote, LOW);
PORTA =B11111111;
}

void playnote() {
 /* start=millis();
  unterschied=0;
 while(unterschied<4){
 */
 PORTA = B01111111;
 //unterschied=millis()-start;  
 
}



