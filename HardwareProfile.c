#include "HardwareProfile.h"
#include <plib.h>
#include <p32xxxx.h>


void init_config_hardware(void){
    TRISA=0b00000000;
    TRISB=0b00000000;
    TRISC=0b00000000;
    TRISD=0b00000000;
    TRISE=0b00000000;
    TRISF=0b00000000;
    TRISG=0b00000000;

    LATA = 0;
    LATB = 0;
    LATC = 0;
    LATD = 0;
    LATE= 0;
    LATF = 0;
    LATG = 0;
}