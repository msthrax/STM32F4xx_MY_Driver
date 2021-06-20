#ifndef __STM32F4xx_MY_USART_H
#define __STM32F4xx_MY_USART_H

#include <stdint.h>
#include <string.h>

#include "stm32f4xx.h"
#include "stm32f4xx_ll_usart.h"

void MY_UART_Puts(USART_TypeDef * USARTx, uint8_t * str);
void MY_UART_TransmitBuffer(USART_TypeDef * USARTx, uint8_t * pData, size_t length);
void MY_UART_TransmitByte(USART_TypeDef * USARTx, uint8_t oneByte);

#endif /* __STM32F4xx_MY_USART_H */
