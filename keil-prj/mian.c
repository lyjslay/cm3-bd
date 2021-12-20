#include <DS_CM3.h>
#include "main.h"

//���2^32ms = 4294967s = 71582min = 1193h = 49.7day
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
	//���ж��ǽ����жϻ��Ƿ����ж�
	if(UART_Rx_FIFO_Valid_Data == 1){//Rx FIFO������,�����ж�
		PA = 0x0f;
	}
	else if(UART_Tx_FIFO_Empty == 1){//Tx FIFO��,�����ж�
		PA = 0xf0;
	}
	else{
		PA = 0x01;
	}
	
}


int main(void){
	NVIC_EnableIRQ(SysTick_IRQn);
	NVIC_EnableIRQ(UART0_IRQn);
	SysTick_Config( SystemCoreClock / 500 );//1ms�ж�һ��
	//��������ж�,����RST��־λ�޷�����,��һֱ��λ
	*(uint32_t *)(UART0_BASE_ADDR + UART_CTRL) = UART_Rx_FIFO_RST;//��ս���FIFO
	*(uint32_t *)(UART0_BASE_ADDR + UART_CTRL) = UART_Tx_FIFO_RST;//��շ���FIFO
	*(uint32_t *)(UART0_BASE_ADDR + UART_CTRL) = UART_INT_EN;//ʹ�ܴ����ж�
	PA = 0xaa;
	while(1){
		if(UART_Rx_FIFO_Valid_Data == 1){//Rx FIFO������
			recv_byte = (*(uint32_t *)(UART0_BASE_ADDR + UART_Rx_FIFO)) & 0x000000ff;//����FIFO�ĵͰ�λ����recv_byte
			if(UART_Tx_FIFO_Full == 0){//Tx FIFOû��
				if(UART_Frame_Error == 1){//�ն�����һ��byte��֡����
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