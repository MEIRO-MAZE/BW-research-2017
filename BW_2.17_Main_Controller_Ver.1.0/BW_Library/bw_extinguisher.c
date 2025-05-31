/*========================================================================================
								   PROJECT BW 2.16 Ver.1.0
								  BW Hydro Extinguisher Library
==============================================================================================*/

#include "bw_extinguisher.h"



void BW_Extinguisher_Init(void)
{
	Pump_GPIOInit();
	EXTINGUISHER_OFF;
}

void Pump_GPIOInit(void)
{

	RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_EXTINGUISHER, ENABLE); // Clocking GPIOC (AHB1/APB1 = 42MHz)
	GPIO_InitStructure.GPIO_Pin = EXTINGUISHER_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;       // Pin ini memiliki Mode Ouput
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD; 		// Pin bersifat Push Pull (Pull-up, down or no Pull)
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; 	// kecepatan clock(2, 25, 50 or 100 MHz)
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; 	// pin tidak diberikan pull up
	GPIO_Init(EXTINGUISHER_PORT, &GPIO_InitStructure); 		// inisialisasi peripheral GPIO sesuai parameter typdef diatas

}

void BW_HydroPump (void)
{
	EXTINGUISHER_ON;
	delay_ms(4000);
	EXTINGUISHER_OFF;
}
void PushTo_Burst (void)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(2,2);sprintf(lcd,"PUSH TO BURST");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
	delay_ms(100);

	mov_static();
	delay_ms(100);
	BW_START=BW_BUTTON_INPUT;
	if(BW_START==1)
	{
		BW_Buzz(2);
//		BW_HydroPump();
		BW_BLDC_Fight();
	}
	else EXTINGUISHER_OFF;
}
