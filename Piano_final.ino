int input = 0;          //rechecksignal einlese speicher variable

byte n = 0;
byte Key[] = {0,0,0,0,0,0,0,0};   //key array, tasten werden gleichzeitig gespielt
byte ToPlay[] = {255,255,255,255,255,255,255,255,255};    //ausgabepins in dezimal aus key library errechnet

const byte KeyInputLibrary[] = {0,64,64,64,64,64,64,64,64,128,128,128,128,128,128,128,128,16,16,16,16,16,16,16,16,32,32,32,32,32,32,32,32,8,8,2,2,2,2,2,2,2,8,8,8};
const byte KeyOutputLibrary[] = {0,2,1,8,4,32,16,128,64,2,1,8,4,32,16,128,64,2,1,8,4,32,16,128,64,2 ,1,8,4,32,16,128,64,32,16,2,4,8,16,32,64,128,1,2,4};
int TaktMulitplier = 40;
unsigned long Takt = 0; //durchgelaufene Takte
unsigned long LastTakt = -1; //durchgelaufene Takte
bool TaktCheck = 1;
 int j=0;
int KeyMatrix[][8]= {  { 8, 12, 15, 27, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 24, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 24, 0, 0, 0, 0 },
                        { 8, 12, 15, 24, 0, 0, 0, 0 },
                        { 8, 12, 15, 24, 0, 0, 0, 0 },   
                        { 8, 12, 0, 24, 0, 0, 0, 0 },  

                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                                                                           
                        { 7, 10, 15, 25, 0, 0, 0, 0 },
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  

                        { 7, 10, 15, 22, 0, 0, 0, 0 },                       
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  
                        { 7, 10, 15, 0, 0, 0, 0, 0 },

                        { 7, 10, 15, 22, 0, 0, 0, 0 },
                        { 7, 10, 15, 22, 0, 0, 0, 0 },                        
                        { 7, 10, 15, 22, 0, 0, 0, 0 },
                        { 7, 10, 15, 22, 0, 0, 0, 0 },

                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },

                        { 8, 12, 15, 20, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },

                        { 8, 12, 15, 22, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },

                         { 8, 12, 15, 24, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },

                        { 8, 12, 15, 25, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },

                         { 8, 12, 15, 27, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        
                        { 8, 12, 15, 27, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        
                        { 8, 12, 15, 27, 0, 0, 0, 0 },
                        { 8, 12, 15, 27, 0, 0, 0, 0 },
                        { 8, 12, 15, 27, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },

                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                      
                        { 0, 0, 0, 0, 27, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },

                        { 0, 0, 0, 0, 24, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },


                        { 0, 0, 0, 0, 24, 0, 0, 0 },
                        { 0, 0, 0, 0, 24, 0, 0, 0 },
                        { 0, 0, 0, 0, 24, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },

                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        
                        { 7, 10, 15, 25, 0, 0, 0, 0 },
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  

                        { 7, 10, 15, 22, 0, 0, 0, 0 },                       
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  
                        { 7, 10, 15, 0, 0, 0, 0, 0 },

                        { 7, 10, 15, 22, 0, 0, 0, 0 },
                        { 7, 10, 15, 22, 0, 0, 0, 0 },                        
                        { 7, 10, 15, 22, 0, 0, 0, 0 },
                        { 7, 10, 15, 22, 0, 0, 0, 0 },

                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },                       

                        { 8, 12, 15, 20, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },                                  
                                  
                                  
                        { 8, 12, 15, 24, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },                                 
                                  
                        { 7, 10, 15, 27, 0, 0, 0, 0 },                       
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  
                        { 7, 10, 15, 0, 0, 0, 0, 0 },                                 
                                  
                        { 7, 10, 15, 27, 0, 0, 0, 0 },                       
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  
                        { 7, 10, 15, 0, 0, 0, 0, 0 },                                    

                        { 8, 12, 15, 20, 0, 0, 0, 0 },
                        { 8, 12, 15, 20, 0, 0, 0, 0 },                        
                        { 8, 12, 15, 20, 0, 0, 0, 0 },
                        { 8, 12, 15, 20, 0, 0, 0, 0 },

                        { 8, 12, 15, 20, 0, 0, 0, 0 },
                        { 8, 12, 15, 20, 0, 0, 0, 0 },                        
                        { 8, 12, 15, 20, 0, 0, 0, 0 },
                        { 8, 12, 15, 20, 0, 0, 0, 0 },
                        
                        { 8, 12, 15, 20, 0, 0, 0, 0 },
                        { 8, 12, 15, 20, 0, 0, 0, 0 },                        
                        { 8, 12, 15, 20, 0, 0, 0, 0 },
                        { 8, 12, 15, 20, 0, 0, 0, 0 },

                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },

                        { 7, 10, 15, 22, 0, 0, 0, 0 },                       
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  
                        { 7, 10, 15, 0, 0, 0, 0, 0 },    
                        
                        { 7, 10, 15, 22, 0, 0, 0, 0 },                       
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  

                        { 7, 10, 15, 22, 0, 0, 0, 0 },                       
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  
                        
                        { 7, 10, 15, 22, 0, 0, 0, 0 },                       
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  
                        { 7, 10, 15, 0, 0, 0, 0, 0 },     
                                            
                        { 7, 10, 15, 22, 0, 0, 0, 0 },                       
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  

                        { 7, 10, 15, 24, 0, 0, 0, 0 },                       
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  

                        { 7, 10, 15, 25, 0, 0, 0, 0 },                       
                        { 7, 10, 15, 25, 0, 0, 0, 0 },  
                        { 7, 10, 15, 25, 0, 0, 0, 0 },  
                        { 7, 10, 15, 0, 0, 0, 0, 0 }, 
                         
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },                       
                       
                        { 8, 12, 15, 24, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 }, 

                        { 8, 12, 15, 24, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 }, 

                        { 8, 12, 15, 24, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 }, 
                        
                        { 8, 12, 15, 24, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 }, 

                        { 8, 12, 15, 24, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 }, 

                        { 8, 12, 15, 25, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 }, 


                        { 8, 12, 15, 27, 0, 0, 0, 0 },
                        { 8, 12, 15, 27, 0, 0, 0, 0 },
                        { 8, 12, 15, 27, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 }, 
                        
                         { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },                        

                        { 0, 0, 0, 0, 27, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },

                        { 0, 0, 0, 0, 24, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },


                        { 0, 0, 0, 0, 24, 0, 0, 0 },
                        { 0, 0, 0, 0, 24, 0, 0, 0 },
                        { 0, 0, 0, 0, 24, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },

                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        
                        { 7, 10, 15, 25, 0, 0, 0, 0 },
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  

                        { 7, 10, 15, 22, 0, 0, 0, 0 },                       
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  
                        { 7, 10, 15, 0, 0, 0, 0, 0 },

                        { 7, 10, 15, 22, 0, 0, 0, 0 },
                        { 7, 10, 15, 22, 0, 0, 0, 0 },                        
                        { 7, 10, 15, 22, 0, 0, 0, 0 },
                        { 7, 10, 15, 22, 0, 0, 0, 0 },

                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 }, 

                        { 8, 12, 15, 20, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },                                  
                                  
                                  
                        { 8, 12, 15, 24, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },
                        { 8, 12, 15, 0, 0, 0, 0, 0 },                                 
                                  
                        { 7, 10, 15, 27, 0, 0, 0, 0 },                       
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  
                        { 7, 10, 15, 0, 0, 0, 0, 0 },                                 
                                  
                        { 7, 10, 15, 27, 0, 0, 0, 0 },                       
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  
                        { 7, 10, 15, 0, 0, 0, 0, 0 },  
                        { 7, 10, 15, 0, 0, 0, 0, 0 },                                    

                        { 8, 12, 15, 20, 0, 0, 0, 0 },
                        { 8, 12, 15, 20, 0, 0, 0, 0 },                        
                        { 8, 12, 15, 20, 0, 0, 0, 0 },
                        { 8, 12, 15, 20, 0, 0, 0, 0 },

                        { 8, 12, 15, 20, 0, 0, 0, 0 },
                        { 8, 12, 15, 20, 0, 0, 0, 0 },                        
                        { 8, 12, 15, 20, 0, 0, 0, 0 },
                        { 8, 12, 15, 20, 0, 0, 0, 0 },
                        
                        { 8, 12, 15, 20, 0, 0, 0, 0 },
                        { 8, 12, 15, 20, 0, 0, 0, 0 },                        
                        { 8, 12, 15, 20, 0, 0, 0, 0 },
                        { 8, 12, 15, 20, 0, 0, 0, 0 },

                                                                                 
                                  };

