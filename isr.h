/* 
 * File:   isr.h
 * Author: leonardoamaya
 *
 * Created on 17 de noviembre de 2014, 1:53
 */

#ifndef ISR_H
#define	ISR_H

#ifdef	__cplusplus
extern "C" {
#endif


void init_interrup_Timer1(void);
void init_interrup_Timer2(void);
void init_config_RTCC(void);
void init_interrup_RTCC(void);

/*
#ifdef INTERRUP_TIMER2
    #pragma interrupt InterruptHandler ipl1 vector 0
    void  InterruptHandler( void)
    {
        counter_interrup++;
        mT2ClearIntFlag();
    } // Interrupt Handler
#endif

#ifdef INTERRUP_RTCC
    // 1. Timer1 interrupt service routine
    void __ISR_SINGLE__ RTCCInterrupt( void)
    {
        // 1.1  your code here, will be executed only once a year
        // or once every 365 x 24 x 60 x 60 x 16,000,000 MCU cycles
        // that is once every 504,576,000,000,000 MCU cycles

        // 1.2 clear the interrupt flag
        mRTCCClearIntFlag();
    } //RTCCInterrupt
#endif

#ifdef INTERRUP_TIMER1
    void __ISR_SINGLE__ T1Interrupt( void){
        //clear the interrupt flag
        mT1ClearIntFlag();
    } //T1Interrupt
#endif
*/



#ifdef	__cplusplus
}
#endif

#endif	/* ISR_H */

