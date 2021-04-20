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
**                                                                                                                                               **
**  $FILENAME   : APACalibration.c $                                                                                                            **
**                                                                                                                                              **
**  $CC VERSION : \main\94 $                                                                                                                    **
**                                                                                                                                              **
**  $DATE       : 2020-08-18 $                                                                                                                  **
**                                                                                                                                              **
**  AUTHOR      : SAIC - CH-Engineering                                                                                                         **
**                                                                                                                                              **
**  VENDOR      : SAIC Technologies                                                                                                             **
**                                                                                                                                              **
**  DESCRIPTION : This file contains                                                                                                            **
**                - APA common carlibration data setting                                                                                        **
**                                                                                                                                              **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                                                                                        **
**                                                                                                                                              **
*************************************************************************************************************************************************/

/*************************************************************************************************************************************************
**                                                     Includes
*************************************************************************************************************************************************/
#include "APACalibration.h"
#include "APACommonType.h"


/*************************************************************************************************************************************************
**                                                     Imported Compiler Switch Check                                                           **
*************************************************************************************************************************************************/
/**/

/*************************************************************************************************************************************************
**                                                     Private Macro Definitions                                                                **
*************************************************************************************************************************************************/
#define    __EP21__   1

/*************************************************************************************************************************************************
**                                                     Private Type Definitions                                                                 **
*************************************************************************************************************************************************/
/**/

/*************************************************************************************************************************************************
**                                                     Private Function Declarations                                                            **
*************************************************************************************************************************************************/
/**/


/*************************************************************************************************************************************************
**                                                     Global Constant Definitions                                                              **
*************************************************************************************************************************************************/
#define ALG_START_SEC_CONST_32BIT
#include "IS31_UserMemMap.h"

APACalibrationDataType const APACal = {  //ethan
/*2.4.1***Vehicle pararmeter****/
#if __EP21__
	4678, // APA_DISTANCE_TYPE LengthOfCar;
	1919, // APA_DISTANCE_TYPE WidthOfCar;
	959.5, // APA_DISTANCE_TYPE HalfWidthOfCar;
	1601, // APA_DISTANCE_TYPE FrontAxisLength;
	800.5, // APA_DISTANCE_TYPE HalfWidthOfFrontAxis;
	1602, // APA_DISTANCE_TYPE RearAxisLength;
	801, // APA_DISTANCE_TYPE HalfWidthOfRearAxis;
	2800, // APA_DISTANCE_TYPE LenBetweenFRAxis;
	921, // APA_DISTANCE_TYPE LenBetweenFAxisAndFBumper;
	3753, // APA_DISTANCE_TYPE LenBetweenRAxisAndFBumper;
	925, // APA_DISTANCE_TYPE LenBetweenRAxisAndRBumper;
#endif
	250, // 25cm, APA_DISTANCE_TYPE LenBetweenFrontRectCornerToFrontBumperCornerCurve;
	200, // 20cm, APA_DISTANCE_TYPE LenBetweenRearRectCornerToRearBumperCornerCurve;

	// APA_DISTANCE_TYPE WheelTireDiameter[MAX_TIRE_SIZE_NUM];		// unit:mm	added by zhx 20120925
	{
	(701),//(703),//C:2208.54 mm,//(708),//C:2225 mm ,
	(632 - 10),	// Tire size 2:(205/55R16)
	(643 - 10),	// Tire size 3:(215/55R16)
	(647 - 10),	// Tire size 4:(215/50R17)
	(634 - 10),	// Tire size 5:(225/45R17)
	(724 - 10),	// Tire size 6:(225/65R17)  ///D2UB 4XF26. Details refer to HEAD of the file.
	(637 - 10),	// Tire size 7:(225/40R18)
	(727 - 10),	// Tire size 8:(225/60R18)
	(717 - 10),	// Tire size 9:(235/50R19)///D2UB 4XG26
	(610 - 10),	// Tire size 10:()
	(717 - 10),	// Tire size 11:()
	(717 - 10),	// Tire size 12:()
	(717 - 10),	// Tire size 13:()
	(717 - 10),	// Tire size 14:()
	(717 - 10),	// Tire size 15:()
	(717 - 10),	// Tire size 16:()
	(717 - 10),	// Tire size 17:()
	(717 - 10),	// Tire size 18:()
	(717 - 10),	// Tire size 19:()
	(717 - 10),	// Tire size 20:()
	(717 - 10),	// Tire size 21:()
	(717 - 10),	// Tire size 22:()
	(717 - 10),	// Tire size 23:()
	(717 - 10),	// Tire size 24:()
	(717 - 10),	// Tire size 25:()
	(717 - 10),	// Tire size 26:()
	(717 - 10),	// Tire size 27:()
	(717 - 10),	// Tire size 28:()
	(717 - 10),	// Tire size 29:()
	(717 - 10),	// Tire size 30:()
	(717 - 10),	// Tire size 31:()
	(717 - 10)		// Tire size 32:()
	},

/*2.4.2***Sensor fixed information****/
	// APACoordinateDataType SnsPos[APA_SUPPORT_APA_SNS_NUM]; // relative to car rotation center
#if __EP21__
	{
		{
			919.2, //915.1,
			-417.5//-432.3
		},    //RRS
		{
			660, //660.4,
			-852.8//-784.2
		},    //RR
		{
			300, //280.4,
			-908.6//-904.5  //RRM
		},
		{
			-300, //-280.4,
			-908.6//-904.5//RLM
		},
		{
			-660, //-660.4,
			-852.8//-784.2 //RL
		},
		{
			-919.2, //-915.1,
			-417.5//-432.3 //RLS
		},


		{

			921.9, //913.1,//880,
			3190//3337.1//3120   //FRS
		},
		{
			721.0, //650.4,
			3453.2,//3528.7  //FR
		},
		{
			340,//320.3,
			3685.6//3673.9 //FRM
		},
		{
			-340, //-320.3,
			3685.6//3673.9 // FLM
		},
		{
			-721.0, //-650.5,
			3453.2 //3528.8 //FL
		},

		{
			-921.9, //-913.1,//-924,
			3190//3237.1//3082  //FLS
		}
			},

			///APA_ANGLE_TYPE SnsAng[APA_SUPPORT_APA_SNS_NUM]; // relative to car rotation center, (unit: radian)		
			{


				6.225589, //6.23082543,
				5.061455, //5.804965092,
				4.827581,  //4.822344723,
				4.597197, //4.602433238,
				4.363323,//4.234168765,
				3.199188,//3.193952531,



				0.040143, // 0.05235987756,//0.17453,   //      APACal.SnsAng[APA_FRS_SNS_INDEX] = 6.728 / 180.0 * PI;	
				1.282817, //0.8953539063,  //      APACal.SnsAng[APA_FR_SNS_INDEX]  = 37.453 / 180.0 * PI;
				1.43117, //1.246165086,  //      APACal.SnsAng[APA_FRM_SNS_INDEX] = 98.26 / 180.0 * PI;
				1.710423,//1.895427568, //      APACal.SnsAng[APA_FLM_SNS_INDEX] = 97.613 / 180.0 * PI;		
				1.858776,//2.246238747,  //      APACal.SnsAng[APA_FL_SNS_INDEX]  = 145.008/ 180.0 *PI;
				3.10145,//3.089232776//2.963569 //       APACal.SnsAng[APA_FLS_SNS_INDEX] = 173.192 / 180.0 * PI;//178.0 / 180.0 * PI;
			},

			// APA_ANGLE_CAL_FLOAT_TYPE SnsAngCos[APA_SUPPORT_APA_SNS_NUM];
			{


				0.998342,//0.9986295348,
				0.34202,// 0.8878153851,
				0.114937,// 0.1097343108,
				-0.11494,// -0.1097343106,
				-0.34202,// -0.4601997851,
				-0.99834,// -0.9986295348,



				0.999194, // 0.9986295348,
				0.284015, // 0.6252426563,
				0.139173,// 0.3189593092,
				-0.13917,// -0.3189593096,
				-0.28402,// -0.6252426561,
				-0.99919// -0.9986295348



			},
			// APA_ANGLE_CAL_FLOAT_TYPE SnsAngSin[APA_SUPPORT_APA_SNS_NUM];
			{
				-0.05756, //-0.05233595586,
				-0.93969, // -0.4601997849,
				-0.99337, // -0.9939609555,
				-0.99337, // -0.9939609555,
				-0.93969,// -0.887815385,
				-0.05756, // -0.05233595609,

				0.040132, // 0.05233595624,
				0.95882, // 0.7804304074,
				0.990268, // 0.94776841,
				0.990268, // 0.9477684099,
				0.95882, // 0.7804304075,
				0.040132 // 0.05233595627

			},

#endif
/*2.4.3***Switch Press time****/
	15000 / PA_PHY_SW_DT_TASK_CALL_CYCLE_TIME, // 15s, WORD wMaxAPAPhySwShortToGNDCnt;
	1500 / PA_PHY_SW_DT_TASK_CALL_CYCLE_TIME, // 1.5s, WORD wMaxAPAPhySwLongPressMinCnt;
    /*2.4.4***Speaker ****/
	// Luhui APA_SPEAKER_TYPE_FRONT_MASK, // APA_ENUM_TYPE APASpeakerType;
	500 / SPK_CHIME_TASK_CALL_TIME, // APA_SPEAKER_CHIME_DELAY_TIMER_TYPE APASpeakerReqChimeStartDelayTime;
	500 / SPK_CHIME_TASK_CALL_TIME, // APA_SPEAKER_CHIME_DELAY_TIMER_TYPE APASpeakerReqChimeStopDelayTime;	
/*2.4.5***apa state relatively ****/
	APA_CAR_PARK_AT_RIGHT_SIDE, // APA_ENUM_TYPE CarParkAtLeftOrRightSide; // Car park at left if true other wise park at right
// 	(
// 	APA_SUPPORT_FUNC_MODE_ParallelParkingIn
// 	| APA_SUPPORT_FUNC_MODE_PerpendicularlParkingIn
// 	// | APA_SUPPORT_FUNC_MODE_AngularParkingIn
// 	| APA_SUPPORT_FUNC_MODE_ParkingExit
// 	// | APA_SUPPORT_FUNC_MODE_SDG
// #ifdef APA_SYSTEM_WITH_10_CH
// #else
// 	| APA_SUPPORT_FUNC_MODE_SBSA
// #endif
// 	), // tAPAByteBitType _APASupportFunctionMode;
	
	(1000/SPK_CHIME_TASK_CALL_TIME), // APA_MS_TIME_TYPE APADisableCauseCheckDelayTime;

/*2.4.6***APA ODI ****/
	14,// APAFUCID
	//(1500/APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME), //APA_MS_TIME_TYPE APAODIInitialReqToGainIPCFocusWaitForIPCResponseTime; // modified by dsh 20140311
	//(1500/APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME),  //APA_MS_TIME_TYPE APAODIInitialReqToGainIPCFocusRetryDurationTime; // added by dsh 20140311	
	//(1000/APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME), // APA_MS_TIME_TYPE APAODIIndicationMsgTxOKAndIPCODIMultiReqDynDataRxTimeOutTime;
	//(1000/APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME), // APA_MS_TIME_TYPE APAODIMsgSendTimeOutTime;;
	//(1500 / APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME), //0xffff, // 0xffff = do not try to regain the IPC focus. APA_MS_TIME_TYPE APAODILoseIPCFocusRegainFocusDelayTime; // Note: if it is set to 0xffff, means will not try to regain the focus again and just treat as IPC focus not lost.
	//(250 / APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME),	// APA_MS_TIME_TYPE APAODILoseIPCFocusRegainFocusRetryDurationTime;
	2, // UCHAR APAODIEventMsgTxTryCntOfInitialGainIPCFocus; // modified by dsh 2014 03 11
	1, // UCHAR APAODIEventMsgTxTryCntOfRegainIPCFocus;// added by dsh 2014 03 11
	5, // UCHAR APAODIIndicationMsgTxTryCnt;,
	//(3000 / APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME), // APA_MS_TIME_TYPE APAODIAPAIsUnavailableIndicationCheckDelayTime; 
	//(0 / APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME), // 0: will not send false firstly, def: 100ms, APA_MS_TIME_TYPE APAODIAPAIsUnavailableIndicationFalseDurationTime; 
	//(3000 / APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME), // def: 120ms, 0xffff = always true. APA_MS_TIME_TYPE APAODIAPAIsUnavailableIndicationTrueDurationTime; 
	10, // UCHAR APAODIParkingProgressPercentageStep;	
	//(20 / APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME), // UCHAR APAODIParkingManueverProgressUpdateDelayTime;

	// calibration for infortainment
	//(1000/APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME), // APA_MS_TIME_TYPE APAODIInitialReqToGainICSFocusWaitForICSResponseTime; // Delay time of second retrying to request ICS Focus after APA first request to gain ICS forcus
	//(250/APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME), // APA_MS_TIME_TYPE APAODIInitialReqToGainICSFocusRetryDurationTime; // APA retry to request ICS focus try time.
	//(1500/APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME), // APA_MS_TIME_TYPE APAODILoseICSFocusRegainFocusDelayTime; // Note: if it is set to 0xffff, means will not try to regain the focus again and just treat as IPC focus not lost.
	//(250/APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME), // APA_MS_TIME_TYPE APAODILoseICSFocusRegainFocusRetryDurationTime; // APA retry to request ICS focus try time IN APA REGAIN FOCUS.
	2, // UCHAR APAODIEventMsgTxTryCntOfInitialGainICSFocus; // APA initial request ICS focus  try count
	1, // UCHAR APAODIEventMsgTxTryCntOfRegainICSFocus; // APA REGIAN ICS focus try count
//	5, // UCHAR APAODIIndicationMsgTxTryCntForICS; // APA INDICAITON msg try count.
/*2.4.7***boolean define ****/
#ifdef APA_SYSTEM_WITH_10_CH // tAPACalFlagType   APACalCommonFlags;

	#ifdef APA_WITH_NORMAL_CORNER_UPA_SNS_POSITION
	0x35fd108c,
	#else
		
	0x35fd168c,
	
	#endif
#else

	0xB7A41D8c,//0xB7A51D8c,//0x27B51D8c, // def: 0x17CD,
#endif	

 #ifdef APA_SYSTEM_WITH_10_CH //tAPACalFlag1Type APACalCommonFlags1;
// 	//0x000000FB,
 	0x000003F9, // Just for SKODA test. kjy 2014 06 09
 #else
 	//0x000000FB,
 	//0x000003F9, // Just for skoda test. kjy 2014 06 09
 #endif
/*
typedef union {
	dword APACalFlagType;
	struct{
		dword reserved	:31;
		dword bAPASlotCorPCorObj1YCheckHasBeenCorrectedDueToRLCMayHitObj1		:1;
 	} Bits;
}tAPACalFlag2Type;
*/
#ifdef APA_SYSTEM_WITH_10_CH // tAPACalFlag2Type APACalCommonFlags2;

	#ifdef APA_WITH_NORMAL_CORNER_UPA_SNS_POSITION

	0x00000000,
	
	#else
		
	0x00000000,
	
	#endif
#else

	0x00000001, //, 0x073c3dcd,	//0x010c3dcd,// 0x1dcd, // 0x15CD, // def: 0x17CD,
#endif	



/*2.4.8*** common use ****/

	1000, // car length + 1m, APA_DISTANCE_TYPE APAReduceZone1DisMaxDeltaSlotLen; // Car len + 1300.	

	APA_TRAJCAL_PARKEXIT_ALLOW_CAR_DRIVE_FORWARD_DIS_WITH_NO_OBJ_AT_FRONT,//APA_DISTANCE_TYPE PEAllowCarDriveForwardDisWithoutObjAtF;
	APA_TRAJCAL_PARKEXIT_ALLOW_CAR_DRIVE_BACKWARD_DIS_WITH_NO_OBJ_AT_REAR,//APA_DISTANCE_TYPE PEAllowCarDriveBackwardDisWithoutObjAtR;


#if __EP21__
	32.0 * PI / 180, // 35deg, APA_ANGLE_TYPE MaxSteeringWheelAngle; // (unit: radian)
	//28.0 * PI / 180, //APA_ANGLE_TYPE MaxSteeringWheelAngleBackward; //Add by wuzhen 0721  r=6
	//30.0 * PI / 180, //APA_ANGLE_TYPE MaxSteeringWheelAngleBackward; //Add by wuzhen 0721   r=5
#endif

#if __EP21__
	520.0 * PI / 180, // 540 deg, APA_ANGLE_TYPE MaxEPSSteeringWheelAngle; // (unit: radian) Ang < 0: turning right, Ang > 0: turning left.
#endif
	32.0 * 0.04 * PI / 180, // 2% of max steering angle, deg, APA_ANGLE_TYPE MaxSteeringWheelAngleTol; // (unit: radian) the tollerance between desired steering wheel angle and EPS steering angle.
//	1.0 * PI / 180, // 1 deg, APA_ANGLE_TYPE MaxSteeringWheelAngleTol2; // (unit: radian) the tollerance between desired steering wheel angle and EPS steering angle.
	1.0 / APA_RX_STEERING_WHEEL_ANGLE_CAL_FACTOR, // APA_ANGLE_TYPE APAControlledSteeringWheelAngleConvertFactor; // Convert the unit: rad to APA tx controlled steering wheel agnle (3D4).
	APA_RX_STEERING_WHEEL_ANGLE_CAL_FACTOR, // APA_ANGLE_TYPE APARxSteeringWheelAngleConvertFactor; //Convert the D0 (EPS Tx steering wheel angle) to unit: rad. APA_RX_STEERING_WHEEL_ANGLE_CAL_FACTOR
	// KJY Add 2012 7 23
	300.0, // 30cm, APA_DISTANCE_CAL_FLOAT_TYPE APAAllowWheelRotateDisMinTol1; // For different tire radius and pulse cnt, this value should be different.
	1000.0, // 1m, APA_DISTANCE_CAL_FLOAT_TYPE APAAllowWheelRotateDisMinTol2; // For different tire radius and pulse cnt, this value should be different.
	6000.0, // 6m, APA_DISTANCE_CAL_FLOAT_TYPE APAAllowWheelRotateDisMinTol3; // For different tire radius and pulse cnt, this value should be different.
	300.0,//APA_DISTANCE_CAL_FLOAT_TYPE APAWheelPulseNeedUpdateDis; //when the car position is not updated,and the wheel distance is more than NeedUpdateDis,then updated the car positon.

#if __EP21__
	1024,//SKODA: 1001, GM D2xx: 1024, APASupportMaxWheelPulseCnt;//for different type of cars,the supported max wheel pulse cnt would be different.
#endif
	3.0, // 3.0, m/s APA_SPEED_TYPE APACarPosCalMaxVehSpeedUpdateDeltaTol;  // unit. m/s considering update cycle: max 300ms and a = 10 m/s^2.
	100, //1000 / APA_CAR_POS_CALCULATION_TASK_CALL_CYCLE_TIME, // 1s, UCHAR APACarPosCalVehSpdMissToBeUpdatedRecoverTime;
	(0.03125 / 3.6), // unit: m/s. // APA_SPEED_CAL_FLOAT_TYPE APACarPosCalWheelSpeedCalFactorMeterPerSecond;
	(1.0 / 64.0), // APA_SPEED_CAL_FLOAT_TYPE APACarPosCalLongitudinalAccelerationPrimaryFactor;
	10.0, // 10m/s^2, APA_SPEED_CAL_FLOAT_TYPE APACarPosCalMaxVehLongitudinalAcceleration;
	(60 / APA_CAR_POS_CALCULATION_TASK_CALL_CYCLE_TIME), // at least: 60ms update one time, UCHAR APACarPosCalCarPosUpdateCycleTime;
	4, // UCHAR APACarPosCalWheelPulseCounterErrorRecoverCnt;
	(2000 / APA_CAR_POS_CALCULATION_TASK_CALL_CYCLE_TIME), // APA_MS_TIME_TYPE APACarPosCalMaxUseVehSpeedAndAccToEvaluateCarPosDurationTime;
	2000, // 2m. APA_DISTANCE_TYPE APACarPosCalMaxUseVehSpeedAndAccToEvaluateCarPosTotalDis1; // during auto parking.
	4000, // 4m. APA_DISTANCE_TYPE APACarPosCalMaxUseVehSpeedAndAccToEvaluateCarPosTotalDis2; // during searching slot mode.
	10000, // 10m. APA_DISTANCE_TYPE APACarPosCalMaxUseVehSpeedAndAccToEvaluateCarPosTotalDis3; // out of searching slot mode.
	400, // 40cm, APA_DISTANCE_CAL_FLOAT_TYPE APACarPosCalMaxCarPosCalUpdateDetalTolerance1; // speed < 10km/h
	1000, // 1m, APA_DISTANCE_CAL_FLOAT_TYPE APACarPosCalMaxCarPosCalUpdateDetalTolerance2; // speed < 40km/h
	6000, // 6m. APA_DISTANCE_CAL_FLOAT_TYPE APACarPosCalMaxCarPosCalUpdateDetalTolerance3; // speed > 40km/h

	(APA_SUPPORT_MAX_DISTANCE - 1000), // APA_DISTANCE_CAL_FLOAT_TYPE APACarPosCalAllowedCarPosXMax;
	(APA_SUPPORT_MAX_DISTANCE - 1000), // APA_DISTANCE_CAL_FLOAT_TYPE APACarPosCalAllowedCarPosYMax;
	2.8 * PI, // APA_ANGLE_CAL_FLOAT_TYPE APACarPosCalAllowedCarPosAngMax;

	2.0 * PI, // 360deg. APA_ANGLE_CAL_FLOAT_TYPE APACarPosCalAllowedCarPosAngMaxForParallelParking;
	- 2.0 * PI, // -360deg. APA_ANGLE_CAL_FLOAT_TYPE APACarPosCalAllowedCarPosAngMinForParallelParking;
	10000, // 10m, APA_DISTANCE_CAL_FLOAT_TYPE APACarPosCalAllowedCarPosXMaxForParallelParking;
	- 10000, // - 10m, APA_DISTANCE_CAL_FLOAT_TYPE APACarPosCalAllowedCarPosXMinForParallelParking;
	25000, // 25m, APA_DISTANCE_CAL_FLOAT_TYPE APACarPosCalAllowedCarPosYMaxForParallelParking;
	- 25000, // -25m, APA_DISTANCE_CAL_FLOAT_TYPE APACarPosCalAllowedCarPosYMinForParallelParking;
	2.0 * PI, // 360deg. APA_ANGLE_CAL_FLOAT_TYPE APACarPosCalAllowedCarPosAngMaxForPerpendicularParking;
	- 2.0 * PI, // -360deg. APA_ANGLE_CAL_FLOAT_TYPE APACarPosCalAllowedCarPosAngMinForPerpendicularParking;
	10000, // 10m, APA_DISTANCE_CAL_FLOAT_TYPE APACarPosCalAllowedCarPosXMaxForPerpendicularParking;
	- 20000, // - 20m, APA_DISTANCE_CAL_FLOAT_TYPE APACarPosCalAllowedCarPosXMinForPerpendicularParking;
	25000, // 25m, APA_DISTANCE_CAL_FLOAT_TYPE APACarPosCalAllowedCarPosYMaxForPerpendicularParking;
	- 25000, // -25m, APA_DISTANCE_CAL_FLOAT_TYPE APACarPosCalAllowedCarPosYMinForPerpendicularParking;

	1e10, // APA_DISTANCE_CAL_FLOAT_TYPE APASupportMaxCarTurningRadius; // def: 1e5, it is too small for traj cal. and will cause traj cal failure.
	250, // 25cm, APA_DISTANCE_CAL_FLOAT_TYPE APATrajCalLineTangentToCircleTolDis;//250 // 25cm //def: (10cm NG. it is too samll)
	30000, // changed by kjy 2014 07 26 from 30m to 20m. Rc > 30m,// APA_DISTANCE_CAL_FLOAT_TYPE APATrajCalMinAllowedDesireTangentOutSideButResultIsInSideTangentRadius;
	30000, // changed by kjy 2014 07 26 from 30m to 20m.  Rc > 30m, //APA_DISTANCE_CAL_FLOAT_TYPE APATrajCalMinAllowedDesireTangentInSideButResultIsOutSideTangentRadius;

	//UCHAR APAWheelPulsePerRevolution[APA_SUPPORT_WHEEL_PLUSE_COUNTER_NUM];
	// {
	// 96, // 86 for skoda
	// 96,
	// 96,
	// 96
	// },


	// Tire auto learning start
	
	80000, //49049, // 49049 = 2 km  382000 = 15km: 15000000.0 / (2 * PI * R / 48), R def to 30cm.	//APA_CAR_POS_WHEEL_PULSE_CNT_CAL_TYPE TireDiameterLearningOneLearningLoopStartCalTireFactorWheelPulseCnt; 2013 - 5- 13
	80, // APA_DISTANCE_TYPE TireDiameterLearningAllowedMaxTireDiameterTol; // max delta diameter for four tires, 8cm. R tol = 4cm.
	0.85, // APA_CAL_FLOAT_TYPE TireDiameterLearningAllowedMinFactor; // 0.85, if tol = 8cm, diameter = 630, it will be: 0.873.
	-7.0 * PI / 180.0, // -5deg. APA_ANGLE_CAL_FLOAT_TYPE TireDiameterLearningAllowedMinEPSAng; // -7deg.
	7.0 * PI / 180.0, // + 5deg. APA_ANGLE_CAL_FLOAT_TYPE TireDiameterLearningAllowedMaxEPSAng; // 7deg.

	60000, //30000, // APA_CAR_POS_WHEEL_PULSE_CNT_TYPE SteeringAngleOffsetLerningAllowedMaxWheelPulseCnt;
	50000, //25500, // 25500 * (PI * 600 / 48) = 1km,  APA_CAR_POS_WHEEL_PULSE_CNT_TYPE SteeringAngleOffsetLerningStartCheckMinWheelPulseCnt;
	1000, // 300 (steering angle = 20deg) = D2XX, 500 = SKODA, APA_CAL_FLOAT_TYPE SteeringAngleOffsetLerningAllowedMaxDeltaFLRRWheelPulseCnt;
	600, // 25 = D2XX, 35 = SKODA, 20 = D2XX, 30 = SKODA, APA_CAL_FLOAT_TYPE SteeringAngleOffsetLerningAllowedMaxDeltaFRRRWheelPulseCnt;
	400, // 20 = D2XX, 30 = SKODA,  10 = D2XX, 20 = SKODA, APA_CAL_FLOAT_TYPE SteeringAngleOffsetLerningDriveStraightlyMaxDeltaFLRRWheelPulseCnt;
	45, // 25, // 30, // // 25, 7 = D2XX, 10 = SKODA, // APA_CAL_FLOAT_TYPE SteeringAngleOffsetLerningCarTurningMinDeltaFLRRWheelPulseCnt;
	40, // 20, // 25, // 20, 5 = D2XX, 8 = SKODA, // APA_CAL_FLOAT_TYPE SteeringAngleOffsetLerningCarTurningMinDeltaRLRRWheelPulseCnt;
	-25, // -4 = D2XX, -4 = SKODA, APA_CAL_FLOAT_TYPE SteeringAngleOffsetLerningAllowedMinDeltaFRRRWheelPulseCnt;
	3.0, // APA_CAL_FLOAT_TYPE SteeringAngleOffsetLerningAllowedMinDeltaFRRRWheelPulseCntRatio;
	300, // 8 = D2XX, 16 = SKODA,  APA_CAL_FLOAT_TYPE SteeringAngleOffsetLerningAllowedMaxDeltaFLRLWheelPulseCnt;

	// APA_ANGLE_TYPE SteeringAngleOffsetLerningAllowedMaxOffsetSteeringAng[APA_STEER_WHEEL_TURNING_SIDE_NUM];  
	// {
	// 	// Turning Left,
	// 	(10.0 * PI / 180.0), // def: 2.15deg ?? 
	// 	// Right,
	// 	(10.0 * PI / 180.0) // def: 1.9deg ?? 
	// },
	// APA_ANGLE_TYPE SteeringAngleOffsetLerningAllowedMinOffsetSteeringAng[APA_STEER_WHEEL_TURNING_SIDE_NUM];  
	// {
	// 	// Turning Left,
	// 	(-10.0 * PI / 180.0), // def: 2.15deg ?? 
	// 	// Right,
	// 	(-10.0 * PI / 180.0) // def: 1.9deg ?? 
	// },
	// APA_ANGLE_TYPE SteeringAngleOffsetDefaultValue[APA_STEER_WHEEL_TURNING_SIDE_NUM];  // 2deg for steering wheel.
	// {
	// 	// Turning Left,
	// 	(0 * PI / 180.0), // def: 2.15deg ?? 
	// 	// Right,
	// 	(0 * PI / 180.0) // def: 1.9deg ?? 
	// },
	
	// Steering ratio learning
	30000, // APA_CAR_POS_WHEEL_PULSE_CNT_TYPE EPSSteeringWheelAngRatioLerningAllowedMaxWheelPulseCnt;
	// APA_CAR_POS_WHEEL_PULSE_CNT_TYPE EPSSteeringWheelAngRatioLerningStartCheckMinWheelPulseCnt[APA_STEER_WHEEL_TURNING_SIDE_NUM][APA_STEER_WHEEL_ANGLE_RATIO_DEVIDED_SEG_NUM];
	// {
		
	// 	// The following point is based on D2UB-S steer ratio data from GMNA.
	// 	// 	APASteeringWheelTurningSide_Left = 0,
	// 	{	
	// 		12800, // D2XX: 12800 = car drv 500m and turn: 180deg. steering angle = 15deg,	// 0		
	// 		2500, // D2XX: 2500 = car drv 92m and turn: 180deg. steering angle = 80deg.	// 1		
	// 		1200, // D2XX: 1200 = car drv 44m and turn: 180deg. steering angle = 170deg.	// 2		
	// 		1200, // D2XX: 1200 = car drv 42m and turn: 283deg. steering angle = 270deg.	// 3		
	// 		1200, // D2XX: 1200 = car drv 39m and turn: 360deg. steering angle = 360deg.	// 4		
	// 		920, // D2XX: 920 = car drv 27m and turn: 360deg. steering angle = 490deg.	// 5		
	// 		920, // D2XX: 920 = car drv 27m and turn: 360deg. steering angle = 490deg.	// 6		
	// 		920, // D2XX: 920 = car drv 27m and turn: 360deg. steering angle = 490deg.	// 7		
	// 		920, // D2XX: 920 = car drv 27m and turn: 360deg. steering angle = 490deg.	// 8		
	// 		920, // D2XX: 920 = car drv 27m and turn: 360deg. steering angle = 490deg.	// 9		
	// 		920, // D2XX: 920 = car drv 27m and turn: 360deg. steering angle = 490deg.	// 10		
	// 		920 // D2XX: 920 = car drv 27m and turn: 360deg. steering angle = 490deg.	// 11		
	// 	},
	// 	// 	APASteeringWheelTurningSide_Right = 1,
	// 	{	
	// 		12800, // D2XX: 12800 = car drv 500m and turn: 180deg. steering angle = 15deg,	// 0		
	// 		2500, // D2XX: 2500 = car drv 92m and turn: 180deg. steering angle = 80deg.	// 1		
	// 		1200, // D2XX: 1200 = car drv 44m and turn: 180deg. steering angle = 170deg.	// 2		
	// 		1200, // D2XX: 1200 = car drv 42m and turn: 283deg. steering angle = 270deg.	// 3		
	// 		1200, // D2XX: 1200 = car drv 39m and turn: 360deg. steering angle = 360deg.	// 4		
	// 		920, // D2XX: 920 = car drv 27m and turn: 360deg. steering angle = 490deg.	// 5		
	// 		920, // D2XX: 920 = car drv 27m and turn: 360deg. steering angle = 490deg.	// 6		
	// 		920, // D2XX: 920 = car drv 27m and turn: 360deg. steering angle = 490deg.	// 7		
	// 		920, // D2XX: 920 = car drv 27m and turn: 360deg. steering angle = 490deg.	// 8		
	// 		920, // D2XX: 920 = car drv 27m and turn: 360deg. steering angle = 490deg.	// 9		
	// 		920, // D2XX: 920 = car drv 27m and turn: 360deg. steering angle = 490deg.	// 10		
	// 		920 // D2XX: 920 = car drv 27m and turn: 360deg. steering angle = 490deg.	// 11		
	// 	}
	// },
	0.2, // 20% ?? or 10% ?? APA_CAL_FLOAT_TYPE EPSSteeringWheelAngRatioLerningAllowedMaxCarAngTolCalByTires;
	//EPSSteeringRatioLearningAlgorithm_MeanValueOfCaledRc, // APA_ENUM_TYPE EPSSteeringWheelAngRatioLerningAlgorithm;
	2.0 , // 2.0 / 15.0 = 13% tol, APA_CAL_FLOAT_TYPE EPSSteeringWheelAngRatioLerningAllowedMaxRatioTol;
	30, // 3cm, APA_DISTANCE_TYPE EPSSteeringWheelAngRatioLerningAllowedMaxRearHalfWidthTol;
	40, // 4cm, APA_DISTANCE_TYPE EPSSteeringWheelAngRatioLerningAllowedMaxFrontHalfWidthTol;
	0.15, // 15% ?? or 10% ?? APA_CAL_FLOAT_TYPE EPSSteeringWheelAngRatioLerningAllowedMaxTurningRadiusTolCalByTires;
	// APA_DISTANCE_TYPE EPSSteeringWheelAngRatioLerningCompensatedTurningRadius[APA_STEER_WHEEL_TURNING_SIDE_NUM][APA_STEER_WHEEL_ANGLE_RATIO_DEVIDED_SEG_NUM];
	// {
		
	// 	// The following point is based on D2UB-S steer ratio data from GMNA.
	// 	// 	APASteeringWheelTurningSide_Left = 0,
	// 	{	
	// 		-250, // D2XX: steering angle = 15deg,	// 0		
	// 		-200, // D2XX: steering angle = 80deg.	// 1		
	// 		-150, // D2XX: steering angle = 170deg.	// 2		
	// 		-100, // D2XX: steering angle = 270deg.	// 3		
	// 		-50, // D2XX: steering angle = 360deg.	// 4		
	// 		-40, // D2XX: steering angle = 490deg.	// 5		
	// 		-40, // D2XX: steering angle = 490deg.	// 6		
	// 		-40, // D2XX: steering angle = 490deg.	// 7		
	// 		-40, // D2XX: steering angle = 490deg.	// 8		
	// 		-40, // D2XX: steering angle = 490deg.	// 9		
	// 		-40, // D2XX: steering angle = 490deg.	// 10		
	// 		-40 // D2XX: steering angle = 490deg.	// 11		
	// 	},
	// 	// 	APASteeringWheelTurningSide_Right = 1,
	// 	{	
	// 		-250, // D2XX: steering angle = 15deg,	// 0		
	// 		-200, // D2XX: steering angle = 80deg.	// 1		
	// 		-150, // D2XX: steering angle = 170deg.	// 2		
	// 		-100, // D2XX: steering angle = 270deg.	// 3		
	// 		-50, // D2XX: steering angle = 360deg.	// 4		
	// 		-40, // D2XX: steering angle = 490deg.	// 5		
	// 		-40, // D2XX: steering angle = 490deg.	// 6		
	// 		-40, // D2XX: steering angle = 490deg.	// 7		
	// 		-40, // D2XX: steering angle = 490deg.	// 8		
	// 		-40, // D2XX: steering angle = 490deg.	// 9		
	// 		-40, // D2XX: steering angle = 490deg.	// 10		
	// 		-40 // D2XX: steering angle = 490deg.	// 11		
	// 	}
	// },

	//12, // 6 for D2UB, APA_ENUM_TYPE EPSSteeringWheelAngRatioSegNum; // max: APA_STEER_WHEEL_ANGLE_RATIO_DEVIDED_SEG_NUM

#if __EP21__
	// tAPASteeringWheelAngleRatioCalType EPSSteeringWheelAngRatio[APA_STEER_WHEEL_TURNING_SIDE_NUM][APA_SUPPORT_CAR_DRIVE_DIRECTION_NUM][APA_STEER_WHEEL_ANGLE_RATIO_DEVIDED_SEG_NUM];//added by lzc 2013 06 28
	// {
	// 	// The following point is based on D2UB-S steer ratio data from GMNA.
	// 	// 	APASteeringWheelTurningSide_Left = 0,
	// 	{	
	// 		// APACarDrvDir_Forward = 0,
	// 		{
	// 			// SYJ EPS Steering Ang, FrontAxis Center Turning Ang			   
	// 			{ 200.0 * PI / 180.0, PI / 180.0 * (12.2606850) }, // 0     		
	// 			{ 220.0 * PI / 180.0, PI / 180.0 * (13.4831944) }, // 1	   
	// 			{ 250.0 * PI / 180.0, PI / 180.0 * (15.3335466) }, // 2	   
	// 			{ 280.0 * PI / 180.0, PI / 180.0 * (17.2110634) }, // 3	   
	// 			{ 310.0 * PI / 180.0, PI / 180.0 * (19.1243267) }, // 4    
	// 			{ 340.0 * PI / 180.0, PI / 180.0 * (21.0823116) }, // 5    
	// 			{ 370.0 * PI / 180.0, PI / 180.0 * (23.0943756) }, // 6    
	// 			{ 400.0 * PI / 180.0, PI / 180.0 * (25.1701736) }, // 7   
	// 			{ 430.0 * PI / 180.0, PI / 180.0 * (27.3196087) }, // 8    
	// 			{ 460.0 * PI / 180.0, PI / 180.0 * (29.5527115) }, // 9   
	// 			{ 490.0 * PI / 180.0, PI / 180.0 * (31.8795338) }, // 10   
	// 			{ 500.0 * PI / 180.0, PI / 180.0 * (32.6776886) }  // 11  Max Physical Angle:519.4  500/519.4 = 96.26%
	// 		},

	// 		// APACarDrvDir_Backward    // 1,
	// 		{
	// 			//SYJ EPS Steering Ang, FrontAxis Center Turning Ang			   
	// 			{ 200.0 * PI / 180.0, PI / 180.0 * (12.3565226) }, // 0  
	// 			{ 220.0 * PI / 180.0, PI / 180.0 * (13.5833693) }, // 1  
	// 			{ 250.0 * PI / 180.0, PI / 180.0 * (15.4459667) }, // 2  
	// 			{ 280.0 * PI / 180.0, PI / 180.0 * (17.3466339) }, // 3  
	// 			{ 310.0 * PI / 180.0, PI / 180.0 * (19.2987175) }, // 4   
	// 			{ 340.0 * PI / 180.0, PI / 180.0 * (21.3162346) }, // 5  
	// 			{ 370.0 * PI / 180.0, PI / 180.0 * (23.4138260) }, // 6  
	// 			{ 400.0 * PI / 180.0, PI / 180.0 * (25.6066647) }, // 7  
	// 			{ 430.0 * PI / 180.0, PI / 180.0 * (27.9103413) }, // 8  
	// 			{ 460.0 * PI / 180.0, PI / 180.0 * (30.3406868) }, // 9  
	// 			{ 490.0 * PI / 180.0, PI / 180.0 * (32.9135284) }, // 10 
	// 			{ 500.0 * PI / 180.0, PI / 180.0 * (33.8055038) }  // 11  Max Physical Angle:519.4  500/519.4 = 96.26% 
	// 		}
	// 	},
	// 	// 	APASteeringWheelTurningSide_Right = 1,
	// 	{	
	// 		// APACarDrvDir_Forward = 0,
	// 		{
	// 			//SYJ EPS Steering Ang, FrontAxis Center Turning Ang
	// 			{ 200.0 * PI / 180.0, PI / 180.0 * (11.8711605) }, // 0	
	// 			{ 220.0 * PI / 180.0, PI / 180.0 * (13.1007938) }, // 1	
	// 			{ 250.0 * PI / 180.0, PI / 180.0 * (14.9696512) }, // 2		
	// 			{ 280.0 * PI / 180.0, PI / 180.0 * (16.8719254) }, // 3		
	// 			{ 310.0 * PI / 180.0, PI / 180.0 * (18.8124142) }, // 4  
	// 			{ 340.0 * PI / 180.0, PI / 180.0 * (20.7960453) }, // 5     
	// 			{ 370.0 * PI / 180.0, PI / 180.0 * (22.8278408) }, // 6  
	// 			{ 400.0 * PI / 180.0, PI / 180.0 * (24.9128857) }, // 7     
	// 			{ 430.0 * PI / 180.0, PI / 180.0 * (27.0562611) }, // 8        
	// 			{ 460.0 * PI / 180.0, PI / 180.0 * (29.2630005) }, // 9   
	// 			{ 490.0 * PI / 180.0, PI / 180.0 * (31.5379639) }, // 10   		
	// 			{ 500.0 * PI / 180.0, PI / 180.0 * (32.3122673) }, // 11	Max Physical Angle:524.4  500/524.4 = 95.35%  			
	// 		},
			
	// 		// APACarDrvDir_Backward    // 1,
	// 		{
	// 			//SYJ EPS Steering Ang, FrontAxis Center Turning Ang
	// 			{ 200.0 * PI / 180.0, PI / 180.0 * (12.1708918) }, // 0		
	// 			{ 220.0 * PI / 180.0, PI / 180.0 * (13.3853083) }, // 1		
	// 			{ 250.0 * PI / 180.0, PI / 180.0 * (15.2285299) }, // 2		
	// 			{ 280.0 * PI / 180.0, PI / 180.0 * (17.1075439) },  // 3     
	// 			{ 310.0 * PI / 180.0, PI / 180.0 * (19.0340252) }, // 4      
	// 			{ 340.0 * PI / 180.0, PI / 180.0 * (21.0202179) }, // 5
	// 			{ 370.0 * PI / 180.0, PI / 180.0 * (23.0788918) }, // 6
	// 			{ 400.0 * PI / 180.0, PI / 180.0 * (25.2232723) }, // 7     
	// 			{ 430.0 * PI / 180.0, PI / 180.0 * (27.4669456) }, // 8
	// 			{ 460.0 * PI / 180.0, PI / 180.0 * (29.8236980) }, // 9  
	// 			{ 490.0 * PI / 180.0, PI / 180.0 * (32.3073158) }, // 10	
	// 			{ 500.0 * PI / 180.0, PI / 180.0 * (33.1657410) }  // 11	Max Physical Angle:524.4  500/524.4 = 95.35%
	// 		}
	// 	}
	// },
#endif
	//APA_ENUM_TYPE EPSSteeringWheelAngRatioLearningPtNum[APA_STEER_WHEEL_ANGLE_RATIO_LEARNING_PER_CYCLE_NUM]; // max: APA_STEER_WHEEL_ANGLE_RATIO_DEVIDED_SEG_NUM
	// {
	// 	// The following point is based on D2UB-S steer ratio data from GMNA.
	// 	1, 1, 1, 2
	// },

	// APA_ANGLE_CAL_FLOAT_TYPE EPSSteeringWheelAngRatioLearningAngArray[APA_STEER_WHEEL_TURNING_SIDE_NUM][APA_STEER_WHEEL_ANGLE_RATIO_LEARNING_PER_CYCLE_NUM][APA_STEER_WHEEL_ANGLE_RATIO_LEARNING_PT_NUM];
	// {
	// 	// The following point is based on D2UB-S steer ratio data from GMNA.
	// 	// 	APASteeringWheelTurningSide_Left = 0,
	// 	{
	// 		{	
	// 			// learning buf 1.
	// 			490.0 * PI / 180.0, //  Use max steering wheel angle. // D2UB-S max: 505deg. D2SC-S Max: 511deg.
	// 			360.0 * PI / 180.0, // NA.
	// 			270.0 * PI / 180.0, // NA.
	// 		},
	// 		{	
	// 			// learning buf 2.
	// 			360.0 * PI / 180.0, 
	// 			270.0 * PI / 180.0, // NA.
	// 			170.0 * PI / 180.0, // NA. 
	// 		},
	// 		{	
	// 			// learning buf 3.
	// 			270.0 * PI / 180.0, 
	// 			170.0 * PI / 180.0, // NA. 
	// 			80.0 * PI / 180.0   // NA.
	// 		},
	// 		{
	// 			// learning buf 4.

	// 			170.0 * PI / 180.0,
	// 			80.0 * PI / 180.0,
	// 			45.0 * PI / 180.0, // NA.
	// 		},
	// 	},
	// 	// 	APASteeringWheelTurningSide_Right = 1,
	// 	{		
	// 		{	
	// 			// learning buf 1.
	// 			490.0 * PI / 180.0, //  Use max steering wheel angle. // D2UB-S max: 502deg, D2SC-S max:495deg.
	// 			365.0 * PI / 180.0, // NA.
	// 			270.0 * PI / 180.0, // NA.
	// 		},
	// 		{	
	// 			// learning buf 1.
	// 			365.0 * PI / 180.0,
	// 			270.0 * PI / 180.0, // NA.
	// 			190.0 * PI / 180.0, // NA
	// 		},
	// 		{
	// 			// learning buf 2.

	// 			270.0 * PI / 180.0,
	// 			190.0 * PI / 180.0, // NA.
	// 			90.0 * PI / 180.0,  // NA.
	// 		},
	// 		{
	// 			// learning buf 2.

	// 			190.0 * PI / 180.0,
	// 			90.0 * PI / 180.0,
	// 			45.0 * PI / 180.0, // NA.
	// 		}
	// 	}
	// },

	// APA_ANGLE_CAL_FLOAT_TYPE EPSSteeringWheelAngLearningTolDevidedAng[APA_STEER_WHEEL_ANGLE_LEARNING_TOL_DEVIDED_NUM - 1];
	// {
	// 	2.0 * PI / 180.0, // 0 ~ 1.5 deg for tire factor learning
	// 	15.0 * PI / 180.0, // 1.5 ~ 15 deg for steering angle offset learning.
	// 	90.0 * PI / 180.0, // 15 ~ 90 deg for steer ratio learning.
	// 	300.0 * PI / 180.0 // 90 ~ 300 deg for steer ratio learnig.
	// },
	
	// APA_ANGLE_CAL_FLOAT_TYPE EPSSteeringWheelAngLearningTol[APA_STEER_WHEEL_ANGLE_LEARNING_TOL_DEVIDED_NUM];
	// {
	// 	2.0 * PI / 180.0, // 0 ~ 1.5 deg for tire factor learning
	// 	1.0 * PI / 180.0, // 1.5 * PI / 180.0, // 1.5 ~ 15 deg for steering angle offset learning.
	// 	1.0 * PI / 180.0, // ,def: 0.5 deg, 15 ~ 90 deg for steer ratio learning.
	// 	1.3 * PI / 180.0, // , def: 0.7 deg, 90 ~ 300 deg for steer ratio learnig.
	// 	1.5 * PI / 180.0 // , def: 1.0 deg,  300 ~ 500 deg for steer ratio learnig.
	// },

	// APA_SPEED_TYPE EPSSteeringWheelAngLearningAllowedMinSpeed[APA_STEER_WHEEL_ANGLE_LEARNING_TOL_DEVIDED_NUM];
	// {
	// 	2.0 / 3.6, // 2km/h, 0 ~ 1.5 deg for tire factor learning
	// 	2.0 / 3.6, // 1.5 ~ 15 deg for steering angle offset learning.
	// 	2.0 / 3.6, // 15 ~ 90 deg for steer ratio learning.
	// 	2.0 / 3.6, // 90 ~ 300 deg for steer ratio learnig.
	// 	1.0 / 3.6 // 300 ~ 500 deg for steer ratio learnig.
	// },
	
	// APA_SPEED_TYPE EPSSteeringWheelAngLearningAllowedMaxSpeed[APA_STEER_WHEEL_ANGLE_LEARNING_TOL_DEVIDED_NUM];	
	// {
	// 	70.0 / 3.6, // 40km/h, 0 ~ 1.5 deg for tire factor learning
	// 	70.0 / 3.6, // 1.5 ~ 15 deg for steering angle offset learning.
	// 	40.0 / 3.6, // 15 ~ 90 deg for steer ratio learning.
	// 	35.0 / 3.6, // 90 ~ 300 deg for steer ratio learnig.
	// 	25.0 / 3.6 // 300 ~ 500 deg for steer ratio learnig.
	// },
	// APA_CAR_POS_WHEEL_PULSE_CNT_TYPE EPSSteeringWheelAngLearningAllowedMinWheelPulseCntPerCycle[APA_STEER_WHEEL_ANGLE_LEARNING_TOL_DEVIDED_NUM];
	// {
	// 	50, // 50 * 5cm = 2.5m, 0 ~ 1.5 deg for tire factor learning
	// 	30, // 1.5 ~ 15 deg for steering angle offset learning.
	// 	20, // 30 * 5cm = 1.5m, 15 ~ 90 deg for steer ratio learning.
	// 	15, // 25 * 5cm = 1.25m, 90 ~ 300 deg for steer ratio learnig.
	// 	10, // 10 * 5cm = 0.5m, // 300 ~ 500 deg for steer ratio learnig.
	// },
	
	// APA_CAL_FLOAT_TYPE EPSSteeringWheelAngLearningAllowedMaxWheelPulseRatioTol[APA_STEER_WHEEL_ANGLE_LEARNING_TOL_DEVIDED_NUM]
	// {
	// 	0.15, // 15% tolerance,  50 * 5cm = 2.5m, 0 ~ 1.5 deg for tire factor learning
	// 	0.15, // 15%, 1.5 ~ 15 deg for steering angle offset learning.
	// 	0.2, // 30 * 5cm = 1.5m, 15 ~ 90 deg for steer ratio learning.
	// 	0.2, // 25 * 5cm = 1.25m, 90 ~ 300 deg for steer ratio learnig.
	// 	0.2, // 10 * 5cm = 0.5m, // 300 ~ 500 deg for steer ratio learnig.
	// },

/*2.4.9*** Searching Slot Algorithm****/
/*2.4.9.1*** Parrallel slot****/
	1000, // 1m, APA_DISTANCE_TYPE APASlotRSamplePointNoisePtStartCheckBkObjWidth; // 100cm.
	30, // 30: 45deg. 2014 07 12 changed by kjy from 70 to 30.  70: 66deg. 52: 60deg. APA_SLOT_PT_SLOPE_TYPE APASlotRSamplePointAllowedMaxDeltaSlope; // 120, // 76deg. // 52: atan(52/30) = 60deg.
	500, // 50cm, APA_DISTANCE_TYPE APASlotRSamplePointNoisePtCanBeRemovedCheckMinNoObjWidth;
	30, // 2014 07 12 changed by kjy from 7cm to 3cm. def: 7cm, APA_DISTANCE_TYPE APASlotRSamplePointNoisePtCanBeRemovedHeadOrTailMaxDeltaObjDis; // 7cm
	17, // 17: 30deg: 30: 45deg. APA_SLOT_PT_SLOPE_TYPE APASlotRSamplePointNoisePtCanBeRemovedHeadOrTailMaxSlope;  // 17, // 30deg. 30, 45deg. 
	-70, // -70: 66deg. -52: -60deg. APA_SLOT_PT_SLOPE_TYPE APASlotRSamplePointNoisePtCanBeRemovedHeadOrTailMinSlope;  // -52, // -52: -60deg.
	600, // 60cm, def: 50cm, APA_DISTANCE_TYPE APASlotRSamplePointNoisePtRegardedAsSameObjMaxNoObjWidth; // 60cm.
	300, // 30cm, APA_DISTANCE_TYPE APASlotRSamplePointNoisePtRegardedAsSameObjMaxDeltaObjDis; // 30cm.
	500, // 50cm, APA_DISTANCE_TYPE APASlotRSamplePointNoisePtRegardedAsSameObjMinObjWidth; // 50cm.
	250, // 25cm, APA_DISTANCE_TYPE APASlotRSamplePointNoisePtCanBeRemovedSameObjTol; // consider: APASlotObjDetSnsDtdNoisePtCanBeRemovedSameObjTol
	400, // 40cm, APA_DISTANCE_TYPE APASlotRSamplePointNoisePtCanBeRemovedCheckNoiseWidth;
	500, // 50cm, APA_DISTANCE_TYPE APASlotRSamplePointNoisePtCanBeRemovedCheckNoiseToObjWidth;
	300, // 30cm, def: 40 APA_DISTANCE_TYPE APASlotRSamplePointNoisePtCanBeRemovedMaxDis; // consider: APASlotObjDetSnsDtdNoisePtCanBeRemovedMaxDis
	2, // at least has two points with the same obj dis within tol, APA_ENUM_TYPE APASlotRSamplePointNoisePtCanBeRemovedMinSameObjPtNum;	
	500, // 50cm, APA_DISTANCE_TYPE APASlotRSamplePointNoisePtCanBeRemovedMinObjWidth;
	25, // 25%, max: 40, APA_ENUM_TYPE APASlotRSamplePointNoisePtCanBeRemovedMaxNoiseWidthPercentage;
	2500, // 2.5m, APA_DISTANCE_TYPE APASlotRSamplePointNoisePtCanBeRemovedCheckMaxObjWidth;
	500, // 50cm, APA_DISTANCE_TYPE APASlotRSamplePointNoisePtCanBeRemovedCheckStartHeadWidth;
	350, // 35cm, APA_DISTANCE_TYPE APASlotRSamplePointNoisePtCanBeRemovedRegardAsNoiseMinObjWidth;
	6, // APA_DISTANCE_TYPE APASlotRSamplePointNoisePtCanBeRemovedMinObjPtOutOfTolNum;
	4, // APA_DISTANCE_TYPE APASlotRSamplePointNoisePtCanBeRemovedMinNoObjPtTotalNum;
	3, // APA_DISTANCE_TYPE APASlotRSamplePointNoisePtCanBeRemovedMinNoObjPtWitinNoiseNum;
	1000, // 1m, APA_DISTANCE_TYPE APASlotRSamplePointUpdateLongDeltaLen;
	25, // 2.5cm, 3cm, 100, // 10cm, now 5cm, def: 50cm,	APA_DISTANCE_TYPE APASlotRSamplePointUpdateSmallDeltaLen;
	200, // 500, // now 5cm, def: 50cm,	APA_DISTANCE_TYPE APASlotRSamplePointUpdateSmallDeltaLen2;
	1, //, 1 = 1.9deg. // 2 = 3.8deg: 0.0667 * 30 (APA_SLOT_OBJ_PT_SLOPE_ZOOM_TIMES),	APA_DISTANCE_TYPE APASlotRSamplePointCanBeRemovedMaxObjPtDeltaSlope; // 0.1
	8000, // 8m: only no obj dis will be keeped. def: 40cm, APA_DISTANCE_TYPE APASlotRSamplePointCanBeRemovedMaxObjDis;
	700, // APA_DISTANCE_TYPE APASlotRPointCanBeRemovedContiguousPointMinDisP;
	200, // def: 10cm, APA_DISTANCE_TYPE APASlotRPointCanBeRemovedContiguousPointMinDisP2;

	1000, // 1m, APA_DISTANCE_TYPE APASlotFSamplePointNoisePtStartCheckBkObjWidth; // 100cm.
	30, // 30: 45deg. 2014 07 12 changed by kjy from 70 to 30.  70: 66deg. 52: 60deg. APA_SLOT_PT_SLOPE_TYPE APASlotFSamplePointAllowedMaxDeltaSlope; // 120, // 76deg. // 52: atan(52/30) = 60deg.
	500, // 50cm, APA_DISTANCE_TYPE APASlotFSamplePointNoisePtCanBeRemovedCheckMinNoObjWidth;
	30, // 2014 07 12 changed by kjy from 7cm to 3cm. def: 7cm, APA_DISTANCE_TYPE APASlotFSamplePointNoisePtCanBeRemovedHeadOrTailMaxDeltaObjDis; // 7cm
	17, // 17: 30deg: 30: 45deg. APA_SLOT_PT_SLOPE_TYPE APASlotFSamplePointNoisePtCanBeRemovedHeadOrTailMaxSlope;  // 17, // 30deg. 30, 45deg. 
	-70, // -70: 66deg. -52: -60deg. APA_SLOT_PT_SLOPE_TYPE APASlotFSamplePointNoisePtCanBeRemovedHeadOrTailMinSlope;  // -52, // -52: -60deg.
	600, // 60cm, def: 50cm, APA_DISTANCE_TYPE APASlotFSamplePointNoisePtRegardedAsSameObjMaxNoObjWidth; // 60cm.
	300, // 30cm, APA_DISTANCE_TYPE APASlotFSamplePointNoisePtRegardedAsSameObjMaxDeltaObjDis; // 30cm.
	500, // 50cm, APA_DISTANCE_TYPE APASlotFSamplePointNoisePtRegardedAsSameObjMinObjWidth; // 50cm.
	250, // 25cm, APA_DISTANCE_TYPE APASlotFSamplePointNoisePtCanBeRemovedSameObjTol; // consider: APASlotObjDetSnsDtdNoisePtCanBeRemovedSameObjTol
	400, // 40cm, APA_DISTANCE_TYPE APASlotFSamplePointNoisePtCanBeRemovedCheckNoiseWidth;
	500, // 50cm, APA_DISTANCE_TYPE APASlotFSamplePointNoisePtCanBeRemovedCheckNoiseToObjWidth;
	300, // 30cm, def: 40 APA_DISTANCE_TYPE APASlotFSamplePointNoisePtCanBeRemovedMaxDis; // consider: APASlotObjDetSnsDtdNoisePtCanBeRemovedMaxDis
	2, // at least has two points with the same obj dis within tol, APA_ENUM_TYPE APASlotFSamplePointNoisePtCanBeRemovedMinSameObjPtNum;	
	500, // 50cm, APA_DISTANCE_TYPE APASlotFSamplePointNoisePtCanBeRemovedMinObjWidth;
	25, // 25%, max: 40, APA_ENUM_TYPE APASlotFSamplePointNoisePtCanBeRemovedMaxNoiseWidthPercentage;
	2500, // 2.5m, APA_DISTANCE_TYPE APASlotFSamplePointNoisePtCanBeRemovedCheckMaxObjWidth;
	500, // 50cm, APA_DISTANCE_TYPE APASlotFSamplePointNoisePtCanBeRemovedCheckStartHeadWidth;
	350, // 35cm, APA_DISTANCE_TYPE APASlotFSamplePointNoisePtCanBeRemovedRegardAsNoiseMinObjWidth;
	6, // APA_DISTANCE_TYPE APASlotFSamplePointNoisePtCanBeRemovedMinObjPtOutOfTolNum;
	4, // APA_DISTANCE_TYPE APASlotFSamplePointNoisePtCanBeRemovedMinNoObjPtTotalNum;
	3, // APA_DISTANCE_TYPE APASlotFSamplePointNoisePtCanBeRemovedMinNoObjPtWitinNoiseNum;
	1000, // 1m, APA_DISTANCE_TYPE APASlotFSamplePointUpdateLongDeltaLen;
	25, // 2.5cm, 3cm, 100, // 10cm, now 5cm, def: 50cm,	APA_DISTANCE_TYPE APASlotFSamplePointUpdateSmallDeltaLen;
	200, // 500, // now 5cm, def: 50cm,	APA_DISTANCE_TYPE APASlotFSamplePointUpdateSmallDeltaLen2;
	1, //, 1 = 1.9deg. // 2 = 3.8deg: 0.0667 * 30 (APA_SLOT_OBJ_PT_SLOPE_ZOOM_TIMES),	APA_DISTANCE_TYPE APASlotFSamplePointCanBeRemovedMaxObjPtDeltaSlope; // 0.1
	8000, // 8m: only no obj dis will be keeped. def: 40cm, APA_DISTANCE_TYPE APASlotFSamplePointCanBeRemovedMaxObjDis;
	700, // APA_DISTANCE_TYPE APASlotFPointCanBeRemovedContiguousPointMinDisP;
	200, // def: 10cm, APA_DISTANCE_TYPE APASlotFPointCanBeRemovedContiguousPointMinDisP2;


	3000, // 3m, APA_DISTANCE_TYPE APASlotSamplePointCanBeRemovedObj2SearchBkDis; // 3m,
	1500, // 1.5m, APA_DISTANCE_TYPE APASlotSamplePointCanBeRemovedObj1SearchBkDis; // 3m,
	400, // 40cm, APA_DISTANCE_TYPE APASlotSamplePointCanBeRemovedMaxTwoPtDis;
	500, // 50cm, // APA_DISTANCE_TYPE APASlotPointCanBeRemovedInTheSlotMaxObjWidth;
		
	3000, // kjy changed to 3m 2014 12 18 just for test. 4m, APA_DISTANCE_TYPE APASlotMaxDisBetweenToCheckCarTurningTheRoad;
	13.0 * PI / 180.0, // Kjy changed to 17 deg 2014 12 18 just for test. 30.0 * PI / 180.0, // 30deg,  APA_ANGLE_TYPE APASlotMaxDeltaCarAngForCheckingCarTurningTheRoad;
	28000, // def: 25m, //9000 // Should not exceed 25000 (considering + 5000 (APA_SLOT_CAR_CENTER_POINT_Y_DEFAUT_VALUE)) shold not exceed 32m.	APA_DISTANCE_TYPE APASlotMaxDisBetweenStartEndPt;
	16000, // 16m // APA_DISTANCE_TYPE APASlotMaxDisBetweenStartEndPtWithObj1Invalid;
	3000, // 3m, APA_DISTANCE_TYPE APASlotMaxWidthOfObj1WithSlotConfirmed;
	6000, // 6m, APA_DISTANCE_TYPE APASlotMaxWidthOfObj1WithoutSlotConfirmed;
	(80.0 * PI / 180.0), //90deg, def:70deg, APA_ANGLE_TYPE APASlotMaxDeltaCarAngBetStartEndPt;
	(40.0 * PI / 180.0), //40deg, APA_ANGLE_TYPE APASlotMaxDeltaCarAngBetObjPt;
	600, // 60cm, APA_DISTANCE_TYPE APASlotMinPerSlotDeltaCarPosDisAtSlotStartAndEndPt;
	3000, // 3m, APA_DISTANCE_TYPE APASlotDisToCarCheckCarTravellingDis;
	
	22000, // 22m, APA_DISTANCE_TYPE APASlotCarCenterPtAllowedMaxY;
	20000, // 22m, APA_DISTANCE_TYPE APASlotCarCenterPtAllowedMaxX;
	80.0 * PI / 180.0, // APA_ANGLE_TYPE APASlotCarCenterPtAllowedMaxCarAng;
	
	15000, // 10m, // ?? def: (5000) // mm, this value can not less than MaxSlotLenth + APA_SLOT_DIS_TO_CAR_CHECK_CAR_TRAVELLING_DIS, ie. 18m APA_DISTANCE_TYPE APASlotCarCenterPtResetMaxY;
	(-15000), // -15m, mm, this value can not less than MaxSlotLenth + APA_SLOT_DIS_TO_CAR_CHECK_CAR_TRAVELLING_DIS, ie. 18m APA_DISTANCE_TYPE APASlotCarCenterPtResetMinY;
	(45.0 * PI / 180.0), // 45deg. APA_ANGLE_TYPE APASlotCarCenterPtResetMaxCarAng;
	5000, //(-5000), // -5m, def: -5m, should consider SDG function, left side and right side slot should be able to saved with 3 parking slot (Max Slot Length + Max Path After Slot), and check if it is OK for the algorithm, APA_DISTANCE_TYPE APASlotCarCenterPtDefaultY;

	800, // 80cm, APA_DISTANCE_TYPE APASLotMinObj1AndObj2BdStartPtWidth; // 80cm,
	
	// Slot Obj Type check parameter: kjy 2013 10 01 added start
	700, // 70cm, 	APA_DISTANCE_TYPE APASlotObjTypeCheckObjStPtAllowSearchDisFromSlotStPt; // 70cm,
	600, // 60cm, APA_DISTANCE_TYPE APASlotObjTypeCheckAllowMaxDeltaSnsDtObjDisFromObjStPt; // 60cm,
	5500, // 5.5m, APA_DISTANCE_TYPE APASLotObjTypeCheckMaxObjWidth;
	1400, // APA_DISTANCE_TYPE APASLotObjTypeCheckMaxCarToObjDeltaDis; // 1.5 m
	2, // APA_ENUM_TYPE APASlotObjTypeCheckRegardedAsObjMinObjPtNum;
	90,	// APA_DISTANCE_TYPE APASlotObjTypeCheckRegardedAsSamePtTolCarDrvDis;
	30, // APA_DISTANCE_TYPE APASlotObjTypeCheckRegardedAsSamePtTolCarToObjDis;
	150, // 12cm, def: 15cm, APA_DISTANCE_TYPE APASlotObjTypeCheckRegardedAsFlatShapeTolDis; // 15cm.
	400, // 40cm, APA_DISTANCE_TYPE APASlotObjTypeCheckRegardedAsNoiseMaxWidth; // 40cm.
	250, // 25cm, APA_DISTANCE_TYPE APASlotObjTypeCheckFlatShapeRegardedAsNoObjDtMinWidth0; // 30cm, 
	500, // 50cm, APA_DISTANCE_TYPE APASlotObjTypeCheckFlatShapeRegardedAsNoObjDtMinWidth1; // 50cm, 
	800, // 100cm, APA_DISTANCE_TYPE APASlotObjTypeCheckFlatShapeRegardedAsNoObjDtMinWidth2; // 100cm, 
	700, // 1m, APA_DISTANCE_TYPE APASlotObjTypeCheckFlatShapeRegardedAsSmallObjMaxWidth1; // 100cm. obj width less than 100cm will be regarded as small obj.
	1200, // 1.5m, APA_DISTANCE_TYPE APASlotObjTypeCheckFlatShapeRegardedAsSmallObjMaxWidth2; // 150cm. obj width less than 150cm will be regarded as small obj.
	500, // APA_DISTANCE_TYPE APASlotObjTypeCheckFlatShapeJumpWidthTol; 
	
	
	400, // 40cm, APA_DISTANCE_TYPE APASlotObjTypeCheckFallingShapeRegardedAsNoObjDtMinWidth1; // 40cm. the falling shape is big
	1000, // 100cm, APA_DISTANCE_TYPE APASlotObjTypeCheckFallingShapeRegardedAsNoObjDtMinWidth2; // 100cm. the falling shape width is small.
	600, // 60cm, APA_DISTANCE_TYPE APASlotObjTypeCheckFallingShapeRegardedAsSmallObjMaxWidth; // 60cm.  regarded as small falling shape.
	1000, // 1m, APA_DISTANCE_TYPE APASlotObjTypeCheckFallingShapeRegardedAsObjEndedMinObjWidth1; // 100cm.
	1500, // 1.5m, APA_DISTANCE_TYPE APASlotObjTypeCheckFallingShapeRegardedAsObjEndedMinObjWidth2; // 150cm.
	400, // 40cm, APA_DISTANCE_TYPE APASlotObjTypeCheckRegardedAsFallingShapeMinObjWidth1; // 40cm.  big obj( > 100cm)
	800, // APA_DISTANCE_TYPE APASlotObjTypeCheckRegardedAsFallingShapeNoiseMaxFallingObjWidth; // 80cm.
	800, // 80cm, APA_DISTANCE_TYPE APASlotObjTypeCheckRegardedAsFallingShapeNoiseMinRisingObjWidth; // 80cm.
	
	250, // 25cm, APA_DISTANCE_TYPE APASlotObjTypeCheckRisingShapeRegardedAsNoObjDtMinWidth0; // 25cm. the Rising shape is big
	700, // 50cm, APA_DISTANCE_TYPE APASlotObjTypeCheckRisingShapeRegardedAsNoObjDtMinWidth1; // 50cm. the Rising shape is big
	1000, // 1m, APA_DISTANCE_TYPE APASlotObjTypeCheckRisingShapeRegardedAsNoObjDtMinWidth2; // 100cm. the Rising shape width is small.
	1000, // 1m, APA_DISTANCE_TYPE APASlotObjTypeCheckRisingShapeRegardedAsSmallObjMaxWidth1; // 100cm. obj width less than 100cm will be regarded as small obj.
	1600, // 1.6m, APA_DISTANCE_TYPE APASlotObjTypeCheckRisingShapeRegardedAsSmallObjMaxWidth2; // 150cm. obj width less than 150cm will be regarded as small obj.

	1000, // 1m, APA_DISTANCE_TYPE APASlotObjTypeCheckRegardedAsPerpendicularCarMinWidth; // 100cm.
	3200, // 3.2m, APA_DISTANCE_TYPE APASlotObjTypeCheckRegardedAsPerpendicularCarMaxWidth1; // 320cm.	
	4000, // 4m, APA_DISTANCE_TYPE APASlotObjTypeCheckRegardedAsPerpendicularCarMaxWidth2; // 400cm.	
	1800, // 1.8m, APA_DISTANCE_TYPE APASlotObjTypeCheckPerpendicularCarSmallWidth; // 180cm.  1m~1.8m,
	2300, // 2.3m, APA_DISTANCE_TYPE APASlotObjTypeCheckPerpendicularCarNormalWidth; // 230cm.  normal width: 1.8m ~ 2.3m, big width: 2.3m ~ 3.2m.
	33, // 33: 0 ~ 1/3, APA_ENUM_TYPE APASlotObjTypeCheckPerpendicularCarSmallFlatShapeMaxPercentage; //33, // 0 ~ 1/3 shape width from total width: flat shape width * 100 / total width.
	66, // 66: 1/3 ~ 2/3, APA_ENUM_TYPE APASlotObjTypeCheckPerpendicularCarNormalFlatShapeMaxPercentage; //66, 1/3 ~ 2/3 shape width from total width.
	400, // 40cm. def: 20cm, APA_DISTANCE_TYPE APASlotObjTypeCheckParallelCarSmallRisingShapeMaxWidth; // 20cm.
	600, // 60cm. def: 40cm, APA_DISTANCE_TYPE APASlotObjTypeCheckParallelCarNormalRisingShapeMaxWidth; // 40cm.
	1000, // 1m. def: 60cm, APA_DISTANCE_TYPE APASlotObjTypeCheckParallelCarBigRisingShapeMaxWidth; // 60cm.
	3, // APA_SLOT_PT_SLOPE_TYPE APASlotObjTypeCheckRegardedAsParallelCarMaxSlope; // 3, max: 3.99: 60cm / 450cm, 7.6deg. 2, max 2.99: 45cm / 450cm, 5.7deg.

	// APA_DISTANCE_TYPE APASlotObjTypeCheckObjRisingShapeEndPtMinDeltaDis[2]; // 5cm.
	{
		// 0: Obj1, 1: Obj2.
		// 5cm,      10cm,
		50,         100
	},
	// APA_DISTANCE_TYPE APASlotObjTypeCheckObjRisingShapeEndPtMaxDeltaDis[2]; // 25cm.
	{
		// 0: Obj1, 1: Obj2.
		// 20cm,      25cm,
		200,         250
	},
	300, // 30cm, APA_DISTANCE_TYPE APASlotObjTypeCheckObjRisingShapeEndPtMinRisingWidth; // 30cm.
	1000, // 100cm, APA_DISTANCE_TYPE APASlotObjTypeCheckObjRisingShapeEndPtMaxRisingWidth; // 100cm.
	
	40, // 40%, APA_ENUM_TYPE APASlotObjTypeCheckRoundObjRegardedAsFlatShapeMinPercentage; // 40, // >= 40%
	100, // 10cm, APA_DISTANCE_TYPE APASlotObjTypeCheckSquareObjMaxRisingShapeWidth; // 10cm.
	200, // 20cm, APA_DISTANCE_TYPE APASlotObjTypeCheckRoundObjSmallRisingShapeMaxWidth; // 20cm.
	600, // 60cm, APA_DISTANCE_TYPE APASlotObjTypeCheckRoundObjBigRisingShapeMaxWidth; // 60cm.
	
	1000, // 1m, 0.6m is not enough, def: 1m, APA_DISTANCE_TYPE APASlotObjTypeCheckRegardedAsAngularCarMinFlatShapeWidth1; // 100cm.
	1500, // 1.m, APA_DISTANCE_TYPE APASlotObjTypeCheckRegardedAsAngularCarMinFlatShapeWidth2; // 150cm.
	100, // 10cm, APA_DISTANCE_TYPE APASlotObjTypeCheckAngularCarSmallRisingShapeMaxWidth; // 10cm.
	
	5, // APA_SLOT_PT_SLOPE_TYPE APASlotObjTypeCheckRegardedAsAngularCarDevidedSlope1; // 5, 5 = 5cm / 30cm * 30, 10 deg.
	11, // APA_SLOT_PT_SLOPE_TYPE APASlotObjTypeCheckRegardedAsAngularCarDevidedSlope2; // 11, 11 = 11cm / 30cm * 30, 20 deg.
	42, // APA_SLOT_PT_SLOPE_TYPE APASlotObjTypeCheckRegardedAsAngularCarMaxSlope; // 42, 42 = 42cm / 30cm * 30, 55 deg.
	2, //2,kjy changed from 2 to 3. // def: 4, APA_SLOT_PT_SLOPE_TYPE APASlotObjTypeCheckRegardedAsObjStartMaxDeltaDisSlope; // 4 // 4 = 4.99cm / 30cm * 30 (zoom 30 times). 9.4deg; 5 = 5.99cm / 30cm * 30, 11.3deg; // 8 // 8 = 10.7cm / 40cm * 30 (zoom 30 times). 15deg. 5 = 7cm / 40cm * 30, 10deg.

	// 1.5m, APA_DISTANCE_TYPE APASlotObjTypeCheckObjStartPtCalSearchBackWidthSmallObj[2]; // 150cm,
	{
		1500, // Obj1.
		2200 // obj2.
	},
	// 1.5m, APA_DISTANCE_TYPE APASlotObjTypeCheckObjStartPtCalSearchBackWidthParallelCar[2]; // 150cm
	{
		2200, // Obj1.
		2200 // obj2.
	},
	
	//-300, // -30cm, APA_DISTANCE_TYPE APASlotObjTypeCheckObjStartPtCalMaxAllowedCompensatedBackDis; // -30cm
	40, // 4cm, APA_DISTANCE_TYPE APASlotObjTypeCheckObjStartPtCalRegardedAsFlatStartPtMaxDeltaObjDis; // 4cm
	// APA_DISTANCE_TYPE APASlotObjTypeCheckObjStartPtCalRegardedAsObjStartPtMaxDeltaObjDis[2]; // 40cm
	{
		400, // Obj1.
		300 // obj2.
	},
	1100, // 1.1m, APA_DISTANCE_TYPE APASlotObjTypeCheckObjStartPtCalRegardedAsObj2BigPerCarRisingShapeWidth; // 110cm // dis from start comp pt to nearest dis pt.
	-1, // -1: 1.9deg, APA_SLOT_PT_SLOPE_TYPE APASlotObjTypeCheckObjStartPtCalRegardedAsNoiseMinObjEndPtSlope; // - 1: 1.9deg.
	8, // 8 : 15deg. APA_SLOT_PT_SLOPE_TYPE APASlotObjTypeCheckObjStartPtCalRegardedAsNoiseMinObjEndPtDeltaSlope; // 8: 15deg.
	
	// APA_DISTANCE_TYPE APASlotObjTypeCheckObjStartPtCalRegardAsCompStPtTooShortDis[2][3]; // 30cm.
	{
		// Obj1.will compensate: APASlotObjTypeCheckObjStartPtCalDeltaObjDisObj1
		{
			200, // 20cm. ratio: 45cm. Small obj with flat or rising end. obj width < 2.3m,
			200, // 10cm, ratio: 40cm, // per car big width 2.3 ~ 3.2m.
			200 // 10cm, ratio: 30cm, // per car big flat or angular car or parallel car. > 3.2m
		},
		
		// Obj2.will compensate: APASlotObjTypeCheckObjStartPtCalDeltaObjDisObj2
		{
			100, // 10cm, ratio: 400, // 40cm, Small obj with flat or rising end. obj width < 2.3m,
			100, // 10cm, ratio: 400, // 40cm, // per car big width 2.3 ~ 3.2m.
			100, // 10cm, 200 // 20cm, // per car big flat or angular car or parallel car. > 3.2m
		}
	},
	// APA_DISTANCE_TYPE APASlotObjTypeCheckObjStartPtCalRegardAsCompStPtMaxWidth[2][3]; // 50cm.
	{
		// Obj1.will compensate: APASlotObjTypeCheckObjStartPtCalDeltaObjDisObj1
		{
			400, // 40cm. ratio: 45cm. Small obj with flat or rising end. obj width < 2.3m,
			400, // 40cm, ratio: 40cm, // per car big width 2.3 ~ 3.2m.
			400 // 40cm, ratio: 30cm, // per car big flat or angular car or parallel car. > 3.2m
		},
		
		// Obj2.will compensate: APASlotObjTypeCheckObjStartPtCalDeltaObjDisObj2
		{
			300, // 40cm, ratio: 400, // 40cm, Small obj with flat or rising end. obj width < 2.3m,
			300, // 40cm, ratio: 400, // 40cm, // per car big width 2.3 ~ 3.2m.
			300, // 40cm, 200 // 20cm, // per car big flat or angular car or parallel car. > 3.2m
		}
	},

	/*
	//APA_DISTANCE_TYPE APASlotObjTypeCheckObjStartPtCalDeltaObjDisSlopeRatio[2]; 	
	{
		4, // Obj1. : 3: if obj start pt and obj nearest dis pt slotp is 45deg will not reduced.
		4, // obj2.
	},
	*/
	
	// APA_DISTANCE_TYPE APASlotObjTypeCheckObjStartPtCalDeltaObjDisObj[2][APA_SLOT_OBJ_PROFILE_TYPE_NUM]; 
	{
		// Obj1.
		{
			250, // 15cm, 1, APA_SLOT_OBJ_TYPE_SQUARE_OBJ, 
			250, // 15cm, 2, APA_SLOT_OBJ_TYPE_SQUARE_OBJ_WITH_FALLING_SHAPE,
			250, // 30cm, 3, APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_RISING_SHAPE_ONLY,
			250, // 25cm, 4, APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_RISING_AND_FLAT_SHAPE,
			250, // 15cm, 5, APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_SMALL_RISING_AND_FALLING_SHAPE,
			250, // 20cm, 6, APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_NORMAL_RISING_AND_FALLING_SHAPE,
			250, // 25cm, 7, APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_BIG_RISING_AND_FALLING_SHAPE,
			500, // 50cm, 8, APA_SLOT_OBJ_TYPE_PER_CAR_SMALL_FLAT_SMALL_WIDTH, // Flat shape < 1/3, car width < 1.8m
			400, // 40cm, 9, APA_SLOT_OBJ_TYPE_PER_CAR_NORMAL_FLAT_SMALL_WIDTH, // Flat shape = 1/3 ~ 2/3, car width < 1.8m
			250, // 25cm, 10, APA_SLOT_OBJ_TYPE_PER_CAR_BIG_FLAT_SMALL_WIDTH, // Flat shape > 2/3, car width < 1.8m
			400, // 40cm, 11, APA_SLOT_OBJ_TYPE_PER_CAR_SMALL_FLAT_NORMAL_WIDTH, // Flat shape < 1/3, car width = 1.8m ~ 2.3m
			250, // 30cm, 12, APA_SLOT_OBJ_TYPE_PER_CAR_NORMAL_FLAT_NORMAL_WIDTH, // Flat shape = 1/3 ~ 2/3, car width = 1.8m ~ 2.3m
			250, // 20cm, 13, APA_SLOT_OBJ_TYPE_PER_CAR_BIG_FLAT_NORMAL_WIDTH, // Flat shape > 2/3, car width = 1.8m ~ 2.3m
			250, // def: 30cm, 14, APA_SLOT_OBJ_TYPE_PER_CAR_SMALL_FLAT_BIG_WIDTH, // Flat shape < 1/3, car width > 2.3m
			250, // 20cm, 15, APA_SLOT_OBJ_TYPE_PER_CAR_NORMAL_FLAT_BIG_WIDTH, // Flat shape = 1/3 ~ 2/3, car width > 2.3m
			250, // 15cm, 16, APA_SLOT_OBJ_TYPE_PER_CAR_BIG_FLAT_BIG_WIDTH, // Flat shape > 2/3, car width > 2.3m	
			200, // 20cm, 17, APA_SLOT_OBJ_TYPE_CAR_ANGULAR_NEG_10DEG_RISING_SHAPE_AT_START,
			200, // 10cm, 18, APA_SLOT_OBJ_TYPE_CAR_ANGULAR_NEG_10DEG_FLAT_SHAPE_AT_START,
			400, // 20cm, 19, APA_SLOT_OBJ_TYPE_CAR_ANGULAR_NEG_20DEG_RISING_SHAPE_AT_START,
			200, // 10cm, 20, APA_SLOT_OBJ_TYPE_CAR_ANGULAR_NEG_20DEG_FLAT_SHAPE_AT_START,
			500, // 20cm, 21, APA_SLOT_OBJ_TYPE_CAR_ANGULAR_NEG_30DEG_RISING_SHAPE_AT_START,
			200, // 10cm, 22, APA_SLOT_OBJ_TYPE_CAR_ANGULAR_NEG_30DEG_FLAT_SHAPE_AT_START,
			250, // 10cm, 23, APA_SLOT_OBJ_TYPE_CAR_ANGULAR_10DEG_RISING_SHAPE_AT_START,
			250, // 10cm, 24, APA_SLOT_OBJ_TYPE_CAR_ANGULAR_10DEG_FLAT_SHAPE_AT_START,
			250, // 10cm, 25, APA_SLOT_OBJ_TYPE_CAR_ANGULAR_20DEG_RISING_SHAPE_AT_START,
			250, // 10cm, 26,APA_SLOT_OBJ_TYPE_CAR_ANGULAR_20DEG_FLAT_SHAPE_AT_START,
			250, // 10cm, 27, APA_SLOT_OBJ_TYPE_CAR_ANGULAR_30DEG_RISING_SHAPE_AT_START,
			250, // 10cm, 28, APA_SLOT_OBJ_TYPE_CAR_ANGULAR_30DEG_FLAT_SHAPE_AT_START,
			250, // 10cm, 29, APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_SMALL_RISING_SHAPE, // rising width < 40cm,
			250, // 10cm, 30, APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_NORMAL_RISING_SHAPE, // rising width < 60cm,
			250, // 10cm, 31, APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_BIG_RISING_SHAPE, // rising width < 100cm.
			250 // 10cm, 32, APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_VERY_BIG_RISING_SHAPE, // rising width > 100cm.
		
		},
		// Obj2.	
		{
			350, // 15cm, 1, APA_SLOT_OBJ_TYPE_SQUARE_OBJ, 
			350, // 15cm, 2, APA_SLOT_OBJ_TYPE_SQUARE_OBJ_WITH_FALLING_SHAPE,
			350, // 30cm, 3, APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_RISING_SHAPE_ONLY,
			350, // 25cm, 4, APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_RISING_AND_FLAT_SHAPE,
			350, // 15cm, 5, APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_SMALL_RISING_AND_FALLING_SHAPE,
			350, // 20cm, 6, APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_NORMAL_RISING_AND_FALLING_SHAPE,
			350, // 25cm, 7, APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_BIG_RISING_AND_FALLING_SHAPE,
			500, // 50cm, 8, APA_SLOT_OBJ_TYPE_PER_CAR_SMALL_FLAT_SMALL_WIDTH, // Flat shape < 1/3, car width < 1.8m
			400, // 40cm, 9, APA_SLOT_OBJ_TYPE_PER_CAR_NORMAL_FLAT_SMALL_WIDTH, // Flat shape = 1/3 ~ 2/3, car width < 1.8m
			350, // 25cm, 10, APA_SLOT_OBJ_TYPE_PER_CAR_BIG_FLAT_SMALL_WIDTH, // Flat shape > 2/3, car width < 1.8m
			350, // 40cm, 11, APA_SLOT_OBJ_TYPE_PER_CAR_SMALL_FLAT_NORMAL_WIDTH, // Flat shape < 1/3, car width = 1.8m ~ 2.3m
			350, // 30cm, 12, APA_SLOT_OBJ_TYPE_PER_CAR_NORMAL_FLAT_NORMAL_WIDTH, // Flat shape = 1/3 ~ 2/3, car width = 1.8m ~ 2.3m
			350, // 20cm, 13, APA_SLOT_OBJ_TYPE_PER_CAR_BIG_FLAT_NORMAL_WIDTH, // Flat shape > 2/3, car width = 1.8m ~ 2.3m
			350, // def: 30cm, 14, APA_SLOT_OBJ_TYPE_PER_CAR_SMALL_FLAT_BIG_WIDTH, // Flat shape < 1/3, car width > 2.3m
			350, // 20cm, 15, APA_SLOT_OBJ_TYPE_PER_CAR_NORMAL_FLAT_BIG_WIDTH, // Flat shape = 1/3 ~ 2/3, car width > 2.3m
			350, // 15cm, 16, APA_SLOT_OBJ_TYPE_PER_CAR_BIG_FLAT_BIG_WIDTH, // Flat shape > 2/3, car width > 2.3m	
			350, // 20cm, 17, APA_SLOT_OBJ_TYPE_CAR_ANGULAR_NEG_10DEG_RISING_SHAPE_AT_START,
			350, // 10cm, 18, APA_SLOT_OBJ_TYPE_CAR_ANGULAR_NEG_10DEG_FLAT_SHAPE_AT_START,
			400, // 20cm, 19, APA_SLOT_OBJ_TYPE_CAR_ANGULAR_NEG_20DEG_RISING_SHAPE_AT_START,
			350, // 10cm, 20, APA_SLOT_OBJ_TYPE_CAR_ANGULAR_NEG_20DEG_FLAT_SHAPE_AT_START,
			500, // 20cm, 21, APA_SLOT_OBJ_TYPE_CAR_ANGULAR_NEG_30DEG_RISING_SHAPE_AT_START,
			350, // 10cm, 22, APA_SLOT_OBJ_TYPE_CAR_ANGULAR_NEG_30DEG_FLAT_SHAPE_AT_START,
			350, // 10cm, 23, APA_SLOT_OBJ_TYPE_CAR_ANGULAR_10DEG_RISING_SHAPE_AT_START,
			350, // 10cm, 24, APA_SLOT_OBJ_TYPE_CAR_ANGULAR_10DEG_FLAT_SHAPE_AT_START,
			350, // 10cm, 25, APA_SLOT_OBJ_TYPE_CAR_ANGULAR_20DEG_RISING_SHAPE_AT_START,
			350, // 10cm, 26,APA_SLOT_OBJ_TYPE_CAR_ANGULAR_20DEG_FLAT_SHAPE_AT_START,
			350, // 10cm, 27, APA_SLOT_OBJ_TYPE_CAR_ANGULAR_30DEG_RISING_SHAPE_AT_START,
			350, // 10cm, 28, APA_SLOT_OBJ_TYPE_CAR_ANGULAR_30DEG_FLAT_SHAPE_AT_START,
			350, // 10cm, 29, APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_SMALL_RISING_SHAPE, // rising width < 40cm,
			350, // 10cm, 30, APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_NORMAL_RISING_SHAPE, // rising width < 60cm,
			350, // 10cm, 31, APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_BIG_RISING_SHAPE, // rising width < 100cm.
			350 // 10cm, 32, APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_VERY_BIG_RISING_SHAPE, // rising width > 100cm.
		
		}
	},
	
	// APA_DISTANCE_TYPE APASlotObjTypeCheckObjStartPtCompensateDisBySpdAndCarToObjDis[2][APA_SLOT_OBJ_PROFILE_COMPENSATE_TYPE_NUM][APA_SLOT_SUPPORT_SLOT_LENGTH_COMPENSATE_SPEED_DEVIDED_NUM];
	{
		// Obj1.

		{
			// APA_SLOT_OBJ_COMP_TYPE_SQUARE_OBJ = 0,
			// APA_SLOT_OBJ_TYPE_UNKNOWN = 0,
			// APA_SLOT_OBJ_TYPE_SQUARE_OBJ,  // 1
			// APA_SLOT_OBJ_TYPE_SQUARE_OBJ_WITH_FALLING_SHAPE,  // 2
			{   //7kph,   25kph
				{100,     100}, //for DisCarToObj 80 cm
				{100,     100}  //for DisCarToObj 170 cm
			}, 
			// APA_SLOT_OBJ_COMP_TYPE_ROUND_OBJ_WITH_RISING_SHAPE_ONLY, // 30cm,
			// APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_RISING_SHAPE_ONLY,  // 3
			// APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_RISING_AND_FLAT_SHAPE,  // 4
			{   //7kph,   25kph
				{250,     250}, //for DisCarToObj 80 cm
				{250 + 70,     250 + 70}  //for DisCarToObj 170 cm
			},
			// APA_SLOT_OBJ_COMP_TYPE_ROUND_OBJ_WITH_SMALL_RISING_AND_FALLING_SHAPE,
			// APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_SMALL_RISING_AND_FALLING_SHAPE, // 5
			{	
				{250,      250}, //for DisCarToObj 80 cm
				{250 + 70,      250 + 70} //for DisCarToObj 170 cm
			},
			// APA_SLOT_OBJ_COMP_TYPE_ROUND_OBJ_WITH_NORMAL_RISING_AND_FALLING_SHAPE,
			// APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_NORMAL_RISING_AND_FALLING_SHAPE, // 6
			// APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_BIG_RISING_AND_FALLING_SHAPE,  // 7
			{	
				{250,      250}, //for DisCarToObj 80 cm
				{250 + 70,      250 + 70} //for DisCarToObj 170 cm
			},	

			// 8, APA_SLOT_OBJ_COMP_TYPE_PER_CAR_WITH_RISING_SMALL_FLAT_FALLING_SHAPE1, // Flat shape < 1/3, car width < 1.8m
			// APA_SLOT_OBJ_TYPE_PER_CAR_WITH_SMALL_FLAT_SMALL_WIDTH, // 8 // Flat shape < 1/3, car width < 1.8m
			{
				{100,      100}, //for DisCarToObj 80 cm
				{100,      100} //for DisCarToObj 170 cm
			},
			// 9, APA_SLOT_OBJ_COMP_TYPE_PER_CAR_WITH_RISING_NORMAL_FLAT_FALLING_SHAPE1, // Flat shape = 1/3 ~ 2/3, car width < 1.8m
			// APA_SLOT_OBJ_TYPE_PER_CAR_WITH_NORMAL_FLAT_SMALL_WIDTH, // 9 // Flat shape = 1/3 ~ 2/3, car width < 1.8m
			{
				{100,      100}, //for DisCarToObj 80 cm
				{100,      100} //for DisCarToObj 170 cm
			},
			// 10, APA_SLOT_OBJ_COMP_TYPE_PER_CAR_WITH_RISING_BIG_FLAT_FALLING_SHAPE1, // Flat shape > 2/3, car width < 1.8m
			// APA_SLOT_OBJ_TYPE_PER_CAR_WITH_BIG_FLAT_SMALL_WIDTH,  // 10 // Flat shape > 2/3, car width < 1.8m
			{
				{100,      100}, //for DisCarToObj 80 cm
				{100,      100} //for DisCarToObj 170 cm
			},
			// 11, APA_SLOT_OBJ_COMP_TYPE_PER_CAR_WITH_RISING_SMALL_FLAT_FALLING_SHAPE2, // Flat shape < 1/3, car width = 1.8m ~ 2.3m
			//APA_SLOT_OBJ_TYPE_PER_CAR_WITH_SMALL_FLAT_NORMAL_WIDTH, // 11  // Flat shape < 1/3, car width = 1.8m ~ 2.3m
			{
				{200,      250}, //for DisCarToObj 80 cm
				{200 + 70,      250 + 70} //for DisCarToObj 170 cm
			},
			// 12, APA_SLOT_OBJ_COMP_TYPE_PER_CAR_WITH_RISING_NORMAL_FLAT_FALLING_SHAPE2, // Flat shape = 1/3 ~ 2/3, car width = 1.8m ~ 2.3m
			// APA_SLOT_OBJ_TYPE_PER_CAR_WITH_NORMAL_FLAT_NORMAL_WIDTH, // 12 // Flat shape = 1/3 ~ 2/3, car width = 1.8m ~ 2.3m
			{
				{200,      200}, //for DisCarToObj 80 cm
				{200 + 70,      200 + 70} //for DisCarToObj 170 cm
			},
			// 13, APA_SLOT_OBJ_COMP_TYPE_PER_CAR_WITH_RISING_BIG_FLAT_FALLING_SHAPE2, // Flat shape > 2/3, car width = 1.8m ~ 2.3m
			// APA_SLOT_OBJ_TYPE_PER_CAR_WITH_BIG_FLAT_NORMAL_WIDTH, // 13 // Flat shape > 2/3, car width = 1.8m ~ 2.3m
			{
				{200,      200}, //for DisCarToObj 80 cm
				{200 + 20,      200 + 20} //for DisCarToObj 170 cm
			},
			// 14, APA_SLOT_OBJ_COMP_TYPE_PER_CAR_WITH_RISING_SMALL_FLAT_FALLING_SHAPE3, // Flat shape < 1/3, car width > 2.3m
			// APA_SLOT_OBJ_TYPE_PER_CAR_WITH_SMALL_FLAT_BIG_WIDTH, // 14 // Flat shape < 1/3, car width > 2.3m
			{	
				{250,      250}, //for DisCarToObj 80 cm
				{250 + 100,      250 + 100} //for DisCarToObj 170 cm
			},
			// 15, APA_SLOT_OBJ_COMP_TYPE_PER_CAR_WITH_RISING_NORMAL_FLAT_FALLING_SHAPE3, // Flat shape = 1/3 ~ 2/3, car width > 2.3m
			// APA_SLOT_OBJ_TYPE_PER_CAR_WITH_NORMAL_FLAT_BIG_WIDTH, // 15 // Flat shape = 1/3 ~ 2/3, car width > 2.3m
			{	
				{250,      250}, //for DisCarToObj 80 cm
				{250 + 100,      250 + 100} //for DisCarToObj 170 cm
			},
			// APA_SLOT_OBJ_COMP_TYPE_CAR_ANGULAR_NEG_10DEG_RISING_SHAPE_AT_START,
			{
				{100,      100}, //for DisCarToObj 80 cm
				{100,      100} //for DisCarToObj 170 cm
			},

			// APA_SLOT_OBJ_COMP_TYPE_CAR_ANGULAR_NEG_10DEG_FLAT_SHAPE_AT_START,
			{
				{0,      0}, //for DisCarToObj 80 cm
				{0,      0}  //for DisCarToObj 170 cm
			},
			// APA_SLOT_OBJ_COMP_TYPE_CAR_ANGULAR_10DEG_RISING_SHAPE_AT_START,
			{	
				{300,      300}, //for DisCarToObj 80 cm
				{300,      300} //for DisCarToObj 170 cm
			},
			
			// APA_SLOT_OBJ_COMP_TYPE_CAR_ANGULAR_10DEG_FLAT_SHAPE_AT_START,
			{	
				{350,      350}, //for DisCarToObj 80 cm
				{350,      350} //for DisCarToObj 170 cm
			},
			
			// 29, 16, APA_SLOT_OBJ_COMP_TYPE_PARALLEL_CAR_WITH_SMALL_RISING_SHAPE, // rising width < 40cm,
			{
				{130,    130}, //{230,      230}, //for DisCarToObj 80 cm
				{130 + 130,    130 + 130}, // {230 + 90,      230 + 90} //for DisCarToObj 170 cm
			},

			// 30, APA_SLOT_OBJ_COMP_TYPE_PARALLEL_CAR_WITH_NORMAL_RISING_SHAPE, // rising width < 60cm,
			{	
				{130,    130}, //{230,      230}, //for DisCarToObj 80 cm
				{130 + 130,    130 + 130}, // {230 + 90,      230 + 90} //for DisCarToObj 170 cm
			},
			// 31, APA_SLOT_OBJ_COMP_TYPE_PARALLEL_CAR_WITH_BIG_RISING_SHAPE, // rising width < 100cm.
			{	
				{150,   150}, //{250,      250}, //for DisCarToObj 80 cm
				{150 + 130,  150 + 130}, // {250 + 130,      250 + 130} //for DisCarToObj 170 cm
			},
			// 32, APA_SLOT_OBJ_COMP_TYPE_PARALLEL_CAR_WITH_VERY_BIG_RISING_SHAPE // rising width > 100cm.
			{	
				{150, 150}, // {250,      250}, //for DisCarToObj 80 cm
				{150 + 130, 150 + 130}, // {250 + 130,      250  + 130} //for DisCarToObj 170 cm
			}
		},
		
		// Obj2.
		{
			// APA_SLOT_OBJ_COMP_TYPE_SQUARE_OBJ = 0,
			{   //7kph,   25kph
				{100,     100}, //for DisCarToObj 80 cm
				{100,     100}  //for DisCarToObj 170 cm
			}, 
			// APA_SLOT_OBJ_COMP_TYPE_ROUND_OBJ_WITH_RISING_SHAPE_ONLY, // 30cm,

			{   //7kph,   25kph
				{250,     250}, //for DisCarToObj 80 cm
				{250  + 150,     250 + 150}  //for DisCarToObj 170 cm
			},
			// APA_SLOT_OBJ_COMP_TYPE_ROUND_OBJ_WITH_SMALL_RISING_AND_FALLING_SHAPE,
			{	
				{250,      250}, //for DisCarToObj 80 cm
				{250 + 150,      250 + 150} //for DisCarToObj 170 cm
			},
			// APA_SLOT_OBJ_COMP_TYPE_ROUND_OBJ_WITH_NORMAL_RISING_AND_FALLING_SHAPE,
			{	
				{250,      250}, //for DisCarToObj 80 cm
				{250 + 150,      250 + 150} //for DisCarToObj 170 cm
			},	

			// 8, APA_SLOT_OBJ_COMP_TYPE_PER_CAR_WITH_RISING_SMALL_FLAT_FALLING_SHAPE1, // Flat shape < 1/3, car width < 1.8m
			{
				{150,      150}, // {250,      250}, //for DisCarToObj 80 cm
				{150 + 100,   150 + 100}, // {250,      250} //for DisCarToObj 170 cm
			},
			// 9, APA_SLOT_OBJ_COMP_TYPE_PER_CAR_WITH_RISING_NORMAL_FLAT_FALLING_SHAPE1, // Flat shape = 1/3 ~ 2/3, car width < 1.8m
			{
				{150,      150}, // {250,      250}, //for DisCarToObj 80 cm
				{150 + 100,   150 + 100}, // {250,      250} //for DisCarToObj 170 cm
			},
			// 10, APA_SLOT_OBJ_COMP_TYPE_PER_CAR_WITH_RISING_BIG_FLAT_FALLING_SHAPE1, // Flat shape > 2/3, car width < 1.8m
			{
				{150,      150}, // {250,      250}, //for DisCarToObj 80 cm
				{150 + 100,   150 + 100}, // {250,      250} //for DisCarToObj 170 cm
			},
			// 11, APA_SLOT_OBJ_COMP_TYPE_PER_CAR_WITH_RISING_SMALL_FLAT_FALLING_SHAPE2, // Flat shape < 1/3, car width = 1.8m ~ 2.3m
			{
				//{250,      250}, //for DisCarToObj 80 cm
				{150,      150}, //for DisCarToObj 80 cm
				{250 + 150,      250 + 150} //for DisCarToObj 170 cm
			},
			// 12, APA_SLOT_OBJ_COMP_TYPE_PER_CAR_WITH_RISING_NORMAL_FLAT_FALLING_SHAPE2, // Flat shape = 1/3 ~ 2/3, car width = 1.8m ~ 2.3m
			{
				//{250,      250}, //for DisCarToObj 80 cm
				{150,      150}, //for DisCarToObj 80 cm
				{250 + 150,      250 + 150} //for DisCarToObj 170 cm
			},
			// 13, APA_SLOT_OBJ_COMP_TYPE_PER_CAR_WITH_RISING_BIG_FLAT_FALLING_SHAPE2, // Flat shape > 2/3, car width = 1.8m ~ 2.3m
			{
				//{250,      250}, //for DisCarToObj 80 cm
				{150,      150}, //for DisCarToObj 80 cm
				{250 + 150,      250 + 150} //for DisCarToObj 170 cm
			},
			// 14, APA_SLOT_OBJ_COMP_TYPE_PER_CAR_WITH_RISING_SMALL_FLAT_FALLING_SHAPE3, // Flat shape < 1/3, car width > 2.3m
			{	
				//{250,      250}, //for DisCarToObj 80 cm
				{150,      150}, //for DisCarToObj 80 cm
				{250 + 200,      250 + 200} //for DisCarToObj 170 cm
			},

			// 15, 16, APA_SLOT_OBJ_COMP_TYPE_PER_CAR_WITH_RISING_NORMAL_FLAT_FALLING_SHAPE3, // Flat shape = 1/3 ~ 2/3, car width > 2.3m
			{	
				//{250,      250}, //for DisCarToObj 80 cm
				{150,      150}, //for DisCarToObj 80 cm
				{250 + 150,      250 + 150} //for DisCarToObj 170 cm
			},
			// APA_SLOT_OBJ_COMP_TYPE_CAR_ANGULAR_NEG_10DEG_RISING_SHAPE_AT_START,
			{
				{100,      100}, //for DisCarToObj 80 cm
				{100,      100} //for DisCarToObj 170 cm
			},

			// APA_SLOT_OBJ_COMP_TYPE_CAR_ANGULAR_NEG_10DEG_FLAT_SHAPE_AT_START,
			{
				{0,      0}, //for DisCarToObj 80 cm
				{0,      0}  //for DisCarToObj 170 cm
			},
			// APA_SLOT_OBJ_COMP_TYPE_CAR_ANGULAR_10DEG_RISING_SHAPE_AT_START,
			{	
				{100,      100}, //for DisCarToObj 80 cm
				{100,      100} //for DisCarToObj 170 cm
			},
			
			// APA_SLOT_OBJ_COMP_TYPE_CAR_ANGULAR_10DEG_FLAT_SHAPE_AT_START,
			{	
				{100,      100}, //for DisCarToObj 80 cm
				{100,      100} //for DisCarToObj 170 cm
			},
			
			// 29, APA_SLOT_OBJ_COMP_TYPE_PARALLEL_CAR_WITH_SMALL_RISING_SHAPE, // rising width < 40cm,
			{	
				//{250,      250}, //for DisCarToObj 80 cm
				{150,      150}, //for DisCarToObj 80 cm
				{250 + 70,      250 + 70} //for DisCarToObj 170 cm
			},

			// 30, APA_SLOT_OBJ_COMP_TYPE_PARALLEL_CAR_WITH_NORMAL_RISING_SHAPE, // rising width < 60cm,
			{	
				//{250,      250}, //for DisCarToObj 80 cm
				{150,      150}, //for DisCarToObj 80 cm
				{250 + 70,      250 + 70} //for DisCarToObj 170 cm
			},
			// 31, APA_SLOT_OBJ_COMP_TYPE_PARALLEL_CAR_WITH_BIG_RISING_SHAPE, // rising width < 100cm.
			{	
				//{250,      250}, //for DisCarToObj 80 cm
				{150,      150}, //for DisCarToObj 80 cm
				{250 + 150,      250 + 150} //for DisCarToObj 170 cm
			},
			// 32, APA_SLOT_OBJ_COMP_TYPE_PARALLEL_CAR_WITH_VERY_BIG_RISING_SHAPE // rising width > 100cm.
			{	
				//{250,      250}, //for DisCarToObj 80 cm
				{150,      150}, //for DisCarToObj 80 cm
				{250 + 200,      250 + 200} //for DisCarToObj 170 cm
			}
		},
	},

	// APA_DISTANCE_TYPE APASlotObjTypeCheckObjStartPtCompensateDisWithFlatEnd[2][3]; // 0cm
	{
		// Obj1.
		{
			0, // Small obj with flat or rising end. obj width < 2.3m,
			200, // 20cm, // per car big width 2.3 ~ 3.2m.
			0 // 0cm, // per car big flat or angular car or parallel car. > 3.2m
		},
		
		// Obj2.
		{
			0, // Small obj with flat or rising end. obj width < 2.3m,
			100, // 10cm, // per car big width 2.3 ~ 3.2m.
			200 // 20cm, // per car big flat or angular car or parallel car. > 3.2m
		}
	},
	
	// APA_DISTANCE_TYPE APASlotObjTypeCheckObjStartPtCompensateDisRatioWithSmallRising[2][3]; // 30cm. 
	{
		// Obj1.will compensate: APASlotObjTypeCheckObjStartPtCalDeltaObjDisObj1
		{
			650, //450, // 45cm. Small obj with flat or rising end. obj width < 2.3m,
			600, //400, // 40cm, // per car big width 2.3 ~ 3.2m.
			500, //300 // 30cm, // per car big flat or angular car or parallel car. > 3.2m
		},
		
		// Obj2.will compensate: APASlotObjTypeCheckObjStartPtCalDeltaObjDisObj2
		{
			600, // 400, // 40cm, Small obj with flat or rising end. obj width < 2.3m,
			600, // 400, // 40cm, // per car big width 2.3 ~ 3.2m.
			500, // 200 // 20cm, // per car big flat or angular car or parallel car. > 3.2m
		}
	},
	// APA_DISTANCE_TYPE APASlotObjTypeCheckObjStartPtCompensateDisWithObj2BigPerCarRisingShapeWidth[2];
	{
		// Per car.
		400, // 40cm,
		// angular car.
		400, // 40cm, 
	},
	
	1000, //1.5m,  80cm, APA_DISTANCE_TYPE APASlotObj1NotExistObj2ExistRegardedAsValidSlotAllowedMinObj2Width; // 80cm, // 80cm object. set to 10m will not regarded as a valid slot.
	1000, //1.5m,  80cm, APA_DISTANCE_TYPE APASlotObj1ExistObj2NotExistRegardedAsValidSlotAllowedMinObj1Width; // 80cm, // 80cm object. set to 10m will not regarded as a valid slot.
	0, // 0cm, APA_DISTANCE_TYPE APASlotObj12ExistRegardedAsValidSlotAllowedMinObj1Width1; // 0cm, // 00cm object1. if object2 > 80cm, set to 10m will not regarded as a valid slot.
	600, // 30cm, APA_DISTANCE_TYPE APASlotObj12ExistRegardedAsValidSlotAllowedMinObj1Width2; // 30cm, // 30cm object1. if object2 > 80cm, set to 10m will not regarded as a valid slot.
	1000, // 80cm, APA_DISTANCE_TYPE APASlotObj12ExistRegardedAsValidSlotAllowedMinObj1Width3; // 80cm, // 80cm object. set to 10m will not regarded as a valid slot.
	0, // 0cm, APA_DISTANCE_TYPE APASlotObj12ExistRegardedAsValidSlotAllowedMinObj2Width1; // 0cm, // 0cm object2. if object1 > 80cm, set to 10m will not regarded as a valid slot.
	600, // 30cm, APA_DISTANCE_TYPE APASlotObj12ExistRegardedAsValidSlotAllowedMinObj2Width2; // 30cm, // 30cm object2. if object1 > 80cm, set to 10m will not regarded as a valid slot.
	1000, // 80cm, APA_DISTANCE_TYPE APASlotObj12ExistRegardedAsValidSlotAllowedMinObj2Width3; // 80cm, // 80cm object. set to 10m will not regarded as a valid slot.


	// 
	// Slot Obj Type check parameter: kjy 2013 10 01 added end

	// SaveSnsDtdObjDisToFilterBuf related cal start

	// UCHAR APASlotSnsDtdObjDisFilterSpeedDevidedThreshold[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM - 1]; // 0 ~ 10km/h, 10 ~ 20km/h, 20km/h ~
	{
		// Notes: with sns detecting loop cycle: 32ms
		// 1 detection loop car will drive dis:
		// 5kph: 4.4cm, 8kph: 7.1cm; 10kph: 8.88cm; 12kph: 10.6cm; 15kph: 13.3cm; 17kph: 15.1cm; 20kph: 17.77cm; 25kph: 22.2cm; 30kph: 26.66cm;
		// 10kph, 15kph, 19kph, 24kph
		10,       15,    19,    24
	},
	// APA_INDEX_TYPE APASlotSnsDtdObjDisFilterMinBufSize[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM];
	{
		// 0 ~ 10 kph, 11 ~ 15kph, 16 ~ 19kph, 20 ~ 24kph, >25kph
		//10,            8,          7,          6,         6		
		5,            4,          3,          2,         2		
	},

	// APA_INDEX_TYPE APASlotSnsDtdObjDisFilterBufSize[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM];
	{
		// 0 ~ 10 kph, 11 ~ 15kph, 16 ~ 19kph, 20 ~ 24kph, >25kph
		//10,            8,          7,          6,         6		
		10,            7,          6,          5,         5		
	},

	2000, // 2m, APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterRegardedAsNoObjDtdDevidedObjDis; // 200cm
	
	// APA_ENUM_TYPE APASlotSnsDtdObjDisFilterRegardedAsNoObjDtdMaxDtdObjPtNum[2][APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 
	{
		// < 2m, 
		{
			// Total detection times = APASlotSnsDtdObjDisFilterBufSize * 2
			// 0 ~ 10 kph, 11 ~ 15kph, 16 ~ 19kph, 20 ~ 24kph, >25kph
			7,            4,          4,          3,         2		
			//6,            6,          5,          4,         4		
		},
		// > 2m 
		{
			// Total detection times = APASlotSnsDtdObjDisFilterBufSize * 2
			// 0 ~ 10 kph, 11 ~ 15kph, 16 ~ 19kph, 20 ~ 24kph, >25kph
			7,            4,          4,          3,         2		
			//6,            6,          5,          4,         4		
		}
	},
	// APA_ENUM_TYPE APASlotSnsDtdObjDisFilterRegardedAsNoObjDtdMinConsecutiveNoDtdObjPtNum[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 
	{   
		// Indicate how many points is within the tol with the neighbor pt.
		// 0 ~ 10 kph, 11 ~ 15kph, 16 ~ 19kph, 20 ~ 24kph, >25kph
		// Max buffer size:
		// 10,            7,          6,          5,       5		
		 1,            2,          2,          3,         3		
	},
	//APA_ENUM_TYPE APASlotSnsDtdObjDisFilterCheckRisingOrFallingEdgeMinDtdObjPtNum[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 
	{
		// 0 ~ 10 kph, 11 ~ 15kph, 16 ~ 19kph, 20 ~ 24kph, >25kph
		// Max buffer size:
		//10,            7,          6,          5,         5		
		//6,               5,          5,          4,         4		
		6,               5,          4,          3,         3		
	},
	500, // 50cm, APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterCheckRisingOrFallingEdgeDevidedObjWidth1; // ~ 50cm,
	800, // 80cm, APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterCheckRisingOrFallingEdgeDevidedObjWidth2; // 80cm,
	// APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterCheckRisingOrFallingEdgeMaxDeltaDisUp[3]; // 30cm, 40cm, 50cm, 
	{
		// Obj width:
		// 0~ 50cm,    50 ~ 80cm,    80cm ~,
		300,           400,          500
	},
	// APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterCheckRisingOrFallingEdgeMaxDeltaDisDown[3]; // 5cm, 8cm, 13cm, 
	{
		// Obj width:
		// 0~ 50cm,    50 ~ 80cm,    80cm ~,
		// 50,            80,           130
		40,            50,           70
	},	
	
	2000, // 2m, APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterFlatObjTolDevidedObjDis; // 200cm
	50, // 7cm, APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterFlatObjTolDis1; // 70, 7cm, obj dis < 200cm vehicle
	70, // 7cm, APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterFlatObjTolDis2; // 70, 7cm, obj dis < 200cm vehicle
	150, // 15cm, APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterFlatObjTolDis3; // 150, 15cm, obj dis > 200cm curb.
	// APA_ENUM_TYPE APASlotSnsDtdObjDisFilterRegardedAsFlatObjMinDtdObjPtNum1[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 
	{   
	    // indicate how many points is within the tol with the checked pt.
		// 0 ~ 10 kph, 11 ~ 15kph, 16 ~ 19kph, 20 ~ 24kph, >25kph
		//6,            5,          5,          4,         4		
		6,            4,          4,          3,         3		
	},

	// APA_ENUM_TYPE APASlotSnsDtdObjDisFilterRegardedAsRisingOrFallingMinDtdObjPtNum[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 
	{   
		// Indicate how many points is within the tol with the neighbor pt.
		// 0 ~ 10 kph, 11 ~ 15kph, 16 ~ 19kph, 20 ~ 24kph, >25kph
		// Max buffer size:
		//10,            7,          6,          5,         5		
		//6,            5,          5,          4,         4		
		6,            4,          4,          3,         3		
	},
	// APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterLowSpdRegardedAsNoiseMinFlatPtNum[3]; // 4, // total flat pt num = 0, 1, 2
	{
		// 0: No point is within tol with checked Pt; 1: one point is within tol with checked pt; 2: two point is within tol with checked pt:
		4,                                            4,                                          5
	},
	
	51, // 51%	APA_ENUM_TYPE APASlotSnsDtdObjDisFilterLowSpdRegardedAsNoiseMaxPercentage; // 50: 50%, 

	// APA_SLOT_PT_SLOPE_TYPE APASlotSnsDtdObjDisFilterAllowedMaxDeltaSlope1[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 120, // 76deg. // 52: atan(52/30) = 60deg.
	{   
		// 0 ~ 10 kph, 11 ~ 15kph, 16 ~ 19kph, 20 ~ 24kph, >25kph
		52,            52,          52,          52,         52		
	},
	// APA_SLOT_PT_SLOPE_TYPE APASlotSnsDtdObjDisFilterAllowedMaxDeltaSlope2[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 30, // 76deg. // 52: atan(52/30) = 60deg.
	{   
		// 0 ~ 10 kph, 11 ~ 15kph, 16 ~ 19kph, 20 ~ 24kph, >25kph
		// 25: 40deg.
		25,            25,          25,          25,         25		
	},
		
	// APA_ENUM_TYPE APASlotSnsDtdObjDisFilterRegardedAsOKShapeMinOKDeltaSlopeNum[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // low speed 2, high speed: 1.
	{   
		// 0 ~ 10 kph, 11 ~ 15kph, 16 ~ 19kph, 20 ~ 24kph, >25kph
		2,            2,          1,          1,         1		
	},
	
	52, // 52: 60deg, // 82: 70deg, APA_SLOT_PT_SLOPE_TYPE APASlotSnsDtdObjDisFilterObjAllowedMaxSlope; // 82, // 70deg. 52, 60deg. 
	
	17, // 17: 30deg. APA_SLOT_PT_SLOPE_TYPE APASlotSnsDtdObjDisFilterObjHeadAllowedMaxSlope; // 17, // 30deg. 30, 45deg. 
	-17, // -30deg, APA_SLOT_PT_SLOPE_TYPE APASlotSnsDtdObjDisFilterObjTailAllowedMinSlope; // -17, // -30deg. 30, 45deg. 
	1, // 1: one no obj dtd between two points. APA_ENUM_TYPE APASlotSnsDtdObjDisFilterObjTailCheckNoiseAllowedMinNoObjDtdBetTwoPt; // 1
	//50, // 5cm, APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterHeadOrTailFlatObjTolDis; // 5cm
	{
		// 0 ~ 10 kph, 11 ~ 15kph, 16 ~ 19kph, 20 ~ 24kph, >25kph
		// Max buffer size:
		//10,            7,          6,          5,         5		
		// 1 detection loop car will drive dis:
		// 5kph: 4.4cm, 8kph: 7.1cm; 10kph: 8.88cm; 12kph: 10.6cm; 15kph: 13.3cm; 17kph: 15.1cm; 20kph: 17.77cm; 25kph: 22.2cm; 30kph: 26.66cm;
		70,              80,           100,          120,        150
	},
	350, // 35cm, APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterAllowedToRemoveTwoPointsMaxDis; // 35cm
	1200, // kjy changed from 1.5m to 1.2m, 2015 1 8. Need to test for ground echo.  1500, // 1.5m, APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterFillRisingEdgeMinObjDis; // 150cm
	3500, // APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterFillRisingEdgeMaxObjDis; // 350cm
	500, // APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterFillFallingEdgeMinObjDis; // 50cm
	3500, // APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterFillFallingEdgeMaxObjDis; // 350cm
	2500,//APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterFillFlatCurbMinObjDis;//220cm
	5000,//APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterFillFlatCurbMaxObjDis;//500cm
	1200,//APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterFillRisingOrFallingEdgeWithCurbMinObjDis;//120cm
	2200,//APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterFillRisingOrFallingEdgeWithCurbMaxObjDis;//200cm
	3,	//APA_ENUM_TYPE APASlotMinObjCntOfCurbToCheckProfileWithCurb;
	2,//APA_ENUM_TYPE APASlotMinObjCntOfProfileToCheckProfileWithCurb;
	//APA_SLOT_PT_SLOPE_TYPE APASlotMaxDeltaSlopeToCheckIfTheProfileWithCurbIsExsit[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]
	{
		// the end of rising point is with flat shape.
		// 0 ~ 10 kph, 11 ~ 15kph, 16 ~ 19kph, 20 ~ 24kph, >25kph
		1,               2,          2,          3,         4
	},
	//APA_DISTANCE_TYPE APASlotMinDeltaDisBetweenCurbAndProfileobjToCheckIfProfileWithCurb;
	1000,//100cm
	-52, // -52: -60deg, APA_SLOT_PT_SLOPE_TYPE APASlotSnsDtdObjDisFilterFillRisingAndFallingEdgeMaxSlope; // -52, // -52: -60deg.

	11, // 8: 15deg. APA_SLOT_PT_SLOPE_TYPE APASlotSnsDtdObjDisFilterFillRisingAndFallingEdgeAllowedMaxFlatSlope; // 8, // 8: 15deg.
	5, // 5: 9 deg. APA_SLOT_PT_SLOPE_TYPE APASlotSnsDtdObjDisFilterFillRisingAndFallingEdgeAllowedMaxDeltaSlope; // 5, // 5: 9deg.
	// APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillRisingAndFallingEdgeAllowedMaxFlatPtNumAtHead[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 
	{
		// 0 ~ 10 kph, 11 ~ 15kph, 16 ~ 19kph, 20 ~ 24kph, >25kph
		// Max buffer size:
		//10,            7,          6,          5,         5		
		// Max flat obj dt num at head:
		5,              4,           4,          3,         3
	},

	// APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillRisingAndFallingEdgeAllowedMaxNoObjPt[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 
	{
		// 0 ~ 10 kph, 11 ~ 15kph, 16 ~ 19kph, 20 ~ 24kph, >25kph
		// Max buffer size:
		//10,            7,          6,          5,         5		
		// Max no obj dt num:
		4,              3,           2,          1,         1
	},
	// APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillRisingAndFallingEdgeAllowedMaxConsecutiveNoObjPt[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 
	{
		// 0 ~ 10 kph, 11 ~ 15kph, 16 ~ 19kph, 20 ~ 24kph, >25kph
		// Max buffer size:
		//10,            7,          6,          5,         5		
		// Max consecutive no obj dt num:
		1,              1,           0,          0,         0
	},
	500, // 50cm, APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterFillRisingAndFallingEdgeMaxObjDeltaDis; // 50cm
	// APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterFillRisingAndFallingEdgeFirstTwoPtMaxObjDeltaDis[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; //  10cm
	{   
		// 0 ~ 10 kph, 11 ~ 15kph, 16 ~ 19kph, 20 ~ 24kph, >25kph
		// two points delta dis:
		//  8 cm,       12cm,         15cm,        18cm,        20cm,
		80,             170,          170,          180,         200		
	},
	
	// APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillRisingEdgeAllowedMinTotalObjPt[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 4 points.
	{
		// 0 ~ 10 kph, 11 ~ 15kph, 16 ~ 19kph, 20 ~ 24kph, >25kph
		// Max buffer size:
		//10,            7,          6,          5,         5		
		// Min total obj dt num:
		6,              5,           5,          4,         4
	},
	// APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillRisingEdgeAllowedMinBigObjPt1[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 2 points. // end pt is rising pt 
	{
		// the end of rising point is still with rising shape.
		// 0 ~ 10 kph, 11 ~ 15kph, 16 ~ 19kph, 20 ~ 24kph, >25kph
		// Max buffer size:
		//10,            7,          6,          5,         5		
		// Min big obj dt num:
		//4,               4,           3,          2,        2, old 2015 02 09
		  8,               6,           4,          3,        3
	},
	// APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillRisingEdgeAllowedMinBigObjPt2[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 3 points. // end pt is flat pt
	{
		// the end of rising point is with flat shape.
		// 0 ~ 10 kph, 11 ~ 15kph, 16 ~ 19kph, 20 ~ 24kph, >25kph
		// Max buffer size:
		//10,            8,          7,          6,         6		
		// Min big obj dt num:
		//5,               5,          4,          3,         3, old 2015 02 09
		  8,               6,           5,          4,        4
	},
	// APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillRisingEdgeAllowedMinObjPtIndex[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // speed < 8kph : 0, < 15kph: 1, < 20kph: 3, > 20kph: 4. 
	{
		// the end of rising point is with flat shape.
		// 0 ~ 10 kph, 11 ~ 15kph, 16 ~ 19kph, 20 ~ 24kph, >25kph
		// Max buffer size:
		//10,            8,          7,          6,         6		
		// Min big obj dt num:
		0,               2,          3,          4,         4
	},
	// APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillFallingEdgeAllowedMinTotalObjPt[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 4 points.
	{
		// 0 ~ 10 kph, 11 ~ 15kph, 16 ~ 19kph, 20 ~ 24kph, >25kph
		// Max buffer size:
		//10,            8,          7,          6,         6		
		// Min total obj dt num:
		7,              6,           5,          4,         4
	},
	// APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillFallingEdgeAllowedMinBigObjPt1[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 2 points. // end pt is Falling pt 
	{
		// the start of falling point is still with falling shape.
		// 0 ~ 10 kph, 11 ~ 15kph, 16 ~ 19kph, 20 ~ 24kph, >25kph
		// Max buffer size:
		//10,            8,          7,          6,         6		
		// Min big obj dt num:
		//4,               4,           3,          2,        2, old 2015 02 09
		  8,               6,           4,          3,        3
	},
	// APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillFallingEdgeAllowedMinBigObjPt2[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 3 points. // end pt is flat pt
	{
		// the start of falling point is with flat shape.
		// 0 ~ 10 kph, 11 ~ 15kph, 16 ~ 19kph, 20 ~ 24kph, >25kph
		// Max buffer size:
		//10,            8,          7,          6,         6		
		// Min big obj dt num:
		//5,               5,          4,          3,         3, old 2015 02 09
		  8,               7,           5,          4,        4
	},
	// APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillFallingEdgeAllowedMinObjPtIndex[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // speed < 8kph : 0, < 15kph: 1, < 20kph: 3, > 20kph: 4. 
	{
		// the end of rising point is with flat shape.
		// 0 ~ 10 kph, 11 ~ 15kph, 16 ~ 19kph, 20 ~ 24kph, >25kph
		// Max buffer size:
		//10,            8,          7,          6,         6		
		// Min big obj dt num:
		0,               2,          3,          4,         4
	},
	150, //25cm, // APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterFillFlatProfilePointsMaxDeltaDis1; // 25cm // max 45deg.
	300, //25cm, // APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterFillFlatProfilePointsMaxDeltaDis2; // 25cm // max 45deg.
	
	17, // 17: 30deg. APA_SLOT_PT_SLOPE_TYPE APASlotSnsDtdObjDisFilterFillFlatProfileMaxSlope; // 30, // 30: 45deg.
	//APA_SLOT_PT_SLOPE_TYPE APASlotSnsDtdObjDisFilterFillFlatProfileMaxDeltaSlope[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 5, // 5: 10deg.
	{   
		// 0 ~ 10 kph, 11 ~ 15kph, 16 ~ 19kph, 20 ~ 24kph, >25kph
		// two points delta dis:
		//  3.cm,       5cm,         5cm,        5cm,        4.5cm,
		// 30deg,     26deg,       20deg,      15deg,      10deg,
		17,           15,          11,          8,         5		
	},
	//APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillFlatProfileAllowedMaxNoObjPt[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 
	{
		// 0 ~ 10 kph, 11 ~ 15kph, 16 ~ 19kph, 20 ~ 24kph, >25kph
		// Max buffer size:
		//10,            10,          10,          10,        10		
		// Max no obj dt num:
		3,               4,           4,          5,         5
	},
	//APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillFlatProfileAllowedMaxConsecutiveNoObjPt[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 
	{
		// 0 ~ 10 kph, 11 ~ 15kph, 16 ~ 19kph, 20 ~ 24kph, >25kph
		// Max buffer size:
		//10,            10,          10,          10,        10		
		// Max no obj dt num:
		1,               2,           1,          1,         1
	},
	//APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillFlatProfileAllowedMinTotalObjPt[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 6 points.
	{
		// 0 ~ 10 kph, 11 ~ 15kph, 16 ~ 19kph, 20 ~ 24kph, >25kph
		// Max buffer size:
		//10,           10,          10,         10,       10		
		// Min total obj dt num:
		7,              6,           6,          5,         5
	},
	// APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillFlatProfileAllowedMinBigObjPt1[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 3 points. // obj pt cnt is 6 ~ 8 
	{
		// Total flat obj pt num is less than 5 + min total obj pt / 2:
		// < 8,        < 8,         < 8,        < 7,       < 7,
		// 0 ~ 10 kph, 11 ~ 15kph, 16 ~ 19kph, 20 ~ 24kph, >25kph
		// Max buffer size:
		//10,           10,          10,         10,       10		
		// Min total obj dt num:
		// 7,              6,           6,          5,         5
		// Min Big Obj dt Num:
		//4,               4,            3,          3,          3, old 2015 02 09
		  7,               6,           5,          5,        5
	},
	// APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillFlatProfileAllowedMinBigObjPt2[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 2 points. // obj pt cnt is 9 or 10
	{
		// Total flat obj pt num is less than 5 + min total obj pt / 2:
		// >= 8,        >= 8,         >= 8,        >= 7,       >= 7,
		// 0 ~ 10 kph, 11 ~ 15kph, 16 ~ 19kph, 20 ~ 24kph, >25kph
		// Max buffer size:
		//10,           10,          10,         10,       10		
		// Min total obj dt num:
		// 7,              6,           6,          5,         5
		// Min Big Obj dt Num:
		//3,               3,            2,          2,          2, old 2015 02 09
		  7,               6,           5,          4,        4
	},

	FALSE, // BOOLEAN APASlotSnsDtdObjDisFilterUseConfirmedSmallObjEvenIfBigObjExist; // FALSE.
	// UCHAR APASlotSnsDtdObjDisFilterFillRisingAndFallingEdgeAllowedSmallObjNum[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM];
	{
		// 0 ~ 10 kph, 11 ~ 15kph, 16 ~ 19kph, 20 ~ 24kph, >25kph
		// Max buffer size:
		//10,            8,          7,          6,         6		
		// Max small obj dt num:
		2,               2,          2,          2,         2
	},
	// APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillRisingAndFallingEdgeAllowedMinBigObjNum[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM];
	{
		// 0 ~ 10 kph, 11 ~ 15kph, 16 ~ 19kph, 20 ~ 24kph, >25kph
		// Max buffer size:
		//10,            8,          7,          6,         6		
		// Max small obj dt num:
		3,               3,          3,          3,         3
	},
		
	// SaveSnsDtdObjDisToFilterBuf related cal end
	
	
	600, // 60cm APA_DISTANCE_TYPE APASlotRoundObjPtSearchBackMaxDis;
	1000, // 1m. APA_DISTANCE_TYPE APASlotDisToCarCheckCarDrvDis1; // 100cm.
	2200, // kjy changed to 2200 2014 12 29. 1500 is too small for the checking of car to obj2 dis if the sensor sensitivity is big and the obj2 is with very big rising edge 3000, // 3m. APA_DISTANCE_TYPE APASlotDisToCarCheckCarDrvDis2; // 300cm.// if it is set to 3m, for the pole or squre, the first slot will be removed. so just set the dis less than the min perpendicular slot len.
	3500, // 4m. APA_DISTANCE_TYPE APASlotDisToCarCheckCarDrvDis3; // 300cm.// if it is set to 3m, for the pole or squre, the first slot will be removed. so just set the dis less than the min perpendicular slot len.
	150, // 15cm, APA_DISTANCE_TYPE APASlotDisToCarCheckObjIsFlatTolDis; // 15cm.
	1200, // 50cm, APA_DISTANCE_TYPE APASlotDisToCarCheckObjIsFlatMinWidth; // 120cm.
	700, // 70cm, APA_DISTANCE_TYPE APASlotDisToCarCheckObjIsFlatMinValidObjWidth; // 70cm.
	600, // 60cm, APA_DISTANCE_TYPE APASlotDisToCarCheckObjIsFlatMaxCarDrvDis; // 60cm.
	-17, // -17: 30deg. APA_SLOT_PT_SLOPE_TYPE APASlotDisToCarCheckObjIsFlatMinSlope; // -17, // 30deg.

	700, // 2013 11 4: kjy change from 1.5m to 1m;// 1.5m, def: 100cm APA_DISTANCE_TYPE APASlotCarToObjDisCalObj1WidthToBeConsidered;
	1000, // 2013 11 4: kjy change from 1.5m to 1m;// 1.5m, def: 100cm APA_DISTANCE_TYPE APASlotCarToObjDisCalObj2WidthToBeConsidered;
	500, // 40cm, 50cm def: 20cm APA_DISTANCE_TYPE APASlotCarToObjDisCalObjToCarDisTolLen;

	//APA_DISTANCE_TYPE APASlotHFOVWidthBySeg[APA_SLOT_APA_SENSOR_HFOV_DIVIDED_SEG_NUM];
	{
		800,
		1000,
		1000,
		1000,
		1000,
		1000,
		1000,
		800,
		600,
		600,
		600,
		600,
		500,
		400,
		400,
		400,
		400,
		400,
		400,		
		400		
	},			

	APA_FLS_SNS_INDEX,// APA_ENUM_TYPE APASlotLAPASnsIndex;
	
	APA_FRS_SNS_INDEX,// APA_ENUM_TYPE APASlotRAPASnsIndex;
	
	// APA_SLOT_ALLOW_SLOT_WITH_OBJ_AT_HEAD_AND_TAIL, //APA_SLOT_ALLOW_ALL_SLOT_DEFINITION, //  short APASlotDefinition;

	// APA_DISTANCE_TYPE APASlotObjCheckMaxSearchDisForNoObjDetected[APA_SLOT_OBJ_IS_BIG_ENOUGH_CHECK_TYPE_NUM];
	{
		// 	APASlotObjIsBigEnoughCheckType_Obj = 0, 
		500, // 80cm, or, def: 50cm.                 
		// APASlotObjIsBigEnoughCheckType_Curb
		1300  // 1.3m
	},
	// APA_DISTANCE_TYPE APASlotObjCheckDevidedObjDis[APA_SLOT_SUPPORT_OBJ_CHECK_OBJ_DIS_DEVIDED_NUM];
	{
		// 0 ~ 0.8m ~ 1.3 ~ 1.8m ~ 4.5m
		800, 1300, 1800
	},
	// APA_ENUM_TYPE APASlotObjCheckMinObjPointNum[APA_SLOT_SUPPORT_OBJ_CHECK_SPEED_DEVIDED_NUM][APA_SLOT_SUPPORT_OBJ_CHECK_OBJ_DIS_DEVIDED_NUM + 1];
	{
		// 0 ~ 5 km/h
		// 0 ~ 0.8m ~ 1.3 ~ 1.8m ~ 4.5m
		{3,      3,         2,         2},
		// 5 ~ 10 km/h
		{3,      3,         2,         2},
		// 10 ~ 15 km/h
		{3,      3,         2,         2},
		// 15 ~ 20 km/h
		{2,      2,         2,         2},
		// 20 ~ 25 km/h
		{2,      2,         2,         2},
		// 25 ~ 30 km/h
		{2,      2,         2,         2},
	},
	// APA_DISTANCE_TYPE APASlotObjCheckMinObjWidth[APA_SLOT_SUPPORT_OBJ_CHECK_SPEED_DEVIDED_NUM][APA_SLOT_SUPPORT_OBJ_CHECK_OBJ_DIS_DEVIDED_NUM + 1];;
	{
		// 0 ~ 5 km/h
		// 0 ~ 0.8m ~ 1.3 ~ 1.8m ~ 4.5m
		{300,          400,         200,         200},
		// 5 ~ 10 km/h
		{300,          400,         200,         200},
		// 10 ~ 15 km/h
		{300,          400,         200,         200},
		// 15 ~ 20 km/h
		{200,          300,         200,         200},
		// 20 ~ 25 km/h
		{200,          300,         200,         200},
		// 25 ~ 30 km/h
		{200,          300,         200,         200},
	},

	2, // within 1.3m curb length, it have to at least 2 points. APA_ENUM_TYPE APASlotObjCheckMinCurbPointNum;
	500, // within 1.3m or big curb length, the min curb point dis should great than 50cm, APA_DISTANCE_TYPE APASlotObjCheckMinCurbWidth;
	// APA_ENUM_TYPE APASlotObjCheckRegardAsObjOrCurbIsBigEnoughMinPointNum[APA_SLOT_OBJ_IS_BIG_ENOUGH_CHECK_TYPE_NUM]; // 5
	{
		6, // APASlotObjIsBigEnoughCheckType_Obj = 0,
		5 // APASlotObjIsBigEnoughCheckType_Curb
	},
	// APA_ENUM_TYPE APASlotObjCheckRegardAsObjOrCurbIsBigEnoughMinContinuousPointNum[APA_SLOT_OBJ_IS_BIG_ENOUGH_CHECK_TYPE_NUM]; // 5
	{
		2, // APASlotObjIsBigEnoughCheckType_Obj = 0,
		2 // APASlotObjIsBigEnoughCheckType_Curb
	},
	// APA_DISTANCE_TYPE APASlotObjCheckRegardAsObjOrCurbIsBigEnoughMinObjWidth[APA_SLOT_OBJ_IS_BIG_ENOUGH_CHECK_TYPE_NUM];
	{
		200, // 50cm, APASlotObjIsBigEnoughCheckType_Obj = 0,
		300 // 50cm, APASlotObjIsBigEnoughCheckType_Curb
	},
	// APA_DISTANCE_TYPE APASlotObjCheckRegardAsSameObjMaxDeltaObjDis[APA_SLOT_OBJ_IS_BIG_ENOUGH_CHECK_TYPE_NUM]; // 120cm
	{
		500, // 50cm, APASlotObjIsBigEnoughCheckType_Obj = 0,
		700 // 0.7m, APASlotObjIsBigEnoughCheckType_Curb
	},

	1500, // 1.5m, APA_DISTANCE_TYPE APASlotObjCheckSearchBkForCheckingObjTypeDisFromCurrentObjPoint; // 1.5m;
	7, // 7, 7 * 20cm = 1.4m, APA_ENUM_TYPE APASlotObjCheckSearchBkForCheckingObjTypeMaxObjPointNum; // 7

	//APA_DISTANCE_TYPE APASlotDetectionCompensateCarToObjDisDevidedThreshold[APA_SLOT_OBJ_CAR_TO_OBJ_DIS_COMPENSATE_TYPE_NUM]; // 0 ~ 10km/h, 10 ~ 20km/h, 20km/h ~
	{
		//800, 1700
		600,   1700
	},


	// 	APA_ENUM_TYPE APASlotDetectionCompensateSpeedDevidedThreshold[APA_SLOT_SUPPORT_SLOT_LENGTH_COMPENSATE_SPEED_DEVIDED_NUM]; // 0 ~ 10km/h, 10 ~ 20km/h, 20km/h ~
	{
		// 10kph,    20kph
		7,          25
	},
	// APA_DISTANCE_TYPE APASlotDetectionCompensateLengthHead[3][APA_SLOT_SUPPORT_SLOT_LENGTH_COMPENSATE_SPEED_DEVIDED_NUM + 1]; // Slot start
	{
		//  APA_SLOT_SIMPLE_OBJ_TYPE_UNKNOWN = 0,
		{
			300, // 0 ~ 10 km/h def: 200
			300, // 10 ~ 20 km/h
			400 // 20 ~ 30 km/h
		},
		//  APA_SLOT_SIMPLE_OBJ_TYPE_ROUND, 
		{
			300, // 0 ~ 10 km/h def: 250
			300, // 10 ~ 20 km/h
			400 // 20 ~ 30 km/h
		},
		//  APA_SLOT_SIMPLE_OBJ_TYPE_SQUARE  
		{
			300, // 0 ~ 10 km/h
			300, // 10 ~ 20 km/h
			400 // 20 ~ 30 km/h
		}
	},
	// APA_DISTANCE_TYPE APASlotDetectionCompensateLengthTail[3][APA_SLOT_SUPPORT_SLOT_LENGTH_COMPENSATE_SPEED_DEVIDED_NUM + 1]; // Slot end.
	{
		// Obj1 = block, obj2 = ISO pole, com_h = 200, com_t = 100, spd < 10, tol = -350.
		//  APA_SLOT_SIMPLE_OBJ_TYPE_UNKNOWN = 0,
		{
			350, // 0 ~ 10 km/h
			250, // 10 ~ 20 km/h
			200 // 20 ~ 30 km/h
		},
		//  APA_SLOT_SIMPLE_OBJ_TYPE_ROUND, 
		{
			350, // 0 ~ 10 km/h
			250, // 10 ~ 20 km/h
			200 // 20 ~ 30 km/h
		},
		//  APA_SLOT_SIMPLE_OBJ_TYPE_SQUARE  
		{
			350, // 0 ~ 10 km/h
			250, // 10 ~ 20 km/h
			200 // 20 ~ 30 km/h
		}
	},
	0, // kjy changed to 0 2014 12 16. 150, // D2SC-S 500, APA_DISTANCE_TYPE APASlotDetectionToleranceDis;
	150, // kjy changed to 15cm 2014 12 16, 250, // 50cm. APA_DISTANCE_TYPE APASlotDetectionToleranceDisForTrajCal;
	17200, // APA_DISTANCE_TYPE APASlotMaxSlotLengthWithInvalidObj2;
	1000, // APA_DISTANCE_TYPE APASlotSlotLengthCompensatedDisWithInvalidObj2;
	300, // 300mm, APA_DISTANCE_TYPE APASlotMinDisCarToObjByPassingSlot;
	2000, // 180mm, APA_DISTANCE_TYPE APASlotMaxDisCarToObjByPassingSlot;
	2800, // 2.8m, APA_DISTANCE_TYPE APASlotMaxDisCarToObjByPassingSlotWhenObjHasOffset;// Use car rear axis center as the reference point 
	10000, // 10m, APA_DISTANCE_TYPE APASlotUseMaxDisCarToObjByPassingSlotWhenObjHasOffsetCarDriveDis; // 10m.
	1300, // 130mm, 	APA_DISTANCE_TYPE APASlotMaxOffsetDisBetweenObj1AndObj2ForParallel;
	1500, // 150mm, 	APA_DISTANCE_TYPE APASlotMaxOffsetDisBetweenObj1AndObj2ForPerpendicular;

	// APACal.APASlotMinDisForCurbDetection = APACal.APASlotMinSlotDepth + APACal.APASlotMinDisCarToObjByPassingSlot; // 2000; // + APACal.WidthOfCar / 2; // mm // do we need this one???
	300 + 500, // 800mm, APA_DISTANCE_TYPE APASlotMinDisForCurbDetection;
	// APACal.APASlotMaxDisForCurbDetection = APACal.APASlotMaxSlotDepth + APACal.APASlotMaxDisCarToObjByPassingSlot; // 4000; // + APACal.WidthOfCar / 2; // mm // do we need this one???
	1800 + 3500, // mm , APA_DISTANCE_TYPE APASlotMaxDisForCurbDetection;// Use car side as the reference point
	500, // 50cm , APA_DISTANCE_TYPE APASlotConsiderSecondSlotDepthMinDeltaSlotLen;
	5537 + 600, // min small slot len + 60cm , APA_DISTANCE_TYPE APASlotRegardAsFirstSlotDepthMinSlotLen;
	2000, // 2000mm , APA_DISTANCE_TYPE APASlotMinStartCheckingCurbOffsetLen;
	1000, // 100cm , APA_DISTANCE_TYPE APASlotMinRegardedAsCurbMinCurbLenAtSlotHeadAndTail;
	5100,//5537,// 4537+1000: just for debug test. 5686, // APA_DISTANCE_TYPE APASlotMinSmallSlotLen; // 6 steps parking. 200 = 20cm, slot tolerance.
	18000, // 18m, def:12m , APA_DISTANCE_TYPE APASlotMaxSlotLength;

	// APA_DISTANCE_TYPE APASlotCurbRegardedAsCurbDetectedDevidedSlotLen[APA_SLOT_CURB_DT_CHECK_DEVIDE_SLOT_LEN_NUM - 1];
	{
		6000,   7500
	},
	// APA_ENUM_TYPE APASlotCurbRegardedAsCurbDetectedMinObjPtNum[APA_SLOT_CURB_DT_CHECK_DEVIDE_SLOT_LEN_NUM]; // 0 ~ 6m ~ 7 ~
	{
		// 0 ~ 6m, 6m ~ 7.5m, 7.5m ~
		3,         4,       5
	},
	1000, // 1m, APA_DISTANCE_TYPE APASlotCurbRegardedAsCurbDetectedMinCurbLen; // 1m.
	1200, // 1.2m, APA_DISTANCE_TYPE APASlotCurbDetCurbToObj2CutOffDis; // 1.2m.

		
	350, // 20201105 350, // 300 mm , APA_DISTANCE_TYPE APASlotCurbLineTolerance;
	800, // 800 mm, APA_DISTANCE_TYPE APASlotCurbLineFitAllowSnsDtObjDisTolerance;
	350, // 35cm, APA_DISTANCE_TYPE APASlotCurbLineFitAllowCurbLineToObjDisTolerance;
	400, // 40cm, APA_DISTANCE_TYPE APASlotCurbLineFitAllowCurbLineToObjDisTolerance2;
	300, // 30cm, APA_DISTANCE_TYPE APASlotEndPosXAllowCurbLineToObjDisTolerance;
	150, // 15cm, APA_DISTANCE_TYPE APASlotEndPosXOutOfAllowCurbLineToObjDisToleranceCompensateDis;
	3, // APA_ENUM_TYPE APASlotCurbLineFitAllowMinObjPt;

	1500, // 1.5m, 	APA_DISTANCE_TYPE APASlotCurbLineFitAllowMinCurbLength;
	40.0 * PI / 180.0, // 40def, def: 60 deg. 	APA_ANGLE_TYPE APASlotCurbLineFitAllowMaxDeltaCarAngAndCurbLineAng;
	70.0 * PI / 180.0, // 70deg. APA_ANGLE_TYPE APASlotCurbLineFitAllowMaxCurbLineAndYAng;
	10.0 / 8.12, // actual 10deg -> fit 8.12deg. APA_ANGLE_TYPE APASlotCurbLineFitCurbLineAngCompensateRatio;

	1400, // def: 500mm , APA_DISTANCE_TYPE APASlotMinSlotDepth;// Use car rear axis center as the reference point
	2600, // def: 3500mm , APA_DISTANCE_TYPE APASlotMaxSlotDepth;// Use car rear axis center as the reference point
	16000, // def: 15m, APA_DISTANCE_TYPE APASlotMaxPathAfterSlot; Distance between slot end index (obj2 index) car center point to cur car center point dis, so, it should actully - length between rear axis to front bumper.
	2400, // kjy changed to 2400 2014 12 29. 1600, // 3100, // 3500, // def: 3000mm , APA_DISTANCE_TYPE APASlotMinPathAfterSlot; // Important notes: this value should great than APASlotDisToCarCheckCarDrvDis2, and less than min per slot width.
	10000, // def: 11m APA_DISTANCE_TYPE APASlotMinPathAfterSlotWithoutObj2; // dis from obj1 to car front bumper. should considering convex or concave road.
	4500, // def:  APA_DISTANCE_TYPE APASlotMinPathAfterSlotWithVeryBigSlot;
	1500,  // def: 2m, APA_DISTANCE_TYPE APASlotRearSideSnsStartInsertObjPtToFrnSideSnsCarDrvDis;
	6, //tan(10) * 30  APA_SLOT_PT_SLOPE_TYPE APASlotRearSideSnsSlopPtSlopeTolerance;
	300,  // APA_DISTANCE_TYPE APASlotRearSideSnsAndFrntSideSnsCarCenterPtXTolerance
	700, //APA_DISTANCE_TYPE APASlotRearSideSnsAndFrntSideSnsCarCenterPtYTolerance
	//(1.5 /180.0 * PI),//APA_ANGLE_TYPE    APASlotRearSideSnsAndFrntSideSnsCarCenterPtAngTol;
	250, //APA_DISTANCE_TYPE APASlotFrontSideSnsCheckAsNoObjDisValue;
	400, //APA_DISTANCE_TYPE APASlotRearSideSnsCheckAsNoObjDisValue;
	11, // 20deg. APA_SLOT_PT_SLOPE_TYPE  APASlotRearSideSnsCheckCurbSlopeMaxValue;
	4, // APA_ENUM_TYPE APASlotRearSideSnsCheckCurbMinValidCurbPtNum;
	1000, // 1m, APA_DISTANCE_TYPE APASlotRearSideSnsCheckCurbMinValidCurbLength;
	4000, // 4m, APA_DISTANCE_TYPE APASlotRearSideSnsCheckCurbMaxAllowSearchBkDis;
	2000, // 1m, APA_DISTANCE_TYPE APASlotRearSideSnsCheckCurbMaxAllowObj12SearchBkDis;
	21.0 * PI / 180.0, // 21deg. 4m with R = 15m. APA_ANGLE_TYPE APASlotRearSideSnsCheckAsInvalidCurbPtMinDeltaCarAng; // 16deg. 4m with R = 15m.
	500, // 50cm, APA_DISTANCE_TYPE APASlotRearSideSnsCheckCurbAsValidMinNoObjDisWidth; // 50cm
	3000, // 3m, APA_DISTANCE_TYPE APASlotRearSideSnsCheckCurbAsValidCurbMaxLength; // 300cm
	1400, // 80cm, APA_DISTANCE_TYPE APASlotRearSideSnsCheckCurbRegardedAsSmallObjWidth; // 120cm
	3, // 6deg, APA_SLOT_PT_SLOPE_TYPE APASlotRearSideSnsCheckCurbRegardedAsFlatObjMaxDeltaSlope; // 3 = 6deg.
	11, // APA_SLOT_PT_SLOPE_TYPE APASlotRearSideSnsCheckCurbRegardedAsFlatObjMaxSlope; // 11 = 20deg.
	40, // 4cm, APA_DISTANCE_TYPE APASlotRearSideSnsCheckCurbRegardedAsFlatObjMaxDeltaDis; // 4cm.
	800, // 80cm, APA_DISTANCE_TYPE APASlotRearSideSnsCheckCurbAsValidForSmallObjDeltaCarToObjDis1; // 80cm
	1600, // 1.6m, APA_DISTANCE_TYPE APASlotRearSideSnsCheckCurbAsValidForSmallObjDeltaCarToObjDis2; // 1.6 m
	-200, // -20cm, curb dis - obj dis, APA_DISTANCE_TYPE APASlotRearSideSnsCheckCurbAsValidForFlatObjDeltaCarToObjDis1; // - 20cm
	300, // 30cm, APA_DISTANCE_TYPE APASlotRearSideSnsCheckCurbAsValidForFlatObjDeltaCarToObjDis2; // 30cm
	1400, // 1.4m, APA_DISTANCE_TYPE APASlotRearSideSnsCheckCurbAsValidForFlatObjDeltaCarToObjDis3; // 140cm
	- 4000, // -4m, actually disabled the function, APA_DISTANCE_TYPE APASlotRearSideSnsCheckCurbAsValidForCarDeltaCarToObjDis1; // -200cm
	1400, // 1.4m, APA_DISTANCE_TYPE APASlotRearSideSnsCheckCurbAsValidForCarDeltaCarToObjDis2; // 140cm
	600, // 60cm, APA_DISTANCE_TYPE APASlotRearSideSnsCheckCurbAsValidForHighCurbCarToObjDis1; // 60cm
		



	500, //APA_DISTANCE_TYPE APASlotFrontSideSnsAdjacentPtsAreNoObjDisMinYValue;
	90,	// degree , uchar APASlotMaxCarAngDuringMeasurement
/*2.4.9.2*** Perpendicular slot ****/
	//APA_SLOT_ALLOW_SLOT_WITH_OBJ_AT_HEAD_AND_TAIL, //APA_SLOT_ALLOW_ALL_SLOT_DEFINITION,  //USHORT PSlotDefinition;
	2100,//3000, // def: 2.4m, APA_DISTANCE_TYPE APASlotPMinSmallSlotLen; // 6 steps parking. 	
	1500, // 1.5m, APA_DISTANCE_TYPE APASlotPNeedToCheckSlotEndPtMinSlotLen;
	800, // 80cm, APA_DISTANCE_TYPE APASlotPNeedToCheckSlotEndPtMinPoleWidth;
	800, // 80cm, APA_DISTANCE_TYPE APASlotPRegardAsInvalidSlotEndPtMinDeltaCarPos;
	4000, // def: 3.5m, APA_DISTANCE_TYPE APASlotPDefSlotLenWithoutObj1; 	
	4000, // def: 3.5m, APA_DISTANCE_TYPE APASlotPDefSlotLenWithoutObj2; 	
	18000,//12000,//APA_DISTANCE_TYPE APASlotPMaxSlotLength;//2014 03 11 wsc
	5000, //APA_DISTANCE_TYPE APASlotPMaxSlotLengthWithInvalidObj2;
	3800,  // def: 4800, APA_DISTANCE_TYPE APASlotPMinSlotDepth;// Use car rear axis center as the reference point 
	5500,  //APA_DISTANCE_TYPE APASlotPMaxSlotDepth;// Use car rear axis center as the reference point 
	12000, //APA_DISTANCE_TYPE APASlotPMaxPathAfterSlot;
	3000, // 300cm , APA_DISTANCE_TYPE APASlotPMinStartCheckingCurbOffsetLen;
	1.0 * PI / 180.0, // 3deg, APA_ANGLE_TYPE APASlotPObj2NotExistObj1BorderLineFitCompensateAng1;
	6.0 * PI / 180.0, // 3deg, APA_ANGLE_TYPE APASlotPObj2NotExistObj1BorderLineFitCompensateAng2;
	2700, // kjy changed to 2500 2014 12 29, 2000, // 3500, // def:4.5m APA_DISTANCE_TYPE APASlotPMinPathAfterSlotWithObj2; // Dis cal from slot end pt.
	6500, // 5500, // def:6.5m, APA_DISTANCE_TYPE APASlotPMinPathAfterSlotWithoutObj2; // dis cal from slot start pt to front bumper. should considering covex or concave road.
	5000, // 5m. APA_DISTANCE_TYPE APASlotPMinPathAfterSlotWithObj2BigSlot; // Dis cal from slot end pt.
	250, // 25cm, APA_DISTANCE_TYPE APASlotPObj1YCorCompensateDeltaDis1IfInvalid; // car L corner pt.y + this delta dis is regarded as the Obj1.Y.
	250, // 25cm, APA_DISTANCE_TYPE APASlotPObj2YCorCompensateDeltaDis1IfInvalid; // car R corner pt.y + this delta dis is regarded as the Obj2.Y.
	500, // 2014 4 22: change to 50cm, 80cm, 30cm, APA_DISTANCE_TYPE APASlotPObj1YCorCompensateDeltaDis2IfInvalid; // Car L side + this delta dis and transform to the real coor.Y is regarded as Obj1.Y.
	500, // 2014 4 22: change to 50cm, 80cm, 30cm, APA_DISTANCE_TYPE APASlotPObj2YCorCompensateDeltaDis2IfInvalid; // Car R side + this delta dis and transform to the real coor.Y is regarded as Obj2.Y.
	
/*2.4.9.3*** Park Exit slot ****/
	500, // 50cm, APA_DISTANCE_TYPE APASlotPEStartConsiderCornerObjMaxDis; // 50cm.

#if __EP21__
	(4646 + 700), //APA_DISTANCE_TYPE APASlotPEMinSlotLength; APACal.LengthOfCar + 600; // 800mm.
#endif
	2000, // 80cm, APA_DISTANCE_TYPE APASlotPEDefaultFrontObjectDisWhenNoObjectIsDetected; // 80cm.	
	1800, //APA_DISTANCE_TYPE APASlotPEDefaultRearObjectDisWhenNoObjectIsDetected; // 80cm.
	100, //wuzhen 2020 0611, 3->24   //APA_MS_TIME_TYPE APASlotPESlotCheckStartDelayTime;                         //modify by wuzhen 0601
	3000, //APA_DISTANCE_TYPE APASlotPEMinParkingOutSideObjectDis;	
	
/*2.4.9.4***Angular slot ****/
	
	//APA_SLOT_ALLOW_ALL_SLOT_DEFINITION, //USHORT APSlotDefinition;
	-9.0036545, // - MATH_TAN(80.0), //APA_DISTANCE_CAL_FLOAT_TYPE APASlotAPMinKofTheAngularSlotBorderLine;
	-0.64836085, // - MATH_TAN(10.0), //APA_DISTANCE_CAL_FLOAT_TYPE APASlotAPMaxKofTheAngularSlotBorderLine;
	2000, //APA_DISTANCE_TYPE APASlotAPSlotBorderLineMinLength;
	300, //APA_DISTANCE_TYPE APASlotAPMinDisCarToObjByPassingSlot; // Use car side as the reference point 
	1800, //APA_DISTANCE_TYPE APASlotAPMaxDisCarToObjByPassingSlot;// Use car side as the reference point 
	2417,  //APACal.WidthOfCar + 300 + 300 APA_DISTANCE_TYPE APASlotAPMinSlotWidthWithNoCarAtHead;
	2417, //APACal.WidthOfCar + 300 + 300; APA_DISTANCE_TYPE APASlotAPMinSlotWidthWithObjAtHead;
	300, //APA_DISTANCE_TYPE APASlotAPSafetyDisToTheSideCarAtTheEndPosition;
	100, //APA_DISTANCE_TYPE APASlotAPCalMinDisToTheCurb; // This parameter is used to confirm if the slot depth is big enough. We should consider the car has a round angle at front and rear. this parameter may be with negative value.
	100, //APA_DISTANCE_TYPE APASlotAPRegardAsACarMinCarWidth;
	3500, //APA_DISTANCE_TYPE APASlotAPRegardAsACarMaxCarWidth;
	8000, //APA_DISTANCE_TYPE APASlotAPRegardAsNoObjMinSlotWidth;
	8000, //APA_DISTANCE_TYPE APASlotAPAllowMaxSlotWidthBetweenTwoCars; // Hear, it is the object 1 (car 1) width + current car width + 2 * safty distance between cars.
    2000 + 300 + 2000 + 300, //APA_DISTANCE_TYPE APASlotAPAllowMinSlotWidthBetweenTwoCars; // Hear, it is the object 1 (car 1) width + current car width + 2 * safty distance between cars.


/* 2.4.9.5 *** Slot Correction ***/

	400, //40cm, APA_DISTANCE_TYPE APASlotCorSDGKeepObjPtDis;
	1500, // 150cm, APA_DISTANCE_TYPE APASlotCorSDGKeepNoObjPtDis;
	250, // 25cm, APA_DISTANCE_TYPE APASlotCorSDGKeepObjPtMinDeltaDtDis;
	200, // 20cm, APA_DISTANCE_TYPE APASlotCorSDGSnsDtObjReagionWidth;
	250, // 25cm, APA_DISTANCE_TYPE APASlotCorSDGSnsDtObjRegardedAsSameObjTolDis;
	60, // 60%, UCHAR APASlotCorSDGSnsDtObjProbalilityPercentage;
	//APASlotPCorRROrRLSnsDeltaAngInfo APASlotPCorRROrRLDeltaAngBetweenCurAngAndEndAng
	{
		7, 
		{
			((-20) * PI / 180.0), 
			(0 * PI / 180.0),
			(10 * PI / 180.0),
			(20 * PI / 180.0),
			(30 * PI / 180.0),
			(40 * PI / 180.0),
			(50 * PI / 180.0),
			(70 * PI / 180.0)
		}	
	},
	//APASlotPCorRRSOrRLSSnsDeltaAngInfo APASlotPCorSideSnsDeltaAngBetweenCurAngAndEndAng
	{
		5, 
		{
			(-20 * PI / 180.0),
			(0 * PI / 180.0),
			(10 * PI / 180.0),
			(20 * PI / 180.0),
			(30 * PI / 180.0),
			(40 * PI / 180.0)
		}	
	},
	//APA_DISTANCE_TYPE APASlotPCorCorOrSideSnsDisArray[2][3];
	  
	{
		{400, 800, 1200}, //Cor sns   
		{400, 800, 1200} //Side Sns
	},
	//mm
	#ifdef APA_WITH_NORMAL_CORNER_UPA_SNS_POSITION
    //APA_ANGLE_TYPE APASlotPCorCorSnsCompensatAngByDeltaAngAndSnsDtObjDis[2][APA_SLOT_COR_DELTA_ANG_MAX_ZONE_NUM][APA_SLOT_P_COR_SNS_DIS_DIV_NUM];
	{
		//RRC	
		{
			// 400mm               800 mm            1200 mm            1200 ~ mm
			{(51.25 * PI / 180), (52.93 * PI / 180), (56.01 * PI / 180), (56.01 * PI / 180)},//Delta angle: (( -20) * PI / 180.0)
			{(51.25 * PI / 180), (52.93 * PI / 180), (56.01 * PI / 180), (56.01 * PI / 180)}, //Delta angle: ((0) * PI / 180.0)
			//{(56.26 * PI / 180), (53.22 * PI / 180), (52.35 * PI / 180), (52.35 * PI / 180)},//Delta angle: ((10) * PI / 180.0)
			//{(62.94 * PI / 180), (65.0 * PI / 180), (65.0 * PI / 180), (68.0 * PI / 180)},//Delta angle: ((10) * PI / 180.0)
			{(62.94 * PI / 180), (70.0 * PI / 180), (75.0 * PI / 180), (75.0 * PI / 180)},//Delta angle: ((10) * PI / 180.0)
			//{(62.94 * PI / 180), (55.52 * PI / 180), (55.28 * PI / 180), (55.28 * PI / 180)},//Delta angle: ((20) * PI / 180.0)
			{(62.94 * PI / 180), (70.0 * PI / 180), (75.0 * PI / 180), (75.0 * PI / 180)},//Delta angle: ((20) * PI / 180.0)
			//{(62.94 * PI / 180), (65.0 * PI / 180), (65.0 * PI / 180), (68.0 * PI / 180)},//Delta angle: ((20) * PI / 180.0)
			//{(52.35 * PI / 180), (53.22 * PI / 180), (53.12 * PI / 180), (53.12 * PI / 180)},//Delta angle: (( 30) * PI / 180.0)
			{(62.94 * PI / 180), (60.0 * PI / 180), (65.0 * PI / 180), (68.0 * PI / 180)},//Delta angle: (30) * PI / 180.0)
			{(48.35 * PI / 180), (51.52 * PI / 180), (50.07 * PI / 180), (50.07 * PI / 180)},//Delta angle: ((40) * PI / 180.0)
			{(54.16 * PI / 180), (52.63 * PI / 180), (52.93 * PI / 180), (52.93 * PI / 180)},//Delta angle: ((50) * PI / 180.0)
			{(62.9 * PI / 180), (53.53 * PI / 180), (52.54 * PI / 180),  (52.54 * PI / 180)} //Delta angle: ((70) * PI / 180.0)
	     },
	     //RLC
		{
			// 400mm               800 mm            1200 mm            1200 ~ mm
			{(51.25 * PI / 180), (52.93 * PI / 180), (56.01 * PI / 180), (56.01 * PI / 180)},//Delta angle: (( -20) * PI / 180.0)
			{(51.25 * PI / 180), (52.93 * PI / 180), (56.01 * PI / 180), (56.01 * PI / 180)}, //Delta angle: ((0) * PI / 180.0)
			//{(56.26 * PI / 180), (53.22 * PI / 180), (52.35 * PI / 180), (52.35 * PI / 180)},//Delta angle: ((10) * PI / 180.0)
			{(20.0 * PI / 180), (42.0 * PI / 180), (25.0 * PI / 180), (25.0 * PI / 180)},//Delta angle: ((10) * PI / 180.0)
			//{(62.94 * PI / 180), (55.52 * PI / 180), (55.28 * PI / 180), (55.28 * PI / 180)},//Delta angle: ((20) * PI / 180.0)
			{(23.0 * PI / 180), (25.0 * PI / 180), (28.0 * PI / 180), (28.0 * PI / 180)},//Delta angle: ((20) * PI / 180.0)
			//{(52.35 * PI / 180), (53.22 * PI / 180), (53.12 * PI / 180), (53.12 * PI / 180)},//Delta angle: (( 30) * PI / 180.0)
			{(45.5 * PI / 180), (48.0 * PI / 180), (48.0 * PI / 180), (48.0 * PI / 180)},//Delta angle: ((30) * PI / 180.0)
			{(48.35 * PI / 180), (51.52 * PI / 180), (50.07 * PI / 180), (50.07 * PI / 180)},//Delta angle: ((40) * PI / 180.0)
			{(54.16 * PI / 180), (52.63 * PI / 180), (52.93 * PI / 180), (52.93 * PI / 180)},//Delta angle: ((50) * PI / 180.0)
			{(62.9 * PI / 180), (53.53 * PI / 180), (52.54 * PI / 180),  (52.54 * PI / 180)} //Delta angle: ((70) * PI / 180.0)
	     },
	},

	//APA_ANGLE_TYPE APASlotPCorRROrRLSnsCompensatAngByDeltaAng[2][APA_SLOT_COR_DELTA_ANG_MAX_ZONE_NUM];
	{
		//RRC
			{
				(52.25 * PI / 180),//Delta angle: ((-10) * PI / 180.0)
				(52.45 * PI / 180), //Delta angle: ((0) * PI / 180.0)
				(54.89 * PI / 180),//Delta angle: ((10) * PI / 180.0)
				(56.56 * PI / 180),//Delta angle: ((20) * PI / 180.0)
				(53.61 * PI / 180),//Delta angle: ((30) * PI / 180.0)
				(50.78 * PI / 180),//Delta angle: ((40) * PI / 180.0)
				(53.98 * PI / 180),//Delta angle: ((50) * PI / 180.0)
				(56.71 * PI / 180) //Delta angle: ((70 ) * PI / 180.0)
			 },
		//RLC	 
			{
				(52.25 * PI / 180),//Delta angle: ((-10) * PI / 180.0)
				(52.45 * PI / 180), //Delta angle: ((0) * PI / 180.0)
				(54.89 * PI / 180),//Delta angle: ((10) * PI / 180.0)
				(56.56 * PI / 180),//Delta angle: ((20) * PI / 180.0)
				(53.61 * PI / 180),//Delta angle: ((30) * PI / 180.0)
				(50.78 * PI / 180),//Delta angle: ((40) * PI / 180.0)
				(53.98 * PI / 180),//Delta angle: ((50) * PI / 180.0)
				(56.71 * PI / 180) //Delta angle: ((70 ) * PI / 180.0)
			 },
	},

	#else
    //APA_ANGLE_TYPE APASlotPCorCorSnsCompensatAngByDeltaAngAndSnsDtObjDis[2][APA_SLOT_COR_DELTA_ANG_MAX_ZONE_NUM][APA_SLOT_P_COR_SNS_DIS_DIV_NUM];
	{
		//RRC	
		{
			// 400mm               800 mm            1200 mm            1200 ~ mm
			{(-12 * PI / 180), (-2 * PI / 180),  (-1 * PI / 180), (-7 * PI / 180)},//Delta angle: (( -20) * PI / 180.0)
			{(5 * PI / 180),   (18 * PI / 180),  (17 * PI / 180), (19 * PI / 180)}, //Delta angle: ((0) * PI / 180.0)
			{(17 * PI / 180),  (17 * PI / 180),  (20 * PI / 180), (22 * PI / 180)},//Delta angle: ((10) * PI / 180.0)
			{(42 * PI / 180),  (20 * PI / 180),  (34 * PI / 180), (31 * PI / 180)},//Delta angle: ((20) * PI / 180.0)
			{(40 * PI / 180),  (40 * PI / 180),   (40 * PI / 180), (40 * PI / 180)},//Delta angle: (( 30) * PI / 180.0)
			{(40 * PI / 180),  (40 * PI / 180),   (40 * PI / 180), (40 * PI / 180)},//Delta angle: ((40) * PI / 180.0)
			{(40 * PI / 180),  (40 * PI / 180),   (40 * PI / 180), (40 * PI / 180)},//Delta angle: ((50) * PI / 180.0)
			{(40 * PI / 180),  (40 * PI / 180),   (40 * PI / 180), (40 * PI / 180)} //Delta angle: ((70) * PI / 180.0)
	     },
	     //RLC
		{
			// 400mm               800 mm            1200 mm            1200 ~ mm
			{(43 * PI / 180),  (40 * PI / 180), (38 * PI / 180), (40 * PI / 180)},//Delta angle: (( -20) * PI / 180.0)
			{(-5 * PI / 180),  (9 * PI / 180), (15 * PI / 180), (14 * PI / 180)}, //Delta angle: ((0) * PI / 180.0)
			{(-12 * PI / 180), (-1 * PI / 180),(5 * PI / 180),  (5 * PI / 180)},//Delta angle: ((10) * PI / 180.0)
			{(-23 * PI / 180), (-16 * PI / 180),(-5 * PI / 180), (-7 * PI / 180)},//Delta angle: ((20) * PI / 180.0)
			{(-39 * PI / 180), (-28 * PI / 180), (-17 * PI / 180), (-10 * PI / 180)},//Delta angle: (( 30) * PI / 180.0)
			{(-42 * PI / 180), (-43 * PI / 180), (-13 * PI / 180), (-29 * PI / 180)},//Delta angle: ((40) * PI / 180.0)
			{(-47 * PI / 180), (-47 * PI / 180), (-24 * PI / 180), (-20 * PI / 180)},//Delta angle: ((50) * PI / 180.0)
			{(-47 * PI / 180), (-47 * PI / 180), (-24 * PI / 180), (-20 * PI / 180)} //Delta angle: ((70) * PI / 180.0)
	     },
	},

	//APA_ANGLE_TYPE APASlotPCorRROrRLSnsCompensatAngByDeltaAng[2][APA_SLOT_COR_DELTA_ANG_MAX_ZONE_NUM];
	{
		//RRC
			{
				(-12 * PI / 180),//Delta angle: ((-10) * PI / 180.0)
				(5 * PI / 180), //Delta angle: ((0) * PI / 180.0)
				(17 * PI / 180),//Delta angle: ((10) * PI / 180.0)
				(42 * PI / 180),//Delta angle: ((20) * PI / 180.0)
				(40 * PI / 180),//Delta angle: ((30) * PI / 180.0)
				(40 * PI / 180),//Delta angle: ((40) * PI / 180.0)
				(40 * PI / 180),//Delta angle: ((50) * PI / 180.0)
				(40 * PI / 180) //Delta angle: ((70 ) * PI / 180.0)
			 },
		//RLC	 
			{
				(-5 * PI / 180),//Delta angle: ((-10) * PI / 180.0)
				(-5 * PI / 180), //Delta angle: ((0) * PI / 180.0)
				(-12 * PI / 180),//Delta angle: ((10) * PI / 180.0)
				(-23 * PI / 180),//Delta angle: ((20) * PI / 180.0)
				(-39 * PI / 180),//Delta angle: ((30) * PI / 180.0)
				(-42 * PI / 180),//Delta angle: ((40) * PI / 180.0)
				(-47 * PI / 180),//Delta angle: ((50) * PI / 180.0)
				(-47 * PI / 180) //Delta angle: ((70 ) * PI / 180.0)
			 },
	},
	#endif
	//APA_ANGLE_TYPE APASlotPCorCompDisByConstantValue[2];
	{
		(6 * PI / 180),
		(-6 * PI / 180)

	},

	#ifdef APA_WITH_60_DEG_REAR_SIDE_SENSOR
	//APA_ANGLE_TYPE APASlotPCorSideSnsCompensatAngByDeltaAngAndSnsDtObjDis[2][APA_SLOT_COR_RRS_RLS_DELTA_ANG_MAX_ZONE_NUM][APA_SLOT_P_COR_RRS_RLS_SNS_DIS_DIV_NUM];
	{
		//RRS_SNS_INDEX
		{
			// 400mm         		800 mm    			1200 mm      		1200 ~ mm
			{(0 * PI / 180), (4 * PI / 180),  (2 * PI / 180),  (4 * PI / 180)},//Delta angle: ((-20) * PI / 180.0)
			{(6 * PI / 180), (6 * PI / 180),  (6 * PI / 180),  (6 * PI / 180)}, //Delta angle: ((0) * PI / 180.0)
			{(16 * PI / 180), (16 * PI / 180),  (16 * PI / 180),  (16 * PI / 180)},//Delta angle: ((10) * PI / 180.0)
			{(24 * PI / 180), (24 * PI / 180),  (16 * PI / 180),  (20 * PI / 180)},//Delta angle: ((20) * PI / 180.0)
			{(22 * PI / 180),  (26 * PI / 180),  (30 * PI / 180),  (28 * PI / 180)},//Delta angle: ((30) * PI / 180.0)
			{(50 * PI / 180), (44 * PI / 180),  (40 * PI / 180),  (40 * PI / 180)}//Delta angle: ((40) * PI / 180.0)
	     },
	     //RLS_SNS_INDEX
		{
			// 400mm         		800 mm    			1200 mm      		1200 ~ mm
			{(-20 * PI / 180), (-26 * PI / 180),  (-30 * PI / 180),  (-26 * PI / 180)},//Delta angle: ((-20) * PI / 180.0)
			{(-6.0 * PI / 180), (-6 * PI / 180),  (-6 * PI / 180),  (-6 * PI / 180)}, //Delta angle: ((0) * PI / 180.0)
			{(-10 * PI / 180), (-10 * PI / 180),  (-10 * PI / 180),  (-11 * PI / 180)},//Delta angle: ((10) * PI / 180.0)
			{(10 * PI / 180), (10 * PI / 180),  (6 * PI / 180),  (0 * PI / 180)},//Delta angle: ((20) * PI / 180.0)
			{(22 * PI / 180), (8 * PI / 180),  (7 * PI / 180),  (5 * PI / 180)},//Delta angle: ((30) * PI / 180.0)
			{(30 * PI / 180), (16 * PI / 180),  (10 * PI / 180),  (8 * PI / 180)}//Delta angle: ((40) * PI / 180.0)
	     }
	},	
	//APA_ANGLE_TYPE APASlotPCorSideSnsCompensatAngByDeltaAng[2][APA_SLOT_COR_RRS_RLS_DELTA_ANG_MAX_ZONE_NUM];
	{
	//RRS_SNS_INDEX
		{
			(6 * PI / 180), //Delta angle: ((-20) * PI / 180.0)
			(6 * PI / 180), //Delta angle: (( 0) * PI / 180.0)
			(6 * PI / 180),//Delta angle: ((10) * PI / 180.0)
			(6 * PI / 180),//Delta angle: ((20) * PI / 180.0)
			(6 * PI / 180),//Delta angle: ((30) * PI / 180.0)
			(6 * PI / 180)//Delta angle: ((40) * PI / 180.0)
		 },
	//RLS_SNS_INDEX
		{
			(-6 * PI / 180),//Delta angle: ((-20) * PI / 180.0)
			(-6 * PI / 180), //Delta angle: (( 0) * PI / 180.0)
			(-6 * PI / 180),//Delta angle: ((10) * PI / 180.0)
			(-6 * PI / 180),//Delta angle: ((20) * PI / 180.0)
			(-6 * PI / 180),//Delta angle: ((30) * PI / 180.0)
			(-6 * PI / 180)//Delta angle: ((40) * PI / 180.0)
		 },
	},
	#else
	//APA_ANGLE_TYPE APASlotPCorSideSnsCompensatAngByDeltaAngAndSnsDtObjDis[2][APA_SLOT_COR_RRS_RLS_DELTA_ANG_MAX_ZONE_NUM][APA_SLOT_P_COR_RRS_RLS_SNS_DIS_DIV_NUM];
	{
		//RRS_SNS_INDEX
		{
			// 400mm         		800 mm    			1200 mm      		1200 ~ mm
			{(0 * PI / 180), (4 * PI / 180),  (2 * PI / 180),  (4 * PI / 180)},//Delta angle: ((-20) * PI / 180.0)
			{(6 * PI / 180), (6 * PI / 180),  (6 * PI / 180),  (6 * PI / 180)}, //Delta angle: ((0) * PI / 180.0)
			{(16 * PI / 180), (16 * PI / 180),  (16 * PI / 180),  (16 * PI / 180)},//Delta angle: ((10) * PI / 180.0)
			{(24 * PI / 180), (24 * PI / 180),  (16 * PI / 180),  (20 * PI / 180)},//Delta angle: ((20) * PI / 180.0)
			{(22 * PI / 180),  (26 * PI / 180),  (30 * PI / 180),  (28 * PI / 180)},//Delta angle: ((30) * PI / 180.0)
			{(50 * PI / 180), (44 * PI / 180),  (40 * PI / 180),  (40 * PI / 180)}//Delta angle: ((40) * PI / 180.0)
	     },
	     //RLS_SNS_INDEX
		{
			// 400mm         		800 mm    			1200 mm      		1200 ~ mm
			{(-20 * PI / 180), (-26 * PI / 180),  (-30 * PI / 180),  (-26 * PI / 180)},//Delta angle: ((-20) * PI / 180.0)
			{(-6.0 * PI / 180), (-6 * PI / 180),  (-6 * PI / 180),  (-6 * PI / 180)}, //Delta angle: ((0) * PI / 180.0)
			{(-10 * PI / 180), (-10 * PI / 180),  (-10 * PI / 180),  (-11 * PI / 180)},//Delta angle: ((10) * PI / 180.0)
			{(10 * PI / 180), (10 * PI / 180),  (6 * PI / 180),  (0 * PI / 180)},//Delta angle: ((20) * PI / 180.0)
			{(22 * PI / 180), (8 * PI / 180),  (7 * PI / 180),  (5 * PI / 180)},//Delta angle: ((30) * PI / 180.0)
			{(30 * PI / 180), (16 * PI / 180),  (10 * PI / 180),  (8 * PI / 180)}//Delta angle: ((40) * PI / 180.0)
	     }
	},	
	//APA_ANGLE_TYPE APASlotPCorSideSnsCompensatAngByDeltaAng[2][APA_SLOT_COR_RRS_RLS_DELTA_ANG_MAX_ZONE_NUM];
	{
	//RRS_SNS_INDEX
		{
			(6 * PI / 180), //Delta angle: ((-20) * PI / 180.0)
			(6 * PI / 180), //Delta angle: (( 0) * PI / 180.0)
			(6 * PI / 180),//Delta angle: ((10) * PI / 180.0)
			(6 * PI / 180),//Delta angle: ((20) * PI / 180.0)
			(6 * PI / 180),//Delta angle: ((30) * PI / 180.0)
			(6 * PI / 180)//Delta angle: ((40) * PI / 180.0)
		 },
	//RLS_SNS_INDEX
		{
			(-6 * PI / 180),//Delta angle: ((-20) * PI / 180.0)
			(-6 * PI / 180), //Delta angle: (( 0) * PI / 180.0)
			(-6 * PI / 180),//Delta angle: ((10) * PI / 180.0)
			(-6 * PI / 180),//Delta angle: ((20) * PI / 180.0)
			(-6 * PI / 180),//Delta angle: ((30) * PI / 180.0)
			(-6 * PI / 180)//Delta angle: ((40) * PI / 180.0)
		 },
	},
	#endif
	//APA_ENUM_TYPE APASlotPCorMinDetXOfCorOrSideSnsDtOnCarBodyIfIngoreDisDtOnCarHead[4];
	{200, 350,200,200}, //APA_ENUM_TYPE APASlotPCorMinCntOfCorOrSideSnsDtOnCarBodyIfIngoreDisDtOnCarHead[4];
	{3, 3, 3, 3},
	//APA_DISTANCE_TYPE APASlotPCorMaxDisOfCorOrSideSnsDtIfCarInOutSideSlot[4];
	{400, 600, 800, 800},
	3400,//APA_DISTANCE_TYPE APASlotPCorMaxSlotLenToAddCompForObj2IfObj1CorObj2NotCor;
	//APASlotPCorObj2CompDisIfObjIsCorObj2IsNotCor[9];
	{

				//if(Obj2Type <= APA_SLOT_OBJ_TYPE_SQUARE_OBJ_WITH_FALLING_SHAPE){
		0,		//	Obj2TypeGroupIndex = 0; small square object, width < 1m, 
				//} else if(Obj2Type <= APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_BIG_RISING_AND_FALLING_SHAPE){
		150,		//	Obj2TypeGroupIndex = 1; small round object, width < 1m.
				//} else if(Obj2Type <= APA_SLOT_OBJ_TYPE_PER_CAR_WITH_BIG_FLAT_SMALL_WIDTH){ // 10
		0,		//	Obj2TypeGroupIndex = 2; small per vehicle, width < 1.8m,
				//} else if(Obj2Type <= APA_SLOT_OBJ_TYPE_PER_CAR_WITH_NORMAL_FLAT_NORMAL_WIDTH){//12
		200,	//	Obj2TypeGroupIndex = 3; normal per vehicle with big or normal rising shape. 1.8 < width < 2.3m.
				//} else if(Obj2Type <= APA_SLOT_OBJ_TYPE_PER_CAR_WITH_BIG_FLAT_NORMAL_WIDTH){ // 13
		150,		//	Obj2TypeGroupIndex = 4; normal per vehicle with big flat bumper, 1.8 < width < 2.3m.
				//} else if(Obj2Type <= APA_SLOT_OBJ_TYPE_PER_CAR_WITH_SMALL_FLAT_BIG_WIDTH){ // 14.
		350,	//	Obj2TypeGroupIndex = 5; big per vehicle with big rising shape, big round bumper, width > 2.3m
				//} else if(Obj2Type <= APA_SLOT_OBJ_TYPE_PER_CAR_WITH_NORMAL_FLAT_BIG_WIDTH){// 15
		300,	//	Obj2TypeGroupIndex = 6; big per vehicle with normal rising shape. normal round bumper, width > 2.3m
				//} else if(Obj2Type <= APA_SLOT_OBJ_TYPE_PER_CAR_WITH_BIG_FLAT_BIG_WIDTH){ // 16
		100,	//	Obj2TypeGroupIndex = 7; big per vehicle with big flat bumper, width > 2.3m
				//} else {
		100		//	Obj2TypeGroupIndex = 8; parallel vehicle width > 3.2m.
				//}
	
	},
	//APA_DISTANCE_TYPE APASlotPCorMinDelPosXToCorObjByAngAndDis[4];
	//RR   RL     RRS   RLS
	{-200, -250, -200, -250},
	//APA_DISTANCE_TYPE APASlotPCorMinDelYToCompDisByConstantValue[2];
	{400, -400},
	//APA_ANGLE_TYPE APASlotPCorMaxCarAngToAcceptRRSnsDis[2]
	#ifdef APA_WITH_NORMAL_CORNER_UPA_SNS_POSITION
	{(70 * PI / 180),(-10 * PI / 180)}, 
	#else
	{(0 * PI / 180),(-10 * PI / 180)}, 
	#endif

	// for perpendicular parking slot correction filter 2014 08 21
	500, // 400, //700, //APA_DISTANCE_TYPE APASlotCorSDGPointCanBeRemovedContiguousPointMinDisP;
	200, //APA_DISTANCE_TYPE APASlotCorSDGPointCanBeRemovedContiguousPointMinDisP2;
	100, // 50, // 5cm, 25, //APA_DISTANCE_TYPE APASlotCorSDGSamplePointUpdateSmallDeltaLen;
	200, // APA_DISTANCE_TYPE APASlotCorSDGSamplePointUpdateSmallDeltaLen2;
	3, // 2,//1, //APA_SLOT_PT_SLOPE_TYPE APASlotCorSDGSamplePointCanBeRemovedMaxObjPtDeltaSlope;
	250, // 350, //APA_DISTANCE_TYPE APASlotCorSDGSamplePointNoisePtCanBeRemovedRegardAsNoiseMinObjWidth;
	500, // 1000, //APA_DISTANCE_TYPE APASlotCorSDGSamplePointNoisePtStartCheckBkObjWidth;
	500, //APA_DISTANCE_TYPE APASlotCorSDGSamplePointNoisePtCanBeRemovedCheckMinNoObjWidth;
	30, //APA_DISTANCE_TYPE APASlotCorSDGSamplePointNoisePtCanBeRemovedHeadOrTailMaxDeltaObjDis;
	10, // 10 = 20deg, 17 = 30deg, //APA_SLOT_PT_SLOPE_TYPE APASlotCorSDGSamplePointNoisePtCanBeRemovedHeadOrTailMaxSlope;
	- 30, // -30 = -45deg, -70 = -60deg, //APA_SLOT_PT_SLOPE_TYPE APASlotCorSDGSamplePointNoisePtCanBeRemovedHeadOrTailMinSlope;
	30, //APA_SLOT_PT_SLOPE_TYPE APASlotCorSDGSamplePointAllowedMaxDeltaSlope;
	500, //APA_DISTANCE_TYPE APASlotCorSDGSamplePointNoisePtCanBeRemovedCheckStartHeadWidth;
	400, //APA_DISTANCE_TYPE APASlotCorSDGSamplePointNoisePtCanBeRemovedCheckNoiseWidth;
	300, //APA_DISTANCE_TYPE APASlotCorSDGSamplePointNoisePtCanBeRemovedMaxDis;
	250, //APA_DISTANCE_TYPE APASlotCorSDGSamplePointNoisePtCanBeRemovedSameObjTol;
	500, //APA_DISTANCE_TYPE APASlotCorSDGSamplePointNoisePtCanBeRemovedCheckNoiseToObjWidth;
	2, //APA_ENUM_TYPE APASlotCorSDGSamplePointNoisePtCanBeRemovedMinSameObjPtNum;
	500, //APA_DISTANCE_TYPE APASlotCorSDGSamplePointNoisePtCanBeRemovedMinObjWidth;
	25, //APA_ENUM_TYPE APASlotCorSDGSamplePointNoisePtCanBeRemovedMaxNoiseWidthPercentage;
	300, //APA_DISTANCE_TYPE APASlotCorSDGSamplePointNoisePtRegardedAsSameObjMaxDeltaObjDis;
	500, //APA_DISTANCE_TYPE APASlotCorSDGSamplePointNoisePtRegardedAsSameObjMinObjWidth;
	1000, //APA_DISTANCE_TYPE APASlotCorSDGSamplePointUpdateLongDeltaLen;
	8000, //APA_DISTANCE_TYPE APASlotCorSDGSamplePointCanBeRemovedMaxObjDis;
	6, // APA_ENUM_TYPE APASlotCorSDGSamplePointNoisePtCanBeRemovedMinObjPtOutOfTolNum;
	3, // APA_ENUM_TYPE APASlotCorSDGSamplePointNoisePtCanBeRemovedMinNoObjPtWitinNoiseNum;
	4, // APA_ENUM_TYPE APASlotCorSDGSamplePointNoisePtCanBeRemovedMinNoObjPtTotalNum;
	
	// Parallel slot:
	1000, // 1m, APA_DISTANCE_TYPE APASlotCarMayHitObj2CheckDeltaDisYMax; // default to: 100cm.	
	-1500, // -1.5m, APA_DISTANCE_TYPE APASlotCarMayHitObj2CheckDeltaDisYMin; // default to: -150cm.	
	800, // 80cm, APA_DISTANCE_TYPE APASlotCorObj2YStCorMinDeltaCarPosToEndPosX; // default to: 80cm.
	600, // 60cm, APA_DISTANCE_TYPE APASlotCorObj2YStCorMaxCornerSnsDtDis1; // default to: 60cm.
	900, // 60cm, APA_DISTANCE_TYPE APASlotCorObj2YStCorMaxCornerSnsDtDis2; // default to: 60cm.
	800, //1.2m, APA_DISTANCE_TYPE APASlotCorObj2YStCorMaxMidSnsDtDis1; // default to: 120cm.
	1000, //1.2m, APA_DISTANCE_TYPE APASlotCorObj2YStCorMaxMidSnsDtDis2; // default to: 120cm.
	//APA_RATIO_TYPE APASlotCorObj2YCompensateDisByCarAng[3]; // 0: FR, 1: FRM, 2: FLM
	{
		// FR,     FRM,    FLM,
		0,         0,      0.53 // 0.53 will compensate +20cm when sns dt dis = 80cm, car angle = 28deg.
	},
	//APA_RATIO_TYPE APASlotCorObj1YCompensateDisByCarAng[3]; // 0: RL, 1: RLM, 2: RRM
	{
		// RL,     RLM,    RRM,
		//0,         0,      0.53 // 0.53 will compensate +20cm when sns dt dis = 80cm, car angle = 28deg.
		0.53,         0.53,      1.0, // 0.53 // 0.53 will compensate +20cm when sns dt dis = 80cm, car angle = 28deg.
	},
	
	500, // 50cm, // APA_DISTANCE_TYPE APASlotCorObj1YStCorMinDeltaCarPosToEndPosX; // default to: 60cm.
	
	1000, // 1.8m, APA_DISTANCE_TYPE APASlotCorObj1YStCorMaxCornerSnsDtDis; // default to: 180cm.
	700, // 1.8m, APA_DISTANCE_TYPE APASlotCorObj1YStCorMaxMidSnsDtDis; // default to: 180cm.
	1500, // 1.5m,	APA_DISTANCE_TYPE APASlotCorObj1YStCorMaxMidSnsDtDis2; // default to: 150cm.
	1000, // 1.8m, APA_DISTANCE_TYPE APASlotCorObj1YStCorMaxMidSnsDtDis3; // default to: 150cm.
	700, // 70cm,	APA_DISTANCE_TYPE APASlotCorObj1YRecalObj1YMaxDeltaCarCornerYandObj1Y; // default to: 70cm.
	-50, // -5cm, APA_DISTANCE_TYPE APASlotCorObj2YResetObj2YEndPosToCurCarPosDeltaX; // when no obj dted reset the obj1. -5cm
	400, // 40cm, APA_DISTANCE_CAL_FLOAT_TYPE APASlotCorObj2YResetObj2YCarFBumperOverObj2YDis; // when no obj dted reset the obj1. 35cm.
	700, // 70cm, APA_DISTANCE_TYPE APASlotCorObj2YResetObj2YRegardAsFSnsDtObjDis; // when no obj dted reset the obj1. 70cm.
	-50, // -5cm, APA_DISTANCE_TYPE APASlotCorObj1YResetObj1YEndPosToCurCarPosDeltaX; // when no obj dted reset the obj1.
	350, // 35cm, APA_DISTANCE_TYPE APASlotCorObj1YResetObj1YCarRBumperOverObj1YDis; // when no obj dted reset the obj1. 35cm.
	2500, // 250cm, APA_DISTANCE_TYPE APASlotCorObj1YResetObj1YRegardAsRSnsDtObjDis; // when no obj dted reset the obj1. 70cm.
	1500 / 35, // 1000ms /35ms,  35ms is the sns dt loop time, // APA_MS_TIME_TYPE APASlotCorObjConfirmedAsNotDtdDelayTimeWhenVehicleIsStatic; // 1s.
	3000 / 35, // 3000ms /35ms,  35ms is the sns dt loop time, // APA_MS_TIME_TYPE APASlotCorObjConfirmedAsNotDtdTimeWhenVehicleIsStatic; // 3s.
	
	350, // 30cm, APA_DISTANCE_TYPE APASlotCorObjConfirmedAsNotDtdDeltaCarToEndPosXDevidedDis; // 30cm.	
	(460 - 260), // 46cm - 26cm (Safety dis at front), APA_DISTANCE_TYPE APASlotCorObjConfirmedAsNotDtdMaxCarToObjDisWithVehIsMovingCor1; // 46cm. when car has a small offset with end pos x.
	//(650 - 260), // 80cm - 26cm (Safety dis at front), APA_DISTANCE_TYPE APASlotCorObjConfirmedAsNotDtdMinCarToObjDisWithVehIsMovingCor1; // 80cm.
	(400 - 260), // 43cm - 26cm (Safety dis at front), APA_DISTANCE_TYPE APASlotCorObjConfirmedAsNotDtdMaxCarToObjDisWithVehIsMovingCor2; // 43cm.
	//(550 - 260), // 46cm - 26cm (Safety dis at front), APA_DISTANCE_TYPE APASlotCorObjConfirmedAsNotDtdMinCarToObjDisWithVehIsMovingCor2; // 46cm.
	450, // 45cm, // APA_DISTANCE_TYPE APASlotCorObjConfirmedAsNotDtdMinCarDrvDisWithOneGearChanged1; // 35cm.
	200, // 20cm, // APA_DISTANCE_TYPE APASlotCorObjConfirmedAsNotDtdMinCarDrvDisWithOneGearChanged2; // 5cm.

	800 / 35, // 800ms /35ms,  35ms is the sns dt loop time, //APA_MS_TIME_TYPE APASlotCorObjConfirmedAsNotDtdTimeMovingAwayFromObj; // 2s.
	0 / 35, // 0ms /35ms,  35ms is the sns dt loop time, //APA_MS_TIME_TYPE APASlotCorObjConfirmedAsNotDtdTimeMovingCloseToObj; // 0s.

	// Perpendicular slot:
	600 / 40, // APA_MS_TIME_TYPE APASlotCorPSlotCorrectCycleTime; 40ms is the sensor one detection loop cycle.
	50, // 150, // 250, def: 50cm. APA_DISTANCE_TYPE APASlotCorPSlotCorrectDeltaXDis;

	0.6 * PI / 180.0, // APA_ANGLE_TYPE APASlotCorPCarEndPosAngCompensateAngPerFrwAndBk; // default to: 1deg

#ifdef APA_WITH_NORMAL_CORNER_UPA_SNS_POSITION
	2500, // 2.5m, APA_DISTANCE_TYPE APASlotCorPObjYCorSearchBkDeltaXDis; // default to: 50cm.
	500, // 50cm changed by kjy 2014 05 17, 300, // 30cm, APA_DISTANCE_TYPE APASlotCorPEndPosYCalObj1YSearchBkStartDeltaXDis; // default to: 30cm.
	1800, // 2.5m, 2m. APA_DISTANCE_TYPE APASlotCorPEndPosYCalObj1YSearchBkEndDeltaXDis; // default to: 200cm.
	200, // 20cm, APA_DISTANCE_TYPE APASlotCorPEndPosYCalObj2YOptimalPtMinDeltaX; // 20cm.
	250, // 25cm, APA_DISTANCE_TYPE APASlotCorPEndPosYCalObj2YOptimalPtDeltaYWithOriginalObj2Y; // 25cm.
	200, // 10cm, APA_DISTANCE_TYPE APASlotCorPEndPosYCalObj2YOptimalPtDeltaY; // 10cm.
	4, // APA_ENUM_TYPE APASlotCorPEndPosYCalObj2YOptimalPtMinPtNum; // 3.
	500, // 0.5m, APA_DISTANCE_TYPE APASlotCorPEndPosYCalObj2YSearchBkStartDeltaXDis; // default to: 150cm.
	1800, // 2.7m, 2.2m, APA_DISTANCE_TYPE APASlotCorPEndPosYCalObj2YSearchBkEndDeltaXDis; // default to: 220cm.
#else
	1300, // 50cm, APA_DISTANCE_TYPE APASlotCorPObjYCorSearchBkDeltaXDis; // default to: 50cm.
	500, // 50cm changed by kjy 2014 05 17, 300, // 30cm, APA_DISTANCE_TYPE APASlotCorPEndPosYCalObj1YSearchBkStartDeltaXDis; // default to: 30cm.
	2000, // 2m. APA_DISTANCE_TYPE APASlotCorPEndPosYCalObj1YSearchBkEndDeltaXDis; // default to: 200cm.
	200, // 20cm, APA_DISTANCE_TYPE APASlotCorPEndPosYCalObj2YOptimalPtMinDeltaX; // 20cm.
	250, // 25cm, APA_DISTANCE_TYPE APASlotCorPEndPosYCalObj2YOptimalPtDeltaYWithOriginalObj2Y; // 25cm.
	200, // 10cm, APA_DISTANCE_TYPE APASlotCorPEndPosYCalObj2YOptimalPtDeltaY; // 10cm.
	4, // APA_ENUM_TYPE APASlotCorPEndPosYCalObj2YOptimalPtMinPtNum; // 3.
	500, // 0.5m, APA_DISTANCE_TYPE APASlotCorPEndPosYCalObj2YSearchBkStartDeltaXDis; // default to: 150cm.
	2200, // 2.2m, APA_DISTANCE_TYPE APASlotCorPEndPosYCalObj2YSearchBkEndDeltaXDis; // default to: 220cm.
#endif
	


	// Car RRC may hit obj2, correct obj2.x, obj2.y parameter:

#ifdef APA_WITH_NORMAL_CORNER_UPA_SNS_POSITION
	30 * PI / 180,//APA_ANGLE_TYPE APASlotCorPCarMayHitObj2CorRRCSnsMaxCompensateAng;
	500, // APA_DISTANCE_TYPE APASlotCorPCarMayHitObj2CorRRCSnsCalObj2YCompensateDis; // default to: 50cm.
	700, // 40cm, APA_DISTANCE_TYPE APASlotCorPCarMayHitObj2CorRRSSnsCalObj2YCompensateDis; // default to: 40cm.
	0,// 600, // 60cm, APA_DISTANCE_TYPE APASlotCorPCarMayHitObj2CorRRCSnsStartCalDis; // default to: 60cm.
	600, // 60cm, APA_DISTANCE_TYPE APASlotCorPCarMayHitObj2CorRRSSnsStartCalDis; // default to: 60cm.

	// Obj2.y correct use SDG buf parameter:

	800, // 80cm, APA_DISTANCE_TYPE APASlotCorPObj2YCorAllowObj2YAndCarPosYDeltaDis; // default to: 80cm.
	150, // 15cm, APA_DISTANCE_TYPE APASlotCorPObj2YCorDuringStep2AllowObj2YDeltaDis; // default to: 15cm.

	15.0 * PI / 180.0, // 15deg. APA_ANGLE_TYPE APASlotCorPObj2YCorRegardedAsInvalidObj2YMaxDeltaCarAng1; // 15deg.
	35.0 * PI / 180.0, // 35deg. APA_ANGLE_TYPE APASlotCorPObj2YCorRegardedAsInvalidObj2YMaxDeltaCarAng2; // 35deg.
	450, // 45cm, // APA_DISTANCE_TYPE APASlotCorPObj2YCorRegardedAsInvalidObj2YMaxSnsDtObjDis; // 45cm.
	150, // 15cm, APA_DISTANCE_TYPE APASlotCorPObj2YCorRegardedAsInvalidObj2YMaxDeltaObj2YDis; // 15cm.
	
	900, // 90cm, APA_DISTANCE_TYPE APASlotCorPObj2YCorStartUseSDGBufCorCarPosDeltaObj2XDis; // default to: 70cm.
	700, // 70cm, APA_DISTANCE_TYPE APASlotCorPObj2YCorStartUseSDGBufCorCarPosDeltaXDis; // default to: 70cm.
	50.0 * PI / 180.0, // APA_ANGLE_TYPE APASlotCorPObj2YCorMaxDeltaCarAng; // default: 50deg.
	45.0 * PI / 180.0, // APA_ANGLE_TYPE APASlotCorPObj2YCorRRSSnsCalCompensateMaxCarAng; // default to: 45deg
	0, // 400, // 60cm, APA_DISTANCE_TYPE APASlotCorPObj2YCorRRSSnsCalObj2YCompensateDis; // default to: 60cm.
	800, // 80cm, APA_DISTANCE_TYPE APASlotCorPObj2YCorRRSSnsCompMinXYWidth; // default to: 80cm.
#else	
	30 * PI / 180,//APA_ANGLE_TYPE APASlotCorPCarMayHitObj2CorRRCSnsMaxCompensateAng;
	500, // APA_DISTANCE_TYPE APASlotCorPCarMayHitObj2CorRRCSnsCalObj2YCompensateDis; // default to: 50cm.
	700, // 40cm, APA_DISTANCE_TYPE APASlotCorPCarMayHitObj2CorRRSSnsCalObj2YCompensateDis; // default to: 40cm.
	400, // 60cm, APA_DISTANCE_TYPE APASlotCorPCarMayHitObj2CorRRCSnsStartCalDis; // default to: 60cm.
	400, // 60cm, APA_DISTANCE_TYPE APASlotCorPCarMayHitObj2CorRRSSnsStartCalDis; // default to: 60cm.

	// Obj2.y correct use SDG buf parameter:

	800, // 80cm, APA_DISTANCE_TYPE APASlotCorPObj2YCorAllowObj2YAndCarPosYDeltaDis; // default to: 80cm.
	150, // 15cm, APA_DISTANCE_TYPE APASlotCorPObj2YCorDuringStep2AllowObj2YDeltaDis; // default to: 15cm.

	15.0 * PI / 180.0, // 15deg. APA_ANGLE_TYPE APASlotCorPObj2YCorRegardedAsInvalidObj2YMaxDeltaCarAng1; // 15deg.
	35.0 * PI / 180.0, // 35deg. APA_ANGLE_TYPE APASlotCorPObj2YCorRegardedAsInvalidObj2YMaxDeltaCarAng2; // 35deg.
	450, // 45cm, // APA_DISTANCE_TYPE APASlotCorPObj2YCorRegardedAsInvalidObj2YMaxSnsDtObjDis; // 45cm.
	150, // 15cm, APA_DISTANCE_TYPE APASlotCorPObj2YCorRegardedAsInvalidObj2YMaxDeltaObj2YDis; // 15cm.
	
	
	900, // 90cm, APA_DISTANCE_TYPE APASlotCorPObj2YCorStartUseSDGBufCorCarPosDeltaObj2XDis; // default to: 70cm.
	700, // 70cm, APA_DISTANCE_TYPE APASlotCorPObj2YCorStartUseSDGBufCorCarPosDeltaXDis; // default to: 70cm.
	50.0 * PI / 180.0, // APA_ANGLE_TYPE APASlotCorPObj2YCorMaxDeltaCarAng; // default: 50deg.
	45.0 * PI / 180.0, // APA_ANGLE_TYPE APASlotCorPObj2YCorRRSSnsCalCompensateMaxCarAng; // default to: 45deg
	0, // changed to 0: 2014 04 22,  400, // 60cm, APA_DISTANCE_TYPE APASlotCorPObj2YCorRRSSnsCalObj2YCompensateDis; // default to: 60cm.
	800, // 80cm, APA_DISTANCE_TYPE APASlotCorPObj2YCorRRSSnsCompMinXYWidth; // default to: 80cm.
#endif

#ifdef APA_SYSTEM_WITH_10_CH

	0, // 600, //for 10 CH: 500, for 12CH: 350, // 40cm, APA_DISTANCE_TYPE APASlotCorPObj2YCorRRSSnsCompDisWithDelatCarAng1; // default to: 40cm.
	#ifdef APA_WITH_NORMAL_CORNER_UPA_SNS_POSITION
	0, //800, //for 10 CH: 500, for 12CH: 300, // 30cm. APA_DISTANCE_TYPE APASlotCorPObj2YCorRRSSnsCompDisWithDelatCarAng2; // default to: 30cm.
	#else
	0, // 450, //for 10 CH: 500, for 12CH: 300, // 30cm. APA_DISTANCE_TYPE APASlotCorPObj2YCorRRSSnsCompDisWithDelatCarAng2; // default to: 30cm.
	#endif
	0, // 700, //for 10 CH: 700, for 12CH: 600, // 60cm, APA_DISTANCE_TYPE APASlotCorPObj2YCorAllowObjMaxYAndMinYDeltaDis; // default to: 60cm.
#else
	0, //350, // 40cm, APA_DISTANCE_TYPE APASlotCorPObj2YCorRRSSnsCompDisWithDelatCarAng1; // default to: 40cm.
	0, //300, // 30cm. APA_DISTANCE_TYPE APASlotCorPObj2YCorRRSSnsCompDisWithDelatCarAng2; // default to: 30cm.
	600, // 60cm, APA_DISTANCE_TYPE APASlotCorPObj2YCorAllowObjMaxYAndMinYDeltaDis; // default to: 60cm.

#endif
	
#ifdef APA_SYSTEM_WITH_10_CH
	#ifdef APA_WITH_NORMAL_CORNER_UPA_SNS_POSITION

	1600, // 2.5m, APA_DISTANCE_TYPE APASlotCorPObj2YCorObj2ExistAllowMaxSnsDtDis; // default to: 250cm.
	3800 - 500, // APA_DISTANCE_TYPE APASlotCorPRecalObj2YCarPosXMinDeltaDisToEndPosX; // default to: 250cm.
	
	#else
	
	2500, // 2.5m, APA_DISTANCE_TYPE APASlotCorPObj2YCorObj2ExistAllowMaxSnsDtDis; // default to: 250cm.
	2500, // APA_DISTANCE_TYPE APASlotCorPRecalObj2YCarPosXMinDeltaDisToEndPosX; // default to: 250cm.

	#endif
#else	
	2500, // 2.5m, APA_DISTANCE_TYPE APASlotCorPObj2YCorObj2ExistAllowMaxSnsDtDis; // default to: 250cm.
	2500, // APA_DISTANCE_TYPE APASlotCorPRecalObj2YCarPosXMinDeltaDisToEndPosX; // default to: 250cm.
#endif

	5.0 * PI / 180.0, // 5deg, // APA_ANGLE_TYPE APASlotCorPRecalObj2YMinCarAng;
	115.0 * PI / 180.0, // 115deg, // APA_ANGLE_TYPE APASlotCorPRecalObj2YMaxCarAng;

	// Obj exist check Parameter:
	2000, // 2m, APA_DISTANCE_TYPE APASlotCorPObjExistMaxSnsDtDis; // default to: 150cm.
	1600, // 1.6m, def:1.2m, APA_DISTANCE_TYPE APASlotCorPObjExistMaxSnsDtDisEndPosCloseToObj1or2; // default to: 80cm.
	1600, // 1.5m, APA_DISTANCE_TYPE APASlotCorPRecalObjYExistMaxSnsDtDis;
	1200, // 1.2m, APA_DISTANCE_TYPE APASlotCorPRecalObjYMaxSnsDtDisEndPosCloseToObj1or2;
	
	// Car RLC may hit obj1, correct obj1.x, obj1.y parameter:
	150, // 15cm, APA_DISTANCE_TYPE APASlotCorPCarMayHitObj1CorUseRLSnsAsHighPriorityDeltaDis; // 15cm.
	100, // 15cm, APA_DISTANCE_TYPE APASlotCorPCarMayHitObj1CorUseMidSnsAsHighPriorityDeltaDis; // 15cm.
	
	100, // 10cm, big slot. APA_DISTANCE_TYPE APASlotCorPCarMayHitObj1CorRLSSnsCalObj1YCompensateDis1; // 10cm.
	200, // 20cm. small slot. APA_DISTANCE_TYPE APASlotCorPCarMayHitObj1CorRLSSnsCalObj1YCompensateDis2; // 15cm.
#ifdef APA_WITH_NORMAL_CORNER_UPA_SNS_POSITION
	0, // 0cm, APA_DISTANCE_TYPE APASlotCorPCarMayHitObj1CorRLCSnsCalObj1YCompensateDis0; // 0cm, big slot inside the slot.
	100, // inside slot. APA_DISTANCE_TYPE APASlotCorPCarMayHitObj1CorRLCSnsCalObj1YCompensateDis1; // 10cm.
	150, // 15cm, APA_DISTANCE_TYPE APASlotCorPCarMayHitObj1CorRLCSnsCalObj1YCompensateDis2; // 15cm.
#else
	100, // 0cm, APA_DISTANCE_TYPE APASlotCorPCarMayHitObj1CorRLCSnsCalObj1YCompensateDis0; // 0cm, big slot inside the slot.
	150, // inside slot. APA_DISTANCE_TYPE APASlotCorPCarMayHitObj1CorRLCSnsCalObj1YCompensateDis1; // 10cm. big slot outside the slot.
	200, // outside slot. 20cm, APA_DISTANCE_TYPE APASlotCorPCarMayHitObj1CorRLCSnsCalObj1YCompensateDis2; // 15cm. small slot inside or out side the slot.
#endif

	150, // 15cm, APA_DISTANCE_TYPE APASlotCorPCarMayHitObj1CorMidSnsCalObj1YCompensateDis; // 20cm.
	
	700, // APA_DISTANCE_TYPE APASlotCorPCarMayHitObj1CorSnsStartCalDis; // default to: 60cm.
	5.0 * PI / 180.0, // 5deg, // APA_ANGLE_TYPE APASlotCorPRecalObj1YMinCarAng;
	115.0 * PI / 180.0, // 115deg, // APA_ANGLE_TYPE APASlotCorPRecalObj1YMaxCarAng;


#ifdef APA_WITH_NORMAL_CORNER_UPA_SNS_POSITION
	#ifdef APA_SYSTEM_WITH_10_CH
	3800 - 500, // APA_DISTANCE_TYPE APASlotCorPRecalObj1YCarPosXMinDeltaDisToEndPosX;
	75.0 * PI / 180.0, //  APA_ANGLE_TYPE APASlotCorPGetObj1MaxYMinCarAng;
	145.0 * PI / 180.0, // APA_ANGLE_TYPE APASlotCorPGetObj1MaxYMaxCarAng;
	70.0 * PI / 180.0, // APA_ANGLE_TYPE APASlotCorPGetObj2MinYMinCarAng;
	145.0 * PI / 180.0, // APA_ANGLE_TYPE APASlotCorPGetObj2MinYMaxCarAng;
	#else
	2500, // 2.5m, APA_DISTANCE_TYPE APASlotCorPRecalObj1YCarPosXMinDeltaDisToEndPosX;	
	15.0 * PI / 180.0, //  APA_ANGLE_TYPE APASlotCorPGetObj1MaxYMinCarAng;
	145.0 * PI / 180.0, // APA_ANGLE_TYPE APASlotCorPGetObj1MaxYMaxCarAng;
	65.0 * PI / 180.0, // APA_ANGLE_TYPE APASlotCorPGetObj2MinYMinCarAng;
	145.0 * PI / 180.0, // APA_ANGLE_TYPE APASlotCorPGetObj2MinYMaxCarAng;
	#endif
#else	
	2500, // 2.5m, APA_DISTANCE_TYPE APASlotCorPRecalObj1YCarPosXMinDeltaDisToEndPosX;	
	15.0 * PI / 180.0, //  APA_ANGLE_TYPE APASlotCorPGetObj1MaxYMinCarAng;
	145.0 * PI / 180.0, // APA_ANGLE_TYPE APASlotCorPGetObj1MaxYMaxCarAng;
	65.0 * PI / 180.0, // APA_ANGLE_TYPE APASlotCorPGetObj2MinYMinCarAng;
	145.0 * PI / 180.0, // APA_ANGLE_TYPE APASlotCorPGetObj2MinYMaxCarAng;
#endif

	// Slot border line delta angle:
	8.0 * PI / 180.0, //APA_ANGLE_TYPE APASlotCorPRegardSlotBorderLineDeltaAngIsBigMinDeltaAng;

	// Slot Border line fit parameter:
	4, // 3step,	APA_ENUM_TYPE APASlotCorPSlotBorderLineFitMaxStepSequenceNum; // 3
	25.0 * PI / 180.0, // 25deg, APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitStartCheckFitSeqenceMaxDetalAng; //25.0 deg
	800, // 80cm, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsOneStepIntoSlotMaxDeltaCarPosX; //0.8m
	2500, // APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsOneStepOutSlotMinDeltaCarPosX; //2.50m
	1800, // 1.8m, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitConvexShapeCheckFirstStepIntoSlotMaxDeltaCarPosX; //1.8m
	-300, // -30cm, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitConvexShapeCheckFirstStepOutSlotMinCarPosX; //-30cm
	1200, // 1.2m, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitConvexShapeCheckSecondStepIntoSlotMaxDeltaCarPosX; //1.2m

	#ifdef APA_SYSTEM_WITH_10_CH

	2000,//2500, // 2.5m, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitMaxSnsDtDis;
	#else
	2500, // 2.5m, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitMaxSnsDtDis;
	#endif
	
	300, // 30cm, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardedRCSnsDtDisAsInvalidMaxDeltaObjDis; // 0.30cm
	150, // 15cm, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardedRSSnsDtDisAsInvalidMaxDeltaObjDis; // 0.15cm
	500, // 50cm, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitDeltaCarPosToEndPos; // 50cm.
	2800, // def 3.2m, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitMaxDeltaCarPosX;
	800, // 80cm, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitUseObjPtWrIndexMaxDeltaCarPosX1;
	3500, // 350cm, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitUseObjPtWrIndexMaxDeltaCarPosX2;
	2300, // 2.3m, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitUseObjPtWrIndexMinObjXWidthHead; // 2300cm,
	1800, // 1.8m, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitNotUseObjPtWrIndexMinObjXWidthTail; // 1800cm,
	5.0 * PI / 180.0, // 5deg. APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitNotUseObjPtWrIndexMaxDeltaCarAng; // 5Deg,

	2400, // 2.8m, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitDeltaObjXDevide1;
	-400, // def: 300, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitStartDeltaObjX;
	-150, // -15cm, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitAllowMinDeltaObjXBtTwoObjPt;

	// APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsValidObjMinWidth[4];
	{
		// RRS, RR,    RLS,    RL
		1200,   1800,  1200,   1800
	},
	
	// APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsValidObjMaxWidth[4];
	{
		// RRS, RR,    RLS,    RL
		2800,   3500,  2800,   3500
	},
	50, // 5cm, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsStraightLineDeltaYTol1;
	80, // 2014 08 23 kjy changed from 10cm to 8cm. 10cm, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsStraightLineDeltaYTol2;
	120, // 2014 08 23 kjy changed from 15cm to 12cm. 15cm, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsStraightLineDeltaYTol3;
	200, // 20cm, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsStraightLineConcaveDeltaYTol1; // 20cm,
	300, // 30cm, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsStraightLineConcaveDeltaYTol2; // 30cm,
	400, // 40cm, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsStraightLineConvexDeltaYTol1; // 40cm,
	700, // 70cm, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsStraightLineConvexDeltaYTol2; // 70cm,
	10, // 10: atan(1/10) = 5.7deg.APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsWihinTolBigLineLenRatio; // 10: atan(1/10) = 5.7deg.
	5.0 * PI / 180.0, // 5deg. APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitUseBigTolMaxDeltaLineAndEndPosAng; // 5deg.

	1400, // 2014 08 25, kjy changed from 120cm to 140cm. 120cm, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitAllowMaxConvexWidthAtMidOfLine; // 80cm, 80cm is too small, for ISO Pole 75mm, the width will be 85cm,

	200, // 20cm, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitConsiderConvexPtMinDeltaYTol1; // 20cm.
	350, // 35cm, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitConsiderConvexPtMinDeltaYTol2; // 35cm.
	350, // 35cm, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitConsiderConvexPtAllowOffsetMaxObjPtYToCarDis; // 35cm.
	800, // 80cm, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitConsiderConvexPtAllowOffsetMaxDis; // 80cm.
	
	25.0 * PI / 180.0, // 25deg. APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitConsiderConvexPtMaxDeltaCarAng; // 25deg.
	0.6, // APA_CAL_FLOAT_TYPE APASlotCorPSlotBorderLineFitConsiderConvexPtLineOffsetFactor; // // pt to line dis * factor. def: 0.6
	
	// APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsConvexOrConcaveLineMinDeltaY[4];
	{
		// RRS, RR,    RLS,    RL
		250,   200,  250,   200
	},
	// APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsConvexOrConcaveLineMinLineLen[4];
	{
		// RRS, RR,    RLS,    RL
		//400,   600,  400,   600
		// def: 600,   800,  600,   800
		//1000,   1200,  1000,   1200 // for d2sc
		3000,   3200,  3000,   3200 // kjy changed 2014 05 30. for d2jo.
	},

	//APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsCarValidObjBdLineMinLen[4]; // 3.5m.
	{
		// RRS, RR,    RLS,    RL
		3500,   3800,  3500,   3800
	},
	
	// APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsValidOKLineMinObjWidth[4];
	{
		// RRS, RR,    RLS,    RL
		1800,   2200,  1800,   2200
	},
	// APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsValidOKLineMinLineLenAtHead[4];
	{
		// RRS, RR,    RLS,    RL
		1000,   1400,  1000,   1400
	},
	//1400, // 1.2m, 80cm, def: 1.1m APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitMinLineLen1[3][4]; // car angle and bdline angle is less than 15deg.
	{
		// RRS, RR, RLS, RL
		// LineLenCheckMode:
		// 0 - line with convex at head. should < 1.7m,
		//{1500, 1700, 1500, 1700},
		{1600, 1600, 1600, 1600},//kjy changed, 2014 05 14, {1700, 1700, 1700, 1700},//{1700, 1900, 1700, 1900}, // for d2sc,
		// 1 - line with convex at mid.
		{2300, 2500, 2300, 2500},
		// 2 - line with covex at tail.
		{1800, 2000, 1800, 2000}
	},
	//1200, // 0.8m, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitMinLineLen2[3][4]; // car angle and bdline angle is great than 15deg.
	{
		// RRS, RR, RLS, RL
		// LineLenCheckMode:
		// 0 - line with convex at head.
		//{1200, 1500, 1200, 1500},
		{1400, 1500, 1400, 1500},//kjy changed, 2014 05 14, //{1600, 1800, 1600, 1800}, // for d2sc,
		// 1 - line with convex at mid.
		{2500, 2800, 2500, 2800},
		// 2 - line with covex at tail.
		{1500, 1800, 1500, 1800}
	},
	3000, // 2000, // kjy changed to 2000, 2014 5 14, 1800, // 1.8m APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitLineWithConvexAtHeadAllowMaxLineLen; // 1.8m.
	
	700, // 70cm. APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsValidLineMinObjPtDeltaXDis;

	8.0 * PI / 180.0, // APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitMinLineLenDevidedDeltaCarAngAndBdLineAng1;
	15.0 * PI / 180.0, // APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitMinLineLenDevidedDeltaCarAngAndBdLineAng2;

	300, // 30cm, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitMaxWithoutDtdObjToCarDrvMaxPosXDis1; // 30cm.
	800, // 80cm, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitMaxWithoutDtdObjToCarDrvMaxPosXDis2; // 80cm. line angle and car angle is less than 15deg.
	1400, // 140cm, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitMaxWithoutDtdObjToCarDrvMaxPosXDis3; // 140cm. line angle and car angle is great than 15deg.
	1000, // 100cm for d2sc, 1.2m, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitStopCheckWithoutDtdObjMinSideObjDis; // 120cm.
	800, // 80cm, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitStopCheckWithoutDtdObjMinCornerObjDis; // 80cm.

	1500, // 150cm, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitStartToCheckLineShapeMinObjXWidth;	
	500, // def: 300, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitDeltaObjXOffset1;
	800, // def: 600, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitDeltaObjXOffset2;
	1200, // def: 1200, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitDeltaObjXOffset3;
	800, // def: 80cm, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitFirstBkStepFitLineMaxObjDis; // 80cm.
	8, // APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitGetRidOffLineEndPtDisCalFactor; // def: 8: for 3m, it will get rid of 37.5cm at head and tail and then fit the line.
	
	2000, // 2m, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsValidBdLineMinLen1; // 200cm with big bd line angle. within min tolerance.
	1000, // 1m, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsValidBdLineMinLen2; // 100cm. general angle should at least big than this value. with big tolerance.

	400, // 40cm, ?? APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitAllowMaxDeltaX;
	100, // 10 cm, ?? APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitAllowMaxDeltaY;
	
	45.0 * PI / 180.0, // APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitMaxDeltaCarAngAndBdLineAng;
	PI, // PI will disable the compensation. 4.0 * PI  /180.0, // APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitCompMinStCarAngAndBdLineAng;

	// APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitMaxBdLineAng[4];
	{
		// RRS,            RR,                RLS,                 RL,
		//45.0 * PI / 180.0, 30.0 * PI / 180.0, 30.0 * PI / 180.0,   20.0 * PI / 180.0
		// Line slope K: = tan(45deg):
		0.577,               0.577,                 0.577,           0.364
	},
	// APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitMinBdLineAng[4];
	{
		// RRS,              RR,                	  RLS,               RL,
		// - 45.0 * PI / 180.0, - 30.0 * PI / 180.0, - 45.0 * PI / 180.0,   - 30.0 * PI / 180.0
		-0.577,               -0.577,                  -0.577,              -0.577
		
	},
	0.268, // 15.0deg->LineK, // APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitCarNeedToReachAlmostEndPosMinBdLineAng;
	
	0.07, // 0.05: for d2sc, // 0.1, // 0.1 def: 0.2 if this value is < 0, the line angle K will be + (- Value). // 5deg/10deg, APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitCompAngPerDeltaRSideSnsAndBdLineAng;
	- 0.15, // def: 0.1, def: 0.2, // 2deg/10deg, APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitCompAngPerDeltaLSideSnsAndBdLineAng;
	0, // 0.3deg / 10deg, APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitCompAngPerDeltaRCornerSnsAndBdLineAng;
	0, //0.3, // 3deg / 10deg, APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitCompAngPerDeltaLCornerSnsAndBdLineAng;

	-0.07, // -0.05, // 0.1 def: 0.2 if this value is < 0, the line angle K will be + (- Value). // 5deg/10deg, APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitCompAngPerDeltaRSideSnsAndBdLineAng2;
	0.05, // def: 0.2, // 2deg/10deg, APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitCompAngPerDeltaLSideSnsAndBdLineAng2;
	0, // 0.3deg / 10deg, APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitCompAngPerDeltaRCornerSnsAndBdLineAng2;
	0, //0.3, // 3deg / 10deg, APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitCompAngPerDeltaLCornerSnsAndBdLineAng2;

		
	0, // 0.05, // 4.5deg / 30deg. // def:0.1: - 3deg / 30deg. APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitCompAngPerBdLineAngLSideSns;
	0, // 0.05, // 4.5deg / 30deg.  - 3deg / 30deg. APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitCompAngPerBdLineAngLCornerSns;
	0, // 140, //def: 287, 573, 40cm / 40deg, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitCompDisPerDeltaSideSnsAndBdLineAng;
	0, // 120, //  15cm for D2SC, // def: 15cm. APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitCompDisRSideSns;
	0, //  // def: . APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitCompDisLSideSns;
	0, //  - 150, // def: 15cm. APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitCompDisRRCornerSns;
	0, // 50,//150, // 150, // def: 15cm. APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitCompDisRLCornerSns;
	1600, // 1.6m APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitMinLineLenDeltaXDisToEndPosX;
	800, // APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitMaxWithoutDtdObjToEndPosDis;
	600, // 60cm, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitMaxAllowNoObjDtDisXInBdLine;
	500, // 50cm. APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitEndPosLineUpdateTolDevidedCarToEndPosDis; // 50cm.
	50, // 5cm APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitEndPosLineUpdateMinCTol1; // 5cm.
	150, // 15cm, APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitEndPosLineUpdateMinCTol2; // 15cm.
	0.5 * PI / 180.0, // 0.3deg. APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitEndPosAngUpdateMinTolAng1; // 0.3 deg.
	1.0 * PI / 180.0, // 1.5deg. APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitEndPosAngUpdateMinTolAng2; // 1.0 deg.
	
	10.0 * PI / 180.0, // 	APA_ANGLE_TYPE APASlotCorPChkEndPosLineMaxDeltaCarAngAndEndPosLineAng;
	400, // 40cm, 	APA_DISTANCE_TYPE APASlotCorPChkEndPosLineMaxCarSideToObjDis;
	120.0 * PI / 180.0, // APA_ANGLE_TYPE APASlotCorPAllowEndPosLineAngResetMaxEndPosCarAng;
	40.0 * PI / 180.0, // APA_ANGLE_TYPE APASlotCorPAllowEndPosLineAngResetMinEndPosCarAng;
	600, // 60cm, APA_DISTANCE_TYPE APASlotPRegardSlotBorderLineExistMaxDeltaObjDis;
	1200, // 120cm, APA_DISTANCE_TYPE APASlotPRegardSlotBorderLineExistMaxDeltaCarPosX;
	7.0 * PI / 180.0, // 7deg. APA_ANGLE_TYPE APASlotPRegardSlotBorderLineExistCheckMinDeltaCarAng; // 7deg,
	400, // 40cm, APA_DISTANCE_TYPE APASlotPRegardSlotBorderLineExistMaxDeltaCarPosXCarAngAchieved; // 40cm,
	500, // 50cm, APA_DISTANCE_TYPE APASlotPRegardRSideSnsAsNoObjDtDeltaDisToEndPosX;
	500, // -50cm, APA_DISTANCE_TYPE APASlotPRegardRCornerSnsAsNoObjDtDeltaDisToEndPosX;

#ifdef APA_WITH_NORMAL_CORNER_UPA_SNS_POSITION

	-1300, // -1.6m, APA_DISTANCE_TYPE APASlotPSDGBufRRCornerSnsDtMinCarPosX;
	-1000, // -1.3m, APA_DISTANCE_TYPE APASlotPSDGBufRLCornerSnsDtMinCarPosX;

#else	
	-1600, // -1.6m, APA_DISTANCE_TYPE APASlotPSDGBufRRCornerSnsDtMinCarPosX;
	-1300, // -1.3m, APA_DISTANCE_TYPE APASlotPSDGBufRLCornerSnsDtMinCarPosX;
#endif

	-1700, // -1.7m, APA_DISTANCE_TYPE APASlotPSDGBufRRSideSnsDtMinCarPosX;
	-1000, // - 1m. APA_DISTANCE_TYPE APASlotPSDGBufRLSideSnsDtMinCarPosX;
	
#ifdef APA_WITH_NORMAL_CORNER_UPA_SNS_POSITION
	// 1.3m,def: 180cm, APA_DISTANCE_TYPE APASlotPRCornerSnsDtMaxObjDisInsideSlot[2]; the corner sns may mis detect obj out side of slot.
	// RR, RL corner sensor
	{1400,1600},
	700, // 70cm, APA_DISTANCE_TYPE APASlotPRCornerSnsDtMaxObjDisOutsideSlot; the corner sns may mis detect obj out side of slot.
#else	
	// 1.3m,def: 180cm, APA_DISTANCE_TYPE APASlotPRCornerSnsDtMaxObjDisInsideSlot[2]; the corner sns may mis detect obj out side of slot.
	{1800,1800},

	700, // 70cm, APA_DISTANCE_TYPE APASlotPRCornerSnsDtMaxObjDisOutsideSlot; the corner sns may mis detect obj out side of slot.
#endif
	2000, // 2013 04 11, kjy change to 2m for making the system more stable. def: 2.5m, APA_DISTANCE_TYPE APASlotPRSideSnsDtMaxObjDis;
	1000, // APA_DISTANCE_TYPE APASlotPResetSlotBorderLineMaxDeltaCarPosX;
	5.0 * PI / 180.0, // APA_ANGLE_TYPE APASlotPResetSlotBorderLineMinDeltaCarAngWithEndPos1;
	15.0 * PI / 180.0, // APA_ANGLE_TYPE APASlotPResetSlotBorderLineMinDeltaCarAngWithEndPos2;
	1000, // 1m, APA_DISTANCE_TYPE APASlotPResetSlotBorderLineMaxCarAndBorderLineDisY;

	2000, // 2m to end pos x APA_DISTANCE_TYPE APASlotPDtmEndPosLineCheckSideObjExisMinDeltaXDisSideSns;
	1500, // 1.5m to end pos x APA_DISTANCE_TYPE APASlotPDtmEndPosLineCheckSideObjExisMinDeltaXDisCornerSns;

/*2.4.10 *** Trajectory Calculate  Algorithm****/
/*2.4.10.1 *** Parallel****/

	// APA_DISTANCE_TYPE APATrajCalMaxOriginalPtToObj2Dis[2]; // 30cm.
	{
		// 0: Parallel,     1: Perpendicular
		//300,                400
		200,                400
	},
	800, // 80cm, APA_DISTANCE_TYPE APATrajCalOriginalPtToObj2DisCompByRisingEdgeMinWidth; // 80cm.
	1500, // 150cm, APA_DISTANCE_TYPE APATrajCalOriginalPtToObj2DisCompByRisingEdgeMaxWidth; // 150cm.
	150, // 15cm, APA_DISTANCE_TYPE APATrajCalOriginalPtToObj2DisCompByRisingEdgeMinSafetyDis; // 15cm at: width: 80cm.
	300, // 30cm, APA_DISTANCE_TYPE APATrajCalOriginalPtToObj2DisCompByRisingEdgeMaxSafetyDis; // 30cm at: width: 150cm.
	700, // 1m, APA_DISTANCE_TYPE APATrajCalOriginalPtToObj2DisCompByRisingEdgeMaxObj2PtX; // 70cm at: width: 150cm.


	// APATrajCalPointOnCarPosDataCalFloatType APATrajCalCarCornerPosExp[APA_CAR_CORNER_NUMBER];
	#if 0
	{
		// APA_CAR_CORNER_FR_INDEX
		// typedef struct {
		//	APACoordinateDataCalFloatType Coordinate;
			// typedef struct {
			//	APACoordinateDataCalFloatType Coordinate;
			// typedef struct {
			//	APA_DISTANCE_CAL_FLOAT_TYPE x;
				// APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_FR_INDEX].Coordinate.x =
				// APACal.HalfWidthOfCar + APACal.APATrajCalSafetyDisToObjAtFrontTurningCar / 2;
				950.0,
			//	APA_DISTANCE_CAL_FLOAT_TYPE y;
				// APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_FR_INDEX].Coordinate.y =
				// APACal.LenBetweenRAxisAndFBumper + APACal.APATrajCalSafetyDisToObjAtFrontTurningCar / 2;
				3613.0,
			// } APACoordinateDataCalFloatType;
		//	APA_DISTANCE_CAL_FLOAT_TYPE DisToCarCenter;
		// APA_DISTANCE_CAL_FLOAT_TYPE X, Y;
		// X = APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_FR_INDEX].Coordinate.x;
		// Y = APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_FR_INDEX].Coordinate.y;
		// APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_FR_INDEX].DisToCarCenterSquare = X * X + Y * Y;
		// APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_FR_INDEX].DisToCarCenter =
		// sqrt(APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_FR_INDEX].DisToCarCenterSquare);
		3735.809015,
		//	APA_DISTANCE_CAL_FLOAT_TYPE DisToCarCenterSquare;
		13956269,
		//	APA_ANGLE_TYPE Ang;
		// APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_FR_INDEX].Ang =
		// acos(X / APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_FR_INDEX].DisToCarCenter);
		1.31367698,
		//	APA_DISTANCE_CAL_FLOAT_TYPE MinInnerTurningRadius;
		//MinInnerTurningRadius = APA_TRAJCAL_GET_CAR_TURNING_RADIUS_FInnerCircle (APACal.LenBetweenRAxisAndFBumper,
		//APACal.HalfWidthOfCar, APACal.APATrajCalMinRearAxisCenterTurningRadius);
		4823.5811,
		//	APA_DISTANCE_CAL_FLOAT_TYPE MinOuterTurningRadius;
		//MinOuterTurningRadius = APA_TRAJCAL_GET_CAR_TURNING_RADIUS_FOuterCircle (APACal.LenBetweenRAxisAndFBumper,
		//	APACal.HalfWidthOfCar, APACal.APATrajCalMinRearAxisCenterTurningRadius);,
		6130.9326,
		// } APATrajCalPointOnCarPosDataCalFloatType;

		// APA_CAR_CORNER_FL_INDEX
		// typedef struct {
		//	APACoordinateDataCalFloatType Coordinate;
			// typedef struct {
			//	APACoordinateDataCalFloatType Coordinate;
			// typedef struct {
			//	APA_DISTANCE_CAL_FLOAT_TYPE x;
				// APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_FL_INDEX].Coordinate.x =
				// - APACal.HalfWidthOfCar - APACal.APATrajCalSafetyDisToObjAtFrontTurningCar / 2;
				-950,
			//	APA_DISTANCE_CAL_FLOAT_TYPE y;
				// APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_FL_INDEX].Coordinate.y =
				// APACal.LenBetweenRAxisAndFBumper + APACal.APATrajCalSafetyDisToObjAtFrontTurningCar / 2;
				3613.0,
			// } APACoordinateDataCalFloatType;
		//	APA_DISTANCE_CAL_FLOAT_TYPE DisToCarCenter;
		// APA_DISTANCE_CAL_FLOAT_TYPE X, Y;
		// X = APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_FL_INDEX].Coordinate.x;
		// Y = APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_FL_INDEX].Coordinate.y;
		// APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_FL_INDEX].DisToCarCenterSquare = X * X + Y * Y;
		// APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_FL_INDEX].DisToCarCenter =
		// sqrt(APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_FL_INDEX].DisToCarCenterSquare);
		3735.809015,
		//	APA_DISTANCE_CAL_FLOAT_TYPE DisToCarCenterSquare;
		13956269.0,
		//	APA_ANGLE_TYPE Ang;
		// APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_FL_INDEX].Ang =
		// acos(X / APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_FL_INDEX].DisToCarCenter);
		1.827915674,
		//	APA_DISTANCE_CAL_FLOAT_TYPE MinInnerTurningRadius;
		//MinInnerTurningRadius = APA_TRAJCAL_GET_CAR_TURNING_RADIUS_FInnerCircle (APACal.LenBetweenRAxisAndFBumper,
		//APACal.HalfWidthOfCar, APACal.APATrajCalMinRearAxisCenterTurningRadius);
		4823.5811,
		//	APA_DISTANCE_CAL_FLOAT_TYPE MinOuterTurningRadius;
		//MinOuterTurningRadius = APA_TRAJCAL_GET_CAR_TURNING_RADIUS_FOuterCircle (APACal.LenBetweenRAxisAndFBumper,
		//	APACal.HalfWidthOfCar, APACal.APATrajCalMinRearAxisCenterTurningRadius);,
		6130.9326,
		// } APATrajCalPointOnCarPosDataCalFloatType;
		// APA_CAR_CORNER_RL_INDEX
		// typedef struct {
		//	APACoordinateDataCalFloatType Coordinate;
			// typedef struct {
			//	APACoordinateDataCalFloatType Coordinate;
			// typedef struct {
			//	APA_DISTANCE_CAL_FLOAT_TYPE x;
				// APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_RL_INDEX].Coordinate.x =
				// -APACal.HalfWidthOfCar - APACal.APATrajCalSafetyDisToObjAtFrontTurningCar / 2;
				-950.0000,
			//	APA_DISTANCE_CAL_FLOAT_TYPE y;
				// APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_RL_INDEX].Coordinate.y =
				// - APACal.LenBetweenRAxisAndRBumper - APACal.APATrajCalSafetyDisToObjAtFrontTurningCar / 2;
				-924,
			// } APACoordinateDataCalFloatType;
		//	APA_DISTANCE_CAL_FLOAT_TYPE DisToCarCenter;
		// APA_DISTANCE_CAL_FLOAT_TYPE X, Y;
		// X = APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_RL_INDEX].Coordinate.x;
		// Y = APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_RL_INDEX].Coordinate.y;
		// APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_RL_INDEX].DisToCarCenterSquare = X * X + Y * Y;
		// APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_RL_INDEX].DisToCarCenter =
		// sqrt(APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_RL_INDEX].DisToCarCenterSquare);
		1325.245638,
		//	APA_DISTANCE_CAL_FLOAT_TYPE DisToCarCenterSquare;
		1756276.0,
		//	APA_ANGLE_TYPE Ang;
		// APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_RL_INDEX].Ang =
		// 2 * PI - acos(X / APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_RL_INDEX].DisToCarCenter);
		3.913117641,
		//	APA_DISTANCE_CAL_FLOAT_TYPE MinInnerTurningRadius;
		//MinInnerTurningRadius = APA_TRAJCAL_GET_CAR_TURNING_RADIUS_FInnerCircle (APACal.LenBetweenRAxisAndFBumper,
		//APACal.HalfWidthOfCar, APACal.APATrajCalMinRearAxisCenterTurningRadius);
		3224.5703,
		//	APA_DISTANCE_CAL_FLOAT_TYPE MinOuterTurningRadius;
		//MinOuterTurningRadius = APA_TRAJCAL_GET_CAR_TURNING_RADIUS_FOuterCircle (APACal.LenBetweenRAxisAndFBumper,
		//	APACal.HalfWidthOfCar, APACal.APATrajCalMinRearAxisCenterTurningRadius);,
		4971.8462,
		// } APATrajCalPointOnCarPosDataCalFloatType;																																	APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_RL_INDEX].MinTurningRadius;

		// APA_CAR_CORNER_RR_INDEX
		// typedef struct {
		//	APACoordinateDataCalFloatType Coordinate;
			// typedef struct {
			//	APACoordinateDataCalFloatType Coordinate;
			// typedef struct {
			//	APA_DISTANCE_CAL_FLOAT_TYPE x;
				// APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_RR_INDEX].Coordinate.x =
				// APACal.HalfWidthOfCar + APACal.APATrajCalSafetyDisToObjAtFrontTurningCar / 2;
				950,
			//	APA_DISTANCE_CAL_FLOAT_TYPE y;
				// APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_RR_INDEX].Coordinate.y =
				// - APACal.LenBetweenRAxisAndRBumper - APACal.APATrajCalSafetyDisToObjAtFrontTurningCar / 2;
				-924,
			// } APACoordinateDataCalFloatType;
		//	APA_DISTANCE_CAL_FLOAT_TYPE DisToCarCenter;
		// APA_DISTANCE_CAL_FLOAT_TYPE X, Y;
		// X = APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_RR_INDEX].Coordinate.x;
		// Y = APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_RR_INDEX].Coordinate.y;
		// APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_RR_INDEX].DisToCarCenterSquare = X * X + Y * Y;
		// APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_RR_INDEX].DisToCarCenter =
		// sqrt(APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_RR_INDEX].DisToCarCenterSquare);
		1325.245638,
		//	APA_DISTANCE_CAL_FLOAT_TYPE DisToCarCenterSquare;
		1756276,
		//	APA_ANGLE_TYPE Ang;
		// APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_RR_INDEX].Ang =
		// 2 * PI - acos(X / APACal.APATrajCalCarCornerPosExp[APA_CAR_CORNER_RR_INDEX].DisToCarCenter);
		5.51166032,
		//	APA_DISTANCE_CAL_FLOAT_TYPE MinInnerTurningRadius;
		//MinInnerTurningRadius = APA_TRAJCAL_GET_CAR_TURNING_RADIUS_FInnerCircle (APACal.LenBetweenRAxisAndFBumper,
		//APACal.HalfWidthOfCar, APACal.APATrajCalMinRearAxisCenterTurningRadius);
		3224.5703,
		//	APA_DISTANCE_CAL_FLOAT_TYPE MinOuterTurningRadius;
		//MinOuterTurningRadius = APA_TRAJCAL_GET_CAR_TURNING_RADIUS_FOuterCircle (APACal.LenBetweenRAxisAndFBumper,
		//	APACal.HalfWidthOfCar, APACal.APATrajCalMinRearAxisCenterTurningRadius);,
		4971.8462
		// } APATrajCalPointOnCarPosDataCalFloatType;
	},
	#else
	{ //Luhui 20200713 
		1009.5,
		3771,
		3903.784222,
		15239531.25,
		1.309228637,
		5018.548828,
		6529.444048,
		-1009.5,
		3771,
		3903.784222,
		15239531.25,
		1.832364017,
		5018.548828,
		6529.444048,
		-1009.5,
		-975,
		1403.465443,
		1969715.25,
		3.909607836,
		3425.057129,
		5418.839689,
		1009.5,
		-975,
		1403.465443,
		1969715.25,
		5.515170124,
		3425.057129,
		5418.839689,
	},
	#endif
	260, // mm APA_DISTANCE_TYPE APATrajCalSafetyDisToObjAtRear; // End Position.
	400, // APA_DISTANCE_TYPE APATrajCalSafetyDisToObjAtRearSnsWithoutDtdObj;	
	-50, //2014 09 20 changed by kjy from 0 to -5cm. 0, //260 APA_DISTANCE_TYPE APATrajCalSafetyDisToObjAtRearTurningCar; // when turning the car

	260, // 26cm, APA_DISTANCE_TYPE APATrajCalSafetyDisToObjAtRearForParallelParkingInStep3Cor;	
	26.0 / (45.0 * PI / 180.0), // 45deg = 0cm. 0deg = 26cm. APA_RATIO_TYPE APATrajCalSafetyDisToObjAtRearRatioForParallelParkingInStep3Cor;	// according to current car angle. drive straight line backwards.
	
	260, // APA_DISTANCE_TYPE APATrajCalSafetyDisToObjAtFront; // when turning the car
	400, // APA_DISTANCE_TYPE APATrajCalSafetyDisToObjAtFrontSnsWithoutDtdObj;	
	-100, //0, //260 APA_DISTANCE_TYPE APATrajCalSafetyDisToObjAtFrontTurningCar; // when turning the car
	260, // APA_DISTANCE_TYPE APATrajCalSafetyDisToObjInOppsiteSide; // End Position
	//APA_DISTANCE_TYPE APATrajCalSafetyDisFromRearTireToObj2AtStep2[10]; // Safety distance between the corner object and the rear tire.
	{
				//if(Obj2Type == APA_SLOT_OBJ_TYPE_UNKNOWN){
		400, // 350 - 70,		//	Obj2TypeGroupIndex = 0;
				//} else if(Obj2Type <= APA_SLOT_OBJ_TYPE_SQUARE_OBJ_WITH_FALLING_SHAPE){
		450, // 350,		//	Obj2TypeGroupIndex = 0; small square object, width < 1m, 
				//} else if(Obj2Type <= APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_BIG_RISING_AND_FALLING_SHAPE){
		400, // 350 - 70,		//	Obj2TypeGroupIndex = 1; small round object, width < 1m.
				//} else if(Obj2Type <= APA_SLOT_OBJ_TYPE_PER_CAR_WITH_BIG_FLAT_SMALL_WIDTH){ // 10
		450, // 350 - 50,		//	Obj2TypeGroupIndex = 2; small per vehicle, width < 1.8m,
				//} else if(Obj2Type <= APA_SLOT_OBJ_TYPE_PER_CAR_WITH_NORMAL_FLAT_NORMAL_WIDTH){//12
		400, // 350 - 100,	//	Obj2TypeGroupIndex = 3; normal per vehicle with big or normal rising shape. 1.8 < width < 2.3m.
				//} else if(Obj2Type <= APA_SLOT_OBJ_TYPE_PER_CAR_WITH_BIG_FLAT_NORMAL_WIDTH){ // 13
		400, // 350,		//	Obj2TypeGroupIndex = 4; normal per vehicle with big flat bumper, 1.8 < width < 2.3m.
				//} else if(Obj2Type <= APA_SLOT_OBJ_TYPE_PER_CAR_WITH_SMALL_FLAT_BIG_WIDTH){ // 14.
		400, // 350 - 150,	//	Obj2TypeGroupIndex = 5; big per vehicle with big rising shape, big round bumper, width > 2.3m
				//} else if(Obj2Type <= APA_SLOT_OBJ_TYPE_PER_CAR_WITH_NORMAL_FLAT_BIG_WIDTH){// 15
		400, // 350 - 100,	//	Obj2TypeGroupIndex = 6; big per vehicle with normal rising shape. normal round bumper, width > 2.3m
				//} else if(Obj2Type <= APA_SLOT_OBJ_TYPE_PER_CAR_WITH_BIG_FLAT_BIG_WIDTH){ // 16
		400, // 350 - 70,	//	Obj2TypeGroupIndex = 7; big per vehicle with big flat bumper, width > 2.3m
				//} else {
		400, // 350 - 150		//	Obj2TypeGroupIndex = 8; parallel vehicle width > 3.2m.
				//}
	},
	//-100, // def: 0, kjy changed to -10cm 2014 07 04  //APA_DISTANCE_TYPE APATrajCalSafetyDisToObjAtFrontCornerTurningCar; // Safety distance between the corner object and the car front outer cor  
	//APA_DISTANCE_TYPE APATrajCalSafetyDisToObjAtFrontCornerTurningCarFor3StepParking[APA_SLOT_OBJ_PROFILE_TYPE_NUM + 1]; // Safety distance between the corner object and the car front outer corner. 
	{
		150, // 0 - 100, // APA_SLOT_OBJ_TYPE_UNKNOWN = 100,
		150, // 0 - 100, // APA_SLOT_OBJ_TYPE_SQUARE_OBJ,  // 1
		150, // 0 - 100, // APA_SLOT_OBJ_TYPE_SQUARE_OBJ_WITH_FALLING_SHAPE,  // 2
		150, // -50 - 100, // APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_RISING_SHAPE_ONLY,  // 3
		150, // -50 - 100, // APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_RISING_AND_FLAT_SHAPE,  // 4
		150, // 0 - 100, // APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_SMALL_RISING_AND_FALLING_SHAPE, // 5
		150, // -50 - 100, // APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_NORMAL_RISING_AND_FALLING_SHAPE, // 6
		150, // -50 - 100, // APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_BIG_RISING_AND_FALLING_SHAPE,  // 7
		150, // -80 - 100, // APA_SLOT_OBJ_TYPE_PER_CAR_WITH_SMALL_FLAT_SMALL_WIDTH, // 8 // Flat shape < 1/3, car width < 1.8m
		150, // -50 - 100, // APA_SLOT_OBJ_TYPE_PER_CAR_WITH_NORMAL_FLAT_SMALL_WIDTH, // 9 // Flat shape = 1/3 ~ 2/3, car width < 1.8m
		150, // 0 - 100, // APA_SLOT_OBJ_TYPE_PER_CAR_WITH_BIG_FLAT_SMALL_WIDTH,  // 10 // Flat shape > 2/3, car width < 1.8m
		150, // -80 - 100, // APA_SLOT_OBJ_TYPE_PER_CAR_WITH_SMALL_FLAT_NORMAL_WIDTH, // 11  // Flat shape < 1/3, car width = 1.8m ~ 2.3m
		150, // -30 - 100, // APA_SLOT_OBJ_TYPE_PER_CAR_WITH_NORMAL_FLAT_NORMAL_WIDTH, // 12 // Flat shape = 1/3 ~ 2/3, car width = 1.8m ~ 2.3m
		150, // 0 - 100, // APA_SLOT_OBJ_TYPE_PER_CAR_WITH_BIG_FLAT_NORMAL_WIDTH, // 13 // Flat shape > 2/3, car width = 1.8m ~ 2.3m
		150, // -80 - 100, // APA_SLOT_OBJ_TYPE_PER_CAR_WITH_SMALL_FLAT_BIG_WIDTH, // 14 // Flat shape < 1/3, car width > 2.3m
		150, // -30 - 100, // APA_SLOT_OBJ_TYPE_PER_CAR_WITH_NORMAL_FLAT_BIG_WIDTH, // 15 // Flat shape = 1/3 ~ 2/3, car width > 2.3m
		150, // -30 - 100, // APA_SLOT_OBJ_TYPE_PER_CAR_WITH_BIG_FLAT_BIG_WIDTH, // 16, // Flat shape > 2/3, car width > 2.3m	
		150, // -50 - 100, // APA_SLOT_OBJ_TYPE_CAR_ANGULAR_NEG_10DEG_RISING_SHAPE_AT_START, // 17 // flat shape is falling shape (slope (k): +), for obj1 it is car with +10deg, for obj2 it is car with -10deg
		150, // -50 - 100, // APA_SLOT_OBJ_TYPE_CAR_ANGULAR_NEG_10DEG_FLAT_SHAPE_AT_START,  // 18
		150, // -50 - 100, // APA_SLOT_OBJ_TYPE_CAR_ANGULAR_NEG_20DEG_RISING_SHAPE_AT_START, // 19
		150, // -50 - 100, // APA_SLOT_OBJ_TYPE_CAR_ANGULAR_NEG_20DEG_FLAT_SHAPE_AT_START,  // 20
		150, // -50 - 100, // APA_SLOT_OBJ_TYPE_CAR_ANGULAR_NEG_30DEG_RISING_SHAPE_AT_START,  // 21
		150, // -50 - 100, // APA_SLOT_OBJ_TYPE_CAR_ANGULAR_NEG_30DEG_FLAT_SHAPE_AT_START,  // 22
		150, // -100 - 100, // APA_SLOT_OBJ_TYPE_CAR_ANGULAR_10DEG_RISING_SHAPE_AT_START, // 23  // flat shape is rising shape (slope (k): -), for obj1 it is car with -10deg, for obj2 it is car with +10deg
		150, // -100 - 100, // APA_SLOT_OBJ_TYPE_CAR_ANGULAR_10DEG_FLAT_SHAPE_AT_START,  // 24
		150, // -100 - 100, // APA_SLOT_OBJ_TYPE_CAR_ANGULAR_20DEG_RISING_SHAPE_AT_START,  // 25
		150, // -100 - 100, // APA_SLOT_OBJ_TYPE_CAR_ANGULAR_20DEG_FLAT_SHAPE_AT_START,  // 26
		150, // -100 - 100, // APA_SLOT_OBJ_TYPE_CAR_ANGULAR_30DEG_RISING_SHAPE_AT_START,  // 27
		150, // -100 - 100, // APA_SLOT_OBJ_TYPE_CAR_ANGULAR_30DEG_FLAT_SHAPE_AT_START,  // 28
		150, // 0 - 50, // APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_SMALL_RISING_SHAPE, // 29 // rising width < 20cm,
		150, // -30 - 50, // APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_NORMAL_RISING_SHAPE, // 30 // rising width < 40cm,
		150, // -50 - 100, // APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_BIG_RISING_SHAPE, // 31 // rising width < 60cm.
		150 // -100 - 100 // APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_VERY_BIG_RISING_SHAPE, // 32 // rising width > 60cm.
	},
	//APA_DISTANCE_TYPE APATrajCalSafetyDisToObjAtFrontCornerTurningCarForOver3StepParking[APA_SLOT_OBJ_PROFILE_TYPE_NUM + 1]; // Safety distance between the corner object and the car front outer corner. 
	{
		250, // 0 , // APA_SLOT_OBJ_TYPE_UNKNOWN = 0,
		250, // 0 , // APA_SLOT_OBJ_TYPE_SQUARE_OBJ,  // 1
		250, // 0 , // APA_SLOT_OBJ_TYPE_SQUARE_OBJ_WITH_FALLING_SHAPE,  // 2
		250, // -50 , // APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_RISING_SHAPE_ONLY,  // 3
		250, // -50 , // APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_RISING_AND_FLAT_SHAPE,  // 4
		250, // 0 , // APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_SMALL_RISING_AND_FALLING_SHAPE, // 5
		250, // -50 , // APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_NORMAL_RISING_AND_FALLING_SHAPE, // 6
		250, // -50 , // APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_BIG_RISING_AND_FALLING_SHAPE,  // 7
		250, // -80 , // APA_SLOT_OBJ_TYPE_PER_CAR_WITH_SMALL_FLAT_SMALL_WIDTH, // 8 // Flat shape < 1/3, car width < 1.8m
		250, // -50 , // APA_SLOT_OBJ_TYPE_PER_CAR_WITH_NORMAL_FLAT_SMALL_WIDTH, // 9 // Flat shape = 1/3 ~ 2/3, car width < 1.8m
		250, // 0 , // APA_SLOT_OBJ_TYPE_PER_CAR_WITH_BIG_FLAT_SMALL_WIDTH,  // 10 // Flat shape > 2/3, car width < 1.8m
		250, // -80 , // APA_SLOT_OBJ_TYPE_PER_CAR_WITH_SMALL_FLAT_NORMAL_WIDTH, // 11  // Flat shape < 1/3, car width = 1.8m ~ 2.3m
		250, // -30 , // APA_SLOT_OBJ_TYPE_PER_CAR_WITH_NORMAL_FLAT_NORMAL_WIDTH, // 12 // Flat shape = 1/3 ~ 2/3, car width = 1.8m ~ 2.3m
		250, // 0 , // APA_SLOT_OBJ_TYPE_PER_CAR_WITH_BIG_FLAT_NORMAL_WIDTH, // 13 // Flat shape > 2/3, car width = 1.8m ~ 2.3m
		250, // -80 , // APA_SLOT_OBJ_TYPE_PER_CAR_WITH_SMALL_FLAT_BIG_WIDTH, // 14 // Flat shape < 1/3, car width > 2.3m
		250, // -30 , // APA_SLOT_OBJ_TYPE_PER_CAR_WITH_NORMAL_FLAT_BIG_WIDTH, // 15 // Flat shape = 1/3 ~ 2/3, car width > 2.3m
		250, // -30 , // APA_SLOT_OBJ_TYPE_PER_CAR_WITH_BIG_FLAT_BIG_WIDTH, // 16, // Flat shape > 2/3, car width > 2.3m	
		250, // -50 , // APA_SLOT_OBJ_TYPE_CAR_ANGULAR_NEG_10DEG_RISING_SHAPE_AT_START, // 17 // flat shape is falling shape (slope (k): +), for obj1 it is car with +10deg, for obj2 it is car with -10deg
		250, // -50 , // APA_SLOT_OBJ_TYPE_CAR_ANGULAR_NEG_10DEG_FLAT_SHAPE_AT_START,  // 18
		250, // -50 , // APA_SLOT_OBJ_TYPE_CAR_ANGULAR_NEG_20DEG_RISING_SHAPE_AT_START, // 19
		250, // -50 , // APA_SLOT_OBJ_TYPE_CAR_ANGULAR_NEG_20DEG_FLAT_SHAPE_AT_START,  // 20
		250, // -50 , // APA_SLOT_OBJ_TYPE_CAR_ANGULAR_NEG_30DEG_RISING_SHAPE_AT_START,  // 21
		250, // -50 , // APA_SLOT_OBJ_TYPE_CAR_ANGULAR_NEG_30DEG_FLAT_SHAPE_AT_START,  // 22
		250, // -100 , // APA_SLOT_OBJ_TYPE_CAR_ANGULAR_10DEG_RISING_SHAPE_AT_START, // 23  // flat shape is rising shape (slope (k): -), for obj1 it is car with -10deg, for obj2 it is car with +10deg
		250, // -100 , // APA_SLOT_OBJ_TYPE_CAR_ANGULAR_10DEG_FLAT_SHAPE_AT_START,  // 24
		250, // -100 , // APA_SLOT_OBJ_TYPE_CAR_ANGULAR_20DEG_RISING_SHAPE_AT_START,  // 25
		250, // -100 , // APA_SLOT_OBJ_TYPE_CAR_ANGULAR_20DEG_FLAT_SHAPE_AT_START,  // 26
		250, // -100 , // APA_SLOT_OBJ_TYPE_CAR_ANGULAR_30DEG_RISING_SHAPE_AT_START,  // 27
		250, // -100 , // APA_SLOT_OBJ_TYPE_CAR_ANGULAR_30DEG_FLAT_SHAPE_AT_START,  // 28
		250, // 0, // APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_SMALL_RISING_SHAPE, // 29 // rising width < 20cm,
		250, // -30, // APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_NORMAL_RISING_SHAPE, // 30 // rising width < 40cm,
		250, // -50 , // APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_BIG_RISING_SHAPE, // 31 // rising width < 60cm.
		250 // -100  // APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_VERY_BIG_RISING_SHAPE, // 32 // rising width > 60cm.
	},
	
	260, //APA_DISTANCE_TYPE APATrajCalSafetyDisForRearTireToCurb;

	200, // 20cm, APA_DISTANCE_TYPE APATrajCalStep3MoveMinDisToObj1For4StepParking; // 20cm.
	4.0 * PI / 180.0, // 4deg. APA_ANGLE_TYPE APATrajCalStep3MoveMinCarAngFor4StepParking; // 4deg. 2cm.
	15.0 * PI / 180.0, // 15deg. APA_ANGLE_TYPE APATrajCalStep3MoveMaxCarAngFor4StepParking; // 15deg. 12cm.
	20, // 2cm, APA_DISTANCE_TYPE APATrajCalStep3MoveOffsetXMinDisFor4StepParking; // 2cm.
	120, // 12cm, APA_DISTANCE_TYPE APATrajCalStep3MoveOffsetXMaxDisFor4StepParking; // 12cm.

		
	50, // mm APA_DISTANCE_TYPE APATrajCalCarPosOnTheKeyPointTolDis;
	-0.43633232,  //APA_ANGLE_CAL_FLOAT_TYPE APATrajCalSnsDtdDistanceValidUpwardStartAngle;
	0.43633232,   //APA_ANGLE_CAL_FLOAT_TYPE APATrajCalSnsDtdDistanceValidUpwardEndAngle;
	2.7052603,    //APA_ANGLE_CAL_FLOAT_TYPE APATrajCalSnsDtdDistanceValidDownwardStartAngle;
	2.7052603,   //	APA_ANGLE_CAL_FLOAT_TYPE APATrajCalSnsDtdDistanceValidDownwardEndAngle;
	// APA_DISTANCE_TYPE APATrajCalMaxSnsDtDis[APA_SUPPORT_APA_SNS_NUM]; // relative to car rotation center
	{
		4100,//RRS
		4100,//RR
		2500,//RRM
		2500,//RLM
		4100, //RL
		4100,//RLS
		
		4100,//FRS
		4100,//FR
		2500,//FRM
		2500,//FLM
		4100,//FL
		4100 //FLS
	},	
	// APACal.APATrajCalCarParkingAlongCurbMinSlotDepthRefObject = APACal.APATrajCalCarEndPosDisToCurb + (APACal.WidthOfCar * 3.0) / 4.0;
	1662,//1663, // 300 + 1817 * 3.0 / 4.0, APA_DISTANCE_TYPE APATrajCalCarParkingAlongCurbMinSlotDepthRefObject;

	1.0 * PI / 180, // 3 deg, APA_ANGLE_TYPE APATrajCalCarDriveStraightlyTolCarAngle; // 1 deg. at APA_TRAJCAL_CAR_DRIVE_STRAIGHTLY_TOL_MAX_CHECK_DIS: 10m
	5.0 * PI / 180.0, // 5deg, APA_ANGLE_TYPE APATrajCalSetupSysCoordinateCarDriveStraightlyTolCarAngle1; // 5 deg.
	3.0 * PI / 180.0, // 5deg, APA_ANGLE_TYPE APATrajCalSetupSysCoordinateCarDriveStraightlyTolCarAngle2; // 3 deg.

	50, // 20cm APA_DISTANCE_TYPE APATrajCalStep23CircleMinOffsetDis;
	0.6, // def: 0.3, APA_RATIO_TYPE APATrajCalRegardedAsLineStepCarAtLineStepRatio; // 0.6
	400, // 40cm, APA_DISTANCE_TYPE APATrajCalRegardedAsStep3MaxCarPosXOffsetToEndPosX;

	// APACoordinateDataType APATrajCalRRCMayHitObj2MoveStep3CircleDeltaDisFor3StepParking;
	{
		// x,    y
		0,  - 250
	},
	// APACoordinateDataType APATrajCalRRCMayHitObj2MoveStep3CircleDeltaDisFor4StepParking;
	{
		// x,    y
		30,  - 200
	},
	0.08 * 35.0 * PI / 180.0, // 8% max steering angle. APA_ANGLE_TYPE APATrajCalRRCMayHitObj2CorStep2SteeringAngReducedValue; // 8% Max steering angle.

	900, // 90cm, APA_DISTANCE_TYPE APATrajCalStep3CarWillHitObj2SearchBkMaxDis; // 70cm	
	700, // 70cm, APA_DISTANCE_TYPE APATrajCalStep3CarWillHitObj2SearchBkMinDis; // 70cm	

	// for recalculating the circle of 3rd step for 3 steps parking 2014 08 21
	1500, // APA_DISTANCE_TYPE APATrajCalMoveStep3Circle3StepParkingMinAddLen;
	1000, // APA_DISTANCE_TYPE APATrajCalKeepEnoughSafety3StepParkingSearchBkDis;
	30,//50, // 75%, APA_DISTANCE_TYPE APATrajCalMoveStep3CircleControlRatio;
	0,//changed from 10 to 0 lzm 2015 03 16,//25, 40, // 75%, APA_DISTANCE_TYPE APATrajCalReCalStep3CircleRadiusControlRation;		

	700, // 70cm, APA_DISTANCE_TYPE APATrajCalCheckSideObjDisDevideDis1; // 70cm	
	1000, // 1m, APA_DISTANCE_TYPE APATrajCalCheckSideObjDisDevideDis2; // 100cm	

	-2000, //Luhui 20200603 500, // 50cm. APA_DISTANCE_TYPE APATrajCalCheckSideObjDisStartObjPosY;
	3000, // 3m. APA_DISTANCE_TYPE APATrajCalCheckSideObjDisEndObjPosY;

	800, // 80cm, APA_DISTANCE_TYPE APATrajCalCarParkingStep2StartSearchingSteeringWheelAngMinDis1ToObj2; // 80cm,
	1300, //130cm, APA_DISTANCE_TYPE APATrajCalCarParkingStep2StartSearchingSteeringWheelAngMinDis2ToObj2; // 130cm,
	7000, // 7m, APA_DISTANCE_TYPE APATrajCalCarParkingStep2StartSearchingSteeringWheelAngSlotLen; // 7m,
	4000, // 400cm, APA_DISTANCE_TYPE APATrajCalCarParkingStep2StartSearchingSteeringWheelAngMinY; // 350cm,
	17.0 * PI / 180.0, // 2014 06 30, kjy changed from 15deg to 17deg due to car may hit obj2. 15 deg. APA_ANGLE_TYPE APATrajCalCarParkingStep2StartSearchingSteeringWheelAng1;	
	20.0 * PI / 180.0, // 25 deg. APA_ANGLE_TYPE APATrajCalCarParkingStep2StartSearchingSteeringWheelAng2;	
	5.0 * PI / 180.0, // 15 deg. APA_ANGLE_TYPE APATrajCalCarParkingStep2AllowMinSteeringWheelAng1;
	10.0 * PI / 180.0, // 15 deg. APA_ANGLE_TYPE APATrajCalCarParkingStep2AllowMinSteeringWheelAng2;	
	10.0 * PI / 180.0, // 15 deg. APA_ANGLE_TYPE APATrajCalCarParkingStep2AllowMinSteeringWheelAng3;	
	15.0 * PI / 180.0, // 15 deg. APA_ANGLE_TYPE APATrajCalCarParkingStep2AllowMaxSteeringWheelAng1;	
	20.0 * PI / 180.0, // 15 deg. APA_ANGLE_TYPE APATrajCalCarParkingStep2AllowMaxSteeringWheelAng2;	
	5.0 * PI / 180.0, // 5 deg. APA_ANGLE_TYPE APATrajCalCarParkingStep2SteeringWheelAngStep1;
	1.0 * PI / 180.0, // 5 deg. APA_ANGLE_TYPE APATrajCalCarParkingStep2SteeringWheelAngStep2;
	2.0 * PI / 180.0, // APA_ANGLE_TYPE APATrajCalCarParkingInStep2AllowMinSteeringWheelAng;	
	2.0 * PI / 180.0, // APA_ANGLE_TYPE APATrajCalCarParkingInStep2SteeringWheelAngStep; 
	0.4 * 35.0 * PI / 180.0, // 40 % max steering angle. APA_ANGLE_TYPE APATrajCalCarParkingInStep2AllowSteeringWheelTurnBackAng; // 40%	
	#if 0
	// APA_DISTANCE_CAL_FLOAT_TYPE APATrajCalMinRearAxisCenterTurningRadius;
	// APACal.APATrajCalMinRearAxisCenterTurningRadius = APA_TRAJCAL_GET_CAR_TURNING_RADIUS_CENTER (APACal.LenBetweenFRAxis,
	// APACal.MaxSteeringWheelAngle);
	4320.903228,
	// APA_DISTANCE_CAL_FLOAT_TYPE APATrajCalMinRearTireTurningRadius;
	3370.903228, // APACal.APATrajCalMinRearAxisCenterTurningRadius - APACal.HalfWidthOfCar;
	
	// APA_DISTANCE_CAL_FLOAT_TYPE APATrajCalMinFOuterTurningRadius;
	// APACal.APATrajCalMinFOuterTurningRadius = APA_TRAJCAL_GET_CAR_TURNING_RADIUS_FOuterCircle (
	// APACal.LenBetweenRAxisAndFBumper,
	//	APACal.HalfWidthOfCar, APACal.APATrajCalMinRearAxisCenterTurningRadius);
	6390.320011,
	// APA_DISTANCE_CAL_FLOAT_TYPE APATrajCalMinFInnerTurningRadius;
	// APACal.APATrajCalMinFInnerTurningRadius = APA_TRAJCAL_GET_CAR_TURNING_RADIUS_FInnerCircle (
	// APACal.LenBetweenRAxisAndFBumper,
	//	APACal.HalfWidthOfCar, APACal.APATrajCalMinRearAxisCenterTurningRadius);
	4941.331559,
	// APA_DISTANCE_CAL_FLOAT_TYPE APATrajCalMinROuterTurningRadius;
	// APACal.APATrajCalMinROuterTurningRadius = APA_TRAJCAL_GET_CAR_TURNING_RADIUS_ROuterCircle (
	// APACal.LenBetweenRAxisAndRBumper,
	//	APACal.HalfWidthOfCar, APACal.APATrajCalMinRearAxisCenterTurningRadius);
	5351.279926,
	// APA_DISTANCE_CAL_FLOAT_TYPE APATrajCalMinRInnerTurningRadius;
	// APACal.APATrajCalMinRInnerTurningRadius = APA_TRAJCAL_GET_CAR_TURNING_RADIUS_RInnerCircle (
	// APACal.LenBetweenRAxisAndRBumper,
	//	APACal.HalfWidthOfCar, APACal.APATrajCalMinRearAxisCenterTurningRadius);
	3495.248857,
	// APA_ANGLE_CAL_FLOAT_TYPE APATrajCalMinFInnerCornerAndRAxisAng;
	// APACal.APATrajCalMinFInnerCornerAndRAxisAng = atan(APACal.LenBetweenRAxisAndFBumper /
	// (R7 - APACal.HalfWidthOfCar));
	#else
	// Luhui 20200713 Collision checker
	4320.903228,
    //4500.000000,							//modify by wuzhen 0726 r=4.5
	3361.403228,
	6459.759999,
	5014.466339,
	5360.809943,
	3486.352917,
	#endif

	0.89024097,
	// APA_ANGLE_CAL_FLOAT_TYPE APATrajCalMinRInnerCornerAndRAxisAng;
	// APACal.APATrajCalMinRInnerCornerAndRAxisAng = atan(APACal.LenBetweenRAxisAndRBumper /
	// (R7 - APACal.HalfWidthOfCar));
	0.34449288,
	600, // 10m, APA_RATIO_TYPE APATrajCalLineIsVMaxK; // if the K of the line great than APATrajCalLineIsVMaxK, means the line is vertical,
	1.0 / 600.0, // 10m, APA_RATIO_TYPE APATrajCalLineIsHMinK; // if the K of the line is less than APATrajCalLineIsHMinK, means the line is horizontal,
	0.0001, // APA_RATIO_TYPE APATrajCalLinesAreParallelMinDeltaK; // if the MATH_FABS(K1 - K2) is less than this value, we will assume that these two lines are parallel.
	0.1 * PI / 180.0, // 0.1 deg, APA_ANGLE_TYPE APATrajCalCarDriveVerticallyMaxCarAng; // if the K of the line great than APATrajCalLineIsVMaxK, means the line is vertical,
	89.9 * PI / 180, // 89.9 deg, APA_ANGLE_TYPE APATrajCalCarDriveHorMinCarAng; // if the K of the line great than APATrajCalLineIsVMaxK, means the line is vertical,
	2500, // 2.5m, APA_DISTANCE_TYPE APATrajCalCarParkingTrajectoryOuterTurningCircleMaxX1; // Car is located at Ycurc < 0
	8000, // 8m, APA_DISTANCE_TYPE APATrajCalCarParkingTrajectoryOuterTurningCircleMaxX2; //  Car is located at Ycurc < 0
	700, // 70cm APA_DISTANCE_TYPE APASlotObj12CheckCarDrvDisY;

	5737, //4537+1200 // Car Lenth + 1.2m, APA_DISTANCE_TYPE APATrajCalMinSlotLengthWithInvalidObj2;

	// APA_DISTANCE_TYPE APATrajCalCoordinateSetupCheckAllowMinCarPosXAtObj1[APA_TRAJCAL_COORDINATE_SETUP_CHECK_OBJ_CASE_NUM];
	{
		-4000, // def: -3m, // APATrajCalCoordinateSetupCheckObjCase_Obj1ExistObj2Exist = 0,
		-4000, // def: -3.5m APATrajCalCoordinateSetupCheckObjCase_Obj1ExistObj2Not,
		-4800 // def: -4.8m APATrajCalCoordinateSetupCheckObjCase_Obj1NotObj2Exist
	
	},
	// APA_DISTANCE_TYPE APATrajCalCoordinateSetupCheckAllowMaxCarPosXAtObj1[APA_TRAJCAL_COORDINATE_SETUP_CHECK_OBJ_CASE_NUM];
	{
		-800, // -0.8m, // APATrajCalCoordinateSetupCheckObjCase_Obj1ExistObj2Exist = 0,
		-900, // -0.9m APATrajCalCoordinateSetupCheckObjCase_Obj1ExistObj2Not,
		-600 // -0.6m APATrajCalCoordinateSetupCheckObjCase_Obj1NotObj2Exist
	
	},
	// APA_DISTANCE_TYPE APATrajCalCoordinateSetupCheckAllowMinCarPosXAtObj2[APA_TRAJCAL_COORDINATE_SETUP_CHECK_OBJ_CASE_NUM];
	{
		-4000, // def: -3m, // APATrajCalCoordinateSetupCheckObjCase_Obj1ExistObj2Exist = 0,
		-4500, // def: -3.5m APATrajCalCoordinateSetupCheckObjCase_Obj1ExistObj2Not,
		-4000 // def: -3m, //-4.8m APATrajCalCoordinateSetupCheckObjCase_Obj1NotObj2Exist
	
	},
	// APA_DISTANCE_TYPE APATrajCalCoordinateSetupCheckAllowMaxCarPosXAtObj2[APA_TRAJCAL_COORDINATE_SETUP_CHECK_OBJ_CASE_NUM];
	{
		-800, // -0.8m, // APATrajCalCoordinateSetupCheckObjCase_Obj1ExistObj2Exist = 0,
		-600, // -0.9m APATrajCalCoordinateSetupCheckObjCase_Obj1ExistObj2Not,
		-800 // -0.6m APATrajCalCoordinateSetupCheckObjCase_Obj1NotObj2Exist
	
	},
	// APA_ANGLE_TYPE APATrajCalCoordinateSetupCheckAllowMinCarAngAtObj1[APA_TRAJCAL_COORDINATE_SETUP_CHECK_OBJ_CASE_NUM];
	{
		-22.0 * PI / 180.0, // -22deg, // APATrajCalCoordinateSetupCheckObjCase_Obj1ExistObj2Exist = 0,
		-20.0 * PI / 180.0, // -20deg, APATrajCalCoordinateSetupCheckObjCase_Obj1ExistObj2Not,
		-25.0 * PI / 180.0 // -25deg, APATrajCalCoordinateSetupCheckObjCase_Obj1NotObj2Exist
	
	},
	// APA_ANGLE_TYPE APATrajCalCoordinateSetupCheckAllowMaxCarAngAtObj1[APA_TRAJCAL_COORDINATE_SETUP_CHECK_OBJ_CASE_NUM];
	{
		25.0 * PI / 180.0, // 25deg, // APATrajCalCoordinateSetupCheckObjCase_Obj1ExistObj2Exist = 0,
		22.0 * PI / 180.0, // 22deg, APATrajCalCoordinateSetupCheckObjCase_Obj1ExistObj2Not,
		22.0 * PI / 180.0 // 22deg, APATrajCalCoordinateSetupCheckObjCase_Obj1NotObj2Exist
	
	},
	// APA_ANGLE_TYPE APATrajCalCoordinateSetupCheckAllowMinCarAngAtObj2[APA_TRAJCAL_COORDINATE_SETUP_CHECK_OBJ_CASE_NUM];
	{
		-22.0 * PI / 180.0, // -22deg, // APATrajCalCoordinateSetupCheckObjCase_Obj1ExistObj2Exist = 0,
		-20.0 * PI / 180.0, // -20deg, APATrajCalCoordinateSetupCheckObjCase_Obj1ExistObj2Not,
		-22.0 * PI / 180.0 // -25deg, APATrajCalCoordinateSetupCheckObjCase_Obj1NotObj2Exist
	
	},
	// APA_ANGLE_TYPE APATrajCalCoordinateSetupCheckAllowMaxCarAngAtObj2[APA_TRAJCAL_COORDINATE_SETUP_CHECK_OBJ_CASE_NUM];
	{
		22.0 * PI / 180.0, // 22deg, // APATrajCalCoordinateSetupCheckObjCase_Obj1ExistObj2Exist = 0,
		20.0 * PI / 180.0, // 20deg, APATrajCalCoordinateSetupCheckObjCase_Obj1ExistObj2Not,
		22.0 * PI / 180.0 // 22deg, APATrajCalCoordinateSetupCheckObjCase_Obj1NotObj2Exist
	
	},
		

	150, // 180, // 20cm, APA_DISTANCE_TYPE APATrajCalSystemCoordinateSetupObj2StartEdgeCheckMaxX; // 20cm.
	600, // 60cm, APA_DISTANCE_TYPE APATrajCalSystemCoordinateSetupObj2StartEdgeCheckMaxX2; // 60cm.
	700, // 60cm, APA_DISTANCE_TYPE APATrajCalSystemCoordinateSetupObj2StartEdgeCheckMaxY; // 70cm.
	-700, // -60cm, APA_DISTANCE_TYPE APATrajCalSystemCoordinateSetupObj2StartEdgeCheckMinY; // -60cm.
	400, // 40cm, APA_DISTANCE_TYPE APATrajCalSystemCoordinateSetupObj2StartEdgeCheckCompMaxY; // 40cm.
	
	
	0, //-200, // 200, 300, 400 	APA_DISTANCE_TYPE APATrajCalAPAParkingCoordinateYOffsetDis; // for block the value 400 is too small, the front bumper may hit the block. but for the ISO pole and car, it is ok.
	1800, // 80cm, // X + Y, APA_DISTANCE_TYPE APATrajCalAPAParkingCoordinateSetUpObj2SearchDis;
	1300, // 1m, // X + Y, APA_DISTANCE_TYPE APATrajCalAPAParkingCoordinateSetUpObj1SearchDis;
	250, // 5cm, APA_DISTANCE_TYPE APATrajCalAPAParkingCoordinateSetUpUseNearestDisPtCalMaxDeltaObj1Dis; // 5cm.
	200, // 5cm, APA_DISTANCE_TYPE APATrajCalAPAParkingCoordinateSetUpUseNearestDisPtCalMaxDeltaObj2Dis; // 5cm.
	350, // 50cm, APA_DISTANCE_TYPE APATrajCalAPAParkingCoordinateSetUpNotUseNearestDisCalMinDeltaObjDis;
	600, // 70cm, APA_DISTANCE_TYPE APATrajCalAPAParkingCoordinateSetUpNotUseNearestDisCalMaxDeltaObjDis;

#if 0
	// 5deg APA_DISTANCE_TYPE APATrajCalParalAPAParkingCoordinateYOffsetAngle1[2][APA_CAR_PARK_SIDE_NUM]; // > Slot + 1.6m, for block the value 400 is too small, the front bumper may hit the block. but for the ISO pole and car, it is ok.
	// Without curb,                   with curb
	// Park at Left,  Park at  Right       Park at Left side,      Park at right side,
	{{-0.5 * PI / 180.0, -0.5 * PI / 180.0}, {-0.5 * PI / 180.0, -0.5 * PI / 180.0}},
	//-0.5 * PI / 180.0, //- 0.2 * PI / 180.0, // 5deg APA_DISTANCE_TYPE APATrajCalParalAPAParkingCoordinateYOffsetAngle2[2][APA_CAR_PARK_SIDE_NUM]; // Slot + 1.5m, ~ 1.6 for block the value 400 is too small, the front bumper may hit the block. but for the ISO pole and car, it is ok.
	// Without curb,                   with curb
	// Park at Left,  Park at  Right       Park at Left side,      Park at right side,
	{{-1.0 * PI / 180.0, - 0.5 * PI / 180.0}, {-1.0 * PI / 180.0, -1.0 * PI / 180.0}},
	//-1.5 * PI / 180.0, //- 0.8 * PI / 180.0, // 5deg APA_DISTANCE_TYPE APATrajCalParalAPAParkingCoordinateYOffsetAngle3[2][APA_CAR_PARK_SIDE_NUM]; // Slot + 1.4m, ~ 1.5 actually it mabe slot len + 80cm due to slot tolerance. for block the value 400 is too small, the front bumper may hit the block. but for the ISO pole and car, it is ok.
	// Without curb,                   with curb
	// Park at Left,  Park at  Right       Park at Left side,      Park at right side,
	{{- 1.0 * PI / 180.0, - 1.0 * PI / 180.0}, {-1.5 * PI / 180.0, -1.0 * PI / 180.0}},
	//-2.0 * PI / 180.0, // - 1.5 * PI / 180.0, // 5deg APA_DISTANCE_TYPE APATrajCalParalAPAParkingCoordinateYOffsetAngle4[2][APA_CAR_PARK_SIDE_NUM]; // Slot + 1.3m, ~ 1.4 for block the value 400 is too small, the front bumper may hit the block. but for the ISO pole and car, it is ok.
	// Without curb,                   with curb
	// Park at Left,  Park at  Right       Park at Left side,      Park at right side,
	{{-1.5 * PI / 180.0, - 1.5 * PI / 180.0}, {-2.0 * PI / 180.0, -1.5 * PI / 180.0}},
	//-2.0 * PI / 180.0, // - 2.2 * PI / 180.0, // -2.2deg: left side park, car tail is a little outside offset. APA_DISTANCE_TYPE APATrajCalParalAPAParkingCoordinateYOffsetAngle5[2][APA_CAR_PARK_SIDE_NUM]; // '-': will have a offset into the right side. Slot + 80cm, for block the value 400 is too small, the front bumper may hit the block. but for the ISO pole and car, it is ok.
	// Without curb,                   with curb
	// Park at Left,  Park at  Right       Park at Left side,      Park at right side,
	{{-1.5 * PI / 180.0, - 1.5 * PI / 180.0}, {-2.0 * PI / 180.0, -1.5 * PI / 180.0}},
#elif 0
	{{-0.5 * PI / 180.0, -1.7 * PI / 180.0}, {0 * PI / 180.0, -1.2 * PI / 180.0}},//Slot length > car length + 1.6 m
	//0 * PI / 180.0, //- 0.2 * PI / 180.0, // 5deg APA_DISTANCE_TYPE APATrajCalParalAPAParkingCoordinateYOffsetAngle2[2][APA_CAR_PARK_SIDE_NUM]; // Slot + 1.5m, ~ 1.6 for block the value 400 is too small, the front bumper may hit the block. but for the ISO pole and car, it is ok.
	// Without curb,                   with curb
	// Park at Left,  Park at  Right       Park at Left side,      Park at right side,//Slot length < car length + 1.6 m
	{{-0.5 * PI / 180.0, -1.7 * PI / 180.0}, {0 * PI / 180.0, -1.2 * PI / 180.0}},
	//0 * PI / 180.0, //- 0.8 * PI / 180.0, // 5deg APA_DISTANCE_TYPE APATrajCalParalAPAParkingCoordinateYOffsetAngle3[2][APA_CAR_PARK_SIDE_NUM]; // Slot + 1.4m, ~ 1.5 actually it mabe slot len + 80cm due to slot tolerance. for block the value 400 is too small, the front bumper may hit the block. but for the ISO pole and car, it is ok.
	// Without curb,                   with curb
	// Park at Left,  Park at  Right       Park at Left side,      Park at right side,
	{{-0.5 * PI / 180.0, -1.7 * PI / 180.0}, {0 * PI / 180.0, -1.2 * PI / 180.0}},//Slot length < car length + 1.5 m
	//0 * PI / 180.0, // - 1.5 * PI / 180.0, // 5deg APA_DISTANCE_TYPE APATrajCalParalAPAParkingCoordinateYOffsetAngle4[2][APA_CAR_PARK_SIDE_NUM]; // Slot + 1.3m, ~ 1.4 for block the value 400 is too small, the front bumper may hit the block. but for the ISO pole and car, it is ok.
	// Without curb,                   with curb
	// Park at Left,  Park at  Right       Park at Left side,      Park at right side,//Slot length < car length + 1.4 m
	{{-0.5 * PI / 180.0, -1.7 * PI / 180.0}, {0 * PI / 180.0, -1.2 * PI / 180.0}},
	//0 * PI / 180.0, // - 2.2 * PI / 180.0, // -2.2deg: left side park, car tail is a little outside offset. APA_DISTANCE_TYPE APATrajCalParalAPAParkingCoordinateYOffsetAngle5[2][APA_CAR_PARK_SIDE_NUM]; // '-': will have a offset into the right side. Slot + 80cm, for block the value 400 is too small, the front bumper may hit the block. but for the ISO pole and car, it is ok.
	// Without curb,                   with curb
	// Park at Left,  Park at  Right       Park at Left side,      Park at right side,//Slot length < car length + 1.3 m
	{{-0.5 * PI / 180.0, -1.7 * PI / 180.0}, {0 * PI / 180.0, -1.2 * PI / 180.0}},
#else
	{{0.0 * PI / 180.0, 0.0 * PI / 180.0}, {0 * PI / 180.0, 0.0 * PI / 180.0}},//Slot length > car length + 1.6 m
	//0 * PI / 180.0, //- 0.2 * PI / 180.0, // 5deg APA_ANGLE_TYPE APATrajCalParalAPAParkingCoordinateYOffsetAngle2[2][APA_CAR_PARK_SIDE_NUM]; // Slot + 1.5m, ~ 1.6 for block the value 400 is too small, the front bumper may hit the block. but for the ISO pole and car, it is ok.
	// Without curb,                   with curb
	// Park at Left,  Park at  Right       Park at Left side,      Park at right side,//Slot length < car length + 1.6 m
	{{0.0 * PI / 180.0, 0.0 * PI / 180.0}, {0 * PI / 180.0, 0.0 * PI / 180.0}},
	//0 * PI / 180.0, //- 0.8 * PI / 180.0, // 5deg APA_ANGLE_TYPE APATrajCalParalAPAParkingCoordinateYOffsetAngle3[2][APA_CAR_PARK_SIDE_NUM]; // Slot + 1.4m, ~ 1.5 actually it mabe slot len + 80cm due to slot tolerance. for block the value 400 is too small, the front bumper may hit the block. but for the ISO pole and car, it is ok.
	// Without curb,                   with curb
	// Park at Left,  Park at  Right       Park at Left side,      Park at right side,
	{{0.0 * PI / 180.0, 0.0 * PI / 180.0}, {0 * PI / 180.0, 0.0 * PI / 180.0}},//Slot length < car length + 1.5 m
	//0 * PI / 180.0, // - 1.5 * PI / 180.0, // 5deg APA_ANGLE_TYPE APATrajCalParalAPAParkingCoordinateYOffsetAngle4[2][APA_CAR_PARK_SIDE_NUM]; // Slot + 1.3m, ~ 1.4 for block the value 400 is too small, the front bumper may hit the block. but for the ISO pole and car, it is ok.
	// Without curb,                   with curb
	// Park at Left,  Park at  Right       Park at Left side,      Park at right side,//Slot length < car length + 1.4 m
	{{0.0 * PI / 180.0, 0.0 * PI / 180.0}, {0 * PI / 180.0, 0.0 * PI / 180.0}},
	//0 * PI / 180.0, // - 2.2 * PI / 180.0, // -2.2deg: left side park, car tail is a little outside offset. APA_ANGLE_TYPE APATrajCalParalAPAParkingCoordinateYOffsetAngle5[2][APA_CAR_PARK_SIDE_NUM]; // '-': will have a offset into the right side. Slot + 80cm, for block the value 400 is too small, the front bumper may hit the block. but for the ISO pole and car, it is ok.
	// Without curb,                   with curb
	// Park at Left,  Park at  Right       Park at Left side,      Park at right side,//Slot length < car length + 1.3 m
	{{0.0 * PI / 180.0, 0.0 * PI / 180.0}, {0 * PI / 180.0, 0.0 * PI / 180.0}},

#endif

	300, // 30cm. APA_DISTANCE_TYPE APATrajCalParalMaxCarDriveOffsetDisFromTheEndPosX;
	50, // 5cm. APA_DISTANCE_TYPE APATrajCalParalMinCarDriveOffsetDisFromTheEndPosX;
	25.0 * PI / 180.0, // APA_ANGLE_TYPE APATrajCalParalMaxCarDriveOffsetDisFromTheEndPosXCorrespondCarAng;
	2.0 * PI / 180.0, // 2deg, APA_ANGLE_TYPE APATrajCalParalAllowCarDrvAlongAGivenRadiusOffsetXCalMinCarAng; // 2deg,
	12.0 * PI / 180.0, // 12deg, APA_ANGLE_TYPE APATrajCalParalAllowCarDrvAlongAGivenRadiusOffsetXCalMaxCarAng; // 12deg.
	10, // 1cm. APA_DISTANCE_TYPE APATrajCalParalAllowCarDrvAlongAGivenRadiusOffsetX1; // 1cm./2deg.
	90, // 9cm, APA_DISTANCE_TYPE APATrajCalParalAllowCarDrvAlongAGivenRadiusOffsetX2; // 9cm./12deg.
	

	6.0 * PI / 180.0, // APA_ANGLE_TYPE APATrajCalParalAllowCarDrvAlongAGivenRadiusMinCarAng;
	2,//4, // def: 2 will have only one correction. 4 will have 2 times correction. APA_ENUM_TYPE APATrajCalParalAllowCarDrvAlongAGivenRadiusFwMaxInSlotFwAndBkCnt;
	3, // def: 3 will have only one correction, 7 will have 3 times correction. APA_ENUM_TYPE APATrajCalParalAllowCarDrvAlongAGivenRadiusBkMaxInSlotFwAndBkCnt;
	260, ///APA_DISTANCE_TYPE APATrajCalSafetyDisToObjAtSideOfCar;
	// Left, Right

	200, // 150, // APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetCheckAllowedMaxPtDeltaX1; // 15cm
	100, // APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetCheckAllowedMaxPtDeltaX2; // 10cm
	80, // APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetCheckAllowedMinPtDeltaX; // 8cm
	2500, // APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetCheckAllowedMinDeltaYObj2; // 250cm
	2000, // APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetCheckAllowedMinDeltaYObj1; // 250cm
	0, // APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetCheckCarCenterPtYMin1; // 0
	0, // APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetCheckCarCenterPtYMin2; // 0
	(4.0 * PI / 180.0), // APA_CAL_FLOAT_TYPE APATrajCalCarEndPosXOffsetCheckAllowedMinDelaCarAng; // 3deg
	(15.0 * PI / 180.0), // APA_CAL_FLOAT_TYPE APATrajCalCarEndPosXOffsetCheckAllowedMaxDeltaBdLineAndCarAng; // 28: 88deg
	(4.0 * PI / 180.0), // APA_CAL_FLOAT_TYPE APATrajCalCarEndPosXOffsetCheckAllowedMinDeltaBdLineAndCarAng; // 3.73: 75deg
	{30, 30},// APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetMinXWithAngledObj1WithoutCurb1[APA_CAR_PARK_SIDE_NUM]; // 3cm
	{250, 250}, // APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetMaxXWithAngledObj1WithoutCurb1[APA_CAR_PARK_SIDE_NUM]; // 25cm
	{0, 0}, // APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetMinXWithAngledObj1WithoutCurb2[APA_CAR_PARK_SIDE_NUM]; // 3cm
	{0, 0}, // APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetMaxXWithAngledObj1WithoutCurb2[APA_CAR_PARK_SIDE_NUM]; // 25cm
	{30, 30}, // APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetMinXWithAngledObj2WithoutCurb1[APA_CAR_PARK_SIDE_NUM]; // 3cm
	{200, 200}, // APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetMaxXWithAngledObj2WithoutCurb1[APA_CAR_PARK_SIDE_NUM]; // 20cm
	{0, 0}, // APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetMinXWithAngledObj2WithoutCurb2[APA_CAR_PARK_SIDE_NUM]; // 3cm
	{0, 0}, // APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetMaxXWithAngledObj2WithoutCurb2[APA_CAR_PARK_SIDE_NUM]; // 20cm
	{30, 30}, // APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetMinXWithAngledObj12WithoutCurb1[APA_CAR_PARK_SIDE_NUM]; // 3cm
	{200, 200}, // APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetMaxXWithAngledObj12WithoutCurb1[APA_CAR_PARK_SIDE_NUM]; // 20cm
	{0, 0}, // APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetMinXWithAngledObj12WithoutCurb2[APA_CAR_PARK_SIDE_NUM]; // 3cm
	{0, 0}, // APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetMaxXWithAngledObj12WithoutCurb2[APA_CAR_PARK_SIDE_NUM]; // 20cm

	300, // 30cm,	APA_DISTANCE_TYPE APATrajCalCarEndPosAllowedMinX;
	2500, // def: 2.3m, APA_DISTANCE_TYPE APATrajCalCarEndPosAllowedMaxX;
	1100, // 60cm, APA_DISTANCE_TYPE APATrajCalCarEndPosHitCurbCheckRearBumperOffsetDis;
	-1400, // -120cm, APA_DISTANCE_TYPE APATrajCalCarEndPosHitCurbCheckFrontBumperOffsetDis;
	-200, // -20cm, APA_DISTANCE_TYPE APATrajCalCarEndPosHitCurbCheckCarSideOffsetDis;
	
	{170, 170},//150, // 50mm?? will hit curb, 150mm , def: 200mm APA_DISTANCE_TYPE APATrajCalCarEndPosDisToCurb[APA_CAR_PARK_SIDE_NUM];
	5837, // length of car + 130cm, APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetToObj1AndObj2LineIfNoCurbDtdSlotLen1;
	6137, // length of car + 160cm, APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetToObj1AndObj2LineIfNoCurbDtdSlotLen2;
	//old cal: {100, 100}, //{150, 150},  15cm, APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetToObj1AndObj2LineIfNoCurbDtd1[APA_CAR_PARK_SIDE_NUM]; // 15cm. Big slot len, Slot Len > Car Len + 1.3m.	
	// old cal: {80, 0}, //{200, 200},{150, 150}, // 20cm, APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetToObj1AndObj2LineIfNoCurbDtd2[APA_CAR_PARK_SIDE_NUM]; // 20cm. Small Slot Len, Slot Len = Car Len + 1 ~ 1.3m.
	// old cal: {100, 100}, //{300, 300} 25cm, APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetToObj1AndObj2LineIfNoCurbDtd3[APA_CAR_PARK_SIDE_NUM]; // 25cm. Small slot Len, Slot Len = Car Len  = 0.8m. ~ 1m.	

#if 0	
	// APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetToObj1AndObj2LineIfNoCurbDtdBothObjExist[APA_CAR_PARK_SIDE_NUM][APA_TRAJCAL_COORDINATE_SETUP_ROAD_TYPE_NUM][3][APA_TRAJCAL_COORDINATE_SETUP_OBJ_TYPE_NUM];	
	{
		// Left side
		{
			// APATrajCalCoordinateSetupRoad_Straight = 0,
			{
				// Slot len > car length + 1.6m,
				{
					120, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					120, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					120, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					120, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					120 // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				},
				// Slot Len = car length + 1.3 ~ 1.6m
				{
					120, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					120, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					120, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					120, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					120 // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				},
				// Slot Len < car length + 1.3
				{
					120, // 16cm, 25cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					120, // 16cm, 25cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					120, // 16cm, 25cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					120, // 16cm, 25cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					120 // 16cm, 25cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				}
			},
			// APATrajCalCoordinateSetupRoad_Convex,
			{
				// Slot len > car length + 1.6m,
				{
					120, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					120, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					120, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					120, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					120 // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				},
				// Slot Len = car length + 1.3 ~ 1.6m
				{
					120, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					120, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					120, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					120, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					120 // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				},
				// Slot Len < car length + 1.3
				{
					120, // 16cm, 25cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					120, // 16cm, 25cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					120, // 16cm, 25cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					120, // 16cm, 25cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					120 // 16cm, 25cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				}
			},
					
			// APATrajCalCoordinateSetupRoad_Concave
			{
				// Slot len > car length + 1.6m,
				{
					120, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					120, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					120, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					120, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					120 // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				},
				// Slot Len = car length + 1.3 ~ 1.6m
				{
					120, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					120, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					120, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					120, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					120 // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				},
				// Slot Len < car length + 1.3
				{
					120, // 16cm, 25cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					120, // 16cm, 25cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					120, // 16cm, 25cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					120, // 16cm, 25cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					120 // 16cm, 25cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				}
			}
		},
		// Right side
		{
			// APATrajCalCoordinateSetupRoad_Straight = 0,
			{
				// Slot len > car length + 1.6m,
				{
					120, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					120, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					120, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					120, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					120 // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				},
				// Slot Len = car length + 1.3 ~ 1.6m
				{
					120, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					120, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					120, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					120, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					120 // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				},
				// Slot Len < car length + 1.3
				{
					120, // 17cm, 25cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					120, // 17cm, 25cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					120, // 17cm, 25cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					120, // 17cm, 25cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					120 // 17cm, 25cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				}
			},
			// APATrajCalCoordinateSetupRoad_Convex,
			{
				// Slot len > car length + 1.6m,
				{
					120, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					120, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					120, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					120, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					120 // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				},
				// Slot Len = car length + 1.3 ~ 1.6m
				{
					120, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					120, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					120, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					120, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					120 // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				},
				// Slot Len < car length + 1.3
				{
					120, // 17cm, 25cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					120, // 17cm, 25cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					120, // 17cm, 25cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					120, // 17cm, 25cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					120 // 17cm, 25cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				}
			},
					
			// APATrajCalCoordinateSetupRoad_Concave
			{
				// Slot len > car length + 1.6m,
				{
					120, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					120, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					120, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					120, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					120 // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				},
				// Slot Len = car length + 1.3 ~ 1.6m
				{
					120, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					120, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					120, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					120, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					120 // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				},
				// Slot Len < car length + 1.3
				{
					120, // 17cm, 25cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					120, // 17cm, 25cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					120, // 17cm, 25cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					120, // 17cm, 25cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					120 // 17cm, 25cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				}
			}
		}
	},
#else
	// APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetToObj1AndObj2LineIfNoCurbDtdBothObjExist[APA_CAR_PARK_SIDE_NUM][APA_TRAJCAL_COORDINATE_SETUP_ROAD_TYPE_NUM][3][APA_TRAJCAL_COORDINATE_SETUP_OBJ_TYPE_NUM];	
	{
		// Left side
		{
			// APATrajCalCoordinateSetupRoad_Straight = 0,
			{
				// Slot len > car length + 1.6m,
				{
					0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					0 // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				},
				// Slot Len = car length + 1.3 ~ 1.6m
				{
					0, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					0, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					0, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					0, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					0 // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				},
				// Slot Len < car length + 1.3
				{
					0, // 16cm, 25cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					0, // 16cm, 25cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					0, // 16cm, 25cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					0, // 16cm, 25cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					0 // 16cm, 25cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				}
			},
			// APATrajCalCoordinateSetupRoad_Convex,
			{
				// Slot len > car length + 1.6m,
				{
					0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					0 // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				},
				// Slot Len = car length + 1.3 ~ 1.6m
				{
					0, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					0, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					0, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					0, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					0 // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				},
				// Slot Len < car length + 1.3
				{
					0, // 16cm, 25cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					0, // 16cm, 25cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					0, // 16cm, 25cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					0, // 16cm, 25cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					0 // 16cm, 25cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				}
			},
					
			// APATrajCalCoordinateSetupRoad_Concave
			{
				// Slot len > car length + 1.6m,
				{
					0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					0 // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				},
				// Slot Len = car length + 1.3 ~ 1.6m
				{
					0, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					0, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					0, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					0, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					0 // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				},
				// Slot Len < car length + 1.3
				{
					0, // 16cm, 25cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					0, // 16cm, 25cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					0, // 16cm, 25cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					0, // 16cm, 25cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					0 // 16cm, 25cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				}
			}
		},
		// Right side
		{
			// APATrajCalCoordinateSetupRoad_Straight = 0,
			{
				// Slot len > car length + 1.6m,
				{
					0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					0 // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				},
				// Slot Len = car length + 1.3 ~ 1.6m
				{
					0, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					0, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					0, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					0, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					0 // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				},
				// Slot Len < car length + 1.3
				{
					0, // 17cm, 25cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					0, // 17cm, 25cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					0, // 17cm, 25cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					0, // 17cm, 25cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					0 // 17cm, 25cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				}
			},
			// APATrajCalCoordinateSetupRoad_Convex,
			{
				// Slot len > car length + 1.6m,
				{
					0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					0 // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				},
				// Slot Len = car length + 1.3 ~ 1.6m
				{
					0, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					0, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					0, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					0, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					0 // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				},
				// Slot Len < car length + 1.3
				{
					0, // 17cm, 25cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					0, // 17cm, 25cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					0, // 17cm, 25cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					0, // 17cm, 25cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					0 // 17cm, 25cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				}
			},
					
			// APATrajCalCoordinateSetupRoad_Concave
			{
				// Slot len > car length + 1.6m,
				{
					0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					0 // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				},
				// Slot Len = car length + 1.3 ~ 1.6m
				{
					0, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					0, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					0, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					0, // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					0 // 13cm, 20cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				},
				// Slot Len < car length + 1.3
				{
					0, // 17cm, 25cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
					0, // 17cm, 25cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
					0, // 17cm, 25cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
					0, // 17cm, 25cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
					0 // 17cm, 25cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
				}
			}
		}
	},

#endif

	// APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetToObj1AndObj2LineIfNoCurbDtdObj1Exist[APA_CAR_PARK_SIDE_NUM][APA_TRAJCAL_COORDINATE_SETUP_ROAD_TYPE_NUM][APA_TRAJCAL_COORDINATE_SETUP_OBJ_TYPE_NUM];	
	{
		// Left side
		{
			// APATrajCalCoordinateSetupRoad_Straight = 0,
			{
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
				0 // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
			},
			// APATrajCalCoordinateSetupRoad_Convex,
			{
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
				0 // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
			},
					
			// APATrajCalCoordinateSetupRoad_Concave
			{
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
				0 // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
			}
		},
		// Right side
		{
			// APATrajCalCoordinateSetupRoad_Straight = 0,
			{
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
				0 // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
			},
			// APATrajCalCoordinateSetupRoad_Convex,
			{
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
				0 // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
			},
					
			// APATrajCalCoordinateSetupRoad_Concave
			{
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
				0 // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
			}
		}
	},
	
	// APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetToObj1AndObj2LineIfNoCurbDtdObj2Exist[APA_CAR_PARK_SIDE_NUM][APA_TRAJCAL_COORDINATE_SETUP_ROAD_TYPE_NUM][APA_TRAJCAL_COORDINATE_SETUP_OBJ_TYPE_NUM];	
	{
		// Left side
		{
			// APATrajCalCoordinateSetupRoad_Straight = 0,
			{
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
				0 // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
			},
			// APATrajCalCoordinateSetupRoad_Convex,
			{
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
				0 // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
			},
					
			// APATrajCalCoordinateSetupRoad_Concave
			{
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
				0 // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
			}
		},
		// Right side
		{
			// APATrajCalCoordinateSetupRoad_Straight = 0,
			{
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
				0 // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
			},
			// APATrajCalCoordinateSetupRoad_Convex,
			{
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
				0 // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
			},
					
			// APATrajCalCoordinateSetupRoad_Concave
			{
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_SmallObj = 0,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PerpendicularCar,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_NegAngularCar,
				0, // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_PosAngularCar,
				0 // 9cm, 15cm ?? // APATrajCalCoordinateSetupObj_ParallelCar
			}
		}
	},
	


	0,  // APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetToObj1AndObj2LineIfCurbDtdRCircle;	
	0, // def: -40cm: outsdie 40cm. APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetToObj1AndObj2LineMaxDisIfCurbDtdRCircle;	
	(1.0 / (15.0 * PI / 180.0)), // delta slot start point and end point car angle 15deg: offset 40cm. APA_CAL_FLOAT_TYPE APATrajCalCarEndPosXOffsetToObj1AndObj2LineCalRatioIfCurbDtdRCircle;	
	0, // APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetToObj1AndObj2LineIfCurbDtdLCircle;	
	-200,//0, // def: -40cm: out side 40cm. APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetToObj1AndObj2LineMaxDisIfCurbDtdLCircle;	//2013 03 18
	(1.0 / (15.0 * PI / 180.0)), // delta slot start point and end point car angle 15deg: offset 40cm. APA_CAL_FLOAT_TYPE APATrajCalCarEndPosXOffsetToObj1AndObj2LineCalRatioIfCurbDtdLCircle;	
	0,//7200, // 6.8m APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetFromCurbMinSlotLength;
	1300, // 1.3m: half width of car + 15cm, APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetFromCurbMinEndPosX;
	0.3, // slot depth: 240cm. offset: (240cm - 180cm(width of car)) * 0.3 = 18cm from the Obj1 and obj2 line,  APA_CAL_FLOAT_TYPE APATrajCalCarEndPosXOffsetFromCurbCalFactor;	
	0, // Length of car + 1600, APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetFromCurbSlotDeltaLength; // Length of car + 1600
	50, // 7cm, APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetFromCurbDis1; // Length of car + 1600: 5cm.
	100, // 7cm, APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetFromCurbDis2; // Length of car + 800: 10cm.
	
	10000, // 8.5m, 7500mm, APA_DISTANCE_TYPE APATrajCalMaxSlotLengthForAGivenSlot;	
	12000, // 12m, APA_DISTANCE_TYPE APATrajCalMaxSlotLengthForRegardingObj1Invalid; // 12m.	
	1000, // 100cm for d2sc, // 1500, // 1.5m APA_DISTANCE_CAL_FLOAT_TYPE APATrajCalInsertLineBtStep23Method1MinDeltaRadius; // ;

	2200, // car length + 220cm, APA_DISTANCE_TYPE APATrajCalInsertLineBtStep23Method1RegardedAsBigSlotDeltaLen; // Car length + this value = slot length. 240cm.
	// X, Y
	{70, -100}, // kjy changed to -100 2015 01 10. {70, -200}, //APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method3Step3CenterPtAddDeltaValue;
	{0, 120}, //APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method1Step2CenterPtAddDeltaValueForBigSlot;

	#if 0
	// APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method12With3StepParkingStep3CenterPtAddDeltaValue[2];
	{
		{0, -50},
		{0, -70}
	}, 
	 // APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method12With4StepParkingStep3CenterPtAddDeltaValue[2];
	{
		{60, -100},
		{60, -100}
	},
	// APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method12With5StepParkingStep3CenterPtAddDeltaValue[2];
	{
		{40, -100}, 
		{40, -100} 
	},
	 // APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method12With6StepParkingStep3CenterPtAddDeltaValue[2];
	{
		{140, -100},
		{140, -100}
	},
	//APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method1With3StepParkingStep2CenterPtAddDeltaValue[APA_TRAJCAL_INSERT_LINE_BET_STEP2_3_CIRCLE_METHOD_VALUE_NUM];	
	//{-700, 100}
	{
		{-600, 200},
		{-800, 100},
		{-600, 100},
		{-600, 50}
	},
	//APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method1With4StepParkingStep2CenterPtAddDeltaValue[APA_TRAJCAL_INSERT_LINE_BET_STEP2_3_CIRCLE_METHOD_VALUE_NUM]; 
	//{50, 100}, 
	{
		{-400, 200},
		{-500, 100},
		{-400, 100},
		{-400, 0}
	},
	//APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method1With5StepOr6StepParkingStep2CenterPtAddDeltaValue[APA_TRAJCAL_INSERT_LINE_BET_STEP2_3_CIRCLE_METHOD_VALUE_NUM];
	
	{
		{-400.0, 50.0},
		{-300.0, 50.0},
		{-400.0, 0.0},
		{-300, 0.0}
	},
	#else
	// kjy added 2014 07 04
	// APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method12With3StepParkingStep3CenterPtAddDeltaValue[2];
	{
		{0, 0}, // {0, -30},
		{0, 0} // {0, -40}
	}, 
	 // APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method12With4StepParkingStep3CenterPtAddDeltaValue[2];
	{
		{80, 40}, //kjy changed 2015 04 24 {80, -40}, //{30, -40},
		{80, 0}, //kjy changed 2015 04 24 {80, - 50} //{30, -50}
	},
	// APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method12With5StepParkingStep3CenterPtAddDeltaValue[2];
	{
		//{20, 0}, 
		{20, 100}, //kjy changed 2015 04 24 {20, 50}, {20, 100},// kjy changed to 50 2015 01 10 
		{0, 60}, //kjy changed 2015 04 24 {0, 0} ,{0, 60},
	},
	 // APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method12With6StepParkingStep3CenterPtAddDeltaValue[2];
	{
		//{40, 0},
		{40, 100}, //kjy changed 2015 04 24 {40, 50}, // kjy changed to 50 2015 01 10 
		{20, 60}, //kjy changed 2015 04 24 {20, 0}
	},
	//APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method1With3StepParkingStep2CenterPtAddDeltaValue[APA_TRAJCAL_INSERT_LINE_BET_STEP2_3_CIRCLE_METHOD_VALUE_NUM];	
	//{-700, 100}
	{
		{-800, 50},
		{-600, 50},
		{-400, 50},
		{-400, 0}
	},
	//APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method1With4StepParkingStep2CenterPtAddDeltaValue[APA_TRAJCAL_INSERT_LINE_BET_STEP2_3_CIRCLE_METHOD_VALUE_NUM]; 
	//{50, 100}, 
	{
		{-1000, 50},
		{-800, 50},
		{-600, 10},
		{-100, 30}
	},
	//APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method1With5StepOr6StepParkingStep2CenterPtAddDeltaValue[APA_TRAJCAL_INSERT_LINE_BET_STEP2_3_CIRCLE_METHOD_VALUE_NUM];
	
	{
		{-600.0, 50},
		{-400.0, 50.0},
		{-200.0, 20.0},
		{-100, 50.0}
	},
	#endif
	
	//APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method2With3StepParkingStep2CenterPtAddDeltaValue1[APA_TRAJCAL_INSERT_LINE_BET_STEP2_3_CIRCLE_METHOD_VALUE_NUM];
	//{50, 200},
	{
		{50, 450},
		{50, 400},
		{-150, 300},
		{-50, 300}
	},
	//APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method2With3StepParkingStep2CenterPtAddDeltaValue2[APA_TRAJCAL_INSERT_LINE_BET_STEP2_3_CIRCLE_METHOD_VALUE_NUM];
	//{50, 200},
	{
		{50, 500},
		{50, 400},
		{250, 300},
		{150, 350}
	},
	
	//APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method2With4StepParkingStep2CenterPtAddDeltaValue1[APA_TRAJCAL_INSERT_LINE_BET_STEP2_3_CIRCLE_METHOD_VALUE_NUM];
	//{50, 100},
	{
		{50, 350},
		{50, 300},
		{-150, 200},
		{-50, 200}
	},
	//APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method2With4StepParkingStep2CenterPtAddDeltaValue1[APA_TRAJCAL_INSERT_LINE_BET_STEP2_3_CIRCLE_METHOD_VALUE_NUM];
	//{50, 100},
	{
		{50, 400},
		{50, 300},
		{250, 200},
		{150, 250}
	},
	//APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method2With5StepOr6StepParkingStep2CenterPtAddDeltaValue1[APA_TRAJCAL_INSERT_LINE_BET_STEP2_3_CIRCLE_METHOD_VALUE_NUM];
	//{50, 100},
	{
		{0, 250},
		{0, 200},
		{-200, 100},
		{-100, 100}
	},
	//APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method2With5StepOr6StepParkingStep2CenterPtAddDeltaValue2[APA_TRAJCAL_INSERT_LINE_BET_STEP2_3_CIRCLE_METHOD_VALUE_NUM];
	//{50, 100},
	{
		{0, 300},
		{0, 200},
		{200, 100},
		{100, 150}
	},
		
	350, // 35cm. APA_DISTANCE_TYPE APATrajCalInsertLineBtStep23MaxCarDriveOffsetDisFromTheEndPosX;

	
	800, // 80cm, APA_DISTANCE_TYPE APATrajCalCarParkingAllowLastStepCorMinCarCanDrvDisAfterEndPosAch;
	15.0 * PI / 180.0, // 15deg, APA_ANGLE_TYPE APATrajCalCarParkingLastStepCorStep1SteeringWheelAng1; // X offset < 10cm
	20.0 * PI / 180.0, // 20deg, APA_ANGLE_TYPE APATrajCalCarParkingLastStepCorStep2SteeringWheelAng1; // X offset < 10cm 
	20.0 * PI / 180.0, // 20deg, APA_ANGLE_TYPE APATrajCalCarParkingLastStepCorStep1SteeringWheelAng2;  // X offset 10cm - 25cm
	22.5 * PI / 180.0, // 22.5deg, APA_ANGLE_TYPE APATrajCalCarParkingLastStepCorStep2SteeringWheelAng2;  // X offset 10cm - 25cm
	25.0 * PI / 180.0, // 25deg, APA_ANGLE_TYPE APATrajCalCarParkingLastStepCorStep1SteeringWheelAng3;  // X offset 25cm - 40cm
	25.0 * PI / 180.0, // 25deg, APA_ANGLE_TYPE APATrajCalCarParkingLastStepCorStep2SteeringWheelAng3;  // X offset 25cm - 40cm


	(3.0 * PI / 180.0), // 3deg, APA_ANGLE_TYPE APATrajCalLastStepCarCanDrvMinDevidedCarAng; // 
	180, // 18cm, APA_DISTANCE_TYPE APATrajCalLastStepCarCanDrvMinDevidedDis1; // 18cm.
	300, // 30cm, APA_DISTANCE_TYPE APATrajCalLastStepCarCanDrvMinDevidedDis2; // 30cm.
	1500, // 150cm, APA_DISTANCE_TYPE APATrajCalLastStepCarCanDrvMaxDevidedDis; // 150cm.
	0.25, // 30%, car angle = 1deg, APA_RATIO_TYPE APATrajCalLastStepCarCanDrvDisMinRatio; // Car angle = 1deg: 30% Dis.
	0.5, // 40%, car angle = 6deg, APA_RATIO_TYPE APATrajCalLastStepCarCanDrvDisMaxRatio; // Car angle = 6deg: 40% Dis.
	0.7, // 70%, APA_RATIO_TYPE APATrajCalLastStepCarCanDrvOptimizedDisRatio; // 70% Dis.
	1.0 * PI / 180.0, // 1deg, APA_ANGLE_CAL_FLOAT_TYPE APATrajCalLastStepCarCanDrvDisDevidedCarAngMin; // car angle = 1deg.
	8.0 * PI / 180.0, // 6deg, APA_ANGLE_CAL_FLOAT_TYPE APATrajCalLastStepCarCanDrvDisDevidedCarAngMax; // car angle = 6deg.
	500, // 50cm, APA_DISTANCE_TYPE APATrajCalLastStepCarCanDrvOptimizedMaxDis1; // car angle = 1 deg. 50cm, Dis.
	1000, // 70cm, APA_DISTANCE_TYPE APATrajCalLastStepCarCanDrvOptimizedMaxDis2; // car angle = 8 deg. 70cm, Dis.
	250, // 25cm, APA_DISTANCE_TYPE APATrajCalLastStepCarPosToEndPosMinDis; // 25cm.
	

	500, // 50cm, APA_DISTANCE_TYPE APATrajCalInStep3WithSmallSlotCalCompensateDisAtFront; // 500; // 50cm,
	500, // 50cm, APA_DISTANCE_TYPE APATrajCalInStep3WithSmallSlotCalCompensateDisAtRear; // 500; // 50cm,

/*2.4.10.2 *** Perpendicular****/

	100, // APA_DISTANCE_TYPE APATrajCalPSafetyDisToObjAtRearTurningCar; // when turning the car
	100, // APA_DISTANCE_TYPE APATrajCalPSafetyDisToObjAtFrontTurningCar; // when turning the car 

	5, // UCHAR APATrajCalPWaitForSlotBorderLineCorrectTime1; // vehicle is static: 5 = 5 * 40ms = 200ms.
	2, // UCHAR APATrajCalPWaitForSlotBorderLineCorrectTime2; // vehicle is moving: 2 = 2 * 40ms = 80ms.	

	0, // 100, // 300, 400 	APA_DISTANCE_TYPE APATrajCalPAPAParkingCoordinateYOffsetDis; // for block the value 400 is too small, the front bumper may hit the block. but for the ISO pole and car, it is ok.
	500, // 50cm changed by kjy 2013 11 08, def: 1.5m, APA_DISTANCE_TYPE APATrajCalPAPAParkingCoordinateYSearchBkDis; // x + y , 150cm,
	
	- 300,  //APA_DISTANCE_TYPE APATrajCalPCarEndPosDisToCurb;
	0,    //APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetX;
	//2,   //APA_ENUM_TYPE APATrajCalPCarEndPosition;
	750, // 1000, //750, //, 650, APA_DISTANCE_TYPE APATrajCalPCarEndPositionToObj1Dis;
	750, // 1000, //750, //, 650, APA_DISTANCE_TYPE APATrajCalPCarEndPositionToObj2Dis;

	#ifdef APA_SYSTEM_WITH_10_CH

	#ifdef APA_WITH_NORMAL_CORNER_UPA_SNS_POSITION

	3000, // 3m, APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetToObj1DisSmallSlotMinDeltaX; // 250cm.
	100, // 10cm, APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetToObj1DisForSmallSlot;	// 15cm
	600, // 60cm, APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetToObj1DisSmallSlotMinSideDis;	// 60cm
	1100, // 1m, APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetToObj1DisSmallSlotMaxSideDis; // 100cm
	300, // 20cm, APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetToObj1DisForSmallSlotResetTol;	// 20cm
	
	0, // def: 0cm,  def: 50cm. APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetDisWithObj12;
	0, // def: 0cm,  def: 50cm. APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetDisWithoutObj1;

	1400, // 140cm, APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetDisWithoutObj2DevidedObj1Dis; // 140cm.
	// APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetDisWithoutObj2[2][4];
	{
		{ // car to obj1 dis < 140cm
			//if(Obj2TypeGroupIndex == APA_SLOT_OBJ_TYPE_PER_CAR_WITH_SMALL_FLAT_BIG_WIDTH){
			0, //	Obj2TypeGroupIndex = 0;
			//} else if(Obj2TypeGroupIndex == APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_BIG_RISING_SHAPE){
			0, //	Obj2TypeGroupIndex = 1;
			//} else if(Obj2TypeGroupIndex == APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_VERY_BIG_RISING_SHAPE){
			0, //	Obj2TypeGroupIndex = 2;
			//} else {
				// Small edge.
			0 //	Obj2TypeGroupIndex = 3;
			//}
		
		},
		{// car to obj1 dis > 140cm
			//if(Obj2TypeGroupIndex == APA_SLOT_OBJ_TYPE_PER_CAR_WITH_SMALL_FLAT_BIG_WIDTH){
			0, //	Obj2TypeGroupIndex = 0;
			//} else if(Obj2TypeGroupIndex == APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_BIG_RISING_SHAPE){
			0, //	Obj2TypeGroupIndex = 1;
			//} else if(Obj2TypeGroupIndex == APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_VERY_BIG_RISING_SHAPE){
			0, //	Obj2TypeGroupIndex = 2;
			//} else {
				// Small edge.
			0 //	Obj2TypeGroupIndex = 3;
			//}
		
		}
	},
	1500, //APA_DISTANCE_TYPE APATrajCalPCalCarEndPosXWithMeanValueAllowObj1Obj2MaxOffsetDis;
	350, //APA_DISTANCE_TYPE APATrajCalPCarEndPositionToRearObjDis;
	
	1000, // 2.5m	APA_DISTANCE_TYPE APATrajCalPCarEndPositionStartToCheckRObjMaxDeltaPosX;

	#else

	3000, // 3m, APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetToObj1DisSmallSlotMinDeltaX; // 250cm.
	50, // 10cm, APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetToObj1DisForSmallSlot;	// 15cm
	600, // 60cm, APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetToObj1DisSmallSlotMinSideDis;	// 60cm
	1100, // 1m, APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetToObj1DisSmallSlotMaxSideDis; // 100cm
	300, // 20cm, APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetToObj1DisForSmallSlotResetTol;	// 20cm
	
	0, // def: 0cm,  def: 50cm. APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetDisWithObj12;
	200, // def: 0cm,  def: 50cm. APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetDisWithoutObj1;
	1400, // 140cm, APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetDisWithoutObj2DevidedObj1Dis; // 140cm.
	// APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetDisWithoutObj2[2][4];
	{
		{ // car to obj1 dis < 140cm
			//if(Obj2TypeGroupIndex == APA_SLOT_OBJ_TYPE_PER_CAR_WITH_SMALL_FLAT_BIG_WIDTH){
			200, //	Obj2TypeGroupIndex = 0;
			//} else if(Obj2TypeGroupIndex == APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_BIG_RISING_SHAPE){
			200, //	Obj2TypeGroupIndex = 1;
			//} else if(Obj2TypeGroupIndex == APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_VERY_BIG_RISING_SHAPE){
			200, //	Obj2TypeGroupIndex = 2;
			//} else {
				// Small edge.
			200 //	Obj2TypeGroupIndex = 3;
			//}
		
		},
		{// car to obj1 dis > 140cm
			//if(Obj2TypeGroupIndex == APA_SLOT_OBJ_TYPE_PER_CAR_WITH_SMALL_FLAT_BIG_WIDTH){
			100, //	Obj2TypeGroupIndex = 0;
			//} else if(Obj2TypeGroupIndex == APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_BIG_RISING_SHAPE){
			100, //	Obj2TypeGroupIndex = 1;
			//} else if(Obj2TypeGroupIndex == APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_VERY_BIG_RISING_SHAPE){
			100, //	Obj2TypeGroupIndex = 2;
			//} else {
				// Small edge.
			200 //	Obj2TypeGroupIndex = 3;
			//}
		
		}
	},
	1500, //APA_DISTANCE_TYPE APATrajCalPCalCarEndPosXWithMeanValueAllowObj1Obj2MaxOffsetDis;
	350, //APA_DISTANCE_TYPE APATrajCalPCarEndPositionToRearObjDis;

	2500, // 2.5m d2ub,	APA_DISTANCE_TYPE APATrajCalPCarEndPositionStartToCheckRObjMaxDeltaPosX;
	
	#endif
	
	#else

	// 12ch
	
	3000, // 3m, APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetToObj1DisSmallSlotMinDeltaX; // 250cm.
	50, // 10cm, APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetToObj1DisForSmallSlot;	// 15cm
	600, // 60cm, APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetToObj1DisSmallSlotMinSideDis;	// 60cm
	1100, // 1m, APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetToObj1DisSmallSlotMaxSideDis; // 100cm
	300, // 20cm, APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetToObj1DisForSmallSlotResetTol;	// 20cm
	
	300, // def: 0cm,  def: 50cm. APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetDisWithObj12;
	200, // def: 0cm,  def: 50cm. APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetDisWithoutObj1;
	1400, // 140cm, APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetDisWithoutObj2DevidedObj1Dis; // 140cm.
	// APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetDisWithoutObj2[2][4];
	{
		{ // car to obj1 dis < 140cm
			//if(Obj2TypeGroupIndex == APA_SLOT_OBJ_TYPE_PER_CAR_WITH_SMALL_FLAT_BIG_WIDTH){
			200, //	Obj2TypeGroupIndex = 0;
			//} else if(Obj2TypeGroupIndex == APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_BIG_RISING_SHAPE){
			200, //	Obj2TypeGroupIndex = 1;
			//} else if(Obj2TypeGroupIndex == APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_VERY_BIG_RISING_SHAPE){
			200, //	Obj2TypeGroupIndex = 2;
			//} else {
				// Small edge.
			200 //	Obj2TypeGroupIndex = 3;
			//}
		
		},
		{// car to obj1 dis > 140cm
			//if(Obj2TypeGroupIndex == APA_SLOT_OBJ_TYPE_PER_CAR_WITH_SMALL_FLAT_BIG_WIDTH){
			100, //	Obj2TypeGroupIndex = 0;
			//} else if(Obj2TypeGroupIndex == APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_BIG_RISING_SHAPE){
			100, //	Obj2TypeGroupIndex = 1;
			//} else if(Obj2TypeGroupIndex == APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_VERY_BIG_RISING_SHAPE){
			100, //	Obj2TypeGroupIndex = 2;
			//} else {
				// Small edge.
			200 //	Obj2TypeGroupIndex = 3;
			//}
		
		}
	},
	1500, //APA_DISTANCE_TYPE APATrajCalPCalCarEndPosXWithMeanValueAllowObj1Obj2MaxOffsetDis;
	350, //APA_DISTANCE_TYPE APATrajCalPCarEndPositionToRearObjDis;
	
	2500, // 2.5m	APA_DISTANCE_TYPE APATrajCalPCarEndPositionStartToCheckRObjMaxDeltaPosX;


	#endif
	
	1.0 * PI / 180, //APA_ANGLE_TYPE APATrajCalPCarEndPositionCarAngTol;
	
	0.70 * 35.0 * PI / 180.0, // kjy 2014 08 20 changed to 70%, def: 85% max steering angle APA_ANGLE_TYPE APATrajCalPCarParkingStep3AllowMaxSteeringWheelAngWithTwoCircleBk;	// 85% steering angle.
	0.07 * 35.0 * PI / 180.0, // kjy 2014 08 20 changed to 7%, 12% max steering angle APA_ANGLE_TYPE APATrajCalPCarParkingStep3SteeringWheelAngSearchStepWithTwoCircleBk;	// 85% steering angle.
	3500, //3.5m, APA_DISTANCE_TYPE APATrajCalPCarParkingStep3UseBigSteeringAngMinDeltaXToEndPosDis; // 250cm.

	400, // 40cm, APA_DISTANCE_TYPE APATrajCalPCarParkingOffsetCarEndPositionAllowMaxDeltaY; // 400mm.
	15.0 * PI / 180.0, // 15deg, APA_DISTANCE_TYPE APATrajCalPCarParkingOffsetCarEndPositionAllowMaxDeltaCarAng; // 15deg.
	
	//APA_DISTANCE_TYPE APATrajCalPCarParkingOffsetCarEndPositionYDis1[6];
	{
		//50, 100, 150, 200, 270, 340,
		30, 50, 70, 100, 150, 200
	},
	//APA_DISTANCE_TYPE APATrajCalPCarParkingOffsetCarEndPositionYDis2[6];
	{
		70, 200, 300, 400, 500, 600
	},
	//APA_DISTANCE_TYPE APATrajCalPCarParkingOffsetCarEndPositionYDis3[6];
	{                    // |-> without check hit obj1 or obj2.
		500, 700, 1000, 1300, 1550, 1800
	},
	25, // 2.5cm, changed by kjy 2014 05 17, //50, // 5cm, APA_DISTANCE_TYPE APATrajCalPCarParkingCarEndPositionYDisTol01;
	40, // def: 10cm, offset 100cm from end pos line to calculate traj. APA_DISTANCE_TYPE APATrajCalPCarParkingCarEndPositionYDisTol02;
	100, // def: 15cm, slot length < 3.4m, APA_DISTANCE_TYPE APATrajCalPCarParkingCarEndPositionYDisTol1;
	150, // def: 15cm, slot length > 3.4m, APA_DISTANCE_TYPE APATrajCalPCarParkingCarEndPositionYDisTol10;
	200, // kjy changed to 20cm 2014 12 19. 250,//150, // def: 400cm, APA_DISTANCE_TYPE APATrajCalPCarParkingCarEndPositionYDisTol2;
	100, // APA_DISTANCE_TYPE APATrajCalPCarParkingCarEndPositionYDisTol1WithOnlyOneObj;
	130, // APA_DISTANCE_TYPE APATrajCalPCarParkingCarEndPositionYDisTol2WithOnlyOneObj;
	
	1700, // 170cm, APA_DISTANCE_TYPE APATrajCalPInStep3RegardedAsBigSlotDeltaWidth; // width of car + 170cm
	3.0 * PI / 180.0, // 3deg. APA_ANGLE_TYPE APATrajCalPInStep3UseOneCircleStepCorDeltaCarAngTol1; // 3deg.
	6.0 * PI / 180.0, // 6deg. APA_ANGLE_TYPE APATrajCalPInStep3UseOneCircleStepCorDeltaCarAngTol2; // 6deg.
	10.0 * PI / 180.0, // 10deg. APA_ANGLE_TYPE APATrajCalPInStep3UseOneCircleStepCorDeltaCarAngTol3; // 10deg.
	50, // 5cm, APA_DISTANCE_TYPE APATrajCalPInStep3UseOneCircleStepCorDeltaYTol1; // 5cm.
	75, // 7.5cm, APA_DISTANCE_TYPE APATrajCalPInStep3UseOneCircleStepCorDeltaYTol2; // 7.5cm
	150, // 15cm, APA_DISTANCE_TYPE APATrajCalPInStep3UseOneCircleStepCorDeltaYTol3; // 15cm.
	200, // 20cm, APA_DISTANCE_TYPE APATrajCalPInStep3UseOneCircleStepCorDeltaYTol4; // 20cm.


	1.0 / 3.6, // 1kph, m/s APA_SPEED_TYPE APATrajCalPCarParkingCarEndPositionXDisTolDevidedSpd1; // 1kph
	4.0 / 3.6, // 4kph, m/s APA_SPEED_TYPE APATrajCalPCarParkingCarEndPositionXDisTolDevidedSpd2; // 4kph
	200, // 20cm, APA_DISTANCE_TYPE APATrajCalPCarParkingCarEndPositionXDisTolLowSpd;	// 20cm, @1kph
	600, // 60cm, APA_DISTANCE_TYPE APATrajCalPCarParkingCarEndPositionXDisTolHighSpd;	// 60cm, @4kph 
	-400, //-300, //APA_DISTANCE_TYPE APATrajCalPCarParkingCarEndPositionXDisTol2;
	900, // APA_DISTANCE_TYPE APATrajCalPUseBigEndPosTolMaxDeltaXDis;
	3400, // def: 3928, APA_DISTANCE_TYPE APATrajCalPCarParkingAlongCurbMinSlotDepthRefObject;
	5000, // def: 5m?? APA_DISTANCE_TYPE APATrajCalPMaxSlotLengthForAGivenSlot;
	3600,//3400, // def: 3.2m?? APA_DISTANCE_TYPE APATrajCalPRegardAsBigSlotLength;
	2000, // 2m, APA_DISTANCE_TYPE APATrajCalPStep3CenterPtXOffsetDisFromEndPosXWithNoObj2;
    //MATH_ATAN(((APA_DISTANCE_CAL_FLOAT_TYPE)(APACal.LenBetweenFRAxis)) / APACal.APATrajCalPStep3CenterPtXOffsetDisFromEndPosXWithNoObj2);

	200, // 20cm, APA_DISTANCE_TYPE APATrajCalPStartToCheckIfCarWillHitObj12OffsetDisFromRearBumper; // 20cm,

	300, // APA_DISTANCE_TYPE APATrajCalSafetyDisToObj12AtRearBumper;
	200, // APA_DISTANCE_TYPE APATrajCalPSafetyDisToObj2InStep3TurningCar00; // 8cm,   // Lei 2020.07.19: 80 -> 200
	150, // APA_DISTANCE_TYPE APATrajCalPSafetyDisToObj2InStep3TurningCar0; // 15cm, 
	200, // APA_DISTANCE_TYPE APATrajCalPSafetyDisToObj2InStep3TurningCar1; // 20cm, 
	300, // 30cm, 2014 07 29 changed by kjy to 30cm, 350, // APA_DISTANCE_TYPE APATrajCalPSafetyDisToObj2InStep3TurningCar2; // 35cm,
	50, // 0cm, APA_DISTANCE_TYPE APATrajCalPSafetyDisToObjAtFrontCornerTurningCar;
	300, // def: 30cm, APA_DISTANCE_TYPE APATrajCalPSafetyDisToObjAtCornerTurningCar;

	#ifdef APA_SYSTEM_WITH_10_CH
	
	//APA_DISTANCE_TYPE const APATrajCalPSafetyDisToObjAtCornerTurningCarForStep1[10] = 
	{
				//if(Obj2Type == APA_SLOT_OBJ_TYPE_UNKNOWN){
		400, // 320, 		//	Obj2TypeGroupIndex = 0;
				//} else if(Obj2Type <= APA_SLOT_OBJ_TYPE_SQUARE_OBJ_WITH_FALLING_SHAPE){
		450, // 350,		//	Obj2TypeGroupIndex = 0; small square object, width < 1m, 
				//} else if(Obj2Type <= APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_BIG_RISING_AND_FALLING_SHAPE){
		400, // 300,		//	Obj2TypeGroupIndex = 1; small round object, width < 1m.
				//} else if(Obj2Type <= APA_SLOT_OBJ_TYPE_PER_CAR_WITH_BIG_FLAT_SMALL_WIDTH){ // 10
		450, // 300,		//	Obj2TypeGroupIndex = 2; small per vehicle, width < 1.8m,
				//} else if(Obj2Type <= APA_SLOT_OBJ_TYPE_PER_CAR_WITH_NORMAL_FLAT_NORMAL_WIDTH){//12
		400, // 250,	//	Obj2TypeGroupIndex = 3; normal per vehicle with big or normal rising shape. 1.8 < width < 2.3m.
				//} else if(Obj2Type <= APA_SLOT_OBJ_TYPE_PER_CAR_WITH_BIG_FLAT_NORMAL_WIDTH){ // 13
		400, // 250,		//	Obj2TypeGroupIndex = 4; normal per vehicle with big flat bumper, 1.8 < width < 2.3m.
				//} else if(Obj2Type <= APA_SLOT_OBJ_TYPE_PER_CAR_WITH_SMALL_FLAT_BIG_WIDTH){ // 14.
		400, // 220,	//	Obj2TypeGroupIndex = 5; big per vehicle with big rising shape, big round bumper, width > 2.3m
				//} else if(Obj2Type <= APA_SLOT_OBJ_TYPE_PER_CAR_WITH_NORMAL_FLAT_BIG_WIDTH){// 15
		400, // 250,	//	Obj2TypeGroupIndex = 6; big per vehicle with normal rising shape. normal round bumper, width > 2.3m
				//} else if(Obj2Type <= APA_SLOT_OBJ_TYPE_PER_CAR_WITH_BIG_FLAT_BIG_WIDTH){ // 16
		400, // 350,	//	Obj2TypeGroupIndex = 7; big per vehicle with big flat bumper, width > 2.3m
				//} else {
		400 // 250		//	Obj2TypeGroupIndex = 8; parallel vehicle width > 3.2m.
				//}
	},	

	#else
		// 12ch.
	//APA_DISTANCE_TYPE const APATrajCalPSafetyDisToObjAtCornerTurningCarForStep1[10] = 
	{
				//if(Obj2Type == APA_SLOT_OBJ_TYPE_UNKNOWN){
		400, // 270,		//	Obj2TypeGroupIndex = 0;
				//} else if(Obj2Type <= APA_SLOT_OBJ_TYPE_SQUARE_OBJ_WITH_FALLING_SHAPE){
		450, // 350,		//	Obj2TypeGroupIndex = 0; small square object, width < 1m, 
				//} else if(Obj2Type <= APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_BIG_RISING_AND_FALLING_SHAPE){
		400, // 300,		//	Obj2TypeGroupIndex = 1; small round object, width < 1m.
				//} else if(Obj2Type <= APA_SLOT_OBJ_TYPE_PER_CAR_WITH_BIG_FLAT_SMALL_WIDTH){ // 10
		450, // 300,		//	Obj2TypeGroupIndex = 2; small per vehicle, width < 1.8m,
				//} else if(Obj2Type <= APA_SLOT_OBJ_TYPE_PER_CAR_WITH_NORMAL_FLAT_NORMAL_WIDTH){//12
		400, // 220,  //180, // 220,	//	Obj2TypeGroupIndex = 3; normal per vehicle with big or normal rising shape. 1.8 < width < 2.3m.
				//} else if(Obj2Type <= APA_SLOT_OBJ_TYPE_PER_CAR_WITH_BIG_FLAT_NORMAL_WIDTH){ // 13
		400, // 250,		//	Obj2TypeGroupIndex = 4; normal per vehicle with big flat bumper, 1.8 < width < 2.3m.
				//} else if(Obj2Type <= APA_SLOT_OBJ_TYPE_PER_CAR_WITH_SMALL_FLAT_BIG_WIDTH){ // 14.
		400, // 200,  //150, // 180,	//	Obj2TypeGroupIndex = 5; big per vehicle with big rising shape, big round bumper, width > 2.3m
				//} else if(Obj2Type <= APA_SLOT_OBJ_TYPE_PER_CAR_WITH_NORMAL_FLAT_BIG_WIDTH){// 15
		400, // 250,	//	Obj2TypeGroupIndex = 6; big per vehicle with normal rising shape. normal round bumper, width > 2.3m
				//} else if(Obj2Type <= APA_SLOT_OBJ_TYPE_PER_CAR_WITH_BIG_FLAT_BIG_WIDTH){ // 16
		400, // 350,	//	Obj2TypeGroupIndex = 7; big per vehicle with big flat bumper, width > 2.3m
				//} else {
		400 // 200, // 250		//	Obj2TypeGroupIndex = 8; parallel vehicle width > 3.2m.
				//}
	},	
		
	#endif
	
	450, // kjy changed to 45cm. 300, //APATrajCalPSafetyDisToObjAtCornerTurningCarWithLastOneStepToEndPosLine;
    15.0 * PI / 180.0, //APA_ANGLE_TYPE APATrajCalPCarParkingStep2AllowMinSteeringWheelAng;
	150,   //APA_ANGLE_TYPE APATrajCalPCarParkingStep3CenterPtXSearchingStep;
	
	6000, //APA_DISTANCE_TYPE APATrajCalPCarParkingTrajectoryOuterTurningCircleMaxX1; // Car is located at Ycurc < 0 
	8000, //APA_DISTANCE_TYPE APATrajCalPCarParkingTrajectoryOuterTurningCircleMaxX2; //  Car is located at Ycurc < 0 
	10, // 1cm, APA_DISTANCE_TYPE APATrajCalPSearchSlotCalTrajAllowMaxKeyPointTolDis; // 10 // 1cm,	
	1.0, // APA_DISTANCE_CAL_FLOAT_TYPE APATrajCalPSearchSlotCalTrajStep3CenterPtXMoveRatio; // 1.25	


	// First step bk, the car may hit the obj2, correct parameter.
	- 700, // -70cm, APA_DISTANCE_TYPE APATrajCalPFirstBkStepCorAllowMinCarToObj2XDis; // -70cm.
	1600, // 160cm,  APA_DISTANCE_TYPE APATrajCalPFirstBkStepCorAllowMaxCarToObj2XDis; // (Half of width of car + 70cm) 160cm.
	-500, // -50cm, APA_DISTANCE_TYPE APATrajCalPFirstBkStepCorAllowMinCarToEndPosYDis; // -50cm.
	55.0 * PI / 180.0, // 45deg. APA_ANGLE_TYPE APATrajCalPFirstBkStepCorAllowMaxCarAng; // 55deg.
	1000, //100cm, APA_DISTANCE_TYPE APATrajCalPFirstBkStepCorAllowMaxCarToObj2YDis; // (Half of width of car + 10cm) 100cm.

	5.0 * PI / 180.0, // 2014 07 29 kjy changed to 5deg. def: 10deg APA_ANGLE_TYPE APATrajCalPUseOneStepCorToEndPosAllowMaxCarAng; // 10deg.
	1500, // 1.5m, APA_DISTANCE_TYPE APAParkProcPJustDriveStraightlyBkMaxDisToEndPos; // 1500, 1.5m
	2000, // 2m, APA_DISTANCE_TYPE APATrajCalPUseOneStepCorToEndPosDevidedDisToEndPos1; // 2000m,
	2500, // 2.5m, APA_DISTANCE_TYPE APATrajCalPUseOneStepCorToEndPosDevidedDisToEndPos2; // 2500m,
	3000, // 3m, APA_DISTANCE_TYPE APATrajCalPUseOneStepCorToEndPosDevidedDisToEndPos3; // 300m,

	
	15 * PI / 180, //APA_ANGLE_TYPE APATrajCalPCorrectTrajectoryAllowedMaxSteeringWheelAng;
	500, // 50cm, APA_DISTANCE_TYPE APATrajCalPHitObj2CorEndPosCOffsetDis; // 50cm.

//APA_TRAJCAL_GET_CAR_TURNING_RADIUS_CENTER (APACal.LenBetweenFRAxis, APACal.APATrajCalPCorrectTrajectoryAllowedMaxSteeringWheelAng);
	600, // 60cm APA_DISTANCE_TYPE APATrajCalPMaxCarDriveOffsetDisFromTheEndPosY;
	300, // 30cm APA_DISTANCE_TYPE APATrajCalPMinCarDriveOffsetDisFromTheEndPosY;
	30.0 * PI / 180.0, // 30deg, APA_ANGLE_TYPE APATrajCalPMaxCarDriveOffsetDisFromTheEndPosYCorrespondCarAng;		
	4000, // 4m APA_DISTANCE_TYPE APATrajCalPFirstStepAllowCarDrvMaxFwDisAtSearchingSlot;
	30.0 * PI / 180.0, // 30deg, APA_ANGLE_TYPE APATrajCalPFirstStepAllowCarDrvFwMaxDeltaCarAngAtSearchingSlot;		
	// 5deg, APA_ANGLE_TYPE 	APA_ANGLE_TYPE APATrajCalPAPAParkingCoordinateYOffsetAngle[APA_CAR_PARK_SIDE_NUM]; // - : End Pos Ang turning counter clock wise Offset Ang. +: End pos ang turning clock wise ang.;		
	// Left side,     right side
	#if 0
	{2.0 * PI / 180.0, 2.8 * PI / 180.0},
	#else
	{0.0 * PI / 180.0, 0.0 * PI / 180.0},
	#endif	
	200, // 20cm, APA_DISTANCE_TYPE APATrajCalPCorStepMinDeltaDisX; 
	400, // 40cm, APA_DISTANCE_TYPE APATrajCalPCorStepMinDeltaDisY; 
	350, // 25cm, APA_DISTANCE_TYPE APATrajCalPCorStepMinDeltaDisToEndPosX; // 25cm.

	600, // APA_DISTANCE_TYPE APATrajCalPLastStepCarCanDrvMinDevidedDis; // 30cm.
	2000, // APA_DISTANCE_TYPE APATrajCalPLastStepCarCanDrvMaxDevidedDis; // 150cm.
	0.4, // APA_RATIO_TYPE APATrajCalPLastStepCarCanDrvDisMinRatio; // Car angle = 1deg: 30% Dis.
	0.6, // APA_RATIO_TYPE APATrajCalPLastStepCarCanDrvDisMaxRatio; // Car angle = 8deg: 40% Dis.
	0.8, // APA_RATIO_TYPE APATrajCalPLastStepCarCanDrvOptimizedDisRatio; // 70% Dis.
	1.0 * PI / 180.0, // 1deg, APA_ANGLE_CAL_FLOAT_TYPE APATrajCalPLastStepCarCanDrvDisDevidedCarAngMin; // car angle = 1deg.
	8.0 * PI / 180.0, // 6deg, APA_ANGLE_CAL_FLOAT_TYPE APATrajCalPLastStepCarCanDrvDisDevidedCarAngMax; // car angle = 6deg.
	500, // 50cm, APA_DISTANCE_TYPE APATrajCalPLastStepCarCanDrvOptimizedMaxDis1; // car angle = 1 deg. 50cm, Dis.
	1500, // 70cm, APA_DISTANCE_TYPE APATrajCalPLastStepCarCanDrvOptimizedMaxDis2; // car angle = 6 deg. 70cm, Dis.
	1.0 * PI / 180.0, // 1deg, APA_ANGLE_CAL_FLOAT_TYPE APATrajCalPLastStepAllowedSteeringAngDevidedCarAngMin; // car angle = 1deg.
	15.0 * PI / 180.0, // 6deg, APA_ANGLE_CAL_FLOAT_TYPE APATrajCalPLastStepAllowedSteeringAngDevidedCarAngMax; // car angle = 15deg.
	0.50 * 35.0 * PI / 180.0, // 0.5 * Max Steering angle. , // APA_ANGLE_CAL_FLOAT_TYPE APATrajCalPLastStepAllowedSteeringAngMax1; // 50% car angle = 1deg.
	0.90 * 35.0 * PI / 180.0, // 0.9 * Max Steering angle. APA_ANGLE_CAL_FLOAT_TYPE APATrajCalPLastStepAllowedSteeringAngMax2; // 95% car angle = 15deg.
		
	5.0 * PI / 180.0, // 5deg. APA_ANGLE_TYPE APATrajCalPCorStepNotCheckCarHitObj12MaxDeltaCarAng;

	500, // 50cm, APA_DISTANCE_TYPE APATrajCalPCorStepExtendedLastCircleMinDeltaDisToEndPosX1; // 50cm.
	0.1 * 35.0 * PI / 180.0, // 0.1 * Max Steering angle. APA_ANGLE_TYPE APATrajCalPCorStepExtendedLastCircleSteeringAngSearchStep; // 10% steering angle.
	0.3 * 35.0 * PI / 180.0, // 0.3 * Max Steering angle. APA_ANGLE_TYPE APATrajCalPCorStepExtendedLastCircleMinSteeringAng; // 30% steering angle.
	
	0.3 * 35.0 * PI / 180.0, // 0.3 * Max Steering angle. APA_ANGLE_TYPE APATrajCalPCorStepInsertLineBetweenTwoCircleMinSteeringAng;
	0.7 * 35.0 * PI / 180.0, // 0.7 * Max Steering angle. APA_ANGLE_TYPE APATrajCalPCorStepInsertLineBetweenTwoCircleUseMinDeltaDisMaxSteeringAng;

	600, // 60cm,	APA_DISTANCE_TYPE APATrajCalPCorStepMoveLastStepCircleMinDeltaDisToEndPos1; // 60cm, 	
	3500, // 350cm,	APA_DISTANCE_TYPE APATrajCalPCorStepMoveLastStepCircleMinDeltaDisToEndPos2; // 350cm, 	
	450, // 45cm, APA_DISTANCE_TYPE APATrajCalPCorStepMoveLastStepCircleMinDisBtwTwoKeyPoint; // 45cm, 	

	// APA_DISTANCE_TYPE APATrajCalPCorStepMoveLastStepCircleDeltaDisDevidedSeg[4]; 
	{ 800, 1100, 1400, 1800},
 	// APA_DISTANCE_TYPE APATrajCalPCorStepMoveLastStepCircleDeltaDisCarDrvBk1[3][5]; 
	{   //80cm, 110cm, 140cm, 180cm,
		//{250,   300,  350,   400,   450},
		//{220,   250,  300,   350,   400},
		{130,   150,  170,   200,   220},
		{100,   120,  150,   180,   200},
		{70,   80,  100,   120,   150}
	},
	// APA_DISTANCE_TYPE APATrajCalPCorStepMoveLastStepCircleDeltaDisCarDrvFw1[3]; 
	{
		450, 350, 300
	},
	//APA_DISTANCE_TYPE APATrajCalPCorStepMoveLastStepCircleDeltaDisCarDrvFw2[3]; 
	{
		400, 300, 200
	},
	- 4600, // APA_DISTANCE_TYPE APATrajCalPCarCanParkIntoSlotMaxSubLaneObjX1; // Slot Len: > width of car + 80cm, < 1.2m
	- 4300, // APA_DISTANCE_TYPE APATrajCalPCarCanParkIntoSlotMaxSubLaneObjX2; // Slot Len: > width of car + 120cm. < 1.6m
	- 4000, // APA_DISTANCE_TYPE APATrajCalPCarCanParkIntoSlotMaxSubLaneObjX3; // Slot Len: > width of car + 160cm. < 2m
	- 3900, // APA_DISTANCE_TYPE APATrajCalPCarCanParkIntoSlotMaxSubLaneObjXWithoutObj1; 
	- 3500, // APA_DISTANCE_TYPE APATrajCalPCarCanParkIntoSlotMaxSubLaneObjXWithoutObj2; 
	
	2.0 * 2.0, // def: 2.0: delta car pos and end pos line.y = 20cm -> Slot length one side should > 40cm. APA_CAL_FLOAT_TYPE APATrajCalPOptimalCircleCrossToEndPosLineDeltaDis1Ratio1;

	-1000, // -1m, APA_DISTANCE_CAL_FLOAT_TYPE APATrajCalPOptimalCircleCrossToEndPosLineDeltaDis3; // -1m,

	5.0 * PI / 180.0, // 5deg, APA_ANGLE_TYPE APATrajCalPTwoCirclesToEndPosCorDeltaCarAng1; // 5deg
	10.0 * PI / 180.0, // 10deg,APA_ANGLE_TYPE APATrajCalPTwoCirclesToEndPosCorDeltaCarAng2; // 10deg
	20.0 * PI / 180.0, // 20deg,APA_ANGLE_TYPE APATrajCalPTwoCirclesToEndPosCorDeltaCarAng3; // 20deg
	45.0 * PI / 180.0, // 20deg,APA_ANGLE_TYPE APATrajCalPTwoCirclesToEndPosCorDeltaCarAng4; // 35deg
	200, // 20cm, APA_DISTANCE_TYPE APATrajCalPTwoCirclesToEndPosCorDeltaY1; // 20cm,
	400, // 40cm, APA_DISTANCE_TYPE APATrajCalPTwoCirclesToEndPosCorDeltaY2; // 40cm,
	600, // 60cm, APA_DISTANCE_TYPE APATrajCalPTwoCirclesToEndPosCorDeltaY3; // 60cm,
	800, // 80cm, APA_DISTANCE_TYPE APATrajCalPTwoCirclesToEndPosCorDeltaY4; // 80cm,

	2500, // 2.5s, APA_MS_TIME_TYPE APATrajCalPInStep3UseTwoCircleCorMethod0UseBigCurSteeringAngTimeToEndPos;
	0.07, // 25%,  APA_RATIO_TYPE APATrajCalPInStep3UseTwoCircleCorMethod0UseCurSteeringAngUperRatio1;
	0.5, // 50%, APA_RATIO_TYPE APATrajCalPInStep3UseTwoCircleCorMethod0UseCurSteeringAngLowerRatio1;
	0.25, // 25% delta angle. APA_RATIO_TYPE APATrajCalPInStep3UseTwoCircleCorMethod0UseDeltaSteeringAngRatio1; // 0.25
	0.07, // 25%, APA_RATIO_TYPE APATrajCalPInStep3UseTwoCircleCorMethod0UseCurSteeringAngUperRatio2;
	1.0 , // 100%, APA_RATIO_TYPE APATrajCalPInStep3UseTwoCircleCorMethod0UseCurSteeringAngLowerRatio2;
	0.5, // 50% delta angle. APA_RATIO_TYPE APATrajCalPInStep3UseTwoCircleCorMethod0UseDeltaSteeringAngRatio2; // 0.5
	// APA_RATIO_TYPE APATrajCalPInStep3UseTwoCircleCorMethod0AddToCurSteeringAngRatio[3];
	{
		0.10, // delta car angle: 5 ~ 10deg.
		0.16, // delta car angle: 10 ~ 20deg.
		0.22, // delta car angle: 20 ~ deg.
	},
	
	// Percentage of max steering angle:
	// 0 - 0% steering angle.
	// 50 - 50% steering angle.
	// 75 - 75% steering angle.
	// 100 - 100% steering angle.

	60, // UCHAR APACalPInStep3OptimalSteeringAngPercentageWithFwTwoCircleCorMethod0; // when the car is out of slot and car angle is big, delta car pos Y is less than 60cm.

	1200, // 120cm. APA_DISTANCE_TYPE APACalPInStep3OptimalSteeringAngPercentageWithTwoCircleCorMayHitObj2MinDeltaY; // 120cm.

	80, // UCHAR APACalPInStep3OptimalSteeringAngPercentageWithTwoCircleCorMayHitObj2;

	//UCHAR APACalPInStep3OptimalSteeringAngPercentageWithTwoCircleCorMethod0[4][4][4] = 
	{
		//                                                                  |  |  |
		//                                                                  |  |  CarPosX to end pos.x dis
		//                                                                  |  CarPosY to end pos line dis
		//                                                                  Delta CarAng and end pos angle
		// 0 ~ 5 deg.
		// DeltaCarAngIndex = 0;
		{
			// 0 ~ 20cm.
			// DeltaYIndex = 0;
			{
				// CarPosXIndex == 0
				// car to end pos.x < 1.5m
				42, // 50, // 75,

				// CarPosXIndex == 1
				// car to end pos.x > 1.5m and < 3m
				38,//45, //50,

				// CarPosXIndex == 2
				// car to end pos.x > 3m and < 4.5m
				30,

				// CarPosXIndex == 4
				// Out of slot.
				20

			},
			// 20 ~ 40cm.
			// DeltaYIndex = 1;
			{
				// CarPosXIndex == 0
				// car to end pos.x < 1.5m
				0, // N.A

				// CarPosXIndex == 1
				// car to end pos.x > 1.5m and < 3m
				70, // 2014 07 28 kjy changed to 70. 75,

				// CarPosXIndex == 2
				// car to end pos.x > 3m and < 4.5m
				45,// 2014 07 28 kjy changed to 45. 55,//60, //65,

				// CarPosXIndex == 4
				// Out of slot.
				40//50
			},
			// 40 ~ 60cm.
			// DeltaYIndex = 2;
			{
				// CarPosXIndex == 0
				// car to end pos.x < 1.5m
				0, // N.A

				// CarPosXIndex == 1
				// car to end pos.x > 1.5m and < 3m
				85, // N.A

				// CarPosXIndex == 2
				// car to end pos.x > 3m and < 4.5m
				70, // 2014 07 28 kjy changed to 70. 75,

				// CarPosXIndex == 4
				// Out of slot.
				50 // 60
			},
			// > 60cm.
			// DeltaYIndex = 3;
			{
				// CarPosXIndex == 0
				// car to end pos.x < 1.5m
				95, // N.A		// Lei 2020.08.14: 0 -> 95

				// CarPosXIndex == 1
				// car to end pos.x > 1.5m and < 3m	// Lei 2020.08.14: 85 -> 90
				90, // N.A

				// CarPosXIndex == 2
				// car to end pos.x > 3m and < 4.5m
				85,

				// CarPosXIndex == 4
				// Out of slot.
				60 // 70 // 75

			},
		},

		// 5 ~ 10 deg.
		// DeltaCarAngIndex = 1;
		{
			// 0 ~ 20cm.
			// DeltaYIndex = 0;
			{
				// CarPosXIndex == 0
				// car to end pos.x < 1.5m
				42, //50, // 60, // 85,

				// CarPosXIndex == 1
				// car to end pos.x > 1.5m and < 3m
				40, //45, //55, // 65,

				// CarPosXIndex == 2
				// car to end pos.x > 3m and < 4.5m
				37, // 40,//50, // Partially N.A.

				// CarPosXIndex == 4
				// Out of slot.
				30//50, // Partially N.A.
			},

			// 20 ~ 40cm.
			// DeltaYIndex = 1;
			{
				// CarPosXIndex == 0
				// car to end pos.x < 1.5m
				85,

				// CarPosXIndex == 1
				// car to end pos.x > 1.5m and < 3m
				60, // 2014 07 28 kjy changed to 60. 75,
				// CarPosXIndex == 2
				// car to end pos.x > 3m and < 4.5m
				45, // 2014 07 28 kjy changed to 45. 55,//60,

				// CarPosXIndex == 4
				// Out of slot.
				40//50,

			},

			// 40 ~ 60cm.
			// DeltaYIndex = 2;
			{
				// CarPosXIndex == 0
				// car to end pos.x < 1.5m
				0, // N.A

				// CarPosXIndex == 1
				// car to end pos.x > 1.5m and < 3m
				70, // 2014 07 28 kjy changed to 70. 85,

				// CarPosXIndex == 2
				// car to end pos.x > 3m and < 4.5m
				60, // 2014 07 28 kjy changed to 70. 70,

				// CarPosXIndex == 4
				// Out of slot.
				50,

			},
			// > 60cm.
			// DeltaYIndex = 3;
			{
				// CarPosXIndex == 0
				// car to end pos.x < 1.5m
				0, // N.A

				// CarPosXIndex == 1
				// car to end pos.x > 1.5m and < 3m
				85, // N.A
				// CarPosXIndex == 2
				// car to end pos.x > 3m and < 4.5m
				80, // 2014 07 28 kjy changed to 80. 85,
				// CarPosXIndex == 4
				// Out of slot.
				60 // 65//75
			},
		},

		// 10 ~ 20 deg.
		// DeltaCarAngIndex = 2;
		{
			// 0 ~ 20cm.
			// DeltaYIndex = 0;
			{
				// CarPosXIndex == 0
				// car to end pos.x < 1.5m
				70, // N.A

				// CarPosXIndex == 1
				// car to end pos.x > 1.5m and < 3m
				60, // N.A

				// CarPosXIndex == 2
				// car to end pos.x > 3m and < 4.5m
				45, // 2014 07 28 kjy changed to 45. 55,//60, // N.A

				// CarPosXIndex == 4
				// Out of slot.
				40//50 // N.A
			},
			// 20 ~ 40cm.
			// DeltaYIndex = 1;
			{
				// CarPosXIndex == 0
				// car to end pos.x < 1.5m
				0,

				// CarPosXIndex == 1
				// car to end pos.x > 1.5m and < 3m
				75,
				// CarPosXIndex == 2
				// car to end pos.x > 3m and < 4.5m
				45, // 2014 07 28 kjy changed to 45. 55,//60,
				// CarPosXIndex == 4
				// Out of slot.
				40//50,
			},
			// 40 ~ 60cm.
			// DeltaYIndex = 2;
			{
				// CarPosXIndex == 0
				// car to end pos.x < 1.5m
				0, // N.A

				// CarPosXIndex == 1
				// car to end pos.x > 1.5m and < 3m
				70, // 80,kjy changed to 70 2014 07 28
				// CarPosXIndex == 2
				// car to end pos.x > 3m and < 4.5m
				45, //70, kjy changed to 45 2014 07 28
				// CarPosXIndex == 4
				// Out of slot.
				40 // 60
			},
			// > 60cm.
			// DeltaYIndex = 3;
			{
				// CarPosXIndex == 0
				// car to end pos.x < 1.5m
				0, // N.A

				// CarPosXIndex == 1
				// car to end pos.x > 1.5m and < 3m
				85,
				// CarPosXIndex == 2
				// car to end pos.x > 3m and < 4.5m
				70, // 2014 07 28 kjy changed to 70. 75,
				// CarPosXIndex == 4
				// Out of slot.
				50 // 55 // 2014 07 28 kjy changed to 55. 65
			},
		}, 
		
		// > 20 deg.
		// DeltaCarAngIndex = 3;
		{
			// 0 ~ 20cm.
			// DeltaYIndex = 0;
			{
				// CarPosXIndex == 0
				// car to end pos.x < 1.5m
				60, // N.A

				// CarPosXIndex == 1
				// car to end pos.x > 1.5m and < 3m
				70, // N.A

				// CarPosXIndex == 2
				// car to end pos.x > 3m and < 4.5m
				55, // 2014 07 28 kjy changed to 55. 70,//60, // N.A

				// CarPosXIndex == 4
				// Out of slot.
				80, //2014 11 11 kjy changed to 80, //50 // 55, // 2014 07 28 kjy changed to 55. 80, // 65
			},
			// 20 ~ 40cm.
			// DeltaYIndex = 1;
			{
				// CarPosXIndex == 0
				// car to end pos.x < 1.5m
				0,

				// CarPosXIndex == 1
				// car to end pos.x > 1.5m and < 3m
				70,
				// CarPosXIndex == 2
				// car to end pos.x > 3m and < 4.5m
				55, // 2014 07 28 kjy changed to 55. 70,//60,
				// CarPosXIndex == 4
				// Out of slot.
				80, //2014 11 11 kjy changed to 80, // // 50, // 2014 07 28 kjy changed to 50. 80, //40//50,
			},
			// 40 ~ 60cm.
			// DeltaYIndex = 2;
			{
				// CarPosXIndex == 0
				// car to end pos.x < 1.5m
				0, // N.A

				// CarPosXIndex == 1
				// car to end pos.x > 1.5m and < 3m
				75,
				// CarPosXIndex == 2
				// car to end pos.x > 3m and < 4.5m
				60, // 2014 07 28 kjy changed to 60. 75,
				// CarPosXIndex == 4
				// Out of slot.
				80, //2014 11 11 kjy changed to 80, //50, // 2014 07 28 kjy changed to 50. 80, //60
			},
			// > 60cm.
			// DeltaYIndex = 3;
			{
				// CarPosXIndex == 0
				// car to end pos.x < 1.5m
				60, // N.A						// Lei 2020.08.17: 0 -> 60

				// CarPosXIndex == 1
				// car to end pos.x > 1.5m and < 3m
				85,
				// CarPosXIndex == 2
				// car to end pos.x > 3m and < 4.5m
				65, // 2014 07 28 kjy changed to 65.75,
				// CarPosXIndex == 4
				// Out of slot.
				80 //2014 11 11 kjy changed to 80, // 50 // 55, // 2014 07 28 kjy changed to 55. 80, // 65
			},
		}
	},

	1500, // 1.5s, APA_MS_TIME_TYPE APATrajCalPInStep3UseOneCircleCorMethod0UseBigCurSteeringAngTimeToEndPos; // 1.5s
	5.0 * PI / 180.0, // 5deg, APA_ANGLE_TYPE APATrajCalPInStep3UseOneCircleCorMethod0UseBigCurSteeringAngMinCarAng; // 5deg.
	200, // 20cm, APA_DISTANCE_TYPE APATrajCalPInStep3UseOneCircleCorMethod0UseBigCurSteeringAngMinDeltaDisY; // 20cm

	// APA_ANGLE_TYPE APACalPInStep3OptimalSteeringAngDevidedCarAngWithOneCircleCorMethod0[APA_CALP_INSTEP3_OPTIMAL_STEERING_ANGLE_DEVIDED_NUM];
	{1.0 * PI / 180.0, 2.0 * PI / 180.0, 3.5 * PI / 180.0, 5.0 * PI / 180.0, (10.0 * PI / 180.0), (15.0 * PI / 180.0), 20.0 * PI / 180.0},
	//APA_DISTANCE_TYPE APACalPInStep3OptimalSteeringAngDevideCarPosXLineWithOneCircleCorMethod0[APA_CALP_INSTEP3_OPTIMAL_STEERING_ANGLE_CAR_TO_END_POS_DIS_DEVIDED_NUM];
	{300, 550, 800, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000},
	//UCHAR APACalPInStep3OptimalSteeringAngPercentageWithOneCircleCorMethod0[APA_CALP_INSTEP3_OPTIMAL_STEERING_ANGLE_DEVIDED_NUM + 1][APA_CALP_INSTEP3_OPTIMAL_STEERING_ANGLE_CAR_TO_END_POS_DIS_DEVIDED_NUM + 1];
		//                                                                  |  |
		//                                                                  |  CarPosX to end pos.x dis
		//                                                                  |  
		//                                                                  Delta CarAng and end pos angle
	{
		// 0 ~ 1.0 deg.
		{
			35, // 0 ~ 30cm,
			20, //25, // 30 ~ 55cm,
			12,//15, // 55 ~ 80cm,
			8, //10, // 80 ~ 150cm,
			5, // 150cm ~ 200cm,
			4, // 200cm ~ 250cm,
			4, // 250cm ~ 300cm,
			3, // 300cm ~ 350cm,
			3, // 350cm ~ 400cm,
			3, // 400cm ~ 450cm,
			2, // 450cm ~ 500cm,
			2, // 500cm ~ 550cm,
			2, // 550cm ~ 600cm,
			2 // 600cm ~ ,
		},
		// 1.0 ~ 2.0 deg.
		{
			50, // 0 ~ 30cm,
			45, // 30 ~ 55cm,
			35, // 55 ~ 80cm,
			25, // 80 ~ 150cm
			20, // 150cm ~ 200cm,
			15, // 200cm ~ 250cm,
			10, // 250cm ~ 300cm,
			10, // 300cm ~ 350cm,
			10, // 350cm ~ 400cm,
			10, // 400cm ~ 450cm,
			10, // 450cm ~ 500cm,
			10, // 500cm ~ 550cm,
			10, // 550cm ~ 600cm,
			10 // 600cm ~ ,
		},
		// 2.0 ~ 3.5 deg.
		{
			50, // 0 ~ 30cm,
			50, // 30 ~ 55cm,
			45, // 55 ~ 80cm,
			35, // 80 ~ 150cm
			30, // 150cm ~ 200cm,
			30, // 200cm ~ 250cm,
			25, // 250cm ~ 300cm,
			25, // 300cm ~ 350cm,
			20, // 350cm ~ 400cm,
			20, // 400cm ~ 450cm,
			15, // 450cm ~ 500cm,
			15, // 500cm ~ 550cm,
			15, // 550cm ~ 600cm,
			15 // 600cm ~ ,
		},
		// 3.5 ~ 5 deg.
		{
			80, // 0 ~ 30cm,
			70, // 30 ~ 55cm,
			60, // 55 ~ 80cm,
			45, // 80 ~ 150cm
			35, // 150cm ~ 200cm,
			30, // 200cm ~ 250cm,
			30, // 250cm ~ 300cm,
			30, // 300cm ~ 350cm,
			25, // 350cm ~ 400cm,
			25, // 400cm ~ 450cm,
			20, // 450cm ~ 500cm,
			20, // 500cm ~ 550cm,
			20, // 550cm ~ 600cm,
			20 // 600cm ~ ,
		},
		// 5 ~ 10 deg.
		{
			90, // 0 ~ 30cm,
			80, // 30 ~ 55cm,
			65, // 55 ~ 80cm,
			55, // 80 ~ 150cm
			50, // 150cm ~ 200cm,
			50, // 200cm ~ 250cm,
			45, // 250cm ~ 300cm,
			45, // 300cm ~ 350cm,
			45, // 350cm ~ 400cm,
			45, // 400cm ~ 450cm,
			45, // 450cm ~ 500cm,
			40, // 500cm ~ 550cm,
			40, // 550cm ~ 600cm,
			40 // 600cm ~ ,
		},
		// 10 ~ 15 deg.
		{
			90, // 0 ~ 30cm,
			85, // 30 ~ 55cm,
			80, // 55 ~ 80cm,
			80, // 80 ~ 150cm
			75, // 2014 07 28 kjy changed fom 80 to 75. 80, // 150cm ~ 200cm,
			60, // 2014 07 28 kjy changed fom 80 to 60. 80, // 200cm ~ 250cm,
			50, // 2014 07 28 kjy changed fom 75 to 50. 75, // 250cm ~ 300cm,
			50, // 2014 07 28 kjy changed fom 75 to 50. 75, // 300cm ~ 350cm,
			50, // 2014 07 28 kjy changed fom 70 to 50. 70, // 350cm ~ 400cm,
			50, // 2014 07 28 kjy changed fom 70 to 50. 70, // 400cm ~ 450cm,
			45, // 2014 07 28 kjy changed fom 65 to 45. 65, // 450cm ~ 500cm,
			45, // 2014 07 28 kjy changed fom 60 to 45. 60, // 500cm ~ 550cm,
			45, // 2014 07 28 kjy changed fom 50 to 45. 50, // 550cm ~ 600cm,
			45 // 600cm ~ ,
		},
		// 15 ~ 20 deg.
		{
			90, // 0 ~ 30cm,
			85, // 30 ~ 55cm,
			85, // 55 ~ 80cm,
			85, // 80 ~ 150cm
			80, // 150cm ~ 200cm,
			75, // 2014 07 28 kjy changed fom 80 to 75. 80, // 200cm ~ 250cm,
			65, // 2014 07 28 kjy changed fom 80 to 65. 80, // 250cm ~ 300cm,
			65, // 2014 07 28 kjy changed fom 80 to 65. 80, // 300cm ~ 350cm,
			60, // 2014 07 28 kjy changed fom 75 to 60. 75, // 350cm ~ 400cm,
			55, // 2014 07 28 kjy changed fom 75 to 55. 75, // 400cm ~ 450cm,
			55, // 2014 07 28 kjy changed fom 65 to 55. 65, // 450cm ~ 500cm,
			50, // 2014 07 28 kjy changed fom 60 to 50. 60, // 500cm ~ 550cm,
			50, // 550cm ~ 600cm,
			45 // 600cm ~ ,
		},
		// 20 ~  deg.
		{
			90, // 0 ~ 30cm,
			85, // 30 ~ 55cm,
			85, // 55 ~ 80cm,
			85, // 80 ~ 150cm
			85, // 150cm ~ 200cm,
			80, // 2014 07 28 kjy changed fom 85 to 80. 85, // 200cm ~ 250cm,
			75, // 2014 07 28 kjy changed fom 80 to 75. 80, // 250cm ~ 300cm,
			70, // 2014 07 28 kjy changed fom 80 to 70. 80, // 300cm ~ 350cm,
			65, // 2014 07 28 kjy changed fom 80 to 65. 80, // 350cm ~ 400cm,
			65, // 2014 07 28 kjy changed fom 80 to 65. 80, // 400cm ~ 450cm,
			60, // 2014 07 28 kjy changed fom 75 to 65. 75, // 450cm ~ 500cm,
			60, // 2014 07 28 kjy changed fom 70 to 60. 70, // 500cm ~ 550cm,
			50, // 550cm ~ 600cm,
			50 // 600cm ~ ,
		},
	},

	// APA_DISTANCE_TYPE APATrajCalPInStep3OutOfSlotCarDriveForwardStraightlyDeltaDis[5];
	{
		// 3 ~ 4m, 4 ~ 4.5m, 4.5m ~ 5m, 5 ~ 5.5m, 5.5m ~
		// 1200,      900,      600,       400,      300,
		1200,      1000,      800,      700,     600
	},

	(0.50 * 35.0 * PI / 180.0), // 45 % max steering angle. APA_ANGLE_TYPE APACalPInStep3EndPosAngleAlmostAchievedCalWithMediumSteeringAngle;

	1000, // 70cm, APA_DISTANCE_TYPE APACal.APATrajCalPUseSmallCirclesToEndPosCorMinDeltaX; // 70cm
	0.2, // APA_RATIO_TYPE APATrajCalPUseSmallCirclesToEndPosCorYOffsetRatio; // 0.2.
	50, // 5cm, APA_DISTANCE_TYPE APACal.APATrajCalPUseSmallCirclesToEndPosCorMinDeltaY; // 5cm.
	350, // 25cm, APA_DISTANCE_TYPE APACal.APATrajCalPUseSmallCirclesToEndPosCorMaxDeltaY; // 20cm.
	0.45 / (350.0 - 50.0), // 0.4 / (APATrajCalPUseSmallCirclesToEndPosCorMaxDeltaY - APATrajCalPUseSmallCirclesToEndPosCorMinDeltaY), APA_RATIO_TYPE APACal.APATrajCalPUseSmallCirclesToEndPosCorRatio; // 0.4 / (250.0 - 50.0)
	(0.80 * 35.0 * PI / 180.0), // APA_ANGLE_TYPE APACal.APATrajCalPUseSmallCirclesToEndPosCorMaxSteeringAng; // 0.85 * Max steering angle.	
	300, // 30cm. APA_DISTANCE_TYPE APATrajCalPUseSmallCirclesToEndPosCorMinOneStepDis; // 30cm.
			
/*2.4.10.3 *** Park Exit****/
	300,  //APA_DISTANCE_TYPE APATrajCalPEDrivingBackwardsDeltaDisBetweenFrontAndRear;
	350,//APA_DISTANCE_TYPE APATrajCalPEDrivingBackwardsMinRearDis;
	0,    //APA_DISTANCE_TYPE APATrajCalPECarPosXOffsetDisAtSetupSystemCoordinate;
	-2008,//APA_DISTANCE_TYPE APATrajCalPECarEndPosXWithoutObjectAtParkingOutSide;
	-3450, // -(APACal.HalfWidthOfCar + 2500), It should great than APASlotPESlotCheckStartDelayTime APA_DISTANCE_TYPE APATrajCalPEMinCarEndPosCoordinateXWithoutObjAtSide;APA_DISTANCE_TYPE APATrajCalPEMinCarEndPosCoordinateXWithoutObjAtSide;
	-1550, // APACal.HalfWidthOfCar + 400; // Offset 40cm from the side object. APA_DISTANCE_TYPE APATrajCalPEMaxCarEndPosCoordinateXWithoutObjAtSide;APA_DISTANCE_TYPE APATrajCalPEMaxCarEndPosCoordinateXWithoutObjAtSide;
	20.0 * PI / 180.0, // 10 deg. APA_ANGLE_TYPE APATrajCalPELastStepAllowMinSteeringWheelAng;
	4.0 * PI / 180,   //APA_ANGLE_TYPE APATrajCalPELastStepSteeringWheelAngSearchingStep;
	7418.189033, //APA_DISTANCE_CAL_FLOAT_TYPE APATrajCalPEMaxLastStepRCenterTurningRadius;
	9114.842658, //APA_DISTANCE_CAL_FLOAT_TYPE APATrajCalPEMaxLastStepFOuterTurningRadius;
	300,	/// 30cm, def: 50cm, APA_DISTANCE_TYPE APATrajCalPESafetyDisToFObjAtCornerTurningCar;
	600, // 60cm, APA_DISTANCE_TYPE APATrajCalPELastStepSafetyDisToFObjAtCornerTurningCar;	
	0, //APA_DISTANCE_TYPE APATrajCalPESafetyDisToObjAtFrontTurningCar; 
    0, // APA_DISTANCE_TYPE APATrajCalPESafetyDisToObjAtRearTurningCar;
	-2813, // APA_DISTANCE_TYPE APATrajCalPECarIsOutOfSlotCriteriaMinCarPosY; // - APACal.LenBetweenRAxisAndFBumper + 800 //  (-APACal.LenBetweenRAxisAndFBumper / 2)

/*2.4.10.3 *** Angular Park****/		
	1408, //APA_DISTANCE_TYPE APATrajCalAPCarEndPositionDisToSideCar;
//APACal.HalfWidthOfCar + 500; 	
	APA_PARKPROC_CAR_END_POSITION_MID_BETWEEN_OBJ1_AND_OBJ2, // APA_ENUM_TYPE APATrajCalAPCarEndPosition;
	300, //APA_DISTANCE_TYPE APATrajCalAPSafetyDisToObj2AtTurningCar;
	
/*2.4.11 *** Park Process Algorithm****/
/*2.4.11.1 *** parallel and perpendicular***/

	100.0, // 10cm, APA_DISTANCE_CAL_FLOAT_TYPE APAParkProcKeepCurSlotDataAtAPAActiveStateMaxCarDrvDis;
	300, // APA_DISTANCE_TYPE APAParkProcSlotFoundAllowPutGearToRCarToStep1KeyPtDis1; // 40cm, 
	100, // 300, APA_DISTANCE_TYPE APAParkProcSlotFoundStopCmdDisplayCarToStep1KeyPtDis1; // 30cm,  < 10km/h
	400, // 400, APA_DISTANCE_TYPE APAParkProcSlotFoundStopCmdDisplayCarToStep1KeyPtDis2; // 40cm, 10 ~ 15km/h
	900, // 600, APA_DISTANCE_TYPE APAParkProcSlotFoundStopCmdDisplayCarToStep1KeyPtDis3; // 60cm, 15 ~ 20km/h
	1500, // 800, APA_DISTANCE_TYPE APAParkProcSlotFoundStopCmdDisplayCarToStep1KeyPtDis4; // 80cm, 20 ~ 30km/h

	350, // 35cm , APA_DISTANCE_TYPE APAParkProcObjRegardedAsInZone1MaxDisAfterStpCmdHasBeenShown;

	// APASnsDtdNearestObjDisDataType APAParkProcStartConsideringCarHitObjSnsDtDis[PA_SYS_NUM];
	{
		#if 0	
		// PARearSys = 0
		//{
			//typedef struct {
			500, // 0cm, will not check RRS. //	APA_DISTANCE_TYPE RSObjDis; // Obj detected by the R side sns. dis from 20cm ~ 200cm
			600, // 50cm //	APA_DISTANCE_TYPE RObjDis; // Obj detected by the R corner sns. dis from 20cm ~ 200cm
			1000, // 100cm //	APA_DISTANCE_TYPE MidObjDis; // Obj detected by the RM, LM, R tx RM Rx, RM tx R Rx, L tx LM rx, LM tx L rx. UPA FOV.
			600, // 60cm //	APA_DISTANCE_TYPE LObjDis; // Obj detected by the L corner sns. dis from 20cm ~ 200cm
			500 // 40cm //	APA_DISTANCE_TYPE LSObjDis; // Obj detected by the L side sns. dis from 20cm ~ 200cm
			//} APASnsDtdNearestObjDisDataType;
		//}
		,
		// PAFrontSys
		//{
			//typedef struct {
			500, // 40cm //	APA_DISTANCE_TYPE RSObjDis; // Obj detected by the R side sns. dis from 20cm ~ 200cm
			600, // 50cm //	APA_DISTANCE_TYPE RObjDis; // Obj detected by the R corner sns. dis from 20cm ~ 200cm
			1000, // 100cm //	APA_DISTANCE_TYPE MidObjDis; // Obj detected by the RM, LM, R tx RM Rx, RM tx R Rx, L tx LM rx, LM tx L rx. UPA FOV.
			600, // 60cm //	APA_DISTANCE_TYPE LObjDis; // Obj detected by the L corner sns. dis from 20cm ~ 200cm
			500 // 50cm //	APA_DISTANCE_TYPE LSObjDis; // Obj detected by the L side sns. dis from 20cm ~ 200cm
			//} APASnsDtdNearestObjDisDataType;
		//}
		#else 

		// Following cal will disable this function:

		
		// PARearSys = 0
		//{
			//typedef struct {
			0, // 0cm, will not check RRS. //	APA_DISTANCE_TYPE RSObjDis; // Obj detected by the R side sns. dis from 20cm ~ 200cm
			0, // 50cm //	APA_DISTANCE_TYPE RObjDis; // Obj detected by the R corner sns. dis from 20cm ~ 200cm
			0, // 100cm //	APA_DISTANCE_TYPE MidObjDis; // Obj detected by the RM, LM, R tx RM Rx, RM tx R Rx, L tx LM rx, LM tx L rx. UPA FOV.
			0, // 60cm //	APA_DISTANCE_TYPE LObjDis; // Obj detected by the L corner sns. dis from 20cm ~ 200cm
			0 // 40cm //	APA_DISTANCE_TYPE LSObjDis; // Obj detected by the L side sns. dis from 20cm ~ 200cm
			//} APASnsDtdNearestObjDisDataType;
		//}
		,
		// PAFrontSys
		//{
			//typedef struct {
			0, // 40cm //	APA_DISTANCE_TYPE RSObjDis; // Obj detected by the R side sns. dis from 20cm ~ 200cm
			0, // 50cm //	APA_DISTANCE_TYPE RObjDis; // Obj detected by the R corner sns. dis from 20cm ~ 200cm
			0, // 100cm //	APA_DISTANCE_TYPE MidObjDis; // Obj detected by the RM, LM, R tx RM Rx, RM tx R Rx, L tx LM rx, LM tx L rx. UPA FOV.
			0, // 60cm //	APA_DISTANCE_TYPE LObjDis; // Obj detected by the L corner sns. dis from 20cm ~ 200cm
			0 // 50cm //	APA_DISTANCE_TYPE LSObjDis; // Obj detected by the L side sns. dis from 20cm ~ 200cm
			//} APASnsDtdNearestObjDisDataType;
		//}

		#endif
	},
	
	30.0 / 3.6, // 25 km/h -> m/s , APA_SPEED_TYPE APAParkProcMaxWarningSearchingSlotSpeedUp;
	27.0 / 3.6, // 22 km/h -> m/s , APA_SPEED_TYPE APAParkProcMaxWarningSearchingSlotSpeedDown;
	40.0 / 3.6, // 30 km/h -> m/s , APA_SPEED_TYPE APAParkProcMaxSearchingSlotSpeed; //20120730
	(30000 / SPK_CHIME_TASK_CALL_TIME) , // APA_MS_TIME_TYPE APADisableBySpeedUpWhenSearchingSlotMaxDelayTime;
	8.0 / 3.6, //10.0 / 3.6, // 10 km/h -> m/s, APA_SPEED_TYPE APAParkProcMaxParkingSpeed;
	10.0, // m/s^2, APA_CAL_FLOAT_TYPE APAParkProcVehicleBrakeAccelerator;
	3000, // ms, APA_MS_TIME_TYPE APAParkProcMinTimeOfObjEnteringFullWarningZone;
	 // def: 2s, APA_MS_TIME_TYPE APAParkProcDriverResponseTimeForAPACmd[APA_ODI_MESSAGE_CMD_NUM];
	// {
	// 	1500 / APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME, // APAODIDispCmdType_NoMessage,/******0*****/
	// 	1500 / APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME, // APAODIDispCmdType_SearchingForParkingSlotRight,/******1*****/
	// 	3000 / APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME, //  APAODIDispCmdType_EndPositionAchieved,/******2*****/
	// 	1500 / APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME, //  APAODIDispCmdType_DriveBackward,/******3*****/
	// 	1500 / APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME, //  APAODIDispCmdType_DriveForward,/******4*****/
	// 	800 / APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME, //  APAODIDispCmdType_APAStop,/******5*****/
	// 	3000 / APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME, //  APAODIDispCmdType_LimitDriveSpeed,/******6*****/
	// 	2000 / APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME, //  APAODIDispCmdType_APACancel,/******7*****/
	// 	2000 / APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME, //  APAODIDispCmdType_ParkingFailedDoOver,/******8*****/
	// 	1500 / APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME, //  APAODIDispCmdType_SearchingForParkingSlotLeft,/******9*****/
	// 	1500 / APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME, //  APAODIDispCmdType_StopTightParking,/******10*****/
	// 	1500 / APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME, //  APAODIDispCmdType_APASlotFoundRight,/******11*****/
	// 	1500 / APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME, //  APAODIDispCmdType_APASlotFoundLeft,/******12*****/
	// 	// For APA system
	// 	1500 / APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME, //  APAODIDispCmdType_PutTheGearToReverse,/******13*****/
	// 	2000 / APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME, //  APAODIDispCmdType_RequestControlEPS,/******14*****/
	// 	1500 / APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME, //  APAODIDispCmdType_CarIsControlledByAPA,/******15*****/
	// 	1500 / APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME, //  APAODIDispCmdType_PutTheGearToDrive,/******16*****/
	// 	2000 / APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME, //  APAODIDispCmdType_APANotAvailableSteeringFailed,/******17*****//// added by dsh 2012.05.10 
	// 	1500 / APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME, //  APAODIDispCmdType_VehicleAutoSteeringActivatedREABOff,/******18*****/
	// 	1500 / APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME, //  APAODIDispCmdType_VehicleUnParkRight,/******19*****/
	// 	1500 / APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME, //  APAODIDispCmdType_VehicleUnParkLeft,/******20*****/
	// 	800 / APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME, //  APAODIDispCmdType_APAStopEndPositionAchieved/******21*****/	
	// 	1500 / APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME  //  APAODIDispCmdType_MoveAheadWhenAPAFoundSlot/******22*****/
	// },
	0, // def: 1000 ms, APA_MS_TIME_TYPE APAParkProcDriverResponseTimeForAPACmdMs;
	//3000 / APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME, // 3s, APA_MS_TIME_TYPE APAParkProcOverSpdMsgDisplayTimeWhenAPASwitchPressed;
	//30 / APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME, // def: 200ms, APA_MS_TIME_TYPE APAParkProcDriverInfoProgressPercentageDisplayTime;
	//350 / APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME, // kjy changed back to 350ms 2014 12 12 // 150ms, def: 200ms, APA_MS_TIME_TYPE APAParkProcDriverInfoFullyProgressPercentageDisplayTime;
	4, // 10, // kjy changed back to 10% 2014 12 12. 20, // 10% UCHAR APAParkProcDriverInfoProgressPercentageStep;	
	1, // 2, // 1.5s from 0 to 100%. UCHAR APAParkProcDriverInfoProgressPercentageStepSmall;	
	50,//	UCHAR APAParkProcDriverInfoProgressPercentageStartFastArrowBarFill;//20140120	
	96, // kjy changed 20140611 def: 90, 10% UCHAR APAParkProcDriverInfoProgressPercentageMaxValueBeforeStopCmd;	
	96, // 96%, UCHAR APAParkProcDriverInfoProgressPercentageResetValueAtSameDrvDir;
	500, // 50cm, APA_DISTANCE_TYPE APAParkProcDriverInfoProgressPercentageRegardTargetPosChangedDevidedDis; // 50cm,
	100, // 10cm, APA_DISTANCE_TYPE APAParkProcDriverInfoProgressPercentageRegardTargetPosChangedTolDis1; // 10cm, total car drive dis < 50cm.
	200, // 20cm, APA_DISTANCE_TYPE APAParkProcDriverInfoProgressPercentageRegardTargetPosChangedTolDis2; // 20cm,

	20.0 * PI / 180.0,//APA_ANGLE_TYPE APAParkProcParallelParkInSlotFrontHasObjRearhasCurbNeedToStopMinCarAng;
	0x7fff,//5,// mm APA_DISTANCE_CAL_FLOAT_TYPE APAParkProcParallelParkInSlotFrontHasObjRearhasCurbNeedToStopMinXOffsetDis;7fff: disable this function
	300,//mm APA_DISTANCE_TYPE APAParkProcParallelParkInSlotFrontHasObjRearhasCurbNeedToStopMaxSnsDtdDis;
	4000,//mm APA_DISTANCE_TYPE APAParkProcParallelParkIInSlotFrontHasObjRearhasCurbNeedToStopMaxSlotDepth;
	60.0 * PI / 180.0,//APA_ANGLE_TYPE APAParkProcPerpendParkFirstDriveBackPhaseHasObjInRearMaxCarAng;
	0x7fff,//0.0,//mm APA_DISTANCE_CAL_FLOAT_TYPE APAParkProcPerpendParkFirstDriveBackPhaseHasObjInRearMinCarCenterPtY;7fff: disable this function
	400,//mm APA_DISTANCE_TYPE APAParkProcPerpendParkFirstDriveBackPhaseHasObjInRearMaxLObjDis;
	400,//mm APA_DISTANCE_TYPE APAParkProcPerpendParkFirstDriveBackPhaseHasObjInRearMaxMObjDis;
    400,//mm APA_DISTANCE_TYPE APAParkProcPerpendParkFirstDriveBackPhaseHasObjInRearMaxRObjDis;

	APA_PARKPROC_CAR_END_POSITION_MID_BETWEEN_OBJ1_AND_OBJ2, // APA_ENUM_TYPE APAParkProcCarEndPosition;
	APA_PARKPROC_CAR_END_POSITION_CLOSE_TO_OBJ2, // APA_ENUM_TYPE APAParkProcCarEndPositionWithSlotLenGreatThanAGivenSlot;
	800, // APA_DISTANCE_TYPE APAParkProcCarEndPositionToObj1Dis;
	800, // APA_DISTANCE_TYPE APAParkProcCarEndPositionToObj2Dis;

	1.5 / 3.6, // 2km/h, APA_SPEED_TYPE APAParkProcCarEndPositionCarAngTolDevidedSpeed1;
	3.5 / 3.6, // 3.5km/h, APA_SPEED_TYPE APAParkProcCarEndPositionCarAngTolDevidedSpeed2;
	7000, // 7m, APA_DISTANCE_TYPE APAParkProcCarEndPositionCarAngTolRegardedAsBigSlotLen;
	
	// 0.5deg. APA_ANGLE_TYPE APAParkProcCarEndPositionAchievedCarAngTolOffsetValue[APA_CAR_PARK_SIDE_NUM]; // 0.5 deg ?? or 0 deg.	
	{
		// Left side,                 right side
		//0.5 * PI / 180.0,             0.5 * PI / 180.0
			0 * PI / 180.0, 0 * PI / 180.0 //2018/9/7 liu.pan changeto 0
	},
	0.6 * PI / 180.0, // 1 deg, def: 0.7, APA_ANGLE_TYPE APAParkProcCarEndPositionCarAngTol1;
	0.9 * PI / 180.0, // 1.5 deg,def: 1.0, APA_ANGLE_TYPE APAParkProcCarEndPositionCarAngTol2;
	1.2 * PI / 180.0, // 1 deg, def: 0.7, APA_ANGLE_TYPE APAParkProcCarEndPositionCarAngTol3;
	1.5 * PI / 180.0, // 1.5 deg,def: 1.0, APA_ANGLE_TYPE APAParkProcCarEndPositionCarAngTol4;
	3.0 * PI / 180.0, // 1.5 deg,APA_ANGLE_TYPE APAParkProcCarEndPositionCarAngTol5;	// used to calculate the target pos for progress bar.
	//800,  //	APA_DISTANCE_TYPE APAParkProcSteerCtrlStartTurnDefDisInSlot;

	// Parallel parking in:
	// APA_ANGLE_CAL_FLOAT_TYPE APAParkProcSteerCtrlSteeringTurningSpeedStep1[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM]; // rad/ms
	{
		// 0 ~ 2kph,    2~4kph,         4~6kph,         6~kph,
		// 200.0 / Max EPS angle speed * Steering Angle At EPS angle 500deg. 
		180.0 / 520.0 * 35.0 * PI / 180.0 / 1000.0, // 0~2kph // def: 120.0, changed by kjy 2014 06 30 to 180deg.
		280.0 / 520.0 * 35.0 * PI / 180.0 / 1000.0, // 4
		400.0 / 520.0 * 35.0 * PI / 180.0 / 1000.0, // 6
		440.0 / 520.0 * 35.0 * PI / 180.0 / 1000.0 // 8
	},
	
	// APA_ANGLE_CAL_FLOAT_TYPE APAParkProcSteerCtrlSteeringTurningSpeedStep2[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM]; // rad/ms
	{
		// 0 ~ 2kph,    2~4kph,         4~6kph,         6~kph,
		// 200.0 / Max EPS angle speed * Steering Angle At EPS angle 500deg. 
		200.0 / 520.0 * 35.0 * PI / 180.0 / 1000.0, // 0~2kph
		300.0 / 520.0 * 35.0 * PI / 180.0 / 1000.0, // 4
		400.0 / 520.0 * 35.0 * PI / 180.0 / 1000.0, // 6
		450.0 / 520.0 * 35.0 * PI / 180.0 / 1000.0 // 8
	},
	
	// APA_ANGLE_CAL_FLOAT_TYPE APAParkProcSteerCtrlSteeringTurningSpeedLineStep[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM]; // rad/ms
	{
		// 0 ~ 2kph,    2~4kph,         4~6kph,         6~kph,
		// 200.0 / Max EPS angle speed * Steering Angle At EPS angle 500deg. 
		250.0 / 520.0 * 35.0 * PI / 180.0 / 1000.0, // 0~2kph // 300
		350.0 / 520.0 * 35.0 * PI / 180.0 / 1000.0, // 4 // 400
		400.0 / 520.0 * 35.0 * PI / 180.0 / 1000.0, // 6 // 450
		450.0 / 520.0 * 35.0 * PI / 180.0 / 1000.0 // 8
	},
	
	//APA_ANGLE_CAL_FLOAT_TYPE APAParkProcSteerCtrlSteeringTurningSpeedInsideSlot[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM]; // rad/ms
	{
		// 0 ~ 2kph,    2~4kph,         4~6kph,         6~8kph,
		// 200.0 / Max EPS angle speed * Steering Angle At EPS angle 500deg. 
		250.0 / 520.0 * 35.0 * PI / 180.0 / 1000.0, // 0~2kph // 300
		350.0 / 520.0 * 35.0 * PI / 180.0 / 1000.0, // 4 // 400
		400.0 / 520.0 * 35.0 * PI / 180.0 / 1000.0, // 6 // 450
		450.0 / 520.0 * 35.0 * PI / 180.0 / 1000.0 // 8
	},

	//APA_RATIO_TYPE APAParkProcSteerCtrlSteeringTurningSpeedFactorStep1[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM]; 
	{
		// 0 ~ 2kph,    2~4kph,         4~6kph,         6~kph,
		0.8, 			0.4, 			0.2, 			0.1
	},
	//APA_RATIO_TYPE APAParkProcSteerCtrlSteeringTurningSpeedFactorStep2[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM]; 
	{
		// 0 ~ 2kph,    2~4kph,         4~6kph,         6~kph,
		0.8, 			0.4, 			0.2, 			0.1
	},
	//APA_RATIO_TYPE APAParkProcSteerCtrlSteeringTurningSpeedFactorInsideSlot[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM];
	{
		// 0 ~ 2kph,    2~4kph,         4~6kph,         6~kph,
		0.4, 			0.2, 			0.15, 			0.1
	},
	//APA_CAL_FLOAT_TYPE APAParkProcSteerCtrlSteeringAngleTurningDelayTime[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM]; // ms
	{
		// 0 ~ 2kph,    4kph,         	6kph,         8~kph,
		150.0, 			150.0, 			165.0, 			200.0
	},
		
	//APA_RATIO_TYPE APAParkProcSteerCtrlSteeringTurningOffsetFactorByDeltaSteerAngStep1[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM];// current angle is less than the target angle.		
	{
		// 0 ~ 2kph,    2~4kph,         4~6kph,         8kph,
		0.02, 			0.04, 			0.05, 			0.1
	},
	//APA_RATIO_TYPE APAParkProcSteerCtrlSteeringTurningOffsetFactorByDeltaSteerAngStep2[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM];// Current angle is large than the current angle.
	{
		// left side	
		{
		// 0 ~ 2kph,    2~4kph,         4~6kph,         8~kph,
		-0.05, 			-0.05, 			-0.025, 		-0.025
		},
		// right side
		{
		// 0 ~ 2kph,    2~4kph,         4~6kph,         8~kph,
		-0.05, 			-0.05, 			-0.025, 		-0.025
		}	
	},	
	//APA_RATIO_TYPE APAParkProcSteerCtrlSteeringTurningOffsetFactorByDeltaSteerAngLineStep[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM];// current angle is less than the target angle.		
	{
		// left side	
		{
		// 0 ~ 2kph,    2~4kph,         4~6kph,         8~kph,
		0,/*0.05,*/ 			0, /*0.05,*/ 			0.04, 			0.04
		},
		
		// right side
		{
		// 0 ~ 2kph,    2~4kph,         4~6kph,         8~kph,
		0,/*0.05,*/ 			0, /*0.05,*/ 			0.04, 			0.04
		}
	},
	//APA_RATIO_TYPE APAParkProcSteerCtrlSteeringTurningOffsetFactorByDeltaSteerAng1[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM];// inside slot current angle is large than the target angle.		
	{
		// 0 ~ 2kph,    2~4kph,         4~6kph,         8~kph,
		-0.05, 			0, 				0, 				0
	},	
	//APA_RATIO_TYPE APAParkProcSteerCtrlSteeringTurningOffsetFactorByDeltaSteerAng2[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM];// inside slot Target angle is large than the current angle.
	{
		// 0 ~ 2kph,    2~4kph,         4~6kph,         8~kph,
		0.05, 			0.05, 			0.05, 			0.05
	},

	// Perpendicular parking in:
	// APA_ANGLE_CAL_FLOAT_TYPE APAParkProcPSteerCtrlSteeringTurningSpeedOutOfSlot[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM]; // rad/ms
	{
		// 0 ~ 2kph,    2~4kph,         4~6kph,         6~8kph,
		// 200.0 / Max EPS angle speed * Steering Angle At EPS angle 500deg. 
		200.0 / 520.0 * 35.0 * PI / 180.0 / 1000.0, // 0~2kph def: 220
		350.0 / 520.0 * 35.0 * PI / 180.0 / 1000.0, // 4 // 400 def: 380
		420.0 / 520.0 * 35.0 * PI / 180.0 / 1000.0, // 6 // 450
		480.0 / 520.0 * 35.0 * PI / 180.0 / 1000.0 // 8
	},
	//APA_ANGLE_CAL_FLOAT_TYPE APAParkProcPSteerCtrlSteeringTurningSpeedInsideSlot[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM]; // rad/ms
	{
		// 0 ~ 2kph,    2~4kph,         4~6kph,         6~kph,
		// 200.0 / Max EPS angle speed * Steering Angle At EPS angle 500deg. 
		300.0 / 520.0 * 35.0 * PI / 180.0 / 1000.0, // 0~2kph // 250, 300
		380.0 / 520.0 * 35.0 * PI / 180.0 / 1000.0, // 4 // 400
		420.0 / 520.0 * 35.0 * PI / 180.0 / 1000.0, // 6 // 450
		480.0 / 520.0 * 35.0 * PI / 180.0 / 1000.0 // 8
	},

	// APA_RATIO_TYPE APAParkProcPSteerCtrlSteeringTurningSpeedFactorOutOfSlot[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM]; // 
	{
		// 0 ~ 2kph,    2~4kph,         4~6kph,         6~kph,
		0.6, 			0.4, 			0.2, 			0.1
	},
	// APA_RATIO_TYPE APAParkProcPSteerCtrlSteeringTurningSpeedFactorInsideSlot[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM]; // 
	{
		// 0 ~ 2kph,    2~4kph,         4~6kph,         6~kph,
		0.6, 			0.4, 			0.2, 			0.1
	},
	// APA_RATIO_TYPE APAParkProcPSteerCtrlSteeringTurningOffsetFactorByDeltaSteerAng1[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM];// current angle is large than the target angle.
	{
		// 0 ~ 2kph,    2~4kph,         4~6kph,         8~kph,
		-0.05, 			-0.05, 			-0.025, 		-0.025
		//0, 			0, 					0, 			0
	},	
	
	// APA_RATIO_TYPE APAParkProcPSteerCtrlSteeringTurningOffsetFactorByDeltaSteerAng2[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM];// Target angle is large than the current angle.
	{
		// 0 ~ 2kph,    2~4kph,         4~6kph,         6~kph,
		//0.02, 			0.04, 			0.05, 			0.1
		0.11, 			0.15, 			0.16, 			0.11
	},
	400.0 / 520.0 * 35.0 * PI / 180.0 / 1000.0, //, APA_ANGLE_CAL_FLOAT_TYPE APAParkProcPSteerCtrlSteeringTurningToTargetAngMaxSpeed;
	400.0 / 520.0 * 35.0 * PI / 180.0 / 1000.0, //, // APA_ANGLE_CAL_FLOAT_TYPE APAParkProcPSteerCtrlSteeringTurningToZeroMaxSpeed;
	1800.0, // 200deg steering angle, car will drive 40cm, APA_ANGLE_CAL_FLOAT_TYPE APAParkProcPSteerCtrlSteeringTurningToZeroDriveDisRatio;

	2.0 / 3.6, // 2kph, APA_SPEED_CAL_FLOAT_TYPE APAParkProcEPSSteeringWheelCtrlCalMinVehSpeed; // 2kph / 3.6 =>m/s
	0.5 / 3.6, // 2kph, APA_SPEED_CAL_FLOAT_TYPE APAParkProcEPSSteeringWheelCtrlCalMinVehSpeedInSlot; // 0.5kph / 3.6 =>m/s
	8.0 / 3.6, // 8kph, APA_SPEED_CAL_FLOAT_TYPE APAParkProcEPSSteeringWheelCtrlCalMaxVehSpeed; // 8kph / 3.6 -> m/s

	400, // 40cm, APA_DISTANCE_TYPE APAParkProcSteerCtrlStartTurnMinDisInSlot;
	2800, // 80cm, APA_DISTANCE_TYPE APAParkProcSteerCtrlStartTurnMaxDisInSlot;	
	300,  // 30cm,	APA_DISTANCE_TYPE APAParkProcPSteerCtrlStartTurnMinDisInSlot;
	2800,  // 2m def: 2500, APA_DISTANCE_TYPE APAParkProcPSteerCtrlStartTurnMaxDisInSlot;
	800,  //def: 800, APA_DISTANCE_TYPE APAParkProcSteerCtrlStartTurnMinDisOutOfSlot;
	4400, //APA_DISTANCE_TYPE APAParkProcSteerCtrlStartTurnMaxDisOutOfSlot;

	100, // 10cm, APA_DISTANCE_TYPE APAParkProcSteerCtrlAllowTurnToCurSteerMinDis;	
	1.5, // 70% -> 100%, APA_CAL_FLOAT_TYPE APAParkProcSteerCtrlAllowTurnToCurSteerCalFactor1; // Vehicle Speed < 5km/h	
	1.2, // 84% -> 100%, APA_CAL_FLOAT_TYPE APAParkProcSteerCtrlAllowTurnToCurSteerCalFactor2; // Vehicle Speed > 5km/h	
	
	0.1 * PI / 180.0, // 0.1 deg, APA_ANGLE_TYPE APAParkProcCarDriveStraightlyMinSteeringWheelAng;
	200, // 20cm, APA_DISTANCE_TYPE APAParkProcCarParkingCarEndPositionXDisTol;
	1000, //Luhui 20200521 change to 100cm,1800, // 30cm, APA_DISTANCE_TYPE APAParkProcCarParkingCarEndPositionDisTol2;

	1000, // car len + 1400 = 6m, APA_DISTANCE_TYPE APAParkProcCarParkingCarEndPositionYDisTolDevidedSlotLen1; // car len + 1200	
	2200, // car len + 2200 = 7m,APA_DISTANCE_TYPE APAParkProcCarParkingCarEndPositionYDisTolDevidedSlotLen2; // car len + 2000
	70, // 100, // 10cm, APA_DISTANCE_TYPE APAParkProcCarParkingCarEndPositionYDisTol0;
	150, // 100, // 10cm, APA_DISTANCE_TYPE APAParkProcCarParkingCarEndPositionYDisTol1;
	300, // 300, // 10cm, APA_DISTANCE_TYPE APAParkProcCarParkingCarEndPositionYDisTol2;
	
	800, // car len + 80cm. APA_DISTANCE_TYPE APAParkProcCarParkingCarEndPositionCarDrvDisByGearChangedDvdSlotLen1; // car len + 80cm. 
	2000, // car len + 200cm.  APA_DISTANCE_TYPE APAParkProcCarParkingCarEndPositionCarDrvDisByGearChangedDvdSlotLen2; // car len + 200cm. 
	70, // 7cm, APA_DISTANCE_TYPE APAParkProcCarParkingCarEndPositionCarDrvMinDisByGearChanged1; // 10cm. 
	200, // APA_DISTANCE_TYPE APAParkProcCarParkingCarEndPositionCarDrvMinDisByGearChanged2; // 30cm. 

	300, // Luhui 20200521 -> 200, // 40cm, APA_DISTANCE_TYPE APAParkProcCarParkingCarEndPositionAchivedMinDisToObj12;
	//400 / APA_PARKPROC_PARKING_PROCESS_TASK_CALL_CYCLE_TIME, // unit: ms, 400ms, APA_MS_TIME_TYPE APAParkProcCarParkingCarEndPositionAchivedDelayTime;
	
	1,//Luhui 2020 0722 -> 1, //D2SC:1	APA_ENUM_TYPE APAParkProcCarParkingCarEndPositionAchivedAllowDrvFwBkNum;

	20.0, // APA_RATIO_TYPE APAParkProcAllowUseLargeSafetyDisBySpeedCompensatedFactor; // 20: 3kph: compensate: 14cm. 2kph: 6cm, 1kph: 1.5cm.
	150, // 15cm, APA_DISTANCE_TYPE APAParkProcAllowUseLargeSafetyDisBySpeedCompensatedMaxDis; // 15cm.

	200, // 20cm, APA_DISTANCE_TYPE APAParkProcAllowUseLargeSafetyDisMaxDeltaCarPosXToEndPosXDis;	
	1500, // 1m, APA_DISTANCE_TYPE APAParkProcAllowUseLargeSafetyDisMinFRDis;	
	2400, // changed to 2400 by kjy 2014 07 05, 2.4m, def: 1.8m APA_DISTANCE_TYPE APAParkProcAllowUseLargeSafetyDisMaxFRDis;	
	450, // APA_DISTANCE_TYPE APAParkProcLenBetweenRearRectCornerToRearBumperCornerCurve; // 450cm.
	450, // changed to 450 by kjy 2014 07 05, 500, // 80cm, APA_DISTANCE_TYPE APAParkProcLargeSafetyDisToRear;	
	400, // 400, 60cm, APA_DISTANCE_TYPE APAParkProcLargeSafetyDisToFront;	
	0.01, // 1% tolerance. 100m radius allowed 1m tolerance. APA_RATIO_TYPE APAParkProcCarParkingAllowedDeviateDisRatioFromCalTrajectory; // 1%
	200, // 30cm, APA_DISTANCE_TYPE APAParkProcCarParkingAllowedDeviateDisFromCalTrajectory;
	15.0 * PI / 180.0, // 15 deg, APA_ANGLE_TYPE APAParkProcCarParkingAllowedDeviateCarAngFromCalTrajectory;
	// APA_ANGLE_TYPE APAParkProcCarParkingAllowedRecalTrajectoryMaxSteeringAngle;
	32.0 * PI / 180.0 * 5.0 / 6.0, // APACal.MaxSteeringWheelAngle * 5.0 / 6.0;
	100, // 10cm, APA_DISTANCE_TYPE APAParkProcCompensatedCarAngMinDriveDis;	
	// APA_ANGLE_TYPE APAParkProcCompensatedCarAngEachStepInSlot1[APA_CAR_PARK_SIDE_NUM]; // 1.5deg / 5 step.
	{
		// Left side.      Right side.
		4.0 * PI / 180.0 / 5.0, 4.0 * PI / 180.0 / 5.0 
	},
	// APA_DISTANCE_CAL_FLOAT_TYPE APAParkProcCompensatedCarPosXEachStepInSlot1[APA_CAR_PARK_SIDE_NUM];	// -10cm / 5 step.
	{
		// Left side.      Right side.
		0,                 0
	},
	// 1.0 * PI / 180.0 / 5.0, // APA_ANGLE_TYPE APAParkProcCompensatedCarAngEachStepInSlot2[APA_CAR_PARK_SIDE_NUM]; // 1.5deg / 5 step.	
	{
		// Left side.      Right side.
		2.0 * PI / 180.0 / 5.0,       2.0 * PI / 180.0 / 5.0
	},
	//- 100 / 5, // APA_DISTANCE_CAL_FLOAT_TYPE APAParkProcCompensatedCarPosXEachStepInSlot2[APA_CAR_PARK_SIDE_NUM];	// -10cm / 5 step.
	{
		// Left side.      Right side.
		0,                 0
	},
	
	14, // APA_ENUM_TYPE APAParkProcCarMaxBackAndForwardCorrectCntInStep3456;
	3, //Luhui 2020 0528 :2=>3 2 - correct twice: APA_ENUM_TYPE APAParkProcCarRearRightCornerMayHitObj2MaxCorCnt;	
	50, // 5cm. APA_DISTANCE_TYPE APAParkProcCarRegardOneDrvFwAndBkStepMinDeltaDis;
	800, // 80cm, APA_DISTANCE_TYPE APAParkProcCarRearRightCornerMayHitObj2MinCarDrvFwDis;
	
	550, // 80cm APA_DISTANCE_TYPE APAParkProcTightSlotMinTotalFrontAndRearSnsDtdDis;
	//30000 / APA_PARKPROC_PARKING_PROCESS_TASK_CALL_CYCLE_TIME, // unit: ms, 10s, APA_MS_TIME_TYPE APAParkProcCarMayHitObjectStopWaitingTime; // If the value is set to APA_PARKPROC_MAX_MS_TIME_VALUE, the function will be disabled. Ie. the APA will wait for ever.
	//3000 / APA_PARKPROC_PARKING_PROCESS_TASK_CALL_CYCLE_TIME, // unit: ms, 3s, APA_MS_TIME_TYPE APAParkProcObjDtdAtRearAndMovingAwayDrvBkDelayTime; // 2s. 
	0.5 / 3.6,//Luhui 0.05 / 3.6, // 0.05 km/ h -> m/s , APA_SPEED_TYPE APAParkProcMaxVehicleStaticSpeedDown;
	0.5 / 3.6, // 1 km/ h -> m/s , APA_SPEED_TYPE APAParkProcMaxVehicleStaticSpeedUp; // 1 km/h;
	0.5 / 3.6, // 1.5km/h, APA_SPEED_TYPE APAParkProcMaxRegardAsStaticAndRecalTrajVehicleSpeed; // 1.5km/h.
	10.0 / 3.6, // 10km/h, 	APA_SPEED_TYPE APAParkProcMaxDisplaySlotFoundVehicleSpeed; // 10km/h.
	0.1 / 3.6, // 3.0km/h  APA_SPEED_TYPE APAParkProcMaxRegardAsStaticAndReqCtrlEPSVehicleSpeed; // 4km/h.
	// /*600*/120 / APA_PARKPROC_PARKING_PROCESS_TASK_CALL_CYCLE_TIME, // 600ms, APA_MS_TIME_TYPE ;// APA_MS_TIME_TYPE APAParkProcMaxCalTactFeedBkDuratn; 
	// 2000 / APA_PARKPROC_PARKING_PROCESS_TASK_CALL_CYCLE_TIME, // 2s, APA_MS_TIME_TYPE ; // APA_MS_TIME_TYPE APAParkProcMaxCalTactFeedBkOvralTime; //add by lzc 2012 05 08
	//1000 / APA_STEERING_WHEEL_CTRL_TASK_CALL_CYCLE_TIME, // 1s,	APA_MS_TIME_TYPE APASteeringWheelCtrlLimitControlStepRemainTime;
	0, // 300 / APA_STEERING_WHEEL_CTRL_TASK_CALL_CYCLE_TIME, // 300ms,	APA_MS_TIME_TYPE APASteeringWheelCtrlSteeringAngCtrlStepHoldTime;
	0, // 150 / APA_STEERING_WHEEL_CTRL_TASK_CALL_CYCLE_TIME, // 2014 08 19 changed from 500ms to 150ms. def:500ms,	APA_MS_TIME_TYPE APASteeringWheelCtrlSteeringIsStaticTime;
	1000.0 * PI / 180.0 * APA_RX_STEERING_WHEEL_ANGLE_CAL_FACTOR, // 20deg/40ms = 500deg/s, APA_ANGLE_TYPE APAParkProcControlledSteeringWheelAngleLimitDeltaAnlePer40ms; // unit: Rad. limit: 500deg/s = 20deg/40ms.
	10.0 * PI / 180.0 * APA_RX_STEERING_WHEEL_ANGLE_CAL_FACTOR, // 10deg/20ms = 500deg/s, APA_ANGLE_TYPE APAParkProcControlledSteeringWheelAngleLimitStep; // unit: Rad. limit: 500deg/s = 10deg/20ms. EPS ratio: 14.5348, = 10deg / 14.5348 deg. 
	1.5 * PI / 180, // //1.5 * PI / 180, // APA_ANGLE_TYPE APAParkProcControlledSteeringWheelAngleStartStepSteeringIsStatic; // unit: Rad. 
	1.5 * PI / 180, // APA_ANGLE_TYPE APAParkProcControlledSteeringWheelAngleStartStepSteeringIsTurning; // unit: Rad. 
	//(2.0) / (200.0 / APA_STEERING_WHEEL_CTRL_TASK_CALL_CYCLE_TIME) * PI / 180, // 200ms to reach the max step. APA_ANGLE_TYPE APAParkProcControlledSteeringWheelAngleStepAddedStep; // unit: Rad. 
	1.5 * PI / 180, // * 5.0, //de: 2.0 * PI / 180, //max 0.1 rad (5deg), APA_ANGLE_TYPE APAParkProcControlledSteeringWheelAngleStepForEndPosAchievedCor; // 
	3.0 * PI / 180, // APA_ANGLE_TYPE APAParkProcControlledSteeringWheelAngleStepForCarHitObj2Cor; // 

	#if 1/* DX7 EPS Control Parameter */
	(3.0 + 5.0) * PI / 180.0,  // APA_ANGLE_TYPE APAParkProcControlledSteeringWheelAngleMaxStep; // unit: Rad.
	(3.3 + 5.0) * PI / 180.0, // APA_ANGLE_TYPE APAParkProcControlledSteeringWheelAngleMaxStepOverSpeed1
	(3.5 + 5.0) * PI / 180.0, // APA_ANGLE_TYPE APAParkProcControlledSteeringWheelAngleMaxStepOverSpeed2
	(2.5 + 5.0) * PI / 180.0, // APA_ANGLE_TYPE APAParkProcControlledSteeringWheelAngleStep1
	#else
	3.0 * PI / 180, // def: 3.8 * PI / 180, //max 0.1 rad (5deg), APA_ANGLE_TYPE APAParkProcControlledSteeringWheelAngleMaxStep; // unit: Rad.
	3.3 * PI / 180.0, // 2014 05 23 changed by kjy from 2.7 to 3.3, //2.7 * PI / 180, // 2.7 * PI / 180, APA_ANGLE_TYPE APAParkProcControlledSteeringWheelAngleMaxStepOverSpeed1; // unit: Rad. Speed > 5km/h
	3.5 * PI / 180.0, // 2014 05 23 changed by kjy from 2.4 to 3.5, //2.4 * PI / 180, // APA_ANGLE_TYPE APAParkProcControlledSteeringWheelAngleMaxStepOverSpeed2; // unit: Rad. Speed > 8km/h
	2.5 * PI / 180.0, // 2014 05 23 changed by kjy from 2 to 2.5, //2.0 * PI / 180.0, // def: 1.5deg. is ok. APA_ANGLE_TYPE APAParkProcControlledSteeringWheelAngleStep1; // unit: Rad. delta steering angle < 2.5deg.
	#endif
	5.0 * PI / 180.0, // 5 * 16 = 90.deg  APA_ANGLE_TYPE APAParkProcControlledSteeringWheelAngleCtrlStepLowSpd; // unit: Rad. steering angle = 5deg.
	1.0 / 3.6, // 5km/h,  APA_SPEED_TYPE APAParkProcControlledSteeringWheelAngleSpeedLimit0; // 1km/h
	1.5 / 3.6, // 5km/h,  APA_SPEED_TYPE APAParkProcControlledSteeringWheelAngleSpeedLimit01; // 1.5km/h
	3.0 / 3.6, // 5km/h,  APA_SPEED_TYPE APAParkProcControlledSteeringWheelAngleSpeedLimit1; // 5km/h
	5.0 / 3.6, // 8km/h, APA_SPEED_TYPE APAParkProcControlledSteeringWheelAngleSpeedLimit2; // 8km/h

	//Added to discard the previous detected slot and start a new slot searching process start 20140303
	//100 / APA_PARKPROC_PARKING_PROCESS_TASK_CALL_CYCLE_TIME, // 100ms  APA_MS_TIME_TYPE APAParkProcAutoSteeringIndicationShowDelayTime;
	//30000 / APA_PARKPROC_PARKING_PROCESS_TASK_CALL_CYCLE_TIME, // 30sec APA_MS_TIME_TYPE APAParkProcKeepSlotForEnablingSysAgainByAPASwtichMaxTime;
	//Added to discard the previous detected slot and start a new slot searching process end 20140303	

	//0x100 / APACal.APAControlledSteeringWheelAngleConvertFactor
	36, //Luhui 20208005 3000 / APA_PARKPROC_PARKING_PROCESS_TASK_CALL_CYCLE_TIME, // 3s, APA_MS_TIME_TYPE APAParkProcMaxAPATrajectoryCalTime; // If the apa trajectory cal time is great than this value. the APA will exit with failure.
	//(200 / APA_STEERING_WHEEL_CTRL_TASK_CALL_CYCLE_TIME), // APA_MS_TIME_TYPE APAParkProcRecalTrajDelayTimeSearchSlotWithCarStaticDrvFw;
	4, // cal 4 times. APA_MS_TIME_TYPE APAParkProcRecalTrajMaxCntSearchSlotWithCarStaticDrvFw;

	3.0 * PI / 180.0, // 2deg:  APA_ANGLE_TYPE APAParkProcTrajCheckAllowedSteeringWheelAngleTol; // (unit: radian) the tollerance
	600.0, // 60cm, APA_DISTANCE_CAL_FLOAT_TYPE APAParkProcTrajCheckAllowedTurningRadiusTol;
			
	//1200 / APA_PARKPROC_PARKING_PROCESS_TASK_CALL_CYCLE_TIME, // 1.2s 	APA_MS_TIME_TYPE APAParkProcCarEndPositionAchievedEPSHoldTime;
	//1300 / APA_PARKPROC_PARKING_PROCESS_TASK_CALL_CYCLE_TIME, // 4s, APA_MS_TIME_TYPE APAParkProcIPCCarEndPositionAchievedDisplayTime;
	2.0 * PI / 180.0, // 2deg: EPS 33deg, around 6% tollerance, 1.5->deg: 24deg:  unit:rad def:0.5deg -> 8deg of steering angle. it is too small, it will out of the EPS tolerance: 10deg. APA_ANGLE_TYPE APAParkProcSteeringWheelAngleAchievedTol; // (unit: radian) the tollerance between desired steering wheel angle and EPS steering angle.
	10.0 * PI / 180.0, // 20deg: just for ESCAPE EPS. 1.5->deg: 24deg:  unit:rad def:0.5deg -> 8deg of steering angle. it is too small, it will out of the EPS tolerance: 10deg. APA_ANGLE_TYPE APAParkProcSteeringWheelAngleTurningTimeOutTol; // (unit: radian) the tollerance between desired steering wheel angle and EPS steering angle.
	600,  //APA_DISTANCE_TYPE APAParkProcMaxStartTurnSteeringWheelDeltaDisToKeyPointLastStep;	
	//(APACal.MaxSteeringWheelAngle / 2000.0); // from 0 to max takes 2s.		
	//300 / APA_PARKPROC_PARKING_PROCESS_TASK_CALL_CYCLE_TIME, // 0.5s // APA_MS_TIME_TYPE APAParkProcEPSControllConnectDelayTimeIntoReverse;
	10,//APA_ENUM_TYPE APAParkProcMaxRequestControlEPSTryTimes;//added 2014 05 06
	//(6 * 60 * (1000 / APA_PARKPROC_PARKING_PROCESS_TASK_CALL_CYCLE_TIME)), // def: 3min APA_MS_TIME_TYPE APAParkProcMaxAPAParkingTime;
	4800, // 4.8m. APA_DISTANCE_TYPE APAParkProcMinPassDisToDeletTheFirstSlotAfterSecondSlotFound; // 2010 12 20.
	//12000 / APA_PARKPROC_PARKING_PROCESS_TASK_CALL_CYCLE_TIME, // APA_MS_TIME_TYPE APAParkProcMaxSteeringWheelTurningTime;
	0, // changed by kjy from 50ms to 0, 2014 05 23, //50 / APA_PARKPROC_PARKING_PROCESS_TASK_CALL_CYCLE_TIME, //def: 0.8s APA_MS_TIME_TYPE wParkProcSteeringWheelAngleHoldTime;	
	//100 / APA_PARKPROC_PARKING_PROCESS_TASK_CALL_CYCLE_TIME, // APA_MS_TIME_TYPE wParkProcCorrectSteeringWheelAngleHoldTime;	
	0, // changed by kjy from 200ms to 0, 2014 05 23, //200 / APA_PARKPROC_PARKING_PROCESS_TASK_CALL_CYCLE_TIME, // def: 0.8s, APA_MS_TIME_TYPE wParkProcRecalTrajSteeringAngleAchievedDelayTime;	
	
	800, //80cm, APA_DISTANCE_TYPE APAParkProcAllowCarCanDrvDisWithoutObjDtd; // 80cm.		
	400, //APA_DISTANCE_TYPE APAParkProcAllowCarDriveTowardsTheObjMinDis;
	600, // 60cm, APA_DISTANCE_TYPE APAParkProcAllowCarDriveTowardsTheObjMinDisAfterStopCmdDisplayed;		
	// Add 2012 05 04 parking out
	1200, //APA_DISTANCE_TYPE APAParkProcAllowCarDriveOutOfTheSlotDisWithoutObjAtFOrR;
	300, //APA_DISTANCE_TYPE APAParkProcAllowCarOffsetDisToEndPosXInTheSlotDuringSteeringCorrect;
	15.0 * PI / 180, //APA_ANGLE_TYPE APAParkProcMinSteeringAngleCanBeCorrectedInTheSlot;
	1.0 * PI / 180,//APA_ANGLE_TYPE APAParkProcSteeringAngleCanBeCorrectedStepAngleInTheSlot;	
	15.0 * PI / 180, //APA_ANGLE_TYPE APAParkProcMinCarAngAllowSteeringCorrectToZeroInTheSlot;		
	200,	// 	APA_DISTANCE_TYPE APAParkProcCarParkingAllowedDeviateDisFromOriginalTrajectory 
	10.0 / 180.0 * PI,	// APA_ANGLE_TYPE APAParkProcCarParkingAllowedDeviateCarAngFromOriginalTrajectory 
	//1000 / APA_PARKPROC_PARKING_PROCESS_TASK_CALL_CYCLE_TIME, // 1s // APA_MS_TIME_TYPE APAParkProcNextStepDirChangedReturnSteeringToZeroVehMaxStaticTime;
	1800, // def: 800, // def: 1.5m + 3.1m, APA_DISTANCE_TYPE APAParkProcMinPassDeltaDisToDeletFirstSlotAfterSecondSlotFound; // This delta dis is based on APASlotMinPathAfterSlot.
	1500, // 100cm, APA_DISTANCE_TYPE APAParkProcCarPosYPassSlotDeltaDisToRecalTrajWithFirstStepFwVeryLowSpd;
	300, // 30cm, APA_DISTANCE_TYPE APAParkProcCarPassSlotDeltaDisToRecalTrajWithFirstStepFwVeryLowSpd;
	3000, // 200cm, APA_DISTANCE_TYPE APAParkProcCarPassSlotDeltaDisToRecalTrajWithFirstStepBk;
	3000, // 200cm, APA_DISTANCE_TYPE APAParkProcCarPassSlotDeltaDisToRecalTrajWithSlotNotConfirmed;
	500, // 50cm, APA_DISTANCE_TYPE APAParkProcCarPassSlotDeltaDisToRecalTrajWithSecondSlotFound; // 50cm.

	-1500, // 0, def: -1m. APA_DISTANCE_TYPE APAParkProcInSlotCarPosYCriteria1;
	2.5 / 3.6, // 2.5kph, APA_SPEED_TYPE APAParkProcInSlotCarPosXOffsetDisDevideSpeed; // 2.5kph
	30, // 1cm, APA_DISTANCE_TYPE APAParkProcInSlotCarPosXMaxOffsetDisHighSpeedBk; // 1cm.
	100, // 7cm, APA_DISTANCE_TYPE APAParkProcInSlotCarPosXMaxOffsetDisHighSpeedFw; // 7cm.
	35, // 35, // 3.5cm, APA_DISTANCE_TYPE APAParkProcInSlotCarPosXMinOffsetDis;
	250.0, // APA_CAL_FLOAT_TYPE APAParkProcInSlotCarPosXOffsetFactorWithCurb;
	50, // kjy changed to 5cm 2014 09 23. 70, // 7cm, APA_DISTANCE_TYPE APAParkProcInSlotCarPosXMaxOffsetDisWithCurb;
	350.0, //APA_CAL_FLOAT_TYPE APAParkProcInSlotCarPosXRightOffsetFactorWithoutCurb;
	350.0, //APA_CAL_FLOAT_TYPE APAParkProcInSlotCarPosXLeftOffsetFactorWithoutCurb;
	60, // kjy changed to 5cm 2014 09 23. 70, // 70, //APA_DISTANCE_TYPE APAParkProcInSlotCarPosXMaxRightOffsetDisWithoutCurb;
	150, // 120, //APA_DISTANCE_TYPE APAParkProcInSlotCarPosXMaxLeftOffsetDisWithoutCurb;
	5.0 * PI / 180.0, // 5deg, APA_ANGLE_TYPE APAParkProcInSlotCarPosXMaxOffsetDisDevidedAng; // 5deg.
	30, // 3cm, APA_DISTANCE_TYPE APAParkProcInSlotCarPosXMaxOffsetDisTol; // 3cm
	5000.0, // APA_CAL_FLOAT_TYPE APAParkProcInSlotCarPosYDriveDisFactor;
	300, // 30cm, APA_DISTANCE_TYPE APAParkProcInSlotCarPosYDriveDisCompValue;
	1500, // 1.8m, APA_DISTANCE_TYPE APAParkProcInSlotCarCanDrvFwDisWithoutObjAtRear;
	0.5, // 0.7, // APA_CAL_FLOAT_TYPE APAParkProcInSlotCarCanDrvFwDisFactorWithObjAtRear;
	1800, // 1.8m APA_DISTANCE_TYPE APAParkProcInSlotCarCanDrvBkDisWithoutObjAtFront;
	0.5, // 0.75, // APA_CAL_FLOAT_TYPE APAParkProcInSlotCarCanDrvBkDisFactorWithObjAtFront;
	0.65, // kjy changed 2014 06 13 Car can drv total dis (Fw + Bk, remove safety dis at front and rear) * 0.55, APA_CAL_FLOAT_TYPE APAParkProcInSlotCarShouldDrvMinDisFactorWithOneGearShift;
	100, // 20cm->7cm, // kjy 2014 05 29 changed. 400->200 20cm, APA_DISTANCE_TYPE APAParkProcInSlotCarShouldDrvMinDisWithOneGearShift;
	700, // 70cm, APA_DISTANCE_TYPE APAParkProcInSlotCarShouldDrvMinDisWithBigSlotLen;
	5000, // 3m, APA_DISTANCE_TYPE APAParkProcInSlotCarShouldDrvFwDisWithoutObjAtRear;
	5000, // 4m, APA_DISTANCE_TYPE APAParkProcInSlotCarShouldDrvBkDisWithoutObjAtFront;
	600, // 60cm, APA_DISTANCE_TYPE APAParkProcInSlotCarResumeToTheSameDriveDirectionMinCarCanDrvDeltaDis;	
	150, // 15cm, APA_DISTANCE_TYPE APAParkProcInSlotAllowCarEndPosAchievedMinCarDrvDisWithOneGearShift;
	1500, // 35cm, APA_DISTANCE_CAL_FLOAT_TYPE APAParkProcInSlotCarResetProgressPercentageCarOverDrvDis; // 35cm.

	800, // 80cm, APA_DISTANCE_TYPE APAParkProcInSlotCarUpdateProgressPercentageTargetPosMaxObjDis;

	//(2500 + 1000) / APA_PARKPROC_PARKING_PROCESS_TASK_CALL_CYCLE_TIME, // 2.5s, =  3s.// APA_MS_TIME_TYPE APAParkProcSnsDtNearestDisUpdateTime; // 5s
	//(400 + 1000) / APA_PARKPROC_PARKING_PROCESS_TASK_CALL_CYCLE_TIME, //  1s.// APA_MS_TIME_TYPE APAParkProcSnsDtNearestIncreasingDisUpdateTime; // 5s
	//(1000 - 100) / APA_PARKPROC_PARKING_PROCESS_TASK_CALL_CYCLE_TIME, // APA_MS_TIME_TYPE APAParkProcSnsDtNearestDisUpdateTimeWhenCarIsMoving; // 0s, will update the dis immediately.
	//1000 / APA_PARKPROC_PARKING_PROCESS_TASK_CALL_CYCLE_TIME, // 1s. APA_MS_TIME_TYPE APAParkProcSnsDtNearestDisUpdateHoldTime; // 1s 2014 05 15
	// APA_DISTANCE_TYPE APAParkProcSnsDtNearestDisUpdateMinThresholdDis[APA_SNS_DTD_NEAREST_OBJ_DIS_REGION_NUM];
	{
		500, // 45cm, RS sns.
		500, // 50cm, R sns.
		600, // 60cm, Mid sns.
		500, // 50cm, L sns.
		500 // 45cm,
	},

	30, //50,//def 50mm,APA_DISTANCE_TYPE APAParkProcSensorDetectDisUpdateThreshold;// 2014 05 15
	4, //5,//APA_ENUM_TYPE MaxSnsDetectObjPtCntRegardAsObjDisIncreasing;//2014 05 21 the buffer size is 10.
	100,//def 100mm,APA_DISTANCE_TYPE APAParkProcSensorDetectRagardAsDisIncreasingTolerance;// 2014 05 15
	100, //50,//def 50mm,APA_DISTANCE_TYPE APAParkProcSensorDetectDisDecreasingTolerance;// 2014 05 15

	300, // 20cm, APA_DISTANCE_TYPE APAParkProcInLineStepReCalTrajMaxCarToTargetPosDis; // 20cm. 

	250, // 25cm, APA_DISTANCE_TYPE APAParkProcInStep3ReCalTrajMinDeltaDisWithTargetPosCanNotAchieved; 
	900, // 1500, // 1.5m, APA_DISTANCE_TYPE APAParkProcInStep3ReCalTrajMinObjDisAtRear; 
	1.5 * PI / 180.0, // 1.5deg, APA_ANGLE_TYPE APAParkProcInStep3ReCalTrajMinDeviateCarAngFromCalTrajectory; // 1.5deg.
	100, // 10cm, //APA_DISTANCE_TYPE APAParkProcInStep3ReCalTrajMinDeviateDisFromCalTrajectory;  // 10cm.
	2.5 * PI / 180.0, // 1.5deg, APA_ANGLE_TYPE APAParkProcInStep3ReCalTrajMinDeviateCarAngFromCalTrajectory2; // 1.0deg.

	350, // 35cm. APA_DISTANCE_TYPE APAParkProcCarMayHitFrontCornerObjStartCorFRSDis;
	320, // 35cm. APA_DISTANCE_TYPE APAParkProcCarMayHitFrontCornerObjStartCorFRDis;
	450, // 45cm. APA_DISTANCE_TYPE APAParkProcCarMayHitFrontCornerObjStopCorFRSDis;
	420, // 45cm. APA_DISTANCE_TYPE APAParkProcCarMayHitFrontCornerObjStopCorFRDis;
	
	350, // changed by kjy 2014 06 30 from 300 back to 350. 300, // 35cm. APA_DISTANCE_TYPE APAParkProcCarMayHitFrontCornerObjStartCorRRSDis;
	400, // 35cm. APA_DISTANCE_TYPE APAParkProcCarMayHitFrontCornerObjStartCorRRDis;
	420, // changed by kjy 2014 06 30 from 400 to 420.400, // 45cm. APA_DISTANCE_TYPE APAParkProcCarMayHitFrontCornerObjStopCorRRSDis;
	500, // 55cm. APA_DISTANCE_TYPE APAParkProcCarMayHitFrontCornerObjStopCorRRDis;

	4.0 * PI / 180.0, // 4deg. ANA_ANGLE_TYPE APAParkProcEndPosAngAchievedAllowCorSteeringAngMaxCarAng;
	100, //10cm, 30cm, def: 50cm, APA_DISTANCE_TYPE APAParkProcEndPosAngAchievedAllowCorSteeringCarToEndPosMinDis; // 50cm.
	300, // 30cm, APA_DISTANCE_TYPE APAParkProcEndPosAngAchievedAllowCorSteeringCarDrvDis1; // 30cm
	700, // 70cm, APA_DISTANCE_TYPE APAParkProcEndPosAngAchievedAllowCorSteeringCarDrvDis2; // 70cm
	0.1 * 32.0 * PI / 180.0, // 0.1, 0.25 * MaxSteeringWheelAngle. 25%// , // APA_ANGLE_TYPE APAParkProcEndPosAngAchievedAllowCorSteeringMinAng; // 12% steering.: car will move 77.56cm for 1deg car angle.
	0.2 * 32.0 * PI / 180.0, // 0.2, 0.25 * MaxSteeringWheelAngle. 25%// APA_ANGLE_TYPE APAParkProcEndPosAngAchievedAllowCorSteeringMaxAng; // 25% steering.: car will move 30.8cm for 1deg car angle.
	0.4 * PI / 180.0, //0.6 * PI / 180.0, // it shold be less than car end pos car angle min tol APA_ANGLE_TYPE APAParkProcEndPosAngAchievedAllowStartCorSteeringAngMinCarAng; // 25% steering.: car will move 30.8cm for 1deg car angle.
	0.2 * PI / 180.0, //0.3 * PI / 180.0, // it shold be less than car end pos car angle min tol APA_ANGLE_TYPE APAParkProcEndPosAngAchievedAllowStopCorSteeringAngMaxCarAng; // 25% steering.: car will move 30.8cm for 1deg car angle.
	150, // 15cm, APA_DISTANCE_TYPE APAParkProcEndPosAngAchievedAllowCorSteeringBkToZeroCarDrvDis; // 15cm.
	100, // 10cm, 30cm,APA_DISTANCE_TYPE APAParkProcEndPosAngAchievedAllowCorSteeringMinCarDrvDis; // 30cm.

	5.0 * PI / 180.0, // 5deg, APA_ANGLE_TYPE APAParkProcInStep3AllowCorSteeringAngMinCarAng; // 5deg
	500, // 50cm, // APA_DISTANCE_TYPE APAParkProcInStep3AllowCorSteeringAngMinRearBumperToObj1Dis; // 50cm.


	50, // 5cm, def: 10cm, APA_DISTANCE_TYPE APAParkProcPCarParkingAllowedDeviateDisFromCalTrajectory;	// 10cm ??
	1.5 * PI / 180.0, // 1.5deg, def: 2deg. APA_ANGLE_TYPE APAParkProcPCarParkingAllowedDeviateCarAngFromCalTrajectory;	// 2deg ??

	1, // APA_ENUM_TYPE APAParkProcPCarParkingCarEndPositionAchivedAllowDrvFwBkNum;
	1.0 * PI / 180.0, //0.8 * PI / 180.0, // 0.9 * PI / 180.0, // 2 deg, APA_ANGLE_TYPE APAParkProcPCarEndPositionCarAngTol00;
	1.5 * PI / 180.0, //1.2 * PI / 180.0, // 0.9 * PI / 180.0, // 2 deg, APA_ANGLE_TYPE APAParkProcPCarEndPositionCarAngTol01;
	1.8 * PI / 180.0, //1.2 * PI / 180.0, // 0.9 * PI / 180.0, // 2 deg, APA_ANGLE_TYPE APAParkProcPCarEndPositionCarAngTol;
	2.2 * PI / 180.0,// 1.8 * PI / 180.0, // 2 deg, APA_ANGLE_TYPE APAParkProcPCarEndPositionCarAngTol2;
	2.2 * PI / 180.0,// 1.8 * PI / 180.0, // 2 deg, APA_ANGLE_TYPE 	APA_ANGLE_TYPE APAParkProcPCarEndPositionCarAngTol2WithOnlyOneObj;
	4.0 * PI / 180.0, // 2.8 * PI / 180.0,// 2.2 * PI / 180.0, // 3 deg, APA_ANGLE_TYPE APAParkProcPCarEndPositionCarAngTol3;
	450, // 450cm, APA_DISTANCE_TYPE APAParkProcPSafetyDisToObjByFSnsDtdOutOfSlot; // 450. // 45cm.
	450, // kjy changed to 45cm. 2014 08 20. 550, //450, // APA_DISTANCE_TYPE APAParkProcPSafetyDisToObjBySnsDtdInFirstDrvBkStep;
	300, // 30cm APA_DISTANCE_TYPE APAParkProcPSafetyDisToCornerObjBySnsDtd;	
	400, // 40cm APA_DISTANCE_TYPE APAParkProcPSafetyDisToMidObjBySnsDtd;
	350, // 400, // changed to 35cm, kjy: 2014 12 05, def:45cm APA_DISTANCE_TYPE  APAParkProcPSafetyDisToSideObjInBigSlotBySnsDtd;
	450, // def: 45cm APA_DISTANCE_TYPE APAParkProcPAfterStopCmdShownMinDisToObjToChangeDrvDir;


	150, // 15cm, APA_DISTANCE_TYPE APAParkProcPStartCheckCarWillHitSideObjCarPosDeltaY;
	25.0 * PI / 180.0, // 15deg. APA_ANGLE_TYPE APAParkProcPStartCheckCarWillHitSideObjDeltaCarAng;

#ifdef APA_SYSTEM_WITH_10_CH

	#ifdef APA_WITH_NORMAL_CORNER_UPA_SNS_POSITION

	// delta car angle < 15 deg.
	900, // 70cm. APA_DISTANCE_TYPE APAParkProcPCarShouldDriveFwInSoltMinRRSSnsDis1;
	1000, // 80cm. APA_DISTANCE_TYPE APAParkProcPCarShouldDriveFwInSoltMinRRSnsDis1;
	350, // 45cm. APA_DISTANCE_TYPE APAParkProcPCarShouldDriveFwInSoltMinRLSSnsDis1;
	650, // 55cm. APA_DISTANCE_TYPE APAParkProcPCarShouldDriveFwInSoltMinRLSnsDis1;

	// delta car angle > 15deg.
	900, // 70cm. APA_DISTANCE_TYPE APAParkProcPCarShouldDriveFwInSoltMinRRSSnsDis2;
	1000, // 80cm. APA_DISTANCE_TYPE APAParkProcPCarShouldDriveFwInSoltMinRRSnsDis2;
	350, // 45cm. APA_DISTANCE_TYPE APAParkProcPCarShouldDriveFwInSoltMinRLSSnsDis2;
	450, // 55cm. APA_DISTANCE_TYPE APAParkProcPCarShouldDriveFwInSoltMinRLSnsDis2;

	#else
	
	900, // 70cm. APA_DISTANCE_TYPE APAParkProcPCarShouldDriveFwInSoltMinRRSSnsDis1;
	1000, // 80cm. APA_DISTANCE_TYPE APAParkProcPCarShouldDriveFwInSoltMinRRSnsDis1;
	350, // 45cm. APA_DISTANCE_TYPE APAParkProcPCarShouldDriveFwInSoltMinRLSSnsDis1;
	450, // 55cm. APA_DISTANCE_TYPE APAParkProcPCarShouldDriveFwInSoltMinRLSnsDis1;
	
	900, // 70cm. APA_DISTANCE_TYPE APAParkProcPCarShouldDriveFwInSoltMinRRSSnsDis2;
	1000, // 80cm. APA_DISTANCE_TYPE APAParkProcPCarShouldDriveFwInSoltMinRRSnsDis2;
	350, // 45cm. APA_DISTANCE_TYPE APAParkProcPCarShouldDriveFwInSoltMinRLSSnsDis2;
	450, // 55cm. APA_DISTANCE_TYPE APAParkProcPCarShouldDriveFwInSoltMinRLSnsDis2;

	#endif

#else
	900, // 70cm. APA_DISTANCE_TYPE APAParkProcPCarShouldDriveFwInSoltMinRRSSnsDis1;
	1000, // 80cm. APA_DISTANCE_TYPE APAParkProcPCarShouldDriveFwInSoltMinRRSnsDis1;
	350, // 45cm. APA_DISTANCE_TYPE APAParkProcPCarShouldDriveFwInSoltMinRLSSnsDis1;
	450, // 55cm. APA_DISTANCE_TYPE APAParkProcPCarShouldDriveFwInSoltMinRLSnsDis1;
	
	900, // 70cm. APA_DISTANCE_TYPE APAParkProcPCarShouldDriveFwInSoltMinRRSSnsDis2;
	1000, // 80cm. APA_DISTANCE_TYPE APAParkProcPCarShouldDriveFwInSoltMinRRSnsDis2;
	350, // 45cm. APA_DISTANCE_TYPE APAParkProcPCarShouldDriveFwInSoltMinRLSSnsDis2;
	450, // 55cm. APA_DISTANCE_TYPE APAParkProcPCarShouldDriveFwInSoltMinRLSnsDis2;
#endif

	//APASnsDtdNearestObjDisDataType APAParkProcPCarCanDrvFwMinDisToObjBySnsDtd[APA_PARKPROC_CAR_CAN_DRV_MIN_DIS_TO_OBJ_BY_SNS_DTD_SCENARIO_NUM][APA_PARKPROC_CAR_DRV_CIRCLE_SIDE_NUM]; // car drive forward, will only check front obj.
	{
		
		//typedef enum {
		//	APAParkProcPCarCanDrvMinDisToObjBySnsDtdAngLess10degIndex = 0,
		//	APAParkProcPCarCanDrvMinDisToObjBySnsDtdAngGreat10degIndex	
		//} tAPAParkProcPCarCanDrvFwMinDisToObjBySnsDtdScenarioIndexType;

		//typedef enum {
		//	APAParkProcPCarDrvCircleLeftIndex = 0,
		//	APAParkProcPCarDrvCircleRightIndex	
		//} tAPAParkProcPCarDrvCircleSideIndexType;
		
		//	APAParkProcPCarCanDrvMinDisToObjBySnsDtdAngLess10degIndex = 0,
		{
			//	APAParkProcPCarDrvCircleLeftIndex = 0,
			{
				//typedef struct {
				300, // 30cm //	APA_DISTANCE_TYPE RSObjDis; // Obj detected by the R side sns. dis from 20cm ~ 200cm
				350, // 40cm //	APA_DISTANCE_TYPE RObjDis; // Obj detected by the R corner sns. dis from 20cm ~ 200cm
				500, // 80cm //	APA_DISTANCE_TYPE MidObjDis; // Obj detected by the RM, LM, R tx RM Rx, RM tx R Rx, L tx LM rx, LM tx L rx. UPA FOV.
				400, // 45cm //	APA_DISTANCE_TYPE LObjDis; // Obj detected by the L corner sns. dis from 20cm ~ 200cm
				300 // 40cm //	APA_DISTANCE_TYPE LSObjDis; // Obj detected by the L side sns. dis from 20cm ~ 200cm
				//} APASnsDtdNearestObjDisDataType;
			},
			//	APAParkProcPCarDrvCircleRightIndex	
			{
				//typedef struct {
				300, // 40cm //	APA_DISTANCE_TYPE RSObjDis; // Obj detected by the R side sns. dis from 20cm ~ 200cm
				400, // 45cm //	APA_DISTANCE_TYPE RObjDis; // Obj detected by the R corner sns. dis from 20cm ~ 200cm
				500, // 80cm //	APA_DISTANCE_TYPE MidObjDis; // Obj detected by the RM, LM, R tx RM Rx, RM tx R Rx, L tx LM rx, LM tx L rx. UPA FOV.
				350, // 40cm //	APA_DISTANCE_TYPE LObjDis; // Obj detected by the L corner sns. dis from 20cm ~ 200cm
				300 // 30cm //	APA_DISTANCE_TYPE LSObjDis; // Obj detected by the L side sns. dis from 20cm ~ 200cm
				//} APASnsDtdNearestObjDisDataType;
			}
		},
		//	APAParkProcPCarCanDrvMinDisToObjBySnsDtdAngGreat10degIndex	
		{
			//	APAParkProcPCarDrvCircleLeftIndex = 0,
			{
				//typedef struct {
				300, // 30cm //	APA_DISTANCE_TYPE RSObjDis; // Obj detected by the R side sns. dis from 20cm ~ 200cm
				300, // 40cm //	APA_DISTANCE_TYPE RObjDis; // Obj detected by the R corner sns. dis from 20cm ~ 200cm
				500, // 80cm //	APA_DISTANCE_TYPE MidObjDis; // Obj detected by the RM, LM, R tx RM Rx, RM tx R Rx, L tx LM rx, LM tx L rx. UPA FOV.
				400, // 60cm //	APA_DISTANCE_TYPE LObjDis; // Obj detected by the L corner sns. dis from 20cm ~ 200cm
				350 // 50cm //	APA_DISTANCE_TYPE LSObjDis; // Obj detected by the L side sns. dis from 20cm ~ 200cm
				//} APASnsDtdNearestObjDisDataType;
			},
			//	APAParkProcPCarDrvCircleRightIndex	
			{
				//typedef struct {
				350, // 50cm //	APA_DISTANCE_TYPE RSObjDis; // Obj detected by the R side sns. dis from 20cm ~ 200cm
				400, // 60cm //	APA_DISTANCE_TYPE RObjDis; // Obj detected by the R corner sns. dis from 20cm ~ 200cm
				500, // 80cm //	APA_DISTANCE_TYPE MidObjDis; // Obj detected by the RM, LM, R tx RM Rx, RM tx R Rx, L tx LM rx, LM tx L rx. UPA FOV.
				300, // 40cm //	APA_DISTANCE_TYPE LObjDis; // Obj detected by the L corner sns. dis from 20cm ~ 200cm
				300 // 30cm //	APA_DISTANCE_TYPE LSObjDis; // Obj detected by the L side sns. dis from 20cm ~ 200cm
				//} APASnsDtdNearestObjDisDataType;
			}
		}		
	},
	//APASnsDtdNearestObjDisDataType APAParkProcPCarCanDrvBkMinDisToObjBySnsDtd[APA_PARKPROC_CAR_CAN_DRV_MIN_DIS_TO_OBJ_BY_SNS_DTD_SCENARIO_NUM][APA_PARKPROC_CAR_DRV_CIRCLE_SIDE_NUM][PA_SYS_NUM]; // car drive bk, will check both rear and front obj.
	{
		
		//typedef enum {
		//	APAParkProcPCarCanDrvMinDisToObjBySnsDtdAngLess10degIndex = 0,
		//	APAParkProcPCarCanDrvMinDisToObjBySnsDtdAngGreat10degIndex	
		//} tAPAParkProcPCarCanDrvFwMinDisToObjBySnsDtdScenarioIndexType;

		//typedef enum {
		//	APAParkProcPCarDrvCircleLeftIndex = 0,
		//	APAParkProcPCarDrvCircleRightIndex	
		//} tAPAParkProcPCarDrvCircleSideIndexType;
		
		//	APAParkProcPCarCanDrvMinDisToObjBySnsDtdAngLess10degIndex = 0,
		{
			//	APAParkProcPCarDrvCircleLeftIndex = 0,
			{
				// PARearSys = 0
				{
					//typedef struct {
					0, // 0cm, will not check RRS. //	APA_DISTANCE_TYPE RSObjDis; // Obj detected by the R side sns. dis from 20cm ~ 200cm
					300, //kjy changed 2014 08 14 350, // 40cm //	APA_DISTANCE_TYPE RObjDis; // Obj detected by the R corner sns. dis from 20cm ~ 200cm
					400, //kjy changed 2014 08 14  500, // 80cm //	APA_DISTANCE_TYPE MidObjDis; // Obj detected by the RM, LM, R tx RM Rx, RM tx R Rx, L tx LM rx, LM tx L rx. UPA FOV.
					300, //kjy changed 2014 08 14  350, // 50cm //	APA_DISTANCE_TYPE LObjDis; // Obj detected by the L corner sns. dis from 20cm ~ 200cm
					300 // 40cm //	APA_DISTANCE_TYPE LSObjDis; // Obj detected by the L side sns. dis from 20cm ~ 200cm
					//} APASnsDtdNearestObjDisDataType;
				},
				// PAFrontSys
				{
					//typedef struct {
					300, // kjy changed 2014 08 14  350, // 40cm //	APA_DISTANCE_TYPE RSObjDis; // Obj detected by the R side sns. dis from 20cm ~ 200cm
					350, //400, // 50cm //	APA_DISTANCE_TYPE RObjDis; // Obj detected by the R corner sns. dis from 20cm ~ 200cm
					0, // 0cm //	APA_DISTANCE_TYPE MidObjDis; // Obj detected by the RM, LM, R tx RM Rx, RM tx R Rx, L tx LM rx, LM tx L rx. UPA FOV.
					0, // 0cm //	APA_DISTANCE_TYPE LObjDis; // Obj detected by the L corner sns. dis from 20cm ~ 200cm
					0 // 0cm //	APA_DISTANCE_TYPE LSObjDis; // Obj detected by the L side sns. dis from 20cm ~ 200cm
					//} APASnsDtdNearestObjDisDataType;
				}
			},
			//	APAParkProcPCarDrvCircleRightIndex	
			{
				// PARearSys = 0
				{
					//typedef struct {
					300, // 40cm, will not check RRS. //	APA_DISTANCE_TYPE RSObjDis; // Obj detected by the R side sns. dis from 20cm ~ 200cm
					300, // 350, // 60cm //	APA_DISTANCE_TYPE RObjDis; // Obj detected by the R corner sns. dis from 20cm ~ 200cm
					400, // 500, // 80cm //	APA_DISTANCE_TYPE MidObjDis; // Obj detected by the RM, LM, R tx RM Rx, RM tx R Rx, L tx LM rx, LM tx L rx. UPA FOV.
					300, // 350, // 50cm //	APA_DISTANCE_TYPE LObjDis; // Obj detected by the L corner sns. dis from 20cm ~ 200cm
					0 // 0cm //	APA_DISTANCE_TYPE LSObjDis; // Obj detected by the L side sns. dis from 20cm ~ 200cm
					//} APASnsDtdNearestObjDisDataType;
				},
				// PAFrontSys
				{
					//typedef struct {
					0, // 0cm //	APA_DISTANCE_TYPE RSObjDis; // Obj detected by the R side sns. dis from 20cm ~ 200cm
					0, // 0cm //	APA_DISTANCE_TYPE RObjDis; // Obj detected by the R corner sns. dis from 20cm ~ 200cm
					0, // 0cm //	APA_DISTANCE_TYPE MidObjDis; // Obj detected by the RM, LM, R tx RM Rx, RM tx R Rx, L tx LM rx, LM tx L rx. UPA FOV.
					350, // 400, // 50cm //	APA_DISTANCE_TYPE LObjDis; // Obj detected by the L corner sns. dis from 20cm ~ 200cm
					300, // 350 // 40cm //	APA_DISTANCE_TYPE LSObjDis; // Obj detected by the L side sns. dis from 20cm ~ 200cm
					//} APASnsDtdNearestObjDisDataType;
				}
			}
		},
		//	APAParkProcPCarCanDrvMinDisToObjBySnsDtdAngGreat10degIndex	
		{
			//	APAParkProcPCarDrvCircleLeftIndex = 0,
			{
				// PARearSys = 0
				{
					//typedef struct {
					0, // 0cm, will not check RRS. //	APA_DISTANCE_TYPE RSObjDis; // Obj detected by the R side sns. dis from 20cm ~ 200cm
					450, // 50cm //	APA_DISTANCE_TYPE RObjDis; // Obj detected by the R corner sns. dis from 20cm ~ 200cm
					500, // 80cm //	APA_DISTANCE_TYPE MidObjDis; // Obj detected by the RM, LM, R tx RM Rx, RM tx R Rx, L tx LM rx, LM tx L rx. UPA FOV.
					400, // 50cm //	APA_DISTANCE_TYPE LObjDis; // Obj detected by the L corner sns. dis from 20cm ~ 200cm
					350 // 40cm //	APA_DISTANCE_TYPE LSObjDis; // Obj detected by the L side sns. dis from 20cm ~ 200cm
					//} APASnsDtdNearestObjDisDataType;
				},
				// PAFrontSys
				{
					//typedef struct {
					400, // 50cm //	APA_DISTANCE_TYPE RSObjDis; // Obj detected by the R side sns. dis from 20cm ~ 200cm
					400, // 60cm //	APA_DISTANCE_TYPE RObjDis; // Obj detected by the R corner sns. dis from 20cm ~ 200cm
					0, // 0cm //	APA_DISTANCE_TYPE MidObjDis; // Obj detected by the RM, LM, R tx RM Rx, RM tx R Rx, L tx LM rx, LM tx L rx. UPA FOV.
					0, // 0cm //	APA_DISTANCE_TYPE LObjDis; // Obj detected by the L corner sns. dis from 20cm ~ 200cm
					0 // 0cm //	APA_DISTANCE_TYPE LSObjDis; // Obj detected by the L side sns. dis from 20cm ~ 200cm
					//} APASnsDtdNearestObjDisDataType;
				}
			},
			//	APAParkProcPCarDrvCircleRightIndex	
			{
				// PARearSys = 0
				{
					//typedef struct {
					350, // 40cm, will not check RRS. //	APA_DISTANCE_TYPE RSObjDis; // Obj detected by the R side sns. dis from 20cm ~ 200cm
					400, // 60cm //	APA_DISTANCE_TYPE RObjDis; // Obj detected by the R corner sns. dis from 20cm ~ 200cm
					500, // 80cm //	APA_DISTANCE_TYPE MidObjDis; // Obj detected by the RM, LM, R tx RM Rx, RM tx R Rx, L tx LM rx, LM tx L rx. UPA FOV.
					450, // 50cm //	APA_DISTANCE_TYPE LObjDis; // Obj detected by the L corner sns. dis from 20cm ~ 200cm
					0 // 0cm //	APA_DISTANCE_TYPE LSObjDis; // Obj detected by the L side sns. dis from 20cm ~ 200cm
					//} APASnsDtdNearestObjDisDataType;
				},
				// PAFrontSys
				{
					//typedef struct {
					0, // 0cm //	APA_DISTANCE_TYPE RSObjDis; // Obj detected by the R side sns. dis from 20cm ~ 200cm
					0, // 0cm //	APA_DISTANCE_TYPE RObjDis; // Obj detected by the R corner sns. dis from 20cm ~ 200cm
					0, // 0cm //	APA_DISTANCE_TYPE MidObjDis; // Obj detected by the RM, LM, R tx RM Rx, RM tx R Rx, L tx LM rx, LM tx L rx. UPA FOV.
					400, // 600cm //	APA_DISTANCE_TYPE LObjDis; // Obj detected by the L corner sns. dis from 20cm ~ 200cm
					400 // 500cm //	APA_DISTANCE_TYPE LSObjDis; // Obj detected by the L side sns. dis from 20cm ~ 200cm
					//} APASnsDtdNearestObjDisDataType;
				}
			}
		}		
	},
	// APASnsDtdNearestObjDisInfoType APAParkProcPAllowToChangeDriveDirectionMinDisToObjBySnsDtd;//[PA_SYS_NUM];
	{
		//typedef struct {
		380, // 40cm, will not check RRS. //	APA_DISTANCE_TYPE RSObjDis; // Obj detected by the R side sns. dis from 20cm ~ 200cm
		700, // 60cm //	APA_DISTANCE_TYPE RObjDis; // Obj detected by the R corner sns. dis from 20cm ~ 200cm
		1000, // 80cm //	APA_DISTANCE_TYPE MidObjDis; // Obj detected by the RM, LM, R tx RM Rx, RM tx R Rx, L tx LM rx, LM tx L rx. UPA FOV.
		700, // 50cm //	APA_DISTANCE_TYPE LObjDis; // Obj detected by the L corner sns. dis from 20cm ~ 200cm
		380 // 0cm //	APA_DISTANCE_TYPE LSObjDis; // Obj detected by the L side sns. dis from 20cm ~ 200cm
		//} APASnsDtdNearestObjDisDataType;
	},
	500, // 50cm, APA_DISTANCE_TYPE APAParkProcPRegardedAsCarCloseToObjMinDeltaY;

	// 2000 / APA_PARKPROC_DRIVER_INFO_OUTPUT_TASK_CALL_CYCLE_TIME, // 2s,	APA_MS_TIME_TYPE APAParkProcPAllowToChangeDriveDirectionMinDelayTime;

	APA_PARKPROC_CAR_END_POSITION_MID_BETWEEN_OBJ1_AND_OBJ2,   //APA_ENUM_TYPE APAParkProcPCarEndPosition;
	APA_PARKPROC_CAR_END_POSITION_CLOSE_TO_OBJ2,   //APA_ENUM_TYPE APAParkProcPCarEndPositionWithSlotLenGreatThanAGivenSlot;
	2200, // kjy changed from 1.8m to 2.2m 2015 01 06; 1800, // 2500, // 1000, // 1m,def: 1.5m  + 3500, APA_DISTANCE_TYPE APAParkProcPMinPassDeltaDisToDeletFirstSlotAfterSecondSlotFound; // This delta dis is based on APASlotPMinPathAfterSlotWithObj2.
	2000, // 500, // def: 1m. APA_DISTANCE_TYPE APAParkProcPMinPassDeltaDisToDeletFirstSlotAfterSecondSlotFoundWithoutObj2; // This delta dis is based on the car min pass dis after slot found.
	1000, // 100cm, APA_DISTANCE_TYPE APAParkProcPCarPosYPassSlotDeltaDisToRecalTrajWithFirstStepFwVeryLowSpd;
	300, // 30cm, APA_DISTANCE_TYPE APAParkProcPCarPassSlotDeltaDisToRecalTrajWithFirstStepFwVeryLowSpd;
	3000, // 2m, APA_DISTANCE_TYPE APAParkProcPCarPassSlotDeltaDisToRecalTrajWithFirstStepBk;
	3000, // 200cm, APA_DISTANCE_TYPE APAParkProcPCarPassSlotDeltaDisToRecalTrajWithSlotNotConfirmed;
	500, // 50cm, APA_DISTANCE_TYPE APAParkProcPCarPassSlotDeltaDisToRecalTrajWithSecondSlotFound; // 50cm.

	//(50.0 / (1.0 / 3.6)), // 5cm / 1 km/h Spd * ratio = ahead dis.	APA_CAL_FLOAT_TYPE APAParkProcPPresShowStopCmdRatioOfSpdAndDis; //  APA_PARKPROC_PRESHOW_STOP_CMD_RATIO_OF_SPD_AND_DIS
	10, // APA_ENUM_TYPE APAParkProcPCarMaxBackAndForwardCorrectCntInStep3456;	
	300, // 30cm, APA_DISTANCE_TYPE APAParkProcPCarRegardOneDrvFwAndBkStepMinDeltaDis;
	300, // 30cm, APA_DISTANCE_TYPE APAParkProcPHasInformToChangeDriveDirCmdChechMinDeltaDis;
	3000, // 300cm, APA_DISTANCE_TYPE APAParkProcPAllowOutOfSlotCarDrvFwCorMaxY; // 300cm
	300, // 30cm, APA_DISTANCE_TYPE APAParkProcPAllowOutOfSlotCarDrvFwCorMinDis1; // 30cm
	700, // 70cm, APA_DISTANCE_TYPE APAParkProcPAllowOutOfSlotCarDrvFwCorMinDis2; // 70cm
	1200, // 120cm, APA_DISTANCE_TYPE APAParkProcPAllowOutOfSlotCarDrvFwCorMinDis3; // 120cm
	1200, // 120cm, APA_DISTANCE_TYPE APAParkProcPAllowInSlotCarDrvFwCorMinDis1; // 120cm
	1600, // 160cm, APA_DISTANCE_TYPE APAParkProcPAllowInSlotCarDrvFwCorMinDis2; // 160cm
	2000, // 200cm, APA_DISTANCE_TYPE APAParkProcPAllowInSlotCarDrvFwCorMinDis3; // 200cm
	3000, // 300cm, APA_DISTANCE_TYPE APAParkProcPAllowInSlotCarDrvFwCorMinDis4; // 300cm
	3600, // 360cm, APA_DISTANCE_TYPE APAParkProcPAllowInSlotCarDrvFwCorMinDis5; // 360cm
	200, // kjy changed from -50cm to 20cm, 2014 08 19,// -500,// 0, // def: -50cm, APA_DISTANCE_TYPE APAParkProcPCheckRecalTrajMinX;
	2800, // 2800, APA_DISTANCE_TYPE APAParkProcPCheckRecalTrajMinDeltaEndPosToCurCarPosX;
	-1000, // kjy changed from -50cm to 20cm, 2014 08 19,// -500,// 0, // def: -50cm, APA_DISTANCE_TYPE APAParkProcPCheckIfCarIsNotOnTrajRecalTrajMinX;
	500, // 50cm, APA_DISTANCE_TYPE APAParkProcPInSlotRecalTrajMinDeltaXDis;		// Lei 2020.08.20: 800 -> 500
	//(1500 / APA_STEERING_WHEEL_CTRL_TASK_CALL_CYCLE_TIME), // 50cm, APA_MS_TIME_TYPE APAParkProcPInSlotRecalTrajMinDeltaTime;
	
	// (200 / APA_STEERING_WHEEL_CTRL_TASK_CALL_CYCLE_TIME), // 200ms, kjy changed to 400ms 2014 07 24. def:800ms, APA_MS_TIME_TYPE wParkProcPSteeringWheelAngleHoldTime; 
	// (800 / APA_STEERING_WHEEL_CTRL_TASK_CALL_CYCLE_TIME), // 200ms, 800ms, APA_MS_TIME_TYPE wParkProcPCorrectSteeringWheelAngleHoldTime; 
	// (1500 / APA_STEERING_WHEEL_CTRL_TASK_CALL_CYCLE_TIME), // 1.5s, APA_MS_TIME_TYPE wParkProcPRecalTrajSteeringAngleAchievedDelyTimeInStep3; 
	// (500 / APA_STEERING_WHEEL_CTRL_TASK_CALL_CYCLE_TIME), // 0.5s, def: 0.3s, APA_MS_TIME_TYPE wParkProcPRecalTrajSteeringAngleAchievedDelayTime; 

	 -2200, // kjy changed to -2200 2014 11 11 //-1800, // -1.8m, APA_DISTANCE_TYPE APAParkProcPOutSlotCarCanDriveMinPosX;
	-1200, // -1.2 m, APA_DISTANCE_TYPE APAParkProcPOutSlotCarCanDriveMinPosXWhenCarAngAchieved;
	0, // 0cm, APA_DISTANCE_TYPE APAParkProcPRegardedAsInSlotCarMaxPosY;

	25.0 * PI / 180.0, // 25deg. APA_ANGLE_TYPE APAParkProcPCarMayHitFrontCornerObjCorDevidedCarAng; // 25deg.
	380, // kjy changed to 38cm. 2014 09 22. 420, // 350, // APA_DISTANCE_TYPE APAParkProcPCarMayHitFrontCornerObjStartCorRRSDis1; 
	400, // kjy changed to 400cm. 460, // 350, // APA_DISTANCE_TYPE APAParkProcPCarMayHitFrontCornerObjStartCorRRSDis2;
	400, // 470, // 420, // APA_DISTANCE_TYPE APAParkProcPCarMayHitFrontCornerObjStartCorRRDis1;
	450, // 520, // 420, // APA_DISTANCE_TYPE APAParkProcPCarMayHitFrontCornerObjStartCorRRDis2;
	50, // 80, // 8cm, // APA_DISTANCE_TYPE APAParkProcPCarMayHitFrontCornerObjStopCorRRSDis;
	70, // 100, // 10cm, // APA_DISTANCE_TYPE APAParkProcPCarMayHitFrontCornerObjStopCorRRDis;

	3.0 * PI / 180.0, // 3deg. APA_ANGLE_TYPE APAParkProcPInSlotStartUseCorSteeringAngleDeltaCarAngle
	2500, // 2.5m, APA_DISTANCE_TYPE APAParkProcPInSlotStartUseCorSteeringAngleDeltaXToEndPosDis;
	
	400, // 40cm. APA_DISTANCE_TYPE APAParkProcPStartUseCorSteeringAngleDeltaDisToKeyPoint;
	350, // 2014 07 21 kjy changed from 60cm to 35cm. 600, // 60cm, def: 20cm, APA_DISTANCE_TYPE APAParkProcPInSlotStartUseCorSteeringAngleDeltaXDis;
	600,// 60cm, def: 30cm, APA_DISTANCE_TYPE APAParkProcPInSlotStopUseCorSteeringAngleDeltaXDis;
	600, // 2014 07 21 kjy changed from 60cm to 40cm. 600, // 50cm, APA_DISTANCE_TYPE APAParkProcPInSlotAllowedToUseCorSteeringAngleMinDeltaXDis;
	0.9 * PI / 180.0, // 0.7 * PI / 180.0, //0.6 * PI / 180.0, //0.8 * PI / 180.0, // 1.1 * PI / 180.0, // APA_ANGLE_TYPE APAParkProcPInSlotStartUseCorSteeringAngleMinDeltaCarAng;
	0.3 * PI / 180.0, // 0.2 * PI / 180.0, //0.4 * PI / 180.0, //0.5 * PI / 180.0,  APA_ANGLE_TYPE APAParkProcPInSlotStopUseCorSteeringAngleMaxDeltaCarAng;
	//0.12 * 30.5 * PI / 180.0, // 0.12 * MaxSteeringWheelAngle. 12%//  APA_ANGLE_TYPE APAParkProcPInSlotUseCorSteeringAngleValue1;	// delta x dis  > 1m,
	//0.15 * 30.5 * PI / 180.0, // 0.15 * MaxSteeringWheelAngle. 15%//  APA_ANGLE_TYPE APAParkProcPInSlotUseCorSteeringAngleValue2;	// delta x dis  > 80cm.

	
	20.0 * PI / 180.0,//APA_ANGLE_TYPE APAParkProcPCarEnterSlotAllowRecalTrajMaxSteeringAng;	
	//400 / APA_STEERING_WHEEL_CTRL_TASK_CALL_CYCLE_TIME, // delay 500ms. APA_MS_TIME_TYPE APAParkProcPCarEnterSlotAllowRecalTrajMinSteeringWheelAngHoldTime;	
	150, // 15cm. APA_DISTANCE_TYPE APAParkProcPCarEnterSlotAllowRecalTrajMinCarDrvDis; // 15cm.

	0, // APA_DISTANCE_TYPE APAParkProcPInSlotUseRemainTheDrvFwMessageMinX; // 0cm
	-5000, // -5m, APA_DISTANCE_TYPE APAParkProcPInSlotUseRemainTheDrvBkMessageMinX; // -500cm, always enable.

	1000 , // 1m.  APA_DISTANCE_TYPE APAParkProcPAllowFirstStepCarDrvMaxDeltaXWithoutObj1; // car end pos.x / 2

	15.0 * PI / 180.0, // kjy changed from 3deg back to 15deg. APA_ANGLE_TYPE	APAParkProcTargetCarPosRegardAsEndPosCanBeAchievedByDrvBkMaxCarAng
	400, // 250, // APA_DISTANCE_TYPE APAParkProcPCarDrvBkProgressCompensateSafetyDisAtRCorner; // 0cm. 
	250, // 100, // APA_DISTANCE_TYPE APAParkProcPCarDrvBkProgressCompensateSafetyDisAtRCornerReduced; // 0cm. 
	0, // -10cm, APA_DISTANCE_TYPE APAParkProcPCarDrvBkProgressCompensateNormalSlotXDis; // - 10cm. // for big slot.
	0, // 20cm, APA_DISTANCE_TYPE APAParkProcPCarDrvBkProgressCompensateNormalSlotYDis; // 20cm. // for big slot.
	1000, // 1m, //450, // 45cm, APA_DISTANCE_CAL_FLOAT_TYPE APAParkProcPInSlotCarResetProgressPercentageCarOverDrvDis; // 45cm.
	1200, // 120cm, APA_DISTANCE_TYPE APAParkProcPProgressHitObj2InFwCorStepCarDrvMinDis; // 120cm.
	2000, // 200cm, APA_DISTANCE_TYPE APAParkProcPProgressHitObj2InFwCorStepCarDrvMaxDis; // 120cm.
	1000, // 1m, APA_DISTANCE_TYPE APAParkProcPProgressOutOfSlotFwStepCarDrvMinDis; // 100cm.
	-1200, // -120cm. APA_DISTANCE_TYPE APAParkProcPProgressInFwCorStepDrvBkWhenPerIs100MaxX; // -120cm.
	-1200, // APA_DISTANCE_TYPE APAParkProcPProgressInFwCorStepDrvMaxXWhenDeltaCarAngIsSmall; // -120cm. delta car angle < 20deg.
	100, // 10cm, APA_DISTANCE_TYPE APAParkProcPProgressInFwCorStepCompTrajCalPosDeltaX1; // 10cm. at delta car angle is 20deg.
	600, // 60cm, APA_DISTANCE_TYPE APAParkProcPProgressInFwCorStepCompTrajCalPosDeltaX2; // 60cm.    at delta car angle is 60deg.
	800, // 80cm, APA_DISTANCE_TYPE APAParkProcPProgressInFwStartCheckFwSnsDtDisMaxValue; // 80cm.
	-500, // -50cm, APA_DISTANCE_TYPE APAParkProcPProgressInFwStartCheckFwSnsDtDisCarPosMaxX; // -50 cm.
	1000, //100cm, APA_DISTANCE_TYPE APAParkProcPProgressInSlotFwStartCheckTargetPosMaxDeltaXDis; // 100 cm.
	50, // 50%, APA_ENUM_TYPE APAParkProcPProgressStartRecalTargetPosMinPercentage; // 50%
	1500, // 1.5m, APA_DISTANCE_TYPE APAParkProcPProgressInBkStartCheckTargetPosMaxDeltaYDis; // 150 cm.
	-1200, // -1.2m, APA_DISTANCE_TYPE APAParkProcPProgressInBkStartCheckTargetPosMinX; // - 120 cm.
	1200, // 1.2m, APA_DISTANCE_TYPE APAParkProcPProgressInBkStartCheckTargetPosMaxX;
	700, // 70cm, APA_DISTANCE_TYPE APAParkProcPProgressInBkStartCheckBkSnsDtDisMaxValue1; // 70cm.
	(37.0 * PI / 180.0), // 37deg, 30deg. APA_ANGLE_TYPE APAParkProcPProgressInBkStartCheckBkSnsDtDisMinDeltaCarAng1; // 30deg.
	500, // 50cm, APA_DISTANCE_TYPE APAParkProcPProgressInBkStartCheckBkSnsDtDisMaxValue2; // 50cm.
	(30.0 * PI / 180.0), // 30deg, 23deg. APA_ANGLE_TYPE APAParkProcPProgressInBkStartCheckBkSnsDtDisMinDeltaCarAng2; // 23deg.

#ifdef 	APA_WITH_NORMAL_CORNER_UPA_SNS_POSITION
	// cm, APA_DISTANCE_TYPE APAParkProcPCarPosDevideLineDeltaY[APA_PER_PREDICT_CAR_CAN_DRV_TARGET_POS_NUM];
	{50, 100, 200, 400, 500, 800, 1000, 800},

#else
	
	// cm, APA_DISTANCE_TYPE APAParkProcPCarPosDevideLineDeltaY[APA_PER_PREDICT_CAR_CAN_DRV_TARGET_POS_NUM];
	{50, 100, 200, 400, 600, 800, 1000, 1200},

#endif

	// APA_DISTANCE_TYPE APAParkProcPCarPosDevideLineDeltaX02; // 30cm,  or 20cm??
	250, // 25cm, def: 50cm. APA_DISTANCE_TYPE APAParkProcPCarPosDevideLineDeltaX01; // 50cm,  or 40cm??
	800, // 80cm, APA_DISTANCE_TYPE APAParkProcPCarPosDevideLineDeltaX0; // 80cm,   or 70cm??
	1500, // 150cm, APA_DISTANCE_TYPE APAParkProcPCarPosDevideLineDeltaX1; // 150cm
	3000, // 300cm, APA_DISTANCE_TYPE APAParkProcPCarPosDevideLineDeltaX2; // 300cm
	4500, // 450cm, APA_DISTANCE_TYPE APAParkProcPCarPosDevideLineDeltaX3; // 450cm
	5500, // 550cm, APA_DISTANCE_TYPE APAParkProcPCarPosDevideLineDeltaX4; // 550cm
	6000, // 600cm, APA_DISTANCE_TYPE APAParkProcPCarPosDevideLineDeltaX5; // 600cm

	(1.5 * PI / 180.0), // 1.5deg, APA_ANGLE_TYPE APAParkProcPCarPosDevideLineDeltaCarAng02; // 1.5deg
	//(2.5 * PI / 180.0), // 2.5degAPA_ANGLE_TYPE APAParkProcPCarPosDevideLineDeltaCarAng01; // 2.5deg
	(5.0 * PI / 180.0), // 5deg, APA_ANGLE_TYPE APAParkProcPCarPosDevideLineDeltaCarAng0; // 5deg
	(10.0 * PI / 180.0), // 10deg, APA_ANGLE_TYPE APAParkProcPCarPosDevideLineDeltaCarAng1; // 10deg
	(20.0 * PI / 180.0), // 20deg, APA_ANGLE_TYPE APAParkProcPCarPosDevideLineDeltaCarAng2; // 20deg
	(30.0 * PI / 180.0), // 30deg, APA_ANGLE_TYPE APAParkProcPCarPosDevideLineDeltaCarAng3; // 30deg
	(40.0 * PI / 180.0), // 40deg, APA_ANGLE_TYPE APAParkProcPCarPosDevideLineDeltaCarAng4; // 40deg
	
/*2.4.11.2 *** park exit ***/
	150,//wuzhen 0819 25 Luhui 20200805 2000 / APA_PARKPROC_PARKING_PROCESS_TASK_CALL_CYCLE_TIME, //APA_MS_TIME_TYPE  APAParkProcPEWaitingForSearchingForSlotTime;
	550, //APA_DISTANCE_TYPE APAParkProcPETightSlotMinTotalFrontAndRearSnsDtdDis;
	//100 / APA_PARKPROC_PARKING_PROCESS_TASK_CALL_CYCLE_TIME, // 1s. //APA_MS_TIME_TYPE APAParkProcPECarMayHitObjectStopWaitingTime;
    APAParkProcPECarEndPosCarWillNotHitFrontCornerObj, //APAParkProcPECarEndPosParallelToFrontObj , // APA_ENUM_TYPE APAParkProcPECarEndPosMode;
	PI / 4.0, //APA_ANGLE_TYPE APAParkProcPECarEndPosMaxCarAngle;						//modify pi/2 to pi/4 
	20.0 / 180.0 * PI,//APA_ANGLE_TYPE APAParkProcPECarEndPosMinCarAngle;
	4500, //APA_DISTANCE_TYPE APAParkProcPEAPAExitWithMaxCarPosY;
	600,  //APA_DISTANCE_TYPE APAParkProcPECarParkingCarEndPositionXDisTol;
//APA_TRAJCAL_GET_CAR_TURNING_RADIUS_CENTER(APACal.LenBetweenFRAxis, APACal.APATrajCalPELastStepAllowMinSteeringWheelAng);
//APA_TRAJCAL_GET_CAR_TURNING_RADIUS_FOuterCircle (APACal.LenBetweenRAxisAndFBumper, APACal.HalfWidthOfCar, APACal.APATrajCalPEMaxLastStepRCenterTurningRadius);	
	3.0 * PI / 180.0, //APA_ANGLE_TYPE APAParkProcPECarEndPositionCarAngTol;
	400,  //APA_DISTANCE_TYPE APAParkProcPEAllowCarDriveTowardsTheObjMinDis;
	600, // 60cm, APA_DISTANCE_TYPE APAParkProcPEStartCheckCarCanDrvOutOfSlotMinFrontObjDis; // def: 600cm.
	200, // 50cm, APA_DISTANCE_TYPE APAParkProcPECheckCarCanDrvOutOfSlotMinDeltaCarPosY; // def: 300cm.
	500, // 50cm, APA_DISTANCE_TYPE APAParkProcPERegardAsCarCanDrvOutOfSlotMinFrontObjDis; // def: 500cm.
	0, // 0cm, APA_DISTANCE_TYPE APAParkProcPERegardAsCarCanDrvOutOfSlotSaftetyDisAtFCorObjDrvFw; // def: 0cm. or -10cm ??
	300, // 30cm, APA_DISTANCE_TYPE APAParkProcPERegardAsCarCanDrvOutOfSlotSaftetyDisAtFCorObjDrvBk; // def: 0cm. or -10cm ??
	-200, // -20cm, APA_DISTANCE_TYPE APAParkProcPERegardAsCarCanDrvOutOfSlotSmallSafetyDis; // def: 0cm. or -10cm ??

	400, // def: 50cm, APA_DISTANCE_TYPE APAParkProcPEBigSafetyDisToObjAtFrontTurningCar; // when turning the car 
    450, // def: 55cm, APA_DISTANCE_TYPE APAParkProcPEBigSafetyDisToObjAtRearTurningCar; 
	6537, // car len + 2.0m APA_DISTANCE_TYPE APAParkProcPEUseBigSafetyDisToObjMinSlotLen; // when turning the car 

	400, // 40cm, APA_DISTANCE_TYPE APAParkProcPERecorObj2XCorrectStep; // def: 40cm.
	-1000, // -1m, APA_DISTANCE_TYPE APAParkProcPERecorObj2XAllowMinObj2X; // def: -100cm.
    500, // 50cm, APA_DISTANCE_TYPE APAParkProcPEStartTurnSteeringToStep2CarToStep2KeyPtDis; // 500

	
    //Luhui 500/APA_DETERMINE_OPERATION_STATE_TASK_CALL_CYCLE_TIME,  //500ms  word AdaptiveCruiseControlActiveIndicateTrueTime;
    //Luhui 5000/PA_PHY_SW_DT_TASK_CALL_CYCLE_TIME, //    word wMaxAPAPhySwDefaultParkingPressMinCnt;

	/***********************DIAG TRACE TEST **************************/
	// 0,		// BOOLEAN bDiagnosticTraceFuncAct;
	// 0,		// BOOLEAN bDefaultParkingTestFuncAct;
	// /*tAPADefaultParkingSlotInfo APADefaultParallelSlotInfo;
	// {
	// 	// BOOLEAN bParkingSide;
	// 	// BOOLEAN bParkingCurbDetected;
	// 	// APA_DISTANCE_TYPE SlotLength;
	// 	// APA_DISTANCE_TYPE SlotDepth;
	// 	// APA_DISTANCE_TYPE SlotPositionX;
	// 	// APA_DISTANCE_TYPE SlotPositionY;
	// 	// APA_DISTANCE_TYPE SlotAngle;	
	// }*/
	// 1,		
	// 0,	
	// 6000,	
	// 4000,	
	// (950 + 1000),		// (APACal.HalfWidthOfCar + CarToSlotObjectByPassingSlot)	
	// (- 3500 - 0),		// (- APACal.APASlotMinPathAfterSlot - 500)	
	// 0,		
	// /*tAPADefaultParkingSlotInfo APADefaultPerpendicularSlotInfo;
	// {
	// 	// BOOLEAN bParkingSide;
	// 	// BOOLEAN bParkingCurbDetected;
	// 	// APA_DISTANCE_TYPE SlotLength;
	// 	// APA_DISTANCE_TYPE SlotDepth;
	// 	// APA_DISTANCE_TYPE SlotPositionX;
	// 	// APA_DISTANCE_TYPE SlotPositionY;
	// 	// APA_DISTANCE_TYPE SlotAngle;	
	// }*/
	// 1,		
	// 1,	
	// 2500,	
	// 8000,	
	// (929 + 500),		// (APACal.HalfWidthOfCar + CarToSlotObjectByPassingSlot)	
	// (- 3500 - 0),		// (- APACal.APASlotMinPathAfterSlot - 500)	
	// 0,		
	/***********************DIAG TRACE TEST **************************/

//    'G'//   char CalibrationTemplate;
};


#define ALG_STOP_SEC_CONST_32BIT
#include "IS31_UserMemMap.h"
/*************************************************************************************************************************************************
**                                                     Global Variable Definitions                                                              **
*************************************************************************************************************************************************/
/**/

/*************************************************************************************************************************************************
**                                                     Private  Constant Definitions                                                            **
*************************************************************************************************************************************************/
/**/

/*************************************************************************************************************************************************
**                                                     Private  Variable Definitions                                                            **
*************************************************************************************************************************************************/
/**/

/*************************************************************************************************************************************************
**                                                     Global Function Definitions                                                              **
*************************************************************************************************************************************************/
/**/


/*************************************************************************************************************************************************
**                                                     End of file                                                                              **
*************************************************************************************************************************************************/






