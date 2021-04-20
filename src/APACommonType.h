/*************************************************************************************************************************************************
**                                                                                                                                              **
** Copyright (C) SAIC Technologies (2020)                                                                                                       **
**                                                                                                                                              **
** All rights reserved.                                                                                                                         **
**                                                                                                                                              **
** This document contains proprietary information belonging to SAIC                                                                             **
** Technologies. Passing on and copying of this document, and communication                                                                     **
** of its contents is not permitted without prior written authorization.                                                                        **
**                                                                                                                                              **
**************************************************************************************************************************************************
**                                                                                                                                              **
**  $FILENAME   : APACommonType.h $                                                                                                             **
**                                                                                                                                              **
**  $CC VERSION : \main\94 $                                                                                                                    **
**                                                                                                                                              **
**  $DATE       : 2020-08-18                                                                                                                    **
**                                                                                                                                              **
**  AUTHOR      : SAIC CH-Engineering                                                                                                           **
**                                                                                                                                              **
**  VENDOR      : SAIC Technologies                                                                                                             **
**                                                                                                                                              **
**  DESCRIPTION : This file contains                                                                                                            **
**                - common data type definition                                                                                                 **
**                                                                                                                                              **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                                                                                        **
**                                                                                                                                              **
*************************************************************************************************************************************************/
#ifndef APACOMMONTYPE_H_
#define APACOMMONTYPE_H_


/*************************************************************************************************************************************************
**                                                              Includes                                                                        **
*************************************************************************************************************************************************/
#include "Platform_Types.h"

/*************************************************************************************************************************************************
**                                                              Global Macro Definitions                                                        **
*************************************************************************************************************************************************/
#define Math_PI             3.1415926535897932384626
#define PI	                Math_PI
#define Math_Deg2Rad        0.017453292519943
#define Math_Rad2Deg        57.295779513082323

#define APAenum             uint8

#define APAen_INVALID       0x0
#define APAen_VALID         0x1
#define APAen_VIRTUAL       0x2

/*Slot sensor source*/
#define APAen_Default                         0x0
#define APAen_SlotSourceFusion                0x1
#define APAen_SlotSourceUSSOnly               0x2
#define APAen_SlotSourceVSSOnly               0x3

#define APAen_FusionMode1                     0x1
#define APAen_FusionModeUSSOnly               0x2
// #define APAen_FusionMode3                     0x3
// #define APAen_FusionMode4                     0x4
// #define APAen_FusionMode5                     0x5

#define APAen_DefaultRightSlotDataIndex       0
#define APAen_DefaultLeftSlotDataIndex        1

#define APAen_EdgeVirtual                     0x0
#define APAen_EdgeReal                        0x1

#define APAen_CurbNone            0x0
#define APAen_CurbLow             0x1
#define APAen_CurbHigh            0x2

#define APAen_TRUE                0x1
#define APAen_FALSE               0x0

/*SlotType*/
#define APAen_SlotTypeDefault         0x0
#define APAen_SlotTypeParallel        0x1
#define APAen_SlotTypeCross           0x2
#define APAen_SlotTypeSlash           0x3
#define APAen_SlotTypeUnkown          0x4

/*Slot Bearing*/
#define APAen_BearingDefault           0x0
#define APAen_BearingLeft              0x1
#define APAen_BearingRight             0x2

/*Slot Occupied*/
#define APAen_OccupiedDefault     0x0
#define APAen_OccupiedAvbl        0x1
#define APAen_OccupiedOccupied    0x2

#define APAen_PrePlnUnkown        0x0
#define APAen_PrePlnAvbl          0x1
#define APAen_PrePlnNeedToGO      0x2
#define APAen_PrePlnFail          0x3
#define APAen_PrePlnBusy          0x4

#define APAen_GearP               0x8
#define APAen_GearR               0x7
#define APAen_GearN               0x6
#define APAen_GearD               0x5


#define APA_SNS_DTD_NEAREST_OBJ_DIS_REGION_NUM			        5
#define NO_OBJ_DISTANCE                                         0x7fff
#define APA_SUPPORT_APA_SNS_NUM									12
#define CALTOLERANCE 											1e-3

#define MAXSHORT												0x7fff
#define APA_SUPPORT_MAX_DISTANCE								MAXSHORT // mm
#define APA_CAR_PARK_SIDE_NUM									2
#define APA_CAR_PARK_AT_LEFT_SIDE								0
#define APA_CAR_PARK_AT_RIGHT_SIDE								1
#define PA_SYS_NUM									            2
#define APA_SLOT_SUPPORT_FRONT_SIDE_MAX_SAMPLE_POINT_NUM				100 // 80 // df: 50.
#define APA_SLOT_SUPPORT_REAR_SIDE_MAX_SAMPLE_POINT_NUM				    15  // dsh 20140723
#define APA_SLOT_SUPPORT_SEARCHING_SLOT_SENSOR_NUM			            2
#define APA_SLOT_SUPPORT_SLOT_LENGTH_COMPENSATE_SPEED_DEVIDED_NUM	    2
#define APA_SLOT_OBJ_CAR_TO_OBJ_DIS_COMPENSATE_TYPE_NUM				    2
#define APA_SLOT_APA_SENSOR_HFOV_DIVIDED_SEG_NUM			            (20)

#define APA_SLOT_SUPPORT_OBJ_CHECK_SPEED_DEVIDED_NUM		            6
#define APA_SLOT_SUPPORT_OBJ_CHECK_OBJ_DIS_DEVIDED_NUM		            3 // 0 ~ 1.3m ~ 2.0 ~ 2.8m ~ 4.5m

