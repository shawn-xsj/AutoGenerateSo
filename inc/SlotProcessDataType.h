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
**  $FILENAME   :  SlotProcessDataType.h $                                                                                                      **
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
**                - USS slot process data type definition                  ..                                                                   **
**                                                                                                                                              **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                                                                                        **
**                                                                                                                                              **
*************************************************************************************************************************************************/
#ifndef SLOTPROCESSDATATYPE_H_
#define SLOTPROCESSDATATYPE_H_

/*************************************************************************************************************************************************
**                                                              Includes                                                                        **
*************************************************************************************************************************************************/
#include "Platform_Types.h"
#include "APACommonType.h"

/*************************************************************************************************************************************************
**                                                              Debug Information SW                                                            **
*************************************************************************************************************************************************/

/*************************************************************************************************************************************************
**                                                              Global Macro/ENUM Definitions                                                   **
*************************************************************************************************************************************************/
#define SDG_SUPPORT_ZONE_NUM							15
#define SDG_SUPPORT_REGION_NUM							3
#define SDG_SUPPORT_OBJ_TYPE_NUM						3
#define SDG_SENSOR_HFOV_DIVIDED_SEG_NUM					(20)
#define SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE				30
#define APA_SUPPORT_MAX_APA_DISABLE_CAUSES_BUF_SIZE				6
#define APA_SUPPORT_MAX_APA_FAILED_CAUSES_BUF_SIZE				7

#define APA_SLOT_MAX_SUPPORT_SNS_DTD_OBJ_POINT_BUF_SIZE		(10) // def: 5
#define APA_SUPPORT_MAX_VEH_SPD_BUF_SIZE        				7 // 70ms, 70 / 10ms
#define APA_SUPPORT_ORIGINAL_STEP_DATA_NUM						4 // Add 2012 06 05
//#define APASupportMaxCarTurningRadius							(1e10) // def(1e5: NG, it is too small). m. It is only used for float calcualtion.


#define APA_SLOT_ALLOW_ALL_SLOT_DEFINITION					0x007f
#define APA_SLOT_ALLOW_SLOT_WITH_OBJ1_INVALID_DIS_TO_CAR	8
#define APA_SLOT_ALLOW_SLOT_WITH_OBJ2_INVALID_DIS_TO_CAR	0x0010
#define APA_SLOT_CAR_CENTER_POINT_X_DEFAUT_VALUE			0
#define APA_SLOT_OBJ_PT_SLOPE_ZOOM_TIMES					(30) // zoom 30 times.
#define APA_SLOT_OBJ_PT_SLOPE_ERROR_OBJ_WIDTH_TOO_LONG		(126)
#define APA_SLOT_OBJ_PT_SLOPE_MAX_VALUE						(120) // zoom 30 times. 120: 120 / 30 = 4: atan(4) = 76deg;
#define APA_SLOT_OBJ_PT_SLOPE_ERROR_OBJ_WIDTH_TOO_SHORT_DEF_VALUE	(30) // zoom 30 times. 120: 120 / 30 = 4: atan(4) = 76deg;
#define APA_SLOT_OBJ_PT_SLOPE_MIN_VALUE						(-120) // zoom 30 times. -120: -120 / 30 = -4: atan(-4) = -76deg;

#define APA_SLOT_OBJ_IS_BIG_ENOUGH_CHECK_CURB_MASK		0x02
#define APA_SLOT_INVALID_SLOT_ID						32767 // 0x7fff
#define UPA_APA_SNS_DT_NON_TRIANGLE_OBJ_ARRAY_NUM			12
#define UPA_SNS_DT_OBJ_BUF_SIZE                   			10
#define UPA_SNS_DT_TRIANGLE_OBJ_ARRAY_NUM					6
#define UPA_SNS_DT_OBJ_LAST_VALUE_INDEX              		(UPA_SNS_DT_OBJ_BUF_SIZE - 1)
#define SDG_MAX_SUPPORT_SNS_DTD_OBJ_POINT_BUF_SIZE		10//5
#define SDG_NO_OBJ_ZONE									0
#define SDG_SUPPORT_SDG_SNS_DIS_NUM						(4)



