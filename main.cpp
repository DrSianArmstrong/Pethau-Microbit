/*
This is me trying to alter the initial Hello World program to have a timer in it as demoed
by I'm not entirely sure who, but the program was called Interrupt_TImer_LED
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
void timer( unsigned long timer_set );

//Globle
//------------------------------------------------------------------//
volatile unsigned long  cnt_timer;      /* Used by timer function   */

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

//Timer function
//------------------------------------------------------------------//
void timer( unsigned long timer_set )
{
    cnt_timer = 0;
    while( cnt_timer < timer_set );
}

//------------------------------------------------------------------//
// End of file
//------------------------------------------------------------------//
