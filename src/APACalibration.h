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
**  $FILENAME   :  APACalibration.h $                                                                                                           **
**                                                                                                                                              **
**  $CC VERSION : \main\94 $                                                                                                                    **
**                                                                                                                                              **
**  $DATE       : 2020-08-18                                                                                                                  **
**                                                                                                                                              **
**  AUTHOR      : SAIC - CH -Engineering                                                                                                        **
**                                                                                                                                              **
**  VENDOR      : SAIC Technologies                                                                                                             **
**                                                                                                                                              **
**  DESCRIPTION : This file contains                                                                                                            **
**                - APA common calibration data type defintion                                                                                  **
**                                                                                                                                              **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                                                                                        **
**                                                                                                                                              **
*************************************************************************************************************************************************/
#ifndef APACALIBRATION_H_
#define APACALIBRATION_H_


/*************************************************************************************************************************************************
**                                                              Includes                                                                        **
*************************************************************************************************************************************************/
#include "APACommonType.h"

/*************************************************************************************************************************************************
**                                                              Global Macro/ENUM Definitions                                                   **
*************************************************************************************************************************************************/
#define PA_PHY_SW_DT_TASK_CALL_CYCLE_TIME			    	10
#define APA_WITH_60_DEG_REAR_SIDE_SENSOR
#define APA_PER_PREDICT_CAR_CAN_DRV_TARGET_POS_NUM				                    8
#define MAX_SUPPORT_TIRE_SIZE_NUM								                    32
#define APA_RX_STEERING_WHEEL_ANGLE_CAL_FACTOR					((35.35923192 - 0.5) / 521.2) // resolution: 0.01 deg, unit: rad.
#define APA_CAR_POS_CALCULATION_TASK_CALL_CYCLE_TIME	40 // 10MS
#define APA_TRAJCAL_PARKEXIT_ALLOW_CAR_DRIVE_FORWARD_DIS_WITH_NO_OBJ_AT_FRONT	1200 // 35cm.
#define APA_TRAJCAL_PARKEXIT_ALLOW_CAR_DRIVE_BACKWARD_DIS_WITH_NO_OBJ_AT_REAR	1500 // 35cm.


/*************************************************************************************************************************************************
**                                                              Global Type Definitions                                                         **
*************************************************************************************************************************************************/
typedef union 
{
	dword APACalFlagType;
	struct
    {
		dword bAPAParkProcExitAPASearchSlotWhenDisOverFlow		                        :1;
		dword bResponseToODIDynamicDataMultiReqWithoutGainedFocus                       :1; 
		dword bAPATrajCalPCarParkingAlongCurbIfCurbDetected		                        :1; 
		dword bAPATrajCalCarParkingAlongCurbIfCurbDetected		                        :1; 
		dword bAPAParkProcKeepCurrentSlotAndCarPosition			                        :1;
		dword bAPAParkProcPEEPCanBeActivatedAtForward			                        :1;
		dword bAPACarSupportLongitudinalAcceleration			                        :1;
		dword bAPACarSupportWheelSpeedCANSignal					                        :1;
		dword bAPASlotCorPCheckObjExistOrNot					                        :1;
		dword bAPASlotCorPUseRCornerSnsToCorrectSlotBorderLine	                        :1;
		dword bAPASlotCorPSupportCorrectSlotBorderLine			                        :1;
		dword bAPASlotCorPReDetermineEndPosSide					                        :1;
		dword bAPASlotCorPParkParallelToObjIfEndPosIsCloseToObj                        	:1;
		dword bAPAODILostFocusInEnableAndGainIPCFocusFailedWillEnterIntoStandbyEnable	:1;	//added by dsh 20140118
		dword bAPACalCarPosDisableByWhlDirConflict				                        :1;
		dword bAPACalCarPosUseNonDrivenWhlDir					                        :1;

		dword bAPACalCarPosSupportTireDiameterLearning			                        :1;
		dword bAPACalCarPosSupportSteeringWheelAngOffsetLearning			            :1;
		dword bAPASupportStartWithPerpendicularModeBySwitchLongPressed	                :1;
		dword bTurningLightHoldOnToParkOppositeSide				                        :1;
		dword bAPAStandbyWhenActiveByGearP						                        :1;
		dword bAPAStandbyWhenSearchingSlotByGearP				                        :1;
		dword bAPASlotCorPUseLCornerSnsToCorrectSlotBorderLine	                        :1;
		dword Reserved											                        :1;
		dword bAPAParkProcDisplayOverSpdMsgWhenAPASwitchPressed	                        :1;
		dword bAPAParkProcDisplayDriveFwWhenSlotIsFound			                        :1;
		dword bAPAParkProcDisplayDriveBkArrowOrStopWhenSlotIsFound	                    :1; // FALSE = display Stop, True = display Bk Arrow
		dword bAPACalCarPosSupportSteeringWheelAngRatioLearning                         :1;
		dword bAPACalCarPosWithRearWheelsPulseCntOnly                                   :1; //FALSE
		dword bAPARxSteeringWheelAngProcessUseSteeringVariedRatio                       :1;	
		dword bAPAODISendAPAUnavailableODIndAtDisabled 	                                :1;
		dword bAPASupportOtsAirTmpCrValV_InvalidDisableCause	                        :1;
	}Bits;
}tAPACalFlagType;

