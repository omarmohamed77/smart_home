#include "lcd.h"
void LCD_init(uint)
{
		LCD_command(CLEAR);
    LCD_command(DISPLAY_ON_CURSOR_OFF);
    LCD_command(FUNCTION_SET_8BIT_2LINE);
    LCD_command(ENTRY_MODE_LEFT_TO_RIGHT);
}
void LCD_command(char command)
{
	GPIO_PORTA_DATA_R = 0; //command mode(RS = 0), wirte mode (RW = 0), ENABLE = 0
	GPIO_PORTB_DATA_R = command;
	//Latch
	GPIO_PORTA_DATA_R |= ENABLIE_BIT; // set Enable bit
	delay(2);
	GPIO_PORTA_DATA_R &= (~(ENABLIE_BIT)); // clear Enable bit
	delay(2);
}
void LCD_data(char data)
{
	GPIO_PORTA_DATA_R = RS_BIT; //data mode(RS = 0), wirte mode (RW = 0), ENABLE = 0
	GPIO_PORTB_DATA_R = data;
	//Latch
	GPIO_PORTA_DATA_R |= ENABLIE_BIT; // set Enable bit
	delay(2);
	GPIO_PORTA_DATA_R &= (~(ENABLIE_BIT)); // clear Enable bit
	delay(2);
}
