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
**  $FILENAME   :  SlotProcessSubFunction.h $                                                                                                   **
**                                                                                                                                              **
**  $CC VERSION : \main\94 $                                                                                                                    **
**                                                                                                                                              **
**  $DATE       : 2020-08-xx $                                                                                                                  **
**                                                                                                                                              **
**  AUTHOR      : SAIC - US Group -Engineering                                                                                                  **
**                                                                                                                                              **
**  VENDOR      : SAIC Technologies                                                                                                             **
**                                                                                                                                              **
**  DESCRIPTION : This file contains                                                                                                            **
**                - USS sub-function processing                 ..                                                                              **
**                                                                                                                                              **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                                                                                        **
**                                                                                                                                              **
*************************************************************************************************************************************************/
#ifndef SLOTPROCESSSUBFUNCTION_H_
#define SLOTPROCESSSUBFUNCTION_H_

/*************************************************************************************************************************************************
**                                                              Includes                                                                        **
*************************************************************************************************************************************************/
#include "Platform_Types.h"
#include "APACommonType.h"
#include "SlotProcessDataType.h"


/*************************************************************************************************************************************************
**                                                              Debug Information SW                                                            **
*************************************************************************************************************************************************/


/*************************************************************************************************************************************************
**                                                              Global Macro Definitions                                                        **
*************************************************************************************************************************************************/
#define MATH_FABS										fabsf
#define MATH_COS										cosf
#define MATH_SIN										sinf
#define MATH_ATAN										atanf


#define SDG_SUPPORT_SDG_SNS_NUM							(4)


#define bFRAPASnsDtdObjDisUpdated                       APAObjDisUpdateFlag.Bits.BIT0
#define bFLAPASnsDtdObjDisUpdated                       APAObjDisUpdateFlag.Bits.BIT1
#define bRRAPASnsDtdObjDisUpdated                       APAObjDisUpdateFlag.Bits.BIT2
#define bRLAPASnsDtdObjDisUpdated                       APAObjDisUpdateFlag.Bits.BIT3
#define bRRCUPASnsDtdObjDisUpdated                      APAObjDisUpdateFlag.Bits.BIT4 // Rear Right Corner sensor.
#define bRLCUPASnsDtdObjDisUpdated                      APAObjDisUpdateFlag.Bits.BIT5 // Rear Left Corner sensor.
#define PA_PHY_SW_DT_TASK_CALL_CYCLE_TIME			    	10


#define APA_TRAJCAL_CAR_DRIVE_STRAIGHTLY_TOL_MAX_CHECK_DIS								10000
#define APA_TRAJCAL_DIS_CAL_VALUE_IS_EQUAL_TOL											20 // 2cm // (1e-2)
#define SDG_OBJECT_ACK_WEIGHT_COEFFICIENT				(50)
#define SDG_OBJECT_MAX_WEIGHT_COEFFICIENT				(100)
#define SDG_SENSOR_MAX_DETECT_LOOP_CNT_TO_CONFIRM_OBJECT (10)
#define APA_TRAJCAL_CURB_LINE_FIT_MAX_SUPPORT_OBJ_NUM									15
#define APA_TRAJCAL_WITHOUT_OBJ1_COORDINATE_X											((APACal.LengthOfCar))
#define APA_TRAJCAL_WITHOUT_OBJ2_COORDINATE_X											((APACal.LengthOfCar))
#define SDG_MAX_NUMBER_OF_DT_TIMES						(55)
#define SDG_NUMBER_OF_DT_TIMES_CAL_MIN_SPD				(1.0 / 3.6) // 1km/h'
#define SDG_SENSOR_DT_ONE_LOOP_TIME_MS					(40) // unit: ms, 40ms.

#define SDG_SENSOR_HFOV_MAX_DT_DIS						(5000)
#define SDG_SENSOR_HFOV_DIVIDED_SEG_DIS					(SDG_SENSOR_HFOV_MAX_DT_DIS / SDG_SENSOR_HFOV_DIVIDED_SEG_NUM)

#define __EP21__ 1


typedef enum {

    SDG_OFF = 0,
    SDG_AUTO_DEACTIVATED,
    SDG_MANUAL_DEACTIVATED,
    SDG_OPERATION_MODE,
    SDG_FAULT_MODE

} SDGOperatingStateType;


typedef enum {

    R_RM_TRIANGLE_OBJ_INDEX = 0,
    RM_LM_TRIANGLE_OBJ_INDEX, /* 1 */
    RM_R_TRIANGLE_OBJ_INDEX,  /* 2 */
    LM_RM_TRIANGLE_OBJ_INDEX, /* 3 */
    LM_L_TRIANGLE_OBJ_INDEX,  /* 4 */
    L_LM_TRIANGLE_OBJ_INDEX   /* 5 */

} UPASnsDtTirangleObjInfoType;


