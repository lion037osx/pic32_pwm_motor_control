
#include <p32xxxx.h>
#include <plib.h>
//#include <peripheral/int.h>
#include "isr.h"

void init_interrup_Timer2(void){
    #ifdef INTERRRUP_TIMER2
    // init interrupts
    mT2SetIntPriority( 1);
    //mT2ClearIntFlag();
    INTEnableSystemSingleVectoredInt();
    mT2IntEnable( 1);
    #endif
}


void init_interrup_Timer1(void){
    #ifdef INTERRRUP_TIMER1
        // init interrupts,
        mT1SetIntPriority( 1);
        mT1ClearIntFlag();
        INTEnableSystemSingleVectoredInt();
        mT1IntEnable( 1);
    #endif
}

void init_interrup_RTCC(void){
    #ifdef INTERRRUP_RTCC
      // init interrupts,
    mRTCCSetIntPriority( 1);
    mRTCCClearIntFlag();
    INTEnableSystemSingleVectoredInt();
    mRTCCIntEnable( 1);
#endif
}


void init_config_RTCC(void){
#ifdef ENABLE_RTCC
    RtccInit();
#endif
}