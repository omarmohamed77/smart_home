#include "UART.h"


//2.Function to send data
void UART1_Send(uint8 data)
{
	  while (UART1_FR_R & (UART_FR_TXFF) ) ;
	  UART1_DR_R = (data) ;
}