#define APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM	        5


#define APA_SLOT_OBJ_PT_SLOPE_ERROR_OBJ_WIDTH_TOO_SHORT		        (127)






#define APA_SLOT_COR_DELTA_ANG_MAX_ZONE_NUM					        8
#define APA_SLOT_COR_RRS_RLS_DELTA_ANG_MAX_ZONE_NUM			        6
#define APA_SLOT_P_COR_SNS_DIS_DIV_NUM 					            4
#define APA_SLOT_P_COR_RRS_RLS_SNS_DIS_DIV_NUM 			            4
#define APA_SLOT_SUPPORT_SIMPLE_OBJ_TYPE_NUM						3
#define APA_SLOT_OBJ_PROFILE_TYPE_NUM								32

#define APA_CALP_INSTEP3_OPTIMAL_STEERING_ANGLE_DEVIDED_NUM		                    7
#define APA_CALP_INSTEP3_OPTIMAL_STEERING_ANGLE_CAR_TO_END_POS_DIS_DEVIDED_NUM		13  // LuHui Need to check again


#define APA_CAR_CORNER_NUMBER									                    4
#define APA_PARKPROC_SUPPORT_MAX_SYS_DT_MIN_DIS_NUM				                    (1000 / 100) // 1s / 100ms



#define APA_PARKPROC_CAR_END_POSITION_CLOSE_TO_OBJ1				                    0
#define APA_PARKPROC_CAR_END_POSITION_CLOSE_TO_OBJ2				                    1
#define APA_PARKPROC_CAR_END_POSITION_MID_BETWEEN_OBJ1_AND_OBJ2                     2
#define APA_PARKPROC_CAR_CAN_DRV_MIN_DIS_TO_OBJ_BY_SNS_DTD_SCENARIO_NUM             2
#define APA_PARKPROC_CAR_DRV_CIRCLE_SIDE_NUM					                    2
#define APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM		                    4



#define APA_TRAJCAL_INSERT_LINE_BET_STEP2_3_CIRCLE_METHOD_VALUE_NUM				    4

#define APA_SLOT_OBJ_IS_BIG_ENOUGH_CHECK_OBJ_MASK		                            0x01
#define APA_SLOT_OBJ_IS_BIG_ENOUGH_CHECK_TYPE_NUM		                            2
#define APA_SLOT_CURB_DT_CHECK_DEVIDE_SLOT_LEN_NUM		                            3

#define APA_SLOT_OBJ_PROFILE_COMPENSATE_TYPE_NUM								    20
#define APA_TRAJCAL_COORDINATE_SETUP_CHECK_OBJ_CASE_NUM							    3
#define APA_TRAJCAL_COORDINATE_SETUP_OBJ_TYPE_NUM								    5
#define APA_TRAJCAL_COORDINATE_SETUP_ROAD_TYPE_NUM								    3
#define APA_TRAJCAL_CAR_DRIVE_STRAIGHTLY_TOL_MAX_CHECK_DIS  						10000 // 10m.
#define APA_TRAJCAL_DIS_CAL_VALUE_IS_EQUAL_TOL										20 // 2cm // (1e-2)
#define DTM_SPK_CHIME_CMD_TASK_CALL_TIME			    	10
#define SPK_CHIME_TASK_CALL_TIME                DTM_SPK_CHIME_CMD_TASK_CALL_TIME
#define APA_TRAJCAL_POINT_IS_ON_LINE_MAX_DIS_TOL										20 // 2cm.

typedef enum
{
  PARearSys = 0,
  PAFrontSys
} PASysType;

typedef enum 
{
	APA_RRS_SNS_INDEX = 0,
	APA_RR_SNS_INDEX,
	APA_RRM_SNS_INDEX,
	APA_RLM_SNS_INDEX,
	APA_RL_SNS_INDEX,
	APA_RLS_SNS_INDEX,
	APA_FRS_SNS_INDEX,
	APA_FR_SNS_INDEX,
	APA_FRM_SNS_INDEX,
	APA_FLM_SNS_INDEX,
	APA_FL_SNS_INDEX,
	APA_FLS_SNS_INDEX
} APASnsIndexType;

typedef enum 
{
	APALineIsIncline = 0,
	APALineIsVertical,
	APALineIsHorizontal,
	APALineIsInvalidLineType
} APALineIsVerticalOrHorizontalType;


typedef enum 
{
	APA_SLOT_TYPE_INVALID = 0,
	APA_SLOT_TYPE_PARALLEL,
	APA_SLOT_TYPE_PERPENDICULAR,
	APA_SLOT_TYPE_ANGULAR
} tAPASlotType;  


typedef enum 
{
	APASlotObjIsBigEnoughCheckType_Obj = 0,
	APASlotObjIsBigEnoughCheckType_Curb	
} APASlotObjIsBigEnoughCheckType;

typedef enum 
{
	APATrajCalCoordinateSetupCheckObjCase_Obj1ExistObj2Exist = 0,
	APATrajCalCoordinateSetupCheckObjCase_Obj1ExistObj2Not,
	APATrajCalCoordinateSetupCheckObjCase_Obj1NotObj2Exist		
} APATrajCalCoordinateSetupCheckObjCaseType;

typedef enum 
{
	APATrajCalCoordinateSetupObj_SmallObj = 0,
	APATrajCalCoordinateSetupObj_PerpendicularCar,
	APATrajCalCoordinateSetupObj_NegAngularCar,
	APATrajCalCoordinateSetupObj_PosAngularCar,
	APATrajCalCoordinateSetupObj_ParallelCar

} APATrajCalCoordinateSetupObjType;

