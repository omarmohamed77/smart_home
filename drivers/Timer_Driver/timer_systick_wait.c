#include "timer.h"

void SysTick_Wait(uint32 delay)
{

  NVIC_ST_RELOAD_R = delay-1; // number of counts to wait
  NVIC_ST_CURRENT_R = 0; // any value written to CURRENT clears
  while((NVIC_ST_CTRL_R&0x00010000)==0){ // wait for count flag
  }
}

// 10000us equals 10ms
void SysTick_Wait10ms(uint32 delay)
{
  uint32 i;
  for(i=0; i<delay; i++)
  {
    SysTick_Wait(800000); // wait 10ms
  }
}
