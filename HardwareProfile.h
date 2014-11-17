/* 
 * File:   HardwareProfile.h
 * Author: leonardoamaya
 *
 * Created on 16 de noviembre de 2014, 17:57
 */

#ifndef HARDWAREPROFILE_H
#define	HARDWAREPROFILE_H

#define __PIC32MX360__
//#define _PIC32MX795_



#define INPUT 1
#define OUTPUT 0

#ifdef	__cplusplus
extern "C" {
#endif

    #if defined (__PIC32MX__)//(__PIC32MX360__|_PIC32MX795_)
           //
            #include <stdlib.h>
            #include <string.h>
            #include <stdio.h>
            //#include<peripheral/timer.h>
            //#include<peripheral/int.h>
            #include "ConfigPorts.h"
            #include "lcd.h"
            #include "leds.h"
            //   #include"interrups.h"

        //#define ENABLE_TIMER0
        #define ENABLE_TIMER1
        //#define ENABLE_TIMER2
        //#define ENABLE_RTCC
        //#define ENABLE_UART0
        //#define ENABLE_UART1
        //#define ENABLE_UART2
    #else
        //"ERROR AL COMPILAR"
    #endif








    #ifdef ENABLE_TIMER1
        #define INTERRUP_TIMER1
    #endif

    #ifdef ENABLE_TIMER2
    #define INTERRUP_TIMER2
    #endif

    #ifdef ENABLE_RTCC
    #define INTERRUP_RTCC
    #endif

    #ifdef ENABLE_UART0
    #define INTERRUP_UART0
    #endif

    #ifdef ENABLE_UART1
    #define INTERRUP_UART1
    #endif

    #ifdef ENABLE_UART2
    #define INTERRUP_UART2
    #endif




#ifdef	__cplusplus
}
#endif

#endif	/* HARDWAREPROFILE_H */

