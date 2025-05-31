/*==============================================================================================
								   PROJECT BW 2017 Ver.1.0
								     BW ALGORITHM LIBRARY
===============================================================================================*/



#ifndef BW2016_ALGORITHM_H
#define BW2016_ALGORITHM_H

#include "main.h"

/*==============================================================================================
							LEGACY FEATURES FROM BW Ver.1.0
===============================================================================================*/

/*
 * BW FOLLOW CARPET COMMAND CODE
 */
#define NORMAL 	1
#define INVERSE 2

/* BW SCAN FLAME FLAG
 *
 */
#define INACTIVE 0
#define SCAN_LEFT 1
#define SCAN_RIGHT 2


/*
 * BW FLAME FOLLOWER VARIABLES
 */
extern unsigned int FlameSense[2];
extern unsigned int FollowFlame_Flag;
extern unsigned int FlameTrack_Flag;
extern unsigned int FlameScan_Flag;
extern unsigned int FlameExtinguish_Flag;
extern unsigned int FlameApproach_Flag;

#define FLAG_INACTIVE 0
#define FLAG_ACTIVE   1


/*
 * BW PING))) RECEIVER VARIABLES
 */
extern unsigned int Ping[9];
extern unsigned int usart_count;

//BW UV-TRON STATE VARIABLES
extern unsigned int UV_state;
extern unsigned int UV_Lock;

//BW ROOM AND CORRIDOR VARIABLES
extern unsigned int BW_LOCATION[];
extern unsigned int LOCATION_CORRIDOR;
extern unsigned int LOCATION_ROOM;
#define PRESENT_LOC 0
#define LAST_LOC 1

//UV TRON CONDITION
extern unsigned int FIRE;
#define FIRE_DETECTED 0
#define NO_FIRE 1

//ADDITIONAL FLAME SENSOR
extern unsigned int FLAME_SIDE;

//INFRARED PROXIMITY VARIABLES
extern int INFRARED[];
//#define MID_LEFT 2
//#define MID_RIGHT 3
//#define IR_FRONT_LEFT    0
//#define IR_FRONT_RIGHT   1
//#define IR_MID_LEFT      2
//#define IR_MID_RIGHT     3
//#define IR_FRONT_SUB     5

/*
 *  BW BUMPER VARIABLES;
 */
extern unsigned int BUMPER[];

/*
 * BW FOLLOW CARPET VARIABLES
 */
//extern unsigned int NORMAL;
//extern unsigned int INVERSE;
#define NORMAL 1
#define INVERSE 2

/*
 * BW CAT OBSTACLE VARIABLES
 */
extern unsigned int CAT_FOUND[];
#define CAT_PREVIOUS 1
#define CAT_PRESENT  0
extern unsigned int CAT_SHIFT_FOLLOW;
extern unsigned int SHIFT_FOLLOW;
extern unsigned int NO_SHIFT;

extern unsigned int CAT_FLAG;
extern unsigned int CAT_DETECTED;
extern unsigned int CAT_NOT_DETECTED;

/*
 * BW ROOM COUNTER
 */
extern unsigned int ROOM_COUNTER;

/*
 * BW WARZONE FLAG
 */
extern unsigned int WARZONE_FLAG;
extern unsigned int SPECIAL_ZONE_FLAG;

/*
 * BW HOME CIRCLE FLAG
 */
extern unsigned int HOME_CIRCLE_FLAG;
extern unsigned int HOME_CIRCLE_DETECTED;
extern unsigned int HOME_CIRCLE_NOT_DETECTED;

/*
 * BW FOLLOWHOME FLAG
 */
extern unsigned int FOLLOWHOME_FLAG;
extern unsigned int FOLLOWHOME_INACTIVE;
extern unsigned int FOLLOWHOME_ACTIVE;

/*
 * BW CAT OBSTACLE VARIABLES
 */
extern unsigned int CAT_FOUND[];
#define CAT_PREVIOUS 1
#define CAT_PRESENT  0
extern unsigned int CAT_SHIFT_FOLLOW;
extern unsigned int SHIFT_FOLLOW;
extern unsigned int NO_SHIFT;

/*
 * FIRST CAT ENCOUNTER
 */
extern unsigned int FIRST_CAT_ENCOUNTER;
extern unsigned int CAT_NOT_DETECTED;
extern unsigned int CAT_DETECTED;

//NEW COMMAND DATA
extern unsigned int TCS_CMD_SEND_FRONT;
extern unsigned int TCS_CMD_SEND_MIDDLE;
extern unsigned int TCS_CMD_SEND_CONCLUSION;
extern unsigned int TCS_CMD_SAVE_EEPROM;
extern unsigned int TCS_CMD_SHOW_EEPROM;

