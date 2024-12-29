#include <string.h>
#include <stdint.h>
#include "stm32f7xx.h"

/* Linker symbols */
extern char __rodata_load__;
extern char __rodata_start__;
extern char __rodata_end__;
extern char __data_load__;
extern char __data_start__;
extern char __data_end__;
extern char __bss_start__;
extern char __bss_end__;
extern char __fastcode_load__;
extern char __fastcode_start__;
extern char __fastcode_end__;
extern char __stack_end__;

int main(void);
void __libc_init_array(void);   /* C runtime array of constructors */
void __libc_fini_array(void);   /* C runtime array of destructors */

/* ISR prototypes. Can be implemented by user */
void Reset_Handler(void);
void NMI_Handler(void)                  __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void)            __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void)            __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void)           __attribute__((weak, alias("Default_Handler")));
void SVCall_Handler(void)               __attribute__((weak, alias("Default_Handler")));
void Debug_Monitor_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void)               __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void WWDG_Handler(void)                 __attribute__((weak, alias("Default_Handler")));
void PVD_Handler(void)                  __attribute__((weak, alias("Default_Handler")));
void TAMP_STAMP_Handler(void)           __attribute__((weak, alias("Default_Handler")));
void RTC_WKUP_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void FLASH_Handler(void)                __attribute__((weak, alias("Default_Handler")));
void RCC_Handler(void)                  __attribute__((weak, alias("Default_Handler")));
void EXTI0_Handler(void)                __attribute__((weak, alias("Default_Handler")));
void EXTI1_Handler(void)                __attribute__((weak, alias("Default_Handler")));
void EXTI2_Handler(void)                __attribute__((weak, alias("Default_Handler")));
void EXTI3_Handler(void)                __attribute__((weak, alias("Default_Handler")));
void EXTI4_Handler(void)                __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream0_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream1_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream2_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream3_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream4_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream5_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream6_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void ADC_Handler(void)                  __attribute__((weak, alias("Default_Handler")));
void CAN1_TX_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void CAN1_RX0_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void CAN1_RX1_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void CAN1_SCE_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void EXTI9_5_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void TIM1_BRK_TIM9_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void TIM1_UP_TIM10_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void TIM1_TRG_COM_TIM11_Handler(void)   __attribute__((weak, alias("Default_Handler")));
void TIM1_CC_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void TIM2_Handler(void)                 __attribute__((weak, alias("Default_Handler")));
void TIM3_Handler(void)                 __attribute__((weak, alias("Default_Handler")));
void TIM4_Handler(void)                 __attribute__((weak, alias("Default_Handler")));
void I2C1_EV_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void I2C1_ER_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void I2C2_EV_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void I2C2_ER_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void SPI1_Handler(void)                 __attribute__((weak, alias("Default_Handler")));
void SPI2_Handler(void)                 __attribute__((weak, alias("Default_Handler")));
void UASRT1_Handler(void)               __attribute__((weak, alias("Default_Handler")));
void UASRT2_Handler(void)               __attribute__((weak, alias("Default_Handler")));
void UASRT3_Handler(void)               __attribute__((weak, alias("Default_Handler")));
void EXTI15_10_Handler(void)            __attribute__((weak, alias("Default_Handler")));
void RTC_Alarm_Handler(void)            __attribute__((weak, alias("Default_Handler")));
void OTG_FS_WKUP_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void TIM8_BRK_TIM12_Handler(void)       __attribute__((weak, alias("Default_Handler")));
void TIM8_UP_TIM13_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void TIM8_TRG_COM_TIM14_Handler(void)   __attribute__((weak, alias("Default_Handler")));
void TIM8_CC_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream7_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void FMC_Handler(void)                  __attribute__((weak, alias("Default_Handler")));
void SDMMC1_Handler(void)               __attribute__((weak, alias("Default_Handler")));
void TIM5_Handler(void)                 __attribute__((weak, alias("Default_Handler")));
void SPI3_Handler(void)                 __attribute__((weak, alias("Default_Handler")));
void UART4_Handler(void)                __attribute__((weak, alias("Default_Handler")));
void UART5_Handler(void)                __attribute__((weak, alias("Default_Handler")));
void TIM6_DAC_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void TIM7_Handler(void)                 __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream0_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream1_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream2_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream3_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream4_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void ETH_Handler(void)                  __attribute__((weak, alias("Default_Handler")));
void ETH_WKUP_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void CAN2_TX_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void CAN2_RX0_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void CAN2_RX1_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void CAN2_SCE_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void OTG_FS_Handler(void)               __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream5_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream6_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream7_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void USART6_Handler(void)               __attribute__((weak, alias("Default_Handler")));
void I2C3_EV_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void I2C3_ER_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void OTG_HS_EP1_OUT_Handler(void)       __attribute__((weak, alias("Default_Handler")));
void OTG_HS_EP1_IN_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void OTG_HS_WKUP_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void OTG_HS_Handler(void)               __attribute__((weak, alias("Default_Handler")));
void DCMI_Handler(void)                 __attribute__((weak, alias("Default_Handler")));
void CRYP_Handler(void)                 __attribute__((weak, alias("Default_Handler")));
void HASH_RNG_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void FPU_Handler(void)                  __attribute__((weak, alias("Default_Handler")));
void UART7_Handler(void)                __attribute__((weak, alias("Default_Handler")));
void UART8_Handler(void)                __attribute__((weak, alias("Default_Handler")));
void SPI4_Handler(void)                 __attribute__((weak, alias("Default_Handler")));
void SPI5_Handler(void)                 __attribute__((weak, alias("Default_Handler")));
void SPI6_Handler(void)                 __attribute__((weak, alias("Default_Handler")));
void SAI1_Handler(void)                 __attribute__((weak, alias("Default_Handler")));
void LCD_TFT_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void LCD_TFT_ERR_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void DMA2D_Handler(void)                __attribute__((weak, alias("Default_Handler")));
void SAI2_Handler(void)                 __attribute__((weak, alias("Default_Handler")));
void QuadSPI_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void LP_Timer1_Handler(void)            __attribute__((weak, alias("Default_Handler")));
void HDMI_CEC_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void I2C4_EV_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void I2C4_ER_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void SPDIFRX_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void DSIHOST_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void DFSDM1_FLT0_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void DFSDM1_FLT1_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void DFSDM1_FLT2_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void DFSDM1_FLT3_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void SDMMC2_Handler(void)               __attribute__((weak, alias("Default_Handler")));
void CAN3_TX_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void CAN3_RX0_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void CAN3_RX1_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void CAN3_SCE_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void JPEG_Handler(void)                 __attribute__((weak, alias("Default_Handler")));
void MDIOS_Handler(void)                __attribute__((weak, alias("Default_Handler")));

