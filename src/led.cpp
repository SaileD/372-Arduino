// Description: This file implements turnOnLED and initLED to control
// the LEDs.
//----------------------------------------------------------------------//

#include <avr/io.h>
#include <util/delay.h>
#include "led.h"
#include "switch.h"
#include <Arduino.h>

/*
 * Initializes pins B6, B5, and B4 to be in output mode using the DDR register
 * and bit operations. Other bits in DDRB must not be affected by this
 * assignment.
 */
void initLED(){
  //we're using pins 13,12,11 on the board, which correspond to
  //PB7, PB6, and PB5
  DDRB |= (1<<4); //001000
  DDRB |= (1<<5); //010000
  DDRB |= (1<<6); //100000
}

/*
 * Turns on a specified LED and turns off other LEDS using PORTB registers
 * and bit operations. This function should also not affect other bits in
 * PORTB while turning on an off LEDs. You can choose which number corresponsds
 * to which LED, but this mapping should be matching the testLED function.
 */
void turnOnLED(int led){
  PORTB = 000000;
  if(led == 0){
    PORTB |= (1<< PORTB6);
  }
  else if(led == 1){
    PORTB |= (1<< PORTB5);
  }
  else if(led == 2){
    PORTB |= (1<< PORTB4);
  }
}

/*
 * Tests initLEDs and turnOnLED by turning on each LED in succession.
 */
void testLED(){
  turnOnLED(0);
  _delay_ms(250.0);
  turnOnLED(1);
  _delay_ms(250.0);
  turnOnLED(2);
  _delay_ms(250.0);
}

//void
