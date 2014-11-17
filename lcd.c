
/*
**
** lcd.c
**
*/
#include <p32xxxx.h>
#include <plib.h>
#include "lcd.h"


#define PMDATA  PMDIN

#ifdef  LCD_TMR1

#define LCDDATA 1
    #define LCDCMD  0

    void initLCD( void)
    {
        // PMP initialization changed considerably!!!
        PMCON = 0x8303;    // Enable the PMP, demuxed, RD/WR and E  
        PMMODE = 0x3FF;    // 8-bit, Master Mode 1, max wait states
         PMAEN = 0x0001;    // only PMA0 enabled

        // init TMR1
        T1CON = 0x8030;    // Fpb/2, prescaled 1:256, 6us/tick

        // wait for >30ms
        TMR1 = 0; while( TMR1<6000);// 6000 x 6us = 36ms   

        //initiate the HD44780 display 8-bit init sequence
        PMADDR = LCDCMD;            // command register
        PMDATA = 0x38;              // 8-bit int, 2 lines, 5x7
        TMR1 = 0; while( TMR1<8);   // 8 x 6us = 48us   

        PMDATA = 0x0c;              // disp.ON, no cursor, no blink
        TMR1 = 0; while( TMR1<8);   // 8 x 6us = 48us   

        PMDATA = 1;                 // clear display
        TMR1 = 0; while( TMR1<300); // 300 x 6us = 1.8ms   

        PMDATA = 6;                 // increment cursor, no shift
        TMR1 = 0; while( TMR1<300); // 300 x 6us = 1.8ms   
    } // initLCD


    char readLCD( int addr)
    {
        int dummy;
        while( PMMODEbits.BUSY);    // wait for PMP to be available
        PMADDR = addr;              // select the command address
        dummy = PMDATA;             // init read cycle, dummy read
        while( PMMODEbits.BUSY);    // wait for PMP to be available
        return( PMDATA);            // read the status register

    } // readLCD

    void writeLCD( int addr, char c)    
    {
        while( busyLCD());
        while( PMMODEbits.BUSY);    // wait for PMP to be available
        PMADDR = addr;
        PMDATA = c;
    } // writeLCD

    #define putLCD( d)  writeLCD( LCDDATA, (d))
    #define cmdLCD( c)  writeLCD( LCDCMD, (c))

    void putsLCD( char *s)
    {
        while( *s) putLCD( *s++);
    } //putsLCD



#else
    #include "timers.h"

    void initLCD( void)
    {
        // PMP initialization
        mPMPOpen( PMP_ON | PMP_READ_WRITE_EN | 3,
                  PMP_DATA_BUS_8 | PMP_MODE_MASTER1 |
                  PMP_WAIT_BEG_4 | PMP_WAIT_MID_15 |
                  PMP_WAIT_END_4,
                  0x0001,           // only PMA0 enabled
                  PMP_INT_OFF);     // no interrupts used

        // wait for >30ms
        Delayms( 30);

        //initiate the HD44780 display 8-bit init sequence
        PMPSetAddress( LCDCMD);     // select command register
        PMPMasterWrite( 0x38);      // 8-bit int, 2 lines, 5x7
        Delayms( 1);                // > 48 us

        PMPMasterWrite( 0x0c);      // ON, no cursor, no blink
        Delayms( 1);                // > 48 us

        PMPMasterWrite( 0x01);      // clear display
        Delayms( 2);                // > 1.6ms

        PMPMasterWrite( 0x06);      // increment cursor, no shift
        Delayms( 2);                // > 1.6ms
    } // initLCD


    char readLCD( int addr)
    {
        PMPSetAddress( addr);       // select register
        mPMPMasterReadByte();       // initiate read sequence
        return mPMPMasterReadByte();// read actual data
    } // readLCD



    void writeLCD( int addr, char c)
    {
        while( busyLCD());
        PMPSetAddress( addr);       // select register
        PMPMasterWrite( c);         // initiate write sequence
    } // writeLCD


    void putsLCD( char *s)
    {
        char c;

        while( *s)
        {
            switch (*s)
            {
            case '\n':          // point to second line
                setLCDC( 0x40);
                break;
            case '\r':          // home, point to first line
                setLCDC( 0);
                break;
            case '\t':          // advance next tab (8) positions
                c = addrLCD();
                while( c & 7)
                {
                    putLCD( ' ');
                    c++;
                }
                if ( c > 15)   // if necessary move to second line
                    setLCDC( 0x40);
                break;
            default:            // print character
                putLCD( *s);
                break;
            } //switch
            s++;
        } //while
    } //putsLCD

#endif



