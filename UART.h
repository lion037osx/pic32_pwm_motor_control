/* 
 * File:   uart.h
 * Author: leonardoamaya
 *
 * Created on 17 de noviembre de 2014, 1:56
 */

#ifndef UART_H
#define	UART_H

#ifdef	__cplusplus
extern "C" {
#endif


// I/O definitions for the Explorer16
#define CTS     _RF12               // Cleart To Send, input
#define RTS     _RF13               // Request To Send, output
#define TRTS    TRISFbits.TRISF13   // tris control for RTS pin

#define BAUDRATE115200 115200
#define BAUDRATE9600 9600
#define BAUDRATE19200 19200

#define  BAUDRATE BAUDRATE19200

// timing and baud rate calculations
#define BRATE    (FPB/4/BAUDRATE)-1   // 115200 baud
#define U_ENABLE 0x8008	            // enable UART (BREGH=1)
#define U_TX     0x0400	            // enable transmission


void init_config_uart0(void);
void init_config_uart1(void);
void init_config_uart2(void);

char getU2( void);
int putU2( int c);
int puts_Uart2( const char *s);
char *getsnUart2( char *s, int len);




#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

