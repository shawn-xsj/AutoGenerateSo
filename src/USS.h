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
**  $FILENAME   : USS.h $                                                                                                                       **
**                                                                                                                                              **
**  $CC VERSION : \main\94 $                                                                                                                    **
**                                                                                                                                              **
**  $DATE       : 2020-08-XX $                                                                                                                  **
**                                                                                                                                              **
**  AUTHOR      : SAIC - US Group -Engineering                                                                                                  **
**                                                                                                                                              **
**  VENDOR      : SAIC Technologies                                                                                                             **
**                                                                                                                                              **
**  DESCRIPTION : This file contains                                                                                                            **
**                - USS main function declarations                          ..                                                                  **
**                                                                                                                                              **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                                                                                        **
**                                                                                                                                              **
*************************************************************************************************************************************************/
#ifndef _USS_H_
#define _USS_H_

/*************************************************************************************************************************************************
**                                                              Includes                                                                        **
*************************************************************************************************************************************************/
#include "Platform_Types.h"
#include "APACommonType.h"

/*************************************************************************************************************************************************
**                                                             Debug Switch                                                                     **
*************************************************************************************************************************************************/

/*************************************************************************************************************************************************
**                                                              Global Macro Definitions                                                        **
*************************************************************************************************************************************************/
#define APA_SIDE_SENSOR_NUM										4
#define APA_SLOT_SUPPORT_MAX_SLOT_NUM						    3
#define APA_MAX_SUPPORT_SNS_DTD_OBJ_DIS_BUF_SIZE				5 // 25 -> 5
#define APA_SLOT_SUPPORT_SLOT_BORDER_LINE_NUM				    4  //8	// 8 * 1m = 8m....

/*************************************************************************************************************************************************
**                                                              Global Type Definitions                                                         **
*************************************************************************************************************************************************/
/*Public data structure definitions*/
#ifndef _CURBINFO_ST
#define _CURBINFO_ST
typedef struct _CurbInfo_ST
{
    uint8 gUSS_u8CurbState;
    float32 gUSS_s16CurbLineParaA;
    float32 gUSS_s16CurbLineParaB;
	float32 gUSS_s16CurbLineParaC;
}CurbInfo_ST;
#endif

#ifndef _CURBINFOFORVSS_ST
#define _CURBINFOFORVSS_ST
typedef struct _CurbInfoForVSS_ST
{
    uint8 u8CurbForVSSUpdateFlag;
    uint8 gUSS_u8VSlotSource;
    CurbInfo_ST stCurbParForVSS;
}CurbInfoForVSS_ST;
#endif


#ifndef _USSCOORD0POS_ST
#define _USSCOORD0POS_ST
typedef struct _USSCoord0PoS_ST
{
    float32 f32Xm;
	float32 f32Ym;
    float32 Arad;
}USSCoord0PoS_ST;
#endif


#ifndef _EDGEINFO_ST
#define _EDGEINFO_ST
typedef struct _EdgeInfo_ST
{
    uint8 gUSS_u8VirtualFlg;
    uint8 ObjType;
    float32 gUSS_f32PosX;
	float32 gUSS_f32PosY;
	uint8 gUSS_u8EdgeLineSts;
	float32 gUSS_s16EdgeLineParaA;
    float32 gUSS_s16EdgeLineParaB;
	float32 gUSS_s16EdgeLineParaC;
	Pose_ST stVehPosInfo;
    sint16 gUSS_s16YPosDevationMM;
}EdgeInfo_ST;
#endif

#ifndef _SLOTINFO_ST
#define _SLOTINFO_ST
typedef struct _SlotInfo_ST
{
	uint8 gUSS_u8UpdState;
	uint8 gUSS_u8ValidState;
	uint8 gUSS_u8Type;
    EdgeInfo_ST stEdge0Info;
    EdgeInfo_ST stEdge1Info;
	CurbInfo_ST stCurbInfo;
    CurbInfoForVSS_ST stCurbInfoForVSS;
}SLOTINFO_ST;
#endif

#ifndef _OBJINFO_ST
#define _OBJINFO_ST
typedef struct _ObjInfo_ST
{
    uint8 u8ObjType;
    Point_ST stObjPos[2];
}ObjInfo_ST;
#endif

#ifndef _SIDEOBJINFO_ST
#define _SIDEOBJINFO_ST
typedef struct _SideObjInfo_ST
{
    uint8 u8ObjUpdateFlag;
    ObjInfo_ST stObjInfo;
}SideObjInfo_ST;
#endif