typedef enum{
    UPA_APA_SNS_RS_EMIT_RS_RX_OBJ_INDEX = 0,
	UPA_APA_SNS_R_EMIT_R_RX_OBJ_INDEX,   // 1
	UPA_APA_SNS_R_EMIT_RM_RX_OBJ_INDEX,   /* 2 */
	UPA_APA_SNS_RM_EMIT_RM_RX_OBJ_INDEX,  /* 3 */
	UPA_APA_SNS_RM_EMIT_LM_RX_OBJ_INDEX,  /* 4 */
	UPA_APA_SNS_RM_EMIT_R_RX_OBJ_INDEX,   /* 5 */
	UPA_APA_SNS_LM_EMIT_LM_RX_OBJ_INDEX,  /* 6 */
	UPA_APA_SNS_LM_EMIT_RM_RX_OBJ_INDEX,  /* 7 */
	UPA_APA_SNS_LM_EMIT_L_RX_OBJ_INDEX,   /* 8 */
	UPA_APA_SNS_L_EMIT_L_RX_OBJ_INDEX,    /* 9 */
	UPA_APA_SNS_L_EMIT_LM_RX_OBJ_INDEX ,  /* 10 */
	UPA_APA_SNS_LS_EMIT_LS_RX_OBJ_INDEX   // 11
} UPAAPASnsDtObjInfoType;  //zp

typedef enum
{
  SDG_OBJ_TYPE_UNKNOWN = 0,
  SDG_OBJ_TYPE_ROUND,
  SDG_OBJ_TYPE_SQUARE
} SDGObjTypeType;

typedef enum {
	APASlotMirrorReqType_IDLE = 0,
	APASlotMirrorReqType_REQ,
	APASlotMirrorReqType_PERMIT
}APASlotMirrorReqType;

typedef enum {
	APA_SLOT_SIMPLE_OBJ_TYPE_UNKNOWN = 0,
	APA_SLOT_SIMPLE_OBJ_TYPE_ROUND,
	APA_SLOT_SIMPLE_OBJ_TYPE_SQUARE
} APASlotSimpleObjType;

typedef enum {
	APA_FRS_SNS_DT_OBJ_DIS_INDEX = 0,
	APA_FLS_SNS_DT_OBJ_DIS_INDEX,
	APA_RRS_SNS_DT_OBJ_DIS_INDEX,
	APA_RLS_SNS_DT_OBJ_DIS_INDEX
} APASideSnsDtObjDisIndexType;

typedef enum {
	APAParkProcSlotFoundTrajCalReqWithoutCaled = 0,
	APAParkProcSlotFoundTrajCalReqPPerpendSlotWithoutObj2OneSlot,
	APAParkProcSlotFoundTrajCalReqPPerpendSlotWithoutObj2MoreThanOneSlot,
	APAParkProcSlotFoundTrajCalReqPPerpendSlotWithObj2OneSlot,
	APAParkProcSlotFoundTrajCalReqPPerpendSlotWithObj2MoreThanOneSlot,
	APAParkProcSlotFoundTrajCalReqPParalSlotLen1OkPkToObj1OneSlot,
	APAParkProcSlotFoundTrajCalReqPParalSlotLen1OkPkToObj1MoreSlot,
	APAParkProcSlotFoundTrajCalReqPParalSlotLen2OkPkToObj1OneSlot,
	APAParkProcSlotFoundTrajCalReqPParalSlotLen2OkPkToObj1MoreSlot,
	APAParkProcSlotFoundTrajCalReqPParalSlotLen2OkPkToObj2OneSlot,
	APAParkProcSlotFoundTrajCalReqPParalSlotLen2OkPkToObj2MoreSlot,
	APAParkProcSlotFoundTrajCalReqPParalSlotLen2OkPkToMidOneSlot,
	APAParkProcSlotFoundTrajCalReqPParalSlotLen2OkPkToMidMoreSlot,
	APAParkProcSlotFoundTrajCalReqPParalSlotLen3OkPkToObj2OneSlot,
	APAParkProcSlotFoundTrajCalReqPParalSlotLen3OkPkToObj2MoreSlot,
	APAParkProcSlotFoundTrajCalReqParalSlotPkToObj1OneSlot,
	APAParkProcSlotFoundTrajCalReqParalSlotPkToObj1MoreSlot,
	APAParkProcSlotFoundTrajCalReqParalSlotPkToObj2OneSlot,
	APAParkProcSlotFoundTrajCalReqParalSlotPkToObj2MoreSlot,
	APAParkProcSlotFoundTrajCalReqParalSlotPkToMidOneSlot,
	APAParkProcSlotFoundTrajCalReqParalSlotPkToMidMoreSlot
} tAPAParkProcSlotFoundTrajCalRequestType;

