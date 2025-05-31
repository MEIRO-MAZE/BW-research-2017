/*****************************************************
Project   : BW* Main Controller
Version   : 1.0
Year      : 2017
Date      : January 5th 2017
Author    : HAFIDIN BANGUN W.(2014)
University: University of Brawijaya
Department: Electrical Engineering Department, Engineering Faculty
Division  : Legged Fire-Fighting Division (KRPAI)
Comments  : *Dreams/aspirations, in Japanese language

What's New: Optimization from Ver.1.x , BW System using single STM32 and Rangefinder Controller
			New Pin Mapping for every actuator, sensor, and other peripheral

Board Type: STM32F4 Discovery Board
Chip  Type: STM32F407VG
*****************************************************/


#include "main.h"


int toggle=1;
void BW_Initialization(void);
int main(void)
{
	int BUTTON_ACT;
	int SOUND_ACT;
	BW_Initialization();

	mov_static();
	delay_ms(100);

	//BW SERVO CALIBRATION
//	Sendto_PC(USART1,"\r BW RUNTIME CALIBRATION! \r");
//	while(1)
//	{
//		BW_Calibration();
//		CMD_ACTUATE();
//	}

			while( (BW_BUTTON_UNCLICKED) && (SOUND_INACTIVE) )
			{
				if(BW_BUTTON_CLICKED){BUTTON_ACT=1;break;}
				if(SOUND_ACTIVATED){SOUND_ACT=1;break;}
				RotSwitch_Sampling();
				Display_MODE();
				if(BW_BUTTON_CLICKED){BUTTON_ACT=1;break;}
				if(SOUND_ACTIVATED){SOUND_ACT=1;break;}
			}

		if(BW_BUTTON_CLICKED){BUTTON_ACT=1;}
		if(SOUND_ACTIVATED){SOUND_ACT=1;}

	if(BUTTON_ACT==1)
	{
		BW_Buzz(1);
		Sendto_PC(USART1,"BW BUTTON ACTIVATED! \r");
		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"BUTTON ACTIVATED");lcd_putstr(lcd);
		delay_ms(100);

		BW_Dimension_Check();

		//BW BRUSHLESS DC FAN INITIALIZATION
		BW_BLDC_Init();
	}
	else if(SOUND_ACT==1)
	{
		BW_Buzz(2);
		Sendto_PC(USART1,"BW SOUND ACTIVATED! \r");
		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"SOUND ACTIVATED");lcd_putstr(lcd);
		delay_ms(100);

		//BW BRUSHLESS DC FAN INITIALIZATION
		BW_BLDC_Init();

	}

	switch(rot_switch_mode)
	{
//		//BW FAILED INITIALIZATION
		case BW_MODE_DEFAULT:
			{

			}break;

//		//BW LOCATION-ROOM MODE
		case BW_MODE_1:
			{
				BW_Initial_Setup(rot_switch_mode);

				while(1)
				{
					H_2017_Algorithm();
					while(1)
					{
						BW_Buzz(1);
						mov_static();
					}

				}
			}break;

//		//BW RANGEFINDER MONITOR
		case BW_MODE_2:
			{
				BW_Initial_Setup(rot_switch_mode);
				lcd_display_clear();
				lcd_gotoxy(1,0);sprintf(lcd,"BHATARA WIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(4,2);sprintf(lcd,"TEST DRIVE");lcd_putstr(lcd);
				lcd_gotoxy(3,3);sprintf(lcd,":) :) :)");lcd_putstr(lcd);

				delay_ms(2000);
				mov_bwd_3cm(15,MED);
				mov_curve_left_reverse(MED,CLOSE);
				mov_curve_left_reverse(MED,CLOSE);
				mov_curve_left_reverse(MED,CLOSE);
				mov_curve_left_reverse(MED,CLOSE);
				mov_bwd_3cm(15,MED);
				mov_curve_right_reverse(MED,CLOSE);
				mov_curve_right_reverse(MED,CLOSE);
				mov_curve_right_reverse(MED,CLOSE);
				mov_curve_right_reverse(MED,CLOSE);
				mov_bwd_3cm(15,MED);
				mov_rot_right_reverse(MED,CLOSE);
				mov_rot_right_reverse(MED,CLOSE);
				mov_rot_right_reverse(MED,CLOSE);

				while(1)
				{
					BW_Buzz(1);
					mov_static();
				}
//				BW_Buzz(1);
//				BW_PID_Init();
//				follow_right_counter(10);
//
//				BW_Buzz(2);
//				BW_PID_Init();
//				FollowCarpet_Right(COLOUR_BLACK,INVERSE);
//
//				while(Ping[PING_FRONT]<17)
//				{
//					mov_fwd_5cm(5,FAST);
//				}
//
//				BW_Buzz(2);
//				BW_PID_Init();
//				FollowTracer_Left();
//
//				H_2017_Room();
//
//				lcd_display_clear();
//				lcd_gotoxy(1,0);sprintf(lcd,"BATHARA WIJAYA");lcd_putstr(lcd);
//				lcd_gotoxy(3,2);sprintf(lcd,"OTW HOME");lcd_putstr(lcd);
//				lcd_gotoxy(3,3);sprintf(lcd,":) :) :)");lcd_putstr(lcd);
//
//				BW_Buzz(1);
//				BW_PID_Init();
//				FollowCarpet_Right(COLOUR_GRAY,INVERSE);
//
//				BW_Buzz(1);
//				BW_PID_Init();
//				follow_right_counter(3);
//
//				mov_deflect_left(FAST,CLOSE);
//				mov_deflect_left(FAST,CLOSE);
//				mov_deflect_left(FAST,CLOSE);
//
//				BW_Buzz(2);
//				BW_PID_Init();
//				FollowTracer_Left();
//
//				mov_fwd_5cm(10,FAST);
//
//				while(1){
//					mov_static();
//				}

//				lcd_gotoxy(0,0);sprintf(lcd,"HELLO");lcd_putstr(lcd);
//				lcd_gotoxy(0,1);sprintf(lcd,"MY NAME'S");lcd_putstr(lcd);
//				lcd_gotoxy(0,2);sprintf(lcd,"BWLORA");lcd_putstr(lcd);
////				lcd_gotoxy(0,3);sprintf(lcd,"MOV_FWD_5CM");lcd_putstr(lcd);
//				lcd_gotoxy(0,3);sprintf(lcd,"2 to 4a SP");lcd_putstr(lcd);
//
//				R2TO4A_SP_ROUTE=R2TO4A_SP_ACTIVE;
//				Nav_2_To_4A();
////				mov_fwd_5cm(75,MED);
////				FollowTracer_Left();
//				void RoomDetector_Check();
			}break;

//		//BW RUNTIME CALIBRATION
		case BW_MODE_3:
			{
				BW_Initial_Setup(rot_switch_mode);
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"NAVI TEST MENU");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"PLEASE");lcd_putstr(lcd);
				lcd_gotoxy(0,3);sprintf(lcd,"PUSH THE BUTTON");lcd_putstr(lcd);

				while(1)
				{
					Nav_Test_Menu();
//					while(1)
//					{
//						BW_Buzz(1);
//						mov_static();
//					}
				}

			}break;

