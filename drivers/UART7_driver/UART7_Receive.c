#include "UART.h"
	
//3.Function to check that there is available data inside Received FIFO 
bool Data_Available_To_Be_Received(void)
{
  if ( UART7_FR_R & UART_FR_RXFE )
		 return FALSE;

	else 
		return TRUE;
}


//4.Function to receive data from RX bit
uint8 UART7_Receive(void)
{
     while (! Data_Available_To_Be_Received () );
	   return  (uint8) (UART7_DR_R & Received_Data_Mask);
}