typedef enum 
{
	APATrajCalCoordinateSetupRoad_Straight = 0,
	APATrajCalCoordinateSetupRoad_Convex,
	APATrajCalCoordinateSetupRoad_Concave

} APATrajCalCoordinateSetupRoadType;

typedef enum 
{
	APATrajCalCmd_SetupSystemCoordinateAccordingToSlotData = 1,
	APATrajCalCmd_SlotFoundReCalSlot,
	// APATrajectoryCalCmd_InStep1SearchForAnotherTrajectory1,
	APATrajCalCmd_InStepNSearchForAnotherTrajectory1,
	APATrajCalCmd_InStepNSearchForCorTrajectory1, // Cal correct to step 2 with one correct step only.
	APATrajCalCmd_InStepNSearchForCorTrajectory2
} APATrajCalCmdType;

typedef enum 
{
	APATrajCalStatus_IDLE = 0,
	APATrajCalStatus_REQUESTCAL,
	APATrajCalStatus_BUSY,	
	APATrajCalStatus_CALFINISHED
}APATrajCalStatusType;

typedef enum 
{
	APAParkProcPCarCanDrvMinDisToObjBySnsDtdAngLess10degIndex = 0,
	APAParkProcPCarCanDrvMinDisToObjBySnsDtdAngGreat10degIndex	
} tAPAParkProcPCarCanDrvFwMinDisToObjBySnsDtdScenarioIndexType;

typedef enum 
{
	APAParkProcPCarDrvCircleLeftIndex = 0,
	APAParkProcPCarDrvCircleRightIndex	
} tAPAParkProcPCarDrvCircleSideIndexType;


typedef enum 
{
	APA_PARKPROC_PARKING_MODE_PARALLEL =	0,
	APA_PARKPROC_PARKING_MODE_PERPENDICULAR,
	APA_PARKPROC_PARKING_MODE_ANGULAR,
	APA_PARKPROC_PARKING_MODE_PARKEXIT,
	APA_PARKPROC_PARKING_MODE_UNKNOWNMODE
} tAPAParkProcParkingModeType;

typedef enum {
	APA_SLOT_OBJ_TYPE_UNKNOWN = 0,
	APA_SLOT_OBJ_TYPE_SQUARE_OBJ,  // 1
	APA_SLOT_OBJ_TYPE_SQUARE_OBJ_WITH_FALLING_SHAPE,  // 2
	APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_RISING_SHAPE_ONLY,  // 3
	APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_RISING_AND_FLAT_SHAPE,  // 4
	APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_SMALL_RISING_AND_FALLING_SHAPE, // 5
	APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_NORMAL_RISING_AND_FALLING_SHAPE, // 6
	APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_BIG_RISING_AND_FALLING_SHAPE,  // 7
	APA_SLOT_OBJ_TYPE_PER_CAR_WITH_SMALL_FLAT_SMALL_WIDTH, // 8 // Flat shape < 1/3, car width < 1.8m
	APA_SLOT_OBJ_TYPE_PER_CAR_WITH_NORMAL_FLAT_SMALL_WIDTH, // 9 // Flat shape = 1/3 ~ 2/3, car width < 1.8m
	APA_SLOT_OBJ_TYPE_PER_CAR_WITH_BIG_FLAT_SMALL_WIDTH,  // 10 // Flat shape > 2/3, car width < 1.8m
	APA_SLOT_OBJ_TYPE_PER_CAR_WITH_SMALL_FLAT_NORMAL_WIDTH, // 11  // Flat shape < 1/3, car width = 1.8m ~ 2.3m
	APA_SLOT_OBJ_TYPE_PER_CAR_WITH_NORMAL_FLAT_NORMAL_WIDTH, // 12 // Flat shape = 1/3 ~ 2/3, car width = 1.8m ~ 2.3m
	APA_SLOT_OBJ_TYPE_PER_CAR_WITH_BIG_FLAT_NORMAL_WIDTH, // 13 // Flat shape > 2/3, car width = 1.8m ~ 2.3m
	APA_SLOT_OBJ_TYPE_PER_CAR_WITH_SMALL_FLAT_BIG_WIDTH, // 14 // Flat shape < 1/3, car width > 2.3m
	APA_SLOT_OBJ_TYPE_PER_CAR_WITH_NORMAL_FLAT_BIG_WIDTH, // 15 // Flat shape = 1/3 ~ 2/3, car width > 2.3m
	APA_SLOT_OBJ_TYPE_PER_CAR_WITH_BIG_FLAT_BIG_WIDTH, // 16, // Flat shape > 2/3, car width > 2.3m	
	APA_SLOT_OBJ_TYPE_CAR_ANGULAR_NEG_10DEG_RISING_SHAPE_AT_START, // 17 // flat shape is falling shape (slope (k): +), for obj1 it is car with +10deg, for obj2 it is car with -10deg
	APA_SLOT_OBJ_TYPE_CAR_ANGULAR_NEG_10DEG_FLAT_SHAPE_AT_START,  // 18
	APA_SLOT_OBJ_TYPE_CAR_ANGULAR_NEG_20DEG_RISING_SHAPE_AT_START, // 19
	APA_SLOT_OBJ_TYPE_CAR_ANGULAR_NEG_20DEG_FLAT_SHAPE_AT_START,  // 20
	APA_SLOT_OBJ_TYPE_CAR_ANGULAR_NEG_30DEG_RISING_SHAPE_AT_START,  // 21
	APA_SLOT_OBJ_TYPE_CAR_ANGULAR_NEG_30DEG_FLAT_SHAPE_AT_START,  // 22
	APA_SLOT_OBJ_TYPE_CAR_ANGULAR_10DEG_RISING_SHAPE_AT_START, // 23  // flat shape is rising shape (slope (k): -), for obj1 it is car with -10deg, for obj2 it is car with +10deg
	APA_SLOT_OBJ_TYPE_CAR_ANGULAR_10DEG_FLAT_SHAPE_AT_START,  // 24
	APA_SLOT_OBJ_TYPE_CAR_ANGULAR_20DEG_RISING_SHAPE_AT_START,  // 25
	APA_SLOT_OBJ_TYPE_CAR_ANGULAR_20DEG_FLAT_SHAPE_AT_START,  // 26
	APA_SLOT_OBJ_TYPE_CAR_ANGULAR_30DEG_RISING_SHAPE_AT_START,  // 27
	APA_SLOT_OBJ_TYPE_CAR_ANGULAR_30DEG_FLAT_SHAPE_AT_START,  // 28
	APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_SMALL_RISING_SHAPE, // 29 // rising width < 20cm,
	APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_NORMAL_RISING_SHAPE, // 30 // rising width < 40cm,
	APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_BIG_RISING_SHAPE, // 31 // rising width < 60cm.
	APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_VERY_BIG_RISING_SHAPE, // 32 // rising width > 60cm.
	APA_SLOT_OBJ_TYPE_NOT_CHECKED

} APASlotObjProfileType;

