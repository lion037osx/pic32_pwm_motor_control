#include "ButtonsConfig.h"
#include "HardwareProfile.h"

void config_buttons_HWEX16(void){
   // TRISA=0b10000000;
    //TRISD=0b0010000011000000;
    TRISAbits.TRISA7=INPUT;
    TRISDbits.TRISD6=INPUT;
    TRISDbits.TRISD7=INPUT;
    TRISDbits.TRISD13=INPUT;
}
