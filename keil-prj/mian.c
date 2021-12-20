#include <DS_CM3.h>
#include "main.h"

//最大2^32ms = 4294967s = 71582min = 1193h = 49.7day
volatile uint32_t systicks;
uint32_t led;
uint8_t recv_byte;
void SysTick_Handler(){
	systicks ++ ;
}
void delay_ms(uint32_t ms){
	uint32_t now = systicks;
	while(systicks - now < ms);
}
void UART0Handler(){
	//先判断是接收中断还是发送中断
	if(UART_Rx_FIFO_Valid_Data == 1){//Rx FIFO有数据,接收中断
		PA = 0x0f;
	}
	else if(UART_Tx_FIFO_Empty == 1){//Tx FIFO空,发送中断
		PA = 0xf0;
	}
	else{
		PA = 0x01;
	}
	
}


int main(void){
	NVIC_EnableIRQ(SysTick_IRQn);
	NVIC_EnableIRQ(UART0_IRQn);
	SysTick_Config( SystemCoreClock / 500 );//1ms中断一次
	//必须最后开中断,否则RST标志位无法清零,会一直复位
	*(uint32_t *)(UART0_BASE_ADDR + UART_CTRL) = UART_Rx_FIFO_RST;//清空接收FIFO
	*(uint32_t *)(UART0_BASE_ADDR + UART_CTRL) = UART_Tx_FIFO_RST;//清空发送FIFO
	*(uint32_t *)(UART0_BASE_ADDR + UART_CTRL) = UART_INT_EN;//使能串口中断
	PA = 0xaa;
	while(1){
		if(UART_Rx_FIFO_Valid_Data == 1){//Rx FIFO有数据
			recv_byte = (*(uint32_t *)(UART0_BASE_ADDR + UART_Rx_FIFO)) & 0x000000ff;//接收FIFO的低八位赋给recv_byte
			if(UART_Tx_FIFO_Full == 0){//Tx FIFO没满
				if(UART_Frame_Error == 1){//刚读到的一个byte有帧错误
					continue;
				}
				else{
					//delay_ms(100);
					*(uint32_t *)(UART0_BASE_ADDR + UART_Tx_FIFO) = recv_byte;
				}
			}
			else{
				continue;
			}
		}
		else{
			continue;
		}
		
		
//		*(uint32_t *)(GPIOA_BASE_ADDR + GPIO_DATA) = 0x01;
//		delay_ms(500);
//		*(uint32_t *)(GPIOA_BASE_ADDR + GPIO_DATA) = 0x00;
//		delay_ms(500);
		
	}

}