/*========================================================================================
								   PROJECT BW 2.16 Ver.1.0
								  BW Hydro Extinguisher Library
==============================================================================================*/
#ifndef BW_EXTINGUISHER_H
#define BW_EXTINGUISHER_H

#include "main.h"
/*
 * BW BUZZER
 */
#define RCC_AHB1Periph_EXTINGUISHER RCC_AHB1Periph_GPIOB
#define EXTINGUISHER_PORT GPIOB
#define EXTINGUISHER_PIN GPIO_Pin_15
#define EXTINGUISHER_ON GPIO_ResetBits (EXTINGUISHER_PORT, EXTINGUISHER_PIN);
#define EXTINGUISHER_OFF GPIO_SetBits(EXTINGUISHER_PORT, EXTINGUISHER_PIN);


void BW_Extinguisher_Init(void);
void Pump_GPIOInit(void);
extern uint16_t BW_START;

#endif
