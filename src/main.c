#include "stm32f1xx_hal.h"
#include "init_gpio.h"

//#define LED_GPIO_PORT                          GPIOA

#define LED_BUILD_IN GPIO_PIN_5

#define PA4_LED_1 GPIO_PIN_4
#define PA6_LED_2 GPIO_PIN_6
#define PA7_LED_3 GPIO_PIN_7
#define PA8_LED_4 GPIO_PIN_8

#define PB0_BIT_0 GPIO_PIN_0
#define PB0_BIT_1 GPIO_PIN_1

#define LED_GPIO_CLK_ENABLE()                  __HAL_RCC_GPIOA_CLK_ENABLE()
 
int main(void)
{
  HAL_Init();
  
  LED_GPIO_CLK_ENABLE();
  
  GPIO_InitTypeDef GPIO_InitStruct;
  
  GPIO_InitStruct.Pin = LED_BUILD_IN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct); 

  while (1)
  {
    // HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_PIN);
    HAL_Delay(1000);
    //HAL_GPIO_WritePin(LED_GPIO_PORT, LED_PIN, 0);
    //HAL_Delay(1000);
  }
}

void SysTick_Handler(void)
{
  HAL_IncTick();
}

void NMI_Handler(void)
{
}

void HardFault_Handler(void)
{
  while (1) {}
}


void MemManage_Handler(void)
{
  while (1) {}
}

void BusFault_Handler(void)
{
  while (1) {}
}

void UsageFault_Handler(void)
{
  while (1) {}
}

void SVC_Handler(void)
{
}


void DebugMon_Handler(void)
{
}

void PendSV_Handler(void)
{
}