#ifndef _USS_OUT_ST
#define _USS_OUT_ST
typedef struct _USS_Out_ST
{
    uint8 gUSS_u8State;
    SLOTINFO_ST stLeftSideSlot;
    SLOTINFO_ST stRightSideSlot;
    USSCoord0PoS_ST gUSS_Coord0Pos;
    uint8 gUSS_u8ObjPtConvertFinishSts;
	SideObjInfo_ST stLeftSideObj;
	SideObjInfo_ST stRightSideObj;
}USS_Out_ST;
#endif

typedef struct 
{
    APA_DISTANCE_TYPE APASnsDtdObjDis[APA_SIDE_SENSOR_NUM];
    APA_DISTANCE_TYPE APASnsDtdSmallObjDis[APA_SIDE_SENSOR_NUM];
	//APA_DISTANCE_TYPE APACorSnsDtdObjDis[APA_CORNER_SENSOR_NUM];
    APACarCoordinateDataCalFloatType CarCenterPt;
	UCHAR VehicleSpd; // 0 ~ 255kph,
} APASnsDtdObjDisInfoType;

typedef struct {
	// Line equation: Y = KX + B;
	// One line at least 1m.
	APALineParameterKBType LinePar;
	APA_ENUM_TYPE StartPtIndex;
	APA_ENUM_TYPE EndPtIndex;
	APA_ENUM_TYPE FitLineShapeType;//QuarterStartLinePtIndex; // 0 = Convex
	APA_DISTANCE_TYPE LineBOffsetDis; //ThreeQuarterLineEndPtIndex; // 0 = no offset.
	//APACoordinateDataCalFloatType NearestPointToCar;
	//APA_DISTANCE_TYPE LineDepth;
} APASlotBorderLineParameterType;

typedef struct  {
	APA_ENUM_TYPE SlotType;
	APA_INDEX_TYPE SlotStartIndex;
	APA_INDEX_TYPE SlotEndIndex;
	APA_DISTANCE_TYPE SlotCalDisCarToObj1;                              // for parking out, it is the rear obj dis
	APA_DISTANCE_TYPE SlotCalDisCarToObj2;                              // for parking out, it is the front obj dis
	APA_DISTANCE_TYPE SlotLengthDetected1;                              // Slot length detected by the slot process task, only used for perpendicular parking
	APA_DISTANCE_TYPE SlotLengthDetected2;                              // Slot length detected by the slot process task, only used for perpendicular parking
	APA_DISTANCE_TYPE SlotLengthDetected3;                              // Slot length detected by the slot process task, only used for perpendicular parking
	APA_DISTANCE_TYPE SlotLengthTotal;                                  // Slot length detected by the slot process task
	APA_DISTANCE_TYPE SlotDepthDetected1;                               // only used for perpendicular parking
	APA_DISTANCE_TYPE SlotDepthDetected2;                               // only used for perpendicular parking
	APA_DISTANCE_TYPE SlotDepthDetected3;                               // only used for perpendicular parking
	APA_DISTANCE_TYPE SlotLength;                                       // Slot length recalculated by setup system coordinate and use to cal the trajectory.
	APA_DISTANCE_TYPE SlotDepthParallel;
	APA_DISTANCE_TYPE SlotDepth;			                            // for parking out, it is the left object dis
	APA_DISTANCE_TYPE SubSlotDepth;			                            // for parking out, it is the right object dis
	APA_DISTANCE_TYPE DisCarToObj1ByPassingSlot;                        // for parking out, it is the left object X coordinate.
	APA_DISTANCE_TYPE DisCarToObj2ByPassingSlot;
    APA_DISTANCE_TYPE CarPassTheSlotEndPtDistance;
    APA_DISTANCE_TYPE CarPassTheSlotStartPtDistance;
    APA_DISTANCE_TYPE CarPassTheSlotDistanceTrajectoryCaled;
    APA_ENUM_TYPE CarPassTheSlotDistanceUsedToRecalTrajectoryIndex;     // 0 = use CarPassTheSlotEndPtDistance, 1 = use CarPassTheSlotStartPtDistance
	APALineParameterKBType SlotCenterLinePar;
	//APACoordinateDataCalFloatType NewSysCoordinateOriginalPoint;
	//APA_ANGLE_CAL_FLOAT_TYPE NewSysCoordinateAngle;
    APA_DISTANCE_TYPE APASlotDetectionCompensateLengthHead;
    APA_DISTANCE_TYPE APASlotDetectionCompensateLengthTail;
	APA_DISTANCE_TYPE Obj1Width;
	APA_DISTANCE_TYPE Obj2Width;
	APA_ENUM_TYPE Obj1Type; // indicate: car or pole or square obj ....
	APA_ENUM_TYPE Obj2Type;
	APA_INDEX_TYPE Obj1StartPtIndex;
	APA_INDEX_TYPE Obj1EndPtIndex;
	APA_INDEX_TYPE Obj2StartPtIndex;
	APA_INDEX_TYPE Obj2EndPtIndex;
	APA_INDEX_TYPE TrajectoryCalRequestType;
	#ifdef APA_SUPPORT_SLOT_POINT_COMPENSATE_ADJ
	BOOLEAN bSlotHeadCompensated;
	BOOLEAN bSlotTailCompensated;
	#endif
	// BOOLEAN bSlotNoiseRemoved;
	BOOLEAN bSlotCurbHasBeenRechecked;
	BOOLEAN bSlotCalConfirmed;
	BOOLEAN bSlotCalConfirmedSpeakerHasChimed;
	APA_SLOT_ID_TYPE SlotID; // To identify a slot uniq ID.
	APA_ENUM_TYPE ParkProcCarEndPosition;
	// APA_DISTANCE_TYPE SlotDepthCal;
	// APA_DISTANCE_TYPE SubSlotDepthCal;
	// APA_DISTANCE_TYPE DisCarToObj1ByPassingSlotCal;
	// APA_DISTANCE_TYPE DisCarToObj2ByPassingSlotCal;
	APA_SPEED_TYPE APAVehicleSpeedWhenSlotFound;
} APASlotParameterType;

