///   5/5/2019   ///
///    Martina   ///

#include "UART0_Send.h"

void UART0_Send(uint8 data)
{
    while((UART0_FR_R & 0x20)!=0)
    {};
		UART0_DR_R = data ;
}
