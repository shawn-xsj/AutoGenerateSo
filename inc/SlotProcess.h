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
**  $FILENAME   :  APASlotProcess.h $                                                                                                           **
**                                                                                                                                              **
**  $CC VERSION : \main\94 $                                                                                                                    **
**                                                                                                                                              **
**  $DATE       : 2020-06-xx $                                                                                                                  **
**                                                                                                                                              **
**  AUTHOR      : SAIC - US Group -Engineering                                                                                                  **
**                                                                                                                                              **
**  VENDOR      : SAIC Technologies                                                                                                             **
**                                                                                                                                              **
**  DESCRIPTION : This file contains                                                                                                            **
**                - USS slot main function declarations                     ..                                                                  **
**                                                                                                                                              **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                                                                                        **
**                                                                                                                                              **
*************************************************************************************************************************************************/
#ifndef _APASLOTPROCESS_H_
#define _APASLOTPROCESS_H_

/*************************************************************************************************************************************************
**                                                              Includes                                                                        **
*************************************************************************************************************************************************/
#include "Platform_Types.h"
#include "APACommonType.h"
#include "SlotProcessDataType.h"

/*************************************************************************************************************************************************
**                                                              Global Macro Definitions                                                        **
*************************************************************************************************************************************************/

#define APA_SLOT_VEHICLE_STATIC_UPDATE_SLOT_PT_TIME		                                (1000 / 40) // 1s.
#define APA_SLOT_VEHICLE_STATIC_MAX_TIME				                                0x7e
#define APA_SLOT_SAMPLE_PT_NO_OBJ_DIS_PT_REMOVE_MIN_SLOT_LEN							(4000) // mm
//#define APA_SLOT_SAMPLE_POINT_BEFORE_SLOT_DT											(40)
#define APA_SLOT_NO_SLOT_DETECTED														(0)// mm
//#define APA_SLOT_START_TO_COMPENSATE_SLOT_END_POS_DIS_TO_MIN_PATH_AFTER_SLOT			(500) // mm,  50cm Notes: it should less than
// APACal.APASlotDisToCarCheckCarDrvDis  and APACal.APASlotMinPathAfterSlot and great than the 2 * max compensate dis.
//#define APA_SLOT_DIS_TO_CAR_CHECK_CAR_TRAVELLING_DIS_1									(500) // mm
#define APA_SLOT_DIS_TO_CAR_CHECK_CAR_TRAVELLING_DIS_REGARD_NO_OBJ1OR2					(APACal.APASlotMaxSlotLength) // mm
//#define APA_SLOT_CURB_DETECTION_DEPTH_TOL												(500) // mm
//#define APA_SLOT_POINT_CAN_BE_REMOVED_CONTIGUOUS_POINT_MIN_DIS							(3500) // mm
//#define APA_SLOT_POINT_CAN_BE_REMOVED_CONTIGUOUS_POINT_MIN_DIS_AP						(1000) // mm
//#define APA_SLOT_BORDER_POINT_CAN_BE_REMOVED_CONTIGUOUS_POINT_MIN_DIS					(1500) // mm
//#define APA_SLOT_BORDER_POINT_CAN_BE_REMOVED_CONTIGUOUS_POINT_MIN_DIS_AP				(800) // mm
//#define APA_SLOT_BORDER_POINT_CAN_BE_REMOVED_CONTIGUOUS_POINT_MIN_DIS_P				(600) // mm
#define APA_SLOT_SENSOR_HFOV_MAX_DT_DIS													(5000)
#define APA_SLOT_SENSOR_HFOV_DIVIDED_SEG_DIS											(APA_SLOT_SENSOR_HFOV_MAX_DT_DIS / APA_SLOT_APA_SENSOR_HFOV_DIVIDED_SEG_NUM)
#define APA_SLOT_SENSOR_DT_ONE_LOOP_TIME_MS												(40) // unit: ms, 40ms.
#define APA_SLOT_NUMBER_OF_DT_TIMES_CAL_MIN_SPD											(1.0 / 3.6) // 1km/h
#define APA_SLOT_MAX_NUMBER_OF_DT_TIMES													(55)
//#define APA_SLOT_SUPPORT_SLOT_BORDER_INFLEXTION_NUM										(APA_SLOT_SUPPORT_SLOT_BORDER_LINE_NUM * 2)	// 8 * 1m = 8m....
//#define APA_SLOT_REGARD_AS_THE_FIRST_SLOT_DEPTH_MIN_SLOT_LEN							(APACal.APASlotMinSmallSlotLen) // 5600.