//CARPET CODE
extern unsigned int COLOUR_NONE;
extern unsigned int COLOUR_BLACK;
extern unsigned int COLOUR_GRAY;
extern unsigned int COLOUR_WHITE;
extern unsigned int COLOUR_RED;
extern unsigned int COLOUR_BLUE;

/*
 * RETURN COUNTER
 */
extern unsigned int RETURN_COUNTER;

/*
 * BW VARIABLE DOOR
 */
extern unsigned int VARIABLE_DOOR;
extern unsigned int VAR_DOOR_NOT_DETECTED;
extern unsigned int VAR_DOOR_DETECTED;
extern unsigned int VAR_DOOR_SCAN;





/*
 * TRACER DETECTED IN BUMPER HANDLER ROUTINES
 */

extern unsigned int TRACER_IN_BUMPER;
extern unsigned int TRC_BMP_ACTIVE;
extern unsigned int TRC_BMP_INACTIVE;

/*
 * TRACER STATUS VARIABLES
 */
extern unsigned int TRACER_STAT;
extern unsigned int TRACER_ACTIVE;
extern unsigned int TRACER_INACTIVE;


/*
 *	NAVIGATION MACRO
 */
#define NAV_HALLWAY_SC 	0
#define NAV_ROOM_1A		1
#define NAV_ROOM_1B		2
#define NAV_ROOM_1C		3
#define NAV_ROOM_2A		4
#define NAV_ROOM_2B		5
#define NAV_ROOM_3		6
#define NAV_ROOM_4A		7
#define NAV_ROOM_4B		8

/*
 * ROOM IDENTIFIER VARIABLES
 */
extern unsigned int HOME;

extern unsigned int ROOM[];

extern unsigned int ROOM_1A;
extern unsigned int ROOM_1B;
extern unsigned int ROOM_1C;

extern unsigned int ROOM_2A;
extern unsigned int ROOM_2B;

extern unsigned int ROOM_3;

extern unsigned int ROOM_4A;
extern unsigned int ROOM_4B;

extern unsigned int HALLWAY_SC;

extern unsigned int ROOM_TYPE;
extern unsigned int NORMAL_ROOM;
extern unsigned int GRAY_ROOM;


/*
 * BW FIRE FIGHTING VARIABLES
 */
extern unsigned int EXTINGUISHED_FIRE;
extern unsigned int FIRE_PUTOFF;


extern unsigned int FLAME_SENSOR[];

/*
 *  BW ROOM COUNTER
 */
extern unsigned int ROOM_COUNTER;


//PRE-TRIAL FUNCTIONS
void BW_Dimension_Check(void);

/*
 *  BW RETURN TO ROOM
 */
void ReturnTo_Room(void);

/*
 *  BW EXIT NO FIRE
 */
void Exit_No_Fire(void);


/*
 * BW EVADE WALL
 */
void Evade_Wall(void);


void BW_Home_Detection(void);
void BW_Home_Detection_Ver2(void);
void Escape_Home(void);
void Home_HallwaySC_Detector(void);
void RoomTypeDetector(void);



/*
 *  BW PID WALL FOLLOWING UNTIL TRACER NEW ALGORITHM
 */
void follow_right_new(void);
void PID_follow_right_new(void);
void curve_left_new(int SPEED, int STEP, float *COMMAND_LOOP);
void curve_right_new(int SPEED, int STEP, float *COMMAND_LOOP);

/*
 *  BW FOLLOW COUNTER RIGHT RULE
 */
void follow_right_counter(int limit);
void PID_follow_right_counter(void);
void curve_right_counter(int SPEED, int STEP, float *COMMAND_LOOP);
void curve_right_counter_reverse(int SPEED, int STEP, float *COMMAND_LOOP);
void curve_left_counter(int SPEED, int STEP, float *COMMAND_LOOP);
void curve_left_counter_reverse(int SPEED, int STEP, float *COMMAND_LOOP);

void follow_left_counter(int limit);
void PID_follow_left_counter(void);



void FlameSense_PID_Init(void);
void FlameSense_PID_Calc(void);
void FlameTracking(void);
void PID_FlameTracking(void);
void Rot_Right_PID(int SPEED, int STEP, float *COMMAND_LOOP);
void Rot_Left_PID(int SPEED, int STEP, float *COMMAND_LOOP);

void BW_FlameSense(void);
void BW_FlameScanning(void);
void BW_FlameExtinguish(int PRESENT_LEFT, int PRESENT_RIGHT);

