/*
This is me trying to alter the initial Hello World program to have a timer in it 
*/
#include "MicroBit.h"
//#include "mbed.h"

MicroBit uBit;


//Constructor
//------------------------------------------------------------------//
Ticker      interrrrupt;


//Prototype
//------------------------------------------------------------------//
void intTimer( void );                  /* Interrupt function       */

int main() {
 uBit.init();
 uBit.display.scroll("So frustrating");
    /* Initialize MCU functions */
    interrrrupt.attach(&intTimer, 0.001);
 
    while(1) {

    }
    
 release_fiber();
}


//Interrupt Timer
//------------------------------------------------------------------//
void intTimer( void )
{
    uBit.io.P0.setDigitalValue(!(uBit.io.P0.getDigitalValue()));
}



//------------------------------------------------------------------//
// End of file
