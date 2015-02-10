int incomingByte = 0;
int displayVal = 0;


#include "Seven_Seg_LED_Display.h"
kdLEDDisplay disp;             // I made a mistake declaring this inside 'loop', but in which case, it can't remember what it displayed previously

int state = 0;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  Serial.println("OK");
  disp.DisplayNumber(0000);
}

void loop() {
        if (Serial.available() > 0) {
          int out = 0;
          int num;
          int seq = 3;
          int mnoznik = 1;
          while(Serial.available() > 0){
            // read the incoming byte:
            incomingByte = Serial.read();

            // say what you got:
//            Serial.print("I received: ");
//            Serial.println(incomingByte);
            switch(incomingByte){
              case 48:
                num = 0;
                break;
              case 49:
                num = 1;
                break;
              case 50:
                num = 2;
                break;
              case 51:
                num = 3;
                break;
              case 52:
                num = 4;
                break;
              case 53:
                num = 5;
                break;
              case 54:
                num = 6;
                break;
              case 55:
                num = 7;
                break;
              case 56:
                num = 8;
                break;
              case 57:
                num = 9;
                break;
              default:
                num = 0;
            }
            switch(seq){
              case 0:
                mnoznik = 1;
                break;
              case 1:
                mnoznik = 10;
                break;
              case 2:
                mnoznik = 100;
                break;
              case 3:
                mnoznik = 1000;
                break;
            }
            out += mnoznik * num;
            
//            Serial.print("NUM=");
//            Serial.print(num);
//            Serial.print("; SEQ=");
//            Serial.print(seq);
//            Serial.print("; mnoznik=");
//            Serial.print(mnoznik);
//            Serial.print("; mnoznik*num=");
//            Serial.print(mnoznik * num);
//            Serial.print("; OUT=");
//            Serial.println(out);
            seq--;
            delay(5);
//              disp.DisplayNumber(num);
          }
//          Serial.print("; OUT=");
//          Serial.println(out);
          if(out > -1)
            displayVal = out;
        }
        
  
  disp.DisplayNumber(displayVal);
}