// used for angular parking slot searching
// #define APA_SLOT_ANGULAR_SLOT_INFLEXTION_OFFSET_DISTANCE								(1000) // 1M
// #define APA_SLOT_ANGULAR_SLOT_INFLEXTION_CONFIRM_LENGTH									(1000) // 1M
// #define APA_SLOT_ANGULAR_SLOT_INFLEXTION_CONFIRM_LENGTH_WITH_NO_OBJ_IN_MID				(2000) // 1M
// #define APA_SLOT_MIN_TWO_ANGULAR_SLOT_BORDER_LINE_DELTA_HIGHT_BETWEEN_HEAD_AND_TAIL		(2000) // 2M : ????? To be confirmed in the real car test.
// #define APA_SLOT_WITHOUT_OBJ12_SLOT_LEN_COMP_MAX_DELTA_CAR_ANG							(20.0 * PI / 180.0) // 20deg.
// #define APA_SLOT_WITHOUT_OBJ12_SLOT_LEN_COMP_MAX_LEN									(700) // 70cm

#define APA_SLOT_OBJ_TYPE_CHECK_OBJ_PT_BUF_NUM						    (25)
#define APA_SLOT_OBJ_TYPE_CHECK_CAL_SLOPE_ALLOW_MIN_PT_TO_PT_DIS	    (30)  // 3cm,
#define APA_SLOT_OBJ_TYPE_CHECK_CAL_SLOPE_ALLOW_MAX_PT_TO_PT_DIS	    (5000)  // 5m,

#define APA_SLOT_OBJ_PT_CHECK_CAL_SLOPE_ALLOW_MIN_PT_TO_PT_DIS		    (10)  // 1cm,
#define APA_SLOT_OBJ_PT_CHECK_CAL_SLOPE_ALLOW_MAX_PT_TO_PT_DIS		    (5000)  // 5m,

/********************* ONLY USED IN SEARCHING SLOT END ********************/

#define INVALID_APA_SLOT_BUFFER_VALUE_INDEX							    ( -1)

// Slot par cor start

// Parallel parking in
// Cor Obj2.Y Par:
#define APA_SLOT_PAL_OBJ2Y_CORRECT_RANGE_CAR_POS_X_MIN1				    (-500) // -2m
#define APA_SLOT_PAL_OBJ2Y_CORRECT_RANGE_CAR_POS_X_MAX1				    (USSPar.TrajCalCarEndPos.Coordinate.x + APACal.WidthOfCar) // mm

#define APA_SLOT_PAL_OBJ2Y_CORRECT_RANGE_CAR_POS_Y_MIN1				    (USSPar.TrajCalObj1Pos.y)
#define APA_SLOT_PAL_OBJ2Y_CORRECT_RANGE_CAR_POS_Y_MAX1				    (USSPar.TrajCalObj2Pos.y - (APACal.LenBetweenRAxisAndFBumper / 2))
#define APA_SLOT_PAL_OBJ2Y_CORRECT_RANGE_CAR_POS_Y_MAX2				    (USSPar.TrajCalObj2Pos.y - APACal.LenBetweenRAxisAndFBumper)

#define APA_SLOT_PAL_OBJ2Y_CORRECT_RANGE_CAR_POS_ANG_MIN1				(-30.0 * PI / 180.0) // 3deg. when the car is very close to the obj2
#define APA_SLOT_PAL_OBJ2Y_CORRECT_RANGE_CAR_POS_ANG_MAX1				(20.0 * PI / 180.0) // 40deg.
#define APA_SLOT_PAL_OBJ2Y_CORRECT_RANGE_CAR_POS_ANG_MAX2				(60.0 * PI / 180.0) // 60deg.

