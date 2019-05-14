#include "LCD.h"
#include "timer.h"
void LCD_init()
{
		LCD_command(CLEAR);
    LCD_command(DISPLAY_ON_CURSOR_OFF);
    LCD_command(FUNCTION_SET_8BIT_2LINE);
    LCD_command(ENTRY_MODE_LEFT_TO_RIGHT);
}
void LCD_command(char command)
{
    GPIO_PORTA_DATA_BITS_R[0xE0] = 0; //command mode(RS = 0), wirte mode (RW = 0), ENABLE = 0
    GPIO_PORTB_DATA_BITS_R[0xFF] = command;
	//Latch
	GPIO_PORTA_DATA_BITS_R[0xE0] |= ENABLIE_BIT; // set Enable bit
	SysTick_Wait10ms(5);
	GPIO_PORTA_DATA_BITS_R[0xE0] &= (~(ENABLIE_BIT)); // clear Enable bit
    SysTick_Wait10ms(5);
}
void LCD_data(char data)
{
    GPIO_PORTA_DATA_BITS_R[0xE0] = RS_BIT; //data mode(RS = 1), wirte mode (RW = 0), ENABLE = 0
    GPIO_PORTB_DATA_BITS_R[0xFF] = data;
	//Latch
	GPIO_PORTA_DATA_BITS_R[0xE0] |= ENABLIE_BIT; // set Enable bit
    SysTick_Wait10ms(5);
    GPIO_PORTA_DATA_BITS_R[0xE0] &= (~(ENABLIE_BIT)); // clear Enable bit
    SysTick_Wait10ms(5);
}
void LCD_print(uint16 number)
{
	LCD_command(CLEAR);
	LCD_data((uint8)(((number%100) / 10) + 48));
	LCD_data((uint8)((number%10) + 48));
}
