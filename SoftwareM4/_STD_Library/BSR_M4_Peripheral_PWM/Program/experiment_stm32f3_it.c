/*====================================================================================================*/
/*====================================================================================================*/
#include "stm32f3_system.h"
#include "experiment_stm32f3.h"
/*====================================================================================================*/
/*====================================================================================================*/
volatile uint32_t IC1Value  = 0;
volatile uint32_t IC2Value  = 0;
volatile uint32_t DutyCycle = 0;
volatile uint32_t Frequency = 0;
/*====================================================================================================*/
/*====================================================================================================*/
void TIM2_IRQHandler(void)
{
//  if(TIM_GetITStatus(TIM4, TIM_IT_CC2) != RESET) {
    TIM_ClearITPendingBit(TIM2, TIM_IT_CC2);
    IC2Value = TIM_GetCapture2(TIM2);

    if(IC2Value != 0) {
      IC1Value = TIM_GetCapture1(TIM2);
      DutyCycle = (IC1Value * 100) / IC2Value;
      Frequency = SystemCoreClock / IC2Value;
    }
    else {
      DutyCycle = 0;
      Frequency = 0;
    }
//  }
}
/*====================================================================================================*/
/*====================================================================================================*/
void NMI_Handler( void ) { while(1); }
void HardFault_Handler( void ) { while(1); }
void MemManage_Handler( void ) { while(1); }
void BusFault_Handler( void ) { while(1); }
void UsageFault_Handler( void ) { while(1); }
void SVC_Handler( void ) { while(1); }
void DebugMon_Handler( void ) { while(1); }
void PendSV_Handler( void ) { while(1); }
/*====================================================================================================*/
/*====================================================================================================*/
//void SysTick_Handler( void )
//void WWDG_IRQHandler( void )
//void PVD_IRQHandler( void )
//void TAMP_STAMP_IRQHandler( void )
//void RTC_WKUP_IRQHandler( void )
//void FLASH_IRQHandler( void )
//void RCC_IRQHandler( void )
//void EXTI0_IRQHandler( void )
//void EXTI1_IRQHandler( void )
//void EXTI2_TSC_IRQHandler( void )
//void EXTI3_IRQHandler( void )
//void EXTI4_IRQHandler( void )
//void DMA1_Channel1_IRQHandler( void )
//void DMA1_Channel2_IRQHandler( void )
//void DMA1_Channel3_IRQHandler( void )
//void DMA1_Channel4_IRQHandler( void )
//void DMA1_Channel5_IRQHandler( void )
//void DMA1_Channel6_IRQHandler( void )
//void DMA1_Channel7_IRQHandler( void )
//void ADC1_2_IRQHandler( void )
//void USB_HP_CAN_TX_IRQHandler( void )
//void USB_LP_CAN_RX0_IRQHandler( void )
//void CAN_RX1_IRQHandler( void )
//void CAN_SCE_IRQHandler( void )
//void EXTI9_5_IRQHandler( void )
//void TIM1_BRK_TIM15_IRQHandler( void )
//void TIM1_UP_TIM16_IRQHandler( void )
//void TIM1_TRG_COM_TIM17_IRQHandler( void )
//void TIM1_CC_IRQHandler( void )
//void TIM2_IRQHandler( void )
//void TIM3_IRQHandler( void )
//void TIM4_IRQHandler( void )
//void I2C1_EV_IRQHandler( void )
//void I2C1_ER_IRQHandler( void )
//void I2C2_EV_IRQHandler( void )
//void I2C2_ER_IRQHandler( void )
//void SPI1_IRQHandler( void )
//void SPI2_IRQHandler( void )
//void USART1_IRQHandler( void )
//void USART2_IRQHandler( void )
//void USART3_IRQHandler( void )
//void EXTI15_10_IRQHandler( void )
//void RTC_Alarm_IRQHandler( void )
//void USBWakeUp_IRQHandler( void )
//void TIM8_BRK_IRQHandler( void )
//void TIM8_UP_IRQHandler( void )
//void TIM8_TRG_COM_IRQHandler( void )
//void TIM8_CC_IRQHandler( void )
//void ADC3_IRQHandler( void )
//void SPI3_IRQHandler( void )
//void UART4_IRQHandler( void )
//void UART5_IRQHandler( void )
//void TIM6_DAC_IRQHandler( void )
//void TIM7_IRQHandler( void )
//void DMA2_Channel1_IRQHandler( void )
//void DMA2_Channel2_IRQHandler( void )
//void DMA2_Channel3_IRQHandler( void )
//void DMA2_Channel4_IRQHandler( void )
//void DMA2_Channel5_IRQHandler( void )
//void ADC4_IRQHandler( void )
//void COMP1_2_3_IRQHandler( void )
//void COMP4_5_6_IRQHandler( void )
//void COMP7_IRQHandler( void )
//void USB_HP_IRQHandler( void )
//void USB_LP_IRQHandler( void )
//void USBWakeUp_RMP_IRQHandler( void )
//void FPU_IRQHandler( void )
/*====================================================================================================*/
/*====================================================================================================*/