typedef enum {
    SDG_FRS_SNS_INDEX = 0,
    SDG_FLS_SNS_INDEX,
    SDG_RRS_SNS_INDEX,
    SDG_RLS_SNS_INDEX
} SDGSnsIndexType;

/*************************************************************************************************************************************************
**                                                              Global Type Definitions                                                         **
*************************************************************************************************************************************************/

typedef union {
	byte SlotCorrectionIndicationFlag;  // for trajectory cal use only.
	struct {
		byte Obj2YChanged : 1;
		byte Obj1YChanged : 1;
		byte LeftSideLineExist : 1;
		byte RightSideLineExist : 1;
		byte CarEndPosXChanged : 1;
		byte CarEndPosYChanged : 1;
		byte CarEndPosAngChanged : 1;
		byte LeftAndRightSideLineDeltaAngIsBig : 1;
	} Bits;
} tAPASlotCorrectionIndicationFlagType;

typedef union{
	byte Status;
	struct{
		byte bIsRisingPt														:1;
		byte bIsFallingPt														:1;
		byte bIsFlatPt															:1;
		byte bIsBigEchoBkWvWidth												:1;
		byte bIsNoise															:1;
		byte bObjDtdCntIsNotEnough												:1;
		byte bIsObjProfileConfirmed												:1;
		byte Reserved															:1;
	}Bits;
}tAPASlotSnsDtdObjPointStatusFlagType;


// typedef struct {
// 	APACoordinateDataCalFloatType LeftTop;
// 	APACoordinateDataCalFloatType RightTop;
// 	APACoordinateDataCalFloatType LeftBottom;
// 	APACoordinateDataCalFloatType RightBottom;
// } APARectCoordinateDataCalFloatType;



typedef APACarCoordinateDataType						SDGCarCoordinateDataType;

typedef APACarCoordinateDataCalFloatType				SDGCarCoordinateDataCalFloatType;

// typedef struct {
// 	APASnsDtdNearestObjDisInfoType ObjDis[APA_PARKPROC_SUPPORT_MAX_SYS_DT_MIN_DIS_NUM];
// 	APA_SPEED_TYPE ObjSpeed[5];
// } APASnsDtdNearestObjDisBufAndObjSpeedDataType;

// typedef struct{

// 	APA_CAL_FLOAT_TYPE EPSSteeringWheelAngle;
// 	APA_CAL_FLOAT_TYPE FrontAxisCenterTurningAngle;
// 	//APA_CAL_FLOAT_TYPE SteeringWheelLearning_Rc;

// }tAPASteeringWheelAngleRatioCalType; // 8 Bytes.

/*2.1************************************* COMMON USE STRUCTURE  END ********************************************/
/*2.2************************* APA SLOT INFO BASE STRUCTURE  START ************************************************/
typedef struct {
	APACoordinateDataType Coordinate;
	APA_DISTANCE_TYPE DisFromCarToObj;
} APASlotCoordinateDataType;

typedef struct {
	APACoordinateDataCalFloatType Coordinate;
	APA_DISTANCE_TYPE DisFromCarToObj;
} APASlotCoordinateDataCalFloatType;

typedef struct  {
	APACarCoordinateDataType CarPos;
	APA_DISTANCE_TYPE BigObjDis; // Object distance detected by the APA sensor. // if big obj dis < 0, it indicate a small obj
	APA_DISTANCE_TYPE SmallObjDis; // Object distance detected by the APA sensor.
	tAPASlotSnsDtdObjPointStatusFlagType BigObjPtStatus;
	tAPASlotSnsDtdObjPointStatusFlagType SmallObjPtStatus;
	uint8 CarSpeed;
} APASlotSnsDtdObjPointType;

typedef struct  {
	APASlotSnsDtdObjPointType ObjPtBuf[APA_SLOT_MAX_SUPPORT_SNS_DTD_OBJ_POINT_BUF_SIZE];
	APA_ENUM_TYPE WrIndex;
	APA_ENUM_TYPE RemovedPtIndex;
} APASlotSnsDtdObjPtBufType;

