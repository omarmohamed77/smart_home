#include "LCD.h"
#include "timer.h"

void delay(uint32 milliseconds)
{
    uint32 cycles = 2000 * milliseconds;
    uint32 i;
    for (i = 0; i < cycles; i++)
        ;
}

void LCD_init()
{
    LCD_command(DISPLAY_ON_CURSOR_OFF);
    LCD_command(FUNCTION_SET_8BIT_2LINE);
    LCD_command(ENTRY_MODE_LEFT_TO_RIGHT);
    LCD_command(CLEAR);
}
void LCD_command(char command)
{
    GPIO_PORTA_DATA_BITS_R[RS_BIT] = 0; //command mode(RS = 0), wirte mode (RW = 0), ENABLE = 0
    GPIO_PORTA_DATA_BITS_R[RW_BIT] = 0;
    GPIO_PORTA_DATA_BITS_R[ENABLIE_BIT] = 0xFF; //command mode(RS = 0), wirte mode (RW = 0), ENABLE = 0
    delay(2);
    GPIO_PORTB_DATA_BITS_R[0xFF] = command;
    delay(2);
    GPIO_PORTA_DATA_BITS_R[ENABLIE_BIT] = 0; // clear Enable bit
    delay(2);
}
void LCD_data(uint8 data)
{
    GPIO_PORTA_DATA_BITS_R[RS_BIT] = RS_BIT; //data mode(RS = 1), wirte mode (RW = 0), ENABLE = 0
    GPIO_PORTA_DATA_BITS_R[RW_BIT] = 0;
    GPIO_PORTA_DATA_BITS_R[ENABLIE_BIT] = ENABLIE_BIT; // set Enable bit
    delay(2);
    GPIO_PORTB_DATA_BITS_R[0xFF] = data;
    delay(2);
    GPIO_PORTA_DATA_BITS_R[ENABLIE_BIT] = 0; // clear Enable bit
    delay(2);
}
void LCD_print(uint16 number)
{
    LCD_command(CLEAR);
    LCD_data((uint8) (((number % 100) / 10) + 48));
    LCD_data((uint8) ((number % 10) + 48));
}
