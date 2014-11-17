/* 
 * File:   spi.h
 * Author: leonardoamaya
 *
 * Created on 16 de noviembre de 2014, 20:53
 */

#ifndef SPI_H
#define	SPI_H

#ifdef	__cplusplus
extern "C" {
#endif

#define SPI0_ENABLE
//#define SPI1_ENABLE
//#define SPI2_ENABLE
//#define SPI3_ENABLE

void init_spi(void);

#ifdef	__cplusplus
}
#endif

#endif	/* SPI_H */