/*2.4************************* APA CALIBRATION STRUCTURE START	*********************************************/
typedef struct  
{
/*2.4.1***Vehicle pararmeter****/
	APA_DISTANCE_TYPE LengthOfCar;
	APA_DISTANCE_TYPE WidthOfCar;
	APA_DISTANCE_TYPE HalfWidthOfCar;
	APA_DISTANCE_TYPE FrontAxisLength;
	APA_DISTANCE_TYPE HalfWidthOfFrontAxis;
	APA_DISTANCE_TYPE RearAxisLength;
	APA_DISTANCE_TYPE HalfWidthOfRearAxis;
	APA_DISTANCE_TYPE LenBetweenFRAxis;
	APA_DISTANCE_TYPE LenBetweenFAxisAndFBumper;
	APA_DISTANCE_TYPE LenBetweenRAxisAndFBumper;
	APA_DISTANCE_TYPE LenBetweenRAxisAndRBumper;
	APA_DISTANCE_TYPE LenBetweenFrontRectCornerToFrontBumperCornerCurve;
	APA_DISTANCE_TYPE LenBetweenRearRectCornerToRearBumperCornerCurve;
	APA_DISTANCE_TYPE WheelTireDiameter[MAX_SUPPORT_TIRE_SIZE_NUM];		// unit:mm added by zhx 20120925
/*2.4.2***Sensor fixed information****/
	APACoordinateDataType SnsPos[APA_SUPPORT_APA_SNS_NUM]; // relative to car rotation center 	
	APA_ANGLE_TYPE SnsAng[APA_SUPPORT_APA_SNS_NUM]; // relative to car rotation center, (unit: radian)
	APA_ANGLE_CAL_FLOAT_TYPE SnsAngCos[APA_SUPPORT_APA_SNS_NUM];
	APA_ANGLE_CAL_FLOAT_TYPE SnsAngSin[APA_SUPPORT_APA_SNS_NUM];	

/*2.4.3***Switch Press time****/
	WORD wMaxAPAPhySwShortToGNDCnt;
	WORD wMaxAPAPhySwLongPressMinCnt;
	
/*2.4.4***Speaker ****/
	// Luhui APA_ENUM_TYPE APASpeakerType;
	APA_SPEAKER_CHIME_DELAY_TIMER_TYPE APASpeakerReqChimeStartDelayTime;
	APA_SPEAKER_CHIME_DELAY_TIMER_TYPE APASpeakerReqChimeStopDelayTime;
	
/*2.4.5***apa state relatively ****/
	APA_ENUM_TYPE CarParkAtLeftOrRightSide; // Car park at left if true other wise park at right
	//tAPAByteBitType _APASupportFunctionMode;
	APA_MS_TIME_TYPE APADisableCauseCheckDelayTime;
	
/*2.4.6***APA ODI ****/
	uchar APAFUCID;   //added by dsh 20120524

	// calibration for IPC
	// APA_MS_TIME_TYPE APAODIInitialReqToGainIPCFocusWaitForIPCResponseTime; // modified by dsh 2014 03 11
	// APA_MS_TIME_TYPE APAODIInitialReqToGainIPCFocusRetryDurationTime; // added by dsh 2014 03 11	
	//APA_MS_TIME_TYPE APAODIIndicationMsgTxOKAndIPCODIMultiReqDynDataRxTimeOutTime;
	//APA_MS_TIME_TYPE APAODIMsgSendTimeOutTime;
	//APA_MS_TIME_TYPE APAODILoseIPCFocusRegainFocusDelayTime; // Note: if it is set to 0xffff, means will not try to regain the focus again and just treat as IPC focus not lost.
	//APA_MS_TIME_TYPE APAODILoseIPCFocusRegainFocusRetryDurationTime;
	UCHAR APAODIEventMsgTxTryCntOfInitialGainIPCFocus; // modified by dsh 2014 03 11
	UCHAR APAODIEventMsgTxTryCntOfRegainIPCFocus;// added by dsh 2014 03 11
	UCHAR APAODIIndicationMsgTxTryCnt;
	//APA_MS_TIME_TYPE APAODIAPAIsUnavailableIndicationCheckDelayTime; 
	//APA_MS_TIME_TYPE APAODIAPAIsUnavailableIndicationFalseDurationTime; 
	//APA_MS_TIME_TYPE APAODIAPAIsUnavailableIndicationTrueDurationTime; 
	UCHAR APAODIParkingProgressPercentageStep;
	//UCHAR APAODIParkingManueverProgressUpdateDelayTime;
	// calibration for infortainment
	//APA_MS_TIME_TYPE APAODIInitialReqToGainICSFocusWaitForICSResponseTime; // Delay time of second retrying to request ICS Focus after APA first request to gain ICS forcus
	//APA_MS_TIME_TYPE APAODIInitialReqToGainICSFocusRetryDurationTime; // APA retry to request ICS focus try time.
	//APA_MS_TIME_TYPE APAODILoseICSFocusRegainFocusDelayTime; // Note: if it is set to 0xffff, means will not try to regain the focus again and just treat as IPC focus not lost.
	//APA_MS_TIME_TYPE APAODILoseICSFocusRegainFocusRetryDurationTime; // APA retry to request ICS focus try time IN APA REGAIN FOCUS.
	UCHAR APAODIEventMsgTxTryCntOfInitialGainICSFocus; // APA initial request ICS focus  try count
	UCHAR APAODIEventMsgTxTryCntOfRegainICSFocus; // APA REGIAN ICS focus try count
	//UCHAR APAODIIndicationMsgTxTryCntForICS; // APA INDICAITON msg try count.

/*2.4.7***boolean define ****/

	tAPACalFlagType   APACalCommonFlags;
	//tAPACalFlag1Type APACalCommonFlags1;
	tAPACalFlag2Type APACalCommonFlags2;
	
/*2.4.8*** common use ****/

	APA_DISTANCE_TYPE APAReduceZone1DisMaxDeltaSlotLen; // Car len + 1300.	

	APA_DISTANCE_TYPE PEAllowCarDriveForwardDisWithoutObjAtF;	
	APA_DISTANCE_TYPE PEAllowCarDriveBackwardDisWithoutObjAtR;
	APA_ANGLE_TYPE MaxSteeringWheelAngle; // (unit: radian) Ang < 0: turning right, Ang > 0: turning left.
	//APA_ANGLE_TYPE MaxSteeringWheelAngleBackward; // (unit: radian) Ang < 0: turning right, Ang > 0: turning left.   //Add by wuzhen 0721
	APA_ANGLE_TYPE MaxEPSSteeringWheelAngle; // (unit: radian) Ang < 0: turning right, Ang > 0: turning left.
	APA_ANGLE_TYPE MaxSteeringWheelAngleTol; // (unit: radian) the tollerance between desired steering wheel angle and EPS steering angle.
//	APA_ANGLE_TYPE MaxSteeringWheelAngleTol2; // (unit: radian) the tollerance between desired steering wheel angle and EPS steering angle.
	APA_ANGLE_TYPE APAControlledSteeringWheelAngleConvertFactor; // Convert the unit: rad to APA tx controlled steering wheel agnle (3D4).
	APA_ANGLE_TYPE APARxSteeringWheelAngleConvertFactor; //Convert the D0 (EPS Tx steering wheel angle) to unit: rad. APA_RX_STEERING_WHEEL_ANGLE_CAL_FACTOR
	// KJY Add 2012 7 23
	APA_DISTANCE_CAL_FLOAT_TYPE APAAllowWheelRotateDisMinTol1; // For different tire radius and pulse cnt, this value should be different.
	APA_DISTANCE_CAL_FLOAT_TYPE APAAllowWheelRotateDisMinTol2; // For different tire radius and pulse cnt, this value should be different.
	APA_DISTANCE_CAL_FLOAT_TYPE APAAllowWheelRotateDisMinTol3; // For different tire radius and pulse cnt, this value should be different.
	APA_DISTANCE_CAL_FLOAT_TYPE APAWheelPulseNeedUpdateDis; //when the car position is not updated,and the wheel distance is more than NeedUpdateDis,then updated the car positon.
	UINT16 APASupportMaxWheelPulseCnt;//for different type of cars,the supported max wheel pulse cnt would be different.
	APA_SPEED_TYPE APACarPosCalMaxVehSpeedUpdateDeltaTol;
	UCHAR APACarPosCalVehSpdMissToBeUpdatedRecoverTime;
	APA_SPEED_CAL_FLOAT_TYPE APACarPosCalWheelSpeedCalFactorMeterPerSecond;
	APA_SPEED_CAL_FLOAT_TYPE APACarPosCalLongitudinalAccelerationPrimaryFactor;
	APA_SPEED_CAL_FLOAT_TYPE APACarPosCalMaxVehLongitudinalAcceleration;
	UCHAR APACarPosCalCarPosUpdateCycleTime;
	UCHAR APACarPosCalWheelPulseCounterErrorRecoverCnt;
	APA_MS_TIME_TYPE APACarPosCalMaxUseVehSpeedAndAccToEvaluateCarPosDurationTime;
	APA_DISTANCE_TYPE APACarPosCalMaxUseVehSpeedAndAccToEvaluateCarPosTotalDis1;
	APA_DISTANCE_TYPE APACarPosCalMaxUseVehSpeedAndAccToEvaluateCarPosTotalDis2;
	APA_DISTANCE_TYPE APACarPosCalMaxUseVehSpeedAndAccToEvaluateCarPosTotalDis3;
	APA_DISTANCE_CAL_FLOAT_TYPE APACarPosCalMaxCarPosCalUpdateDetalTolerance1;
	APA_DISTANCE_CAL_FLOAT_TYPE APACarPosCalMaxCarPosCalUpdateDetalTolerance2;
	APA_DISTANCE_CAL_FLOAT_TYPE APACarPosCalMaxCarPosCalUpdateDetalTolerance3;
	
	
	APA_DISTANCE_CAL_FLOAT_TYPE APACarPosCalAllowedCarPosXMax;
	APA_DISTANCE_CAL_FLOAT_TYPE APACarPosCalAllowedCarPosYMax;
	APA_ANGLE_CAL_FLOAT_TYPE APACarPosCalAllowedCarPosAngMax;
	APA_ANGLE_CAL_FLOAT_TYPE APACarPosCalAllowedCarPosAngMaxForParallelParking;
	APA_ANGLE_CAL_FLOAT_TYPE APACarPosCalAllowedCarPosAngMinForParallelParking;
	APA_DISTANCE_CAL_FLOAT_TYPE APACarPosCalAllowedCarPosXMaxForParallelParking;
	APA_DISTANCE_CAL_FLOAT_TYPE APACarPosCalAllowedCarPosXMinForParallelParking;
	APA_DISTANCE_CAL_FLOAT_TYPE APACarPosCalAllowedCarPosYMaxForParallelParking;
	APA_DISTANCE_CAL_FLOAT_TYPE APACarPosCalAllowedCarPosYMinForParallelParking;
	APA_ANGLE_CAL_FLOAT_TYPE APACarPosCalAllowedCarPosAngMaxForPerpendicularParking;
	APA_ANGLE_CAL_FLOAT_TYPE APACarPosCalAllowedCarPosAngMinForPerpendicularParking;
	APA_DISTANCE_CAL_FLOAT_TYPE APACarPosCalAllowedCarPosXMaxForPerpendicularParking;
	APA_DISTANCE_CAL_FLOAT_TYPE APACarPosCalAllowedCarPosXMinForPerpendicularParking;
	APA_DISTANCE_CAL_FLOAT_TYPE APACarPosCalAllowedCarPosYMaxForPerpendicularParking;
	APA_DISTANCE_CAL_FLOAT_TYPE APACarPosCalAllowedCarPosYMinForPerpendicularParking;
	APA_DISTANCE_CAL_FLOAT_TYPE APASupportMaxCarTurningRadius;
	APA_DISTANCE_CAL_FLOAT_TYPE APATrajCalLineTangentToCircleTolDis;//250 // 25cm //def: (10cm NG. it is too samll)
	APA_DISTANCE_CAL_FLOAT_TYPE APATrajCalMinAllowedDesireTangentOutSideButResultIsInSideTangentRadius;
	APA_DISTANCE_CAL_FLOAT_TYPE APATrajCalMinAllowedDesireTangentInSideButResultIsOutSideTangentRadius;
	
	//UCHAR APAWheelPulsePerRevolution[APA_SUPPORT_PER_REVOLUTION_CAL_NUM];

	/*APA Wheel and Steering Learnnig  start */

	// Tire factor learning
	APA_CAR_POS_WHEEL_PULSE_CNT_CAL_TYPE TireDiameterLearningOneLearningLoopStartCalTireFactorWheelPulseCnt;
	APA_DISTANCE_TYPE TireDiameterLearningAllowedMaxTireDiameterTol; // 8cm. R tol = 4cm.
	APA_CAL_FLOAT_TYPE TireDiameterLearningAllowedMinFactor; // 0.85, if tol = 8cm, diameter = 630, it will be: 0.873.
	APA_ANGLE_CAL_FLOAT_TYPE TireDiameterLearningAllowedMinEPSAng; // -7deg.
	APA_ANGLE_CAL_FLOAT_TYPE TireDiameterLearningAllowedMaxEPSAng; // 7deg.

	// Steering angle offset learning
	APA_CAR_POS_WHEEL_PULSE_CNT_TYPE SteeringAngleOffsetLerningAllowedMaxWheelPulseCnt;
	APA_CAR_POS_WHEEL_PULSE_CNT_TYPE SteeringAngleOffsetLerningStartCheckMinWheelPulseCnt;
	APA_CAL_FLOAT_TYPE SteeringAngleOffsetLerningAllowedMaxDeltaFLRRWheelPulseCnt;
	APA_CAL_FLOAT_TYPE SteeringAngleOffsetLerningAllowedMaxDeltaFRRRWheelPulseCnt;
	APA_CAL_FLOAT_TYPE SteeringAngleOffsetLerningDriveStraightlyMaxDeltaFLRRWheelPulseCnt;
	APA_CAL_FLOAT_TYPE SteeringAngleOffsetLerningCarTurningMinDeltaFLRRWheelPulseCnt;
	APA_CAL_FLOAT_TYPE SteeringAngleOffsetLerningCarTurningMinDeltaRLRRWheelPulseCnt;
	APA_CAL_FLOAT_TYPE SteeringAngleOffsetLerningAllowedMinDeltaFRRRWheelPulseCnt;
	APA_CAL_FLOAT_TYPE SteeringAngleOffsetLerningAllowedMinDeltaFRRRWheelPulseCntRatio;
	APA_CAL_FLOAT_TYPE SteeringAngleOffsetLerningAllowedMaxDeltaFLRLWheelPulseCnt;	
	//APA_ANGLE_TYPE SteeringAngleOffsetLerningAllowedMaxOffsetSteeringAng[APA_STEER_WHEEL_TURNING_SIDE_NUM];  // 10deg for steering wheel. used for steering offset learning
	//APA_ANGLE_TYPE SteeringAngleOffsetLerningAllowedMinOffsetSteeringAng[APA_STEER_WHEEL_TURNING_SIDE_NUM];  // 0deg for steering wheel. used for steering offset learning
	//APA_ANGLE_TYPE SteeringAngleOffsetDefaultValue[APA_STEER_WHEEL_TURNING_SIDE_NUM];  // 2deg for steering wheel.

	// Steering ratio learning
	APA_CAR_POS_WHEEL_PULSE_CNT_TYPE EPSSteeringWheelAngRatioLerningAllowedMaxWheelPulseCnt;
	//APA_CAR_POS_WHEEL_PULSE_CNT_TYPE EPSSteeringWheelAngRatioLerningStartCheckMinWheelPulseCnt[APA_STEER_WHEEL_TURNING_SIDE_NUM][APA_STEER_WHEEL_ANGLE_RATIO_DEVIDED_SEG_NUM];
	APA_CAL_FLOAT_TYPE EPSSteeringWheelAngRatioLerningAllowedMaxCarAngTolCalByTires;
	//APA_ENUM_TYPE EPSSteeringWheelAngRatioLerningAlgorithm; // Luhui 20200804
	APA_CAL_FLOAT_TYPE EPSSteeringWheelAngRatioLerningAllowedMaxRatioTol;
	APA_DISTANCE_TYPE EPSSteeringWheelAngRatioLerningAllowedMaxRearHalfWidthTol;
	APA_DISTANCE_TYPE EPSSteeringWheelAngRatioLerningAllowedMaxFrontHalfWidthTol;
	APA_CAL_FLOAT_TYPE EPSSteeringWheelAngRatioLerningAllowedMaxTurningRadiusTolCalByTires;
	//APA_DISTANCE_TYPE EPSSteeringWheelAngRatioLerningCompensatedTurningRadius[APA_STEER_WHEEL_TURNING_SIDE_NUM][APA_STEER_WHEEL_ANGLE_RATIO_DEVIDED_SEG_NUM];
	//APA_ENUM_TYPE EPSSteeringWheelAngRatioSegNum; // max: APA_STEER_WHEEL_ANGLE_RATIO_DEVIDED_SEG_NUM
	//tAPASteeringWheelAngleRatioCalType EPSSteeringWheelAngRatio[APA_STEER_WHEEL_TURNING_SIDE_NUM][APA_SUPPORT_CAR_DRIVE_DIRECTION_NUM][APA_STEER_WHEEL_ANGLE_RATIO_DEVIDED_SEG_NUM];
	//APA_ENUM_TYPE EPSSteeringWheelAngRatioLearningPtNum[APA_STEER_WHEEL_ANGLE_RATIO_LEARNING_PER_CYCLE_NUM]; // max: APA_STEER_WHEEL_ANGLE_RATIO_DEVIDED_SEG_NUM
	//APA_ANGLE_CAL_FLOAT_TYPE EPSSteeringWheelAngRatioLearningAngArray[APA_STEER_WHEEL_TURNING_SIDE_NUM][APA_STEER_WHEEL_ANGLE_RATIO_LEARNING_PER_CYCLE_NUM][APA_STEER_WHEEL_ANGLE_RATIO_LEARNING_PT_NUM];
	//APA_ANGLE_CAL_FLOAT_TYPE EPSSteeringWheelAngLearningTolDevidedAng[APA_STEER_WHEEL_ANGLE_LEARNING_TOL_DEVIDED_NUM - 1];
	//APA_ANGLE_CAL_FLOAT_TYPE EPSSteeringWheelAngLearningTol[APA_STEER_WHEEL_ANGLE_LEARNING_TOL_DEVIDED_NUM];
	//APA_SPEED_TYPE EPSSteeringWheelAngLearningAllowedMinSpeed[APA_STEER_WHEEL_ANGLE_LEARNING_TOL_DEVIDED_NUM];
	//APA_SPEED_TYPE EPSSteeringWheelAngLearningAllowedMaxSpeed[APA_STEER_WHEEL_ANGLE_LEARNING_TOL_DEVIDED_NUM];	
	//APA_CAR_POS_WHEEL_PULSE_CNT_TYPE EPSSteeringWheelAngLearningAllowedMinWheelPulseCntPerCycle[APA_STEER_WHEEL_ANGLE_LEARNING_TOL_DEVIDED_NUM];
	//APA_CAL_FLOAT_TYPE EPSSteeringWheelAngLearningAllowedMaxWheelPulseRatioTol[APA_STEER_WHEEL_ANGLE_LEARNING_TOL_DEVIDED_NUM];

	/*APA Wheel and Steering Learnnig    end */ 

/*2.4.9*** Searching Slot Algorithm****/
/*2.4.9.1*** Parrallel slot****/
	APA_DISTANCE_TYPE APASlotRSamplePointNoisePtStartCheckBkObjWidth; // 100cm.
	APA_SLOT_PT_SLOPE_TYPE APASlotRSamplePointAllowedMaxDeltaSlope; // 120, // 76deg. // 52: atan(52/30) = 60deg.
	APA_DISTANCE_TYPE APASlotRSamplePointNoisePtCanBeRemovedCheckMinNoObjWidth; // 50cm
	APA_DISTANCE_TYPE APASlotRSamplePointNoisePtCanBeRemovedHeadOrTailMaxDeltaObjDis; // 7cm
	APA_SLOT_PT_SLOPE_TYPE APASlotRSamplePointNoisePtCanBeRemovedHeadOrTailMaxSlope;  // 17, // 30deg. 30, 45deg. 
	APA_SLOT_PT_SLOPE_TYPE APASlotRSamplePointNoisePtCanBeRemovedHeadOrTailMinSlope;  // -52, // -52: -60deg.	
	APA_DISTANCE_TYPE APASlotRSamplePointNoisePtRegardedAsSameObjMaxNoObjWidth; // 60cm.
	APA_DISTANCE_TYPE APASlotRSamplePointNoisePtRegardedAsSameObjMaxDeltaObjDis; // 30cm.
	APA_DISTANCE_TYPE APASlotRSamplePointNoisePtRegardedAsSameObjMinObjWidth; // 50cm.
	APA_DISTANCE_TYPE APASlotRSamplePointNoisePtCanBeRemovedSameObjTol; // 25cm.
	APA_DISTANCE_TYPE APASlotRSamplePointNoisePtCanBeRemovedCheckNoiseWidth;
	APA_DISTANCE_TYPE APASlotRSamplePointNoisePtCanBeRemovedCheckNoiseToObjWidth;
	APA_DISTANCE_TYPE APASlotRSamplePointNoisePtCanBeRemovedMaxDis;
	APA_ENUM_TYPE APASlotRSamplePointNoisePtCanBeRemovedMinSameObjPtNum;	
	APA_DISTANCE_TYPE APASlotRSamplePointNoisePtCanBeRemovedMinObjWidth;
	APA_ENUM_TYPE APASlotRSamplePointNoisePtCanBeRemovedMaxNoiseWidthPercentage;
	APA_DISTANCE_TYPE APASlotRSamplePointNoisePtCanBeRemovedCheckMaxObjWidth;
	APA_DISTANCE_TYPE APASlotRSamplePointNoisePtCanBeRemovedCheckStartHeadWidth;
	APA_DISTANCE_TYPE APASlotRSamplePointNoisePtCanBeRemovedRegardAsNoiseMinObjWidth;
	APA_DISTANCE_TYPE APASlotRSamplePointNoisePtCanBeRemovedMinObjPtOutOfTolNum;
	APA_DISTANCE_TYPE APASlotRSamplePointNoisePtCanBeRemovedMinNoObjPtTotalNum;
	APA_DISTANCE_TYPE APASlotRSamplePointNoisePtCanBeRemovedMinNoObjPtWitinNoiseNum;
	APA_DISTANCE_TYPE APASlotRSamplePointUpdateLongDeltaLen;
	APA_DISTANCE_TYPE APASlotRSamplePointUpdateSmallDeltaLen; // 5cm,
	APA_DISTANCE_TYPE APASlotRSamplePointUpdateSmallDeltaLen2; // 50cm,
	APA_DISTANCE_TYPE APASlotRSamplePointCanBeRemovedMaxObjPtDeltaSlope; // 0.1
	APA_DISTANCE_TYPE APASlotRSamplePointCanBeRemovedMaxObjDis;
	APA_DISTANCE_TYPE APASlotRPointCanBeRemovedContiguousPointMinDisP;
	APA_DISTANCE_TYPE APASlotRPointCanBeRemovedContiguousPointMinDisP2;	

	APA_DISTANCE_TYPE APASlotFSamplePointNoisePtStartCheckBkObjWidth; // 100cm.
	APA_SLOT_PT_SLOPE_TYPE APASlotFSamplePointAllowedMaxDeltaSlope; // 120, // 76deg. // 52: atan(52/30) = 60deg.
	APA_DISTANCE_TYPE APASlotFSamplePointNoisePtCanBeRemovedCheckMinNoObjWidth; // 50cm
	APA_DISTANCE_TYPE APASlotFSamplePointNoisePtCanBeRemovedHeadOrTailMaxDeltaObjDis; // 7cm
	APA_SLOT_PT_SLOPE_TYPE APASlotFSamplePointNoisePtCanBeRemovedHeadOrTailMaxSlope;  // 17, // 30deg. 30, 45deg. 
	APA_SLOT_PT_SLOPE_TYPE APASlotFSamplePointNoisePtCanBeRemovedHeadOrTailMinSlope;  // -52, // -52: -60deg.	
	APA_DISTANCE_TYPE APASlotFSamplePointNoisePtRegardedAsSameObjMaxNoObjWidth; // 60cm.
	APA_DISTANCE_TYPE APASlotFSamplePointNoisePtRegardedAsSameObjMaxDeltaObjDis; // 30cm.
	APA_DISTANCE_TYPE APASlotFSamplePointNoisePtRegardedAsSameObjMinObjWidth; // 50cm.
	APA_DISTANCE_TYPE APASlotFSamplePointNoisePtCanBeRemovedSameObjTol; // 25cm.
	APA_DISTANCE_TYPE APASlotFSamplePointNoisePtCanBeRemovedCheckNoiseWidth;
	APA_DISTANCE_TYPE APASlotFSamplePointNoisePtCanBeRemovedCheckNoiseToObjWidth;
	APA_DISTANCE_TYPE APASlotFSamplePointNoisePtCanBeRemovedMaxDis;
	APA_ENUM_TYPE APASlotFSamplePointNoisePtCanBeRemovedMinSameObjPtNum;	
	APA_DISTANCE_TYPE APASlotFSamplePointNoisePtCanBeRemovedMinObjWidth;
	APA_ENUM_TYPE APASlotFSamplePointNoisePtCanBeRemovedMaxNoiseWidthPercentage;
	APA_DISTANCE_TYPE APASlotFSamplePointNoisePtCanBeRemovedCheckMaxObjWidth;
	APA_DISTANCE_TYPE APASlotFSamplePointNoisePtCanBeRemovedCheckStartHeadWidth;
	APA_DISTANCE_TYPE APASlotFSamplePointNoisePtCanBeRemovedRegardAsNoiseMinObjWidth;
	APA_DISTANCE_TYPE APASlotFSamplePointNoisePtCanBeRemovedMinObjPtOutOfTolNum;
	APA_DISTANCE_TYPE APASlotFSamplePointNoisePtCanBeRemovedMinNoObjPtTotalNum;
	APA_DISTANCE_TYPE APASlotFSamplePointNoisePtCanBeRemovedMinNoObjPtWitinNoiseNum;
	APA_DISTANCE_TYPE APASlotFSamplePointUpdateLongDeltaLen;
	APA_DISTANCE_TYPE APASlotFSamplePointUpdateSmallDeltaLen; // 5cm,
	APA_DISTANCE_TYPE APASlotFSamplePointUpdateSmallDeltaLen2; // 50cm,
	APA_DISTANCE_TYPE APASlotFSamplePointCanBeRemovedMaxObjPtDeltaSlope; // 0.1
	APA_DISTANCE_TYPE APASlotFSamplePointCanBeRemovedMaxObjDis;
	APA_DISTANCE_TYPE APASlotFPointCanBeRemovedContiguousPointMinDisP;
	APA_DISTANCE_TYPE APASlotFPointCanBeRemovedContiguousPointMinDisP2;
	
	APA_DISTANCE_TYPE APASlotSamplePointCanBeRemovedObj2SearchBkDis; // 3m,
	APA_DISTANCE_TYPE APASlotSamplePointCanBeRemovedObj1SearchBkDis; // 1.5m,
	APA_DISTANCE_TYPE APASlotSamplePointCanBeRemovedMaxTwoPtDis;
	APA_DISTANCE_TYPE APASlotPointCanBeRemovedInTheSlotMaxObjWidth;

	APA_DISTANCE_TYPE APASlotMaxDisBetweenToCheckCarTurningTheRoad;
	APA_ANGLE_TYPE APASlotMaxDeltaCarAngForCheckingCarTurningTheRoad;
	APA_DISTANCE_TYPE APASlotMaxDisBetweenStartEndPt;
	APA_DISTANCE_TYPE APASlotMaxDisBetweenStartEndPtWithObj1Invalid;
	APA_DISTANCE_TYPE APASlotMaxWidthOfObj1WithSlotConfirmed;
	APA_DISTANCE_TYPE APASlotMaxWidthOfObj1WithoutSlotConfirmed;
	APA_ANGLE_TYPE APASlotMaxDeltaCarAngBetStartEndPt;
	APA_ANGLE_TYPE APASlotMaxDeltaCarAngBetObjPt;
	APA_DISTANCE_TYPE APASlotMinPerSlotDeltaCarPosDisAtSlotStartAndEndPt;
	APA_DISTANCE_TYPE APASlotDisToCarCheckCarTravellingDis;
	APA_DISTANCE_TYPE APASlotCarCenterPtAllowedMaxY;
	APA_DISTANCE_TYPE APASlotCarCenterPtAllowedMaxX;
	APA_ANGLE_TYPE APASlotCarCenterPtAllowedMaxCarAng;
	APA_DISTANCE_TYPE APASlotCarCenterPtResetMaxY;
	APA_DISTANCE_TYPE APASlotCarCenterPtResetMinY;
	APA_ANGLE_TYPE APASlotCarCenterPtResetMaxCarAng;
	APA_DISTANCE_TYPE APASlotCarCenterPtDefaultY;


	APA_DISTANCE_TYPE APASLotMinObj1AndObj2BdStartPtWidth; // 80cm,

	// Slot Obj Type check parameter: kjy 2013 10 01 added start
	APA_DISTANCE_TYPE APASlotObjTypeCheckObjStPtAllowSearchDisFromSlotStPt; // 70cm,
	APA_DISTANCE_TYPE APASlotObjTypeCheckAllowMaxDeltaSnsDtObjDisFromObjStPt; // 70cm,
	APA_DISTANCE_TYPE APASLotObjTypeCheckMaxObjWidth; // 5.5m,
	APA_DISTANCE_TYPE APASLotObjTypeCheckMaxCarToObjDeltaDis; // 1.5 m,	
	APA_ENUM_TYPE APASlotObjTypeCheckRegardedAsObjMinObjPtNum;
	APA_DISTANCE_TYPE APASlotObjTypeCheckRegardedAsSamePtTolCarDrvDis;
	APA_DISTANCE_TYPE APASlotObjTypeCheckRegardedAsSamePtTolCarToObjDis;
	APA_DISTANCE_TYPE APASlotObjTypeCheckRegardedAsFlatShapeTolDis; // 15cm.
	APA_DISTANCE_TYPE APASlotObjTypeCheckRegardedAsNoiseMaxWidth; // 40cm.
	APA_DISTANCE_TYPE APASlotObjTypeCheckFlatShapeRegardedAsNoObjDtMinWidth0; // 25cm, 
	APA_DISTANCE_TYPE APASlotObjTypeCheckFlatShapeRegardedAsNoObjDtMinWidth1; // 50cm, 
	APA_DISTANCE_TYPE APASlotObjTypeCheckFlatShapeRegardedAsNoObjDtMinWidth2; // 100cm, 
	APA_DISTANCE_TYPE APASlotObjTypeCheckFlatShapeRegardedAsSmallObjMaxWidth1; // 100cm. obj width less than 100cm will be regarded as small obj.
	APA_DISTANCE_TYPE APASlotObjTypeCheckFlatShapeRegardedAsSmallObjMaxWidth2; // 150cm. obj width less than 150cm will be regarded as small obj.
	APA_DISTANCE_TYPE APASlotObjTypeCheckFlatShapeJumpWidthTol;
	
	
	APA_DISTANCE_TYPE APASlotObjTypeCheckFallingShapeRegardedAsNoObjDtMinWidth1; // 40cm. the falling shape is big
	APA_DISTANCE_TYPE APASlotObjTypeCheckFallingShapeRegardedAsNoObjDtMinWidth2; // 100cm. the falling shape width is small.
	APA_DISTANCE_TYPE APASlotObjTypeCheckFallingShapeRegardedAsSmallObjMaxWidth; // 60cm.  regarded as small falling shape.
	APA_DISTANCE_TYPE APASlotObjTypeCheckFallingShapeRegardedAsObjEndedMinObjWidth1; // 100cm.
	APA_DISTANCE_TYPE APASlotObjTypeCheckFallingShapeRegardedAsObjEndedMinObjWidth2; // 150cm.
	APA_DISTANCE_TYPE APASlotObjTypeCheckRegardedAsFallingShapeMinObjWidth1; // 40cm.  big obj( > 100cm)
	APA_DISTANCE_TYPE APASlotObjTypeCheckRegardedAsFallingShapeNoiseMaxFallingObjWidth; // 80cm.
	APA_DISTANCE_TYPE APASlotObjTypeCheckRegardedAsFallingShapeNoiseMinRisingObjWidth; // 80cm.
	
	APA_DISTANCE_TYPE APASlotObjTypeCheckRisingShapeRegardedAsNoObjDtMinWidth0; // 25cm. the Rising shape is big
	APA_DISTANCE_TYPE APASlotObjTypeCheckRisingShapeRegardedAsNoObjDtMinWidth1; // 70cm. the Rising shape is big
	APA_DISTANCE_TYPE APASlotObjTypeCheckRisingShapeRegardedAsNoObjDtMinWidth2; // 100cm. the Rising shape width is small.
	APA_DISTANCE_TYPE APASlotObjTypeCheckRisingShapeRegardedAsSmallObjMaxWidth1; // 100cm. obj width less than 100cm will be regarded as small obj.
	APA_DISTANCE_TYPE APASlotObjTypeCheckRisingShapeRegardedAsSmallObjMaxWidth2; // 160cm. obj width less than 150cm will be regarded as small obj.

	APA_DISTANCE_TYPE APASlotObjTypeCheckRegardedAsPerpendicularCarMinWidth; // 100cm.
	APA_DISTANCE_TYPE APASlotObjTypeCheckRegardedAsPerpendicularCarMaxWidth1; // 320cm.	
	APA_DISTANCE_TYPE APASlotObjTypeCheckRegardedAsPerpendicularCarMaxWidth2; // 400cm.	
	APA_DISTANCE_TYPE APASlotObjTypeCheckPerpendicularCarSmallWidth; // 180cm.  1m~1.8m,
	APA_DISTANCE_TYPE APASlotObjTypeCheckPerpendicularCarNormalWidth; // 230cm.  normal width: 1.8m ~ 2.3m, big width: 2.3m ~ 3.2m.
	APA_ENUM_TYPE APASlotObjTypeCheckPerpendicularCarSmallFlatShapeMaxPercentage; //33, // 0 ~ 1/3 shape width from total width: flat shape width * 100 / total width.
	APA_ENUM_TYPE APASlotObjTypeCheckPerpendicularCarNormalFlatShapeMaxPercentage; //66, 1/3 ~ 2/3 shape width from total width.
	APA_DISTANCE_TYPE APASlotObjTypeCheckParallelCarSmallRisingShapeMaxWidth; // 20cm.
	APA_DISTANCE_TYPE APASlotObjTypeCheckParallelCarNormalRisingShapeMaxWidth; // 40cm.
	APA_DISTANCE_TYPE APASlotObjTypeCheckParallelCarBigRisingShapeMaxWidth; // 60cm.
	APA_SLOT_PT_SLOPE_TYPE APASlotObjTypeCheckRegardedAsParallelCarMaxSlope; // 3, max: 3.99: 60cm / 450cm, 7.6deg. 2, max 2.99: 45cm / 450cm, 5.7deg.
	APA_DISTANCE_TYPE APASlotObjTypeCheckObjRisingShapeEndPtMinDeltaDis[2]; // 5cm.
	APA_DISTANCE_TYPE APASlotObjTypeCheckObjRisingShapeEndPtMaxDeltaDis[2]; // 25cm.
	APA_DISTANCE_TYPE APASlotObjTypeCheckObjRisingShapeEndPtMinRisingWidth; // 30cm.
	APA_DISTANCE_TYPE APASlotObjTypeCheckObjRisingShapeEndPtMaxRisingWidth; // 100cm.

	
	APA_ENUM_TYPE APASlotObjTypeCheckRoundObjRegardedAsFlatShapeMinPercentage; // 4, // >= 40%
	APA_DISTANCE_TYPE APASlotObjTypeCheckSquareObjMaxRisingShapeWidth; // 10cm.
	APA_DISTANCE_TYPE APASlotObjTypeCheckRoundObjSmallRisingShapeMaxWidth; // 20cm.
	APA_DISTANCE_TYPE APASlotObjTypeCheckRoundObjBigRisingShapeMaxWidth; // 60cm.
	
	APA_DISTANCE_TYPE APASlotObjTypeCheckRegardedAsAngularCarMinFlatShapeWidth1; // 100cm.
	APA_DISTANCE_TYPE APASlotObjTypeCheckRegardedAsAngularCarMinFlatShapeWidth2; // 150cm.
	APA_DISTANCE_TYPE APASlotObjTypeCheckAngularCarSmallRisingShapeMaxWidth; // 10cm.
	
	APA_SLOT_PT_SLOPE_TYPE APASlotObjTypeCheckRegardedAsAngularCarDevidedSlope1; // 5, 5 = 5cm / 30cm * 30, 10 deg.
	APA_SLOT_PT_SLOPE_TYPE APASlotObjTypeCheckRegardedAsAngularCarDevidedSlope2; // 11, 11 = 11cm / 30cm * 30, 20 deg.
	APA_SLOT_PT_SLOPE_TYPE APASlotObjTypeCheckRegardedAsAngularCarMaxSlope; // 42, 42 = 42cm / 30cm * 30, 55 deg.
	APA_SLOT_PT_SLOPE_TYPE APASlotObjTypeCheckRegardedAsObjStartMaxDeltaDisSlope; // 4 // 4 = 4.99cm / 30cm * 30 (zoom 30 times). 9.4deg; 5 = 5.99cm / 30cm * 30, 11.3deg; // 8 // 8 = 10.7cm / 40cm * 30 (zoom 30 times). 15deg. 5 = 7cm / 40cm * 30, 10deg.

	APA_DISTANCE_TYPE APASlotObjTypeCheckObjStartPtCalSearchBackWidthSmallObj[2]; // 150cm,
	APA_DISTANCE_TYPE APASlotObjTypeCheckObjStartPtCalSearchBackWidthParallelCar[2]; // 150cm
	//APA_DISTANCE_TYPE APASlotObjTypeCheckObjStartPtCalMaxAllowedCompensatedBackDis; // -30cm
	APA_DISTANCE_TYPE APASlotObjTypeCheckObjStartPtCalRegardedAsFlatStartPtMaxDeltaObjDis; // 4cm
	APA_DISTANCE_TYPE APASlotObjTypeCheckObjStartPtCalRegardedAsObjStartPtMaxDeltaObjDis[2]; // 40cm
	APA_DISTANCE_TYPE APASlotObjTypeCheckObjStartPtCalRegardedAsObj2BigPerCarRisingShapeWidth; // 110cm // dis from start comp pt to nearest dis pt.
	APA_SLOT_PT_SLOPE_TYPE APASlotObjTypeCheckObjStartPtCalRegardedAsNoiseMinObjEndPtSlope; // - 1: 1.9deg.
	APA_SLOT_PT_SLOPE_TYPE APASlotObjTypeCheckObjStartPtCalRegardedAsNoiseMinObjEndPtDeltaSlope; // 8: 15deg.
	APA_DISTANCE_TYPE APASlotObjTypeCheckObjStartPtCalRegardAsCompStPtTooShortDis[2][3]; // 30cm.
	APA_DISTANCE_TYPE APASlotObjTypeCheckObjStartPtCalRegardAsCompStPtMaxWidth[2][3]; // 50cm.
	
	//APA_DISTANCE_TYPE APASlotObjTypeCheckObjStartPtCalDeltaObjDisSlopeRatio[2]; 	
	APA_DISTANCE_TYPE APASlotObjTypeCheckObjStartPtCalDeltaObjDisObj[2][APA_SLOT_OBJ_PROFILE_TYPE_NUM]; 
	APA_DISTANCE_TYPE APASlotObjTypeCheckObjStartPtCompensateDisBySpdAndCarToObjDis[2][APA_SLOT_OBJ_PROFILE_COMPENSATE_TYPE_NUM]\
		[APA_SLOT_OBJ_CAR_TO_OBJ_DIS_COMPENSATE_TYPE_NUM][APA_SLOT_SUPPORT_SLOT_LENGTH_COMPENSATE_SPEED_DEVIDED_NUM];
	
	APA_DISTANCE_TYPE APASlotObjTypeCheckObjStartPtCompensateDisWithFlatEnd[2][3]; // 0cm
	APA_DISTANCE_TYPE APASlotObjTypeCheckObjStartPtCompensateDisRatioWithSmallRising[2][3]; // 30cm.
	APA_DISTANCE_TYPE APASlotObjTypeCheckObjStartPtCompensateDisWithObj2BigPerCarRisingShapeWidth[2];
	
	APA_DISTANCE_TYPE APASlotObj1NotExistObj2ExistRegardedAsValidSlotAllowedMinObj2Width; // 80cm, // 80cm object. set to 10m will not regarded as a valid slot.
	APA_DISTANCE_TYPE APASlotObj1ExistObj2NotExistRegardedAsValidSlotAllowedMinObj1Width; // 80cm, // 80cm object. set to 10m will not regarded as a valid slot.
	APA_DISTANCE_TYPE APASlotObj12ExistRegardedAsValidSlotAllowedMinObj1Width1; // 0cm, // 00cm object1. if object2 > 80cm, set to 10m will not regarded as a valid slot.
	APA_DISTANCE_TYPE APASlotObj12ExistRegardedAsValidSlotAllowedMinObj1Width2; // 30cm, // 30cm object1. if object2 > 80cm, set to 10m will not regarded as a valid slot.
	APA_DISTANCE_TYPE APASlotObj12ExistRegardedAsValidSlotAllowedMinObj1Width3; // 80cm, // 80cm object. set to 10m will not regarded as a valid slot.
	APA_DISTANCE_TYPE APASlotObj12ExistRegardedAsValidSlotAllowedMinObj2Width1; // 0cm, // 0cm object2. if object1 > 80cm, set to 10m will not regarded as a valid slot.
	APA_DISTANCE_TYPE APASlotObj12ExistRegardedAsValidSlotAllowedMinObj2Width2; // 30cm, // 30cm object2. if object1 > 80cm, set to 10m will not regarded as a valid slot.
	APA_DISTANCE_TYPE APASlotObj12ExistRegardedAsValidSlotAllowedMinObj2Width3; // 80cm, // 80cm object. set to 10m will not regarded as a valid slot.

	
	// 
	// Slot Obj Type check parameter: kjy 2013 10 01 added end
	
	// SaveSnsDtdObjDisToFilterBuf related cal start
	
	UCHAR APASlotSnsDtdObjDisFilterSpeedDevidedThreshold[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM - 1]; // 0 ~ 10km/h, 10 ~ 20km/h, 20km/h ~
	APA_INDEX_TYPE APASlotSnsDtdObjDisFilterMinBufSize[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM];
	APA_INDEX_TYPE APASlotSnsDtdObjDisFilterBufSize[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM];
	APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterRegardedAsNoObjDtdDevidedObjDis; // 200cm
	APA_ENUM_TYPE APASlotSnsDtdObjDisFilterRegardedAsNoObjDtdMaxDtdObjPtNum[2][APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 
	APA_ENUM_TYPE APASlotSnsDtdObjDisFilterRegardedAsNoObjDtdMinConsecutiveNoDtdObjPtNum[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 
	APA_ENUM_TYPE APASlotSnsDtdObjDisFilterCheckRisingOrFallingEdgeMinDtdObjPtNum[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 
	APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterCheckRisingOrFallingEdgeDevidedObjWidth1; // ~ 50cm,
	APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterCheckRisingOrFallingEdgeDevidedObjWidth2; // 80cm,
	APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterCheckRisingOrFallingEdgeMaxDeltaDisUp[3]; // 30cm, 40cm, 50cm, 
	APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterCheckRisingOrFallingEdgeMaxDeltaDisDown[3]; // 5cm, 8cm, 13cm, 
	
	APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterFlatObjTolDevidedObjDis; // 200cm
	APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterFlatObjTolDis1; // 50, 5cm, obj dis < 200cm vehicle
	APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterFlatObjTolDis2; // 70, 7cm, obj dis < 200cm vehicle
	APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterFlatObjTolDis3; // 150, 15cm, obj dis > 200cm curb.
	APA_ENUM_TYPE APASlotSnsDtdObjDisFilterRegardedAsFlatObjMinDtdObjPtNum1[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 
	APA_ENUM_TYPE APASlotSnsDtdObjDisFilterRegardedAsRisingOrFallingMinDtdObjPtNum[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 
	APA_ENUM_TYPE APASlotSnsDtdObjDisFilterLowSpdRegardedAsNoiseMinFlatPtNum[3]; // 4, // total flat pt num = 0, 1, 2
	APA_ENUM_TYPE APASlotSnsDtdObjDisFilterLowSpdRegardedAsNoiseMaxPercentage; // 40: 40%, 
	APA_SLOT_PT_SLOPE_TYPE APASlotSnsDtdObjDisFilterAllowedMaxDeltaSlope1[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 120, // 76deg. // 52: atan(52/30) = 60deg.
	APA_SLOT_PT_SLOPE_TYPE APASlotSnsDtdObjDisFilterAllowedMaxDeltaSlope2[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 30, // 76deg. // 52: atan(52/30) = 60deg.
	APA_ENUM_TYPE APASlotSnsDtdObjDisFilterRegardedAsOKShapeMinOKDeltaSlopeNum[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // low speed 2, high speed: 1.
	APA_SLOT_PT_SLOPE_TYPE APASlotSnsDtdObjDisFilterObjAllowedMaxSlope; // 52,// 82, 70deg. 52, 60deg. 
	APA_SLOT_PT_SLOPE_TYPE APASlotSnsDtdObjDisFilterObjHeadAllowedMaxSlope; // 17, // 30deg. 30, 45deg. 
	APA_SLOT_PT_SLOPE_TYPE APASlotSnsDtdObjDisFilterObjTailAllowedMinSlope; // -17, // -30deg. 30, 45deg. 
	APA_ENUM_TYPE APASlotSnsDtdObjDisFilterObjTailCheckNoiseAllowedMinNoObjDtdBetTwoPt; // 1 
	APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterHeadOrTailFlatObjTolDis[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 5cm
	APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterAllowedToRemoveTwoPointsMaxDis; // 35cm
	APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterFillRisingEdgeMinObjDis; // 150cm
	APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterFillRisingEdgeMaxObjDis; // 350cm
	APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterFillFallingEdgeMinObjDis; // 50cm
	APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterFillFallingEdgeMaxObjDis; // 350cm
	APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterFillFlatCurbMinObjDis;//250cm
	APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterFillFlatCurbMaxObjDis;//500cm
	APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterFillRisingOrFallingEdgeWithCurbMinObjDis;//120cm
	APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterFillRisingOrFallingEdgeWithCurbMaxObjDis;//220cm
	APA_ENUM_TYPE APASlotMinObjCntOfCurbToCheckProfileWithCurb;//3
	APA_ENUM_TYPE APASlotMinObjCntOfProfileToCheckProfileWithCurb;//2
	APA_SLOT_PT_SLOPE_TYPE APASlotMaxDeltaSlopeToCheckIfTheProfileWithCurbIsExsit[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM];//
    APA_DISTANCE_TYPE APASlotMinDeltaDisBetweenCurbAndProfileobjToCheckIfProfileWithCurb;//100cm
	APA_SLOT_PT_SLOPE_TYPE APASlotSnsDtdObjDisFilterFillRisingAndFallingEdgeMaxSlope; // -52, // -52: -60deg.
	APA_SLOT_PT_SLOPE_TYPE APASlotSnsDtdObjDisFilterFillRisingAndFallingEdgeAllowedMaxFlatSlope; // 8, // 8: 15deg.
	APA_SLOT_PT_SLOPE_TYPE APASlotSnsDtdObjDisFilterFillRisingAndFallingEdgeAllowedMaxDeltaSlope; // 5, // 5: 9deg.
	APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillRisingAndFallingEdgeAllowedMaxFlatPtNumAtHead[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 
	APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillRisingAndFallingEdgeAllowedMaxNoObjPt[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 
	APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillRisingAndFallingEdgeAllowedMaxConsecutiveNoObjPt[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 
	APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterFillRisingAndFallingEdgeMaxObjDeltaDis; // 80cm
	APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterFillRisingAndFallingEdgeFirstTwoPtMaxObjDeltaDis[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; //  10cm
	APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillRisingEdgeAllowedMinTotalObjPt[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 4 points.
	APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillRisingEdgeAllowedMinBigObjPt1[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 2 points. // end pt is rising pt 
	APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillRisingEdgeAllowedMinBigObjPt2[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 3 points. // end pt is flat pt
	APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillRisingEdgeAllowedMinObjPtIndex[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // speed < 8kph : 0, < 15kph: 1, < 20kph: 3, > 20kph: 4. 
	APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillFallingEdgeAllowedMinTotalObjPt[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 4 points.
	APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillFallingEdgeAllowedMinBigObjPt1[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 2 points. // end pt is Falling pt 
	APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillFallingEdgeAllowedMinBigObjPt2[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 3 points. // end pt is flat pt
	APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillFallingEdgeAllowedMinObjPtIndex[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // speed < 8kph : 0, < 15kph: 1, < 20kph: 3, > 20kph: 4. 
	APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterFillFlatProfilePointsMaxDeltaDis1; // 15cm 
	APA_DISTANCE_TYPE APASlotSnsDtdObjDisFilterFillFlatProfilePointsMaxDeltaDis2; // 35cm // max 45deg.
	APA_SLOT_PT_SLOPE_TYPE APASlotSnsDtdObjDisFilterFillFlatProfileMaxSlope; // 30, // 30: 45deg.
	APA_SLOT_PT_SLOPE_TYPE APASlotSnsDtdObjDisFilterFillFlatProfileMaxDeltaSlope[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 5, // 5: 10deg.
	APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillFlatProfileAllowedMaxNoObjPt[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 
	APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillFlatProfileAllowedMaxConsecutiveNoObjPt[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 
	APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillFlatProfileAllowedMinTotalObjPt[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 6 points.
	APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillFlatProfileAllowedMinBigObjPt1[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 3 points. // obj pt cnt is 6 ~ 8 
	APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillFlatProfileAllowedMinBigObjPt2[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM]; // 2 points. // obj pt cnt is 9 or 10
	BOOLEAN APASlotSnsDtdObjDisFilterUseConfirmedSmallObjEvenIfBigObjExist; // FALSE.	
	APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillRisingAndFallingEdgeAllowedSmallObjNum[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM];
	APA_ENUM_TYPE APASlotSnsDtdObjDisFilterFillRisingAndFallingEdgeAllowedMinBigObjNum[APA_SLOT_SUPPORT_OBJ_DIS_NOISE_CHECK_SPEED_DEVIDED_NUM];
	
	// SaveSnsDtdObjDisToFilterBuf related cal end

	APA_DISTANCE_TYPE APASlotRoundObjPtSearchBackMaxDis;
	APA_DISTANCE_TYPE APASlotDisToCarCheckCarDrvDis1; // 100cm.
	APA_DISTANCE_TYPE APASlotDisToCarCheckCarDrvDis2; // 300cm.
	APA_DISTANCE_TYPE APASlotDisToCarCheckCarDrvDis3; // 400cm.
	APA_DISTANCE_TYPE APASlotDisToCarCheckObjIsFlatTolDis; // 15cm.
	APA_DISTANCE_TYPE APASlotDisToCarCheckObjIsFlatMinWidth; // 120cm.
	APA_DISTANCE_TYPE APASlotDisToCarCheckObjIsFlatMinValidObjWidth; // 70cm.
	APA_DISTANCE_TYPE APASlotDisToCarCheckObjIsFlatMaxCarDrvDis; // 60cm.
	APA_SLOT_PT_SLOPE_TYPE APASlotDisToCarCheckObjIsFlatMinSlope; // -17, // 30deg.
	APA_DISTANCE_TYPE APASlotCarToObjDisCalObj1WidthToBeConsidered;
	APA_DISTANCE_TYPE APASlotCarToObjDisCalObj2WidthToBeConsidered;
	APA_DISTANCE_TYPE APASlotCarToObjDisCalObjToCarDisTolLen; 
	
	APA_DISTANCE_TYPE APASlotHFOVWidthBySeg[APA_SLOT_APA_SENSOR_HFOV_DIVIDED_SEG_NUM];	
	APA_ENUM_TYPE APASlotLAPASnsIndex;
	APA_ENUM_TYPE APASlotRAPASnsIndex;
	// USHORT APASlotDefinition;
	APA_DISTANCE_TYPE APASlotObjCheckMaxSearchDisForNoObjDetected[APA_SLOT_OBJ_IS_BIG_ENOUGH_CHECK_TYPE_NUM];
	APA_DISTANCE_TYPE APASlotObjCheckDevidedObjDis[APA_SLOT_SUPPORT_OBJ_CHECK_OBJ_DIS_DEVIDED_NUM];
	APA_ENUM_TYPE APASlotObjCheckMinObjPointNum[APA_SLOT_SUPPORT_OBJ_CHECK_SPEED_DEVIDED_NUM][APA_SLOT_SUPPORT_OBJ_CHECK_OBJ_DIS_DEVIDED_NUM + 1];
	APA_DISTANCE_TYPE APASlotObjCheckMinObjWidth[APA_SLOT_SUPPORT_OBJ_CHECK_SPEED_DEVIDED_NUM][APA_SLOT_SUPPORT_OBJ_CHECK_OBJ_DIS_DEVIDED_NUM + 1];
	APA_ENUM_TYPE APASlotObjCheckMinCurbPointNum;
	APA_DISTANCE_TYPE APASlotObjCheckMinCurbWidth;
	APA_ENUM_TYPE APASlotObjCheckRegardAsObjOrCurbIsBigEnoughMinPointNum[APA_SLOT_OBJ_IS_BIG_ENOUGH_CHECK_TYPE_NUM]; // 5
	APA_ENUM_TYPE APASlotObjCheckRegardAsObjOrCurbIsBigEnoughMinContinuousPointNum[APA_SLOT_OBJ_IS_BIG_ENOUGH_CHECK_TYPE_NUM]; // 5
	APA_DISTANCE_TYPE APASlotObjCheckRegardAsObjOrCurbIsBigEnoughMinObjWidth[APA_SLOT_OBJ_IS_BIG_ENOUGH_CHECK_TYPE_NUM];
	APA_DISTANCE_TYPE APASlotObjCheckRegardAsSameObjMaxDeltaObjDis[APA_SLOT_OBJ_IS_BIG_ENOUGH_CHECK_TYPE_NUM]; // 120cm
	APA_DISTANCE_TYPE APASlotObjCheckSearchBkForCheckingObjTypeDisFromCurrentObjPoint; // 1.5m;
	APA_ENUM_TYPE APASlotObjCheckSearchBkForCheckingObjTypeMaxObjPointNum; // 7


	APA_DISTANCE_TYPE APASlotDetectionCompensateCarToObjDisDevidedThreshold[APA_SLOT_OBJ_CAR_TO_OBJ_DIS_COMPENSATE_TYPE_NUM]; // 0 ~ 10km/h, 10 ~ 20km/h, 20km/h ~
	UCHAR APASlotDetectionCompensateSpeedDevidedThreshold[APA_SLOT_SUPPORT_SLOT_LENGTH_COMPENSATE_SPEED_DEVIDED_NUM]; // 0 ~ 10km/h, 10 ~ 20km/h, 20km/h ~
	APA_DISTANCE_TYPE APASlotDetectionCompensateLengthHead[APA_SLOT_SUPPORT_SIMPLE_OBJ_TYPE_NUM][APA_SLOT_SUPPORT_SLOT_LENGTH_COMPENSATE_SPEED_DEVIDED_NUM + 1]; // Slot start
	APA_DISTANCE_TYPE APASlotDetectionCompensateLengthTail[APA_SLOT_SUPPORT_SIMPLE_OBJ_TYPE_NUM][APA_SLOT_SUPPORT_SLOT_LENGTH_COMPENSATE_SPEED_DEVIDED_NUM + 1]; // Slot end.
	APA_DISTANCE_TYPE APASlotDetectionToleranceDis;
	APA_DISTANCE_TYPE APASlotDetectionToleranceDisForTrajCal;
	APA_DISTANCE_TYPE APASlotMaxSlotLengthWithInvalidObj2;
	APA_DISTANCE_TYPE APASlotSlotLengthCompensatedDisWithInvalidObj1;
	APA_DISTANCE_TYPE APASlotMinDisCarToObjByPassingSlot; // Use car rear axis center as the reference point 
	APA_DISTANCE_TYPE APASlotMaxDisCarToObjByPassingSlot;// Use car rear axis center as the reference point 
	APA_DISTANCE_TYPE APASlotMaxDisCarToObjByPassingSlotWhenObjHasOffset;// Use car rear axis center as the reference point 
	APA_DISTANCE_TYPE APASlotUseMaxDisCarToObjByPassingSlotWhenObjHasOffsetCarDriveDis; // 10m.
	APA_DISTANCE_TYPE APASlotMaxOffsetDisBetweenObj1AndObj2ForParallel;
	APA_DISTANCE_TYPE APASlotMaxOffsetDisBetweenObj1AndObj2ForPerpendicular;
	APA_DISTANCE_TYPE APASlotMinDisForCurbDetection;// Use car rear axis center as the reference point 
	APA_DISTANCE_TYPE APASlotMaxDisForCurbDetection;// Use car rear axis center as the reference point 
	APA_DISTANCE_TYPE APASlotConsiderSecondSlotDepthMinDeltaSlotLen;
	APA_DISTANCE_TYPE APASlotRegardAsFirstSlotDepthMinSlotLen;
	APA_DISTANCE_TYPE APASlotMinStartCheckingCurbOffsetLen;
	APA_DISTANCE_TYPE APASlotMinRegardedAsCurbMinCurbLenAtSlotHeadAndTail;
	APA_DISTANCE_TYPE APASlotMinSmallSlotLen; // 6 steps parking. 	
	APA_DISTANCE_TYPE APASlotMaxSlotLength;	
	APA_DISTANCE_TYPE APASlotCurbRegardedAsCurbDetectedDevidedSlotLen[APA_SLOT_CURB_DT_CHECK_DEVIDE_SLOT_LEN_NUM - 1];
	APA_ENUM_TYPE APASlotCurbRegardedAsCurbDetectedMinObjPtNum[APA_SLOT_CURB_DT_CHECK_DEVIDE_SLOT_LEN_NUM]; // 0 ~ 6m ~ 7 ~
	APA_DISTANCE_TYPE APASlotCurbRegardedAsCurbDetectedMinCurbLen; // 1m.
	APA_DISTANCE_TYPE APASlotCurbDetCurbToObj2CutOffDis; // 1.2m.
	
	APA_DISTANCE_TYPE APASlotCurbLineTolerance;
	APA_DISTANCE_TYPE APASlotCurbLineFitAllowSnsDtObjDisTolerance;
	APA_DISTANCE_TYPE APASlotCurbLineFitAllowCurbLineToObjDisTolerance;
	APA_DISTANCE_TYPE APASlotCurbLineFitAllowCurbLineToObjDisTolerance2;
	APA_DISTANCE_TYPE APASlotEndPosXAllowCurbLineToObjDisTolerance;
	APA_DISTANCE_TYPE APASlotEndPosXOutOfAllowCurbLineToObjDisToleranceCompensateDis;
	APA_ENUM_TYPE APASlotCurbLineFitAllowMinObjPt;
	APA_DISTANCE_TYPE APASlotCurbLineFitAllowMinCurbLength;
	APA_ANGLE_TYPE APASlotCurbLineFitAllowMaxDeltaCarAngAndCurbLineAng;
	APA_ANGLE_TYPE APASlotCurbLineFitAllowMaxCurbLineAndYAng;
	APA_ANGLE_TYPE APASlotCurbLineFitCurbLineAngCompensateRatio;
	APA_DISTANCE_TYPE APASlotMinSlotDepth;// Use car rear axis center as the reference point 
	APA_DISTANCE_TYPE APASlotMaxSlotDepth;// Use car rear axis center as the reference point	
	APA_DISTANCE_TYPE APASlotMaxPathAfterSlot;
	APA_DISTANCE_TYPE APASlotMinPathAfterSlot; // With obj 2 valid. dis cal from slot end pt.
	APA_DISTANCE_TYPE APASlotMinPathAfterSlotWithoutObj2; // dis cal from slot start pt. should considering covex or concave road.
	APA_DISTANCE_TYPE APASlotMinPathAfterSlotWithVeryBigSlot; // With obj 2 valid. dis cal from slot end pt.
	
	APA_DISTANCE_TYPE APASlotRearSideSnsStartInsertObjPtToFrnSideSnsCarDrvDis;
	//APA_DISTANCE_TYPE APASlotRearSideSnsCheckCurbMinValidCurbLen;
	APA_SLOT_PT_SLOPE_TYPE APASlotRearSideSnsSlopPtSlopeTolerance;
	APA_DISTANCE_TYPE APASlotRearSideSnsAndFrntSideSnsCarCenterPtXTolerance; 
	APA_DISTANCE_TYPE APASlotRearSideSnsAndFrntSideSnsCarCenterPtYTolerance;
//	APA_ANGLE_TYPE    APASlotRearSideSnsAndFrntSideSnsCarCenterPtAngTol;
	APA_DISTANCE_TYPE APASlotFrontSideSnsCheckAsNoObjDisValue;
	APA_DISTANCE_TYPE APASlotRearSideSnsCheckAsNoObjDisValue;
	APA_SLOT_PT_SLOPE_TYPE  APASlotRearSideSnsCheckCurbSlopeMaxValue;
	APA_ENUM_TYPE APASlotRearSideSnsCheckCurbMinValidCurbPtNum;
	APA_DISTANCE_TYPE APASlotRearSideSnsCheckCurbMinValidCurbLength;
	APA_DISTANCE_TYPE APASlotRearSideSnsCheckCurbMaxAllowSearchBkDis; // 4m
	APA_DISTANCE_TYPE APASlotRearSideSnsCheckCurbMaxAllowObj12SearchBkDis; // 2m
	APA_ANGLE_TYPE APASlotRearSideSnsCheckAsInvalidCurbPtMinDeltaCarAng; // 16deg. 4m with R = 15m.
	APA_DISTANCE_TYPE APASlotRearSideSnsCheckCurbAsValidMinNoObjDisWidth; // 50cm
	APA_DISTANCE_TYPE APASlotRearSideSnsCheckCurbAsValidCurbMaxLength; // 300cm
	APA_DISTANCE_TYPE APASlotRearSideSnsCheckCurbRegardedAsSmallObjWidth; // 80cm
	APA_SLOT_PT_SLOPE_TYPE APASlotRearSideSnsCheckCurbRegardedAsFlatObjMaxDeltaSlope; // 3 = 6deg.
	APA_SLOT_PT_SLOPE_TYPE APASlotRearSideSnsCheckCurbRegardedAsFlatObjMaxSlope; // 11 = 20deg.
	APA_DISTANCE_TYPE APASlotRearSideSnsCheckCurbRegardedAsFlatObjMaxDeltaDis; // 4cm.
	APA_DISTANCE_TYPE APASlotRearSideSnsCheckCurbAsValidForSmallObjDeltaCarToObjDis1; // 80cm
	APA_DISTANCE_TYPE APASlotRearSideSnsCheckCurbAsValidForSmallObjDeltaCarToObjDis2; // 1.6 m
	APA_DISTANCE_TYPE APASlotRearSideSnsCheckCurbAsValidForFlatObjDeltaCarToObjDis1; // - 20cm
	APA_DISTANCE_TYPE APASlotRearSideSnsCheckCurbAsValidForFlatObjDeltaCarToObjDis2; // 30cm
	APA_DISTANCE_TYPE APASlotRearSideSnsCheckCurbAsValidForFlatObjDeltaCarToObjDis3; // 140cm
	APA_DISTANCE_TYPE APASlotRearSideSnsCheckCurbAsValidForCarDeltaCarToObjDis1; // -400cm
	APA_DISTANCE_TYPE APASlotRearSideSnsCheckCurbAsValidForCarDeltaCarToObjDis2; // 140cm
	APA_DISTANCE_TYPE APASlotRearSideSnsCheckCurbAsValidForHighCurbCarToObjDis1; // 60cm
		
	
	APA_DISTANCE_TYPE APASlotFrontSideSnsAdjacentPtsAreNoObjDisMinYValue;
	uchar APASlotMaxCarAngDuringMeasurement;	// unit:degree	// for DID$63 by zhx 20120802
/*2.4.9.2*** Perpendicular slot ****/
	// USHORT PSlotDefinition;
	APA_DISTANCE_TYPE APASlotPMinSmallSlotLen; // 6 steps parking. 	
	APA_DISTANCE_TYPE APASlotPNeedToCheckSlotEndPtMinSlotLen;
	APA_DISTANCE_TYPE APASlotPNeedToCheckSlotEndPtMinPoleWidth;
	APA_DISTANCE_TYPE APASlotPRegardAsInvalidSlotEndPtMinDeltaCarPos;
	APA_DISTANCE_TYPE APASlotPDefSlotLenWithoutObj1;
	APA_DISTANCE_TYPE APASlotPDefSlotLenWithoutObj2;
	APA_DISTANCE_TYPE APASlotPMaxSlotLength;
	APA_DISTANCE_TYPE APASlotPMaxSlotLengthWithInvalidObj2;	
	APA_DISTANCE_TYPE APASlotPMinSlotDepth;// Use car rear axis center as the reference point 
	APA_DISTANCE_TYPE APASlotPMaxSlotDepth;// Use car rear axis center as the reference point 
	APA_DISTANCE_TYPE APASlotPMaxPathAfterSlot;	
	APA_DISTANCE_TYPE APASlotPMinStartCheckingCurbOffsetLen;
	APA_ANGLE_TYPE APASlotPObj2NotExistObj1BorderLineFitCompensateAng1;
	APA_ANGLE_TYPE APASlotPObj2NotExistObj1BorderLineFitCompensateAng2;
	APA_DISTANCE_TYPE APASlotPMinPathAfterSlotWithObj2; // Dis cal from slot end pt.
	APA_DISTANCE_TYPE APASlotPMinPathAfterSlotWithoutObj2; // dis cal from slot start pt. should considering covex or concave road.
	APA_DISTANCE_TYPE APASlotPMinPathAfterSlotWithObj2BigSlot; // Dis cal from slot end pt.
	APA_DISTANCE_TYPE APASlotPObj1YCorCompensateDeltaDis1IfInvalid; // car L corner pt.y + this delta dis is regarded as the Obj1.Y.
	APA_DISTANCE_TYPE APASlotPObj2YCorCompensateDeltaDis1IfInvalid; // car R corner pt.y + this delta dis is regarded as the Obj2.Y.
	APA_DISTANCE_TYPE APASlotPObj1YCorCompensateDeltaDis2IfInvalid; // Car L side + this delta dis and transform to the real coor.Y is regarded as Obj1.Y.
	APA_DISTANCE_TYPE APASlotPObj2YCorCompensateDeltaDis2IfInvalid; // Car R side + this delta dis and transform to the real coor.Y is regarded as Obj2.Y.

/*2.4.9.3*** Park Exit slot ****/
	APA_DISTANCE_TYPE APASlotPEStartConsiderCornerObjMaxDis; // 50cm.
	APA_DISTANCE_TYPE APASlotPEMinSlotLength;	
	APA_DISTANCE_TYPE APASlotPEDefaultFrontObjectDisWhenNoObjectIsDetected; // 80cm.
	APA_DISTANCE_TYPE APASlotPEDefaultRearObjectDisWhenNoObjectIsDetected; // 80cm.
	APA_MS_TIME_TYPE  APASlotPESlotCheckStartDelayTime;
	APA_DISTANCE_TYPE APASlotPEMinParkingOutSideObjectDis;	
	
/*2.4.9.4***Angular slot ****/
	//USHORT APSlotDefinition;	
	APA_DISTANCE_CAL_FLOAT_TYPE APASlotAPMinKofTheAngularSlotBorderLine;	
	APA_DISTANCE_CAL_FLOAT_TYPE APASlotAPMaxKofTheAngularSlotBorderLine;	
	APA_DISTANCE_TYPE APASlotAPSlotBorderLineMinLength;	
	APA_DISTANCE_TYPE APASlotAPMinDisCarToObjByPassingSlot; // Use car side as the reference point		
	APA_DISTANCE_TYPE APASlotAPMaxDisCarToObjByPassingSlot;// Use car side as the reference point	
	APA_DISTANCE_TYPE APASlotAPMinSlotWidthWithNoCarAtHead;	
	APA_DISTANCE_TYPE APASlotAPMinSlotWidthWithObjAtHead;		
	APA_DISTANCE_TYPE APASlotAPSafetyDisToTheSideCarAtTheEndPosition;
	APA_DISTANCE_TYPE APASlotAPCalMinDisToTheCurb; // This parameter is used to confirm if the slot depth is big enough. We should consider the car has a round angle at front and rear. this parameter may be with negative value.
	APA_DISTANCE_TYPE APASlotAPRegardAsACarMinCarWidth;
	APA_DISTANCE_TYPE APASlotAPRegardAsACarMaxCarWidth;
	APA_DISTANCE_TYPE APASlotAPRegardAsNoObjMinSlotWidth;
	APA_DISTANCE_TYPE APASlotAPAllowMaxSlotWidthBetweenTwoCars; // Hear, it is the object 1 (car 1) width + current car width + 2 * safty distance between cars.
	APA_DISTANCE_TYPE APASlotAPAllowMinSlotWidthBetweenTwoCars; // Hear, it is the object 1 (car 1) width + current car width + 2 * safty distance between cars.

/* 2.4.9.5 *** Slot Correction ***/
	APA_DISTANCE_TYPE APASlotCorSDGKeepObjPtDis;
	APA_DISTANCE_TYPE APASlotCorSDGKeepNoObjPtDis;
	APA_DISTANCE_TYPE APASlotCorSDGKeepObjPtMinDeltaDtDis;
	APA_DISTANCE_TYPE APASlotCorSDGSnsDtObjReagionWidth;
	APA_DISTANCE_TYPE APASlotCorSDGSnsDtObjRegardedAsSameObjTolDis;
	UCHAR APASlotCorSDGSnsDtObjProbalilityPercentage;
	APASlotPCorRROrRLSnsDeltaAngInfo APASlotPCorRROrRLDeltaAngBetweenCurAngAndEndAng;
	APASlotPCorRRSOrRLSSnsDeltaAngInfo APASlotPCorSideSnsDeltaAngBetweenCurAngAndEndAng;
	APA_DISTANCE_TYPE APASlotPCorCorOrSideSnsDisArray[2][APA_SLOT_P_COR_SNS_DIS_DIV_NUM -1];
	APA_ANGLE_TYPE APASlotPCorCorSnsCompensatAngByDeltaAngAndSnsDtObjDis[2][APA_SLOT_COR_DELTA_ANG_MAX_ZONE_NUM][APA_SLOT_P_COR_SNS_DIS_DIV_NUM];
	APA_ANGLE_TYPE APASlotPCorRROrRLSnsCompensatAngByDeltaAng[2][APA_SLOT_COR_DELTA_ANG_MAX_ZONE_NUM];
	APA_ANGLE_TYPE APASlotPCorCompDisByConstantValue[2];
	APA_ANGLE_TYPE APASlotPCorSideSnsCompensatAngByDeltaAngAndSnsDtObjDis[2][APA_SLOT_COR_RRS_RLS_DELTA_ANG_MAX_ZONE_NUM][APA_SLOT_P_COR_RRS_RLS_SNS_DIS_DIV_NUM];
	APA_ANGLE_TYPE APASlotPCorSideSnsCompensatAngByDeltaAng[2][APA_SLOT_COR_RRS_RLS_DELTA_ANG_MAX_ZONE_NUM];
	APA_ENUM_TYPE APASlotPCorMinDetXOfCorOrSideSnsDtOnCarBodyIfIngoreDisDtOnCarHead[4];
	APA_ENUM_TYPE APASlotPCorMinCntOfCorOrSideSnsDtOnCarBodyIfIngoreDisDtOnCarHead[4];
	APA_DISTANCE_TYPE APASlotPCorMaxDisOfCorOrSideSnsDtIfCarInOutSideSlot[4];
	APA_DISTANCE_TYPE APASlotPCorMaxSlotLenToAddCompForObj2IfObj1CorObj2NotCor;
	APA_DISTANCE_TYPE APASlotPCorObj2CompDisIfObjIsCorObj2IsNotCor[9];
	APA_DISTANCE_TYPE APASlotPCorMinDelPosXToCorObjByAngAndDis[4];
	APA_DISTANCE_TYPE APASlotPCorMinDelYToCompDisByConstantValue[2];
	APA_ANGLE_TYPE APASlotPCorMaxCarAngToAcceptRRSnsDis[2];

	// for perpendicular parking slot correction filter 2014 08 21
	APA_DISTANCE_TYPE APASlotCorSDGPointCanBeRemovedContiguousPointMinDisP;
	APA_DISTANCE_TYPE APASlotCorSDGPointCanBeRemovedContiguousPointMinDisP2;
	APA_DISTANCE_TYPE APASlotCorSDGSamplePointUpdateSmallDeltaLen;
	APA_DISTANCE_TYPE APASlotCorSDGSamplePointUpdateSmallDeltaLen2;
	APA_SLOT_PT_SLOPE_TYPE APASlotCorSDGSamplePointCanBeRemovedMaxObjPtDeltaSlope;
	APA_DISTANCE_TYPE APASlotCorSDGSamplePointNoisePtCanBeRemovedRegardAsNoiseMinObjWidth;
	APA_DISTANCE_TYPE APASlotCorSDGSamplePointNoisePtStartCheckBkObjWidth;
	APA_DISTANCE_TYPE APASlotCorSDGSamplePointNoisePtCanBeRemovedCheckMinNoObjWidth;
	APA_DISTANCE_TYPE APASlotCorSDGSamplePointNoisePtCanBeRemovedHeadOrTailMaxDeltaObjDis;
	APA_SLOT_PT_SLOPE_TYPE APASlotCorSDGSamplePointNoisePtCanBeRemovedHeadOrTailMaxSlope;
	APA_SLOT_PT_SLOPE_TYPE APASlotCorSDGSamplePointNoisePtCanBeRemovedHeadOrTailMinSlope;
	APA_SLOT_PT_SLOPE_TYPE APASlotCorSDGSamplePointAllowedMaxDeltaSlope;
	APA_DISTANCE_TYPE APASlotCorSDGSamplePointNoisePtCanBeRemovedCheckStartHeadWidth;
	APA_DISTANCE_TYPE APASlotCorSDGSamplePointNoisePtCanBeRemovedCheckNoiseWidth;
	APA_DISTANCE_TYPE APASlotCorSDGSamplePointNoisePtCanBeRemovedMaxDis;
	APA_DISTANCE_TYPE APASlotCorSDGSamplePointNoisePtCanBeRemovedSameObjTol;
	APA_DISTANCE_TYPE APASlotCorSDGSamplePointNoisePtCanBeRemovedCheckNoiseToObjWidth;
	APA_ENUM_TYPE APASlotCorSDGSamplePointNoisePtCanBeRemovedMinSameObjPtNum;
	APA_DISTANCE_TYPE APASlotCorSDGSamplePointNoisePtCanBeRemovedMinObjWidth;
	APA_ENUM_TYPE APASlotCorSDGSamplePointNoisePtCanBeRemovedMaxNoiseWidthPercentage;
	APA_DISTANCE_TYPE APASlotCorSDGSamplePointNoisePtRegardedAsSameObjMaxDeltaObjDis;
	APA_DISTANCE_TYPE APASlotCorSDGSamplePointNoisePtRegardedAsSameObjMinObjWidth;
	APA_DISTANCE_TYPE APASlotCorSDGSamplePointUpdateLongDeltaLen;
	APA_DISTANCE_TYPE APASlotCorSDGSamplePointCanBeRemovedMaxObjDis;
	APA_ENUM_TYPE APASlotCorSDGSamplePointNoisePtCanBeRemovedMinObjPtOutOfTolNum;
	APA_ENUM_TYPE APASlotCorSDGSamplePointNoisePtCanBeRemovedMinNoObjPtWitinNoiseNum;
	APA_ENUM_TYPE APASlotCorSDGSamplePointNoisePtCanBeRemovedMinNoObjPtTotalNum;
	
	// Parallel slot:
	APA_DISTANCE_TYPE APASlotCarMayHitObj2CheckDeltaDisYMax; // default to: 100cm.	
	APA_DISTANCE_TYPE APASlotCarMayHitObj2CheckDeltaDisYMin; // default to: -150cm.	
	APA_DISTANCE_TYPE APASlotCorObj2YStCorMinDeltaCarPosToEndPosX; // default to: 80cm.
	APA_DISTANCE_TYPE APASlotCorObj2YStCorMaxCornerSnsDtDis1; // default to: 60cm.
	APA_DISTANCE_TYPE APASlotCorObj2YStCorMaxCornerSnsDtDis2; // default to: 60cm.
	APA_DISTANCE_TYPE APASlotCorObj2YStCorMaxMidSnsDtDis1; // default to: 120cm.
	APA_DISTANCE_TYPE APASlotCorObj2YStCorMaxMidSnsDtDis2; // default to: 120cm.
	APA_RATIO_TYPE APASlotCorObj2YCompensateDisByCarAng[3]; // 0: FR, 1: FRM, 2: FLM
	APA_RATIO_TYPE APASlotCorObj1YCompensateDisByCarAng[3]; // 0: RL, 1: RLM, 2: RRM
	APA_DISTANCE_TYPE APASlotCorObj1YStCorMinDeltaCarPosToEndPosX; // default to: 60cm.
	APA_DISTANCE_TYPE APASlotCorObj1YStCorMaxCornerSnsDtDis; // default to: 180cm.
	APA_DISTANCE_TYPE APASlotCorObj1YStCorMaxMidSnsDtDis; // default to: 50cm.
	APA_DISTANCE_TYPE APASlotCorObj1YStCorMaxMidSnsDtDis2; // default to: 150cm.
	APA_DISTANCE_TYPE APASlotCorObj1YStCorMaxMidSnsDtDis3; // default to: 150cm.
	APA_DISTANCE_TYPE APASlotCorObj1YRecalObj1YMaxDeltaCarCornerYandObj1Y; // default to: 70cm.
	APA_DISTANCE_TYPE APASlotCorObj2YResetObj2YEndPosToCurCarPosDeltaX; // when no obj dted reset the obj1. -5cm
	APA_DISTANCE_CAL_FLOAT_TYPE APASlotCorObj2YResetObj2YCarFBumperOverObj2YDis; // when no obj dted reset the obj1. 35cm.
	APA_DISTANCE_TYPE APASlotCorObj2YResetObj2YRegardAsFSnsDtObjDis; // when no obj dted reset the obj1. 70cm.
	APA_DISTANCE_TYPE APASlotCorObj1YResetObj1YEndPosToCurCarPosDeltaX; // when no obj dted reset the obj1. -5cm
	APA_DISTANCE_CAL_FLOAT_TYPE APASlotCorObj1YResetObj1YCarRBumperOverObj1YDis; // when no obj dted reset the obj1. 35cm.
	APA_DISTANCE_TYPE APASlotCorObj1YResetObj1YRegardAsRSnsDtObjDis; // when no obj dted reset the obj1. 70cm.
	APA_MS_TIME_TYPE APASlotCorObjConfirmedAsNotDtdDelayTimeWhenVehicleIsStatic; // 1s.
	APA_MS_TIME_TYPE APASlotCorObjConfirmedAsNotDtdTimeWhenVehicleIsStatic; // 3s.
	APA_DISTANCE_TYPE APASlotCorObjConfirmedAsNotDtdDeltaCarToEndPosXDevidedDis; // 30cm.	
	APA_DISTANCE_TYPE APASlotCorObjConfirmedAsNotDtdMaxCarToObjDisWithVehIsMovingCor1; // 46cm.
	//APA_DISTANCE_TYPE APASlotCorObjConfirmedAsNotDtdMinCarToObjDisWithVehIsMovingCor1; // 80cm.
	APA_DISTANCE_TYPE APASlotCorObjConfirmedAsNotDtdMaxCarToObjDisWithVehIsMovingCor2; // 46cm.
	//APA_DISTANCE_TYPE APASlotCorObjConfirmedAsNotDtdMinCarToObjDisWithVehIsMovingCor2; // 80cm.
	APA_DISTANCE_TYPE APASlotCorObjConfirmedAsNotDtdMinCarDrvDisWithOneGearChanged1; // 35cm.
	APA_DISTANCE_TYPE APASlotCorObjConfirmedAsNotDtdMinCarDrvDisWithOneGearChanged2; // 5cm.
	
	APA_MS_TIME_TYPE APASlotCorObjConfirmedAsNotDtdTimeMovingAwayFromObj; // 2s.
	APA_MS_TIME_TYPE APASlotCorObjConfirmedAsNotDtdTimeMovingCloseToObj; // 0s.
	
	// Perpendicular slot:
	APA_MS_TIME_TYPE APASlotCorPSlotCorrectCycleTime;
	APA_DISTANCE_TYPE APASlotCorPSlotCorrectDeltaXDis;
	APA_ANGLE_TYPE APASlotCorPCarEndPosAngCompensateAngPerFrwAndBk; // default to: 1deg
	
	APA_DISTANCE_TYPE APASlotCorPObjYCorSearchBkDeltaXDis; // default to: 100cm.
	APA_DISTANCE_TYPE APASlotCorPEndPosYCalObj1YSearchBkStartDeltaXDis; // default to: 30cm.
	APA_DISTANCE_TYPE APASlotCorPEndPosYCalObj1YSearchBkEndDeltaXDis; // default to: 200cm.
	APA_DISTANCE_TYPE APASlotCorPEndPosYCalObj2YOptimalPtMinDeltaX; // 20cm.
	APA_DISTANCE_TYPE APASlotCorPEndPosYCalObj2YOptimalPtDeltaYWithOriginalObj2Y; // 25cm.
	APA_DISTANCE_TYPE APASlotCorPEndPosYCalObj2YOptimalPtDeltaY; // 10cm.
	APA_ENUM_TYPE APASlotCorPEndPosYCalObj2YOptimalPtMinPtNum; // 3.
	APA_DISTANCE_TYPE APASlotCorPEndPosYCalObj2YSearchBkStartDeltaXDis; // default to: 150cm.
	APA_DISTANCE_TYPE APASlotCorPEndPosYCalObj2YSearchBkEndDeltaXDis; // default to: 220cm.

	// Car RRC may hit obj2, correct obj2.x, obj2.y parameter:
	APA_ANGLE_TYPE APASlotCorPCarMayHitObj2CorRRCSnsMaxCompensateAng; // default to: 30deg
	APA_DISTANCE_TYPE APASlotCorPCarMayHitObj2CorRRCSnsCalObj2YCompensateDis; // default to: 40cm.
	APA_DISTANCE_TYPE APASlotCorPCarMayHitObj2CorRRSSnsCalObj2YCompensateDis; // default to: 40cm.
	APA_DISTANCE_TYPE APASlotCorPCarMayHitObj2CorRRCSnsStartCalDis; // default to: 60cm.
	APA_DISTANCE_TYPE APASlotCorPCarMayHitObj2CorRRSSnsStartCalDis; // default to: 60cm.

	// Obj2.y correct use SDG buf parameter:
	APA_DISTANCE_TYPE APASlotCorPObj2YCorAllowObj2YAndCarPosYDeltaDis; // default to: 80cm.
	APA_DISTANCE_TYPE APASlotCorPObj2YCorDuringStep2AllowObj2YDeltaDis; // default to: 15cm.

	APA_ANGLE_TYPE APASlotCorPObj2YCorRegardedAsInvalidObj2YMaxDeltaCarAng1; // 15deg.
	APA_ANGLE_TYPE APASlotCorPObj2YCorRegardedAsInvalidObj2YMaxDeltaCarAng2; // 35deg.
	APA_DISTANCE_TYPE APASlotCorPObj2YCorRegardedAsInvalidObj2YMaxSnsDtObjDis; // 45cm.
	APA_DISTANCE_TYPE APASlotCorPObj2YCorRegardedAsInvalidObj2YMaxDeltaObj2YDis; // 15cm.
	
	APA_DISTANCE_TYPE APASlotCorPObj2YCorStartUseSDGBufCorCarPosDeltaObj2XDis; // default to: 90cm.
	APA_DISTANCE_TYPE APASlotCorPObj2YCorStartUseSDGBufCorCarPosDeltaXDis; // default to: 70cm.
	APA_ANGLE_TYPE APASlotCorPObj2YCorMaxDeltaCarAng; // default: 50deg.
	APA_ANGLE_TYPE APASlotCorPObj2YCorRRSSnsCalCompensateMaxCarAng; // default to: 45deg
	APA_DISTANCE_TYPE APASlotCorPObj2YCorRRSSnsCalObj2YCompensateDis; // default to: 60cm.
	APA_DISTANCE_TYPE APASlotCorPObj2YCorRRSSnsCompMinXYWidth; // default to: 100cm.
	APA_DISTANCE_TYPE APASlotCorPObj2YCorRRSSnsCompDisWithDelatCarAng1; // default to: 40cm.
	APA_DISTANCE_TYPE APASlotCorPObj2YCorRRSSnsCompDisWithDelatCarAng2; // default to: 20cm.
	APA_DISTANCE_TYPE APASlotCorPObj2YCorAllowObjMaxYAndMinYDeltaDis; // default to: 60cm.
	APA_DISTANCE_TYPE APASlotCorPObj2YCorObj2ExistAllowMaxSnsDtDis; // default to: 250cm.
	
	APA_DISTANCE_TYPE APASlotCorPRecalObj2YCarPosXMinDeltaDisToEndPosX; // default to: 250cm.
	APA_ANGLE_TYPE APASlotCorPRecalObj2YMinCarAng;
	APA_ANGLE_TYPE APASlotCorPRecalObj2YMaxCarAng;

	// Obj exist check Parameter:
	APA_DISTANCE_TYPE APASlotCorPObjExistMaxSnsDtDis; // default to: 120cm.
	APA_DISTANCE_TYPE APASlotCorPObjExistMaxSnsDtDisEndPosCloseToObj1or2; // default to: 80cm.
	APA_DISTANCE_TYPE APASlotCorPRecalObjYExistMaxSnsDtDis;
	APA_DISTANCE_TYPE APASlotCorPRecalObjYMaxSnsDtDisEndPosCloseToObj1or2;
	
	// Car RLC may hit obj1, correct obj1.x, obj1.y parameter:
	APA_DISTANCE_TYPE APASlotCorPCarMayHitObj1CorUseRLSnsAsHighPriorityDeltaDis; // 15cm.
	APA_DISTANCE_TYPE APASlotCorPCarMayHitObj1CorUseMidSnsAsHighPriorityDeltaDis; // 15cm.
	APA_DISTANCE_TYPE APASlotCorPCarMayHitObj1CorRLSSnsCalObj1YCompensateDis1; // 10cm.
	APA_DISTANCE_TYPE APASlotCorPCarMayHitObj1CorRLSSnsCalObj1YCompensateDis2; // 15cm.
	APA_DISTANCE_TYPE APASlotCorPCarMayHitObj1CorRLCSnsCalObj1YCompensateDis0; // 0cm, big slot inside the slot.
	APA_DISTANCE_TYPE APASlotCorPCarMayHitObj1CorRLCSnsCalObj1YCompensateDis1; // 10cm. big slot outside the slot.
	APA_DISTANCE_TYPE APASlotCorPCarMayHitObj1CorRLCSnsCalObj1YCompensateDis2; // 15cm. small slot.
	APA_DISTANCE_TYPE APASlotCorPCarMayHitObj1CorMidSnsCalObj1YCompensateDis; // 20cm.
	APA_DISTANCE_TYPE APASlotCorPCarMayHitObj1CorSnsStartCalDis; // default to: 70cm.
	APA_ANGLE_TYPE APASlotCorPRecalObj1YMinCarAng;
	APA_ANGLE_TYPE APASlotCorPRecalObj1YMaxCarAng;
	APA_DISTANCE_TYPE APASlotCorPRecalObj1YCarPosXMinDeltaDisToEndPosX;

	APA_ANGLE_TYPE APASlotCorPGetObj1MaxYMinCarAng;
	APA_ANGLE_TYPE APASlotCorPGetObj1MaxYMaxCarAng;
	APA_ANGLE_TYPE APASlotCorPGetObj2MinYMinCarAng;
	APA_ANGLE_TYPE APASlotCorPGetObj2MinYMaxCarAng;

	// Slot border line delta angle:
	APA_ANGLE_TYPE APASlotCorPRegardSlotBorderLineDeltaAngIsBigMinDeltaAng;
	
	// Slot Border line fit parameter:
	APA_ENUM_TYPE APASlotCorPSlotBorderLineFitMaxStepSequenceNum; // 3
	APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitStartCheckFitSeqenceMaxDetalAng; //25.0 deg
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsOneStepIntoSlotMaxDeltaCarPosX; //0.8m
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsOneStepOutSlotMinDeltaCarPosX; //2.5m
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitConvexShapeCheckFirstStepIntoSlotMaxDeltaCarPosX; //1.8m
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitConvexShapeCheckFirstStepOutSlotMinCarPosX; //-30cm
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitConvexShapeCheckSecondStepIntoSlotMaxDeltaCarPosX; //1.2m
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitMaxSnsDtDis; //1.8m
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardedRCSnsDtDisAsInvalidMaxDeltaObjDis; // 30cm
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardedRSSnsDtDisAsInvalidMaxDeltaObjDis; // 15cm
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitDeltaCarPosToEndPos; // 50cm.
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitMaxDeltaCarPosX;
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitUseObjPtWrIndexMaxDeltaCarPosX1; // 80cm,
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitUseObjPtWrIndexMaxDeltaCarPosX2; // 3500cm,
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitUseObjPtWrIndexMinObjXWidthHead; // 2300cm,
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitNotUseObjPtWrIndexMinObjXWidthTail; // 1800cm,
	APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitNotUseObjPtWrIndexMaxDeltaCarAng; // 5Deg,
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitDeltaObjXDevide1;
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitStartDeltaObjX;
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitAllowMinDeltaObjXBtTwoObjPt;
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsValidObjMinWidth[4];
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsValidObjMaxWidth[4];
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsStraightLineDeltaYTol1; // 5cm.
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsStraightLineDeltaYTol2; // 8cm.
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsStraightLineDeltaYTol3; // 12cm.
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsStraightLineConcaveDeltaYTol1; // 20cm,
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsStraightLineConcaveDeltaYTol2; // 30cm,
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsStraightLineConvexDeltaYTol1; // 40cm,
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsStraightLineConvexDeltaYTol2; // 70cm,
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsWihinTolBigLineLenRatio; // 10: atan(1/10) = 5.7deg.
	APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitUseBigTolMaxDeltaLineAndEndPosAng; // 5deg.
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitAllowMaxConvexWidthAtMidOfLine;
	
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitConsiderConvexPtMinDeltaYTol1; // 15cm.
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitConsiderConvexPtMinDeltaYTol2; // 35cm.
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitConsiderConvexPtAllowOffsetMaxObjPtYToCarDis; // 35cm.
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitConsiderConvexPtAllowOffsetMaxDis; // 80cm.
	
	APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitConsiderConvexPtMaxDeltaCarAng; // 25deg.
	APA_CAL_FLOAT_TYPE APASlotCorPSlotBorderLineFitConsiderConvexPtLineOffsetFactor; // pt to line dis * factor. def: 0.6
	
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsConvexOrConcaveLineMinDeltaY[4];
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsConvexOrConcaveLineMinLineLen[4];
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsCarValidObjBdLineMinLen[4]; // 3.5m.
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsValidOKLineMinObjWidth[4];
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsValidOKLineMinLineLenAtHead[4];
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitMinLineLen1[3][4]; // car angle and bdline angle is less than 15deg.
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitMinLineLen2[3][4]; // car angle and bdline angle is great than 15deg.
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitLineWithConvexAtHeadAllowMaxLineLen; // 1.8m.
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsValidLineMinObjPtDeltaXDis;
	APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitMinLineLenDevidedDeltaCarAngAndBdLineAng1; // 8deg
	APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitMinLineLenDevidedDeltaCarAngAndBdLineAng2; // 15deg.
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitMaxWithoutDtdObjToCarDrvMaxPosXDis1; // 30cm.
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitMaxWithoutDtdObjToCarDrvMaxPosXDis2; // 80cm. line angle and car angle is great than -15deg.
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitMaxWithoutDtdObjToCarDrvMaxPosXDis3; // 140cm. line angle and car angle is less than -15deg.
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitStopCheckWithoutDtdObjMinSideObjDis; // 120cm.
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitStopCheckWithoutDtdObjMinCornerObjDis; // 80cm.
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitStartToCheckLineShapeMinObjXWidth;
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitDeltaObjXOffset1; // 50cm,
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitDeltaObjXOffset2; // 100cm,
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitDeltaObjXOffset3;
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitFirstBkStepFitLineMaxObjDis; // 80cm.
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitGetRidOffLineEndPtDisCalFactor; // def: 8: for 3m, it will get rid of 37.5cm at head and tail and then fit the line.
	
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsValidBdLineMinLen1; // 200cm with big bd line angle.
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitRegardAsValidBdLineMinLen2; // 100cm. general angle should at least big than this value.
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitAllowMaxDeltaX;
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitAllowMaxDeltaY;
	APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitMaxDeltaCarAngAndBdLineAng;
	APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitCompMinStCarAngAndBdLineAng;
	APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitMaxBdLineAng[4];
	APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitMinBdLineAng[4];
	APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitCarNeedToReachAlmostEndPosMinBdLineAng; // car tail angle is great than head.
	APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitCompAngPerDeltaRSideSnsAndBdLineAng;
	APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitCompAngPerDeltaLSideSnsAndBdLineAng;
	APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitCompAngPerDeltaRCornerSnsAndBdLineAng;
	APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitCompAngPerDeltaLCornerSnsAndBdLineAng;
	APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitCompAngPerDeltaRSideSnsAndBdLineAng2; // car head has a great angle than tail.
	APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitCompAngPerDeltaLSideSnsAndBdLineAng2;
	APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitCompAngPerDeltaRCornerSnsAndBdLineAng2;
	APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitCompAngPerDeltaLCornerSnsAndBdLineAng2;
	APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitCompAngPerBdLineAngLSideSns;
	APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitCompAngPerBdLineAngLCornerSns;
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitCompDisPerDeltaSideSnsAndBdLineAng;
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitCompDisRSideSns;
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitCompDisLSideSns;
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitCompDisRRCornerSns;
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitCompDisRLCornerSns;
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitMinLineLenDeltaXDisToEndPosX;
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitMaxWithoutDtdObjToEndPosDis;
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitMaxAllowNoObjDtDisXInBdLine;	
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitEndPosLineUpdateTolDevidedCarToEndPosDis; // 50cm.
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitEndPosLineUpdateMinCTol1; // 5cm.
	APA_DISTANCE_TYPE APASlotCorPSlotBorderLineFitEndPosLineUpdateMinCTol2; // 15cm.
	APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitEndPosAngUpdateMinTolAng1; // 0.3 deg.
	APA_ANGLE_TYPE APASlotCorPSlotBorderLineFitEndPosAngUpdateMinTolAng2; // 1.0 deg.
	APA_ANGLE_TYPE APASlotCorPChkEndPosLineMaxDeltaCarAngAndEndPosLineAng;
	APA_DISTANCE_TYPE APASlotCorPChkEndPosLineMaxCarSideToObjDis;
	APA_ANGLE_TYPE APASlotCorPAllowEndPosLineAngResetMaxEndPosCarAng;
	APA_ANGLE_TYPE APASlotCorPAllowEndPosLineAngResetMinEndPosCarAng;
	APA_DISTANCE_TYPE APASlotPRegardSlotBorderLineExistMaxDeltaObjDis;
	APA_DISTANCE_TYPE APASlotPRegardSlotBorderLineExistMaxDeltaCarPosX; // 1.2m
	APA_ANGLE_TYPE APASlotPRegardSlotBorderLineExistCheckMinDeltaCarAng; // 7deg,
	APA_DISTANCE_TYPE APASlotPRegardSlotBorderLineExistMaxDeltaCarPosXCarAngAchieved; // 40cm,
	APA_DISTANCE_TYPE APASlotPRegardRSideSnsAsNoObjDtDeltaDisToEndPosX;
	APA_DISTANCE_TYPE APASlotPRegardRCornerSnsAsNoObjDtDeltaDisToEndPosX;
	APA_DISTANCE_TYPE APASlotPSDGBufRRCornerSnsDtMinCarPosX;
	APA_DISTANCE_TYPE APASlotPSDGBufRLCornerSnsDtMinCarPosX;
	APA_DISTANCE_TYPE APASlotPSDGBufRRSideSnsDtMinCarPosX;
	APA_DISTANCE_TYPE APASlotPSDGBufRLSideSnsDtMinCarPosX;
	APA_DISTANCE_TYPE APASlotPRCornerSnsDtMaxObjDisInsideSlot[2];
	APA_DISTANCE_TYPE APASlotPRCornerSnsDtMaxObjDisOutsideSlot;
	APA_DISTANCE_TYPE APASlotPRSideSnsDtMaxObjDis;
	APA_DISTANCE_TYPE APASlotPResetSlotBorderLineMaxDeltaCarPosX;
	APA_ANGLE_TYPE APASlotPResetSlotBorderLineMinDeltaCarAngWithEndPos1;
	APA_ANGLE_TYPE APASlotPResetSlotBorderLineMinDeltaCarAngWithEndPos2;
	APA_DISTANCE_TYPE APASlotPResetSlotBorderLineMaxCarAndBorderLineDisY;

	APA_DISTANCE_TYPE APASlotPDtmEndPosLineCheckSideObjExisMinDeltaXDisSideSns;
	APA_DISTANCE_TYPE APASlotPDtmEndPosLineCheckSideObjExisMinDeltaXDisCornerSns;
	

/*2.4.10 *** Trajectory Calculate  Algorithm****/
/*2.4.10.1 *** Parallel****/

	APA_DISTANCE_TYPE APATrajCalMaxOriginalPtToObj2Dis[2]; // 30cm.
	APA_DISTANCE_TYPE APATrajCalOriginalPtToObj2DisCompByRisingEdgeMinWidth; // 80cm.
	APA_DISTANCE_TYPE APATrajCalOriginalPtToObj2DisCompByRisingEdgeMaxWidth; // 150cm.
	APA_DISTANCE_TYPE APATrajCalOriginalPtToObj2DisCompByRisingEdgeMinSafetyDis; // 15cm at: width: 80cm.
	APA_DISTANCE_TYPE APATrajCalOriginalPtToObj2DisCompByRisingEdgeMaxSafetyDis; // 30cm at: width: 150cm.
	APA_DISTANCE_TYPE APATrajCalOriginalPtToObj2DisCompByRisingEdgeMaxObj2PtX; // 100cm at: width: 150cm.

	APATrajCalPointOnCarPosDataCalFloatType APATrajCalCarCornerPosExp[APA_CAR_CORNER_NUMBER];
	APA_DISTANCE_TYPE APATrajCalSafetyDisToObjAtRear;	
	APA_DISTANCE_TYPE APATrajCalSafetyDisToObjAtRearSnsWithoutDtdObj;	
	APA_DISTANCE_TYPE APATrajCalSafetyDisToObjAtRearTurningCar; // when turning the car
	APA_DISTANCE_TYPE APATrajCalSafetyDisToObjAtRearForParallelParkingInStep3Cor;	
	APA_RATIO_TYPE APATrajCalSafetyDisToObjAtRearRatioForParallelParkingInStep3Cor;	// according to current car angle. drive straight line backwards.
	APA_DISTANCE_TYPE APATrajCalSafetyDisToObjAtFront;  
	APA_DISTANCE_TYPE APATrajCalSafetyDisToObjAtFrontSnsWithoutDtdObj; // 
	APA_DISTANCE_TYPE APATrajCalSafetyDisToObjAtFrontTurningCar; // when turning the car 
	APA_DISTANCE_TYPE APATrajCalSafetyDisToObjInOppsiteSide; // End Position
	APA_DISTANCE_TYPE APATrajCalSafetyDisFromRearTireToObj2AtStep2[10]; // Safety distance between the corner object and the rear tire.
	APA_DISTANCE_TYPE APATrajCalSafetyDisToObjAtFrontCornerTurningCarFor3StepParking[APA_SLOT_OBJ_PROFILE_TYPE_NUM + 1]; // Safety distance between the corner object and the car front outer corner. 
	APA_DISTANCE_TYPE APATrajCalSafetyDisToObjAtFrontCornerTurningCarForOver3StepParking[APA_SLOT_OBJ_PROFILE_TYPE_NUM + 1]; // Safety distance between the corner object and the car front outer corner. 
	APA_DISTANCE_TYPE APATrajCalSafetyDisForRearTireToCurb;	
	APA_DISTANCE_TYPE APATrajCalStep3MoveMinDisToObj1For4StepParking; // 20cm.
	APA_ANGLE_TYPE APATrajCalStep3MoveMinCarAngFor4StepParking; // 4deg. 2cm.
	APA_ANGLE_TYPE APATrajCalStep3MoveMaxCarAngFor4StepParking; // 15deg. 10cm.
	APA_DISTANCE_TYPE APATrajCalStep3MoveOffsetXMinDisFor4StepParking; // 2cm.
	APA_DISTANCE_TYPE APATrajCalStep3MoveOffsetXMaxDisFor4StepParking; // 10cm.
	APA_DISTANCE_TYPE APATrajCalCarPosOnTheKeyPointTolDis;
	APA_ANGLE_CAL_FLOAT_TYPE APATrajCalSnsDtdDistanceValidUpwardStartAngle;	
	APA_ANGLE_CAL_FLOAT_TYPE APATrajCalSnsDtdDistanceValidUpwardEndAngle;	
	APA_ANGLE_CAL_FLOAT_TYPE APATrajCalSnsDtdDistanceValidDownwardStartAngle;
	APA_ANGLE_CAL_FLOAT_TYPE APATrajCalSnsDtdDistanceValidDownwardEndAngle;	
	APA_DISTANCE_TYPE APATrajCalMaxSnsDtDis[APA_SUPPORT_APA_SNS_NUM]; // relative to car rotation center 
	APA_DISTANCE_TYPE APATrajCalCarParkingAlongCurbMinSlotDepthRefObject;	
	APA_ANGLE_TYPE APATrajCalCarDriveStraightlyTolCarAngle;	
	APA_ANGLE_TYPE APATrajCalSetupSysCoordinateCarDriveStraightlyTolCarAngle1; // 5 deg.
	APA_ANGLE_TYPE APATrajCalSetupSysCoordinateCarDriveStraightlyTolCarAngle2; // 3 deg.
	APA_DISTANCE_TYPE APATrajCalStep23CircleMinOffsetDis;
	APA_RATIO_TYPE APATrajCalRegardedAsLineStepCarAtLineStepRatio; // 0.6
	APA_DISTANCE_TYPE APATrajCalRegardedAsStep3MaxCarPosXOffsetToEndPosX;
	APACoordinateDataType APATrajCalRRCMayHitObj2MoveStep3CircleDeltaDisFor3StepParking;
	APACoordinateDataType APATrajCalRRCMayHitObj2MoveStep3CircleDeltaDisFor4StepParking;
	APA_ANGLE_TYPE APATrajCalRRCMayHitObj2CorStep2SteeringAngReducedValue; // 8% Max steering angle.
	
	APA_DISTANCE_TYPE APATrajCalStep3CarWillHitObj2SearchBkMaxDis; // 150cm	
	APA_DISTANCE_TYPE APATrajCalStep3CarWillHitObj2SearchBkMinDis; // - 70cm

	// for recalculating the circle of 3rd step for 3 steps parking 2014 08 21
	APA_DISTANCE_TYPE APATrajCalMoveStep3Circle3StepParkingMinAddLen;
	APA_DISTANCE_TYPE APATrajCalKeepEnoughSafety3StepParkingSearchBkDis;
	APA_DISTANCE_TYPE APATrajCalMoveStep3CircleControlRatio;
	APA_DISTANCE_TYPE APATrajCalReCalStep3CircleRadiusControlRation;

	APA_DISTANCE_TYPE APATrajCalCheckSideObjDisDevideDis1; // 70cm	
	APA_DISTANCE_TYPE APATrajCalCheckSideObjDisDevideDis2; // 100cm	
	APA_DISTANCE_TYPE APATrajCalCheckSideObjDisStartObjPosY;
	APA_DISTANCE_TYPE APATrajCalCheckSideObjDisEndObjPosY;
	APA_DISTANCE_TYPE APATrajCalCarParkingStep2StartSearchingSteeringWheelAngMinDis1ToObj2; // 80cm,
	APA_DISTANCE_TYPE APATrajCalCarParkingStep2StartSearchingSteeringWheelAngMinDis2ToObj2; // 130cm,
	APA_DISTANCE_TYPE APATrajCalCarParkingStep2StartSearchingSteeringWheelAngSlotLen; // 7m,
	APA_DISTANCE_TYPE APATrajCalCarParkingStep2StartSearchingSteeringWheelAngMinY; // 350cm,
	APA_ANGLE_TYPE APATrajCalCarParkingStep2StartSearchingSteeringWheelAng1;	
	APA_ANGLE_TYPE APATrajCalCarParkingStep2StartSearchingSteeringWheelAng2;	
	APA_ANGLE_TYPE APATrajCalCarParkingStep2AllowMinSteeringWheelAng1;	
	APA_ANGLE_TYPE APATrajCalCarParkingStep2AllowMinSteeringWheelAng2;	
	APA_ANGLE_TYPE APATrajCalCarParkingStep2AllowMinSteeringWheelAng3;	
	APA_ANGLE_TYPE APATrajCalCarParkingStep2AllowMaxSteeringWheelAng1;	
	APA_ANGLE_TYPE APATrajCalCarParkingStep2AllowMaxSteeringWheelAng2;	
	APA_ANGLE_TYPE APATrajCalCarParkingStep2SteeringWheelAngStep1; // Add 2012 05 24	
	APA_ANGLE_TYPE APATrajCalCarParkingStep2SteeringWheelAngStep2; // Add 2012 05 24
	APA_ANGLE_TYPE APATrajCalCarParkingInStep2AllowMinSteeringWheelAng;	
	APA_ANGLE_TYPE APATrajCalCarParkingInStep2SteeringWheelAngStep; 
	APA_ANGLE_TYPE APATrajCalCarParkingInStep2AllowSteeringWheelTurnBackAng; // 40%	
	APA_DISTANCE_CAL_FLOAT_TYPE APATrajCalMinRearAxisCenterTurningRadius;
	//APA_DISTANCE_CAL_FLOAT_TYPE APATrajCalBackwardRearAxisCenterTurningRadius;     //add by wuzhen 0721
	APA_DISTANCE_CAL_FLOAT_TYPE APATrajCalMinRearTireTurningRadius;
	APA_DISTANCE_CAL_FLOAT_TYPE APATrajCalMinFOuterTurningRadius;
	APA_DISTANCE_CAL_FLOAT_TYPE APATrajCalMinFInnerTurningRadius;	
	APA_DISTANCE_CAL_FLOAT_TYPE APATrajCalMinROuterTurningRadius;	
	APA_DISTANCE_CAL_FLOAT_TYPE APATrajCalMinRInnerTurningRadius;	
	APA_ANGLE_CAL_FLOAT_TYPE APATrajCalMinFInnerCornerAndRAxisAng;
	APA_ANGLE_CAL_FLOAT_TYPE APATrajCalMinRInnerCornerAndRAxisAng;	
	APA_RATIO_TYPE APATrajCalLineIsVMaxK; // if the K of the line great than APATrajCalLineIsVMaxK, means the line is vertical,
	APA_RATIO_TYPE APATrajCalLineIsHMinK; // if the K of the line is less than APATrajCalLineIsHMinK, means the line is horizontal,
	APA_RATIO_TYPE APATrajCalLinesAreParallelMinDeltaK; // if the MATH_FABS(K1 - K2) is less than this value, we will assume that these two lines are parallel.
	APA_ANGLE_TYPE APATrajCalCarDriveVerticallyMaxCarAng; // if the K of the line great than APATrajCalLineIsVMaxK, means the line is vertical,
	APA_ANGLE_TYPE APATrajCalCarDriveHorMinCarAng; // if the K of the line great than APATrajCalLineIsVMaxK, means the line is vertical,
	APA_DISTANCE_TYPE APATrajCalCarParkingTrajectoryOuterTurningCircleMaxX1; // Car is located at Ycurc < 0 
	APA_DISTANCE_TYPE APATrajCalCarParkingTrajectoryOuterTurningCircleMaxX2; //  Car is located at Ycurc < 0	
	APA_DISTANCE_TYPE APASlotObj12CheckCarDrvDisY;
	
	APA_DISTANCE_TYPE APATrajCalMinSlotLengthWithInvalidObj2;
	APA_DISTANCE_TYPE APATrajCalCoordinateSetupCheckAllowMinCarPosXAtObj1[APA_TRAJCAL_COORDINATE_SETUP_CHECK_OBJ_CASE_NUM];
	APA_DISTANCE_TYPE APATrajCalCoordinateSetupCheckAllowMaxCarPosXAtObj1[APA_TRAJCAL_COORDINATE_SETUP_CHECK_OBJ_CASE_NUM];
	APA_DISTANCE_TYPE APATrajCalCoordinateSetupCheckAllowMinCarPosXAtObj2[APA_TRAJCAL_COORDINATE_SETUP_CHECK_OBJ_CASE_NUM];
	APA_DISTANCE_TYPE APATrajCalCoordinateSetupCheckAllowMaxCarPosXAtObj2[APA_TRAJCAL_COORDINATE_SETUP_CHECK_OBJ_CASE_NUM];
	APA_ANGLE_TYPE APATrajCalCoordinateSetupCheckAllowMinCarAngAtObj1[APA_TRAJCAL_COORDINATE_SETUP_CHECK_OBJ_CASE_NUM];
	APA_ANGLE_TYPE APATrajCalCoordinateSetupCheckAllowMaxCarAngAtObj1[APA_TRAJCAL_COORDINATE_SETUP_CHECK_OBJ_CASE_NUM];
	APA_ANGLE_TYPE APATrajCalCoordinateSetupCheckAllowMinCarAngAtObj2[APA_TRAJCAL_COORDINATE_SETUP_CHECK_OBJ_CASE_NUM];
	APA_ANGLE_TYPE APATrajCalCoordinateSetupCheckAllowMaxCarAngAtObj2[APA_TRAJCAL_COORDINATE_SETUP_CHECK_OBJ_CASE_NUM];

	APA_DISTANCE_TYPE APATrajCalSystemCoordinateSetupObj2StartEdgeCheckMaxX; // 130cm.
	APA_DISTANCE_TYPE APATrajCalSystemCoordinateSetupObj2StartEdgeCheckMaxX2; // 60cm.
	APA_DISTANCE_TYPE APATrajCalSystemCoordinateSetupObj2StartEdgeCheckMaxY; // 70cm.
	APA_DISTANCE_TYPE APATrajCalSystemCoordinateSetupObj2StartEdgeCheckMinY; // -60cm.
	APA_DISTANCE_TYPE APATrajCalSystemCoordinateSetupObj2StartEdgeCheckCompMaxY; // 40cm.
	
	APA_DISTANCE_TYPE APATrajCalAPAParkingCoordinateYOffsetDis;
	APA_DISTANCE_TYPE APATrajCalAPAParkingCoordinateSetUpObj2SearchDis;
	APA_DISTANCE_TYPE APATrajCalAPAParkingCoordinateSetUpObj1SearchDis;
	APA_DISTANCE_TYPE APATrajCalAPAParkingCoordinateSetUpUseNearestDisPtCalMaxDeltaObj1Dis; // 5cm.
	APA_DISTANCE_TYPE APATrajCalAPAParkingCoordinateSetUpUseNearestDisPtCalMaxDeltaObj2Dis; // 5cm.
	APA_DISTANCE_TYPE APATrajCalAPAParkingCoordinateSetUpNotUseNearestDisCalMinDeltaObjDis;
	APA_DISTANCE_TYPE APATrajCalAPAParkingCoordinateSetUpNotUseNearestDisCalMaxDeltaObjDis;
	APA_ANGLE_TYPE APATrajCalParalAPAParkingCoordinateYOffsetAngle1[2][APA_CAR_PARK_SIDE_NUM]; // - : End Pos Ang turning counter clock wise Offset Ang. +: End pos ang turning clock wise ang.
	APA_ANGLE_TYPE APATrajCalParalAPAParkingCoordinateYOffsetAngle2[2][APA_CAR_PARK_SIDE_NUM]; // - : End Pos Ang turning counter clock wise Offset Ang. +: End pos ang turning clock wise ang.
	APA_ANGLE_TYPE APATrajCalParalAPAParkingCoordinateYOffsetAngle3[2][APA_CAR_PARK_SIDE_NUM]; // - : End Pos Ang turning counter clock wise Offset Ang. +: End pos ang turning clock wise ang.
	APA_ANGLE_TYPE APATrajCalParalAPAParkingCoordinateYOffsetAngle4[2][APA_CAR_PARK_SIDE_NUM]; // - : End Pos Ang turning counter clock wise Offset Ang. +: End pos ang turning clock wise ang.
	APA_ANGLE_TYPE APATrajCalParalAPAParkingCoordinateYOffsetAngle5[2][APA_CAR_PARK_SIDE_NUM]; // - : End Pos Ang turning counter clock wise Offset Ang. +: End pos ang turning clock wise ang.
	APA_DISTANCE_TYPE APATrajCalParalMaxCarDriveOffsetDisFromTheEndPosX;
	APA_DISTANCE_TYPE APATrajCalParalMinCarDriveOffsetDisFromTheEndPosX;
	APA_ANGLE_TYPE APATrajCalParalMaxCarDriveOffsetDisFromTheEndPosXCorrespondCarAng;
	APA_ANGLE_TYPE APATrajCalParalAllowCarDrvAlongAGivenRadiusOffsetXCalMinCarAng; // 2deg,
	APA_ANGLE_TYPE APATrajCalParalAllowCarDrvAlongAGivenRadiusOffsetXCalMaxCarAng; // 12deg.
	APA_DISTANCE_TYPE APATrajCalParalAllowCarDrvAlongAGivenRadiusOffsetX1; // 1cm./2deg.
	APA_DISTANCE_TYPE APATrajCalParalAllowCarDrvAlongAGivenRadiusOffsetX2; // 9cm./12deg.
	
	APA_ANGLE_TYPE APATrajCalParalAllowCarDrvAlongAGivenRadiusMinCarAng;
	APA_ENUM_TYPE APATrajCalParalAllowCarDrvAlongAGivenRadiusFwMaxInSlotFwAndBkCnt;
	APA_ENUM_TYPE APATrajCalParalAllowCarDrvAlongAGivenRadiusBkMaxInSlotFwAndBkCnt;
	
	APA_DISTANCE_TYPE APATrajCalSafetyDisToObjAtSideOfCar;

	APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetCheckAllowedMaxPtDeltaX1; // 15cm
	APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetCheckAllowedMaxPtDeltaX2; // 10cm
	APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetCheckAllowedMinPtDeltaX; // 8cm
	APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetCheckAllowedMinDeltaYObj2; // 250cm
	APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetCheckAllowedMinDeltaYObj1; // 250cm
	APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetCheckCarCenterPtYMin1; // 0
	APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetCheckCarCenterPtYMin2; // 0
	APA_CAL_FLOAT_TYPE APATrajCalCarEndPosXOffsetCheckAllowedMinDelaCarAng; // 3deg
	APA_CAL_FLOAT_TYPE APATrajCalCarEndPosXOffsetCheckAllowedMaxDeltaBdLineAndCarAng; // 15deg
	APA_CAL_FLOAT_TYPE APATrajCalCarEndPosXOffsetCheckAllowedMinDeltaBdLineAndCarAng; // 3deg
	APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetMinXWithAngledObj1WithoutCurb1[APA_CAR_PARK_SIDE_NUM]; // 3cm
	APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetMaxXWithAngledObj1WithoutCurb1[APA_CAR_PARK_SIDE_NUM]; // 25cm
	APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetMinXWithAngledObj1WithoutCurb2[APA_CAR_PARK_SIDE_NUM]; // 3cm
	APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetMaxXWithAngledObj1WithoutCurb2[APA_CAR_PARK_SIDE_NUM]; // 25cm
	APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetMinXWithAngledObj2WithoutCurb1[APA_CAR_PARK_SIDE_NUM]; // 3cm
	APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetMaxXWithAngledObj2WithoutCurb1[APA_CAR_PARK_SIDE_NUM]; // 20cm
	APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetMinXWithAngledObj2WithoutCurb2[APA_CAR_PARK_SIDE_NUM]; // 3cm
	APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetMaxXWithAngledObj2WithoutCurb2[APA_CAR_PARK_SIDE_NUM]; // 20cm
	APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetMinXWithAngledObj12WithoutCurb1[APA_CAR_PARK_SIDE_NUM]; // 3cm
	APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetMaxXWithAngledObj12WithoutCurb1[APA_CAR_PARK_SIDE_NUM]; // 20cm
	APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetMinXWithAngledObj12WithoutCurb2[APA_CAR_PARK_SIDE_NUM]; // 3cm
	APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetMaxXWithAngledObj12WithoutCurb2[APA_CAR_PARK_SIDE_NUM]; // 20cm
	
	APA_DISTANCE_TYPE APATrajCalCarEndPosAllowedMinX;
	APA_DISTANCE_TYPE APATrajCalCarEndPosAllowedMaxX;
	APA_DISTANCE_TYPE APATrajCalCarEndPosHitCurbCheckRearBumperOffsetDis;
	APA_DISTANCE_TYPE APATrajCalCarEndPosHitCurbCheckFrontBumperOffsetDis;
	APA_DISTANCE_TYPE APATrajCalCarEndPosHitCurbCheckCarSideOffsetDis;
	
	APA_DISTANCE_TYPE APATrajCalCarEndPosDisToCurb[APA_CAR_PARK_SIDE_NUM];
	APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetToObj1AndObj2LineIfNoCurbDtdSlotLen1;
	APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetToObj1AndObj2LineIfNoCurbDtdSlotLen2;
	APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetToObj1AndObj2LineIfNoCurbDtdBothObjExist[APA_CAR_PARK_SIDE_NUM][APA_TRAJCAL_COORDINATE_SETUP_ROAD_TYPE_NUM][3][APA_TRAJCAL_COORDINATE_SETUP_OBJ_TYPE_NUM];	
	APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetToObj1AndObj2LineIfNoCurbDtdObj1Exist[APA_CAR_PARK_SIDE_NUM][APA_TRAJCAL_COORDINATE_SETUP_ROAD_TYPE_NUM][APA_TRAJCAL_COORDINATE_SETUP_OBJ_TYPE_NUM];	
	APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetToObj1AndObj2LineIfNoCurbDtdObj2Exist[APA_CAR_PARK_SIDE_NUM][APA_TRAJCAL_COORDINATE_SETUP_ROAD_TYPE_NUM][APA_TRAJCAL_COORDINATE_SETUP_OBJ_TYPE_NUM];	
	APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetToObj1AndObj2LineIfCurbDtdRCircle;	
	APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetToObj1AndObj2LineMaxDisIfCurbDtdRCircle;	
	APA_CAL_FLOAT_TYPE APATrajCalCarEndPosXOffsetToObj1AndObj2LineCalRatioIfCurbDtdRCircle;	
	APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetToObj1AndObj2LineIfCurbDtdLCircle;	
	APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetToObj1AndObj2LineMaxDisIfCurbDtdLCircle;	
	APA_CAL_FLOAT_TYPE APATrajCalCarEndPosXOffsetToObj1AndObj2LineCalRatioIfCurbDtdLCircle;	
	APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetFromCurbMinSlotLength;
	APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetFromCurbMinEndPosX;
	APA_CAL_FLOAT_TYPE APATrajCalCarEndPosXOffsetFromCurbCalFactor;	
	APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetFromCurbSlotDeltaLength; // Length of car + 1600
	APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetFromCurbDis1; // Length of car + 1600: 5cm.
	APA_DISTANCE_TYPE APATrajCalCarEndPosXOffsetFromCurbDis2; // Length of car + 800: 10cm.
	APA_DISTANCE_TYPE APATrajCalMaxSlotLengthForAGivenSlot;	
	APA_DISTANCE_TYPE APATrajCalMaxSlotLengthForRegardingObj1Invalid; // 12m.	
	APA_DISTANCE_CAL_FLOAT_TYPE APATrajCalInsertLineBtStep23Method1MinDeltaRadius; // APA_TRAJCAL_INSERT_LINE_BET_STEP2_3_CIRCLE_METHOD_1_MIN_DELTA_RADIUS;
//	APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method1Step2CenterPtAddDeltaValue[APA_TRAJCAL_INSERT_LINE_BET_STEP2_3_CIRCLE_METHOD_VALUE_NUM]; // APA_TRAJCAL_INSERT_LINE_BET_STEP2_3_CIRCLE_METHOD_1_MIN_DELTA_RADIUS;
//	APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method2Step2CenterPtAddDeltaValue[2][APA_TRAJCAL_INSERT_LINE_BET_STEP2_3_CIRCLE_METHOD_VALUE_NUM]; // APA_TRAJCAL_INSERT_LINE_BET_STEP2_3_CIRCLE_METHOD_1_MIN_DELTA_RADIUS;
	APA_DISTANCE_TYPE APATrajCalInsertLineBtStep23Method1RegardedAsBigSlotDeltaLen; // Car length + this value = slot length. 240cm.
	APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method3Step3CenterPtAddDeltaValue;
	APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method1Step2CenterPtAddDeltaValueForBigSlot;
	APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method12With3StepParkingStep3CenterPtAddDeltaValue[2];
	APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method12With4StepParkingStep3CenterPtAddDeltaValue[2];
	APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method12With5StepParkingStep3CenterPtAddDeltaValue[2];
	APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method12With6StepParkingStep3CenterPtAddDeltaValue[2];
	APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method1With3StepParkingStep2CenterPtAddDeltaValue[APA_TRAJCAL_INSERT_LINE_BET_STEP2_3_CIRCLE_METHOD_VALUE_NUM];
	APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method1With4StepParkingStep2CenterPtAddDeltaValue[APA_TRAJCAL_INSERT_LINE_BET_STEP2_3_CIRCLE_METHOD_VALUE_NUM];
	APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method1With5StepOr6StepParkingStep2CenterPtAddDeltaValue[APA_TRAJCAL_INSERT_LINE_BET_STEP2_3_CIRCLE_METHOD_VALUE_NUM];
	APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method2With3StepParkingStep2CenterPtAddDeltaValue1[APA_TRAJCAL_INSERT_LINE_BET_STEP2_3_CIRCLE_METHOD_VALUE_NUM];
	APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method2With3StepParkingStep2CenterPtAddDeltaValue2[APA_TRAJCAL_INSERT_LINE_BET_STEP2_3_CIRCLE_METHOD_VALUE_NUM];
	APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method2With4StepParkingStep2CenterPtAddDeltaValue1[APA_TRAJCAL_INSERT_LINE_BET_STEP2_3_CIRCLE_METHOD_VALUE_NUM];
	APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method2With4StepParkingStep2CenterPtAddDeltaValue2[APA_TRAJCAL_INSERT_LINE_BET_STEP2_3_CIRCLE_METHOD_VALUE_NUM];
	APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method2With5StepOr6StepParkingStep2CenterPtAddDeltaValue1[APA_TRAJCAL_INSERT_LINE_BET_STEP2_3_CIRCLE_METHOD_VALUE_NUM];
	APACoordinateDataCalFloatType APATrajCalInsertLineBtStep23Method2With5StepOr6StepParkingStep2CenterPtAddDeltaValue2[APA_TRAJCAL_INSERT_LINE_BET_STEP2_3_CIRCLE_METHOD_VALUE_NUM];
	APA_DISTANCE_TYPE APATrajCalInsertLineBtStep23MaxCarDriveOffsetDisFromTheEndPosX;
	
	APA_DISTANCE_TYPE APATrajCalCarParkingAllowLastStepCorMinCarCanDrvDisAfterEndPosAch;
	APA_ANGLE_TYPE APATrajCalCarParkingLastStepCorStep1SteeringWheelAng1; // X offset < 10cm
	APA_ANGLE_TYPE APATrajCalCarParkingLastStepCorStep2SteeringWheelAng1; // X offset < 10cm 
	APA_ANGLE_TYPE APATrajCalCarParkingLastStepCorStep1SteeringWheelAng2;  // X offset 10cm - 25cm
	APA_ANGLE_TYPE APATrajCalCarParkingLastStepCorStep2SteeringWheelAng2;  // X offset 10cm - 25cm
	APA_ANGLE_TYPE APATrajCalCarParkingLastStepCorStep1SteeringWheelAng3;  // X offset 25cm - 40cm
	APA_ANGLE_TYPE APATrajCalCarParkingLastStepCorStep2SteeringWheelAng3;  // X offset 25cm - 40cm

	APA_ANGLE_TYPE APATrajCalLastStepCarCanDrvMinDevidedCarAng; // (3.0 * PI / 180.0)
	APA_DISTANCE_TYPE APATrajCalLastStepCarCanDrvMinDevidedDis1; // 16cm.
	APA_DISTANCE_TYPE APATrajCalLastStepCarCanDrvMinDevidedDis2; // 30cm.
	APA_DISTANCE_TYPE APATrajCalLastStepCarCanDrvMaxDevidedDis; // 150cm.
	APA_RATIO_TYPE APATrajCalLastStepCarCanDrvDisMinRatio; // Car angle = 1deg: 30% Dis.
	APA_RATIO_TYPE APATrajCalLastStepCarCanDrvDisMaxRatio; // Car angle = 6deg: 40% Dis.
	APA_RATIO_TYPE APATrajCalLastStepCarCanDrvOptimizedDisRatio; // 70% Dis.
	APA_ANGLE_CAL_FLOAT_TYPE APATrajCalLastStepCarCanDrvDisDevidedCarAngMin; // car angle = 1deg.
	APA_ANGLE_CAL_FLOAT_TYPE APATrajCalLastStepCarCanDrvDisDevidedCarAngMax; // car angle = 6deg.
	APA_DISTANCE_TYPE APATrajCalLastStepCarCanDrvOptimizedMaxDis1; // car angle = 1 deg. 50cm, Dis.
	APA_DISTANCE_TYPE APATrajCalLastStepCarCanDrvOptimizedMaxDis2; // car angle = 6 deg. 70cm, Dis.
	APA_DISTANCE_TYPE APATrajCalLastStepCarPosToEndPosMinDis; // 30cm.
	
	
	APA_DISTANCE_TYPE APATrajCalInStep3WithSmallSlotCalCompensateDisAtFront; // 500; // 50cm,
	APA_DISTANCE_TYPE APATrajCalInStep3WithSmallSlotCalCompensateDisAtRear; // 500; // 50cm,

    /*2.4.10.2 *** Perpendicular****/
	APA_DISTANCE_TYPE APATrajCalPSafetyDisToObjAtRearTurningCar; // when turning the car
	APA_DISTANCE_TYPE APATrajCalPSafetyDisToObjAtFrontTurningCar; // when turning the car 

	UCHAR APATrajCalPWaitForSlotBorderLineCorrectTime1; // vehicle is static: 5 = 5 * 40ms = 200ms.
	UCHAR APATrajCalPWaitForSlotBorderLineCorrectTime2; // vehicle is moving: 2 = 2 * 40ms = 80ms.
	
	APA_DISTANCE_TYPE APATrajCalPAPAParkingCoordinateYOffsetDis;
	APA_DISTANCE_TYPE APATrajCalPAPAParkingCoordinateYSearchBkDis; // x + y , 150cm,
	APA_DISTANCE_TYPE APATrajCalPCarEndPosDisToCurb;
	APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetX;
	APA_DISTANCE_TYPE APATrajCalPCarEndPositionToObj1Dis;	
	APA_DISTANCE_TYPE APATrajCalPCarEndPositionToObj2Dis;
	
	APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetToObj1DisSmallSlotMinDeltaX; // 250cm.
	APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetToObj1DisForSmallSlot;	// 15cm
	APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetToObj1DisSmallSlotMinSideDis;	// 60cm
	APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetToObj1DisSmallSlotMaxSideDis; // 100cm
	APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetToObj1DisForSmallSlotResetTol;	// 20cm
	
	APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetDisWithObj12;
	APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetDisWithoutObj1;
	APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetDisWithoutObj2DevidedObj1Dis; // 140cm.
	APA_DISTANCE_TYPE APATrajCalPCarEndPositionOffsetDisWithoutObj2[2][4];
	APA_DISTANCE_TYPE APATrajCalPCalCarEndPosXWithMeanValueAllowObj1Obj2MaxOffsetDis;
	APA_DISTANCE_TYPE APATrajCalPCarEndPositionToRearObjDis;
	APA_DISTANCE_TYPE APATrajCalPCarEndPositionStartToCheckRObjMaxDeltaPosX;

	APA_ANGLE_TYPE APATrajCalPCarEndPositionCarAngTol;	
	APA_ANGLE_TYPE APATrajCalPCarParkingStep3AllowMaxSteeringWheelAngWithTwoCircleBk;	// 85% steering angle.
	APA_ANGLE_TYPE APATrajCalPCarParkingStep3SteeringWheelAngSearchStepWithTwoCircleBk;	// 12% steering angle.
	APA_DISTANCE_TYPE APATrajCalPCarParkingStep3UseBigSteeringAngMinDeltaXToEndPosDis; // 250cm.
	
	APA_DISTANCE_TYPE APATrajCalPCarParkingOffsetCarEndPositionAllowMaxDeltaY; // 400mm.
	APA_ANGLE_TYPE    APATrajCalPCarParkingOffsetCarEndPositionAllowMaxDeltaCarAng; // 15deg.
	APA_DISTANCE_TYPE APATrajCalPCarParkingOffsetCarEndPositionYDis1[6];
	APA_DISTANCE_TYPE APATrajCalPCarParkingOffsetCarEndPositionYDis2[6];
	APA_DISTANCE_TYPE APATrajCalPCarParkingOffsetCarEndPositionYDis3[6];
	APA_DISTANCE_TYPE APATrajCalPCarParkingCarEndPositionYDisTol01;
	APA_DISTANCE_TYPE APATrajCalPCarParkingCarEndPositionYDisTol02;
	APA_DISTANCE_TYPE APATrajCalPCarParkingCarEndPositionYDisTol1;
	APA_DISTANCE_TYPE APATrajCalPCarParkingCarEndPositionYDisTol10;
	APA_DISTANCE_TYPE APATrajCalPCarParkingCarEndPositionYDisTol2;
	APA_DISTANCE_TYPE APATrajCalPCarParkingCarEndPositionYDisTol1WithOnlyOneObj;
	APA_DISTANCE_TYPE APATrajCalPCarParkingCarEndPositionYDisTol2WithOnlyOneObj;
	APA_DISTANCE_TYPE APATrajCalPInStep3RegardedAsBigSlotDeltaWidth; // width of car + 170cm
	APA_ANGLE_TYPE    APATrajCalPInStep3UseOneCircleStepCorDeltaCarAngTol1; // 3deg.
	APA_ANGLE_TYPE    APATrajCalPInStep3UseOneCircleStepCorDeltaCarAngTol2; // 6deg.
	APA_ANGLE_TYPE    APATrajCalPInStep3UseOneCircleStepCorDeltaCarAngTol3; // 10deg.
	APA_DISTANCE_TYPE APATrajCalPInStep3UseOneCircleStepCorDeltaYTol1; // 5cm.
	APA_DISTANCE_TYPE APATrajCalPInStep3UseOneCircleStepCorDeltaYTol2; // 7.5cm
	APA_DISTANCE_TYPE APATrajCalPInStep3UseOneCircleStepCorDeltaYTol3; // 15cm.
	APA_DISTANCE_TYPE APATrajCalPInStep3UseOneCircleStepCorDeltaYTol4; // 20cm.
	
	APA_SPEED_TYPE APATrajCalPCarParkingCarEndPositionXDisTolDevidedSpd1; // 1kph
	APA_SPEED_TYPE APATrajCalPCarParkingCarEndPositionXDisTolDevidedSpd2; // 4kph
	APA_DISTANCE_TYPE APATrajCalPCarParkingCarEndPositionXDisTolLowSpd;	// 20cm, @1kph
	APA_DISTANCE_TYPE APATrajCalPCarParkingCarEndPositionXDisTolHighSpd;	// 60cm, @4kph 
	APA_DISTANCE_TYPE APATrajCalPCarParkingCarEndPositionXDisTol2;	// -40cm,
	APA_DISTANCE_TYPE APATrajCalPUseBigEndPosTolMaxDeltaXDis;
	APA_DISTANCE_TYPE APATrajCalPCarParkingAlongCurbMinSlotDepthRefObject;
	APA_DISTANCE_TYPE APATrajCalPMaxSlotLengthForAGivenSlot;	
	APA_DISTANCE_TYPE APATrajCalPRegardAsBigSlotLength;	
	APA_DISTANCE_TYPE APATrajCalPStep3CenterPtXOffsetDisFromEndPosXWithNoObj2;		
	APA_DISTANCE_TYPE APATrajCalPStartToCheckIfCarWillHitObj12OffsetDisFromRearBumper; // 20cm,
	APA_DISTANCE_TYPE APATrajCalPSafetyDisToObj12AtRearBumper; 
	APA_DISTANCE_TYPE APATrajCalPSafetyDisToObj2InStep3TurningCar00; // 8cm, 
	APA_DISTANCE_TYPE APATrajCalPSafetyDisToObj2InStep3TurningCar0; // 15cm, 
	APA_DISTANCE_TYPE APATrajCalPSafetyDisToObj2InStep3TurningCar1; // 20cm, 
	APA_DISTANCE_TYPE APATrajCalPSafetyDisToObj2InStep3TurningCar2; // 35cm,
	APA_DISTANCE_TYPE APATrajCalPSafetyDisToObjAtFrontCornerTurningCar;
	APA_DISTANCE_TYPE APATrajCalPSafetyDisToObjAtCornerTurningCar;	
	APA_DISTANCE_TYPE APATrajCalPSafetyDisToObjAtCornerTurningCarForStep1[10];
	APA_DISTANCE_TYPE APATrajCalPSafetyDisToObjAtCornerTurningCarWithLastOneStepToEndPosLine;	
	APA_ANGLE_TYPE APATrajCalPCarParkingStep2AllowMinSteeringWheelAng;	
	APA_ANGLE_TYPE APATrajCalPCarParkingStep3CenterPtXSearchingStep;	
	APA_DISTANCE_TYPE APATrajCalPCarParkingTrajectoryOuterTurningCircleMaxX1; // Car is located at Ycurc < 0 
	APA_DISTANCE_TYPE APATrajCalPCarParkingTrajectoryOuterTurningCircleMaxX2; //  Car is located at Ycurc < 0 
	APA_DISTANCE_TYPE APATrajCalPSearchSlotCalTrajAllowMaxKeyPointTolDis; // 10 // 1cm,	
	APA_DISTANCE_CAL_FLOAT_TYPE APATrajCalPSearchSlotCalTrajStep3CenterPtXMoveRatio; // 1.25	

	// First step bk, the car may hit the obj2, correct parameter.
	APA_DISTANCE_TYPE APATrajCalPFirstBkStepCorAllowMinCarToObj2XDis; // -70cm.
	APA_DISTANCE_TYPE APATrajCalPFirstBkStepCorAllowMaxCarToObj2XDis; // (Half of width of car + 50cm) 140cm.
	APA_DISTANCE_TYPE APATrajCalPFirstBkStepCorAllowMinCarToEndPosYDis; // -50cm.
	APA_ANGLE_TYPE APATrajCalPFirstBkStepCorAllowMaxCarAng; // 55deg.
	APA_DISTANCE_TYPE APATrajCalPFirstBkStepCorAllowMaxCarToObj2YDis; // (Half of width of car + 10cm) 100cm.

	APA_ANGLE_TYPE APATrajCalPUseOneStepCorToEndPosAllowMaxCarAng; // 10deg.
	APA_DISTANCE_TYPE APAParkProcPJustDriveStraightlyBkMaxDisToEndPos; // 1500, 1.5m
	APA_DISTANCE_TYPE APATrajCalPUseOneStepCorToEndPosDevidedDisToEndPos1; // 2000m,
	APA_DISTANCE_TYPE APATrajCalPUseOneStepCorToEndPosDevidedDisToEndPos2; // 2500m,
	APA_DISTANCE_TYPE APATrajCalPUseOneStepCorToEndPosDevidedDisToEndPos3; // 300m,
	
		
	APA_ANGLE_TYPE APATrajCalPCorrectTrajectoryAllowedMaxSteeringWheelAng;
	APA_DISTANCE_TYPE APATrajCalPHitObj2CorEndPosCOffsetDis; // 50cm.
	APA_DISTANCE_TYPE APATrajCalPMaxCarDriveOffsetDisFromTheEndPosY;
	APA_DISTANCE_TYPE APATrajCalPMinCarDriveOffsetDisFromTheEndPosY;
	APA_ANGLE_TYPE APATrajCalPMaxCarDriveOffsetDisFromTheEndPosYCorrespondCarAng;
	APA_DISTANCE_TYPE APATrajCalPFirstStepAllowCarDrvMaxFwDisAtSearchingSlot;
	APA_ANGLE_TYPE APATrajCalPFirstStepAllowCarDrvFwMaxDeltaCarAngAtSearchingSlot;
	APA_ANGLE_TYPE APATrajCalPAPAParkingCoordinateYOffsetAngle[APA_CAR_PARK_SIDE_NUM]; // - : End Pos Ang turning counter clock wise Offset Ang. +: End pos ang turning clock wise ang.
	APA_DISTANCE_TYPE APATrajCalPCorStepMinDeltaDisX; 
	APA_DISTANCE_TYPE APATrajCalPCorStepMinDeltaDisY; 
	APA_DISTANCE_TYPE APATrajCalPCorStepMinDeltaDisToEndPosX; // 25cm.

	APA_DISTANCE_TYPE APATrajCalPLastStepCarCanDrvMinDevidedDis; // 30cm.
	APA_DISTANCE_TYPE APATrajCalPLastStepCarCanDrvMaxDevidedDis; // 150cm.
	APA_RATIO_TYPE APATrajCalPLastStepCarCanDrvDisMinRatio; // Car angle = 1deg: 30% Dis.
	APA_RATIO_TYPE APATrajCalPLastStepCarCanDrvDisMaxRatio; // Car angle = 6deg: 40% Dis.
	APA_RATIO_TYPE APATrajCalPLastStepCarCanDrvOptimizedDisRatio; // 70% Dis.
	APA_ANGLE_CAL_FLOAT_TYPE APATrajCalPLastStepCarCanDrvDisDevidedCarAngMin; // car angle = 1deg.
	APA_ANGLE_CAL_FLOAT_TYPE APATrajCalPLastStepCarCanDrvDisDevidedCarAngMax; // car angle = 6deg.
	APA_DISTANCE_TYPE APATrajCalPLastStepCarCanDrvOptimizedMaxDis1; // car angle = 1 deg. 50cm, Dis.
	APA_DISTANCE_TYPE APATrajCalPLastStepCarCanDrvOptimizedMaxDis2; // car angle = 6 deg. 70cm, Dis.
	
	APA_ANGLE_CAL_FLOAT_TYPE APATrajCalPLastStepAllowedSteeringAngDevidedCarAngMin; // car angle = 1deg.
	APA_ANGLE_CAL_FLOAT_TYPE APATrajCalPLastStepAllowedSteeringAngDevidedCarAngMax; // car angle = 15deg.
	APA_ANGLE_CAL_FLOAT_TYPE APATrajCalPLastStepAllowedSteeringAngMax1; // 50% car angle = 1deg.
	APA_ANGLE_CAL_FLOAT_TYPE APATrajCalPLastStepAllowedSteeringAngMax2; // 95% car angle = 15deg.
	
	APA_ANGLE_TYPE APATrajCalPCorStepNotCheckCarHitObj12MaxDeltaCarAng;

	APA_DISTANCE_TYPE APATrajCalPCorStepExtendedLastCircleMinDeltaDisToEndPosX1; // 50cm.
	APA_ANGLE_TYPE APATrajCalPCorStepExtendedLastCircleSteeringAngSearchStep; // 10% steering angle.
	APA_ANGLE_TYPE APATrajCalPCorStepExtendedLastCircleMinSteeringAng; // 30% steering angle.

	APA_ANGLE_TYPE APATrajCalPCorStepInsertLineBetweenTwoCircleMinSteeringAng;
	APA_ANGLE_TYPE APATrajCalPCorStepInsertLineBetweenTwoCircleUseMinDeltaDisMaxSteeringAng;

	APA_DISTANCE_TYPE APATrajCalPCorStepMoveLastStepCircleMinDeltaDisToEndPos1; // 60cm, 	
	APA_DISTANCE_TYPE APATrajCalPCorStepMoveLastStepCircleMinDeltaDisToEndPos2; // 350cm, 	
	APA_DISTANCE_TYPE APATrajCalPCorStepMoveLastStepCircleMinDisBtwTwoKeyPoint; // 45cm, 	
	APA_DISTANCE_TYPE APATrajCalPCorStepMoveLastStepCircleDeltaDisDevidedSeg[4]; 
	APA_DISTANCE_TYPE APATrajCalPCorStepMoveLastStepCircleDeltaDisCarDrvBk1[3][5]; 
	APA_DISTANCE_TYPE APATrajCalPCorStepMoveLastStepCircleDeltaDisCarDrvFw1[3]; 
	APA_DISTANCE_TYPE APATrajCalPCorStepMoveLastStepCircleDeltaDisCarDrvFw2[3]; 
	APA_DISTANCE_TYPE APATrajCalPCarCanParkIntoSlotMaxSubLaneObjX1; // Slot Len: > width of car + 80cm, < 1.2m
	APA_DISTANCE_TYPE APATrajCalPCarCanParkIntoSlotMaxSubLaneObjX2; // Slot Len: > width of car + 120cm. < 1.6m
	APA_DISTANCE_TYPE APATrajCalPCarCanParkIntoSlotMaxSubLaneObjX3; // Slot Len: > width of car + 160cm. < 2m
	APA_DISTANCE_TYPE APATrajCalPCarCanParkIntoSlotMaxSubLaneObjXWithoutObj1; 
	APA_DISTANCE_TYPE APATrajCalPCarCanParkIntoSlotMaxSubLaneObjXWithoutObj2; 
	APA_CAL_FLOAT_TYPE APATrajCalPOptimalCircleCrossToEndPosLineDeltaDis1Ratio1;
	APA_DISTANCE_CAL_FLOAT_TYPE APATrajCalPOptimalCircleCrossToEndPosLineDeltaDis3; // -1m,
	
	APA_ANGLE_TYPE APATrajCalPTwoCirclesToEndPosCorDeltaCarAng1; // 5deg
	APA_ANGLE_TYPE APATrajCalPTwoCirclesToEndPosCorDeltaCarAng2; // 10deg
	APA_ANGLE_TYPE APATrajCalPTwoCirclesToEndPosCorDeltaCarAng3; // 20deg
	APA_ANGLE_TYPE APATrajCalPTwoCirclesToEndPosCorDeltaCarAng4; // 35deg
	APA_DISTANCE_TYPE APATrajCalPTwoCirclesToEndPosCorDeltaY1; // 20cm,
	APA_DISTANCE_TYPE APATrajCalPTwoCirclesToEndPosCorDeltaY2; // 40cm,
	APA_DISTANCE_TYPE APATrajCalPTwoCirclesToEndPosCorDeltaY3; // 60cm,
	APA_DISTANCE_TYPE APATrajCalPTwoCirclesToEndPosCorDeltaY4; // 80cm,

	APA_MS_TIME_TYPE APATrajCalPInStep3UseTwoCircleCorMethod0UseBigCurSteeringAngTimeToEndPos; // 2.5s
	APA_RATIO_TYPE APATrajCalPInStep3UseTwoCircleCorMethod0UseCurSteeringAngUperRatio1; // 0.25
	APA_RATIO_TYPE APATrajCalPInStep3UseTwoCircleCorMethod0UseCurSteeringAngLowerRatio1; // 0.5
	APA_RATIO_TYPE APATrajCalPInStep3UseTwoCircleCorMethod0UseDeltaSteeringAngRatio1; // 0.25
	APA_RATIO_TYPE APATrajCalPInStep3UseTwoCircleCorMethod0UseCurSteeringAngUperRatio2; // 0.25
	APA_RATIO_TYPE APATrajCalPInStep3UseTwoCircleCorMethod0UseCurSteeringAngLowerRatio2; // 1.0
	APA_RATIO_TYPE APATrajCalPInStep3UseTwoCircleCorMethod0UseDeltaSteeringAngRatio2; // 0.5
	APA_RATIO_TYPE APATrajCalPInStep3UseTwoCircleCorMethod0AddToCurSteeringAngRatio[3];
	
	UCHAR APACalPInStep3OptimalSteeringAngPercentageWithFwTwoCircleCorMethod0; // when the car is out of slot and car angle is big, delta car pos Y is less than 60cm.
	APA_DISTANCE_TYPE APACalPInStep3OptimalSteeringAngPercentageWithTwoCircleCorMayHitObj2MinDeltaY; // 120cm.
	UCHAR APACalPInStep3OptimalSteeringAngPercentageWithTwoCircleCorMayHitObj2;
	UCHAR APACalPInStep3OptimalSteeringAngPercentageWithTwoCircleCorMethod0[4][4][4];
		//                                                                  |  |  |
		//                                                                  |  |  CarPosX to end pos.x dis
		//                                                                  |  CarPosY to end pos line dis
		//                                                                  Delta CarAng and end pos angle
		
	APA_MS_TIME_TYPE APATrajCalPInStep3UseOneCircleCorMethod0UseBigCurSteeringAngTimeToEndPos; // 1.5s
	APA_ANGLE_TYPE APATrajCalPInStep3UseOneCircleCorMethod0UseBigCurSteeringAngMinCarAng; // 5deg.
	APA_DISTANCE_TYPE APATrajCalPInStep3UseOneCircleCorMethod0UseBigCurSteeringAngMinDeltaDisY; // 20cm
	APA_ANGLE_TYPE APACalPInStep3OptimalSteeringAngDevidedCarAngWithOneCircleCorMethod0[APA_CALP_INSTEP3_OPTIMAL_STEERING_ANGLE_DEVIDED_NUM];
	APA_DISTANCE_TYPE APACalPInStep3OptimalSteeringAngDevideCarPosXLineWithOneCircleCorMethod0[APA_CALP_INSTEP3_OPTIMAL_STEERING_ANGLE_CAR_TO_END_POS_DIS_DEVIDED_NUM];
	UCHAR APACalPInStep3OptimalSteeringAngPercentageWithOneCircleCorMethod0[APA_CALP_INSTEP3_OPTIMAL_STEERING_ANGLE_DEVIDED_NUM + 1][APA_CALP_INSTEP3_OPTIMAL_STEERING_ANGLE_CAR_TO_END_POS_DIS_DEVIDED_NUM + 1];
		//                                                                  |  |
		//                                                                  |  CarPosX to end pos.x dis
		//                                                                  |  
		//                                                                  Delta CarAng and end pos angle
	APA_DISTANCE_TYPE APATrajCalPInStep3OutOfSlotCarDriveForwardStraightlyDeltaDis[5];
	APA_ANGLE_TYPE APACalPInStep3EndPosAngleAlmostAchievedCalWithMediumSteeringAngle;

	APA_DISTANCE_TYPE APATrajCalPUseSmallCirclesToEndPosCorMinDeltaX; // 70cm
	APA_RATIO_TYPE APATrajCalPUseSmallCirclesToEndPosCorYOffsetRatio; // 0.2.
	APA_DISTANCE_TYPE APATrajCalPUseSmallCirclesToEndPosCorMinDeltaY; // 5cm.
	APA_DISTANCE_TYPE APATrajCalPUseSmallCirclesToEndPosCorMaxDeltaY; // 20cm.
	APA_RATIO_TYPE APATrajCalPUseSmallCirclesToEndPosCorRatio; // 0.4
	APA_ANGLE_TYPE APATrajCalPUseSmallCirclesToEndPosCorMaxSteeringAng; // 0.85 * Max steering angle.	
	APA_DISTANCE_TYPE APATrajCalPUseSmallCirclesToEndPosCorMinOneStepDis; // 30cm.
	
/*2.4.10.3 *** Park Exit****/
	APA_DISTANCE_TYPE APATrajCalPEDrivingBackwardsDeltaDisBetweenFrontAndRear;	
	APA_DISTANCE_TYPE APATrajCalPEDrivingBackwardsMinRearDis;
	APA_DISTANCE_TYPE APATrajCalPECarPosXOffsetDisAtSetupSystemCoordinate;	
	APA_DISTANCE_TYPE APATrajCalPECarEndPosXWithoutObjectAtParkingOutSide;	
	APA_DISTANCE_TYPE APATrajCalPEMinCarEndPosCoordinateXWithoutObjAtSide;	
	APA_DISTANCE_TYPE APATrajCalPEMaxCarEndPosCoordinateXWithoutObjAtSide;	
	APA_ANGLE_TYPE APATrajCalPELastStepAllowMinSteeringWheelAng;	
	APA_ANGLE_TYPE APATrajCalPELastStepSteeringWheelAngSearchingStep;		
	APA_DISTANCE_CAL_FLOAT_TYPE APATrajCalPEMaxLastStepRCenterTurningRadius;	
	APA_DISTANCE_CAL_FLOAT_TYPE APATrajCalPEMaxLastStepFOuterTurningRadius;
	APA_DISTANCE_TYPE APATrajCalPESafetyDisToFObjAtCornerTurningCar;	
	APA_DISTANCE_TYPE APATrajCalPELastStepSafetyDisToFObjAtCornerTurningCar;	
	APA_DISTANCE_TYPE APATrajCalPESafetyDisToObjAtFrontTurningCar; // when turning the car 
    APA_DISTANCE_TYPE APATrajCalPESafetyDisToObjAtRearTurningCar; 
	APA_DISTANCE_TYPE APATrajCalPECarIsOutOfSlotCriteriaMinCarPosY; // - APACal.LenBetweenRAxisAndFBumper + 800 //  (-APACal.LenBetweenRAxisAndFBumper / 2)
	
/*2.4.10.3 *** Angular Park****/
	APA_DISTANCE_TYPE APATrajCalAPCarEndPositionDisToSideCar;	
	APA_ENUM_TYPE APATrajCalAPCarEndPosition;	
	APA_DISTANCE_TYPE APATrajCalAPSafetyDisToObj2AtTurningCar;
	
	
/*2.4.11 *** Park Process Algorithm****/
/*2.4.11.1 *** parallel and perpendicular***/
	APA_DISTANCE_CAL_FLOAT_TYPE APAParkProcKeepCurSlotDataAtAPAActiveStateMaxCarDrvDis;
	APA_DISTANCE_TYPE APAParkProcSlotFoundAllowPutGearToRCarToStep1KeyPtDis1; // 40cm, 
	APA_DISTANCE_TYPE APAParkProcSlotFoundStopCmdDisplayCarToStep1KeyPtDis1; // 30cm,  < 5km/h
	APA_DISTANCE_TYPE APAParkProcSlotFoundStopCmdDisplayCarToStep1KeyPtDis2; // 40cm, 5 ~ 10km/h
	APA_DISTANCE_TYPE APAParkProcSlotFoundStopCmdDisplayCarToStep1KeyPtDis3; // 60cm, 10 ~ 20km/h
	APA_DISTANCE_TYPE APAParkProcSlotFoundStopCmdDisplayCarToStep1KeyPtDis4; // 80cm, 20 ~ 30km/h
	APA_DISTANCE_TYPE APAParkProcObjRegardedAsInZone1MaxDisAfterStpCmdHasBeenShown;
	APASnsDtdNearestObjDisInfoType APAParkProcStartConsideringCarHitObjSnsDtDis[PA_SYS_NUM];
	APA_SPEED_TYPE APAParkProcMaxWarningSearchingSlotSpeedUp;
	APA_SPEED_TYPE APAParkProcMaxWarningSearchingSlotSpeedDown;
	APA_SPEED_TYPE APAParkProcMaxSearchingSlotSpeed;///20120730
	APA_MS_TIME_TYPE APADisableBySpeedUpWhenSearchingSlotMaxDelayTime;
	APA_SPEED_TYPE APAParkProcMaxParkingSpeed;
	APA_CAL_FLOAT_TYPE APAParkProcVehicleBrakeAccelerator;	
	APA_MS_TIME_TYPE APAParkProcMinTimeOfObjEnteringFullWarningZone;	
	// Luhui 20200805 APA_MS_TIME_TYPE APAParkProcDriverResponseTimeForAPACmd[APA_ODI_MESSAGE_CMD_NUM];
	APA_MS_TIME_TYPE APAParkProcDriverResponseTimeForAPACmdMs;	
	//APA_MS_TIME_TYPE APAParkProcOverSpdMsgDisplayTimeWhenAPASwitchPressed;
	//APA_MS_TIME_TYPE APAParkProcDriverInfoProgressPercentageDisplayTime;	
	//APA_MS_TIME_TYPE APAParkProcDriverInfoFullyProgressPercentageDisplayTime;	
	UCHAR APAParkProcDriverInfoProgressPercentageStep;	
	UCHAR APAParkProcDriverInfoProgressPercentageStepSmall;	
	UCHAR APAParkProcDriverInfoProgressPercentageStartFastArrowBarFill;//20140120	
	UCHAR APAParkProcDriverInfoProgressPercentageMaxValueBeforeStopCmd;
	UCHAR APAParkProcDriverInfoProgressPercentageResetValueAtSameDrvDir;
	APA_DISTANCE_TYPE APAParkProcDriverInfoProgressPercentageRegardTargetPosChangedDevidedDis; // 50cm,
	APA_DISTANCE_TYPE APAParkProcDriverInfoProgressPercentageRegardTargetPosChangedTolDis1; // 10cm, total car drive dis < 50cm.
	APA_DISTANCE_TYPE APAParkProcDriverInfoProgressPercentageRegardTargetPosChangedTolDis2; // 20cm,

	APA_ANGLE_TYPE APAParkProcParallelParkInSlotFrontHasObjRearhasCurbNeedToStopMinCarAng;
	APA_DISTANCE_CAL_FLOAT_TYPE APAParkProcParallelParkInSlotFrontHasObjRearhasCurbNeedToStopMinXOffsetDis;
	APA_DISTANCE_TYPE APAParkProcParallelParkInSlotFrontHasObjRearhasCurbNeedToStopMaxSnsDtdDis;
	APA_DISTANCE_TYPE APAParkProcParallelParkIInSlotFrontHasObjRearhasCurbNeedToStopMaxSlotDepth;
	APA_ANGLE_TYPE APAParkProcPerpendParkFirstDriveBackPhaseHasObjInRearMaxCarAng;
	APA_DISTANCE_CAL_FLOAT_TYPE APAParkProcPerpendParkFirstDriveBackPhaseHasObjInRearMinCarCenterPtY;
	APA_DISTANCE_TYPE APAParkProcPerpendParkFirstDriveBackPhaseHasObjInRearMaxLObjDis;
	APA_DISTANCE_TYPE APAParkProcPerpendParkFirstDriveBackPhaseHasObjInRearMaxMObjDis;
	APA_DISTANCE_TYPE APAParkProcPerpendParkFirstDriveBackPhaseHasObjInRearMaxRObjDis;
	
	APA_ENUM_TYPE APAParkProcCarEndPosition;	
	APA_ENUM_TYPE APAParkProcCarEndPositionWithSlotLenGreatThanAGivenSlot;	
	APA_DISTANCE_TYPE APAParkProcCarEndPositionToObj1Dis;	
	APA_DISTANCE_TYPE APAParkProcCarEndPositionToObj2Dis;	
	APA_SPEED_TYPE APAParkProcCarEndPositionCarAngTolDevidedSpeed1;
	APA_SPEED_TYPE APAParkProcCarEndPositionCarAngTolDevidedSpeed2;
	APA_DISTANCE_TYPE APAParkProcCarEndPositionCarAngTolRegardedAsBigSlotLen;
	APA_ANGLE_TYPE APAParkProcCarEndPositionAchievedCarAngTolOffsetValue[APA_CAR_PARK_SIDE_NUM]; // 0.5 deg ?? or 0 deg.	
	APA_ANGLE_TYPE APAParkProcCarEndPositionCarAngTol1;	
	APA_ANGLE_TYPE APAParkProcCarEndPositionCarAngTol2;	
	APA_ANGLE_TYPE APAParkProcCarEndPositionCarAngTol3;	
	APA_ANGLE_TYPE APAParkProcCarEndPositionCarAngTol4;	
	APA_ANGLE_TYPE APAParkProcCarEndPositionCarAngTol5;	// used to calculate the target pos for progress bar.
	//APA_DISTANCE_TYPE APAParkProcSteerCtrlStartTurnDefDisInSlot;
	
	// Parallel parking in:
	APA_ANGLE_CAL_FLOAT_TYPE APAParkProcSteerCtrlSteeringTurningSpeedStep1[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM]; // rad/ms
	APA_ANGLE_CAL_FLOAT_TYPE APAParkProcSteerCtrlSteeringTurningSpeedStep2[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM]; // rad/ms
	APA_ANGLE_CAL_FLOAT_TYPE APAParkProcSteerCtrlSteeringTurningSpeedLineStep[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM]; // rad/ms
	APA_ANGLE_CAL_FLOAT_TYPE APAParkProcSteerCtrlSteeringTurningSpeedInsideSlot[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM]; // rad/ms
	APA_RATIO_TYPE APAParkProcSteerCtrlSteeringTurningSpeedFactorStep1[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM]; 
	APA_RATIO_TYPE APAParkProcSteerCtrlSteeringTurningSpeedFactorStep2[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM]; 
	APA_RATIO_TYPE APAParkProcSteerCtrlSteeringTurningSpeedFactorInsideSlot[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM];
	APA_CAL_FLOAT_TYPE APAParkProcSteerCtrlSteeringAngleTurningDelayTime[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM]; // ms
	APA_RATIO_TYPE APAParkProcSteerCtrlSteeringTurningOffsetFactorByDeltaSteerAngStep1[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM];// current angle is less than the target angle.		
	APA_RATIO_TYPE APAParkProcSteerCtrlSteeringTurningOffsetFactorByDeltaSteerAngStep2[APA_CAR_PARK_SIDE_NUM][APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM];// Target angle is large than the current angle.
	APA_RATIO_TYPE APAParkProcSteerCtrlSteeringTurningOffsetFactorByDeltaSteerAngLineStep[APA_CAR_PARK_SIDE_NUM][APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM];// current angle is less than the target angle.		
	APA_RATIO_TYPE APAParkProcSteerCtrlSteeringTurningOffsetFactorByDeltaSteerAng1[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM];// inside slot current angle is large than the target angle.		
	APA_RATIO_TYPE APAParkProcSteerCtrlSteeringTurningOffsetFactorByDeltaSteerAng2[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM];// inside slot Target angle is large than the current angle.

	// Perpendicular parking in:
	APA_ANGLE_CAL_FLOAT_TYPE APAParkProcPSteerCtrlSteeringTurningSpeedOutOfSlot[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM]; // deg/ms
	APA_ANGLE_CAL_FLOAT_TYPE APAParkProcPSteerCtrlSteeringTurningSpeedInsideSlot[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM]; // deg/ms
	APA_RATIO_TYPE APAParkProcPSteerCtrlSteeringTurningSpeedFactorOutOfSlot[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM]; // deg/ms
	APA_RATIO_TYPE APAParkProcPSteerCtrlSteeringTurningSpeedFactorInsideSlot[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM]; // deg/ms
	APA_RATIO_TYPE APAParkProcPSteerCtrlSteeringTurningOffsetFactorByDeltaSteerAng1[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM];// current angle is large than the target angle.		
	APA_RATIO_TYPE APAParkProcPSteerCtrlSteeringTurningOffsetFactorByDeltaSteerAng2[APA_PARKPROC_EPS_CTRL_VEHICLE_SPEED_DEVIDED_SEG_NUM];// Target angle is large than the current angle.
	APA_ANGLE_CAL_FLOAT_TYPE APAParkProcPSteerCtrlSteeringTurningToTargetAngMaxSpeed;
	APA_ANGLE_CAL_FLOAT_TYPE APAParkProcPSteerCtrlSteeringTurningToZeroMaxSpeed;
	APA_ANGLE_CAL_FLOAT_TYPE APAParkProcPSteerCtrlSteeringTurningToZeroDriveDisRatio;
	APA_SPEED_CAL_FLOAT_TYPE APAParkProcEPSSteeringWheelCtrlCalMinVehSpeed; // 2kph / 3.6 =>m/s
	APA_SPEED_CAL_FLOAT_TYPE APAParkProcEPSSteeringWheelCtrlCalMinVehSpeedInSlot; // 0.5kph / 3.6 =>m/s
	APA_SPEED_CAL_FLOAT_TYPE APAParkProcEPSSteeringWheelCtrlCalMaxVehSpeed; // 8kph / 3.6 -> m/s

	APA_DISTANCE_TYPE APAParkProcSteerCtrlStartTurnMinDisInSlot;
	APA_DISTANCE_TYPE APAParkProcSteerCtrlStartTurnMaxDisInSlot;	
	APA_DISTANCE_TYPE APAParkProcPSteerCtrlStartTurnMinDisInSlot;
	APA_DISTANCE_TYPE APAParkProcPSteerCtrlStartTurnMaxDisInSlot;	
	APA_DISTANCE_TYPE APAParkProcSteerCtrlStartTurnMinDisOutOfSlot;	
	APA_DISTANCE_TYPE APAParkProcSteerCtrlStartTurnMaxDisOutOfSlot;	
	

	
	APA_DISTANCE_TYPE APAParkProcSteerCtrlAllowTurnToCurSteerMinDis;	
	APA_CAL_FLOAT_TYPE APAParkProcSteerCtrlAllowTurnToCurSteerCalFactor1; // Vehicle Speed < 5km/h	
	APA_CAL_FLOAT_TYPE APAParkProcSteerCtrlAllowTurnToCurSteerCalFactor2; // Vehicle Speed > 5km/h	
	
	APA_ANGLE_TYPE APAParkProcCarDriveStraightlyMinSteeringWheelAng;	
	APA_DISTANCE_TYPE APAParkProcCarParkingCarEndPositionXDisTol;	
	APA_DISTANCE_TYPE APAParkProcCarParkingCarEndPositionDisTol2;
	APA_DISTANCE_TYPE APAParkProcCarParkingCarEndPositionYDisTolDevidedSlotLen1; // car len + 1200	
	APA_DISTANCE_TYPE APAParkProcCarParkingCarEndPositionYDisTolDevidedSlotLen2; // car len + 2000
	APA_DISTANCE_TYPE APAParkProcCarParkingCarEndPositionYDisTol0; // 7cm	
	APA_DISTANCE_TYPE APAParkProcCarParkingCarEndPositionYDisTol1; // 15cm	
	APA_DISTANCE_TYPE APAParkProcCarParkingCarEndPositionYDisTol2; // 30cm	
	APA_DISTANCE_TYPE APAParkProcCarParkingCarEndPositionCarDrvDisByGearChangedDvdSlotLen1; // car len + 80cm. 
	APA_DISTANCE_TYPE APAParkProcCarParkingCarEndPositionCarDrvDisByGearChangedDvdSlotLen2; // car len + 200cm. 
	APA_DISTANCE_TYPE APAParkProcCarParkingCarEndPositionCarDrvMinDisByGearChanged1; // 10cm. 
	APA_DISTANCE_TYPE APAParkProcCarParkingCarEndPositionCarDrvMinDisByGearChanged2; // 30cm. 
	
	APA_DISTANCE_TYPE APAParkProcCarParkingCarEndPositionAchivedMinDisToObj12;
	//APA_MS_TIME_TYPE APAParkProcCarParkingCarEndPositionAchivedDelayTime;
	APA_ENUM_TYPE APAParkProcCarParkingCarEndPositionAchivedAllowDrvFwBkNum;
	APA_RATIO_TYPE APAParkProcAllowUseLargeSafetyDisBySpeedCompensatedFactor; // 20: 3kph: compensate: 14cm. 2kph: 6cm, 1kph: 1.5cm.
	APA_DISTANCE_TYPE APAParkProcAllowUseLargeSafetyDisBySpeedCompensatedMaxDis; // 15cm.
	APA_DISTANCE_TYPE APAParkProcAllowUseLargeSafetyDisMaxDeltaCarPosXToEndPosXDis;	
	APA_DISTANCE_TYPE APAParkProcAllowUseLargeSafetyDisMinFRDis;	
	APA_DISTANCE_TYPE APAParkProcAllowUseLargeSafetyDisMaxFRDis;
	APA_DISTANCE_TYPE APAParkProcLenBetweenRearRectCornerToRearBumperCornerCurve; // 450cm.
	APA_DISTANCE_TYPE APAParkProcLargeSafetyDisToRear;	
	APA_DISTANCE_TYPE APAParkProcLargeSafetyDisToFront;	
	APA_RATIO_TYPE APAParkProcCarParkingAllowedDeviateDisRatioFromCalTrajectory; // 1%
	APA_DISTANCE_TYPE APAParkProcCarParkingAllowedDeviateDisFromCalTrajectory;	
	APA_ANGLE_TYPE APAParkProcCarParkingAllowedDeviateCarAngFromCalTrajectory;	
	APA_ANGLE_TYPE APAParkProcCarParkingAllowedRecalTrajectoryMaxSteeringAngle;	
	APA_DISTANCE_TYPE APAParkProcCompensatedCarAngMinDriveDis;	// 10cm, 
	APA_ANGLE_TYPE APAParkProcCompensatedCarAngEachStepInSlot1[APA_CAR_PARK_SIDE_NUM]; // 1.5deg / 5 step.	
	APA_DISTANCE_CAL_FLOAT_TYPE APAParkProcCompensatedCarPosXEachStepInSlot1[APA_CAR_PARK_SIDE_NUM];	// -10cm / 5 step.
	APA_ANGLE_TYPE APAParkProcCompensatedCarAngEachStepInSlot2[APA_CAR_PARK_SIDE_NUM]; // 1.5deg / 5 step.	
	APA_DISTANCE_CAL_FLOAT_TYPE APAParkProcCompensatedCarPosXEachStepInSlot2[APA_CAR_PARK_SIDE_NUM];	// -10cm / 5 step.
	APA_ENUM_TYPE APAParkProcCarMaxBackAndForwardCorrectCntInStep3456;	
	APA_ENUM_TYPE APAParkProcCarRearRightCornerMayHitObj2MaxCorCnt;	
	APA_DISTANCE_TYPE APAParkProcCarRegardOneDrvFwAndBkStepMinDeltaDis;
	APA_DISTANCE_TYPE APAParkProcCarRearRightCornerMayHitObj2MinCarDrvFwDis;
	APA_DISTANCE_TYPE APAParkProcTightSlotMinTotalFrontAndRearSnsDtdDis;	
	//APA_MS_TIME_TYPE APAParkProcCarMayHitObjectStopWaitingTime; // If the value is set to APA_PARKPROC_MAX_MS_TIME_VALUE, the function will be disabled. Ie. the APA will wait for ever. 
	//APA_MS_TIME_TYPE APAParkProcObjDtdAtRearAndMovingAwayDrvBkDelayTime; // 2s. 
	APA_SPEED_TYPE APAParkProcMaxVehicleStaticSpeedDown; // 0.2 km/h;
	APA_SPEED_TYPE APAParkProcMaxVehicleStaticSpeedUp; // 1 km/h;
	APA_SPEED_TYPE APAParkProcMaxRegardAsStaticAndRecalTrajVehicleSpeed; // 1.5km/h.
	APA_SPEED_TYPE APAParkProcMaxDisplaySlotFoundVehicleSpeed; // 10km/h.
	APA_SPEED_TYPE APAParkProcMaxRegardAsStaticAndReqCtrlEPSVehicleSpeed; // 0.0km/h.
	//APA_MS_TIME_TYPE APAParkProcMaxCalTactFeedBkDuratn; 
	//APA_MS_TIME_TYPE APAParkProcMaxCalTactFeedBkOvralTime;
	//APA_MS_TIME_TYPE APASteeringWheelCtrlLimitControlStepRemainTime;
	APA_MS_TIME_TYPE APASteeringWheelCtrlSteeringAngCtrlStepHoldTime;
	APA_MS_TIME_TYPE APASteeringWheelCtrlSteeringIsStaticTime;
	APA_ANGLE_TYPE APAParkProcControlledSteeringWheelAngleLimitDeltaAnlePer40ms; // unit: Rad. limit: 500deg/s = 20deg/40ms.
	APA_ANGLE_TYPE APAParkProcControlledSteeringWheelAngleLimitStep; // unit: Rad. limit: 500deg/s = 10deg/20ms. EPS ratio: 14.5348, = 10deg / 14.5348 deg. 
	APA_ANGLE_TYPE APAParkProcControlledSteeringWheelAngleStartStepSteeringIsStatic; // unit: Rad. 
	APA_ANGLE_TYPE APAParkProcControlledSteeringWheelAngleStartStepSteeringIsTurning; // unit: Rad. 
	//APA_ANGLE_TYPE APAParkProcControlledSteeringWheelAngleStepAddedStep; // unit: Rad. 
	APA_ANGLE_TYPE APAParkProcControlledSteeringWheelAngleStepForEndPosAchievedCor; // 
	APA_ANGLE_TYPE APAParkProcControlledSteeringWheelAngleStepForCarHitObj2Cor; // 
	APA_ANGLE_TYPE APAParkProcControlledSteeringWheelAngleMaxStep; // unit: Rad. Speed < 5km/h
	APA_ANGLE_TYPE APAParkProcControlledSteeringWheelAngleMaxStepOverSpeed1; // unit: Rad. Speed > 5km/h
	APA_ANGLE_TYPE APAParkProcControlledSteeringWheelAngleMaxStepOverSpeed2; // unit: Rad. Speed > 8km/h
	APA_ANGLE_TYPE APAParkProcControlledSteeringWheelAngleStep1; // unit: Rad. delta steering angle < 2.5deg.
	APA_ANGLE_TYPE APAParkProcControlledSteeringWheelAngleCtrlStepLowSpd; // unit: Rad. steering angle = 5deg.
	APA_SPEED_TYPE APAParkProcControlledSteeringWheelAngleSpeedLimit0; // 0.8km/h
	APA_SPEED_TYPE APAParkProcControlledSteeringWheelAngleSpeedLimit01; // 1.5km/h
	APA_SPEED_TYPE APAParkProcControlledSteeringWheelAngleSpeedLimit1; // 5km/h
	APA_SPEED_TYPE APAParkProcControlledSteeringWheelAngleSpeedLimit2; // 8km/h

	//Added to discard the previous detected slot and start a new slot searching process start 20140303
	//APA_MS_TIME_TYPE APAParkProcAutoSteeringIndicationShowDelayTime;
	//APA_MS_TIME_TYPE APAParkProcKeepSlotForEnablingSysAgainByAPASwtichMaxTime;
	//Added to discard the previous detected slot and start a new slot searching process end 20140303
		
	APA_MS_TIME_TYPE APAParkProcMaxAPATrajectoryCalTime; // If the apa trajectory cal time is great than this value. the APA will exit with failure.
	//APA_MS_TIME_TYPE APAParkProcRecalTrajDelayTimeSearchSlotWithCarStaticDrvFw;
	APA_MS_TIME_TYPE APAParkProcRecalTrajMaxCntSearchSlotWithCarStaticDrvFw;

	APA_ANGLE_TYPE APAParkProcTrajCheckAllowedSteeringWheelAngleTol; // (unit: radian) the tollerance
	APA_DISTANCE_CAL_FLOAT_TYPE APAParkProcTrajCheckAllowedTurningRadiusTol;
	
	//APA_MS_TIME_TYPE APAParkProcCarEndPositionAchievedEPSHoldTime; // 1.2s,
	//APA_MS_TIME_TYPE APAParkProcIPCCarEndPositionAchievedDisplayTime;
	APA_ANGLE_TYPE APAParkProcSteeringWheelAngleAchievedTol; // (unit: radian) the tollerance between desired steering wheel angle and EPS steering angle.
	APA_ANGLE_TYPE APAParkProcSteeringWheelAngleTurningTimeOutTol; // (unit: radian) the tollerance between desired steering wheel angle and EPS steering angle.
	APA_DISTANCE_TYPE APAParkProcMaxStartTurnSteeringWheelDeltaDisToKeyPointLastStep; // If the distance between the car to the key point is less than this value, the APA will start turning the steering wheel.
	//APA_MS_TIME_TYPE APAParkProcEPSControllConnectDelayTimeIntoReverse;
	APA_ENUM_TYPE APAParkProcMaxRequestControlEPSTryTimes;//added 2014 05 06
	//APA_MS_TIME_TYPE APAParkProcMaxAPAParkingTime;
	APA_DISTANCE_TYPE APAParkProcMinPassDisToDeletTheFirstSlotAfterSecondSlotFound; // 2010 12 20.
	//APA_MS_TIME_TYPE APAParkProcMaxSteeringWheelTurningTime;
	APA_MS_TIME_TYPE wParkProcSteeringWheelAngleHoldTime;	
	//APA_MS_TIME_TYPE wParkProcCorrectSteeringWheelAngleHoldTime;	
	APA_MS_TIME_TYPE wParkProcRecalTrajSteeringAngleAchievedDelayTime;	
	APA_DISTANCE_TYPE APAParkProcAllowCarCanDrvDisWithoutObjDtd; // 80cm.		
	APA_DISTANCE_TYPE APAParkProcAllowCarDriveTowardsTheObjMinDis;		
	APA_DISTANCE_TYPE APAParkProcAllowCarDriveTowardsTheObjMinDisAfterStopCmdDisplayed;		
	APA_DISTANCE_TYPE APAParkProcAllowCarDriveOutOfTheSlotDisWithoutObjAtFOrR;	
	APA_DISTANCE_TYPE APAParkProcAllowCarOffsetDisToEndPosXInTheSlotDuringSteeringCorrect;	
	APA_ANGLE_TYPE APAParkProcMinSteeringAngleCanBeCorrectedInTheSlot;	
	APA_ANGLE_TYPE APAParkProcSteeringAngleCanBeCorrectedStepAngleInTheSlot;
	APA_ANGLE_TYPE APAParkProcMinCarAngAllowSteeringCorrectToZeroInTheSlot;
	APA_DISTANCE_TYPE APAParkProcCarParkingAllowedDeviateDisFromOriginalTrajectory;
	APA_ANGLE_TYPE APAParkProcCarParkingAllowedDeviateCarAngFromOriginalTrajectory;	
	//APA_MS_TIME_TYPE APAParkProcNextStepDirChangedReturnSteeringToZeroVehMaxStaticTime;
	APA_DISTANCE_TYPE APAParkProcMinPassDeltaDisToDeletFirstSlotAfterSecondSlotFound; // This delta dis is based on the car min pass dis after slot found.
	APA_DISTANCE_TYPE APAParkProcCarPosYPassSlotDeltaDisToRecalTrajWithFirstStepFwVeryLowSpd;
	APA_DISTANCE_TYPE APAParkProcCarPassSlotDeltaDisToRecalTrajWithFirstStepFwVeryLowSpd;
	APA_DISTANCE_TYPE APAParkProcCarPassSlotDeltaDisToRecalTrajWithFirstStepBk;
	APA_DISTANCE_TYPE APAParkProcCarPassSlotDeltaDisToRecalTrajWithSlotNotConfirmed;
	APA_DISTANCE_TYPE APAParkProcCarPassSlotDeltaDisToRecalTrajWithSecondSlotFound; // 50cm.
	
	APA_DISTANCE_TYPE APAParkProcInSlotCarPosYCriteria1;
	APA_SPEED_TYPE APAParkProcInSlotCarPosXOffsetDisDevideSpeed; // 2.5kph
	APA_DISTANCE_TYPE APAParkProcInSlotCarPosXMaxOffsetDisHighSpeedBk; // 1cm.
	APA_DISTANCE_TYPE APAParkProcInSlotCarPosXMaxOffsetDisHighSpeedFw; // 7cm.
	APA_DISTANCE_TYPE APAParkProcInSlotCarPosXMinOffsetDis;
	APA_CAL_FLOAT_TYPE APAParkProcInSlotCarPosXOffsetFactorWithCurb;
	APA_DISTANCE_TYPE APAParkProcInSlotCarPosXMaxOffsetDisWithCurb;
	APA_CAL_FLOAT_TYPE APAParkProcInSlotCarPosXRightOffsetFactorWithoutCurb;
	APA_CAL_FLOAT_TYPE APAParkProcInSlotCarPosXLeftOffsetFactorWithoutCurb;
	APA_DISTANCE_TYPE APAParkProcInSlotCarPosXMaxRightOffsetDisWithoutCurb;
	APA_DISTANCE_TYPE APAParkProcInSlotCarPosXMaxLeftOffsetDisWithoutCurb;
	APA_ANGLE_TYPE APAParkProcInSlotCarPosXMaxOffsetDisDevidedAng; // 5deg.
	APA_DISTANCE_TYPE APAParkProcInSlotCarPosXMaxOffsetDisTol; // 3cm
	APA_CAL_FLOAT_TYPE APAParkProcInSlotCarPosYDriveDisFactor;
	APA_DISTANCE_TYPE APAParkProcInSlotCarPosYDriveDisCompValue;
	APA_DISTANCE_TYPE APAParkProcInSlotCarCanDrvFwDisWithoutObjAtRear;
	APA_CAL_FLOAT_TYPE APAParkProcInSlotCarCanDrvFwDisFactorWithObjAtRear;
	APA_DISTANCE_TYPE APAParkProcInSlotCarCanDrvBkDisWithoutObjAtFront;
	APA_CAL_FLOAT_TYPE APAParkProcInSlotCarCanDrvBkDisFactorWithObjAtFront;
	APA_CAL_FLOAT_TYPE APAParkProcInSlotCarShouldDrvMinDisFactorWithOneGearShift;
	APA_DISTANCE_TYPE APAParkProcInSlotCarShouldDrvMinDisWithOneGearShift;
	APA_DISTANCE_TYPE APAParkProcInSlotCarShouldDrvMinDisWithBigSlotLen;
	APA_DISTANCE_TYPE APAParkProcInSlotCarShouldDrvFwDisWithoutObjAtRear;
	APA_DISTANCE_TYPE APAParkProcInSlotCarShouldDrvBkDisWithoutObjAtFront;
	APA_DISTANCE_TYPE APAParkProcInSlotCarResumeToTheSameDriveDirectionMinCarCanDrvDeltaDis;
	APA_DISTANCE_TYPE APAParkProcInSlotAllowCarEndPosAchievedMinCarDrvDisWithOneGearShift;
	
	APA_DISTANCE_CAL_FLOAT_TYPE APAParkProcInSlotCarResetProgressPercentageCarOverDrvDis; // 35cm.
	APA_DISTANCE_TYPE APAParkProcInSlotCarUpdateProgressPercentageTargetPosMaxObjDis;
	
	//APA_MS_TIME_TYPE APAParkProcSnsDtNearestDisUpdateTime; // 2.5s (3.5s - 1s)
	//APA_MS_TIME_TYPE APAParkProcSnsDtNearestIncreasingDisUpdateTime; // (1.4s - 1s) 2014 05 15
	//APA_MS_TIME_TYPE APAParkProcSnsDtNearestDisUpdateTimeWhenCarIsMoving; // 0s, will update the dis immediately.
	//APA_MS_TIME_TYPE APAParkProcSnsDtNearestDisUpdateHoldTime; // 1s 2014 05 15
	APA_DISTANCE_TYPE APAParkProcSnsDtNearestDisUpdateMinThresholdDis[APA_SNS_DTD_NEAREST_OBJ_DIS_REGION_NUM];
	APA_DISTANCE_TYPE APAParkProcSensorDetectDisUpdateThreshold;// 2014 05 15
	APA_ENUM_TYPE MaxSnsDetectObjPtCntRegardAsObjDisIncreasing;//2014 05 21
	APA_DISTANCE_TYPE APAParkProcSensorDetectRagardAsDisIncreasingTolerance;// 2014 05 15
	APA_DISTANCE_TYPE APAParkProcSensorDetectDisDecreasingTolerance;// 2014 05 15

	APA_DISTANCE_TYPE APAParkProcInLineStepReCalTrajMaxCarToTargetPosDis; // 20cm. 
	APA_DISTANCE_TYPE APAParkProcInStep3ReCalTrajMinDeltaDisWithTargetPosCanNotAchieved; 
	APA_DISTANCE_TYPE APAParkProcInStep3ReCalTrajMinObjDisAtRear; 
	APA_ANGLE_TYPE APAParkProcInStep3ReCalTrajMinDeviateCarAngFromCalTrajectory; // 1.5deg.
	APA_DISTANCE_TYPE APAParkProcInStep3ReCalTrajMinDeviateDisFromCalTrajectory;  // 10cm.
	APA_ANGLE_TYPE APAParkProcInStep3ReCalTrajMinDeviateCarAngFromCalTrajectory2; // 1.0deg.
	
	APA_DISTANCE_TYPE APAParkProcCarMayHitFrontCornerObjStartCorFRSDis;
	APA_DISTANCE_TYPE APAParkProcCarMayHitFrontCornerObjStartCorFRDis;
	APA_DISTANCE_TYPE APAParkProcCarMayHitFrontCornerObjStopCorFRSDis;
	APA_DISTANCE_TYPE APAParkProcCarMayHitFrontCornerObjStopCorFRDis;
	
	APA_DISTANCE_TYPE APAParkProcCarMayHitFrontCornerObjStartCorRRSDis;
	APA_DISTANCE_TYPE APAParkProcCarMayHitFrontCornerObjStartCorRRDis;
	APA_DISTANCE_TYPE APAParkProcCarMayHitFrontCornerObjStopCorRRSDis;
	APA_DISTANCE_TYPE APAParkProcCarMayHitFrontCornerObjStopCorRRDis;

	APA_ANGLE_TYPE APAParkProcEndPosAngAchievedAllowCorSteeringAngMaxCarAng; // 4deg
	APA_DISTANCE_TYPE APAParkProcEndPosAngAchievedAllowCorSteeringCarToEndPosMinDis; // 50cm.
	APA_DISTANCE_TYPE APAParkProcEndPosAngAchievedAllowCorSteeringCarDrvDis1; // 30cm
	APA_DISTANCE_TYPE APAParkProcEndPosAngAchievedAllowCorSteeringCarDrvDis2; // 70cm
	APA_ANGLE_TYPE APAParkProcEndPosAngAchievedAllowCorSteeringMinAng; // 12% steering.: car will move 30.8cm for 1deg car angle.
	APA_ANGLE_TYPE APAParkProcEndPosAngAchievedAllowCorSteeringMaxAng; // 25% steering.: car will move 30.8cm for 1deg car angle.
	APA_ANGLE_TYPE APAParkProcEndPosAngAchievedAllowStartCorSteeringAngMinCarAng; // 25% steering.: car will move 30.8cm for 1deg car angle.
	APA_ANGLE_TYPE APAParkProcEndPosAngAchievedAllowStopCorSteeringAngMaxCarAng; // 25% steering.: car will move 30.8cm for 1deg car angle.
	APA_DISTANCE_TYPE APAParkProcEndPosAngAchievedAllowCorSteeringBkToZeroCarDrvDis; // 15cm.
	APA_DISTANCE_TYPE APAParkProcEndPosAngAchievedAllowCorSteeringMinCarDrvDis; // 30cm.
	APA_ANGLE_TYPE APAParkProcInStep3AllowCorSteeringAngMinCarAng; // 5deg
	APA_DISTANCE_TYPE APAParkProcInStep3AllowCorSteeringAngMinRearBumperToObj1Dis; // 50cm.

	APA_DISTANCE_TYPE APAParkProcPCarParkingAllowedDeviateDisFromCalTrajectory;	// 10cm ??
	APA_ANGLE_TYPE APAParkProcPCarParkingAllowedDeviateCarAngFromCalTrajectory;	// 2deg ??

	APA_ENUM_TYPE APAParkProcPCarParkingCarEndPositionAchivedAllowDrvFwBkNum;
	APA_ANGLE_TYPE APAParkProcPCarEndPositionCarAngTol00;	
	APA_ANGLE_TYPE APAParkProcPCarEndPositionCarAngTol01;	
	APA_ANGLE_TYPE APAParkProcPCarEndPositionCarAngTol;	
	APA_ANGLE_TYPE APAParkProcPCarEndPositionCarAngTol2;	
	APA_ANGLE_TYPE APAParkProcPCarEndPositionCarAngTol2WithOnlyOneObj;	
	APA_ANGLE_TYPE APAParkProcPCarEndPositionCarAngTol3;	
	APA_DISTANCE_TYPE APAParkProcPSafetyDisToObjByFSnsDtdOutOfSlot; // 450. // 45cm.
	APA_DISTANCE_TYPE APAParkProcPSafetyDisToObjBySnsDtdInFirstDrvBkStep;
	APA_DISTANCE_TYPE APAParkProcPSafetyDisToCornerObjBySnsDtd;	
	APA_DISTANCE_TYPE APAParkProcPSafetyDisToMidObjBySnsDtd;
	APA_DISTANCE_TYPE APAParkProcPSafetyDisToSideObjInBigSlotBySnsDtd;
	APA_DISTANCE_TYPE APAParkProcPAfterStopCmdShownMinDisToObjToChangeDrvDir;

	APA_DISTANCE_TYPE APAParkProcPStartCheckCarWillHitSideObjCarPosDeltaY;
	APA_ANGLE_TYPE APAParkProcPStartCheckCarWillHitSideObjDeltaCarAng;
	
	APA_DISTANCE_TYPE APAParkProcPCarShouldDriveFwInSoltMinRRSSnsDis1;
	APA_DISTANCE_TYPE APAParkProcPCarShouldDriveFwInSoltMinRRSnsDis1;
	APA_DISTANCE_TYPE APAParkProcPCarShouldDriveFwInSoltMinRLSSnsDis1;
	APA_DISTANCE_TYPE APAParkProcPCarShouldDriveFwInSoltMinRLSnsDis1;
	
	APA_DISTANCE_TYPE APAParkProcPCarShouldDriveFwInSoltMinRRSSnsDis2;
	APA_DISTANCE_TYPE APAParkProcPCarShouldDriveFwInSoltMinRRSnsDis2;
	APA_DISTANCE_TYPE APAParkProcPCarShouldDriveFwInSoltMinRLSSnsDis2;
	APA_DISTANCE_TYPE APAParkProcPCarShouldDriveFwInSoltMinRLSnsDis2;
	
	APASnsDtdNearestObjDisInfoType APAParkProcPCarCanDrvFwMinDisToObjBySnsDtd[APA_PARKPROC_CAR_CAN_DRV_MIN_DIS_TO_OBJ_BY_SNS_DTD_SCENARIO_NUM][APA_PARKPROC_CAR_DRV_CIRCLE_SIDE_NUM]; // car drive forward, will only check front obj.
	APASnsDtdNearestObjDisInfoType APAParkProcPCarCanDrvBkMinDisToObjBySnsDtd[APA_PARKPROC_CAR_CAN_DRV_MIN_DIS_TO_OBJ_BY_SNS_DTD_SCENARIO_NUM][APA_PARKPROC_CAR_DRV_CIRCLE_SIDE_NUM][PA_SYS_NUM]; // car drive bk, will check both rear and front obj.
	APASnsDtdNearestObjDisInfoType APAParkProcPAllowToChangeDriveDirectionMinDisToObjBySnsDtd;//[PA_SYS_NUM];
	APA_DISTANCE_TYPE APAParkProcPRegardedAsCarCloseToObjMinDeltaY;	
	//APA_MS_TIME_TYPE APAParkProcPAllowToChangeDriveDirectionMinDelayTime;
	APA_ENUM_TYPE APAParkProcPCarEndPosition;	
	APA_ENUM_TYPE APAParkProcPCarEndPositionWithSlotLenGreatThanAGivenSlot;	
	APA_DISTANCE_TYPE APAParkProcPMinPassDeltaDisToDeletFirstSlotAfterSecondSlotFound; // This delta dis is based on the car min pass dis after slot found.
	APA_DISTANCE_TYPE APAParkProcPMinPassDeltaDisToDeletFirstSlotAfterSecondSlotFoundWithoutObj2; // This delta dis is based on the car min pass dis after slot found.
	APA_DISTANCE_TYPE APAParkProcPCarPosYPassSlotDeltaDisToRecalTrajWithFirstStepFwVeryLowSpd;
	APA_DISTANCE_TYPE APAParkProcPCarPassSlotDeltaDisToRecalTrajWithFirstStepFwVeryLowSpd;
	APA_DISTANCE_TYPE APAParkProcPCarPassSlotDeltaDisToRecalTrajWithFirstStepBk;
	APA_DISTANCE_TYPE APAParkProcPCarPassSlotDeltaDisToRecalTrajWithSlotNotConfirmed;
	APA_DISTANCE_TYPE APAParkProcPCarPassSlotDeltaDisToRecalTrajWithSecondSlotFound; // 50cm.
	//APA_CAL_FLOAT_TYPE APAParkProcPPresShowStopCmdRatioOfSpdAndDis; //  APA_PARKPROC_PRESHOW_STOP_CMD_RATIO_OF_SPD_AND_DIS
	APA_ENUM_TYPE APAParkProcPCarMaxBackAndForwardCorrectCntInStep3456;	
	APA_DISTANCE_TYPE APAParkProcPCarRegardOneDrvFwAndBkStepMinDeltaDis;
	APA_DISTANCE_TYPE APAParkProcPHasInformToChangeDriveDirCmdChechMinDeltaDis;
	APA_DISTANCE_TYPE APAParkProcPAllowOutOfSlotCarDrvFwCorMaxY; // 300cm
	APA_DISTANCE_TYPE APAParkProcPAllowOutOfSlotCarDrvFwCorMinDis1; // 30cm
	APA_DISTANCE_TYPE APAParkProcPAllowOutOfSlotCarDrvFwCorMinDis2; // 70cm
	APA_DISTANCE_TYPE APAParkProcPAllowOutOfSlotCarDrvFwCorMinDis3; // 120cm
	APA_DISTANCE_TYPE APAParkProcPAllowInSlotCarDrvFwCorMinDis1; // 120cm
	APA_DISTANCE_TYPE APAParkProcPAllowInSlotCarDrvFwCorMinDis2; // 160cm
	APA_DISTANCE_TYPE APAParkProcPAllowInSlotCarDrvFwCorMinDis3; // 200cm
	APA_DISTANCE_TYPE APAParkProcPAllowInSlotCarDrvFwCorMinDis4; // 300cm
	APA_DISTANCE_TYPE APAParkProcPAllowInSlotCarDrvFwCorMinDis5; // 360cm
	APA_DISTANCE_TYPE APAParkProcPCheckRecalTrajMinX;
	APA_DISTANCE_TYPE APAParkProcPCheckRecalTrajMinDeltaEndPosToCurCarPosX;
	APA_DISTANCE_TYPE APAParkProcPCheckIfCarIsNotOnTrajRecalTrajMinX;
	APA_DISTANCE_TYPE APAParkProcPInSlotRecalTrajMinDeltaXDis;
	//APA_MS_TIME_TYPE APAParkProcPInSlotRecalTrajMinDeltaTime;
	//APA_MS_TIME_TYPE wParkProcPSteeringWheelAngleHoldTime; // 100ms.
	//APA_MS_TIME_TYPE wParkProcPCorrectSteeringWheelAngleHoldTime; // 200ms.
	//APA_MS_TIME_TYPE wParkProcPRecalTrajSteeringAngleAchievedDelyTimeInStep3;
	//APA_MS_TIME_TYPE wParkProcPRecalTrajSteeringAngleAchievedDelayTime;
	APA_DISTANCE_TYPE APAParkProcPOutSlotCarCanDriveMinPosX;
	APA_DISTANCE_TYPE APAParkProcPOutSlotCarCanDriveMinPosXWhenCarAngAchieved;
	APA_DISTANCE_TYPE APAParkProcPRegardedAsInSlotCarMaxPosY;

	APA_ANGLE_TYPE APAParkProcPCarMayHitFrontCornerObjCorDevidedCarAng; // 25deg.
	APA_DISTANCE_TYPE APAParkProcPCarMayHitFrontCornerObjStartCorRRSDis1; 
	APA_DISTANCE_TYPE APAParkProcPCarMayHitFrontCornerObjStartCorRRSDis2;
	APA_DISTANCE_TYPE APAParkProcPCarMayHitFrontCornerObjStartCorRRDis1;
	APA_DISTANCE_TYPE APAParkProcPCarMayHitFrontCornerObjStartCorRRDis2;
	APA_DISTANCE_TYPE APAParkProcPCarMayHitFrontCornerObjStopCorRRSDis;
	APA_DISTANCE_TYPE APAParkProcPCarMayHitFrontCornerObjStopCorRRDis;

	APA_ANGLE_TYPE APAParkProcPInSlotStartUseCorSteeringAngleDeltaCarAngle;
	APA_DISTANCE_TYPE APAParkProcPInSlotStartUseCorSteeringAngleDeltaXToEndPosDis;
	APA_DISTANCE_TYPE APAParkProcPStartUseCorSteeringAngleDeltaDisToKeyPoint;
	APA_DISTANCE_TYPE APAParkProcPInSlotStartUseCorSteeringAngleDeltaXDis;
	APA_DISTANCE_TYPE APAParkProcPInSlotStopUseCorSteeringAngleDeltaXDis;
	APA_DISTANCE_TYPE APAParkProcPInSlotAllowedToUseCorSteeringAngleMinDeltaXDis;
	APA_ANGLE_TYPE APAParkProcPInSlotStartUseCorSteeringAngleMinDeltaCarAng;
	APA_ANGLE_TYPE APAParkProcPInSlotStopUseCorSteeringAngleMaxDeltaCarAng;
	
	APA_ANGLE_TYPE APAParkProcPCarEnterSlotAllowRecalTrajMaxSteeringAng;	
	//APA_MS_TIME_TYPE APAParkProcPCarEnterSlotAllowRecalTrajMinSteeringWheelAngHoldTime;	
	APA_DISTANCE_TYPE APAParkProcPCarEnterSlotAllowRecalTrajMinCarDrvDis; // 15cm.
	
	APA_DISTANCE_TYPE APAParkProcPInSlotUseRemainTheDrvFwMessageMinX; // 0cm
	APA_DISTANCE_TYPE APAParkProcPInSlotUseRemainTheDrvBkMessageMinX; // -500cm, always enable.

	APA_DISTANCE_TYPE APAParkProcPAllowFirstStepCarDrvMaxDeltaXWithoutObj1; // car end pos.x / 2

	APA_ANGLE_TYPE APAParkProcTargetCarPosRegardAsEndPosCanBeAchievedByDrvBkMaxCarAng; // 15deg.
	APA_DISTANCE_TYPE APAParkProcPCarDrvBkProgressCompensateSafetyDisAtRCorner; // 0cm. 
	APA_DISTANCE_TYPE APAParkProcPCarDrvBkProgressCompensateSafetyDisAtRCornerReduced; // 0cm. 
	APA_DISTANCE_TYPE APAParkProcPCarDrvBkProgressCompensateNormalSlotXDis; // - 30cm. // for big slot.
	APA_DISTANCE_TYPE APAParkProcPCarDrvBkProgressCompensateNormalSlotYDis; // 20cm. // for big slot.
	APA_DISTANCE_TYPE APAParkProcPInSlotCarResetProgressPercentageCarOverDrvDis; // 45cm.
	APA_DISTANCE_TYPE APAParkProcPProgressHitObj2InFwCorStepCarDrvMinDis; // 120cm.
	APA_DISTANCE_TYPE APAParkProcPProgressHitObj2InFwCorStepCarDrvMaxDis; // 200cm.
	APA_DISTANCE_TYPE APAParkProcPProgressOutOfSlotFwStepCarDrvMinDis; // 100cm.
	APA_DISTANCE_TYPE APAParkProcPProgressInFwCorStepDrvBkWhenPerIs100MaxX; // -120cm.
	APA_DISTANCE_TYPE APAParkProcPProgressInFwCorStepDrvMaxXWhenDeltaCarAngIsSmall; // -120cm.
	APA_DISTANCE_TYPE APAParkProcPProgressInFwCorStepCompTrajCalPosDeltaX1; // 10cm. at delta car angle is 20deg.
	APA_DISTANCE_TYPE APAParkProcPProgressInFwCorStepCompTrajCalPosDeltaX2; // 60cm.    at delta car angle is 60deg.
	APA_DISTANCE_TYPE APAParkProcPProgressInFwStartCheckFwSnsDtDisMaxValue; // 80cm.
	APA_DISTANCE_TYPE APAParkProcPProgressInFwStartCheckFwSnsDtDisCarPosMaxX; // -50 cm.
	APA_DISTANCE_TYPE APAParkProcPProgressInSlotFwStartCheckTargetPosMaxDeltaXDis; // 100 cm.
	APA_ENUM_TYPE APAParkProcPProgressStartRecalTargetPosMinPercentage; // 50%
	APA_DISTANCE_TYPE APAParkProcPProgressInBkStartCheckTargetPosMaxDeltaYDis; // 150 cm.
	APA_DISTANCE_TYPE APAParkProcPProgressInBkStartCheckTargetPosMinX; // - 120 cm.
	APA_DISTANCE_TYPE APAParkProcPProgressInBkStartCheckTargetPosMaxX; // 120 cm.
	APA_DISTANCE_TYPE APAParkProcPProgressInBkStartCheckBkSnsDtDisMaxValue1; // 70cm.
	APA_ANGLE_TYPE APAParkProcPProgressInBkStartCheckBkSnsDtDisMinDeltaCarAng1; // 30deg.
	APA_DISTANCE_TYPE APAParkProcPProgressInBkStartCheckBkSnsDtDisMaxValue2; // 50cm.
	APA_ANGLE_TYPE APAParkProcPProgressInBkStartCheckBkSnsDtDisMinDeltaCarAng2; // 23deg.
	
	APA_DISTANCE_TYPE APAParkProcPCarPosDevideLineDeltaY[APA_PER_PREDICT_CAR_CAN_DRV_TARGET_POS_NUM]; // 5cm, 10, 20, 40, 60, 80, 100, 120cm,

	// APA_DISTANCE_TYPE APAParkProcPCarPosDevideLineDeltaX02; // 30cm,  or 20cm??
	APA_DISTANCE_TYPE APAParkProcPCarPosDevideLineDeltaX01; // 50cm,  or 40cm??
	APA_DISTANCE_TYPE APAParkProcPCarPosDevideLineDeltaX0; // 80cm,   or 70cm??
	APA_DISTANCE_TYPE APAParkProcPCarPosDevideLineDeltaX1; // 150cm
	APA_DISTANCE_TYPE APAParkProcPCarPosDevideLineDeltaX2; // 300cm
	APA_DISTANCE_TYPE APAParkProcPCarPosDevideLineDeltaX3; // 450cm
	APA_DISTANCE_TYPE APAParkProcPCarPosDevideLineDeltaX4; // 550cm
	APA_DISTANCE_TYPE APAParkProcPCarPosDevideLineDeltaX5; // 600cm

	APA_ANGLE_TYPE APAParkProcPCarPosDevideLineDeltaCarAng02; // 1.5deg
	//APA_ANGLE_TYPE APAParkProcPCarPosDevideLineDeltaCarAng01; // 2.5deg
	APA_ANGLE_TYPE APAParkProcPCarPosDevideLineDeltaCarAng0; // 5deg
	APA_ANGLE_TYPE APAParkProcPCarPosDevideLineDeltaCarAng1; // 10deg
	APA_ANGLE_TYPE APAParkProcPCarPosDevideLineDeltaCarAng2; // 20deg
	APA_ANGLE_TYPE APAParkProcPCarPosDevideLineDeltaCarAng3; // 30deg
	APA_ANGLE_TYPE APAParkProcPCarPosDevideLineDeltaCarAng4; // 40deg
	
/*2.4.11.2 *** park exit ***/
	APA_MS_TIME_TYPE  APAParkProcPEWaitingForSearchingForSlotTime;
 	APA_DISTANCE_TYPE APAParkProcPETightSlotMinTotalFrontAndRearSnsDtdDis;	
	//APA_MS_TIME_TYPE APAParkProcPECarMayHitObjectStopWaitingTime;	
	APA_ENUM_TYPE APAParkProcPECarEndPosMode;
	APA_ANGLE_TYPE APAParkProcPECarEndPosMaxCarAngle;	
	APA_ANGLE_TYPE APAParkProcPECarEndPosMinCarAngle;		
	APA_DISTANCE_TYPE APAParkProcPEAPAExitWithMaxCarPosY;	
	APA_DISTANCE_TYPE APAParkProcPECarParkingCarEndPositionXDisTol;
	APA_ANGLE_TYPE APAParkProcPECarEndPositionCarAngTol;
	APA_DISTANCE_TYPE APAParkProcPEAllowCarDriveTowardsTheObjMinDis;
	APA_DISTANCE_TYPE APAParkProcPEStartCheckCarCanDrvOutOfSlotMinFrontObjDis; // def: 600cm.
	APA_DISTANCE_TYPE APAParkProcPECheckCarCanDrvOutOfSlotMinDeltaCarPosY; // def: 300cm.
	APA_DISTANCE_TYPE APAParkProcPERegardAsCarCanDrvOutOfSlotMinFrontObjDis; // def: 500cm.
	APA_DISTANCE_TYPE APAParkProcPERegardAsCarCanDrvOutOfSlotSaftetyDisAtFCorObjDrvFw; // def: 0cm. or -10cm ??
	APA_DISTANCE_TYPE APAParkProcPERegardAsCarCanDrvOutOfSlotSaftetyDisAtFCorObjDrvBk; // def: 30cm. or 40cm ??
	APA_DISTANCE_TYPE APAParkProcPERegardAsCarCanDrvOutOfSlotSmallSafetyDis; // def: 0cm.

	APA_DISTANCE_TYPE APAParkProcPEBigSafetyDisToObjAtFrontTurningCar; // when turning the car 
    APA_DISTANCE_TYPE APAParkProcPEBigSafetyDisToObjAtRearTurningCar; 
	APA_DISTANCE_TYPE APAParkProcPEUseBigSafetyDisToObjMinSlotLen; // when turning the car 
	
	APA_DISTANCE_TYPE APAParkProcPERecorObj2XCorrectStep; // def: 40cm.
	APA_DISTANCE_TYPE APAParkProcPERecorObj2XAllowMinObj2X; // def: 100cm.
    APA_DISTANCE_TYPE APAParkProcPEStartTurnSteeringToStep2CarToStep2KeyPtDis; // 500
	
	/****************************************************************/
	// Luhui 20200805 word AdaptiveCruiseControlActiveIndicateTrueTime;//add by lzc 2012 09 26
	//Luhui word wMaxAPAPhySwDefaultParkingPressMinCnt;///******DIAG TRACE TEST*********/
	
	/***********************DIAG TRACE TEST **************************/ //ethan
//	tAPADiagnosticTraceInfoType APADiagnosticTraceDefaultData;	// added by zhx 2013 03 07
	/***********************DIAG TRACE TEST **************************/
	 
	// char CalibrationTemplate;//added by lzc 2013 01 29
}APACalibrationDataType;


/*************************************************************************************************************************************************
**                                                              Global Constant Declarations                                                    **
*************************************************************************************************************************************************/
extern APACalibrationDataType const APACal;

/*************************************************************************************************************************************************
**                                                              Global Variable Declarations                                                    **
*************************************************************************************************************************************************/

/*************************************************************************************************************************************************
**                                                              Global Function Declarations                                                    **
*************************************************************************************************************************************************/

/*************************************************************************************************************************************************
**                                                              End of file                                                                     **
*************************************************************************************************************************************************/

#endif /* APACalibration_H */