typedef enum {

	APA_SLOT_OBJ_COMP_TYPE_SQUARE_OBJ = 0,
	APA_SLOT_OBJ_COMP_TYPE_ROUND_OBJ_WITH_RISING_SHAPE_ONLY,
	APA_SLOT_OBJ_COMP_TYPE_ROUND_OBJ_WITH_SMALL_RISING_AND_FALLING_SHAPE,
	APA_SLOT_OBJ_COMP_TYPE_ROUND_OBJ_WITH_NORMAL_RISING_AND_FALLING_SHAPE,
	APA_SLOT_OBJ_COMP_TYPE_PER_CAR_WITH_SMALL_FLAT_SMALL_WIDTH, // Flat shape < 1/3, car width < 1.8m
	APA_SLOT_OBJ_COMP_TYPE_PER_CAR_WITH_NORMAL_FLAT_SMALL_WIDTH, // Flat shape = 1/3 ~ 2/3, car width < 1.8m
	APA_SLOT_OBJ_COMP_TYPE_PER_CAR_WITH_BIG_FLAT_SMALL_WIDTH, // Flat shape > 2/3, car width < 1.8m
	APA_SLOT_OBJ_COMP_TYPE_PER_CAR_WITH_SMALL_FLAT_NORMAL_WIDTH, // Flat shape < 1/3, car width = 1.8m ~ 2.3m
	APA_SLOT_OBJ_COMP_TYPE_PER_CAR_WITH_NORMAL_FLAT_NORMAL_WIDTH, // Flat shape = 1/3 ~ 2/3, car width = 1.8m ~ 2.3m
	APA_SLOT_OBJ_COMP_TYPE_PER_CAR_WITH_BIG_FLAT_NORMAL_WIDTH, // Flat shape > 2/3, car width = 1.8m ~ 2.3m
	APA_SLOT_OBJ_COMP_TYPE_PER_CAR_WITH_SMALL_FLAT_BIG_WIDTH, // Flat shape < 1/3, car width > 2.3m
	APA_SLOT_OBJ_COMP_TYPE_PER_CAR_WITH_NORMAL_FLAT_BIG_WIDTH, // Flat shape = 1/3 ~ 2/3, car width > 2.3m
	APA_SLOT_OBJ_COMP_TYPE_CAR_ANGULAR_NEG_10DEG_RISING_SHAPE_AT_START,
	APA_SLOT_OBJ_COMP_TYPE_CAR_ANGULAR_NEG_10DEG_FLAT_SHAPE_AT_START,
	APA_SLOT_OBJ_COMP_TYPE_CAR_ANGULAR_10DEG_RISING_SHAPE_AT_START,
	APA_SLOT_OBJ_COMP_TYPE_CAR_ANGULAR_10DEG_FLAT_SHAPE_AT_START,
	APA_SLOT_OBJ_COMP_TYPE_PARALLEL_CAR_WITH_SMALL_RISING_SHAPE, // rising width < 20cm,
	APA_SLOT_OBJ_COMP_TYPE_PARALLEL_CAR_WITH_NORMAL_RISING_SHAPE, // rising width < 40cm,
	APA_SLOT_OBJ_COMP_TYPE_PARALLEL_CAR_WITH_BIG_RISING_SHAPE, // rising width < 60cm.
	APA_SLOT_OBJ_COMP_TYPE_PARALLEL_CAR_WITH_VERY_BIG_RISING_SHAPE // rising width > 60cm.
	
} APASlotObjProfileCompensateType;

typedef enum {
	APA_CAR_CORNER_FR_INDEX = 0,
	APA_CAR_CORNER_FL_INDEX,
	APA_CAR_CORNER_RL_INDEX,
	APA_CAR_CORNER_RR_INDEX
} tAPACarCornerIndexType;

