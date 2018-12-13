
long unterschied = 0;
long interval = 1000;
long start = 0;
int takt = 2000;      //Länge des Takts festlegen
int resetT = 30;

byte rows = 0;
int ges = 0;
//Nummerierung für spalten und Reihen vereinfachen
byte sr1 = B01111111;
byte sr2 = B10111111;
byte sr3 = B11011111;
byte sr4 = B11101111;
byte sr5 = B11110111;
byte sr6 = B11111011;
byte sr7 = B11111101;
byte sr8 = B11111110;


void setup() {
  DDRC = B00000000;
  DDRA = B11111111;
}

void loop() {
  // put your main code here, to run repeatedly:
  

  lied();
  
  
  
}
//Dienst um einen Ton auszugeben mit den Übergabeparametern reihe und spalte
void spielen(byte reihe, byte spalte) {
   if (PINC == reihe) {
   PORTA = spalte;
  } else {
    PORTA = B11111111;
    }
  }
  
//Dienst um eine bestimmte Note mit bestimmter Reihe und Spalte auszugeben  mit dem Übergabeparameter für die Länge des zu spielenden Tons
void c4(int val) {
  unterschied = 0;                        //unterschied auf 0 setzten
  start = millis();                       //start vor beginn der while Schleife auf die Millisekunden seit start des Sketches setzen
  while(unterschied<=val) {               //Überprüfen ob Unterschied kleiner oder gleich der länge der Note
    unterschied = millis()-start;         //unterschied auf die millisekunden-start setzen
    spielen(sr4,sr6);                     //mit den Reihen und Spalten der note, diese über den Dienst spielen aufrufen
  }
}

void d4(int val) {
  unterschied = 0;
  start = millis();
  while(unterschied<=val) {
    unterschied = millis()-start;
    spielen(sr4,sr4);
  }
}

void e4(int val) {
  unterschied = 0;
  start = millis();
  while(unterschied<=val) {
    unterschied = millis()-start;
    spielen(sr1,sr2);
  }
}

void f4(int val) {
  unterschied = 0;
  start = millis();
  while(unterschied<=val) {
    unterschied = millis()-start;
    spielen(sr3,sr7);
  }
}

void g4(int val) {
  unterschied = 0;
  start = millis();
  while(unterschied<=val) {
    unterschied = millis()-start;
    spielen(sr3,sr5);
  }
}

void g3(int val) {
  unterschied = 0;
  start = millis();
  while(unterschied<=val) {
    unterschied = millis()-start;
    spielen(sr1,sr1);
  }
}

void a4(int val) {
  unterschied = 0;
  start = millis();
  while(unterschied<=val) {
    unterschied = millis()-start;
    spielen(sr3,sr3);
  }
}

//Alle Spalten in allen Reihen auf 1 setzen
void set1(int val) {
  unterschied = 0;
  start = millis();
  while(unterschied<=val) {
    unterschied = millis()-start;
    spielen(sr1,B11111111);
    spielen(sr2,B11111111);
    spielen(sr3,B11111111);
    spielen(sr4,B11111111);
    spielen(sr5,B11111111);
    spielen(sr6,B11111111);
    spielen(sr7,B11111111);
    spielen(sr8,B11111111); 
  }
}

//void spiele3(void note1,void note2,void note3, int t) {
  //ti = t/30;
  //for(int i = 0; i<=ti; i++) {
   // note1(10);
   // note2(10);
    //note3(10);