//		//BW TRIAL MODE
		case BW_MODE_4:
			{
				BW_Initial_Setup(rot_switch_mode);
				lcd_display_clear();

				while(1)
				{
					Hybrid_TCS3200Tracer_MainMenu();
				}
			}break;

//		//BW TESTING MODE
		case BW_MODE_5:
			{
				BW_Initial_Setup(rot_switch_mode);
				lcd_display_clear();

				while(1)
				{
					Sensor_Menu();
				}

			}break;

//		//BW SEARCH FIRE TEST
		case BW_MODE_6:
			{
				BW_Initial_Setup(rot_switch_mode);
				lcd_display_clear();

				while(1)
				{
					BW_FlameFollowDemo();

//					BW_PID_Init();
//					FollowTracer_Left();
//					//BW IN ROOM
//					BW_Buzz(1);
//					H_2017_Room();


				}
			}break;
	}
	while(1)

	return 0;
}

void BW_Initialization(void)
{
	//CLOCK CONFIG
	SystemInit();

	//SYSTICK DELAY INIT
	SysTick_Init();



	//BW HEXAPOD SERVO INIT
	BW_Servo_Initialization();

	//LCD INIT
	delay_ms(50);
	BW_LCD_Init();
	lcd_cursor_off_blink_off();
	lcd_display_clear();

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(5,1);sprintf(lcd,"SYSTEM");lcd_putstr(lcd);
	lcd_gotoxy(1,2);sprintf(lcd,"INITIALIZATION");lcd_putstr(lcd);
	lcd_gotoxy(1,3);sprintf(lcd,"BRAWIJAYA 2017");lcd_putstr(lcd);
	delay_ms(500);

	//INERTIAL MEASUREMENT UNIT (IMU) SENSOR
	BW_CMPS11_Init();

	//BW USART COMMUNICATION PROTOCOLS
	USART1_Init(9600);
	USART2_Init(9600);
	USART3_Init(9600);
	UART4_Init(9600);
	UART5_Init(9600);
	USART6_Init(9600);

	//BW USER INTERFACE
	Button_Init();
	Buzzer_Init();
	FIRE_LED_Init();
	BW_LED_Interrupt_Init();
	RotSwitch_Init();
	RotSwitch_Sampling();

	//INFRARED PROXIMITY SENSOR
	IR_Proximity_Init();



	//BW PID CONTROLLER INITIALIZATION
	BW_PID_Init();

	//BW CONTACT BUMPER
	Bumper_Init();

	//BW SENSOR STAT INTERRUPT

	FlameSensor_Init();

	//BW FLAME TRACKING PID
	FlameSense_PID_Init();

	//BW SOUND ACTIVATION INIT
	BW_Sound_Activation_Init();

	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(5,1);sprintf(lcd,"SYSTEM");lcd_putstr(lcd);
	lcd_gotoxy(1,2);sprintf(lcd,"INITIALIZATION");lcd_putstr(lcd);
	lcd_gotoxy(3,3);sprintf(lcd,"COMPLETED");lcd_putstr(lcd);
	delay_ms(50);


	Sendto_PC(USART1,"PROJECT BW 2017 \r");
	Sendto_PC(USART1,"ELECTRICAL ENGINEERING - UNIVERSITY OF BRAWIJAYA \r");
	Sendto_PC(USART1,"SYSTEM INITIALIZATION");
	Sendto_PC(USART1,".");
	Sendto_PC(USART1,".");
	Sendto_PC(USART1,". \r");
	Sendto_PC(USART1,"INITIALIZATION COMPLETED \r");

}

