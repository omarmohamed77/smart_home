///   5/5/2019   ///
///    Martina   ///

#include <UART0.h>

uint8 UART0_Recieve (void)
 {
	  uint8 x ;
    while((UART0_FR_R & 0x10)!=0)
		{};
			x  = (UART0_DR_R & 0x0ff);
			return x;
 }