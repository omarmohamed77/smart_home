#include "UART7.h"

 //1.Function to Initiazlize the UART7 Module
void UART7_init(void)
{
	//1.Enable PORTE Clock:
	SYSCTL_RCGCGPIO_R |=  SYSCTL_PRGPIO_R4;
	while( (SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R4) == 0);

 	//2.Enable PE0 and PE1 as TX and RX For UART7 in digital mode:
	GPIO_PORTE_AFSEL_R|= (0x03);
	GPIO_PORTE_DEN_R  |= (0x03);
	GPIO_PORTE_PCTL_R  = (GPIO_PORTE_PCTL_R & 0xFFFFFF00) | (GPIO_PCTL_PE1_U7TX  | GPIO_PCTL_PE0_U7RX );

 	//3.Enable UART7 Clock
	SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R7;
        while( (SYSCTL_PRUART_R & SYSCTL_PRUART_R7) == 0);

 	//4.Disable UART0 Firstly:
	UART7_CTL_R &= ~(UART_CTL_UARTEN);

         //5.Baud Rate Configuration:
	UART7_IBRD_R = 104;
	UART7_FBRD_R = 5;

 	//6.UART0 Enable FIFOS and data farme length equal to one word:
	UART7_LCRH_R = (UART_LCRH_FEN | UART_LCRH_WLEN_8 )   ;

 	//7.UART0 Enable, UART0 Transmit Enable and UART0 Receive Enable:
	UART7_CTL_R |= (UART_CTL_UARTEN | UART_CTL_TXE | UART_CTL_RXE);}
