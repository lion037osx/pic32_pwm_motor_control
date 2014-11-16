#include <plib.h>

void init_interrup2(void){
    // init interrupts
    mT2SetIntPriority( 1);
    INTEnableSystemSingleVectoredInt();
    mT2IntEnable( 1);
}


void init_interrup1(void){
    // init interrupts,
    mT1SetIntPriority( 1);
    mT1ClearIntFlag();
    INTEnableSystemSingleVectoredInt();
    mT1IntEnable( 1);
}

void init_interrup_RTCC(void){
      // init interrupts,
    mRTCCSetIntPriority( 1);
    mRTCCClearIntFlag();
    INTEnableSystemSingleVectoredInt();
    mRTCCIntEnable( 1);
}


void init_config_RTCC(void){
    RtccInit();  
}