typedef enum {
	APAParkProcPECarEndPosCarWillNotHitFrontCornerObj = 0,
	APAParkProcPECarEndPosParallelToFrontObj	
} tAPAParkProcParkExitCarEndPosModeType;

typedef enum {
	APA_SLOT_DT_FAILED_BY_NO_FAILURE = 0,
	APA_SLOT_DT_FAILED_BY_INVALID_FRONT_OBJECT,
	APA_SLOT_DT_FAILED_BY_INVALID_REAR_OBJECT,
	APA_SLOT_DT_FAILED_BY_SLOT_LENGTH_TOO_SMALL,
	APA_SLOT_DT_FAILED_BY_SIDE_OBJECT_TOO_CLOSE
} APASlotDetectFailCausesType;  //add 20200826 by yjm (pp&uss)

typedef enum {
	APATrajCalPointIsAtAboveOfLine = 0, // Only used when line is horizontal.
	APATrajCalPointIsAtUnderOfLine, // Only used when line is horizontal.
	APATrajCalPointIsAtLeftOfLine, // Used when line is vertical or incline.
	APATrajCalPointIsAtRightOfLine, // Used when line is vertical or incline.
	APATrajCalPointIsOnLine // Point is on line with a tollerance.
} tAPATrajCalPointAndLineRelerativePosType;  //add 20200827 by yjm (pp&uss)

/*************************************************************************************************************************************************
**                                                              Global Type Definitions                                                         **
*************************************************************************************************************************************************/
typedef unsigned char    byte;
typedef unsigned char    uchar;
typedef unsigned char    BOOLEAN;
typedef unsigned char    UCHAR;
typedef unsigned char    BOOL;
typedef unsigned char    UINT8;
typedef unsigned char    UBYTE;
typedef unsigned char    VUINT8;
typedef unsigned char    APA_SPEAKER_CHIME_DELAY_TIMER_TYPE;


typedef signed char      SBYTE;
typedef signed char      SINT8;
typedef signed char      schar;
typedef signed char      VINT8;
typedef signed char      APA_ENUM_TYPE;
typedef signed char      SDG_ENUM_TYPE;
typedef signed char      SDG_SLOT_PT_SLOPE_TYPE;
typedef signed char      APA_SLOT_PT_SLOPE_TYPE;
typedef signed char      APA_INDEX_TYPE;

typedef unsigned short/*int*/   word;
typedef unsigned short/*int*/   WORD;
typedef unsigned short          UINT16;
typedef unsigned short          USHORT;
typedef unsigned short          VUINT16;
typedef unsigned short          APA_SPEED_WORD_TYPE;
typedef unsigned short          APA_MS_TIME_TYPE;

typedef signed short    SSHORT;
typedef signed short    SINT16;
typedef signed short    VINT16;
typedef short           SDG_DISTANCE_TYPE;
typedef short           SDG_TIMES_TYPE;
typedef short           APA_DISTANCE_TYPE;
typedef short           APA_TIMES_TYPE;
typedef short           APA_WEIGHT_COEFFICIENT_TYPE;
typedef short           SDG_WEIGHT_COEFFICIENT_TYPE;
typedef signed short    APA_SLOT_ID_TYPE;
typedef signed short    APA_SLOT_PT_SLOPE_CAL_TYPE;

typedef int                              APA_CAL_INT_TYPE;
typedef unsigned long   				 UINT32;
typedef unsigned long 			         VUINT32;
typedef unsigned long 					 DWORD;
typedef unsigned long 					 dword;
typedef unsigned long      			     ulong;

typedef signed long   					 SINT32;
typedef signed long 				     VINT32;
typedef signed long        			     slong;
typedef signed long                      APA_INT_TYPE;
typedef signed long                      APA_DISTANCE_CAL_INT_TYPE;
// typedef signed int                      APA_DISTANCE_CAL_INT_TYPE;

typedef unsigned long long			     UINT64;
typedef unsigned long long 		         VUINT64;

typedef signed long long				 SINT64;
typedef signed long long 			     VINT64;

typedef long double 				     ddword;
typedef long double 					 DDWORD;

typedef float	                         APA_SPEED_TYPE;
typedef float	                         APA_SPEED_CAL_FLOAT_TYPE;
typedef float                            APA_ANGLE_TYPE;
typedef float                            APA_S_TIME_CAL_FLOAT_TYPE;
typedef float                            APA_RATIO_TYPE;
typedef float	                         APA_DISTANCE_CAL_FLOAT_TYPE;
typedef float	                         APA_ANGLE_CAL_FLOAT_TYPE;
typedef float                            APA_CAL_FLOAT_TYPE;
typedef float 							 SDG_ANGLE_TYPE;
typedef float							 SDG_SPEED_TYPE;
typedef float							 SDG_SPEED_CAL_FLOAT_TYPE;
typedef float							 SDG_DISTANCE_CAL_FLOAT_TYPE;
typedef float 							 SDG_CAL_FLOAT_TYPE;
typedef word                             SIA_ERROR_FLAG_TYPE;
typedef word                             APA_CAR_POS_WHEEL_PULSE_CNT_TYPE;
typedef dword                            APA_CAR_POS_WHEEL_PULSE_CNT_CAL_TYPE;

typedef union 
{
	byte bt;
	struct 
    {
		byte  BIT0        :1;
		byte  BIT1        :1;
		byte  BIT2        :1;
		byte  BIT3        :1;
		byte  BIT4        :1;
		byte  BIT5        :1;
		byte  BIT6        :1;
		byte  BIT7        :1;
	} Bits;
} tAPAByteBitType;

