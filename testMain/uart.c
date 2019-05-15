#include "UART7.h"
#include "mcal.h"
#include "port.h"
#include "timer.h"

int main(void){
    Systick_init();
    UART7_init();
    Port_Init(5);
    Port_SetPinDirection(5, 0x06, PORT_PIN_OUT);
    GPIO_PORTF_DATA_BITS_R[0x06] = (0x02);
    SysTick_Wait10ms(200);
    for(;;){
        UART7_Send('a');
        if(UART7_Receive() == 'a'){
            GPIO_PORTF_DATA_BITS_R[0x06] ^= (0x06);
        }
        SysTick_Wait10ms(100);
    }
}
