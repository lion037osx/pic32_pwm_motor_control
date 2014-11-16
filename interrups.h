/* 
 * File:   interrups.h
 * Author: leonardoamaya
 *
 * Created on 16 de noviembre de 2014, 18:16
 */
#include"types.h"
#include <plib.h>

#ifndef INTERRUPS_H
#define	INTERRUPS_H
extern static uint32_t counter_interrup;
#ifdef	__cplusplus
extern "C" {
#endif

void init_interrup1(void);
void init_interrup2(void);
void init_config_RTCC(void);
void init_interrup_RTCC(void);


#pragma interrupt InterruptHandler ipl1 vector 0
static void  InterruptHandler( void)
{
    counter_interrup++;
    mT2ClearIntFlag();
} // Interrupt Handler

// 1. Timer1 interrupt service routine
void __ISR_SINGLE__ RTCCInterrupt( void)
{
    // 1.1  your code here, will be executed only once a year
    // or once every 365 x 24 x 60 x 60 x 16,000,000 MCU cycles
    // that is once every 504,576,000,000,000 MCU cycles
    
    // 1.2 clear the interrupt flag
    mRTCCClearIntFlag();
} //RTCCInterrupt

#ifdef	__cplusplus
}
#endif

#endif	/* INTERRUPS_H */

