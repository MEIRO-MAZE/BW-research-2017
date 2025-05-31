/*==============================================================================================
								   PROJECT BW 2017 Ver.1.0
								     BW ALGORITHM LIBRARY
===============================================================================================*/

#include "bw2017_algorithm.h"
/*==============================================================================================
								   PRE-TRIAL FUNCTION
===============================================================================================*/

/* func      : void BW_Dimension_Check(void)
 * brief     : Detecting dimension checking condition and configuring locomotion to fit the dimension check box
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Sunday, October 15th 2015)
 * Revised BY: N/A
 * programmer's Note: Trigger the BW Dimension check by putting your hands <= 10 cm away from RIGHT and LEFT PING)))
 *
 */
void BW_Dimension_Check(void)
{
	BW_Buzz(3);

	while( (Ping[PING_LEFT]<=10)&&(Ping[PING_RIGHT]<=10) )
	{
//		mov_fwd_5cm(5,FAST_LEVEL_3);
//		mov_fwd_3cm(3,FAST_LEVEL_3);
		mov_fwd_2cm(2,FAST_LEVEL_3);
		BW_Buzz(1);
	}

	BW_Buzz(3);
}


void Sensor_Menu(void)
{
	int MENU_VAR=0;

//	while(BUTTON_IDLE)
//	{
//		lcd_display_clear();
//		lcd_gotoxy(0,0);sprintf(lcd,"BW 2016");lcd_putstr(lcd);
//		lcd_gotoxy(0,1);sprintf(lcd,"SENSOR MONITOR");lcd_putstr(lcd);
//		delay_ms(100);
//	}

	if(BW_BUTTON_CLICKED)
	{
//		while(BUTTON_IDLE)
//		{
//			BW_Buzz(1);
//			lcd_display_clear();
//			lcd_gotoxy(0,0);sprintf(lcd,"BW 2016");lcd_putstr(lcd);
//			lcd_gotoxy(0,1);sprintf(lcd,"SENSOR MONITOR");lcd_putstr(lcd);
//			delay_ms(100);
//		}

		while(1)
		{
			if(BUTTON_A_CLICKED)
			{
				BW_Buzz(2);
				while(BUTTON_A_CLICKED){};
				MENU_VAR++;
			}
			if(BUTTON_B_CLICKED)
			{
				BW_Buzz(1);
				while(BUTTON_B_CLICKED){};
				MENU_VAR--;
			}

			if(MENU_VAR>5) MENU_VAR=0;
			else if (MENU_VAR<0) MENU_VAR=5;

			switch(MENU_VAR)
			{
				case 0:
						{
							Display_Ping_Status ();
							Send_Ping_Status ();
						}break;

				case 1:
						{
							Get_IR();
							Display_IR_Stat();
						}break;
				case 2:
						{
							Display_Bumper_Stat();
						}break;
				case 3:
						{
							Display_FlameSense();
						}break;

				case 4:
						{
//							RoomTypeDetector();
							RoomDetector();
						}break;
				case 5:
						{
							PushTo_Burst();
//							BW_BLDC_Fight();
						}break;
//				case 6:
//						{
//							Display_Flame();
//						}break;

			}

		}

	}

}

void Nav_Test_Menu(void)
{
	int MENU_VAR=0;

	if(BW_BUTTON_CLICKED)
	{

		while(1)
		{
			if(BUTTON_A_CLICKED)
			{
				BW_Buzz(2);
				while(BUTTON_A_CLICKED){};
				MENU_VAR++;
			}
			if(BUTTON_B_CLICKED)
			{
				BW_Buzz(1);
				while(BUTTON_B_CLICKED){};
				MENU_VAR--;
			}

			if(MENU_VAR>27) MENU_VAR=0;
			else if (MENU_VAR<0) MENU_VAR=27;

			switch(MENU_VAR)
			{
				case 0:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"1A to 2");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_1A_To_2();
						}break;

				case 1:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"1A to 3");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_1A_To_3();
						}break;
				case 2:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"1A to 4A");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_1A_To_4A();
						}break;
				case 3:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"1A to 4B");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_1A_To_4B();
						}break;

				case 4:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"1B to 2");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_1B_To_2();
						}break;
				case 5:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"1C to 2");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_1C_To_2();
						}break;
				case 6:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"1C to 3");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_1C_To_3();
						}break;
				case 7:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"1C to 4A");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_1C_To_4A();
						}break;
				case 8:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"1C to 4B");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_1C_To_4B();
						}break;
				case 9:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"2 to 1A");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_2_To_1A();
						}break;
				case 10:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"2 to 3");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_2_To_3();
						}break;
				case 11:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"2 to 4A");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_2_To_4A();
						}break;
				case 12:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"2 to 4B");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_2_To_4B();
						}break;
				case 13:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"1C to 4B");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_1C_To_4B();
						}break;
				case 14:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"2A to 1BC");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_2A_To_1BC();
						}break;
				case 15:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"2B to 1BC");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_2B_To_1BC();
						}break;
				case 16:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"3 to 1A");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_3_To_1A();
						}break;
				case 17:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"3 to 1BC");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_3_To_1BC();
						}break;
				case 18:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"3 to 2");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_3_To_2();
						}break;
				case 19:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"3 to 4A");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_3_To_4A();
						}break;
				case 20:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"3 to 4B");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_3_To_4B();
						}break;
				case 21:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"4A to 1A");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_4A_To_1A();
						}break;
				case 22:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"4A to 2");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_4A_To_2();
						}break;
				case 23:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"4A to 3");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_4A_To_3();
						}break;
				case 24:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"4B to 1A");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_4B_To_1A();
						}break;
				case 25:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"4B to 1BC");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_4B_To_1BC();
						}break;
				case 26:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"4B to 2");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_4B_To_2();
						}break;
				case 27:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"4B to 3");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_4B_To_3();
						}break;

			}

		}

	}
}

/* func      : void BW_Home_Detection(void)
 * brief     : Detecting Home
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Sunday, October 15th 2015)
 * Revised BY: Ver.2 -> Ryan (Monday, March 15th 2016)
 * 				Configured for the KRPAI 2016 Rule (Red Zone Version)
 * programmer's Note:
 *
 */
void BW_Home_Detection(void)
{
	unsigned int HOME;
	int counter=0;

	HOME=1;
	if (HOME==1)
	{
		if (Ping[PING_FRONT]>25)
		{
//			BW_Buzz(1);
			if( Ping[PING_LEFT]>16 || Ping[PING_ASKEW_LEFT]>16)
			{
				if(Ping[PING_RIGHT]<16)
				{
					while(Ping[PING_RIGHT]<16)
					{
						mov_rot_right(FAST,FAR);
					}
					mov_rot_right(FAST,FAR);
					mov_rot_right(FAST,FAR);
					mov_rot_right(FAST,FAR);
					mov_rot_right(FAST,FAR);
					mov_rot_right(FAST,FAR);
					while(Ping[PING_FRONT]<16)
					{
						mov_rot_right(FAST,FAR);
					}
					mov_fwd_5cm(5,FAST);
				}
				else
				{
					mov_rot_left(FAST,FAR); //adjust to correct position
					mov_rot_left(FAST,FAR); //adjust to correct position
					mov_rot_left(FAST,FAR); //adjust to correct position
					mov_rot_left(FAST,FAR);
//					mov_rot_left(FAST,FAR);
					while(
							(Ping[PING_LEFT]>=15) && (Ping[PING_ASKEW_LEFT]>=15)
						 )
					{
						mov_rot_left(FAST,FAR);
						mov_rot_left(FAST,FAR);
	//					mov_rot_left(FAST_LEVEL_3,CLOSE);
						if(Ping[PING_FRONT]<=13 )
						{
							mov_bwd_5cm(5,FAST);
						}
						counter++;

						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"ROT COUNTER: %d",counter);lcd_putstr(lcd);
						delay_ms(100);

						if(counter>=1)
						{
							BW_Buzz(1);
							mov_deflect_left(FAST,CLOSE);
							mov_deflect_left(FAST,CLOSE);
							mov_deflect_left(FAST,CLOSE);

							mov_rot_left(FAST,FAR);
//							mov_fwd_5cm(5,FAST);

							BW_Buzz(1);
							BW_PID_Init();
							follow_left_counter(5);
						}

					}
				}
			}
		}

		else if(Ping[PING_FRONT]<=25)
		{
			BW_Buzz(2);

			while(
				   ( (Ping[PING_FRONT]<=25) && (Ping[PING_LEFT]>=15) ) ||
				   ( (Ping[PING_FRONT]<=25 && Ping[PING_LEFT]<=15)   )
				 )
			{
				if(Ping[PING_FRONT]<=13 )
				{
					mov_bwd_5cm(5,FAST);
				}
				mov_rot_right(FAST,FAR);
//				mov_rot_right(FAST_LEVEL_2,FAR);
			}
			while(Ping[PING_ASKEW_LEFT]<=15)
			{
				mov_rot_right(FAST,FAR);
//				mov_rot_right(FAST_LEVEL_2,FAR);
			}
		}

	}
}

/* func      : void BW_Home_Detection_Ver2(void)
 * brief     : Detecting Home
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Hafidin (Wed, Dec 7th 2016)
 * Revised BY:
 *
 * programmer's Note:
 *
 */

void BW_Home_Detection_Ver2(void)
{
	unsigned int HOME;
	int counter=0;

	HOME=1;
	if (HOME==1)
	{
		if ((Ping[PING_RIGHT]<25) || (Ping[PING_FRONT]<20) || (Ping[PING_ASKEW_RIGHT]<25))
		{
			if (Ping[PING_FRONT]<20)
			{
				mov_rot_right(FAST,FAR);
				mov_rot_right(FAST,FAR);
				mov_rot_right(FAST,FAR);
			}

			while(Ping[PING_RIGHT]<25 || (Ping[PING_ASKEW_RIGHT]<25))
			{
				mov_rot_right(FAST,FAR);
			}

			if (Ping[PING_FRONT]<20)
			{
				mov_rot_right(FAST,FAR);
				mov_rot_right(FAST,FAR);
				mov_rot_right(FAST,FAR);
			}

			while(Ping[PING_LEFT]>18)
			{
				mov_rot_right(FAST,FAR);
			}

		}
		else
		{
			while(Ping[PING_LEFT]>20)
			{
				mov_rot_left(FAST,FAR);
				counter++;

				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"ROT COUNTER: %d",counter);lcd_putstr(lcd);
				delay_ms(100);

				if(counter>=3)
				{
					BW_Buzz(1);
					mov_deflect_left(FAST,CLOSE);
					mov_deflect_left(FAST,CLOSE);
					mov_deflect_left(FAST,CLOSE);
					mov_deflect_left(FAST,CLOSE);

					mov_rot_left(FAST,FAR);
					mov_fwd_5cm(5,FAST);

					BW_Buzz(1);
					BW_PID_Init();
					follow_left_counter(3);
				}
			}
		}
	}
}

void Home_HallwaySC_Detector(void)
{
//	RoomTypeDetector();
//	mov_static();
//	delay_ms(100);

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);

	delay_ms(100);

	if	(
			(TCS3200_SLV_DATA[0]==COLOUR_GRAY)
		)

	{
//		BW_Buzz(1);
//		BW_PID_Init();
//		follow_right_counter(4);

		if ( (Ping[PING_FRONT]>=85) && (Ping[PING_LEFT]<=30) && (Ping[PING_RIGHT]<=30) )
		{
			ROOM[1]= HALLWAY_SC;
			ROOM_COUNTER++;

			BW_Buzz(2);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"HALLWAY SC");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"DETECTED");lcd_putstr(lcd);
			delay_ms(100);

		}

	}


}



/* func      : void Escape_Home(void)
 * brief     : BW Escape from Home sequences
 * param     : N/A
 * retval    : N/A
 * Ver       : 3
 * written By: Ryan (*MISSING NOTES*)
 * Revised BY: Ver.3 -> Ryan (Monday, March 15 2016)
 * 						Configured for the 2016 Rule (Simplified version from before)
 * 						Ryan (Friday, April 1st 2016)
 * 						Configured for the new TCS3200 Processor interfacing
 * programmer's Note:
 *
 */
void Escape_Home(void)
{


	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"ESCAPE HOME");lcd_putstr(lcd);
	delay_ms(100);

	if(Ping[PING_LEFT]<18)
	{
		mov_deflect_left(FAST,CLOSE);
	}
	if(Ping[PING_LEFT]<18)
	{
		mov_deflect_left(FAST,CLOSE);
	}
	if(Ping[PING_LEFT]<18)
	{
		mov_deflect_left(FAST,CLOSE);
	}

	BW_PID_Init();
	follow_left_counter(3);

	TCSlave_Check();
	BW_PID_Init();

	while( (TCS3200_SLV_DATA[0]==COLOUR_WHITE) || (TCS3200_SLV_DATA[1]==TRACER_ACTIVE) )
	{
		TCSlave_Check();
		follow_left_counter(2);
	}
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"EXIT ROOM");lcd_putstr(lcd);
	delay_ms(100);
}


void BW_FireFighter(void)
{
//====================================BW DEFAULT ROUTINES=====================================//
	//PING_FRONT FAILCHECK
	while(Ping[PING_FRONT]==0)
	{
		BW_Buzz(1);
		delay_ms(100);
	}

	Sendto_PC(USART1,"\r BW BLUE FIGHTER WHILE INFINITE LOOP \r");

	BW_Home_Detection();

	BW_Buzz(4);
	Escape_Home();
	Evade_Wall();
//==============================================================================================//

}

void BW_Arbitrary_Start(void)
{
	BW_LOCATION[PRESENT_LOC]=LOCATION_ROOM;
	BW_Buzz(2);
}

void BW_Non_Arbitrary_Start(void)
{
	BW_LOCATION[PRESENT_LOC]=LOCATION_CORRIDOR;
	BW_Buzz(2);
}


void Evade_Wall(void)
{

	Get_IR();
	GetBumper();
	GetFlame();

//	if(BW_LOCATION[0]==LOCATION_ROOM)
//	{
//		if(SHARP[SHARP_LEFT]<7)
//		{
//			while(SHARP[SHARP_LEFT]<6)
//			{
//				mov_deflect_right(FAST,CLOSE);
//			}
//		}
//
//		else if (SHARP[SHARP_RIGHT]<9)
//		{
//			while(SHARP[SHARP_RIGHT]<7)
//			{
//				mov_deflect_left(FAST,CLOSE);
//			}
//		}
//	}
//
//	else if(BW_LOCATION[0]==LOCATION_CORRIDOR)
//	{
//		if(SHARP[SHARP_LEFT]<6)
//		{
//			while(SHARP[SHARP_LEFT]<5)
//			{
//				mov_deflect_right(FAST,CLOSE);
//			}
//		}
//
//		else if (SHARP[SHARP_RIGHT]<6)
//		{
//			while(SHARP[SHARP_RIGHT]<5)
//			{
//				mov_deflect_left(FAST,CLOSE);
//			}
//		}
//	}

	if(BW_LOCATION[0]==LOCATION_ROOM)
	{
		if(Ping[PING_LEFT]<10)
		{
			while(Ping[PING_LEFT]<10)
			{
//				mov_deflect_right(FAST,CLOSE);
				mov_deflect_right(FAST,CLOSE);
			}
		}

		else if (Ping[PING_RIGHT]<10)
		{
			while(Ping[PING_RIGHT]<10)
			{
//				mov_deflect_left(FAST,CLOSE);
				mov_deflect_left(FAST,CLOSE);
			}
		}
	}

	else if(BW_LOCATION[0]==LOCATION_CORRIDOR)
	{
		if(Ping[PING_LEFT]<10)
		{
			while(Ping[PING_LEFT]<10)
			{
//				mov_deflect_right(FAST,CLOSE);
				mov_deflect_right(FAST,CLOSE);
			}
		}

		else if (Ping[PING_RIGHT]<10)
		{
			while(Ping[PING_RIGHT]<10)
			{
//				mov_deflect_left(FAST,CLOSE);
				mov_deflect_left(FAST,CLOSE);
			}
		}
	}

//	if(Ping[PING_LEFT]<6)
//	{
//		while(Ping[PING_LEFT]<5)
//		{
//			mov_deflect_right(FAST,CLOSE);
//		}
//	}
//
//	else if (Ping[PING_RIGHT]<6)
//	{
//		while(Ping[PING_RIGHT]<5)
//		{
//			mov_deflect_left(FAST,CLOSE);
//		}
//	}

//	if	(
//			((INFRARED[IR_MID_RIGHT]==IR_MID_DETECTED) || (INFRARED[IR_MID_LEFT]==IR_MID_DETECTED))
//
//	 	 )
//	{
//		while( (INFRARED[IR_MID_RIGHT]==IR_MID_DETECTED) )
//		{
//			//RIGHT OVERFLOW RESET
//			RIGHT_OVERFLOW_COUNTER=0;
//
//			//COUNTING LEFT OVERFLOW
//			LEFT_OVERFLOW_COUNTER++;
//
//			Get_IR();
//			mov_deflect_left(FAST,CLOSE);
//
//			if(LEFT_OVERFLOW_COUNTER>=13)
//			{-
//				LEFT_OVERFLOW_COUNTER=0;
//				lcd_display_clear();
//				lcd_gotoxy(0,0);sprintf(lcd,"DEFLECT LEFT");lcd_putstr(lcd);
//				lcd_gotoxy(0,1);sprintf(lcd,"OVERFLOW");lcd_putstr(lcd);
//				delay_ms(100);
//
//				mov_fwd_5cm(15,FAST_LEVEL_3);
//			}
//		}
//
//		while( (INFRARED[IR_MID_LEFT]==IR_MID_DETECTED) )
//		{
//			//LEFT OVERFLOW RESET
//			LEFT_OVERFLOW_COUNTER=0;
//
//			//COUNTING LEFT OVERFLOW
//			RIGHT_OVERFLOW_COUNTER++;
//
//			Get_IR();
//			mov_deflect_right(FAST,CLOSE);
//
//			if(RIGHT_OVERFLOW_COUNTER>=13)
//			{
//				RIGHT_OVERFLOW_COUNTER=0;
//				lcd_display_clear();
//				lcd_gotoxy(0,0);sprintf(lcd,"DEFLECT RIGHT");lcd_putstr(lcd);
//				lcd_gotoxy(0,1);sprintf(lcd,"OVERFLOW");lcd_putstr(lcd);
//				delay_ms(100);
//
//				mov_fwd_5cm(15,FAST_LEVEL_3);
//			}
//
//		}
//	}




	if	(
			 	 ((BUMPER[LEFT]==ACTIVE) && (BUMPER[RIGHT]==INACTIVE))
			)
	{
		BW_Buzz(1);
		Sendto_PC(USART1,"BW ROT RIGHT in Evade Wall: IR_FRONT_RIGHT DETECTS OBSTACLE \r");
		//mov_bwd(5,FAST_LEVEL_3);
		if(TCS3200_SLV_DATA[1]==1)
		{
			TRACER_IN_BUMPER=TRC_BMP_ACTIVE;
		}
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);

		if(TCS3200_SLV_DATA[1]==1)
		{
			TRACER_IN_BUMPER=TRC_BMP_ACTIVE;
		}
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);


//		Get_IR();
//		while( INFRARED[IR_FRONT_LEFT]==IR_DETECTED )
//		{
//			if(TCS3200_SLV_DATA[1]==1)
//			{
//				TRACER_IN_BUMPER=TRC_BMP_ACTIVE;
//			}
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//
//			Get_IR();
//		}
	}
	else if	(
				((BUMPER[RIGHT]==ACTIVE) && (BUMPER[LEFT]==INACTIVE))
			)
	{
		BW_Buzz(1);

		Sendto_PC(USART1,"BW ROT LEFT in Evade Wall: IR_FRONT_LEFT DETECTS OBSTACLE \r");
		//mov_bwd(5,FAST_LEVEL_3);

		if(TCS3200_SLV_DATA[1]==1)
		{
			TRACER_IN_BUMPER=TRC_BMP_ACTIVE;
		}
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);

		if(TCS3200_SLV_DATA[1]==1)
		{
			TRACER_IN_BUMPER=TRC_BMP_ACTIVE;
		}
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);


//		Get_IR();
//		while( INFRARED[IR_FRONT_RIGHT]==IR_DETECTED )
//		{
//			if(TCS3200_SLV_DATA[1]==1)
//			{
//				TRACER_IN_BUMPER=TRC_BMP_ACTIVE;
//			}
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			Get_IR();
//		}
	}
}

void Evade_Wall_Room(void)
{
	Get_IR();
	GetBumper();
//	GetFlame();

//	if	(
//			((INFRARED[IR_MID_RIGHT]==IR_MID_DETECTED) || (INFRARED[IR_MID_LEFT]==IR_MID_DETECTED)) &&
//			(( FLAME_SENSOR[FLM_RIGHT]==FLAME_NOT_DETECTED) || ( FLAME_SENSOR[FLM_LEFT]==FLAME_NOT_DETECTED))
//	 	 )
//	{
//		while( (INFRARED[IR_MID_RIGHT]==IR_MID_DETECTED) && ( FLAME_SENSOR[FLM_RIGHT]==FLAME_NOT_DETECTED) )
//		{
//			Get_IR();
//			mov_deflect_left(FAST,CLOSE);
//		}
//
//		while( (INFRARED[IR_MID_LEFT]==IR_MID_DETECTED) && ( FLAME_SENSOR[FLM_LEFT]==FLAME_NOT_DETECTED) )
//		{
//			Get_IR();
//			mov_deflect_right(FAST,CLOSE);
//		}
//	}

//	if(SHARP[SHARP_LEFT]<7)
//	{
//		while(SHARP[SHARP_LEFT]<6)
//		{
//			mov_deflect_right(FAST,CLOSE);
//		}
//	}
//
//	else if (SHARP[SHARP_RIGHT]<7)
//	{
//		while(SHARP[SHARP_RIGHT]<6)
//		{
//			mov_deflect_left(FAST,CLOSE);
//		}
//	}

	if(Ping[PING_LEFT]<7)
	{
		while(Ping[PING_LEFT]<6)
		{
//			mov_deflect_right(FAST,CLOSE);
			mov_deflect_right(FAST,CLOSE);
			mov_deflect_right(FAST,CLOSE);
		}
	}

	else if (Ping[PING_RIGHT]<7)
	{
		while(Ping[PING_RIGHT]<6)
		{
//			mov_deflect_left(FAST,CLOSE);
			mov_deflect_left(FAST,CLOSE);
			mov_deflect_left(FAST,CLOSE);
		}
	}

	if	(
			(Ping[PING_LEFT]<=5) || (Ping[PING_RIGHT]<=5)
	 	 )
	{
		while( (Ping[PING_LEFT]<=5) && (Ping[PING_RIGHT]>5) )
		{
			Get_IR();
//			mov_deflect_right(FAST,CLOSE);
			mov_deflect_right(FAST,CLOSE);
			mov_deflect_right(FAST,CLOSE);
		}

		while( (Ping[PING_RIGHT]<=5) && (Ping[PING_LEFT]>5) )
		{
			Get_IR();
//			mov_deflect_left(FAST,CLOSE);
			mov_deflect_left(FAST,CLOSE);
			mov_deflect_left(FAST,CLOSE);
		}
	}

	else if	(
			 	 ((BUMPER[LEFT]==ACTIVE) && (BUMPER[RIGHT]==INACTIVE))
			)
	{
		BW_Buzz(1);
		Sendto_PC(USART1,"BW ROT RIGHT in Evade Wall: IR_FRONT_RIGHT DETECTS OBSTACLE \r");
		//mov_bwd(5,FAST_LEVEL_3);
		if(TCS3200_SLV_DATA[1]==1)
		{
			TRACER_IN_BUMPER=TRC_BMP_ACTIVE;
		}
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);

		if(TCS3200_SLV_DATA[1]==1)
		{
			TRACER_IN_BUMPER=TRC_BMP_ACTIVE;
		}
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);


//		Get_IR();
//		while( INFRARED[IR_FRONT_LEFT]==IR_DETECTED )
//		{
//			if(TCS3200_SLV_DATA[1]==1)
//			{
//				TRACER_IN_BUMPER=TRC_BMP_ACTIVE;
//			}
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//
//			Get_IR();
//		}
//		mov_fwd_5cm(10,FAST_LEVEL_3);
	}
	else if	(
				((BUMPER[RIGHT]==ACTIVE) && (BUMPER[LEFT]==INACTIVE))
			)
	{

		BW_Buzz(1);
		Sendto_PC(USART1,"BW ROT LEFT in Evade Wall: IR_FRONT_LEFT DETECTS OBSTACLE \r");
		//mov_bwd(5,FAST_LEVEL_3);

		if(TCS3200_SLV_DATA[1]==1)
		{
			TRACER_IN_BUMPER=TRC_BMP_ACTIVE;
		}
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);

		if(TCS3200_SLV_DATA[1]==1)
		{
			TRACER_IN_BUMPER=TRC_BMP_ACTIVE;
		}
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);

//		Get_IR();
//		while( INFRARED[IR_FRONT_RIGHT]==IR_DETECTED )
//		{
//			if(TCS3200_SLV_DATA[1]==1)
//			{
//				TRACER_IN_BUMPER=TRC_BMP_ACTIVE;
//			}
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			Get_IR();
//		}
//		mov_fwd_5cm(10,FAST_LEVEL_3);
	}
}


void Bump_Avoider(void)
{

		GetBumper();

		if	(
				 	 ((BUMPER[LEFT]==ACTIVE) && (BUMPER[RIGHT]==INACTIVE))
				)
		{
			Sendto_PC(USART1,"BW ROT RIGHT in Evade Wall: IR_FRONT_RIGHT DETECTS OBSTACLE \r");
			if(TCS3200_SLV_DATA[1]==1)
			{
				TRACER_IN_BUMPER=TRC_BMP_ACTIVE;
			}
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
			mov_rot_right(FAST_LEVEL_3,CLOSE);
			mov_rot_right(FAST_LEVEL_3,CLOSE);
		}
		else if	(
					((BUMPER[RIGHT]==ACTIVE) && (BUMPER[LEFT]==INACTIVE))
				)
		{

			Sendto_PC(USART1,"BW ROT LEFT in Evade Wall: IR_FRONT_LEFT DETECTS OBSTACLE \r");

			if(TCS3200_SLV_DATA[1]==1)
			{
				TRACER_IN_BUMPER=TRC_BMP_ACTIVE;
			}
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
			mov_rot_left(FAST_LEVEL_3,CLOSE);
			mov_rot_left(FAST_LEVEL_3,CLOSE);
		}

}
void ReturnTo_Room(void)
{
	Get_IR();
	while ( (Ping[PING_FRONT]>=25) && (INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED) )
	{
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		Get_IR();
	}

	Get_IR();
	while ( Ping[PING_FRONT]<=25 || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
	{
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		Get_IR();
	}
//	mov_fwd_5cm(10,FAST_LEVEL_3);
	mov_fwd_5cm(10,FAST_LEVEL_3);


	RETURN_COUNTER++;

	if(RETURN_COUNTER>=2)
	{
		BW_Buzz(4);

		if(VARIABLE_DOOR==VAR_DOOR_DETECTED)
		{
//			followfire_left_new();
		}
		else
		{
//			followfire_right_new();

		}

	}

}


/* 	  CAT POSSIBLE LOCATION
 * ___________________________
 *  |                         |
 *  |	  xxx				  |
 * 	|    _____                |
 * 	|    |              |     |
 * 	|    |              | xxx |
 * 	|    |              |     |
 * 	|    |              |     |
 *__| 	 |______________|     |
 * 	                          |
 *			xxx               |
 *____________________________|
 */
void Cat_Avoider(void)
{
	Get_IR();
	if(
//		 ( (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) )&&
//
//		(
//			(
//				(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
//				(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED) &&
//				(Ping[PING_FRONT]>=30)
//			)
//		 )
//		((INFRARED[IR_UPPER_RIGHT]==IR_DETECTED) && (INFRARED[IR_UPPER_LEFT]==IR_DETECTED)) && ((INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED) && (Ping[PING_FRONT]>=35) )
		((INFRARED[IR_UPPER_RIGHT]==IR_DETECTED) && (INFRARED[IR_UPPER_LEFT]==IR_DETECTED)) && ((INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED) && (INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED))
		 &&
		 (BW_LOCATION[0]==LOCATION_CORRIDOR) //Cat Avoider Routines only active inside room
	  )
	{
		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"CAT DETECTOR");lcd_putstr(lcd);
		lcd_gotoxy(3,1);sprintf(lcd,"ACTIVATED");lcd_putstr(lcd);


		delay_ms(100);

		if(SHIFT_ALGORITHM_FLAG==SHIFT_ALGORITHM_ACTIVE)
		{
			CAT_FLAG = CAT_DETECTED;
		}


		BW_Buzz(2);
		//BW_Buzz(3);

//		Get_IR();

//		Evade_Wall();
//		mov_bwd(10,FAST_LEVEL_3);
//		mov_bwd(10,FAST_LEVEL_3);
		mov_bwd_5cm(25,FAST);
//		mov_bwd_3cm(9,FAST_LEVEL_3);
//		mov_bwd_3cm(3,FAST_LEVEL_3);

		Evade_Wall();
//		mov_bwd(10,FAST_LEVEL_3);
//		mov_bwd(10,FAST_LEVEL_3);
//		mov_bwd_3cm(9,FAST_LEVEL_3);
//		mov_bwd_3cm(9,FAST_LEVEL_3);


//		Evade_Wall();

		if(ROOM4A_CAT_AVOIDER==ROOM4A_CAT_AVOIDER_ACTIVE)
		{
			lcd_gotoxy(3,2);sprintf(lcd,"ROOM4A CAT");lcd_putstr(lcd);
			BW_Buzz(2);

			if(Ping[PING_RIGHT]<=15)
			{
				mov_deflect_left(FAST,CLOSE);
				mov_deflect_left(FAST,CLOSE);
				mov_deflect_left(FAST,CLOSE);
				mov_deflect_left(FAST,CLOSE);
			}

			while(Ping[PING_RIGHT]<25)
			{
				mov_rot_right(FAST_LEVEL_2,FAR);
				if(Ping[PING_FRONT]<13)
				{
					mov_bwd_5cm(10,FAST_LEVEL_3);
				}
			}

			while(Ping[PING_FRONT]<13)
			{
				mov_rot_right(FAST_LEVEL_2,FAR);
			}
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//			if(Ping[PING_FRONT]<=10) mov_bwd_3cm(3,FAST_LEVEL_3);//mov_bwd(5,FAST_LEVEL_3);
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//			mov_rot_right(FAST_LEVEL_3,CLOSE);

			BW_Buzz(2);
//			Get_IR();
//			while ( (INFRARED[IR_UPPER_LEFT]==IR_DETECTED) || (INFRARED[IR_UPPER_RIGHT]==IR_DETECTED) )
//			while (INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
//			{
//				if(Ping[PING_FRONT]<=15) mov_bwd_3cm(3,FAST_LEVEL_3);//mov_bwd(5,FAST_LEVEL_3);
//				mov_rot_right(FAST_LEVEL_3,CLOSE);
//				mov_rot_right(FAST_LEVEL_3,CLOSE);
//				Get_IR();
//			}

			ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_INACTIVE;
		}

		else
		{
			BW_Buzz(2);
			if(Ping[PING_LEFT]<=15)
			{
				mov_deflect_right(FAST,CLOSE);
				mov_deflect_right(FAST,CLOSE);
				mov_deflect_right(FAST,CLOSE);
				mov_deflect_right(FAST,CLOSE);
			}

//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
			if(Ping[PING_FRONT]<=10) mov_bwd_3cm(3,FAST_LEVEL_3); //mov_bwd(5,FAST_LEVEL_3);
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			mov_rot_left(FAST_LEVEL_3,CLOSE);



			BW_Buzz(2);
//			Get_IR();
////			while ( (INFRARED[IR_UPPER_LEFT]==IR_DETECTED) || (INFRARED[IR_UPPER_RIGHT]==IR_DETECTED) )
//				while (INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
//				{
//					if(Ping[PING_FRONT]<=15) mov_bwd_3cm(3,FAST_LEVEL_3);//mov_bwd(5,FAST_LEVEL_3);
//					mov_rot_right(FAST_LEVEL_3,CLOSE);
//					mov_rot_right(FAST_LEVEL_3,CLOSE);
//					Get_IR();
//				}
		}


	}
}

void Check_Cat_Avoider(void)
{
	CAT_FLAG=CAT_NOT_DETECTED;
	while(CAT_FLAG==CAT_NOT_DETECTED)
	{
		follow_right_counter(1);
	}

	while(1)
	{
		mov_static();
		BW_Buzz(2);
	}
}



/*
 *  FOLLOW RIGHT COUNTER
 *
 */
void follow_right_counter(int limit)
{
	int counter;
//	CAT_FLAG = CAT_NOT_DETECTED;
	//int limit=15;
	for(counter=1;counter<=limit;counter++)
	{
		Cat_Avoider();
		Evade_Wall();

		if (Ping[PING_FRONT]<=16)
//		if (Ping[PING_FRONT]<=20)
		{

//			mov_rot_left(FAST_LEVEL_3, CLOSE);
//			mov_rot_left(FAST_LEVEL_3, CLOSE);
			mov_rot_left(FAST_LEVEL_2,FAR);
			mov_rot_left(FAST_LEVEL_2,FAR);
//			if (Ping[PING_RIGHT]<=20)
//			{
//				Sendto_PC(USART1,"BW ROTATE LEFT \r");
//				mov_rot_left(FAST_LEVEL_3, CLOSE);
//			}
//
//			if (Ping[PING_RIGHT]>20)
//			{
//				Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//				mov_rot_right(FAST_LEVEL_3, CLOSE);
//			}
		}
		else
		{
			PID_follow_right_counter();
		}
	}



}

/* func      : void PID_follow_tracer_right(void)
 * brief     : Wall following using PID controller right rule
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Monday, October 19th 2015)
 * Revised BY: Ver.2 Ryan (Friday, April 16th 2016)
 * 					* Added Follow overflow limit
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */
void PID_follow_right_counter(void)
{
	//int limit= *COMMAND_LOOP;
	int OVERRIDE=0;

	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;

//	Sendto_PC(USART1,"Ping: %d \t",(int)Ping[PING_ASKEW_RIGHT]);
//	Sendto_PC(USART1,"SHARP ASKEW RIGHT: %d \t",(int)SHARP[SHARP_RIGHT]);
	Sendto_PC(USART1,"Ping: %d \t",(int)Ping[PING_RIGHT]);
	PID_Calc_RightRule();
	Sendto_PC(USART1,"PID_F_R.pid_value[0]: %d \r",(int)PID_F_R.pid_value[0]);

//	BW_Buzz(3);
//	lcd_display_clear();
//	lcd_gotoxy(0,0);sprintf(lcd,"pid_value: %d \r",(int)PID_F_R.pid_value[0]);lcd_putstr(lcd);
//	delay_ms(100);


	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
			if ( (Ping[PING_ASKEW_RIGHT]<=PID_F_R.set_point_upper) && (Ping[PING_ASKEW_RIGHT]>=PID_F_R.set_point_lower) )
//			if ( (SHARP[SHARP_RIGHT]<=PID_F_R.set_point_upper) && (SHARP[SHARP_RIGHT]>=PID_F_R.set_point_lower)) //&& ((Ping[PING_RIGHT]<=12) && (Ping[PING_RIGHT]>=16)) )
//			if ( (Ping[PING_RIGHT]<=PID_F_R.set_point_upper) && (Ping[PING_RIGHT]>=PID_F_R.set_point_lower) )
				{
					if (Ping[PING_FRONT]<=16)
//					if (Ping[PING_FRONT]<=20)
					{
//						mov_rot_left(FAST_LEVEL_3, CLOSE);
//						mov_rot_left(FAST_LEVEL_3, CLOSE);
						mov_rot_left(FAST_LEVEL_2,FAR);
						mov_rot_left(FAST_LEVEL_2,FAR);
//						if (Ping[PING_RIGHT]<=20)
//						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
//						if (Ping[PING_RIGHT]>20)
//						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

						Sendto_PC(USART1,"BW FORWARD \r");
//						mov_fwd_5cm(5, FAST_LEVEL_3);
						mov_fwd_5cm(5,FAST_LEVEL_3);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT JAUH DARI DINDING
			else if ( Ping[PING_ASKEW_RIGHT]>PID_F_R.set_point )
//			else if ( SHARP[SHARP_RIGHT]>PID_F_R.set_point )
//			else if ( Ping[PING_RIGHT]>PID_F_R.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
					if (PID_F_R.pid_value[0]>13)
					{
						WINDUP_RIGHT_COUNTER++;
						PID_F_R.pid_value[0]=13; //WINDUP
					}

					if (Ping[PING_FRONT]<=16)
//					if (Ping[PING_FRONT]<=20)
					{
//						mov_rot_left(FAST_LEVEL_3, CLOSE);
//						mov_rot_left(FAST_LEVEL_3, CLOSE);
						mov_rot_left(FAST_LEVEL_2,FAR);
						mov_rot_left(FAST_LEVEL_2,FAR);
//						if (Ping[PING_RIGHT]<=20)
//						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
//						if (Ping[PING_RIGHT]>20)
//						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
//						if(WINDUP_RIGHT_COUNTER>=25)
						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

							GetBumper();
							while(Ping[PING_FRONT]>=16)
//							while(Ping[PING_FRONT]>=20)
							{
//								mov_fwd_5cm(5,FAST_LEVEL_3);
								mov_fwd_5cm(5,FAST_LEVEL_3);
								GetBumper();
//								Get_IR();		//FUNGSI BARU!!!!!
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_RIGHT]>=16)
//							while(Ping[PING_RIGHT]>=10)
							{
//								mov_rot_left(FAST_LEVEL_3,CLOSE);
//								mov_rot_left(FAST_LEVEL_3,CLOSE);
								mov_rot_left(FAST_LEVEL_2,FAR);
								mov_rot_left(FAST_LEVEL_2,FAR);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;
//							mov_fwd_5cm(12,FAST_LEVEL_3);break;
//							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
//							Get_IR();
						}

						OVERRIDE=1;
					}

				}

			//KONDISI ROBOT DEKAT DENGAN DINDING
			else if ( Ping[PING_ASKEW_RIGHT]<PID_F_R.set_point )
//			else if ( SHARP[SHARP_RIGHT]<PID_F_R.set_point )
//			else if ( Ping[PING_RIGHT]<PID_F_R.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
					if (PID_F_R.pid_value[0]>13)
					{
						WINDUP_LEFT_COUNTER++;
						PID_F_R.pid_value[0]=13; //WINDUP

					}

					if (Ping[PING_FRONT]<=16)
//					if (Ping[PING_FRONT]<=20)
					{
//						mov_rot_left(FAST_LEVEL_3, CLOSE);
//						mov_rot_left(FAST_LEVEL_3, CLOSE);
						mov_rot_left(FAST_LEVEL_2,FAR);
						mov_rot_left(FAST_LEVEL_2,FAR);
//						if (Ping[PING_RIGHT]<=20)
//						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
//						if (Ping[PING_RIGHT]>20)
//						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_LEFT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>=16)
//							while(Ping[PING_FRONT]>=20)
							{
//								mov_fwd_5cm(5,FAST_LEVEL_3);
								mov_fwd_5cm(5,FAST_LEVEL_3);
								GetBumper();
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_RIGHT]>=16)
//							while(Ping[PING_RIGHT]>=10)
							{
//								mov_rot_left(FAST_LEVEL_3,CLOSE);
//								mov_rot_left(FAST_LEVEL_3,CLOSE);
								mov_rot_left(FAST_LEVEL_2,FAR);
								mov_rot_left(FAST_LEVEL_2,FAR);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_LEFT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

//							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
						}

						OVERRIDE=1;
					}

				}
		}
	}

}

void follow_left_counter(int limit)
{
	int counter;
	//int limit=15;
	for(counter=1;counter<=limit;counter++)
	{
		Evade_Wall();
		Cat_Avoider();

		if (Ping[PING_FRONT]<=14)
		{
			Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//			mov_rot_right(FAST_LEVEL_3, CLOSE);
//			mov_rot_right(FAST_LEVEL_3, CLOSE);
			mov_rot_right(FAST_LEVEL_3, FAR);
			mov_rot_right(FAST_LEVEL_3, FAR);

			GetBumper();
			while(BUMPER[RIGHT]==ACTIVE)
			{
				BW_Buzz(1);
				mov_bwd_3cm(6,FAST_LEVEL_3);
				mov_rot_right(FAST, FAR);
				mov_rot_right(FAST, FAR);
//				mov_rot_left(FAST_LEVEL_3, CLOSE);
				GetBumper();
				if(BUMPER[RIGHT]==INACTIVE)break;
			}
			GetBumper();
			while(BUMPER[LEFT]==ACTIVE)
			{
				BW_Buzz(1);
				mov_bwd_3cm(6,FAST_LEVEL_3);
				mov_rot_right(FAST, FAR);
				mov_rot_right(FAST, FAR);
//				mov_rot_right(FAST_LEVEL_3, CLOSE);
				GetBumper();
				if(BUMPER[LEFT]==INACTIVE)break;
			}
//			if (Ping[PING_LEFT]>=20)
//			{
//				Sendto_PC(USART1,"BW ROTATE LEFT \r");
//				mov_rot_left(FAST_LEVEL_3, CLOSE);
//				mov_rot_left(FAST_LEVEL_3, CLOSE);
//			}
//
//			if (Ping[PING_LEFT]<20)
//			{
//				Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//				mov_rot_right(FAST_LEVEL_3, CLOSE);
//				mov_rot_right(FAST_LEVEL_3, CLOSE);
//			}
		}
		else
		{
			PID_follow_left_counter();
		}
	}



}

/* func      : void PID_follow_left_counter(void)
 * brief     : Wall following using PID controller left rule
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Monday, October 19th 2015)
 * Revised BY: Ver.2 Ryan (Friday, April 16th 2016)
 * 					* Added Follow overflow limit
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */
void PID_follow_left_counter(void)
{
	//int limit= *COMMAND_LOOP;
	int OVERRIDE=0;

	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;


	PID_Calc_LeftRule();

	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
			if ( (Ping[PING_ASKEW_LEFT]<=PID_F_L.set_point_upper) && (Ping[PING_ASKEW_LEFT]>=PID_F_L.set_point_lower) )
//			if ( (SHARP[SHARP_LEFT]<=PID_F_L.set_point_upper) && (SHARP[SHARP_LEFT]>=PID_F_L.set_point_lower) )
				{
					if (Ping[PING_FRONT]<=14)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
						mov_rot_right(FAST_LEVEL_3, FAR);
						mov_rot_right(FAST_LEVEL_3, FAR);

						GetBumper();
						while(BUMPER[RIGHT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_3);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, FAR);
			//				mov_rot_left(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[RIGHT]==INACTIVE)break;
						}
						GetBumper();
						while(BUMPER[LEFT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_3);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, FAR);
			//				mov_rot_right(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[LEFT]==INACTIVE)break;
						}
//						if (Ping[PING_LEFT]>=20)
//						{
//
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
//						if (Ping[PING_LEFT]<20)
//						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

						Sendto_PC(USART1,"BW FORWARD \r");
//						mov_fwd_5cm(5, FAST_LEVEL_3);
						mov_fwd_5cm(5, FAST_LEVEL_3);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT DEKAT DARI DINDING
			else if ( Ping[PING_ASKEW_LEFT]<PID_F_L.set_point )
//			else if ( SHARP[SHARP_LEFT]<PID_F_L.set_point )
				{
					//RESET WINDUP RIGHT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
					if (PID_F_L.pid_value[0]>13)
					{
						WINDUP_RIGHT_COUNTER++;
						PID_F_L.pid_value[0]=13; //WINDUP
					}

					if (Ping[PING_FRONT]<=14)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
						mov_rot_right(FAST_LEVEL_3, FAR);
						mov_rot_right(FAST_LEVEL_3, FAR);

						GetBumper();
						while(BUMPER[RIGHT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_3);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, FAR);
			//				mov_rot_left(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[RIGHT]==INACTIVE)break;
						}
						GetBumper();
						while(BUMPER[LEFT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_3);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, FAR);
			//				mov_rot_right(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[LEFT]==INACTIVE)break;
						}
//						if (Ping[PING_LEFT]>=20)
//						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
//						if (Ping[PING_LEFT]<20)
//						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>=14)
							{
//								mov_fwd_5cm(5,FAST_LEVEL_3);
								mov_fwd_5cm(5,FAST_LEVEL_3);
								GetBumper();
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_LEFT]>=15)
							{
//								mov_rot_right(FAST_LEVEL_3,CLOSE);
//								mov_rot_right(FAST_LEVEL_3,CLOSE);
								mov_rot_right(FAST_LEVEL_3, FAR);
								mov_rot_right(FAST_LEVEL_3, FAR);

								GetBumper();
								while(BUMPER[RIGHT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_3);
									mov_rot_right(FAST, FAR);
									mov_rot_right(FAST, FAR);
					//				mov_rot_left(FAST_LEVEL_3, CLOSE);
									GetBumper();
									if(BUMPER[RIGHT]==INACTIVE)break;
								}
								GetBumper();
								while(BUMPER[LEFT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_3);
									mov_rot_right(FAST, FAR);
									mov_rot_right(FAST, FAR);
					//				mov_rot_right(FAST_LEVEL_3, CLOSE);
									GetBumper();
									if(BUMPER[LEFT]==INACTIVE)break;
								}
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

//							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);
							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);

							GetBumper();
							while(BUMPER[RIGHT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_3);
								mov_rot_right(FAST, FAR);
								mov_rot_right(FAST, FAR);
				//				mov_rot_left(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[RIGHT]==INACTIVE)break;
							}
							GetBumper();
							while(BUMPER[LEFT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_3);
								mov_rot_right(FAST, FAR);
								mov_rot_right(FAST, FAR);
				//				mov_rot_right(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[LEFT]==INACTIVE)break;
							}
						}

						OVERRIDE=1;
					}

				}

			//KONDISI ROBOT JAUH DENGAN DINDING
			else if ( Ping[PING_ASKEW_LEFT]>PID_F_L.set_point )
//			else if ( SHARP[SHARP_LEFT]>PID_F_L.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
					if (PID_F_L.pid_value[0]>13)
					{
						WINDUP_LEFT_COUNTER++;
						PID_F_L.pid_value[0]=13;
					}

					if (Ping[PING_FRONT]<=14)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
						mov_rot_right(FAST_LEVEL_3, FAR);
						mov_rot_right(FAST_LEVEL_3, FAR);

						GetBumper();
						while(BUMPER[RIGHT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_3);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, FAR);
			//				mov_rot_left(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[RIGHT]==INACTIVE)break;
						}
						GetBumper();
						while(BUMPER[LEFT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_3);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, FAR);
			//				mov_rot_right(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[LEFT]==INACTIVE)break;
						}
//						if (Ping[PING_LEFT]>=20)
//						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
//						if (Ping[PING_LEFT]<20)
//						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_LEFT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>=14)
							{
//								mov_fwd_5cm(5,FAST_LEVEL_3);
								mov_fwd_5cm(5,FAST_LEVEL_3);
								GetBumper();
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_LEFT]>=15)
							{
//								mov_rot_right(FAST_LEVEL_3,CLOSE);
//								mov_rot_right(FAST_LEVEL_3,CLOSE);
								mov_rot_right(FAST_LEVEL_2,FAR);
								mov_rot_right(FAST_LEVEL_2,FAR);

								GetBumper();
								while(BUMPER[RIGHT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_3);
									mov_rot_right(FAST, FAR);
									mov_rot_right(FAST, FAR);
					//				mov_rot_left(FAST_LEVEL_3, CLOSE);
									GetBumper();
									if(BUMPER[RIGHT]==INACTIVE)break;
								}
								GetBumper();
								while(BUMPER[LEFT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_3);
									mov_rot_right(FAST, FAR);
									mov_rot_right(FAST, FAR);
					//				mov_rot_right(FAST_LEVEL_3, CLOSE);
									GetBumper();
									if(BUMPER[LEFT]==INACTIVE)break;
								}
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_LEFT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}
						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

//							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);
							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);

							GetBumper();
							while(BUMPER[RIGHT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_3);
								mov_rot_right(FAST, FAR);
								mov_rot_right(FAST, FAR);
				//				mov_rot_left(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[RIGHT]==INACTIVE)break;
							}
							GetBumper();
							while(BUMPER[LEFT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_3);
								mov_rot_right(FAST, FAR);
								mov_rot_right(FAST, FAR);
				//				mov_rot_right(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[LEFT]==INACTIVE)break;
							}
						}

						OVERRIDE=1;
					}

				}
		}
	}

}

void curve_right_counter(int SPEED, int STEP, float *COMMAND_LOOP)
{
	Sendto_PC(USART1,"BW Curve Right Counter \r");
	generate_movement_data(0,STEP,9);
	delay_ms(50);

	unsigned int DELTA_FL=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_FR=10+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_ML=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_MR=10+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_RL=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_RR=10+ (1 * *COMMAND_LOOP);

//	Evade_Wall();
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();

	//1
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,90+beta[3],10,leg-3);
	inv_kine(middle_left,90+beta[1],10,leg-3);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90+beta[5],10,leg-3);
	delay_ms(SPEED);

//	Evade_Wall();
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();


	//2
	inv_kine(front_left,90+beta[0]+DELTA_FL,7,leg);
	inv_kine(front_right,90-beta[3]+DELTA_FR,10,leg-3);
	inv_kine(middle_left,90-beta[1]-DELTA_ML,10,leg-3);
	inv_kine(middle_right,90+beta[4]-DELTA_MR,7,leg);
	inv_kine(rear_left,90+beta[2]+DELTA_RL,7,leg);
	inv_kine(rear_right,90-beta[5]+DELTA_RR,10,leg-3);
	delay_ms(SPEED);

//	Evade_Wall();
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();

	//3
	inv_kine(front_left,90+beta[0]+DELTA_FL,7,leg);
	inv_kine(front_right,90-beta[3]+DELTA_FR,7,leg);
	inv_kine(middle_left,90-beta[1]-DELTA_ML,7,leg);
	inv_kine(middle_right,90+beta[4]-DELTA_MR,7,leg);
	inv_kine(rear_left,90+beta[2]+DELTA_RL,7,leg);
	inv_kine(rear_right,90-beta[5]+DELTA_RR,7,leg);
	delay_ms(SPEED);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();
	//4
	inv_kine(front_left,90+beta[0]+DELTA_FL,10,leg-3);
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90+beta[4]-DELTA_MR,10.5,leg-3);
	inv_kine(rear_left,90+beta[2]+DELTA_RL,10,leg-3);
	inv_kine(rear_right,90,7,leg);
	delay_ms(SPEED);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();

	//5
	inv_kine(front_left,90-beta[0]-DELTA_FL,10,leg-3);
	inv_kine(front_right,90+beta[3]-DELTA_FR,7,leg);
	inv_kine(middle_left,90+beta[1]+DELTA_ML,7,leg);
	inv_kine(middle_right,90-beta[4]+DELTA_MR,10.5,leg-3);
	inv_kine(rear_left,90-beta[2]-DELTA_RL,10,leg-3);
	inv_kine(rear_right,90+beta[5]-DELTA_RR,7,leg);
	delay_ms(SPEED);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();
	//6
	inv_kine(front_left,90-beta[0]-DELTA_FL,7,leg);
	inv_kine(front_right,90+beta[3]-DELTA_FR,7,leg);
	inv_kine(middle_left,90+beta[1]+DELTA_ML,7,leg);
	inv_kine(middle_right,90-beta[4]+DELTA_MR,7,leg);
	inv_kine(rear_left,90-beta[2]-DELTA_RL,7,leg);
	inv_kine(rear_right,90+beta[5]-DELTA_RR,7,leg);
	delay_ms(SPEED);
}

void curve_right_counter_reverse(int SPEED, int STEP, float *COMMAND_LOOP)
{
	Sendto_PC(USART1,"BW Curve Right Counter \r");
	generate_movement_data(0,-STEP,9);
	delay_ms(50);

	unsigned int DELTA_FL=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_FR=10+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_ML=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_MR=10+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_RL=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_RR=10+ (1 * *COMMAND_LOOP);

//	Evade_Wall();
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();

	//1
	inv_kine(front_left,90+beta[5],10,leg-3);
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90+beta[1],10,leg-3);
	inv_kine(rear_left,90+beta[3],10,leg-3);
	inv_kine(rear_right,90,7,leg);
	delay_ms(SPEED);

//	Evade_Wall();
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();


	//2
	inv_kine(front_left,90-beta[5]+DELTA_RR,10,leg-3);
	inv_kine(front_right,90+beta[2]+DELTA_RL,7,leg);
	inv_kine(middle_left,90+beta[4]-DELTA_MR,7,leg);
	inv_kine(middle_right,90-beta[1]-DELTA_ML,10,leg-3);
	inv_kine(rear_left,90-beta[3]+DELTA_FR,10,leg-3);
	inv_kine(rear_right,90+beta[0]+DELTA_FL,7,leg);
	delay_ms(SPEED);

//	Evade_Wall();
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();

	//3
	inv_kine(front_left,90-beta[5]+DELTA_RR,7,leg);
	inv_kine(front_right,90+beta[2]+DELTA_RL,7,leg);
	inv_kine(middle_left,90+beta[4]-DELTA_MR,7,leg);
	inv_kine(middle_right,90-beta[1]-DELTA_ML,7,leg);
	inv_kine(rear_left,90-beta[3]+DELTA_FR,7,leg);
	inv_kine(rear_right,90+beta[0]+DELTA_FL,7,leg);
	delay_ms(SPEED);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();
	//4
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,90+beta[2]+DELTA_RL,10,leg-3);
	inv_kine(middle_left,90+beta[4]-DELTA_MR,10.5,leg-3);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90+beta[0]+DELTA_FL,10,leg-3);
	delay_ms(SPEED);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();

	//5
	inv_kine(front_left,90+beta[5]-DELTA_RR,7,leg);
	inv_kine(front_right,90-beta[2]-DELTA_RL,10,leg-3);
	inv_kine(middle_left,90-beta[4]+DELTA_MR,10.5,leg-3);
	inv_kine(middle_right,90+beta[1]+DELTA_ML,7,leg);
	inv_kine(rear_left,90+beta[3]-DELTA_FR,7,leg);
	inv_kine(rear_right,90-beta[0]-DELTA_FL,10,leg-3);
	delay_ms(SPEED);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();
	//6
	inv_kine(front_left,90+beta[5]-DELTA_RR,7,leg);
	inv_kine(front_right,90-beta[2]-DELTA_RL,7,leg);
	inv_kine(middle_left,90-beta[4]+DELTA_MR,7,leg);
	inv_kine(middle_right,90+beta[1]+DELTA_ML,7,leg);
	inv_kine(rear_left,90+beta[3]-DELTA_FR,7,leg);
	inv_kine(rear_right,90-beta[0]-DELTA_FL,7,leg);
	delay_ms(SPEED);
}

void curve_left_counter(int SPEED, int STEP, float *COMMAND_LOOP)
{
	Sendto_PC(USART1,"BW Curve Left Counter \r");
	generate_movement_data(0,STEP,9);
	delay_ms(50);

	unsigned int DELTA_FL=5+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_FR=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_ML=5+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_MR=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_RL=5+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_RR=15+ (1 * *COMMAND_LOOP);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();
	//1
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,90+beta[3]+DELTA_FR,10,leg-3);
	inv_kine(middle_left,90+beta[1]-DELTA_ML,10,leg-3);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90+beta[5]+DELTA_RR,10,leg-3);
	delay_ms(SPEED);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();
	//2
	inv_kine(front_left,90+beta[0]-DELTA_FL,7,leg);
	inv_kine(front_right,90-beta[3]-DELTA_FR,10,leg-3);
	inv_kine(middle_left,90-beta[1]+DELTA_ML,10,leg-3);
	inv_kine(middle_right,90+beta[4]+DELTA_MR,7,leg);
	inv_kine(rear_left,90+beta[2]-DELTA_RL,7,leg);
	inv_kine(rear_right,90-beta[5]-DELTA_RR,10,leg-3);
	delay_ms(SPEED);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();
	//3
	inv_kine(front_left,90+beta[0]-DELTA_FL,7,leg);
	inv_kine(front_right,90-beta[3]-DELTA_FR,7,leg);
	inv_kine(middle_left,90-beta[1]+DELTA_ML,7,leg);
	inv_kine(middle_right,90+beta[4]+DELTA_MR,7,leg);
	inv_kine(rear_left,90+beta[2]-DELTA_RL,7,leg);
	inv_kine(rear_right,90-beta[5]-DELTA_RR,7,leg);
	delay_ms(SPEED);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();
	//4
	inv_kine(front_left,90+beta[0]-DELTA_FL,10,leg-3);
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90+beta[4]+DELTA_MR,10.5,leg-3);
	inv_kine(rear_left,90+beta[2]-DELTA_RL,10,leg-3);
	inv_kine(rear_right,90,7,leg);
	delay_ms(SPEED);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();
	//5
	inv_kine(front_left,90-beta[0]+DELTA_FL,10,leg-3);
	inv_kine(front_right,90+beta[3]+DELTA_FR,7,leg);
	inv_kine(middle_left,90+beta[1]-DELTA_ML,7,leg);
	inv_kine(middle_right,90-beta[4]-DELTA_MR,10.5,leg-3);
	inv_kine(rear_left,90-beta[2]+DELTA_RL,10,leg-3);
	inv_kine(rear_right,90+beta[5]+DELTA_RR,7,leg);
	delay_ms(SPEED);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();
	//6
	inv_kine(front_left,90-beta[0]+DELTA_FL,7,leg);
	inv_kine(front_right,90+beta[3]+DELTA_FR,7,leg);
	inv_kine(middle_left,90+beta[1]-DELTA_ML,7,leg);
	inv_kine(middle_right,90-beta[4]-DELTA_MR,7,leg);
	inv_kine(rear_left,90-beta[2]+DELTA_RL,7,leg);
	inv_kine(rear_right,90+beta[5]+DELTA_RR,7,leg);
	delay_ms(SPEED);
}

void curve_left_counter_reverse(int SPEED, int STEP, float *COMMAND_LOOP)
{
	Sendto_PC(USART1,"BW Curve Left Counter \r");
	generate_movement_data(0,-STEP,9);
	delay_ms(50);

	unsigned int DELTA_FL=5+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_FR=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_ML=5+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_MR=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_RL=5+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_RR=15+ (1 * *COMMAND_LOOP);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();
	//1
	inv_kine(front_left,90+beta[5]+DELTA_RR,10,leg-3);
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90+beta[1]-DELTA_ML,10,leg-3);
	inv_kine(rear_left,90+beta[3]+DELTA_FR,10,leg-3);
	inv_kine(rear_right,90,7,leg);
	delay_ms(SPEED);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();
	//2
	inv_kine(front_left,90-beta[5]-DELTA_RR,10,leg-3);
	inv_kine(front_right,90+beta[2]-DELTA_RL,7,leg);
	inv_kine(middle_left,90+beta[4]+DELTA_MR,7,leg);
	inv_kine(middle_right,90-beta[1]+DELTA_ML,10,leg-3);
	inv_kine(rear_left,90-beta[3]-DELTA_FR,10,leg-3);
	inv_kine(rear_right,90+beta[0]-DELTA_FL,7,leg);
	delay_ms(SPEED);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();
	//3
	inv_kine(front_left,90-beta[5]-DELTA_RR,7,leg);
	inv_kine(front_right,90+beta[2]-DELTA_RL,7,leg);
	inv_kine(middle_left,90+beta[4]+DELTA_MR,7,leg);
	inv_kine(middle_right,90-beta[1]+DELTA_ML,7,leg);
	inv_kine(rear_left,90-beta[3]-DELTA_FR,7,leg);
	inv_kine(rear_right,90+beta[0]-DELTA_FL,7,leg);
	delay_ms(SPEED);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();
	//4
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,90+beta[2]-DELTA_RL,10,leg-3);
	inv_kine(middle_left,90+beta[4]+DELTA_MR,10.5,leg-3);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90+beta[0]-DELTA_FL,10,leg-3);
	delay_ms(SPEED);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();
	//5
	inv_kine(front_left,90+beta[5]+DELTA_RR,7,leg);
	inv_kine(front_right,90-beta[2]+DELTA_RL,10,leg-3);
	inv_kine(middle_left,90-beta[4]-DELTA_MR,10.5,leg-3);
	inv_kine(middle_right,90+beta[1]-DELTA_ML,7,leg);
	inv_kine(rear_left,90+beta[3]+DELTA_FR,7,leg);
	inv_kine(rear_right,90-beta[0]+DELTA_FL,10,leg-3);
	delay_ms(SPEED);

//	Evade_Wall();

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	if(TCS3200_SLV_DATA[2]==TRACER_ACTIVE) TRACER_STAT= TRACER_ACTIVE;
	TCSlave_Check();
	TCSlave_Check();
	TCSlave_Check();
	//6
	inv_kine(front_left,90+beta[5]+DELTA_RR,7,leg);
	inv_kine(front_right,90-beta[2]+DELTA_RL,7,leg);
	inv_kine(middle_left,90-beta[4]-DELTA_MR,7,leg);
	inv_kine(middle_right,90+beta[1]-DELTA_ML,7,leg);
	inv_kine(rear_left,90+beta[3]+DELTA_FR,7,leg);
	inv_kine(rear_right,90-beta[0]+DELTA_FL,7,leg);
	delay_ms(SPEED);
}

/*==============================================================================================
							NEW FEATURES FROM BW Ver.1.0
===============================================================================================*/

void FlameSense_PID_Init(void)
{
	//BW PID WALL FOLLOWING RIGHT RULE
	PID_FLAME.P[0]=0;
	PID_FLAME.P[1]=0;
	PID_FLAME.P[2]=0;
	PID_FLAME.I[0]=0;
	PID_FLAME.I[1]=0;
	PID_FLAME.I[2]=0;
	PID_FLAME.D[0]=0;
	PID_FLAME.D[1]=0;
	PID_FLAME.D[2]=0;

	PID_FLAME.Kp=2;
	PID_FLAME.Ki=0;
	PID_FLAME.Kd=0;

	PID_FLAME.Ts=1;

//	PID_FLAME.set_point_upper=3;
//	PID_FLAME.set_point_lower=3;
	PID_FLAME.set_point=3;

	PID_FLAME.error[0]=0;
	PID_FLAME.error[1]=0;
	PID_FLAME.error[2]=0;
	PID_FLAME.pid_value[0]=0;
	PID_FLAME.pid_value[1]=0;
	PID_FLAME.pid_value[2]=0;
}

/*
 * func      : void PID_Calc(void)
 * brief     : PID Controller Calculations
 * param     : N/A
 * Written By: Ryan
 * Ver       : 1
 * Programmer's Note: PID Formula rewritten with guidance from KRPAI Senior, Desta.
 * 					  This function should be called everytime PID function executed
 */
void FlameSense_PID_Calc(void)
{

	/*
	 * Update Nilai Variable PID & Set-Point Error
	 */
	PID_FLAME.pid_value[2]=PID_FLAME.pid_value[1];
	PID_FLAME.pid_value[1]=PID_FLAME.pid_value[0];

	PID_FLAME.error[2]=PID_FLAME.error[1];
	PID_FLAME.error[1]=PID_FLAME.error[0];

	if (FlameSense[0]==PID_FLAME.set_point) {PID_FLAME.error[0]=0;}


	else if ( FlameSense[0] > PID_FLAME.set_point)
		{
			PID_FLAME.error[0] = FlameSense[0] - PID_FLAME.set_point;
		}

	else if (FlameSense[0] < PID_FLAME.set_point)
		{
			PID_FLAME.error[0] = PID_FLAME.set_point - FlameSense[0];
		}

	/*
	 * PID FORMULA
	 */
	PID_FLAME.P[2]= PID_FLAME.error[0]-PID_FLAME.error[2];
	PID_FLAME.P[1]= PID_FLAME.Kp;
	PID_FLAME.P[0]= PID_FLAME.P[1]*PID_FLAME.P[2]; //Proportional Controller

	PID_FLAME.I[2]= PID_FLAME.Ki*PID_FLAME.Ts/2;
	PID_FLAME.I[1]= PID_FLAME.error[0]+(2*PID_FLAME.error[1])+PID_FLAME.error[2];
	PID_FLAME.I[0]= PID_FLAME.I[2]*PID_FLAME.I[1]; //Integral Controller


	PID_FLAME.D[2]= 2*PID_FLAME.Kd/PID_FLAME.Ts;
	PID_FLAME.D[1]= PID_FLAME.error[0]-(2*PID_FLAME.error[1])+PID_FLAME.error[2];
	PID_FLAME.D[0]= PID_FLAME.D[2]*PID_FLAME.D[1]; //Derivative Controller

//	PID_FLAME.I= ( (PID_FLAME.Ki*PID_FLAME.Ts/2)*(PID_FLAME.error[0]+(2*PID_FLAME.error[1])+PID_FLAME.error[2]) );
//	PID_FLAME.D= ( (2*PID_FLAME.Kd/PID_FLAME.Ts)*(PID_FLAME.error[0]-(2*PID_FLAME.error[1])+PID_FLAME.error[2]));

	PID_FLAME.pid_value[0]= PID_FLAME.pid_value[2] + PID_FLAME.P[0] + PID_FLAME.I[0] + PID_FLAME.D[0];
}

void FlameTracking(void)
{

	Get_UV();
	UV_Lock=1;

	while(UV_Lock==1)
	{
//		FlameSense[1]=FlameSense[0];


		Send_FlameSense();

		PID_FlameTracking();
	}

}

/* func      : void PID_FlameTracking(void)
 * brief     : Wall following using PID controller until BW detects TRACER LINE
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Monday, October 19th 2015)
 * Revised BY: N/A
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */
void PID_FlameTracking(void)
{
	float DUMMY_PIDVALUE=1;
	//int limit= *COMMAND_LOOP;
	//OVERCOMING BLIND SPOTS
	if(FlameSense[0]==0) FlameSense[0]=10;
	Sendto_PC(USART1,"FlameSense[0]: %d \r",FlameSense[0]);

	FlameSense_PID_Calc();
	Sendto_PC(USART1,"PID Value : %d \r",(int)PID_FLAME.pid_value[0]);

	//KONDISI ROBOT SESUAI
	if ( FlameSense[0]==PID_FLAME.set_point)
	{
//		mov_static();
		BW_Buzz(3);
		while(Ping[PING_FRONT]>=20)
		{
//			mov_fwd_5cm(5,FAST_LEVEL_3);
			mov_fwd_5cm(5,FAST_LEVEL_3);
		}

		BW_FlameScanning();


	}

	else if(FlameSense[0]==10)
	{

		if( (FlameSense[1]==1) )
		{
//			Rot_Left_PID(FAST_LEVEL_3, CLOSE, &DUMMY_PIDVALUE);
			Rot_Left_PID(FAST_LEVEL_3, CLOSE, &DUMMY_PIDVALUE);
			Sendto_PC(USART1,"WINDUP ROT LEFT NARROW ACTIVATED \r");
		}
		else if( (FlameSense[1]==5) )
		{
//			Rot_Right_PID(FAST_LEVEL_3, CLOSE, &DUMMY_PIDVALUE);
			Rot_Right_PID(FAST_LEVEL_3, CLOSE, &DUMMY_PIDVALUE);
			Sendto_PC(USART1,"WINDUP ROT RIGHT NARROW ACTIVATED \r");
		}

		else if ( FlameSense[1] > PID_FLAME.set_point )
		{
//			Rot_Right_PID(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
			Rot_Right_PID(FAST_LEVEL_3, CLOSE, &DUMMY_PIDVALUE);
			Sendto_PC(USART1,"WINDUP ROT RIGHT CLOSE REACH ACTIVATED \r");
		}

		else if ( FlameSense[1] < PID_FLAME.set_point )
		{
//			Rot_Left_PID(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
			Rot_Left_PID(FAST_LEVEL_3, CLOSE, &DUMMY_PIDVALUE);
			Sendto_PC(USART1,"WINDUP ROT LEFT CLOSE REACH ACTIVATED \r");
		}



	}
	//KONDISI ROBOT JAUH DARI DINDING
	else if ( FlameSense[0] > PID_FLAME.set_point )
	{
//		if (PID_FLAME.pid_value[0]>5) PID_FLAME.pid_value[0]=5; //WINDUP


//		Rot_Right_PID(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
		Rot_Right_PID(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
		FlameSense[1]=5;

	}

	//KONDISI ROBOT DEKAT DENGAN DINDING
	else if ( FlameSense[0] < PID_FLAME.set_point )
	{
//		if (PID_F_R.pid_value[0]>5) PID_F_R.pid_value[0]=5; //WINDUP

		FlameSense[1]=1;
//		Rot_Left_PID(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
		Rot_Left_PID(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);

	}

}

void Rot_Right_PID(int SPEED, int STEP, float *COMMAND_LOOP)
{
	Sendto_PC(USART1,"BW Rotate Right PID \r");
	generate_movement_data(0,STEP,9);
	delay_ms(50);

	unsigned int DELTA_FL= (2 * *COMMAND_LOOP);
	unsigned int DELTA_FR= (2 * *COMMAND_LOOP);
	unsigned int DELTA_ML= (2 * *COMMAND_LOOP);
	unsigned int DELTA_MR= (2 * *COMMAND_LOOP);
	unsigned int DELTA_RL= (2 * *COMMAND_LOOP);
	unsigned int DELTA_RR= (2 * *COMMAND_LOOP);

	//gait_mode(ROTATE_RIGHT,SPEED);
	//1
	inv_kine(front_left,90+beta[0]+DELTA_FL,7,leg); //mundur
	inv_kine(front_right,90+beta[3]+DELTA_FR,10,leg-3); //mundur
	inv_kine(middle_left,90-beta[1]-DELTA_ML,10,leg-3); //maju
	inv_kine(middle_right,90-beta[4]-DELTA_MR,7,leg); //maju
	inv_kine(rear_left,90+beta[2]+DELTA_RL,7,leg); //mundur
	inv_kine(rear_right,90+beta[5]+DELTA_RR,10,leg-3); //mundur
	delay_ms(SPEED);

	//2
	inv_kine(front_left,90+beta[0]+DELTA_FL,7,leg); //mundur
	inv_kine(front_right,90+beta[3]+DELTA_FR,7,leg); //mundur
	inv_kine(middle_left,90-beta[1]-DELTA_ML,7,leg); //maju
	inv_kine(middle_right,90-beta[4]-DELTA_MR,7,leg); //maju
	inv_kine(rear_left,90+beta[2]+DELTA_RL,7,leg); //mundur
	inv_kine(rear_right,90+beta[5]+DELTA_RR,7,leg); //mundur
	delay_ms(SPEED);

	//3
	inv_kine(front_left,90-beta[0]-DELTA_FL,10,leg-3); //maju
	inv_kine(front_right,90-beta[3]-DELTA_FR,7,leg); //maju
	inv_kine(middle_left,90+beta[1]+DELTA_ML,7,leg); //mundur
	inv_kine(middle_right,90+beta[4]+DELTA_MR,10.5,leg-3); //mundur
	inv_kine(rear_left,90-beta[2]-DELTA_RL,10,leg-3); //maju
	inv_kine(rear_right,90-beta[5]-DELTA_RR,7,leg); //maju
	delay_ms(SPEED);

	//4
	inv_kine(front_left,90-beta[0]-DELTA_FL,7,leg); //maju
	inv_kine(front_right,90-beta[3]-DELTA_FR,7,leg); //maju
	inv_kine(middle_left,90+beta[1]+DELTA_ML,7,leg); //mundur
	inv_kine(middle_right,90+beta[4]+DELTA_MR,7,leg); //mundur
	inv_kine(rear_left,90-beta[2]-DELTA_RL,7,leg); //maju
	inv_kine(rear_right,90-beta[5]-DELTA_RR,7,leg); //maju
	delay_ms(SPEED);
}

void Rot_Left_PID(int SPEED, int STEP, float *COMMAND_LOOP)
{
	Sendto_PC(USART1,"BW Rotate Left PID \r");
	generate_movement_data(0,STEP,9);
	delay_ms(50);

	unsigned int DELTA_FL= (2 * *COMMAND_LOOP);
	unsigned int DELTA_FR= (2 * *COMMAND_LOOP);
	unsigned int DELTA_ML= (2 * *COMMAND_LOOP);
	unsigned int DELTA_MR= (2 * *COMMAND_LOOP);
	unsigned int DELTA_RL= (2 * *COMMAND_LOOP);
	unsigned int DELTA_RR= (2 * *COMMAND_LOOP);

	//gait_mode(ROTATE_LEFT, SPEED);
	//1
	inv_kine(front_left,90-beta[0]-DELTA_FL,7,leg); //maju /
	inv_kine(front_right,90-beta[3]-DELTA_FR,10,leg-3); //maju
	inv_kine(middle_left,90+beta[1]+DELTA_ML,10,leg-3); //mundur /
	inv_kine(middle_right,90+beta[4]+DELTA_MR,7,leg); //mundur /
	inv_kine(rear_left,90-beta[2]-DELTA_RL,7,leg); //maju /
	inv_kine(rear_right,90-beta[5]-DELTA_RR,10,leg-3); //maju /
	delay_ms(SPEED);

	//2
	inv_kine(front_left,90-beta[0]-DELTA_FL,7,leg); //maju /
	inv_kine(front_right,90-beta[3]-DELTA_FR,7,leg); //maju /
	inv_kine(middle_left,90+beta[1]+DELTA_ML,7,leg); //mundur /
	inv_kine(middle_right,90+beta[4]+DELTA_MR,7,leg); //mundur /
	inv_kine(rear_left,90-beta[2]-DELTA_RL,7,leg); //maju /
	inv_kine(rear_right,90-beta[5]-DELTA_RR,7,leg); //maju /
	delay_ms(SPEED);

	//3
	inv_kine(front_left,90+beta[0]+DELTA_FL,10,leg-3); //mundur /
	inv_kine(front_right,90+beta[3]+DELTA_FR,7,leg); //mundur /
	inv_kine(middle_left,90-beta[1]-DELTA_ML,7,leg); //maju /
	inv_kine(middle_right,90-beta[4]-DELTA_MR,10.5,leg-3); //maju /
	inv_kine(rear_left,90+beta[2]+DELTA_RL,10,leg-3); //mundur /
	inv_kine(rear_right,90+beta[5]+DELTA_RR,7,leg); //mundur /
	delay_ms(SPEED);

	//4
	inv_kine(front_left,90+beta[0]+DELTA_FL,7,leg); //mundur /
	inv_kine(front_right,90+beta[3]+DELTA_FR,7,leg); //mundur /
	inv_kine(middle_left,90-beta[1]-DELTA_ML,7,leg); //maju /
	inv_kine(middle_right,90-beta[4]-DELTA_MR,7,leg); //maju /
	inv_kine(rear_left,90+beta[2]+DELTA_RL,7,leg); //mundur /
	inv_kine(rear_right,90+beta[5]+DELTA_RR,7,leg); //mundur /
	delay_ms(SPEED);


}
void BW_FlameSense(void)
{
//	while(1)
//	{
//		Send_FlameSense[0]();
//		if(FlameSense[0]<4) mov_rot_right(FAST_LEVEL_3,CLOSE);
//		else if(FlameSense[0]>4) mov_rot_left(FAST_LEVEL_3,CLOSE);
//		else if(FlameSense[0]==4) while(1){mov_static();}
//	}

	while(1)
	{
		Send_FlameSense();
		if( (FlameSense[0]<4) && (FlameSense[0]>0) ) mov_rot_left(FAST_LEVEL_3,CLOSE);
		else if(FlameSense[0]>4) mov_rot_right(FAST_LEVEL_3,CLOSE);
		else if(FlameSense[0]==0) mov_rot_right(FAST_LEVEL_3,CLOSE);
		else if(FlameSense[0]==4) {mov_static();}
	}
}


void BW_FlameScanning(void)
{

	static int right=90,left=90;

	generate_movement_data(0,0,9);
	delay_ms(50);

//	while(FlameSense[0]!=3)
//	{
	if(FlameSense[0]==3){BW_Buzz(2);BW_FlameExtinguish(left,right);}

		while(right>=10&&left<=170&&FlameSense[0]!=3)
		{
			Send_FlameSense();
			if(FlameSense[0]==3){BW_Buzz(2);BW_FlameExtinguish(left,right);}
			inv_kine(front_left,left,7,leg);
			inv_kine(front_right,right,7,leg);
			inv_kine(middle_left,left,7,leg);
			inv_kine(middle_right,right,7,leg);
			inv_kine(rear_left,left,7,leg);
			inv_kine(rear_right,right,7,leg);
			delay_ms(13);
			right-=2;
			left+=2;
		}
		delay_ms(50);

		if(FlameSense[0]==3){BW_Buzz(2);BW_FlameExtinguish(left,right);}
		while(right<=90&&left>=90&&FlameSense[0]!=3)
		{
			Send_FlameSense();
			if(FlameSense[0]==3){BW_Buzz(2);BW_FlameExtinguish(left,right);}
			inv_kine(front_left,left,7,leg);
			inv_kine(front_right,right,7,leg);
			inv_kine(middle_left,left,7,leg);
			inv_kine(middle_right,right,7,leg);
			inv_kine(rear_left,left,7,leg);
			inv_kine(rear_right,right,7,leg);
			delay_ms(13);
			right+=2;
			left-=2;
		}
		delay_ms(50);

		if(FlameSense[0]==3){BW_Buzz(2);BW_FlameExtinguish(left,right);}
		while(right<=170&&left>=10&&FlameSense[0]!=3)
		{
			Send_FlameSense();
			if(FlameSense[0]==3){BW_Buzz(2);BW_FlameExtinguish(left,right);}
			inv_kine(front_left,left,7,leg);
			inv_kine(front_right,right,7,leg);
			inv_kine(middle_left,left,7,leg);
			inv_kine(middle_right,right,7,leg);
			inv_kine(rear_left,left,7,leg);
			inv_kine(rear_right,right,7,leg);
			delay_ms(13);
			right+=2;
			left-=2;
		}
		delay_ms(50);

		if(FlameSense[0]==3){BW_Buzz(2);BW_FlameExtinguish(left,right);}
		while(right>=90&&left<=90&&FlameSense[0]!=3)
		{
			Send_FlameSense();
			if(FlameSense[0]==3){BW_Buzz(2);BW_FlameExtinguish(left,right);}
			inv_kine(front_left,left,7,leg);
			inv_kine(front_right,right,7,leg);
			inv_kine(middle_left,left,7,leg);
			inv_kine(middle_right,right,7,leg);
			inv_kine(rear_left,left,7,leg);
			inv_kine(rear_right,right,7,leg);
			delay_ms(13);
			right-=2;
			left+=2;
		}
		delay_ms(50);
		if(FlameSense[0]==3){BW_Buzz(2);BW_FlameExtinguish(left,right);}
//	}

//	while(FlameSense[0]==3) {Send_FlameSense();}
}

void BW_FlameExtinguish(int PRESENT_LEFT, int PRESENT_RIGHT)
{
	generate_movement_data(0,0,9);
	delay_ms(50);
	int counter=1;

	int right=PRESENT_RIGHT,left=PRESENT_LEFT;

	EXTINGUISHER_ON;
	delay_ms(2000);
	for(counter=1;counter<=2;counter++)
	{
		while( ( right>= (PRESENT_RIGHT-40) ) && ( left<= (PRESENT_LEFT+40) ) )
		{
			inv_kine(front_left,left,7,leg);
			inv_kine(front_right,right,7,leg);
			inv_kine(middle_left,left,7,leg);
			inv_kine(middle_right,right,7,leg);
			inv_kine(rear_left,left,7,leg);
			inv_kine(rear_right,right,7,leg);
			delay_ms(15);
			right-=1;
			left+=1;
		}

		while( (right<=PRESENT_RIGHT) && (left>=PRESENT_LEFT) )
		{
			inv_kine(front_left,left,7,leg);
			inv_kine(front_right,right,7,leg);
			inv_kine(middle_left,left,7,leg);
			inv_kine(middle_right,right,7,leg);
			inv_kine(rear_left,left,7,leg);
			inv_kine(rear_right,right,7,leg);
			delay_ms(15);
			right+=1;
			left-=1;
		}

		while( (right<= (PRESENT_RIGHT+40) ) && (left>= (PRESENT_LEFT-40) ) )
		{
			inv_kine(front_left,left,7,leg);
			inv_kine(front_right,right,7,leg);
			inv_kine(middle_left,left,7,leg);
			inv_kine(middle_right,right,7,leg);
			inv_kine(rear_left,left,7,leg);
			inv_kine(rear_right,right,7,leg);
			delay_ms(15);
			right+=1;
			left-=1;
		}

		while( (right<=PRESENT_RIGHT) && (left>=PRESENT_LEFT) )
		{
			inv_kine(front_left,left,7,leg);
			inv_kine(front_right,right,7,leg);
			inv_kine(middle_left,left,7,leg);
			inv_kine(middle_right,right,7,leg);
			inv_kine(rear_left,left,7,leg);
			inv_kine(rear_right,right,7,leg);
			delay_ms(15);
			right-=1;
			left+=1;
		}
	}

	UVLock_Refresh();
	if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}

//	if(FlameSense[0]>3)
//	{
//		while(FlameSense[0]!=3)
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//	}
//	else if(FlameSense[0]<3)
//	{
//		while(FlameSense[0]!=3)
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//	}

//	while(UV_Lock==UVLOCK_ACTIVE)
//	{
		Evade_Wall();

		BW_Buzz(1);
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"EXTINGUISH");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
		delay_ms(100);
		FlameTracking_New();


		GetFlame();
		if(FLAME_SENSOR[FLM_ANALOG]<=170)
		{
			mov_fwd_5cm(5,FAST_LEVEL_3);
		}

		while(Ping[PING_FRONT]<=13)
		{
//			mov_bwd(5,FAST_LEVEL_3);
			mov_bwd_3cm(6,FAST_LEVEL_3);
		}

		//LEFT
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}

		mov_rot_left(FAST_LEVEL_3,CLOSE);
		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}

		while(Ping[PING_FRONT]<=13)
		{
//			mov_bwd(5,FAST_LEVEL_3);
			mov_bwd_3cm(6,FAST_LEVEL_3);
		}

//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		UVLock_Refresh();
//		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}

//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		UVLock_Refresh();
//		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}
//
//		while(Ping[PING_FRONT]<=10)
//		{
//			mov_bwd(5,FAST_LEVEL_3);
//		}


		//CENTER
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}

		mov_rot_right(FAST_LEVEL_3,CLOSE);
		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}

		while(Ping[PING_FRONT]<=13)
		{
//			mov_bwd(5,FAST_LEVEL_3);
			mov_bwd_3cm(6,FAST_LEVEL_3);
		}

		mov_rot_right(FAST_LEVEL_3,CLOSE);
		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}

		mov_rot_right(FAST_LEVEL_3,CLOSE);
		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}

		while(Ping[PING_FRONT]<=13)
		{
//			mov_bwd(5,FAST_LEVEL_3);
			mov_bwd_3cm(6,FAST_LEVEL_3);
		}


//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		UVLock_Refresh();
//		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}
//
//		while(Ping[PING_FRONT]<=10)
//		{
//			mov_bwd(5,FAST_LEVEL_3);
//		}


		//RIGHT
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}

		mov_rot_right(FAST_LEVEL_3,CLOSE);
		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}

		while(Ping[PING_FRONT]<=5)
		{
//			mov_bwd(5,FAST_LEVEL_3);
			mov_bwd_3cm(6,FAST_LEVEL_3);
		}

		mov_rot_right(FAST_LEVEL_3,CLOSE);
		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}

//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		UVLock_Refresh();
//		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}
//
//		while(Ping[PING_FRONT]<=10)
//		{
//			mov_bwd(5,FAST_LEVEL_3);
//		}



		//CENTER
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}

		mov_rot_left(FAST_LEVEL_3,CLOSE);
		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}

		while(Ping[PING_FRONT]<=5)
		{
//			mov_bwd(5,FAST_LEVEL_3);
			mov_bwd_3cm(6,FAST_LEVEL_3);
		}

		mov_rot_left(FAST_LEVEL_3,CLOSE);
		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}

//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		UVLock_Refresh();
//		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}
//
//		while(Ping[PING_FRONT]<=10)
//		{
//			mov_bwd(5,FAST_LEVEL_3);
//		}



//		while(FlameSense[0]==3)
//		{
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			UVLock_Refresh();
//			if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}
//		}
		EXTINGUISHER_OFF;


//		UVLock_Refresh();
//		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}
//
//		while(FlameSense[0]!=3)
//		{
//			UVLock_Refresh();
//			if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}
//
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//
//		}
//
//
//		UVLock_Refresh();
//		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}
//
//		while(FlameSense[0]==3)
//		{
//			UVLock_Refresh();
//			if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//		}
//
//		UVLock_Refresh();
//		if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}

//	}


//	delay_ms(500);
//
//
//
//	if(FlameSense[0]>3)
//	{
////		while(FlameSense[0]!=3)
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//	}
//
//	else if(FlameSense[0]<3)
//	{
////		while(FlameSense[0]!=3)
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//	}
//	mov_fwd_5cm(5,FAST_LEVEL_3);
//
//	delay_ms(500);
//
//	UVLock_Refresh();
//	if(UV_Lock==UVLOCK_INACTIVE) {EXTINGUISHER_OFF; return;}
//
//	if(FlameSense[0]>3)
//	{
////		while(FlameSense[0]!=3)
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//	}
//	else if(FlameSense[0]<3)
//	{
////		while(FlameSense[0]!=3)
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//	}
//
//	mov_fwd_5cm(5,FAST_LEVEL_3);

//	delay_ms(1000);

	EXTINGUISHER_OFF;

}

void FollowFlame_Left(void)
{
//	int counter;
	//int limit=15;
	while(FlameSense[0]==0)
	{
		if (Ping[PING_FRONT]<=5)
		{
			if (Ping[PING_LEFT]>=20)
			{
				Sendto_PC(USART1,"BW ROTATE LEFT \r");
//				mov_rot_left(FAST_LEVEL_3, CLOSE);
				mov_rot_left(FAST_LEVEL_3, CLOSE);
				mov_rot_left(FAST_LEVEL_3, CLOSE);
			}

			if (Ping[PING_LEFT]<20)
			{
				Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//				mov_rot_right(FAST_LEVEL_3, CLOSE);
				mov_rot_right(FAST_LEVEL_3, CLOSE);
				mov_rot_right(FAST_LEVEL_3, CLOSE);
			}
		}
		else
		{
			PID_FollowFlame_Left();
		}
	}



}


void PID_FollowFlame_Left(void)
{
	//int limit= *COMMAND_LOOP;
	int OVERRIDE=0;

	PID_Calc_LeftRule();

	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
			if ( (Ping[PING_ASKEW_LEFT]<=PID_F_L.set_point_upper) && (Ping[PING_ASKEW_LEFT]>=PID_F_L.set_point_lower) )
//			if ( (SHARP[SHARP_LEFT]<=PID_F_L.set_point_upper) && (SHARP[SHARP_LEFT]>=PID_F_L.set_point_lower) )
				{
					if (Ping[PING_FRONT]<=5)
					{
						if (Ping[PING_LEFT]>=15)
						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
						if (Ping[PING_LEFT]<15)
						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						Sendto_PC(USART1,"BW FORWARD \r");
//						mov_fwd_5cm(5, FAST_LEVEL_3);
						mov_fwd_5cm(5, FAST_LEVEL_3);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT JAUH DARI DINDING
			else if ( Ping[PING_ASKEW_LEFT]<PID_F_L.set_point )
//			else if ( SHARP[SHARP_LEFT]<PID_F_L.set_point )
				{
					if (PID_F_L.pid_value[0]>5) PID_F_L.pid_value[0]=5; //WINDUP

					if (Ping[PING_FRONT]<=5)
					{
						if (Ping[PING_LEFT]>=15)
						{

//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
						if (Ping[PING_LEFT]<15)
						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
//						CurveRight_FlameSense(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
						CurveRight_FlameSense(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
						CurveRight_FlameSense(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
						OVERRIDE=1;
					}

				}

			//KONDISI ROBOT DEKAT DENGAN DINDING
			else if ( Ping[PING_ASKEW_LEFT]>PID_F_L.set_point )
//			else if ( SHARP[SHARP_LEFT]>PID_F_L.set_point )
				{
					if (PID_F_L.pid_value[0]>5) PID_F_L.pid_value[0]=5; //WINDUP

					if (Ping[PING_FRONT]<=5)
					{
						if (Ping[PING_LEFT]>=15)
						{

//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
						if (Ping[PING_LEFT]<15)
						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
//						CurveLeft_FlameSense(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
						CurveLeft_FlameSense(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
						CurveLeft_FlameSense(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
						OVERRIDE=1;
					}

				}
		}
	}

}




void CurveRight_FlameSense(int SPEED, int STEP, float *COMMAND_LOOP)
{
	Sendto_PC(USART1,"BW Curve Right Counter \r");
	generate_movement_data(0,STEP,9);
	delay_ms(50);

	unsigned int DELTA_FL=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_FR=10+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_ML=15+ (1 * *COMMAND_LOOP);
	//unsigned int DELTA_MR;
	unsigned int DELTA_RL=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_RR=10+ (1 * *COMMAND_LOOP);

	if(FlameSense[0]!=0){FlameTracking();}
	//1
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,90+beta[3],10,leg-3);
	inv_kine(middle_left,90+beta[1],10,leg-3);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90+beta[5],10,leg-3);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FlameTracking();}
	//2
	inv_kine(front_left,90+beta[0]+DELTA_FL,7,leg);
	inv_kine(front_right,90-beta[3]+DELTA_FR,10,leg-3);
	inv_kine(middle_left,90-beta[1]-DELTA_ML,10,leg-3);
	inv_kine(middle_right,90+beta[4],7,leg);
	inv_kine(rear_left,90+beta[2]+DELTA_RL,7,leg);
	inv_kine(rear_right,90-beta[5]+DELTA_RR,10,leg-3);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FlameTracking();}
	//3
	inv_kine(front_left,90+beta[0]+DELTA_FL,7,leg);
	inv_kine(front_right,90-beta[3]+DELTA_FR,7,leg);
	inv_kine(middle_left,90-beta[1]-DELTA_ML,7,leg);
	inv_kine(middle_right,90+beta[4],7,leg);
	inv_kine(rear_left,90+beta[2]+DELTA_RL,7,leg);
	inv_kine(rear_right,90-beta[5]+DELTA_RR,7,leg);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FlameTracking();}
	//4
	inv_kine(front_left,90+beta[0]+DELTA_FL,10,leg-3);
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90+beta[4],10.5,leg-3);
	inv_kine(rear_left,90+beta[2]+DELTA_RL,10,leg-3);
	inv_kine(rear_right,90,7,leg);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FlameTracking();}
	//5
	inv_kine(front_left,90-beta[0]-DELTA_FL,10,leg-3);
	inv_kine(front_right,90+beta[3],7,leg);
	inv_kine(middle_left,90+beta[1]+DELTA_ML,7,leg);
	inv_kine(middle_right,90-beta[4]+10,10.5,leg-3);
	inv_kine(rear_left,90-beta[2]-DELTA_RL,10,leg-3);
	inv_kine(rear_right,90+beta[5],7,leg);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FlameTracking();}
	//6
	inv_kine(front_left,90-beta[0]-DELTA_FL,7,leg);
	inv_kine(front_right,90+beta[3],7,leg);
	inv_kine(middle_left,90+beta[1]+DELTA_ML,7,leg);
	inv_kine(middle_right,90-beta[4]+10,7,leg);
	inv_kine(rear_left,90-beta[2]-DELTA_RL,7,leg);
	inv_kine(rear_right,90+beta[5],7,leg);
	delay_ms(SPEED);
}


void CurveLeft_FlameSense(int SPEED, int STEP, float *COMMAND_LOOP)
{
	Sendto_PC(USART1,"BW Curve Left Counter \r");
	generate_movement_data(0,STEP,9);
	delay_ms(50);

	unsigned int DELTA_FL=10+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_FR=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_ML=10+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_MR=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_RL=10+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_RR=15+ (1 * *COMMAND_LOOP);

	if(FlameSense[0]!=0){FlameTracking();}
	//1
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,90+beta[3]+DELTA_FR,10,leg-3);
	inv_kine(middle_left,90+beta[1]-DELTA_ML,10,leg-3);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90+beta[5]+DELTA_RR,10,leg-3);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FlameTracking();}
	//2
	inv_kine(front_left,90+beta[0]-DELTA_FL,7,leg);
	inv_kine(front_right,90-beta[3]-DELTA_FR,10,leg-3);
	inv_kine(middle_left,90-beta[1]+DELTA_ML,10,leg-3);
	inv_kine(middle_right,90+beta[4]+DELTA_MR,7,leg);
	inv_kine(rear_left,90+beta[2]-DELTA_RL,7,leg);
	inv_kine(rear_right,90-beta[5]-DELTA_RR,10,leg-3);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FlameTracking();}
	//3
	inv_kine(front_left,90+beta[0]-DELTA_FL,7,leg);
	inv_kine(front_right,90-beta[3]-DELTA_FR,7,leg);
	inv_kine(middle_left,90-beta[1]+DELTA_ML,7,leg);
	inv_kine(middle_right,90+beta[4]+DELTA_MR,7,leg);
	inv_kine(rear_left,90+beta[2]-DELTA_RL,7,leg);
	inv_kine(rear_right,90-beta[5]-DELTA_RR,7,leg);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FlameTracking();}
	//4
	inv_kine(front_left,90+beta[0]-DELTA_FL,10,leg-3);
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90+beta[4]+DELTA_MR,10.5,leg-3);
	inv_kine(rear_left,90+beta[2]-DELTA_RL,10,leg-3);
	inv_kine(rear_right,90,7,leg);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FlameTracking();}
	//5
	inv_kine(front_left,90-beta[0]+DELTA_FL,10,leg-3);
	inv_kine(front_right,90+beta[3]+DELTA_FR,7,leg);
	inv_kine(middle_left,90+beta[1]-DELTA_ML,7,leg);
	inv_kine(middle_right,90-beta[4]-DELTA_MR,10.5,leg-3);
	inv_kine(rear_left,90-beta[2]+DELTA_RL,10,leg-3);
	inv_kine(rear_right,90+beta[5]+DELTA_RR,7,leg);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FlameTracking();}
	//6
	inv_kine(front_left,90-beta[0]+DELTA_FL,7,leg);
	inv_kine(front_right,90+beta[3]+DELTA_FR,7,leg);
	inv_kine(middle_left,90+beta[1]-DELTA_ML,7,leg);
	inv_kine(middle_right,90-beta[4]-DELTA_MR,7,leg);
	inv_kine(rear_left,90-beta[2]+DELTA_RL,7,leg);
	inv_kine(rear_right,90+beta[5]+DELTA_RR,7,leg);
	delay_ms(SPEED);
}

/* func      : void BW_FireFollow(void)
 * brief     : BW Following Fire Source using Okky's Flame Sensor
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Friday, March 4th 2016)
 * Revised BY: N/A
 * programmer's Note:
 *
 */
void BW_FireFollow(void)
{
	FollowFlame_Flag	 = FLAG_INACTIVE;
	FlameTrack_Flag 	 = FLAG_INACTIVE;
	FlameScan_Flag   	 = FLAG_INACTIVE;
	FlameExtinguish_Flag = FLAG_INACTIVE;

	BW_Buzz(2);
	Sendto_PC(USART1,"FollowFlame Initializing \r");
	while(FollowFlame_Flag==FLAG_INACTIVE)
	{
		FollowFlame_Flag = FollowFlame_Left_New();
	}
	BW_Buzz(3);
	Sendto_PC(USART1,"FollowFlame Finished \r");

//	if(FlameSense[0]==5) mov_fwd_5cm(15,FAST_LEVEL_3);
//	if(FlameSense[0]==1) mov_fwd_5cm(15,FAST_LEVEL_3);
	if(FlameSense[0]==1) mov_fwd_5cm(15,FAST_LEVEL_3);
	if(FlameSense[0]==1) mov_fwd_5cm(15,FAST_LEVEL_3);

	BW_Buzz(2);
	Sendto_PC(USART1,"FlameTrack Initializing \r");
	while(FlameTrack_Flag==FLAG_INACTIVE)
	{
//		FlameTrack_Flag = FlameTracking_New();
		FlameTracking_New();
	}
	BW_Buzz(3);
	Sendto_PC(USART1,"FollowTrack Finished \r");

	BW_Buzz(2);
	Sendto_PC(USART1,"FlameApproach Initializing \r");
	while(FlameApproach_Flag==FLAG_INACTIVE)
	{
		FlameApproach();
	}
	BW_Buzz(3);
	Sendto_PC(USART1,"FollowApproach Finished \r");
//
//	while(Ping[PING_FRONT]>=17)
//	{
//		mov_fwd_5cm(5,FAST_LEVEL_3);
//	}

	while(Ping[PING_FRONT]>=12)
	{
		FlameApproach();
	}

	BW_Buzz(3);
	while(FlameSense[0]!=0)
	{
		BW_FlameScanning();
	}


}


int FollowFlame_Left_New(void)
{
//	int counter;
	//int limit=15;
	while(FollowFlame_Flag==FLAG_INACTIVE)
	{
		if (Ping[PING_FRONT]<=5)
		{
			if (Ping[PING_LEFT]>=20)
			{
				Sendto_PC(USART1,"BW ROTATE LEFT \r");
//				mov_rot_left(FAST_LEVEL_3, CLOSE);
				mov_rot_left(FAST_LEVEL_3, CLOSE);
				mov_rot_left(FAST_LEVEL_3, CLOSE);
			}

			if (Ping[PING_LEFT]<20)
			{
				Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//				mov_rot_right(FAST_LEVEL_3, CLOSE);
				mov_rot_right(FAST_LEVEL_3, CLOSE);
				mov_rot_right(FAST_LEVEL_3, CLOSE);
			}
		}
		else
		{
			PID_FollowFlame_Left_New();
		}
	}
	return 0;
}


void PID_FollowFlame_Left_New(void)
{
	//int limit= *COMMAND_LOOP;
	int OVERRIDE=0;

	PID_Calc_LeftRule();

	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
			if ( (Ping[PING_ASKEW_LEFT]<=PID_F_L.set_point_upper) && (Ping[PING_ASKEW_LEFT]>=PID_F_L.set_point_lower) )
//			if ( (SHARP[SHARP_LEFT]<=PID_F_L.set_point_upper) && (SHARP[SHARP_LEFT]>=PID_F_L.set_point_lower) )
				{
					if (Ping[PING_FRONT]<=5)
					{
						if (Ping[PING_LEFT]>=15)
						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
						if (Ping[PING_LEFT]<15)
						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						Sendto_PC(USART1,"BW FORWARD \r");
//						mov_fwd_5cm(5, FAST_LEVEL_3);
						mov_fwd_5cm(5, FAST_LEVEL_3);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT JAUH DARI DINDING
			else if ( Ping[PING_ASKEW_LEFT]<PID_F_L.set_point )
//			else if ( SHARP[SHARP_LEFT]<PID_F_L.set_point )
				{
					if (PID_F_L.pid_value[0]>5) PID_F_L.pid_value[0]=5; //WINDUP

					if (Ping[PING_FRONT]<=5)
					{
						if (Ping[PING_LEFT]>=15)
						{

//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
						if (Ping[PING_LEFT]<15)
						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
//						CurveRight_FlameSense_New(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
						CurveRight_FlameSense_New(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
						CurveRight_FlameSense_New(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
						OVERRIDE=1;
					}

				}

			//KONDISI ROBOT DEKAT DENGAN DINDING
			else if ( Ping[PING_ASKEW_LEFT]>PID_F_L.set_point )
//			else if ( SHARP[SHARP_LEFT]>PID_F_L.set_point )
				{
					if (PID_F_L.pid_value[0]>5) PID_F_L.pid_value[0]=5; //WINDUP

					if (Ping[PING_FRONT]<=5)
					{
						if (Ping[PING_LEFT]>=15)
						{

//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
						if (Ping[PING_LEFT]<15)
						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
//						CurveLeft_FlameSense_New(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
						CurveLeft_FlameSense_New(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
						CurveLeft_FlameSense_New(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
						OVERRIDE=1;
					}

				}
		}
	}

}




void CurveRight_FlameSense_New(int SPEED, int STEP, float *COMMAND_LOOP)
{
	Sendto_PC(USART1,"BW Curve Right FlameSense \r");
	generate_movement_data(0,STEP,9);
	delay_ms(50);

	unsigned int DELTA_FL=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_FR=10+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_ML=15+ (1 * *COMMAND_LOOP);
	//unsigned int DELTA_MR;
	unsigned int DELTA_RL=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_RR=10+ (1 * *COMMAND_LOOP);

	if(FlameSense[0]!=0){FollowFlame_Flag = FLAG_ACTIVE;}
	//1
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,90+beta[3],10,leg-3);
	inv_kine(middle_left,90+beta[1],10,leg-3);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90+beta[5],10,leg-3);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FollowFlame_Flag = FLAG_ACTIVE;}
	//2
	inv_kine(front_left,90+beta[0]+DELTA_FL,7,leg);
	inv_kine(front_right,90-beta[3]+DELTA_FR,10,leg-3);
	inv_kine(middle_left,90-beta[1]-DELTA_ML,10,leg-3);
	inv_kine(middle_right,90+beta[4],7,leg);
	inv_kine(rear_left,90+beta[2]+DELTA_RL,7,leg);
	inv_kine(rear_right,90-beta[5]+DELTA_RR,10,leg-3);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FollowFlame_Flag = FLAG_ACTIVE;}
	//3
	inv_kine(front_left,90+beta[0]+DELTA_FL,7,leg);
	inv_kine(front_right,90-beta[3]+DELTA_FR,7,leg);
	inv_kine(middle_left,90-beta[1]-DELTA_ML,7,leg);
	inv_kine(middle_right,90+beta[4],7,leg);
	inv_kine(rear_left,90+beta[2]+DELTA_RL,7,leg);
	inv_kine(rear_right,90-beta[5]+DELTA_RR,7,leg);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FollowFlame_Flag = FLAG_ACTIVE;}
	//4
	inv_kine(front_left,90+beta[0]+DELTA_FL,10,leg-3);
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90+beta[4],10.5,leg-3);
	inv_kine(rear_left,90+beta[2]+DELTA_RL,10,leg-3);
	inv_kine(rear_right,90,7,leg);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FollowFlame_Flag = FLAG_ACTIVE;}
	//5
	inv_kine(front_left,90-beta[0]-DELTA_FL,10,leg-3);
	inv_kine(front_right,90+beta[3],7,leg);
	inv_kine(middle_left,90+beta[1]+DELTA_ML,7,leg);
	inv_kine(middle_right,90-beta[4]+10,10.5,leg-3);
	inv_kine(rear_left,90-beta[2]-DELTA_RL,10,leg-3);
	inv_kine(rear_right,90+beta[5],7,leg);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FollowFlame_Flag = FLAG_ACTIVE;}
	//6
	inv_kine(front_left,90-beta[0]-DELTA_FL,7,leg);
	inv_kine(front_right,90+beta[3],7,leg);
	inv_kine(middle_left,90+beta[1]+DELTA_ML,7,leg);
	inv_kine(middle_right,90-beta[4]+10,7,leg);
	inv_kine(rear_left,90-beta[2]-DELTA_RL,7,leg);
	inv_kine(rear_right,90+beta[5],7,leg);
	delay_ms(SPEED);
}


void CurveLeft_FlameSense_New(int SPEED, int STEP, float *COMMAND_LOOP)
{
	Sendto_PC(USART1,"BW Curve Left FlameSense \r");
	generate_movement_data(0,STEP,9);
	delay_ms(50);

	unsigned int DELTA_FL=10+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_FR=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_ML=10+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_MR=15+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_RL=10+ (1 * *COMMAND_LOOP);
	unsigned int DELTA_RR=15+ (1 * *COMMAND_LOOP);

	if(FlameSense[0]!=0){FollowFlame_Flag = FLAG_ACTIVE;}
	//1
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,90+beta[3]+DELTA_FR,10,leg-3);
	inv_kine(middle_left,90+beta[1]-DELTA_ML,10,leg-3);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90+beta[5]+DELTA_RR,10,leg-3);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FollowFlame_Flag = FLAG_ACTIVE;}
	//2
	inv_kine(front_left,90+beta[0]-DELTA_FL,7,leg);
	inv_kine(front_right,90-beta[3]-DELTA_FR,10,leg-3);
	inv_kine(middle_left,90-beta[1]+DELTA_ML,10,leg-3);
	inv_kine(middle_right,90+beta[4]+DELTA_MR,7,leg);
	inv_kine(rear_left,90+beta[2]-DELTA_RL,7,leg);
	inv_kine(rear_right,90-beta[5]-DELTA_RR,10,leg-3);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FollowFlame_Flag = FLAG_ACTIVE;}
	//3
	inv_kine(front_left,90+beta[0]-DELTA_FL,7,leg);
	inv_kine(front_right,90-beta[3]-DELTA_FR,7,leg);
	inv_kine(middle_left,90-beta[1]+DELTA_ML,7,leg);
	inv_kine(middle_right,90+beta[4]+DELTA_MR,7,leg);
	inv_kine(rear_left,90+beta[2]-DELTA_RL,7,leg);
	inv_kine(rear_right,90-beta[5]-DELTA_RR,7,leg);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FollowFlame_Flag = FLAG_ACTIVE;}
	//4
	inv_kine(front_left,90+beta[0]-DELTA_FL,10,leg-3);
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90+beta[4]+DELTA_MR,10.5,leg-3);
	inv_kine(rear_left,90+beta[2]-DELTA_RL,10,leg-3);
	inv_kine(rear_right,90,7,leg);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FollowFlame_Flag = FLAG_ACTIVE;}
	//5
	inv_kine(front_left,90-beta[0]+DELTA_FL,10,leg-3);
	inv_kine(front_right,90+beta[3]+DELTA_FR,7,leg);
	inv_kine(middle_left,90+beta[1]-DELTA_ML,7,leg);
	inv_kine(middle_right,90-beta[4]-DELTA_MR,10.5,leg-3);
	inv_kine(rear_left,90-beta[2]+DELTA_RL,10,leg-3);
	inv_kine(rear_right,90+beta[5]+DELTA_RR,7,leg);
	delay_ms(SPEED);

	if(FlameSense[0]!=0){FollowFlame_Flag = FLAG_ACTIVE;}
	//6
	inv_kine(front_left,90-beta[0]+DELTA_FL,7,leg);
	inv_kine(front_right,90+beta[3]+DELTA_FR,7,leg);
	inv_kine(middle_left,90+beta[1]-DELTA_ML,7,leg);
	inv_kine(middle_right,90-beta[4]-DELTA_MR,7,leg);
	inv_kine(rear_left,90-beta[2]+DELTA_RL,7,leg);
	inv_kine(rear_right,90+beta[5]+DELTA_RR,7,leg);
	delay_ms(SPEED);
}



int FlameTracking_New(void)
{
//	int counter;
//	for(counter=1;counter<=10;counter++)
	int flametrack_cnt=0;



	while( (FlameSense[0]!=3) && (UV_Lock==UVLOCK_ACTIVE) )
	{
//		Bump_Avoider();
		Evade_Wall();


//		if(Ping[PING_FRONT]<=13) {mov_bwd(15,FAST_LEVEL_3);}
		if(Ping[PING_FRONT]<=8) {mov_bwd_3cm(12,FAST_LEVEL_3);}

		Send_FlameSense();
		PID_FlameTracking_New();
		lcd_display_clear();

		flametrack_cnt++;
		lcd_gotoxy(0,3);sprintf(lcd,"flametrack: %d",flametrack_cnt);lcd_putstr(lcd);
		if(flametrack_cnt>=35)
		{
			flametrack_cnt=0;
			BW_Buzz(2);
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"FLAMETRACKING");lcd_putstr(lcd);
			lcd_gotoxy(4,0);sprintf(lcd,"OVERFLOW");lcd_putstr(lcd);
			delay_ms(100);
			UVLock_Refresh();

		}
	}
	return 0;
}


int PID_FlameTracking_New(void)
{
	float DUMMY_PIDVALUE=1;
	//int limit= *COMMAND_LOOP;
//	int OVERRIDE=0;

	//OVERCOMING BLIND SPOTS
	if(FlameSense[0]==0) FlameSense[0]=10;
	Sendto_PC(USART1,"FlameSense[0]: %d \r",FlameSense[0]);

	FlameSense_PID_Calc();
	Sendto_PC(USART1,"PID Value : %d \r",(int)PID_FLAME.pid_value[0]);

	//KONDISI ROBOT SESUAI
	if ( FlameSense[0]==PID_FLAME.set_point)
	{
//		mov_static();
//		BW_Buzz(3);
//		while(Ping[PING_FRONT]>=25)
//		{
//			mov_fwd_5cm(5,FAST_LEVEL_3);
//		}
//
//		BW_FlameScanning();
		Sendto_PC(USART1,"FlameSense[0]: %d \r",FlameSense[0]);
//		return FLAG_ACTIVE;
		FlameTrack_Flag=FLAG_ACTIVE;
	}
//	else if ( FlameSense[0]==(PID_FLAME.set_point-1))
//	{
//
//		Sendto_PC(USART1,"FlameSense[0]: %d \r",FlameSense[0]);
//		FlameTrack_Flag=FLAG_ACTIVE;
//	}
//	else if ( FlameSense[0]==(PID_FLAME.set_point+1))
//	{
//		Sendto_PC(USART1,"FlameSense[0]: %d \r",FlameSense[0]);
//		FlameTrack_Flag=FLAG_ACTIVE;
//	}


	else if(FlameSense[0]==10)
	{

		if ( (FlameSense[1]==10) || (FlameSense[1]==0) )
		{
			Rot_Right_PID(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
			Sendto_PC(USART1,"WINDUP ROT RIGHT CLOSE REACH ACTIVATED \r");
		}
		else if( (FlameSense[1]==1) )
		{
			Rot_Left_PID(FAST_LEVEL_3, CLOSE, &DUMMY_PIDVALUE);
			Sendto_PC(USART1,"WINDUP ROT LEFT NARROW ACTIVATED \r");
		}
		else if( (FlameSense[1]==5) )
		{
			Rot_Right_PID(FAST_LEVEL_3, CLOSE, &DUMMY_PIDVALUE);
			Sendto_PC(USART1,"WINDUP ROT RIGHT NARROW ACTIVATED \r");
		}

		else if ( FlameSense[1] > PID_FLAME.set_point )
		{
			Rot_Right_PID(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
			Sendto_PC(USART1,"WINDUP ROT RIGHT CLOSE REACH ACTIVATED \r");
		}

		else if ( FlameSense[1] < PID_FLAME.set_point )
		{
			Rot_Left_PID(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
			Sendto_PC(USART1,"WINDUP ROT LEFT CLOSE REACH ACTIVATED \r");
		}



	}
	//KONDISI ROBOT JAUH DARI DINDING
	else if ( FlameSense[0] > PID_FLAME.set_point )
	{
//		if (PID_FLAME.pid_value[0]>5) PID_FLAME.pid_value[0]=5; //WINDUP


		Rot_Right_PID(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
		FlameSense[1]=5;

	}

	//KONDISI ROBOT DEKAT DENGAN DINDING
	else if ( FlameSense[0] < PID_FLAME.set_point )
	{
//		if (PID_F_R.pid_value[0]>5) PID_F_R.pid_value[0]=5; //WINDUP

		FlameSense[1]=1;
		Rot_Left_PID(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);

	}
	return 0;

}

/* func      : int FlameApproach(void)
 * brief     : BW Following Fire Source using Okky's Flame Sensor
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Friday, March 4th 2016)
 * Revised BY: N/A
 * programmer's Note:
 *
 */
int FlameApproach(void)
{
	Get_UV();
	Send_FlameSense();
//	Evade_Wall();
	Evade_Wall_Room();
	PID_FlameApproach();

	FireFight_CandleStickDetector();
	FireFight_CandleFireDetector();

//	Get_IR();
//	if(
//			( (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ) &&
//			( (FlameSense[0]!=3) )
//	  )
//	{
//		BW_Buzz(5);
//		lcd_display_clear();
//		lcd_gotoxy(0,0);sprintf(lcd,"FURNITURE");lcd_putstr(lcd);
//		lcd_gotoxy(0,1);sprintf(lcd,"DETECTED");lcd_putstr(lcd);
//		delay_ms(100);
//
//		if(Ping[PING_RIGHT]<=Ping[PING_LEFT])
//		{
//			BW_PID_Init();
//			follow_right_counter(2);
//		}
//
//		else if(Ping[PING_LEFT]<Ping[PING_RIGHT])
//		{
//			BW_PID_Init();
//			follow_left_counter(2);
//		}
////		FlameTracking_New();
//
//	}



	return 0;
}


/* func      : int PID_FlameApproach(void)
 * brief     : Calculating and actuating kinematics for Following Fire Source using Okky's Flame Sensor
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Friday, March 4th 2016)
 * Revised BY: N/A
 * programmer's Note: This function must be called FlameApproach() function
 *
 */
int PID_FlameApproach(void)
{
	float DUMMY_PIDVALUE=5;
	//int limit= *COMMAND_LOOP;
//	int OVERRIDE=0;

	//OVERCOMING BLIND SPOTS
	if(FlameSense[0]==0) FlameSense[0]=5;
	Sendto_PC(USART1,"FlameSense[0]: %d \r",FlameSense[0]);

	FlameSense_PID_Calc();
	Sendto_PC(USART1,"PID Value : %d \r",(int)PID_FLAME.pid_value[0]);

	//KONDISI ROBOT SESUAI
	if ( FlameSense[0]==PID_FLAME.set_point)
	{
//		FlameApproach_Flag=FLAG_ACTIVE;
//		mov_fwd_5cm(5,FAST_LEVEL_3);
		mov_fwd_5cm(5,FAST_LEVEL_3);
//		BW_HydroPump();
//		BW_Celebrate();

//		if(Ping[PING_FRONT]<=20)
//		{
//			FlameApproach_Flag=FLAG_ACTIVE;
//		}
	}

	else if(FlameSense[0]==5)
	{

		if ( (FlameSense[1]==0) || (FlameSense[1]==5) )
		{
//			Rot_Right_PID(FAST_LEVEL_3, CLOSE, &DUMMY_PIDVALUE);
			Rot_Right_PID(FAST_LEVEL_3, CLOSE, &DUMMY_PIDVALUE);

			Sendto_PC(USART1,"WINDUP ROT RIGHT NARROW ACTIVATED \r");
		}

		else if( (FlameSense[1]==1) )
		{
//			CurveLeft_FlameApproach(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
//			Rot_Left_PID(FAST_LEVEL_3, CLOSE, &DUMMY_PIDVALUE);
			Rot_Left_PID(FAST_LEVEL_3, CLOSE, &DUMMY_PIDVALUE);
			Sendto_PC(USART1,"WINDUP ROT LEFT NARROW ACTIVATED \r");
		}
		else if( (FlameSense[1]==5) )
		{
//			CurveRight_FlameApproach(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
//			Rot_Right_PID(FAST_LEVEL_3, CLOSE, &DUMMY_PIDVALUE);
			Rot_Right_PID(FAST_LEVEL_3, CLOSE, &DUMMY_PIDVALUE);
			Sendto_PC(USART1,"WINDUP ROT RIGHT NARROW ACTIVATED \r");
		}

		else if ( FlameSense[1] > PID_FLAME.set_point )
		{
//			CurveRight_FlameApproach(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
			CurveRight_FlameApproach(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
			Sendto_PC(USART1,"WINDUP ROT RIGHT CLOSE REACH ACTIVATED \r");
		}

		else if ( FlameSense[1] < PID_FLAME.set_point )
		{
//			CurveLeft_FlameApproach(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
			CurveLeft_FlameApproach(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
			Sendto_PC(USART1,"WINDUP ROT LEFT CLOSE REACH ACTIVATED \r");
		}



	}
	//KONDISI ROBOT JAUH DARI DINDING
	else if ( FlameSense[0] > PID_FLAME.set_point )
	{
		if (PID_FLAME.pid_value[0]>10) PID_FLAME.pid_value[0]=10; //WINDUP

//		CurveRight_FlameApproach(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
		CurveRight_FlameApproach(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
		FlameSense[1]=5;

	}

	//KONDISI ROBOT DEKAT DENGAN DINDING
	else if ( FlameSense[0] < PID_FLAME.set_point )
	{
		if (PID_F_R.pid_value[0]>10) PID_F_R.pid_value[0]=10; //WINDUP

		FlameSense[1]=1;
//		CurveLeft_FlameApproach(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
		CurveLeft_FlameApproach(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);

	}
	return 0;
}

/* func      : void CurveRight_FlameApproach(int SPEED, int STEP, float *COMMAND_LOOP)
 * brief     : Applying actuating signal to curve right locomotion
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Friday, March 4th 2016)
 * Revised BY: N/A
 * programmer's Note: This function must be called FlameApproach() function
 *
 */
void CurveRight_FlameApproach(int SPEED, int STEP, float *COMMAND_LOOP)
{
	Sendto_PC(USART1,"BW Curve Right FlameSense \r");
	generate_movement_data(0,STEP,9);
	delay_ms(50);

	FireFight_CandleStickDetector();
	FireFight_CandleFireDetector();
	Evade_Wall_Room();
	if(FlameSense[0]==3){FlameApproach_Flag=FLAG_ACTIVE;}
	GetFlame();
	if(FLAME_SENSOR[FLM_ANALOG]>=200){FlameApproach_Flag=FLAG_ACTIVE;}
	unsigned int DELTA_FL=15+ (4 * *COMMAND_LOOP);
	unsigned int DELTA_FR=10+ (4 * *COMMAND_LOOP);
	unsigned int DELTA_ML=15+ (4 * *COMMAND_LOOP);
	unsigned int DELTA_MR=10+ (4 * *COMMAND_LOOP);
	unsigned int DELTA_RL=15+ (4 * *COMMAND_LOOP);
	unsigned int DELTA_RR=10+ (4 * *COMMAND_LOOP);

	FireFight_CandleStickDetector();
	FireFight_CandleFireDetector();
	Evade_Wall_Room();
	if(FlameSense[0]==3){FlameApproach_Flag=FLAG_ACTIVE;}
	GetFlame();
	if(FLAME_SENSOR[FLM_ANALOG]>=200){FlameApproach_Flag=FLAG_ACTIVE;}
	//1
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,90+beta[3]-DELTA_FR,10,leg-3);
	inv_kine(middle_left,90+beta[1]+DELTA_ML,10,leg-3);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90+beta[5]-DELTA_RR,10,leg-3);
	delay_ms(SPEED);

	FireFight_CandleStickDetector();
	FireFight_CandleFireDetector();
	Evade_Wall_Room();
	if(FlameSense[0]==3){FlameApproach_Flag=FLAG_ACTIVE;}
	GetFlame();
	if(FLAME_SENSOR[FLM_ANALOG]>=200){FlameApproach_Flag=FLAG_ACTIVE;}
	//2
	inv_kine(front_left,90+beta[0]+DELTA_FL,7,leg);
	inv_kine(front_right,90-beta[3]+DELTA_FR,10,leg-3);
	inv_kine(middle_left,90-beta[1]-DELTA_ML,10,leg-3);
	inv_kine(middle_right,90+beta[4]-DELTA_MR,7,leg);
	inv_kine(rear_left,90+beta[2]+DELTA_RL,7,leg);
	inv_kine(rear_right,90-beta[5]+DELTA_RR,10,leg-3);
	delay_ms(SPEED);

	FireFight_CandleStickDetector();
	FireFight_CandleFireDetector();
	Evade_Wall_Room();
	if(FlameSense[0]==3){FlameApproach_Flag=FLAG_ACTIVE;}
	GetFlame();
	if(FLAME_SENSOR[FLM_ANALOG]>=200){FlameApproach_Flag=FLAG_ACTIVE;}
	//3
	inv_kine(front_left,90+beta[0]+DELTA_FL,7,leg);
	inv_kine(front_right,90-beta[3]+DELTA_FR,7,leg);
	inv_kine(middle_left,90-beta[1]-DELTA_ML,7,leg);
	inv_kine(middle_right,90+beta[4]-DELTA_MR,7,leg);
	inv_kine(rear_left,90+beta[2]+DELTA_RL,7,leg);
	inv_kine(rear_right,90-beta[5]+DELTA_RR,7,leg);
	delay_ms(SPEED);

	FireFight_CandleStickDetector();
	FireFight_CandleFireDetector();
	Evade_Wall_Room();
	if(FlameSense[0]==3){FlameApproach_Flag=FLAG_ACTIVE;}
	GetFlame();
	if(FLAME_SENSOR[FLM_ANALOG]>=200){FlameApproach_Flag=FLAG_ACTIVE;}
	//4
	inv_kine(front_left,90+beta[0]+DELTA_FL,10,leg-3);
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90+beta[4]-DELTA_MR,10.5,leg-3);
	inv_kine(rear_left,90+beta[2]+DELTA_RL,10,leg-3);
	inv_kine(rear_right,90,7,leg);
	delay_ms(SPEED);

	FireFight_CandleStickDetector();
	FireFight_CandleFireDetector();
	Evade_Wall_Room();
	if(FlameSense[0]==3){FlameApproach_Flag=FLAG_ACTIVE;}
	GetFlame();
	if(FLAME_SENSOR[FLM_ANALOG]>=200){FlameApproach_Flag=FLAG_ACTIVE;}
	//5
	inv_kine(front_left,90-beta[0]-DELTA_FL,10,leg-3);
	inv_kine(front_right,90+beta[3]-DELTA_FR,7,leg);
	inv_kine(middle_left,90+beta[1]+DELTA_ML,7,leg);
	inv_kine(middle_right,90-beta[4]+DELTA_MR,10.5,leg-3);
	inv_kine(rear_left,90-beta[2]-DELTA_RL,10,leg-3);
	inv_kine(rear_right,90+beta[5]-DELTA_RR,7,leg);
	delay_ms(SPEED);

	FireFight_CandleStickDetector();
	FireFight_CandleFireDetector();
	Evade_Wall_Room();
	if(FlameSense[0]==3){FlameApproach_Flag=FLAG_ACTIVE;}
	GetFlame();
	if(FLAME_SENSOR[FLM_ANALOG]>=200){FlameApproach_Flag=FLAG_ACTIVE;}
	//6
	inv_kine(front_left,90-beta[0]-DELTA_FL,7,leg);
	inv_kine(front_right,90+beta[3]-DELTA_FR,7,leg);
	inv_kine(middle_left,90+beta[1]+DELTA_ML,7,leg);
	inv_kine(middle_right,90-beta[4]+DELTA_MR,7,leg);
	inv_kine(rear_left,90-beta[2]-DELTA_RL,7,leg);
	inv_kine(rear_right,90+beta[5]-DELTA_RR,7,leg);
	delay_ms(SPEED);
}

/* func      : void CurveLeft_FlameApproach(int SPEED, int STEP, float *COMMAND_LOOP)
 * brief     : Applying actuating signal to curve left locomotion
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Friday, March 4th 2016)
 * Revised BY: N/A
 * programmer's Note: This function must be called FlameApproach() function
 *
 */
void CurveLeft_FlameApproach(int SPEED, int STEP, float *COMMAND_LOOP)
{
	Sendto_PC(USART1,"BW Curve Left FlameSense \r");
	generate_movement_data(0,STEP,9);
	delay_ms(50);

	unsigned int DELTA_FL=10+ (4 * *COMMAND_LOOP);
	unsigned int DELTA_FR=15+ (4 * *COMMAND_LOOP);
	unsigned int DELTA_ML=10+ (4 * *COMMAND_LOOP);
	unsigned int DELTA_MR=15+ (4 * *COMMAND_LOOP);
	unsigned int DELTA_RL=10+ (4 * *COMMAND_LOOP);
	unsigned int DELTA_RR=15+ (4 * *COMMAND_LOOP);

//	Evade_Wall();
	FireFight_CandleStickDetector();
	FireFight_CandleFireDetector();
	Evade_Wall_Room();
	if(FlameSense[0]==3){FlameApproach_Flag=FLAG_ACTIVE;}
	GetFlame();
	if(FLAME_SENSOR[FLM_ANALOG]>=200){FlameApproach_Flag=FLAG_ACTIVE;}


	//1
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,90+beta[3]+DELTA_FR,10,leg-3);
	inv_kine(middle_left,90+beta[1]-DELTA_ML,10,leg-3);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90+beta[5]+DELTA_RR,10,leg-3);
	delay_ms(SPEED);

	FireFight_CandleStickDetector();
	FireFight_CandleFireDetector();
	Evade_Wall_Room();
	if(FlameSense[0]==3){FlameApproach_Flag=FLAG_ACTIVE;}
	GetFlame();
	if(FLAME_SENSOR[FLM_ANALOG]>=200){FlameApproach_Flag=FLAG_ACTIVE;}

	//2
	inv_kine(front_left,90+beta[0]-DELTA_FL,7,leg);
	inv_kine(front_right,90-beta[3]-DELTA_FR,10,leg-3);
	inv_kine(middle_left,90-beta[1]+DELTA_ML,10,leg-3);
	inv_kine(middle_right,90+beta[4]+DELTA_MR,7,leg);
	inv_kine(rear_left,90+beta[2]-DELTA_RL,7,leg);
	inv_kine(rear_right,90-beta[5]-DELTA_RR,10,leg-3);
	delay_ms(SPEED);

	FireFight_CandleStickDetector();
	FireFight_CandleFireDetector();
	Evade_Wall_Room();
	if(FlameSense[0]==3){FlameApproach_Flag=FLAG_ACTIVE;}
	GetFlame();
	if(FLAME_SENSOR[FLM_ANALOG]>=200){FlameApproach_Flag=FLAG_ACTIVE;}
	//3
	inv_kine(front_left,90+beta[0]-DELTA_FL,7,leg);
	inv_kine(front_right,90-beta[3]-DELTA_FR,7,leg);
	inv_kine(middle_left,90-beta[1]+DELTA_ML,7,leg);
	inv_kine(middle_right,90+beta[4]+DELTA_MR,7,leg);
	inv_kine(rear_left,90+beta[2]-DELTA_RL,7,leg);
	inv_kine(rear_right,90-beta[5]-DELTA_RR,7,leg);
	delay_ms(SPEED);

	FireFight_CandleStickDetector();
	FireFight_CandleFireDetector();
	Evade_Wall_Room();
	if(FlameSense[0]==3){FlameApproach_Flag=FLAG_ACTIVE;}
	GetFlame();
	if(FLAME_SENSOR[FLM_ANALOG]>=200){FlameApproach_Flag=FLAG_ACTIVE;}
	//4
	inv_kine(front_left,90+beta[0]-DELTA_FL,10,leg-3);
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90+beta[4]+DELTA_MR,10.5,leg-3);
	inv_kine(rear_left,90+beta[2]-DELTA_RL,10,leg-3);
	inv_kine(rear_right,90,7,leg);
	delay_ms(SPEED);

	FireFight_CandleStickDetector();
	FireFight_CandleFireDetector();
	Evade_Wall_Room();
	if(FlameSense[0]==3){FlameApproach_Flag=FLAG_ACTIVE;}
	GetFlame();
	if(FLAME_SENSOR[FLM_ANALOG]>=200){FlameApproach_Flag=FLAG_ACTIVE;}
	//5
	inv_kine(front_left,90-beta[0]+DELTA_FL,10,leg-3);
	inv_kine(front_right,90+beta[3]+DELTA_FR,7,leg);
	inv_kine(middle_left,90+beta[1]-DELTA_ML,7,leg);
	inv_kine(middle_right,90-beta[4]-DELTA_MR,10.5,leg-3);
	inv_kine(rear_left,90-beta[2]+DELTA_RL,10,leg-3);
	inv_kine(rear_right,90+beta[5]+DELTA_RR,7,leg);
	delay_ms(SPEED);

	FireFight_CandleStickDetector();
	FireFight_CandleFireDetector();
	Evade_Wall_Room();
	if(FlameSense[0]==3){FlameApproach_Flag=FLAG_ACTIVE;}
	GetFlame();
	if(FLAME_SENSOR[FLM_ANALOG]>=200){FlameApproach_Flag=FLAG_ACTIVE;}
	//6
	inv_kine(front_left,90-beta[0]+DELTA_FL,7,leg);
	inv_kine(front_right,90+beta[3]+DELTA_FR,7,leg);
	inv_kine(middle_left,90+beta[1]-DELTA_ML,7,leg);
	inv_kine(middle_right,90-beta[4]-DELTA_MR,7,leg);
	inv_kine(rear_left,90-beta[2]+DELTA_RL,7,leg);
	inv_kine(rear_right,90+beta[5]+DELTA_RR,7,leg);
	delay_ms(SPEED);
}


void RotRight_Angle(void)
{
	int Init_Angle;

	GetCMPS11_Angle8Bit();
	GetCMPS11_Angle8Bit();
	GetCMPS11_Angle8Bit();
	GetCMPS11_Angle8Bit();
	GetCMPS11_Angle8Bit();

	Init_Angle = BW_CMPS11.Compass8Bit+90;

	while( BW_CMPS11.Compass8Bit <= Init_Angle )
	{
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		GetCMPS11_Angle8Bit();
		if(BW_CMPS11.Compass8Bit > Init_Angle) break;
	}

	while(1)
	{
		mov_static();
		BW_Buzz(1);
	}
}

void RotLeft_Angle(void)
{
	int Init_Angle;

	GetCMPS11_Angle16Bit();

	Init_Angle = BW_CMPS11.Compass16Bit[MERGED];

	while( BW_CMPS11.Compass16Bit[MERGED] >= (Init_Angle-90) )
	{
		mov_rot_left(FAST_LEVEL_3,CLOSE);
	}
}




/*==============================================================================================
								BW DEMO ROUTINES
===============================================================================================*/
void Obstacle_Avoider(void)
{
	Get_IR();
	while(
			(Ping[PING_FRONT]>=20) &&
			(INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED) &&
			(INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED)
		 )
	{
		Get_IR();
//		mov_fwd_5cm(10,FAST_LEVEL_3);
		mov_fwd_5cm(10,FAST_LEVEL_3);
	}
//	BW_Celebrate();

	BW_Buzz(4);
	if(Ping[PING_RIGHT]>=Ping[PING_LEFT])
	{
		while(Ping[PING_FRONT]<20)
		{
			BW_Buzz(1);
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
			mov_rot_right(FAST_LEVEL_3,CLOSE);
			mov_rot_right(FAST_LEVEL_3,CLOSE);
		}
	}

	else if(Ping[PING_LEFT]>=Ping[PING_RIGHT])
	{
		while(Ping[PING_FRONT]<20)
		{
			BW_Buzz(1);
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
			mov_rot_left(FAST_LEVEL_3,CLOSE);
			mov_rot_left(FAST_LEVEL_3,CLOSE);
		}
	}
}


void Object_Follow(void)
{
	Get_IR();
	if(
			(Ping[PING_FRONT]<25) &&
			(INFRARED[IR_FRONT_LEFT]==IR_DETECTED) &&
			(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED)
	  )
	{
//		BW_Celebrate();
		mov_static();
		BW_Buzz(2);
	}

	else
	{
		if( (Ping[PING_ASKEW_RIGHT]<60) || (Ping[PING_RIGHT]<60) )
//		if( (SHARP[SHARP_RIGHT]<60) || (Ping[PING_RIGHT]<60) )
		{
			while(
					(Ping[PING_FRONT]>=55)
				 )
			{
//				mov_rot_right(FAST_LEVEL_3,CLOSE);
				mov_rot_right(FAST_LEVEL_3,CLOSE);
				mov_rot_right(FAST_LEVEL_3,CLOSE);
			}
		}

		else if( (Ping[PING_ASKEW_LEFT]<60) || (Ping[PING_LEFT]<60) )
//		else if( (SHARP[SHARP_LEFT]<60) || (Ping[PING_LEFT]<60) )
		{
			while(
					(Ping[PING_FRONT]>=55)
				 )
			{
//				mov_rot_left(FAST_LEVEL_3,CLOSE);
				mov_rot_left(FAST_LEVEL_3,CLOSE);
				mov_rot_left(FAST_LEVEL_3,CLOSE);
			}
		}
	}

	Get_IR();
	while(
			(Ping[PING_FRONT]>=15) &&
			(INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED) &&
			(INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED)
		 )
	{
		Get_IR();
//		mov_fwd_5cm(10,FAST_LEVEL_3);
		mov_fwd_5cm(10,FAST_LEVEL_3);
	}
}

//void Avoider (void)
//{
//	GetBumper();
//
//	if(BUMPER[LEFT]==1)
//	{
//		BW_Action_A();
//	}
//	if(BUMPER[RIGHT]==1)
//	{
//		BW_Celebrate();
//	}
//
//	if(Ping[PING_FRONT]<=30)
//	{
//		while(Ping[PING_FRONT]<=30)
//		{
//			mov_bwd(10,FAST_LEVEL_3);
//		}
//
//	}
//
//	else if (Ping[PING_RIGHT]<=30)
//	{
//		while(Ping[PING_RIGHT]<=30)
//		{
//			mov_deflect_left(FAST,CLOSE);
//		}
//	}
//
//	else if (Ping[PING_LEFT]<=30)
//	{
//		while(Ping[PING_LEFT]<=30)
//		{
//			mov_deflect_right(FAST,CLOSE);
//		}
//	}
//
//	else if (Ping[PING_ASKEW_RIGHT]<=30)
//	{
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//
//		if(Ping[PING_FRONT]>=30)
//		{
//			mov_fwd_5cm(20,FAST_LEVEL_3);
//		}
//	}
//
//	else if (Ping[PING_ASKEW_LEFT]<=30)
//	{
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//
//		if(Ping[PING_FRONT]>=30)
//		{
//			mov_fwd_5cm(20,FAST_LEVEL_3);
//		}
//	}
//}

/* func      : void FollowTracer_Right(void)
 * brief     : Wall Following Right Rule using PID controller until BW detects TRACER LINE
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Friday, March 18th 2016)
 * Revised BY: N/A
 * programmer's Note:
 *
 */
void FollowTracer_Right(void)
{
	TRACER_IN_BUMPER=TRC_BMP_INACTIVE;
	TRACER_STAT=TRACER_INACTIVE;
	//DISABLE FOLLOW HOME MODE ON TCSlave_Check();
	FOLLOWHOME_FLAG=FOLLOWHOME_INACTIVE;

	//ENABLE INTERRUPT TRACER STAT CHECKING
	FOLLOWTRACER_FLAG=FOLLOWTRACER_ENABLE;

	CAT_FLAG = CAT_NOT_DETECTED;
//	TRACER_STAT=TRACER_INACTIVE;
	TCSlave_Check();

	while(
			(TCS3200_SLV_DATA[1]!=TRACER_ACTIVE) &&
			(TRACER_STAT==TRACER_INACTIVE) &&
			(TRACER_IN_BUMPER==TRC_BMP_INACTIVE) &&
			(CAT_FLAG==CAT_NOT_DETECTED)
		 )
	{
		TCSlave_Check();
		Cat_Avoider();

		if (Ping[PING_FRONT]<=15)
		{
			if (TRACER_STAT==TRACER_ACTIVE)break;

			mov_rot_left(FAST_LEVEL_3, FAR);
			mov_rot_left(FAST_LEVEL_3, FAR);
			GetBumper();
			while(BUMPER[RIGHT]==ACTIVE)
			{
				BW_Buzz(1);
				mov_bwd_3cm(6,FAST_LEVEL_2);
				mov_rot_left(FAST, FAR);
				mov_rot_left(FAST, CLOSE);
//				mov_rot_left(FAST_LEVEL_3, CLOSE);
				GetBumper();
				if(BUMPER[RIGHT]==INACTIVE)break;
			}
			GetBumper();
			while(BUMPER[LEFT]==ACTIVE)
			{
				BW_Buzz(1);
				mov_bwd_3cm(6,FAST_LEVEL_2);
				mov_rot_right(FAST, FAR);
				mov_rot_right(FAST, CLOSE);
//				mov_rot_right(FAST_LEVEL_3, CLOSE);
				GetBumper();
				if(BUMPER[LEFT]==INACTIVE)break;
			}
		}
		else
		{
			if (TRACER_STAT==TRACER_ACTIVE)break;
			PID_FollowTracer_Right();
		}
	}
}

/* func      : void PID_FollowTracer_Right(void)
 * brief     : PID Calculation and actuate control signal
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Friday, March 18th 2016)
 * Revised BY: N/A
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */
void PID_FollowTracer_Right(void)
{
	int OVERRIDE=0;

	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;

	Sendto_PC(USART1,"Ping: %d \t",(int)Ping[PING_ASKEW_RIGHT]);
	PID_Calc_RightRule();
	Sendto_PC(USART1,"PID_F_R.pid_value[0]: %d \r",(int)PID_F_R.pid_value[0]);

	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			if ( (Ping[PING_ASKEW_RIGHT]<=PID_F_R.set_point_upper) && (Ping[PING_ASKEW_RIGHT]>=PID_F_R.set_point_lower) )
				{
					if (Ping[PING_FRONT]<=15)
					{
						mov_rot_left(FAST_LEVEL_3, FAR);
						mov_rot_left(FAST_LEVEL_3, FAR);
						GetBumper();
						while(BUMPER[RIGHT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_left(FAST, FAR);
							mov_rot_left(FAST, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[RIGHT]==INACTIVE) break;
						}
						GetBumper();
						while(BUMPER[LEFT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[LEFT]==INACTIVE)break;
						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

						if (TRACER_STAT==TRACER_ACTIVE)break;
						Sendto_PC(USART1,"BW FORWARD \r");
						mov_fwd_5cm(5, FAST_LEVEL_3);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT JAUH DARI DINDING
			else if ( Ping[PING_ASKEW_RIGHT]>PID_F_R.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
					if (PID_F_R.pid_value[0]>13)
					{
						WINDUP_RIGHT_COUNTER++;
						PID_F_R.pid_value[0]=13; //WINDUP
					}

					if (Ping[PING_FRONT]<=15)
					{
						mov_rot_left(FAST_LEVEL_3, FAR);
						mov_rot_left(FAST_LEVEL_3, FAR);
						GetBumper();
						while(BUMPER[RIGHT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_left(FAST, FAR);
							mov_rot_left(FAST, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[RIGHT]==INACTIVE) break;
						}
						GetBumper();
						while(BUMPER[LEFT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[LEFT]==INACTIVE)break;
						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if (TRACER_STAT==TRACER_ACTIVE)break;

						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>=15)
							{
								if (TRACER_STAT==TRACER_ACTIVE)break;
								mov_fwd_5cm(5, FAST_LEVEL_3);
								GetBumper();
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_RIGHT]>=16)
							{
								mov_rot_left(FAST_LEVEL_3, FAR);
								mov_rot_left(FAST_LEVEL_3, FAR);
								GetBumper();
								while(BUMPER[RIGHT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_2);
									mov_rot_left(FAST, FAR);
									mov_rot_left(FAST, CLOSE);
//									mov_rot_left(FAST_LEVEL_3, CLOSE);
									GetBumper();
									if(BUMPER[RIGHT]==INACTIVE) break;
								}
								GetBumper();
								while(BUMPER[LEFT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_2);
									mov_rot_right(FAST, FAR);
									mov_rot_right(FAST, CLOSE);
//									mov_rot_right(FAST_LEVEL_3, CLOSE);
									GetBumper();
									if(BUMPER[LEFT]==INACTIVE)break;
								}
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
							mov_fwd_3cm(3,FAST_LEVEL_3);

							GetBumper();
							while(BUMPER[RIGHT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_left(FAST, FAR);
								mov_rot_left(FAST, CLOSE);
//								mov_rot_left(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[RIGHT]==INACTIVE) break;
							}
							GetBumper();
							while(BUMPER[LEFT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_right(FAST, FAR);
								mov_rot_right(FAST, CLOSE);
//								mov_rot_right(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[LEFT]==INACTIVE)break;
							}


						}

						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT DEKAT DENGAN DINDING
			else if ( Ping[PING_ASKEW_RIGHT]<PID_F_R.set_point )
				{

					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
					if (PID_F_R.pid_value[0]>13)
					{
						WINDUP_LEFT_COUNTER++;
						PID_F_R.pid_value[0]=13; //WINDUP
					}

					if (Ping[PING_FRONT]<=15)
					{
						mov_rot_left(FAST_LEVEL_3, FAR);
						mov_rot_left(FAST_LEVEL_3, FAR);
						GetBumper();
						while(BUMPER[RIGHT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_left(FAST, FAR);
							mov_rot_left(FAST, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[RIGHT]==INACTIVE) break;
						}
						GetBumper();
						while(BUMPER[LEFT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[LEFT]==INACTIVE)break;
						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if (TRACER_STAT==TRACER_ACTIVE) break;

						if(WINDUP_LEFT_COUNTER>=25)
							{
								BW_Buzz(5);
								lcd_display_clear();
								lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
								delay_ms(100);

								while(Ping[PING_FRONT]>=15)
								{
									if (TRACER_STAT==TRACER_ACTIVE)break;
									mov_fwd_5cm(5, FAST_LEVEL_3);
									GetBumper();
									if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
								}
								while(Ping[PING_RIGHT]>=16)
								{
									mov_rot_left(FAST_LEVEL_3, FAR);
									mov_rot_left(FAST_LEVEL_3, FAR);
									GetBumper();
									while(BUMPER[RIGHT]==ACTIVE)
									{
										BW_Buzz(1);
										mov_bwd_3cm(6,FAST_LEVEL_2);
										mov_rot_left(FAST, FAR);
										mov_rot_left(FAST, CLOSE);
//										mov_rot_left(FAST_LEVEL_3, CLOSE);
										GetBumper();
										if(BUMPER[RIGHT]==INACTIVE) break;
									}
									GetBumper();
									while(BUMPER[LEFT]==ACTIVE)
									{
										BW_Buzz(1);
										mov_bwd_3cm(6,FAST_LEVEL_2);
										mov_rot_right(FAST, FAR);
										mov_rot_right(FAST, CLOSE);
//										mov_rot_right(FAST_LEVEL_3, CLOSE);
										GetBumper();
										if(BUMPER[LEFT]==INACTIVE)break;
									}
								}
								//RESET WINDUP RIGHT COUNTER
								WINDUP_LEFT_COUNTER=0;

								//REINIT PID
								BW_PID_Init();
							}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

							GetBumper();
							while(BUMPER[RIGHT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_left(FAST, FAR);
								mov_rot_left(FAST, CLOSE);
//								mov_rot_left(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[RIGHT]==INACTIVE) break;
							}
							GetBumper();
							while(BUMPER[LEFT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_right(FAST, FAR);
								mov_rot_right(FAST, CLOSE);
//								mov_rot_right(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[LEFT]==INACTIVE)break;
							}
							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
							mov_fwd_3cm(3,FAST_LEVEL_3);
						}

						OVERRIDE=1;
					}

				}
		}
	}

}

/* func      : void FollowTracer_Right_Reverse(void)
 * brief     : Wall Following Right Reverse Rule using PID controller until BW detects TRACER LINE
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (Wed, Dec 21st 2016)
 * Revised BY: N/A
 * programmer's Note:
 *
 */
void FollowTracer_Right_Reverse (void)
{
	TRACER_IN_BUMPER=TRC_BMP_INACTIVE;
	TRACER_STAT=TRACER_INACTIVE;
	//DISABLE FOLLOW HOME MODE ON TCSlave_Check();
	FOLLOWHOME_FLAG=FOLLOWHOME_INACTIVE;

	//ENABLE INTERRUPT TRACER STAT CHECKING
	FOLLOWTRACER_FLAG=FOLLOWTRACER_ENABLE;

	CAT_FLAG = CAT_NOT_DETECTED;
	TCSlave_Check();

	while(
			(TCS3200_SLV_DATA[1]!=TRACER_ACTIVE) &&
			(TRACER_STAT==TRACER_INACTIVE) &&
			(TRACER_IN_BUMPER==TRC_BMP_INACTIVE) &&
			(CAT_FLAG==CAT_NOT_DETECTED)
		 )
	{
		TCSlave_Check();
		Cat_Avoider();

		if (Ping[PING_REAR]<=15)
		{
			if (TRACER_STAT==TRACER_ACTIVE)break;

			mov_rot_right_reverse(FAST_LEVEL_3, FAR);
			mov_rot_right_reverse(FAST_LEVEL_3, FAR);
		}
		else
		{
			if (TRACER_STAT==TRACER_ACTIVE)break;
			PID_FollowTracer_Right_Reverse();
		}
	}
}

/* func      : void PID_FollowTracer_Right_Reverse (void)
 * brief     : PID Calculation and actuate control signal
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (Wed, Dec 21st 2016)
 * Revised BY: N/A
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */

void PID_FollowTracer_Right_Reverse (void)
{
	int OVERRIDE=0;

	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;

	PID_Calc_RightRule_Reverse();

	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			if ( (Ping[PING_REAR_RIGHT]<=PID_F_R.set_point_upper) && (Ping[PING_REAR_RIGHT]>=PID_F_R.set_point_lower) )
				{
					if (Ping[PING_REAR]<=15)
					{
						mov_rot_right_reverse(FAST_LEVEL_3, FAR);
						mov_rot_right_reverse(FAST_LEVEL_3, FAR);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

						if (TRACER_STAT==TRACER_ACTIVE)break;
						Sendto_PC(USART1,"BW FORWARD \r");
						mov_bwd_5cm(5, FAST_LEVEL_3);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT JAUH DARI DINDING
			else if ( Ping[PING_REAR_RIGHT]>PID_F_R.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
					if (PID_F_R.pid_value[0]>13)
					{
						WINDUP_RIGHT_COUNTER++;
						PID_F_R.pid_value[0]=13; //WINDUP
					}

					if (Ping[PING_REAR]<=15)
					{
						mov_rot_right_reverse(FAST_LEVEL_3, FAR);
						mov_rot_right_reverse(FAST_LEVEL_3, FAR);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if (TRACER_STAT==TRACER_ACTIVE)break;

						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_REAR]>=15)
							{
								if (TRACER_STAT==TRACER_ACTIVE)break;
								mov_bwd_5cm(5, FAST_LEVEL_3);
//								GetBumper();
//								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_RIGHT]>=16)
							{
								mov_rot_right_reverse(FAST_LEVEL_3, FAR);
								mov_rot_right_reverse(FAST_LEVEL_3, FAR);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

							//==BELUM DI GANTI==//
							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
							//==================//

							mov_bwd_3cm(3,FAST_LEVEL_3);
						}
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT DEKAT DENGAN DINDING
			else if ( Ping[PING_REAR_RIGHT]<PID_F_R.set_point )
				{

					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
					if (PID_F_R.pid_value[0]>13)
					{
						WINDUP_LEFT_COUNTER++;
						PID_F_R.pid_value[0]=13; //WINDUP
					}

					if (Ping[PING_REAR]<=15)
					{
						mov_rot_right_reverse(FAST_LEVEL_3, FAR);
						mov_rot_right_reverse(FAST_LEVEL_3, FAR);
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if (TRACER_STAT==TRACER_ACTIVE) break;

						if(WINDUP_LEFT_COUNTER>=25)
							{
								BW_Buzz(5);
								lcd_display_clear();
								lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
								delay_ms(100);

								while(Ping[PING_REAR]>=15)
								{
									if (TRACER_STAT==TRACER_ACTIVE)break;
									mov_bwd_5cm(5, FAST_LEVEL_3);
//									GetBumper();
//									if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
								}
								while(Ping[PING_RIGHT]>=16)
								{
									mov_rot_right_reverse(FAST_LEVEL_3, FAR);
									mov_rot_right_reverse(FAST_LEVEL_3, FAR);
								}
								//RESET WINDUP RIGHT COUNTER
								WINDUP_LEFT_COUNTER=0;

								//REINIT PID
								BW_PID_Init();
							}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

							//==BELUM DIGANTI==//
							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
							//=================//

							mov_bwd_3cm(3,FAST_LEVEL_3);
						}

						OVERRIDE=1;
					}

				}
		}
	}

}

/* func      : void FollowTracer_Left(void)
 * brief     : Wall Following Left Rule using PID controller until BW detects TRACER LINE
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Friday, March 18th 2016)
 * Revised BY: N/A
 * programmer's Note:
 *
 */
void FollowTracer_Left(void)
{
	TRACER_IN_BUMPER=TRC_BMP_INACTIVE;
	TRACER_STAT=TRACER_INACTIVE;
	//DISABLE FOLLOW HOME MODE ON TCSlave_Check();
	FOLLOWHOME_FLAG=FOLLOWHOME_INACTIVE;

	//ENABLE INTERRUPT TRACER STAT CHECKING
	FOLLOWTRACER_FLAG=FOLLOWTRACER_ENABLE;
	CAT_FLAG=CAT_NOT_DETECTED;

	TCSlave_Check();

	while(
			(TRACER_IN_BUMPER==TRC_BMP_INACTIVE) &&
			(TCS3200_SLV_DATA[1]!=TRACER_ACTIVE) &&
			(TRACER_STAT==TRACER_INACTIVE) &&
			(CAT_FLAG==CAT_NOT_DETECTED)
		 )
	{
		TCSlave_Check();
		Cat_Avoider();

		if (Ping[PING_FRONT]<=14)
		{
			if (TRACER_STAT==TRACER_ACTIVE)break;
			Sendto_PC(USART1,"BW ROTATE RIGHT \r");
			mov_rot_right(FAST_LEVEL_3, FAR);
			mov_rot_right(FAST_LEVEL_3, FAR);
		}
		else
		{
			if (TRACER_STAT==TRACER_ACTIVE)break;
			PID_FollowTracer_Left();
		}
	}
}

/* func      : void PID_FollowTracer_Left(void)
 * brief     : PID Calculation and actuate control signal
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Friday, March 18th 2016)
 * Revised BY: N/A
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */
void PID_FollowTracer_Left(void)
{
	//int limit= *COMMAND_LOOP;
	int OVERRIDE=0;
	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;

	PID_Calc_LeftRule();

	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
			if ( (Ping[PING_ASKEW_LEFT]<=PID_F_L.set_point_upper) && (Ping[PING_ASKEW_LEFT]>=PID_F_L.set_point_lower) )
//			if ( (SHARP[SHARP_LEFT]<=PID_F_L.set_point_upper) && (SHARP[SHARP_LEFT]>=PID_F_L.set_point_lower) )
				{
					if (Ping[PING_FRONT]<=14)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
						mov_rot_right(FAST_LEVEL_3, FAR);
						mov_rot_right(FAST_LEVEL_3, FAR);
						GetBumper();
						while(BUMPER[LEFT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, FAR);

							GetBumper();
							if(BUMPER[LEFT]==INACTIVE) break;
						}
						while(BUMPER[RIGHT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_left(FAST, FAR);
							mov_rot_left(FAST, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, FAR);
							GetBumper();
							if(BUMPER[RIGHT]==INACTIVE) break;
						}
//						if (Ping[PING_LEFT]>=15)
//						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
//						if (Ping[PING_LEFT]<15)
//						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

						if (TRACER_STAT==TRACER_ACTIVE)break;
						Sendto_PC(USART1,"BW FORWARD \r");
//						mov_fwd_5cm(5, FAST_LEVEL_3);
						mov_fwd_5cm(5, FAST_LEVEL_3);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT DEKAT DARI DINDING
			else if ( Ping[PING_ASKEW_LEFT]<PID_F_L.set_point )
//			else if ( SHARP[SHARP_LEFT]<PID_F_L.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
					if (PID_F_L.pid_value[0]>13)
					{
						WINDUP_RIGHT_COUNTER++;
						PID_F_L.pid_value[0]=13; //WINDUP
					}

					if (Ping[PING_FRONT]<=14)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
						mov_rot_right(FAST_LEVEL_3, FAR);
						mov_rot_right(FAST_LEVEL_3, FAR);
						GetBumper();
						while(BUMPER[LEFT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, FAR);
							GetBumper();
							if(BUMPER[LEFT]==INACTIVE)break;
						}
						while(BUMPER[RIGHT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_left(FAST, FAR);
							mov_rot_left(FAST, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, FAR);
							GetBumper();
							if(BUMPER[RIGHT]==INACTIVE) break;
						}
//						if (Ping[PING_LEFT]>=20)
//						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
//						if (Ping[PING_LEFT]<20)
//						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if (TRACER_STAT==TRACER_ACTIVE)break;

						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>=14)
							{
//								mov_fwd_5cm(5,FAST_LEVEL_3);
								mov_fwd_5cm(5,FAST_LEVEL_3);
								GetBumper();
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_LEFT]>=16)
							{
//								mov_rot_right(FAST_LEVEL_3,CLOSE);
//								mov_rot_right(FAST_LEVEL_3,CLOSE);
								mov_rot_right(FAST_LEVEL_3, FAR);
								mov_rot_right(FAST_LEVEL_3, FAR);
								GetBumper();
								while(BUMPER[LEFT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_2);
									mov_rot_right(FAST, FAR);
									mov_rot_right(FAST, CLOSE);
//									mov_rot_right(FAST_LEVEL_3, FAR);
									GetBumper();
									if(BUMPER[LEFT]==INACTIVE) break;
								}
								while(BUMPER[RIGHT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_2);
									mov_rot_left(FAST, FAR);
									mov_rot_left(FAST, CLOSE);
//									mov_rot_left(FAST_LEVEL_3, FAR);
									GetBumper();
									if(BUMPER[RIGHT]==INACTIVE) break;
								}
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}
						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

//							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);
							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);
							GetBumper();
							while(BUMPER[LEFT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_right(FAST, FAR);
								mov_rot_right(FAST, CLOSE);
//								mov_rot_right(FAST_LEVEL_3, FAR);
								GetBumper();
								if(BUMPER[LEFT]==INACTIVE) break;
							}
							while(BUMPER[RIGHT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_left(FAST, FAR);
								mov_rot_left(FAST, CLOSE);
//								mov_rot_left(FAST_LEVEL_3, FAR);
								GetBumper();
								if(BUMPER[RIGHT]==INACTIVE) break;
							}
						}


						OVERRIDE=1;
					}

				}

			//KONDISI ROBOT JAUH DENGAN DINDING
			else if ( Ping[PING_ASKEW_LEFT]>PID_F_L.set_point )
//			else if ( SHARP[SHARP_LEFT]>PID_F_L.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
					if (PID_F_L.pid_value[0]>13)
					{
						WINDUP_LEFT_COUNTER++;
						PID_F_L.pid_value[0]=13;
					}

					if (Ping[PING_FRONT]<=14)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
						mov_rot_right(FAST_LEVEL_3, FAR);
						mov_rot_right(FAST_LEVEL_3, FAR);
						GetBumper();
						while(BUMPER[LEFT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, FAR);
							GetBumper();
							if(BUMPER[LEFT]==INACTIVE) break;
						}
						while(BUMPER[RIGHT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_left(FAST, FAR);
							mov_rot_left(FAST, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, FAR);
							GetBumper();
							if(BUMPER[RIGHT]==INACTIVE) break;
						}
//						if (Ping[PING_LEFT]>=20)
//						{
//
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
//						if (Ping[PING_LEFT]<20)
//						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if (TRACER_STAT==TRACER_ACTIVE)break;

						if(WINDUP_LEFT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>=14)
							{
//								mov_fwd_5cm(5,FAST_LEVEL_3);
								mov_fwd_5cm(5,FAST_LEVEL_3);
								GetBumper();
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_LEFT]>=16)
							{
//								mov_rot_right(FAST_LEVEL_3,CLOSE);
//								mov_rot_right(FAST_LEVEL_3,CLOSE);
								mov_rot_right(FAST_LEVEL_3, FAR);
								mov_rot_right(FAST_LEVEL_3, FAR);
								GetBumper();
								while(BUMPER[LEFT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_2);
									mov_rot_right(FAST, FAR);
									mov_rot_right(FAST, CLOSE);
//									mov_rot_right(FAST_LEVEL_3, FAR);
									GetBumper();
									if(BUMPER[LEFT]==INACTIVE) break;
								}
								while(BUMPER[RIGHT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_2);
									mov_rot_left(FAST, FAR);
									mov_rot_left(FAST, CLOSE);
//									mov_rot_left(FAST_LEVEL_3, FAR);
									GetBumper();
									if(BUMPER[RIGHT]==INACTIVE) break;
								}
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_LEFT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}
						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

//							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);
							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);
							GetBumper();
							while(BUMPER[LEFT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_right(FAST, FAR);
								mov_rot_right(FAST, CLOSE);
//								mov_rot_right(FAST_LEVEL_3, FAR);
								GetBumper();
								if(BUMPER[LEFT]==INACTIVE) break;
							}
							while(BUMPER[RIGHT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_left(FAST, FAR);
								mov_rot_left(FAST, CLOSE);
//								mov_rot_left(FAST_LEVEL_3, FAR);
								GetBumper();
								if(BUMPER[RIGHT]==INACTIVE) break;
							}
						}
						OVERRIDE=1;
					}

				}
		}
	}

}


/* func      : void FollowCarpet_Right(int CARPET_CODE, int FOLLOW_MODE)
 * brief     : Wall Following Right Rule using PID controller until BW detects desired carpet
 * param     : 	int CARPET CODE:
 *
 * 					COLOUR_NONE		-> 0
 * 					COLOUR_BLACK 	-> 1
 * 					COLOUR_GRAY		-> 2
 * 					COLOUR_WHITE	-> 3
 * 					COLOUR_RED		-> 4
 * 					COLOUR_BLUE		-> 5
 *
 * 				int FOLLOW_MODE:
 * 					NORMAL 	-> 1
 * 					INVERSE -> 2
 * retval    : N/A
 * Ver       : 3
 * written By: Ryan (Friday, March 18th 2016)
 * Revised By: Ver. 2 -> Ryan (Thursday, April 21st 2016
 * 					Configured for the new Hybrid TCS3200+Tracer Processor
 * programmer's Note:
 *
 */
void FollowCarpet_Right(int CARPET_CODE, int FOLLOW_MODE)
{
//	int counter;
	//int limit=15;
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);

	//DISABLE FOLLOW HOME MODE ON TCSlave_Check();
	FOLLOWHOME_FLAG=FOLLOWHOME_INACTIVE;
	CAT_FLAG=CAT_NOT_DETECTED;

	switch(FOLLOW_MODE)
	{
		case NORMAL: //BW FOLLOW WHILE CARPET == X
				{
					while( (TCS3200_SLV_DATA[0]==CARPET_CODE) && (CAT_FLAG==CAT_NOT_DETECTED) )
					{
						Cat_Avoider();

						TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
						if (Ping[PING_FRONT]<=16)
						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, FAR);
							mov_rot_left(FAST_LEVEL_3, FAR);
							GetBumper();
							while(BUMPER[RIGHT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_left(FAST, FAR);
								mov_rot_left(FAST, CLOSE);
				//				mov_rot_left(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[RIGHT]==INACTIVE)break;
							}
							GetBumper();
							while(BUMPER[LEFT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_right(FAST, FAR);
								mov_rot_right(FAST, CLOSE);
				//				mov_rot_right(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[LEFT]==INACTIVE)break;
							}
//							if (Ping[PING_RIGHT]<=20)
//							{
//								Sendto_PC(USART1,"BW ROTATE LEFT \r");
//								mov_rot_left(FAST_LEVEL_3, CLOSE);
//							}
//
//							if (Ping[PING_RIGHT]>20)
//							{
//								Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//								mov_rot_right(FAST_LEVEL_3, CLOSE);
//							}
						}
						else
						{
							PID_FollowCarpet_Right();
						}
					}
				}break;


		case INVERSE: ////BW FOLLOW WHILE CARPET != X
				{
					while( (TCS3200_SLV_DATA[0]!=CARPET_CODE) && (CAT_FLAG==CAT_NOT_DETECTED) )
					{
						Cat_Avoider();

						TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
						if (Ping[PING_FRONT]<=16)
						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, FAR);
							mov_rot_left(FAST_LEVEL_3, FAR);
							GetBumper();
							while(BUMPER[RIGHT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_left(FAST, FAR);
								mov_rot_left(FAST, CLOSE);
				//				mov_rot_left(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[RIGHT]==INACTIVE)break;
							}
							GetBumper();
							while(BUMPER[LEFT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_right(FAST, FAR);
								mov_rot_right(FAST, CLOSE);
				//				mov_rot_right(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[LEFT]==INACTIVE)break;
							}
//							if (Ping[PING_RIGHT]<=20)
//							{
//								Sendto_PC(USART1,"BW ROTATE LEFT \r");
//								mov_rot_left(FAST_LEVEL_3, CLOSE);
//							}
//
//							if (Ping[PING_RIGHT]>20)
//							{
//								Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//								mov_rot_right(FAST_LEVEL_3, CLOSE);
//							}
						}
						else
						{
							PID_FollowCarpet_Right();
						}
					}
				}break;
	}
}


/* func      : void PID_FollowCarpet_Right(void)
 * brief     : PID Calculation and actuate control signal
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Friday, March 18th 2016)
 * Revised BY: N/A
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */
void PID_FollowCarpet_Right(void)
{
	//int limit= *COMMAND_LOOP;
	int OVERRIDE=0;
	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;

	Sendto_PC(USART1,"Ping: %d \t",(int)Ping[PING_ASKEW_RIGHT]);
	PID_Calc_RightRule();
	Sendto_PC(USART1,"PID_F_R.pid_value[0]: %d \r",(int)PID_F_R.pid_value[0]);


	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
			if ( (Ping[PING_ASKEW_RIGHT]<=PID_F_R.set_point_upper) && (Ping[PING_ASKEW_RIGHT]>=PID_F_R.set_point_lower) )
//			if ( (SHARP[SHARP_RIGHT]<=PID_F_R.set_point_upper) && (SHARP[SHARP_RIGHT]>=PID_F_R.set_point_lower) )
				{
					if (Ping[PING_FRONT]<=16)
					{
//						mov_rot_left(FAST_LEVEL_3, CLOSE);
//						mov_rot_left(FAST_LEVEL_3, CLOSE);
						mov_rot_left(FAST_LEVEL_3, FAR);
						mov_rot_left(FAST_LEVEL_3, FAR);
						GetBumper();
						while(BUMPER[RIGHT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_left(FAST, FAR);
							mov_rot_left(FAST, CLOSE);
			//				mov_rot_left(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[RIGHT]==INACTIVE)break;
						}
						GetBumper();
						while(BUMPER[LEFT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, CLOSE);
			//				mov_rot_right(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[LEFT]==INACTIVE)break;
						}
//						if (Ping[PING_RIGHT]<=20)
//						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
//						if (Ping[PING_RIGHT]>20)
//						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

						Sendto_PC(USART1,"BW FORWARD \r");
//						mov_fwd_5cm(5, FAST_LEVEL_3);
						mov_fwd_5cm(5, FAST_LEVEL_3);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT JAUH DARI DINDING
			else if ( Ping[PING_ASKEW_RIGHT]>PID_F_R.set_point )
//			else if ( SHARP[SHARP_RIGHT]>PID_F_R.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
					if (PID_F_R.pid_value[0]>13)
					{
						WINDUP_RIGHT_COUNTER++;
						PID_F_R.pid_value[0]=13; //WINDUP
					}

					if (Ping[PING_FRONT]<=16)
					{
//						mov_rot_left(FAST_LEVEL_3, CLOSE);
//						mov_rot_left(FAST_LEVEL_3, CLOSE);
						mov_rot_left(FAST_LEVEL_3, FAR);
						mov_rot_left(FAST_LEVEL_3, FAR);
						GetBumper();
						while(BUMPER[RIGHT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_left(FAST, FAR);
							mov_rot_left(FAST, CLOSE);
			//				mov_rot_left(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[RIGHT]==INACTIVE)break;
						}
						GetBumper();
						while(BUMPER[LEFT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, CLOSE);
			//				mov_rot_right(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[LEFT]==INACTIVE)break;
						}
//						if (Ping[PING_RIGHT]<=20)
//						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
//						if (Ping[PING_RIGHT]>20)
//						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>=16)
							{
//								mov_fwd_5cm(5,FAST_LEVEL_3);
								mov_fwd_5cm(5,FAST_LEVEL_3);
								GetBumper();
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_RIGHT]>=16)
							{
//								mov_rot_left(FAST_LEVEL_3,CLOSE);
//								mov_rot_left(FAST_LEVEL_3,CLOSE);
								mov_rot_left(FAST_LEVEL_3, FAR);
								mov_rot_left(FAST_LEVEL_3, FAR);
								GetBumper();
								while(BUMPER[RIGHT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_2);
									mov_rot_left(FAST, FAR);
									mov_rot_left(FAST, CLOSE);
					//				mov_rot_left(FAST_LEVEL_3, CLOSE);
									GetBumper();
									if(BUMPER[RIGHT]==INACTIVE)break;
								}
								GetBumper();
								while(BUMPER[LEFT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_2);
									mov_rot_right(FAST, FAR);
									mov_rot_right(FAST, CLOSE);
					//				mov_rot_right(FAST_LEVEL_3, CLOSE);
									GetBumper();
									if(BUMPER[LEFT]==INACTIVE)break;
								}
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

//							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
//							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
							mov_fwd_3cm(3,FAST_LEVEL_3);
							GetBumper();
							while(BUMPER[RIGHT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_left(FAST_LEVEL_3, FAR);
								mov_rot_left(FAST_LEVEL_3, CLOSE);
				//				mov_rot_left(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[RIGHT]==INACTIVE)break;
							}
							GetBumper();
							while(BUMPER[LEFT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_right(FAST, FAR);
								mov_rot_right(FAST, CLOSE);
				//				mov_rot_right(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[LEFT]==INACTIVE)break;
							}
						}

						OVERRIDE=1;
					}

				}

			//KONDISI ROBOT DEKAT DENGAN DINDING
			else if ( Ping[PING_ASKEW_RIGHT]<PID_F_R.set_point )
//			else if ( SHARP[SHARP_RIGHT]<PID_F_R.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
					if (PID_F_R.pid_value[0]>13)
					{
						WINDUP_LEFT_COUNTER++;
						PID_F_R.pid_value[0]=13; //WINDUP
					}

					if (Ping[PING_FRONT]<=16)
					{
//						mov_rot_left(FAST_LEVEL_3, CLOSE);
//						mov_rot_left(FAST_LEVEL_3, CLOSE);
						mov_rot_left(FAST_LEVEL_3, FAR);
						mov_rot_left(FAST_LEVEL_3, FAR);
						GetBumper();
						while(BUMPER[RIGHT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_left(FAST, FAR);
							mov_rot_left(FAST, CLOSE);
			//				mov_rot_left(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[RIGHT]==INACTIVE)break;
						}
						GetBumper();
						while(BUMPER[LEFT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, CLOSE);
			//				mov_rot_right(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[LEFT]==INACTIVE)break;
						}
//						if (Ping[PING_RIGHT]<=20)
//						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
//						if (Ping[PING_RIGHT]>20)
//						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_LEFT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>=16)
							{
//								mov_fwd_5cm(5,FAST_LEVEL_3);
								mov_fwd_5cm(5,FAST_LEVEL_3);
								GetBumper();
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_RIGHT]>=16)
							{
//								mov_rot_left(FAST_LEVEL_3,CLOSE);
//								mov_rot_left(FAST_LEVEL_3,CLOSE);
								mov_rot_left(FAST_LEVEL_3, FAR);
								mov_rot_left(FAST_LEVEL_3, FAR);
								GetBumper();
								while(BUMPER[RIGHT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_2);
									mov_rot_left(FAST, FAR);
									mov_rot_left(FAST, CLOSE);
					//				mov_rot_left(FAST_LEVEL_3, CLOSE);
									GetBumper();
									if(BUMPER[RIGHT]==INACTIVE)break;
								}
								GetBumper();
								while(BUMPER[LEFT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_2);
									mov_rot_right(FAST, FAR);
									mov_rot_right(FAST, CLOSE);
					//				mov_rot_right(FAST_LEVEL_3, CLOSE);
									GetBumper();
									if(BUMPER[LEFT]==INACTIVE)break;
								}
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_LEFT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;
							GetBumper();
							while(BUMPER[RIGHT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_left(FAST, FAR);
								mov_rot_left(FAST, CLOSE);
				//				mov_rot_left(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[RIGHT]==INACTIVE)break;
							}
							GetBumper();
							while(BUMPER[LEFT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_right(FAST, FAR);
								mov_rot_right(FAST, CLOSE);
				//				mov_rot_right(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[LEFT]==INACTIVE)break;
							}
//							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
//							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
							mov_fwd_3cm(3,FAST_LEVEL_3);
						}

						OVERRIDE=1;
					}

				}
		}
	}

}


/* func      : void FollowCarpet_Left(int CARPET_CODE, int FOLLOW_MODE)
 * brief     : Wall Following Left Rule using PID controller until BW detects desired carpet
 * param     : 	int CARPET CODE:
 *
 * 					COLOUR_NONE		-> 0
 * 					COLOUR_BLACK 	-> 1
 * 					COLOUR_GRAY		-> 2
 * 					COLOUR_WHITE	-> 3
 * 					COLOUR_RED		-> 4
 * 					COLOUR_BLUE		-> 5
 *
 * 				int FOLLOW_MODE:
 * 					NORMAL 	-> 1
 * 					INVERSE -> 2
 * retval    : N/A
 * Ver       : 3
 * written By: Ryan (Friday, March 18th 2016)
 * Revised By:
 * 				Ver. 2 -> Ryan (Thursday, April 21st 2016
 * 					Configured for the new Hybrid TCS3200+Tracer Processor
 * programmer's Note:
 *
 */
void FollowCarpet_Left(int CARPET_CODE, int FOLLOW_MODE)
{

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
//	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
//	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
//	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);

	//DISABLE FOLLOW HOME MODE ON TCSlave_Check();
	FOLLOWHOME_FLAG=FOLLOWHOME_INACTIVE;
	CAT_FLAG= CAT_NOT_DETECTED;

	switch(FOLLOW_MODE)
	{
		case NORMAL:
				{
					while(
							(TCS3200_SLV_DATA[0]==CARPET_CODE) &&
							(CAT_FLAG==CAT_NOT_DETECTED)
//							(TCS3200_SLV_DATA[1]==CARPET_CODE)
						 )
					{
						Cat_Avoider();

						TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
						if (Ping[PING_FRONT]<=14)
						{
							Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, FAR);
							mov_rot_right(FAST_LEVEL_3, FAR);

							GetBumper();
							while(BUMPER[RIGHT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_left(FAST, FAR);
								mov_rot_left(FAST, CLOSE);
				//				mov_rot_left(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[RIGHT]==INACTIVE)break;
							}
							GetBumper();
							while(BUMPER[LEFT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_right(FAST, FAR);
								mov_rot_right(FAST, CLOSE);
				//				mov_rot_right(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[LEFT]==INACTIVE)break;
							}
//							if (Ping[PING_LEFT]>=20)
//							{
//								Sendto_PC(USART1,"BW ROTATE LEFT \r");
//								mov_rot_left(FAST_LEVEL_3, CLOSE);
//								mov_rot_left(FAST_LEVEL_3, CLOSE);
//							}
//
//							if (Ping[PING_LEFT]<20)
//							{
//								Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//								mov_rot_right(FAST_LEVEL_3, CLOSE);
//								mov_rot_right(FAST_LEVEL_3, CLOSE);
//							}
						}
						else
						{
							PID_FollowCarpet_Left();
						}
					}
				}break;

		case INVERSE:
				{
					while(
							(TCS3200_SLV_DATA[0]!=CARPET_CODE) &&
							(CAT_FLAG==CAT_NOT_DETECTED)//||
//							(TCS3200_SLV_DATA[1]!=CARPET_CODE)
						 )
					{
						Cat_Avoider();

						TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
						if (Ping[PING_FRONT]<=14)
						{
							Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, FAR);
							mov_rot_right(FAST_LEVEL_3, FAR);

							GetBumper();
							while(BUMPER[RIGHT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_left(FAST, FAR);
								mov_rot_left(FAST, CLOSE);
				//				mov_rot_left(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[RIGHT]==INACTIVE)break;
							}
							GetBumper();
							while(BUMPER[LEFT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_right(FAST, FAR);
								mov_rot_right(FAST, CLOSE);
				//				mov_rot_right(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[LEFT]==INACTIVE)break;
							}
//							if (Ping[PING_LEFT]>=20)
//							{
//								Sendto_PC(USART1,"BW ROTATE LEFT \r");
//								mov_rot_left(FAST_LEVEL_3, CLOSE);
//								mov_rot_left(FAST_LEVEL_3, CLOSE);
//							}
//
//							if (Ping[PING_LEFT]<20)
//							{
//								Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//								mov_rot_right(FAST_LEVEL_3, CLOSE);
//								mov_rot_right(FAST_LEVEL_3, CLOSE);
//							}
						}
						else
						{
							PID_FollowCarpet_Left();
						}
					}
				}break;
	}
}

/* func      : void PID_FollowTracer_Left(void)
 * brief     : PID Calculation and actuate control signal
 * param     : N/A
 * retval    : N/A
 * Ver       : 3
 * written By: Ryan (Friday, March 18th 2016)
 * Revised BY: Ver 3. Toni (Wed, November 30th 2016)
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */
void PID_FollowCarpet_Left(void)
{
	//int limit= *COMMAND_LOOP;
	int OVERRIDE=0;

	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;

	PID_Calc_LeftRule();

	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
			if ( (Ping[PING_ASKEW_LEFT]<=PID_F_L.set_point_upper) && (Ping[PING_ASKEW_LEFT]>=PID_F_L.set_point_lower) )
//			if ( (SHARP[SHARP_LEFT]<=PID_F_L.set_point_upper) && (SHARP[SHARP_LEFT]>=PID_F_L.set_point_lower) )
				{
					if (Ping[PING_FRONT]<=14)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
						mov_rot_right(FAST_LEVEL_3, FAR);
						mov_rot_right(FAST_LEVEL_3, FAR);

						GetBumper();
						while(BUMPER[RIGHT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_left(FAST, FAR);
							mov_rot_left(FAST, CLOSE);
			//				mov_rot_left(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[RIGHT]==INACTIVE)break;
						}
						GetBumper();
						while(BUMPER[LEFT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, CLOSE);
			//				mov_rot_right(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[LEFT]==INACTIVE)break;
						}
//						if (Ping[PING_LEFT]>=20)
//						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
//						if (Ping[PING_LEFT]<20)
//						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

						Sendto_PC(USART1,"BW FORWARD \r");
//						mov_fwd_5cm(5, FAST_LEVEL_3);
						mov_fwd_5cm(5, FAST_LEVEL_3);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT DEKAT DARI DINDING
			else if ( Ping[PING_ASKEW_LEFT]<PID_F_L.set_point )
//			else if ( SHARP[SHARP_LEFT]<PID_F_L.set_point )
				{
					//RESET WINDUP RIGHT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
					if (PID_F_L.pid_value[0]>13)
					{
						WINDUP_RIGHT_COUNTER++;
						PID_F_L.pid_value[0]=13; //WINDUP
					}

					if (Ping[PING_FRONT]<=14)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
						mov_rot_right(FAST_LEVEL_3, FAR);
						mov_rot_right(FAST_LEVEL_3, FAR);

						GetBumper();
						while(BUMPER[RIGHT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_left(FAST, FAR);
							mov_rot_left(FAST, CLOSE);
			//				mov_rot_left(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[RIGHT]==INACTIVE)break;
						}
						GetBumper();
						while(BUMPER[LEFT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, CLOSE);
			//				mov_rot_right(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[LEFT]==INACTIVE)break;
						}
//						if (Ping[PING_LEFT]>=20)
//						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
//						if (Ping[PING_LEFT]<20)
//						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

//							Sendto_PC(USART1,"BW ROTATE RIGHT \r");
////							mov_rot_right(FAST_LEVEL_3, CLOSE);
////							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, FAR);
//							mov_rot_right(FAST_LEVEL_3, FAR);
//
////							while(Ping[PING_FRONT]>=18)
////							{
////								mov_fwd_5cm(5,FAST_LEVEL_3);
////								GetBumper();
////								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
////							}
////							while(Ping[PING_LEFT]>=15)
////							{
////								mov_rot_right(FAST_LEVEL_3,CLOSE);
////								mov_rot_right(FAST_LEVEL_3,CLOSE);
////							}

							while(Ping[PING_FRONT]>=14)
							{
//								mov_fwd_5cm(5,FAST_LEVEL_3);
								mov_fwd_5cm(5,FAST_LEVEL_3);
								GetBumper();
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_LEFT]>=16)
							{
//								mov_rot_right(FAST_LEVEL_3,CLOSE);
//								mov_rot_right(FAST_LEVEL_3,CLOSE);
								mov_rot_right(FAST_LEVEL_3, FAR);
								mov_rot_right(FAST_LEVEL_3, FAR);
								GetBumper();
								while(BUMPER[LEFT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_2);
									mov_rot_right(FAST, FAR);
									mov_rot_right(FAST, CLOSE);
//									mov_rot_right(FAST_LEVEL_3, FAR);
									GetBumper();
									if(BUMPER[LEFT]==INACTIVE) break;
								}
								while(BUMPER[RIGHT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_2);
									mov_rot_left(FAST, FAR);
									mov_rot_left(FAST, CLOSE);
//									mov_rot_left(FAST_LEVEL_3, FAR);
									GetBumper();
									if(BUMPER[RIGHT]==INACTIVE) break;
								}
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

							GetBumper();
							while(BUMPER[RIGHT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_left(FAST, FAR);
								mov_rot_left(FAST, CLOSE);
				//				mov_rot_left(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[RIGHT]==INACTIVE)break;
							}
							GetBumper();
							while(BUMPER[LEFT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_right(FAST, FAR);
								mov_rot_right(FAST, CLOSE);
				//				mov_rot_right(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[LEFT]==INACTIVE)break;
							}

//							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);
							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);
						}

						OVERRIDE=1;
					}

				}

			//KONDISI ROBOT JAUH DENGAN DINDING
			else if ( Ping[PING_ASKEW_LEFT]>PID_F_L.set_point )
//			else if ( SHARP[SHARP_LEFT]>PID_F_L.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
					if (PID_F_L.pid_value[0]>13)
					{
						WINDUP_LEFT_COUNTER++;
						PID_F_L.pid_value[0]=13;
					}

					if (Ping[PING_FRONT]<=14)
					{
						Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
//						mov_rot_right(FAST_LEVEL_3, CLOSE);
						mov_rot_right(FAST_LEVEL_3, FAR);
						mov_rot_right(FAST_LEVEL_3, FAR);

						GetBumper();
						while(BUMPER[RIGHT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_left(FAST, FAR);
							mov_rot_left(FAST, CLOSE);
			//				mov_rot_left(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[RIGHT]==INACTIVE)break;
						}
						GetBumper();
						while(BUMPER[LEFT]==ACTIVE)
						{
							BW_Buzz(1);
							mov_bwd_3cm(6,FAST_LEVEL_2);
							mov_rot_right(FAST, FAR);
							mov_rot_right(FAST, CLOSE);
			//				mov_rot_right(FAST_LEVEL_3, CLOSE);
							GetBumper();
							if(BUMPER[LEFT]==INACTIVE)break;
						}
//						if (Ping[PING_LEFT]>=20)
//						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
//						if (Ping[PING_LEFT]<20)
//						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							OVERRIDE=1;
//						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_LEFT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>=14)
							{
//								mov_fwd_5cm(5,FAST_LEVEL_3);
								mov_fwd_5cm(5,FAST_LEVEL_3);
								GetBumper();
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_LEFT]>=16)
							{
//								mov_rot_right(FAST_LEVEL_3,CLOSE);
//								mov_rot_right(FAST_LEVEL_3,CLOSE);
								mov_rot_right(FAST_LEVEL_2,FAR);
								mov_rot_right(FAST_LEVEL_2,FAR);
								GetBumper();
								while(BUMPER[RIGHT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_2);
									mov_rot_left(FAST, FAR);
									mov_rot_left(FAST, CLOSE);
					//				mov_rot_left(FAST_LEVEL_3, CLOSE);
									GetBumper();
									if(BUMPER[RIGHT]==INACTIVE)break;
								}
								GetBumper();
								while(BUMPER[LEFT]==ACTIVE)
								{
									BW_Buzz(1);
									mov_bwd_3cm(6,FAST_LEVEL_2);
									mov_rot_right(FAST, FAR);
									mov_rot_right(FAST, CLOSE);
					//				mov_rot_right(FAST_LEVEL_3, CLOSE);
									GetBumper();
									if(BUMPER[LEFT]==INACTIVE)break;
								}
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_LEFT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}
						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;
							GetBumper();
							while(BUMPER[RIGHT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_left(FAST, FAR);
								mov_rot_left(FAST, CLOSE);
				//				mov_rot_left(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[RIGHT]==INACTIVE)break;
							}
							GetBumper();
							while(BUMPER[LEFT]==ACTIVE)
							{
								BW_Buzz(1);
								mov_bwd_3cm(6,FAST_LEVEL_2);
								mov_rot_right(FAST, FAR);
								mov_rot_right(FAST, CLOSE);
				//				mov_rot_right(FAST_LEVEL_3, CLOSE);
								GetBumper();
								if(BUMPER[LEFT]==INACTIVE)break;
							}
//							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);
							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);

						}
						OVERRIDE=1;
					}

				}
		}
	}

}


/* func      : void FollowTracer_Right(void)
 * brief     : Wall Following Right Rule using PID controller until BW detects TRACER LINE
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Friday, March 18th 2016)
 * Revised BY: N/A
 * programmer's Note:
 *
 */
void FollowHome_Right(void)
{
//	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);

	TCSlave_Check();


	TRACER_IN_BUMPER=TRC_BMP_INACTIVE;
	TRACER_STAT=TRACER_INACTIVE;
	HOME_CIRCLE_FLAG=HOME_CIRCLE_NOT_DETECTED;

	//ACTIVATE FOLLOW HOME MODE ON TCSlave_Check();
	FOLLOWHOME_FLAG=FOLLOWHOME_ACTIVE;

	CAT_FLAG= CAT_NOT_DETECTED;


	while(
			(HOME_CIRCLE_FLAG==HOME_CIRCLE_NOT_DETECTED) && (CAT_FLAG==CAT_NOT_DETECTED)
		 )
	{
//		TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
		TCSlave_Check();
		Cat_Avoider();

		if (Ping[PING_FRONT]<=13)
		{
			if (Ping[PING_RIGHT]<=20)
			{
				Sendto_PC(USART1,"BW ROTATE LEFT \r");
//				mov_rot_left(FAST_LEVEL_3, CLOSE);
				mov_rot_left(FAST_LEVEL_3, CLOSE);

			}

			if (Ping[PING_RIGHT]>20)
			{
				Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//				mov_rot_right(FAST_LEVEL_3, CLOSE);
				mov_rot_right(FAST_LEVEL_3, CLOSE);
			}
		}
		else
		{
			PID_FollowHome_Right();
		}
	}



}

/* func      : void PID_FollowTracer_Right(void)
 * brief     : PID Calculation and actuate control signal
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Friday, March 18th 2016)
 * Revised BY: N/A
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */
void PID_FollowHome_Right(void)
{
	//int limit= *COMMAND_LOOP;
	int OVERRIDE=0;

	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;

	Sendto_PC(USART1,"Ping: %d \t",(int)Ping[PING_ASKEW_RIGHT]);
//	Sendto_PC(USART1,"SHARP: %d \t",(int)SHARP[SHARP_RIGHT]);
	PID_Calc_RightRule();
	Sendto_PC(USART1,"PID_F_R.pid_value[0]: %d \r",(int)PID_F_R.pid_value[0]);


	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
			if ( (Ping[PING_ASKEW_RIGHT]<=PID_F_R.set_point_upper) && (Ping[PING_ASKEW_RIGHT]>=PID_F_R.set_point_lower) )
//			if ( (SHARP[SHARP_RIGHT]<=PID_F_R.set_point_upper) && (SHARP[SHARP_RIGHT]>=PID_F_R.set_point_lower) )
				{
					if (Ping[PING_FRONT]<=13)
					{
						if (Ping[PING_RIGHT]<=20)
						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
						if (Ping[PING_RIGHT]>20)
						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

						Sendto_PC(USART1,"BW FORWARD \r");
//						mov_fwd_5cm(5, FAST_LEVEL_3);
						mov_fwd_5cm(5, FAST_LEVEL_3);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT JAUH DARI DINDING
			else if ( Ping[PING_ASKEW_RIGHT]>PID_F_R.set_point )
//			else if ( SHARP[SHARP_RIGHT]>PID_F_R.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
					if (PID_F_R.pid_value[0]>6)
					{
						WINDUP_RIGHT_COUNTER++;
						PID_F_R.pid_value[0]=6; //WINDUP
					}

					if (Ping[PING_FRONT]<=13)
					{
						if (Ping[PING_RIGHT]<=20)
						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
						if (Ping[PING_RIGHT]>20)
						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>=13)
							{
//								mov_fwd_5cm(5,FAST_LEVEL_3);
								mov_fwd_5cm(5,FAST_LEVEL_3);
								GetBumper();
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_RIGHT]>=15)
							{
//								mov_rot_left(FAST_LEVEL_3,CLOSE);
//								mov_rot_left(FAST_LEVEL_3,CLOSE);
								mov_rot_left(FAST_LEVEL_3,CLOSE);
								mov_rot_left(FAST_LEVEL_3,CLOSE);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

//							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
						}
						OVERRIDE=1;
					}

				}

			//KONDISI ROBOT DEKAT DENGAN DINDING
			else if ( Ping[PING_ASKEW_RIGHT]<PID_F_R.set_point )
//			else if ( SHARP[SHARP_RIGHT]<PID_F_R.set_point )
				{

					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
					if (PID_F_R.pid_value[0]>6)
					{
						WINDUP_LEFT_COUNTER++;
						PID_F_R.pid_value[0]=6; //WINDUP

					}

					if (Ping[PING_FRONT]<=13)
					{
						if (Ping[PING_RIGHT]<=20)
						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3,CLOSE);
							mov_rot_left(FAST_LEVEL_3,CLOSE);
							OVERRIDE=1;
						}
						if (Ping[PING_RIGHT]>20)
						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_LEFT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>=13)
							{
//								mov_fwd_5cm(5,FAST_LEVEL_3);
								mov_fwd_5cm(5,FAST_LEVEL_3);
								GetBumper();
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_RIGHT]>=15)
							{
//								mov_rot_left(FAST_LEVEL_3,CLOSE);
//								mov_rot_left(FAST_LEVEL_3,CLOSE);
								mov_rot_left(FAST_LEVEL_3,CLOSE);
								mov_rot_left(FAST_LEVEL_3,CLOSE);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_LEFT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

//							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_R.pid_value[0]);
						}
						OVERRIDE=1;
					}

				}
		}
	}

}


/* func      : void FollowTracer_Left(void)
 * brief     : Wall Following Left Rule using PID controller until BW detects TRACER LINE
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Friday, March 18th 2016)
 * Revised BY: N/A
 * programmer's Note:
 *
 */
void FollowHome_Left(void)
{


//	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	TCSlave_Check();

	TRACER_IN_BUMPER=TRC_BMP_INACTIVE;
	TRACER_STAT=TRACER_INACTIVE;
	HOME_CIRCLE_FLAG=HOME_CIRCLE_NOT_DETECTED;

	//ACTIVATE FOLLOW HOME MODE ON TCSlave_Check();
	FOLLOWHOME_FLAG=FOLLOWHOME_ACTIVE;

	CAT_FLAG= CAT_NOT_DETECTED;



	while(
			(HOME_CIRCLE_FLAG==HOME_CIRCLE_NOT_DETECTED) && (CAT_FLAG==CAT_NOT_DETECTED)
		 )
	{
//		TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
		TCSlave_Check();
		Cat_Avoider();

		if (Ping[PING_FRONT]<=13)
		{
			if (Ping[PING_LEFT]>=25)
			{
				Sendto_PC(USART1,"BW ROTATE LEFT \r");
//				mov_rot_left(FAST_LEVEL_3, CLOSE);
				mov_rot_left(FAST_LEVEL_3, CLOSE);
			}

			if (Ping[PING_LEFT]<25)
			{
				Sendto_PC(USART1,"BW ROTATE RIGHT \r");
//				mov_rot_right(FAST_LEVEL_3, CLOSE);
				mov_rot_right(FAST_LEVEL_3, CLOSE);
			}
		}
		else
		{
			PID_FollowHome_Left();
		}
	}



}

/* func      : void PID_FollowTracer_Left(void)
 * brief     : PID Calculation and actuate control signal
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Friday, March 18th 2016)
 * Revised BY: N/A
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */
void PID_FollowHome_Left(void)
{
	//int limit= *COMMAND_LOOP;
	int OVERRIDE=0;
	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;

	PID_Calc_LeftRule();

	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
			if ( (Ping[PING_ASKEW_LEFT]<=PID_F_L.set_point_upper) && (Ping[PING_ASKEW_LEFT]>=PID_F_L.set_point_lower) )
//			if ( (SHARP[SHARP_LEFT]<=PID_F_L.set_point_upper) && (SHARP[SHARP_LEFT]>=PID_F_L.set_point_lower) )
				{
					if (Ping[PING_FRONT]<=13)
					{
						if (Ping[PING_LEFT]>=25)
						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
						if (Ping[PING_LEFT]<25)
						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						RIGHT_OVERFLOW_COUNTER=0;
						LEFT_OVERFLOW_COUNTER=0;

						Sendto_PC(USART1,"BW FORWARD \r");
//						mov_fwd_5cm(5, FAST_LEVEL_3);
						mov_fwd_5cm(5, FAST_LEVEL_3);
						OVERRIDE=1;
					}
				}

			//KONDISI ROBOT JAUH DARI DINDING
			else if ( Ping[PING_ASKEW_LEFT]<PID_F_L.set_point )
//			else if ( SHARP[SHARP_LEFT]<PID_F_L.set_point )
				{
					//RESET WINDUP RIGHT COUNTER
					WINDUP_LEFT_COUNTER=0;

					//WINDUP
					if (PID_F_L.pid_value[0]>13)
					{
						WINDUP_RIGHT_COUNTER++;
						PID_F_L.pid_value[0]=13; //WINDUP
					}

					if (Ping[PING_FRONT]<=13)
					{
						if (Ping[PING_LEFT]>=20)
						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
						if (Ping[PING_LEFT]<20)
						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_RIGHT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW R");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>=13)
							{
//								mov_fwd_5cm(5,FAST_LEVEL_3);
								mov_fwd_5cm(5,FAST_LEVEL_3);
								GetBumper();
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_LEFT]>=15)
							{
//								mov_rot_right(FAST_LEVEL_3,CLOSE);
//								mov_rot_right(FAST_LEVEL_3,CLOSE);
								mov_rot_right(FAST_LEVEL_3,CLOSE);
								mov_rot_right(FAST_LEVEL_3,CLOSE);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_RIGHT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}

						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

//							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);
							curve_right_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);
						}
						OVERRIDE=1;
					}

				}

			//KONDISI ROBOT DEKAT DENGAN DINDING
			else if ( Ping[PING_ASKEW_LEFT]>PID_F_L.set_point )
//			else if ( SHARP[SHARP_LEFT]>PID_F_L.set_point )
				{
					//RESET WINDUP LEFT COUNTER
					WINDUP_RIGHT_COUNTER=0;

					//WINDUP
					if (PID_F_L.pid_value[0]>13)
					{
						WINDUP_LEFT_COUNTER++;
						PID_F_L.pid_value[0]=13;
					}

					if (Ping[PING_FRONT]<=13)
					{
						if (Ping[PING_LEFT]>=20)
						{
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
//							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							mov_rot_left(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
						if (Ping[PING_LEFT]<20)
						{
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
//							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							mov_rot_right(FAST_LEVEL_3, CLOSE);
							OVERRIDE=1;
						}
					}

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						if(WINDUP_LEFT_COUNTER>=25)
						{
							BW_Buzz(5);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW OVERFLOW L");lcd_putstr(lcd);
							delay_ms(100);

							while(Ping[PING_FRONT]>=13)
							{
//								mov_fwd_5cm(5,FAST_LEVEL_3);
								mov_fwd_5cm(5,FAST_LEVEL_3);
								GetBumper();
								if((BUMPER[RIGHT]==ACTIVE) || (BUMPER[LEFT]==ACTIVE)) break;
							}
							while(Ping[PING_LEFT]>=15)
							{
//								mov_rot_right(FAST_LEVEL_3,CLOSE);
//								mov_rot_right(FAST_LEVEL_3,CLOSE);
								mov_rot_right(FAST_LEVEL_3,CLOSE);
								mov_rot_right(FAST_LEVEL_3,CLOSE);
							}
							//RESET WINDUP RIGHT COUNTER
							WINDUP_LEFT_COUNTER=0;

							//REINIT PID
							BW_PID_Init();
						}
						else
						{
							RIGHT_OVERFLOW_COUNTER=0;
							LEFT_OVERFLOW_COUNTER=0;

//							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);
							curve_left_counter(FAST_LEVEL_3, CLOSE, &PID_F_L.pid_value[0]);
						}
						OVERRIDE=1;
					}

				}
		}
	}

}



/* func      : void WallFollow_Tester(void)
 * brief     : Wallfollower Tester
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Monday, March 21st 2016)
 * Revised BY: N/A
 * programmer's Note:
 *
 */
void WallFollow_Tester(void)
{
	int MENU_VAR;

	while(BUTTON_IDLE)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"BW 2016");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"WALL FOLLOW TESTER");lcd_putstr(lcd);
		delay_ms(100);
	}

	if(BW_BUTTON_CLICKED)
	{
		while(BUTTON_IDLE)
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"BW 2016");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"WALL FOLLOW TESTER");lcd_putstr(lcd);
			delay_ms(100);
		}
		delay_ms(1000);

		while(1)
		{
			while(BW_BUTTON_UNCLICKED)
			{
				if(BUTTON_A_CLICKED)
				{
					BW_Buzz(2);
					while(BUTTON_A_CLICKED){};
					MENU_VAR++;
				}
				if(BUTTON_B_CLICKED)
				{
					BW_Buzz(1);
					while(BUTTON_B_CLICKED){};
					MENU_VAR--;
				}

				if(MENU_VAR>3) MENU_VAR=0;
				else if (MENU_VAR<0) MENU_VAR=3;
			}


			switch(MENU_VAR)
			{
				case 0:
						{
							lcd_display_clear();
							lcd_gotoxy(0,1);sprintf(lcd,"FOLLOW BLACK");lcd_putstr(lcd);
							FollowCarpet_Right(COLOUR_BLACK,INVERSE);
							while(1)
							{
								BW_Buzz(3);
								mov_static();
							}
						}break;

				case 1:
						{
							lcd_display_clear();
							lcd_gotoxy(0,1);sprintf(lcd,"FOLLOW GRAY");lcd_putstr(lcd);
							FollowCarpet_Right(COLOUR_GRAY,INVERSE);
							while(1)
							{
								BW_Buzz(3);
								mov_static();
							}
						}break;
				case 2:
						{
							lcd_display_clear();
							lcd_gotoxy(0,1);sprintf(lcd,"FOLLOW WHITE");lcd_putstr(lcd);
							FollowCarpet_Right(COLOUR_WHITE,INVERSE);
							while(1)
							{
								BW_Buzz(3);
								mov_static();
							}
						}break;
				case 3:
						{
							lcd_display_clear();
							lcd_gotoxy(0,1);sprintf(lcd,"NO FOLLOW");lcd_putstr(lcd);
							while(1)
							{
								BW_Buzz(3);
								mov_static();
							}
						}break;

			}

		}

	}
}


/* func      : void RoomTypeDetector(void)
 * brief     : Detects Room Type, whether it's GRAY_ROOM or NORMAL_ROOM
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Monday, March 21st 2016)
 * Revised BY: N/A
 * programmer's Note:
 *
 */
void RoomTypeDetector(void)
{
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);

	delay_ms(50);

	if	(
			(TCS3200_SLV_DATA[0]==COLOUR_GRAY)
		)

	{
		BW_Buzz(1);
		ROOM_TYPE= GRAY_ROOM;

		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
		lcd_gotoxy(2,3);sprintf(lcd,"GRAY ROOM");lcd_putstr(lcd);

		delay_ms(50);

	}
	else if	(
			(TCS3200_SLV_DATA[0]==COLOUR_BLACK)
		)
	{
		ROOM_TYPE= NORMAL_ROOM;

//		BW_Buzz(1);
		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
		lcd_gotoxy(2,3);sprintf(lcd,"NORMAL ROOM");lcd_putstr(lcd);

		delay_ms(50);
	}
	else
	{
		ROOM_TYPE= NORMAL_ROOM;

		BW_Buzz(1);
		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
		lcd_gotoxy(2,3);sprintf(lcd,"ID FAILED");lcd_putstr(lcd);

		delay_ms(50);

			BW_PID_Init();
			follow_right_counter(1);
			RoomTypeDetector();

	}

}



/* func      : void RoomDetector(void)
 * brief     : Detect room and store the room identifiers
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Monday, March 21st 2016)
 * Revised BY: N/A
 * programmer's Note:
 *
 */
void RoomDetector(int ROOM_COUNTER)
{
	if(Ping[PING_FRONT]>=30)
	{
		if( (Ping[PING_LEFT]<=40) && (Ping[PING_ASKEW_LEFT]<=50) )
		{
			ROOM[ROOM_COUNTER]= ROOM_1C;
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"ROOM 1 ");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"DOOR C ");lcd_putstr(lcd);
			delay_ms(100);
		}
		else
		{
			if( (Ping[PING_RIGHT]>=50)  )
			{
				ROOM[ROOM_COUNTER]= ROOM_1C;
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"ROOM 1");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"DOOR C ALT");lcd_putstr(lcd);
				delay_ms(100);
			}

			else if(ROOM_TYPE==GRAY_ROOM)
			{
				ROOM[ROOM_COUNTER]= ROOM_2B;
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"ROOM 2");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"DOOR B ");lcd_putstr(lcd);
				delay_ms(100);
			}
			else
			{
				ROOM[ROOM_COUNTER]= ROOM_1A;
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"ROOM 1");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"DOOR A");lcd_putstr(lcd);
				delay_ms(100);
			}

		}
	}
	else
	{
		if( (Ping[PING_RIGHT]<40) && (Ping[PING_ASKEW_RIGHT]<30) )
		{
			if(ROOM_TYPE==GRAY_ROOM)
			{
				ROOM[ROOM_COUNTER]= ROOM_2A;
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"ROOM 2");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"DOOR A ");lcd_putstr(lcd);
				delay_ms(100);
			}
			else
			{
				ROOM[ROOM_COUNTER]= ROOM_3;
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"ROOM 3");lcd_putstr(lcd);
				delay_ms(100);
			}

		}

		else if( (Ping[PING_LEFT]>=30) && (Ping[PING_RIGHT]>=40) )
		{

			if( ( (Ping[PING_LEFT]>=30) && (Ping[PING_LEFT]<75) ) && ( (Ping[PING_ASKEW_RIGHT]>=128) || (Ping[PING_RIGHT]>=128) ) )
			{
				ROOM[ROOM_COUNTER]= ROOM_1B;
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"ROOM 1 ");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"DOOR B ");lcd_putstr(lcd);
				delay_ms(100);
			}

			else
			{
				mov_rot_left(FAST_LEVEL_3,CLOSE);
				mov_rot_left(FAST_LEVEL_3,CLOSE);

				if( ( (Ping[PING_LEFT]>=40) && (Ping[PING_LEFT]<75) ) && (Ping[PING_RIGHT]>=80) && (Ping[PING_ASKEW_RIGHT]>=80))
				{
					ROOM[ROOM_COUNTER]= ROOM_1B;
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"ROOM 1 ");lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"DOOR B ");lcd_putstr(lcd);
					delay_ms(100);
				}

				else
				{
					BW_Buzz(1);
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"ROOM 4AB ");lcd_putstr(lcd);
					delay_ms(100);

					//BW RE-CHECKING

					while(Ping[PING_FRONT]<=12)
					{
						mov_bwd_5cm(5,FAST_LEVEL_3);
					}
					mov_rot_right(FAST_LEVEL_3,CLOSE);
					mov_rot_right(FAST_LEVEL_3,CLOSE);

					if( ( (Ping[PING_LEFT]>=40) && (Ping[PING_LEFT]<75) ) && (Ping[PING_RIGHT]>=80) && (Ping[PING_ASKEW_RIGHT]>=80))
					{
						ROOM[ROOM_COUNTER]= ROOM_1B;
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"ROOM 1");lcd_putstr(lcd);
						lcd_gotoxy(0,1);sprintf(lcd,"DOOR B");lcd_putstr(lcd);
						delay_ms(100);
					}

					else
					{
						BW_Buzz(1);
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"ROOM 4AB ");lcd_putstr(lcd);
						delay_ms(100);

						//BW STABILIZE
//						mov_fwd_5cm(5,FAST_LEVEL_3);
//						while(Ping[PING_FRONT]>=15)
//						{
//							mov_fwd_5cm(5,FAST_LEVEL_3);
//						}
//						if(Ping[PING_FRONT]>=15)
//						{
//							mov_fwd_5cm(5,FAST_LEVEL_3);
//						}
//						if(Ping[PING_FRONT]>=15)
//						{
//							mov_fwd_5cm(5,FAST_LEVEL_3);
//						}
//
//						if(Ping[PING_FRONT]<=13)
//						{
//							mov_bwd_5cm(5,FAST_LEVEL_3);
//						}
//
//						if(Ping[PING_FRONT]<=13)
//						{
//							mov_bwd_5cm(5,FAST_LEVEL_3);
//						}
//						mov_rot_right(FAST_LEVEL_3,CLOSE);
//
//						if(Ping[PING_FRONT]<=13)
//						{
//							mov_bwd_5cm(5,FAST_LEVEL_3);
//						}
//						mov_rot_right(FAST_LEVEL_3,CLOSE);
//
//						if(Ping[PING_FRONT]<=13)
//						{
//							mov_bwd_5cm(5,FAST_LEVEL_3);
//						}
//						mov_rot_right(FAST_LEVEL_3,CLOSE);
//
//						if(Ping[PING_FRONT]<=13)
//						{
//							mov_bwd_5cm(5,FAST_LEVEL_3);
//						}
//						mov_rot_right(FAST_LEVEL_3,CLOSE);

/*
						while(Ping[PING_FRONT]<=25)
						{
							mov_rot_right(FAST_LEVEL_2,FAR);
//							mov_rot_right(FAST_LEVEL_2,FAR);
							if(Ping[PING_FRONT]<=13)
							{
								mov_bwd_5cm(5,FAST_LEVEL_3);
							}
						}
						mov_rot_right(FAST_LEVEL_2,FAR);
						mov_rot_right(FAST_LEVEL_2,FAR);
						mov_rot_right(FAST_LEVEL_3,CLOSE);
//						mov_rot_right(FAST_LEVEL_3,CLOSE);
						if(Ping[PING_LEFT]<=13)
						{
							mov_deflect_right(FAST,CLOSE);
							mov_deflect_right(FAST,CLOSE);
							mov_deflect_right(FAST,CLOSE);
						}
*/

						if(Ping[PING_RIGHT]>=75)
						{
							ROOM[ROOM_COUNTER]= ROOM_4B;
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"ROOM 4 ");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"DOOR B ");lcd_putstr(lcd);
							delay_ms(100);
						}
						else
						{
							ROOM[ROOM_COUNTER]= ROOM_4A;
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"ROOM 4 ");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"DOOR A ");lcd_putstr(lcd);
							delay_ms(100);

//							//RE-CHECKING
//							mov_rot_right(FAST_LEVEL_3,CLOSE);
//							mov_rot_right(FAST_LEVEL_3,CLOSE);
////							mov_rot_right(FAST_LEVEL_3,CLOSE);
//
//							if(Ping[PING_FRONT]>=65)
//							{
//								ROOM[ROOM_COUNTER]= ROOM_4B;
//								lcd_display_clear();
//								lcd_gotoxy(0,0);sprintf(lcd,"ROOM 4 ");lcd_putstr(lcd);
//								lcd_gotoxy(0,1);sprintf(lcd,"DOOR B ");lcd_putstr(lcd);
//								delay_ms(100);
//							}
//							else
//							{
//								ROOM[ROOM_COUNTER]= ROOM_4A;
//								lcd_display_clear();
//								lcd_gotoxy(0,0);sprintf(lcd,"ROOM 4 ");lcd_putstr(lcd);
//								lcd_gotoxy(0,1);sprintf(lcd,"DOOR A ");lcd_putstr(lcd);
//								delay_ms(100);
//							}
						}
					}
				}
			}
		}
		else
		{
			mov_static();
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
			lcd_gotoxy(4,1);sprintf(lcd,"ROOM ID");lcd_putstr(lcd);
			lcd_gotoxy(4,2);sprintf(lcd,"FAILED");lcd_putstr(lcd);
			delay_ms(100);

			if ( (Ping[PING_FRONT]<=25) && (Ping[PING_ASKEW_RIGHT]>=100) && (Ping[PING_ASKEW_LEFT]>=100) )
			{
				mov_rot_left(FAST_LEVEL_3,CLOSE);
			}

			if(Ping[PING_FRONT]>5)
			{
				BW_Buzz(1);
				mov_rot_left(FAST_LEVEL_3,CLOSE);
				mov_fwd_5cm(5,FAST_LEVEL_3);
			}
			else if(Ping[PING_FRONT]<=5)
			{
				BW_Buzz(2);
				mov_bwd_5cm(5,FAST_LEVEL_3);
			}
			RoomDetector(ROOM_COUNTER);

		}
	}
}

/* func      : void RoomDetector_Check(void)
 * brief     : FollowTracer_
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 23rd 2016)
 * Revised BY: TONI (Thursday, December 1st 2016)
 * programmer's Note: Test detektor setelah keluar ruang
 */
void RoomDetector_Check(void)
{
	RoomTypeDetector();
	RoomTypeDetector();
	lcd_gotoxy(0,1);sprintf(lcd," MIDDLE: %d",TCS3200_SLV_DATA[1]);lcd_putstr(lcd);
	FollowTracer_Right();
//	mov_fwd_5cm(15,FAST_LEVEL_3);
	//LOCATION: CORRIDOR
		BW_Buzz(1);
		H_Correction_Left();

		if(Ping[PING_FRONT]>=16)
		{
			mov_fwd_5cm(10, FAST);
		}

		mov_rot_right(FAST,CLOSE);
	//	mov_rot_right(FAST,FAR);
	//	mov_rot_right(FAST_LEVEL_3,CLOSE);
	//	H_Correction_ExitRoom();

	//	BW_Buzz(1);
		if (Ping[PING_RIGHT]<75)
		{
			if((Ping[PING_ASKEW_RIGHT])>(Ping[PING_RIGHT]))
			{
				mov_rot_right(FAST,CLOSE);
				mov_rot_right(FAST,CLOSE);
				mov_rot_right(FAST,CLOSE);
		//		mov_rot_right(FAST,CLOSE);
			}
			if((Ping[PING_ASKEW_RIGHT])<(Ping[PING_RIGHT]))
			{
				mov_rot_left(FAST,CLOSE);
				mov_rot_left(FAST,CLOSE);
				mov_rot_left(FAST,CLOSE);
		//		mov_rot_left(FAST,CLOSE);
			}
		}
		else
		{
			if((Ping[PING_ASKEW_LEFT])>(Ping[PING_LEFT]))
			{
				mov_rot_left(FAST,CLOSE);
				mov_rot_left(FAST,CLOSE);
				mov_rot_left(FAST,CLOSE);
		//		mov_rot_left(FAST,CLOSE);
			}
			if((Ping[PING_ASKEW_LEFT])<(Ping[PING_LEFT]))
			{
				mov_rot_right(FAST,CLOSE);
				mov_rot_right(FAST,CLOSE);
				mov_rot_right(FAST,CLOSE);
		//		mov_rot_right(FAST,CLOSE);
			}

		}
	RoomDetector(1);
	while(1)
	{
		RoomDetector(1);
		mov_static();
	}
}

/* func      : void BW_FireFight(void)
 * brief     : BW FireFighting Routines
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 23rd 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void BW_FireFight(void)
{
//	int counter;
//	int FOLLOW_DECISION;
	FlameSense_PID_Init();

//	mov_static();

	//FLAME IN CORNER RIGHT OR LEFT
//	if(FLAME_SIDE==FLAME_LEFT)
//	{
//		lcd_display_clear();
//		lcd_gotoxy(0,0);sprintf(lcd,"ROTATE LEFT");lcd_putstr(lcd);
//		delay_ms(100);
//
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//
//		BW_Buzz(5);
//		lcd_display_clear();
//		lcd_gotoxy(0,0);sprintf(lcd,"FLAME APPROACH");lcd_putstr(lcd);
//		delay_ms(100);
//
//		Get_IR();
//		while(
//				( (INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED)) ||
//				( (FlameSense[0]!=2) && (FlameSense[0]!=3) && (FlameSense[0]!=4) )
//			 )
//		{
//			Get_IR();
//			if(
//					(
//							(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED)
//					)
//															&&
//					(
//							(FlameSense[0]==2) || (FlameSense[0]==3) || (FlameSense[0]==4)
//					)
//			  )
//
//			{
//				break; //EXIT FROM ITERATION
//			}
//
//			FlameApproach();
//		}
//
//	}
//
//	else if (FLAME_SIDE==FLAME_RIGHT)
//	{
//		lcd_display_clear();
//		lcd_gotoxy(0,0);sprintf(lcd,"ROTATE RIGHT");lcd_putstr(lcd);
//		delay_ms(100);
//
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//
//		BW_Buzz(5);
//		lcd_display_clear();
//		lcd_gotoxy(0,0);sprintf(lcd,"FLAME APPROACH");lcd_putstr(lcd);
//		delay_ms(1000);
//
//		Get_IR();
//		while(
//				( (INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED)) ||
//				( (FlameSense[0]!=2) && (FlameSense[0]!=3) && (FlameSense[0]!=4) )
//			 )
//		{
//			Get_IR();
//			if(
//					(
//							(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED)
//					)
//															&&
//					(
//							(FlameSense[0]==2) || (FlameSense[0]==3) || (FlameSense[0]==4)
//					)
//			  )
//
//			{
//				break; //EXIT FROM ITERATION
//			}
//
//			FlameApproach();
//		}
//	}

//	else
//	{
		mov_fwd_5cm(10,FAST_LEVEL_3);

		BW_Buzz(2);
		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
		delay_ms(100);
		FlameTracking_New();

		BW_Buzz(5);
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"FLAME APPROACH");lcd_putstr(lcd);
		delay_ms(1000);

		Get_IR();
		while(
				( (INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED)) ||
				( (FlameSense[0]!=2) && (FlameSense[0]!=3) && (FlameSense[0]!=4) )
			 )
		{
			Get_IR();
			if(
					(
							(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED)
					)
															&&
					(
							(FlameSense[0]==2) || (FlameSense[0]==3) || (FlameSense[0]==4)
					)
			  )

			{
				break; //EXIT FROM ITERATION
			}

			FlameApproach();
		}
//	}


//	//FIRE ACROSS THE ROOM
//	else if	(
////			(FlameSense[0]!=5) &&
//				(Ping[PING_FRONT]>=40)
//			)
//	{
//		if(Ping[PING_LEFT]<= Ping[PING_RIGHT])
//		{
//			BW_Buzz(3);
//			lcd_display_clear();
//			lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW LEFT");lcd_putstr(lcd);
//			lcd_gotoxy(0,1);sprintf(lcd,"10 TIMES");lcd_putstr(lcd);
//			delay_ms(100);
//			BW_PID_Init();
//			follow_left_counter(10);
//		}
//
//		else if(Ping[PING_RIGHT]< Ping[PING_LEFT])
//		{
//			BW_Buzz(1);
//			lcd_display_clear();
//			lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW RIGHT");lcd_putstr(lcd);
//			lcd_gotoxy(0,1);sprintf(lcd,"10 TIMES");lcd_putstr(lcd);
//			delay_ms(100);
//			BW_PID_Init();
//			follow_right_counter(10);
//		}
//
//		if(Ping[PING_LEFT]<= Ping[PING_RIGHT])
//		{
//			FOLLOW_DECISION=1;
//		}
//		else if(Ping[PING_RIGHT]< Ping[PING_LEFT])
//		{
//			FOLLOW_DECISION=2;
//		}
//
//		BW_PID_Init();
//		Get_IR();
//		while(
//				( (INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED)) ||
//				( (FlameSense[0]!=2) && (FlameSense[0]!=3) && (FlameSense[0]!=4) )
//			 )
//		{
////			Get_IR();
////			if(
////					(
////							(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED)
////					)
////															&&
////					(
////							(FlameSense[0]==2) || (FlameSense[0]==3) || (FlameSense[0]==4)
////					)
////			  )
////
////			{
//				lcd_display_clear();
//				lcd_gotoxy(0,0);sprintf(lcd,"FURNITURE");lcd_putstr(lcd);
//				lcd_gotoxy(0,1);sprintf(lcd,"DETECTED");lcd_putstr(lcd);
//				delay_ms(1000);
//				break; //EXIT FROM ITERATION
//
////			}
//
//	//		if(Ping[PING_RIGHT]<=15)
//	//		{
//	//			BW_PID_Init();
//	//			follow_right_counter(2);
//	//		}
//	//		else if(Ping[PING_LEFT]<=15)
//	//		{
//	//			BW_PID_Init();
//	//			follow_left_counter(2);
//	//		}
//
////			FlameApproach();
//
////			if(FOLLOW_DECISION==1)
////			{
////				follow_left_counter(1);
////			}
////			else if(FOLLOW_DECISION==2)
////			{
////				follow_right_counter(1);
////			}
//
//		}
//
//		if(Ping[PING_RIGHT]<=Ping[PING_LEFT])
//		{
//			lcd_display_clear();
//			lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW RIGHT");lcd_putstr(lcd);
//			lcd_gotoxy(0,1);sprintf(lcd,"15 TIMES");lcd_putstr(lcd);
//			delay_ms(100);
//
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//
//			BW_PID_Init();
//			follow_right_counter(15);
//	//		while((FlameSense[0]!=3))
//	//		{
//	//			follow_right_counter(1);
//	//		}
//
//		}
//
//		else if(Ping[PING_LEFT]<Ping[PING_RIGHT])
//		{
//			lcd_display_clear();
//			lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW LEFT");lcd_putstr(lcd);
////			lcd_gotoxy(3,1);sprintf(lcd,"");lcd_putstr(lcd);
//			delay_ms(100);
//
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//
//			BW_PID_Init();
////			follow_left_counter(15);
//			while((FlameSense[0]!=4))
//			{
//				follow_left_counter(1);
//			}
//		}
//	}


	/*
	 *  MANDATORY SEQUENCES
	 */
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(3,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
	delay_ms(100);
	FlameTracking_New();

	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(3,0);sprintf(lcd,"CREATE SPACES");lcd_putstr(lcd);
	delay_ms(100);
	BW_Buzz(2);


	//CREATING SPACES BETWEEN ROBOT AND CANDLES
	if(Ping[PING_FRONT]>15)
	{
		while(Ping[PING_FRONT]>15)
		{
			mov_fwd_5cm(5,FAST_LEVEL_3);
		}

	}

	else if(Ping[PING_FRONT]<=15)
	{
		while(Ping[PING_FRONT]<=15)
		{
			mov_bwd(5,FAST_LEVEL_3);
		}
	}



//	while(FlameSense[0]!=0)
	while(UV_Lock==UVLOCK_ACTIVE)
	{
		BW_Buzz(2);
		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
		delay_ms(100);
		BW_Buzz(2);
		FlameTracking_New();

		//CREATING SPACES BETWEEN ROBOT AND CANDLES
		if(Ping[PING_FRONT]>15)
		{
			while(Ping[PING_FRONT]>15)
			{
				mov_fwd_5cm(5,FAST_LEVEL_3);
			}

		}
		else if(Ping[PING_FRONT]<=15)
		{
			while(Ping[PING_FRONT]<=15)
			{
				mov_bwd(5,FAST_LEVEL_3);
			}
		}

		BW_Buzz(2);
		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"FLAME SCANNING");lcd_putstr(lcd);
		delay_ms(100);

		BW_FlameScanning();

		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) break;

//		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		BW_FlameScanning();

		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) break;

//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		BW_FlameScanning();

		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) break;
	}

	EXTINGUISHED_FIRE=1;

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(2,1);sprintf(lcd,"FIREFIGHTING");lcd_putstr(lcd);
	lcd_gotoxy(3,2);sprintf(lcd,"SUCCESS!!!");lcd_putstr(lcd);
	delay_ms(100);

}

void UVLock_Refresh(void)
{
	Get_UV();
	if(UV_state==UVSTATE_INACTIVE)
	{
		UV_Lock=UVLOCK_INACTIVE;
	}
}

/* func      : void BW_Navi(int STARTING_POINT, int DESTINATION)
 * brief     : BW NAVIGATION ROUTINES
 * param     : int STARTING_POINT->Initial location | int DESTINATION -> BW's target location
 *     					STARTING POINT 					DESTINATION
 * 				HALLWAY_SC			(1A, 1B, 1C, 2A, 2B, 3, 4A, 4B					)
 * 				ROOM_1A				(HALLWAY_SC, 2A, 2B, 3, 4A, 4B				)
 * 				ROOM_1B				( 				N/A								)
 * 				ROOM_1C				(HALLWAY_SC, 2A, 2B, 3, 4A, 4B				)
 * 				ROOM_2A/2B			(HALLWAY_SC, 1A, 1B, 1C, 2A, 2B, 3, 4A, 4B	)
 * 				ROOM_3				(HALLWAY_SC, 1A, 1B, 1C, 2A, 2B, 3, 4A, 4B	)
 * 				ROOM_4A				(HALLWAY_SC, 1A, 1B, 1C, 2A, 2B, 3			)
 * 				ROOM_4B				(HALLWAY_SC, 1A, 1B, 1C, 2A, 2B, 3					)
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 25th 2016)
 * Revised BY: N/A
 * programmer's Note:
 *
 */
void BW_Navi(int STARTING_POINT, int DESTINATION)
{
	int DEPARTURE=99;

	DEPARTURE = STARTING_POINT;
	//STARTING POINT == HALLWAY SC
	if(DEPARTURE==HALLWAY_SC)
	{
		switch(DESTINATION)
		{
			case NAV_HALLWAY_SC:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}
				}break;

			case NAV_ROOM_1A:
				{
					Nav_HallwaySC_To_1A(2);
				}break;

			case NAV_ROOM_1B:
				{
					Nav_HallwaySC_To_1B();
				}break;

			case NAV_ROOM_1C:
				{
					Nav_HallwaySC_To_1B();
				}break;

			case NAV_ROOM_2A:
				{
					Nav_HallwaySC_To_2();
				}break;

			case NAV_ROOM_2B:
				{
					Nav_HallwaySC_To_2();
				}break;

			case NAV_ROOM_3:
				{
					Nav_HallwaySC_To_3();
				}break;

			case NAV_ROOM_4A:
				{
					Nav_HallwaySC_To_4A();
				}break;

			case NAV_ROOM_4B:
				{
					Nav_HallwaySC_To_4B();
				}break;
		}
	}

	//STARTING POINT == ROOM 1A
	else if (DEPARTURE==NAV_ROOM_1A)
	{
		switch(DESTINATION)
		{
			case NAV_HALLWAY_SC:
				{
					Nav_1A_To_HallwaySC();

				}break;

			case NAV_ROOM_1A:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}

				}break;

			case NAV_ROOM_1B:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}
				}break;

			case NAV_ROOM_1C:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}
				}break;

			case NAV_ROOM_2A:
				{
					Nav_1A_To_2();
				}break;

			case NAV_ROOM_2B:
				{
					Nav_1A_To_2();
				}break;

			case NAV_ROOM_3:
				{
					Nav_1A_To_3();
				}break;

			case NAV_ROOM_4A:
				{
					Nav_1A_To_4A();
				}break;

			case NAV_ROOM_4B:
				{
					Nav_1A_To_4B();
				}break;
		}
	}

	//STARTING POINT == ROOM 1B
	else if (DEPARTURE==NAV_ROOM_1B)
	{
		switch(DESTINATION)
		{
			case NAV_HALLWAY_SC:
				{
					Nav_1C_To_HallwaySC();

				}break;

			case NAV_ROOM_1A:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}

				}break;

			case NAV_ROOM_1B:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}
				}break;

			case NAV_ROOM_1C:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}
				}break;

			case NAV_ROOM_2A:
				{
					Nav_1B_To_2();
				}break;

			case NAV_ROOM_2B:
				{
					Nav_1B_To_2();
				}break;

			case NAV_ROOM_3:
				{
					Nav_1C_To_3();
				}break;

			case NAV_ROOM_4A:
				{
					Nav_1C_To_4A();
				}break;

			case NAV_ROOM_4B:
				{
					Nav_1C_To_4B();
				}break;
		}
	}

	//STARTING POINT == ROOM 1C
	else if (DEPARTURE==NAV_ROOM_1C)
	{
		switch(DESTINATION)
		{
			case NAV_HALLWAY_SC:
				{
					Nav_1C_To_HallwaySC();

				}break;

			case NAV_ROOM_1A:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}

				}break;

			case NAV_ROOM_1B:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}
				}break;

			case NAV_ROOM_1C:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}
				}break;

			case NAV_ROOM_2A:
				{
					Nav_1C_To_2();
				}break;

			case NAV_ROOM_2B:
				{
					Nav_1C_To_2();
				}break;

			case NAV_ROOM_3:
				{
					Nav_1C_To_3();
				}break;

			case NAV_ROOM_4A:
				{
					Nav_1C_To_4A();
				}break;

			case NAV_ROOM_4B:
				{
					Nav_1C_To_4B();
				}break;
		}
	}

	//STARTING POINT == ROOM 2A
	else if ( (DEPARTURE==NAV_ROOM_2A)  )
	{
		switch(DESTINATION)
		{
			case NAV_HALLWAY_SC:
				{
					Nav_2_To_HallwaySC();

				}break;

			case NAV_ROOM_1A:
				{
					Nav_2_To_1A();
				}break;

			case NAV_ROOM_1B:
				{
					Nav_2A_To_1BC();
				}break;

			case NAV_ROOM_1C:
				{
					Nav_2A_To_1BC();
				}break;

			case NAV_ROOM_2A:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}

				}break;

			case NAV_ROOM_2B:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}

				}break;

			case NAV_ROOM_3:
				{
					Nav_2_To_3();
				}break;

			case NAV_ROOM_4A:
				{
					Nav_2_To_4A();
				}break;

			case NAV_ROOM_4B:
				{
					Nav_2_To_4B();
				}break;
		}
	}

	//STARTING POINT == ROOM 2B
	else if ( (DEPARTURE==NAV_ROOM_2B) )
	{
		switch(DESTINATION)
		{
			case NAV_HALLWAY_SC:
				{
					Nav_2_To_HallwaySC();

				}break;

			case NAV_ROOM_1A:
				{
					Nav_2_To_1A();
				}break;

			case NAV_ROOM_1B:
				{
					Nav_2B_To_1BC();
				}break;

			case NAV_ROOM_1C:
				{
					Nav_2B_To_1BC();
				}break;

			case NAV_ROOM_2A:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}

				}break;

			case NAV_ROOM_2B:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}

				}break;

			case NAV_ROOM_3:
				{
					Nav_2_To_3();
				}break;

			case NAV_ROOM_4A:
				{
					Nav_2_To_4A();
				}break;

			case NAV_ROOM_4B:
				{
					Nav_2_To_4B();
				}break;
		}
	}


	//STARTING POINT == ROOM 3
	else if (DEPARTURE==NAV_ROOM_3)
	{
		switch(DESTINATION)
		{
			case NAV_HALLWAY_SC:
				{
					Nav_3_To_HallwaySC();
				}break;

			case NAV_ROOM_1A:
				{
					Nav_3_To_1A();
				}break;

			case NAV_ROOM_1B:
				{
					Nav_3_To_1BC();
				}break;

			case NAV_ROOM_1C:
				{
					Nav_3_To_1BC();
				}break;

			case NAV_ROOM_2A:
				{
					Nav_3_To_2();
				}break;

			case NAV_ROOM_2B:
				{
					Nav_3_To_2();
				}break;

			case NAV_ROOM_3:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}
				}break;

			case NAV_ROOM_4A:
				{
					Nav_3_To_4A();
				}break;

			case NAV_ROOM_4B:
				{
					Nav_3_To_4B();
				}break;
		}
	}

	//STARTING POINT == ROOM 4A
	else if (DEPARTURE==NAV_ROOM_4A)
	{
		switch(DESTINATION)
		{
			case NAV_HALLWAY_SC:
				{
					Nav_4A_To_HallwaySC();
				}break;

			case NAV_ROOM_1A:
				{
					Nav_4A_To_1A();
				}break;

			case NAV_ROOM_1B:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}
				}break;

			case NAV_ROOM_1C:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}
				}break;

			case NAV_ROOM_2A:
				{
					Nav_4A_To_2();
				}break;

			case NAV_ROOM_2B:
				{
					Nav_4A_To_2();
				}break;

			case NAV_ROOM_3:
				{
					Nav_4A_To_3();
				}break;

			case NAV_ROOM_4A:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}
				}break;

			case NAV_ROOM_4B:
				{
					//WRONG ANSWER
					while(1)
					{
						BW_Buzz(2);
						mov_static();
					}
				}break;
		}
	}

	//STARTING POINT == ROOM 4B
	else if (DEPARTURE==NAV_ROOM_4B)
	{
		switch(DESTINATION)
		{
			case NAV_HALLWAY_SC:
				{
					Nav_4B_To_HallwaySC();
				}break;
			case NAV_ROOM_1A:
				{
					Nav_4B_To_1A();
				}break;
			case NAV_ROOM_1C:
				{
					Nav_4B_To_1BC();
				}break;
			case NAV_ROOM_1B:
				{
					Nav_4B_To_1BC();
				}break;

			case NAV_ROOM_2A:
				{
					Nav_4B_To_2();
				}break;

			case NAV_ROOM_2B:
				{
					Nav_4B_To_2();
				}break;

			case NAV_ROOM_3:
				{
					Nav_4B_To_3();
				}break;
		}
	}

	//WRONG CASE
	else
	{
		while(1)
		{
			BW_Buzz(2);
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
			lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
			lcd_gotoxy(2,3);sprintf(lcd,"NAVIGATION");lcd_putstr(lcd);
			delay_ms(100);
			BW_Buzz(2);
			mov_static();

			delay_ms(500);

			BW_Buzz(2);
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
			lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
			lcd_gotoxy(2,3);sprintf(lcd,"ERROR");lcd_putstr(lcd);
			delay_ms(100);
			BW_Buzz(2);
			mov_static();

			delay_ms(500);
		}
	}


}

/* func      : void Nav_HallwaySC_To_3(void)
 * brief     : Navigate from HallwaySC to Room 3
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 25th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_HallwaySC_To_3(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"SC TO R3");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	BW_Buzz(1);
	BW_PID_Init();
	FollowCarpet_Right(COLOUR_BLACK,INVERSE);

//	mov_deflect_right(FAST,CLOSE);
//	mov_deflect_right(FAST,CLOSE);
	mov_deflect_right(FAST,CLOSE);
	mov_deflect_right(FAST,CLOSE);

//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);
	mov_rot_right(FAST_LEVEL_3,CLOSE);
	mov_rot_right(FAST_LEVEL_3,CLOSE);

	BW_Buzz(2);
	BW_PID_Init();
	FollowTracer_Right();


}

/* func      : void Nav_HallwaySC_To_2(void)
 * brief     : Navigate from HallwaySC to Room 2
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 25th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_HallwaySC_To_2(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"SC TO R2");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	while(Ping[PING_ASKEW_LEFT]<=70)
//	while(SHARP[SHARP_LEFT]<=70)
	{
		BW_PID_Init();
		follow_right_counter(1);
	}
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	lcd_gotoxy(0,1);sprintf(lcd," MIDDLE: %d",TCS3200_SLV_DATA[1]);lcd_putstr(lcd);
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	lcd_gotoxy(0,1);sprintf(lcd," MIDDLE: %d",TCS3200_SLV_DATA[1]);lcd_putstr(lcd);
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	lcd_gotoxy(0,1);sprintf(lcd," MIDDLE: %d",TCS3200_SLV_DATA[1]);lcd_putstr(lcd);
	while(Ping[PING_RIGHT]>=20)
	{
		TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
		mov_fwd_5cm(5,FAST_LEVEL_3);
	}
	BW_PID_Init();
	FollowTracer_Right();

}

/* func      : void Nav_HallwaySC_To_4B(void)
 * brief     : Navigate from HallwaySC to Room 4B
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 25th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_HallwaySC_To_4B(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"SC TO 4B");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	BW_PID_Init();
	FollowTracer_Left();
	mov_fwd_5cm(15,FAST_LEVEL_3);
	while(1)
	{
		BW_Buzz(2);
		mov_static();
	}
}

/* func      : void Nav_HallwaySC_To_4A(void)
 * brief     : Navigate from HallwaySC to Room 4A
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 25th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_HallwaySC_To_4A(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"SC TO R4A");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	while ( (Ping[PING_FRONT]>=25) && (INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED) )
	{
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		if(Ping[PING_FRONT]<=5) mov_bwd(5,FAST_LEVEL_3);
		Get_IR();
	}

	Get_IR();
	while ( Ping[PING_FRONT]<=25 || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
	{
		if(Ping[PING_FRONT]<=5) mov_bwd(5,FAST_LEVEL_3);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);

		Get_IR();
	}

	BW_PID_Init();
	FollowTracer_Right();


}

/* func      : void Nav_HallwaySC_To_1B(void)
 * brief     : Navigate from HallwaySC to Room 1B
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 25th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_HallwaySC_To_1B(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"SC TO R1B");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	while(Ping[PING_ASKEW_LEFT]<=70)
//	while(SHARP[SHARP_LEFT])
	{
		follow_right_counter(1);
	}
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	lcd_gotoxy(0,1);sprintf(lcd," MIDDLE: %d",TCS3200_SLV_DATA[1]);lcd_putstr(lcd);
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	lcd_gotoxy(0,1);sprintf(lcd," MIDDLE: %d",TCS3200_SLV_DATA[1]);lcd_putstr(lcd);
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	lcd_gotoxy(0,1);sprintf(lcd," MIDDLE: %d",TCS3200_SLV_DATA[1]);lcd_putstr(lcd);
	while(Ping[PING_RIGHT]>=20)
	{
		TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
		mov_fwd_5cm(5,FAST_LEVEL_3);

		Get_IR();

		if(
			(INFRARED[IR_FRONT_LEFT]==IR_DETECTED) ||
			(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ||
			(Ping[PING_FRONT]<=25)
		  )
		{
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
			mov_rot_left(FAST_LEVEL_3,CLOSE);
			mov_rot_left(FAST_LEVEL_3,CLOSE);
			mov_rot_left(FAST_LEVEL_3,CLOSE);

		}
	}

	BW_PID_Init();
	FollowTracer_Left();

}

/* func      : void Nav_HallwaySC_To_1A(void)
 * brief     : Navigate from HallwaySC to Room 1A
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 25th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_HallwaySC_To_1A(int OPTION)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"SC TO R1A");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	switch(OPTION)
	{
		case 1:
				{

					BW_PID_Init();
					FollowTracer_Left();
					mov_fwd_5cm(15,FAST_LEVEL_3);

				}break;
		case 2:
				{
					FollowCarpet_Left(COLOUR_BLACK,INVERSE);

					BW_Buzz(5);
					BW_PID_Init();
					FollowTracer_Right();

				}break;
	}

}

/* func      : void Nav_3_To_HallwaySC(void)
 * brief     : Navigate from Room 3 to HallwaySC
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 26th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_3_To_HallwaySC(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R3 TO SC");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	while(Ping[PING_FRONT]<=25)
	{
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
	}

	BW_Buzz(2);
	BW_PID_Init();
	FollowHome_Left();

}

/* func      : void Nav_3_To_2(void)
 * brief     : Navigate from Room 3 to Room 2
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 26th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_3_To_2(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R3 TO R2");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
	TRACER_STAT=TRACER_INACTIVE;

//
//	mov_rot_left(FAST_LEVEL_2,FAR);
//	mov_rot_left(FAST_LEVEL_2,FAR);
//	mov_rot_left(FAST_LEVEL_2,FAR);
//	mov_fwd_5cm(10,FAST_LEVEL_2);
	if(Ping[PING_FRONT]<20)
	{
		mov_fwd_5cm(10,FAST_LEVEL_2);
	}
	while(Ping[PING_FRONT]<=25)
	{
		mov_rot_left(FAST_LEVEL_2,FAR);
		mov_rot_left(FAST_LEVEL_2,FAR);
		mov_rot_left(FAST_LEVEL_2,FAR);
	}
//	Get_IR();
//	while
//	(
//		((INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) && (INFRARED[IR_FRONT_LEFT]==IR_DETECTED))
//	)
//	{
//		Get_IR();
//		mov_rot_left(FAST_LEVEL_2,FAR);
//		mov_rot_left(FAST_LEVEL_2,FAR);
//		mov_rot_left(FAST_LEVEL_2,FAR);
//	}

//	mov_rot_left(FAST_LEVEL_2,FAR);
//	mov_rot_left(FAST_LEVEL_2,FAR);
//	mov_rot_left(FAST_LEVEL_2,FAR);
//	mov_rot_left(FAST_LEVEL_2,FAR);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);

	BW_Buzz(1);
	BW_PID_Init();
	FollowCarpet_Right(COLOUR_GRAY,INVERSE);

	BW_Buzz(1);
	BW_PID_Init();
	FollowCarpet_Right(COLOUR_BLACK,INVERSE);

	BW_Buzz(2);
	BW_PID_Init();
	follow_right_counter(8);

	mov_rot_right(FAST,CLOSE);
	BW_Buzz(1);

	while(Ping[PING_FRONT]>=20)
		{
			Evade_Wall();
			Bumper_Action();
			mov_fwd_5cm(5,FAST_LEVEL_2);
		}

		BW_Buzz(1);
		mov_rot_right(FAST,FAR);
		mov_rot_right(FAST,FAR);
		while(Ping[PING_FRONT]<=20)
		{
			mov_rot_right(FAST,FAR);
	//		mov_rot_right(FAST_LEVEL_2,FAR);
		}


	BW_Buzz(2);
	BW_PID_Init();
	FollowTracer_Left();

//	BW_Buzz(2);
//	BW_PID_Init();
//	TRACER_STAT=TRACER_INACTIVE;
//	FollowTracer_Right();

}

/* func      : void Nav_3_To_1A(void)
 * brief     : Navigate from Room 3 to Room 1A
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 26th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_3_To_1A(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R3 TO R1A");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	while(Ping[PING_FRONT]<=25)
	{
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
	}

	BW_Buzz(2);
	BW_PID_Init();
	FollowCarpet_Right(COLOUR_GRAY,INVERSE);

	BW_Buzz(2);
	BW_PID_Init();
	FollowCarpet_Left(COLOUR_BLACK,INVERSE);

	BW_Buzz(2);
	BW_PID_Init();
	FollowCarpet_Left(COLOUR_GRAY,INVERSE);


	BW_Buzz(2);

	BW_PID_Init();
	FollowTracer_Left();
}

/* func      : void Nav_3_To_1BC(void)
 * brief     : Navigate from Room 3 to Room 1BC
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 26th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_3_To_1BC(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R3 TO R1BC");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_fwd_5cm(10,FAST_LEVEL_2);
	while(Ping[PING_FRONT]<=20)
	{
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST,FAR);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
	}

	BW_Buzz(1);
	BW_PID_Init();
	FollowCarpet_Right(COLOUR_GRAY,INVERSE);

	BW_Buzz(1);
	BW_PID_Init();
	FollowCarpet_Right(COLOUR_BLACK,INVERSE);

	Evade_Wall();

	if(Ping[PING_LEFT]>=20)
	{
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_fwd_5cm(10,FAST_LEVEL_2);
	}

//	mov_fwd_5cm(5,FAST_LEVEL_3);mov_deflect_left(FAST,CLOSE);
	BW_Buzz(2);
	BW_PID_Init();
	FollowTracer_Left();

}

/* func      : void Nav_3_To_4A(void)
 * brief     : Navigate from Room 3 to Room 4A
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 26th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_3_To_4A(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R3 TO R4A");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	while(Ping[PING_FRONT]<=25)
	{
		mov_rot_left(FAST_LEVEL_2,FAR);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
	}

	BW_Buzz(1);
	BW_PID_Init();
	follow_right_counter(3);

	BW_Buzz(2);
	BW_PID_Init();

	FollowCarpet_Right(COLOUR_GRAY,INVERSE);

//	while(Ping[PING_LEFT]<=40)
//	{
//		Evade_Wall();
//		mov_fwd_5cm(5,FAST_LEVEL_3);
//	}

//	follow_left_counter(20);
//	mov_fwd_5cm(10,FAST_LEVEL_3);
//	mov_rot_left(FAST_LEVEL_2,FAR);
//	mov_rot_left(FAST_LEVEL_2,FAR);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);

//	mov_fwd_5cm(15,FAST_LEVEL_3);

	mov_deflect_left(FAST,CLOSE);

	BW_Buzz(1);
	BW_PID_Init();
	follow_left_counter(15);
//	while( (Ping[PING_LEFT]>=40) || (Ping[PING_RIGHT]>=40) )
//	{
//		follow_left_counter(3);
//	}

	ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;
	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

	BW_Buzz(1);
	BW_PID_Init();
	FollowCarpet_Right(COLOUR_BLACK,INVERSE);


	if(CAT_FLAG==CAT_NOT_DETECTED)
	{
		mov_fwd_5cm(10,FAST_LEVEL_2);

		mov_rot_right(FAST,FAR);
		mov_rot_right(FAST,FAR);
		mov_rot_right(FAST,FAR);

		BW_Buzz(1);
		BW_PID_Init();
		FollowTracer_Right();
	}

	if(CAT_FLAG==CAT_DETECTED)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"ALTERNATE");lcd_putstr(lcd);
		lcd_gotoxy(8,1);sprintf(lcd,"ROUTE");lcd_putstr(lcd);
		delay_ms(100);

		mov_rot_right(FAST_LEVEL_2,FAR);
		mov_rot_right(FAST_LEVEL_2,FAR);
		mov_rot_right(FAST_LEVEL_2,FAR);

		while(Ping[PING_FRONT]<20)
		{
			mov_rot_right(FAST_LEVEL_2,FAR);
		}

		while(Ping[PING_RIGHT]>30)
		{
			mov_rot_right(FAST_LEVEL_2,FAR);
		}

		mov_fwd_5cm(15,FAST_LEVEL_3);

		BW_Buzz(2);
		BW_PID_Init();
		while(Ping[PING_LEFT]>=30)
		{
			follow_right_counter(5);
			Evade_Wall();
		}

		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);

		CAT_FLAG=CAT_NOT_DETECTED;
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
		BW_Buzz(2);
		BW_PID_Init();
		FollowTracer_Left();
	}
}

/* func      : void Nav_3_To_4B(void)
 * brief     : Navigate from Room 3 to Room 4B
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Thursday, March 26th 2016)
 * Revised BY: Ver.2 - Ryan (Wednesday, May 19th 2016)
 * programmer's Note:
 */
void Nav_3_To_4B(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R3 TO R4B");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	while(Ping[PING_FRONT]<=25)
	{
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
	}

//OLD ALGORITHM
//	BW_Buzz(2);
//
//	while( (Ping[PING_ASKEW_LEFT]<=100) || (Ping[PING_ASKEW_RIGHT]<=100))
//	{
//		follow_right_counter(1);
//	}
//
//	BW_Buzz(2);
//
//	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
//
//	while(TCS3200_SLV_DATA[1]!=COLOUR_BLACK)
//	{
//		Get_IR();
//		if(
//			(INFRARED[IR_FRONT_LEFT]==IR_DETECTED) ||
//			(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ||
//			(Ping[PING_FRONT]<=30)
//		  )
//		{
//			if( (Ping[PING_LEFT]<=80) )
//			{
//				BW_Buzz(1);
//				lcd_display_clear();
//				lcd_gotoxy(0,0);sprintf(lcd,"BUMP LEFT");lcd_putstr(lcd);
//				delay_ms(100);
//
//				mov_rot_right(FAST_LEVEL_3,CLOSE);
//				mov_rot_right(FAST_LEVEL_3,CLOSE);
//				mov_deflect_right(FAST,CLOSE);
//				mov_deflect_right(FAST,CLOSE);
//				mov_fwd_5cm(15,FAST_LEVEL_3);
//			}
//			else
//			{
//				BW_Buzz(1);
//				lcd_display_clear();
//				lcd_gotoxy(0,0);sprintf(lcd,"BUMP LEFT");lcd_putstr(lcd);
//				delay_ms(100);
//
//				mov_rot_left(FAST_LEVEL_3,CLOSE);
//				mov_rot_left(FAST_LEVEL_3,CLOSE);
//				mov_deflect_left(FAST,CLOSE);
//				mov_deflect_left(FAST,CLOSE);
//
//				mov_fwd_5cm(15,FAST_LEVEL_3);
//			}
//
//		}
//
//		Evade_Wall();
//		mov_fwd_5cm(5,FAST_LEVEL_3);
//	}

	BW_Buzz(2);
	BW_PID_Init();
	FollowCarpet_Right(COLOUR_GRAY,INVERSE);

	BW_Buzz(1);
//	while( (Ping[PING_LEFT]<=30) || (Ping[PING_RIGHT]<=30) )
	while( (Ping[PING_LEFT]<=30) )
	{
		Get_IR();
		if(
//			(INFRARED[IR_FRONT_LEFT]==IR_DETECTED) ||
//			(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ||
			(Ping[PING_FRONT]<=20)
		  )
		{
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
			mov_rot_right(FAST_LEVEL_3,CLOSE);
			mov_rot_right(FAST_LEVEL_3,CLOSE);
		}

		Evade_Wall();
//		mov_fwd_5cm(5,FAST_LEVEL_3);
		mov_fwd_5cm(5,FAST_LEVEL_3);
	}

//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_2,FAR);
	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);

	BW_Buzz(1);
	BW_PID_Init();
	while( (Ping[PING_RIGHT]>=25) || (Ping[PING_ASKEW_RIGHT]>=25) )
	{
		follow_left_counter(3);
	}

	BW_Buzz(1);
	Nav_TurnAround(TURN_RIGHT);

	BW_Buzz(2);
	BW_PID_Init();
	FollowTracer_Left();

}

/* func      : void Nav_2_To_HallwaySC(void)
 * brief     : Navigate from Room 2 to HallwaySC
 * param     : N/A
 * retval    : N/A
 * Ver       : 13.
 * *.3.*
 * +--
 * written By: Ryan (Thursday, March 27th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_2_To_HallwaySC(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R2 TO SC");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);

	BW_Buzz(2);
	while(Ping[PING_LEFT]>=30)
	{
//		mov_fwd_5cm(5,FAST_LEVEL_3);
		mov_fwd_5cm(5,FAST_LEVEL_3);
		Evade_Wall();
	}

	BW_Buzz(2);
	BW_PID_Init();
	while( (Ping[PING_ASKEW_LEFT]<=80) || (Ping[PING_ASKEW_RIGHT]<=80))
//	while( (SHARP[SHARP_LEFT]<=80) || (SHARP[SHARP_RIGHT]<=80))
	{
		follow_left_counter(1);
	}

	BW_Buzz(2);
	while( (Ping[PING_LEFT]<=30) || (Ping[PING_RIGHT]<=30) )
	{
		Get_IR();
		if(
			(INFRARED[IR_FRONT_LEFT]==IR_DETECTED) ||
			(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ||
			(Ping[PING_FRONT]<=25)
		  )
		{
			mov_rot_right(FAST_LEVEL_3,CLOSE);
			mov_rot_right(FAST_LEVEL_3,CLOSE);
		}

		Evade_Wall();
		mov_fwd_5cm(5,FAST_LEVEL_3);
	}

	BW_Buzz(2);
	while( (Ping[PING_LEFT]>=30) || (Ping[PING_RIGHT]>=30) )
	{
		Get_IR();
		if(
			(INFRARED[IR_FRONT_LEFT]==IR_DETECTED) ||
			(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ||
			(Ping[PING_FRONT]<=25)
		  )
		{
			mov_rot_right(FAST_LEVEL_3,CLOSE);
			mov_rot_right(FAST_LEVEL_3,CLOSE);
		}

		Evade_Wall();
		mov_fwd_5cm(5,FAST_LEVEL_3);
	}

	BW_Buzz(2);
	BW_PID_Init();
	FollowHome_Left();

}

/* func      : void Nav_2A_To_1BC(void)
 * brief     : Navigate from Room 2 to Room 1BC
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 27th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_2A_To_1BC(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R2A TO R1BC");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
	if(Ping[PING_RIGHT]>16)
	{
		mov_rot_right(FAST,FAR);
		mov_fwd_5cm(10,FAST_LEVEL_2);

		mov_deflect_right(FAST,CLOSE);
		mov_deflect_right(FAST,CLOSE);
		mov_deflect_right(FAST,CLOSE);
	}
	BW_Buzz(2);
	BW_PID_Init();
	follow_right_counter(5);
	FollowTracer_Right();

}

/* func      : void Nav_2B_To_1BC(void)
 * brief     : Navigate from Room 2 to Room 1BC
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Wednesday, April 14th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_2B_To_1BC(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R2B TO ROOM 1BC");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
	TRACER_STAT=TRACER_INACTIVE;

	if(Ping[PING_RIGHT]>16)
	{
		mov_rot_right(FAST,FAR);
		mov_fwd_5cm(10,FAST_LEVEL_2);

		mov_deflect_right(FAST,CLOSE);
		mov_deflect_right(FAST,CLOSE);
		mov_deflect_right(FAST,CLOSE);
	}

	BW_PID_Init();
	follow_right_counter(1);

	BW_Buzz(2);
	BW_PID_Init();
	FollowTracer_Right();
}


/* func      : void Nav_2_To_3(void)
 * brief     : Navigate from Room 2 to Room 3
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 27th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_2_To_3(void)
{
	int counter;

	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R2 TO R3");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	Evade_Wall();
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);

//	if (Ping[PING_FRONT]>25)
//	{
//		while(Ping[PING_FRONT]>25)
//		{
//			mov_rot_left(FAST_LEVEL_2,FAR);
//		}
//		mov_fwd_5cm(15,FAST_LEVEL_3);
//	}
//	else
//	{
//		while (Ping[PING_FRONT]<25)
//		{
//			mov_rot_left(FAST_LEVEL_2,FAR);
//		}
//
//		if(Ping[PING_FRONT]<=25)
//		{
//			mov_rot_left(FAST_LEVEL_2,FAR);
//		}
//		mov_fwd_5cm(15,FAST_LEVEL_3);
//	}

//	while(Ping[PING_RIGHT]<20)
//	{
//		mov_rot_left(FAST_LEVEL_2,FAR);
//		if(Ping[PING_FRONT]>40)break;
//		mov_rot_left(FAST,FAR);
//		mov_rot_left(FAST,FAR);
//		mov_rot_left(FAST,FAR);
//		mov_rot_left(FAST,CLOSE);
////		mov_rot_left(FAST,FAR);
////		mov_rot_left(FAST,CLOSE);
////	}
//
//	while(Ping[PING_FRONT]<20)
//	{
//		mov_rot_left(FAST_LEVEL_2,FAR);
//	}
//
//	mov_rot_left(FAST,FAR);
//	mov_rot_left(FAST,FAR);
//	mov_rot_left(FAST,FAR);

//	while(Ping[PING_LEFT]<25)
//	{
//		mov_rot_right(FAST,FAR);
//	}
//	follow_left_counter(10);
	if (Ping[PING_FRONT]>30)
	{
		while(Ping[PING_RIGHT]<30)
		{
			mov_rot_left(FAST,FAR);
			mov_rot_left(FAST,FAR);
		}
	}
	else if (Ping[PING_FRONT]<30)
	{
		while(Ping[PING_FRONT]<30)
		{
			mov_rot_left(FAST,FAR);
			mov_rot_left(FAST,FAR);
		}
	}
	mov_rot_left(FAST,FAR);
//	mov_fwd_5cm(10, FAST_LEVEL_3);


	for(counter=0;counter<=5;counter++)
		{
			mov_fwd_5cm(5,FAST_LEVEL_3);
			GetBumper();
			while(BUMPER[RIGHT]==ACTIVE)
			{
				BW_Buzz(1);
				mov_bwd_3cm(6,FAST_LEVEL_3);
				mov_rot_left(FAST_LEVEL_3, FAR);
				mov_rot_left(FAST_LEVEL_3, FAR);
		//				mov_rot_left(FAST_LEVEL_3, CLOSE);
				GetBumper();
				if(BUMPER[RIGHT]==INACTIVE)break;
			}
			GetBumper();
			while(BUMPER[LEFT]==ACTIVE)
			{
				BW_Buzz(1);
				mov_bwd_3cm(6,FAST_LEVEL_3);
				mov_rot_right(FAST_LEVEL_3, FAR);
				mov_rot_right(FAST_LEVEL_3, FAR);
		//				mov_rot_right(FAST_LEVEL_3, CLOSE);
				GetBumper();
				if(BUMPER[LEFT]==INACTIVE)break;
			}
		}
//		mov_fwd_5cm(10,FAST_LEVEL_3);

		if(Ping[PING_LEFT]>=14)
		{
		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);
		}
/*
  	for(counter=1;counter<=3;counter++)
	{
		Evade_Wall();
		Get_IR();
		if (   (INFRARED[IR_UPPER_LEFT]==IR_DETECTED) || (INFRARED[IR_UPPER_RIGHT]==IR_DETECTED) )
		{
			mov_rot_right(FAST_LEVEL_2,FAR);
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
		}
		mov_fwd_5cm(5,FAST_LEVEL_3);
	}

	BW_Buzz(2);
	if(Ping[PING_LEFT]>=18)
	{
		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);
//		mov_deflect_left(FAST,CLOSE);
	}

	BW_Buzz(2);
	BW_PID_Init();
	FollowCarpet_Left(COLOUR_GRAY,INVERSE);

	if(Ping[PING_LEFT]>=12)
	{
		mov_deflect_left(FAST,CLOSE);
	}
	if(Ping[PING_LEFT]>=12)
	{
		mov_deflect_left(FAST,CLOSE);
	}
	if(Ping[PING_LEFT]>=12)
	{
		mov_deflect_left(FAST,CLOSE);
	}

	BW_Buzz(2);
	BW_PID_Init();
	FollowCarpet_Left(COLOUR_BLACK,INVERSE);

	if(Ping[PING_LEFT]>=12)
	{
		mov_deflect_left(FAST,CLOSE);
	}
	if(Ping[PING_LEFT]>=12)
	{
		mov_deflect_left(FAST,CLOSE);
	}
	mov_rot_left(FAST_LEVEL_3,CLOSE);

	BW_Buzz(1);
	while(Ping[PING_FRONT]>=17)
	{
		Evade_Wall();
		mov_fwd_5cm(5,FAST_LEVEL_3);
	}

	BW_Buzz(1);
	mov_rot_right(FAST_LEVEL_3,CLOSE);
	mov_rot_right(FAST_LEVEL_3,CLOSE);
	while(Ping[PING_FRONT]<=25)
	{
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
	}
*/

	BW_Buzz(1);
	BW_PID_Init();
	FollowTracer_Left();
}

/* func      : void Nav_2_To_4A(void)
 * brief     : Navigate from Room 2 to Room 4A
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 27th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_2_To_4A(void)
{
	int counter;

	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R2 TO R4A");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	while(Ping[PING_RIGHT]<30)
//	{
//		mov_rot_left(FAST_LEVEL_2,FAR);
//		mov_rot_left(FAST_LEVEL_2,FAR);
//	}
	if (Ping[PING_FRONT]>30)
	{
		while(Ping[PING_RIGHT]<30)
		{
			mov_rot_left(FAST,FAR);
			mov_rot_left(FAST,FAR);
		}
	}
	else if (Ping[PING_FRONT]<30)
	{
		while(Ping[PING_FRONT]<30)
		{
			mov_rot_left(FAST,FAR);
			mov_rot_left(FAST,FAR);
		}
	}
	mov_rot_left(FAST,FAR);
//	mov_rot_left(FAST,FAR);
	mov_fwd_5cm(5,FAST_LEVEL_2);
//	mov_rot_left(FAST_LEVEL_2,FAR);

//	while(Ping[PING_FRONT]<=25)
//	{
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//	}

	for(counter=1;counter<=3;counter++)
	{
		Evade_Wall();
//		Get_IR();
//		if ( (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) ||  (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) )
//		{
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//		}
		Bumper_Action();
		mov_fwd_5cm(5,FAST_LEVEL_3);
	}
	mov_deflect_left(FAST,CLOSE);
	mov_deflect_left(FAST,CLOSE);


	BW_Buzz(1);
	BW_PID_Init();
	FollowCarpet_Left(COLOUR_GRAY,INVERSE);
	mov_fwd_5cm(10,FAST_LEVEL_2);
//	while(Ping[PING_RIGHT]>=30)
//	{
//		BW_Buzz(1);
//		BW_PID_Init();
//		follow_left_counter(1);
//	}
//
//	Nav_TurnAround(TURN_RIGHT);
//
//	BW_Buzz(1);
//	BW_PID_Init();
//	follow_left_counter(15);
//
//	if(Ping[PING_LEFT]>=17)
//	{
//		mov_deflect_left(FAST,CLOSE);
//		mov_deflect_left(FAST,CLOSE);
//		mov_deflect_left(FAST,CLOSE);
//
//	}


//	mov_fwd_5cm(15,FAST_LEVEL_3);
//	BW_Buzz(1);
//	while(Ping[PING_LEFT]<=30)
//	{
//		Evade_Wall();
//		mov_fwd_5cm(5,FAST_LEVEL_3);
//	}
//
//	BW_Buzz(1);
//	while( (Ping[PING_RIGHT]>=30) )
//	{
//		Get_IR();
//		if(
//			(INFRARED[IR_FRONT_LEFT]==IR_DETECTED) ||
//			(INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) ||
//			(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ||
//			(Ping[PING_FRONT]<=30)
//		  )
//		{
//			if( (Ping[PING_LEFT]<=80) )
//			{
//				BW_Buzz(1);
//				lcd_display_clear();
//				lcd_gotoxy(0,0);sprintf(lcd,"BUMP LEFT");lcd_putstr(lcd);
//				delay_ms(100);
//
//				mov_rot_right(FAST_LEVEL_3,CLOSE);
//				mov_rot_right(FAST_LEVEL_3,CLOSE);
//				mov_deflect_right(FAST,CLOSE);
//				mov_deflect_right(FAST,CLOSE);
//				mov_fwd_5cm(15,FAST_LEVEL_3);
//			}
//			else
//			{
//				BW_Buzz(1);
//				lcd_display_clear();
//				lcd_gotoxy(0,0);sprintf(lcd,"BUMP RIGHT");lcd_putstr(lcd);
//				delay_ms(100);
//
//				mov_rot_left(FAST_LEVEL_3,CLOSE);
//				mov_rot_left(FAST_LEVEL_3,CLOSE);
//				mov_deflect_left(FAST,CLOSE);
//				mov_deflect_left(FAST,CLOSE);
//
//				mov_fwd_5cm(15,FAST_LEVEL_3);
//			}
//
//		}
//	}

//	BW_Buzz(2);
//	BW_PID_Init();
//	while( (Ping[PING_ASKEW_LEFT]<=80) || (Ping[PING_ASKEW_RIGHT]<=80))
//	{
//		follow_left_counter(1);
//	}
//	BW_Buzz(2);
//	BW_PID_Init();
//	FollowCarpet_Right(COLOUR_BLACK,INVERSE);
//
//	BW_Buzz(1);
//	mov_rot_right(FAST,FAR);
//	mov_rot_right(FAST,FAR);
//
//	BW_Buzz(2);
//	BW_PID_Init();
//	FollowTracer_Right();
//	while( (Ping[PING_LEFT]<=40) )
//	{
//		Get_IR();
//		if(
//			(INFRARED[IR_FRONT_LEFT]==IR_DETECTED) ||
//			(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ||
//			(Ping[PING_FRONT]<=25)
//		  )
//		{
//			BW_Buzz(1);
//			lcd_display_clear();
//			lcd_gotoxy(0,0);sprintf(lcd,"BUMP LEFT");lcd_putstr(lcd);
//			delay_ms(100);
//
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//		}
//
//		Evade_Wall();
//		mov_fwd_5cm(15,FAST_LEVEL_3);
//	}

	//DEFAULT ROUTE
	if (R2TO4A_SP_ROUTE==R2TO4A_SP_INACTIVE)
	{
//OLD CROSSING ALGORITHM
//		BW_Buzz(1);
//		while( (Ping[PING_LEFT]>=30) || (Ping[PING_RIGHT]>=30) )
//		{
//			Get_IR();
//			if(
//				(INFRARED[IR_FRONT_LEFT]==IR_DETECTED) ||
//				(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ||
//				(Ping[PING_FRONT]<=30)
//			  )
//			{
//				BW_Buzz(1);
//				lcd_display_clear();
//				lcd_gotoxy(0,0);sprintf(lcd,"BUMP RIGHT");lcd_putstr(lcd);
//				delay_ms(100);
//
//				mov_rot_right(FAST_LEVEL_3,CLOSE);
//				mov_rot_right(FAST_LEVEL_3,CLOSE);
//			}
//
//			Evade_Wall();
//			mov_fwd_5cm(5,FAST_LEVEL_3);
//		}

//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);

		BW_Buzz(1);
		BW_PID_Init();
		while( (Ping[PING_RIGHT]>=30) || (Ping[PING_LEFT]>=25) )
		{
			follow_left_counter(3);
		}

		BW_Buzz(1);
		Nav_TurnAround(TURN_RIGHT);

		BW_Buzz(1);
		BW_PID_Init();
		while( (Ping[PING_RIGHT]>=30) || (Ping[PING_ASKEW_RIGHT]>=30) )
//		while( (Ping[PING_RIGHT]>=25) || (SHARP[SHARP_RIGHT]>=25) )
		{
			follow_left_counter(3);
		}

		BW_Buzz(1);
		BW_PID_Init();
		follow_left_counter(8);

		ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

		BW_Buzz(1);
		BW_PID_Init();
		FollowCarpet_Right(COLOUR_BLACK,INVERSE);


		if(CAT_FLAG==CAT_NOT_DETECTED)
		{
//			mov_fwd_5cm(15,FAST_LEVEL_3);
			while(Ping[PING_RIGHT]<30)
			{
				mov_fwd_5cm(5,FAST_LEVEL_2);
			}

			mov_rot_right(FAST,FAR);
			mov_rot_right(FAST,FAR);
			mov_rot_right(FAST,FAR);
//			mov_rot_right(FAST_LEVEL_3,CLOSE);

			BW_Buzz(1);
			BW_PID_Init();
			FollowTracer_Right();
		}

		if (CAT_FLAG==CAT_DETECTED)
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"ALTERNATE");lcd_putstr(lcd);
			lcd_gotoxy(8,1);sprintf(lcd,"ROUTE");lcd_putstr(lcd);
			lcd_gotoxy(3,1);sprintf(lcd,"R2 TO R4B");lcd_putstr(lcd);
			delay_ms(100);

			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

			BW_Buzz(2);
			BW_PID_Init();
			FollowTracer_Left();
		}

	}
	else if (R2TO4A_SP_ROUTE==R2TO4A_SP_ACTIVE)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"SPECIAL");lcd_putstr(lcd);
		lcd_gotoxy(8,1);sprintf(lcd,"ROUTE");lcd_putstr(lcd);
		lcd_gotoxy(3,2);sprintf(lcd,"R2 TO R4B");lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"CAT CONFIG A");lcd_putstr(lcd);
		delay_ms(100);

		BW_Buzz(2);
		mov_deflect_right(FAST,FAR);
		mov_deflect_right(FAST,FAR);
		mov_deflect_right(FAST,FAR);
		mov_deflect_right(FAST,FAR);
		mov_rot_right(FAST,FAR);
		mov_rot_right(FAST,FAR);
		mov_rot_right(FAST,FAR);
		mov_rot_right(FAST,FAR);
		mov_fwd_5cm(10,FAST_LEVEL_2);

		BW_Buzz(2);
		BW_PID_Init();
		FollowCarpet_Right(COLOUR_BLACK,INVERSE);

		mov_deflect_left(FAST,FAR);
		mov_deflect_left(FAST,FAR);
		mov_deflect_left(FAST,FAR);
		mov_deflect_left(FAST,FAR);
		mov_fwd_5cm(10,FAST_LEVEL_2);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//
//		BW_Buzz(2);
//		while( (Ping[PING_RIGHT]>=30) )
//		{
//			Get_IR();
//			if(
//				(INFRARED[IR_FRONT_LEFT]==IR_DETECTED) ||
//				(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ||
//				(Ping[PING_FRONT]<=25)
//			  )
//			{
//				mov_rot_right(FAST_LEVEL_3,CLOSE);
//				mov_rot_right(FAST_LEVEL_3,CLOSE);
//			}
//
//			Evade_Wall();
//			mov_fwd_5cm(5,FAST_LEVEL_3);
//		}
//
//		mov_fwd_5cm(10,FAST_LEVEL_3);
//
//		if(Ping[PING_LEFT]<=17)
//		{
//			mov_deflect_left(FAST,CLOSE);
//			mov_deflect_left(FAST,CLOSE);
//		}

	//	mov_deflect_left(FAST,CLOSE);

		BW_Buzz(2);
		BW_PID_Init();
		FollowTracer_Left();

	}

}

/* func      : void Nav_2_To_4B(void)
 * brief     : Navigate from Room 2 to Room 4B
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Thursday, March 27th 2016)
 * Revised BY: Ryan (Friday, December 2nd 2016
 * programmer's Note:
 */
void Nav_2_To_4B(void)
{
	int counter;

	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R2 TO R4B");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);

//	while(Ping[PING_RIGHT]<30)
//	{
//		mov_rot_left(FAST,FAR);
//	}
//
//	while(Ping[PING_LEFT]<30)
//	{
//		mov_rot_right(FAST,FAR);
//	}

	if (Ping[PING_FRONT]>30)
	{
		while(Ping[PING_RIGHT]<30)
		{
			mov_rot_left(FAST,FAR);
			mov_rot_left(FAST,FAR);
		}
	}
	else if (Ping[PING_FRONT]<30)
	{
		while(Ping[PING_FRONT]<30)
		{
			mov_rot_left(FAST,FAR);
			mov_rot_left(FAST,FAR);
		}
	}
	mov_rot_left(FAST,FAR);
//	mov_rot_left(FAST,CLOSE);
//	mov_rot_left(FAST,CLOSE);
//	mov_fwd_5cm(10,FAST_LEVEL_2);

	for(counter=1;counter<=5;counter++)
	{
		Evade_Wall();
		Bumper_Action();
		mov_fwd_5cm(5,FAST_LEVEL_3);
	}

	if(Ping[PING_LEFT]<20)
	{
		mov_deflect_left(FAST,CLOSE);
	}
	if(Ping[PING_LEFT]<20)
	{
		mov_deflect_left(FAST,CLOSE);
	}
	if(Ping[PING_LEFT]<20)
	{
		mov_deflect_left(FAST,CLOSE);
	}
//	BW_Buzz(1);
//	while(Ping[PING_LEFT]>=30)
//	{
//		Evade_Wall();
//		Bumper_Action();
//		mov_fwd_5cm(5,FAST_LEVEL_3);
//	}

//	mov_fwd_5cm(15,FAST_LEVEL_3);
//
//	mov_deflect_left(FAST,CLOSE);
//	mov_deflect_left(FAST,CLOSE);

//	if(Ping[PING_LEFT]<=13)
//	{
//		mov_deflect_left(FAST,CLOSE);
//		mov_deflect_left(FAST,CLOSE);
//	}
//
//	BW_Buzz(1);
//	BW_PID_Init();
//	FollowCarpet_Left(COLOUR_GRAY,INVERSE);
//
////	mov_fwd_5cm(10,FAST_LEVEL_3);
//
//
////	while( (Ping[PING_LEFT]<=80) )
////	{
////		mov_fwd_5cm(15,FAST_LEVEL_3);
////		Evade_Wall();
////	}
//
//
////	BW_Buzz(2);
////	while(Ping[PING_LEFT]>=30)
////	{
////		mov_fwd_5cm(5,FAST_LEVEL_3);
////		Evade_Wall();
////	}
////
////	BW_Buzz(2);
////	BW_PID_Init();
////	while( (Ping[PING_LEFT]<=80) )
////	{
////		mov_fwd_5cm(5,FAST_LEVEL_3);
////		Evade_Wall();
////	}
//
//	BW_Buzz(1);
//	while(Ping[PING_LEFT]<=30)
//	{
//		Evade_Wall();
//		mov_fwd_5cm(5,FAST_LEVEL_3);
//	}
//
////	mov_fwd_5cm(5,FAST_LEVEL_3);
//
//	BW_Buzz(2);
//	mov_rot_right(FAST_LEVEL_2,FAR);
//	mov_rot_right(FAST_LEVEL_2,FAR);
//	mov_rot_right(FAST_LEVEL_2,FAR);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//
//
//
//	BW_Buzz(2);
//	while( (Ping[PING_RIGHT]>=30) )
//	{
//		Get_IR();
//		if(
//			(INFRARED[IR_FRONT_LEFT]==IR_DETECTED) ||
//			(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ||
//			(Ping[PING_FRONT]<=25)
//		  )
//		{
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//		}
//
//		Evade_Wall();
//		mov_fwd_5cm(5,FAST_LEVEL_3);
//	}
//
//	mov_fwd_5cm(10,FAST_LEVEL_3);
//
//	if(Ping[PING_LEFT]<=13)
//	{
//		mov_deflect_left(FAST,CLOSE);
//		mov_deflect_left(FAST,CLOSE);
//	}
//
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);

//	mov_deflect_left(FAST,CLOSE);

//	BW_Buzz(1);
//	BW_PID_Init();
//	FollowCarpet_Right(COLOUR_GRAY,INVERSE);

	BW_Buzz(1);
	BW_PID_Init();
	FollowCarpet_Left(COLOUR_GRAY,INVERSE);

	mov_rot_right(FAST_LEVEL_2,FAR);
	mov_rot_right(FAST_LEVEL_2,FAR);

	BW_Buzz(1);
	BW_PID_Init();
	FollowCarpet_Right(COLOUR_BLACK,INVERSE);

	mov_deflect_left(FAST,CLOSE);
	mov_deflect_left(FAST,CLOSE);
	mov_deflect_left(FAST,CLOSE);

	BW_Buzz(2);
	BW_PID_Init();
	FollowTracer_Left();

}

/* func      : void Nav_2_To_1A(void)
 * brief     : Navigate from Room 2 to Room 1A
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Thursday, March 27th 2016)
 * Revised BY: Ver.2 : Ryan (Tuesday, April 5th 2016)
 * programmer's Note:
 */
void Nav_2_To_1A(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R2 TO R1A");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	BW_Buzz(2);
	BW_PID_Init();
	follow_right_counter(7);

	BW_Buzz(2);
	BW_PID_Init();
	FollowTracer_Left();

}

/* func      : void Nav_1A_To_4A(void)
 * brief     : Navigate from Room 1A to Room HallwaySC
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 28th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_1A_To_HallwaySC(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1A TO SC");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	BW_Buzz(2);
	BW_PID_Init();
	FollowCarpet_Right(COLOUR_GRAY,INVERSE);

	if(CAT_FLAG==CAT_NOT_DETECTED)
	{
		BW_Buzz(2);
		BW_PID_Init();
		FollowCarpet_Right(COLOUR_BLACK,INVERSE);
	}

	//CAT DETECTED IN CONFIG B (RIGHT SIDE OF ROOM 4
	if(CAT_FLAG==CAT_DETECTED)
	{
		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"CAT DETECTED");lcd_putstr(lcd);
		lcd_gotoxy(3,1);sprintf(lcd,"CONFIG B");lcd_putstr(lcd);
		delay_ms(100);

		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"FOLLOWCARPET");lcd_putstr(lcd);
		lcd_gotoxy(3,1);sprintf(lcd,"BLACK");lcd_putstr(lcd);
		delay_ms(100);
		BW_Buzz(2);
		BW_PID_Init();
		FollowCarpet_Right(COLOUR_BLACK,INVERSE);

		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"FOLLOWCARPET");lcd_putstr(lcd);
		lcd_gotoxy(3,1);sprintf(lcd,"GRAY");lcd_putstr(lcd);
		delay_ms(100);
		BW_Buzz(2);
		BW_PID_Init();
		FollowCarpet_Right(COLOUR_GRAY,INVERSE);

		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"FOLLOWCARPET");lcd_putstr(lcd);
		lcd_gotoxy(3,1);sprintf(lcd,"BLACK");lcd_putstr(lcd);
		delay_ms(100);
		BW_Buzz(2);
		BW_PID_Init();
		FollowCarpet_Right(COLOUR_BLACK,INVERSE);

		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"FORWARD TO");lcd_putstr(lcd);
		lcd_gotoxy(3,1);sprintf(lcd,"CROSSROAD");lcd_putstr(lcd);
		delay_ms(100);
		BW_Buzz(2);
		while( (Ping[PING_LEFT]<=30) || (Ping[PING_RIGHT]<=30) )
		{
			Get_IR();
			if(
				(INFRARED[IR_FRONT_LEFT]==IR_DETECTED) ||
				(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ||
				(Ping[PING_FRONT]<=25)
			  )
			{
				mov_rot_right(FAST_LEVEL_3,CLOSE);
				mov_rot_right(FAST_LEVEL_3,CLOSE);
			}

			Evade_Wall();
			mov_fwd_5cm(5,FAST_LEVEL_3);
		}

		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"FOLLOW RIGHT");lcd_putstr(lcd);
		lcd_gotoxy(3,1);sprintf(lcd,"10 STEP");lcd_putstr(lcd);
		delay_ms(100);
		BW_Buzz(2);
		BW_PID_Init();
		follow_right_counter(10);

		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"DEFLECT LEFT");lcd_putstr(lcd);
		lcd_gotoxy(3,1);sprintf(lcd,"3 TIMES");lcd_putstr(lcd);
		delay_ms(100);
		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);

		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"FOLLOWHOME");lcd_putstr(lcd);
		lcd_gotoxy(3,1);sprintf(lcd,"LEFT RULE");lcd_putstr(lcd);
		delay_ms(100);
		BW_Buzz(2);
		BW_PID_Init();
		FollowHome_Left();
	}

	//CAT NOT DETECTED IN CONFIG B
	else
	{
		BW_Buzz(2);
		BW_PID_Init();
		FollowHome_Right();

		//CAT DETECTED IN CONFIG A
		if(CAT_FLAG==CAT_DETECTED)
		{
			lcd_display_clear();
			lcd_gotoxy(3,0);sprintf(lcd,"CAT DETECTED");lcd_putstr(lcd);
			lcd_gotoxy(3,1);sprintf(lcd,"CONFIG A");lcd_putstr(lcd);
			delay_ms(100);

			BW_Buzz(2);
			BW_PID_Init();
			FollowCarpet_Right(COLOUR_GRAY,INVERSE);

			BW_Buzz(2);
			BW_PID_Init();
			FollowCarpet_Right(COLOUR_BLACK,INVERSE);

			BW_Buzz(2);
			while( (Ping[PING_LEFT]<=30) || (Ping[PING_RIGHT]<=30) )
			{
				Get_IR();
				if(
					(INFRARED[IR_FRONT_LEFT]==IR_DETECTED) ||
					(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ||
					(Ping[PING_FRONT]<=25)
				  )
				{
					mov_rot_right(FAST_LEVEL_3,CLOSE);
					mov_rot_right(FAST_LEVEL_3,CLOSE);
				}

				Evade_Wall();
				mov_fwd_5cm(5,FAST_LEVEL_3);
			}

			BW_Buzz(2);
			BW_PID_Init();
			follow_right_counter(10);

			mov_deflect_left(FAST,CLOSE);
			mov_deflect_left(FAST,CLOSE);
			mov_deflect_left(FAST,CLOSE);

			BW_Buzz(2);
			BW_PID_Init();
			FollowHome_Left();
		}

		//CAT OBSTACLE NOT DETECTED
		else
		{
			BW_Buzz(2);
			BW_PID_Init();
			FollowHome_Right();
		}

	}



}


/* func      : void Nav_1A_To_2(void)
 * brief     : Navigate from Room 1A to Room 2
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Thursday, March 28th 2016)
 * Revised BY: Ver.2 :  Ryan (Tuesday, April 5th 2016)
 * programmer's Note:
 */
void Nav_1A_To_2(void)
{
//	int counter;

	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1A TO R2");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
	ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;
	CAT_FLAG=CAT_NOT_DETECTED;

	BW_Buzz(2);
	mov_rot_left(FAST,FAR);
	mov_rot_left(FAST,FAR);
	mov_rot_left(FAST,FAR);
	mov_rot_left(FAST,FAR);
	if(Ping[PING_FRONT]<30)
	{
		mov_rot_right(FAST,FAR);
		mov_rot_right(FAST,CLOSE);
	}
//	mov_rot_left(FAST,FAR);
//	mov_rot_left(FAST,FAR);
//
//	mov_deflect_left(FAST,CLOSE);
//	mov_deflect_left(FAST,CLOSE);
//	mov_deflect_left(FAST,CLOSE);


//	BW_Buzz(2);
//	BW_PID_Init();
//	FollowCarpet_Left(COLOUR_GRAY,INVERSE);
//	while( ((Ping[PING_LEFT]>=30) || (Ping[PING_RIGHT]>=30)) && (CAT_FLAG==CAT_NOT_DETECTED) )
//	{
////		Get_IR();
////		if( (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) )
////		{
////			mov_rot_right(FAST_LEVEL_3,CLOSE);
//////			mov_rot_right(FAST_LEVEL_3,CLOSE);
////		}
//
		while(((Ping[PING_LEFT]>=30) || (Ping[PING_RIGHT]>=30)) && (CAT_FLAG==CAT_NOT_DETECTED)){

			Cat_Avoider();
			Bumper_Action();
			mov_fwd_5cm(5, FAST);
			if(CAT_FLAG==CAT_DETECTED)break;
		}
//		if(CAT_FLAG==CAT_DETECTED)break;
////		mov_fwd_5cm(5,FAST_LEVEL_3);
//		mov_fwd_5cm(5, FAST_LEVEL_3);
//		if(CAT_FLAG==CAT_DETECTED)break;
//		Evade_Wall();
//		if(CAT_FLAG==CAT_DETECTED)break;
//	}

//	BW_Buzz(2);
//	BW_PID_Init();
//	while( (Ping[PING_LEFT]<=40) && (CAT_FLAG==CAT_NOT_DETECTED) )
//	{
//		Cat_Avoider();
//		follow_left_counter(1);
//	}

	if(CAT_FLAG==CAT_NOT_DETECTED)
	{
		BW_Buzz(1);
		BW_PID_Init();
		FollowCarpet_Left(COLOUR_BLACK,INVERSE);

		BW_Buzz(1);
		BW_PID_Init();
		FollowCarpet_Left(COLOUR_GRAY,INVERSE);

		BW_Buzz(1);
		BW_PID_Init();
		FollowCarpet_Left(COLOUR_BLACK,INVERSE);

		mov_deflect_right(FAST,CLOSE);
		mov_deflect_right(FAST,CLOSE);
		mov_deflect_right(FAST,CLOSE);

		BW_Buzz(2);
		BW_PID_Init();
		FollowTracer_Right();

	}


//	if(CAT_FLAG==CAT_NOT_DETECTED)
//	{
////		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
//
////		mov_fwd_5cm(15,FAST_LEVEL_3);
//		mov_fwd_5cm(15, FAST_LEVEL_3);
//
//		BW_Buzz(1);
//		BW_PID_Init();
//		FollowCarpet_Left(COLOUR_BLACK,INVERSE);
//
//		BW_Buzz(1);
//		BW_PID_Init();
//		FollowCarpet_Left(COLOUR_GRAY,INVERSE);
//
//		BW_Buzz(2);
//		while(Ping[PING_LEFT]<=30)
//		{
//			Evade_Wall();
////			mov_fwd_5cm(5,FAST_LEVEL_3);
//			mov_fwd_5cm(5, FAST_LEVEL_3);
//		}
//
//		Evade_Wall();
////		mov_fwd_5cm(5,FAST_LEVEL_3);
//		mov_fwd_5cm(5, FAST_LEVEL_3);
//
//		Evade_Wall();
////		mov_fwd_5cm(5,FAST_LEVEL_3);
//		mov_fwd_5cm(5, FAST_LEVEL_3);
//
//		Evade_Wall();
////		mov_fwd_5cm(5,FAST_LEVEL_3);
//		mov_fwd_5cm(5, FAST_LEVEL_3);
//
//
//		BW_Buzz(2);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
////		mov_rot_left(FAST_LEVEL_3,CLOSE);
//
//		BW_Buzz(2);
//		while(Ping[PING_RIGHT]>=30)
//		{
//			Evade_Wall();
////			mov_fwd_5cm(5,FAST_LEVEL_3);
//			mov_fwd_5cm(5, FAST_LEVEL_3);
//		}
//
//		BW_Buzz(2);
//		BW_PID_Init();
//		FollowTracer_Right();
//	}


	if (CAT_FLAG==CAT_DETECTED)
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

//		mov_deflect_right(FAST,CLOSE);
//		mov_deflect_right(FAST,CLOSE);
//		mov_deflect_right(FAST,CLOSE);
		mov_bwd_5cm(10,FAST_LEVEL_3);
		mov_rot_right(FAST,FAR);
		mov_rot_right(FAST,FAR);
		mov_rot_right(FAST,FAR);
		mov_rot_right(FAST,FAR);

		BW_Buzz(1);
		BW_PID_Init();
		follow_right_counter(13);

//		while(Ping[PING_FRONT]>=20)
//		{
//			Evade_Wall();
////			mov_fwd_5cm(5,FAST_LEVEL_3);
//			mov_fwd_5cm(5, FAST_LEVEL_3);
//		}

		BW_Buzz(1);
		BW_PID_Init();
		FollowCarpet_Right(COLOUR_BLACK,INVERSE);

//		BW_Buzz(1);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);

		BW_Buzz(1);
		BW_PID_Init();
		FollowCarpet_Right(COLOUR_GRAY,INVERSE);

//		while(Ping[PING_FRONT]<=25)
//		{
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//		}

		BW_Buzz(1);
		BW_PID_Init();
		FollowCarpet_Right(COLOUR_BLACK,INVERSE);


//		BW_Buzz(1);
//		BW_PID_Init();
//		FollowCarpet_Right(COLOUR_GRAY,INVERSE);
//		Nav_TurnAround(TURN_LEFT);
//
//		Evade_Wall();
//		BW_Buzz(1);
//		while(Ping[PING_FRONT]>=20)
//		{
//			Evade_Wall();
////			mov_fwd_5cm(5,FAST_LEVEL_3);
//			mov_fwd_5cm(5, FAST_LEVEL_3);
//		}
//
//		BW_Buzz(1);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//
//		while(Ping[PING_FRONT]<=25)
//		{
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//		}
//
//		BW_Buzz(1);
//		BW_PID_Init();
//		follow_right_counter(4);
//
//		BW_Buzz(1);
//		while( (Ping[PING_RIGHT]<=30) )
//		{
//			Get_IR();
//			if(
//				(INFRARED[IR_FRONT_LEFT]==IR_DETECTED) ||
//				(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ||
//				(Ping[PING_FRONT]<=25)
//			  )
//			{
//				mov_rot_right(FAST_LEVEL_3,CLOSE);
//				mov_rot_right(FAST_LEVEL_3,CLOSE);
//			}
//
//			Evade_Wall();
////			mov_fwd_5cm(5,FAST_LEVEL_3);
//			mov_fwd_5cm(5, FAST_LEVEL_3);
//		}
//
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//
//		BW_Buzz(1);
//		BW_PID_Init();
//		while( (Ping[PING_LEFT]>=25) || (Ping[PING_ASKEW_LEFT]>=25) )
////		while( (Ping[PING_LEFT]>=25) || (SHARP[SHARP_LEFT]>=25) )
////		while (Ping[PING_LEFT]>=25)
//		{
//			follow_right_counter(3);
//		}

		BW_Buzz(1);
		Nav_TurnAround(TURN_LEFT);

		BW_Buzz(1);
		BW_PID_Init();
		FollowTracer_Right();
	}



//	while(1)
//	{
//		BW_Buzz(2);
//		mov_static();
//	}
}

/* func      : void Nav_1A_To_3(void)
 * brief     : Navigate from Room 1A to Room 3
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 28th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_1A_To_3(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1A TO R3");lcd_putstr(lcd);
	delay_ms(100);



//	BW_Buzz(2);
//	BW_PID_Init();
//	while( (Ping[PING_ASKEW_LEFT]<=80) || (Ping[PING_ASKEW_RIGHT]<=80))
//	{
//		follow_left_counter(1);
//	}

	mov_fwd_3cm(3,FAST_LEVEL_3);		//BARU DITAMBAHIN

	while(Ping[PING_RIGHT]<30)
	{
		mov_rot_left(FAST,FAR);
		mov_rot_left(FAST,FAR);
	}

	mov_rot_left(FAST,CLOSE);
	mov_rot_left(FAST,CLOSE);
//	mov_rot_left(FAST,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
	ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;

	mov_fwd_5cm(5,FAST_LEVEL_3);
	BW_Buzz(2);
	while( (Ping[PING_LEFT]>=30) && (CAT_FLAG==CAT_NOT_DETECTED) )
	{
//		Get_IR();
//		if(INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED)
//		{
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//		}
													// TAMBAH FUNGSI BUMPER YANG MUNDUR
		GetBumper();
		while(BUMPER[LEFT]==ACTIVE)
		{
			BW_Buzz(1);
			mov_bwd_3cm(6,FAST_LEVEL_3);
			mov_rot_right(FAST, FAR);
			mov_rot_right(FAST, FAR);
//							mov_rot_right(FAST_LEVEL_3, FAR);

			GetBumper();
			if(BUMPER[LEFT]==INACTIVE) break;
		}
		while(BUMPER[RIGHT]==ACTIVE)
		{
			BW_Buzz(1);
			mov_bwd_3cm(6,FAST_LEVEL_3);
			mov_rot_left(FAST, FAR);
			mov_rot_left(FAST, FAR);
//							mov_rot_left(FAST_LEVEL_3, FAR);
			GetBumper();
			if(BUMPER[RIGHT]==INACTIVE) break;
		}


		Cat_Avoider();
		if(CAT_FLAG==CAT_DETECTED)break;
//		mov_fwd_5cm(5,FAST_LEVEL_3);
		mov_fwd_5cm(5, FAST_LEVEL_3);
		if(CAT_FLAG==CAT_DETECTED)break;
		Evade_Wall();
		if(CAT_FLAG==CAT_DETECTED)break;
	}

	Cat_Avoider();

//	BW_Buzz(1);
//	BW_PID_Init();
//	FollowCarpet_Left(COLOUR_GRAY,INVERSE);



	if(CAT_FLAG==CAT_NOT_DETECTED)
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

		mov_fwd_5cm(5,FAST_LEVEL_3);
		if(Ping[PING_LEFT]>=15)					//BARU DITAMBAHIN
		{
			mov_deflect_left(FAST,CLOSE);
			mov_deflect_left(FAST,CLOSE);
			mov_deflect_left(FAST,CLOSE);
		}
		BW_Buzz(1);
		BW_PID_Init();
		FollowCarpet_Left(COLOUR_GRAY,INVERSE);

		BW_Buzz(1);
		BW_PID_Init();
		FollowCarpet_Left(COLOUR_BLACK,INVERSE);

//		BW_Buzz(1);
//		BW_PID_Init();
//		FollowCarpet_Left(COLOUR_GRAY,INVERSE);

		BW_Buzz(1);
		BW_PID_Init();
		FollowCarpet_Left(COLOUR_GRAY,INVERSE);
//		while( (Ping[PING_LEFT]<=30) || (Ping[PING_RIGHT]<=30) )
//		{
//			Get_IR();
//			if(
//				(INFRARED[IR_UPPER_LEFT]==IR_DETECTED) ||
//				(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED) ||
//				(Ping[PING_FRONT]<=25)
//			  )
//			{
////				mov_rot_right(FAST_LEVEL_3,CLOSE);
////				mov_rot_right(FAST_LEVEL_3,CLOSE);
//				mov_rot_right(FAST_LEVEL_3,CLOSE);
//				mov_rot_right(FAST_LEVEL_3,CLOSE);
//			}
//
//			Evade_Wall();
////			mov_fwd_5cm(5,FAST_LEVEL_3);
//			mov_fwd_5cm(5, FAST_LEVEL_3);
//		}

//		mov_deflect_right(FAST,CLOSE);
//		mov_deflect_right(FAST,CLOSE);
//		mov_deflect_right(FAST,CLOSE);
//		mov_deflect_right(FAST,CLOSE);
//		mov_deflect_right(FAST,CLOSE);
//		mov_deflect_right(FAST,CLOSE);

//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);

//OLD ALGORITHM
//		BW_Buzz(1);
//		while( (Ping[PING_LEFT]>=30) )
//		{
//			Get_IR();
//			if(
//				(INFRARED[IR_FRONT_LEFT]==IR_DETECTED) ||
//				(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ||
//				(Ping[PING_FRONT]<=30)
//			  )
//			{
//				mov_rot_right(FAST_LEVEL_3,CLOSE);
//				mov_rot_right(FAST_LEVEL_3,CLOSE);
//			}
//
//			Evade_Wall();
//			mov_fwd_5cm(5,FAST_LEVEL_3);
//		}
//
//		mov_fwd_5cm(15,FAST_LEVEL_3);

//		BW_Buzz(1);
//		BW_PID_Init();
//		while( (Ping[PING_LEFT]>=25) || (Ping[PING_ASKEW_LEFT]>=25) )
////		while( (Ping[PING_LEFT]>=25) || (SHARP[SHARP_LEFT]>=25) )
////		while (Ping[PING_LEFT]>=25)
//		{
//			follow_right_counter(3);
//		}
		BW_Buzz(1);
		BW_PID_Init();
		FollowCarpet_Left(COLOUR_BLACK,INVERSE);

		mov_deflect_right(FAST,CLOSE);
		mov_deflect_right(FAST,CLOSE);
		mov_deflect_right(FAST,CLOSE);

//TURN AROUND
		BW_Buzz(1);
		Nav_TurnAround(TURN_RIGHT);

//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//
////		while ( (Ping[PING_FRONT]>=30) || (INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED) )
//		while ( (Ping[PING_FRONT]>=30) )
//		{
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			if(Ping[PING_FRONT]<=18) mov_bwd(5,FAST_LEVEL_3);
//			Get_IR();
//		}
//
//		Get_IR();
////		while ( Ping[PING_FRONT]<=30 || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
//		while ( Ping[PING_FRONT]<=30 )
//		{
//			if(Ping[PING_FRONT]<=18) mov_bwd(5,FAST_LEVEL_3);
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			Get_IR();
//		}
//
//		if(Ping[PING_RIGHT]>15)
//		{
//			mov_deflect_right(FAST,CLOSE);
//			mov_deflect_right(FAST,CLOSE);
//			mov_deflect_right(FAST,CLOSE);
//		}



//		BW_Buzz(1);
//		BW_PID_Init();
//		FollowCarpet_Right(COLOUR_BLACK,INVERSE);

	//	if(Ping[PING_LEFT]>=6)
	//	{
	//		mov_deflect_left(FAST,CLOSE);
	//	}
	//	if(Ping[PING_LEFT]>=6)
	//	{
	//		mov_deflect_left(FAST,CLOSE);
	//	}

//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//
//		BW_Buzz(1);
//		while(Ping[PING_FRONT]>=20)
//		{
//			Evade_Wall();
////			mov_fwd_5cm(5,FAST_LEVEL_3);
//			mov_fwd_5cm(5, FAST_LEVEL_3);
//		}
//
//		BW_Buzz(1);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		while(Ping[PING_FRONT]<=25)
//		{
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//		}

		BW_Buzz(1);
		BW_PID_Init();
		FollowTracer_Left();

	}


	if(CAT_FLAG==CAT_DETECTED)
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

//		BW_Buzz(1);
//		BW_PID_Init();
//		FollowCarpet_Right(COLOUR_BLACK,INVERSE);
//
//		BW_Buzz(1);
//		BW_PID_Init();
//		FollowCarpet_Right(COLOUR_GRAY,INVERSE);
//
////		mov_deflect_left(FAST,CLOSE);
////		mov_deflect_left(FAST,CLOSE);
////		mov_deflect_left(FAST,CLOSE);
////		mov_deflect_left(FAST,CLOSE);
//		if(Ping[PING_LEFT]>=6)
//		{
//			mov_deflect_left(FAST,CLOSE);
//		}
//		if(Ping[PING_LEFT]>=6)
//		{
//			mov_deflect_left(FAST,CLOSE);
//		}
//		if(Ping[PING_LEFT]>=6)
//		{
//			mov_deflect_left(FAST,CLOSE);
//		}
//		if(Ping[PING_LEFT]>=6)
//		{
//			mov_deflect_left(FAST,CLOSE);
//		}
//
//		BW_Buzz(1);
//		BW_PID_Init();
//		follow_left_counter(13);
//
//		mov_deflect_right(FAST,CLOSE);
//		mov_deflect_right(FAST,CLOSE);
//		mov_deflect_right(FAST,CLOSE);
//		mov_deflect_right(FAST,CLOSE);

//		BW_Buzz(1);
//		BW_PID_Init();
//		FollowCarpet_Right(COLOUR_BLACK,INVERSE);

//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//
		mov_bwd_5cm(10,FAST_LEVEL_3);
		mov_rot_right(FAST,FAR);
		mov_rot_right(FAST,FAR);
		mov_rot_right(FAST,FAR);
		mov_rot_right(FAST,FAR);
		while(Ping[PING_RIGHT]>30)
		{
			mov_rot_right(FAST,FAR);
		}

		BW_Buzz(1);
		BW_PID_Init();
		FollowTracer_Right();

//		mov_deflect_left(FAST,CLOSE);
//		mov_deflect_left(FAST,CLOSE);
//		mov_deflect_left(FAST,CLOSE);
//		mov_deflect_left(FAST,CLOSE);
//		mov_deflect_left(FAST,CLOSE);
//
//		BW_Buzz(2);
//		BW_PID_Init();
//		FollowTracer_Left();
	}



}

/* func      : void Nav_1A_To_4B(void)
 * brief     : Navigate from Room 1A to Room 4B
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Thursday, March 28th 2016)
 * Revised BY: Ver.2 :  Ryan (Tuesday, April 5th 2016)
 * programmer's Note:
 */
void Nav_1A_To_4B(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1A TO R4B");lcd_putstr(lcd);
	delay_ms(100);

//	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//
//	BW_Buzz(1);
//	while(Ping[PING_RIGHT]>=30)
//	{
//		mov_fwd_5cm(5,FAST_LEVEL_3);
//		Evade_Wall();
//	}
	BW_Buzz(2);
	mov_rot_left(FAST,FAR);
	mov_rot_left(FAST,FAR);
	mov_rot_left(FAST,FAR);
	mov_rot_left(FAST,FAR);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
	ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;

	BW_Buzz(2);
	BW_Buzz(1);
	BW_PID_Init();
	while( ((Ping[PING_LEFT]>=30) || (Ping[PING_RIGHT]>=30)) && (CAT_FLAG==CAT_NOT_DETECTED) )
	{
		Cat_Avoider();
		mov_fwd_5cm(5, FAST);
		if(CAT_FLAG==CAT_DETECTED)break;
//		Get_IR();
//		if (
//				(INFRARED[IR_FRONT_LEFT]==IR_DETECTED)||
//				(INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED)||
//				(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED)
//			)
//		{
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//		}
//
//		Cat_Avoider();
//		if(CAT_FLAG==CAT_DETECTED)break;
////		mov_fwd_5cm(5,FAST_LEVEL_3);
//		mov_fwd_5cm(5, FAST_LEVEL_3);
//		if(CAT_FLAG==CAT_DETECTED)break;
//		Evade_Wall();
//		if(CAT_FLAG==CAT_DETECTED)break;
//
//
//		FollowCarpet_Left(COLOUR_GRAY,INVERSE);
	}



	if(CAT_FLAG==CAT_NOT_DETECTED)
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

		BW_Buzz(1);
		BW_PID_Init();
		FollowCarpet_Right(COLOUR_GRAY,INVERSE);

		BW_Buzz(1);
		BW_PID_Init();
		FollowTracer_Right();

	}

	if(CAT_FLAG==CAT_DETECTED)
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;


//		if(Ping[PING_RIGHT]>=15)
//		{
//			mov_deflect_right(FAST,CLOSE);
//			mov_deflect_right(FAST,CLOSE);
//		}
//
//		if(Ping[PING_RIGHT]>=15)
//		{
//			mov_deflect_right(FAST,CLOSE);
//			mov_deflect_right(FAST,CLOSE);
//		}

		mov_bwd_5cm(10,FAST_LEVEL_3);
		mov_rot_right(FAST,FAR);
		mov_rot_right(FAST,FAR);
		mov_rot_right(FAST,FAR);
		mov_rot_right(FAST,FAR);

		BW_Buzz(1);
		BW_PID_Init();
		follow_right_counter(13);

//		BW_Buzz(1);
//		BW_PID_Init();
//		FollowCarpet_Left(COLOUR_BLACK,INVERSE);
//
//		BW_Buzz(1);
//		BW_PID_Init();
//		FollowCarpet_Left(COLOUR_GRAY,INVERSE);
//
//		BW_Buzz(1);
//		BW_PID_Init();
//		FollowCarpet_Left(COLOUR_BLACK,INVERSE);

		BW_Buzz(1);
		BW_PID_Init();
		FollowTracer_Left();
	}




}

/* func      : void Nav_1A_To_4A(void)
 * brief     : Navigate from Room 1A to Room 4A
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 28th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_1A_To_4A(void)
{
	int counter=0;

//	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1A TO R4A");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

	Evade_Wall();
	Cat_Avoider();
	CAT_FLAG=CAT_NOT_DETECTED;

	if(Ping[PING_RIGHT]>16)
	{
		mov_rot_right(FAST,FAR);
		mov_fwd_5cm(10,FAST_LEVEL_2);

		mov_deflect_right(FAST,CLOSE);
		mov_deflect_right(FAST,CLOSE);
		mov_deflect_right(FAST,CLOSE);
	}

	BW_Buzz(1);
	while( (CAT_FLAG==CAT_NOT_DETECTED) && (counter<=14) )
	{
		Cat_Avoider();
		if(CAT_FLAG==CAT_DETECTED)break;
		Evade_Wall();
		if(CAT_FLAG==CAT_DETECTED)break;
		follow_right_counter(1);
		if(CAT_FLAG==CAT_DETECTED)break;

		counter++;
	}

	if(CAT_FLAG==CAT_NOT_DETECTED)
	{
		BW_Buzz(2);
		BW_PID_Init();
		FollowTracer_Left();
	}

	if(CAT_FLAG==CAT_DETECTED)
	{
		CAT_FLAG=CAT_NOT_DETECTED;
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"ALTERNATE");lcd_putstr(lcd);
		lcd_gotoxy(8,1);sprintf(lcd,"ROUTE");lcd_putstr(lcd);
		delay_ms(100);

		BW_Buzz(1);
		Evade_Wall();

		mov_bwd_5cm(10,FAST_LEVEL_3);
		mov_rot_left(FAST,FAR);
		mov_rot_left(FAST,FAR);
		mov_rot_left(FAST,FAR);
//		mov_rot_left(FAST,FAR);
		mov_fwd_5cm(10,FAST);
		mov_rot_left(FAST,FAR);
//		mov_rot_left(FAST,CLOSE);
//		while(Ping[PING_FRONT]<30)
//		{
//			mov_rot_left(FAST,FAR);
//		}
//		mov_rot_left(FAST,FAR);
//		mov_rot_left(FAST,FAR);
//		mov_rot_left(FAST_LEVEL_2,FAR);
		while(Ping[PING_FRONT]<17)
		{
			mov_rot_left(FAST,CLOSE);
//			if(Ping[PING_FRONT]>=17)break;
		}
//		mov_rot_left(FAST,FAR);
		mov_fwd_5cm(10,FAST_LEVEL_3);

		//ANTICIPATION FOR KRPAI REGIONAL IV CAT LOCATION
		BW_Buzz(1);
		BW_PID_Init();
		FollowCarpet_Right(COLOUR_GRAY,INVERSE);

		BW_Buzz(1);
		BW_PID_Init();
		FollowCarpet_Right(COLOUR_BLACK,INVERSE);

		mov_fwd_5cm(10,FAST_LEVEL_2);
		if((Ping[PING_RIGHT]>30) && (Ping[PING_RIGHT]<80))
		{
			mov_rot_right(FAST,FAR);
			mov_rot_right(FAST,FAR);
			mov_rot_right(FAST,FAR);

			BW_Buzz(1);
			BW_PID_Init();
			FollowTracer_Right();
		}
		else if((Ping[PING_RIGHT]<30) || (Ping[PING_RIGHT]>80))
		{
			BW_Buzz(1);
			BW_PID_Init();
			FollowCarpet_Right(COLOUR_GRAY,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			FollowCarpet_Right(COLOUR_BLACK,INVERSE);

			mov_fwd_5cm(10,FAST_LEVEL_2);

			mov_rot_right(FAST,FAR);
			mov_rot_right(FAST,FAR);
			mov_rot_right(FAST,FAR);

			BW_Buzz(1);
			BW_PID_Init();
			FollowTracer_Right();
		}

//		BW_Buzz(1);
//		BW_PID_Init();
//		FollowTracer_Right();

		/*
		if(CAT_FLAG==CAT_DETECTED)
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"ALTERNATE");lcd_putstr(lcd);
			lcd_gotoxy(8,1);sprintf(lcd,"ROUTE 2");lcd_putstr(lcd);
			delay_ms(100);

			BW_Buzz(1);
			BW_PID_Init();
			FollowTracer_Left();
		}
		*/
	}
}


/* func      : void Nav_1C_To_HallwaySC(void)
 * brief     : Navigate from Room 1C to HallwaySC
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Sunday, April 10th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_1C_To_HallwaySC(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1C TO SC");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	mov_rot_right(FAST_LEVEL_3,CLOSE);
	mov_rot_right(FAST_LEVEL_3,CLOSE);
	mov_rot_right(FAST_LEVEL_3,CLOSE);
	mov_rot_right(FAST_LEVEL_3,CLOSE);

	BW_Buzz(2);
	while(Ping[PING_FRONT]<=25)
	{
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
	}

	BW_Buzz(2);
	while(Ping[PING_LEFT]>=30)
	{
//		mov_fwd_5cm(5,FAST_LEVEL_3);
		mov_fwd_5cm(5,FAST_LEVEL_3);
	}

	BW_Buzz(2);
	BW_PID_Init();
	while( (Ping[PING_ASKEW_LEFT]<=100) || (Ping[PING_ASKEW_RIGHT]<=100))
//	while( (SHARP[SHARP_LEFT]<=100) || (SHARP[SHARP_RIGHT]<=100))
//	while (SHARP[SHARP_LEFT]<=100)
	{
		follow_left_counter(1);
	}

	//CROSSING CROSSROAD
	BW_Buzz(2);
	while(Ping[PING_LEFT]>=30)
	{
		Evade_Wall();
//		mov_fwd_5cm(5,FAST_LEVEL_3);
		mov_fwd_5cm(5,FAST_LEVEL_3);
	}

	BW_Buzz(2);
	BW_PID_Init();
	FollowHome_Left();
}



/* func      : void Nav_1C_To_2(void)
 * brief     : Navigate from Room 1C to Room 2
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 29th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_1C_To_2(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1C TO R2");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	BW_Buzz(2);
	if(Ping[PING_LEFT]>=17)
	{
		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);
//		mov_deflect_left(FAST,CLOSE);
//		mov_deflect_left(FAST,CLOSE);
	}

	BW_Buzz(2);
	BW_PID_Init();
	FollowTracer_Left();
}

void Nav_1B_To_2(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1B TO R2");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	BW_Buzz(2);
	mov_rot_left(FAST,FAR);
	mov_rot_left(FAST,FAR);
	mov_rot_left(FAST,FAR);
	mov_rot_left(FAST,CLOSE);

//	if(Ping[PING_RIGHT]>16)
//	{
//		mov_rot_left(FAST_LEVEL_2,FAR);
//	}
	mov_fwd_5cm(10,FAST_LEVEL_2);
	if(Ping[PING_ASKEW_LEFT]>25)
	{
		mov_rot_left(FAST,FAR);
		mov_rot_left(FAST,CLOSE);
	}
	while(Ping[PING_FRONT]<=30)
	{
		mov_rot_left(FAST,FAR);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
	}
//	mov_rot_left(FAST_LEVEL_2,FAR);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);

//	while(Ping[PING_LEFT]>=20)
//	{
//		Evade_Wall();
//		Bumper_Action();
//		mov_fwd_5cm(5,FAST_LEVEL_3);
//	}
	mov_fwd_5cm(10,FAST_LEVEL_2);

	if(Ping[PING_LEFT]>=20)
	{
		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);
	}

	mov_fwd_5cm(10,FAST_LEVEL_2);

	if(Ping[PING_LEFT]>=20)
	{
		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);
	}

//	mov_fwd_5cm(10,FAST_LEVEL_3);
//	mov_deflect_left(FAST,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);


	BW_Buzz(1);
/*	while(Ping[PING_FRONT]>=20)
	{
		Evade_Wall();
		mov_fwd_5cm(5,FAST_LEVEL_3);
	}

	BW_Buzz(1);
	mov_rot_right(FAST_LEVEL_3,CLOSE);
	mov_rot_right(FAST_LEVEL_3,CLOSE);
	while(Ping[PING_FRONT]<=20)
	{
		mov_rot_right(FAST_LEVEL_2,FAR);
//		mov_rot_right(FAST_LEVEL_2,FAR);
	}

	if(Ping[PING_LEFT]>=15)
	{
		mov_deflect_left(FAST,CLOSE);
	}
	if(Ping[PING_ASKEW_LEFT]>=15)
	{
		mov_deflect_left(FAST,CLOSE);
	}
	if(Ping[PING_ASKEW_LEFT]>=15)
	{
		mov_deflect_left(FAST,CLOSE);
	}
*/

	while(Ping[PING_FRONT]>=17)
		{
			Evade_Wall();
			Bumper_Action();
			mov_fwd_5cm(5,FAST_LEVEL_3);
		}

		BW_Buzz(1);
		mov_rot_right(FAST,FAR);
		mov_rot_right(FAST,FAR);
		while(Ping[PING_FRONT]<=20)
		{
			mov_rot_right(FAST,FAR);
	//		mov_rot_right(FAST_LEVEL_2,FAR);
		}


	BW_Buzz(1);
	BW_PID_Init();
	FollowTracer_Left();
}

/* func      : void Nav_1C_To_3(void)
 * brief     : Navigate from Room 1C to Room 3
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 29th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_1C_To_3(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1C TO R3");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);
	while(Ping[PING_LEFT]<30)
	{
		mov_rot_right(FAST,FAR);
	}
//	mov_rot_right(FAST_LEVEL_2,FAR);
	mov_rot_right(FAST,FAR);
	mov_rot_right(FAST,CLOSE);


	while(Ping[PING_FRONT]<=30)
	{
		mov_rot_right(FAST,FAR);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
	}

	BW_Buzz(1);
	BW_PID_Init();
	follow_left_counter(1);

	BW_Buzz(2);
	while(Ping[PING_LEFT]>=30)
	{
//		mov_fwd_5cm(5,FAST_LEVEL_3);
		mov_fwd_5cm(5,FAST_LEVEL_3);
		if (Ping[PING_FRONT]<=30)
		{
			mov_rot_right(FAST,FAR);
		}
	}
	mov_fwd_5cm(10,FAST_LEVEL_3);
	mov_deflect_left(FAST,CLOSE);
	mov_deflect_left(FAST,CLOSE);

/*
	BW_Buzz(2);
	BW_PID_Init();
	FollowCarpet_Left(COLOUR_GRAY,INVERSE);

	while(Ping[PING_LEFT]<=30)
	{
//		mov_fwd_5cm(5,FAST_LEVEL_3);
		mov_fwd_5cm(5,FAST_LEVEL_3);
	}
	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);

	BW_Buzz(2);
	BW_PID_Init();
	FollowCarpet_Left(COLOUR_BLACK,INVERSE);

	mov_rot_left(FAST_LEVEL_3,CLOSE);

//OLD ALGORITHM
//	mov_deflect_right(FAST,CLOSE);
//	mov_deflect_right(FAST,CLOSE);
//
//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//
//	BW_Buzz(2);
//	BW_PID_Init();
//	FollowTracer_Right();

//ALGORITHM VER.2
//	mov_deflect_left(FAST,CLOSE);
//	mov_deflect_left(FAST,CLOSE);
//	mov_deflect_left(FAST,CLOSE);
//
//	BW_Buzz(2);
//	BW_PID_Init();
//	FollowTracer_Left();

//ALGORITHM VER. 3
	BW_Buzz(1);
	while(Ping[PING_FRONT]>=17)
	{
		Evade_Wall();
//		mov_fwd_5cm(5,FAST_LEVEL_3);
		mov_fwd_5cm(5,FAST_LEVEL_3);
	}

	BW_Buzz(1);
	mov_rot_right(FAST_LEVEL_3,CLOSE);
	mov_rot_right(FAST_LEVEL_3,CLOSE);
	while(Ping[PING_FRONT]<=25)
	{
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
	}
*/

	BW_Buzz(1);
	BW_PID_Init();
	FollowTracer_Left();



}

/* func      : void Nav_1C_To_4A(void)
 * brief     : Navigate from Room 1C to Room 4A
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 29th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_1C_To_4A(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1C TO R4A");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);

	while(Ping[PING_LEFT]<30)
	{
		mov_rot_right(FAST,FAR);
	}
	mov_rot_right(FAST,FAR);
//	mov_rot_right(FAST_LEVEL_2,FAR);
	mov_rot_right(FAST,CLOSE);

	BW_Buzz(2);
	while(Ping[PING_FRONT]<=30)
	{
		mov_rot_right(FAST_LEVEL_2,FAR);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
	}
//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);

//	BW_Buzz(1);
//	while(Ping[PING_LEFT]>=30)
//	{
////		mov_fwd_5cm(5,FAST_LEVEL_3);
//		mov_fwd_5cm(5,FAST_LEVEL_3);
//	}

	BW_Buzz(1);
	BW_PID_Init();
	follow_left_counter(1);

	BW_Buzz(2);
	while(Ping[PING_LEFT]>=30)
	{
//		mov_fwd_5cm(5,FAST_LEVEL_3);
		mov_fwd_5cm(5,FAST_LEVEL_3);
		if (Ping[PING_FRONT]<=30)
		{
			mov_rot_right(FAST,FAR);
		}
	}
	mov_fwd_5cm(10,FAST_LEVEL_3);
	mov_deflect_left(FAST,CLOSE);
	mov_deflect_left(FAST,CLOSE);

	//	while(Ping[PING_LEFT]<=50)
	//	{
	//		mov_fwd_5cm(5,FAST_LEVEL_3);
	//	}


	BW_Buzz(1);
	BW_PID_Init();
	FollowCarpet_Left(COLOUR_GRAY,INVERSE);



//OLD ALGORITHM
//	BW_Buzz(2);
//	while( (Ping[PING_RIGHT]>=30) )
//	{
//		Get_IR();
//		if(
//			(INFRARED[IR_FRONT_LEFT]==IR_DETECTED) ||
//			(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ||
//			(Ping[PING_FRONT]<=30)
//		  )
//		{
//			if( (Ping[PING_LEFT]<=80) )
//			{
//				BW_Buzz(1);
//				lcd_display_clear();
//				lcd_gotoxy(0,0);sprintf(lcd,"BUMP LEFT");lcd_putstr(lcd);
//				delay_ms(100);
//
//				mov_rot_right(FAST_LEVEL_3,CLOSE);
//				mov_rot_right(FAST_LEVEL_3,CLOSE);
//				mov_deflect_right(FAST,CLOSE);
//				mov_deflect_right(FAST,CLOSE);
//				mov_fwd_5cm(15,FAST_LEVEL_3);
//			}
//			else
//			{
//				BW_Buzz(1);
//				lcd_display_clear();
//				lcd_gotoxy(0,0);sprintf(lcd,"BUMP LEFT");lcd_putstr(lcd);
//				delay_ms(100);
//
//				mov_rot_left(FAST_LEVEL_3,CLOSE);
//				mov_rot_left(FAST_LEVEL_3,CLOSE);
//				mov_deflect_left(FAST,CLOSE);
//				mov_deflect_left(FAST,CLOSE);
//
//				mov_fwd_5cm(15,FAST_LEVEL_3);
//			}
//
//		}
//
//		Evade_Wall();
//		mov_fwd_5cm(5,FAST_LEVEL_3);
//	}

	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);

	BW_Buzz(1);
	BW_PID_Init();
	while( (Ping[PING_RIGHT]>=25) || (Ping[PING_ASKEW_RIGHT]>=25) )
//	while( (Ping[PING_RIGHT]>=25) || (SHARP[SHARP_RIGHT]>=25) )
//	while (Ping[PING_RIGHT]>=25)
	{
		follow_left_counter(3);
	}

	BW_Buzz(1);
	Nav_TurnAround(TURN_RIGHT);

	BW_Buzz(1);
	BW_PID_Init();
	while( (Ping[PING_RIGHT]>=25) || (Ping[PING_ASKEW_RIGHT]>=25) )
//	while( (Ping[PING_RIGHT]>=25) || (SHARP[SHARP_RIGHT]>=25) )
//	while (Ping[PING_RIGHT]>=25)
	{
		follow_left_counter(3);
	}

	BW_Buzz(1);
	BW_PID_Init();
	follow_left_counter(8);

	BW_Buzz(1);
	BW_PID_Init();
	follow_right_counter(8);

	ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;
	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

//	if(CAT_FLAG==CAT_NOT_DETECTED)
//	{
//		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
//
//		BW_Buzz(2);
//		BW_PID_Init();
//		FollowTracer_Right();
//	}

	BW_Buzz(1);
	BW_PID_Init();
	FollowCarpet_Right(COLOUR_BLACK,INVERSE);

	if(CAT_FLAG==CAT_NOT_DETECTED)
	{
//		mov_fwd_5cm(10,FAST_LEVEL_3);
		mov_fwd_5cm(10,FAST_LEVEL_3);

		mov_rot_right(FAST,FAR);
		mov_rot_right(FAST,FAR);
		mov_rot_right(FAST,FAR);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);

		BW_Buzz(1);
		BW_PID_Init();
		FollowTracer_Right();

	}


	if(CAT_FLAG==CAT_DETECTED)
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

		mov_rot_right(FAST,FAR);
		mov_rot_right(FAST,FAR);
		BW_Buzz(2);
		BW_PID_Init();
		follow_right_counter(15);

		Evade_Wall();
		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);

		BW_Buzz(2);
		BW_PID_Init();
		FollowTracer_Left();
	}


}

/* func      : void Nav_1C_To_4B(void)
 * brief     : Navigate from Room 1C to Room 4B
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 29th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_1C_To_4B(void)
{
	int counter;

	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1C TO R4B");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);

	while(Ping[PING_LEFT]<30)
	{
		mov_rot_right(FAST,FAR);
	}
	mov_rot_right(FAST,FAR);
	mov_rot_right(FAST,CLOSE);
	BW_Buzz(2);
	while(Ping[PING_FRONT]<=30)
	{
		mov_rot_right(FAST,FAR);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
	}
	BW_Buzz(1);
	BW_PID_Init();
	follow_left_counter(1);

	BW_Buzz(2);
	while(Ping[PING_LEFT]>=30)
	{
//		mov_fwd_5cm(5,FAST_LEVEL_3);
		mov_fwd_5cm(5,FAST_LEVEL_3);
		if (Ping[PING_FRONT]<=30)
		{
			mov_rot_right(FAST,FAR);
		}
	}
//	for(counter=1;counter<=5;counter++)
//	{
//		Evade_Wall();
////		Get_IR();
////		if ( (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) ||  (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) )
////		{
////			mov_rot_right(FAST_LEVEL_3,CLOSE);
////			mov_rot_right(FAST_LEVEL_3,CLOSE);
////		}
////		mov_fwd_5cm(5,FAST_LEVEL_3);
//		mov_fwd_5cm(5,FAST_LEVEL_3);
//	}

//	BW_Buzz(2);
//	while(Ping[PING_RIGHT]>30)
//	{
//		mov_fwd_5cm(5,FAST_LEVEL_3);
//	}
//	for(counter=1;counter<=5;counter++)
//	{
//		Evade_Wall();
//		mov_fwd_5cm(5,FAST_LEVEL_3);
//	}


	BW_Buzz(2);
	BW_PID_Init();
	FollowCarpet_Left(COLOUR_GRAY,INVERSE);

	mov_rot_right(FAST,FAR);
	mov_rot_right(FAST,FAR);
	mov_deflect_right(FAST,CLOSE);
	mov_deflect_right(FAST,CLOSE);
	mov_deflect_right(FAST,CLOSE);
	mov_deflect_right(FAST,CLOSE);

	BW_Buzz(2);
	BW_PID_Init();
	FollowCarpet_Right(COLOUR_BLACK,INVERSE);
//	follow_right_counter(8);

	BW_Buzz(2);
	mov_deflect_left(FAST,CLOSE);
	mov_deflect_left(FAST,CLOSE);
	mov_deflect_left(FAST,CLOSE);
	mov_deflect_left(FAST,CLOSE);
	mov_deflect_left(FAST,CLOSE);

	BW_Buzz(2);
	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);

	BW_Buzz(2);
	BW_PID_Init();
	FollowTracer_Left();

//	if(CAT_FLAG==CAT_DETECTED)
//	{
//		while(1)
//		{
//			mov_static();
//			BW_Buzz(2);
//		}
//	}

//	while(1)
//	{
//		BW_Buzz(2);
//		mov_static();
//	}
}

/* func      : void Nav_4A_To_HallwaySC(void)
 * brief     : Navigate from Room 4A to Hallway SC
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Monday, April 10th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_4A_To_HallwaySC(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R4A TO SC");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);


	while(Ping[PING_FRONT]<=25)
	{
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
	}

	if(CAT_FLAG==CAT_NOT_DETECTED)
	{
		BW_Buzz(2);
		BW_PID_Init();
		FollowHome_Right();
	}

	if(CAT_FLAG==CAT_DETECTED)
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
		BW_Buzz(2);
		BW_PID_Init();
		follow_left_counter(15);

		BW_Buzz(2);
		BW_PID_Init();
		FollowCarpet_Left(COLOUR_GRAY,INVERSE);

		BW_Buzz(2);
		BW_PID_Init();
		follow_left_counter(15);

		BW_Buzz(2);
		mov_deflect_right(FAST,CLOSE);
		mov_deflect_right(FAST,CLOSE);
		mov_deflect_right(FAST,CLOSE);

		BW_Buzz(2);
		BW_PID_Init();
		FollowCarpet_Right(COLOUR_BLACK,INVERSE);

		BW_Buzz(2);
		BW_PID_Init();
		FollowCarpet_Right(COLOUR_GRAY,INVERSE);

		BW_Buzz(2);
		BW_PID_Init();
		FollowCarpet_Right(COLOUR_BLACK,INVERSE);

		BW_Buzz(2);
		BW_PID_Init();
		FollowCarpet_Right(COLOUR_GRAY,INVERSE);

		BW_Buzz(2);
		BW_PID_Init();
		follow_right_counter(25);

		BW_Buzz(2);
		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);

		BW_Buzz(2);
		BW_PID_Init();
		FollowHome_Left();


	}

}




/* func      : void Nav_4A_To_3(void)
 * brief     : Navigate from Room 4A to Room 3
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 29th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_4A_To_3(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R4A TO R3");lcd_putstr(lcd);
	delay_ms(100);

	Evade_Wall();

	mov_fwd_5cm(10,FAST_LEVEL_3);
//	while((Ping[PING_LEFT]<25) || (Ping[PING_ASKEW_LEFT]<25))
//	{
//		mov_rot_left(FAST_LEVEL_2,FAR);
//		if(Ping[PING_FRONT]<13)
//		{
//			mov_bwd_5cm(10,FAST_LEVEL_3);
//		}
//	}
	/*
	if((Ping[PING_RIGHT]>20) && (Ping[PING_ASKEW_RIGHT]>20))
	{
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_bwd_3cm(9,FAST_LEVEL_3);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
	}
	 */
	mov_rot_left(FAST,FAR);
	mov_rot_left(FAST,FAR);
	while(Ping[PING_FRONT]<=25)
	{
		mov_rot_left(FAST,FAR);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
	}

	ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;
	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

	Evade_Wall();

//	BW_Buzz(2);
//	BW_PID_Init();
//	FollowCarpet_Right(COLOUR_BLACK,INVERSE);

	BW_Buzz(2);
	BW_PID_Init();
	FollowCarpet_Right(COLOUR_GRAY,INVERSE);

	Cat_Avoider();

	if(CAT_FLAG==CAT_NOT_DETECTED)
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

		Evade_Wall();

		BW_Buzz(1);
		mov_fwd_5cm(10,FAST_LEVEL_3);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);

//		while(Ping[PING_FRONT]<=25)
//		{
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//		}

		//NEW ALGORITHM
		BW_Buzz(1);
		BW_PID_Init();
		FollowCarpet_Right(COLOUR_BLACK,INVERSE);

		BW_Buzz(1);
		BW_PID_Init();
		follow_right_counter(1);

		BW_Buzz(1);
		BW_PID_Init();
		FollowCarpet_Right(COLOUR_BLACK,INVERSE);

		mov_rot_left(FAST,CLOSE);
		mov_rot_left(FAST,CLOSE);
		mov_rot_left(FAST,CLOSE);
		mov_rot_left(FAST,CLOSE);

		BW_Buzz(1);
		while(Ping[PING_FRONT]>=16)
		{
			Evade_Wall();
			mov_fwd_5cm(5,FAST_LEVEL_3);
		}

		BW_Buzz(1);
		mov_rot_right(FAST,FAR);
		mov_rot_right(FAST,FAR);

		while(Ping[PING_FRONT]<=20)
		{
			mov_rot_right(FAST,FAR);
			mov_rot_right(FAST,FAR);
		}

		mov_rot_right(FAST,CLOSE);
		mov_rot_right(FAST,CLOSE);

		BW_Buzz(1);
		BW_PID_Init();
		FollowTracer_Left();

//		BW_Buzz(1);
//		BW_PID_Init();
//		FollowTracer_Right();

		ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_INACTIVE;
	}

	if (CAT_FLAG==CAT_DETECTED)
	{
		mov_bwd_5cm(10,FAST);
		while(Ping[PING_RIGHT]<30)
		{
			mov_rot_right(FAST,FAR);
//			if(Ping[PING_FRONT]<13)
//			{
//				mov_bwd_5cm(10,FAST);
//			}
		}
		mov_rot_right(FAST,FAR);
		mov_rot_right(FAST,FAR);
		mov_rot_right(FAST,FAR);
		mov_rot_right(FAST,FAR);
		while(Ping[PING_FRONT]<25)
		{
			mov_rot_right(FAST,FAR);
		}

		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
//		ROOM4B_FLAG=ROOM4BFLAG_ACTIVE;
//		if( (ROOM[ROOM_COUNTER-1]==ROOM_1A) || (ROOM[ROOM_COUNTER-1]==ROOM_1B) || (ROOM[ROOM_COUNTER-1]==ROOM_1B) )
		if( (ROOM[1]==ROOM_1A) || (ROOM[1]==ROOM_2B) || (ROOM[1]==ROOM_2A) )
		{
			BW_Buzz(1);
			BW_PID_Init();
			FollowCarpet_Left(COLOUR_GRAY,INVERSE);

			BW_Buzz(1);
			while(Ping[PING_FRONT]>=19)
			{
				Evade_Wall();
				mov_fwd_5cm(5,FAST_LEVEL_3);
			}

			BW_Buzz(1);
			mov_rot_right(FAST_LEVEL_2,FAR);
			mov_rot_right(FAST_LEVEL_2,FAR);
			mov_rot_right(FAST_LEVEL_2,FAR);
			mov_rot_right(FAST_LEVEL_2,FAR);
			while(Ping[PING_FRONT]<=25)
			{
				mov_rot_right(FAST_LEVEL_2,FAR);
//				mov_rot_right(FAST_LEVEL_3,CLOSE);
			}
			mov_rot_right(FAST_LEVEL_2,FAR);
			mov_rot_right(FAST_LEVEL_2,FAR);

			BW_Buzz(1);
			while(Ping[PING_RIGHT]>=40)
			{
				Evade_Wall();
				mov_fwd_5cm(5,FAST_LEVEL_3);
			}

			BW_Buzz(1);
			BW_PID_Init();
			FollowCarpet_Right(COLOUR_BLACK,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			FollowCarpet_Right(COLOUR_GRAY,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			FollowCarpet_Right(COLOUR_BLACK,INVERSE);

			mov_deflect_left(FAST,CLOSE);
			mov_deflect_left(FAST,CLOSE);
			mov_deflect_left(FAST,CLOSE);

			BW_Buzz(1);
			BW_PID_Init();
			FollowCarpet_Left(COLOUR_GRAY,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			FollowCarpet_Left(COLOUR_BLACK,INVERSE);

			mov_deflect_right(FAST,CLOSE);
			mov_deflect_right(FAST,CLOSE);
			mov_deflect_right(FAST,CLOSE);

			Nav_TurnAround(TURN_RIGHT);


//			BW_Buzz(1);
//			while( (Ping[PING_LEFT]<=40))
//			{
//				Evade_Wall();
//				mov_fwd_5cm(5,FAST_LEVEL_3);
//			}
//
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//
//			while((Ping[PING_RIGHT]>25) || (Ping[PING_LEFT]>25) || (Ping[PING_ASKEW_LEFT]>25) || (Ping[PING_ASKEW_RIGHT]>25))
//			{
//				mov_fwd_5cm(5,FAST_LEVEL_3);
//				if((Ping[PING_RIGHT]<25) || (Ping[PING_LEFT]<25) || (Ping[PING_ASKEW_LEFT]<25) || (Ping[PING_ASKEW_RIGHT]<25))break;
//			}
/*
			BW_Buzz(1);
			BW_PID_Init();
			while( (Ping[PING_LEFT]>=25) || (Ping[PING_ASKEW_LEFT]>=25) )
			{
				follow_right_counter(3);
			}

			//TURN AROUND
			BW_Buzz(1);
			Nav_TurnAround(TURN_LEFT);

			BW_Buzz(1);
			BW_PID_Init();
			FollowCarpet_Right(COLOUR_BLACK,INVERSE);

			mov_rot_left(FAST_LEVEL_3,CLOSE);
			mov_rot_left(FAST_LEVEL_3,CLOSE);

			BW_Buzz(1);
			while(Ping[PING_FRONT]>=20)
			{
				Evade_Wall();
				mov_fwd_5cm(5,FAST_LEVEL_3);
			}

			BW_Buzz(1);
			mov_rot_right(FAST_LEVEL_3,CLOSE);
			mov_rot_right(FAST_LEVEL_3,CLOSE);
			while(Ping[PING_FRONT]<=25)
			{
				mov_rot_right(FAST_LEVEL_3,CLOSE);
				mov_rot_right(FAST_LEVEL_3,CLOSE);
			}
*/

			BW_Buzz(1);
			BW_PID_Init();
			FollowTracer_Left();
		}
		else
		{
			BW_Buzz(2);
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"ALTERNATE");lcd_putstr(lcd);
			lcd_gotoxy(8,2);sprintf(lcd,"ROUTE");lcd_putstr(lcd);
			lcd_gotoxy(2,3);sprintf(lcd,"R4A TO R1A");lcd_putstr(lcd);
			delay_ms(100);

			ROOM4A_FLAG=ROOM4AFLAG_ACTIVE;
			ROOM1A_SP_EXIT_FLAG=ROOM1A_SP_EXIT_FLAG_ACTIVE;

			//ACTIVATING SPECIAL ROUTE
			R2TO4A_SP_ROUTE=R2TO4A_SP_ACTIVE;

			if(Ping[PING_LEFT]>16)
			{
				mov_deflect_left(FAST,CLOSE);
			}
			if(Ping[PING_LEFT]>16)
			{
				mov_deflect_left(FAST,CLOSE);
			}
			if(Ping[PING_LEFT]>16)
			{
				mov_deflect_left(FAST,CLOSE);
			}

			BW_Buzz(1);
			BW_PID_Init();
			FollowCarpet_Left(COLOUR_GRAY,INVERSE);

			BW_Buzz(1);
			while(Ping[PING_FRONT]>=17)
			{
				Evade_Wall();
				mov_fwd_5cm(5,FAST_LEVEL_3);
			}

			BW_Buzz(1);
			mov_rot_right(FAST_LEVEL_3,CLOSE);
			mov_rot_right(FAST_LEVEL_3,CLOSE);
			mov_rot_right(FAST_LEVEL_3,CLOSE);
			while(Ping[PING_FRONT]<=25)
			{
				mov_rot_right(FAST_LEVEL_3,CLOSE);
				mov_rot_right(FAST_LEVEL_3,CLOSE);
			}

			BW_Buzz(1);
			BW_PID_Init();
			FollowTracer_Left();
		}
	}
}

/* func      : void Nav_4A_To_1A(void)
 * brief     : Navigate from Room 4A to Room 1A
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 29th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_4A_To_1A(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R4A TO R1A");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	while(Ping[PING_FRONT]<=30)
//	{
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//	}

	BW_Buzz(1);

//	if(Ping[PING_LEFT]>=12)
//	{
//		mov_deflect_left(FAST,CLOSE);
//	}

	if(Ping[PING_LEFT]>=12)
	{
		mov_deflect_left(FAST,CLOSE);
	}

	if(Ping[PING_LEFT]>=12)
	{
		mov_deflect_left(FAST,CLOSE);
	}
	while(Ping[PING_FRONT]>=18)
	{
		Evade_Wall();
//		mov_fwd_5cm(5,FAST_LEVEL_3);
		mov_fwd_5cm(5,FAST_LEVEL_3);
	}

	mov_rot_right(FAST_LEVEL_2,FAR);
	mov_rot_right(FAST_LEVEL_2,FAR);
	while(Ping[PING_FRONT]<=25)
	{
		mov_rot_right(FAST_LEVEL_2,FAR);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
	}

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

	BW_Buzz(2);
	BW_PID_Init();
	FollowTracer_Left();

	//CAT DETECTED
	if (CAT_FLAG==CAT_DETECTED)
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

		mov_bwd_5cm(15,FAST_LEVEL_3);
//		mov_rot_left(FAST_LEVEL_2,FAR);
//		mov_rot_left(FAST_LEVEL_2,FAR);
//		mov_rot_left(FAST_LEVEL_2,FAR);
//		mov_rot_left(FAST_LEVEL_2,FAR);
		while(Ping[PING_LEFT]<25)
		{
			mov_rot_left(FAST,FAR);
		}

		mov_rot_left(FAST,FAR);
		mov_rot_left(FAST,FAR);
		mov_rot_left(FAST,FAR);
		mov_rot_left(FAST,FAR);

		while(Ping[PING_FRONT]<25)
		{
			mov_rot_left(FAST,FAR);
		}

		BW_Buzz(2);
		BW_PID_Init();
		FollowCarpet_Right(COLOUR_BLACK,INVERSE);

		BW_Buzz(2);
		BW_PID_Init();
		FollowCarpet_Right(COLOUR_GRAY,INVERSE);


		BW_Buzz(2);
		mov_fwd_5cm(15,FAST_LEVEL_3);
//		BW_PID_Init();
//		follow_right_counter(25);

		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);

		BW_Buzz(2);
		BW_PID_Init();
		FollowCarpet_Left(COLOUR_BLACK,INVERSE);
		follow_left_counter(5);
		FollowCarpet_Left(COLOUR_BLACK,INVERSE);

		BW_Buzz(2);
		BW_PID_Init();
		FollowCarpet_Left(COLOUR_GRAY,INVERSE);

		mov_deflect_right(FAST,CLOSE);
		mov_deflect_right(FAST,CLOSE);
		mov_deflect_right(FAST,CLOSE);

		BW_Buzz(2);
		BW_PID_Init();
		FollowTracer_Right();

	}

}

/* func      : void Nav_4A_To_2(void)
 * brief     : Navigate from Room 4A to Room 2
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 29th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_4A_To_2(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R4A TO R2");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
	while(Ping[PING_LEFT]<30)
	{
		mov_rot_left(FAST_LEVEL_2,FAR);
	}
	mov_rot_left(FAST_LEVEL_2,FAR);
	mov_rot_left(FAST_LEVEL_2,FAR);
	mov_rot_left(FAST_LEVEL_2,FAR);

	while(Ping[PING_FRONT]<=25)
	{
		mov_rot_left(FAST_LEVEL_2,FAR);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
	}

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
	ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;

	BW_Buzz(1);
	BW_PID_Init();
	FollowCarpet_Right(COLOUR_GRAY,INVERSE);

	if(CAT_FLAG==CAT_NOT_DETECTED)
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

		FollowCarpet_Right(COLOUR_BLACK,INVERSE);
		/*
		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);

//OLD ALGORITHM
//		BW_Buzz(1);
//		BW_PID_Init();
//		while( (Ping[PING_ASKEW_RIGHT]<=80) || (Ping[PING_ASKEW_RIGHT]>=110))
//		{
//
//			follow_left_counter(1);
//			Evade_Wall();
//		}
//
//		while( (Ping[PING_RIGHT]<=30) )
//		{
//			mov_fwd_5cm(15,FAST_LEVEL_3);
//		}
//
//		BW_Buzz(1);
//		while( (Ping[PING_RIGHT]>=30) )
//		{
//			Get_IR();
//			if(
//				(INFRARED[IR_FRONT_LEFT]==IR_DETECTED) ||
//				(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ||
//				(Ping[PING_FRONT]<=30)
//			  )
//			{
//				mov_rot_left(FAST_LEVEL_3,CLOSE);
//				mov_rot_left(FAST_LEVEL_3,CLOSE);
//			}
//
//			Evade_Wall();
//			mov_fwd_5cm(5,FAST_LEVEL_3);
//		}
//
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		while(Ping[PING_FRONT]<=40)
//		{
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//		}

		Evade_Wall();
		BW_Buzz(1);
		while(Ping[PING_FRONT]>=20)
		{
			Evade_Wall();
//			mov_fwd_5cm(5,FAST_LEVEL_3);
			mov_fwd_5cm(5,FAST_LEVEL_3);
		}

		BW_Buzz(1);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);

		while(Ping[PING_FRONT]<=25)
		{
			mov_rot_left(FAST_LEVEL_3,CLOSE);
			mov_rot_left(FAST_LEVEL_3,CLOSE);
		}

		BW_Buzz(1);
		BW_PID_Init();
		follow_right_counter(4);

		BW_Buzz(1);
		while( (Ping[PING_LEFT]<=30) || (Ping[PING_RIGHT]<=30) )
		{
			Get_IR();
			if(
				(INFRARED[IR_FRONT_LEFT]==IR_DETECTED) ||
				(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ||
				(Ping[PING_FRONT]<=25)
			  )
			{
				mov_rot_right(FAST_LEVEL_3,CLOSE);
				mov_rot_right(FAST_LEVEL_3,CLOSE);
			}

			Evade_Wall();
//			mov_fwd_5cm(5,FAST_LEVEL_3);
			mov_fwd_5cm(5,FAST_LEVEL_3);
		}

		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);

		BW_Buzz(1);
		BW_PID_Init();
		while( (Ping[PING_LEFT]>=25) || (Ping[PING_ASKEW_LEFT]>=25) )
//		while( (Ping[PING_LEFT]>=25) || (SHARP[SHARP_LEFT]>=25) )
//		while (Ping[PING_LEFT]>=25)
		{
			follow_right_counter(3);
		}
		*/

		BW_Buzz(1);
		Nav_TurnAround(TURN_LEFT);

		BW_Buzz(1);
		BW_PID_Init();
		FollowTracer_Right();
	}

	if(CAT_FLAG==CAT_DETECTED)
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

		mov_bwd_5cm(10,FAST_LEVEL_3);

		mov_rot_right(FAST_LEVEL_2,FAR);
		mov_rot_right(FAST_LEVEL_2,FAR);
		mov_rot_right(FAST_LEVEL_2,FAR);
		mov_rot_right(FAST_LEVEL_2,FAR);
		mov_rot_right(FAST_LEVEL_2,FAR);
		mov_rot_right(FAST_LEVEL_2,FAR);
		mov_rot_right(FAST_LEVEL_2,FAR);
		mov_rot_right(FAST_LEVEL_2,FAR);

		while(Ping[PING_FRONT]<25)
		{
			mov_rot_right(FAST_LEVEL_2,FAR);
		}


		BW_Buzz(1);
		BW_PID_Init();
		FollowCarpet_Left(COLOUR_GRAY,INVERSE);

//		while(Ping[PING_FRONT]>=20)
//		{
//			Evade_Wall();
////			mov_fwd_5cm(5,FAST_LEVEL_3);
//			mov_fwd_5cm(5,FAST_LEVEL_3);
//		}
//
//		mov_rot_right(FAST_LEVEL_2,FAR);
//		mov_rot_right(FAST_LEVEL_2,FAR);
//		while(Ping[PING_FRONT]<=25)
//		{
//			mov_rot_right(FAST_LEVEL_2,FAR);
////			mov_rot_right(FAST_LEVEL_3,CLOSE);
//		}

		BW_Buzz(1);
		BW_PID_Init();
		FollowCarpet_Left(COLOUR_BLACK,INVERSE);

		BW_Buzz(1);
		BW_PID_Init();
		FollowCarpet_Right(COLOUR_GRAY,INVERSE);

		BW_Buzz(1);
		BW_PID_Init();
		FollowCarpet_Right(COLOUR_BLACK,INVERSE);


		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);

		BW_Buzz(1);
		BW_PID_Init();
		FollowCarpet_Left(COLOUR_GRAY,INVERSE);



		BW_Buzz(1);
//		mov_fwd_5cm(10,FAST_LEVEL_3);
		mov_fwd_5cm(10,FAST_LEVEL_3);

		BW_Buzz(1);
		mov_rot_left(FAST,FAR);
		mov_rot_left(FAST,FAR);
		mov_rot_left(FAST,CLOSE);
		mov_rot_left(FAST,CLOSE);

		while( (Ping[PING_RIGHT]>=30))
		{
			Evade_Wall();
//			mov_fwd_5cm(5,FAST_LEVEL_3);
			mov_fwd_5cm(5,FAST_LEVEL_3);
			if(Ping[PING_FRONT]<20)
			{
				mov_rot_left(FAST,FAR);
			}
		}

		BW_Buzz(1);
		BW_PID_Init();
		FollowTracer_Right();


	}





}


/* func      : void Nav_4B_To_HallwaySC(void)
 * brief     : Navigate from Room 4B to Hallway SC
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Sunday, 10th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_4B_To_HallwaySC(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R4B TO SC");lcd_putstr(lcd);
	delay_ms(100);

//	while(Ping[PING_FRONT]<=30)
//	{
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//	}

//	mov_fwd_5cm(15,FAST_LEVEL_3);
	mov_fwd_5cm(15,FAST_LEVEL_3);

	BW_Buzz(2);
	BW_PID_Init();
	follow_right_counter(5);

	mov_deflect_left(FAST,CLOSE);
	mov_deflect_left(FAST,CLOSE);
	mov_deflect_left(FAST,CLOSE);

	BW_Buzz(2);
	BW_PID_Init();
	FollowHome_Left();
}



/* func      : void Nav_4B_To_1(void)
 * brief     : Navigate from Room 4B to Room 1
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 29th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_4B_To_1A(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R4B TO R1A");lcd_putstr(lcd);
	delay_ms(100);



	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_left(FAST_LEVEL_3,CLOSE);

	while(Ping[PING_FRONT]<=25)
	{
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
	}

	ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;
	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

	BW_Buzz(2);
	BW_PID_Init();
	FollowTracer_Right();

	if(CAT_FLAG==CAT_DETECTED)
	{
		BW_Buzz(2);
		BW_PID_Init();
		FollowTracer_Left();
	}

}

void Nav_4B_To_1BC(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R4B TO R1BC");lcd_putstr(lcd);
	delay_ms(100);


	if(Ping[PING_FRONT]>=12)
	{
		mov_fwd_5cm(10,FAST_LEVEL_3);
		BW_Buzz(1);
	}

	mov_rot_right(FAST,FAR);
	mov_rot_right(FAST,FAR);
	while(Ping[PING_FRONT]<30)
	{
		mov_rot_right(FAST,FAR);
		mov_rot_right(FAST,FAR);
	}

//	BW_Buzz(1);
//	if(Ping[PING_LEFT]>=10)
//	{
//		mov_deflect_left(FAST,CLOSE);
//	}
//
//	if(Ping[PING_LEFT]>=10)
//	{
//		mov_deflect_left(FAST,CLOSE);
//	}
//
//	if(Ping[PING_LEFT]>=10)
//	{
//		mov_deflect_left(FAST,CLOSE);
//	}

//	BW_Buzz(1);
//	while( (Ping[PING_LEFT]<=50))
//	{
//		Evade_Wall();
//		mov_fwd_5cm(5,FAST_LEVEL_3);
//	}
//
//	BW_Buzz(1);
//	mov_fwd_5cm(10,FAST_LEVEL_3);
//
//	if(Ping[PING_LEFT]>=6)
//	{
//		mov_deflect_left(FAST,CLOSE);
//	}
//
//	if(Ping[PING_LEFT]>=6)
//	{
//		mov_deflect_left(FAST,CLOSE);
//	}
//
//	if(Ping[PING_LEFT]>=6)
//	{
//		mov_deflect_left(FAST,CLOSE);
//	}

//	BW_Buzz(1);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//
////	BW_Buzz(1);
//	mov_fwd_5cm(15,FAST_LEVEL_3);


//	BW_Buzz(1);
//	BW_PID_Init();
//	FollowCarpet_Left(COLOUR_GRAY,INVERSE);
//
//	BW_Buzz(1);
//	if(Ping[PING_RIGHT]<=17)
//	{
//		mov_deflect_left(FAST,CLOSE);
//	}
//
//	if(Ping[PING_RIGHT]<=17)
//	{
//		mov_deflect_left(FAST,CLOSE);
//	}
//
//	BW_Buzz(1);
//	BW_PID_Init();
//	FollowCarpet_Left(COLOUR_BLACK,INVERSE);
//
//	BW_Buzz(1);
//	if(Ping[PING_RIGHT]<=17)
//	{
//		mov_deflect_left(FAST,CLOSE);
//	}
//
//	if(Ping[PING_RIGHT]<=17)
//	{
//		mov_deflect_left(FAST,CLOSE);
//	}
//
//	if(Ping[PING_RIGHT]<=17)
//	{
//		mov_deflect_left(FAST,CLOSE);
//	}
//	if(Ping[PING_RIGHT]<=17)
//	{
//		mov_deflect_left(FAST,CLOSE);
//	}
//
//	BW_Buzz(1);
////	mov_fwd_5cm(5,FAST_LEVEL_3);
//	mov_fwd_5cm(5,FAST_LEVEL_3);
//
//	if(Ping[PING_LEFT]>=15)
//	{
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//	}


	BW_Buzz(2);
	BW_PID_Init();
	FollowTracer_Left();
}

/* func      : void Nav_4B_To_2(void)
 * brief     : Navigate from Room 4B to Room 3
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 29th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_4B_To_2(void)
{
	int counter;

	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R4B TO R2");lcd_putstr(lcd);
	delay_ms(100);

//	while(Ping[PING_FRONT]>=12)
//	{
//		mov_fwd_5cm(5,FAST_LEVEL_3);
//	}
//
//
//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);

//	while(Ping[PING_FRONT]<=50)
//	{
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//	}

//	BW_Buzz(1);
//	if(Ping[PING_LEFT]>=13)
//	{
//		mov_deflect_left(FAST,CLOSE);
//	}
//
//	if(Ping[PING_LEFT]>=13)
//	{
//		mov_deflect_left(FAST,CLOSE);
//	}
//
//	if(Ping[PING_LEFT]>=13)
//	{
//		mov_deflect_left(FAST,CLOSE);
//	}
//
//	BW_Buzz(1);
//	while( (Ping[PING_LEFT]<=50))
//	{
//		Evade_Wall();
////		mov_fwd_5cm(5,FAST_LEVEL_3);
//		mov_fwd_5cm(5,FAST_LEVEL_3);
//	}

//	BW_Buzz(1);
////	mov_fwd_5cm(10,FAST_LEVEL_3);
//	mov_fwd_5cm(10,FAST_LEVEL_3);


//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);


//	BW_Buzz(1);
//	for(counter=1;counter<=4;counter++)
//	{
//		Evade_Wall();
////		mov_fwd_5cm(5,FAST_LEVEL_3);
//		mov_fwd_5cm(5,FAST_LEVEL_3);
//	}
//
//	BW_Buzz(1);
//	mov_deflect_right(FAST,CLOSE);
//	mov_deflect_right(FAST,CLOSE);
//	mov_deflect_right(FAST,CLOSE);

//	while(Ping[PING_FRONT]<30)
//	{
//		mov_rot_right(FAST,FAR);
//	}
	if(Ping[PING_FRONT]>=12)
	{
		mov_fwd_5cm(10,FAST_LEVEL_3);
		BW_Buzz(1);
	}

	mov_rot_right(FAST,FAR);
	mov_rot_right(FAST,FAR);
	while(Ping[PING_FRONT]<30)
	{
		mov_rot_right(FAST,FAR);
		mov_rot_right(FAST,FAR);
	}


	BW_Buzz(1);
	BW_PID_Init();
	FollowCarpet_Left(COLOUR_GRAY,INVERSE);

	BW_Buzz(1);
	BW_PID_Init();
	FollowCarpet_Left(COLOUR_BLACK,INVERSE);

	mov_deflect_right(FAST,CLOSE);
	mov_deflect_right(FAST,CLOSE);
	mov_deflect_right(FAST,CLOSE);

	BW_Buzz(1);
	BW_PID_Init();
	FollowTracer_Right();

//	while(1)
//	{
//		BW_Buzz(2);
//		mov_static();
//	}

}

/* func      : void Nav_4B_To_3(void)
 * brief     : Navigate from Room 4B to Room 3
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 29th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_4B_To_3(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R4B TO R3");lcd_putstr(lcd);
	delay_ms(100);

	if(Ping[PING_FRONT]>=12)
	{
		mov_fwd_5cm(10,FAST_LEVEL_3);
		BW_Buzz(1);
	}

	mov_rot_right(FAST,FAR);
	mov_rot_right(FAST,FAR);
	while(Ping[PING_FRONT]<30)
	{
		mov_rot_right(FAST,FAR);
		mov_rot_right(FAST,FAR);
	}


//	while ((Ping[PING_ASKEW_LEFT])<=(Ping[PING_LEFT]))
//	{
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//	}
//
//	while(Ping[PING_LEFT]>30)
//	{
//		mov_rot_left(FAST_LEVEL_2,FAR);
//	}
//
//	while ((Ping[PING_ASKEW_LEFT])<=(Ping[PING_LEFT]))
//	{
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//	}
//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);

//	mov_fwd_5cm(40,FAST_LEVEL_3);
//	mov_rot_right(FAST,CLOSE);
//	mov_rot_right(FAST,CLOSE);
//	while((Ping[PING_RIGHT]>25) || (Ping[PING_LEFT]>25) || (Ping[PING_ASKEW_LEFT]>25) || (Ping[PING_ASKEW_RIGHT]>25))
//	{
//		mov_fwd_5cm(5,FAST_LEVEL_3);
//		if((Ping[PING_RIGHT]<25) || (Ping[PING_LEFT]<25) || (Ping[PING_ASKEW_LEFT]<25) || (Ping[PING_ASKEW_RIGHT]<25))break;
//	}
	BW_Buzz(1);
	BW_PID_Init();
	FollowCarpet_Left(COLOUR_GRAY,INVERSE);

	BW_Buzz(1);
	BW_PID_Init();
	FollowCarpet_Left(COLOUR_BLACK,INVERSE);

	mov_deflect_right(FAST,CLOSE);
	mov_deflect_right(FAST,CLOSE);
	Nav_TurnAround(TURN_RIGHT);

	BW_Buzz(1);
	BW_PID_Init();
	FollowTracer_Left();

}

/* func      : void TCSlave_Check(void)
 * brief     : Detecting white lines with TCS3200 Processor
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Thursday, March 30th 2016)
 * Revised BY: Ver. 2 -> Ryan (Thursday, April 21st 2016
 * 					Configured for the new Hybrid TCS3200+Tracer Processor
 * programmer's Note:
 */
void TCSlave_Check(void)
{
	HomeCircle_Detector();
//	HomeCircle_Detector();

//	if((HOME_CIRCLE_FLAG==HOME_CIRCLE_DETECTED) && (FOLLOWHOME_FLAG==FOLLOWHOME_INACTIVE))
//	{
//		lcd_display_clear();
//		lcd_gotoxy(0,0);sprintf(lcd,"ESCAPING");lcd_putstr(lcd);
//		lcd_gotoxy(0,1);sprintf(lcd,"HOME CIRCLE");lcd_putstr(lcd);
//		delay_ms(100);
//
//		BW_PID_Init();
//		follow_right_counter(5);
////		TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
////		while ( (TCS3200_SLV_DATA[1]==TRACER_ACTIVE) || (TCS3200_SLV_DATA[0]==COLOUR_WHITE) )
////		{
////			follow_right_counter(2);
////			TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
////		}
//
//		lcd_display_clear();
//		lcd_gotoxy(0,0);sprintf(lcd,"HOME CIRCLE");lcd_putstr(lcd);
//		lcd_gotoxy(0,0);sprintf(lcd,"ESCAPED!");lcd_putstr(lcd);
//		delay_ms(100);
//		HOME_CIRCLE_FLAG==HOME_CIRCLE_NOT_DETECTED;
//
//	}

	if( (HOME_CIRCLE_FLAG == HOME_CIRCLE_NOT_DETECTED) && (FOLLOWHOME_FLAG==FOLLOWHOME_INACTIVE))
	{
		TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
//		if(
//			(TCS3200_SLV_DATA[0]==COLOUR_WHITE)
//		  )
//		{
//			TRACER_STAT= TRACER_ACTIVE;
//		}
		if(
			(TCS3200_SLV_DATA[1]==TRACER_ACTIVE)
		  )
		{
			TRACER_STAT= TRACER_ACTIVE;
		}

		TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
//		if(
//			(TCS3200_SLV_DATA[0]==COLOUR_WHITE)
//		  )
//		{
//			TRACER_STAT= TRACER_ACTIVE;
//		}
		if(
			(TCS3200_SLV_DATA[1]==TRACER_ACTIVE)
		  )
		{
			TRACER_STAT= TRACER_ACTIVE;
		}

		TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
//		if(
//			(TCS3200_SLV_DATA[0]==COLOUR_WHITE)
//		  )
//		{
//			TRACER_STAT= TRACER_ACTIVE;
//		}
		if(
			(TCS3200_SLV_DATA[1]==TRACER_ACTIVE)
		  )
		{
			TRACER_STAT= TRACER_ACTIVE;
		}

		TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
//		if(
//			(TCS3200_SLV_DATA[0]==COLOUR_WHITE)
//		  )
//		{
//			TRACER_STAT= TRACER_ACTIVE;
//		}
		if(
			(TCS3200_SLV_DATA[1]==TRACER_ACTIVE)
		  )
		{
			TRACER_STAT= TRACER_ACTIVE;
		}
	}

}

/* func      : void HomeCircle_Detector(void)
 * brief     : Detecting HomeCircle's presence
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Thursday, March 30th 2016)
 * Revised BY: Ver. 2 -> Ryan (Thursday, April 21st 2016
 * 					Configured for the new Hybrid TCS3200+Tracer Processor
 * programmer's Note:
 */
void HomeCircle_Detector(void)
{
	HOME_CIRCLE_FLAG = HOME_CIRCLE_NOT_DETECTED;

	if(HOME_CIRCLE_FLAG == HOME_CIRCLE_NOT_DETECTED)
	{
//		TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
//		if( (TCS3200_SLV_DATA[0]==COLOUR_WHITE) && (TCS3200_SLV_DATA[1]==TRACER_ACTIVE) )
//		{
//			HOME_CIRCLE_FLAG = HOME_CIRCLE_DETECTED;
//
//			lcd_display_clear();
//			lcd_gotoxy(0,0);sprintf(lcd,"HOME CIRCLE");lcd_putstr(lcd);
//			lcd_gotoxy(8,1);sprintf(lcd,"DETECTED");lcd_putstr(lcd);
//			delay_ms(100);
//		}
//		else
//		{
//			HOME_CIRCLE_FLAG = HOME_CIRCLE_NOT_DETECTED;
//		}
	}

}


/* func      : void Exit_No_Fire(void)
 * brief     : BW Escape ROOM when fire is not present
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (*MISSING NOTES*, Legacy codes from BW 2015)
 * Revised BY: N/A
 * programmer's Note:
 *
 */
void Exit_No_Fire(void)
{
	int counter;
	Sendto_PC(USART1,"BW EXIT NO FIRE \r");

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(1,1);sprintf(lcd,"FIRE NOT FOUND");lcd_putstr(lcd);
	lcd_gotoxy(2,2);sprintf(lcd,"EXIT  ROOM");lcd_putstr(lcd);
	lcd_gotoxy(3,3);sprintf(lcd,"INITIATE");lcd_putstr(lcd);
	delay_ms(100);
	Get_IR();

	if( (ROOM1_FLAG==ROOM1FLAG_ACTIVE) )
	{
		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(2,1);sprintf(lcd,"ROOM 1 FLAG");lcd_putstr(lcd);
		lcd_gotoxy(2,2);sprintf(lcd,"EXIT  ROOM");lcd_putstr(lcd);
		lcd_gotoxy(3,3);sprintf(lcd,"INITIATE");lcd_putstr(lcd);
		delay_ms(100);

		mov_fwd_5cm(10,FAST_LEVEL_3);
		if(Ping[PING_RIGHT]<=25)
		{
			BW_Buzz(1);
			BW_PID_Init();
			follow_right_counter(1);
			FollowTracer_Right();
		}

		else
		{
//			mov_rot_left(FAST_LEVEL_3,CLOSE);

			BW_Buzz(1);
			mov_deflect_left(FAST,CLOSE);
			mov_deflect_left(FAST,CLOSE);
			mov_deflect_left(FAST,CLOSE);
			mov_deflect_left(FAST,CLOSE);

			BW_Buzz(1);
			if(Ping[PING_LEFT]>=10)
			{
				mov_rot_left(FAST_LEVEL_3,CLOSE);
				mov_rot_left(FAST_LEVEL_3,CLOSE);

				for(counter=1;counter<=5;counter++)
				{
					mov_fwd_5cm(5,FAST_LEVEL_3);
					if(Ping[PING_FRONT]<=20)break;
				}
			}

			BW_Buzz(1);
			BW_PID_Init();
			follow_left_counter(1);
			FollowTracer_Left();
		}

		ROOM1_FLAG=ROOM1FLAG_INACTIVE;
	}

	//ENTER FROM R1A, EXIT FROM RIBC
	else if(ROOM1A_SP_EXIT_FLAG==ROOM1A_SP_EXIT_FLAG_ACTIVE)
	{
		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"R 4A TO 1A FLAG");lcd_putstr(lcd);
		lcd_gotoxy(2,2);sprintf(lcd,"EXIT  ROOM");lcd_putstr(lcd);
		lcd_gotoxy(3,3);sprintf(lcd,"INITIATE");lcd_putstr(lcd);
		delay_ms(100);
		mov_fwd_5cm(10,FAST_LEVEL_3);
//		if(Ping[PING_LEFT]<=25)
//		{
//			mov_rot_right(FAST_LEVEL_2,FAR);
//			mov_rot_right(FAST_LEVEL_2,FAR);
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
////			mov_rot_right(FAST_LEVEL_3,CLOSE);
//			mov_fwd_5cm(20,FAST_LEVEL_3);
//		}
//
////		if(Ping[PING_RIGHT]>=17)
////		{
////			mov_deflect_right(FAST,CLOSE);
////			mov_deflect_right(FAST,CLOSE);
////			mov_deflect_right(FAST,CLOSE);
////		}
//
//		if(Ping[PING_RIGHT]>=20)
//		{
//			mov_deflect_right(FAST,CLOSE);
//			mov_deflect_right(FAST,CLOSE);
//			mov_deflect_right(FAST,CLOSE);
//		}
//
//		BW_Buzz(2);
//		BW_PID_Init();
//		FollowTracer_Right();
		if(Ping[PING_LEFT]<20)
		{
			mov_deflect_left(FAST,CLOSE);
		}
		if(Ping[PING_LEFT]<20)
		{
			mov_deflect_left(FAST,CLOSE);
		}
		if(Ping[PING_LEFT]<20)
		{
			mov_deflect_left(FAST,CLOSE);
		}

		BW_Buzz(2);
		BW_PID_Init();
		FollowTracer_Left();

		ROOM1A_SP_EXIT_FLAG=ROOM1A_SP_EXIT_FLAG_INACTIVE;
	}

	//FUNGSI EXIT KHUSUS RUANG 4, AGAR BISA MEMBEDAKAN 4A / 4B
	else if(ROOM4_FLAG==ROOM4FLAG_ACTIVE)
	{
//			if (Ping[PING_ASKEW_LEFT]<15)
//			{
//				mov_rot_right(FAST,CLOSE);
//				mov_rot_right(FAST,CLOSE);
//				mov_rot_right(FAST,CLOSE);
//			}
//			else if ((Ping[PING_ASKEW_LEFT]>15) && (Ping[PING_ASKEW_LEFT]<60))
//			{
//				mov_deflect_left(FAST,CLOSE);
//				mov_deflect_left(FAST,CLOSE);
//				mov_deflect_left(FAST,CLOSE);
//				mov_deflect_left(FAST,CLOSE);
//				mov_deflect_left(FAST,CLOSE);
////				mov_rot_right(FAST_LEVEL_2,FAR);
//				mov_deflect_left(FAST,CLOSE);
////				mov_deflect_left(FAST,CLOSE);
////				mov_deflect_left(FAST,CLOSE);
////				mov_deflect_left(FAST,CLOSE);
//
//
//				if ((Ping[PING_ASKEW_LEFT]<15))
//				{
//					mov_rot_right(FAST_LEVEL_2,FAR);
//				}
//			}

		while ((Ping[PING_ASKEW_LEFT])>=(Ping[PING_LEFT]))
		{
			mov_rot_left(FAST_LEVEL_2,FAR);
//				mov_rot_left(FAST_LEVEL_2,FAR);
		}

		while(Ping[PING_LEFT]<12)
		{
			mov_deflect_right(FAST,CLOSE);
		}

		if(Ping[PING_LEFT]>17)
		{
			mov_deflect_left(FAST,CLOSE);
			mov_deflect_left(FAST,CLOSE);
			mov_deflect_left(FAST,CLOSE);
			mov_deflect_left(FAST,CLOSE);
			mov_deflect_left(FAST,CLOSE);
			mov_rot_right(FAST_LEVEL_2,FAR);
			mov_rot_right(FAST_LEVEL_2,FAR);
			mov_deflect_left(FAST,CLOSE);
			mov_deflect_left(FAST,CLOSE);
			mov_deflect_left(FAST,CLOSE);
		}

		if(Ping[PING_LEFT]>17)
		{
			mov_deflect_left(FAST,CLOSE);
			mov_deflect_left(FAST,CLOSE);
			mov_deflect_left(FAST,CLOSE);
			mov_deflect_left(FAST,CLOSE);
			mov_deflect_left(FAST,CLOSE);
			mov_deflect_left(FAST,CLOSE);
			mov_rot_right(FAST_LEVEL_2,FAR);
			mov_rot_right(FAST_LEVEL_2,FAR);
		}
		if(Ping[PING_LEFT]>17)
		{
			mov_deflect_left(FAST,CLOSE);
			mov_deflect_left(FAST,CLOSE);
			mov_deflect_left(FAST,CLOSE);
			mov_deflect_left(FAST,CLOSE);
			mov_deflect_left(FAST,CLOSE);
		}

		while ((Ping[PING_ASKEW_LEFT])>=(Ping[PING_LEFT]))
		{
			mov_rot_left(FAST_LEVEL_3,CLOSE);
//				mov_rot_left(FAST_LEVEL_2,FAR);
		}

		while ((Ping[PING_ASKEW_LEFT])<=(Ping[PING_LEFT]))
		{
			mov_rot_right(FAST_LEVEL_3,CLOSE);
		}

		if(Ping[PING_FRONT]<14)
		{
			while (Ping[PING_FRONT]<14)
			{
				mov_rot_right(FAST_LEVEL_2,FAR);
			}

			while ((Ping[PING_ASKEW_LEFT])>=(Ping[PING_LEFT]))
			{
				mov_rot_left(FAST_LEVEL_3,CLOSE);
//				mov_rot_left(FAST_LEVEL_2,FAR);
			}

			while ((Ping[PING_ASKEW_LEFT])<=(Ping[PING_LEFT]))
			{
				mov_rot_right(FAST_LEVEL_3,CLOSE);
			}
		}

			TRACER_STAT=TRACER_INACTIVE;
			TCSlave_Check();
			while (TRACER_STAT==TRACER_INACTIVE)
			{
				mov_bwd_5cm(5,FAST);
				TCSlave_Check();
				if(TRACER_STAT==TRACER_ACTIVE) break;
			}
			BW_Buzz(2);

//			mov_rot_right(FAST_LEVEL_2,FAR);
			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			mov_rot_left(FAST_LEVEL_3,CLOSE);

			mov_bwd_5cm(25,FAST_LEVEL_3);

			if(Ping[PING_LEFT]<65)
			{
				BW_Buzz(1);
				while((Ping[PING_RIGHT]>30) || (Ping[PING_ASKEW_RIGHT]>30))
				{
					mov_rot_right(FAST_LEVEL_2,FAR);
					mov_rot_right(FAST_LEVEL_2,FAR);
					mov_rot_right(FAST_LEVEL_2,FAR);
					if((Ping[PING_LEFT]>100) || (Ping[PING_ASKEW_LEFT]>100))
					{
						mov_deflect_right(FAST,CLOSE);
						mov_deflect_right(FAST,CLOSE);
					}
				}

				if (Ping[PING_RIGHT]<17)
				{
					mov_deflect_right(FAST,CLOSE);
				}
				if (Ping[PING_RIGHT]<17)
				{
					mov_deflect_right(FAST,CLOSE);
				}
			}

			else
			{
				ROOM4B_FLAG=ROOM4BFLAG_ACTIVE;
				BW_Buzz(2);
				while((Ping[PING_LEFT]>30) || (Ping[PING_ASKEW_LEFT]>30))
				{
					mov_rot_left(FAST_LEVEL_2,FAR);
					mov_rot_left(FAST_LEVEL_2,FAR);
					mov_rot_left(FAST_LEVEL_2,FAR);
					if((Ping[PING_RIGHT]>60) || (Ping[PING_ASKEW_RIGHT]>60))
					{
						mov_deflect_left(FAST,CLOSE);
						mov_deflect_left(FAST,CLOSE);
					}
				}

				if (Ping[PING_RIGHT]<17)
				{
					mov_deflect_right(FAST,CLOSE);
				}
				if (Ping[PING_RIGHT]<17)
				{
					mov_deflect_right(FAST,CLOSE);
				}
			}

	}
	else if (ROOM4B_EXIT_FLAG==ROOM4BFLAG_EXIT_ACTIVE)
	{
		if(Ping[PING_LEFT]<20)
		{
			while ((Ping[PING_ASKEW_LEFT])>=(Ping[PING_LEFT]))
			{
				mov_rot_left(FAST_LEVEL_2,FAR);
	//				mov_rot_left(FAST_LEVEL_2,FAR);
			}

			mov_rot_left(FAST_LEVEL_2,FAR);
			mov_fwd_5cm(10,FAST_LEVEL_2);

			mov_rot_left(FAST_LEVEL_2,FAR);
			mov_rot_left(FAST_LEVEL_2,FAR);

			while(Ping[PING_FRONT]<30)
			{
				mov_rot_left(FAST_LEVEL_2,FAR);
			}
			FollowTracer_Right();
			BW_Buzz(1);
			mov_fwd_5cm(10,FAST_LEVEL_2);

			if (Ping[PING_RIGHT]<14)
			{
				mov_deflect_left(FAST,CLOSE);
			}
			if (Ping[PING_RIGHT]<14)
			{
				mov_deflect_left(FAST,CLOSE);
			}
		}
		else
		{
			while ((Ping[PING_ASKEW_RIGHT])>=(Ping[PING_RIGHT]))
			{
				mov_rot_right(FAST,FAR);
	//				mov_rot_left(FAST_LEVEL_2,FAR);
			}

			mov_rot_right(FAST_LEVEL_2,FAR);
			mov_fwd_5cm(10,FAST_LEVEL_2);

			mov_rot_right(FAST_LEVEL_2,FAR);
			mov_rot_right(FAST_LEVEL_2,FAR);

			while(Ping[PING_FRONT]<30)
			{
				mov_rot_right(FAST_LEVEL_2,FAR);
			}
			FollowTracer_Left();
			BW_Buzz(1);
			mov_fwd_5cm(10,FAST_LEVEL_2);

			if (Ping[PING_LEFT]<14)
			{
				mov_deflect_right(FAST,CLOSE);
			}
			if (Ping[PING_LEFT]<14)
			{
				mov_deflect_right(FAST,CLOSE);
			}
		}
		ROOM4B_EXIT_FLAG=ROOM4BFLAG_EXIT_INACTIVE;
	}
	//DEFAULT EXIT NO FIRE ROUTINES
	else
	{
//			while (Ping[PING_LEFT]<18)
//			{
//				mov_deflect_left(FAST,CLOSE);
//			}
			while ((Ping[PING_ASKEW_LEFT])>=(Ping[PING_LEFT]))
			{
				mov_rot_left(FAST,FAR);
//				mov_rot_left(FAST_LEVEL_2,FAR);
			}

			mov_rot_left(FAST,FAR);
			mov_fwd_5cm(10,FAST_LEVEL_2);

			mov_rot_left(FAST,FAR);
			mov_rot_left(FAST,FAR);

			if(Ping[PING_LEFT]<20)
			{
				mov_rot_left(FAST,FAR);
				mov_rot_left(FAST,FAR);
				mov_rot_left(FAST,FAR);
			}

			while(Ping[PING_FRONT]<30)
			{
				mov_rot_left(FAST_LEVEL_2,FAR);
			}
			FollowTracer_Right();
			BW_Buzz(1);
			mov_fwd_5cm(10,FAST_LEVEL_2);
/*
			while(Ping[PING_LEFT]<12)
			{
				mov_deflect_right(FAST,CLOSE);
			}

			if(Ping[PING_LEFT]>17)
			{
				mov_deflect_left(FAST,CLOSE);
				mov_deflect_left(FAST,CLOSE);
				mov_deflect_left(FAST,CLOSE);
				mov_deflect_left(FAST,CLOSE);
				mov_deflect_left(FAST,CLOSE);
				mov_rot_right(FAST_LEVEL_2,FAR);
				mov_rot_right(FAST_LEVEL_2,FAR);
				mov_deflect_left(FAST,CLOSE);
				mov_deflect_left(FAST,CLOSE);
				mov_deflect_left(FAST,CLOSE);
			}

			if(Ping[PING_LEFT]>17)
			{
				mov_deflect_left(FAST,CLOSE);
				mov_deflect_left(FAST,CLOSE);
				mov_deflect_left(FAST,CLOSE);
				mov_deflect_left(FAST,CLOSE);
				mov_deflect_left(FAST,CLOSE);
				mov_deflect_left(FAST,CLOSE);
				mov_rot_right(FAST_LEVEL_2,FAR);
				mov_rot_right(FAST_LEVEL_2,FAR);
			}
			if(Ping[PING_LEFT]>17)
			{
				mov_deflect_left(FAST,CLOSE);
				mov_deflect_left(FAST,CLOSE);
				mov_deflect_left(FAST,CLOSE);
				mov_deflect_left(FAST,CLOSE);
				mov_deflect_left(FAST,CLOSE);
			}

			while ((Ping[PING_ASKEW_LEFT])>=(Ping[PING_LEFT]))
			{
				mov_rot_left(FAST_LEVEL_3,CLOSE);
//				mov_rot_left(FAST_LEVEL_2,FAR);
			}

			while ((Ping[PING_ASKEW_LEFT])<=(Ping[PING_LEFT]))
			{
				mov_rot_right(FAST_LEVEL_3,CLOSE);
			}

			if(Ping[PING_FRONT]<30)
			{
				while (Ping[PING_FRONT]<30)
				{
					mov_rot_right(FAST_LEVEL_2,FAR);
				}

				while ((Ping[PING_ASKEW_LEFT])>=(Ping[PING_LEFT]))
				{
					mov_rot_left(FAST_LEVEL_3,CLOSE);
	//				mov_rot_left(FAST_LEVEL_2,FAR);
				}

				while ((Ping[PING_ASKEW_LEFT])<=(Ping[PING_LEFT]))
				{
					mov_rot_right(FAST_LEVEL_3,CLOSE);
				}
			}


		//==================================//
		 	if (Ping[PING_ASKEW_LEFT]<15)
			{
				mov_rot_right(FAST,FAR);
				mov_rot_right(FAST,FAR);
				mov_rot_right(FAST,CLOSE);
//				mov_rot_right(FAST,CLOSE);
//				mov_rot_right(FAST,CLOSE);
//				mov_rot_right(FAST,CLOSE);
//				mov_rot_right(FAST,CLOSE);
			}
			else if ((Ping[PING_ASKEW_LEFT]>15) && (Ping[PING_ASKEW_LEFT]<60))
			{
				mov_deflect_left(FAST,CLOSE);
				mov_deflect_left(FAST,CLOSE);
				mov_deflect_left(FAST,CLOSE);
				mov_deflect_left(FAST,CLOSE);
				mov_deflect_left(FAST,CLOSE);
				mov_deflect_left(FAST,CLOSE);

//				mov_rot_left(FAST,CLOSE);
//				mov_rot_left(FAST,CLOSE);

				if ((Ping[PING_ASKEW_LEFT]<15))
				{
					mov_rot_right(FAST_LEVEL_2,FAR);
				}
			}
			//==================================//

//		mov_rot_right(FAST_LEVEL_2,FAR);
		TRACER_STAT=TRACER_INACTIVE;
		TCSlave_Check();
//		delay_ms(100);
		if(TRACER_STAT==TRACER_INACTIVE)
			while (TRACER_STAT==TRACER_INACTIVE)
			{
				mov_bwd_5cm(5,FAST);
				TCSlave_Check();
				if(TRACER_STAT==TRACER_ACTIVE)
				{
					EXIT_FLAG=1;
				}
				if(TRACER_STAT==TRACER_ACTIVE) break;
			}
		if(EXIT_FLAG==0)
			while (TRACER_STAT==TRACER_INACTIVE)
			{
				mov_bwd_5cm(5,FAST);
				TCSlave_Check();
				if(TRACER_STAT==TRACER_ACTIVE)
				{
					EXIT_FLAG=1;
				}
				if(TRACER_STAT==TRACER_ACTIVE) break;
			}

		BW_Buzz(2);
//		mov_bwd_5cm(30,FAST_LEVEL_3);
		mov_rot_right(FAST_LEVEL_2,FAR);
		mov_rot_right(FAST_LEVEL_2,FAR);
//		mov_rot_right(FAST_LEVEL_2,FAR);
//		mov_rot_right(FAST_LEVEL_2,FAR);
//		mov_rot_right(FAST_LEVEL_2,FAR);
		mov_bwd_5cm(25,FAST_LEVEL_3);
//		Get_IR();
//		if((INFRARED[IR_FRONT_MIDDLE]==IR_NOT_DETECTED))
//		{
//			mov_bwd_5cm(10,FAST_LEVEL_3);
//		}

//		while((Ping[PING_RIGHT]>30) || (Ping[PING_ASKEW_RIGHT]>30))
		while(Ping[PING_RIGHT]>30)
		{
			mov_rot_right(FAST_LEVEL_2,FAR);
			mov_rot_right(FAST_LEVEL_2,FAR);
			mov_rot_right(FAST_LEVEL_2,FAR);
			if((Ping[PING_LEFT]>100) || (Ping[PING_ASKEW_LEFT]>100))
			{
				mov_deflect_right(FAST,CLOSE);
				mov_deflect_right(FAST,CLOSE);
			}
		}
*/


		if (Ping[PING_RIGHT]<17)
		{
			mov_deflect_right(FAST,CLOSE);
		}
		if (Ping[PING_RIGHT]<17)
		{
			mov_deflect_right(FAST,CLOSE);
		}

	}

}

/* func      : void Stabilize_After_Exit(void)
 * brief     : Approach nearest wall in front of door, except in front of ROOM
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 30th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Stabilize_After_Exit(void)
{
	int counter;
	BW_Buzz(1);
	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"BW STABILIZE");lcd_putstr(lcd);
	delay_ms(100);

	if(Ping[PING_FRONT]<=75)
	{
		Evade_Wall();

		for(counter=1;counter<=3;counter++)
		{
//			mov_fwd_5cm(5,FAST_LEVEL_3);
			mov_fwd_5cm(5,FAST_LEVEL_3);
			if(Ping[PING_FRONT]<=17)break;
		}
//		while(Ping[PING_FRONT]>=14)
//		{
//			mov_fwd_5cm(5,FAST_LEVEL_3);
//			Evade_Wall();
//		}
	}

}

/* func      : void BW_Room(void)
 * brief     : BW in Room routines
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 30th 2016)
 * Revised BY: N/A
 * programmer's Note: 	1. Detecting ROOM_TYPE (NORMAL_ROOM or GRAY_ROOM)
 * 						2. Checking fire presence
 * 							if fire didn't exist, then Exit_No_Fire() routines initiated
 * 							if fire exist, then FireFighting algorithm initiated
 */
void BW_Room(void)
{
	int EXIT_STAT=0;
	BW_Buzz(2);

	mov_rot_right(FAST_LEVEL_3,CLOSE);
	mov_rot_right(FAST_LEVEL_3,CLOSE);
	mov_rot_right(FAST_LEVEL_3,CLOSE);
	Fwd_FlameSide(9, FAST_LEVEL_3);

	mov_static();
	delay_ms(500);

	BW_Buzz(1);
	RoomTypeDetector();

	if(ROOM_TYPE==GRAY_ROOM)
	{
		mov_fwd_5cm(5,FAST_LEVEL_3);
		RoomTypeDetector();
	}


//	Evade_Wall();

	//===FUNGSI BARU 7/10/16===//
	Get_UV();
	if(UV_state==UVSTATE_ACTIVE)
	{
		FIRE=FIRE_ON;
		UV_Lock=UVLOCK_ACTIVE;
	}

		if(UV_Lock==UVLOCK_INACTIVE)
		{
			mov_rot_right(FAST_LEVEL_3,CLOSE);
			mov_rot_right(FAST_LEVEL_3,CLOSE);
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
			}
		}

		if(UV_Lock==UVLOCK_INACTIVE)
		{
			mov_rot_right(FAST_LEVEL_3,CLOSE);
			mov_rot_right(FAST_LEVEL_3,CLOSE);
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
			}
		}

	//===COMMENT BARU 7/10/16===//
//	BW_FlameCheck();

	//===COMMENT BARU 7/10/16===//
//	if(UV_Lock==UVLOCK_INACTIVE)
//	{
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		BW_FlameCheck();
//	}

//	if(FlameSense[0]!=0)
	if(FIRE==FIRE_ON)
	{
		UV_Lock=UVLOCK_ACTIVE;
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"BW");lcd_putstr(lcd);
		lcd_gotoxy(6,1);sprintf(lcd,"FIREFIGHT");lcd_putstr(lcd);
		delay_ms(100);


//		BW_FireFight();
//		BW_FireFight_Ver2();
//		BW_FireFight_Ver4();
		BW_FireFight_Ver5();

		/*
		 * FIRE == OFF
		 */

		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);
		mov_rot_left(FAST_LEVEL_3,CLOSE);

			if(Ping[PING_FRONT]<=35)
			{
				if(Ping[PING_FRONT]<=15)
				{
					mov_bwd_3cm(18,FAST_LEVEL_3);
				}


				mov_rot_left(FAST_LEVEL_3,CLOSE);
				mov_rot_left(FAST_LEVEL_3,CLOSE);
				Get_IR();
				while(
						(Ping[PING_FRONT]<=25) ||
						(INFRARED[IR_UPPER_LEFT]==IR_DETECTED) ||
						(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
					 )
				{
					mov_rot_left(FAST_LEVEL_3,CLOSE);
					mov_rot_left(FAST_LEVEL_3,CLOSE);
					Get_IR();
				}
				FIRE_LED_BLINK_OFF;
				FIRE_LED_OFF;
				FIRE=FIRE_SUCCESS;
				BW_PID_Init();
				FollowTracer_Right();
			}

			else if(Ping[PING_FRONT]>35)
			{
				if(Ping[PING_LEFT]<Ping[PING_RIGHT])
				{
					mov_rot_left(FAST_LEVEL_3,CLOSE);
					mov_rot_left(FAST_LEVEL_3,CLOSE);
					mov_rot_left(FAST_LEVEL_3,CLOSE);
					mov_rot_left(FAST_LEVEL_3,CLOSE);
					mov_rot_left(FAST_LEVEL_3,CLOSE);
					mov_rot_left(FAST_LEVEL_3,CLOSE);
					mov_rot_left(FAST_LEVEL_3,CLOSE);

					TRACER_STAT=TRACER_INACTIVE;
					while(Ping[PING_FRONT]>=20)
					{
						TCSlave_Check();
						if (TRACER_STAT==TRACER_ACTIVE){EXIT_STAT=1;break;}
						Get_IR();
						if	((INFRARED[IR_UPPER_LEFT]==IR_DETECTED) ||(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED))break;
//						mov_fwd_5cm(5,FAST_LEVEL_3);
						mov_fwd_5cm(5,FAST_LEVEL_3);

					}

					if(EXIT_STAT==0)
					{
						mov_rot_left(FAST_LEVEL_3,CLOSE);
						mov_rot_left(FAST_LEVEL_3,CLOSE);
						mov_rot_left(FAST_LEVEL_3,CLOSE);
						mov_rot_left(FAST_LEVEL_3,CLOSE);
						while(Ping[PING_FRONT]<15)
						{
							mov_rot_left(FAST_LEVEL_3,CLOSE);
							mov_rot_left(FAST_LEVEL_3,CLOSE);
							mov_rot_left(FAST_LEVEL_3,CLOSE);
						}

						FIRE_LED_BLINK_OFF;
						FIRE_LED_OFF;
						FIRE=FIRE_SUCCESS;
						BW_PID_Init();
						FollowTracer_Right();
					}


				}
				else
				{
					mov_rot_right(FAST_LEVEL_3,CLOSE);
					mov_rot_right(FAST_LEVEL_3,CLOSE);
					mov_rot_right(FAST_LEVEL_3,CLOSE);
					mov_rot_right(FAST_LEVEL_3,CLOSE);
					mov_rot_right(FAST_LEVEL_3,CLOSE);
					mov_rot_right(FAST_LEVEL_3,CLOSE);
					mov_rot_right(FAST_LEVEL_3,CLOSE);

					TRACER_STAT=TRACER_INACTIVE;
					while(Ping[PING_FRONT]>=20)
					{
						TCSlave_Check();
						if (TRACER_STAT==TRACER_ACTIVE){EXIT_STAT=1;break;}
						Get_IR();
						if	((INFRARED[IR_UPPER_LEFT]==IR_DETECTED) ||(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED))break;
						mov_fwd_5cm(5, FAST_LEVEL_3);
					}

					if(EXIT_STAT==0)
					{
						mov_rot_right(FAST_LEVEL_3,CLOSE);
						mov_rot_right(FAST_LEVEL_3,CLOSE);
						mov_rot_right(FAST_LEVEL_3,CLOSE);
						mov_rot_right(FAST_LEVEL_3,CLOSE);
						while(Ping[PING_FRONT]<15)
						{
							mov_rot_right(FAST_LEVEL_3,CLOSE);
							mov_rot_right(FAST_LEVEL_3,CLOSE);
							mov_rot_right(FAST_LEVEL_3,CLOSE);
						}

						FIRE_LED_BLINK_OFF;
						FIRE_LED_OFF;
						FIRE=FIRE_SUCCESS;
						BW_PID_Init();
						FollowTracer_Left();
					}
				}

			}

			else
			{
				while(Ping[PING_FRONT]>=15)
				{
					Get_IR();
					if	((INFRARED[IR_UPPER_LEFT]==IR_DETECTED) ||(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED))break;
//					mov_fwd_5cm(5,FAST_LEVEL_3);
					mov_fwd_5cm(5,FAST_LEVEL_3);
				}

				mov_rot_left(FAST_LEVEL_3,CLOSE);
				mov_rot_left(FAST_LEVEL_3,CLOSE);
				while(Ping[PING_FRONT]<15)
				{
					mov_rot_left(FAST_LEVEL_3,CLOSE);
					mov_rot_left(FAST_LEVEL_3,CLOSE);
					mov_rot_left(FAST_LEVEL_3,CLOSE);
				}

				FIRE_LED_BLINK_OFF;
				FIRE_LED_OFF;
				FIRE=FIRE_SUCCESS;
				BW_PID_Init();
				FollowTracer_Right();

			}



	}

	else
	{
		FIRE=FIRE_OFF;
		Exit_No_Fire();
	}

}

/* func      : void BW_Strategy(void)
 * brief     : BW Trial Routines (after escape home)
 * 				Behavior Based System

 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Wednesday, March 30th 2016)
 * Revised BY: N/A
 * programmer's Note:
 * 						BW'S location stored in ROOM[1] ~ ROOM[4] variable
 * 						Program sequences from escape home to return trip
 * 						Decision making for navigation path planning
 */
void BW_Strategy(void)
{
	int Error_Code;

	//LOCATION: CORRIDOR
	BW_Buzz(1);
//	if((SHARP[SHARP_RIGHT]<10)||(Ping[PING_RIGHT]<10))
	if(Ping[PING_RIGHT]<14)
	{
//		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);
	}
//	if((SHARP[SHARP_RIGHT]<10)||(Ping[PING_RIGHT]<10))
	if(Ping[PING_RIGHT]<14)
	{
//		mov_deflect_left(FAST,CLOSE);
		mov_deflect_left(FAST,CLOSE);
	}

//	mov_fwd_5cm(15,FAST_LEVEL_3);
	mov_fwd_5cm(10, FAST_LEVEL_3);

//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
	mov_rot_right(FAST_LEVEL_3,CLOSE);
	mov_rot_right(FAST_LEVEL_3,CLOSE);
	mov_rot_right(FAST_LEVEL_3,CLOSE);

	//BW STABILIZE
	BW_Buzz(1);
//	Stabilize_After_Exit();

	//ROOM DETECTOR FOR FIRST ROOM
	RoomDetector(ROOM_COUNTER);


//	if(ROOM[ROOM_COUNTER]== ROOM_1A)
//	{
////		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		RoomDetector(ROOM_COUNTER);
//	}




	BW_LOCATION[1]= BW_LOCATION[0];
	BW_LOCATION[0]= LOCATION_CORRIDOR;

	while(EXTINGUISHED_FIRE==0)
	{
		//SPECIAL CASE (HOME ROOM ROOM_1B, ROOM_1C, ROOM_4B, ROOM4AFLAG ACTIVE
		if ( (ROOM[1]==ROOM_1B) || (ROOM[1]==ROOM_1C) || (ROOM[1]==ROOM_4B) || (ROOM4A_FLAG==ROOM4AFLAG_ACTIVE) )
		{
//			BW_Buzz(2);
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"REVERSE");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"STRATEGY");lcd_putstr(lcd);
			delay_ms(200);

			if (ROOM[ROOM_COUNTER]== ROOM_1A)
			{
				BW_Navi(ROOM_1A,ROOM_2A);
			}

			if (ROOM[ROOM_COUNTER]== ROOM_1B)
			{
				BW_Navi(ROOM_1B,ROOM_2A);
			}

			if (ROOM[ROOM_COUNTER]== ROOM_1C)
			{
				BW_Navi(ROOM_1C,ROOM_2A);
			}

			else if(ROOM[ROOM_COUNTER]== ROOM_2A)
			{
//				BW_Navi(ROOM_2A,ROOM_3);
				BW_Navi(ROOM_2A,ROOM_1C);
			}

			else if(ROOM[ROOM_COUNTER]== ROOM_2B)
			{
//				BW_Navi(ROOM_2B,ROOM_3);
				BW_Navi(ROOM_2B,ROOM_1B);
			}

			else if(ROOM[ROOM_COUNTER]== ROOM_3)
			{
//				BW_Navi(ROOM_3,ROOM_4A);
				BW_Navi(ROOM_3,ROOM_2A);
			}

			else if(ROOM[ROOM_COUNTER]== ROOM_4A)
			{
				BW_Navi(ROOM_4A,ROOM_1A);
			}

			else if(ROOM[ROOM_COUNTER]== ROOM_4B)
			{
//				BW_Navi(ROOM_4B,ROOM_1C);
				BW_Navi(ROOM_4B,ROOM_3);
			}
		}

		else
		{
//			BW_Buzz(3);
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"DEFAULT");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"STRATEGY");lcd_putstr(lcd);
			delay_ms(100);

			if(ROOM[ROOM_COUNTER]== ROOM_3)
			{
				BW_Navi(ROOM_3,ROOM_2A);
			}
			else if(ROOM[ROOM_COUNTER]== ROOM_2A)
			{
				ROOM1_FLAG=ROOM1FLAG_ACTIVE;
				BW_Navi(ROOM_2A,ROOM_1B);
			}

			else if (ROOM[ROOM_COUNTER]==ROOM_2B)
			{
				ROOM1_FLAG=ROOM1FLAG_ACTIVE;
				BW_Navi(ROOM_2B,ROOM_1B);
			}

			else if(ROOM[ROOM_COUNTER]==ROOM_1A)
			{
				BW_Navi(ROOM_1A,ROOM_4A);
			}
			else if(ROOM[ROOM_COUNTER]==ROOM_1B)
			{
				BW_Navi(ROOM_1C,ROOM_4A);

			}
			else if(ROOM[ROOM_COUNTER]==ROOM_1C)
			{
				BW_Navi(ROOM_1C,ROOM_4A);
			}
			else if(ROOM[ROOM_COUNTER]==ROOM_4A)
			{
				BW_Navi(ROOM_4A,ROOM_3);
			}
			else if(ROOM[ROOM_COUNTER]==ROOM_4B)
			{
				BW_Navi(ROOM_4B,ROOM_3);
			}
		}

		//UPDATE BW LOCATION
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_ROOM;

		//BW IN ROOM
		BW_Buzz(1);
		BW_Room();



		//BW IN CORRIDOR
		BW_Buzz(1);
//		if((SHARP[SHARP_RIGHT]<10)||(Ping[PING_RIGHT]<10))
		if (Ping[PING_RIGHT]<14)
		{
			mov_deflect_left(FAST,CLOSE);
		}
//		if((SHARP[SHARP_RIGHT]<10)||(Ping[PING_RIGHT]<10))
		if (Ping[PING_RIGHT]<14)
		{
			mov_deflect_left(FAST,CLOSE);
		}

//		mov_fwd_5cm(15,FAST_LEVEL_3);
		mov_fwd_5cm(10, FAST_LEVEL_3);

		//BW IN CORRIDOR
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);

		//BW STABILIZE
		BW_Buzz(1);
//		Stabilize_After_Exit();

		//BW MAP UPDATE
		BW_Buzz(1);
		ROOM_COUNTER++;
		RoomDetector(ROOM_COUNTER);


//		if(ROOM[ROOM_COUNTER]== ROOM_4A)
//		{
//			mov_deflect_left(FAST,CLOSE);
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			RoomDetector(ROOM_COUNTER);
//		}

//		mov_rot_left(FAST_LEVEL_3,CLOSE);

//		if(ROOM[ROOM_COUNTER]== ROOM_1A)
//		{
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			RoomDetector(ROOM_COUNTER);
//		}

		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;
	}

	BW_LOCATION[1]= BW_LOCATION[0];
	BW_LOCATION[0]= LOCATION_CORRIDOR;

	Error_Code= BW_ReturnTrip();

	Evade_Wall();
	if(ROOM[1]!=HALLWAY_SC)
	{
		BW_Buzz(2);

		Evade_Wall();
//		mov_fwd_5cm(10,FAST_LEVEL_3);
		mov_fwd_5cm(10,FAST_LEVEL_3);

		Evade_Wall();
//		mov_fwd_5cm(10,FAST_LEVEL_3);
		mov_fwd_5cm(10,FAST_LEVEL_3);

		Evade_Wall();
//		mov_fwd_5cm(10,FAST_LEVEL_3);
		mov_fwd_5cm(10,FAST_LEVEL_3);

		Evade_Wall();
//		mov_fwd_5cm(10,FAST_LEVEL_3);
		mov_fwd_5cm(10,FAST_LEVEL_3);

	}

//	while(1)
//	{
//		mov_celebrate();
//	}
//	mov_fwd_5cm(15,FAST_LEVEL_3);
//	FollowHome_Left();

	if(Error_Code==0)
	{
		BW_Buzz(5);

		while(1)
		{
			mov_celebrate();
		}

	}
	else
	{
		BW_Buzz(1);
		mov_static();
	}


//	//NON ARBITRARY START
//	if(HOME == HALLWAY_SC)
//	{
//		BW_Navi(HALLWAY_SC,ROOM_3);
//	}
//
//	//ARBITRARY START
//	else
//	{
//
//	}
}


/* func      : int BW_ReturnTrip(void)
 * brief     : BW Return Trip Routines
 * param     : N/A
 * retval    : int error codes
 * 				0 	-> SUCCESS
 * 				-1 	-> ERROR, EXTINGUISHED_FIRE==0 / !=1
 * Ver       : 1
 * written By: Ryan (Thursday, March 31th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
int BW_ReturnTrip(void)
{
	//BW RETURN TRIP
	if(EXTINGUISHED_FIRE==1)
	{

//		BW_Buzz(5);
//		BW_Buzz(5);

		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"RETURN TRIP");lcd_putstr(lcd);
//		lcd_gotoxy(8,1);sprintf(lcd,"TRIP");lcd_putstr(lcd);
		delay_ms(100);

		if( (ROOM[ROOM_COUNTER]== ROOM_1A) )
		{
			if( (ROOM[1] == HALLWAY_SC) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R1A TO SC");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_1A,HALLWAY_SC);
			}

			else if( (ROOM[1] == ROOM_2A) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R1A TO R2A");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_1A,ROOM_2A);
			}

			else if( (ROOM[1] == ROOM_2B) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R1A TO R2B");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_1A,ROOM_2B);
			}

			else if(ROOM[1] == ROOM_3)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R1A TO R3");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_1A,ROOM_3);
			}

			else if(ROOM[1] == ROOM_4A)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R1A TO R4A");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_1A,ROOM_4A);
			}

			else if(ROOM[1] == ROOM_4B)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R1A TO R4B");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_1A,ROOM_4B);
			}


		}

		else if( (ROOM[ROOM_COUNTER]== ROOM_1B) || (ROOM[ROOM_COUNTER]== ROOM_1C) )
		{
			if( (ROOM[1] == HALLWAY_SC) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R1C TO SC");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_1C,HALLWAY_SC);
			}

			else if(ROOM[1] == ROOM_3)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R1C TO R3");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_1C,ROOM_3);
			}

			else if( (ROOM[1] == ROOM_2A) || (ROOM[1] == ROOM_2B) )
			{
				if(ROOM[ROOM_COUNTER]== ROOM_1B)
				{
					lcd_gotoxy(0,1);sprintf(lcd,"R1B TO R2A");lcd_putstr(lcd);
					delay_ms(100);
					BW_Navi(ROOM_1B,ROOM_2A);
				}

				else if(ROOM[ROOM_COUNTER]== ROOM_1C)
				{
					lcd_gotoxy(0,1);sprintf(lcd,"R1C TO R2A");lcd_putstr(lcd);
					delay_ms(100);
					BW_Navi(ROOM_1C,ROOM_2A);
				}

			}

			else if(ROOM[1] == ROOM_4A)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R1C TO R4A");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_1C,ROOM_4A);
			}
			else if(ROOM[1] == ROOM_4B)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R1C TO R4B");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_1C,ROOM_4B);
			}
		}

		//ROOM[ROOM_COUNTER] == ROOM_2AB
		else if ( (ROOM[ROOM_COUNTER]== ROOM_2A) || (ROOM[ROOM_COUNTER]== ROOM_2B) )
		{
			if( (ROOM[1] == HALLWAY_SC) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R2A TO SC");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_2A,HALLWAY_SC);
			}

			else if( (ROOM[1] == ROOM_1A) || (ROOM[1] == ROOM_1B) || (ROOM[1] == ROOM_1C) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R2AB TO R1BC");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_2B,ROOM_1B);

			}

			else if(ROOM[1] == ROOM_3)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R2A TO R3");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_2A,ROOM_3);

			}

			else if(ROOM[1] == ROOM_4A)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R2A TO R4A");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_2A,ROOM_4A);
			}
			else if(ROOM[1] == ROOM_4B)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R2A TO R4B");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_2A,ROOM_4B);
			}
		}

		//ROOM[ROOM_COUNTER] == ROOM_3
		else if (ROOM[ROOM_COUNTER]== ROOM_3)
		{
			if( (ROOM[1] == HALLWAY_SC) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R3 TO SC");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_3,HALLWAY_SC);
			}

			else if ( (ROOM[1] == ROOM_1A) || (ROOM[1] == ROOM_1B) || (ROOM[1] == ROOM_1C) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R3 TO R1B");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_3,ROOM_1B);

			}

			else if( (ROOM[1] == ROOM_2A) || (ROOM[1] == ROOM_2B) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R3 TO R2A");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_3,ROOM_2A);

			}

			else if(ROOM[1] == ROOM_4A)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R3 TO R4A");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_3,ROOM_4A);

			}

			else if(ROOM[1] == ROOM_4B)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R3 TO R4B");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_3,ROOM_4B);

			}
		}

		//ROOM[ROOM_COUNTER] == ROOM_4A
		else if (ROOM[ROOM_COUNTER]== ROOM_4A)
		{
			if( (ROOM[1] == HALLWAY_SC) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R4A TO SC");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_4A,HALLWAY_SC);
			}

			else if ( (ROOM[1] == ROOM_1A) || (ROOM[1] == ROOM_1B) || (ROOM[1] == ROOM_1C) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R4A TO R1A");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_4A,ROOM_1A);

			}

			else if( (ROOM[1] == ROOM_2A) || (ROOM[1] == ROOM_2B) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R4A TO R2A");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_4A,ROOM_2A);

			}

			else if(ROOM[1] == ROOM_3)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R4A TO R3");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_4A,ROOM_3);

			}
		}

		//ROOM[ROOM_COUNTER] == ROOM_4B
		else if (ROOM[ROOM_COUNTER]== ROOM_4B)
		{
			if( (ROOM[1] == HALLWAY_SC) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R4B TO SC");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_4B,HALLWAY_SC);
			}

			else if ( (ROOM[1] == ROOM_1A) || (ROOM[1] == ROOM_1B) || (ROOM[1] == ROOM_1C) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R4B TO R1A");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_4B,ROOM_1B);

			}

			else if( (ROOM[1] == ROOM_2A) || (ROOM[1] == ROOM_2B) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R4B TO R2A");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_4B,ROOM_2A);

			}

			else if(ROOM[1] == ROOM_3)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R4B TO R3");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_4B,ROOM_3);

			}
		}

		// Everything's Alright~ *I hope
		return 0;
	}

	//Return Error Code
	else
	{
		BW_Buzz(2);
		lcd_gotoxy(0,1);sprintf(lcd,"ROUTE ERROR");lcd_putstr(lcd);
		delay_ms(100);

		while(1)
		{
			BW_Buzz(1);
			mov_static();
		}
//		BW_Navi(ROOM_4B,ROOM_3);

		//BW MAP UPDATE

		RoomDetector(ROOM_COUNTER);
		BW_ReturnTrip();

		return -1;
	}
}


/* func      : void RoomType_Init(void)
 * brief     : Initialize ROOM_TYPE variables manually (for debugging purposes)
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 31th 2016)
 * Revised BY: N/A
 * programmer's Note: 	1. Setting by clicking BUTTON_A and BUTTON_B
 * 						2. Finalize decision by pressing BW_BUTTON (START BUTTON)
 */
void RoomType_Init(void)
{
	int MENU_VAR=1;

	while(BW_BUTTON_UNCLICKED)
	{
		if(BUTTON_A_CLICKED)
		{
			BW_Buzz(2);
			while(BUTTON_A_CLICKED){};
			MENU_VAR++;
		}
		if(BUTTON_B_CLICKED)
		{
			BW_Buzz(1);
			while(BUTTON_B_CLICKED){};
			MENU_VAR--;
		}

		if(MENU_VAR>2) MENU_VAR=1;
		else if (MENU_VAR<1) MENU_VAR=2;

		switch(MENU_VAR)
		{
			case 1:
					{
						ROOM_TYPE=NORMAL_ROOM;
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"NORMAL ROOM");lcd_putstr(lcd);
						delay_ms(100);
					}break;
			case 2:
					{
						ROOM_TYPE=GRAY_ROOM;
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"GRAY ROOM");lcd_putstr(lcd);
						delay_ms(100);
					}break;
		}
	}
}


void BW_FlameCheck(void)
{

	static int right=90,left=90;

	generate_movement_data(0,0,9);
	delay_ms(50);


	Get_UV();
	if(UV_state==UVSTATE_ACTIVE){FIRE=FIRE_ON;UV_Lock=UVLOCK_ACTIVE;}
//	if(FlameSense[0]!=0){FIRE=1; }

		while(right>=10&&left<=170)
		{
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE){FIRE=FIRE_ON;UV_Lock=UVLOCK_ACTIVE;}
//			Send_FlameSense();
//			if(FlameSense[0]!=0){FIRE=1;}
			inv_kine(front_left,left,7,leg);
			inv_kine(front_right,right,7,leg);
			inv_kine(middle_left,left,7,leg);
			inv_kine(middle_right,right,7,leg);
			inv_kine(rear_left,left,7,leg);
			inv_kine(rear_right,right,7,leg);
			delay_ms(13);
			right-=2;
			left+=2;
		}
		delay_ms(50);

		Get_UV();
		if(UV_state==UVSTATE_ACTIVE){FIRE=FIRE_ON;UV_Lock=UVLOCK_ACTIVE;}

		while(right<=90&&left>=90)
		{
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE){FIRE=FIRE_ON;UV_Lock=UVLOCK_ACTIVE;}
//			Send_FlameSense();
//			if(FlameSense[0]!=0){FIRE=1;}
			inv_kine(front_left,left,7,leg);
			inv_kine(front_right,right,7,leg);
			inv_kine(middle_left,left,7,leg);
			inv_kine(middle_right,right,7,leg);
			inv_kine(rear_left,left,7,leg);
			inv_kine(rear_right,right,7,leg);
			delay_ms(13);
			right+=2;
			left-=2;
		}
		delay_ms(50);

		Get_UV();
		if(UV_state==UVSTATE_ACTIVE){FIRE=FIRE_ON;UV_Lock=UVLOCK_ACTIVE;}

		while(right<=170&&left>=10)
		{
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE){FIRE=FIRE_ON;UV_Lock=UVLOCK_ACTIVE;}
//			Send_FlameSense();
//			if(FlameSense[0]!=0){FIRE=1;}
			inv_kine(front_left,left,7,leg);
			inv_kine(front_right,right,7,leg);
			inv_kine(middle_left,left,7,leg);
			inv_kine(middle_right,right,7,leg);
			inv_kine(rear_left,left,7,leg);
			inv_kine(rear_right,right,7,leg);
			delay_ms(13);
			right+=2;
			left-=2;
		}
		delay_ms(50);

		Get_UV();
		if(UV_state==UVSTATE_ACTIVE){FIRE=FIRE_ON;UV_Lock=UVLOCK_ACTIVE;}
		while(right>=90&&left<=90)
		{
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE){FIRE=FIRE_ON;UV_Lock=UVLOCK_ACTIVE;}
//			Send_FlameSense();
//			if(FlameSense[0]!=0){FIRE=1;}
			inv_kine(front_left,left,7,leg);
			inv_kine(front_right,right,7,leg);
			inv_kine(middle_left,left,7,leg);
			inv_kine(middle_right,right,7,leg);
			inv_kine(rear_left,left,7,leg);
			inv_kine(rear_right,right,7,leg);
			delay_ms(13);
			right-=2;
			left+=2;
		}
		delay_ms(50);
		Get_UV();
		if(UV_state==UVSTATE_ACTIVE){FIRE=FIRE_ON;UV_Lock=UVLOCK_ACTIVE;}

		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(1,1);sprintf(lcd,"FLAME  MONITOR");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"UV_state: %d",UV_state);lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"FlameSense[0]: %d",FlameSense[0]);lcd_putstr(lcd);
		delay_ms(100);
}


void BW_CandleScan(void)
{
	static int right=90,left=90;
	int OVERRIDE=0;
	generate_movement_data(0,0,9);
	delay_ms(50);

	while(OVERRIDE==0)
	{
		Get_IR();
//		if( (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) &&
//			(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
//			(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)
//		  )
		if(
			(
					((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_LEFT]==IR_DETECTED)) ||
					((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
			)&&
			(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
			(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED) &&
			(FlameSense[0]==3)
		  )
		{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}

		Get_IR();
		if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
		{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}

		while(right>=10&&left<=170 &&(OVERRIDE==0))
		{
			Get_IR();
			if( (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) &&
				(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
				(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)&&
				(FlameSense[0]==3)
			  )
			{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}

			Get_IR();
			if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
			{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}

			inv_kine(front_left,left,7,leg);
			inv_kine(front_right,right,7,leg);
			inv_kine(middle_left,left,7,leg);
			inv_kine(middle_right,right,7,leg);
			inv_kine(rear_left,left,7,leg);
			inv_kine(rear_right,right,7,leg);
			delay_ms(13);
			right-=2;
			left+=2;
		}
		delay_ms(50);

		Get_IR();
//		if( (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) &&
//			(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
//			(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)
//		  )
		if(
			(
					((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_LEFT]==IR_DETECTED)) ||
					((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
			)&&
			(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
			(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)&&
			(FlameSense[0]==3)
		  )
		{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}

		Get_IR();
		if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
		{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}


		while(right<=90&&left>=90&&(OVERRIDE==0))
		{
			Get_IR();
			if( (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) &&
				(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
				(INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED)&&
				(FlameSense[0]==3)
			  )
			{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}

			Get_IR();
			if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
			{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}


			inv_kine(front_left,left,7,leg);
			inv_kine(front_right,right,7,leg);
			inv_kine(middle_left,left,7,leg);
			inv_kine(middle_right,right,7,leg);
			inv_kine(rear_left,left,7,leg);
			inv_kine(rear_right,right,7,leg);
			delay_ms(13);
			right+=2;
			left-=2;
		}
		delay_ms(50);

		Get_IR();
//		if( (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) &&
//			(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
//			(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)
//		  )
		if(
			(
					((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_LEFT]==IR_DETECTED)) ||
					((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
			)&&
			(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
			(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)&&
			(FlameSense[0]==3)
		  )
		{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}

		Get_IR();
		if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
		{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}


		while(right<=170&&left>=10&&(OVERRIDE==0))
		{
			if(
				(
						((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_LEFT]==IR_DETECTED)) ||
						((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
				)&&
				(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
				(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)&&
				(FlameSense[0]==3)
			  )
			{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}

			Get_IR();
			if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
			{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}

			inv_kine(front_left,left,7,leg);
			inv_kine(front_right,right,7,leg);
			inv_kine(middle_left,left,7,leg);
			inv_kine(middle_right,right,7,leg);
			inv_kine(rear_left,left,7,leg);
			inv_kine(rear_right,right,7,leg);
			delay_ms(13);
			right+=2;
			left-=2;
		}
		delay_ms(50);

		Get_IR();
//		if( (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) &&
//			(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
//			(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)
//		  )
		if(
			(
					((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_LEFT]==IR_DETECTED)) ||
					((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
			)&&
			(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
			(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)&&
			(FlameSense[0]==3)
		  )
		{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}

		Get_IR();
		if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
		{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}


		while(right>=90&&left<=90&&(OVERRIDE==0))
		{
			Get_IR();
//			if( (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) &&
//				(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
//				(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)
//			  )
			if(
				(
						((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_LEFT]==IR_DETECTED)) ||
						((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
				)&&
				(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
				(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)&&
				(FlameSense[0]==3)
			  )
			{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}

			Get_IR();
			if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
			{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}


			inv_kine(front_left,left,7,leg);
			inv_kine(front_right,right,7,leg);
			inv_kine(middle_left,left,7,leg);
			inv_kine(middle_right,right,7,leg);
			inv_kine(rear_left,left,7,leg);
			inv_kine(rear_right,right,7,leg);
			delay_ms(13);
			right-=2;
			left+=2;
		}
		delay_ms(50);
		Get_IR();
//		if( (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) &&
//			(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
//			(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)
//		  )
		if(
			(
					((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_LEFT]==IR_DETECTED)) ||
					((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
			)&&
			(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
			(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)&&
			(FlameSense[0]==3)
		  )
		{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}

		Get_IR();
		if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
		{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;break;}


		OVERRIDE=1;
	}


//	while(1)
//	{
//		BW_Buzz(3);
//		lcd_display_clear();
//		lcd_gotoxy(0,0);sprintf(lcd,"CANDLE FOUND");lcd_putstr(lcd);
//		delay_ms(100);
//	}

}


void FollowCandle (void)
{
	int counter=0;
	FlameSense_PID_Init();

	UV_Lock=UVLOCK_ACTIVE;

	FlameTracking_New();

	for(counter=1;counter<=3;counter++)
	{
		FlameApproach();
		Get_IR();
		if( (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) &&
			(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
			(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)
		  )
		{
//			if(FlameSense[0]!=3)
//			{
//				FollowCandle();
//			}
//			else
//			{
//				{BW_Buzz(2);CANDLE_STAT=1;break;}
//			}
			if(FlameSense[0]==3)
			{
				{BW_Buzz(2);CANDLE_STAT=1;break;}
			}
		}

	}

	BW_CandleScan();

//	if(CANDLE_STAT==1)
//	{
//		while(1)
//		{
//			BW_Buzz(3);
//			lcd_display_clear();
//			lcd_gotoxy(0,0);sprintf(lcd,"CANDLE FOUND");lcd_putstr(lcd);
//			delay_ms(100);
//		}
//
//	}
}

void CandleScan2(void)
{
	int OVERRIDE=0;
	generate_movement_data(0,0,10);
	delay_ms(50);
	while(OVERRIDE==0)
	{
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		Get_IR();
		if( (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) &&
			(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
			(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)
		  )
		{BW_Buzz(2);OVERRIDE=1;break;}
	}

	while(1)
	{
		BW_Buzz(3);
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"CANDLE FOUND");lcd_putstr(lcd);
		delay_ms(100);
	}
}


void BW_FlameDemo(void)
{
	UV_Lock=1;
	while(UV_Lock==UVLOCK_ACTIVE)
	{
		BW_Buzz(2);
		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
		delay_ms(100);
		FlameTracking_New();

		BW_Buzz(2);
		FollowCandle();

		BW_Buzz(2);
		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
		delay_ms(100);
		FlameTracking_New();

		BW_Buzz(2);
		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"FLAME SCANNING");lcd_putstr(lcd);
		delay_ms(100);

		BW_FlameScanning();

		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) break;

		mov_rot_left(FAST_LEVEL_3,CLOSE);
		BW_FlameScanning();

		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) break;

		mov_rot_right(FAST_LEVEL_3,CLOSE);
		mov_rot_right(FAST_LEVEL_3,CLOSE);
		BW_FlameScanning();
	}

	mov_celebrate();

}

/* func      : int FireFight_FrontDetector(void)
 * brief     : Detect Wall or furniture in BW_FireFight Algorithm
 * param     : N/A
 * retval    : integer
 * 				1 -> Wall Detected
 * 				0 -> Wall not Detected
 * Ver       : 1
 * written By: Ryan (Saturday, April 23rd 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
int FireFight_FrontDetector(void)
{
	Get_IR();
//	if( (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) && (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_LEFT]==IR_DETECTED))
	if( (INFRARED[IR_FRONT_LEFT]==IR_DETECTED)  && (INFRARED[IR_FRONT_LEFT]==IR_DETECTED))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/* func      : int FireFight_FlameDetector(int MODE)
 * brief     : Detect Wall or furniture in BW_FireFight Algorithm
 * param     : int MODE
 * 					1 -> Candle Absence Detector
 * 					2 -> Candle Presence Detector
 *
 * retval    : integer
 * 				1 -> ACTIVE
 * 				0 -> INACTIVE
 * Ver       : 1
 * written By: Ryan (Saturday, April 23rd 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
int FireFight_FlameDetector(int MODE)
{

	switch(MODE)
	{
		case 1:
				{
//					if((FlameSense[0]==2) || (FlameSense[0]==3) || (FlameSense[0]==4))
//					if((FlameSense[0]==3) || (FlameSense[0]==4))
					if((FlameSense[0]==3))
//					if( (FlameSense[0]==3) )
					{
						return 1; break;
					}
					else
					{
						return 0; break;
					}
				}break;

		case 2:
				{
//					if((FlameSense[0]!=2) && (FlameSense[0]!=3) && (FlameSense[0]!=4))
//					if((FlameSense[0]!=3) && (FlameSense[0]!=4))
					if((FlameSense[0]!=3))
//					if( (FlameSense[0]!=3) )
					{
						return 1;break;
					}
					else
					{
						return 0; break;
					}
				}break;
	}


}

void FireFight_CandleStickDetector(void)
{
	int CANDLE=0;

//	FlameApproach();
	Get_IR();
	GetFlame();

	if(FLAME_SENSOR[FLM_ANALOG]>=200)
	{
		CANDLE=1;
	}

	if (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED)
	{
		CANDLE=1;
	}

	if( (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
	{
		CANDLE=1;
	}

	if( (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_LEFT]==IR_DETECTED))
	{
		CANDLE=1;
	}

	if( (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) && (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
	{
		CANDLE=1;
	}


	if( (CANDLE==1)	&&
		(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
		(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)
	  )
	{
		CANDLE_STICK=1;
	}
}

void FireFight_CandleFireDetector(void)
{

	if(CANDLE_STICK==1)
	{
//		if ( (FlameSense[0]==2) || (FlameSense[0]==3) || (FlameSense[0]==4) ) CANDLE_FIRE=1;
		if ( (FlameSense[0]==3)  )
		{
//			GetFlame();
//			if(FLAME_SENSOR[FLM_ANALOG]<=200)
//			{
//				mov_fwd_5cm(5,FAST_LEVEL_3);
//			}
//			else
//			{
				CANDLE_FIRE=1;
//			}

		}
	}
}


/* func      : void BW_FireFight(void)
 * brief     : BW FireFighting Routines
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 23rd 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void BW_FireFight_Ver2(void)
{
	int counter;
	int PINPOINT_COUNTER;

//	int FOLLOW_DECISION;
	FlameSense_PID_Init();

	int WALL_STAT;
	int FLAME_PRESENCE;
	int FLAME_ABSENCE;

	CANDLE_STICK=0;
	CANDLE_FIRE=0;

	//FLAME IN CORNER RIGHT OR LEFT
//	if(FLAME_SIDE==FLAME_LEFT)
//	{
//			mov_fwd_5cm(25,FAST_LEVEL_3);
//
//			lcd_display_clear();
//			lcd_gotoxy(0,0);sprintf(lcd,"ROTATE LEFT");lcd_putstr(lcd);
//			delay_ms(100);
//
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//
//			FIRE_LED_BLINK_ON;
//
//	}
//	else if (FLAME_SIDE==FLAME_RIGHT)
//	{
//			mov_fwd_5cm(15,FAST_LEVEL_3);
//
//
//			lcd_display_clear();
//			lcd_gotoxy(0,0);sprintf(lcd,"ROTATE RIGHT");lcd_putstr(lcd);
//			delay_ms(100);
//
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//
//			FIRE_LED_BLINK_ON;
//	}
//	else
//	{
		FIRE_LED_BLINK_ON;


		if(Ping[PING_FRONT]>=13)
		{
			mov_fwd_5cm(5,FAST_LEVEL_3);
		}

		if(Ping[PING_FRONT]>=13)
		{
			mov_fwd_5cm(5,FAST_LEVEL_3);
		}

		if(Ping[PING_FRONT]>=13)
		{
			mov_fwd_5cm(5,FAST_LEVEL_3);
		}

		if(Ping[PING_FRONT]>=13)
		{
			mov_fwd_5cm(5,FAST_LEVEL_3);
		}

		if(Ping[PING_FRONT]<10)
		{
			mov_bwd(5,FAST_LEVEL_3);
		}


		if(Ping[PING_FRONT]<=13)
		{
			mov_rot_right(FAST_LEVEL_3,CLOSE);
			mov_rot_right(FAST_LEVEL_3,CLOSE);
			mov_rot_right(FAST_LEVEL_3,CLOSE);
			mov_rot_right(FAST_LEVEL_3,CLOSE);
		}

		BW_Buzz(1);
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
		delay_ms(100);
		FlameTracking_New();


		BW_Buzz(1);
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"BLDC FIGHT");lcd_putstr(lcd);
		delay_ms(100);
		BW_BLDC_Fight();

		UVLock_Refresh();
		if(UV_Lock==UVLOCK_ACTIVE)
		{
			BW_BLDC_Extinguish();
		}



//	}
		BW_Buzz(1);
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"CANDLE SCAN");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"EXTINGUISH");lcd_putstr(lcd);
		delay_ms(100);
		BW_CandleScanExecute();

		//FLAME APPROACH
		BW_Buzz(1);
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"FLAME APPROACH");lcd_putstr(lcd);
		delay_ms(1000);

		GetFlame();
		if( (Ping[PING_FRONT]<=15) && ((FlameSense[0]==3)) )
		{
			CANDLE_FIRE=1;
		}

		WALL_STAT= FireFight_FrontDetector();
		FLAME_ABSENCE= FireFight_FlameDetector(2);


		while(
				( (WALL_STAT==0) || (FLAME_ABSENCE==1) ) &&
				(CANDLE_FIRE==0)
			 )
		{
			for(counter=1;counter<=2;counter++)
			{
				GetFlame();
				if( (Ping[PING_FRONT]<=15) && ((FlameSense[0]==3)) )
				{
					CANDLE_FIRE=1;
				}

				FireFight_CandleStickDetector();
				FireFight_CandleFireDetector();

				if(CANDLE_FIRE==1)
				{
					break;
				}

				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW %d",counter);lcd_putstr(lcd);
				delay_ms(100);
				FlameApproach();

				GetFlame();
				if(FLAME_SENSOR[FLM_ANALOG]>=180)
				{
					CANDLE_FIRE=1;
					break;
				}

				//ITERATION BREAKER
				WALL_STAT= FireFight_FrontDetector();
				FLAME_PRESENCE= FireFight_FlameDetector(1);
				if( ( WALL_STAT==1) && ( FLAME_PRESENCE==1) )
				{
					break; //EXIT FROM ITERATION
				}

				FireFight_CandleStickDetector();
				FireFight_CandleFireDetector();
				if(CANDLE_FIRE==1)
				{
					break;
				}

				GetFlame();
				if( (Ping[PING_FRONT]<=13) && ((FLAME_SENSOR[FLM_ANALOG]>=180) && (FlameSense[0]==3)) )
				{
					CANDLE_FIRE=0;
					break;
				}

			}

			GetFlame();
			if( (Ping[PING_FRONT]<=13) && ((FLAME_SENSOR[FLM_ANALOG]>=100) && (FlameSense[0]==3)) )
			{
				CANDLE_FIRE=0;
				break;
			}

			GetFlame();
			if(FLAME_SENSOR[FLM_ANALOG]>=100)
			{
				CANDLE_FIRE=1;
				break;
			}

			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
			delay_ms(100);
			FlameTracking_New();

			BW_CandleScan();

			FireFight_CandleStickDetector();
			FireFight_CandleFireDetector();

			if(CANDLE_FIRE==1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"CANDLE DETECTED!");lcd_putstr(lcd);
				delay_ms(500);
				break;
			}

			//CONTROL VARIABLE UPDATES
			WALL_STAT= FireFight_FrontDetector();
			FLAME_ABSENCE= FireFight_FlameDetector(2);
		}

//	}

	if(CANDLE_FIRE==1)
	{
	//	while(FlameSense[0]!=0)

//		GetFlame();
//		lcd_display_clear();
//		lcd_gotoxy(0,3);sprintf(lcd,"FLAME_AN: %d",FLAME_SENSOR[FLM_ANALOG]);lcd_putstr(lcd);
//		while ((FLAME_SENSOR[FLM_ANALOG]<=130) && (Ping[PING_FRONT]>=18))
//		{
//			GetFlame();
//			lcd_display_clear();
//			lcd_gotoxy(0,3);sprintf(lcd,"FLAME_AN: %d",FLAME_SENSOR[FLM_ANALOG]);lcd_putstr(lcd);
////				mov_fwd_5cm(5,FAST_LEVEL_3);
//			FlameApproach();
//		}

		BW_Buzz(1);
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"CANDLE SCAN");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"EXTINGUISH");lcd_putstr(lcd);
		delay_ms(100);
		BW_CandleScanExecute();




		UVLock_Refresh();
		while(UV_Lock==UVLOCK_ACTIVE)
		{
			GetFlame();
			if( (FLAME_SENSOR[FLM_ANALOG]<=180) && (Ping[PING_FRONT]>=15))
			{
				mov_fwd_5cm(5,FAST_LEVEL_3);
			}

//			BW_CandleScanExecute();

//			mov_rot_left(FAST_LEVEL_3,CLOSE);
			mov_rot_left(FAST_LEVEL_3,CLOSE);

			if(Ping[PING_FRONT]<=12)
			{
				mov_bwd(5,FAST_LEVEL_3);
			}

			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
			delay_ms(100);
			FlameTracking_New();

			BW_CandleScanExecute();

//			if ( (Ping[PING_FRONT]>=25) && (Ping[PING_ASKEW_LEFT]<=18) )
//			{
//				lcd_display_clear();
//				lcd_gotoxy(3,0);sprintf(lcd,"ROTATE RIGHT");lcd_putstr(lcd);
//				delay_ms(100);
//				mov_rot_right(FAST_LEVEL_3,CLOSE);
//			}
//			else if ( (Ping[PING_FRONT]>=25) && (Ping[PING_ASKEW_RIGHT]<=18) )
//			{
//				lcd_display_clear();
//				lcd_gotoxy(3,0);sprintf(lcd,"ROTATE LEFT");lcd_putstr(lcd);
//				delay_ms(100);
//				mov_rot_left(FAST_LEVEL_3,CLOSE);
//			}



			//RE-CHECKING
			BW_CandleScan();
			FireFight_CandleStickDetector();
			FireFight_CandleFireDetector();
			if(CANDLE_FIRE==0)
			{
				//FLAME APPROACH
				BW_Buzz(1);
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME APPROACH");lcd_putstr(lcd);
				delay_ms(1000);

				WALL_STAT= FireFight_FrontDetector();
				FLAME_ABSENCE= FireFight_FlameDetector(2);


				while(
						( (WALL_STAT==0) || (FLAME_ABSENCE==1) ) &&
						(CANDLE_FIRE==0)
					 )
				{
					for(counter=1;counter<=2;counter++)
					{
						FireFight_CandleStickDetector();
						FireFight_CandleFireDetector();

						if(CANDLE_FIRE==1)
						{
							break;
						}

						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW %d",counter);lcd_putstr(lcd);
						delay_ms(100);
						FlameApproach();

						GetFlame();
						if(FLAME_SENSOR[FLM_ANALOG]>=100)
						{
							CANDLE_FIRE=1;
							break;
						}

						//ITERATION BREAKER
						WALL_STAT= FireFight_FrontDetector();
						FLAME_PRESENCE= FireFight_FlameDetector(1);
						if( ( WALL_STAT==1) && ( FLAME_PRESENCE==1) )
						{
							break; //EXIT FROM ITERATION
						}

						FireFight_CandleStickDetector();
						FireFight_CandleFireDetector();

						if(CANDLE_FIRE==1)
						{
							break;
						}
					}

					GetFlame();
					if(FLAME_SENSOR[FLM_ANALOG]>=100)
					{
						CANDLE_FIRE=1;
						break;
					}

					BW_CandleScan();

					FireFight_CandleStickDetector();
					FireFight_CandleFireDetector();

					if(CANDLE_FIRE==1)
					{
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"CANDLE DETECTED!");lcd_putstr(lcd);
						delay_ms(2000);
						break;
					}


					//CONTROL VARIABLE UPDATES
					WALL_STAT= FireFight_FrontDetector();
					FLAME_ABSENCE= FireFight_FlameDetector(2);
				}
			}

			if((Ping[PING_LEFT]<=7)|| (Ping[PING_RIGHT]<=7) )
			{
				BW_Buzz(1);

				Evade_Wall();

				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"EVADE WALL");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
				delay_ms(100);
				FlameTracking_New();
			}

/////////////////////////////////////////////////////////////////////////////////
			//CREATING SPACES
			if(Ping[PING_FRONT]<=15)
			{
				while(Ping[PING_FRONT]<=15)
				{
					Evade_Wall();
					mov_bwd(5,FAST_LEVEL_3);
				}
			}

//			Evade_Wall();
//			if(( (Ping[PING_LEFT]<=15) || (Ping[PING_ASKEW_LEFT]<=5) )&& (Ping[PING_RIGHT]>=20))
//			{
//				while( (Ping[PING_LEFT]<=15) || (Ping[PING_ASKEW_LEFT]<=5) )
//				{
//					mov_deflect_right(FAST,CLOSE);
//				}
//			}
//			else if(( (Ping[PING_RIGHT]<=15) || (Ping[PING_ASKEW_RIGHT]<=5) ) && (Ping[PING_LEFT]>=20))
//			{
//				while( (Ping[PING_RIGHT]<=15) || (Ping[PING_ASKEW_RIGHT]<=5) )
//				{
//					mov_deflect_left(FAST,CLOSE);
//				}
//			}
//			if(Ping[PING_FRONT]<=20)
//			{
//				while(Ping[PING_FRONT]<=20)
//				{
//					Evade_Wall();
//					mov_bwd(5,FAST_LEVEL_3);
//				}
//			}

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"EVADE WALL");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
			delay_ms(100);
			FlameTracking_New();
/////////////////////////////////////////////////////////////////////////////////


			BW_Buzz(2);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SCANNING");lcd_putstr(lcd);
			delay_ms(100);

			BW_FlameScanning();

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_INACTIVE) break;

			mov_rot_right(FAST_LEVEL_3,CLOSE);
			BW_Buzz(1);



			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
			delay_ms(100);
			FlameTracking_New();

			BW_FlameScanning();

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_INACTIVE) break;


			mov_rot_left(FAST_LEVEL_3,CLOSE);
			mov_rot_left(FAST_LEVEL_3,CLOSE);

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
			delay_ms(100);
			FlameTracking_New();

			BW_FlameScanning();

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_INACTIVE) break;


		}
	}

	else if (CANDLE_FIRE==0)
	{
		UVLock_Refresh();
		if(UV_Lock==UVLOCK_ACTIVE)
		{
//			mov_rot_left(FAST_LEVEL_3,CLOSE);

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"CORNER CANDLE");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"DETECTED!");lcd_putstr(lcd);
			delay_ms(100);

			/*
			 *  MANDATORY SEQUENCES
			 */

			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
			delay_ms(100);
			FlameTracking_New();

			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"CANDLE SCAN");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"EXTINGUISH");lcd_putstr(lcd);
			delay_ms(100);

			BW_CandleScanExecute();


			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(3,0);sprintf(lcd,"CREATE SPACES");lcd_putstr(lcd);
			delay_ms(100);
			BW_Buzz(2);


//			//CREATING SPACES BETWEEN ROBOT AND CANDLES
//			if(Ping[PING_FRONT]>20)
//			{
//				while(Ping[PING_FRONT]>20)
//				{
//					mov_fwd_5cm(5,FAST_LEVEL_3);
//				}
//
//			}
//			else if(Ping[PING_FRONT]<=17)
//			{
//				while(Ping[PING_FRONT]<=17)
//				{
//					mov_bwd(5,FAST_LEVEL_3);
//				}
//			}

/////////////////////////////////////////////////////////////////////////////////
			//CREATING SPACES
			if(Ping[PING_FRONT]<=15)
			{
				while(Ping[PING_FRONT]<=15)
				{
					Evade_Wall();
					mov_bwd(5,FAST_LEVEL_3);
				}
			}

//			Evade_Wall();
//			if(( (Ping[PING_LEFT]<=15) || (Ping[PING_ASKEW_LEFT]<=5) )&& (Ping[PING_RIGHT]>=20))
//			{
//				while( (Ping[PING_LEFT]<=15) || (Ping[PING_ASKEW_LEFT]<=5) )
//				{
//					mov_deflect_right(FAST,CLOSE);
//				}
//			}
//
//			else if(( (Ping[PING_RIGHT]<=15) || (Ping[PING_ASKEW_RIGHT]<=5) )&& (Ping[PING_LEFT]>=20))
//			{
//				while( (Ping[PING_RIGHT]<=15) || (Ping[PING_ASKEW_RIGHT]<=5) )
//				{
//					mov_deflect_left(FAST,CLOSE);
//				}
//			}
//
//			if(Ping[PING_FRONT]<=20)
//			{
//				while(Ping[PING_FRONT]<=20)
//				{
//					Evade_Wall();
//					mov_bwd(5,FAST_LEVEL_3);
//				}
//			}

			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"EVADE WALL");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
			delay_ms(100);
			FlameTracking_New();
/////////////////////////////////////////////////////////////////////////////////

		}




	//	while(FlameSense[0]!=0)
		while(UV_Lock==UVLOCK_ACTIVE)
		{

			//CREATING SPACES
			if(Ping[PING_FRONT]<=15)
			{
				while(Ping[PING_FRONT]<=15)
				{
					Evade_Wall();
					mov_bwd(5,FAST_LEVEL_3);
				}
			}

			Evade_Wall();
			if(( (Ping[PING_LEFT]<=15) || (Ping[PING_ASKEW_LEFT]<=5) )&& (Ping[PING_RIGHT]>=25))
//			if(( (Ping[PING_LEFT]<=15) || (SHARP[SHARP_LEFT]<=5) )&& (Ping[PING_RIGHT]>=25))
			{
				while( (Ping[PING_LEFT]<=15) || (Ping[PING_ASKEW_LEFT]<=5) )
//				while( (Ping[PING_LEFT]<=15) || (SHARP[SHARP_LEFT]<=5) )
				{
					mov_deflect_right(FAST,CLOSE);
				}
			}

			else if(( (Ping[PING_RIGHT]<=15) || (Ping[PING_ASKEW_RIGHT]<=5) )&& (Ping[PING_LEFT]>=25))
//			else if(( (Ping[PING_RIGHT]<=15) || (SHARP[SHARP_RIGHT]<=5) )&& (Ping[PING_LEFT]>=25))
			{
				while( (Ping[PING_RIGHT]<=15) || (Ping[PING_ASKEW_RIGHT]<=5) )
//				while( (Ping[PING_RIGHT]<=15) || (SHARP[SHARP_RIGHT]<=5) )
				{
					mov_deflect_left(FAST,CLOSE);
				}
			}

			if(Ping[PING_FRONT]<=15)
			{
				while(Ping[PING_FRONT]<=15)
				{
					Evade_Wall();
					mov_bwd(5,FAST_LEVEL_3);
				}
			}

			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
			delay_ms(100);
			BW_Buzz(2);
			FlameTracking_New();

			//CREATING SPACES BETWEEN ROBOT AND CANDLES
			if(Ping[PING_FRONT]>15)
			{
				while(Ping[PING_FRONT]>15)
				{
					mov_fwd_5cm(5,FAST_LEVEL_3);
				}

			}
			else if(Ping[PING_FRONT]<=15)
			{
				while(Ping[PING_FRONT]<=15)
				{
					mov_bwd(5,FAST_LEVEL_3);
				}
			}

			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SCANNING");lcd_putstr(lcd);
			delay_ms(100);

			BW_FlameScanning();

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_INACTIVE) break;

//			BW_Buzz(1);
//			lcd_display_clear();
//			lcd_gotoxy(3,0);sprintf(lcd,"FLAME SCANNING 2");lcd_putstr(lcd);
//			delay_ms(100);
//
//			if(FlameSense[0]>3)
//			{
//				mov_rot_right(FAST_LEVEL_3,CLOSE);
//				mov_rot_right(FAST_LEVEL_3,CLOSE);
//			}
////			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			BW_FlameScanning();
//
//			UVLock_Refresh();
//			if(UV_Lock==UVLOCK_INACTIVE) break;
//
//			BW_Buzz(1);
//			lcd_display_clear();
//			lcd_gotoxy(3,0);sprintf(lcd,"FLAME SCANNING 2");lcd_putstr(lcd);
//			delay_ms(100);
//
//			if(FlameSense[0]<3)
//			{
////				while(FlameSense[0]!=3)
//				mov_rot_left(FAST_LEVEL_3,CLOSE);
//				mov_rot_left(FAST_LEVEL_3,CLOSE);
//			}
//
////			mov_rot_right(FAST_LEVEL_3,CLOSE);
////			mov_rot_right(FAST_LEVEL_3,CLOSE);
//			BW_FlameScanning();
//
//			UVLock_Refresh();
//			if(UV_Lock==UVLOCK_INACTIVE) break;

			//FLAME APPROACH
			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAMETRACKING");lcd_putstr(lcd);
			delay_ms(100);
			BW_Buzz(2);
			FlameTracking_New();

			BW_Buzz(5);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME APPROACH");lcd_putstr(lcd);
			delay_ms(1000);

			WALL_STAT= FireFight_FrontDetector();
			FLAME_ABSENCE= FireFight_FlameDetector(2);


			while(
					( WALL_STAT==0) ||
					( FLAME_ABSENCE==1)
				 )
			{
				for(counter=1;counter<=2;counter++)
				{
					FireFight_CandleStickDetector();
					FireFight_CandleFireDetector();

					if(CANDLE_FIRE==1)
					{
						break;
					}

					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW %d",counter);lcd_putstr(lcd);
					delay_ms(100);
					FlameApproach();

					//ITERATION BREAKER
					WALL_STAT= FireFight_FrontDetector();
					FLAME_PRESENCE= FireFight_FlameDetector(1);
					if( ( WALL_STAT==1) && ( FLAME_PRESENCE==1) )
					{
						break; //EXIT FROM ITERATION
					}

					FireFight_CandleStickDetector();
					FireFight_CandleFireDetector();

					if(CANDLE_FIRE==1)
					{
						break;
					}


				}


				BW_CandleScan();

				FireFight_CandleStickDetector();
				FireFight_CandleFireDetector();

				if(CANDLE_FIRE==1)
				{
					break;
				}


				//CONTROL VARIABLE UPDATES
				WALL_STAT= FireFight_FrontDetector();
				FLAME_ABSENCE= FireFight_FlameDetector(2);
			}


		}

	}


	EXTINGUISHER_OFF;
	EXTINGUISHED_FIRE=1;

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(2,1);sprintf(lcd,"FIREFIGHTING");lcd_putstr(lcd);
	lcd_gotoxy(3,2);sprintf(lcd,"SUCCESS!!!");lcd_putstr(lcd);
	delay_ms(100);

}




/* func      : void BW_FireFight(void)
 * brief     : BW FireFighting Routines
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 23rd 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void BW_FireFight_Ver3(void)
{
	int counter=0;

//	int FOLLOW_DECISION;
	FlameSense_PID_Init();


	CANDLE_STICK=0;
	CANDLE_FIRE=0;

	mov_fwd_5cm(20,FAST_LEVEL_3);

	FIRE_LED_BLINK_ON;

	BW_Buzz(1);
	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
	delay_ms(100);
	FlameTracking_New();

	//FLAME APPROACH
	BW_Buzz(1);
	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"FLAME APPROACH");lcd_putstr(lcd);
	delay_ms(1000);

	GetFlame();
	while(
			(FLAME_SENSOR[FLM_ANALOG]<=150)
		 )
	{
		counter++;

		GetFlame();
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW %d",counter);lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"FLAME_AN: %d",FLAME_SENSOR[FLM_ANALOG]);lcd_putstr(lcd);
		delay_ms(100);
		FlameApproach();
	}

		BW_Buzz(1);
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
		delay_ms(100);
		FlameTracking_New();


		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"CANDLE DETECTED!");lcd_putstr(lcd);
		delay_ms(500);

		UVLock_Refresh();
		while(UV_Lock==UVLOCK_ACTIVE)
		{
			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
			delay_ms(100);
			FlameTracking_New();

			if ( (Ping[PING_FRONT]>=20) && (Ping[PING_ASKEW_LEFT]<=13) )
//			if ( (Ping[PING_FRONT]>=25) && (SHARP[SHARP_LEFT]<=13) )
			{
				lcd_display_clear();
				lcd_gotoxy(3,0);sprintf(lcd,"ROTATE RIGHT");lcd_putstr(lcd);
				delay_ms(100);
				mov_rot_right(FAST_LEVEL_3,CLOSE);
			}
			else if ( (Ping[PING_FRONT]>=20) && (Ping[PING_ASKEW_RIGHT]<=13) )
//			else if ( (Ping[PING_FRONT]>=25) && (SHARP[SHARP_RIGHT]<=13) )
			{
				lcd_display_clear();
				lcd_gotoxy(3,0);sprintf(lcd,"ROTATE LEFT");lcd_putstr(lcd);
				delay_ms(100);
				mov_rot_left(FAST_LEVEL_3,CLOSE);
			}

			GetFlame();
			lcd_display_clear();
			lcd_gotoxy(0,3);sprintf(lcd,"FLAME_AN: %d",FLAME_SENSOR[FLM_ANALOG]);lcd_putstr(lcd);
			while ( (FLAME_SENSOR[FLM_ANALOG]<=150) && (Ping[PING_FRONT]>=15) )
			{
				BW_Buzz(1);
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
				delay_ms(100);
				FlameTracking_New();

				GetFlame();
				if(FLAME_SENSOR[FLM_ANALOG]>150) break;
				lcd_display_clear();
				lcd_gotoxy(0,3);sprintf(lcd,"FLAME_AN: %d",FLAME_SENSOR[FLM_ANALOG]);lcd_putstr(lcd);
				mov_fwd_5cm(5,FAST_LEVEL_3);
			}

			BW_Buzz(2);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SCANNING");lcd_putstr(lcd);
			delay_ms(100);

			BW_FlameScanning();

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_INACTIVE) break;

			mov_rot_left(FAST_LEVEL_3,CLOSE);
			BW_FlameScanning();

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_INACTIVE) break;

			mov_rot_right(FAST_LEVEL_3,CLOSE);
			mov_rot_right(FAST_LEVEL_3,CLOSE);
			BW_FlameScanning();

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_INACTIVE) break;

		}

	EXTINGUISHER_OFF;
	EXTINGUISHED_FIRE=1;

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(2,1);sprintf(lcd,"FIREFIGHTING");lcd_putstr(lcd);
	lcd_gotoxy(3,2);sprintf(lcd,"SUCCESS!!!");lcd_putstr(lcd);
	delay_ms(100);

}


void BW_CandleScanExecute(void)
{
		static int right=90,left=90;
		int OVERRIDE=0;
		generate_movement_data(0,0,10);
		delay_ms(50);


		while(OVERRIDE==0)
		{
			Get_IR();
			GetFlame();
			if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
//			if( ((FLAME_SENSOR[FLM_ANALOG]>=170))&&(FlameSense[0]==3))
			{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;EXTINGUISHER_ON;delay_ms(5000);EXTINGUISHER_OFF;break;}

			while(right>=10&&left<=170 &&(OVERRIDE==0))
			{
				Get_IR();
				if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
//				if( ((FLAME_SENSOR[FLM_ANALOG]>=170))&&(FlameSense[0]==3))
				{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;EXTINGUISHER_ON;delay_ms(5000);EXTINGUISHER_OFF;break;}

				inv_kine(front_left,left,7,leg);
				inv_kine(front_right,right,7,leg);
				inv_kine(middle_left,left,7,leg);
				inv_kine(middle_right,right,7,leg);
				inv_kine(rear_left,left,7,leg);
				inv_kine(rear_right,right,7,leg);
				delay_ms(13);
				right-=2;
				left+=2;
			}
			delay_ms(50);

			Get_IR();
			if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
//			if( ((FLAME_SENSOR[FLM_ANALOG]>=170))&&(FlameSense[0]==3))
			{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;EXTINGUISHER_ON;delay_ms(5000);EXTINGUISHER_OFF;break;}


			while(right<=90&&left>=90&&(OVERRIDE==0))
			{
				Get_IR();
				if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
//				if( ((FLAME_SENSOR[FLM_ANALOG]>=170))&&(FlameSense[0]==3))
				{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;EXTINGUISHER_ON;delay_ms(5000);EXTINGUISHER_OFF;break;}

				inv_kine(front_left,left,7,leg);
				inv_kine(front_right,right,7,leg);
				inv_kine(middle_left,left,7,leg);
				inv_kine(middle_right,right,7,leg);
				inv_kine(rear_left,left,7,leg);
				inv_kine(rear_right,right,7,leg);
				delay_ms(13);
				right+=2;
				left-=2;
			}
			delay_ms(50);

			Get_IR();
			if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
//			if( ((FLAME_SENSOR[FLM_ANALOG]>=170))&&(FlameSense[0]==3))
			{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;EXTINGUISHER_ON;delay_ms(5000);EXTINGUISHER_OFF;break;}


			while(right<=170&&left>=10&&(OVERRIDE==0))
			{
				Get_IR();
				if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
//				if( ((FLAME_SENSOR[FLM_ANALOG]>=170))&&(FlameSense[0]==3))
				{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;EXTINGUISHER_ON;delay_ms(5000);EXTINGUISHER_OFF;break;}

				inv_kine(front_left,left,7,leg);
				inv_kine(front_right,right,7,leg);
				inv_kine(middle_left,left,7,leg);
				inv_kine(middle_right,right,7,leg);
				inv_kine(rear_left,left,7,leg);
				inv_kine(rear_right,right,7,leg);
				delay_ms(13);
				right+=2;
				left-=2;
			}
			delay_ms(50);

			Get_IR();
			if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
//			if( ((FLAME_SENSOR[FLM_ANALOG]>=170))&&(FlameSense[0]==3))
			{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;EXTINGUISHER_ON;delay_ms(5000);EXTINGUISHER_OFF;break;}

			while(right>=90&&left<=90&&(OVERRIDE==0))
			{
				Get_IR();
				if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
//				if( ((FLAME_SENSOR[FLM_ANALOG]>=170))&&(FlameSense[0]==3))
				{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;EXTINGUISHER_ON;delay_ms(5000);EXTINGUISHER_OFF;break;}

				inv_kine(front_left,left,7,leg);
				inv_kine(front_right,right,7,leg);
				inv_kine(middle_left,left,7,leg);
				inv_kine(middle_right,right,7,leg);
				inv_kine(rear_left,left,7,leg);
				inv_kine(rear_right,right,7,leg);
				delay_ms(13);
				right-=2;
				left+=2;
			}
			delay_ms(50);

			Get_IR();
			if( ((INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (FLAME_SENSOR[FLM_ANALOG]>=150))&&(FlameSense[0]==3))
//			if( ((FLAME_SENSOR[FLM_ANALOG]>=170))&&(FlameSense[0]==3))
			{BW_Buzz(2);OVERRIDE=1;CANDLE_FIRE=1;EXTINGUISHER_ON;delay_ms(5000);EXTINGUISHER_OFF;break;}

			OVERRIDE=1;
		}
}


void BW_FlameFollowDemo(void)
{
	int counter;
	int PINPOINT_COUNTER;

//	FlameSense_PID_Init();
	FlameSenseDigi_PID_Init();

	int WALL_STAT;
	int FLAME_PRESENCE;
	int FLAME_ABSENCE;

	Get_UV();

	while(UV_state==UVSTATE_INACTIVE)
	{
		Get_UV();
		mov_static();
	}
		CANDLE_STICK=0;
		CANDLE_FIRE=0;
		FIRE_LED_BLINK_ON;

		BW_Buzz(1);
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
		delay_ms(100);
		FlameTracking_Ver3();

		UVLock_Refresh();
		if(UV_Lock==UVLOCK_ACTIVE)
		{
			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"BLDC FIGHT");lcd_putstr(lcd);
			delay_ms(100);
			BW_BLDC_Fight();
		}





		UVLock_Refresh();
		if(UV_Lock==UVLOCK_ACTIVE)
		{
			BW_BLDC_Extinguish();

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_ACTIVE)
			{
				//FLAME APPROACH
				BW_Buzz(1);
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME APPROACH");lcd_putstr(lcd);
				delay_ms(1000);

				GetFlame();
				if( (Ping[PING_FRONT]<=15) && ((FlameSense[0]==3)) )
				{
					CANDLE_FIRE=1;
				}

				WALL_STAT= FireFight_FrontDetector();
				FLAME_ABSENCE= FireFight_FlameDetector(2);


				while(
						( (WALL_STAT==0) || (FLAME_ABSENCE==1) ) &&
						(CANDLE_FIRE==0)
					 )
				{
					for(counter=1;counter<=2;counter++)
					{
						GetFlame();
						if( (Ping[PING_FRONT]<=15) && ((FlameSense[0]==3)) )
						{
							CANDLE_FIRE=1;
						}

						FireFight_CandleStickDetector();
						FireFight_CandleFireDetector();

						if(CANDLE_FIRE==1)
						{
							break;
						}

						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW %d",counter);lcd_putstr(lcd);
						delay_ms(100);
						FlameApproach();

						GetFlame();
						if(FLAME_SENSOR[FLM_ANALOG]>=180)
						{
							CANDLE_FIRE=1;
							break;
						}

						//ITERATION BREAKER
						WALL_STAT= FireFight_FrontDetector();
						FLAME_PRESENCE= FireFight_FlameDetector(1);
						if( ( WALL_STAT==1) && ( FLAME_PRESENCE==1) )
						{
							break; //EXIT FROM ITERATION
						}

						FireFight_CandleStickDetector();
						FireFight_CandleFireDetector();
						if(CANDLE_FIRE==1)
						{
							break;
						}

						GetFlame();
						if( (Ping[PING_FRONT]<=13) && ((FLAME_SENSOR[FLM_ANALOG]>=180) && (FlameSense[0]==3)) )
						{
							CANDLE_FIRE=0;
							break;
						}

					}

					GetFlame();
					if( (Ping[PING_FRONT]<=13) && ((FLAME_SENSOR[FLM_ANALOG]>=100) && (FlameSense[0]==3)) )
					{
						CANDLE_FIRE=0;
						break;
					}

					GetFlame();
					if(FLAME_SENSOR[FLM_ANALOG]>=100)
					{
						CANDLE_FIRE=1;
						break;
					}



					BW_Buzz(1);
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
					delay_ms(100);
//-------
					FlameTracking_New();

					BW_CandleScan();

					FireFight_CandleStickDetector();
					FireFight_CandleFireDetector();

					if(CANDLE_FIRE==1)
					{
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"CANDLE DETECTED!");lcd_putstr(lcd);
						delay_ms(500);
						break;
					}

					//CONTROL VARIABLE UPDATES
					WALL_STAT= FireFight_FrontDetector();
					FLAME_ABSENCE= FireFight_FlameDetector(2);
				}
			}



		}


	if(CANDLE_FIRE==1)
	{

		BW_Buzz(1);
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"BLDC FIGHT");lcd_putstr(lcd);
		delay_ms(100);
		BW_BLDC_Fight();
		BW_BLDC_Extinguish();


		UVLock_Refresh();
		while(UV_Lock==UVLOCK_ACTIVE)
		{
			GetFlame();
			if( (FLAME_SENSOR[FLM_ANALOG]<=180) && (Ping[PING_FRONT]>=15))
			{
//				mov_fwd_5cm(5,FAST_LEVEL_3);
				mov_fwd_5cm(5,FAST_LEVEL_3);
			}

//			mov_rot_left(FAST_LEVEL_3,CLOSE);
			mov_rot_left(FAST_LEVEL_3,CLOSE);

			if(Ping[PING_FRONT]<=12)
			{
//				mov_bwd(5,FAST_LEVEL_3);
				mov_bwd_3cm(3,FAST_LEVEL_3);
			}

			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
			delay_ms(100);
			FlameTracking_New();

			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"BLDC FIGHT");lcd_putstr(lcd);
			delay_ms(100);
			BW_BLDC_Fight();
			BW_BLDC_Extinguish();


			//RE-CHECKING
			BW_CandleScan();
			FireFight_CandleStickDetector();
			FireFight_CandleFireDetector();
			if(CANDLE_FIRE==0)
			{
				//FLAME APPROACH
				BW_Buzz(1);
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME APPROACH");lcd_putstr(lcd);
				delay_ms(1000);

				WALL_STAT= FireFight_FrontDetector();
				FLAME_ABSENCE= FireFight_FlameDetector(2);


				while(
						( (WALL_STAT==0) || (FLAME_ABSENCE==1) ) &&
						(CANDLE_FIRE==0)
					 )
				{
					for(counter=1;counter<=2;counter++)
					{
						FireFight_CandleStickDetector();
						FireFight_CandleFireDetector();

						if(CANDLE_FIRE==1)
						{
							break;
						}

						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW %d",counter);lcd_putstr(lcd);
						delay_ms(100);
						FlameApproach();

						GetFlame();
						if(FLAME_SENSOR[FLM_ANALOG]>=100)
						{
							CANDLE_FIRE=1;
							break;
						}

						//ITERATION BREAKER
						WALL_STAT= FireFight_FrontDetector();
						FLAME_PRESENCE= FireFight_FlameDetector(1);
						if( ( WALL_STAT==1) && ( FLAME_PRESENCE==1) )
						{
							break; //EXIT FROM ITERATION
						}

						FireFight_CandleStickDetector();
						FireFight_CandleFireDetector();

						if(CANDLE_FIRE==1)
						{
							break;
						}
					}

					GetFlame();
					if(FLAME_SENSOR[FLM_ANALOG]>=100)
					{
						CANDLE_FIRE=1;
						break;
					}

					BW_CandleScan();

					FireFight_CandleStickDetector();
					FireFight_CandleFireDetector();

					if(CANDLE_FIRE==1)
					{
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"CANDLE DETECTED!");lcd_putstr(lcd);
						delay_ms(2000);
						break;
					}


					//CONTROL VARIABLE UPDATES
					WALL_STAT= FireFight_FrontDetector();
					FLAME_ABSENCE= FireFight_FlameDetector(2);
				}
			}

			if((Ping[PING_LEFT]<=7)|| (Ping[PING_RIGHT]<=7) )
			{
				BW_Buzz(1);

				Evade_Wall();

				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"EVADE WALL");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
				delay_ms(100);
				FlameTracking_New();
			}

/////////////////////////////////////////////////////////////////////////////////
			//CREATING SPACES
			if(Ping[PING_FRONT]<=15)
			{
				while(Ping[PING_FRONT]<=15)
				{
					Evade_Wall();
//					mov_bwd(5,FAST_LEVEL_3);
					mov_bwd_3cm(3,FAST_LEVEL_3);
				}
			}

//			Evade_Wall();
//			if(( (Ping[PING_LEFT]<=15) || (Ping[PING_ASKEW_LEFT]<=5) )&& (Ping[PING_RIGHT]>=20))
//			{
//				while( (Ping[PING_LEFT]<=15) || (Ping[PING_ASKEW_LEFT]<=5) )
//				{
//					mov_deflect_right(FAST,CLOSE);
//				}
//			}
//			else if(( (Ping[PING_RIGHT]<=15) || (Ping[PING_ASKEW_RIGHT]<=5) ) && (Ping[PING_LEFT]>=20))
//			{
//				while( (Ping[PING_RIGHT]<=15) || (Ping[PING_ASKEW_RIGHT]<=5) )
//				{
//					mov_deflect_left(FAST,CLOSE);
//				}
//			}
//			if(Ping[PING_FRONT]<=20)
//			{
//				while(Ping[PING_FRONT]<=20)
//				{
//					Evade_Wall();
//					mov_bwd(5,FAST_LEVEL_3);
//				}
//			}

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"EVADE WALL");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
			delay_ms(100);
			FlameTracking_New();
/////////////////////////////////////////////////////////////////////////////////


			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"BLDC FIGHT");lcd_putstr(lcd);
			delay_ms(100);
			BW_BLDC_Fight();
			BW_BLDC_Extinguish();

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_INACTIVE) break;

//			mov_rot_right(FAST_LEVEL_3,CLOSE);
			mov_rot_right(FAST_LEVEL_3,CLOSE);

			BW_Buzz(1);

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
			delay_ms(100);
			FlameTracking_New();

			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"BLDC FIGHT");lcd_putstr(lcd);
			delay_ms(100);
			BW_BLDC_Fight();
			BW_BLDC_Extinguish();

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_INACTIVE) break;


//			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
			mov_rot_left(FAST_LEVEL_3,CLOSE);
			mov_rot_left(FAST_LEVEL_3,CLOSE);

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
			delay_ms(100);
			FlameTracking_New();

			BW_FlameScanning();

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_INACTIVE) break;


		}
	}

	else if (CANDLE_FIRE==0)
	{
		UVLock_Refresh();
		if(UV_Lock==UVLOCK_ACTIVE)
		{
//			mov_rot_left(FAST_LEVEL_3,CLOSE);

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"CORNER CANDLE");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"DETECTED!");lcd_putstr(lcd);
			delay_ms(100);

			/*
			 *  MANDATORY SEQUENCES
			 */

			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
			delay_ms(100);
			FlameTracking_New();

			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"BLDC FIGHT");lcd_putstr(lcd);
			delay_ms(100);
			BW_BLDC_Fight();
			BW_BLDC_Extinguish();


			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(3,0);sprintf(lcd,"CREATE SPACES");lcd_putstr(lcd);
			delay_ms(100);
			BW_Buzz(2);

/////////////////////////////////////////////////////////////////////////////////
			//CREATING SPACES
			if(Ping[PING_FRONT]<=15)
			{
				while(Ping[PING_FRONT]<=15)
				{
					Evade_Wall();
//					mov_bwd(5,FAST_LEVEL_3);
					mov_bwd_3cm(3,FAST_LEVEL_3);
				}
			}

//			Evade_Wall();
//			if(( (Ping[PING_LEFT]<=15) || (Ping[PING_ASKEW_LEFT]<=5) )&& (Ping[PING_RIGHT]>=20))
//			{
//				while( (Ping[PING_LEFT]<=15) || (Ping[PING_ASKEW_LEFT]<=5) )
//				{
//					mov_deflect_right(FAST,CLOSE);
//				}
//			}
//
//			else if(( (Ping[PING_RIGHT]<=15) || (Ping[PING_ASKEW_RIGHT]<=5) )&& (Ping[PING_LEFT]>=20))
//			{
//				while( (Ping[PING_RIGHT]<=15) || (Ping[PING_ASKEW_RIGHT]<=5) )
//				{
//					mov_deflect_left(FAST,CLOSE);
//				}
//			}
//
//			if(Ping[PING_FRONT]<=20)
//			{
//				while(Ping[PING_FRONT]<=20)
//				{
//					Evade_Wall();
//					mov_bwd(5,FAST_LEVEL_3);
//				}
//			}

			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"EVADE WALL");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
			delay_ms(100);
			FlameTracking_New();
/////////////////////////////////////////////////////////////////////////////////

		}




	//	while(FlameSense[0]!=0)
		while(UV_Lock==UVLOCK_ACTIVE)
		{

			//CREATING SPACES
			if(Ping[PING_FRONT]<=15)
			{
				while(Ping[PING_FRONT]<=15)
				{
					Evade_Wall();
//					mov_bwd(5,FAST_LEVEL_3);
					mov_bwd_3cm(3,FAST_LEVEL_3);
				}
			}

			Evade_Wall();
//			if(( (Ping[PING_LEFT]<=15) || (Ping[PING_ASKEW_LEFT]<=5) )&& (Ping[PING_RIGHT]>=25))
//			{
//				while( (Ping[PING_LEFT]<=15) || (Ping[PING_ASKEW_LEFT]<=5) )
//				{
//					mov_deflect_right(FAST,CLOSE);
//				}
//			}
//			else if(( (Ping[PING_RIGHT]<=15) || (Ping[PING_ASKEW_RIGHT]<=5) )&& (Ping[PING_LEFT]>=25))
//			{
//				while( (Ping[PING_RIGHT]<=15) || (Ping[PING_ASKEW_RIGHT]<=5) )
//				{
//					mov_deflect_left(FAST,CLOSE);
//				}
//			}
//----------------------
//			if(( (Ping[PING_LEFT]<=15) || (SHARP[SHARP_LEFT]<=5) )&& (Ping[PING_RIGHT]>=25))
			if( (Ping[PING_LEFT]<=15) && (Ping[PING_RIGHT]>=25))
			{
//				while( (Ping[PING_LEFT]<=15) || (SHARP[SHARP_LEFT]<=5) )
				while (Ping[PING_LEFT]<=15)
				{
//					mov_deflect_right(FAST,CLOSE);
					mov_deflect_right(FAST,CLOSE);
				}
			}

//			else if(( (Ping[PING_RIGHT]<=15) || (SHARP[SHARP_RIGHT]<=5) )&& (Ping[PING_LEFT]>=25))
			else if(( (Ping[PING_RIGHT]<=15) )&& (Ping[PING_LEFT]>=25))
			{
//				while( (Ping[PING_RIGHT]<=15) || (SHARP[SHARP_RIGHT]<=5) )
				while (Ping[PING_RIGHT]<=15)
				{
//					mov_deflect_left(FAST,CLOSE);
					mov_deflect_left(FAST,CLOSE);
				}
			}

			if(Ping[PING_FRONT]<=15)
			{
				while(Ping[PING_FRONT]<=15)
				{
					Evade_Wall();
//					mov_bwd(5,FAST_LEVEL_3);
					mov_bwd_3cm(3,FAST_LEVEL_3);
				}
			}

			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
			delay_ms(100);
			BW_Buzz(2);
			FlameTracking_New();

			//CREATING SPACES BETWEEN ROBOT AND CANDLES
			if(Ping[PING_FRONT]>15)
			{
				while(Ping[PING_FRONT]>15)
				{
//					mov_fwd_5cm(5,FAST_LEVEL_3);
					mov_fwd_5cm(5,FAST_LEVEL_3);
				}

			}
			else if(Ping[PING_FRONT]<=15)
			{
				while(Ping[PING_FRONT]<=15)
				{
//					mov_bwd(5,FAST_LEVEL_3);
					mov_bwd_3cm(3,FAST_LEVEL_3);
				}
			}

			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"BLDC FIGHT");lcd_putstr(lcd);
			delay_ms(100);
			BW_BLDC_Fight();
			BW_BLDC_Extinguish();

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_INACTIVE) break;

//------------
			//FLAME APPROACH
			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAMETRACKING");lcd_putstr(lcd);
			delay_ms(100);
			BW_Buzz(2);
			FlameTracking_New();

			BW_Buzz(5);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME APPROACH");lcd_putstr(lcd);
			delay_ms(1000);

			WALL_STAT= FireFight_FrontDetector();
			FLAME_ABSENCE= FireFight_FlameDetector(2);


			while(
					( WALL_STAT==0) ||
					( FLAME_ABSENCE==1)
				 )
			{
				for(counter=1;counter<=2;counter++)
				{
					FireFight_CandleStickDetector();
					FireFight_CandleFireDetector();

					if(CANDLE_FIRE==1)
					{
						break;
					}

					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW %d",counter);lcd_putstr(lcd);
					delay_ms(100);
					FlameApproach();

					//ITERATION BREAKER
					WALL_STAT= FireFight_FrontDetector();
					FLAME_PRESENCE= FireFight_FlameDetector(1);
					if( ( WALL_STAT==1) && ( FLAME_PRESENCE==1) )
					{
						break; //EXIT FROM ITERATION
					}

					FireFight_CandleStickDetector();
					FireFight_CandleFireDetector();

					if(CANDLE_FIRE==1)
					{
						break;
					}


				}


				BW_CandleScan();

				FireFight_CandleStickDetector();
				FireFight_CandleFireDetector();

				if(CANDLE_FIRE==1)
				{
					break;
				}


				//CONTROL VARIABLE UPDATES
				WALL_STAT= FireFight_FrontDetector();
				FLAME_ABSENCE= FireFight_FlameDetector(2);
			}


		}

	}


	EXTINGUISHER_OFF;
	EXTINGUISHED_FIRE=1;

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(2,1);sprintf(lcd,"FIREFIGHTING");lcd_putstr(lcd);
	lcd_gotoxy(3,2);sprintf(lcd,"SUCCESS!!!");lcd_putstr(lcd);
	delay_ms(100);

//		BW_Buzz(1);
//		lcd_display_clear();
//		lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
//		delay_ms(100);
//		FlameTracking_New();
//
//		//FLAME APPROACH
//		BW_Buzz(1);
//		lcd_display_clear();
//		lcd_gotoxy(0,0);sprintf(lcd,"FLAME APPROACH");lcd_putstr(lcd);
//		delay_ms(1000);
//
//		WALL_STAT= FireFight_FrontDetector();
//		FLAME_ABSENCE= FireFight_FlameDetector(2);
//
//
//		while(
//				( (WALL_STAT==0) || (FLAME_ABSENCE==1) ) &&
//				(CANDLE_FIRE==0)
//			 )
//		{
//				FireFight_CandleStickDetector();
//				FireFight_CandleFireDetector();
//
//				if(CANDLE_FIRE==1)
//				{
//					break;
//				}
//
//				lcd_display_clear();
//				lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW %d",counter);lcd_putstr(lcd);
//				delay_ms(100);
//				FlameApproach();
//
//				GetFlame();
//				if(FLAME_SENSOR[FLM_ANALOG]>=200)
//				{
//					CANDLE_FIRE=1;
//					break;
//				}
//
//				//ITERATION BREAKER
//				WALL_STAT= FireFight_FrontDetector();
//				FLAME_PRESENCE= FireFight_FlameDetector(1);
//				if( ( WALL_STAT==1) && ( FLAME_PRESENCE==1) )
//				{
//					break; //EXIT FROM ITERATION
//				}
//
//				FireFight_CandleStickDetector();
//				FireFight_CandleFireDetector();
//				if(CANDLE_FIRE==1)
//				{
//					break;
//				}
//
//				GetFlame();
//				if( (Ping[PING_FRONT]<=18) && ((FLAME_SENSOR[FLM_ANALOG]>=200) && (FlameSense[0]==3)) )
//				{
//					CANDLE_FIRE=0;
//					break;
//				}
//		}
//
//		BW_Buzz(1);
//		lcd_display_clear();
//		lcd_gotoxy(0,0);sprintf(lcd,"CANDLE SCAN");lcd_putstr(lcd);
//		lcd_gotoxy(0,1);sprintf(lcd,"EXTINGUISH");lcd_putstr(lcd);
//		delay_ms(100);
//		BW_CandleScanExecute();
//
//		UVLock_Refresh();
//		while(UV_Lock==UVLOCK_ACTIVE)
//		{
//				BW_Buzz(1);
//				lcd_display_clear();
//				lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
//				delay_ms(100);
//				FlameTracking_New();
//
//				BW_Buzz(2);
//				lcd_display_clear();
//				lcd_gotoxy(0,0);sprintf(lcd,"FLAME SCANNING");lcd_putstr(lcd);
//				delay_ms(100);
//
//				BW_FlameScanning();
//
//				UVLock_Refresh();
//				if(UV_Lock==UVLOCK_INACTIVE) break;
//
//				lcd_display_clear();
//				lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
//				delay_ms(100);
//				FlameTracking_New();
//
//				BW_FlameScanning();
//
//				UVLock_Refresh();
//				if(UV_Lock==UVLOCK_INACTIVE) break;
//
//				BW_FlameScanning();
//
//				UVLock_Refresh();
//				if(UV_Lock==UVLOCK_INACTIVE) break;
//
//		}
//
//
//
//
//
//	EXTINGUISHER_OFF;
//	EXTINGUISHED_FIRE=1;
//
//	lcd_display_clear();
//	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
//	lcd_gotoxy(2,1);sprintf(lcd,"FIREFIGHTING");lcd_putstr(lcd);
//	lcd_gotoxy(3,2);sprintf(lcd,"SUCCESS!!!");lcd_putstr(lcd);
//	delay_ms(100);

	mov_celebrate();

}

void Nav_TurnAround(int ORIENTATION)
{
	switch(ORIENTATION)
	{
		case 1:
				{
					//TURN AROUND
					BW_Buzz(1);



					mov_rot_left(FAST,FAR);
					mov_rot_left(FAST,FAR);
					mov_rot_left(FAST,FAR);

				//		while ( (Ping[PING_FRONT]>=30) || (INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED) )
					while ( (Ping[PING_FRONT]>=25) )
					{
//						mov_rot_left(FAST_LEVEL_3,CLOSE);
						mov_rot_left(FAST,FAR);
						if(Ping[PING_FRONT]<=13) mov_bwd(5,FAST_LEVEL_3);
						Get_IR();
					}

					Get_IR();
				//		while ( Ping[PING_FRONT]<=30 || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
					while ( Ping[PING_FRONT]<=25 )
					{
						if(Ping[PING_FRONT]<=13) mov_bwd(5,FAST_LEVEL_3);
//						mov_rot_left(FAST_LEVEL_3,CLOSE);
						mov_rot_left(FAST,FAR);
						Get_IR();
					}

					if(Ping[PING_RIGHT]>15)
					{
						mov_deflect_right(FAST,CLOSE);
						mov_deflect_right(FAST,CLOSE);
						mov_deflect_right(FAST,CLOSE);
					}

				}break;

		case 2:
				{

					mov_rot_right(FAST,FAR);
					mov_rot_right(FAST,FAR);
					mov_rot_right(FAST,FAR);

			//		while ( (Ping[PING_FRONT]>=30) || (INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED) )
					while ( (Ping[PING_FRONT]>=25) )
					{
						mov_rot_right(FAST,FAR);
//						mov_rot_right(FAST_LEVEL_3,CLOSE);
						if(Ping[PING_FRONT]<=9) mov_bwd(5,FAST_LEVEL_3);
						Get_IR();
					}

					Get_IR();
			//		while ( Ping[PING_FRONT]<=30 || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
					while ( Ping[PING_FRONT]<=25 )
					{
						if(Ping[PING_FRONT]<=9) mov_bwd(5,FAST_LEVEL_3);
						mov_rot_right(FAST,FAR);
//						mov_rot_right(FAST_LEVEL_3,CLOSE);
						Get_IR();
					}

					if(Ping[PING_LEFT]>20)
					{
						mov_deflect_left(FAST,CLOSE);
						mov_deflect_left(FAST,CLOSE);
						mov_deflect_left(FAST,CLOSE);
					}

				}break;

	}


}



void BW_BLDC_Extinguish(void)
{
//	Sendto_PC(USART1,"BW Hexapod Search Fire Sequences \r");

	BW_Buzz(4);

	static int right=90,left=90;

	BW_Buzz(4);
	BW_BLDC_ON;
	delay_ms(2000);

	generate_movement_data(0,0,9);
	delay_ms(50);

	Get_UV();

	while(right>=50&&left<=130&&UV_state==0)
	{
		inv_kine(front_left,left,7,leg);
		inv_kine(front_right,right,7,leg);
		inv_kine(middle_left,left,7,leg);
		inv_kine(middle_right,right,7,leg);
		inv_kine(rear_left,left,7,leg);
		inv_kine(rear_right,right,7,leg);
		delay_ms(20);
		right-=5;
		left+=5;
		if(UV_state==1) break;
	}
	delay_ms(100);

	Get_UV();

	while(right<=90&&left>=90&&UV_state==0)
	{
	    inv_kine(front_left,left,7,leg);
	    inv_kine(front_right,right,7,leg);
	    inv_kine(middle_left,left,7,leg);
	    inv_kine(middle_right,right,7,leg);
	    inv_kine(rear_left,left,7,leg);
	    inv_kine(rear_right,right,7,leg);
	    delay_ms(20);
	    right+=5;
	    left-=5;
	    if(UV_state==1) break;
	}
	delay_ms(100);

	Get_UV();
	while(right<=130&&left>=50&&UV_state==0)
	{
		inv_kine(front_left,left,7,leg);
		inv_kine(front_right,right,7,leg);
		inv_kine(middle_left,left,7,leg);
		inv_kine(middle_right,right,7,leg);
		inv_kine(rear_left,left,7,leg);
		inv_kine(rear_right,right,7,leg);
		delay_ms(20);
		right+=5;
		left-=5;
		if(UV_state==1) break;
	}
	delay_ms(100);

	Get_UV();
	while(right>=90&&left<=90&&UV_state==0)
	{
		inv_kine(front_left,left,7,leg);
		inv_kine(front_right,right,7,leg);
		inv_kine(middle_left,left,7,leg);
		inv_kine(middle_right,right,7,leg);
		inv_kine(rear_left,left,7,leg);
		inv_kine(rear_right,right,7,leg);
		delay_ms(20);
		right-=5;
		left+=5;
		if(UV_state==1) break;
	}
	delay_ms(100);

	BW_BLDC_OFF;

}



/* func      : void BW_FireFight(void)
 * brief     : BW FireFighting Routines
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 23rd 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void BW_FireFight_Ver4(void)
{
	int counter;
	int PINPOINT_COUNTER;

//	int FOLLOW_DECISION;
	FlameSense_PID_Init();

	int WALL_STAT;
	int FLAME_PRESENCE;
	int FLAME_ABSENCE;

	CANDLE_STICK=0;
	CANDLE_FIRE=0;

	FIRE_LED_BLINK_ON;


	if(Ping[PING_FRONT]>=15)
		{
			mov_fwd_5cm(5,FAST_LEVEL_3);
		}

		if(Ping[PING_FRONT]>=15)
		{
			mov_fwd_5cm(5,FAST_LEVEL_3);
		}

		if(Ping[PING_FRONT]>=15)
		{
			mov_fwd_5cm(5,FAST_LEVEL_3);
		}

		if(Ping[PING_FRONT]>=15)
		{
			mov_fwd_5cm(5,FAST_LEVEL_3);
		}

		if(Ping[PING_FRONT]<15)
		{
			mov_bwd(5,FAST_LEVEL_3);
		}


		if(Ping[PING_FRONT]<=13)
		{
			mov_rot_right(FAST_LEVEL_3,CLOSE);
			mov_rot_right(FAST_LEVEL_3,CLOSE);
			mov_rot_right(FAST_LEVEL_3,CLOSE);
			mov_rot_right(FAST_LEVEL_3,CLOSE);
		}

		BW_Buzz(1);
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
		delay_ms(100);
		FlameTracking_New();


		BW_Buzz(1);
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"BLDC FIGHT");lcd_putstr(lcd);
		delay_ms(100);
		BW_BLDC_Fight();


		UVLock_Refresh();
		if(UV_Lock==UVLOCK_ACTIVE)
		{
			BW_BLDC_Extinguish();

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_ACTIVE)
			{
				//FLAME APPROACH
				BW_Buzz(1);
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME APPROACH");lcd_putstr(lcd);
				delay_ms(1000);

				GetFlame();
				if( (Ping[PING_FRONT]<=15) && ((FlameSense[0]==3)) )
				{
					CANDLE_FIRE=1;
				}

				WALL_STAT= FireFight_FrontDetector();
				FLAME_ABSENCE= FireFight_FlameDetector(2);


				while(
						( (WALL_STAT==0) || (FLAME_ABSENCE==1) ) &&
						(CANDLE_FIRE==0)
					 )
				{
					for(counter=1;counter<=2;counter++)
					{
						GetFlame();
						if( (Ping[PING_FRONT]<=15) && ((FlameSense[0]==3)) )
						{
							CANDLE_FIRE=1;
						}

						FireFight_CandleStickDetector();
						FireFight_CandleFireDetector();

						if(CANDLE_FIRE==1)
						{
							break;
						}

						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW %d",counter);lcd_putstr(lcd);
						delay_ms(100);
						FlameApproach();

						GetFlame();
						if(FLAME_SENSOR[FLM_ANALOG]>=180)
						{
							CANDLE_FIRE=1;
							break;
						}

						//ITERATION BREAKER
						WALL_STAT= FireFight_FrontDetector();
						FLAME_PRESENCE= FireFight_FlameDetector(1);
						if( ( WALL_STAT==1) && ( FLAME_PRESENCE==1) )
						{
							break; //EXIT FROM ITERATION
						}

						FireFight_CandleStickDetector();
						FireFight_CandleFireDetector();
						if(CANDLE_FIRE==1)
						{
							break;
						}

						GetFlame();
						if( (Ping[PING_FRONT]<=13) && ((FLAME_SENSOR[FLM_ANALOG]>=180) && (FlameSense[0]==3)) )
						{
							CANDLE_FIRE=0;
							break;
						}

					}

					GetFlame();
					if( (Ping[PING_FRONT]<=13) && ((FLAME_SENSOR[FLM_ANALOG]>=100) && (FlameSense[0]==3)) )
					{
						CANDLE_FIRE=0;
						break;
					}

					GetFlame();
					if(FLAME_SENSOR[FLM_ANALOG]>=100)
					{
						CANDLE_FIRE=1;
						break;
					}



					BW_Buzz(1);
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
					delay_ms(100);
					FlameTracking_New();

					BW_CandleScan();

					FireFight_CandleStickDetector();
					FireFight_CandleFireDetector();

					if(CANDLE_FIRE==1)
					{
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"CANDLE DETECTED!");lcd_putstr(lcd);
						delay_ms(500);
						break;
					}

					//CONTROL VARIABLE UPDATES
					WALL_STAT= FireFight_FrontDetector();
					FLAME_ABSENCE= FireFight_FlameDetector(2);
				}
			}



		}


	if(CANDLE_FIRE==1)
	{

		BW_Buzz(1);
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"BLDC FIGHT");lcd_putstr(lcd);
		delay_ms(100);
		BW_BLDC_Fight();
		BW_BLDC_Extinguish();


		UVLock_Refresh();
		while(UV_Lock==UVLOCK_ACTIVE)
		{
			GetFlame();
			if( (FLAME_SENSOR[FLM_ANALOG]<=180) && (Ping[PING_FRONT]>=15))
			{
				mov_fwd_5cm(5,FAST_LEVEL_3);
			}

			mov_rot_left(FAST_LEVEL_3,CLOSE);

			if(Ping[PING_FRONT]<=12)
			{
				mov_bwd(5,FAST_LEVEL_3);
			}

			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
			delay_ms(100);
			FlameTracking_New();

			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"BLDC FIGHT");lcd_putstr(lcd);
			delay_ms(100);
			BW_BLDC_Fight();
			BW_BLDC_Extinguish();


			//RE-CHECKING
			BW_CandleScan();
			FireFight_CandleStickDetector();
			FireFight_CandleFireDetector();
			if(CANDLE_FIRE==0)
			{
				//FLAME APPROACH
				BW_Buzz(1);
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME APPROACH");lcd_putstr(lcd);
				delay_ms(1000);

				WALL_STAT= FireFight_FrontDetector();
				FLAME_ABSENCE= FireFight_FlameDetector(2);


				while(
						( (WALL_STAT==0) || (FLAME_ABSENCE==1) ) &&
						(CANDLE_FIRE==0)
					 )
				{
					for(counter=1;counter<=2;counter++)
					{
						FireFight_CandleStickDetector();
						FireFight_CandleFireDetector();

						if(CANDLE_FIRE==1)
						{
							break;
						}

						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW %d",counter);lcd_putstr(lcd);
						delay_ms(100);
						FlameApproach();

						GetFlame();
						if(FLAME_SENSOR[FLM_ANALOG]>=100)
						{
							CANDLE_FIRE=1;
							break;
						}

						//ITERATION BREAKER
						WALL_STAT= FireFight_FrontDetector();
						FLAME_PRESENCE= FireFight_FlameDetector(1);
						if( ( WALL_STAT==1) && ( FLAME_PRESENCE==1) )
						{
							break; //EXIT FROM ITERATION
						}

						FireFight_CandleStickDetector();
						FireFight_CandleFireDetector();

						if(CANDLE_FIRE==1)
						{
							break;
						}
					}

					GetFlame();
					if(FLAME_SENSOR[FLM_ANALOG]>=100)
					{
						CANDLE_FIRE=1;
						break;
					}

					BW_CandleScan();

					FireFight_CandleStickDetector();
					FireFight_CandleFireDetector();

					if(CANDLE_FIRE==1)
					{
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"CANDLE DETECTED!");lcd_putstr(lcd);
						delay_ms(2000);
						break;
					}


					//CONTROL VARIABLE UPDATES
					WALL_STAT= FireFight_FrontDetector();
					FLAME_ABSENCE= FireFight_FlameDetector(2);
				}
			}

			if((Ping[PING_LEFT]<=7)|| (Ping[PING_RIGHT]<=7) )
			{
				BW_Buzz(1);

				Evade_Wall();

				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"EVADE WALL");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
				delay_ms(100);
				FlameTracking_New();
			}

/////////////////////////////////////////////////////////////////////////////////
			//CREATING SPACES
			if(Ping[PING_FRONT]<=15)
			{
				while(Ping[PING_FRONT]<=15)
				{
					Evade_Wall();
					mov_bwd(5,FAST_LEVEL_3);
				}
			}

//			Evade_Wall();
//			if(( (Ping[PING_LEFT]<=15) || (Ping[PING_ASKEW_LEFT]<=5) )&& (Ping[PING_RIGHT]>=20))
//			{
//				while( (Ping[PING_LEFT]<=15) || (Ping[PING_ASKEW_LEFT]<=5) )
//				{
//					mov_deflect_right(FAST,CLOSE);
//				}
//			}
//			else if(( (Ping[PING_RIGHT]<=15) || (Ping[PING_ASKEW_RIGHT]<=5) ) && (Ping[PING_LEFT]>=20))
//			{
//				while( (Ping[PING_RIGHT]<=15) || (Ping[PING_ASKEW_RIGHT]<=5) )
//				{
//					mov_deflect_left(FAST,CLOSE);
//				}
//			}
//			if(Ping[PING_FRONT]<=20)
//			{
//				while(Ping[PING_FRONT]<=20)
//				{
//					Evade_Wall();
//					mov_bwd(5,FAST_LEVEL_3);
//				}
//			}

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"EVADE WALL");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
			delay_ms(100);
			FlameTracking_New();
/////////////////////////////////////////////////////////////////////////////////


			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"BLDC FIGHT");lcd_putstr(lcd);
			delay_ms(100);
			BW_BLDC_Fight();
			BW_BLDC_Extinguish();

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_INACTIVE) break;

			mov_rot_right(FAST_LEVEL_3,CLOSE);
			BW_Buzz(1);

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
			delay_ms(100);
			FlameTracking_New();

			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"BLDC FIGHT");lcd_putstr(lcd);
			delay_ms(100);
			BW_BLDC_Fight();
			BW_BLDC_Extinguish();

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_INACTIVE) break;


			mov_rot_left(FAST_LEVEL_3,CLOSE);
			mov_rot_left(FAST_LEVEL_3,CLOSE);

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
			delay_ms(100);
			FlameTracking_New();

			BW_FlameScanning();

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_INACTIVE) break;


		}
	}

	else if (CANDLE_FIRE==0)
	{
		UVLock_Refresh();
		if(UV_Lock==UVLOCK_ACTIVE)
		{
//			mov_rot_left(FAST_LEVEL_3,CLOSE);

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"CORNER CANDLE");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"DETECTED!");lcd_putstr(lcd);
			delay_ms(100);

			/*
			 *  MANDATORY SEQUENCES
			 */

			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
			delay_ms(100);
			FlameTracking_New();

			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"BLDC FIGHT");lcd_putstr(lcd);
			delay_ms(100);
			BW_BLDC_Fight();
			BW_BLDC_Extinguish();


			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(3,0);sprintf(lcd,"CREATE SPACES");lcd_putstr(lcd);
			delay_ms(100);
			BW_Buzz(2);

/////////////////////////////////////////////////////////////////////////////////
			//CREATING SPACES
			if(Ping[PING_FRONT]<=15)
			{
				while(Ping[PING_FRONT]<=15)
				{
					Evade_Wall();
					mov_bwd(5,FAST_LEVEL_3);
				}
			}

//			Evade_Wall();
//			if(( (Ping[PING_LEFT]<=15) || (Ping[PING_ASKEW_LEFT]<=5) )&& (Ping[PING_RIGHT]>=20))
//			{
//				while( (Ping[PING_LEFT]<=15) || (Ping[PING_ASKEW_LEFT]<=5) )
//				{
//					mov_deflect_right(FAST,CLOSE);
//				}
//			}
//
//			else if(( (Ping[PING_RIGHT]<=15) || (Ping[PING_ASKEW_RIGHT]<=5) )&& (Ping[PING_LEFT]>=20))
//			{
//				while( (Ping[PING_RIGHT]<=15) || (Ping[PING_ASKEW_RIGHT]<=5) )
//				{
//					mov_deflect_left(FAST,CLOSE);
//				}
//			}
//
//			if(Ping[PING_FRONT]<=20)
//			{
//				while(Ping[PING_FRONT]<=20)
//				{
//					Evade_Wall();
//					mov_bwd(5,FAST_LEVEL_3);
//				}
//			}

			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"EVADE WALL");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
			delay_ms(100);
			FlameTracking_New();
/////////////////////////////////////////////////////////////////////////////////

		}




	//	while(FlameSense[0]!=0)
		while(UV_Lock==UVLOCK_ACTIVE)
		{

			//CREATING SPACES
			if(Ping[PING_FRONT]<=15)
			{
				while(Ping[PING_FRONT]<=15)
				{
					Evade_Wall();
					mov_bwd(5,FAST_LEVEL_3);
				}
			}

			Evade_Wall();
//			if(( (Ping[PING_LEFT]<=15) || (Ping[PING_ASKEW_LEFT]<=5) )&& (Ping[PING_RIGHT]>=25))
//			{
//				while( (Ping[PING_LEFT]<=15) || (Ping[PING_ASKEW_LEFT]<=5) )
//				{
//					mov_deflect_right(FAST,CLOSE);
//				}
//			}
//
//			else if(( (Ping[PING_RIGHT]<=15) || (Ping[PING_ASKEW_RIGHT]<=5) )&& (Ping[PING_LEFT]>=25))
//			{
//				while( (Ping[PING_RIGHT]<=15) || (Ping[PING_ASKEW_RIGHT]<=5) )
//				{
//					mov_deflect_left(FAST,CLOSE);
//				}
//			}

			if(( (Ping[PING_LEFT]<=15) || (SHARP[SHARP_LEFT]<=5) )&& (Ping[PING_RIGHT]>=25))
			{
				while( (Ping[PING_LEFT]<=15) || (SHARP[SHARP_LEFT]<=5) )
				{
					mov_deflect_right(FAST,CLOSE);
				}
			}

			else if(( (Ping[PING_RIGHT]<=15) || (SHARP[SHARP_RIGHT]<=5) )&& (Ping[PING_LEFT]>=25))
			{
				while( (Ping[PING_RIGHT]<=15) || (SHARP[SHARP_RIGHT]<=5) )
				{
					mov_deflect_left(FAST,CLOSE);
				}
			}

			if(Ping[PING_FRONT]<=15)
			{
				while(Ping[PING_FRONT]<=15)
				{
					Evade_Wall();
					mov_bwd(5,FAST_LEVEL_3);
				}
			}

			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
			delay_ms(100);
			BW_Buzz(2);
			FlameTracking_New();

			//CREATING SPACES BETWEEN ROBOT AND CANDLES
			if(Ping[PING_FRONT]>15)
			{
				while(Ping[PING_FRONT]>15)
				{
					mov_fwd_5cm(5,FAST_LEVEL_3);
				}

			}
			else if(Ping[PING_FRONT]<=15)
			{
				while(Ping[PING_FRONT]<=15)
				{
					mov_bwd(5,FAST_LEVEL_3);
				}
			}

			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"BLDC FIGHT");lcd_putstr(lcd);
			delay_ms(100);
			BW_BLDC_Fight();
			BW_BLDC_Extinguish();

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_INACTIVE) break;


			//FLAME APPROACH
			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAMETRACKING");lcd_putstr(lcd);
			delay_ms(100);
			BW_Buzz(2);
			FlameTracking_New();

			BW_Buzz(5);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME APPROACH");lcd_putstr(lcd);
			delay_ms(1000);

			WALL_STAT= FireFight_FrontDetector();
			FLAME_ABSENCE= FireFight_FlameDetector(2);


			while(
					( WALL_STAT==0) ||
					( FLAME_ABSENCE==1)
				 )
			{
				for(counter=1;counter<=2;counter++)
				{
					FireFight_CandleStickDetector();
					FireFight_CandleFireDetector();

					if(CANDLE_FIRE==1)
					{
						break;
					}

					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW %d",counter);lcd_putstr(lcd);
					delay_ms(100);
					FlameApproach();

					//ITERATION BREAKER
					WALL_STAT= FireFight_FrontDetector();
					FLAME_PRESENCE= FireFight_FlameDetector(1);
					if( ( WALL_STAT==1) && ( FLAME_PRESENCE==1) )
					{
						break; //EXIT FROM ITERATION
					}

					FireFight_CandleStickDetector();
					FireFight_CandleFireDetector();

					if(CANDLE_FIRE==1)
					{
						break;
					}


				}


				BW_CandleScan();

				FireFight_CandleStickDetector();
				FireFight_CandleFireDetector();

				if(CANDLE_FIRE==1)
				{
					break;
				}


				//CONTROL VARIABLE UPDATES
				WALL_STAT= FireFight_FrontDetector();
				FLAME_ABSENCE= FireFight_FlameDetector(2);
			}


		}

	}


	EXTINGUISHER_OFF;
	EXTINGUISHED_FIRE=1;

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(2,1);sprintf(lcd,"FIREFIGHTING");lcd_putstr(lcd);
	lcd_gotoxy(3,2);sprintf(lcd,"SUCCESS!!!");lcd_putstr(lcd);
	delay_ms(100);

}


void FlameSenseDigi_PID_Init(void)
{
	//BW PID WALL FOLLOWING RIGHT RULE
	PID_FLAME.P[0]=0;
	PID_FLAME.P[1]=0;
	PID_FLAME.P[2]=0;
	PID_FLAME.I[0]=0;
	PID_FLAME.I[1]=0;
	PID_FLAME.I[2]=0;
	PID_FLAME.D[0]=0;
	PID_FLAME.D[1]=0;
	PID_FLAME.D[2]=0;

	PID_FLAME.Kp=2;
	PID_FLAME.Ki=0;
	PID_FLAME.Kd=0;

	PID_FLAME.Ts=1;

	PID_FLAME.set_point=4;

	PID_FLAME.error[0]=0;
	PID_FLAME.error[1]=0;
	PID_FLAME.error[2]=0;
	PID_FLAME.pid_value[0]=0;
	PID_FLAME.pid_value[1]=0;
	PID_FLAME.pid_value[2]=0;
}

/*
 * func      : void PID_Calc(void)
 * brief     : PID Controller Calculations
 * param     : N/A
 * Written By: Ryan
 * Ver       : 1
 * Programmer's Note: PID Formula rewritten with guidance from KRPAI Senior, Desta.
 * 					  This function should be called everytime PID function executed
 */
void FlameSense_PID_Calc_Ver3(void)
{
	/*
	 * Update Nilai Variable PID & Set-Point Error
	 */
	PID_FLAME.pid_value[2]=PID_FLAME.pid_value[1];
	PID_FLAME.pid_value[1]=PID_FLAME.pid_value[0];

	PID_FLAME.error[2]=PID_FLAME.error[1];
	PID_FLAME.error[1]=PID_FLAME.error[0];

	if (FlameSenseDigi[0]==PID_FLAME.set_point) {PID_FLAME.error[0]=0;}

	else if ( FlameSenseDigi[0] > PID_FLAME.set_point)
		{
			PID_FLAME.error[0] = FlameSenseDigi[0] - PID_FLAME.set_point;
		}

	else if (FlameSenseDigi[0] < PID_FLAME.set_point)
		{
			PID_FLAME.error[0] = PID_FLAME.set_point - FlameSenseDigi[0];
		}

	/*
	 * PID FORMULA
	 */
	PID_FLAME.P[2]= PID_FLAME.error[0]-PID_FLAME.error[2];
	PID_FLAME.P[1]= PID_FLAME.Kp;
	PID_FLAME.P[0]= PID_FLAME.P[1]*PID_FLAME.P[2]; //Proportional Controller

	PID_FLAME.I[2]= PID_FLAME.Ki*PID_FLAME.Ts/2;
	PID_FLAME.I[1]= PID_FLAME.error[0]+(2*PID_FLAME.error[1])+PID_FLAME.error[2];
	PID_FLAME.I[0]= PID_FLAME.I[2]*PID_FLAME.I[1]; //Integral Controller


	PID_FLAME.D[2]= 2*PID_FLAME.Kd/PID_FLAME.Ts;
	PID_FLAME.D[1]= PID_FLAME.error[0]-(2*PID_FLAME.error[1])+PID_FLAME.error[2];
	PID_FLAME.D[0]= PID_FLAME.D[2]*PID_FLAME.D[1]; //Derivative Controller

	PID_FLAME.pid_value[0]= PID_FLAME.pid_value[2] + PID_FLAME.P[0] + PID_FLAME.I[0] + PID_FLAME.D[0];
}


int FlameTracking_Ver3(void)
{
	int flametrack_cnt=0;

	while( (FlameSenseDigi[0]!=4) && (UV_Lock==UVLOCK_ACTIVE) )
	{

//		Evade_Wall();

//		if(Ping[PING_FRONT]<=13) {mov_bwd(15,FAST_LEVEL_3);}
//		if(Ping[PING_FRONT]<=13) {mov_bwd_5cm(10,FAST_LEVEL_3);}

//		Send_FlameSense();
		PID_FlameTracking_Ver3();


		lcd_display_clear();

		flametrack_cnt++;
		lcd_gotoxy(0,3);sprintf(lcd,"flametrack: %d",flametrack_cnt);lcd_putstr(lcd);
		if(flametrack_cnt>=35)
		{
			flametrack_cnt=0;
			BW_Buzz(2);
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"FLAMETRACKING");lcd_putstr(lcd);
			lcd_gotoxy(4,0);sprintf(lcd,"OVERFLOW");lcd_putstr(lcd);
			delay_ms(100);
			UVLock_Refresh();

		}
	}
	BW_BLDC_OFF;
	return 0;
}


int PID_FlameTracking_Ver3(void)
{
	float DUMMY_PIDVALUE=1;

	//OVERCOMING BLIND SPOTS
	if(FlameSenseDigi[0]==0) FlameSenseDigi[0]=10;

//	FlameSense_PID_Calc();
	FlameSense_PID_Calc_Ver3();

//	if  (
//			(FlameSenseDigi[0]==4) ||
//			(FlameSenseDigi[0]==3) ||
//			(FlameSenseDigi[0]==5) ||
//			(FlameSenseDigi[0]==2) ||
//			(FlameSenseDigi[0]==6)
//		)
//	{
//		BW_BLDC_ON;
//		UVLock_Refresh();
//	}


//	else
//	{
//		BW_BLDC_OFF;
//	}

	//KONDISI ROBOT SESUAI
	if ( FlameSenseDigi[0]==PID_FLAME.set_point)
	{

		FlameTrack_Flag=FLAG_ACTIVE;
	}

	else if(FlameSenseDigi[0]==10)
	{



		if ( (FlameSenseDigi[1]==10) || (FlameSenseDigi[1]==0) )
		{
			Rot_Right_PID(FAST, CLOSE, &PID_FLAME.pid_value[0]);
			Sendto_PC(USART1,"WINDUP ROT RIGHT CLOSE REACH ACTIVATED \r");
		}
		else if( (FlameSenseDigi[1]==1) )
		{
			UVLock_Refresh();
			Rot_Left_PID(FAST, CLOSE, &DUMMY_PIDVALUE);
			Sendto_PC(USART1,"WINDUP ROT LEFT NARROW ACTIVATED \r");
		}
		else if( (FlameSenseDigi[1]==7) )
		{
			UVLock_Refresh();
			Rot_Right_PID(FAST, CLOSE, &DUMMY_PIDVALUE);
			Sendto_PC(USART1,"WINDUP ROT RIGHT NARROW ACTIVATED \r");
		}

		else if ( FlameSenseDigi[1] > PID_FLAME.set_point )
		{
			Rot_Right_PID(FAST, CLOSE, &PID_FLAME.pid_value[0]);
			Sendto_PC(USART1,"WINDUP ROT RIGHT CLOSE REACH ACTIVATED \r");
		}

		else if ( FlameSenseDigi[1] < PID_FLAME.set_point )
		{
			Rot_Left_PID(FAST, CLOSE, &PID_FLAME.pid_value[0]);
			Sendto_PC(USART1,"WINDUP ROT LEFT CLOSE REACH ACTIVATED \r");
		}
	}

	//KONDISI ROBOT JAUH DARI DINDING
	else if ( FlameSenseDigi[0] > PID_FLAME.set_point )
	{
		Rot_Right_PID(FAST, CLOSE, &PID_FLAME.pid_value[0]);
		FlameSenseDigi[1]=7;

	}

	//KONDISI ROBOT DEKAT DENGAN DINDING
	else if ( FlameSenseDigi[0] < PID_FLAME.set_point )
	{
		FlameSenseDigi[1]=1;
		Rot_Left_PID(FAST, CLOSE, &PID_FLAME.pid_value[0]);

	}
	return 0;

}


/* func      : int FlameApproach(void)
 * brief     : BW Following Fire Source using Okky's Flame Sensor
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Friday, March 4th 2016)
 * Revised BY: N/A
 * programmer's Note:
 *
 */
int FlameApproach_Ver2(void)
{
	Get_UV();
	Evade_Wall_Room();
	PID_FlameApproach_Ver2();




	return 0;
}


/* func      : int PID_FlameApproach(void)
 * brief     : Calculating and actuating kinematics for Following Fire Source using Okky's Flame Sensor
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Friday, March 4th 2016)
 * Revised BY: N/A
 * programmer's Note: This function must be called FlameApproach() function
 *
 */
int PID_FlameApproach_Ver2(void)
{
	float DUMMY_PIDVALUE=5;

	//OVERCOMING BLIND SPOTS
	if(FlameSenseDigi[0]==0) FlameSenseDigi[0]=7;

	FlameSense_PID_Calc_Ver3();

	//KONDISI ROBOT SESUAI
	if ( FlameSenseDigi[0]==PID_FLAME.set_point)
	{
		mov_fwd_5cm(10,FAST_LEVEL_3);
		BW_BLDC_ON;
		delay_ms(4000);
		BW_BLDC_OFF;
	}

	else if(FlameSenseDigi[0]==7)
	{

		if ( (FlameSenseDigi[1]==0) || (FlameSenseDigi[1]==7) )
		{
			Rot_Right_PID(FAST_LEVEL_3, CLOSE, &DUMMY_PIDVALUE);
			Sendto_PC(USART1,"WINDUP ROT RIGHT NARROW ACTIVATED \r");
		}

		else if( (FlameSenseDigi[1]==1) )
		{
//			CurveLeft_FlameApproach(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
			Rot_Left_PID(FAST_LEVEL_3, CLOSE, &DUMMY_PIDVALUE);
			Sendto_PC(USART1,"WINDUP ROT LEFT NARROW ACTIVATED \r");
		}
		else if( (FlameSenseDigi[1]==7) )
		{
//			CurveRight_FlameApproach(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
			Rot_Right_PID(FAST_LEVEL_3, CLOSE, &DUMMY_PIDVALUE);
			Sendto_PC(USART1,"WINDUP ROT RIGHT NARROW ACTIVATED \r");
		}

		else if ( FlameSenseDigi[1] > PID_FLAME.set_point )
		{
			CurveRight_FlameApproach(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
			Sendto_PC(USART1,"WINDUP ROT RIGHT CLOSE REACH ACTIVATED \r");
		}

		else if ( FlameSenseDigi[1] < PID_FLAME.set_point )
		{
			CurveLeft_FlameApproach(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
			Sendto_PC(USART1,"WINDUP ROT LEFT CLOSE REACH ACTIVATED \r");
		}



	}
	//KONDISI ROBOT JAUH DARI DINDING
	else if ( FlameSenseDigi[0] > PID_FLAME.set_point )
	{
		if (PID_FLAME.pid_value[0]>10) PID_FLAME.pid_value[0]=10; //WINDUP

		CurveRight_FlameApproach(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
		FlameSenseDigi[1]=7;

	}

	//KONDISI ROBOT DEKAT DENGAN DINDING
	else if ( FlameSenseDigi[0] < PID_FLAME.set_point )
	{
		if (PID_F_R.pid_value[0]>10) PID_F_R.pid_value[0]=10; //WINDUP


		CurveLeft_FlameApproach(FAST_LEVEL_3, CLOSE, &PID_FLAME.pid_value[0]);
		FlameSenseDigi[1]=1;

	}
	return 0;
}

/* func      : int FireFight_FrontDetector(void)
 * brief     : Detect Wall or furniture in BW_FireFight Algorithm
 * param     : N/A
 * retval    : integer
 * 				1 -> Wall Detected
 * 				0 -> Wall not Detected
 * Ver       : 1
 * written By: Ryan (Saturday, April 23rd 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
int FireFight_FrontDetector_Ver2(void)
{
	Get_IR();
	if( (INFRARED[IR_FRONT_LEFT]==IR_DETECTED)  && (INFRARED[IR_FRONT_LEFT]==IR_DETECTED))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/* func      : int FireFight_FlameDetector(int MODE)
 * brief     : Detect Wall or furniture in BW_FireFight Algorithm
 * param     : int MODE
 * 					1 -> Candle Absence Detector
 * 					2 -> Candle Presence Detector
 *
 * retval    : integer
 * 				1 -> ACTIVE
 * 				0 -> INACTIVE
 * Ver       : 1
 * written By: Ryan (Saturday, April 23rd 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
int FireFight_FlameDetector_Ver2(int MODE)
{
	switch(MODE)
	{
		case 1:
				{
					if((FlameSenseDigi[0]==4))
					{
						return 1; break;
					}
					else
					{
						return 0; break;
					}
				}break;

		case 2:
				{
					if((FlameSenseDigi[0]!=4))
					{
						return 1;break;
					}
					else
					{
						return 0; break;
					}
				}break;
	}
}

void FireFight_CandleStickDetector_Ver2(void)
{
	int CANDLE=0;

	Get_IR();
	GetFlame();

	if(FlameFrontDigi[0]>=200)
	{
		CANDLE=1;
	}

	if (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED)
	{
		CANDLE=1;
	}

	if( (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
	{
		CANDLE=1;
	}

	if( (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_LEFT]==IR_DETECTED))
	{
		CANDLE=1;
	}

	if( (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) && (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
	{
		CANDLE=1;
	}

	if( (CANDLE==1)	&&
		(INFRARED[IR_UPPER_LEFT]==IR_NOT_DETECTED) &&
		(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED)
	  )
	{
		CANDLE_STICK=1;
	}
}

void FireFight_CandleFireDetector_Ver2(void)
{
	if(CANDLE_STICK==1)
	{
		if ( (FlameSenseDigi[0]==4)  )
		{
				CANDLE_FIRE=1;
		}
	}
}


/* func      : void BW_FireFight(void)
 * brief     : BW FireFighting Routines
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 23rd 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void BW_FireFight_Ver5(void)
{
	int counter=0;
	int PINPOINT_COUNTER;

	FlameSenseDigi_PID_Init();

	int WALL_STAT;
	int FLAME_PRESENCE;
	int FLAME_ABSENCE;

	CANDLE_STICK=0;
	CANDLE_FIRE=0;

	FIRE_LED_BLINK_ON;

	BW_TurnAround=ACTIVE;

//		if(Ping[PING_FRONT]>=15)
//		{
//			mov_fwd_5cm(5,FAST_LEVEL_3);
//		}
//
//		if(Ping[PING_FRONT]>=15)
//		{
//			mov_fwd_5cm(5,FAST_LEVEL_3);
//		}

		if(Ping[PING_FRONT]>=15)
		{
			mov_fwd_5cm(5,FAST_LEVEL_3);
		}

		if(Ping[PING_FRONT]<13)
		{
			mov_bwd_5cm(5,FAST_LEVEL_3);
		}

		if(FIRESCAN_DIRECTION==SCAN_LEFT)
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"SCAN LEFT");lcd_putstr(lcd);
			delay_ms(100);
			while(FlameSenseDigi[0]==0)
			{
				mov_rot_left(FAST_LEVEL_2,FAR);
			}
		}
		if(FIRESCAN_DIRECTION==SCAN_RIGHT)
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"SCAN RIGHT");lcd_putstr(lcd);
			delay_ms(100);
			while(FlameSenseDigi[0]==0)
			{
				mov_rot_right(FAST_LEVEL_2,FAR);
			}										//===========================
		}


//		if(Ping[PING_FRONT]<=13)
//		{
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//			mov_rot_right(FAST_LEVEL_3,CLOSE);
//		}

		BW_Buzz(1);
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
		delay_ms(100);
		FlameTracking_Ver3();

		UVLock_Refresh();
		if(UV_Lock==UVLOCK_ACTIVE)
		{
			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"BLDC FIGHT 1");lcd_putstr(lcd);
			delay_ms(100);
			BW_BLDC_Fight();
		}

		UVLock_Refresh();
		if(UV_Lock==UVLOCK_ACTIVE)
		{
			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"BLDC FIGHT 2");lcd_putstr(lcd);
			delay_ms(100);
			mov_fwd_5cm(10,FAST_LEVEL_3);
			BW_BLDC_Extinguish();
		}

		UVLock_Refresh();
		while(UV_Lock==UVLOCK_ACTIVE)
		{

			BW_TurnAround=INACTIVE;

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_ACTIVE)
			{
				//FLAME APPROACH
				BW_Buzz(1);
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME APPROACH");lcd_putstr(lcd);
				delay_ms(1000);

				while(
						(Ping[PING_FRONT]>=13) && (UV_Lock==UVLOCK_ACTIVE)
					 )
				{
					counter++;
					if(FlameFrontDigi[0]>=230) break;

					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW %d",counter);lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"Val: %d",FlameSenseDigi[0]);lcd_putstr(lcd);
					delay_ms(100);
					FlameApproach_Ver2();

					BW_BLDC_OFF;

					UVLock_Refresh();
					if(UV_Lock==UVLOCK_INACTIVE) break;
				}

				UVLock_Refresh();
				if(UV_Lock==UVLOCK_ACTIVE)
				{
					BW_Buzz(1);
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"BLDC FIGHT 1");lcd_putstr(lcd);
					delay_ms(100);
					BW_BLDC_Fight();
				}

				UVLock_Refresh();
				if(UV_Lock==UVLOCK_ACTIVE)
				{
					BW_Buzz(1);
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"BLDC FIGHT 2");lcd_putstr(lcd);
					delay_ms(100);
					mov_fwd_5cm(10,FAST_LEVEL_3);
					BW_BLDC_Extinguish();
				}
			}

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_INACTIVE) break;

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_ACTIVE)
			{
/////////////////////////////////////////////////////////////////////////////////
				//CREATING SPACES
				if(Ping[PING_FRONT]<=15)
				{
					while(Ping[PING_FRONT]<=15)
					{
						Evade_Wall();
						mov_bwd(5,FAST_LEVEL_3);
					}
				}

				UVLock_Refresh();
				if(UV_Lock==UVLOCK_ACTIVE)
				{
					BW_Buzz(1);
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
					delay_ms(100);
					FlameTracking_Ver3();
				}

/////////////////////////////////////////////////////////////////////////////////

				UVLock_Refresh();
				if(UV_Lock==UVLOCK_ACTIVE)
				{
					BW_Buzz(1);
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"BLDC FIGHT");lcd_putstr(lcd);
					delay_ms(100);
					BW_BLDC_Fight();
				}

				UVLock_Refresh();
				if(UV_Lock==UVLOCK_ACTIVE)
				{
					BW_Buzz(1);
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"BLDC FIGHT 2");lcd_putstr(lcd);
					delay_ms(100);
					BW_BLDC_Extinguish();
				}

				UVLock_Refresh();
				if(UV_Lock==UVLOCK_ACTIVE)
				{
					mov_rot_right(FAST_LEVEL_3,CLOSE);
					BW_Buzz(1);
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
					delay_ms(100);
					FlameTracking_Ver3();

					BW_Buzz(1);
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"BLDC FIGHT");lcd_putstr(lcd);
					delay_ms(100);
					BW_BLDC_Fight();

					UVLock_Refresh();
					if(UV_Lock==UVLOCK_ACTIVE)
					{
						BW_Buzz(1);
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"BLDC FIGHT 2");lcd_putstr(lcd);
						delay_ms(100);
						BW_BLDC_Extinguish();
					}
				}
			}
			UVLock_Refresh();
			if(UV_Lock==UVLOCK_INACTIVE) break;
		}

	EXTINGUISHER_OFF;
	EXTINGUISHED_FIRE=1;

	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(2,1);sprintf(lcd,"FIREFIGHTING");lcd_putstr(lcd);
	lcd_gotoxy(3,2);sprintf(lcd,"SUCCESS!!!");lcd_putstr(lcd);
	delay_ms(200);

}

/* func      : void H_2017_Algorithm(void)
 * brief     : BW 2017 Level 1 Trial Algorithm
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Hafidin (MISSING NOTES)
 * Revised BY: Ver.2.Toni(Friday,1 Dec 2016)
 * programmer's Note:
 */
void H_2017_Algorithm(void)
{
	int Error_Code=1;

	BW_LOCATION[0]= LOCATION_ROOM;
	ROOM_COUNTER = 1;
	BW_Home_Detection_Ver2();
	Escape_Home();

	RoomTypeDetector();

	if(ROOM_TYPE==GRAY_ROOM)
	{
		mov_fwd_5cm(5,MED);
		RoomTypeDetector();
	}

//	BW_Buzz(1);
	BW_PID_Init();
	FollowTracer_Left();

	BW_LOCATION[1]=BW_LOCATION[0];
	BW_LOCATION[0]=LOCATION_CORRIDOR;

	//LOCATION: CORRIDOR
	BW_Buzz(1);
	H_Correction_Left();

//	if(Ping[PING_FRONT]>=16)
//	{
//		mov_fwd_5cm(10, FAST);
//	}
	mov_fwd_5cm(10, FAST);
	mov_fwd_3cm(3,FAST);

	mov_rot_right(FAST,FAR);
//	mov_rot_right(FAST,FAR);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	H_Correction_ExitRoom();

//	BW_Buzz(1);
	if (Ping[PING_RIGHT]<75)
	{
		if((Ping[PING_ASKEW_RIGHT])>(Ping[PING_RIGHT]))
		{
			mov_rot_right(FAST,CLOSE);
			mov_rot_right(FAST,CLOSE);
			mov_rot_right(FAST,CLOSE);
	//		mov_rot_right(FAST,CLOSE);
		}
		if((Ping[PING_ASKEW_RIGHT])<(Ping[PING_RIGHT]))
		{
			mov_rot_left(FAST,CLOSE);
			mov_rot_left(FAST,CLOSE);
			mov_rot_left(FAST,CLOSE);
	//		mov_rot_left(FAST,CLOSE);
		}
	}
	else
	{
		if((Ping[PING_ASKEW_LEFT])>(Ping[PING_LEFT]))
		{
			mov_rot_left(FAST,CLOSE);
			mov_rot_left(FAST,CLOSE);
			mov_rot_left(FAST,CLOSE);
	//		mov_rot_left(FAST,CLOSE);
		}
		if((Ping[PING_ASKEW_LEFT])<(Ping[PING_LEFT]))
		{
			mov_rot_right(FAST,CLOSE);
			mov_rot_right(FAST,CLOSE);
			mov_rot_right(FAST,CLOSE);
	//		mov_rot_right(FAST,CLOSE);
		}

	}

	if(Ping[PING_FRONT]>30)
	{
		mov_fwd_5cm(5,FAST);
//		mov_fwd_3cm(3,FAST);
		mov_fwd_2cm(2,FAST);
	}
	
	RoomDetector(ROOM_COUNTER);

	BW_LOCATION[1]= BW_LOCATION[0];
	BW_LOCATION[0]= LOCATION_CORRIDOR;

	while(EXTINGUISHED_FIRE==0)
		{
			//SPECIAL CASE (HOME ROOM ROOM_1B, ROOM_1C, ROOM_4B, ROOM4AFLAG ACTIVE
			if ( (ROOM[1]==ROOM_1B) || (ROOM[1]==ROOM_1C) || (ROOM[1]==ROOM_4B) || (ROOM4A_FLAG==ROOM4AFLAG_ACTIVE) )
			{
				lcd_display_clear();
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"REVERSE");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"STRATEGY");lcd_putstr(lcd);
				delay_ms(200);

				if (ROOM[ROOM_COUNTER]== ROOM_1B)
				{
					H_ROOM_1BC();
				}
				else if (ROOM[ROOM_COUNTER]== ROOM_1C)
				{
					H_ROOM_1BC();
				}
				else if(ROOM[ROOM_COUNTER]== ROOM_4A)
				{
					H_ROOM_4A();
				}
				else if(ROOM[ROOM_COUNTER]== ROOM_4B)
				{
					H_ROOM_4B();
				}
//				if(EXTINGUISHED_FIRE==1)break;
			}

			else
			{
				lcd_display_clear();
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"DEFAULT");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"STRATEGY");lcd_putstr(lcd);
				delay_ms(100);

				if(ROOM[ROOM_COUNTER]== ROOM_3)
				{
					H_ROOM_3();
				}
				else if(ROOM[ROOM_COUNTER]== ROOM_2A)
				{
					H_ROOM_2();
				}

				else if (ROOM[ROOM_COUNTER]==ROOM_2B)
				{
					H_ROOM_2();
				}

				else if(ROOM[ROOM_COUNTER]==ROOM_1A)
				{
					H_ROOM_1A();
				}
				else if(ROOM[ROOM_COUNTER]==ROOM_1B)
				{
					H_ROOM_1BC();
				}
				else if(ROOM[ROOM_COUNTER]==ROOM_1C)
				{
					H_ROOM_1BC();
				}
				else if(ROOM[ROOM_COUNTER]==ROOM_4A)
				{
					H_ROOM_4A();
				}
				else if(ROOM[ROOM_COUNTER]==ROOM_4B)
				{
					H_ROOM_4B();
				}
//				if(EXTINGUISHED_FIRE==1)break;
			}
//			if(EXTINGUISHED_FIRE==1)break;
		}


		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;

		//LOCATION: CORRIDOR
		BW_Buzz(1);
		if(Ping[PING_LEFT]<14)
		{
			mov_deflect_right(FAST,CLOSE);
		}
		if(Ping[PING_LEFT]<14)
		{
			mov_deflect_right(FAST,CLOSE);
		}

		mov_fwd_5cm(10, FAST);
		mov_fwd_3cm(3,FAST);

		mov_rot_right(FAST,FAR);

//		if((Ping[PING_ASKEW_RIGHT])>(Ping[PING_RIGHT]))
//		{
//			mov_rot_right(FAST,CLOSE);
//			mov_rot_right(FAST,CLOSE);
//			mov_rot_right(FAST,CLOSE);
////			mov_rot_right(FAST,CLOSE);
//		}
//		if((Ping[PING_ASKEW_RIGHT])<(Ping[PING_RIGHT]))
//		{
//			mov_rot_left(FAST,CLOSE);
//			mov_rot_left(FAST,CLOSE);
//			mov_rot_left(FAST,CLOSE);
////			mov_rot_left(FAST,CLOSE);
//		}

		if (Ping[PING_RIGHT]<75)
		{
			if((Ping[PING_ASKEW_RIGHT])>(Ping[PING_RIGHT]))
			{
				mov_rot_right(FAST,CLOSE);
				mov_rot_right(FAST,CLOSE);
				mov_rot_right(FAST,CLOSE);
		//		mov_rot_right(FAST,CLOSE);
			}
			if((Ping[PING_ASKEW_RIGHT])<(Ping[PING_RIGHT]))
			{
				mov_rot_left(FAST,CLOSE);
				mov_rot_left(FAST,CLOSE);
				mov_rot_left(FAST,CLOSE);
		//		mov_rot_left(FAST,CLOSE);
			}
		}
		else
		{
			if((Ping[PING_ASKEW_LEFT])>(Ping[PING_LEFT]))
			{
				mov_rot_left(FAST,CLOSE);
				mov_rot_left(FAST,CLOSE);
				mov_rot_left(FAST,CLOSE);
		//		mov_rot_left(FAST,CLOSE);
			}
			if((Ping[PING_ASKEW_LEFT])<(Ping[PING_LEFT]))
			{
				mov_rot_right(FAST,CLOSE);
				mov_rot_right(FAST,CLOSE);
				mov_rot_right(FAST,CLOSE);
		//		mov_rot_right(FAST,CLOSE);
			}

		}
//		mov_rot_left(FAST,CLOSE);
//		mov_rot_left(FAST,CLOSE);

		if(Ping[PING_FRONT]>30)
		{
			mov_fwd_5cm(5,FAST);
//			mov_fwd_3cm(3,FAST);
			mov_fwd_2cm(2,FAST);
		}
		
		//BW MAP UPDATE
		BW_Buzz(1);
		ROOM_COUNTER++;
		RoomDetector(ROOM_COUNTER);

		Error_Code= BW_ReturnTrip();

		Evade_Wall();
		if(ROOM[1]!=HALLWAY_SC)
		{
			BW_Buzz(2);

			Evade_Wall();
			mov_fwd_5cm(10,FAST);

			if(Ping[PING_RIGHT]>20)
			{
				mov_rot_right(FAST,FAR);
			}
			else if(Ping[PING_LEFT]>20)
			{
				mov_rot_left(FAST,FAR);
			}

			Evade_Wall();
			mov_fwd_5cm(10,FAST);

			if(Ping[PING_RIGHT]>20)
			{
				mov_rot_right(FAST,FAR);
			}
			else if(Ping[PING_LEFT]>20)
			{
				mov_rot_left(FAST,FAR);
			}

			Evade_Wall();
			mov_fwd_5cm(10,FAST);
//
//			Evade_Wall();
//			mov_fwd_5cm(10,FAST);
		}

		if(Error_Code==0)
		{
			BW_Buzz(5);

			while(1)
			{
				mov_celebrate();
			}
		}
		else
		{
			BW_Buzz(1);
			mov_static();
		}
}

/* func      : void H_2017_Room (void)
 * brief     : BW 2017 Room Algorithm
 * param     : N/A
 * retval    : N/A
 * Ver       : 3
 * written By: Hafidin (MISSING NOTES)
 * Revised BY:
 * 				Ver.2. - Toni (Thursday, December 1st 2016)
 * 				Ver.3. - Ryan (Friday, December 2nd 2016)
 * programmer's Note:
 */
void H_2017_Room (void)
{
	int EXIT_STAT=0;
	BW_Buzz(2);

//	unsigned int SCAN_DIRECTION;		//BARU DITAMBAHIN DEC 1st 2016
//	lcd_display_clear();				//===========================
//	lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
//	delay_ms(100);
//	if(FlameSenseDigi[0]!=0)
//	{
//		if(FlameSenseDigi[0]<4)
//		{
//			lcd_display_clear();
//			lcd_gotoxy(0,0);sprintf(lcd,"SCAN LEFT");lcd_putstr(lcd);
//			delay_ms(100);
//			SCAN_DIRECTION=SCAN_LEFT;
//
//		}
//		else if(FlameSenseDigi[0]>4)
//		{
//			lcd_display_clear();
//			lcd_gotoxy(0,0);sprintf(lcd,"SCAN RIGHT");lcd_putstr(lcd);
//			delay_ms(100);
//			SCAN_DIRECTION=SCAN_RIGHT;
//		}
//	}									//===========================

	Fwd_FlameSide(5, FAST);
	BW_Buzz(1);
	H_Correction_Right();
	H_Correction_Left();

//	Fwd_FlameSide(10, FAST);

	Get_UV();
	if(UV_state==UVSTATE_ACTIVE)
	{
		FIRE=FIRE_ON;
		UV_Lock=UVLOCK_ACTIVE;
	}

		if(UV_Lock==UVLOCK_INACTIVE)
		{
			mov_rot_right(FAST,FAR);
			mov_rot_right(FAST,CLOSE);
			mov_rot_right(FAST,CLOSE);
			mov_rot_right(FAST,CLOSE);

			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
			}
		}

	if(FIRE==FIRE_ON)
	{
		UV_Lock=UVLOCK_ACTIVE;
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"BW");lcd_putstr(lcd);
		lcd_gotoxy(6,1);sprintf(lcd,"FIREFIGHT");lcd_putstr(lcd);
		delay_ms(100);

		Fwd_FlameSide(5, FAST);

		if(Ping[PING_RIGHT]<20)
		{
//			mov_rot_right(FAST,FAR);
			mov_rot_left(FAST,CLOSE);
		}
		else if(Ping[PING_LEFT]<20)
		{
//			mov_rot_left(FAST,FAR);
			mov_rot_right(FAST,CLOSE);
		}

		Fwd_FlameSide(10, FAST);

		mov_rot_right(FAST_LEVEL_2,FAR);
//		mov_fwd_5cm(5,FAST_LEVEL_3);

//		if(SCAN_DIRECTION==SCAN_LEFT)				//BARU DITAMBAHIN DEC 1st 2016
//		{											//===========TONI===========
//			while(FlameSenseDigi[0]==0)
//			{
//				mov_rot_left(FAST_LEVEL_2,FAR);
//			}
//		}
//		if(SCAN_DIRECTION==SCAN_RIGHT)
//		{
//			while(FlameSenseDigi[0]==0)
//			{
//				mov_rot_right(FAST_LEVEL_2,FAR);
//			}
//		}											//===========================

		if(Ping[PING_RIGHT]<=25)
		{
			FIRESCAN_DIRECTION=SCAN_LEFT;
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"SCAN LEFT");lcd_putstr(lcd);
			delay_ms(100);
		}
		if(Ping[PING_LEFT]<=25)
		{
			FIRESCAN_DIRECTION=SCAN_RIGHT;
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"SCAN RIGHT");lcd_putstr(lcd);
			delay_ms(100);								//===========================
		}





		if(ROOM2B_FLAG==ROOM2BFLAG_ACTIVE)
		{
			mov_rot_left(FAST_LEVEL_2,FAR);
			mov_rot_left(FAST_LEVEL_2,FAR);
			mov_rot_left(FAST_LEVEL_3,CLOSE);
//			mov_rot_left(FAST_LEVEL_3,CLOSE);
			BW_FireFight_Ver5();
		}
		else
		{
			BW_FireFight_Ver5();
		}

//		BW_FireFight_Ver5();

		RoomTypeDetector();




//		if(ROOM_TYPE==NORMAL_ROOM)
//		{
//			mov_fwd_5cm(5,MED);
//			RoomTypeDetector();
//		}


		/*
		 * FIRE == OFF
		 */

//		if(ROOM1_FLAG==ROOM1FLAG_ACTIVE)
//		{
//
//			mov_rot_left(FAST,CLOSE);
//			mov_rot_left(FAST,CLOSE);
//			mov_rot_left(FAST,CLOSE);
//			mov_rot_left(FAST,CLOSE);
//			mov_rot_left(FAST,CLOSE);
//			while((Ping[PING_LEFT]<22) || (Ping[PING_ASKEW_LEFT]<22))
//			{
//				mov_deflect_left(FAST,CLOSE);
//			}
//			FollowTracer_Left();
//		}
//		mov_rot_left(FAST,CLOSE);
//		mov_rot_left(FAST,CLOSE);
//		mov_rot_left(FAST,CLOSE);
//		mov_rot_left(FAST,CLOSE);
//		mov_rot_left(FAST,CLOSE);
//		mov_rot_left(FAST,CLOSE);
//		mov_rot_left(FAST,CLOSE);
//		mov_rot_left(FAST,CLOSE);

//		else if(ROOM1_FLAG==ROOM1FLAG_INACTIVE)
//		{




//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);

		//====fungsi agar robot cepet dekat dengan tembok
//		while((Ping[PING_RIGHT]<22) || (Ping[PING_ASKEW_RIGHT]<22))
//		{
//			mov_fwd_5cm(10,FAST_LEVEL_3);
//			mov_deflect_right(FAST,CLOSE);
//		}
		//=========================

		if(BW_TurnAround==ACTIVE)
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"BW TURNAROUND");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"ACTIVATED");lcd_putstr(lcd);
			delay_ms(100);
			if(FIRESCAN_DIRECTION==SCAN_LEFT)
			{
				lcd_gotoxy(0,2);sprintf(lcd,"ROTATE RIGHT");lcd_putstr(lcd);
				delay_ms(100);
				mov_rot_right(FAST,FAR);
				mov_rot_right(FAST,FAR);

				while(Ping[PING_FRONT]>=30)
				{
					mov_rot_right(FAST,FAR);
					mov_rot_right(FAST,FAR);
					mov_fwd_5cm(10,FAST);
				}

				while(Ping[PING_FRONT]<=30)
				{
					mov_rot_right(FAST,FAR);
					mov_rot_right(FAST,FAR);
				}

				if(Ping[PING_LEFT]<20)
				{
					mov_deflect_left(FAST,CLOSE);
					mov_deflect_left(FAST,CLOSE);
					mov_deflect_left(FAST,CLOSE);
				}

				FIRE_LED_BLINK_OFF;
				FIRE_LED_OFF;
				FIRE=FIRE_SUCCESS;
				BW_PID_Init();
				FollowTracer_Left();
			}

			else if(FIRESCAN_DIRECTION==SCAN_RIGHT)
			{
				lcd_gotoxy(0,2);sprintf(lcd,"ROTATE LEFT");lcd_putstr(lcd);
				delay_ms(100);
				mov_rot_left(FAST,FAR);
				mov_rot_left(FAST,FAR);

				while(Ping[PING_FRONT]>=30)
				{
					mov_rot_left(FAST,FAR);
					mov_rot_left(FAST,FAR);
					mov_fwd_5cm(10,FAST);
				}
				mov_rot_left(FAST,FAR);
				while(Ping[PING_FRONT]<=30)
				{
					mov_rot_left(FAST,FAR);
					mov_rot_left(FAST,FAR);
				}

				if(Ping[PING_RIGHT]<20)
				{
					mov_deflect_right(FAST,CLOSE);
					mov_deflect_right(FAST,CLOSE);
					mov_deflect_right(FAST,CLOSE);
				}

				FIRE_LED_BLINK_OFF;
				FIRE_LED_OFF;
				FIRE=FIRE_SUCCESS;
				BW_PID_Init();
				FollowTracer_Right();
			}

			else
			{
				lcd_gotoxy(0,2);sprintf(lcd,"NO WALL PARAM");lcd_putstr(lcd);
				delay_ms(100);

				BW_Buzz(3);
				while(Ping[PING_FRONT]<25)
				{
					mov_fwd_5cm(5,FAST_LEVEL_2);
				}

				FIRE_LED_BLINK_OFF;
				FIRE_LED_OFF;
				FIRE=FIRE_SUCCESS;
				BW_Buzz(2);
				BW_PID_Init();
				FollowTracer_Left();
			}
		}
		else if (BW_TurnAround==INACTIVE)
		{
			mov_rot_right(FAST_LEVEL_3,CLOSE);
			mov_rot_right(FAST_LEVEL_3,CLOSE);
			mov_rot_right(FAST_LEVEL_3,CLOSE);
			mov_rot_right(FAST_LEVEL_3,CLOSE);
			mov_rot_right(FAST_LEVEL_3,CLOSE);

			if(Ping[PING_FRONT]<=35)
			{
				if(Ping[PING_FRONT]<=15)
				{
					mov_bwd_3cm(18,FAST);
				}

				mov_rot_left(FAST,CLOSE);
				mov_rot_left(FAST,CLOSE);
				Get_IR();
				while(
						(Ping[PING_FRONT]<=25) ||
						(INFRARED[IR_UPPER_LEFT]==IR_DETECTED) ||
						(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
					 )
				{
					mov_rot_left(FAST,CLOSE);
					mov_rot_left(FAST,CLOSE);
					Get_IR();
				}
				FIRE_LED_BLINK_OFF;
				FIRE_LED_OFF;
				FIRE=FIRE_SUCCESS;
				BW_PID_Init();
				FollowTracer_Right();
			}

			else if(Ping[PING_FRONT]>35)
			{
				if(Ping[PING_LEFT]<Ping[PING_RIGHT])
				{
					mov_rot_left(FAST,CLOSE);
					mov_rot_left(FAST,CLOSE);
					mov_rot_left(FAST,CLOSE);
					mov_rot_left(FAST,CLOSE);
					mov_rot_left(FAST,CLOSE);
					mov_rot_left(FAST,CLOSE);
					mov_rot_left(FAST,CLOSE);

					TRACER_STAT=TRACER_INACTIVE;
					while(Ping[PING_FRONT]>=20)
					{
						TCSlave_Check();
						if (TRACER_STAT==TRACER_ACTIVE){EXIT_STAT=1;break;}
						Get_IR();
						if	((INFRARED[IR_UPPER_LEFT]==IR_DETECTED) ||(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED))break;
						mov_fwd_5cm(5,FAST);
					}

					if(EXIT_STAT==0)
					{
						mov_rot_left(FAST,CLOSE);
						mov_rot_left(FAST,CLOSE);
						mov_rot_left(FAST,CLOSE);
						mov_rot_left(FAST,CLOSE);
						while(Ping[PING_FRONT]<15)
						{
							mov_rot_left(FAST,CLOSE);
							mov_rot_left(FAST,CLOSE);
							mov_rot_left(FAST,CLOSE);
						}

						FIRE_LED_BLINK_OFF;
						FIRE_LED_OFF;
						FIRE=FIRE_SUCCESS;
						BW_PID_Init();
						FollowTracer_Right();
					}
				}

				else
				{
					mov_rot_right(FAST,CLOSE);
					mov_rot_right(FAST,CLOSE);
					mov_rot_right(FAST,CLOSE);
					mov_rot_right(FAST,CLOSE);
					mov_rot_right(FAST,CLOSE);
					mov_rot_right(FAST,CLOSE);
					mov_rot_right(FAST,CLOSE);

					TRACER_STAT=TRACER_INACTIVE;
					while(Ping[PING_FRONT]>=20)
					{
						TCSlave_Check();
						if (TRACER_STAT==TRACER_ACTIVE){EXIT_STAT=1;break;}
						Get_IR();
						if	((INFRARED[IR_UPPER_LEFT]==IR_DETECTED) ||(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED))break;
						mov_fwd_5cm(5, FAST);
					}

					if(EXIT_STAT==0)
					{
						mov_rot_right(FAST,CLOSE);
						mov_rot_right(FAST,CLOSE);
						mov_rot_right(FAST,CLOSE);
						mov_rot_right(FAST,CLOSE);
						while(Ping[PING_FRONT]<15)
						{
							mov_rot_right(FAST,CLOSE);
							mov_rot_right(FAST,CLOSE);
							mov_rot_right(FAST,CLOSE);
						}

						FIRE_LED_BLINK_OFF;
						FIRE_LED_OFF;
						FIRE=FIRE_SUCCESS;
						BW_PID_Init();
						FollowTracer_Left();
					}
				}
			}

			else
			{
				while(Ping[PING_FRONT]>=15)
				{
					Get_IR();
					if	((INFRARED[IR_UPPER_LEFT]==IR_DETECTED) ||(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED))break;

					GetBumper();
					if(BUMPER[LEFT]==ACTIVE)break;
					if(BUMPER[RIGHT]==ACTIVE)break;
					mov_fwd_5cm(5,FAST);
				}

				mov_rot_left(FAST,CLOSE);
				mov_rot_left(FAST,CLOSE);
				while(Ping[PING_FRONT]<15)
				{
					mov_rot_left(FAST,CLOSE);
					mov_rot_left(FAST,CLOSE);
					mov_rot_left(FAST,CLOSE);
				}

				FIRE_LED_BLINK_OFF;
				FIRE_LED_OFF;
				FIRE=FIRE_SUCCESS;
				BW_PID_Init();
				FollowTracer_Right();
			}
	//	}
		}



		}
	else
	{
		mov_rot_left(FAST,FAR);
		mov_rot_left(FAST,CLOSE);
		mov_rot_left(FAST,CLOSE);
		mov_rot_left(FAST,CLOSE);

		FIRE=FIRE_OFF;
		Exit_No_Fire();
	}



}

/* func      : void H_ROOM_1A (void)
 * brief     : BW 2017 Navigation Routine. Home== R1A
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (MISSING NOTES)
 * Revised BY:
 * programmer's Note:
 */
void H_ROOM_1A (void)
{
	while(EXTINGUISHED_FIRE==0)
	{
		//=======ROOM 1 KE ROOM 4=======//
		Nav_1A_To_4A();

		H_Correction_Right();
		//=======ROOM 4=======//
//		ROOM4_FLAG=ROOM4FLAG_ACTIVE;
		//UPDATE BW LOCATION
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_ROOM;

		//BW IN ROOM
		BW_Buzz(1);
		H_2017_Room();
		if(EXTINGUISHED_FIRE==1)break;

		//BW IN CORRIDOR
		BW_Buzz(1);
		H_Correction_Right();

//		mov_fwd_5cm(10, FAST);

		mov_rot_right(FAST,CLOSE);
//		mov_rot_right(FAST,CLOSE);
//		mov_rot_right(FAST,CLOSE);

		BW_Buzz(1);

		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;

		//=======ROOM 4 KE ROOM 3=======//
		if(Ping[PING_RIGHT]>=75)
		{
			Nav_4B_To_3();
		}
		else
		{
			Nav_4A_To_3();
		}

		H_Correction_Right();
		//=======ROOM 3=======//
		//UPDATE BW LOCATION
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_ROOM;

		//BW IN ROOM
		BW_Buzz(1);
		H_2017_Room();
		if(EXTINGUISHED_FIRE==1)break;

		//BW IN CORRIDOR
		BW_Buzz(1);
		H_Correction_Right();

//		mov_fwd_5cm(10, FAST);

		mov_rot_right(FAST,CLOSE);
		mov_rot_right(FAST,CLOSE);
		mov_rot_right(FAST,CLOSE);

		BW_Buzz(1);

		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;

		//=======ROOM 3 KE ROOM 2=======//
		Nav_3_To_2();

		H_Correction_Right();
		//=======ROOM 2=======//
		//UPDATE BW LOCATION
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_ROOM;

		//BW IN ROOM
		BW_Buzz(1);
		H_2017_Room();
		if(EXTINGUISHED_FIRE==1)break;

		//BW IN CORRIDOR
		BW_Buzz(1);
		H_Correction_Right();

		mov_fwd_5cm(10, FAST);

		mov_rot_right(FAST,CLOSE);
		mov_rot_right(FAST,CLOSE);
		mov_rot_right(FAST,CLOSE);

		BW_Buzz(1);

		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;
	}
}

/* func      : void H_ROOM_1BC (void)
 * brief     : BW 2017 Navigation Routine. Home== R1BC
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (MISSING NOTES)
 * Revised BY:
 * programmer's Note:
 */
void H_ROOM_1BC (void)
{
	while(EXTINGUISHED_FIRE==0)
	{
		//=======ROOM 1 KE ROOM 2=======//
		Nav_1B_To_2();

		//=======ROOM 2=======//
		//UPDATE BW LOCATION
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_ROOM;

		//BW IN ROOM
		BW_Buzz(1);
		H_2017_Room();
		if(EXTINGUISHED_FIRE==1)break;

		//BW IN CORRIDOR
		BW_Buzz(1);
		H_Correction_Right();

//		mov_fwd_5cm(10, FAST);

		mov_rot_right(FAST,CLOSE);
		mov_rot_right(FAST,CLOSE);
		mov_rot_right(FAST,CLOSE);

		BW_Buzz(1);

		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;

		//=======ROOM 2 KE ROOM 3=======//
		Nav_2_To_3();

		//=======ROOM 3=======//
		//UPDATE BW LOCATION
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_ROOM;

		//BW IN ROOM
		BW_Buzz(1);
		H_2017_Room();
		if(EXTINGUISHED_FIRE==1)break;

		//BW IN CORRIDOR
		BW_Buzz(1);
		H_Correction_Right();

//		mov_fwd_5cm(10, FAST);

		mov_rot_right(FAST,CLOSE);
		mov_rot_right(FAST,CLOSE);
		mov_rot_right(FAST,CLOSE);

		BW_Buzz(1);

		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;

		//=======ROOM 3 KE ROOM 4=======//
		Nav_3_To_4A();

		H_Correction_Right();
		//=======ROOM 4=======//
		//UPDATE BW LOCATION
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_ROOM;

		//BW IN ROOM
		BW_Buzz(1);
		H_2017_Room();
		if(EXTINGUISHED_FIRE==1)break;

		//BW IN CORRIDOR
		BW_Buzz(1);
		H_Correction_Right();

		mov_fwd_5cm(10, FAST);

		mov_rot_right(FAST,CLOSE);
		mov_rot_right(FAST,CLOSE);
		mov_rot_right(FAST,CLOSE);

		BW_Buzz(1);

		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;
	}
}

/* func      : void H_ROOM_1BC_SP (void)
 * brief     : BW 2017 Navigation Routine. Home== 1BC_SP
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (MISSING NOTES)
 * Revised BY:
 * programmer's Note:
 */
void H_ROOM_1BC_SP (void)
{
	while(EXTINGUISHED_FIRE==0)
	{
		//=======ROOM 1=======//
		//UPDATE BW LOCATION
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_ROOM;

		//BW IN ROOM
		BW_Buzz(1);
		H_2017_Room();
		if(EXTINGUISHED_FIRE==1)break;

		//BW IN CORRIDOR
		BW_Buzz(1);
		H_Correction_Right();

//		mov_fwd_5cm(10, FAST);

		mov_rot_right(FAST,CLOSE);
		mov_rot_right(FAST,CLOSE);
		mov_rot_right(FAST,CLOSE);

		BW_Buzz(1);

		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;

		//=======ROOM 1 KE ROOM 2=======//
		if(Ping[PING_FRONT]<30)
		{
			Nav_1B_To_2();
		}
		else
		{
			Nav_1C_To_2();
		}
		//=======ROOM 2=======//
		//UPDATE BW LOCATION
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_ROOM;

		//BW IN ROOM
		BW_Buzz(1);
		H_2017_Room();
		if(EXTINGUISHED_FIRE==1)break;

		//BW IN CORRIDOR
		BW_Buzz(1);
		H_Correction_Right();

//		mov_fwd_5cm(10, FAST);

		mov_rot_right(FAST,CLOSE);
		mov_rot_right(FAST,CLOSE);
		mov_rot_right(FAST,CLOSE);

		BW_Buzz(1);

		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;

		//=======ROOM 2 KE ROOM 3=======//
		Nav_2_To_3();

		//=======ROOM 3=======//
		//UPDATE BW LOCATION
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_ROOM;

		//BW IN ROOM
		BW_Buzz(1);
		H_2017_Room();
		if(EXTINGUISHED_FIRE==1)break;

		//BW IN CORRIDOR
		BW_Buzz(1);
		H_Correction_Right();

//		mov_fwd_5cm(10, FAST);

		mov_rot_right(FAST,CLOSE);
		mov_rot_right(FAST,CLOSE);
		mov_rot_right(FAST,CLOSE);

		BW_Buzz(1);

		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;

	}
}

/* func      : void H_ROOM_2 (void)
 * brief     : BW 2017 Navigation Routine. Home== R2
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (MISSING NOTES)
 * Revised BY:
 * programmer's Note:
 */
void H_ROOM_2 (void)
{
	while(EXTINGUISHED_FIRE==0)
	{
		//=======ROOM 2 KE ROOM 1=======//
		ROOM1_FLAG=ROOM1FLAG_ACTIVE;
		if(Ping[PING_FRONT]<25)
		{
			Nav_2A_To_1BC();
		}
		else
		{
			ROOM2B_FLAG=ROOM2BFLAG_ACTIVE;
			Nav_2B_To_1BC();
		}

		H_Correction_Right();
		//=======ROOM 1=======//
		//UPDATE BW LOCATION
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_ROOM;

		//BW IN ROOM
		BW_Buzz(1);
		H_2017_Room();
		if(EXTINGUISHED_FIRE==1)break;

		//BW IN CORRIDOR
		BW_Buzz(1);
		H_Correction_Right();

		mov_fwd_5cm(10, FAST);

		mov_rot_right(FAST,CLOSE);
		mov_rot_right(FAST,CLOSE);
		mov_rot_right(FAST,CLOSE);

		BW_Buzz(1);

		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;

		//=======ROOM 1 KE ROOM 4=======//
		Nav_1A_To_4A();

		H_Correction_Right();
		//=======ROOM 4=======//
//		ROOM4_FLAG=ROOM4FLAG_ACTIVE;
		//UPDATE BW LOCATION
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_ROOM;

		//BW IN ROOM
		BW_Buzz(1);
		H_2017_Room();
		if(EXTINGUISHED_FIRE==1)break;

		//BW IN CORRIDOR
		BW_Buzz(1);
		H_Correction_Right();

//		mov_fwd_5cm(10, FAST);

		mov_rot_right(FAST,CLOSE);
//		mov_rot_right(FAST,CLOSE);
//		mov_rot_right(FAST,CLOSE);

		BW_Buzz(1);

		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;

		//=======ROOM 4 KE ROOM 3=======//
		if(Ping[PING_RIGHT]>=75)
		{
			Nav_4B_To_3();
		}
		else
		{
			Nav_4A_To_3();
		}

		H_Correction_Right();
		//=======ROOM 3=======//
		//UPDATE BW LOCATION
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_ROOM;

		//BW IN ROOM
		BW_Buzz(1);
		H_2017_Room();
		if(EXTINGUISHED_FIRE==1)break;

		//BW IN CORRIDOR
		BW_Buzz(1);
		H_Correction_Right();

//		mov_fwd_5cm(10, FAST);

		mov_rot_right(FAST,CLOSE);
		mov_rot_right(FAST,CLOSE);
		mov_rot_right(FAST,CLOSE);

		BW_Buzz(1);

		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;
	}
}

/* func      : void H_ROOM_3 (void)
 * brief     : BW 2017 Navigation Routine. Home== R3
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (MISSING NOTES)
 * Revised BY:
 * programmer's Note:
 */
void H_ROOM_3 (void)
{
	while(EXTINGUISHED_FIRE==0)
	{
		//=======ROOM 3 KE ROOM 2=======//
		Nav_3_To_2();
		H_Correction_Right();

		//=======ROOM 2=======//
		//UPDATE BW LOCATION
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_ROOM;

		//BW IN ROOM
		BW_Buzz(1);
		H_2017_Room();
		if(EXTINGUISHED_FIRE==1)break;

		//BW IN CORRIDOR
		BW_Buzz(1);
		H_Correction_Right();

//		mov_fwd_5cm(10, FAST);

		mov_rot_right(FAST,CLOSE);
		mov_rot_right(FAST,CLOSE);
		mov_rot_right(FAST,CLOSE);

		BW_Buzz(1);

		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;

		//=======ROOM 2 KE ROOM 1=======//
		ROOM1_FLAG=ROOM1FLAG_ACTIVE;
//		if(Ping[PING_FRONT]<25)
//		{
//			Nav_2A_To_1BC();
//		}
//		else
//		{
//			ROOM2B_FLAG==ROOM2BFLAG_ACTIVE;
//			Nav_2B_To_1BC();
//		}

		if(Ping[PING_FRONT]>25)
		{
			ROOM2B_FLAG==ROOM2BFLAG_ACTIVE;
			Nav_2B_To_1BC();
		}
		else
		{
			Nav_2A_To_1BC();
		}

		H_Correction_Right();
		//=======ROOM 1=======//
		//UPDATE BW LOCATION
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_ROOM;

		//BW IN ROOM
		BW_Buzz(1);
		H_2017_Room();
		if(EXTINGUISHED_FIRE==1)break;

		//BW IN CORRIDOR
		BW_Buzz(1);
		H_Correction_Right();

		mov_fwd_5cm(10, FAST);

		mov_rot_right(FAST,CLOSE);
		mov_rot_right(FAST,CLOSE);
		mov_rot_right(FAST,CLOSE);

		BW_Buzz(1);

		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;

		//=======ROOM 1 KE ROOM 4=======//
		Nav_1A_To_4A();

		H_Correction_Right();
		//=======ROOM 4=======//
		//UPDATE BW LOCATION
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_ROOM;

		//BW IN ROOM
		BW_Buzz(1);
		H_2017_Room();
		if(EXTINGUISHED_FIRE==1)break;

		//BW IN CORRIDOR
		BW_Buzz(1);
		H_Correction_Right();

		mov_fwd_5cm(10, FAST);

		mov_rot_right(FAST,CLOSE);
//		mov_rot_right(FAST,CLOSE);
//		mov_rot_right(FAST,CLOSE);

		BW_Buzz(1);

		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;
	}
}

/* func      : void H_ROOM_4A (void)
 * brief     : BW 2017 Navigation Routine. Home== R4A
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (MISSING NOTES)
 * Revised BY:
 * programmer's Note:
 */
void H_ROOM_4A (void)
{
	while(EXTINGUISHED_FIRE==0)
	{
		//=======ROOM 4 KE ROOM 3=======//

			Nav_4A_To_3();


		H_Correction_Right();
		if (ROOM1A_SP_EXIT_FLAG==ROOM1A_SP_EXIT_FLAG_ACTIVE)
		{
			H_ROOM_1BC_SP();
		}

		else
		{
			//=======ROOM 3=======//
			//UPDATE BW LOCATION
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_ROOM;

			//BW IN ROOM
			BW_Buzz(1);
			H_2017_Room();
			if(EXTINGUISHED_FIRE==1)break;

			//BW IN CORRIDOR
			BW_Buzz(1);
			H_Correction_Right();

	//		mov_fwd_5cm(10, FAST);

			mov_rot_right(FAST,CLOSE);
			mov_rot_right(FAST,CLOSE);
			mov_rot_right(FAST,CLOSE);

			BW_Buzz(1);

			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_CORRIDOR;

			//=======ROOM 3 KE ROOM 2=======//
			Nav_3_To_2();

			H_Correction_Right();
			//=======ROOM 2=======//
			//UPDATE BW LOCATION
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_ROOM;

			//BW IN ROOM
			BW_Buzz(1);
			H_2017_Room();
			if(EXTINGUISHED_FIRE==1)break;

			//BW IN CORRIDOR
			BW_Buzz(1);
			H_Correction_Right();

	//		mov_fwd_5cm(10, FAST);

			mov_rot_right(FAST,CLOSE);
			mov_rot_right(FAST,CLOSE);
			mov_rot_right(FAST,CLOSE);

			BW_Buzz(1);

			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_CORRIDOR;

			//=======ROOM 2 KE ROOM 1=======//
			ROOM1_FLAG=ROOM1FLAG_ACTIVE;
			if(Ping[PING_FRONT]<25)
			{
				Nav_2A_To_1BC();
			}
			else
			{
				ROOM2B_FLAG==ROOM2BFLAG_ACTIVE;
				Nav_2B_To_1BC();
			}

			H_Correction_Right();
			//=======ROOM 1=======//
			//UPDATE BW LOCATION
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_ROOM;

			//BW IN ROOM
			BW_Buzz(1);
			H_2017_Room();
			if(EXTINGUISHED_FIRE==1)break;

			//BW IN CORRIDOR
			BW_Buzz(1);
			H_Correction_Right();

			mov_fwd_5cm(10, FAST);

			mov_rot_right(FAST,CLOSE);
			mov_rot_right(FAST,CLOSE);
			mov_rot_right(FAST,CLOSE);

			BW_Buzz(1);

			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_CORRIDOR;
		}
	}
}

/* func      : void H_ROOM_4B (void)
 * brief     : BW 2017 Navigation Routine. Home== R4B
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (MISSING NOTES)
 * Revised BY:
 * programmer's Note:
 */
void H_ROOM_4B (void)
{
	while(EXTINGUISHED_FIRE==0)
	{
		//=======ROOM 4 KE ROOM 1=======//

			Nav_4B_To_1BC();
			ROOM4B_EXIT_FLAG=ROOM4BFLAG_EXIT_ACTIVE;

		H_Correction_Right();
//		if (ROOM1A_SP_EXIT_FLAG==ROOM1A_SP_EXIT_FLAG_ACTIVE)
//		{
//			H_ROOM_1BC_SP();
//		}

//		else
//		{
			//=======ROOM 1=======//
			//UPDATE BW LOCATION
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_ROOM;

			//BW IN ROOM
			BW_Buzz(1);
			H_2017_Room();
			if(EXTINGUISHED_FIRE==1)break;

			//BW IN CORRIDOR
			BW_Buzz(1);
			H_Correction_Right();

	//		mov_fwd_5cm(10, FAST);

			mov_rot_right(FAST,CLOSE);
			mov_rot_right(FAST,CLOSE);
			mov_rot_right(FAST,CLOSE);

			BW_Buzz(1);

			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_CORRIDOR;

			//=======ROOM 1 KE ROOM 2=======//
			if(Ping[PING_FRONT]<30)
			{
				Nav_1B_To_2();
			}
			else
			{
				Nav_1C_To_2();
			}

			H_Correction_Right();
			//=======ROOM 2=======//
			//UPDATE BW LOCATION
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_ROOM;

			//BW IN ROOM
			BW_Buzz(1);
			H_2017_Room();
			if(EXTINGUISHED_FIRE==1)break;

			//BW IN CORRIDOR
			BW_Buzz(1);
			H_Correction_Right();

	//		mov_fwd_5cm(10, FAST);

			mov_rot_right(FAST,CLOSE);
			mov_rot_right(FAST,CLOSE);
			mov_rot_right(FAST,CLOSE);

			BW_Buzz(1);

			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_CORRIDOR;

			//=======ROOM 2 KE ROOM 3=======//
			Nav_2_To_3();

			H_Correction_Right();
			//=======ROOM 3=======//
			//UPDATE BW LOCATION
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_ROOM;

			//BW IN ROOM
			BW_Buzz(1);
			H_2017_Room();
			if(EXTINGUISHED_FIRE==1)break;

			//BW IN CORRIDOR
			BW_Buzz(1);
			H_Correction_Right();

			mov_fwd_5cm(10, FAST);

			mov_rot_right(FAST,CLOSE);
			mov_rot_right(FAST,CLOSE);
			mov_rot_right(FAST,CLOSE);

			BW_Buzz(1);

			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_CORRIDOR;
//		}
	}
}

/* func      : void H_Correction_Left (void)
 * brief     : BW 2017 Position correction referencing left side rangefinder
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (MISSING NOTES)
 * Revised BY:
 * programmer's Note:
 */
void H_Correction_Left (void)
{
	if(Ping[PING_LEFT]<14)
	{
		mov_deflect_right(FAST,CLOSE);
	}
	if(Ping[PING_LEFT]<14)
	{
		mov_deflect_right(FAST,CLOSE);
	}
}

/* func      : void H_Correction_Right (void)
 * brief     : BW 2017 Position correction referencing right side rangefinder
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (MISSING NOTES)
 * Revised BY:
 * programmer's Note:
 */
void H_Correction_Right (void)
{
	if(Ping[PING_RIGHT]<14)
	{
		mov_deflect_left(FAST,CLOSE);
	}
	if(Ping[PING_RIGHT]<14)
	{
		mov_deflect_left(FAST,CLOSE);
	}
}

/* func      : void H_Correction_Right (void)
 * brief     : BW 2017 Position correction after exiting room
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (MISSING NOTES)
 * Revised BY:
 * programmer's Note:
 */
void H_Correction_ExitRoom (void)
{
	mov_fwd_5cm(10,FAST_LEVEL_3);
	if(Ping[PING_RIGHT]>90)
	{
		while(((Ping[PING_ASKEW_LEFT])>(Ping[PING_LEFT])))
		{
			mov_rot_left(FAST_LEVEL_3,CLOSE);
		}
	}
	else
	{
		while(((Ping[PING_ASKEW_RIGHT])>(Ping[PING_RIGHT])))
		{
			mov_rot_right(FAST_LEVEL_3,CLOSE);
		}
	}
}


/* func      : void Bumper_Action(void)
 * brief     : BW Evading obstacle detected by Limit Switch's Bumper
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Friday, December 2nd 2016)
 * Revised BY:
 * programmer's Note: This routine differ from usual Evade_Wall routine
 */
void Bumper_Action(void)
{
	GetBumper();
	while(BUMPER[LEFT]==ACTIVE)
	{
		BW_Buzz(1);
		mov_bwd_3cm(6,FAST_LEVEL_3);
		mov_rot_right(FAST, FAR);
		mov_rot_right(FAST, FAR);
		GetBumper();
		if(BUMPER[LEFT]==INACTIVE) break;
	}
	while(BUMPER[RIGHT]==ACTIVE)
	{
		BW_Buzz(1);
		mov_bwd_3cm(6,FAST_LEVEL_3);
		mov_rot_left(FAST, FAR);
		mov_rot_left(FAST, FAR);
		GetBumper();
		if(BUMPER[RIGHT]==INACTIVE) break;
	}
}


