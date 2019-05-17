#include "timer.h"
void Systick_init(void)
{
NVIC_ST_CTRL_R = 0;
NVIC_ST_RELOAD_R = 0x00FFFFFF;
NVIC_ST_CURRENT_R = 0 ;
NVIC_ST_CTRL_R = 0x00000005;
}
