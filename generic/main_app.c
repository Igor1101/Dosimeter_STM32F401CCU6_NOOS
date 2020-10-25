#include "stm32f4xx_hal.h"
#include "usart.h"
#include "gpio.h"
#include "iwdg.h"
#include "generic/serial.h"
extern void SystemClock_Config(void);

int main(void)
{
	/* Reset peripherals,
	 * init flash and system tick timer peripherals */
	HAL_Init();
	// system clock configuration
	SystemClock_Config();
	// configure and init gpio
	MX_GPIO_Init();
	// usarts
	MX_USART1_UART_Init();
	MX_USART2_UART_Init();
	while (1) {
		// reset watchdog
		__HAL_IWDG_RELOAD_COUNTER(&hiwdg);
		// goto sleep
		HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI);
	}
}
// interrupt handlers
void SysTick_Handler(void)
{
	pr_debugln("systick handler");
}
