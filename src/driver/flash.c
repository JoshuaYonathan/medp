#include "stm32f7xx.h"
#include "flash.h"

void flash_ac_config(void)
{
    /* Configure flash latency */
    MODIFY_REG(FLASH->ACR, FLASH_ACR_LATENCY_Msk, FLASH_ACR_LATENCY_7WS);
    
    return;
}

void flash_ac_wait(void)
{
    /* Wait until flash latency applied */
    while(READ_BIT(FLASH->ACR, FLASH_ACR_LATENCY_Msk) != FLASH_ACR_LATENCY_7WS);

    return;
}
