#include "UART7.h"


//2.Function to send data
void UART7_Send(uint8 data)
{
	  while (UART7_FR_R & (UART_FR_TXFF) ) ;
	  UART7_DR_R = (data) ;
}