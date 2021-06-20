#ifndef __STM32F4xx_MY_GPIO_H
#define __STM32F4xx_MY_GPIO_H

#include <stdbool.h>
#include <stdint.h>

#include "stm32f4xx.h"

#define MY_GPIO_WritePin(gpioPort,gpioPin,gpioState) gpioPort->BSRR = gpioState == 0 ? (uint32_t)gpioPin << 16 : (uint32_t)gpioPin
#define MY_GPIO_SetPin(gpioPort,gpioPin) gpioPort->BSRR = (uint32_t)gpioPin
#define MY_GPIO_ResetPin(gpioPort,gpioPin) gpioPort->BSRR = (uint32_t)gpioPin << 16
#define MY_GPIO_TogglePin(gpioPort,gpioPin) gpioPort->ODR ^= gpioPin
#define MY_GPIO_ReadPin(gpioPort,gpioPin) (((gpioPort->IDR & gpioPin) != (uint32_t)GPIO_PIN_RESET) ? (/*GPIO_PIN_SET*/ true) : (/*GPIO_PIN_RESET*/ false))

#endif /* __STM32F4xx_MY_GPIO_H */
