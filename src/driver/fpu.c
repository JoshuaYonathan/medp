#include "stm32f7xx.h"
#include "fpu.h"

void fpu_enable(void)
{
    SCB->CPACR |= 0xF << 20; /* Enable coprocessor access control register */

    __DSB();
    __ISB();

    return;
}
