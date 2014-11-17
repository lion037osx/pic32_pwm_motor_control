#include "ButtonsConfig.h"
#include<p32xxxx.h>
#include <plib.h>
//#include "HardwareProfile.h"

void config_buttons_HWEX16(void){
   // TRISA=0b10000000;
    //TRISD=0b0010000011000000;
    TRISAbits.TRISA7=1;
    TRISDbits.TRISD6=1;
    TRISDbits.TRISD7=1;
    TRISDbits.TRISD13=1;
}