void FollowFlame_Left(void);
void PID_FollowFlame_Left(void);
void CurveRight_FlameSense(int SPEED, int STEP, float *COMMAND_LOOP);
void CurveLeft_FlameSense(int SPEED, int STEP, float *COMMAND_LOOP);

void BW_FireFollow(void);
int FollowFlame_Left_New(void);
void PID_FollowFlame_Left_New(void);
void CurveRight_FlameSense_New(int SPEED, int STEP, float *COMMAND_LOOP);
void CurveLeft_FlameSense_New(int SPEED, int STEP, float *COMMAND_LOOP);


void BW_CandleScanExecute(void);

/*
 * NEW ALGORITHM
 */

int FlameTracking_New(void);
int PID_FlameTracking_New(void);

int FlameApproach(void);
int PID_FlameApproach(void);
void CurveRight_FlameApproach(int SPEED, int STEP, float *COMMAND_LOOP);
void CurveLeft_FlameApproach(int SPEED, int STEP, float *COMMAND_LOOP);

void RotRight_Angle(void);
void RotLeft_Angle(void);


/*
 *  BW FOLLOWTRACER
 */
void FollowTracer_Right(void);
void PID_FollowTracer_Right(void);

void FollowTracer_Right_Reverse(void);
void PID_FollowTracer_Right_Reverse(void);

void FollowTracer_Left();
void PID_FollowTracer_Left(void);

void FollowTracer_Left_Reverse(void);
void PID_FollowTracer_Left_Reverse(void);


/*
 * BW FOLLOW CARPET
 */
void FollowCarpet_Right(int CARPET_CODE, int FOLLOW_MODE);
void PID_FollowCarpet_Right(void);

void PID_FollowCarpet_Left(void);
void FollowCarpet_Left(int CARPET_CODE, int FOLLOW_MODE);

/*
 *  BW FOLLOW HOME
 */
void PID_FollowHome_Right(void);
void PID_FollowHome_Left(void);


/*
 * BW NAVIGATION FUNCTION PROTOTYPE
 */
void BW_Navi(int STARTING_POINT, int DESTINATION);

//STARTING POINT = HALLWAY SC
void Nav_HallwaySC_To_3(void);
void Nav_HallwaySC_To_2(void);
void Nav_HallwaySC_To_4B(void);
void Nav_HallwaySC_To_4A(void);
void Nav_HallwaySC_To_1A(int OPTION);
void Nav_HallwaySC_To_1B(void);

//STARTING POINT = 1A
void Nav_1A_To_HallwaySC(void);
void Nav_1A_To_2(void);
void Nav_1A_To_3(void);
void Nav_1A_To_4B(void);
void Nav_1A_To_4A(void);

//STARTING POINT = 1B
void Nav_1B_To_2(void);

//STARTING POINT = 1C
void Nav_1C_To_HallwaySC(void);
void Nav_1C_To_2(void);
void Nav_1C_To_3(void);
void Nav_1C_To_4A(void);
void Nav_1C_To_4B(void);

//STARTING POINT = 2
void Nav_2_To_HallwaySC(void);
void Nav_2B_To_1BC(void);
void Nav_2_To_1A(void);
void Nav_2_To_1BC(void);
void Nav_2_To_3(void);
void Nav_2_To_4A(void);
void Nav_2_To_4B(void);

//STARTING POINT = 3
void Nav_3_To_HallwaySC(void);
void Nav_2A_To_1BC(void);
void Nav_3_To_1A(void);
void Nav_3_To_1BC(void);
void Nav_3_To_2(void);
void Nav_3_To_4A(void);
void Nav_3_To_4B(void);


//STARTING POINT = 4A
void Nav_4A_To_HallwaySC(void);
void Nav_4A_To_3(void);
void Nav_4A_To_1A(void);
void Nav_4A_To_2(void);

//STARTING POINT = 4B
void Nav_4B_To_HallwaySC(void);
void Nav_4B_To_1A(void);
void Nav_4B_To_1BC(void);
void Nav_4B_To_2(void);
void Nav_4B_To_3(void);


//TCS3200 SLAVE STATUS CHECK
void TCSlave_Check(void);

void Stabilize_After_Exit(void);
void BW_Room(void);
void BW_Strategy(void);
int BW_ReturnTrip(void);


void RoomType_Init(void);

void BW_FlameCheck(void);

void HomeCircle_Detector(void);
void BW_FireFight_Ver2(void);

void UVLock_Refresh(void);
void FireFight_CandleStickDetector(void);
void FireFight_CandleFireDetector(void);

