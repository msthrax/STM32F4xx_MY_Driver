#include "stm32f4xx_my_uart.h"

void MY_UART_Puts(USART_TypeDef * USARTx, uint8_t * str) {
  size_t sz = strlen((char *)str);
  while(sz > 0) {
    sz--;
    while(!(LL_USART_IsActiveFlag_TXE(USARTx)));
    LL_USART_TransmitData8(USARTx, (*str++ & (uint8_t)0xFFU));
  }
}
void MY_UART_TransmitBuffer(USART_TypeDef * USARTx, uint8_t * pData, size_t length) {
  while(length > 0) {
  length--;
  while(!(LL_USART_IsActiveFlag_TXE(USARTx)));
  LL_USART_TransmitData8(USARTx, (*pData++ & (uint8_t)0xFFU));
  }
}
void MY_UART_TransmitByte(USART_TypeDef * USARTx, uint8_t oneByte) {
  while(!(LL_USART_IsActiveFlag_TXE(USARTx)));
  LL_USART_TransmitData8(USARTx, (oneByte & (uint8_t)0xFFU));
}
//bool My_UART_ReceiveBuffer(USART_TypeDef * USARTx, uint8_t * pData, size_t length, volatile size_t timeout_sys_tick) {
//  uint32_t startSysTick = SysTick->VAL;
//  uint32_t tickPerMiliSec = SystemCoreClock;
//  size_t count = length;
//	while(count > 0) {
//		count--;		
//		while((USARTx->ISR & 0x20) != 0x20 && timeout > 0){ HAL_Delay(1); timeout--;}
//		if(timeout < 1) return false;		
//		*pData++ = LL_USART_ReceiveData8(USARTx);			
//	}
//	return true;
//}
