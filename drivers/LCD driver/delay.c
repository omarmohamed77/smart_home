#include "delay.h"

void delay(uint32 milliseconds)
{
    uint32 cycles = 2000 * milliseconds;
	uint32 i ;
    for (i = 0; i < cycles; i++);
}
