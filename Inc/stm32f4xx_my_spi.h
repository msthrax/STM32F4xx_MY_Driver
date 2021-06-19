#ifndef __STM32F4xx_MY_SPI_H
#define __STM32F4xx_MY_SPI_H

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "stm32f4xx.h"
#include "stm32f4xx_ll_spi.h"

void MY_SPI_TransmitByte(SPI_TypeDef* SPIx, uint8_t spiData);
void MY_SPI_Transmit(SPI_TypeDef* SPIx, uint8_t* spiData, uint16_t length);
uint8_t MY_SPI_ReceiveByte(SPI_TypeDef* SPIx);
void MY_SPI_Receive(SPI_TypeDef* SPIx, uint8_t* spiData, uint16_t length);
uint8_t MY_SPI_TransmitReceiveByte(SPI_TypeDef* SPIx, uint8_t txData);
void MY_SPI_TransmitReceive(SPI_TypeDef* SPIx, uint8_t* txData, uint8_t* rxData, uint16_t length);

#endif /* __STM32F4xx_MY_SPI_H */