int Size=sizeof KeyMatrix / sizeof KeyMatrix[0];

//KeyList[] {25,


void setup() {
  DDRA = 255 ;
  DDRC = 0;
  PORTA = 255;

}


void loop() {
  if (j < Size){
Key[0]=KeyMatrix[j][0];
Key[1]=KeyMatrix[j][1];
Key[2]=KeyMatrix[j][2];
Key[3]=KeyMatrix[j][3];
Key[4]=KeyMatrix[j][4];
Key[5]=KeyMatrix[j][5];
Key[6]=KeyMatrix[j][6];
Key[7]=KeyMatrix[j][7];
  }
else
{
Key[0]=0;
Key[1]=0;
Key[2]=0;
Key[3]=0;
Key[4]=0;
Key[5]=0;
Key[6]=0;
Key[7]=0;
  }


  input = PINC;      //rechteck signal reinholen
if (input == 255-2 && TaktCheck == 1){    //Takt weiter zählen wenn check zulässt
  Takt = Takt+1;        //Takt Zähler abhängig von der Rechteckwelle auf einem PIN
  TaktCheck = 0;        //Check reset
}

if (Takt > LastTakt + TaktMulitplier){  
  LastTakt = Takt;
  j=j+1;

 // hier Keyvektor ändern

  ToPlay[1] = 255;
  ToPlay[2] = 255;
  ToPlay[3] = 255;
  ToPlay[4] = 255;
  ToPlay[5] = 255;
  ToPlay[6] = 255;
  ToPlay[7] = 255;
  ToPlay[8] = 255;  
              
  for (int i=0; i<=7; i=i+1) {
switch(KeyInputLibrary[Key[i]]){
  case (2):
    ToPlay[1]=ToPlay[1]-KeyOutputLibrary[Key[i]]; 
  break;
    case (8):
    ToPlay[2]=ToPlay[2]-KeyOutputLibrary[Key[i]];
  break;
    case (16):
    ToPlay[3]=ToPlay[3]-KeyOutputLibrary[Key[i]];
  break;
    case (32):
    ToPlay[4]=ToPlay[4]-KeyOutputLibrary[Key[i]];
  break;
    case (64):
    ToPlay[5]=ToPlay[5]-KeyOutputLibrary[Key[i]];
  break;
    case (128):
    ToPlay[6]=ToPlay[6]-KeyOutputLibrary[Key[i]];
  break;
  default:
  break;
}
}
}



  
switch(input){       
  case (255-2):
    n=1; 
  break;
    case (255-8):
    n=2;
    TaktCheck = 1;    //Check dass Takt weitergezählt werden kann setzen
  break;
    case (255-16):
    n=3;
  break;
    case (255-32):
    n=4;
  break;
    case (255-64):
    n=5;
  break;
    case (255-128):
    n=6;
  break;
  default:
  n=0;
  break;
}
PORTA=ToPlay[n];


}
