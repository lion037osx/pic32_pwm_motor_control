/* 
 * File:   adc.h
 * Author: leonardoamaya
 *
 * Created on 16 de noviembre de 2014, 20:07
 */

#ifndef ADC_H
#define	ADC_H

#ifdef	__cplusplus
extern "C" {
#endif


void initADC( int amask) ;
int readADC( int ch);

#ifdef	__cplusplus
}
#endif

#endif	/* ADC_H */

