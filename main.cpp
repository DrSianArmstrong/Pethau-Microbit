/*
This is me trying to alter the initial Hello World program to have a timer in it as demoed
by I'm not entirely sure who, but the program was called Interrupt_TImer_LED
*/
#include "MicroBit.h"
//#include "mbed.h"

MicroBit uBit;


//Constructor
//------------------------------------------------------------------//
Ticker      interrput;


//Prototype
//------------------------------------------------------------------//
void intTimer( void );                  /* Interrupt fanction       */
void timer( unsigned long timer_set );

//Globle
//------------------------------------------------------------------//
volatile unsigned long  cnt_timer;      /* Used by timer function   */

int main() {
 uBit.init();
 uBit.display.scroll("Really Pissed off");
    /* Initialize MCU functions */
    interrput.attach(&intTimer, 0.001);
 
    while(1) {
 //       uBit.io.P0.setDigitalValue(1);
 //       timer( 1000 );
 //       uBit.io.P0.setDigitalValue(0);
 //       timer( 1000 );
    }
    
 release_fiber();
}




//Interrupt Timer
//------------------------------------------------------------------//
void intTimer( void )
{
    uBit.io.P0.setDigitalValue(!(uBit.io.P0.getDigitalValue()));
//    cnt_timer++;
}

//Timer fanction
//------------------------------------------------------------------//
void timer( unsigned long timer_set )
{
    cnt_timer = 0;
    while( cnt_timer < timer_set );
}

//------------------------------------------------------------------//
// End of file
//------------------------------------------------------------------//