void BW_FlameDemo(void);
void Sensor_Menu(void);
void Nav_Test_Menu(void);

void H_2017_Algorithm (void);
void H_2017_Room (void);
void H_ROOM_1A (void);
void H_ROOM_1BC (void);
void H_ROOM_1BC_SP (void);
void H_ROOM_2 (void);
void H_ROOM_3 (void);
void H_ROOM_4A (void);
void H_ROOM_4B (void);
void H_Correction_Left (void);
void H_Correction_Right (void);

/*
 *  BW CANDLE TRACKER VARIABLES;
 */
extern unsigned int CANDLE_STAT;
extern unsigned int CANDLE_STICK;
extern unsigned int CANDLE_FIRE;
extern unsigned int CANDLE_STAT;


/*
 *  EXIT FLAG
 */

extern unsigned int EXIT_FLAG;
extern unsigned int EXIT_ACTIVE;
extern unsigned int EXIT_INACTIVE;


/*
 *  ROOM 1 FLAG
 */

extern unsigned int ROOM1_FLAG;
extern unsigned int ROOM1FLAG_ACTIVE;
extern unsigned int ROOM1FLAG_INACTIVE;

/*
 *  ROOM 1BC FLAG
 */

extern unsigned int ROOM1BC_FLAG;
extern unsigned int ROOM1BCFLAG_ACTIVE;
extern unsigned int ROOM1BCFLAG_INACTIVE;

/*
 * ROOM 2B FLAG
 */
extern unsigned int ROOM2B_FLAG;
extern unsigned int ROOM2BFLAG_ACTIVE;
extern unsigned int ROOM2BFLAG_INACTIVE;

/*
 * ROOM 4 FLAG
 */
extern unsigned int ROOM4_FLAG;
extern unsigned int ROOM4FLAG_ACTIVE;
extern unsigned int ROOM4FLAG_INACTIVE;

/*
 * ROOM 4A FLAG
 */
extern unsigned int ROOM4A_FLAG;
extern unsigned int ROOM4AFLAG_ACTIVE;
extern unsigned int ROOM4AFLAG_INACTIVE;

/*
 * ROOM 4B FLAG
 */
extern unsigned int ROOM4B_FLAG;
extern unsigned int ROOM4BFLAG_ACTIVE;
extern unsigned int ROOM4BFLAG_INACTIVE;

/*
 * ROOM 4B_EXIT FLAG
 */
extern unsigned int ROOM4B_EXIT_FLAG;
extern unsigned int ROOM4BFLAG_EXIT_ACTIVE;
extern unsigned int ROOM4BFLAG_EXIT_INACTIVE;

/*
 * ROOM1A SPECIAL EXIT FLAG
 */
extern unsigned int ROOM1A_SP_EXIT_FLAG;
extern unsigned int ROOM1A_SP_EXIT_FLAG_ACTIVE;
extern unsigned int ROOM1A_SP_EXIT_FLAG_INACTIVE;


/*
 * ROOM4A CAT AVOIDER
 */
extern unsigned int ROOM4A_CAT_AVOIDER;
extern unsigned int ROOM4A_CAT_AVOIDER_ACTIVE;
extern unsigned int ROOM4A_CAT_AVOIDER_INACTIVE;


/*
 * CAT SHIFT ALGORITHM FLAG
 */
extern unsigned int SHIFT_ALGORITHM_FLAG;
extern unsigned int SHIFT_ALGORITHM_ACTIVE;
extern unsigned int SHIFT_ALGORITHM_INACTIVE;

/*
 *  DEFLECT WALL OVERFLOW COUNTER
 */
extern int RIGHT_OVERFLOW_COUNTER;
extern int LEFT_OVERFLOW_COUNTER;

/*
 * SPECIAL ROUTE FOR RETURN TRIP R2 TO R4A
 * HOME: R4A
 * FIRE ROOM: R2
 * CAT CONFIG: A
 */
extern unsigned int R2TO4A_SP_ROUTE;
extern unsigned int R2TO4A_SP_ACTIVE;
extern unsigned int R2TO4A_SP_INACTIVE;


/*
 *  BW TURNAROUND NAVIGATION
 */
extern unsigned int TURN_LEFT;
extern unsigned int TURN_RIGHT;


//SHARP IR RANGEFINDER
extern unsigned int SHARP[];

/*
 * BW FIRE SCAN DIRECTION FLAG
 */
extern unsigned int FIRESCAN_DIRECTION;

/*
 * BW FIREFIGHT SUCCESS TURN AROUND
 */
extern unsigned int BW_TurnAround;


#endif