#define APA_SLOT_PAL_OBJ2Y_COR_USE_MID_SNS_CAR_POS_ANG_MAX1				(12.0 * PI / 180.0) // 15deg.
#define APA_SLOT_PAL_OBJ2Y_COR_OBJ2Y_MAX1								(2500) // 2.5m
#define APA_SLOT_PAL_OBJ2Y_COR_OBJ2Y_MIN1								(-2500) // 2.5m

#define APA_SLOT_PAL_OBJ2Y_CORRECT_TOL_DIS								(1500) // 1.5 m
#define APA_SLOT_PAL_OBJ2Y_COR_USE_COR_SNS_COR_MAX_SNS_TO_SIDE_DIS		(600) // 60cm.

// Cor Obj1.Y Par:
#define APA_SLOT_PAL_OBJ1Y_CORRECT_RANGE_CAR_POS_X_MIN1				    (-500) // -2m
#define APA_SLOT_PAL_OBJ1Y_CORRECT_RANGE_CAR_POS_X_MAX1				    (USSPar.TrajCalCarEndPos.Coordinate.x + 800) // mm

#define APA_SLOT_PAL_OBJ1Y_CORRECT_RANGE_CAR_POS_Y_MIN1				    (-APACal.APASlotMaxSlotLength)
#define APA_SLOT_PAL_OBJ1Y_CORRECT_RANGE_CAR_POS_Y_MAX1				    (- 1000)
#define APA_SLOT_PAL_OBJ1Y_CORRECT_RANGE_CAR_POS_Y_MAX2				    (USSPar.TrajCalObj2Pos.y - APACal.LenBetweenRAxisAndFBumper)

#define APA_SLOT_PAL_OBJ1Y_CORRECT_RANGE_CAR_POS_ANG_MIN1				(-30.0 * PI / 180.0) // 3deg. when the car is very close to the obj2
#define APA_SLOT_PAL_OBJ1Y_CORRECT_RANGE_CAR_POS_ANG_MAX1				(20.0 * PI / 180.0) // 40deg.
#define APA_SLOT_PAL_OBJ1Y_CORRECT_RANGE_CAR_POS_ANG_MAX2				(60.0 * PI / 180.0) // 60deg.

#define APA_SLOT_PAL_OBJ1Y_COR_USE_MID_SNS_CAR_POS_ANG_MAX1				(12.0 * PI / 180.0) // 15deg.
#define APA_SLOT_PAL_OBJ1Y_COR_USE_COR_SNS_COR_MAX_SNS_TO_SIDE_DIS		(600) // 60cm.
#define APA_SLOT_PAL_OBJ1Y_COR_OBJ1Y_MAX1								(2500 - APACal.LengthOfCar) // 2.5m
#define APA_SLOT_PAL_OBJ1Y_COR_OBJ1Y_MIN1								(USSPar.TrajCalObj2Pos.y - APACal.APASlotMaxSlotLength) // 2.5m

#define APA_SLOT_PAL_OBJ1Y_CORRECT_TOL_DIS								(1500) // 1.5 m

// Perpendicular parking in


#define APA_SLOT_PER_OBJ2X_CORRECT_RANGE_CAR_POS_X_MIN									(-2000) // -2m
#define APA_SLOT_PER_OBJ2X_CORRECT_RANGE_CAR_POS_X_MAX									(USSPar.TrajCalObj2Pos.x) // mm
#define APA_SLOT_PER_OBJ2X_CORRECT_RANGE_CAR_POS_X_MAX2									2000 // mm

#define APA_SLOT_PER_OBJ2X_CORRECT_RANGE_CAR_POS_Y_MIN1									(USSPar.TrajCalObj2Pos.y) // -2m
#define APA_SLOT_PER_OBJ2X_CORRECT_RANGE_CAR_POS_Y_MIN2									(0) // -1m
#define APA_SLOT_PER_OBJ2X_CORRECT_RANGE_CAR_POS_Y_MIN3									(USSPar.TrajCalObj1Pos.y) // -1m
#define APA_SLOT_PER_OBJ2X_CORRECT_RANGE_CAR_POS_Y_MAX									(3000) // 3m