typedef enum{
    APADisable_NO_CAUSES = 0,
    APADisable_AC_Temp_AMB_INVALID,/***1***/
    APADisable_ABS_Valid_Pulse_Counter_RL_INVALID,/***2***/
    APADisable_ABS_Valid_Pulse_Counter_RR_INVALID,/***3***/
    APADisable_ABS_Valid_Pulse_Counter_FL_INVALID,	/***4***/
    APADisable_ABS_Valid_Pulse_Counter_FR_INVALID,	/***5***/
    APADisable_ABS_Valid_WhlSpdRL_INVALID,/***6***/
    APADisable_ABS_Valid_WhlSpdRR_INVALID,/***7***/
    APADisable_ABS_Valid_WhlSpdFL_INVALID,/***8***/
    APADisable_ABS_Valid_WhlSpdFR_INVALID,/***9***/
    APADisable_UPA_DISABLE,/**10**/
    APADisable_APA_FAILED,/***11***/
    APADisable_VEHICLE_SPD_EXCEED_MAX_SEARCHING_SLOT_SPD,/***12***/
    APADisable_ABS_Counter_MSG_6_SEQUENCE_NUM_INCORRECT,/***13***/
    APADisable_ABS_Counter_MSG_5_SEQUENCE_NUM_INCORRECT,/***14***/
    APADisable_EPS_STATUS_UNAVAILILABLE,	/***15***/
    APADisable_EPS_Status_Msg_Cnt_Or_CheckSum_INCORRECT,	/***16***/
    APADisable_ABS_Valid_SPD_Lateral_ACC_VALIDITY_INVALID,	/***17***/
    APADisable_ABS_Valid_SPD_Longitudinal_ACC_VALIDITY_INVALID,/***18***/
    APADisable_SAS_Status_Calibration_NOT_CALIBRATED,/***19***/
    APADisable_SAS_MSG_Counter_Or_CheckSumINCORRECT,/**20**/
    APADisable_ABS_2_FrontWhlSpdRxTimeout,/***21***/
    APADisable_ABS_4_RearWhlSpdRxTimeout,/***22***/
    APADisable_EPS_1_StatusRxTimeout,/***23***/
    APADisable_GearSignalRxTimeout,/***24***/
    APADisable_MANULLY_DEACTIVATED,/***25***/
    APADisable_CaledVehSpd_INVALID,/***26***/
    APADisable_Lateral_Or_Longitudinall_ACC_Msg_Cnt_Or_CheckSum_INCORRECT,/***27***/
    APADisable_CAN_SIGNAL_INVALID,/***28***/
    APADisable_SAS_Angle_SteeringWheel_Signal_Invalid/***29***/

}tAPADisableCausesForDX7;

typedef  enum{
        APA_STATE_OFF = 0,
        APA_STATE_DISABLE,
        APA_STATE_STANDBY_ENABLE,
        APA_STATE_ENABLE,
        APA_STATE_ACTIVE
}tAPAOperationState;
/*************************************************************************************************************************************************
**                                                              Global Type Definitions                                                         **
*************************************************************************************************************************************************/



typedef struct  {
    SDG_DISTANCE_TYPE ZoneDivisionLineX[SDG_SUPPORT_ZONE_NUM + 1];
    SDG_DISTANCE_TYPE ZoneDivisionHysteresisDis;
    SDG_ENUM_TYPE ZoneNum; // Support up to 15 zone.
    SDG_DISTANCE_TYPE RegionDivisionLineY[SDG_SUPPORT_REGION_NUM + 1];
    SDG_DISTANCE_TYPE RegionDivisionHysteresisDis;
    SDG_ENUM_TYPE RegionNum; // Support up to 3 region.

}  SDGRegionAndZoneDivisionInfoType;


typedef union {
    unsigned char Byte;
    struct {
    unsigned int  BIT0        :1;                                       /* Bit 0 */
    unsigned int  BIT1        :1;                                       /* Bit 1 */
    unsigned int  BIT2        :1;                                       /* Bit 2 */
    unsigned int  BIT3        :1;                                       /* Bit 3 */
    unsigned int  BIT4        :1;                                       /* Bit 4 */
    unsigned int  BIT5        :1;                                       /* Bit 5 */
    unsigned int  BIT6        :1;                                       /* Bit 6 */
    unsigned int  BIT7        :1;                                       /* Bit 7 */
    } Bits;
} tByteBitType;



