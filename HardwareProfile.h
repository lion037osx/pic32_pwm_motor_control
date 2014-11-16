/* 
 * File:   HardwareProfile.h
 * Author: leonardoamaya
 *
 * Created on 16 de noviembre de 2014, 17:57
 */

#ifndef HARDWAREPROFILE_H
#define	HARDWAREPROFILE_H

#define PIC32MX360
//#define PIC32MX795

#define INPUT 1
#define OUTPUT 0

#ifdef	__cplusplus
extern "C" {
#endif
#ifdef  PIC32MX360
    #include <p32xxxx.h>
#endif

#define FCY     80000000L
#define FPB     40000000L



void init_config_hardware(void);

#ifdef	__cplusplus
}
#endif

#endif	/* HARDWAREPROFILE_H */