typedef struct {
	APASlotBorderLineParameterType LineBuf[APA_SLOT_SUPPORT_SLOT_BORDER_LINE_NUM];  // 8 * 15 bytes = 120 bytes.
	APA_ENUM_TYPE LineNum; 															// indicate how many lines in the line buffer
} APASlotBorderLineInfoType;

typedef struct  {
	APASlotOutlineDataType SlotOutline;
	APASlotOutlineRearSensorDetectedDataType SlotOutlineRearSideSnsDetected;
	APASlotBorderLineInfoType BorderLineInfo;
	APA_ENUM_TYPE SlotNum;
	APA_ENUM_TYPE SlotConfirmSeq;
	//BOOLEAN RequestToRemoveSlotNum;
	//APA_ENUM_TYPE PrevSlotEndIndex;
	APASlotParameterType SlotPar[APA_SLOT_SUPPORT_MAX_SLOT_NUM];
	APASlotDetectFailCausesType SlotDtFailCause;
} APASlotInfoDataType;

typedef struct 
{
/*2.5.1  BOOLEAN Variables	****************/	
	tAPACarParFlag1Type APACommonFlags;
/*2.5.2  COMMON USE Variables	****************/
	APA_SPEED_TYPE APAVehicleSpeed; 								// Unit: m/s
	APA_ENUM_TYPE APACarParkAtLeftOrRightSide; 						// Car park at left if true other wise park at right
	APA_ENUM_TYPE APACarParkingMode; 								// Parallel or perpendicular parking.
	APACarCoordinateDataCalFloatType APACarCenterPt;
	APACarCoordinateDataCalFloatType APACarCenterPtCaledByWheelCnt;
	// APA_ENUM_TYPE APACurrentCarAngState;							// 0 -- Normal, ie. oblique line. inclined line
																	// 1 - vertical.
																	// 2 - horizontal.
	APA_ENUM_TYPE APAState;
    APASnsDtdObjDisInfoType APASnsDtdObjDisInfoBuf[APA_MAX_SUPPORT_SNS_DTD_OBJ_DIS_BUF_SIZE];
    APA_ENUM_TYPE APASnsDtdObjDisInfoBufReadIndex;
    APA_ENUM_TYPE APASnsDtdObjDisInfoBufWriteIndex;
	APA_ENUM_TYPE APARequestToMirrorSlot;
	APA_INDEX_TYPE APARightSlotDataIndex;
	APA_INDEX_TYPE APALeftSlotDataIndex;
	
////2.5.2.1 APARxSteeringWheelAngleMsgProcess
////2.5.2.2 calculate Carpos
/*2.5.3  SEARCHING SLOT USE Variables	****************/
	APASlotInfoDataType Slot[APA_SLOT_SUPPORT_SEARCHING_SLOT_SENSOR_NUM]; 	// modified BY  DSH 2012.2.13  //USS
	APA_MS_TIME_TYPE SlotPEStartSlotCheckTimer;
	APA_DISTANCE_TYPE SlotCarEndPosXPrevValue; 								// Use for perpendicular parking: car end pos correction to save the value when the car end pos angle is 90deg.
	APA_SLOT_ID_TYPE SlotPrevID; 											// To identify a slot uniq ID.	
/*2.5.4  TRAJECTORY CALCULATION USE Variables	********/
	APACarCoordinateDataCalFloatType TrajCalCarEndPos;	
	APALineParameterABCType TrajCalCarEndPosLine;	
	APACoordinateDataCalFloatType TrajCalObj1Pos;
	APACoordinateDataCalFloatType TrajCalObj2Pos;
	APALineParameterKBType TrajCalSlotRightSideLine;
	APALineParameterKBType TrajCalSlotLeftSideLine;
	APA_DISTANCE_TYPE TrajCalDistanceBetweenOriginalPtAndObj2;  			//parkin
	// APA_DISTANCE_CAL_FLOAT_TYPE TrajCalCarParkingTrajectoryOuterTurningCircleMaxX; //parkin
	// APA_ENUM_TYPE TrajCalCarParkingCurrentStepIndex;//parkin
	APACarCoordinateDataCalFloatType TrajCalCarCenterPtCal;
	APA_ENUM_TYPE TrajCalCurrentCalSlotIndex; //parkin
	APA_DISTANCE_TYPE TrajCalObj2RisingShapeWidth;
	APA_ENUM_TYPE TrajCalAPATrajectoryCalResult;
	APA_ANGLE_TYPE ParkProcAPATargetSteeringWheelAngle;
	APA_ENUM_TYPE TrajCalCarParkAtLeftOrRightSide;
	// BOOLEAN TrajCalTheEndPosXHasBeenReCaled;
	// BOOLEAN TrajCalCurbDetected;
	APA_ENUM_TYPE ParkProcCarInTheSlotEndPosAngAchievedDriveForwardAndBackwardCnt;
	APASnsDtdNearestObjDisInfoType ParkProcSnsDtNearestDis[PA_SYS_NUM];
	// APA_DISTANCE_TYPE ParkProcRearSnsDtdNearestDis;   // delete3
	APA_ENUM_TYPE ParkProcCarEndPosition;
	APA_DISTANCE_TYPE ParkProcCarEndPositionTol; // end pos tolerance
	APA_DISTANCE_TYPE ParkProcSafetyDisToObjAtFront;   // delete3 TBD
	APA_DISTANCE_TYPE ParkProcSafetyDisToObjAtRear;  // delete3 TBD
#ifdef APA_SUPPORT_STATE_DEGRADATION		// added by zhx 20130203
	tAPAStateDegradationType  APAStateDegradation;
#endif
}APACarParameterInfoType;