#define APA_SLOT_PER_OBJ2X_CORRECT_RANGE_CAR_POS_ANG_MIN1								(-10.0 * PI / 180.0) // -10deg.
#define APA_SLOT_PER_OBJ2X_CORRECT_RANGE_CAR_POS_ANG_MAX1								(30.0 * PI / 180.0) // 30deg.
#define APA_SLOT_PER_OBJ2X_CORRECT_RANGE_CAR_POS_ANG_MIN2								(10.0 * PI / 180.0) // 10deg.
#define APA_SLOT_PER_OBJ2X_CORRECT_RANGE_CAR_POS_ANG_MAX2								(150.0 * PI / 180.0) // 150deg.
#define APA_SLOT_PER_OBJ2X_CORRECT_RANGE_OBJ_DIS_MAX									(1500) // 1.5m
#define APA_SLOT_PER_OBJ2X_CORRECT_OBJ_X_MAX											(3000) // 1m
#define APA_SLOT_PER_OBJ2X_CORRECT_OBJ_X_MIN											(-1000) // -0.5m

#define APA_SLOT_PER_OBJ1_OBJ2_REGARD_AS_EXIST_X_MIN									(1500) // 1m

#define APA_SLOT_PER_START_CHECK_OBJ_EXIST_END_POS_DELTA_X								(1000) // 1m
#define APA_SLOT_PER_START_CHECK_OBJ_EXIST_REGARD_CAR_OUT_OF_SLOT_X_MIN					(- APACal.LenBetweenRAxisAndRBumper - 300) // -1.3 m
#define APA_SLOT_PER_START_CHECK_OBJ_EXIST_REGARD_END_POS_ALMOST_ACH_DELTA_CAR_ANG		(30.0 * PI / 180.0)

// For Obj2Y Correct At Turning Around Obj2 :
#define APA_SLOT_PER_OBJ2Y_CORRECT_RANGE_CAR_MAY_HIT_OBJ2_CAR_POS_X_MIN1				(-2000) // -2m
#define APA_SLOT_PER_OBJ2Y_CORRECT_RANGE_CAR_MAY_HIT_OBJ2_CAR_POS_X_MAX1				(USSPar.TrajCalObj2Pos.x) // mm

#define APA_SLOT_PER_OBJ2Y_CORRECT_RANGE_CAR_MAY_HIT_OBJ2_CAR_POS_Y_MIN1				(USSPar.TrajCalObj2Pos.y - 1000) // -0.5m
#define APA_SLOT_PER_OBJ2Y_CORRECT_RANGE_CAR_MAY_HIT_OBJ2_CAR_POS_Y_MIN2				(- 500) // -0.5m
#define APA_SLOT_PER_OBJ2Y_CORRECT_RANGE_CAR_MAY_HIT_OBJ2_CAR_POS_Y_MAX1				(2000) // 2m

#define APA_SLOT_PER_OBJ2Y_CORRECT_RANGE_CAR_MAY_HIT_OBJ2_CAR_POS_ANG_MIN1				(3.0 * PI / 180.0) // 3deg. when the car is very close to the obj2
#define APA_SLOT_PER_OBJ2Y_CORRECT_RANGE_CAR_MAY_HIT_OBJ2_CAR_POS_ANG_MAX1				(90.0 * PI / 180.0) // 60deg. when the car is far away from the obj2.


#define APA_SLOT_PER_OBJ2Y_CORRECT_RANGE_CAR_POS_X_MIN1									(-2000) // -2m
#define APA_SLOT_PER_OBJ2Y_CORRECT_RANGE_CAR_POS_X_MIN2									(USSPar.TrajCalObj2Pos.x - APACal.LenBetweenRAxisAndRBumper) // mm
#define APA_SLOT_PER_OBJ2Y_CORRECT_RANGE_CAR_POS_X_MAX1									(USSPar.TrajCalObj2Pos.x) // mm
#define APA_SLOT_PER_OBJ2Y_CORRECT_RANGE_OBJ_PT_X_MIN1									(USSPar.TrajCalObj2Pos.x) // mm

#define APA_SLOT_PER_OBJ2Y_CORRECT_RANGE_CAR_POS_Y_MIN1									(- 3000)
#define APA_SLOT_PER_OBJ2Y_CORRECT_RANGE_CAR_POS_Y_MAX1									(2000) // 2m

