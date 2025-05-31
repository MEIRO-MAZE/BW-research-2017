/*==============================================================================================
								  PROJECT YUME 3.17 Ver.1.0
								  YUME DYNAMIXEL AX-12A
==============================================================================================*/

#include "bw_dynamixel_ax_12a.h"

void Dynamixel_USART6_Init(uint32_t DYNAMIXEL_BAUDRATE)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART6,ENABLE);

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;  // Pins 6 (TX) and 7 (RX) are used
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF; 			// the pins are configured as alternate function so the USART peripheral has access to them
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		// this defines the IO speed and has nothing to do with the baudrate!
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			// this defines the output type as push pull mode (as opposed to open drain)
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			// this activates the pullup resistors on the IO pins
	GPIO_Init(GPIOC, &GPIO_InitStructure);					// now all the values are passed to the GPIO_Init() function which sets the GPIO registers

	GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_USART6);
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_USART6);

	USART_InitStructure.USART_BaudRate = DYNAMIXEL_BAUDRATE;	// the baudrate is set to the value we passed into this init function
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;// we want the data frame size to be 8 bits (standard)
	USART_InitStructure.USART_StopBits = USART_StopBits_1;		// we want 1 stop bit (standard)
	USART_InitStructure.USART_Parity = USART_Parity_No;		// we don't want a parity bit (standard)
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // we don't want flow control (standard)
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx; // we want to enable the transmitter and the receiver
	USART_Init(USART6, &USART_InitStructure);					// again all the properties are passed to the USART_Init function which takes care of all the bit setting

	USART_ITConfig(USART6, USART_IT_RXNE, ENABLE); // enable the USART1 receive interrupt

	NVIC_InitStructure.NVIC_IRQChannel = USART6_IRQn;		 // we want to configure the USART3 interrupts
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;// this sets the priority group of the USART3 interrupts
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;		 // this sets the subpriority inside the group
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			 // the USART3 interrupts are globally enabled
	NVIC_Init(&NVIC_InitStructure);							 // the properties are passed to the NVIC_Init function which takes care of the low level stuff

	// finally this enables the complete USART6 peripheral
	USART_Cmd(USART6, ENABLE);
}

// Send USART
void Dynamx_Send(USART_TypeDef* USARTx, int DATA)
{
  USART_ClearFlag(USARTx,USART_FLAG_TXE);

  while(USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET); // Wait empty
  USART_SendData(USARTx, DATA); // Send char
}

void Dynamixel_Pin_Config(void)
{
	RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_GPIOA, ENABLE);
	GPIO_InitStructure.GPIO_Pin 	= GPIO_Pin_0 ;
	GPIO_InitStructure.GPIO_Mode 	= GPIO_Mode_OUT;       	// Pin ini memiliki Mode Ouput
	GPIO_InitStructure.GPIO_Speed 	= GPIO_Speed_50MHz; 	// kecepatan clock(2, 25, 50 or 100 MHz)
	GPIO_InitStructure.GPIO_PuPd 	= GPIO_PuPd_NOPULL; 	// pin tidak diberikan pull up
	GPIO_Init(GPIOA, &GPIO_InitStructure); 	// inisialisasi periperal GPIO sesuai parameter typdef diatas
}
//*******************************Dynamixel*************************************//
int Dynamixel_moveSpeed(unsigned char ID, int Position, int Speed)
{
    char Position_H,Position_L,Speed_H,Speed_L;
    Position_H = Position >> 8;
    Position_L = Position;                // 16 bits - 2 x 8 bits variables
    Speed_H = Speed >> 8;
    Speed_L = Speed;                      // 16 bits - 2 x 8 bits variables
    Checksum = (~(ID + AX_GOAL_SP_LENGTH + AX_WRITE_DATA + AX_GOAL_POSITION_L + Position_L + Position_H + Speed_L + Speed_H))&0xFF;

    GPIO_SetBits(GPIOA, GPIO_Pin_0);

    Dynamx_Send(USART6,AX_HEADER); // Send Instructions over Serial
    Dynamx_Send(USART6,AX_HEADER);
    Dynamx_Send(USART6,ID);
    Dynamx_Send(USART6,AX_GOAL_SP_LENGTH);
    Dynamx_Send(USART6,AX_WRITE_DATA);
    Dynamx_Send(USART6,AX_GOAL_POSITION_L);
    Dynamx_Send(USART6,Position_L);
    Dynamx_Send(USART6,Position_H);
    Dynamx_Send(USART6,Speed_L);
    Dynamx_Send(USART6,Speed_H);
    Dynamx_Send(USART6,Checksum);

    delay_ms(TX_DELAY_TIME);

    GPIO_ResetBits(GPIOA, GPIO_Pin_0);

    return -1 ;
}

