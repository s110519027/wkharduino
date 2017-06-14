int latchPin =8;
int clockPin=12;
int dataPin=11;

byte colDataMatrix[8]={
  B01111111,
  B10111111,
  B11011111,
  B11101111,
  B11110111,
  B11111011,
  B11111101,
  B11111110
  };
  
byte rowDataMatrix[8]={
  B11111111,
  B11000011,
  B10100101,
  B10011001,
  B10011001,
  B10100101,
  B11000011,
  B11111111
  };
  
int delay_time=1;

void setup() {
  // put your setup code here, to run once:
pinMode(latchPin,OUTPUT);
pinMode(clockPin,OUTPUT);
pinMode(dataPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
for(int i=0 ; i<8 ; i++ ){
  digitalWrite(latchPin,LOW) ;
   shiftOut(dataPin,clockPin,MSBFIRST,colDataMatrix[i]);
      shiftOut(dataPin,clockPin,MSBFIRST,rowDataMatrix[i]);
  digitalWrite(latchPin,HIGH) ;
  delay(delay_time);
  }
}
/*void pickDigit(int x){
  byte rowByte=1<<x;
   shiftOut(dataPin,clockPin,MSBFIRST,rowByte);
  }*/