#define APA_SLOT_PER_OBJ2Y_CORRECT_RRS_CAL_COMPENSATE_DELTA_CAR_POS_Y_MIN				(- 400) // -40cm

#define APA_SLOT_PER_OBJ2Y_CORRECT_RANGE_CAR_POS_ANG_MIN1								(3.0 * PI / 180.0) // 3deg. when the car is very close to the obj2
#define APA_SLOT_PER_OBJ2Y_CORRECT_RANGE_CAR_POS_ANG_MAX1								(110.0 * PI / 180.0) // 110deg. when the car is far away from the obj2.
#define APA_SLOT_PER_OBJ2Y_CORRECT_OBJ_Y_MAX											(1500) // 1m ??
#define APA_SLOT_PER_OBJ2Y_CORRECT_OBJ_Y_MIN											(-1500) // -1m ???
#define APA_SLOT_PER_OBJ2Y_CORRECT_HFOV_COMPENSATE_DIS									(400) // 0.4 m
#define APA_SLOT_PER_OBJ1Y_CORRECT_TOL_DIS												(1500) // 1.5 m

// For Obj1Y Correct At Turning Around Obj1 :
#define APA_SLOT_PER_OBJ1Y_CORRECT_RANGE_CAR_POS_X_MIN1									(-2000) // -2m
#define APA_SLOT_PER_OBJ1Y_CORRECT_RANGE_CAR_POS_X_MAX2									(1500) // 1.5m

#define APA_SLOT_PER_OBJ1Y_CORRECT_RANGE_CAR_POS_ANG_MAX1								(110.0 * PI / 180.0) // 110deg. when the car is far away from the obj2.



#define APA_SLOT_PER_OBJ1Y_CORRECT_RANGE_CAR_POS_X_MIN1									(-2000) // -2m
#define APA_SLOT_PER_OBJ1Y_CORRECT_RANGE_CAR_POS_X_MAX1									(USSPar.TrajCalObj1Pos.x + 2500) // mm
#define APA_SLOT_PER_OBJ1Y_CORRECT_RANGE_OBJ_PT_X_DELTA_DIS1							(300) // mm
#define APA_SLOT_PER_OBJ1Y_CORRECT_RANGE_OBJ_PT_X_DELTA_DIS2							(600) // mm
#define APA_SLOT_PER_OBJ1Y_CORRECT_RANGE_OBJ_PT_X_DELTA_DIS3							(800) // mm

#define APA_SLOT_PER_OBJ1Y_CORRECT_RANGE_CAR_POS_Y_MIN1									(- 4000) // -4m.
#define APA_SLOT_PER_OBJ1Y_CORRECT_RANGE_CAR_POS_Y_MAX1									(-200) // -0.2m
#define APA_SLOT_PER_OBJ1Y_CORRECT_RANGE_CAR_POS_ANG_MIN1								(3.0 * PI / 180.0) // 3deg. when the car is very close to the obj2
#define APA_SLOT_PER_OBJ1Y_CORRECT_RANGE_CAR_POS_ANG_MAX1								(110.0 * PI / 180.0) // 110deg. when the car is far away from the obj2.




// For Obj1Y, Obj2Y Correct At Turning Around Obj1 :
#define APA_SLOT_PER_OBJ1Y_OBJ2Y_CORRECT_RANGE_CAR_POS_X_MIN1							(-2000) // -0.8m
#define APA_SLOT_PER_OBJ1Y_OBJ2Y_CORRECT_RANGE_CAR_POS_X_MIN3							(-800) // -0.8m
#define APA_SLOT_PER_OBJ1Y_OBJ2Y_CORRECT_RANGE_CAR_POS_X_MAX1							(2000) // 1.0m

#define APA_SLOT_PER_OBJ1Y_OBJ2Y_CORRECT_RANGE_CAR_POS_Y_MIN1							(USSPar.TrajCalObj1Pos.y) // -0.8m
#define APA_SLOT_PER_OBJ1Y_OBJ2Y_CORRECT_RANGE_CAR_POS_Y_MIN3							(-800) // -0.8m
#define APA_SLOT_PER_OBJ1Y_OBJ2Y_CORRECT_RANGE_CAR_POS_Y_MAX1							(0) // 0m
#define APA_SLOT_PER_OBJ1Y_OBJ2Y_CORRECT_RANGE_CAR_POS_Y_MAX3							(- 400) // -0.4m

