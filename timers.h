/* 
 * File:   timers.h
 * Author: leonardoamaya
 *
 * Created on 16 de noviembre de 2014, 18:09
 */

#ifndef TIMERS_H
#define	TIMERS_H

#ifdef	__cplusplus
extern "C" {
#endif

void init_timer1(void);
void init_timer2(void);
void Delay_ms_T1( unsigned t);


 static void __ISR_SINGLE__ T1Interrupt( void){
    //clear the interrupt flag
    mT1ClearIntFlag();
} //T1Interrupt


#ifdef	__cplusplus
}
#endif

#endif	/* TIMERS_H */

