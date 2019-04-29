#include "UART.h"

//1.Function to Initiazlize the UART0 Module
void UART0_init(void)
{
	//1.Enable PORTA Clock:
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0 ;
    while( (SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R0) == 0);

	//2.Enable UART0 Clock
	SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R0;

	//3.Disable UART0 Firstly:
	UART0_CTL_R = ~(UART_CTL_UARTEN);

    //4.UART0 Enable FIFOS and data farme length equal to one word:
	UART0_LCRH_R = (UART_LCRH_FEN | UART_LCRH_WLEN_8 )   ;

    //5.Baud Rate Configuration:
	UART0_IBRD_R = 520;
	UART0_FBRD_R = 53;

	//6.UART0 Enable, UART0 Transmit Enable and UART0 Receive Enable:
	UART0_CTL_R |= (UART_CTL_UARTEN | UART_CTL_TXE | UART_CTL_RXE);

	//7.Enable PA0 and PA1 as TX and RX For UART0 in digital mode:
	GPIO_PORTA_AFSEL_R|= (0x03);
	GPIO_PORTA_DEN_R  |= (0x03);
	GPIO_PORTA_PCTL_R  = (GPIO_PORTA_PCTL_R & 0xFFFFFF00) | (GPIO_PCTL_PA0_U0RX | GPIO_PCTL_PA1_U0TX);

}