typedef union 
{
	word Word;
	struct 
    {
		word  BIT0        :1;
		word  BIT1        :1;
		word  BIT2        :1;
		word  BIT3        :1;
		word  BIT4        :1;
		word  BIT5        :1;
		word  BIT6        :1;
		word  BIT7        :1;
		word  BIT8        :1;
		word  BIT9        :1;
		word  BIT10       :1;
		word  BIT11       :1;
		word  BIT12       :1;
		word  BIT13       :1;
		word  BIT14       :1;
		word  BIT15       :1;
	} Bits;
} tAPAWordBitType;

/*Public data structure definitions*/
#ifndef _TAGPOINTFLOAT_ST
#define _TAGPOINTFLOAT_ST
typedef struct TagPoint_ST
{
	float32 f32XMtr;
	float32 f32YMtr;
}Point_ST;
#endif

#ifndef _TAGPOSEFLOAT_ST
#define _TAGPOSEFLOAT_ST
typedef struct TagPose_ST
{
	float32 f32XMtr;
	float32 f32YMtr;
	float32 f32ARad;
}Pose_ST;
#endif

#ifndef _TAGLINEABCFLOAT_ST
#define _TAGLINEABCFLOAT_ST
typedef struct TagLineABC_ST
{
	float32 f32A;
	float32 f32B;
    float32 f32C;
}LineABC_ST;
#endif

#ifndef _TAGLINEKBFLOAT_ST
#define _TAGLINEKBFLOAT_ST
typedef struct TagLineKB_ST
{
	float32 f32K;
	float32 f32B;
}LineKB_ST;
#endif

typedef union {
	dword SlotCorrectionFlag;  // For slot process internal use only
	struct {
		dword Obj2XHasBeenCorrectedAtTurningAroundObj2 : 1;
		dword Obj2XHasbeenCorrectedWhenObj2DoesNotExist : 1;
		dword Obj2YHasBeenCorrectedDueToRRCMayHitObj2 : 1;
		dword InhibitUsingCarMayHitObj2CorMethod : 1;
		dword InhibitUsingCarMayHitObj1CorMethod : 1;
		dword Obj1YHasBeenCorrectedDueToRLCMayHitObj1 : 1;
		dword APAEndterActiveState : 1;
		dword ParkProcReqSlotBorderLineCorrect : 1;
		dword Obj2UseSDGBufToCorIsEnalbed : 1;
		dword SlotBorderLineHasBeenCorrected : 1;
		dword ParkProcReqSlotBorderLineCorrectConfirmed : 1;
		dword bCarPrevDrvDirIsBackwards : 1;
		dword ObjExistCheckCarHasDrvnOutOfSlotWithCarAngAlmostAch : 1;
		dword Obj2YHasBeenCorrected : 1;
		dword Obj1YHasBeenCorrected : 1;
		dword LeftSideLineHasBeenCorrected : 1;
		dword RightSideLineHasBeenCorrected : 1;
		dword RightSideLineCanNotBeCorrected : 1;
		dword LeftSideLineCanNotBeCorrected : 1;
		dword RightAndLeftSideLineCanNotBeCorrectedEndPosLineReseted : 1;
		dword ConvexShapeFitCarPosMinHasBeenReached : 1;
		dword ConvexShapeFitCarPosMaxHasBeenReached : 1;
		dword ResetLeftSideSlotBorderLineCheck : 1;
		dword ResetRightSideSlotBorderLineCheck : 1;
		dword EndPosYHasBeenCorrectedToOffsetFromObj1 : 1;
		dword reserved1 : 7;
	} Bits;
} tAPASlotCorrectionFlagType; //Need to check with USS Luhui 20200804

typedef union {
	byte CarInSlotCarMayHitObj1Or2Flag;
	struct {
		byte Reserved : 4;
		byte CarInSlotRearBumperCloseToObj1Or2 : 1;
		byte CarInSlotFrontBumperCloseToObj1Or2 : 1;
		byte CarInSlotRearBumperHitObj1Or2 : 1;
		byte CarInSlotFrontBumperHitObj1Or2 : 1;
	} Bits;
} tAPACarInSlotCarMayHitObj1Or2FlagType;


typedef union 
{
	dword APACalFlagType;
	struct
	{
		dword bAPASlotCorPCorObj1YCheckHasBeenCorrectedDueToRLCMayHitObj1		:1;
		dword reserved	:31;
 	} Bits;
}tAPACalFlag2Type;