typedef struct  {

    SDGObjPtBufType SnsObjPtBuf[SDG_SUPPORT_SDG_SNS_NUM];

}  SDGObjInfoType;

typedef struct  {

		SDG_ENUM_TYPE SDGObjDtDisapearDelayLoopCnt; // 30 * 35ms = 1.05s.
		SDG_SPEED_TYPE SDG_ThresholdDesactivationSpeed;
		SDG_SPEED_TYPE SDG_ThresholdActivationSpeed;
		SDG_DISTANCE_TYPE SDG_minDistanceWarning;
		SDG_ANGLE_TYPE SDG_StartCheckObjectSteeringAngle;
		SDG_DISTANCE_TYPE SDGSafetyDisWhenCarIsTurning;

		SDG_DISTANCE_TYPE SDGDtObjMinDis;
		SDG_DISTANCE_TYPE SDGDtObjMaxDis;
		SDG_DISTANCE_TYPE SDGSnsDtRoundObjMaxDeltaDis;
		SDG_DISTANCE_TYPE SDGSnsDtRoundObjMinDeltaDis;
		SDG_DISTANCE_TYPE SDGSnsDtSQuareObjMaxDeltaDis;
		SDG_DISTANCE_TYPE SDGTrackingAreaDrivingDirection;
		SDGRegionAndZoneDivisionInfoType SDGRegionAndZoneDivisionInfo;
		SDG_DISTANCE_TYPE SDGHFOVWidthBySeg[SDG_SENSOR_HFOV_DIVIDED_SEG_NUM];
		SDG_DISTANCE_TYPE SDGHFOVCompensateDisByObjTypeAndSeg[SDG_SUPPORT_OBJ_TYPE_NUM][SDG_SENSOR_HFOV_DIVIDED_SEG_NUM];
		SDG_ANGLE_TYPE SDGDrvBkPtKeepMaxDeltaCarAng;
		SDG_DISTANCE_TYPE SDGKeepObjectPointDis;
		SDG_DISTANCE_TYPE SDGKeepNoObjectPointDis;
		SDG_DISTANCE_TYPE SDGSnsDtObjRegionAreaWidth;
		SDG_DISTANCE_TYPE SDGKeepObjPtMinDeltaDtDis;
		SDG_DISTANCE_TYPE SDGSnsDtObjRegardedAsSameObjTolDis;
		UCHAR SDGSnsDtObjProbalilityPercentage;

		// for perpendicular parking slot correction filter 2014 08 21
		SDG_DISTANCE_TYPE SDGPointCanBeRemovedContiguousPointMinDisP;
		SDG_DISTANCE_TYPE SDGPointCanBeRemovedContiguousPointMinDisP2;
		SDG_DISTANCE_TYPE SDGSamplePointUpdateSmallDeltaLen;
		SDG_DISTANCE_TYPE SDGSamplePointUpdateSmallDeltaLen2;
		SDG_SLOT_PT_SLOPE_TYPE SDGSamplePointCanBeRemovedMaxObjPtDeltaSlope;
		SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedRegardAsNoiseMinObjWidth;
		SDG_DISTANCE_TYPE SDGSamplePointNoisePtStartCheckBkObjWidth;
		SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedCheckMinNoObjWidth;
		SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedHeadOrTailMaxDeltaObjDis;
		SDG_SLOT_PT_SLOPE_TYPE SDGSamplePointNoisePtCanBeRemovedHeadOrTailMaxSlope;
		SDG_SLOT_PT_SLOPE_TYPE SDGSamplePointNoisePtCanBeRemovedHeadOrTailMinSlope;
		SDG_SLOT_PT_SLOPE_TYPE SDGSamplePointAllowedMaxDeltaSlope;
		SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedCheckStartHeadWidth;
		SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedCheckNoiseWidth;
		SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedMaxDis;
		SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedSameObjTol;
		SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedCheckNoiseToObjWidth;
		SDG_ENUM_TYPE SDGSamplePointNoisePtCanBeRemovedMinSameObjPtNum;
		SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedMinObjWidth;
		SDG_ENUM_TYPE SDGSamplePointNoisePtCanBeRemovedMaxNoiseWidthPercentage;
		SDG_DISTANCE_TYPE SDGSamplePointNoisePtRegardedAsSameObjMaxDeltaObjDis;
		SDG_DISTANCE_TYPE SDGSamplePointNoisePtRegardedAsSameObjMinObjWidth;
		SDG_DISTANCE_TYPE SDGSamplePointUpdateLongDeltaLen;
		SDG_DISTANCE_TYPE SDGSamplePointCanBeRemovedMaxObjDis;
		SDG_ENUM_TYPE SDGSamplePointNoisePtCanBeRemovedMinObjPtOutOfTolNum;
		SDG_ENUM_TYPE SDGSamplePointNoisePtCanBeRemovedMinNoObjPtWitinNoiseNum;
		SDG_ENUM_TYPE SDGSamplePointNoisePtCanBeRemovedMinNoObjPtTotalNum;

} SDGCalibrationDataType;

