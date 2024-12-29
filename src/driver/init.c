#include "stm32f7xx.h"
#include "init.h"
#include "fpu.h"
#include "rcc.h"
#include "pwr.h"
#include "flash.h"
#include "vectors.h"

void init_clocks(void)
{
    rcc_hse_enable();
    rcc_hse_wait();

    rcc_pll_config();
    rcc_pll_enable();
    rcc_pll_wait();

    rcc_pwr_enable();

    pwr_od_enable();
    pwr_od_wait();
    pwr_odsw_enable();
    pwr_odsw_wait();

    flash_ac_config();
    flash_ac_wait();

    rcc_sys_config();
    rcc_sys_enable();
    rcc_sys_wait();

    return;
}

void init_peripherals(void)
{
    rcc_gpio_enable();
    fpu_enable();

    return;
}

void init_device(void)
{
    init_clocks();
    init_peripherals();

    return;
}