int Dyna_Actuate(unsigned char Dyna_ID, unsigned int Angle, unsigned int Speed)
{
	int Position;
    char Position_H,Position_L,Speed_H,Speed_L;

    //Convert Angle to position value
    Position= Angle*1024;
    Position= Position/300;
    if(Position!=0) {Position-=1;}

//    Position = Angle;

    //Break 16 Bit value to two variables of 8 bit each
    Position_H = Position >> 8;
    Position_L = Position;

    //Break 16 Bit value to two variables of 8 bit each
    Speed_H = Speed >> 8;
    Speed_L = Speed;

    Checksum = (~(Dyna_ID + AX_GOAL_SP_LENGTH + AX_WRITE_DATA + AX_GOAL_POSITION_L + Position_L + Position_H + Speed_L + Speed_H))&0xFF;

    GPIO_SetBits(GPIOA, GPIO_Pin_0);

    Dynamx_Send(USART6,AX_HEADER); // Send Instructions over Serial
    Dynamx_Send(USART6,AX_HEADER);
    Dynamx_Send(USART6,Dyna_ID);
    Dynamx_Send(USART6,AX_GOAL_SP_LENGTH);
    Dynamx_Send(USART6,AX_WRITE_DATA);
    Dynamx_Send(USART6,AX_GOAL_POSITION_L);
    Dynamx_Send(USART6,Position_L);
    Dynamx_Send(USART6,Position_H);
    Dynamx_Send(USART6,Speed_L);
    Dynamx_Send(USART6,Speed_H);
    Dynamx_Send(USART6,Checksum);

    delay_ms(TX_DELAY_TIME);

    GPIO_ResetBits(GPIOA, GPIO_Pin_0);

    return -1 ;
}

/*
 * Comparison between 3DOF leg vs 2DOF leg
 */
void Dynamx_Demo(void)
{

		//DEPAN ANGKAT
		Dyna_Actuate(FRONT_RIGHT_COXA,175,500);
		Dyna_Actuate(FRONT_RIGHT_FEMUR,200,500);
		Dyna_Actuate(FRONT_RIGHT_TIBIA,190,500);
	
		Dyna_Actuate(FRONT_LEFT_COXA,175,500);
		Dyna_Actuate(FRONT_LEFT_FEMUR,120,500);
	
		//DEPAN MENAPAK
		Dyna_Actuate(FRONT_RIGHT_COXA,175,500);
		Dyna_Actuate(FRONT_RIGHT_FEMUR,175,500);
		Dyna_Actuate(FRONT_RIGHT_TIBIA,175,500);
	
		Dyna_Actuate(FRONT_LEFT_COXA,175,500);
		Dyna_Actuate(FRONT_LEFT_FEMUR,140,500);
	
		//BELAKANG MENAPAK
		Dyna_Actuate(FRONT_RIGHT_COXA,125,500);
		Dyna_Actuate(FRONT_RIGHT_FEMUR,175,500);
		Dyna_Actuate(FRONT_RIGHT_TIBIA,175,500);
	
		Dyna_Actuate(FRONT_LEFT_COXA,125,500);
		Dyna_Actuate(FRONT_LEFT_FEMUR,140,500);
	
		//DEPAN ANGKAT
		Dyna_Actuate(FRONT_RIGHT_COXA,125,500);
		Dyna_Actuate(FRONT_RIGHT_FEMUR,200,500);
		Dyna_Actuate(FRONT_RIGHT_TIBIA,190,500);
	
	
	//DEFAULT
	//		Dyna_Actuate(FRONT_LEFT_COXA,125,500);
	//		Dyna_Actuate(FRONT_LEFT_FEMUR,120,500);
}