typedef struct  {
	APACoordinateDataType Pt;
	APACarCoordinateDataType CarPos;
	APA_DISTANCE_TYPE ObjDis; // Object distance detected by the APA sensor.
	//APA_ENUM_TYPE ObjType; /*APASlotObjTypeType ObjType; Object type indicates what kind of object it is. It can be Round, Square or Unknown object type. */
	uint8 CarSpeed;
} APASlotObjPointType;

typedef union{
	byte bt;
	struct {
		byte  bSDGCarIsRunningBackwards			:1;
		byte  bAPASlotDataIsMirrorChange			:1;
		byte  Reserved					        :6;
	} Bits;
} tSDGBooleanType;


//typedef APACoordinateDataType							SDGCoordinateDataType;
//typedef APACarCoordinateDataType						SDGCarCoordinateDataType;
typedef APACoordinateDataCalFloatType					SDGCoordinateDataCalFloatType;

typedef struct  {

	SDG_DISTANCE_TYPE x;
	SDG_DISTANCE_TYPE y;
}SDGCoordinateDataType;

//typedef struct {
//    SDGCoordinateDataType Coordinate;
//    SDG_ANGLE_TYPE CarAng;
//}SDGCarCoordinateDataType;

typedef struct  {
    SDGCoordinateDataType Pt;
    SDGCarCoordinateDataType CarPos;
    SDG_DISTANCE_TYPE ObjDis; // Object distance detected by the SDG sensor.
    SDGObjTypeType ObjType; /* Object type indicates what kind of object it is. It can be Round, Square or Unknown object type. */
} SDGObjPointType;

typedef struct  {
    SDGObjPointType ObjPtBuf[SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE];
    SDG_ENUM_TYPE WrIndex;
    SDG_ENUM_TYPE ObjPtCnt;
} SDGObjPtBufType;

typedef struct{
	SINT16 wDis[UPA_APA_SNS_DT_NON_TRIANGLE_OBJ_ARRAY_NUM][UPA_SNS_DT_OBJ_BUF_SIZE];
	SINT16 wX[UPA_SNS_DT_TRIANGLE_OBJ_ARRAY_NUM][UPA_SNS_DT_OBJ_BUF_SIZE]; /* Horrizontal distance of the obj */
	SINT16 wY[UPA_SNS_DT_TRIANGLE_OBJ_ARRAY_NUM][UPA_SNS_DT_OBJ_BUF_SIZE]; /* Distance between the Obj and the bumper */
} tDtObjUPASnsDtObjDisInfoType;

typedef struct{
	word wDis[UPA_APA_SNS_DT_NON_TRIANGLE_OBJ_ARRAY_NUM];
	SINT16 wX[UPA_SNS_DT_TRIANGLE_OBJ_ARRAY_NUM]; /* Horrizontal distance of the obj */
	SINT16 wY[UPA_SNS_DT_TRIANGLE_OBJ_ARRAY_NUM]; /* Distance between the Obj and the bumper */
} tDtObjSnsDtObjNearestDisInfoType;

typedef struct  {
	SDGCarCoordinateDataType CarPos;
	SDGCoordinateDataType Pt;
	SDG_DISTANCE_TYPE ObjDis; // Object distance detected by the SDG sensor.
	SDG_ENUM_TYPE WeightCoe; /* Weight coefficient indicates how many times the object has been detected. A delta weight coefficient is defined. It is related to the vehicle speed. The higher the speed is the large delta weight coefficient will be. If the WeightCoe is less than 50, it indicates there is no object (or object has been removed. The max WeightCoe is 100.*/
} SDGSnsDtdObjPointType;

typedef struct  {

	SDGSnsDtdObjPointType ObjPtBuf[SDG_MAX_SUPPORT_SNS_DTD_OBJ_POINT_BUF_SIZE];
	SDGObjTypeType ObjType; /* Object type indicates what kind of object it is. It can be Round, Square or Unknown object type. */
	SDG_ENUM_TYPE SnsDtLoopCnt; // Indicate how many times the sensor has detected.
	SDG_ENUM_TYPE WrIndex;

} SDGSnsDtdObjPtBufType;

typedef struct {
	// SDG_ENUM_TYPE SysStatus;
	SDG_ENUM_TYPE RegionNZone[SDG_SUPPORT_REGION_NUM];
} tParkAssistantStatusLSType;

/*************************************************************************************************************************************************
**                                                              End of file                                                                     **
*************************************************************************************************************************************************/

#endif /* SLOTPROCESSDATATYPE_H_ */
