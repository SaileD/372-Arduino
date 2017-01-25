// Author:         John Smith
// Net ID:         jsmith
// Date:           11 Jan 2017
// Assignment:     Lab 0 part 1
//
// Description: This file contains a programmatic overall description of the
// program. It should never contain assignments to special function registers
// for the exception key one-line code such as checking the state of the pin.
//
// Requirements: Implement initLED and turnOnLED according to the requirements
// described in the .cpp files.
//----------------------------------------------------------------------//

#include <avr/io.h>
#include <Arduino.h>
#include "led.h"
#include "switch.h"

typedef enum stateType_enum{
  button_pressed, button_released
} stateType;

stateType state = button_released;

int main(){

  initLED();
  initSwitchPB3();
  while(1){
    /*
    * Implement a state machine in the whole loop which achieves assignment
    * requirements.
    */

    if(!(PIND & (1 << PIND2))){
          Serial.println("Pin pressed.");
          state = button_released;
          testLED();
        }

    // switch (state) {
    //   case button_pressed:
    //     Serial.println("State: button_pressed.");
    //     if((PIND & (1 << PIND2))){
    //       Serial.println("Pin pressed.");
    //       state = button_released;
    //     }
    //     testLED();
    //     break;
    //   case button_released:
    //     Serial.println("State: button_released.");
    //     if(!(PIND & (1 << PIND2))){
    //       Serial.println("Pin released.");
    //       state = button_pressed;
    //     }
    //     testLED();
    //     break;
    // }
  }

  return 0;
}
