#include "stm32f7xx.h"
#include "pwr.h"

void pwr_od_enable(void)
{
    /* Enable overdrive mode */
    MODIFY_REG(PWR->CR1, PWR_CR1_ODEN_Msk, PWR_CR1_ODEN);

    return;
}

void pwr_od_wait(void)
{
    /* Wait until overdrive mode is ready */
    while(READ_BIT(PWR->CSR1, PWR_CSR1_ODRDY_Msk) != PWR_CSR1_ODRDY);

    return;
}

void pwr_odsw_enable(void)
{
    /* Configure voltage regulator for overdrive mode */
    MODIFY_REG(PWR->CR1, PWR_CR1_ODSWEN_Msk, PWR_CR1_ODSWEN);

    return;
}

void pwr_odsw_wait(void)
{
    /* Wait until overdrive mode is ready */
    while(READ_BIT(PWR->CSR1, PWR_CSR1_ODSWRDY_Msk) != PWR_CSR1_ODSWRDY);

    return;
}