/*************************************************************************************************************************************************
**                                                              Global Constant Declarations                                                    **
*************************************************************************************************************************************************/

/*************************************************************************************************************************************************
**                                                              Global Variable Declarations                                                    **
*************************************************************************************************************************************************/
extern tAPAWordBitType _APACommonFlag00;
#define APACommonFlag00                          			_APACommonFlag00.Word   //uss
#define bAPARxSteeringWheelAngleDirection        			_APACommonFlag00.Bits.BIT0
#define bAPASteeringWheelCtrlTask_APAOperatingStateChanged	_APACommonFlag00.Bits.BIT1
#define bAPATrajectoryCalTaskActivated                  	_APACommonFlag00.Bits.BIT2
#define bAPASnsDtdObjDisInfoBufOverFlowed               	_APACommonFlag00.Bits.BIT3
#define bAPARequestReconnectEPS               				_APACommonFlag00.Bits.BIT4
#define bAPAGearPutIntoReverse               				_APACommonFlag00.Bits.BIT5
#define bAPAGearPutIntoDrive               					_APACommonFlag00.Bits.BIT6
#define bAPAVehicleIsStatic									_APACommonFlag00.Bits.BIT7   //uss
#define bAPAVehicleIsMoving									_APACommonFlag00.Bits.BIT8   //uss
#define bAPATrajGearPutIntoReverse							_APACommonFlag00.Bits.BIT10
#define bAPATrajGearPutIntoDrive							_APACommonFlag00.Bits.BIT11
#define bDriverTryToControlTheEPS							_APACommonFlag00.Bits.BIT12
#define bAutoLearningWheelPulseAccumulateStart				_APACommonFlag00.Bits.BIT13
#define bAPATrajCalCarParkAlongCurb							_APACommonFlag00.Bits.BIT14   //uss
#define bTireDiameterAutoLearningWheelPulseAccumulateStart	_APACommonFlag00.Bits.BIT15

//extern SDGObjInfoType SDGObjInfo;
extern SDGOperatingStateType SDGState;
extern tByteBitType APAObjDisUpdateFlag;
extern SDG_DISTANCE_TYPE SDGKeepNoObjPtDis;
extern SDGSnsDtdObjPtBufType SDGSnsDtdObjPtBuf[SDG_SUPPORT_SDG_SNS_NUM];
extern tParkAssistantStatusLSType SDGParkAssistantLeftStatusLS;
extern tParkAssistantStatusLSType SDGParkAssistantRightStatusLS;
extern SDG_DISTANCE_TYPE SDGSnsDtObjRegardedAsSameObjTolDis;
extern SDG_DISTANCE_TYPE SDGSnsDtObjRegionWidth;
extern SDG_WEIGHT_COEFFICIENT_TYPE SDGSnsDtObjProbalilityPercentage;
extern SDG_DISTANCE_TYPE SDGPointCanBeRemovedContiguousPointMinDisP;
extern SDG_DISTANCE_TYPE SDGPointCanBeRemovedContiguousPointMinDisP2;
extern SDG_SLOT_PT_SLOPE_TYPE SDGSamplePointAllowedMaxDeltaSlope;
extern SDG_SLOT_PT_SLOPE_TYPE SDGSamplePointCanBeRemovedMaxObjPtDeltaSlope;
extern SDG_DISTANCE_TYPE SDGPointCanBeRemovedContiguousPointMinDisP;
extern SDG_DISTANCE_TYPE SDGPointCanBeRemovedContiguousPointMinDisP2;
extern SDG_SLOT_PT_SLOPE_TYPE SDGSamplePointAllowedMaxDeltaSlope;
extern SDG_SLOT_PT_SLOPE_TYPE SDGSamplePointCanBeRemovedMaxObjPtDeltaSlope;
extern SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedCheckMinNoObjWidth;
extern SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedRegardAsNoiseMinObjWidth;
extern SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedCheckNoiseWidth;
extern SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedCheckStartHeadWidth;
extern SDG_DISTANCE_TYPE SDGSamplePointNoisePtRegardedAsSameObjMaxDeltaObjDis;
extern SDG_SLOT_PT_SLOPE_TYPE SDGSamplePointNoisePtCanBeRemovedHeadOrTailMaxSlope;
extern SDG_SLOT_PT_SLOPE_TYPE SDGSamplePointNoisePtCanBeRemovedHeadOrTailMinSlope;
extern SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedMaxDis;
extern SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedSameObjTol;
extern SDG_ENUM_TYPE SDGSamplePointNoisePtCanBeRemovedMaxNoiseWidthPercentage;
extern SDG_ENUM_TYPE SDGSamplePointNoisePtCanBeRemovedMinSameObjPtNum;
extern SDG_ENUM_TYPE SDGSamplePointNoisePtCanBeRemovedMinObjPtOutOfTolNum;
extern SDG_ENUM_TYPE SDGSamplePointNoisePtCanBeRemovedMinNoObjPtWitinNoiseNum;
extern SDG_DISTANCE_TYPE SDGSamplePointNoisePtRegardedAsSameObjMinObjWidth;
extern SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedHeadOrTailMaxDeltaObjDis;
extern SDG_DISTANCE_TYPE SDGSamplePointNoisePtStartCheckBkObjWidth;
extern SDG_DISTANCE_TYPE SDGSamplePointUpdateSmallDeltaLen;
extern SDG_DISTANCE_TYPE SDGSamplePointUpdateSmallDeltaLen2;
extern SDG_WEIGHT_COEFFICIENT_TYPE SDGSnsDtObjProbalilityPercentage;
extern SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedCheckNoiseToObjWidth;
extern SDG_ENUM_TYPE SDGSamplePointNoisePtCanBeRemovedMinNoObjPtTotalNum;
extern SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedMinObjWidth;
extern SDG_DISTANCE_TYPE SDGSamplePointNoisePtRegardedAsSameObjMinObjWidth;