typedef union
{
	dword APACarParFlag1;
	struct
    {
		dword bAPADistanceOverFlow												:1;
		dword bAPATrajectoryCalResultChecked									:1;
		dword bAPAParkExitModeConfirmed											:1;
		dword bAPAParkModeChanged												:1;
		dword bAPAVehicleSpeedIsValid											:1;
		dword bCarIsDrivingBackwards											:1;
		dword bSlotDataIsMirrorChanged											:1;	///dsh 20120727
		dword bCarPosCalWheelPlsCntrMissUpdatedFlagIsSet						:1;
		
		// Added to discard the previous detected slot and start a new slot searching process start 20140303
		//dword reserved															:1;
		dword bAPAParkProcClearSlotAfterSlotFoundTimerOn						:1;
		// Added to discard the previous detected slot and start a new slot searching process end 20140303
		
		dword bParkProcAPATrajCalDriveStraightlyFirstStep						:1;
		dword bParkProcAPATrajCalInSlotFirstStepAllowUseGivenTurningRadius		:1;
		dword bParkProcAPATrajCalUseTheCurSteeringAngToCal						:1;
		dword bParkProcAPATrajCalTargetDriveDirectionIsForward					:1;
		dword bParkProcCarIsInTheSlotCarEndPosCanBeAchievedWithCurSteeringAng	:1;
		dword bParkProcCarIsInTheSlotCarEndPosCanBeAchievedWithCurStepData		:1;
		dword bParkProcCarIsInTheSlotSteeringCtrlCorrected						:1;
		dword bParkProcLastStepSteeringWheelReturnToZero						:1;
		dword bParkProcLastStepSteeringWheelReqReturnToZero						:1;
		dword bParkProcCarIsInTheSlotCriteria1									:1;
		dword bParkProcParkingLimitSpeed										:1;
		dword bParkProcCurrentStepDriveDirectionForward							:1;
		dword bParkProcKeepCurrentSlotAndCarPosition							:1;
		dword bParkProcDriveDirectionChange										:1;
		dword bParkProcRecalculatingTrajectory									:1;
		dword bParkProcCurrentCarOnCalTrajectory								:1;
		dword bParkProcSteeringWheelIsTurning									:1;
		dword bParkProcCarEndPosAngleAchieved									:1;
		dword bParkProcSaveParkingParIntoEEPROM									:1;
		dword bParkProcSaveMaxParkVehilceSpeedIntoEEPROM						:1;
		dword bParkProcSlotFoundReqReSetUpSystemCoordinate						:1;
		dword bSlotProcSlotObj2Exist											:1;
		dword bSlotProcSlotObj1Exist											:1;
	}Bits;
}tAPACarParFlag1Type;

typedef union
{
	byte APACarParFlag2;
	struct
    {
		byte bParkProcAPATrajCalNextTargetDriveDirectionIsForward				:1;
		byte bParkProcAPATrajCalInslotLastStepInhibitUseCorStep					:1;
		byte bParkProcAPATrajCalInslotLastStepUseCorStepCalculated				:1;
		byte bParkProcPrevDesiredDrvDirIsFw										:1;
		byte bAPACalCarPosBiDirWhlSpeSnsSignalInvalid							:1;
		byte bAPACalCarPosWhlPlsPerRevIsCorrect									:1;
		byte bAPAODIParkingModeHaveBeenSelectedViaDisplayInfoByDriver		    :1;
		byte bAPAParkProcSupportUnknownMode						                :1; // dsh 20140324
	}Bits;
}tAPACarParFlag2Type;

typedef struct 
{
	APA_DISTANCE_TYPE x;
	APA_DISTANCE_TYPE y;
} APACoordinateDataType;

typedef struct 
{
	APA_DISTANCE_CAL_FLOAT_TYPE x;
	APA_DISTANCE_CAL_FLOAT_TYPE y;
} APACoordinateDataCalFloatType;

typedef struct 
{
	// Line equation: AX + BY + C = 0;
	// One line at least 1m.
	// LineType: Incline: Y = AX + C; Y = KX + C;
	//           Vertical X = C;
	//           Horizontal Y = C;

	APALineIsVerticalOrHorizontalType LineType;
	APA_DISTANCE_CAL_FLOAT_TYPE A;
	APA_DISTANCE_CAL_FLOAT_TYPE B;
	APA_DISTANCE_CAL_FLOAT_TYPE C;
} APALineParameterABCType;

typedef struct 
{
	// Line equation: Y = KX + B;
	// One line at least 1m.	
	APA_DISTANCE_CAL_FLOAT_TYPE K;
	APA_DISTANCE_CAL_FLOAT_TYPE B;
} APALineParameterKBType;

typedef struct 
{
	APACoordinateDataType Coordinate;
	APA_ANGLE_TYPE CarAng;
} APACarCoordinateDataType;

typedef struct 
{
	APACoordinateDataCalFloatType Coordinate;
	APA_ANGLE_CAL_FLOAT_TYPE CarAng;
} APACarCoordinateDataCalFloatType;

typedef struct 
{
	APA_DISTANCE_TYPE RSObjDis; // Obj detected by the R side sns. dis from 20cm ~ 200cm
	APA_DISTANCE_TYPE RObjDis; // Obj detected by the R corner sns. dis from 20cm ~ 200cm
	APA_DISTANCE_TYPE MidObjDis; // Obj detected by the RM, LM, R tx RM Rx, RM tx R Rx, L tx LM rx, LM tx L rx. UPA FOV.
	APA_DISTANCE_TYPE LObjDis; // Obj detected by the L corner sns. dis from 20cm ~ 200cm
	APA_DISTANCE_TYPE LSObjDis; // Obj detected by the L side sns. dis from 20cm ~ 200cm
} APASnsDtdNearestObjDisRegionType;

typedef union 
{	
	 APASnsDtdNearestObjDisRegionType NearestDis;
	 APA_DISTANCE_TYPE Dis[APA_SNS_DTD_NEAREST_OBJ_DIS_REGION_NUM];
} APASnsDtdNearestObjDisInfoType;

typedef struct 
{
	APASnsDtdNearestObjDisInfoType ObjDis[APA_PARKPROC_SUPPORT_MAX_SYS_DT_MIN_DIS_NUM];
	APA_SPEED_TYPE ObjSpeed[5];
} APASnsDtdNearestObjDisBufAndObjSpeedDataType;

