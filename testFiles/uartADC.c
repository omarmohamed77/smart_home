#include "UART7.h"
#include "mcal.h"
#include "port.h"
#include "timer.h"

int main(void){
    Systick_init();
    UART7_init();
    ADC0_Init();
    Port_Init(5);
    uint8 temp;
    Port_SetPinDirection(5, 0x06, PORT_PIN_OUT);
    GPIO_PORTF_DATA_BITS_R[0x06] = (0x02);
    SysTick_Wait10ms(200);
    for(;;){
        temp = get_temperature();
        UART7_Send(temp);
        if(UART7_Receive() == temp){
            GPIO_PORTF_DATA_BITS_R[0x06] ^= (0x06);
        }
        SysTick_Wait10ms(100);
    }
}