/*************************************************************************************************************************************************
**                                                              Global Function Declarations                                                    **
*************************************************************************************************************************************************/
void APACarParInit(void);

void APAResetCarPosition(void); 
    
void APAGetSideSnsDtdDistance(APA_DISTANCE_TYPE *pSnsLDtMinDis,	APA_DISTANCE_TYPE *pSnsRDtMinDis,APA_DISTANCE_TYPE *pSnsLDtMinDis_Rear,APA_DISTANCE_TYPE *pSnsRDtMinDis_Rear);

void APATrajCalDistanceBetweenOriginalPtAndObj2(APA_ENUM_TYPE ParkingModeIndex);

BOOLEAN APATrajCalParallelSetupSystemCoordinateAccordingToSlotData(APA_ENUM_TYPE *pCalResult,
	APA_ENUM_TYPE SlotLaneCalMode,
	APA_ENUM_TYPE *pSubSlotCaled,
	APA_ANGLE_CAL_FLOAT_TYPE *pNewCarAngToBeTransfered,
	APACoordinateDataCalFloatType *pNewCarCenterPtToBeTransfered
	);
BOOLEAN APATrajCalPerpendSetupSystemCoordinateAccordingToSlotData(void);

void APATrajCalParallelSetupSystemCoordinateAccordingToSlotDataCheckObj2StartEdge(void);

BOOLEAN APATrajCalPerpendCheckIfCurCarWillHitObj12OrSlotBorderLine(
    APACarCoordinateDataCalFloatType * pCurCarPos,
    BOOLEAN bCheckObj1,
    BOOLEAN bCheckObj2,
    BOOLEAN bCheckObj1BorderLine,
    BOOLEAN bCheckObj2BorderLine
) ;

//void SDGResetDetectedObj(void);

// void SDGSaveObjPointToBuf(
//     SDG_ENUM_TYPE SnsIndex,
//     SDGObjPointType *pObjPt
// );

void SDGSensorDtdObjectDisProcessTask(APA_ENUM_TYPE cProcessMode);
BOOLEAN APATrajCalFitCurbLineAccordingToSlotData(APASlotOutlineCoordinateDataType *pMainSlot,
                                                 APA_DISTANCE_TYPE CarToObj2Dis,
                                                 APA_INDEX_TYPE SlotStartIndex,
                                                 APA_INDEX_TYPE SlotEndIndex,
                                                 APA_DISTANCE_TYPE SlotDepth,
                                                 APA_ANGLE_CAL_FLOAT_TYPE *pCurbLineAngWithY,
                                                 APALineParameterABCType *pCurbLine);
/*************************************************************************************************************************************************
**                                                              Global Inline Function Definitions                                              **
*************************************************************************************************************************************************/


/*************************************************************************************************************************************************
**                                                              End of file                                                                     **
*************************************************************************************************************************************************/

#endif /* SLOTPROCESSSUBFUNCTION_H_ */