#define APA_SLOT_PER_OBJ1Y_OBJ2Y_CORRECT_RANGE_CAR_POS_ANG_MIN1							(10.0 * PI / 180.0) // 60deg. when the car is very close to the obj2
#define APA_SLOT_PER_OBJ1Y_OBJ2Y_CORRECT_RANGE_CAR_POS_ANG_MIN3							(20.0 * PI / 180.0) // 20deg. when the car is very close to the obj2
#define APA_SLOT_PER_OBJ1Y_OBJ2Y_CORRECT_RANGE_CAR_POS_ANG_MAX1							(120.0 * PI / 180.0) // 120deg. when the car is far away from the obj2.
#define APA_SLOT_PER_OBJ1Y_OBJ2Y_CORRECT_RANGE_OBJ_DELTA_DIS_MAX1						(1800) // 1m // For 2m long car dis, it can detect delta car angle and border line angle less than 26deg.
#define APA_SLOT_PER_OBJ1Y_OBJ2Y_CORRECT_RANGE_RM_R_SNS_MIN_DELTA_DIS					(400) // 40cm
#define APA_SLOT_PER_OBJ1Y_OBJ2Y_CORRECT_RANGE_OBJ2_COR_MAX_RR_DIS1						(800) // 80cm
#define APA_SLOT_PER_OBJ1Y_OBJ2Y_CORRECT_RANGE_OBJ2_COR_MAX_RRS_DIS1					(800) // 80cm
#define APA_SLOT_PER_OBJ1Y_OBJ2Y_CORRECT_RANGE_OBJ2_COR_MAX_RR_DIS2						(1200) // 120cm
#define APA_SLOT_PER_OBJ1Y_OBJ2Y_CORRECT_RANGE_OBJ2_COR_MAX_RRS_DIS2					(1200) // 120cm
#define APA_SLOT_PER_OBJ1Y_OBJ2Y_CORRECT_RANGE_OBJ2_COR_MAX_RL_DIS1						(1500) // 150cm
#define APA_SLOT_PER_OBJ1Y_OBJ2Y_CORRECT_RANGE_OBJ2_COR_MAX_RLS_DIS1					(1500) // 150cm

#define APA_SLOT_PER_OBJ1Y_OBJ2Y_CORRECT_RANGE_CAR_POS_X_DIVIDE_VALUE					(APACal.SnsPos[APA_RRS_SNS_INDEX].y) // -0.7m

#define APA_SLOT_PER_OBJ1Y_CORRECT_OBJ_Y_MAX											(- 1000) // -1m ??
#define APA_SLOT_PER_OBJ1Y_CORRECT_OBJ_Y_MIN											(-APACal.APASlotPMaxSlotLength) // -5m ???

// For Obj1Y, Obj2Y Correct Entering the slot :
#define APA_SLOT_PER_OBJ1Y_OBJ2Y_CORRECT_RANGE_CAR_POS_X_MIN2							(-2300) // -2.3m ,, -1.5m
#define APA_SLOT_PER_OBJ1Y_OBJ2Y_CORRECT_RANGE_CAR_POS_X_MAX2							(4500) // 4.5m

#define APA_SLOT_PER_OBJ1Y_OBJ2Y_CORRECT_MAX_CAR_POS_OBJ2Y_DELTA_DIS					(1400) // 1.4m
#define APA_SLOT_PER_OBJ1Y_OBJ2Y_CORRECT_OBJ2Y_COR_RRS_DIS1								(1000) // 1m
#define APA_SLOT_PER_OBJ1Y_OBJ2Y_CORRECT_OBJ2Y_COR_RR_DIS1								(1000) // 1m
#define APA_SLOT_PER_OBJ1Y_OBJ2Y_CORRECT_OBJ2Y_COR_RRS_DIS2								(2000) // 1m
#define APA_SLOT_PER_OBJ1Y_OBJ2Y_CORRECT_OBJ2Y_COR_RR_DIS2								(1500) // 1m
#define APA_SLOT_PER_OBJ1Y_OBJ2Y_CORRECT_OBJ2Y_COR_MAX_DELTA_CAR_ANG1					(40.0 * PI / 180.0) // 20deg. when the car is very close to the obj2