typedef struct 
{
	APACoordinateDataType CarCenterPoint[APA_SLOT_SUPPORT_FRONT_SIDE_MAX_SAMPLE_POINT_NUM]; // Car center point. 
	APA_DISTANCE_TYPE DisFromCarToObj[APA_SLOT_SUPPORT_FRONT_SIDE_MAX_SAMPLE_POINT_NUM]; // Slot outline point. 
	//APA_DISTANCE_TYPE SnsDtSmallBkWaveDis[APA_SLOT_SUPPORT_FRONT_SIDE_MAX_SAMPLE_POINT_NUM];
	APACoordinateDataType ObjPt[APA_SLOT_SUPPORT_FRONT_SIDE_MAX_SAMPLE_POINT_NUM];
	APA_ANGLE_TYPE CarAng[APA_SLOT_SUPPORT_FRONT_SIDE_MAX_SAMPLE_POINT_NUM];
	UCHAR bObjIsBigEnough[APA_SLOT_SUPPORT_FRONT_SIDE_MAX_SAMPLE_POINT_NUM]; // Bit0: bObjTypeIsBigEnough. Bit1: bCurbTypeIsBigEnough.
	UCHAR CarSpeed[APA_SLOT_SUPPORT_FRONT_SIDE_MAX_SAMPLE_POINT_NUM]; // km/h
	//APA_ENUM_TYPE ObjType[APA_SLOT_SUPPORT_FRONT_SIDE_MAX_SAMPLE_POINT_NUM];
	UCHAR WrIndex;
	APA_ENUM_TYPE ObjPtCnt;   //added by dsh 20120310
} APASlotOutlineCoordinateDataType;        ///modified by DSH 2012.2.13

typedef union 
{
	APASlotOutlineCoordinateDataType Lane;  //
	UCHAR Data[sizeof(APASlotOutlineCoordinateDataType)];
} APASlotOutlineDataType;

typedef struct 
{
	APACoordinateDataType CarCenterPointRSns[APA_SLOT_SUPPORT_REAR_SIDE_MAX_SAMPLE_POINT_NUM]; // Car center point. 
	APA_DISTANCE_TYPE DisFromCarToObjRSns[APA_SLOT_SUPPORT_REAR_SIDE_MAX_SAMPLE_POINT_NUM]; // Slot outline point. 
	APACoordinateDataType ObjPtRSns[APA_SLOT_SUPPORT_REAR_SIDE_MAX_SAMPLE_POINT_NUM];
	APA_ANGLE_TYPE CarAngRSns[APA_SLOT_SUPPORT_REAR_SIDE_MAX_SAMPLE_POINT_NUM];
	UCHAR bObjIsBigEnoughRSns[APA_SLOT_SUPPORT_REAR_SIDE_MAX_SAMPLE_POINT_NUM];
	UCHAR CarSpeedRSns[APA_SLOT_SUPPORT_REAR_SIDE_MAX_SAMPLE_POINT_NUM];
	UCHAR RemoveIndex;//WrIndexRSns;
	APA_ENUM_TYPE ObjPtCntRSns;
	APA_ENUM_TYPE APASlotRearSideSnsCheckCurbPrevValidCurbPtNum;
	APA_SLOT_PT_SLOPE_TYPE APASlotRearSideSnsCheckCurbPrevValidCurbPtSlope;	
} APASlotOutlineDtcdByRearSideSnsCoordinateDataType;

typedef union 
{
	APASlotOutlineDtcdByRearSideSnsCoordinateDataType LaneDetectedByRearSideSensor;  //
	UCHAR DataDetectedByRearSideSensor[sizeof(APASlotOutlineDtcdByRearSideSnsCoordinateDataType)];	
} APASlotOutlineRearSensorDetectedDataType;

typedef struct 
{
	APA_ENUM_TYPE APASlotPCorDeltaAngZoneNum;
	APA_ANGLE_CAL_FLOAT_TYPE APASlotPCorDeltaAngArray[APA_SLOT_COR_DELTA_ANG_MAX_ZONE_NUM];
} APASlotPCorRROrRLSnsDeltaAngInfo;

typedef struct 
{
	APA_ENUM_TYPE APASlotPCorSideSnsDeltaAngZoneNum;
	APA_ANGLE_CAL_FLOAT_TYPE APASlotPCorSideSnsDeltaAngArray[APA_SLOT_COR_RRS_RLS_DELTA_ANG_MAX_ZONE_NUM];
} APASlotPCorRRSOrRLSSnsDeltaAngInfo;

typedef struct 
{
	APACoordinateDataCalFloatType Coordinate;
	APA_DISTANCE_CAL_FLOAT_TYPE DisToCarCenter;
	APA_DISTANCE_CAL_FLOAT_TYPE DisToCarCenterSquare;
	APA_ANGLE_TYPE Ang;
	APA_DISTANCE_CAL_FLOAT_TYPE MinInnerTurningRadius;
	APA_DISTANCE_CAL_FLOAT_TYPE MinOuterTurningRadius;
} APATrajCalPointOnCarPosDataCalFloatType;


/*************************************************************************************************************************************************
**                                                              Global Constant Declarations                                                    **
*************************************************************************************************************************************************/

/*************************************************************************************************************************************************
**                                                              Global Variable Declarations                                                    **
*************************************************************************************************************************************************/

/*************************************************************************************************************************************************
**                                                              Global Function Declarations                                                    **
*************************************************************************************************************************************************/

/*************************************************************************************************************************************************
**                                                              Global Inline Function Definitions                                              **
*************************************************************************************************************************************************/


/*************************************************************************************************************************************************
**                                                              End of file                                                                     **
*************************************************************************************************************************************************/

#endif /* APACOMMONTYPE_H_ */

