#include "Keyboard.h"


void setup() {
  // put your setup code here, to run once:

  DDRF=0;
  PORTF=0xff;
  Serial.begin(115200);
}

#define PINKIE _BV(5)
#define RING _BV(4)
#define MIDDLE _BV(3)
#define INDEX _BV(2)
#define  THUMB _BV(1)
#define FUNCTION _BV(0)


byte setPins(byte source) {

  byte pins = 0;
  
  // pinkie
  if (!(source & _BV(7))) {
    pins |= _BV(5);
    
  }
  //ring
  if (!(source & _BV(6) )) {
    pins |= _BV(4);
  }
  // Middle
  if (!(source & _BV(5) )) {
    pins |= _BV(3);
  }
  // index
  if (!(source & _BV(4) )) {
    pins |= _BV(2);
  }

  //thumb
  if (!(source & _BV(0) )) {
    pins |= _BV(1);
  }  

  //thumb
  if (!(source & _BV(1) )) {
    pins |= _BV(0);
  }  

  return pins;
}

void sendKeystroke(byte pins) {
  switch (pins) {




case INDEX|MIDDLE: Keyboard.write('a'); break; 
case MIDDLE|RING|PINKIE: Keyboard.write('b'); break; 
case THUMB|MIDDLE: Keyboard.write('c'); break; 
case THUMB|INDEX|MIDDLE: Keyboard.write('d'); break; 
case INDEX: Keyboard.write('e'); break; 
case THUMB|INDEX|MIDDLE|RING: Keyboard.write('f'); break; 
case RING|PINKIE: Keyboard.write('g'); break; 
case THUMB|PINKIE: Keyboard.write('h'); break; 
case THUMB|INDEX: Keyboard.write('i'); break; 
case THUMB|RING|PINKIE: Keyboard.write('j'); break; 
case THUMB|RING: Keyboard.write('k'); break; 
case THUMB|INDEX|PINKIE: Keyboard.write('l'); break; 
case INDEX|MIDDLE|RING|PINKIE: Keyboard.write('m'); break; 
case MIDDLE|RING: Keyboard.write('n'); break; 
case MIDDLE: Keyboard.write('o'); break; 
case THUMB|INDEX|MIDDLE|RING|PINKIE: Keyboard.write('p'); break; 
case MIDDLE|PINKIE: Keyboard.write('q'); break; 
case THUMB|INDEX|RING: Keyboard.write('r'); break; 
case RING: Keyboard.write('s'); break; 
case INDEX|RING: Keyboard.write('t'); break; 
case PINKIE: Keyboard.write('u'); break; 
case INDEX|PINKIE: Keyboard.write('v'); break; 
case THUMB|INDEX|RING|PINKIE: Keyboard.write('w'); break; 
case THUMB|MIDDLE|RING|PINKIE: Keyboard.write('x'); break; 
case THUMB|MIDDLE|RING: Keyboard.write('y'); break; 
case THUMB|MIDDLE|PINKIE: Keyboard.write('z'); break; 
case THUMB: Keyboard.write(' '); break; 
case INDEX|MIDDLE|RING: Keyboard.write('.'); break; 
case INDEX|MIDDLE|PINKIE: Keyboard.write('-'); break; 
case INDEX|RING|PINKIE: Keyboard.write(','); break; 
case THUMB|INDEX|MIDDLE|PINKIE: Keyboard.write('\''); break; 
case FUNCTION: Keyboard.print("command"); break; 



  }

  
}


void sendNumericKeystroke(byte pins) {
  switch (pins) {


case INDEX: Keyboard.write('1'); break; 
case THUMB|INDEX: Keyboard.write('2'); break; 
case THUMB|INDEX|MIDDLE: Keyboard.write('3'); break; 
case THUMB|INDEX|MIDDLE|RING: Keyboard.write('4'); break; 
case THUMB|INDEX|MIDDLE|RING|PINKIE: Keyboard.write('5'); break; 
case PINKIE: Keyboard.write('6'); break; 
case RING|PINKIE: Keyboard.write('7'); break; 
case MIDDLE|RING|PINKIE: Keyboard.write('8'); break; 
case INDEX|MIDDLE|RING|PINKIE: Keyboard.write('9'); break; 
case MIDDLE: Keyboard.write('0'); break; 


  }


void sendPunctuationKeystroke(byte pins) {
  switch (pins) {

case FUNCTION|MIDDLE|RING: Keyboard.write('numericshift'); break; 
case THUMB|MIDDLE: Keyboard.write('('); break; 
case MIDDLE|PINKIE: Keyboard.write(')'); break; 
case THUMB|INDEX|PINKIE: Keyboard.write('#'); break; 
case RING: Keyboard.write('$'); break; 
case INDEX|MIDDLE: Keyboard.write('*'); break; 
case INDEX|RING: Keyboard.write('+'); break; 
case THUMB|PINKIE: Keyboard.write('-'); break; 
case THUMB|MIDDLE|RING|PINKIE: Keyboard.write('x'); break; 
case THUMB|RING|PINKIE: Keyboard.write('='); break; 
case THUMB|MIDDLE|RING: Keyboard.write('?'); break; 
case INDEX|MIDDLE|PINKIE: Keyboard.write('!'); break; 
case THUMB|RING: Keyboard.write('/'); break; 
case THUMB|INDEX|RING|PINKIE: Keyboard.write(':'); break; 
case THUMB|INDEX|RING: Keyboard.write(';'); break; 
case THUMB|MIDDLE|PINKIE: Keyboard.write('%'); break; 
case MIDDLE|RING: Keyboard.write('"'); break; 
case INDEX|PINKIE: Keyboard.write('&'); break; 
case THUMB|INDEX|MIDDLE|PINKIE: Keyboard.write('@'); break; 
case THUMB: Keyboard.write('space'); break; 
case INDEX|MIDDLE|RING: Keyboard.write('.'); break; 
case INDEX|RING|PINKIE: Keyboard.write(','); break; 

  }
  

byte lastPins=0;

void loop() {
  // put your main code here, to run repeatedly:
  byte pins = setPins(PINF);

  delay(1);
  if (pins ==0x00 && lastPins != 0x00 ) {

      sendKeystroke(lastPins);
      lastPins = 0x00;
  }
  

  lastPins = lastPins| pins;
}/*


*/