#define APA_SLOT_PER_OBJ1Y_OBJ2Y_CORRECT_RANGE_CAR_POS_Y_MIN2							(USSPar.TrajCalObj1Pos.y - 1000) // -0.8m
#define APA_SLOT_PER_OBJ1Y_OBJ2Y_CORRECT_RANGE_CAR_POS_Y_MAX2							(2500) // 2.5 m

#define APA_SLOT_PER_OBJ1Y_OBJ2Y_CORRECT_RANGE_CAR_POS_ANG_MIN2							(20.0 * PI / 180.0) // 20deg. when the car is very close to the obj2
#define APA_SLOT_PER_OBJ1Y_OBJ2Y_CORRECT_RANGE_CAR_POS_ANG_MAX2							(160.0 * PI / 180.0) // 160deg. when the car is far away from the obj2.

#define APA_SLOT_PER_IN_SLOT_SLOT_BORDER_LINE_FIT_MAX_CAR_POS_X							(USSPar.TrajCalCarEndPos.Coordinate.x) // (APACal.LenBetweenRAxisAndFBumper) // 3m 
#define APA_SLOT_PER_IN_SLOT_SLOT_BORDER_LINE_FIT_MAX_DELTA_CAR_POS_X					(2500) // 2.0m 
#define APA_SLOT_PER_IN_SLOT_SLOT_BORDER_LINE_MAX_K_VALUE								(2.74748) // 70deg. 
#define APA_SLOT_PER_ENDPOSY_CLOSE_TO_OBJ1_OR_OBJ2_COR_MIN_X							(APA_SLOT_PER_OBJ1Y_OBJ2Y_CORRECT_RANGE_CAR_POS_X_MAX1 - 500) // x = 50cm

#define APA_SLOT_PER_SDG_SNS_DT_OBJ_DATA_RESET_CAR_POS_X_MIN							(-500) // -0.5m
#define APA_SLOT_PER_SDG_SNS_DT_OBJ_DATA_RESET_CAR_POS_Y_MAX							(0) // 0m
#define APA_SLOT_PER_SDG_SNS_DT_OBJ_DATA_RESET_CAR_POS_ANG_MIN							(45.0 * PI / 180.0) // 24degm

#define APA_SLOT_PER_IN_SLOT_OBJ2_NOT_EXIST_OBJ1_BORDERLINE_FIT_MAX_X1					(1700) // 1.72m
#define APA_SLOT_PER_IN_SLOT_OBJ2_NOT_EXIST_OBJ1_BORDERLINE_FIT_MIN_X1					(0) // 0cm

#define APA_SLOT_PER_OBJ1Y_OBJ2Y_HIT_REAR_BUMPER_CHECK_CAR_POS_ANG_MIN1					(10.0 * PI / 180.0) // 20deg. 
#define APA_SLOT_PER_OBJ1Y_OBJ2Y_HIT_REAR_BUMPER_CHECK_CAR_POS_ANG_MAX1					(170.0 * PI / 180.0) // 160deg
#define APA_SLOT_PER_OBJ1Y_OBJ2Y_HIT_REAR_BUMPER_CHECK_CAR_POS_X_MIN1					(- 1500) 
#define APA_SLOT_PER_OBJ1Y_OBJ2Y_HIT_REAR_BUMPER_CHECK_CAR_POS_X_MAX1					(APACal.LengthOfCar)

#define APA_SLOT_PER_OBJ1Y_OBJ2Y_HIT_REAR_BUMPER_CHECK_CAR_POS_Y_MIN1					(USSPar.TrajCalObj1Pos.y - 1000) 
#define APA_SLOT_PER_OBJ1Y_OBJ2Y_HIT_REAR_BUMPER_CHECK_CAR_POS_Y_MAX1					(1000)

