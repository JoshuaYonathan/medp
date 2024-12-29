#pragma once

/* ISR prototypes */
void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVCall_Handler(void);
void Debug_Monitor_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);
void WWDG_Handler(void);
void PVD_Handler(void);
void TAMP_STAMP_Handler(void);
void RTC_WKUP_Handler(void);
void FLASH_Handler(void);
void RCC_Handler(void);
void EXTI0_Handler(void);      
void EXTI1_Handler(void);
void EXTI2_Handler(void);
void EXTI3_Handler(void);
void EXTI4_Handler(void);
void DMA1_Stream0_Handler(void);
void DMA1_Stream1_Handler(void);
void DMA1_Stream2_Handler(void);
void DMA1_Stream3_Handler(void);
void DMA1_Stream4_Handler(void);
void DMA1_Stream5_Handler(void);
void DMA1_Stream6_Handler(void);
void ADC_Handler(void);
void CAN1_TX_Handler(void);
void CAN1_RX0_Handler(void);
void CAN1_RX1_Handler(void);
void CAN1_SCE_Handler(void);
void EXTI9_5_Handler(void);
void TIM1_BRK_TIM9_Handler(void);
void TIM1_UP_TIM10_Handler(void);
void TIM1_TRG_COM_TIM11_Handler(void);
void TIM1_CC_Handler(void);
void TIM2_Handler(void);
void TIM3_Handler(void);
void TIM4_Handler(void);
void I2C1_EV_Handler(void);
void I2C1_ER_Handler(void);
void I2C2_EV_Handler(void);
void I2C2_ER_Handler(void);
void SPI1_Handler(void);
void SPI2_Handler(void);
void UASRT1_Handler(void);
void UASRT2_Handler(void);
void UASRT3_Handler(void);     
void EXTI15_10_Handler(void);
void RTC_Alarm_Handler(void);
void OTG_FS_WKUP_Handler(void);
void TIM8_BRK_TIM12_Handler(void);
void TIM8_UP_TIM13_Handler(void);
void TIM8_TRG_COM_TIM14_Handler(void);
void TIM8_CC_Handler(void);
void DMA1_Stream7_Handler(void);
void FMC_Handler(void);
void SDMMC1_Handler(void);
void TIM5_Handler(void);
void SPI3_Handler(void);
void UART4_Handler(void);
void UART5_Handler(void);
void TIM6_DAC_Handler(void);
void TIM7_Handler(void);
void DMA2_Stream0_Handler(void);
void DMA2_Stream1_Handler(void);
void DMA2_Stream2_Handler(void);
void DMA2_Stream3_Handler(void);
void DMA2_Stream4_Handler(void);
void ETH_Handler(void);
void ETH_WKUP_Handler(void);
void CAN2_TX_Handler(void); 
void CAN2_RX0_Handler(void);
void CAN2_RX1_Handler(void);
void CAN2_SCE_Handler(void);
void OTG_FS_Handler(void);
void DMA2_Stream5_Handler(void);
void DMA2_Stream6_Handler(void);
void DMA2_Stream7_Handler(void);
void USART6_Handler(void);
void I2C3_EV_Handler(void);
void I2C3_ER_Handler(void);
void OTG_HS_EP1_OUT_Handler(void);
void OTG_HS_EP1_IN_Handler(void);
void OTG_HS_WKUP_Handler(void);
void OTG_HS_Handler(void);
void DCMI_Handler(void);
void CRYP_Handler(void);
void HASH_RNG_Handler(void);
void FPU_Handler(void);
void UART7_Handler(void);
void UART8_Handler(void);
void SPI4_Handler(void);
void SPI5_Handler(void);
void SPI6_Handler(void);
void SAI1_Handler(void);
void LCD_TFT_Handler(void);
void LCD_TFT_ERR_Handler(void);
void DMA2D_Handler(void);
void SAI2_Handler(void);
void QuadSPI_Handler(void);
void LP_Timer1_Handler(void);
void HDMI_CEC_Handler(void);
void I2C4_EV_Handler(void);
void I2C4_ER_Handler(void);     
void SPDIFRX_Handler(void);
void DSIHOST_Handler(void);
void DFSDM1_FLT0_Handler(void);
void DFSDM1_FLT1_Handler(void);
void DFSDM1_FLT2_Handler(void);
void DFSDM1_FLT3_Handler(void);
void SDMMC2_Handler(void);
void CAN3_TX_Handler(void);
void CAN3_RX0_Handler(void);
void CAN3_RX1_Handler(void);
void CAN3_SCE_Handler(void);     
void JPEG_Handler(void);
void MDIOS_Handler(void);
