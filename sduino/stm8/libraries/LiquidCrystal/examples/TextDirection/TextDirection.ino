/*
LiquidCrystal Library - TextDirection

Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
library works with all LCD displays that are compatible with the
Hitachi HD44780 driver. There are many of them out there, and you
can usually tell them by the 16-pin interface.

This sketch demonstrates how to use leftToRight() and rightToLeft()
to move the cursor.

The circuit:
* LCD RS pin to PA1 (digital pin 0)
* LCD Enable pin to PA2 (digital pin 1)
* LCD D4 pin to PA3 (digital pin 2)
* LCD D5 pin to PD2 (digital pin 11)
* LCD D6 pin to PD3 (digital pin 12)
* LCD D7 pin to PD4 (digital pin 13)
* LCD R/W pin to ground
* LCD VSS pin to ground
* LCD VCC pin to 5V
* 10K potentiometer:
* ends to +5V and ground
* wiper to LCD VO pin (pin 3)

Library originally added 18 Apr 2008
by David A. Mellis
library modified 5 Jul 2009
by Limor Fried (http://www.ladyada.net)
example added 9 Jul 2009
by Tom Igoe
modified 22 Nov 2010
by Tom Igoe
modified 26 Jan 2017
by Michael Mayer

This example code is in the public domain.

http://www.arduino.cc/en/Tutorial/LiquidCrystalTextDirection

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal (lcd,PA1,PA2, PA3,PD2,PD3,PD4);

int thisChar = 'a';

void setup() {
  // set up the LCD's number of columns and rows:
  lcd_begin(16, 2);
  // turn on the cursor:
  lcd_cursor();
}

void loop() {
  // reverse directions at 'm':
  if (thisChar == 'm') {
    // go right for the next letter
    lcd_rightToLeft();
  }
  // reverse again at 's':
  if (thisChar == 's') {
    // go left for the next letter
    lcd_leftToRight();
  }
  // reset at 'z':
  if (thisChar > 'z') {
    // go to (0,0):
    lcd_home();
    // start again at 0
    thisChar = 'a';
  }
  // print the character
  lcd_write(thisChar);
  // wait a second:
  delay(1000);
  // increment the letter:
  thisChar++;
}








