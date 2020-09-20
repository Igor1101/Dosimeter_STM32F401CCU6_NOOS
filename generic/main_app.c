#include "stm32f4xx_hal.h"

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
	}
}
