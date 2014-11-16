#include <plib.h>
#include <p32xxxx.h>
#include "HardwareProfile.h"


void init_timer1(void){
    // configure Timer1 module
    PR1 = 25000-1;  // set the period register
    T1CON = 0x8030;	// enabled, prescaler 1:256, internal clock
}

void init_timer2(void){
    // 1. init timers
    PR2 = 15;
    T2CON = 0x8030;
}

/*
 void __ISR_SINGLE__ T1Interrupt( void){
    //clear the interrupt flag
    mT1ClearIntFlag();
} //T1Interrupt
 */

void Delay_ms_T1( unsigned t)
{
    T1CON = 0x8000;     // enable TMR1, Tpb, 1:1
    while (t--)
    {  // t x 1ms loop
        TMR1 = 0;
        while (TMR1 < FPB/1000);
    }
} // Delayms
