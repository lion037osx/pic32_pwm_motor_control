
#include <p32xxxx.h>
#include <plib.h>
#include "delays.h"
#include "sysclock.h"

void Delayms( unsigned t){
//#ifdef ENABLE_TIMER1
    T1CON = 0x8000;     // enable TMR1, Tpb, 1:1
    while (t--)
    {  // t x 1ms loop
        TMR1 = 0;
        while (TMR1 < FPB/4000);//TMR1<40000//40000*6us=        
    }
//#endif
} // Delayms