/* Vector table to be stored at program entry point */
/* Vector table must be aligned on a 512-byte boundary */
const uintptr_t vectors[] __attribute__((used, section(".vectors"))) =
{
    (uintptr_t)&__stack_end__,
    (uintptr_t)&Reset_Handler,
    (uintptr_t)&NMI_Handler,
    (uintptr_t)&HardFault_Handler,
    (uintptr_t)&MemManage_Handler,
    (uintptr_t)&BusFault_Handler,
    (uintptr_t)&UsageFault_Handler,
    (uintptr_t)0,
    (uintptr_t)0,
    (uintptr_t)0,
    (uintptr_t)0,
    (uintptr_t)&SVCall_Handler,
    (uintptr_t)&Debug_Monitor_Handler,
    (uintptr_t)0,
    (uintptr_t)&PendSV_Handler,
    (uintptr_t)&SysTick_Handler,
    (uintptr_t)&WWDG_Handler,
    (uintptr_t)&PVD_Handler,
    (uintptr_t)&TAMP_STAMP_Handler,
    (uintptr_t)&RTC_WKUP_Handler,
    (uintptr_t)&FLASH_Handler,
    (uintptr_t)&RCC_Handler,
    (uintptr_t)&EXTI0_Handler,
    (uintptr_t)&EXTI1_Handler,
    (uintptr_t)&EXTI2_Handler,
    (uintptr_t)&EXTI3_Handler,
    (uintptr_t)&EXTI4_Handler,
    (uintptr_t)&DMA1_Stream0_Handler,
    (uintptr_t)&DMA1_Stream1_Handler,
    (uintptr_t)&DMA1_Stream2_Handler,
    (uintptr_t)&DMA1_Stream3_Handler,
    (uintptr_t)&DMA1_Stream4_Handler,
    (uintptr_t)&DMA1_Stream5_Handler,
    (uintptr_t)&DMA1_Stream6_Handler,
    (uintptr_t)&ADC_Handler,
    (uintptr_t)&CAN1_TX_Handler,
    (uintptr_t)&CAN1_RX0_Handler,
    (uintptr_t)&CAN1_RX1_Handler,
    (uintptr_t)&CAN1_SCE_Handler,
    (uintptr_t)&EXTI9_5_Handler,
    (uintptr_t)&TIM1_BRK_TIM9_Handler,
    (uintptr_t)&TIM1_UP_TIM10_Handler,
    (uintptr_t)&TIM1_TRG_COM_TIM11_Handler,
    (uintptr_t)&TIM1_CC_Handler,
    (uintptr_t)&TIM2_Handler,
    (uintptr_t)&TIM3_Handler,
    (uintptr_t)&TIM4_Handler,
    (uintptr_t)&I2C1_EV_Handler,
    (uintptr_t)&I2C1_ER_Handler,
    (uintptr_t)&I2C2_EV_Handler,
    (uintptr_t)&I2C2_ER_Handler,
    (uintptr_t)&SPI1_Handler,
    (uintptr_t)&SPI2_Handler,
    (uintptr_t)&UASRT1_Handler,
    (uintptr_t)&UASRT2_Handler,
    (uintptr_t)&UASRT3_Handler,
    (uintptr_t)&EXTI15_10_Handler,
    (uintptr_t)&RTC_Alarm_Handler,
    (uintptr_t)&OTG_FS_WKUP_Handler,
    (uintptr_t)&TIM8_BRK_TIM12_Handler,
    (uintptr_t)&TIM8_UP_TIM13_Handler,
    (uintptr_t)&TIM8_TRG_COM_TIM14_Handler,
    (uintptr_t)&TIM8_CC_Handler,
    (uintptr_t)&DMA1_Stream7_Handler,
    (uintptr_t)&FMC_Handler,
    (uintptr_t)&SDMMC1_Handler,
    (uintptr_t)&TIM5_Handler,
    (uintptr_t)&SPI3_Handler,
    (uintptr_t)&UART4_Handler,
    (uintptr_t)&UART5_Handler,
    (uintptr_t)&TIM6_DAC_Handler,
    (uintptr_t)&TIM7_Handler,
    (uintptr_t)&DMA2_Stream0_Handler,
    (uintptr_t)&DMA2_Stream1_Handler,
    (uintptr_t)&DMA2_Stream2_Handler,
    (uintptr_t)&DMA2_Stream3_Handler,
    (uintptr_t)&DMA2_Stream4_Handler,
    (uintptr_t)&ETH_Handler,
    (uintptr_t)&ETH_WKUP_Handler,
    (uintptr_t)&CAN2_TX_Handler,
    (uintptr_t)&CAN2_RX0_Handler,
    (uintptr_t)&CAN2_RX1_Handler,
    (uintptr_t)&CAN2_SCE_Handler,
    (uintptr_t)&OTG_FS_Handler,
    (uintptr_t)&DMA2_Stream5_Handler,
    (uintptr_t)&DMA2_Stream6_Handler,
    (uintptr_t)&DMA2_Stream7_Handler,
    (uintptr_t)&USART6_Handler,
    (uintptr_t)&I2C3_EV_Handler,
    (uintptr_t)&I2C3_ER_Handler,
    (uintptr_t)&OTG_HS_EP1_OUT_Handler,
    (uintptr_t)&OTG_HS_EP1_IN_Handler,
    (uintptr_t)&OTG_HS_WKUP_Handler,
    (uintptr_t)&OTG_HS_Handler,
    (uintptr_t)&DCMI_Handler,
    (uintptr_t)&CRYP_Handler,
    (uintptr_t)&HASH_RNG_Handler,
    (uintptr_t)&FPU_Handler,
    (uintptr_t)&UART7_Handler,
    (uintptr_t)&UART8_Handler,
    (uintptr_t)&SPI4_Handler,
    (uintptr_t)&SPI5_Handler,
    (uintptr_t)&SPI6_Handler,
    (uintptr_t)&SAI1_Handler,
    (uintptr_t)&LCD_TFT_Handler,
    (uintptr_t)&LCD_TFT_ERR_Handler,
    (uintptr_t)&DMA2D_Handler,
    (uintptr_t)&SAI2_Handler,
    (uintptr_t)&QuadSPI_Handler,
    (uintptr_t)&LP_Timer1_Handler,
    (uintptr_t)&HDMI_CEC_Handler,
    (uintptr_t)&I2C4_EV_Handler,
    (uintptr_t)&I2C4_ER_Handler,
    (uintptr_t)&SPDIFRX_Handler,
    (uintptr_t)&DSIHOST_Handler,
    (uintptr_t)&DFSDM1_FLT0_Handler,
    (uintptr_t)&DFSDM1_FLT1_Handler,
    (uintptr_t)&DFSDM1_FLT2_Handler,
    (uintptr_t)&DFSDM1_FLT3_Handler,
    (uintptr_t)&SDMMC2_Handler,
    (uintptr_t)&CAN3_TX_Handler,
    (uintptr_t)&CAN3_RX0_Handler,
    (uintptr_t)&CAN3_RX1_Handler,
    (uintptr_t)&CAN3_SCE_Handler,
    (uintptr_t)&JPEG_Handler,
    (uintptr_t)&MDIOS_Handler
};

void Reset_Handler(void)
{
    size_t size;

    size = (uintptr_t)&__rodata_end__ - (uintptr_t)&__rodata_start__;

    memcpy(&__rodata_start__, &__rodata_load__, size);

    size = (uintptr_t)&__data_end__ - (uintptr_t)&__data_start__;

    memcpy(&__data_start__, &__data_load__, size);

    size = (uintptr_t)&__bss_end__ - (uintptr_t)&__bss_start__;

    memset(&__bss_start__, 0, size);

    size = (uintptr_t)&__fastcode_end__ - (uintptr_t)&__fastcode_start__;

    memcpy(&__fastcode_start__, &__fastcode_load__, size);

    SCB->VTOR = (uint32_t)&vectors;

    __libc_init_array();

    main();

    __libc_fini_array();

    while(1);
}

void Default_Handler(void)
{
    while(1);
}
