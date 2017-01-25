// Description: This file implements the initialization of an external
// switch.
//----------------------------------------------------------------------//

#include "switch.h"
#include <avr/io.h>

/*
 * Initializes pull-up resistor on PB3 and sets it into input mode
 */
void initSwitchPB3(){
  PORTD |= (1 << PORTD2); // set PB3 as a pull-up when DDRD is set to zero.
  DDRD &= ~(1 << DDD2); //set PB3 as input
}