#define APA_PARKPROC_CAR_END_POSITION_REDTM_SLOT_TOL1									(1200)
#define APA_PARKPROC_CAR_END_POSITION_REDTM_SLOT_TOL2									(600)

#define APA_SLOT_REAR_SIDE_SNS_DT_CURB_PT_FIT_CAR_DRV_PATH_MIN_DIS						(2000) // 2m.

/*
Obj shape index:
0: Unknown, invalid shape, do not fit.	
1: Convex: left side object (obj1)
2: Concave: right side object (obj2)
3: OK Line
4: line with convex at head
5: line with convex at mid
6: line with convex at tail
7: line with concave at head.
8: line with concave at mid
9: line with concave at tail
*/

typedef enum {

	APASlotPObjShape_Unknown = 0,
	APASlotPObjShape_Convex,	// 1
	APASlotPObjShape_Concave,   // 2
	APASlotPObjShape_OKLine,    // 3
	APASlotPObjShape_LineWithCovexAtHead,  // 4
	APASlotPObjShape_LineWithCovexAtMid,   // 5
	APASlotPObjShape_LineWithCovexAtTail,  // 6
	APASlotPObjShape_LineWithConcaveAtHead, // 7
	APASlotPObjShape_LineWithConcaveAtMid,  // 8
	APASlotPObjShape_LineWithConcaveAtTail  // 9
	
} tAPASlotPObjShapeType;

typedef enum {

	APASlotObjPtNoiseCheckType_Noise = 0,
	APASlotObjPtNoiseCheckType_Obj
	
} tAPASlotObjPtNoiseCheckType;

/*************************************************************************************************************************************************
**                                                              Global Type Definitions                                                         **
*************************************************************************************************************************************************/

/*************************************************************************************************************************************************
**                                                              Global Variable Declarations                                                    **
*************************************************************************************************************************************************/
extern APASlotSnsDtdObjPtBufType APASnsDtdObjPtBuf[4];


#if 1//Debug_SW_ExeTimeTest
extern uint32 Task_USSExeTimeTest[4];

#endif
extern uint8 u8USS_CutSteps;
extern APACarCoordinateDataCalFloatType CarCenterPtBackUp;
#if 1//Debug_SW_COUNTLOOP
extern uint16 iscurb_cnt[5][2]; /*iscurb_cnt[i][0]: current frame cnt;iscurb_cnt[i][1]: max cnt during the process*/
#endif
/*************************************************************************************************************************************************
**                                                              Global Function Declarations                                                    **
*************************************************************************************************************************************************/
APA_ENUM_TYPE APASlotProcCheckSlotObjTypePerpendicularCarTypeCheck(
	APA_ENUM_TYPE EndOfObj,
	APA_DISTANCE_TYPE ObjTotalWidth,
	APA_DISTANCE_TYPE FlatShapeWidth,
	APA_DISTANCE_TYPE RisingShapeWidth,
	APA_SLOT_PT_SLOPE_TYPE ObjAverageSlope,
	APA_SLOT_PT_SLOPE_TYPE StartPtSlope
);
APA_ENUM_TYPE APASlotProcCheckSlotObjTypeParallelOrAngularCarTypeCheck(
	APA_ENUM_TYPE EndOfObj,
	APA_DISTANCE_TYPE ObjTotalWidth,
	APA_DISTANCE_TYPE FlatShapeWidth,
	APA_DISTANCE_TYPE RisingShapeWidth,
	APA_SLOT_PT_SLOPE_TYPE ObjAverageSlope,
	APA_SLOT_PT_SLOPE_TYPE StartPtSlope
);


APACoordinateDataCalFloatType APASlotProcCalObjPtCoordinateBySnsDtdDis(
    APA_DISTANCE_TYPE SnsDtdDis,
    APA_ANGLE_CAL_FLOAT_TYPE AngBetObjAndSnsCenterLine,
    UCHAR SnsIndex);

BOOLEAN APASlotProcSlotMeasuringTask(void);

/*************************************************************************************************************************************************
**                                                              Global Inline Function Definitions                                              **
*************************************************************************************************************************************************/


/*************************************************************************************************************************************************
**                                                              End of file                                                                     **
*************************************************************************************************************************************************/
#endif  /* _APASLOTPROCESS_H_ */