/*************************************************************************************************************************************************
**                                                              Global Variable Declarations                                                    **
*************************************************************************************************************************************************/
extern USS_Out_ST gUSS_stOut;
extern APACarParameterInfoType USSPar;
extern APACoordinateDataCalFloatType TransCenterPt;
extern APA_ANGLE_CAL_FLOAT_TYPE TransCenterAng;
extern APACoordinateDataCalFloatType CenterPtBackup1;
extern APA_ANGLE_CAL_FLOAT_TYPE CenterAngBackup1;
extern APACoordinateDataCalFloatType CenterPtBackup2;
extern APA_ANGLE_CAL_FLOAT_TYPE CenterAngBackup2;
extern APACoordinateDataCalFloatType CenterPtBackup3;
extern APA_ANGLE_CAL_FLOAT_TYPE CenterAngBackup3;
extern APACoordinateDataCalFloatType Edge0BkInUSS[2];
extern APACoordinateDataCalFloatType Edge1BkInUSS[2];
extern APA_ANGLE_TYPE AngleBK[2];
/*************************************************************************************************************************************************
**                                                              Global Function Declarations                                                    **
*************************************************************************************************************************************************/
// extern void USS(void);
 void USS();
void APASlotProcResetSlotBufAndFilterBufData();

/*************************************************************************************************************************************************
**                                                              Global Inline Function Definitions                                              **
*************************************************************************************************************************************************/

/*************************************************************************************************************************************************
**                                                              End of file                                                                     **
*************************************************************************************************************************************************/

#endif /*_USS_H_*/
