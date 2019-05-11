#include "UART.h"

//1.Function to Initiazlize the UART1 Module
void UART1_init(void)
{
	//1.Enable PORTB Clock:
	SYSCTL_RCGCGPIO_R |=  SYSCTL_PRGPIO_R1;
	while( (SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R1) == 0);

	//2.Enable PB0 and PB1 as TX and RX For UART1 in digital mode:
	GPIO_PORTB_AFSEL_R|= (0x03);
	GPIO_PORTB_DEN_R  |= (0x03);
	GPIO_PORTB_PCTL_R  = (GPIO_PORTA_PCTL_R & 0xFFFFFF00) | ( GPIO_PCTL_PB1_U1TX | GPIO_PCTL_PB0_U1RX);
	
	//3.Enable UART1 Clock
	SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R1;
        while( (SYSCTL_PRUART_R & SYSCTL_PRUART_R1) == 0);

	//4.Disable UART0 Firstly:
	UART1_CTL_R &= ~(UART_CTL_UARTEN);

        //5.Baud Rate Configuration:
	UART1_IBRD_R = 104;
	UART1_FBRD_R = 5;

	//6.UART0 Enable FIFOS and data farme length equal to one word:
	UART1_LCRH_R = (UART_LCRH_FEN | UART_LCRH_WLEN_8 )   ;
	
	//7.UART0 Enable, UART0 Transmit Enable and UART0 Receive Enable:
	UART1_CTL_R |= (UART_CTL_UARTEN | UART_CTL_TXE | UART_CTL_RXE);

}