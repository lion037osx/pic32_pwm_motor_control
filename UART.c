/*
** UART2 RS232 asynchronous communication code
*/

#include <p32xxxx.h>
#include <plib.h>
#include "uart.h"

#define BACKSPACE 0x20

void init_config_uart0(void){
#ifdef PIC32MX360

#endif

#ifdef PIC32MX795

#endif
}

void init_config_uart1(void){
#ifdef PIC32MX360
#endif

#ifdef PIC32MX795

#endif
}

void init_config_uart2(void){
#ifdef PIC32MX360

    U2BRG 	= BRATE;
    U2MODE 	= U_ENABLE;
    U2STA 	= U_TX;
    TRTS    = 0;        // make RTS output
    RTS     = 1;        // set RTS default status

#endif

#ifdef PIC32MX795

#endif
}

int putU2( int c)
{
    while ( CTS);		        // wait for !CTS, clear to send
    while ( U2STAbits.UTXBF);   // wait while Tx buffer full
    U2TXREG = c;
    return c;
} // putU2


// wait for a new character to arrive to the UART2 serial port
char getU2( void)
{
    RTS = 0;            // assert Request To Send !RTS
    while ( !U2STAbits.URXDA);	// wait for a new character to arrive
    RTS = 1;
    return U2RXREG;		// read the character from the receive buffer
}// getU2

int puts_Uart2( const char *s)
{
	while( *s)			// loop until *s == '\0' end of string
		putU2( *s++);	// send char and point to the next one
    putU2( '\r');       // terminate with a cr / line feed
} // putsU2

char *getsnUart2( char *s, int len)
{
    char *p = s;            // copy the buffer pointer
    do{
        *s = getU2();       // wait for a new character
        putU2( *s);         // echo character

        if (( *s==BACKSPACE)&&( s>p))
        {
            putU2( ' ');     // overwrite the last character
            putU2( BACKSPACE);
            len++;
            s--;            // back the pointer
            continue;
        }
        if ( *s=='\n')      // line feed, ignore it
            continue;
        if ( *s=='\r')      // end of line, end loop
            break;
        s++;                // increment buffer pointer
        len--;
    } while ( len>1 );      // until buffer full

    *s = '\0';              // null terminate the string

    return p;               // return buffer pointer
} // getsn