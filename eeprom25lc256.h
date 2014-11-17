/* 
 * File:   eeprom25lc256.h
 * Author: leonardoamaya
 *
 * Created on 16 de noviembre de 2014, 18:42
 */

#ifndef EEPROM25LC256_H
#define	EEPROM25LC256_H

#ifdef	__cplusplus
extern "C" {
#endif

// initialize access to memory device
void initSEE(void);

// 32-bit integer read and write functions
// NOTE: address must be an even value between 0x0000 and 0x3ffc
// (see page write restrictions on the device datasheet)
int  readSEE ( int address);
void writeSEE( int address, int data);

#ifdef	__cplusplus
}
#endif

#endif	/* EEPROM25LC256_H */

