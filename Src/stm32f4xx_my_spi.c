#include "stm32f4xx_my_spi.h"

void MY_SPI_TransmitByte(SPI_TypeDef* SPIx, uint8_t spiData) {
  if((SPIx->CR1 & SPI_CR1_SPE) != SPI_CR1_SPE) { /* Enable SPI peripheral */ LL_SPI_Enable(SPIx); }
  LL_SPI_TransmitData8(SPIx, spiData);
  while (!LL_SPI_IsActiveFlag_TXE(SPIx));
  while (LL_SPI_IsActiveFlag_BSY(SPIx));
  LL_SPI_ClearFlag_OVR(SPIx);
}
void MY_SPI_Transmit(SPI_TypeDef* SPIx, uint8_t* spiData, uint16_t length) {
  if((SPIx->CR1 & SPI_CR1_SPE) != SPI_CR1_SPE) { /* Enable SPI peripheral */ LL_SPI_Enable(SPIx); }
  for(uint16_t _for_i_LL_SPI_Send = 0; _for_i_LL_SPI_Send < length; _for_i_LL_SPI_Send++) {
    LL_SPI_TransmitData8(SPIx, spiData[_for_i_LL_SPI_Send]);
    while (!LL_SPI_IsActiveFlag_TXE(SPIx));
  }
  while (LL_SPI_IsActiveFlag_BSY(SPIx));
  LL_SPI_ClearFlag_OVR(SPIx);
}
uint8_t MY_SPI_ReceiveByte(SPI_TypeDef* SPIx) {
  if((SPIx->CR1 & SPI_CR1_SPE) != SPI_CR1_SPE) { /* Enable SPI peripheral */ LL_SPI_Enable(SPIx); }
  LL_SPI_TransmitData8(SPIx, 0/*DUMMY*/);
  while (!LL_SPI_IsActiveFlag_TXE(SPIx));
  while (!LL_SPI_IsActiveFlag_RXNE(SPIx));
  uint8_t receiveSpiData = LL_SPI_ReceiveData8(SPIx);
  while (LL_SPI_IsActiveFlag_BSY(SPIx));
  LL_SPI_ClearFlag_OVR(SPIx);
  return receiveSpiData;
}
void MY_SPI_Receive(SPI_TypeDef* SPIx, uint8_t* spiData, uint16_t length) {
  if((SPIx->CR1 & SPI_CR1_SPE) != SPI_CR1_SPE) { /* Enable SPI peripheral */ LL_SPI_Enable(SPIx); }
  for(uint16_t _for_i_LL_SPI_Send = 0; _for_i_LL_SPI_Send < length; _for_i_LL_SPI_Send++) {
    LL_SPI_TransmitData8(SPIx, 0 /*DUMMY*/);
    while (!LL_SPI_IsActiveFlag_TXE(SPIx));
    while (!LL_SPI_IsActiveFlag_RXNE(SPIx));
    spiData[_for_i_LL_SPI_Send] = LL_SPI_ReceiveData8(SPIx);
  }
  while (LL_SPI_IsActiveFlag_BSY(SPIx));
  LL_SPI_ClearFlag_OVR(SPIx);
}
uint8_t MY_SPI_TransmitReceiveByte(SPI_TypeDef* SPIx, uint8_t txData) {
  if((SPIx->CR1 & SPI_CR1_SPE) != SPI_CR1_SPE) { /* Enable SPI peripheral */ LL_SPI_Enable(SPIx); }
  LL_SPI_TransmitData8(SPIx, txData);
  while (!LL_SPI_IsActiveFlag_TXE(SPIx));
  while (!LL_SPI_IsActiveFlag_RXNE(SPIx));
  uint8_t receiveSpiData = LL_SPI_ReceiveData8(SPIx);
  while (LL_SPI_IsActiveFlag_BSY(SPIx));
  LL_SPI_ClearFlag_OVR(SPIx);
  return receiveSpiData;
}
void MY_SPI_TransmitReceive(SPI_TypeDef* SPIx, uint8_t* txData, uint8_t* rxData, uint16_t length) {
  if((SPIx->CR1 & SPI_CR1_SPE) != SPI_CR1_SPE) { /* Enable SPI peripheral */ LL_SPI_Enable(SPIx); }
  for(uint16_t _for_i_LL_SPI_Send = 0; _for_i_LL_SPI_Send < length; _for_i_LL_SPI_Send++) {
    LL_SPI_TransmitData8(SPIx, txData[_for_i_LL_SPI_Send]);
    while (!LL_SPI_IsActiveFlag_TXE(SPIx));
    while (!LL_SPI_IsActiveFlag_RXNE(SPIx));
    rxData[_for_i_LL_SPI_Send] = LL_SPI_ReceiveData8(SPIx);
  }
  while (LL_SPI_IsActiveFlag_BSY(SPIx));
  LL_SPI_ClearFlag_OVR(SPIx);
}
