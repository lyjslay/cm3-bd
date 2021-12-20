
//GPIO
//GPIOA����ַ
#define GPIOA_BASE_ADDR 0x40000000
//���ݼĴ����ı��˵�ַ
#define GPIO_DATA 0x0000 
//��̬���ƼĴ������˵�ַ
#define GPIO_TRI 0x0004 
#define PA (*(uint32_t *)(GPIOA_BASE_ADDR + GPIO_DATA))




//����
//����0����ַ
#define UART0_BASE_ADDR 0x40600000
#define UART0_BAUD_RATE 9600
//UART�Ĵ�����ƫ�Ƶ�ַ
#define UART_Rx_FIFO 0x00 //8bit * (5 ~ 8)depth
#define UART_Tx_FIFO 0x04
#define UART_STAT 0x08 //UART Lite status register
#define UART_CTRL 0x0c //UART Lite control register
//UART_CTRL�Ĵ���ָ��,ֻд
#define UART_INT_EN 0x10 //�����ն˵�ʹ��
#define UART_INT_DIS 0x00
#define UART_Rx_FIFO_RST 0x02 //���ڽ��պͷ���FIFO�����
#define UART_Tx_FIFO_RST 0x01
//UART_STATÿһλ�ı�־,ֻ��
#define UART_Rx_FIFO_Valid_Data (((*(uint32_t *)(UART0_BASE_ADDR + UART_STAT))&0x00000001))
#define UART_Rx_FIFO_Full       (((*(uint32_t *)(UART0_BASE_ADDR + UART_STAT))&0x00000002) >> 1)
#define UART_Tx_FIFO_Empty      (((*(uint32_t *)(UART0_BASE_ADDR + UART_STAT))&0x00000004) >> 2)
#define UART_Tx_FIFO_Full       (((*(uint32_t *)(UART0_BASE_ADDR + UART_STAT))&0x00000008) >> 3)
#define UART_Intr_Enabled       (((*(uint32_t *)(UART0_BASE_ADDR + UART_STAT))&0x00000010) >> 4)
#define UART_Overrun_Error      (((*(uint32_t *)(UART0_BASE_ADDR + UART_STAT))&0x00000020) >> 5)
#define UART_Frame_Error        (((*(uint32_t *)(UART0_BASE_ADDR + UART_STAT))&0x00000040) >> 6)
#define UART_Parity_Error       (((*(uint32_t *)(UART0_BASE_ADDR + UART_STAT))&0x00000080) >> 7)
/*
31-8 ����
7 Parity Error ��żУ������־
		Indicates that a parity error has occurred after the last time the
		status register was read. If the UART is configured without any
		parity handling, this bit is always 0.
		The received character is written into the receive FIFO.
		This bit is cleared when the status register is read.
		0 = No parity error has occurred
		1 = Parity error has occurred
6 Frame Error �ϴζ�ȡ��ֵ��֡����(��ֹͣλ�ĵط������0,˵����λ��)
		Indicates that a frame error has occurred after the last time the
		status register was read. Frame error is defined as detection of
		a stop bit with the value 0. The receive character is ignored and
		not written to the receive FIFO.
		This bit is cleared when the status register is read.
		0 = No frame error has occurred
		1 = Frame error has occurred
5 Overrun Error �ϴζ�ȡ��FIFO�������������(���յ����ֽڵ�FIFO����,���ֽڲ��ᱻд��)
		Indicates that a overrun error has occurred after the last time
		the status register was read. Overrun is when a new character
		has been received but the receive FIFO is full. The received
		character is ignored and not written into the receive FIFO. This
		bit is cleared when the status register is read.
		0 = No overrun error has occurred
		1 = Overrun error has occurred
4 Intr Enabled �жϱ�ʹ��Ϊ1
		Indicates that interrupts is enabled.
		0 = Interrupt is disabled
		1 = Interrupt is enabled
3 Tx FIFO Full ����FIFO��Ϊ1
		Indicates if the transmit FIFO is full.
		0 = Transmit FIFO is not full
		1 = Transmit FIFO is full
2 Tx FIFO Empty ����FIFO��Ϊ1
		Indicates if the transmit FIFO is empty.
		0 = Transmit FIFO is not empty
		1 = Transmit FIFO is empty
1 Rx FIFO Full ����FIFO��Ϊ1
		Indicates if the receive FIFO is full.
		0 = Receive FIFO is not full
		1 = Receive FIFO is full
0 Rx FIFO Valid Data ����FIFO��Ϊ0,������Ϊ1
		Indicates if the receive FIFO has data.
		0 = Receive FIFO is empty
		1 = Receive FIFO has data
*/