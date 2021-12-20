
//GPIO
//GPIOA基地址
#define GPIOA_BASE_ADDR 0x40000000
//数据寄存器的便宜地址
#define GPIO_DATA 0x0000 
//三态控制寄存器便宜地址
#define GPIO_TRI 0x0004 
#define PA (*(uint32_t *)(GPIOA_BASE_ADDR + GPIO_DATA))




//串口
//串口0基地址
#define UART0_BASE_ADDR 0x40600000
#define UART0_BAUD_RATE 9600
//UART寄存器的偏移地址
#define UART_Rx_FIFO 0x00 //8bit * (5 ~ 8)depth
#define UART_Tx_FIFO 0x04
#define UART_STAT 0x08 //UART Lite status register
#define UART_CTRL 0x0c //UART Lite control register
//UART_CTRL寄存器指令,只写
#define UART_INT_EN 0x10 //串口终端的使能
#define UART_INT_DIS 0x00
#define UART_Rx_FIFO_RST 0x02 //串口接收和发送FIFO的清空
#define UART_Tx_FIFO_RST 0x01
//UART_STAT每一位的标志,只读
#define UART_Rx_FIFO_Valid_Data (((*(uint32_t *)(UART0_BASE_ADDR + UART_STAT))&0x00000001))
#define UART_Rx_FIFO_Full       (((*(uint32_t *)(UART0_BASE_ADDR + UART_STAT))&0x00000002) >> 1)
#define UART_Tx_FIFO_Empty      (((*(uint32_t *)(UART0_BASE_ADDR + UART_STAT))&0x00000004) >> 2)
#define UART_Tx_FIFO_Full       (((*(uint32_t *)(UART0_BASE_ADDR + UART_STAT))&0x00000008) >> 3)
#define UART_Intr_Enabled       (((*(uint32_t *)(UART0_BASE_ADDR + UART_STAT))&0x00000010) >> 4)
#define UART_Overrun_Error      (((*(uint32_t *)(UART0_BASE_ADDR + UART_STAT))&0x00000020) >> 5)
#define UART_Frame_Error        (((*(uint32_t *)(UART0_BASE_ADDR + UART_STAT))&0x00000040) >> 6)
#define UART_Parity_Error       (((*(uint32_t *)(UART0_BASE_ADDR + UART_STAT))&0x00000080) >> 7)
/*
31-8 保留
7 Parity Error 奇偶校验错误标志
		Indicates that a parity error has occurred after the last time the
		status register was read. If the UART is configured without any
		parity handling, this bit is always 0.
		The received character is written into the receive FIFO.
		This bit is cleared when the status register is read.
		0 = No parity error has occurred
		1 = Parity error has occurred
6 Frame Error 上次读取的值有帧错误(即停止位的地方变成了0,说明错位了)
		Indicates that a frame error has occurred after the last time the
		status register was read. Frame error is defined as detection of
		a stop bit with the value 0. The receive character is ignored and
		not written to the receive FIFO.
		This bit is cleared when the status register is read.
		0 = No frame error has occurred
		1 = Frame error has occurred
5 Overrun Error 上次读取后FIFO发生了溢出错误(接收到新字节但FIFO已满,新字节不会被写入)
		Indicates that a overrun error has occurred after the last time
		the status register was read. Overrun is when a new character
		has been received but the receive FIFO is full. The received
		character is ignored and not written into the receive FIFO. This
		bit is cleared when the status register is read.
		0 = No overrun error has occurred
		1 = Overrun error has occurred
4 Intr Enabled 中断被使能为1
		Indicates that interrupts is enabled.
		0 = Interrupt is disabled
		1 = Interrupt is enabled
3 Tx FIFO Full 发送FIFO满为1
		Indicates if the transmit FIFO is full.
		0 = Transmit FIFO is not full
		1 = Transmit FIFO is full
2 Tx FIFO Empty 发送FIFO空为1
		Indicates if the transmit FIFO is empty.
		0 = Transmit FIFO is not empty
		1 = Transmit FIFO is empty
1 Rx FIFO Full 接收FIFO满为1
		Indicates if the receive FIFO is full.
		0 = Receive FIFO is not full
		1 = Receive FIFO is full
0 Rx FIFO Valid Data 接收FIFO空为0,有数据为1
		Indicates if the receive FIFO has data.
		0 = Receive FIFO is empty
		1 = Receive FIFO has data
*/