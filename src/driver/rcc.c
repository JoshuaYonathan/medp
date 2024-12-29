#include <stdint.h>
#include "stm32f7xx.h"
#include "rcc.h"

void rcc_hse_enable(void)
{
    /* Enable high-speed external crystal oscillator */
    SET_BIT(RCC->CR, RCC_CR_HSEON);

    return;
}

void rcc_hse_wait(void)
{
    /* Wait until HSE is ready */
    while(READ_BIT(RCC->CR, RCC_CR_HSERDY_Msk) != RCC_CR_HSERDY);

    return;
}

void rcc_pll_config(void)
{
    /* Configure PLL to 216MHz */
    const uint32_t PLLM   = RCC_PLLCFGR_PLLM_4 | RCC_PLLCFGR_PLLM_3 | RCC_PLLCFGR_PLLM_0;
    const uint32_t PLLN   = RCC_PLLCFGR_PLLN_8 | RCC_PLLCFGR_PLLN_7 | RCC_PLLCFGR_PLLN_5 | RCC_PLLCFGR_PLLN_4;
    const uint32_t PLLP   = 0;
    const uint32_t PLLQ   = RCC_PLLCFGR_PLLQ_3 | RCC_PLLCFGR_PLLQ_0;
    const uint32_t PLLR   = RCC_PLLCFGR_PLLR_1;
    const uint32_t PLLSRC = RCC_PLLCFGR_PLLSRC_HSE;
    
    MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLM_Msk, PLLM);
    MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLN_Msk, PLLN);
    MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLP_Msk, PLLP);
    MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLQ_Msk, PLLQ);
    MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLR_Msk, PLLR);
    MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC_Msk, PLLSRC);

    return;
}

void rcc_pll_enable(void)
{
    /* Enable PLL */
    MODIFY_REG(RCC->CR, RCC_CR_PLLON_Msk, RCC_CR_PLLON);

    return;
}

void rcc_pll_wait(void)
{
    /* Wait until PLL is ready */
    while(READ_BIT(RCC->CR, RCC_CR_PLLRDY_Msk) != RCC_CR_PLLRDY);

    return;
}

void rcc_sys_config(void)
{
    /* Configure system clock */
    const uint32_t PPRE2  = RCC_CFGR_PPRE2_2 | RCC_CFGR_PPRE2_0;
    const uint32_t PPRE1  = RCC_CFGR_PPRE1_2 | RCC_CFGR_PPRE1_1;
    const uint32_t HPRE   = 0;

    MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE2_Msk, PPRE2);
    MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE1_Msk, PPRE1);
    MODIFY_REG(RCC->CFGR, RCC_CFGR_HPRE_Msk, HPRE);

    return;
}

void rcc_sys_enable(void)
{
    /* Switch system clock source to PLL */
    MODIFY_REG(RCC->CFGR, RCC_CFGR_SW_Msk, RCC_CFGR_SW_PLL);

    return;
}

void rcc_sys_wait(void)
{
    /* Wait until system clock switch status is ready */
    while(READ_BIT(RCC->CFGR, RCC_CFGR_SWS_Msk) != RCC_CFGR_SWS_PLL);

    return;
}

void rcc_pwr_enable(void)
{
    /* Enable power peripheral */
    MODIFY_REG(RCC->APB1ENR, RCC_APB1ENR_PWREN_Msk, RCC_APB1ENR_PWREN);

    return;
}

void rcc_gpio_enable(void)
{
    /* Enable GPIO peripheral clocks */
    MODIFY_REG(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN_Msk, RCC_AHB1ENR_GPIOAEN);
    MODIFY_REG(RCC->AHB1ENR, RCC_AHB1ENR_GPIOBEN_Msk, RCC_AHB1ENR_GPIOBEN);
    MODIFY_REG(RCC->AHB1ENR, RCC_AHB1ENR_GPIOCEN_Msk, RCC_AHB1ENR_GPIOCEN);
    MODIFY_REG(RCC->AHB1ENR, RCC_AHB1ENR_GPIOFEN_Msk, RCC_AHB1ENR_GPIOFEN);
    MODIFY_REG(RCC->AHB1ENR, RCC_AHB1ENR_GPIOJEN_Msk, RCC_AHB1ENR_GPIOJEN);

    return;
}

void rcc_usart_enable(void)
{
    /* Enable USART6 peripheral */
    

    return;
}
