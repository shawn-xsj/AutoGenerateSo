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
**  $FILENAME   : SlotProcessSubFunction.c $                                                                                                    **
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
**                - USS slot process sub function definition                ..                                                                  **
**                                                                                                                                              **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                                                                                        **
**                                                                                                                                              **
*************************************************************************************************************************************************/

/*************************************************************************************************************************************************
**                                                     Includes
*************************************************************************************************************************************************/
#include "SlotProcessSubFunction.h"
#include "SlotProcess.h"
#include "USS.h"
#include "USSSubFunction.h"
#include "APACommonFunctions.h"
#include "APACalibration.h"
/*************************************************************************************************************************************************
**                                                     Imported Compiler Switch Check                                                           **
*************************************************************************************************************************************************/
/**/

/*************************************************************************************************************************************************
**                                                     Global Constant Definitions                                                              **
*************************************************************************************************************************************************/
#define ALG_START_SEC_CONST_32BIT
#include "IS31_UserMemMap.h"

SDGCalibrationDataType const SDGCal = {

    30,               // SDG_ENUM_TYPE SDGObjDtDisapearDelayLoopCnt; // 30 * 35ms = 1.05s.
    10.0 / 3.6,       // 10 km/h -> m/s , SDG_SPEED_TYPE SDG_ThresholdDesactivationSpeed;
    8.0 / 3.6,        // 8 km/h -> m/s , SDG_SPEED_TYPE SDG_ThresholdActivationSpeed;
    300,              // 30cm, SDG_DISTANCE_TYPE SDG_minDistanceWarning;
    0.1 * PI / 180.0, // 0.1 deg, 	SDG_ANGLE_TYPE SDG_StartCheckObjectSteeringAngle;
    300,              // 30cm, SDG_DISTANCE_TYPE SDGSafetyDisWhenCarIsTurning;

    200,   // 20cm, SDG_DISTANCE_TYPE SDGDtObjMinDis;
    5000,  // 5m, SDG_DISTANCE_TYPE SDGDtObjMaxDis;
    1000,  // 1m SDG_DISTANCE_TYPE SDGSnsDtRoundObjMaxDeltaDis;
    100,   // 10cm, SDG_DISTANCE_TYPE SDGSnsDtRoundObjMinDeltaDis;
    100,   // 10cm, SDG_DISTANCE_TYPE SDGSnsDtSQuareObjMaxDeltaDis;
    12000, // 12m, SDG_DISTANCE_TYPE SDGTrackingAreaDrivingDirection;
    // SDGRegionAndZoneDivisionInfoType SDGRegionAndZoneDivisionInfo;
    {
        // typedef struct  {
        // SDG_DISTANCE_TYPE ZoneDivisionLineX[SDG_SUPPORT_ZONE_NUM + 1];
        // It is the relative value to the car coordinate system (Rear Axis Center point). unit: mm
        // Zone 0, Zone 1,    Zone 2,          Zone3,                 Zone4, Zone5, Zone6, Zone7,Zone8...Zone15
        // SKODA,{  900,    900 + 200, 900 + 200 + 200, 900 + 200 + 200 + 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {400, 950 + 200, 950 + 200 + 200, 950 + 200 + 200 + 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // Escape.
                                                                                                      // SDG_DISTANCE_TYPE ZoneDivisionHysteresisDis;
        150, // 10cm
        3,   // SDG_ENUM_TYPE ZoneNum; // Support up to 15 zone.
           // SDG_DISTANCE_TYPE RegionDivisionLineY[SDG_SUPPORT_REGION_NUM + 1];
           // It is the relative value to the car coordinate system (Rear Axis Center point). unit: mm
           // Region 0, Region 1, Region 2, Region 3,
           // skoda, {3400,       2000,      600,     - 800},
        {3300, 1900, 600, -800},
        // SDG_DISTANCE_TYPE RegionDivisionHysteresisDis;
        200, // 20cm
        3    // SDG_ENUM_TYPE RegionNum; // Support up to 3 region.
             //}  SDGRegionAndZoneDivisionInfoType;
    },

#ifdef SDG_SUPPORT_PC_DEMO
    // SDG_DISTANCE_TYPE SDGHFOVWidthBySeg[SDG_SENSOR_HFOV_DIVIDED_SEG_NUM];
    /*
    unit: mm
    0-250, 500, 750, 1000,1250,1500,1750,2000,2250,2500,2750,3000,3250,3500,3750,4000,4250,4500,4750,5000
    */
    {800, 1000, 1000, 1000, 1000, 1000, 1000, 800, 600, 600, 600, 600, 500, 400, 400, 400, 400, 400, 400, 400},

    // SDG_DISTANCE_TYPE SDGHFOVCompensateDisByObjTypeAndSeg[SDG_SUPPORT_OBJ_TYPE_NUM][SDG_SENSOR_HFOV_DIVIDED_SEG_NUM];
    {
        // typedef enum {
        //  SDG_OBJ_TYPE_UNKNOWN = 0,
        /*
        unit: mm
         0-250, 500, 750, 1000,1250,1500,1750,2000,2250,2500,2750,3000,3250,3500,3750,4000,4250,4500,4750,5000
        */
        {350, 400, 400, 400, 400, 400, 400, 350, 300, 300, 300, 300, 300, 200, 200, 200, 200, 200, 200, 200},
        //  SDG_OBJ_TYPE_ROUND,
        /*
        unit: mm
         0-250, 500, 750, 1000,1250,1500,1750,2000,2250,2500,2750,3000,3250,3500,3750,4000,4250,4500,4750,5000
        */
        {400, 500, 500, 500, 500, 500, 450, 400, 300, 300, 300, 300, 300, 200, 200, 200, 200, 200, 200, 200},
        //  SDG_OBJ_TYPE_SQUARE,
        /*
        unit: mm
         0-250, 500, 750, 1000,1250,1500,1750,2000,2250,2500,2750,3000,3250,3500,3750,4000,4250,4500,4750,5000
        */
        {350, 400, 400, 400, 400, 400, 400, 350, 300, 300, 300, 300, 300, 200, 200, 200, 200, 200, 200, 200},
        //} SDGObjTypeType;
    },
#else
    // SDG_DISTANCE_TYPE SDGHFOVWidthBySeg[SDG_SENSOR_HFOV_DIVIDED_SEG_NUM];
    /*
    unit: mm
    0-250, 500, 750, 1000,1250,1500,1750,2000,2250,2500,2750,3000,3250,3500,3750,4000,4250,4500,4750,5000
    */
    {400, 600, 600, 600, 600, 600, 500, 400, 300, 300, 300, 300, 250, 200, 200, 200, 200, 200, 200, 200},

    // SDG_DISTANCE_TYPE SDGHFOVCompensateDisByObjTypeAndSeg[SDG_SUPPORT_OBJ_TYPE_NUM][SDG_SENSOR_HFOV_DIVIDED_SEG_NUM];
    {
        // typedef enum {
        //  SDG_OBJ_TYPE_UNKNOWN = 0,
        /*
        unit: mm
         0-250, 500, 750, 1000,1250,1500,1750,2000,2250,2500,2750,3000,3250,3500,3750,4000,4250,4500,4750,5000
        */
        {200, 300, 300, 300, 300, 300, 250, 200, 150, 150, 150, 150, 125, 100, 100, 100, 100, 100, 100, 100},
        //  SDG_OBJ_TYPE_ROUND,
        /*
        unit: mm
         0-250, 500, 750, 1000,1250,1500,1750,2000,2250,2500,2750,3000,3250,3500,3750,4000,4250,4500,4750,5000
        */
        {200, 400, 400, 400, 400, 400, 300, 250, 200, 200, 200, 200, 150, 100, 100, 100, 100, 100, 100, 100},
        //  SDG_OBJ_TYPE_SQUARE,
        /*
        unit: mm
         0-250, 500, 750, 1000,1250,1500,1750,2000,2250,2500,2750,3000,3250,3500,3750,4000,4250,4500,4750,5000
        */
        {200, 200, 200, 200, 200, 200, 200, 150, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0},
        //} SDGObjTypeType;
    },
#endif

    60.0 * PI / 180.0, // 60 deg. SDG_ANGLE_TYPE SDGDrvBkPtKeepMaxDeltaCarAng;
    1000, // 1m, SDG_DISTANCE_TYPE SDGKeepObjectPointDis; #define SDG_KEEP_OBJECT_POINT_DIS	(1000) // 1m, def: 2m, It is calculate with DeltaX +
          // DeltaY,
    2500, // 2.5m, SDG_DISTANCE_TYPE SDGKeepNoObjectPointDis;
    600,  // 60cm, SDG_DISTANCE_TYPE SDGSnsDtObjRegionAreaWidth;
    500,  // 50cm, SDG_DISTANCE_TYPE SDGKeepObjPtMinDeltaDtDis;
    300,  // 50cm, SDG_DISTANCE_TYPE SDGSnsDtObjRegardedAsSameObjTolDis;
    50,   // 50%, UCHAR SDGSnsDtObjProbalilityPercentage;

    // for perpendicular parking slot correction filter 2014 08 21
    700,  // SDG_DISTANCE_TYPE SDGPointCanBeRemovedContiguousPointMinDisP;
    200,  // SDG_DISTANCE_TYPE SDGPointCanBeRemovedContiguousPointMinDisP2;
    50,   // 25, //SDG_DISTANCE_TYPE SDGSamplePointUpdateSmallDeltaLen;
    200,  // SDG_DISTANCE_TYPE SDGSamplePointUpdateSmallDeltaLen2;
    2,    // 1, //SDG_SLOT_PT_SLOPE_TYPE SDGSamplePointCanBeRemovedMaxObjPtDeltaSlope;
    350,  // SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedRegardAsNoiseMinObjWidth;
    1000, // SDG_DISTANCE_TYPE SDGSamplePointNoisePtStartCheckBkObjWidth;
    500,  // SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedCheckMinNoObjWidth;
    30,   // SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedHeadOrTailMaxDeltaObjDis;
    17,   // SDG_SLOT_PT_SLOPE_TYPE SDGSamplePointNoisePtCanBeRemovedHeadOrTailMaxSlope;
    -70,  // SDG_SLOT_PT_SLOPE_TYPE SDGSamplePointNoisePtCanBeRemovedHeadOrTailMinSlope;
    30,   // SDG_SLOT_PT_SLOPE_TYPE SDGSamplePointAllowedMaxDeltaSlope;
    500,  // SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedCheckStartHeadWidth;
    400,  // SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedCheckNoiseWidth;
    300,  // SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedMaxDis;
    250,  // SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedSameObjTol;
    500,  // SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedCheckNoiseToObjWidth;
    2,    // SDG_ENUM_TYPE SDGSamplePointNoisePtCanBeRemovedMinSameObjPtNum;
    500,  // SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedMinObjWidth;
    25,   // SDG_ENUM_TYPE SDGSamplePointNoisePtCanBeRemovedMaxNoiseWidthPercentage;
    300,  // SDG_DISTANCE_TYPE SDGSamplePointNoisePtRegardedAsSameObjMaxDeltaObjDis;
    500,  // SDG_DISTANCE_TYPE SDGSamplePointNoisePtRegardedAsSameObjMinObjWidth;
    1000, // SDG_DISTANCE_TYPE SDGSamplePointUpdateLongDeltaLen;
    8000, // SDG_DISTANCE_TYPE SDGSamplePointCanBeRemovedMaxObjDis;
    6,    // SDG_ENUM_TYPE SDGSamplePointNoisePtCanBeRemovedMinObjPtOutOfTolNum;
    2,    // SDG_ENUM_TYPE SDGSamplePointNoisePtCanBeRemovedMinNoObjPtWitinNoiseNum;
    4     // SDG_ENUM_TYPE SDGSamplePointNoisePtCanBeRemovedMinNoObjPtTotalNum;

};

#define ALG_STOP_SEC_CONST_32BIT
#include "IS31_UserMemMap.h"

#define ALG_START_SEC_VAR_32BIT
#include "IS31_UserMemMap.h"

//SDGObjInfoType SDGObjInfo;
SDGOperatingStateType SDGState;
tByteBitType APAObjDisUpdateFlag;

/*************************************************************************************************************************************************
**                                                     Private  Constant Definitions                                                            **
*************************************************************************************************************************************************/
tAPAWordBitType _APACommonFlag00;
tSDGBooleanType SDGBooleanFlags;
SDG_DISTANCE_TYPE SDGKeepNoObjPtDis;
SDG_SPEED_TYPE SDGVehicleSpeed;
//SDGSnsDtdObjPtBufType SDGSnsDtdObjPtBuf[SDG_SUPPORT_SDG_SNS_NUM];
tParkAssistantStatusLSType SDGParkAssistantLeftStatusLS;
tParkAssistantStatusLSType SDGParkAssistantRightStatusLS;
SDG_DISTANCE_TYPE SDGSnsDtObjRegardedAsSameObjTolDis;
SDG_DISTANCE_TYPE SDGSnsDtObjRegionWidth;
SDG_WEIGHT_COEFFICIENT_TYPE SDGSnsDtObjProbalilityPercentage;
SDG_DISTANCE_TYPE SDGPointCanBeRemovedContiguousPointMinDisP;
SDG_DISTANCE_TYPE SDGPointCanBeRemovedContiguousPointMinDisP2;
SDG_SLOT_PT_SLOPE_TYPE SDGSamplePointAllowedMaxDeltaSlope;
SDG_SLOT_PT_SLOPE_TYPE SDGSamplePointCanBeRemovedMaxObjPtDeltaSlope;

SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedCheckMinNoObjWidth;
SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedCheckNoiseToObjWidth;
SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedCheckNoiseWidth;
SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedCheckStartHeadWidth;
SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedHeadOrTailMaxDeltaObjDis;
SDG_SLOT_PT_SLOPE_TYPE SDGSamplePointNoisePtCanBeRemovedHeadOrTailMaxSlope;
SDG_SLOT_PT_SLOPE_TYPE SDGSamplePointNoisePtCanBeRemovedHeadOrTailMinSlope;
SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedMaxDis;
SDG_ENUM_TYPE SDGSamplePointNoisePtCanBeRemovedMaxNoiseWidthPercentage;
SDG_ENUM_TYPE SDGSamplePointNoisePtCanBeRemovedMinObjPtOutOfTolNum;
SDG_ENUM_TYPE SDGSamplePointNoisePtCanBeRemovedMinNoObjPtWitinNoiseNum;
SDG_ENUM_TYPE SDGSamplePointNoisePtCanBeRemovedMinNoObjPtTotalNum;
SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedMinObjWidth;
SDG_ENUM_TYPE SDGSamplePointNoisePtCanBeRemovedMinSameObjPtNum;
SDG_DISTANCE_TYPE SDGSamplePointNoisePtRegardedAsSameObjMaxDeltaObjDis;
SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedSameObjTol;
SDG_DISTANCE_TYPE SDGSamplePointNoisePtStartCheckBkObjWidth;
SDG_DISTANCE_TYPE SDGSamplePointUpdateSmallDeltaLen;
SDG_DISTANCE_TYPE SDGSamplePointUpdateSmallDeltaLen2;
SDG_DISTANCE_TYPE SDGSamplePointNoisePtCanBeRemovedRegardAsNoiseMinObjWidth;
SDG_DISTANCE_TYPE SDGSamplePointNoisePtRegardedAsSameObjMinObjWidth;

SDG_ENUM_TYPE SDGSnsIndexConvertToSysSnsIndex[SDG_SUPPORT_SDG_SNS_NUM] = {
    // typedef enum {
    APA_FRS_SNS_INDEX,
    APA_FLS_SNS_INDEX,
    APA_RRS_SNS_INDEX,
    APA_RLS_SNS_INDEX
    //} SDGSnsIndexType;
};

#define ALG_STOP_SEC_VAR_32BIT
#include "IS31_UserMemMap.h"
/*************************************************************************************************************************************************
**                                                     Global Variable Definitions                                                              **
*************************************************************************************************************************************************/

/*************************************************************************************************************************************************
**                                                     Private  Variable Definitions                                                            **
*************************************************************************************************************************************************/
/**/

/*************************************************************************************************************************************************
**                                                     Private Macro Definitions                                                                **
*************************************************************************************************************************************************/

/*************************************************************************************************************************************************
**                                                     Private Function Definitions                                                             **
*************************************************************************************************************************************************/

/*************************************************************************************************************************************************
**                                                     Global Function Definitions                                                              **
*************************************************************************************************************************************************/
#define ALG_START_SEC_CODE
#include "IS31_UserMemMap.h"


/*************************************************************************************************************************************************
** Syntax :  void USS(void)                                                                                                                     **
**                                                                                                                                              **
** Service ID:   : NA                                                                                                                           **
**                                                                                                                                              **
** Sync/Async:   : Synchronous                                                                                                                  **
**                                                                                                                                              **
** Reentrancy:   : Non Reentrant                                                                                                                **
**                                                                                                                                              **
** Parameters (in): none                                                                                                                        **
**                                                                                                                                              **
** Parameters (out): none                                                                                                                       **
**                                                                                                                                              **
** Return value: none                                                                                                                           **
**                                                                                                                                              **
** Description : ..                                                                                                                             **
*************************************************************************************************************************************************/
void APATrajCalDistanceBetweenOriginalPtAndObj2(APA_ENUM_TYPE ParkingModeIndex) {
  // ParkingModeIndex: 0: parallel
  //				  1: Perpendicular
  // TrajCalDistanceBetweenOriginalPtAndObj2: > 0 means there are more safety space between the
  // original point and obj2.

  APA_INDEX_TYPE i, j;
  APACoordinateDataCalFloatType PtTemp1, PtTemp2;
  APASlotOutlineCoordinateDataType *pMainSlot;
  APA_DISTANCE_CAL_FLOAT_TYPE fDis, X1, X2, Y1, Y2;

  APASlotParameterType *pMainSlotPar;
  APA_INDEX_TYPE SlotEndIndex, SlotStartIndex;
  APA_INDEX_TYPE MinYPtIndex, MaxYPtIndex, YZeroPtIndex1, YZeroPtIndex2;
  APA_INDEX_TYPE LeftPtIndex, RightPtIndex;
  APA_DISTANCE_TYPE PtMaxX, PtMidX;
  APALineParameterABCType LineTemp;
  APA_ENUM_TYPE Obj2PtIndex, Obj2RisingShapeStartIndex;

  // APA_DISTANCE_CAL_FLOAT_TYPE

  USSPar.TrajCalObj2RisingShapeWidth = 0; // from Obj2 start point index to Y = 0 distance.

  if (USSPar.APACommonFlags.Bits.bSlotProcSlotObj2Exist == FALSE) {
    // obj2 does not exist.
    USSPar.TrajCalDistanceBetweenOriginalPtAndObj2 = APACal.APATrajCalMaxOriginalPtToObj2Dis[ParkingModeIndex];
    return;
  }

  USSPar.TrajCalDistanceBetweenOriginalPtAndObj2 = 0;
  pMainSlot                                         = &USSPar.Slot[USSPar.APARightSlotDataIndex].SlotOutline.Lane;
  pMainSlotPar                                      = &USSPar.Slot[USSPar.APARightSlotDataIndex].SlotPar[USSPar.TrajCalCurrentCalSlotIndex];
  SlotStartIndex                                    = pMainSlotPar->SlotStartIndex;
  SlotEndIndex                                      = pMainSlotPar->SlotEndIndex;

  if (pMainSlot->DisFromCarToObj[SlotEndIndex] == NO_OBJ_DISTANCE) {
    // data error
    return;
  }

  MinYPtIndex   = SlotEndIndex;
  i             = MinYPtIndex;
  YZeroPtIndex1 = APA_SLOT_SUPPORT_FRONT_SIDE_MAX_SAMPLE_POINT_NUM; // min Y > 0 point.
  YZeroPtIndex2 = APA_SLOT_SUPPORT_FRONT_SIDE_MAX_SAMPLE_POINT_NUM; // Max Y < 0 Point.
  MaxYPtIndex   = SlotEndIndex;
  j             = SlotStartIndex + 2;
  while (i > j) {
    if (pMainSlot->ObjPt[i].y < -1500) {
      break;
    }
    if (pMainSlot->DisFromCarToObj[i] != NO_OBJ_DISTANCE) {
      if (pMainSlot->ObjPt[i].x > 600) {
        // Over 60cm.
        if (pMainSlot->ObjPt[i].x < 1000) {
          MinYPtIndex = i;
        }
        break;
      }
      MinYPtIndex = i;
      if (pMainSlot->ObjPt[i].y >= 0) {
        YZeroPtIndex1 = i;
      } else if (YZeroPtIndex2 == APA_SLOT_SUPPORT_FRONT_SIDE_MAX_SAMPLE_POINT_NUM) {
        YZeroPtIndex2 = i;
      }
    }
    i--;
  }

  j = pMainSlot->ObjPtCnt;

  for (i = SlotEndIndex + 1; i < j; i++) {
    if (pMainSlot->ObjPt[i].y > 800) {
      break;
    }
    if (pMainSlot->DisFromCarToObj[i] != NO_OBJ_DISTANCE) {
      if (pMainSlot->ObjPt[i].x <= 0) {
        if ((YZeroPtIndex2 != APA_SLOT_SUPPORT_FRONT_SIDE_MAX_SAMPLE_POINT_NUM) &&
            (YZeroPtIndex1 == APA_SLOT_SUPPORT_FRONT_SIDE_MAX_SAMPLE_POINT_NUM)) {
          if ((pMainSlot->ObjPt[i].y > (-pMainSlot->ObjPt[i].x)) && (pMainSlot->ObjPt[i].y > 0)) {
            YZeroPtIndex1 = i;
          }
        }
        break;
      }
      MaxYPtIndex = i;
      if (pMainSlot->ObjPt[i].y < 0) {
        YZeroPtIndex2 = i;
      } else if (YZeroPtIndex1 == APA_SLOT_SUPPORT_FRONT_SIDE_MAX_SAMPLE_POINT_NUM) {
        YZeroPtIndex1 = i;
      }
    }
  }
  Obj2PtIndex = APA_SLOT_SUPPORT_FRONT_SIDE_MAX_SAMPLE_POINT_NUM;
  if (YZeroPtIndex1 == APA_SLOT_SUPPORT_FRONT_SIDE_MAX_SAMPLE_POINT_NUM) {
    if (YZeroPtIndex2 == APA_SLOT_SUPPORT_FRONT_SIDE_MAX_SAMPLE_POINT_NUM) {
      // Use the slot end pt index as the reference point.
      Obj2PtIndex = SlotEndIndex;
    } else {
      j             = pMainSlot->ObjPtCnt - 1;
      YZeroPtIndex1 = YZeroPtIndex2;
      i             = YZeroPtIndex1;
      while (i < j) {
        i++;
        if (pMainSlot->DisFromCarToObj[i] != NO_OBJ_DISTANCE) {
          if (pMainSlot->ObjPt[YZeroPtIndex1].x > pMainSlot->ObjPt[i].x) {
            YZeroPtIndex1 = i;
          }
          if (pMainSlot->ObjPt[i].y > 300) {
            break;
          }
        }
      }
      Obj2PtIndex = YZeroPtIndex1;
    }
  } else {
    PtMaxX = pMainSlot->ObjPt[YZeroPtIndex1].x;
    if ((YZeroPtIndex1 == YZeroPtIndex2) || (YZeroPtIndex2 == APA_SLOT_SUPPORT_FRONT_SIDE_MAX_SAMPLE_POINT_NUM)) {
      // PtMaxX = pMainSlot->ObjPt[YZeroPtIndex1].x;
    } else {
      PtTemp1.x = pMainSlot->ObjPt[YZeroPtIndex1].x;
      PtTemp1.y = pMainSlot->ObjPt[YZeroPtIndex1].y;
      PtTemp2.x = pMainSlot->ObjPt[YZeroPtIndex2].x;
      PtTemp2.y = pMainSlot->ObjPt[YZeroPtIndex2].y;
      if (APATrajCalLineParABCbyTwoPoints(PtTemp1, PtTemp2, &LineTemp) == TRUE) {
        if ((LineTemp.LineType == APALineIsIncline) && (LineTemp.A != 0)) {
          fDis   = -LineTemp.C / LineTemp.A;
          PtMaxX = (APA_DISTANCE_TYPE)fDis;
        } else {
          // PtMaxX = pMainSlot->ObjPt[YZeroPtIndex1].x;
        }
      } else {
        // PtMaxX = pMainSlot->ObjPt[YZeroPtIndex1].x;
      }
    }
    PtMidX       = PtMaxX / 2;
    RightPtIndex = YZeroPtIndex1;
    LeftPtIndex  = RightPtIndex;
    if (MaxYPtIndex <= RightPtIndex) {
      MaxYPtIndex = RightPtIndex;
    } else {
      if (pMainSlot->ObjPt[RightPtIndex].x < pMainSlot->ObjPt[MaxYPtIndex].x) {
        MaxYPtIndex = RightPtIndex;
      } else {
        LeftPtIndex = MaxYPtIndex;
      }
    }
    for (i = YZeroPtIndex1 + 1; i < MaxYPtIndex; i++) {
      if (pMainSlot->DisFromCarToObj[i] != NO_OBJ_DISTANCE) {
        if (pMainSlot->ObjPt[i].x > PtMidX) {
          RightPtIndex = i;
        } else {
          if (pMainSlot->ObjPt[i].x < pMainSlot->ObjPt[RightPtIndex].x) {
            LeftPtIndex = i;
          }
          break;
        }
      }
    }

    if (pMainSlot->ObjPt[RightPtIndex].x < 0) {
      // ?? Data error, Code should never reach
      // regarded as the cal pt.
      Obj2PtIndex = RightPtIndex;
    } else {
      // Ok.  Obj2 corner is at first phase

      if (LeftPtIndex == RightPtIndex) {
        // Same index.
        if (pMainSlot->ObjPt[RightPtIndex].x > PtMidX) {
          i = pMainSlot->ObjPtCnt - 1;
          while (LeftPtIndex < i) {
            LeftPtIndex++;
            if (pMainSlot->DisFromCarToObj[LeftPtIndex] != NO_OBJ_DISTANCE) {
              break;
            }
          }
        } else {
          while (LeftPtIndex > SlotStartIndex) {
            LeftPtIndex--;
            if (pMainSlot->DisFromCarToObj[LeftPtIndex] != NO_OBJ_DISTANCE) {
              break;
            }
          }
        }
        if (pMainSlot->DisFromCarToObj[LeftPtIndex] == NO_OBJ_DISTANCE) {
          // ?? data error.
          // regarded as the cal pt.
          Obj2PtIndex = RightPtIndex;
        }
      } else {
      }

      if (Obj2PtIndex == APA_SLOT_SUPPORT_FRONT_SIDE_MAX_SAMPLE_POINT_NUM) {
        if (RightPtIndex > LeftPtIndex) {
          i            = RightPtIndex;
          RightPtIndex = LeftPtIndex;
          LeftPtIndex  = i;
        }
        if (pMainSlot->ObjPt[RightPtIndex].y > pMainSlot->ObjPt[LeftPtIndex].y) {
          // Data error ??
          return;
        } else {

          if (pMainSlot->ObjPt[RightPtIndex].x < pMainSlot->ObjPt[LeftPtIndex].x) {
            LeftPtIndex = RightPtIndex;
            if (pMainSlot->ObjPt[RightPtIndex].y < 0) {
              // ?? data error ??
              return;
            }
            if (pMainSlot->ObjPt[LeftPtIndex].x < 0) {
              // regarded as the cal pt.
              Obj2PtIndex = RightPtIndex;
            } else {
              j = SlotStartIndex + 2;
              i = LeftPtIndex;
              while (i > j) {
                i--;
                if (pMainSlot->ObjPt[i].y < -1500) {
                  break;
                }
                if (pMainSlot->DisFromCarToObj[i] != NO_OBJ_DISTANCE) {
                  if ((pMainSlot->ObjPt[i].x > pMainSlot->ObjPt[LeftPtIndex].x) && (pMainSlot->ObjPt[i].x < 1000)) {
                    RightPtIndex = i;
                    break;
                  }
                }
              }
              if (LeftPtIndex == RightPtIndex) {
                // Can not found.
                // Data error ??
                return;
              }
            }
          }
        }
        if (Obj2PtIndex == APA_SLOT_SUPPORT_FRONT_SIDE_MAX_SAMPLE_POINT_NUM) {
          if (((pMainSlot->ObjPt[RightPtIndex].x < PtMidX) && (pMainSlot->ObjPt[RightPtIndex].x < (pMainSlot->ObjPt[RightPtIndex].y - 50))) ||
              ((pMainSlot->ObjPt[RightPtIndex].x < PtMaxX) && (pMainSlot->ObjPt[LeftPtIndex].y > (400)))) {
            j = SlotStartIndex + 2;
            i = RightPtIndex;
            while (i > j) {
              i--;
              if (pMainSlot->ObjPt[i].y < -500) {
                break;
              }
              if (pMainSlot->DisFromCarToObj[i] != NO_OBJ_DISTANCE) {
                if ((pMainSlot->ObjPt[i].x > PtMidX) && (pMainSlot->ObjPt[i].x < 1000) &&
                    (pMainSlot->ObjPt[i].y < pMainSlot->ObjPt[RightPtIndex].y) && (pMainSlot->ObjPt[LeftPtIndex].y > (-pMainSlot->ObjPt[i].y))) {
                  LeftPtIndex  = RightPtIndex;
                  RightPtIndex = i;
                  break;
                }
              }
            }
          }
          PtTemp1.x = pMainSlot->ObjPt[RightPtIndex].x;
          PtTemp1.y = pMainSlot->ObjPt[RightPtIndex].y;
          PtTemp2.x = pMainSlot->ObjPt[LeftPtIndex].x;
          PtTemp2.y = pMainSlot->ObjPt[LeftPtIndex].y;
          if (APATrajCalLineParABCbyTwoPoints(PtTemp1, PtTemp2, &LineTemp) == FALSE) {
            // data error ??
            return;
          }
          PtTemp1.x                                         = 0;
          PtTemp1.y                                         = 0;
          fDis                                              = APATrajCalGetPointToLineDis(PtTemp1, LineTemp);
          USSPar.TrajCalDistanceBetweenOriginalPtAndObj2 = (APA_DISTANCE_TYPE)fDis;
        }
      }
    }
  }

  if (Obj2PtIndex != APA_SLOT_SUPPORT_FRONT_SIDE_MAX_SAMPLE_POINT_NUM) {
    if (pMainSlot->ObjPt[Obj2PtIndex].x < 0) {
      // Obj2Pt is at left side.
      if (pMainSlot->ObjPt[Obj2PtIndex].y < 150) {
        j = pMainSlot->ObjPtCnt - 1;
        while (Obj2PtIndex < j) {
          if (pMainSlot->ObjPt[Obj2PtIndex].y >= 150) {
            break;
          }
          if (pMainSlot->DisFromCarToObj[Obj2PtIndex] != NO_OBJ_DISTANCE) {
            if (USSPar.TrajCalDistanceBetweenOriginalPtAndObj2 > pMainSlot->ObjPt[Obj2PtIndex].x) {
              USSPar.TrajCalDistanceBetweenOriginalPtAndObj2 = pMainSlot->ObjPt[Obj2PtIndex].x;
            }
          }
          Obj2PtIndex++;
        }
      } else {
        USSPar.TrajCalDistanceBetweenOriginalPtAndObj2 = pMainSlot->ObjPt[Obj2PtIndex].x;
      }
    } else {
      if (pMainSlot->ObjPt[Obj2PtIndex].y < 0) {
        j = pMainSlot->ObjPtCnt - 1;
        i = Obj2PtIndex;
        while (i < j) {
          i++;
          if (pMainSlot->DisFromCarToObj[i] != NO_OBJ_DISTANCE) {
            if (pMainSlot->ObjPt[i].y >= 150) {
              break;
            }
            if (pMainSlot->ObjPt[i].x < pMainSlot->ObjPt[Obj2PtIndex].x) {
              Obj2PtIndex = i;
            }
          }
        }
        if (Obj2PtIndex >= j) {
          // Data error ??
          return;
        }
      } else {
        // Ok phase four.
      }
      if (pMainSlot->ObjPt[Obj2PtIndex].y > 0) {
        PtTemp1.x                                         = 0;
        PtTemp1.y                                         = 0;
        PtTemp2.x                                         = pMainSlot->ObjPt[Obj2PtIndex].x;
        PtTemp2.y                                         = pMainSlot->ObjPt[Obj2PtIndex].y;
        fDis                                              = APATrajCalGetTwoPointDisFloat(PtTemp1, PtTemp2);
        USSPar.TrajCalDistanceBetweenOriginalPtAndObj2 = (APA_DISTANCE_TYPE)fDis;
      } else {
        USSPar.TrajCalDistanceBetweenOriginalPtAndObj2 = (APA_DISTANCE_TYPE)pMainSlot->ObjPt[Obj2PtIndex].x;
      }
    }
  }

  if ((pMainSlotPar->Obj2StartPtIndex < pMainSlot->ObjPtCnt) && (pMainSlotPar->Obj2StartPtIndex > SlotStartIndex) &&
      (pMainSlot->DisFromCarToObj[pMainSlotPar->Obj2StartPtIndex] != NO_OBJ_DISTANCE)) {
    j                         = SlotStartIndex + 2;
    i                         = SlotEndIndex;
    Obj2RisingShapeStartIndex = i;
    while (i > j) {
      i--;
      if (pMainSlot->ObjPt[i].y < -APACal.APATrajCalOriginalPtToObj2DisCompByRisingEdgeMaxWidth) {
        break;
      }
      if (pMainSlot->DisFromCarToObj[i] != NO_OBJ_DISTANCE) {
        if (pMainSlot->ObjPt[i].x > APACal.APATrajCalOriginalPtToObj2DisCompByRisingEdgeMaxObj2PtX) {
          break;
        }
        Obj2RisingShapeStartIndex = i;
      }
    }
    // USSPar.TrajCalObj2RisingShapeWidth = - pMainSlot->ObjPt[pMainSlotPar->Obj2StartPtIndex].y;
    USSPar.TrajCalObj2RisingShapeWidth = -pMainSlot->ObjPt[Obj2RisingShapeStartIndex].y;

    if (USSPar.TrajCalObj2RisingShapeWidth > APACal.APATrajCalOriginalPtToObj2DisCompByRisingEdgeMinWidth) {
      // > 0.8m
      // It is a very big width ??
      // May be the system coordinate is set up too above the obj2. the
      // car may hit obj2 during back up.
      // use a little big safety dis.
      X1   = (APA_DISTANCE_CAL_FLOAT_TYPE)APACal.APATrajCalOriginalPtToObj2DisCompByRisingEdgeMinWidth;
      X2   = (APA_DISTANCE_CAL_FLOAT_TYPE)APACal.APATrajCalOriginalPtToObj2DisCompByRisingEdgeMaxWidth;
      Y1   = (APA_DISTANCE_CAL_FLOAT_TYPE)APACal.APATrajCalOriginalPtToObj2DisCompByRisingEdgeMinSafetyDis;
      Y2   = (APA_DISTANCE_CAL_FLOAT_TYPE)APACal.APATrajCalOriginalPtToObj2DisCompByRisingEdgeMaxSafetyDis;
      fDis = (APA_DISTANCE_CAL_FLOAT_TYPE)USSPar.TrajCalObj2RisingShapeWidth;
      fDis = APATrajCalTwoPointInterpolationCalculation(Y1, Y2, X1, X2, fDis);
      USSPar.TrajCalDistanceBetweenOriginalPtAndObj2 -= ((APA_DISTANCE_TYPE)fDis);
    }
  }
  PtMaxX = APACal.APATrajCalMaxOriginalPtToObj2Dis[ParkingModeIndex];
  PtMidX = -PtMaxX;

  if (USSPar.TrajCalDistanceBetweenOriginalPtAndObj2 > PtMaxX) {
    USSPar.TrajCalDistanceBetweenOriginalPtAndObj2 = PtMaxX;
  } else if (USSPar.TrajCalDistanceBetweenOriginalPtAndObj2 < PtMidX) {
    USSPar.TrajCalDistanceBetweenOriginalPtAndObj2 = PtMidX;
  }
}


/*************************************************************************************************************************************************
** Syntax :  void USS(void)                                                                                                                     **
**                                                                                                                                              **
** Service ID:   : NA                                                                                                                           **
**                                                                                                                                              **
** Sync/Async:   : Synchronous                                                                                                                  **
**                                                                                                                                              **
** Reentrancy:   : Non Reentrant                                                                                                                **
**                                                                                                                                              **
** Parameters (in): none                                                                                                                        **
**                                                                                                                                              **
** Parameters (out): none                                                                                                                       **
**                                                                                                                                              **
** Return value: none                                                                                                                           **
**                                                                                                                                              **
** Description : ..                                                                                                                             **
*************************************************************************************************************************************************/
BOOLEAN APATrajCalFitCurbLineAccordingToSlotData(APASlotOutlineCoordinateDataType *pMainSlot,
                                                 APA_DISTANCE_TYPE CarToObj2Dis,
                                                 APA_INDEX_TYPE SlotStartIndex,
                                                 APA_INDEX_TYPE SlotEndIndex,
                                                 APA_DISTANCE_TYPE SlotDepth,
                                                 APA_ANGLE_CAL_FLOAT_TYPE *pCurbLineAngWithY,
                                                 APALineParameterABCType *pCurbLine) {
  // Input Par: pMainSlot
  // SlotStartIndex,
  // SlotEndIndex,

  // Output par: pCurbLine
  // return value:
  // FALSE = Line does not exist.
  // TRUE = OK.

  APA_INDEX_TYPE ObjPtCnt, d, g, h, m;
  APA_DISTANCE_CAL_FLOAT_TYPE mX, mY, mXX, mXY, fTemp, fDis1, fDis2;
  APA_DISTANCE_TYPE Dis1, Dis2, Dis3, ValidLineLen;
  APA_ANGLE_CAL_FLOAT_TYPE BorderLineAng;
  BOOLEAN bLineIsHorizontal, bValidObjPtFound;
  APA_INDEX_TYPE ValidObjIndex[APA_TRAJCAL_CURB_LINE_FIT_MAX_SUPPORT_OBJ_NUM], TotalValidObjNum;

   // Algorithm Start:

  // 1. search the start point of the slot curb.
  for (; SlotStartIndex < SlotEndIndex; SlotStartIndex++) {
    Dis1 = MATH_ABS(pMainSlot->DisFromCarToObj[SlotStartIndex] - SlotDepth);
    if (Dis1 < APACal.APASlotCurbLineFitAllowSnsDtObjDisTolerance) { // 800=80cm
      // OK, within tol
      break;
    }
  }

  SlotEndIndex--;
  if (CarToObj2Dis != NO_OBJ_DISTANCE) {
    d    = SlotEndIndex;
    Dis2 = APACal.APASlotMinSlotDepth - 500;              // 1400 -500
    for (g = SlotEndIndex - 1; g > SlotStartIndex; g--) {
      if (pMainSlot->DisFromCarToObj[g] != NO_OBJ_DISTANCE) {
        Dis1 = pMainSlot->DisFromCarToObj[g] - CarToObj2Dis;

        if (Dis1 > Dis2) {
          // OK, within tol
          SlotEndIndex = g;
          // break; // ??
        }
      }
      Dis3 = APASlotProcCalTwoPtApproximateDisInt(pMainSlot->CarCenterPoint[d], // Dis2  ->> Dis3 Found by Lin Huiting unit test
                                                  pMainSlot->CarCenterPoint[g]);
      if (Dis3 > 800) {
        break;
      }
    }
  }

  while (SlotEndIndex > SlotStartIndex) {
    Dis1 = MATH_ABS(pMainSlot->DisFromCarToObj[SlotEndIndex] - SlotDepth);
    if (Dis1 < APACal.APASlotCurbLineFitAllowSnsDtObjDisTolerance) { // 80cm
      // OK, within tol
      break;
    }
    SlotEndIndex--;
  }
  ObjPtCnt = SlotEndIndex - SlotStartIndex;
  if (ObjPtCnt < 3) {
    return FALSE;
  }

  ValidLineLen = APATrajCalGetTwoPointDisInt(pMainSlot->CarCenterPoint[SlotStartIndex].x,
                                             pMainSlot->CarCenterPoint[SlotStartIndex].y,
                                             pMainSlot->CarCenterPoint[SlotEndIndex].x,
                                             pMainSlot->CarCenterPoint[SlotEndIndex].y);

  // Check the valid object point:
  TotalValidObjNum = 0;
  for (g = SlotStartIndex; g <= SlotEndIndex; g++) {
    Dis1 = MATH_ABS(pMainSlot->DisFromCarToObj[g] - SlotDepth);
    if (Dis1 < APACal.APASlotCurbLineFitAllowCurbLineToObjDisTolerance) { // 35cm
      // OK, valid obj
      if (TotalValidObjNum < APA_TRAJCAL_CURB_LINE_FIT_MAX_SUPPORT_OBJ_NUM) { // 15
        ValidObjIndex[TotalValidObjNum] = g; 
        TotalValidObjNum++;
      } else {
        break;
      }
    }
  }
  if (TotalValidObjNum == 0) {
    return FALSE;
  }
  bValidObjPtFound = FALSE;
  if (TotalValidObjNum >= APACal.APASlotCurbLineFitAllowMinObjPt) { // 3
    m    = ValidObjIndex[TotalValidObjNum - 1];                     // end point
    h    = ValidObjIndex[0];                                        // Start point
    Dis1 = APATrajCalGetTwoPointDisInt(
        pMainSlot->CarCenterPoint[h].x,
        pMainSlot->CarCenterPoint[h].y,
        pMainSlot->CarCenterPoint[m].x,
        pMainSlot->CarCenterPoint[m].y);
    ValidLineLen *= 6;
    ValidLineLen /= 10;
    if (ValidLineLen < APACal.APASlotCurbLineFitAllowMinCurbLength) { // 1.5m
      ValidLineLen = APACal.APASlotCurbLineFitAllowMinCurbLength;
    }
    if ((Dis1 > ValidLineLen) &&
        (MATH_FABS(pMainSlot->CarAng[h] - pMainSlot->CarAng[m]) < (PI / 2.0))) { // def: 2 // or 3, 4, 5, .... need to be debug in the real car test.
      // OK, Valid curb line found
      bValidObjPtFound = TRUE;
    } else {
      // It may be a incline line. or curve line
    }
  }
  if (bValidObjPtFound == FALSE) {
    // search from the start of the first valid obj index to end
    m                = ValidObjIndex[0];
    TotalValidObjNum = 1;
    for (g = m + 1; g <= SlotEndIndex; g++) {
      Dis1 = MATH_ABS(pMainSlot->DisFromCarToObj[g] - pMainSlot->DisFromCarToObj[m]);
      if (Dis1 < APACal.APASlotCurbLineFitAllowCurbLineToObjDisTolerance2) { // 40cm
        // OK, valid obj
        if (TotalValidObjNum < APA_TRAJCAL_CURB_LINE_FIT_MAX_SUPPORT_OBJ_NUM) {
          ValidObjIndex[TotalValidObjNum] = g;
          TotalValidObjNum++;
          m = g;
        } else {
          break;
        }
      }
    }
    h = ValidObjIndex[0];
    for (g = h - 1; g >= SlotStartIndex; g--) {
      Dis1 = MATH_ABS(pMainSlot->DisFromCarToObj[g] - pMainSlot->DisFromCarToObj[h]);
      if (Dis1 < APACal.APASlotCurbLineFitAllowCurbLineToObjDisTolerance2) {
        // OK, valid obj
        if (TotalValidObjNum < APA_TRAJCAL_CURB_LINE_FIT_MAX_SUPPORT_OBJ_NUM) {
          ValidObjIndex[TotalValidObjNum] = g;
          TotalValidObjNum++;
          h = g;
        } else {
          break;
        }
      }
    }
    if (TotalValidObjNum > APACal.APASlotCurbLineFitAllowMinObjPt) {
      Dis1 = APATrajCalGetTwoPointDisInt(
          pMainSlot->CarCenterPoint[h].x, pMainSlot->CarCenterPoint[h].y, pMainSlot->CarCenterPoint[m].x, pMainSlot->CarCenterPoint[m].y);

      if ((Dis1 > APACal.APASlotCurbLineFitAllowMinCurbLength) && (MATH_FABS(pMainSlot->CarAng[h] - pMainSlot->CarAng[m]) <
                                                                   (PI / 2.0))) { // def: 2 // or 3, 4, 5, .... need to be debug in the real car test.
        // OK, Valid curb line found
        bValidObjPtFound = TRUE;
      } else {
        // It may be a incline line. or curve line
      }
    }
  }

  if (bValidObjPtFound == FALSE) {
    return FALSE;
  }

  // Algorithm Start:

  mX  = 0;
  mY  = 0;
  mXX = 0;
  mXY = 0;
  for (g = 0; g < TotalValidObjNum; g++) {
    d     = ValidObjIndex[g];
    fDis1 = (float)(pMainSlot->ObjPt[d].y/1000.0); // ********** Switch the X and Y coordinate due to the calculation accuracy of vertical line.
    fDis2 = (float)(pMainSlot->ObjPt[d].x/1000.0);
    mX += fDis1;
    mY += fDis2;
    mXX += fDis1 * fDis1;
    mXY += fDis1 * fDis2;
  }

  // We assume that the line should be constructed by at least 3 points (object points).
  fTemp = TotalValidObjNum;
  fDis1 = mX * mX - mXX * fTemp;

  if (fDis1 == 0) {
    // Is it a horizontal line,
    bLineIsHorizontal = TRUE;
  } else {
    fDis2             = (mY * mX - mXY * fTemp) / fDis1; // Line: Y = KX + B => K,
    bLineIsHorizontal = FALSE;
  }

  if ((bLineIsHorizontal == TRUE) || (MATH_FABS(fDis2) < APACal.APATrajCalLineIsHMinK)) {
    // Actually it is vertical line. due to we have switch the X Y coordinate.
    if (MATH_FABS(pMainSlot->CarAng[h]) > APACal.APASlotCurbLineFitAllowMaxDeltaCarAngAndCurbLineAng) {
      // Data error
      return FALSE;
    }
    if(MATH_FABS(fTemp)>0.001)
    {
        pCurbLine->A         = 1;
        pCurbLine->B         = 0;
        pCurbLine->LineType  = APALineIsVertical;
        pCurbLine->C         = -mY / fTemp;
        (*pCurbLineAngWithY) = 0;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
  } else {
    BorderLineAng = -MATH_ATAN(fDis2);
    if(MATH_FABS(fTemp)>0.001)
    {
        fDis1         = (mY - mX * fDis2) / fTemp; // Line: Y = KX + B => B,
    }
    else
    {
        return FALSE;
    }
    

    // Step 1.3.2.2: Offset the fit border line.
    /*
                                      \	   \ *
                                       \    \
                                            \    \*
                                             \    \
    Offset border line -> \    \
                                               \  * \ <------- fitted border line.
                                                \    \
                                                 \   *\
                                                  \    \
                            ^ 		       \    \
                            | 		        \    \
                            | 		         *    \
    Car driving direction	      \	   \*<---- Object Point.

    */

#ifdef APA_SLOT_SUPPORT_SLOT_BORDER_LINE_OFFSET_CAL
    d   = 0x7f; // Invalid index. Indicate the point which the offset line cross.
    mXX = 1000; // 1m,
    for (g = h; g <= m; g++) {
      if ((pSDGObjPtBuf->ObjPtBuf[g].ObjDis < APA_SLOT_PER_OBJ1Y_OBJ2Y_CORRECT_RANGE_OBJ_DIS_MAX1) &&
          (pSDGObjPtBuf->ObjPtBuf[g].ObjDis < MinObjDis)) {
        mX  = pSDGObjPtBuf->ObjPtBuf[g].Pt.x;
        mY  = pSDGObjPtBuf->ObjPtBuf[g].Pt.y;
        mXY = fDis2 * mX + fDis1; // Y = K * X + B;
        if (bRightSideBorderLine == FALSE) {
          // Left side. the offset border line should be above of the fit line.
          mXY = mXY - mY;
        } else {
          // Right side. the offset border line should be under of the fit line.
          mXY = mY - mXY;
        }
        if (mXX > mXY) {
          mXX = mXY;
          d   = g;
        }
      }
    }
    if (d != 0x7f)
#endif
    {
#ifdef APA_SLOT_SUPPORT_SLOT_BORDER_LINE_OFFSET_CAL

      // OK, a valid offset border line is found.
      // Calculate the offset line:
      // Y = KX + B1:
      mX       = pSDGObjPtBuf->ObjPtBuf[d].Pt.x;
      mY       = pSDGObjPtBuf->ObjPtBuf[d].Pt.y;
      LineParB = mY - fDis2 * mX; // B1: New B1.

      fDis1 = (fDis1 + LineParB) / 2.0; // Mid of Offset line and fit border line.
#endif
      // Check the line angle:

#ifdef WITHOUT_SWITCH_COORDINATE_XY

      if (BorderLineAng < 0) {
        BorderLineAng += PI / 2.0;
      } else {
        BorderLineAng = BorderLineAng - PI / 2.0;
      }
#endif

      if ((MATH_FABS(BorderLineAng) < APACal.APASlotCurbLineFitAllowMaxCurbLineAndYAng) &&
          (MATH_FABS(pMainSlot->CarAng[h] - (BorderLineAng)) < APACal.APASlotCurbLineFitAllowMaxDeltaCarAngAndCurbLineAng) &&
          (MATH_FABS(pMainSlot->CarAng[m] - (BorderLineAng)) < APACal.APASlotCurbLineFitAllowMaxDeltaCarAngAndCurbLineAng)) {

        // Check if the slot border line is reasonable.
        // 1. all the point dis to line should not exceed a tolerance.
        // 2. compensate the angle. actual: 10deg -> fit =8.12deg.

#ifdef WITHOUT_SWITCH_COORDINATE_XY
        pCurbLine->A        = fDis2;
        pCurbLine->B        = 1.0;
        pCurbLine->C        = fDis1;
        pCurbLine->LineType = APALineIsIncline;
#else
      if(MATH_FABS(fDis2)>0.001)
      {
          pCurbLine->A        = 1.0 / fDis2; // we also need to compensate the K.
          pCurbLine->B        = 1.0;
          pCurbLine->C        = -fDis1 / fDis2;
          pCurbLine->LineType = APALineIsIncline;
      }
      else
      {
          return FALSE;
      }
#endif
        (*pCurbLineAngWithY) = BorderLineAng * APACal.APASlotCurbLineFitCurbLineAngCompensateRatio;
        return TRUE;
      }
      //} else {
      // data error, just go to next line.
    }
  }

  // Algorithm End

  return FALSE;
}
/*************************************************************************************************************************************************
** Syntax :  void USS(void)                                                                                                                     **
**                                                                                                                                              **
** Service ID:   : NA                                                                                                                           **
**                                                                                                                                              **
** Sync/Async:   : Synchronous                                                                                                                  **
**                                                                                                                                              **
** Reentrancy:   : Non Reentrant                                                                                                                **
**                                                                                                                                              **
** Parameters (in): none                                                                                                                        **
**                                                                                                                                              **
** Parameters (out): none                                                                                                                       **
**                                                                                                                                              **
** Return value: none                                                                                                                           **
**                                                                                                                                              **
** Description : ..                                                                                                                             **
*************************************************************************************************************************************************/
void APATrajCalTransferCoordinateToNewWoldCoordinateSystem(APA_ENUM_TYPE SlotLaneCalMode,
                                                           APACoordinateDataCalFloatType Pto2,
                                                           APA_ANGLE_CAL_FLOAT_TYPE Ang_o1o2,
                                                           APA_ANGLE_CAL_FLOAT_TYPE NewCoordinateY,
                                                           APA_ENUM_TYPE CarEndPosType,
                                                           APA_DISTANCE_CAL_FLOAT_TYPE SlotLen,
                                                           APA_ANGLE_CAL_FLOAT_TYPE *pNewCarAngToBeTransfered,
                                                           APACoordinateDataCalFloatType *pNewCarCenterPtToBeTransfered) {
  // SlotLaneCalMode: 0 - just cal the main slot and cur car pos ... except the sub slot.
  //                  1 - only cal sub slot.
  //                  2 - cal all the second time.
  //                  3 - cal all.

  APA_INDEX_TYPE i, j;
  APA_ANGLE_CAL_FLOAT_TYPE CarAng, AngTemp;
  APACoordinateDataCalFloatType CenterPt, DstPt, PtTemp;
  APASlotOutlineCoordinateDataType *pMainSlot;
  APASlotOutlineCoordinateDataType *pSubSlot;
  APA_DISTANCE_CAL_FLOAT_TYPE fDis;
  APA_DISTANCE_TYPE X1, LTemp, LTemp2, ObjPtMaxX;

  if (SlotLaneCalMode != 1) {

    pMainSlot = &USSPar.Slot[USSPar.APARightSlotDataIndex].SlotOutline.Lane;

    USSPar.SlotCarEndPosXPrevValue = USSPar.TrajCalCarEndPos.Coordinate.x;

    // Coordinate transfer from the old real world system O1 to the new real world coordinate system O2.

    DstPt.x = Pto2.x;
    DstPt.y = Pto2.y;

    CarAng     = -Ang_o1o2;
    CenterPt.x = 0;

    CenterPt.y = NewCoordinateY; // 0;
    DstPt      = APATrajCalPointPosWithAngAndCenterPt(DstPt, CarAng, CenterPt);
    CenterPt.x = -DstPt.x;
    CenterPt.y = -DstPt.y;

    if (SlotLaneCalMode == 0) {
      (*pNewCarAngToBeTransfered)      = CarAng;
      (*pNewCarCenterPtToBeTransfered) = CenterPt;
    }

    // LIU.PAN vision_slot 2018/9/05
    // for (i = 0; i < USSPar.H_APA_CARPOSISION_ForVision.num; i++) {
    //   APACoordinateDataCalFloatType DstPt;
    //   DstPt.x = USSPar.H_APA_CARPOSISION_ForVision.carpose[i].H_APACarCenterPt.Coordinate.x;
    //   DstPt.y = USSPar.H_APA_CARPOSISION_ForVision.carpose[i].H_APACarCenterPt.Coordinate.y;
    //   DstPt   = APATrajCalPointPosWithAngAndCenterPt(DstPt, CarAng, CenterPt);
    //   USSPar.H_APA_CARPOSISION_ForVision.carpose[i].H_APACarCenterPt.CarAng += CarAng;
    //   USSPar.H_APA_CARPOSISION_ForVision.carpose[i].H_APACarCenterPt.Coordinate.x = DstPt.x;
    //   USSPar.H_APA_CARPOSISION_ForVision.carpose[i].H_APACarCenterPt.Coordinate.y = DstPt.y;
    // }

    USSPar.ParkProcCarEndPosition = CarEndPosType;
    DstPt.x                          = USSPar.APACarCenterPt.Coordinate.x;
    DstPt.y                          = USSPar.APACarCenterPt.Coordinate.y;
    DstPt                            = APATrajCalPointPosWithAngAndCenterPt(DstPt, CarAng, CenterPt);
    USSPar.APACarCenterPt.CarAng += CarAng;
    USSPar.APACarCenterPt.Coordinate.x = DstPt.x;
    USSPar.APACarCenterPt.Coordinate.y = DstPt.y;
    // USSPar.APACarCenterPt.CarAngCosValue = MATH_COS(USSPar.APACarCenterPt.CarAng);
    // USSPar.APACarCenterPt.CarAngSinValue = MATH_SIN(USSPar.APACarCenterPt.CarAng);

    // USSPar.APACurrentCarAngState = APATrajCalCheckIfTheCarIsDrivingVerticallyOrHorizontally(USSPar.APACarCenterPt.CarAng);
    /*
    if(USSPar.APACurrentCarAngState == 0){
    // Normal line
    USSPar.APACarCenterPt.CarAngTanValue = MATH_TAN(USSPar.APACarCenterPt.CarAng);
    } else if(USSPar.APACurrentCarAngState == 1){
    // vertical
    USSPar.APACarCenterPt.CarAngTanValue = APACal.APATrajCalLineIsVMaxK;
    } else {
    // horizontal
    USSPar.APACarCenterPt.CarAngTanValue = APACal.APATrajCalLineIsHMinK;
    }
    */

    DstPt.x = USSPar.APACarCenterPtCaledByWheelCnt.Coordinate.x;
    DstPt.y = USSPar.APACarCenterPtCaledByWheelCnt.Coordinate.y;
    DstPt   = APATrajCalPointPosWithAngAndCenterPt(DstPt, CarAng, CenterPt);
    USSPar.APACarCenterPtCaledByWheelCnt.CarAng += CarAng;
    USSPar.APACarCenterPtCaledByWheelCnt.Coordinate.x = DstPt.x;
    USSPar.APACarCenterPtCaledByWheelCnt.Coordinate.y = DstPt.y;

    for (i = USSPar.APASnsDtdObjDisInfoBufReadIndex; i < USSPar.APASnsDtdObjDisInfoBufWriteIndex; i++) {
      /* There is sns dtd dis need to be processed */
      DstPt.x = USSPar.APASnsDtdObjDisInfoBuf[i].CarCenterPt.Coordinate.x;
      DstPt.y = USSPar.APASnsDtdObjDisInfoBuf[i].CarCenterPt.Coordinate.y;
      DstPt   = APATrajCalPointPosWithAngAndCenterPt(DstPt, CarAng, CenterPt);
      USSPar.APASnsDtdObjDisInfoBuf[i].CarCenterPt.CarAng += CarAng;
      USSPar.APASnsDtdObjDisInfoBuf[i].CarCenterPt.Coordinate.x = DstPt.x;
      USSPar.APASnsDtdObjDisInfoBuf[i].CarCenterPt.Coordinate.y = DstPt.y;
    }

#ifdef PC_TRAJECTORY_DEBUG15
    if (cDlgDebug == 5) {
      CDlgTrajectoryDebug Dlg;
      Dlg.m_pSlotInfo       = &USSPar.Slot[USSPar.APARightSlotDataIndex];
      Dlg.m_pSubSlotInfo    = &USSPar.Slot[USSPar.APALeftSlotDataIndex];
      Dlg.m_pTrajectoryData = NULL;
      Dlg.m_CurCarAng       = pMainSlot->CarAng[SlotEndIndex];
      Dlg.m_CurCarPos.x     = pMainSlot->CarCenterPoint[SlotEndIndex].x;
      Dlg.m_CurCarPos.y     = pMainSlot->CarCenterPoint[SlotEndIndex].y;
      /*Dlg.m_CircleCenterPt[0] = CPoint(StepData[StepNum].CarTurningCenterPt.x, StepData[StepNum].CarTurningCenterPt.y);
      Dlg.m_CircleRadius[0] = StepData[StepNum].CarRearAxisCenterTurningRadius + APACal.APATrajCalMinRearAxisCenterTurningRadius;
      Dlg.m_CircleCenterPt[1] = CPoint(NextKeyPoint.Coordinate.x, NextKeyPoint.Coordinate.y);
      Dlg.m_CircleRadius[1] = APACal.APATrajCalMinRearAxisCenterTurningRadius;
      Dlg.m_CircleCenterPt[2] = CPoint(StepData[StepNum].CarTurningCenterPt.x, StepData[StepNum].CarTurningCenterPt.y);
      Dlg.m_CircleRadius[2] = StepData[StepNum].CarRearAxisCenterTurningRadius;
      Dlg.m_CircleNum = 3;*/

      Dlg.m_CircleCrossPt[0] = CPoint(CenterPt.x, CenterPt.y);
      Dlg.m_CircleCrossPt[1] = CPoint(pMainSlot->ObjPt[SlotEndIndex].x, pMainSlot->ObjPt[SlotEndIndex].y);
      Dlg.m_CircleCrossPtNum = 2;

      int ID = Dlg.DoModal();
    }
#endif

    for (j = 0; j < APA_SIDE_SENSOR_NUM; j++) {
      for (i = 0; i < APASnsDtdObjPtBuf[j].WrIndex; i++) {

        DstPt.x = APASnsDtdObjPtBuf[j].ObjPtBuf[i].CarPos.Coordinate.x;
        DstPt.y = APASnsDtdObjPtBuf[j].ObjPtBuf[i].CarPos.Coordinate.y;
        DstPt   = APATrajCalPointPosWithAngAndCenterPt(DstPt, CarAng, CenterPt);

        APASnsDtdObjPtBuf[j].ObjPtBuf[i].CarPos.Coordinate.x = DstPt.x;
        APASnsDtdObjPtBuf[j].ObjPtBuf[i].CarPos.Coordinate.y = DstPt.y;
        APASnsDtdObjPtBuf[j].ObjPtBuf[i].CarPos.CarAng       = APASnsDtdObjPtBuf[j].ObjPtBuf[i].CarPos.CarAng + CarAng;
      }
    }

    // USSPar.TrajCalObj1Pos.x = APA_TRAJCAL_WITHOUT_OBJ1_COORDINATE_X;
    USSPar.TrajCalObj1Pos.y = -SlotLen;

    // USSPar.TrajCalObj2Pos.x = APA_TRAJCAL_WITHOUT_OBJ2_COORDINATE_X;
    USSPar.TrajCalObj2Pos.y = 0;
    j                          = 0;
    fDis                       = USSPar.TrajCalObj1Pos.y / 2;
    for (i = 0; i < pMainSlot->ObjPtCnt; i++) {
      DstPt.x = pMainSlot->ObjPt[i].x;
      DstPt.y = pMainSlot->ObjPt[i].y;

      DstPt                 = APATrajCalPointPosWithAngAndCenterPt(DstPt, CarAng, CenterPt);
      pMainSlot->ObjPt[i].x = DstPt.x;
      pMainSlot->ObjPt[i].y = DstPt.y;

      if (j == 0) {
        if (DstPt.y > fDis) {  
          j = i;
        }
      }
      DstPt.x = pMainSlot->CarCenterPoint[i].x;
      DstPt.y = pMainSlot->CarCenterPoint[i].y;

      DstPt                          = APATrajCalPointPosWithAngAndCenterPt(DstPt, CarAng, CenterPt);
      pMainSlot->CarCenterPoint[i].x = DstPt.x;
      pMainSlot->CarCenterPoint[i].y = DstPt.y;

      pMainSlot->CarAng[i] = pMainSlot->CarAng[i] + CarAng;
    }

    i     = j;
    LTemp = USSPar.TrajCalObj1Pos.y - APACal.APASlotObj12CheckCarDrvDisY;   //70cm
    if (SlotLen < 3500) {
      LTemp2 = LTemp - 2500;
    } else {
      LTemp2 = LTemp - APACal.APASlotObj12CheckCarDrvDisY;   //70cm
    }
    X1 = APA_TRAJCAL_WITHOUT_OBJ1_COORDINATE_X;

    if ((USSPar.APACarParkingMode == APA_PARKPROC_PARKING_MODE_PERPENDICULAR)) {
      ObjPtMaxX = APACal.APASlotMaxOffsetDisBetweenObj1AndObj2ForPerpendicular / 2;   //150/2 = 75cm
    } else {
      ObjPtMaxX = APACal.APASlotMaxOffsetDisBetweenObj1AndObj2ForParallel;  //130cm
    }

#ifdef APA_SUPPORT_SLOT_POINT_COMPENSATE_ADJ
    Y1 = USSPar.TrajCalObj1Pos.y;
#endif

    while (i > 0) {
      i--;
      if ((pMainSlot->bObjIsBigEnough[i] & APA_SLOT_OBJ_IS_BIG_ENOUGH_CHECK_OBJ_MASK) != 0) {
        if (X1 > pMainSlot->ObjPt[i].x) {
          X1 = pMainSlot->ObjPt[i].x;
        }

#ifdef APA_SUPPORT_SLOT_POINT_COMPENSATE_ADJ
        if (pMainSlot->ObjPt[i].y > Y1) {
          pMainSlot->ObjPt[i].y = Y1;
        }
#endif
        if (X1 < ObjPtMaxX) {
          if (pMainSlot->ObjPt[i].y < LTemp) {
            break;
          }
        } else {
          if (pMainSlot->ObjPt[i].y < LTemp2) {
            break;
          }
        }
      }
    }
    if (X1 >= ObjPtMaxX) {
      if (USSPar.APACommonFlags.Bits.bSlotProcSlotObj1Exist == TRUE) {
        // ?? Data error ??
        X1 = 0;
      }
    }
    USSPar.TrajCalObj1Pos.x = X1;

    // i = j + 1; ????????????????? need to debug...........
    i  = j;
    X1 = APA_TRAJCAL_WITHOUT_OBJ2_COORDINATE_X;

    LTemp  = APACal.APASlotObj12CheckCarDrvDisY;       // 70cm.
    LTemp2 = APACal.APASlotObj12CheckCarDrvDisY + 500; // 70cm + 50cm.

#ifdef APA_SUPPORT_SLOT_POINT_COMPENSATE_ADJ
    Y1 = USSPar.TrajCalObj2Pos.y;
#endif
    while (i < pMainSlot->ObjPtCnt) {

      if ((pMainSlot->bObjIsBigEnough[i] & APA_SLOT_OBJ_IS_BIG_ENOUGH_CHECK_OBJ_MASK) != 0) {
        if (X1 > pMainSlot->ObjPt[i].x) {
          X1 = pMainSlot->ObjPt[i].x;
        }

#ifdef APA_SUPPORT_SLOT_POINT_COMPENSATE_ADJ

        if (pMainSlot->ObjPt[i].y < Y1) {
          pMainSlot->ObjPt[i].y = Y1;
        }

#endif
        if (X1 < ObjPtMaxX) {
          if (pMainSlot->ObjPt[i].y > LTemp) {
            break;
          }
        } else {
          if (pMainSlot->ObjPt[i].y > LTemp2) {
            break;
          }
        }
      }
      i++;
    }

    if (X1 >= ObjPtMaxX) {
      if (USSPar.APACommonFlags.Bits.bSlotProcSlotObj2Exist == TRUE) {
        // ?? Data error ??
        X1 = 0;
      }
    }

    USSPar.TrajCalObj2Pos.x = X1;

    USSPar.TrajCalSlotLeftSideLine.K  = 0;
    USSPar.TrajCalSlotLeftSideLine.B  = USSPar.TrajCalObj1Pos.y;
    USSPar.TrajCalSlotRightSideLine.K = 0;
    USSPar.TrajCalSlotRightSideLine.B = USSPar.TrajCalObj2Pos.y;
  }

  if (SlotLaneCalMode > 0) {
    if (SlotLaneCalMode == 2) {
      // Cal second times
      DstPt = (*pNewCarCenterPtToBeTransfered);
      DstPt = APATrajCalPointPosWithAngAndCenterPt(DstPt, CarAng, CenterPt);
      CarAng += (*pNewCarAngToBeTransfered);
      CenterPt = DstPt;
    } else if (SlotLaneCalMode == 1) {
      // first time to cal sub slot
      CarAng   = (*pNewCarAngToBeTransfered);
      CenterPt = (*pNewCarCenterPtToBeTransfered);
    }

    pSubSlot = &USSPar.Slot[USSPar.APALeftSlotDataIndex].SlotOutline.Lane;

    for (i = 0; i < pSubSlot->ObjPtCnt; i++) {
      DstPt.x = pSubSlot->ObjPt[i].x;
      DstPt.y = pSubSlot->ObjPt[i].y;

      DstPt                = APATrajCalPointPosWithAngAndCenterPt(DstPt, CarAng, CenterPt);
      pSubSlot->ObjPt[i].x = DstPt.x;
      pSubSlot->ObjPt[i].y = DstPt.y;

      DstPt.x = pSubSlot->CarCenterPoint[i].x;
      DstPt.y = pSubSlot->CarCenterPoint[i].y;

      DstPt                         = APATrajCalPointPosWithAngAndCenterPt(DstPt, CarAng, CenterPt);
      pSubSlot->CarCenterPoint[i].x = DstPt.x;
      pSubSlot->CarCenterPoint[i].y = DstPt.y;

      pSubSlot->CarAng[i] = pSubSlot->CarAng[i] + CarAng;
    }

    for (j = 0; j < APA_SLOT_SUPPORT_SEARCHING_SLOT_SENSOR_NUM; j++) {
      for (i = 0; i < USSPar.Slot[j].SlotOutlineRearSideSnsDetected.LaneDetectedByRearSideSensor.ObjPtCntRSns; i++) {
        DstPt.x = (APA_DISTANCE_CAL_FLOAT_TYPE)USSPar.Slot[j].SlotOutlineRearSideSnsDetected.LaneDetectedByRearSideSensor.ObjPtRSns[i].x;
        DstPt.y = (APA_DISTANCE_CAL_FLOAT_TYPE)USSPar.Slot[j].SlotOutlineRearSideSnsDetected.LaneDetectedByRearSideSensor.ObjPtRSns[i].y;
        DstPt   = APATrajCalPointPosWithAngAndCenterPt(DstPt, CarAng, CenterPt);
        USSPar.Slot[j].SlotOutlineRearSideSnsDetected.LaneDetectedByRearSideSensor.ObjPtRSns[i].x = (APA_DISTANCE_TYPE)DstPt.x;
        USSPar.Slot[j].SlotOutlineRearSideSnsDetected.LaneDetectedByRearSideSensor.ObjPtRSns[i].y = (APA_DISTANCE_TYPE)DstPt.y;

        DstPt.x = (APA_DISTANCE_CAL_FLOAT_TYPE)USSPar.Slot[j].SlotOutlineRearSideSnsDetected.LaneDetectedByRearSideSensor.CarCenterPointRSns[i].x;
        DstPt.y = (APA_DISTANCE_CAL_FLOAT_TYPE)USSPar.Slot[j].SlotOutlineRearSideSnsDetected.LaneDetectedByRearSideSensor.CarCenterPointRSns[i].y;
        DstPt   = APATrajCalPointPosWithAngAndCenterPt(DstPt, CarAng, CenterPt);
        USSPar.Slot[j].SlotOutlineRearSideSnsDetected.LaneDetectedByRearSideSensor.CarCenterPointRSns[i].x = DstPt.x;
        USSPar.Slot[j].SlotOutlineRearSideSnsDetected.LaneDetectedByRearSideSensor.CarCenterPointRSns[i].y = DstPt.y;

        USSPar.Slot[j].SlotOutlineRearSideSnsDetected.LaneDetectedByRearSideSensor.CarAngRSns[i] += CarAng;
      }
    }
  }
#ifdef PC_TRAJECTORY_DEBUG12
  if (cDlgDebug == 5) {
    CDlgTrajectoryDebug Dlg;
    Dlg.m_pSlotInfo       = &USSPar.Slot[USSPar.APARightSlotDataIndex];
    Dlg.m_pSubSlotInfo    = &USSPar.Slot[USSPar.APALeftSlotDataIndex];
    Dlg.m_pTrajectoryData = NULL;
    Dlg.m_CurCarAng       = USSPar.APACarCenterPt.CarAng;
    Dlg.m_CurCarPos.x     = USSPar.APACarCenterPt.Coordinate.x;
    Dlg.m_CurCarPos.y     = USSPar.APACarCenterPt.Coordinate.y;
    int ID                = Dlg.DoModal();
  }
#endif
}
/*************************************************************************************************************************************************
** Syntax :  void USS(void)                                                                                                                     **
**                                                                                                                                              **
** Service ID:   : NA                                                                                                                           **
**                                                                                                                                              **
** Sync/Async:   : Synchronous                                                                                                                  **
**                                                                                                                                              **
** Reentrancy:   : Non Reentrant                                                                                                                **
**                                                                                                                                              **
** Parameters (in): none                                                                                                                        **
**                                                                                                                                              **
** Parameters (out): none                                                                                                                       **
**                                                                                                                                              **
** Return value: none                                                                                                                           **
**                                                                                                                                              **
** Description : ..                                                                                                                             **
*************************************************************************************************************************************************/

BOOLEAN APATrajCalParallelSetupSystemCoordinateAccordingToSlotData(APA_ENUM_TYPE *pCalResult,
                                                                   APA_ENUM_TYPE SlotLaneCalMode,
                                                                   APA_ENUM_TYPE *pSubSlotCaled,
                                                                   APA_ANGLE_CAL_FLOAT_TYPE *pNewCarAngToBeTransfered,
                                                                   APACoordinateDataCalFloatType *pNewCarCenterPtToBeTransfered) {

  // Input:
  // pCalResult: 0 - the first time to start cal.
  //             1 - the second time to cal and ignore the curb.

  APA_INDEX_TYPE i, j, k, m, n;
  APASlotOutlineCoordinateDataType *pMainSlot;
  APASlotParameterType *pMainSlotPar;
  APACoordinateDataCalFloatType CenterPt, DstPt, Pto2_c, Pto2, PtTemp2;
  APACoordinateDataCalFloatType PtSlotStart_c, PtSlotStart, PtSlotEnd, CarCenterPt;
  APA_ANGLE_CAL_FLOAT_TYPE Ang_o1o2;
  APA_ANGLE_CAL_FLOAT_TYPE Ang1;
  APA_DISTANCE_CAL_FLOAT_TYPE fDis, fDis2, fDis3, fDis4, fDis5;
  APA_RATIO_TYPE K1;
  APA_DISTANCE_TYPE SnsDetectedObjDis, DisCarToObj1ByPassingSlot, DisCarToObj2ByPassingSlot;
  APA_DISTANCE_TYPE DisCarToObj1ToCalSlot, DisCarToObj2ToCalSlot;
  APA_DISTANCE_TYPE LTemp, X1, X2, Y1, Y2, Y3, Y4, Y5, Y6, SlotDepthRefCarSide, SlotDepthRefObj, MinPSlotLen, YceMid;
  APA_DISTANCE_TYPE SlotDepth, SlotLen, SlotDepth2, SlotLen2, SlotDepth3, SlotLen3, SysCoordinateOffsetY;
  BOOLEAN bCurbFound, bRecalSlotEndPt, bObj2RegardAsInvalid, bUseFirstSlot, bFlag;
  APA_ENUM_TYPE APASnsIndex, LineIsVOrH;
  APA_INDEX_TYPE SlotEndIndex, SlotStartIndex, SlotEndCalIndex, SlotStartCalIndex;
  APA_ENUM_TYPE EndPosYCalMethod, CarEndPosType;
  APALineParameterABCType CurbLine;
  BOOLEAN bCurbLineFited;
  APA_ANGLE_CAL_FLOAT_TYPE CurbLineAngWithY;
  APA_ENUM_TYPE CarParkAtLeftOrRightSide;
  BOOLEAN bObjIsBigEnough;
  APA_DISTANCE_TYPE DeltaSnsDtDis;
  APA_INDEX_TYPE Obj1InflexionPtIndex, Obj2InflexionPtIndex;
  APA_DISTANCE_CAL_FLOAT_TYPE fX1, fX2, fY1, fY2, fSlotLen;

  if ((SlotLaneCalMode) == 1) {
    // Only need to cal sub slot
    Pto2.x        = 0;
    Pto2.y        = 0;
    Ang_o1o2      = 0;
    Y1            = 0;
    CarEndPosType = 0;
    SlotLen       = 0;
    APATrajCalTransferCoordinateToNewWoldCoordinateSystem(1,
                                                          Pto2,          // not used
                                                          Ang_o1o2,      // not used
                                                          Y1,            // not used
                                                          CarEndPosType, // not used
                                                          SlotLen,       // not used.
                                                          pNewCarAngToBeTransfered,
                                                          pNewCarCenterPtToBeTransfered);

    return TRUE;
  }

  pMainSlot      = &USSPar.Slot[USSPar.APARightSlotDataIndex].SlotOutline.Lane;
  pMainSlotPar   = &USSPar.Slot[USSPar.APARightSlotDataIndex].SlotPar[USSPar.TrajCalCurrentCalSlotIndex];
  SlotStartIndex = pMainSlotPar->SlotStartIndex;
  SlotEndIndex   = pMainSlotPar->SlotEndIndex;
  APASnsIndex    = APACal.APASlotRAPASnsIndex;

  if (pMainSlot->ObjPt[SlotStartIndex].y < 0) {
    return TRUE;
  }

  SlotLen = pMainSlotPar->SlotLengthTotal;
  if (SlotLen >= APACal.APASlotMinSmallSlotLen) {  // length +1m
  } else {
    return FALSE;
  }

  // 1. Cal the dis from car to obj by passing slot.

  DisCarToObj1ByPassingSlot = pMainSlotPar->DisCarToObj1ByPassingSlot;
  DisCarToObj2ByPassingSlot = pMainSlotPar->DisCarToObj2ByPassingSlot;

  // check if it is a concave road or convex road

#ifdef APA_SLOT_SUPPORT_DEBUG1
  if ((pMainSlotPar->Obj1Type != APA_SLOT_OBJ_TYPE_UNKNOWN) &&
      ((SlotStartIndex < (pMainSlotPar->Obj1EndPtIndex)) || ((SlotEndIndex) > (pMainSlotPar->Obj1StartPtIndex)))) {

    // Data error ??

    // cSlotDebug = 1;
  }
#endif

  bObj2RegardAsInvalid = FALSE;

  // 1.1 Check if the Offset distance between Obj1 and Obj2 is great than the calibration value.
  // if yes, just treat as the obj1 or obj2 is invalid.
  if ((DisCarToObj1ByPassingSlot == NO_OBJ_DISTANCE) && (DisCarToObj2ByPassingSlot == NO_OBJ_DISTANCE)) {
    // Data error ??
    return FALSE;
  } else if ((DisCarToObj1ByPassingSlot != NO_OBJ_DISTANCE) && (DisCarToObj2ByPassingSlot != NO_OBJ_DISTANCE)) {
    Y1 = APACal.APASlotMaxOffsetDisBetweenObj1AndObj2ForParallel;   //130cm
    if (DisCarToObj1ByPassingSlot > DisCarToObj2ByPassingSlot) {
      X1 = DisCarToObj1ByPassingSlot - DisCarToObj2ByPassingSlot;
      if (X1 > Y1) {
        // Hear we treat obj1 as invalid obj (no obj).
        DisCarToObj1ByPassingSlot = NO_OBJ_DISTANCE;
      }
    } else {
      X1 = DisCarToObj2ByPassingSlot - DisCarToObj1ByPassingSlot;
      if (X1 > Y1) {
        // Hear we treat obj2 as invalid obj (no obj).
        DisCarToObj2ByPassingSlot = NO_OBJ_DISTANCE;
        bObj2RegardAsInvalid      = TRUE;
      }
    }
  }

#if 1
  if (DisCarToObj1ByPassingSlot != NO_OBJ_DISTANCE) {
    if ((DisCarToObj2ByPassingSlot != NO_OBJ_DISTANCE) && (SlotLen > APACal.APATrajCalMaxSlotLengthForRegardingObj1Invalid)) {  //12m
      // The slot is very big. > 12m. obj1 will be regarded as invalid.
      // Hear we treat obj1 as invalid obj (no obj).
      DisCarToObj1ByPassingSlot = NO_OBJ_DISTANCE; 
    } else {
    }
  }
#else

  bFlag = TRUE;
  if (DisCarToObj1ByPassingSlot != NO_OBJ_DISTANCE) {
    if ((DisCarToObj2ByPassingSlot != NO_OBJ_DISTANCE) && (SlotLen > APACal.APATrajCalMaxSlotLengthForRegardingObj1Invalid)) {
      // The slot is very big. > 12m. obj1 will be regarded as invalid.
      // Hear we treat obj1 as invalid obj (no obj).
      DisCarToObj1ByPassingSlot = NO_OBJ_DISTANCE;
    } else {
      if (MATH_FABS(pMainSlot->CarAng[SlotEndIndex] - pMainSlot->CarAng[SlotStartIndex]) <
          APACal.APATrajCalSetupSysCoordinateCarDriveStraightlyTolCarAngle1) {
        // < 5deg. almost straight road.
        if ((pMainSlotPar->Obj1Type >= APA_SLOT_OBJ_TYPE_CAR_ANGULAR_10DEG_RISING_SHAPE_AT_START) &&
            (pMainSlotPar->Obj1Type <= APA_SLOT_OBJ_TYPE_CAR_ANGULAR_30DEG_FLAT_SHAPE_AT_START)) {
          bFlag = FALSE;
        }
      } else {
        // > 5deg.
        // convex or concave road
        if (((pMainSlotPar->Obj1Type >= APA_SLOT_OBJ_TYPE_CAR_ANGULAR_10DEG_RISING_SHAPE_AT_START) &&
             (pMainSlotPar->Obj1Type <= APA_SLOT_OBJ_TYPE_CAR_ANGULAR_30DEG_FLAT_SHAPE_AT_START)) ||
            ((pMainSlotPar->Obj1Type >= APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_SMALL_RISING_SHAPE) &&
             (pMainSlotPar->Obj1Type <= APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_VERY_BIG_RISING_SHAPE))) {
          bFlag = FALSE;
        }
      }
    }
  }

  if (bFlag == FALSE) {
    if (DisCarToObj2ByPassingSlot != NO_OBJ_DISTANCE) {
      if (MATH_FABS(pMainSlot->CarAng[SlotEndIndex] - pMainSlot->CarAng[SlotStartIndex]) <
          APACal.APATrajCalSetupSysCoordinateCarDriveStraightlyTolCarAngle1) {
        // < 5deg.
        if ((pMainSlotPar->Obj2Type >= APA_SLOT_OBJ_TYPE_CAR_ANGULAR_10DEG_RISING_SHAPE_AT_START) &&
            (pMainSlotPar->Obj2Type <= APA_SLOT_OBJ_TYPE_CAR_ANGULAR_30DEG_FLAT_SHAPE_AT_START)) {
          bFlag = TRUE;
        }
      } else {
        // > 5deg.
        if (((pMainSlotPar->Obj2Type >= APA_SLOT_OBJ_TYPE_CAR_ANGULAR_10DEG_RISING_SHAPE_AT_START) &&
             (pMainSlotPar->Obj2Type <= APA_SLOT_OBJ_TYPE_CAR_ANGULAR_30DEG_FLAT_SHAPE_AT_START)) ||
            ((pMainSlotPar->Obj2Type >= APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_SMALL_RISING_SHAPE) &&
             (pMainSlotPar->Obj2Type <= APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_VERY_BIG_RISING_SHAPE))) {
          bFlag = TRUE;
        }
      }
      if (bFlag == TRUE) {
        // recal dis car to obj 1.2.

        i = pMainSlotPar->Obj1StartPtIndex;
        if (pMainSlot->DisFromCarToObj[i] != DisCarToObj1ByPassingSlot) {
          j = i;
          while (j > 0) {

            j--;
            LTemp = pMainSlot->DisFromCarToObj[j];
            if (pMainSlot->DisFromCarToObj[j] <= DisCarToObj1ByPassingSlot) {
              break;
            }
            Y1 = APASlotProcCalTwoPtApproximateDisInt(pMainSlot->CarCenterPoint[i], pMainSlot->CarCenterPoint[j]);
            if (Y1 > 1000) {
              break;
            }
          }

          if ((j < i) && (j > 0)) {

            if ((LTemp - DisCarToObj1ByPassingSlot) < 700) {
              DisCarToObj1ByPassingSlot = LTemp;
            }
          }
        }

        i = pMainSlotPar->Obj2StartPtIndex;
        j = i;
        if (i < (pMainSlot->ObjPtCnt - 1)) {
          j = i + 1;
        }
        LTemp = pMainSlot->DisFromCarToObj[j];
        if (((LTemp - DisCarToObj2ByPassingSlot) < 700) && (pMainSlot->DisFromCarToObj[i] != DisCarToObj2ByPassingSlot)) {
          DisCarToObj2ByPassingSlot = LTemp;
        }
      }
    }
  }

#endif
  // 2. Check if a curb is found.

  SlotDepthRefCarSide = DisCarToObj1ByPassingSlot;
  if (SlotDepthRefCarSide > DisCarToObj2ByPassingSlot) {
    SlotDepthRefCarSide = DisCarToObj2ByPassingSlot;
  }

  // SlotIndex = 0;
  // SlotDept: is the dis between side of car to curb.

  SlotDepth = pMainSlotPar->SlotDepthParallel;

  // SlotDepthRefObj: is the dis between outside of obj and curb.
  SlotDepthRefObj = SlotDepth - SlotDepthRefCarSide;

  Y2 = (SlotDepthRefCarSide + APACal.APASlotMaxSlotDepth);  //2.6m

  if (SlotDepth <= Y2) {
    j          = 0; // Cur Point Num
    X1         = -APACal.APASlotCurbLineTolerance;  //30cm
    bCurbFound = FALSE;
    m          = APA_SLOT_SUPPORT_FRONT_SIDE_MAX_SAMPLE_POINT_NUM;
    // Check if the curb should be acknowedged.
    for (k = 0; k < (APA_SLOT_CURB_DT_CHECK_DEVIDE_SLOT_LEN_NUM - 1); k++) {
      if (SlotLen < APACal.APASlotCurbRegardedAsCurbDetectedDevidedSlotLen[k]) {  //6m\7.5m
        break;
      }
    }
    for (i = SlotStartIndex; i < SlotEndIndex; i++) {
      Y1 = APASlotProcCalTwoPtApproximateDisInt(pMainSlot->CarCenterPoint[SlotEndIndex], pMainSlot->CarCenterPoint[i]);
      if (Y1 < APACal.APASlotCurbDetCurbToObj2CutOffDis) {   //1.2m
        break;
      }
      LTemp = pMainSlot->DisFromCarToObj[i] - SlotDepth;  
      if ((LTemp > X1) && (LTemp < APACal.APASlotCurbLineFitAllowSnsDtObjDisTolerance)) {  
        // OK, Curb Point confirmed.
        j++;
        if (m == APA_SLOT_SUPPORT_FRONT_SIDE_MAX_SAMPLE_POINT_NUM) {
          m = i;  
        }
        if (j >= APACal.APASlotCurbRegardedAsCurbDetectedMinObjPtNum[k]) {  //3\4\5
          Y1 = APASlotProcCalTwoPtApproximateDisInt(pMainSlot->CarCenterPoint[m], pMainSlot->CarCenterPoint[i]);
          if (Y1 > APACal.APASlotCurbRegardedAsCurbDetectedMinCurbLen) {  //1m
            bCurbFound = TRUE;  
            break;
          }
        }
      }
    }
    if (bCurbFound == FALSE) {
      // Noise ?? or not meet the curb detected criteria.
      SlotDepth = NO_OBJ_DISTANCE;
    }
  }

  bCurbLineFited = FALSE;
  if (SlotDepth <= Y2) {
    // Curb detected.
    //
    // Xce should great than 0.!!!!!!!!!
    //
    bCurbFound = TRUE;

    if ((*pCalResult) == 0) {
      // Fit curb line.
      bCurbLineFited = APATrajCalFitCurbLineAccordingToSlotData(
          pMainSlot, pMainSlotPar->DisCarToObj2ByPassingSlot, SlotStartIndex, SlotEndIndex, SlotDepth, &CurbLineAngWithY, &CurbLine);
    }

#ifdef PC_TRAJECTORY_DEBUG12
    if (cDlgDebug == 5) {
      CDlgTrajectoryDebug Dlg;
      Dlg.m_pSlotInfo       = &USSPar.Slot[USSPar.APARightSlotDataIndex];
      Dlg.m_pSubSlotInfo    = &USSPar.Slot[USSPar.APALeftSlotDataIndex];
      Dlg.m_pTrajectoryData = NULL;
      Dlg.m_CurCarAng       = pMainSlot->CarAng[SlotEndIndex];
      Dlg.m_CurCarPos.x     = pMainSlot->CarCenterPoint[SlotEndIndex].x;
      Dlg.m_CurCarPos.y     = pMainSlot->CarCenterPoint[SlotEndIndex].y;
      /*Dlg.m_CircleCenterPt[0] = CPoint(StepData[StepNum].CarTurningCenterPt.x, StepData[StepNum].CarTurningCenterPt.y);
      Dlg.m_CircleRadius[0] = StepData[StepNum].CarRearAxisCenterTurningRadius + APACal.APATrajCalMinRearAxisCenterTurningRadius;
      Dlg.m_CircleCenterPt[1] = CPoint(NextKeyPoint.Coordinate.x, NextKeyPoint.Coordinate.y);
      Dlg.m_CircleRadius[1] = APACal.APATrajCalMinRearAxisCenterTurningRadius;
      Dlg.m_CircleCenterPt[2] = CPoint(StepData[StepNum].CarTurningCenterPt.x, StepData[StepNum].CarTurningCenterPt.y);
      Dlg.m_CircleRadius[2] = StepData[StepNum].CarRearAxisCenterTurningRadius;
      Dlg.m_CircleNum = 3;*/

      // Dlg.m_CircleCrossPt[0] = CPoint(Pto2.x, Pto2.y);
      // Dlg.m_CircleCrossPt[1] = CPoint(pMainSlot->ObjPt[SlotEndIndex].x, pMainSlot->ObjPt[SlotEndIndex].y);
      // Dlg.m_CircleCrossPtNum = 2;

      Dlg.m_pLinePar = &CurbLine;
      Dlg.m_LineNum  = 1;

      int ID = Dlg.DoModal();
    }
#endif

  } else {
    bCurbFound = FALSE;
  }

  // 3. Cal the new system coordinate original point O2 (relerative to current global coordinate:
  // Cal the slot system coordinate Y angle at the current global coordinate: AngO1O2.
  // And for the perpendicual slot, check if the slot width is great than APASlotPMaxSlotLengthWithInvalidObj2
  // (4m)? If yes, just regard the obj2 as invalid (if end pos park close to obj1). Or vice verser.

  CarEndPosType = APACal.APAParkProcCarEndPosition;  //2
  // 3.1 Slot Head Obj2. end searching point.Y
  // With curb.
  // 1. The curb is straight
  // 2. The curb is concave curve.
  // 3. The curb is convex curve.
  // End Pos:
  // 1. mid of two obj.
  // 2. colse to obj1.
  // 3. close to obj2.
  // Obj1 or obj2 state:
  // Obj1 and 2 exist.
  // Obj1 exist and 2 not exist.
  // Obj1 not exist and 2 exist.
  if ((DisCarToObj2ByPassingSlot == NO_OBJ_DISTANCE) ||
      ((bCurbFound == TRUE) && (DisCarToObj1ByPassingSlot != NO_OBJ_DISTANCE) && (SlotLen > APACal.APATrajCalMaxSlotLengthForAGivenSlot) &&
       (APACal.APAParkProcCarEndPositionWithSlotLenGreatThanAGivenSlot == APA_PARKPROC_CAR_END_POSITION_CLOSE_TO_OBJ1))) {
    DisCarToObj2ToCalSlot = SlotDepthRefCarSide;
    // According to the calibration, the slot length is 7500mm, it is ok. do not need to searching for the slot end point.
    //
    CarEndPosType = APA_PARKPROC_CAR_END_POSITION_CLOSE_TO_OBJ1;
    Y2            = pMainSlot->ObjPt[SlotStartIndex].y + APACal.APASlotMinSmallSlotLen;
  } else {
    if (bCurbFound == TRUE) {
      // Parking along the curb.
      // Original point should be along the min dis to car.
      DisCarToObj2ToCalSlot = SlotDepthRefCarSide;
    } else {
      DisCarToObj2ToCalSlot = DisCarToObj2ByPassingSlot;
    }
    Y2 = pMainSlot->ObjPt[SlotEndIndex].y;
  }
  // 3.2 Slot Tail Obj1. start searching point.Y
  if ((DisCarToObj1ByPassingSlot == NO_OBJ_DISTANCE) ||
      ((bCurbFound == TRUE) && (DisCarToObj2ByPassingSlot != NO_OBJ_DISTANCE) && (SlotLen > APACal.APATrajCalMaxSlotLengthForAGivenSlot) &&
       (APACal.APAParkProcCarEndPositionWithSlotLenGreatThanAGivenSlot == APA_PARKPROC_CAR_END_POSITION_CLOSE_TO_OBJ2))) {
    CarEndPosType         = APA_PARKPROC_CAR_END_POSITION_CLOSE_TO_OBJ2;
    DisCarToObj1ToCalSlot = SlotDepthRefCarSide;
    Y1                    = pMainSlot->ObjPt[SlotEndIndex].y - APACal.APASlotMinSmallSlotLen;
  } else {
    DisCarToObj1ToCalSlot = DisCarToObj1ByPassingSlot;
    Y1                    = pMainSlot->ObjPt[SlotStartIndex].y;
  }

  if ((bCurbFound == FALSE) && (DisCarToObj1ByPassingSlot != NO_OBJ_DISTANCE) && (DisCarToObj2ByPassingSlot != NO_OBJ_DISTANCE) &&
      (SlotLen > APACal.APATrajCalMaxSlotLengthForAGivenSlot)) {
    CarEndPosType = APACal.APAParkProcCarEndPositionWithSlotLenGreatThanAGivenSlot;
  }

  if (DisCarToObj1ByPassingSlot == NO_OBJ_DISTANCE) {
    USSPar.APACommonFlags.Bits.bSlotProcSlotObj1Exist = FALSE;
  } else {
    USSPar.APACommonFlags.Bits.bSlotProcSlotObj1Exist = TRUE;
  }
  if (DisCarToObj2ByPassingSlot == NO_OBJ_DISTANCE) {
    USSPar.APACommonFlags.Bits.bSlotProcSlotObj2Exist = FALSE;
  } else {
    USSPar.APACommonFlags.Bits.bSlotProcSlotObj2Exist = TRUE;
  }

  CarParkAtLeftOrRightSide = USSPar.TrajCalCarParkAtLeftOrRightSide;

  SlotStartCalIndex = SlotStartIndex;
  SlotEndCalIndex   = SlotEndIndex;
  for (i = SlotEndIndex; i < pMainSlot->ObjPtCnt; i++) {
    if (pMainSlot->CarCenterPoint[i].y > Y2) {
      break;
    }
    SlotEndCalIndex = i;
  }

  //	LTemp = (Y1 + Y2) / 2;
  //	Y1 = LTemp - (pMainSlot->CarCenterPoint[SlotEndCalIndex].y - LTemp);
  // 	||
  // 	\/

  LTemp = (Y1 + Y2);
  Y1    = LTemp - pMainSlot->CarCenterPoint[SlotEndCalIndex].y;

  for (i = SlotStartIndex; i < SlotEndIndex; i++) {
    if (pMainSlot->CarCenterPoint[i].y > Y1) {
      break;
    }
    SlotStartCalIndex = i;
  }

  if (bCurbLineFited == FALSE) {
    Ang_o1o2 = (pMainSlot->CarAng[SlotStartCalIndex] + pMainSlot->CarAng[SlotEndCalIndex]) / 2.0;
  } else {
    Ang_o1o2 = CurbLineAngWithY;
  }

  SysCoordinateOffsetY = 0;

  // 4. With different scenario, recalculate the Ang_o1o2 and new original center point O2
  if ((bCurbLineFited == FALSE) && (USSPar.APACommonFlags.Bits.bSlotProcSlotObj1Exist == TRUE) &&
      (USSPar.APACommonFlags.Bits.bSlotProcSlotObj2Exist == TRUE)) {
    // without curb.
    // And both obj1 and obj2 exist.
    // park along the line of obj1 and obj2 edge.

    SnsDetectedObjDis = NO_OBJ_DISTANCE;
    j                 = SlotStartIndex;
    i                 = j;
    while (i >= 0) {  //��slot start��ǰ1.3m��Χ�ڲ��ң���һ��С��DisCarToObj1ToCalSlot�Ĵ��ϰ����
      if (pMainSlot->DisFromCarToObj[i] != NO_OBJ_DISTANCE) {
        Y1 = APASlotProcCalTwoPtApproximateDisInt(pMainSlot->CarCenterPoint[i], pMainSlot->CarCenterPoint[SlotStartIndex]);
        if (Y1 > APACal.APATrajCalAPAParkingCoordinateSetUpObj1SearchDis) {
          break;
        }

        if ((pMainSlot->bObjIsBigEnough[i] & APA_SLOT_OBJ_IS_BIG_ENOUGH_CHECK_OBJ_MASK) != 0) {
          if (pMainSlot->DisFromCarToObj[i] < SnsDetectedObjDis) {
            SnsDetectedObjDis = pMainSlot->DisFromCarToObj[i];
            j                 = i;
            if (SnsDetectedObjDis <= DisCarToObj1ToCalSlot) {
              break;
            }
          }
        }
      }
      i--;
    }

    DeltaSnsDtDis = (SnsDetectedObjDis - DisCarToObj1ToCalSlot);
    if ((DeltaSnsDtDis < APACal.APATrajCalAPAParkingCoordinateSetUpUseNearestDisPtCalMaxDeltaObj1Dis) ||   //25cm
        ((DeltaSnsDtDis > APACal.APATrajCalAPAParkingCoordinateSetUpNotUseNearestDisCalMinDeltaObjDis) &&   //35cm
         (DeltaSnsDtDis < APACal.APATrajCalAPAParkingCoordinateSetUpNotUseNearestDisCalMaxDeltaObjDis))) {  //60cm
      // PtSlotStart_c = APASlotProcCalSlotRelativeToCarCoordinateBySlotDisToCar(SnsDetectedObjDis, APASnsIndex);
      PtSlotStart.x = pMainSlot->ObjPt[j].x;
      PtSlotStart.y = pMainSlot->ObjPt[j].y;
    } else {
      SnsDetectedObjDis = DisCarToObj1ToCalSlot;

      PtTemp2 = APASlotProcCalSlotRelativeToCarCoordinateBySlotDisToCar(SnsDetectedObjDis, APASnsIndex);

      PtSlotStart_c.x = APACal.HalfWidthOfCar + DisCarToObj1ToCalSlot;

      Ang1 = pMainSlot->CarAng[SlotStartIndex] - Ang_o1o2;

      fDis            = ((APA_DISTANCE_CAL_FLOAT_TYPE)(MATH_FABS(PtTemp2.x - PtSlotStart_c.x))) * MATH_TAN(Ang1);
      PtSlotStart_c.y = (APA_DISTANCE_CAL_FLOAT_TYPE)fDis + PtTemp2.y;
      j               = SlotStartIndex;
      CarCenterPt.x   = pMainSlot->CarCenterPoint[j].x;
      CarCenterPt.y   = pMainSlot->CarCenterPoint[j].y;
      PtSlotStart     = APATrajCalPointPosWithAngAndCenterPt(PtSlotStart_c, pMainSlot->CarAng[j], CarCenterPt);
    }

    SnsDetectedObjDis = NO_OBJ_DISTANCE;
    j                 = SlotEndIndex;
    for (i = SlotEndIndex; i < pMainSlot->ObjPtCnt; i++) {
      if (pMainSlot->DisFromCarToObj[i] != NO_OBJ_DISTANCE) {
        Y1 = APASlotProcCalTwoPtApproximateDisInt(pMainSlot->CarCenterPoint[i], pMainSlot->CarCenterPoint[SlotEndIndex]);
        if ((Y1 > APACal.APATrajCalAPAParkingCoordinateSetUpObj2SearchDis)
            /*&& (SnsDetectedObjDis != NO_OBJ_DISTANCE)*/) {
          break;
        }
        if ((pMainSlot->bObjIsBigEnough[i] & APA_SLOT_OBJ_IS_BIG_ENOUGH_CHECK_OBJ_MASK) != 0) {

          if (pMainSlot->DisFromCarToObj[i] < SnsDetectedObjDis) {
            SnsDetectedObjDis = pMainSlot->DisFromCarToObj[i];
            j                 = i;
            if (SnsDetectedObjDis <= DisCarToObj2ToCalSlot) {
              break;
            }
          }
        }
      }
    }
    DeltaSnsDtDis = (SnsDetectedObjDis - DisCarToObj2ToCalSlot);
    if ((DeltaSnsDtDis < APACal.APATrajCalAPAParkingCoordinateSetUpUseNearestDisPtCalMaxDeltaObj2Dis) ||
        ((DeltaSnsDtDis > APACal.APATrajCalAPAParkingCoordinateSetUpNotUseNearestDisCalMinDeltaObjDis) &&
         (DeltaSnsDtDis < APACal.APATrajCalAPAParkingCoordinateSetUpNotUseNearestDisCalMaxDeltaObjDis))) {

      // Pto2_c = APASlotProcCalSlotRelativeToCarCoordinateBySlotDisToCar(SnsDetectedObjDis, APASnsIndex);
      Pto2.x               = pMainSlot->ObjPt[j].x;
      Pto2.y               = pMainSlot->ObjPt[j].y;
      SysCoordinateOffsetY = APATrajCalGetTwoPointDisInt(pMainSlot->CarCenterPoint[j].x,
                                                         pMainSlot->CarCenterPoint[j].y,
                                                         pMainSlot->CarCenterPoint[SlotEndIndex].x,
                                                         pMainSlot->CarCenterPoint[SlotEndIndex].y);
      if (SysCoordinateOffsetY < APACal.APATrajCalAPAParkingCoordinateSetUpObj2SearchDis) {
        // OK,

      } else {
        // Data error ??
        SysCoordinateOffsetY = APACal.APATrajCalAPAParkingCoordinateSetUpObj2SearchDis / 2;
      }
    } else {
      SnsDetectedObjDis = DisCarToObj2ToCalSlot;
      PtTemp2           = APASlotProcCalSlotRelativeToCarCoordinateBySlotDisToCar(SnsDetectedObjDis, APASnsIndex);

      Pto2_c.x = APACal.HalfWidthOfCar + DisCarToObj2ToCalSlot;

      Ang1          = pMainSlot->CarAng[SlotEndIndex] - Ang_o1o2;
      fDis          = (MATH_FABS(PtTemp2.x - Pto2_c.x)) * MATH_TAN(Ang1);
      Pto2_c.y      = fDis + PtTemp2.y;
      j             = SlotEndIndex;
      CarCenterPt.x = pMainSlot->CarCenterPoint[j].x;
      CarCenterPt.y = pMainSlot->CarCenterPoint[j].y;
      Pto2          = APATrajCalPointPosWithAngAndCenterPt(Pto2_c, pMainSlot->CarAng[j], CarCenterPt);
    }

    LineIsVOrH = APATrajCalCheckIfTheLineIsVerticalOrHorizontalByTwoPoint(Pto2, PtSlotStart, &K1);

    if (LineIsVOrH == 0) {
      // Normal Line.
      Ang_o1o2 = MATH_ATAN(K1);
      if (K1 < 0) {
        Ang_o1o2 += PI / 2;
      } else {
        Ang_o1o2 -= PI / 2;
      }
    } else if (LineIsVOrH == 1) {
      // Vertical.
      Ang_o1o2 = 0;
    } else {
      // Horizontal.
      // Data error,
      // Ang_o1o2 = PI / 2;
      return FALSE;
    }
  } else {

    bRecalSlotEndPt = FALSE;

    // Search the slot end point calculation car pos (x, y , ang).
    CarCenterPt.x   = pMainSlot->CarCenterPoint[SlotEndIndex].x;
    CarCenterPt.y   = pMainSlot->CarCenterPoint[SlotEndIndex].y;
    SlotEndCalIndex = SlotEndIndex;

    SnsDetectedObjDis = NO_OBJ_DISTANCE;

    if ((CarEndPosType == APA_PARKPROC_CAR_END_POSITION_CLOSE_TO_OBJ1) || (bObj2RegardAsInvalid == TRUE)) {
      bFlag = FALSE;
      // if(bCurbFound == FALSE){
      // Without curb.

      //} else {
      //}
      if (bObj2RegardAsInvalid == FALSE) {
        LTemp = pMainSlotPar->CarPassTheSlotStartPtDistance - APACal.LengthOfCar;
        if ((pMainSlotPar->bSlotCalConfirmed == TRUE) && (LTemp < (APACal.APASlotMaxSlotLengthWithInvalidObj2 + 1500))) {
          // It is second time to rebuild the system coordinate.
          fDis2           = APACal.APATrajCalMinSlotLengthWithInvalidObj2;
          bRecalSlotEndPt = TRUE;
        } else {
          if (SlotLen < APACal.APASlotMaxSlotLengthWithInvalidObj2) {
            // fDis2 = SlotLen;
            // OK. do no need to research the end slot index.
            // bRecalSlotEndPt = FALSE;
          } else {
            fDis2           = APACal.APASlotMaxSlotLengthWithInvalidObj2;
            bRecalSlotEndPt = TRUE;
          }
        }
      } else {
        // The obj2 is regarded as invalid due to obj1 and obj2 offset dis is two big.
        // recalculate the slot length along the obj1.
        if (SlotLen < (APACal.APASlotMaxSlotLengthWithInvalidObj2 + 400)) { // 40cm compensate obj1 and obj2 offset dis.
          fDis2 = SlotLen;                                                  // 300cm compensate obj1 and obj2 offset dis
          fDis2 -= (pMainSlotPar->APASlotDetectionCompensateLengthTail + pMainSlotPar->APASlotDetectionCompensateLengthTail);
          fDis            = fDis2 * fDis2;
          SlotEndCalIndex = SlotEndIndex;
          fDis5           = 0;
          for (i = SlotEndIndex; i < pMainSlot->ObjPtCnt; i++) {
            fDis3 = (pMainSlot->CarCenterPoint[i].y - pMainSlot->CarCenterPoint[SlotStartIndex].y);
            fDis4 = (pMainSlot->CarCenterPoint[i].x - pMainSlot->CarCenterPoint[SlotStartIndex].x);
            fDis3 = fDis3 * fDis3 + fDis4 * fDis4;
            if (fDis3 > fDis) {
              break;
            }
            fDis5           = fDis3;
            SlotEndCalIndex = i;
          }

          if (fDis5 != 0) {
            fDis          = fDis2 - MATH_SQRT(fDis5);
            Ang1          = pMainSlot->CarAng[SlotEndCalIndex];
            CarCenterPt.x = pMainSlot->CarCenterPoint[SlotEndCalIndex].x + fDis * MATH_SIN(Ang1);
            CarCenterPt.y = pMainSlot->CarCenterPoint[SlotEndCalIndex].y + fDis * MATH_COS(Ang1);
          }
        } else {
          bRecalSlotEndPt = TRUE;
          fDis2           = APACal.APASlotMaxSlotLengthWithInvalidObj2;
        }
      }

      if (bRecalSlotEndPt == TRUE) {
        fDis2 -= (pMainSlotPar->APASlotDetectionCompensateLengthTail);
        fDis = fDis2 * fDis2;
        for (i = SlotEndIndex; i > SlotStartIndex; i--) {
          fDis3           = (pMainSlot->CarCenterPoint[i].y - pMainSlot->CarCenterPoint[SlotStartIndex].y);
          fDis4           = (pMainSlot->CarCenterPoint[i].x - pMainSlot->CarCenterPoint[SlotStartIndex].x);
          fDis3           = fDis3 * fDis3 + fDis4 * fDis4;
          SlotEndCalIndex = i;
          if (fDis3 < fDis) {
            break;
          }
        }

        if (SlotEndCalIndex < SlotEndIndex) {
          fDis          = fDis2 - MATH_SQRT(fDis3);
          Ang1          = pMainSlot->CarAng[SlotEndCalIndex];
          CarCenterPt.x = pMainSlot->CarCenterPoint[SlotEndCalIndex].x + fDis * MATH_SIN(Ang1);
          CarCenterPt.y = pMainSlot->CarCenterPoint[SlotEndCalIndex].y + fDis * MATH_COS(Ang1);
        } else {
          bRecalSlotEndPt = FALSE;
        }

        // Ang_o1o2 need to be recalculated.
        // Research the car angle when the rear axis center passing the slot end pt.
        // re cal Ang_o1o2.
        // for(i = SlotStartIndex + 1; i <= SlotEndIndex; i ++) {
        //}
        // Ang_o1o2 = (pMainSlot->CarAng[SlotStartCalIndex]
        //            + pMainSlot->CarAng[SlotEndCalIndex]) / 2.0;
      }
    } else {
      bFlag = TRUE;
      j     = SlotEndIndex;
      for (i = SlotEndIndex; i < pMainSlot->ObjPtCnt; i++) {
        if (pMainSlot->DisFromCarToObj[i] != NO_OBJ_DISTANCE) {
          Y1 = APASlotProcCalTwoPtApproximateDisInt(pMainSlot->CarCenterPoint[i], pMainSlot->CarCenterPoint[SlotEndIndex]);
          if (Y1 > APACal.APATrajCalAPAParkingCoordinateSetUpObj2SearchDis) {
            break;
          }
          if ((pMainSlot->bObjIsBigEnough[i] & APA_SLOT_OBJ_IS_BIG_ENOUGH_CHECK_OBJ_MASK) != 0) {
            if (pMainSlot->DisFromCarToObj[i] < SnsDetectedObjDis) {
              SnsDetectedObjDis = pMainSlot->DisFromCarToObj[i];
              j                 = i;
            }
          }
        }
      }
    }

    DeltaSnsDtDis = (SnsDetectedObjDis - DisCarToObj2ToCalSlot);

    if ((bFlag == TRUE) && ((DeltaSnsDtDis > APACal.APATrajCalAPAParkingCoordinateSetUpNotUseNearestDisCalMinDeltaObjDis) &&
                            (DeltaSnsDtDis < APACal.APATrajCalAPAParkingCoordinateSetUpNotUseNearestDisCalMaxDeltaObjDis))) {
      // Pto2_c = APASlotProcCalSlotRelativeToCarCoordinateBySlotDisToCar(SnsDetectedObjDis, APASnsIndex);
      Pto2.x               = pMainSlot->ObjPt[j].x;
      Pto2.y               = pMainSlot->ObjPt[j].y;
      SysCoordinateOffsetY = APATrajCalGetTwoPointDisInt(pMainSlot->CarCenterPoint[j].x,
                                                         pMainSlot->CarCenterPoint[j].y,
                                                         pMainSlot->CarCenterPoint[SlotEndIndex].x,
                                                         pMainSlot->CarCenterPoint[SlotEndIndex].y);
      if (SysCoordinateOffsetY < APACal.APATrajCalAPAParkingCoordinateSetUpObj2SearchDis) {
        // OK,

      } else {
        // Data error ??
        SysCoordinateOffsetY = APACal.APATrajCalAPAParkingCoordinateSetUpObj2SearchDis / 2;
      }
    } else {
      SnsDetectedObjDis = DisCarToObj2ToCalSlot;
      PtTemp2           = APASlotProcCalSlotRelativeToCarCoordinateBySlotDisToCar(SnsDetectedObjDis, APASnsIndex);

      Pto2_c.x = APACal.HalfWidthOfCar + DisCarToObj2ToCalSlot;

      Ang1     = pMainSlot->CarAng[SlotEndCalIndex] - Ang_o1o2;
      fDis     = (MATH_FABS(PtTemp2.x - Pto2_c.x)) * MATH_TAN(Ang1);
      Pto2_c.y = fDis + PtTemp2.y;

      Pto2 = APATrajCalPointPosWithAngAndCenterPt(Pto2_c, pMainSlot->CarAng[SlotEndCalIndex], CarCenterPt);
    }

    // Recal slot len:
    if ((bRecalSlotEndPt == TRUE) || (bObj2RegardAsInvalid == TRUE)) {

      PtSlotStart   = APASlotProcCalSlotRelativeToCarCoordinateBySlotDisToCar(pMainSlotPar->SlotCalDisCarToObj1, APASnsIndex);
      CarCenterPt.x = pMainSlot->CarCenterPoint[SlotStartIndex].x;
      CarCenterPt.y = pMainSlot->CarCenterPoint[SlotStartIndex].y;

      PtSlotStart = APATrajCalPointPosWithAngAndCenterPt(PtSlotStart, pMainSlot->CarAng[SlotStartIndex], CarCenterPt);

      fDis    = APATrajCalGetTwoPointDisFloat(PtSlotStart, Pto2);
      SlotLen = (APA_DISTANCE_TYPE)fDis;
      SlotLen += (pMainSlotPar->APASlotDetectionCompensateLengthTail);
      //+ pMainSlotPar->APASlotDetectionCompensateLengthHead);
    }
  }
  // Trajcal will use the SlotLen to calculate the trajectory.
  pMainSlotPar->SlotLength = SlotLen;
  pMainSlotPar->SlotDepth  = SlotDepth;

#ifdef PC_TRAJECTORY_DEBUG12
  if (cDlgDebug == 5) {
    CDlgTrajectoryDebug Dlg;
    Dlg.m_pSlotInfo       = &USSPar.Slot[USSPar.APARightSlotDataIndex];
    Dlg.m_pSubSlotInfo    = &USSPar.Slot[USSPar.APALeftSlotDataIndex];
    Dlg.m_pTrajectoryData = NULL;
    Dlg.m_CurCarAng       = pMainSlot->CarAng[SlotEndIndex];
    Dlg.m_CurCarPos.x     = pMainSlot->CarCenterPoint[SlotEndIndex].x;
    Dlg.m_CurCarPos.y     = pMainSlot->CarCenterPoint[SlotEndIndex].y;
    /*Dlg.m_CircleCenterPt[0] = CPoint(StepData[StepNum].CarTurningCenterPt.x, StepData[StepNum].CarTurningCenterPt.y);
    Dlg.m_CircleRadius[0] = StepData[StepNum].CarRearAxisCenterTurningRadius + APACal.APATrajCalMinRearAxisCenterTurningRadius;
    Dlg.m_CircleCenterPt[1] = CPoint(NextKeyPoint.Coordinate.x, NextKeyPoint.Coordinate.y);
    Dlg.m_CircleRadius[1] = APACal.APATrajCalMinRearAxisCenterTurningRadius;
    Dlg.m_CircleCenterPt[2] = CPoint(StepData[StepNum].CarTurningCenterPt.x, StepData[StepNum].CarTurningCenterPt.y);
    Dlg.m_CircleRadius[2] = StepData[StepNum].CarRearAxisCenterTurningRadius;
    Dlg.m_CircleNum = 3;*/

    Dlg.m_CircleCrossPt[0] = CPoint(Pto2.x, Pto2.y);
    Dlg.m_CircleCrossPt[1] = CPoint(pMainSlot->ObjPt[SlotEndIndex].x, pMainSlot->ObjPt[SlotEndIndex].y);
    Dlg.m_CircleCrossPtNum = 2;

    int ID = Dlg.DoModal();
  }
#endif

  // 5. Determine the car end position coordinate in the new O2 system (Xce, Yce):

  // USSPar.TrajCalCarParkingCurrentStepIndex = 0;
  // bAPATrajCalCarParkAlongCurb = FALSE;

  Y1 = (SlotLen - APACal.LengthOfCar) / 2;

  YceMid = Y1 - SlotLen + APACal.LenBetweenRAxisAndRBumper;

  if (CarEndPosType == APA_PARKPROC_CAR_END_POSITION_CLOSE_TO_OBJ1) {
    USSPar.TrajCalCarEndPos.Coordinate.y = APACal.LenBetweenRAxisAndRBumper + APACal.APAParkProcCarEndPositionToObj1Dis - SlotLen;
  } else if (CarEndPosType == APA_PARKPROC_CAR_END_POSITION_CLOSE_TO_OBJ2) {
    USSPar.TrajCalCarEndPos.Coordinate.y = -(APACal.LenBetweenRAxisAndFBumper + APACal.APAParkProcCarEndPositionToObj2Dis);
  } else {
    // APA_PARKPROC_CAR_END_POSITION_MID_BETWEEN_OBJ1_AND_OBJ2
    USSPar.TrajCalCarEndPos.Coordinate.y = YceMid;
  }

  USSPar.TrajCalCarEndPos.CarAng       = 0;
  USSPar.TrajCalCarEndPosLine.A        = 1.0;
  USSPar.TrajCalCarEndPosLine.B        = 0.0;
  USSPar.TrajCalCarEndPosLine.C        = USSPar.TrajCalCarEndPos.Coordinate.x;
  USSPar.TrajCalCarEndPosLine.LineType = APALineIsVertical;

  m = bCurbLineFited;
  if (SlotLen < (APACal.LengthOfCar + 1300)) { // actually it is 5 or 6 step parking.
    Ang_o1o2 += APACal.APATrajCalParalAPAParkingCoordinateYOffsetAngle5[m][CarParkAtLeftOrRightSide];
  } else if (SlotLen < (APACal.LengthOfCar + 1400)) { // actully it is 5 or 4 step parking
    Ang_o1o2 += APACal.APATrajCalParalAPAParkingCoordinateYOffsetAngle4[m][CarParkAtLeftOrRightSide];
  } else if (SlotLen < (APACal.LengthOfCar + 1500)) { // actually it is 5 or 4 step parking.
    Ang_o1o2 += APACal.APATrajCalParalAPAParkingCoordinateYOffsetAngle3[m][CarParkAtLeftOrRightSide];
  } else if (SlotLen < (APACal.LengthOfCar + 1600)) { // actually it is 4 step parking.
    Ang_o1o2 += APACal.APATrajCalParalAPAParkingCoordinateYOffsetAngle2[m][CarParkAtLeftOrRightSide];
  } else {
    Ang_o1o2 += APACal.APATrajCalParalAPAParkingCoordinateYOffsetAngle1[m][CarParkAtLeftOrRightSide];
  }

#ifdef APA_SUPPORT_SLOT_POINT_COMPENSATE_ADJ
  Y1 = APACal.APATrajCalAPAParkingCoordinateYOffsetDis;
#else
  Y1 = pMainSlotPar->APASlotDetectionCompensateLengthHead + APACal.APATrajCalAPAParkingCoordinateYOffsetDis;
  // When the car is turning around the obj2, to make sure it will not hit the obj2. use a more safety dis to the obj2.
  // Y1 = APACal.APATrajCalAPAParkingCoordinateYOffsetDis;
#endif

  Y1 -= SysCoordinateOffsetY;

  APATrajCalTransferCoordinateToNewWoldCoordinateSystem(
      SlotLaneCalMode, Pto2, Ang_o1o2, Y1, CarEndPosType, SlotLen, pNewCarAngToBeTransfered, pNewCarCenterPtToBeTransfered);

  if ((SlotLaneCalMode) == 0) {
    (*pSubSlotCaled) = 0;
  } else {
    (*pSubSlotCaled) = 1;
  }

  if (bCurbLineFited == TRUE) {
    // recalculate the car end pos.X according to the curb line.
    bCurbLineFited = APATrajCalFitCurbLineAccordingToSlotData(
        pMainSlot, pMainSlotPar->DisCarToObj2ByPassingSlot, SlotStartIndex, SlotEndIndex, SlotDepth, &CurbLineAngWithY, &CurbLine);
  }

  // Check the car angle at slot start point and end point is reasonable or not with the new
  // system coordinate ??
  // a. search the car pos at slot start point.

  SlotStartCalIndex = SlotStartIndex;
  SlotEndCalIndex   = SlotEndIndex;
  for (i = SlotEndIndex + 1; i < pMainSlot->ObjPtCnt; i++) {
    SlotEndCalIndex = i;
    if (pMainSlot->CarCenterPoint[i].y > 0) {
      break;
    }
  }

  Y1 = -SlotLen;

  for (i = SlotStartIndex + 1; i < SlotEndIndex; i++) {
    if (pMainSlot->CarCenterPoint[i].y > Y1) {
      break;
    }
    SlotStartCalIndex = i;
  }

  i = APATrajCalCoordinateSetupCheckObjCase_Obj1ExistObj2Exist;
  if (USSPar.APACommonFlags.Bits.bSlotProcSlotObj1Exist == TRUE) {
    if (USSPar.APACommonFlags.Bits.bSlotProcSlotObj2Exist == TRUE) {
      // Both obj1 and obj2 exist.
    } else {
      i = APATrajCalCoordinateSetupCheckObjCase_Obj1ExistObj2Not;
    }

  } else {
    i = APATrajCalCoordinateSetupCheckObjCase_Obj1NotObj2Exist;
  }

  if ((pMainSlot->CarCenterPoint[SlotStartCalIndex].x < APACal.APATrajCalCoordinateSetupCheckAllowMinCarPosXAtObj1[i]) ||
      (pMainSlot->CarCenterPoint[SlotStartCalIndex].x > APACal.APATrajCalCoordinateSetupCheckAllowMaxCarPosXAtObj1[i]) ||
      (pMainSlot->CarAng[SlotStartCalIndex] < APACal.APATrajCalCoordinateSetupCheckAllowMinCarAngAtObj1[i]) ||
      (pMainSlot->CarAng[SlotStartCalIndex] > APACal.APATrajCalCoordinateSetupCheckAllowMaxCarAngAtObj1[i]) ||
      (pMainSlot->CarCenterPoint[SlotEndCalIndex].x < APACal.APATrajCalCoordinateSetupCheckAllowMinCarPosXAtObj2[i]) ||
      (pMainSlot->CarCenterPoint[SlotEndCalIndex].x > APACal.APATrajCalCoordinateSetupCheckAllowMaxCarPosXAtObj2[i]) ||
      (pMainSlot->CarAng[SlotEndCalIndex] < APACal.APATrajCalCoordinateSetupCheckAllowMinCarAngAtObj2[i]) ||
      (pMainSlot->CarAng[SlotEndCalIndex] > APACal.APATrajCalCoordinateSetupCheckAllowMaxCarAngAtObj2[i])) {
    if (bCurbLineFited == TRUE) {
      (*pCalResult) = 1;
    }
    return FALSE;
  }

  if (SlotLen > APACal.APATrajCalCarEndPosXOffsetToObj1AndObj2LineIfNoCurbDtdSlotLen2) {
    // SlotLen > length of car + 1.6m
    j = 0;
  } else if (SlotLen > APACal.APATrajCalCarEndPosXOffsetToObj1AndObj2LineIfNoCurbDtdSlotLen1) {
    //  length of car + 1.3m
    j = 1;
  } else {
    j = 2;
  }

  Ang1 = MATH_FABS(pMainSlot->CarAng[SlotEndIndex] - pMainSlot->CarAng[SlotStartIndex]);
  if (Ang1 < -APACal.APATrajCalSetupSysCoordinateCarDriveStraightlyTolCarAngle1) {
    // convex road.
    k = APATrajCalCoordinateSetupRoad_Convex;
  } else if (Ang1 < APACal.APATrajCalSetupSysCoordinateCarDriveStraightlyTolCarAngle1) {
    // straight road.
    k = APATrajCalCoordinateSetupRoad_Straight;
  } else {
    k = APATrajCalCoordinateSetupRoad_Concave;
  }

  if (i == APATrajCalCoordinateSetupCheckObjCase_Obj1ExistObj2Exist) {
    // Both obj1 and 2 exist.
    if (pMainSlotPar->Obj1Type < APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_BIG_RISING_AND_FALLING_SHAPE) {
      // Small obj
      m = APATrajCalCoordinateSetupObj_SmallObj;
    } else if (pMainSlotPar->Obj1Type <= APA_SLOT_OBJ_TYPE_PER_CAR_WITH_BIG_FLAT_BIG_WIDTH) {
      // Perpendicular car. or car with big angle.
      m = APATrajCalCoordinateSetupObj_PerpendicularCar;
    } else if (pMainSlotPar->Obj1Type <= APA_SLOT_OBJ_TYPE_CAR_ANGULAR_NEG_30DEG_FLAT_SHAPE_AT_START) {
      // neg angular car.
      m = APATrajCalCoordinateSetupObj_NegAngularCar;
    } else if (pMainSlotPar->Obj1Type <= APA_SLOT_OBJ_TYPE_CAR_ANGULAR_30DEG_FLAT_SHAPE_AT_START) {
      // positive angular car.
      m = APATrajCalCoordinateSetupObj_PosAngularCar;
    } else {
      // parallel car
      m = APATrajCalCoordinateSetupObj_ParallelCar;
    }
    if (pMainSlotPar->Obj2Type <= APA_SLOT_OBJ_TYPE_CAR_ANGULAR_NEG_30DEG_FLAT_SHAPE_AT_START) {
      // obj2 is small obj, perpendicular car, or neg angular car.
      // refer to obj1.
    } else if (pMainSlotPar->Obj2Type <= APA_SLOT_OBJ_TYPE_CAR_ANGULAR_30DEG_FLAT_SHAPE_AT_START) {
      // positive angular car.
      m = APATrajCalCoordinateSetupObj_PosAngularCar;
    } else {
      // parallel car
      if (m <= APATrajCalCoordinateSetupObj_PerpendicularCar) {
        // use parallel car as reference.
        m = APATrajCalCoordinateSetupObj_ParallelCar;
      }
    }
    X1 = APACal.APATrajCalCarEndPosXOffsetToObj1AndObj2LineIfNoCurbDtdBothObjExist[CarParkAtLeftOrRightSide][k][j][m];
  } else if (i == APATrajCalCoordinateSetupCheckObjCase_Obj1ExistObj2Not) {
    if (pMainSlotPar->Obj1Type < APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_BIG_RISING_AND_FALLING_SHAPE) {
      // Small obj
      m = APATrajCalCoordinateSetupObj_SmallObj;
    } else if (pMainSlotPar->Obj1Type <= APA_SLOT_OBJ_TYPE_PER_CAR_WITH_BIG_FLAT_BIG_WIDTH) {
      // Perpendicular car. or car with big angle.
      m = APATrajCalCoordinateSetupObj_PerpendicularCar;
    } else if (pMainSlotPar->Obj1Type <= APA_SLOT_OBJ_TYPE_CAR_ANGULAR_NEG_30DEG_FLAT_SHAPE_AT_START) {
      // neg angular car.
      m = APATrajCalCoordinateSetupObj_NegAngularCar;
    } else if (pMainSlotPar->Obj1Type <= APA_SLOT_OBJ_TYPE_CAR_ANGULAR_30DEG_FLAT_SHAPE_AT_START) {
      // positive angular car.
      m = APATrajCalCoordinateSetupObj_PosAngularCar;
    } else {
      // parallel car
      m = APATrajCalCoordinateSetupObj_ParallelCar;
    }
    X1 = APACal.APATrajCalCarEndPosXOffsetToObj1AndObj2LineIfNoCurbDtdObj1Exist[CarParkAtLeftOrRightSide][k][m];
  } else {
    if (pMainSlotPar->Obj2Type < APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_BIG_RISING_AND_FALLING_SHAPE) {
      // Small obj
      m = APATrajCalCoordinateSetupObj_SmallObj;
    } else if (pMainSlotPar->Obj2Type <= APA_SLOT_OBJ_TYPE_PER_CAR_WITH_BIG_FLAT_BIG_WIDTH) {
      // Perpendicular car. or car with big angle.
      m = APATrajCalCoordinateSetupObj_PerpendicularCar;
    } else if (pMainSlotPar->Obj2Type <= APA_SLOT_OBJ_TYPE_CAR_ANGULAR_NEG_30DEG_FLAT_SHAPE_AT_START) {
      // neg angular car.
      m = APATrajCalCoordinateSetupObj_NegAngularCar;
    } else if (pMainSlotPar->Obj2Type <= APA_SLOT_OBJ_TYPE_CAR_ANGULAR_30DEG_FLAT_SHAPE_AT_START) {
      // positive angular car.
      m = APATrajCalCoordinateSetupObj_PosAngularCar;
    } else {
      // parallel car
      m = APATrajCalCoordinateSetupObj_ParallelCar;
    }
    X1 = APACal.APATrajCalCarEndPosXOffsetToObj1AndObj2LineIfNoCurbDtdObj2Exist[CarParkAtLeftOrRightSide][k][m];
  }

  X2 = APACal.HalfWidthOfCar + X1; // Xce,

  // cal car rear bumper start pos and front bumper end pos.
  Y5 = (APA_DISTANCE_TYPE)USSPar.TrajCalCarEndPos.Coordinate.y;
  Y6 = Y5 - APACal.LenBetweenRAxisAndRBumper + APACal.APATrajCalCarEndPosHitCurbCheckRearBumperOffsetDis;  // rear bumper
  Y5 = Y5 + APACal.LenBetweenRAxisAndFBumper + APACal.APATrajCalCarEndPosHitCurbCheckFrontBumperOffsetDis; // front bumper

  if (bCurbFound == TRUE) {
    // Curb detected.
    //
    // Xce should great than 0.!!!!!!!!!
    //
    if ((SlotDepth < APACal.APATrajCalCarParkingAlongCurbMinSlotDepthRefObject) &&
        (APACal.APACalCommonFlags.Bits.bAPATrajCalCarParkingAlongCurbIfCurbDetected == FALSE)) {
      // Park on curb.
      USSPar.TrajCalCarEndPos.Coordinate.x = APACal.HalfWidthOfCar; // Xce,
      USSPar.TrajCalCarEndPos.Coordinate.x += X1;
    } else {
      if (bCurbLineFited == TRUE) {
        // search the slot end pos.y arae to determine the Xce.
        i  = SlotStartIndex;
        j  = SlotEndIndex - 1;
        Y1 = Y6;   // USSPar.TrajCalCarEndPos.Coordinate.y - APACal.LenBetweenRAxisAndRBumper;
        Y2 = Y5;   // USSPar.TrajCalCarEndPos.Coordinate.y + APACal.LenBetweenRAxisAndFBumper;
        X1 = 5000; // 5m.
        while (i < j) {
          i++;
          if ((pMainSlot->DisFromCarToObj[i] != NO_OBJ_DISTANCE) && (pMainSlot->ObjPt[i].y > Y2)) {
            break;
          }
          LTemp = MATH_ABS(pMainSlot->DisFromCarToObj[i] - SlotDepth);
          if (LTemp < APACal.APASlotCurbLineFitAllowSnsDtObjDisTolerance) {
            // OK, within tol
            if ((pMainSlot->ObjPt[i].y > Y1) && (pMainSlot->ObjPt[i].x > -500)) {
              // OK, within range.
              if (X1 > pMainSlot->ObjPt[i].x) {
                X1 = pMainSlot->ObjPt[i].x;
              }
            }
          }
        }
        // OK, compare the X1 and the Curb Line.B
        if (CurbLine.LineType == APALineIsVertical) {
          LTemp = CurbLine.C;
        } else {
          // ??? Actually code should never reach???
          // Just use X1 ??
          fDis  = (USSPar.TrajCalCarEndPos.Coordinate.y - CurbLine.C) / CurbLine.A;
          LTemp = fDis;
        }
        if (X1 == 5000) {
          // ?? data error ??
          X1 = SlotDepthRefObj - APACal.HalfWidthOfCar - APACal.APATrajCalCarEndPosDisToCurb[CarParkAtLeftOrRightSide]; // Xce,
        } else {
          if (X1 < LTemp) {
            Y1 = (LTemp - X1);
            if (Y1 < APACal.APASlotEndPosXAllowCurbLineToObjDisTolerance) {
              // Allow tolerance
              X1 += Y1 / 2;
            } else {
              // Just use X1.
              X1 += APACal.APASlotEndPosXOutOfAllowCurbLineToObjDisToleranceCompensateDis;
            }
          } else {
            // Curb line is a little offset Left side ??? concave road.
            // Just use X1.
          }
          X1 = X1 - APACal.HalfWidthOfCar - APACal.APATrajCalCarEndPosDisToCurb[CarParkAtLeftOrRightSide]; // Xce,
        }
      } else {
        // search the nearest points of curb.
        LTemp = SlotLen;
        X1    = NO_OBJ_DISTANCE;
        for (i = SlotStartIndex; i < SlotEndIndex; i++) {
          if ((pMainSlot->bObjIsBigEnough[i] & APA_SLOT_OBJ_IS_BIG_ENOUGH_CHECK_OBJ_MASK) != 0) {

            if (pMainSlot->ObjPt[i].y > Y5) {
              break;
            }
            if (pMainSlot->ObjPt[i].y > Y6) {
              if (pMainSlot->ObjPt[i].x < X1) {
                // Curb found.
                X1 = pMainSlot->ObjPt[i].x;
              }
            }
          }
        }

        if (X1 == NO_OBJ_DISTANCE) {
          // ?? no curb found
          X1 = X2;
        } else {
          X1 = X1 - APACal.HalfWidthOfCar - APACal.APATrajCalCarEndPosDisToCurb[CarParkAtLeftOrRightSide]; // Xce,
        }
      }
      USSPar.TrajCalCarEndPos.Coordinate.x = X1;
      Ang1                                    = (pMainSlot->CarAng[SlotEndCalIndex] - pMainSlot->CarAng[SlotStartCalIndex]);
      if (Ang1 > APACal.APATrajCalSetupSysCoordinateCarDriveStraightlyTolCarAngle2) {
        // Left circle road
        fDis  = APACal.APATrajCalCarEndPosXOffsetToObj1AndObj2LineIfCurbDtdLCircle;
        fDis2 = APACal.APATrajCalCarEndPosXOffsetToObj1AndObj2LineMaxDisIfCurbDtdLCircle;
        fDis += (fDis2 * APACal.APATrajCalCarEndPosXOffsetToObj1AndObj2LineCalRatioIfCurbDtdLCircle * MATH_FABS(Ang1));
        if (APACal.APATrajCalCarEndPosXOffsetToObj1AndObj2LineMaxDisIfCurbDtdLCircle > 0) {
          if (fDis > fDis2) {
            fDis = fDis2;
          }
        } else {
          if (fDis < fDis2) {
            fDis = fDis2;
          }
        }
        USSPar.TrajCalCarEndPos.Coordinate.x += fDis;
      } else if (Ang1 < -APACal.APATrajCalSetupSysCoordinateCarDriveStraightlyTolCarAngle2) {
        // right circle road
        fDis  = APACal.APATrajCalCarEndPosXOffsetToObj1AndObj2LineIfCurbDtdRCircle;
        fDis2 = APACal.APATrajCalCarEndPosXOffsetToObj1AndObj2LineMaxDisIfCurbDtdRCircle;
        fDis += (fDis2 * APACal.APATrajCalCarEndPosXOffsetToObj1AndObj2LineCalRatioIfCurbDtdRCircle * MATH_FABS(Ang1));
        if (APACal.APATrajCalCarEndPosXOffsetToObj1AndObj2LineMaxDisIfCurbDtdRCircle > 0) {
          if (fDis > fDis2) {
            fDis = fDis2;
          }
        } else {
          if (fDis < fDis2) {
            fDis = fDis2;
          }
        }
        USSPar.TrajCalCarEndPos.Coordinate.x += fDis;
      } else {
        // straight road.
      }
      if (SlotLen < APACal.APATrajCalCarEndPosXOffsetFromCurbMinSlotLength) {

        if (USSPar.TrajCalCarEndPos.Coordinate.x > APACal.APATrajCalCarEndPosXOffsetFromCurbMinEndPosX) {
          LTemp = USSPar.TrajCalCarEndPos.Coordinate.x - APACal.HalfWidthOfCar;
          fDis  = LTemp;
          fDis *= APACal.APATrajCalCarEndPosXOffsetFromCurbCalFactor;
          fDis += APACal.APATrajCalCarEndPosXOffsetFromCurbMinEndPosX;
          if (USSPar.TrajCalCarEndPos.Coordinate.x > fDis) {
            USSPar.TrajCalCarEndPos.Coordinate.x = fDis;
          }
        }
      }

      LTemp = APACal.LengthOfCar + APACal.APATrajCalCarEndPosXOffsetFromCurbSlotDeltaLength;
      if (SlotLen < LTemp) {

        fY2      = APACal.APATrajCalCarEndPosXOffsetFromCurbDis1; // 5cm
        fY1      = APACal.APATrajCalCarEndPosXOffsetFromCurbDis2; // 10cm
        fX1      = APACal.LengthOfCar + 800;
        fX2      = LTemp;
        fSlotLen = SlotLen;
        fX1      = APATrajCalTwoPointInterpolationCalculation(fY1, fY2, fX1, fX2, fSlotLen);
        USSPar.TrajCalCarEndPos.Coordinate.x += fX1;
      }

      if (bCurbLineFited == FALSE) {
        X1 = (APA_DISTANCE_TYPE)USSPar.TrajCalCarEndPos.Coordinate.x;
        if (X2 < X1) {
          USSPar.TrajCalCarEndPos.Coordinate.x = X2;
        }
      }
    }
  } else {
    USSPar.TrajCalCarEndPos.Coordinate.x = X2;
  }

  if ((USSPar.TrajCalCarEndPos.Coordinate.x < APACal.APATrajCalCarEndPosAllowedMinX) ||
      (USSPar.TrajCalCarEndPos.Coordinate.x > APACal.APATrajCalCarEndPosAllowedMaxX)) {
    // car end pos.x out of allowed range.
    if (bCurbLineFited == TRUE) {
      (*pCalResult) = 1;
    }
    return FALSE;
  }

  // Check if the curb will hit the car??
  if (CarEndPosType == APA_PARKPROC_CAR_END_POSITION_CLOSE_TO_OBJ2) {
    Y3 = YceMid;
    Y4 = Y3 - APACal.LenBetweenRAxisAndRBumper + APACal.APATrajCalCarEndPosHitCurbCheckRearBumperOffsetDis;
    Y3 = Y3 + APACal.LenBetweenRAxisAndFBumper + APACal.APATrajCalCarEndPosHitCurbCheckFrontBumperOffsetDis;
  } else {
    Y3 = Y5;
    Y4 = Y6;
  }
  X1    = USSPar.TrajCalCarEndPos.Coordinate.x + APACal.HalfWidthOfCar + APACal.APATrajCalCarEndPosHitCurbCheckCarSideOffsetDis;
  bFlag = FALSE;
  for (i = SlotStartIndex; i < SlotEndIndex; i++) {
    if ((pMainSlot->bObjIsBigEnough[i] & APA_SLOT_OBJ_IS_BIG_ENOUGH_CHECK_OBJ_MASK) != 0) {
      if (CarEndPosType == APA_PARKPROC_CAR_END_POSITION_CLOSE_TO_OBJ2) {
        if ((pMainSlot->ObjPt[i].y > Y3) && (bFlag == FALSE)) {
          break;
        }

        if (pMainSlot->ObjPt[i].y > Y4) {
          if (pMainSlot->ObjPt[i].x < X1) {
            // car will hit obj.
            bFlag = TRUE;
          }
        }
      }
      if (pMainSlot->ObjPt[i].y > Y5) {
        break;
      }
      if (pMainSlot->ObjPt[i].y > Y6) {
        if (pMainSlot->ObjPt[i].x < X1) {
          // car will hit obj.
          if (bCurbLineFited == TRUE) {
            (*pCalResult) = 1;
          }
          return FALSE;
        }
      }
    }
  }

  // USSPar.TrajCalTheEndPosXHasBeenReCaled = FALSE;
  // USSPar.TrajCalCurbDetected             = bCurbFound;
  USSPar.TrajCalCarEndPosLine.C          = USSPar.TrajCalCarEndPos.Coordinate.x;

#ifdef APA_SLOT_SUPPORT_DEBUG1
  if ((pMainSlotPar->Obj1Type != APA_SLOT_OBJ_TYPE_UNKNOWN) &&
      ((SlotStartIndex < (pMainSlotPar->Obj1EndPtIndex)) || ((SlotEndIndex) > (pMainSlotPar->Obj1StartPtIndex)))) {

    // Data error ??

    // cSlotDebug = 1;
  }
#endif

  return TRUE;
}

/*************************************************************************************************************************************************
** Syntax :  void USS(void)                                                                                                                     **
**                                                                                                                                              **
** Service ID:   : NA                                                                                                                           **
**                                                                                                                                              **
** Sync/Async:   : Synchronous                                                                                                                  **
**                                                                                                                                              **
** Reentrancy:   : Non Reentrant                                                                                                                **
**                                                                                                                                              **
** Parameters (in): none                                                                                                                        **
**                                                                                                                                              **
** Parameters (out): none                                                                                                                       **
**                                                                                                                                              **
** Return value: none                                                                                                                           **
**                                                                                                                                              **
** Description : ..                                                                                                                             **
*************************************************************************************************************************************************/
BOOLEAN APATrajCalPerpendSetupSystemCoordinateAccordingToSlotData(void) {

  APA_INDEX_TYPE i, j;
  APASlotOutlineCoordinateDataType *pMainSlot;
  APASlotParameterType *pMainSlotPar;
  APACoordinateDataCalFloatType CenterPt, DstPt, Pto2_c, Pto2, PtTemp2;
  APACoordinateDataCalFloatType PtSlotStart_c, PtSlotStart, PtSlotEnd, CarCenterPt;
  APA_ANGLE_TYPE CarAng;
  APA_ANGLE_CAL_FLOAT_TYPE Ang_o1o2;
  APA_ANGLE_CAL_FLOAT_TYPE Ang1;
  APA_DISTANCE_CAL_FLOAT_TYPE fDis, fDis2, fDis3, fDis4, fDis5;
  APA_RATIO_TYPE K1;
  APA_DISTANCE_TYPE SnsDetectedObjDis, DisCarToObj1ByPassingSlot, DisCarToObj2ByPassingSlot;
  APA_DISTANCE_TYPE DisCarToObj1ToCalSlot, DisCarToObj2ToCalSlot;
  APA_DISTANCE_TYPE LTemp, X1, Y1, Y2, SlotDepthRefCarSide, SlotDepthRefObj, MinPSlotLen;
  APA_DISTANCE_TYPE SlotDepth, SlotLen, SlotDepth2, SlotLen2, SlotDepth3, SlotLen3;
  BOOLEAN bCurbFound, bRecalSlotEndPt, bObj2RegardAsInvalid, bUseFirstSlot, bObj2PtFound;
  APA_ENUM_TYPE APASnsIndex, LineIsVOrH;
  APA_INDEX_TYPE SlotEndIndex, SlotStartIndex, SlotEndCalIndex, SlotStartCalIndex;
  APA_ENUM_TYPE EndPosYCalMethod, CarEndPosType, Obj2TypeGroupIndex;
  APA_ENUM_TYPE CarParkAtLeftOrRightSide;
  APACoordinateDataType PtTemp;

  APA_ANGLE_CAL_FLOAT_TYPE NewCarAngToBeTransfered;
  APACoordinateDataCalFloatType NewCarCenterPtToBeTransfered;

  BOOLEAN bObjIsBigEnough;

  pMainSlot      = &USSPar.Slot[USSPar.APARightSlotDataIndex].SlotOutline.Lane;
  pMainSlotPar   = &USSPar.Slot[USSPar.APARightSlotDataIndex].SlotPar[USSPar.TrajCalCurrentCalSlotIndex];
  SlotStartIndex = pMainSlotPar->SlotStartIndex;
  SlotEndIndex   = pMainSlotPar->SlotEndIndex;
  APASnsIndex    = APACal.APASlotRAPASnsIndex;

  if (pMainSlot->ObjPt[SlotStartIndex].y < 0) {
    return TRUE;
  }

#ifdef APA_SLOT_SUPPORT_DEBUG1
  if ((pMainSlotPar->Obj1Type != APA_SLOT_OBJ_TYPE_UNKNOWN) &&
      ((SlotStartIndex < (pMainSlotPar->Obj1EndPtIndex)) || ((SlotStartIndex) > (pMainSlotPar->Obj1StartPtIndex)))) {

    // Data error ??

    // cSlotDebug = 1;
  }
#endif

  // 0. recheck the slot end index ??
  // Case:
  /*

Start   EndIndex

  -----*
       |   Pole        *--------------
  Car1 |   *           |
       |   | Actual    | car 2.
       |   |  Slot     |
       |   |           |
       |   |           |
       |---|-----------|

  */

  LTemp = APATrajCalGetTwoPointDisInt(pMainSlot->CarCenterPoint[SlotStartIndex].x,
                                      pMainSlot->CarCenterPoint[SlotStartIndex].y,
                                      pMainSlot->CarCenterPoint[SlotEndIndex].x,
                                      pMainSlot->CarCenterPoint[SlotEndIndex].y);

  if (LTemp < APACal.APASlotPRegardAsInvalidSlotEndPtMinDeltaCarPos) {
    // Data error ???
    return FALSE;
  }

  if (LTemp < APACal.APASlotPNeedToCheckSlotEndPtMinSlotLen) {
    // Check if the above case exist?
    for (i = SlotEndIndex + 1; i < pMainSlot->ObjPtCnt; i++) {
      if (pMainSlot->DisFromCarToObj[i] >= APACal.APASlotPMinSlotDepth) {
        // Check the pole width.
        LTemp = APATrajCalGetTwoPointDisInt(pMainSlot->CarCenterPoint[i].x,
                                            pMainSlot->CarCenterPoint[i].y,
                                            pMainSlot->CarCenterPoint[SlotEndIndex].x,
                                            pMainSlot->CarCenterPoint[SlotEndIndex].y);

        if (LTemp < APACal.APASlotPNeedToCheckSlotEndPtMinPoleWidth) {
          // Check next slot length
          for (j = i + 1; j < pMainSlot->ObjPtCnt; j++) {
            if (pMainSlot->DisFromCarToObj[j] < APACal.APASlotPMinSlotDepth) {
              // Check the slot width.
              LTemp = APATrajCalGetTwoPointDisInt(
                  pMainSlot->CarCenterPoint[i].x, pMainSlot->CarCenterPoint[i].y, pMainSlot->CarCenterPoint[j].x, pMainSlot->CarCenterPoint[j].y);
              LTemp += pMainSlotPar->APASlotDetectionCompensateLengthHead + pMainSlotPar->APASlotDetectionCompensateLengthTail;
              if (LTemp > APACal.APASlotPMinSmallSlotLen) {
                // OK, Valid slot.
                SlotStartIndex = i;
                SlotEndIndex   = j;
              }
              break;
            }
          }
        }
        break;
      }
    }
  }

  // 1. Cal the dis from car to obj by passing slot.

  DisCarToObj1ByPassingSlot = pMainSlotPar->DisCarToObj1ByPassingSlot;
  DisCarToObj2ByPassingSlot = pMainSlotPar->DisCarToObj2ByPassingSlot;

  bObj2RegardAsInvalid = FALSE;

  // 1.1 Check if the Offset distance between Obj1 and Obj2 is great than the calibration value.
  // if yes, just treat as the obj1 or obj2 is invalid.
  if ((DisCarToObj1ByPassingSlot == NO_OBJ_DISTANCE) && (DisCarToObj2ByPassingSlot == NO_OBJ_DISTANCE)) {
    // Data error ??
    return FALSE;
  } else if ((DisCarToObj1ByPassingSlot != NO_OBJ_DISTANCE) && (DisCarToObj2ByPassingSlot != NO_OBJ_DISTANCE)) {
    if (pMainSlotPar->SlotType == APA_SLOT_TYPE_PARALLEL) {
      Y1 = APACal.APASlotMaxOffsetDisBetweenObj1AndObj2ForParallel;
    } else {
      Y1 = APACal.APASlotMaxOffsetDisBetweenObj1AndObj2ForPerpendicular;
    }
    if (DisCarToObj1ByPassingSlot > DisCarToObj2ByPassingSlot) {
      X1 = DisCarToObj1ByPassingSlot - DisCarToObj2ByPassingSlot;
      if (X1 > Y1) {
        // Hear we treat obj1 as invalid obj (no obj).
        DisCarToObj1ByPassingSlot = NO_OBJ_DISTANCE;
      }
    } else {
      X1 = DisCarToObj2ByPassingSlot - DisCarToObj1ByPassingSlot;
      if (X1 > Y1) {
        // Hear we treat obj2 as invalid obj (no obj).
        DisCarToObj2ByPassingSlot = NO_OBJ_DISTANCE;
        bObj2RegardAsInvalid      = TRUE;
      }
    }
  }

  // 2. Check if a curb is found.

  SlotDepthRefCarSide = DisCarToObj1ByPassingSlot;
  if (SlotDepthRefCarSide > DisCarToObj2ByPassingSlot) {
    SlotDepthRefCarSide = DisCarToObj2ByPassingSlot;
  }

  // SlotIndex = 0;
  // SlotDepth: is the dis between side of car to curb.
  SlotDepth   = pMainSlotPar->SlotDepthParallel;
  SlotLen     = pMainSlotPar->SlotLengthTotal;
  MinPSlotLen = APACal.APASlotPMinSmallSlotLen - APACal.APASlotDetectionToleranceDis;  //2500- 0

  bUseFirstSlot = FALSE;
  if (SlotDepth < APACal.LengthOfCar) {
    // curb exist.
    if (DisCarToObj2ByPassingSlot != NO_OBJ_DISTANCE) {
      // Obj2 exist.
      // park the car near to the obj2.
      if ((pMainSlotPar->SlotDepthDetected3 >= APACal.LengthOfCar) && (pMainSlotPar->SlotLengthDetected3 >= MinPSlotLen)) {
        // OK, park the car near to obj2.
        bUseFirstSlot = TRUE;
      }
    } else {
      // Obj2 does not exist.
      // park the car near to the obj1.
      if ((pMainSlotPar->SlotDepthDetected1 >= APACal.LengthOfCar) && (pMainSlotPar->SlotLengthDetected1 >= MinPSlotLen)) {
        // OK, park the car near to obj1.
        bUseFirstSlot = TRUE;
      }
    }
  }

  if ((bUseFirstSlot == FALSE) &&
      ((SlotDepth >= APACal.APASlotPMinSlotDepth) ||
       ((pMainSlotPar->SlotDepthDetected1 >= APACal.APASlotPMinSlotDepth) && (pMainSlotPar->SlotDepthDetected2 >= APACal.APASlotPMinSlotDepth) &&
        (pMainSlotPar->SlotDepthDetected3 >= APACal.APASlotPMinSlotDepth) && (pMainSlotPar->SlotLengthDetected2 == 0) &&
        ((pMainSlotPar->SlotLengthDetected1 == 0) || (pMainSlotPar->SlotLengthDetected3 == 0)))) &&
      (SlotLen >= MinPSlotLen) && (SlotLen <= APACal.APASlotPMaxSlotLength)) {
    // Valid slot is found.
    if ((DisCarToObj2ByPassingSlot != NO_OBJ_DISTANCE) && (SlotLen > APACal.APASlotPMaxSlotLengthWithInvalidObj2) &&
        (pMainSlotPar->CarPassTheSlotEndPtDistance >= APACal.APASlotPMinPathAfterSlotWithObj2) &&
        (APACal.APAParkProcPCarEndPositionWithSlotLenGreatThanAGivenSlot == APA_PARKPROC_CAR_END_POSITION_CLOSE_TO_OBJ2)) {
      // Use park close to Obj2
      // Regard the Obj1 as invalid.
      DisCarToObj1ByPassingSlot = NO_OBJ_DISTANCE;
    }
  } else {
    SlotDepth  = pMainSlotPar->SlotDepthDetected1;
    SlotLen    = pMainSlotPar->SlotLengthDetected1;
    SlotDepth2 = pMainSlotPar->SlotDepthDetected2;
    SlotLen2   = pMainSlotPar->SlotLengthDetected2;
    SlotDepth3 = pMainSlotPar->SlotDepthDetected3;
    SlotLen3   = pMainSlotPar->SlotLengthDetected3;

    if ((SlotDepth >= APACal.APASlotPMinSlotDepth) && (SlotLen >= MinPSlotLen) && (SlotLen <= APACal.APASlotPMaxSlotLength)) {
      // OK, first slot is valid.
      bUseFirstSlot = TRUE;
      if ((SlotDepth3 >= APACal.APASlotPMinSlotDepth) && (SlotLen3 >= MinPSlotLen) && (SlotLen3 <= APACal.APASlotPMaxSlotLength)) {
        // OK, third slot is valid.
        PtTemp.x = (APA_DISTANCE_TYPE)USSPar.TrajCalCarCenterPtCal.Coordinate.x;
        PtTemp.y = (APA_DISTANCE_TYPE)USSPar.TrajCalCarCenterPtCal.Coordinate.y;
        LTemp    = APASlotProcCalTwoPtApproximateDisInt(PtTemp, pMainSlot->CarCenterPoint[SlotEndIndex]);
        Y1       = APACal.LengthOfCar;
        if ((SlotDepth3 > SlotDepth) || (LTemp > Y1)) {
          // Use the third slot.
          SlotDepth                 = SlotDepth3;
          SlotLen                   = SlotLen3;
          DisCarToObj1ByPassingSlot = NO_OBJ_DISTANCE;
          // SlotIndex = 3;
          bUseFirstSlot = FALSE;
        } else {
          // Just use the fist slot.
        }
      } else {
        // Just use the fist slot.
      }
      if (bUseFirstSlot == TRUE) {
        if ((DisCarToObj2ByPassingSlot != NO_OBJ_DISTANCE) && (SlotLen > APACal.APASlotPMaxSlotLengthWithInvalidObj2) &&
            (pMainSlotPar->CarPassTheSlotEndPtDistance >= APACal.APASlotPMinPathAfterSlotWithObj2) &&
            (APACal.APAParkProcPCarEndPositionWithSlotLenGreatThanAGivenSlot == APA_PARKPROC_CAR_END_POSITION_CLOSE_TO_OBJ2) && (SlotLen3 == 0) &&
            (SlotLen2 == 0)) {
          // Use park close to Obj2
          // Regard the Obj1 as invalid.
          DisCarToObj1ByPassingSlot = NO_OBJ_DISTANCE;
        } else {
          if (pMainSlotPar->SlotLengthTotal > APACal.APASlotPMaxSlotLengthWithInvalidObj2) {
            bObj2RegardAsInvalid = TRUE;
          }
          // Recal the slot end index.
          Y1 = pMainSlotPar->SlotDepthParallel;
          if (Y1 != NO_OBJ_DISTANCE) {
            Y1 += APACal.APASlotCurbLineTolerance;
          }
          bObj2PtFound = FALSE;
          i            = SlotEndIndex;
          for (j = SlotStartIndex + 1; j < SlotEndIndex; j++) {
            if (pMainSlot->DisFromCarToObj[j] > Y1) {
              for (i = j + 1; i < SlotEndIndex; i++) {
                Y2 = APATrajCalGetTwoPointDisInt(
                    pMainSlot->CarCenterPoint[j].x, pMainSlot->CarCenterPoint[j].y, pMainSlot->CarCenterPoint[i].x, pMainSlot->CarCenterPoint[i].y);
                if (pMainSlot->DisFromCarToObj[i] > Y1) {
                  if (Y2 > APACal.APASlotPDefSlotLenWithoutObj2) {
                    bObj2PtFound = TRUE;
                    break;
                  }
                } else {
                  if (Y2 < APACal.APASlotPRegardAsInvalidSlotEndPtMinDeltaCarPos) {
                  } else {
                    // OK
                    Y2 = APATrajCalGetTwoPointDisInt(pMainSlot->CarCenterPoint[SlotStartIndex].x,
                                                     pMainSlot->CarCenterPoint[SlotStartIndex].y,
                                                     pMainSlot->CarCenterPoint[i].x,
                                                     pMainSlot->CarCenterPoint[i].y);
                    Y2 += pMainSlotPar->APASlotDetectionCompensateLengthTail;
                    if (Y2 > APACal.APASlotPMinSmallSlotLen) {
                      // OK, Valid slot.

                      bObj2PtFound = TRUE;
                      break;
                    }
                  }
                }
              }
              if (bObj2PtFound == TRUE) {
                break;
              }
            }
          }

          if (bObj2PtFound == FALSE) {
            // data error
            return FALSE;
          }
          if (SlotEndIndex > i) {
            SlotEndIndex = i;
          }
          if ((SlotLen2 + SlotLen3) > APACal.APASlotPMinSmallSlotLen) {
            DisCarToObj2ByPassingSlot = NO_OBJ_DISTANCE;
          }
        }
      }
    } else {
      if ((SlotDepth3 >= APACal.APASlotPMinSlotDepth) && (SlotLen3 >= MinPSlotLen) && (SlotLen3 <= APACal.APASlotPMaxSlotLength)) {
        // OK, third slot is valid.
        // Use the third slot.
        if ((SlotLen2 + SlotLen) > APACal.APASlotPMinSmallSlotLen) {
          DisCarToObj1ByPassingSlot = NO_OBJ_DISTANCE;
        }
        SlotDepth = SlotDepth3;
        SlotLen   = SlotLen3;
        // SlotIndex = 3;
      } else {
        // do not use second slot.
        return FALSE;
      }
    }
  }

  LTemp = APATrajCalGetTwoPointDisInt(pMainSlot->CarCenterPoint[SlotStartIndex].x,
                                      pMainSlot->CarCenterPoint[SlotStartIndex].y,
                                      pMainSlot->CarCenterPoint[SlotEndIndex].x,
                                      pMainSlot->CarCenterPoint[SlotEndIndex].y);

  if (LTemp < APACal.APASlotPRegardAsInvalidSlotEndPtMinDeltaCarPos) {
    // Data error ???
    return FALSE;
  }

  /*
  if(SlotIndex == 3){
          // Recal the slot start index.
          X1 = pMainSlot->CarCenterPoint[SlotEndIndex].x;
          Y1 = pMainSlot->CarCenterPoint[SlotEndIndex].y;
          Y2 = 0;
          LTemp = 0;
          for(i = SlotEndIndex - 1; i > SlotStartIndex; i --) {
                  LTemp = APATrajCalGetTwoPointDisInt(X1, Y1,
                          pMainSlot->CarCenterPoint[i].x, pMainSlot->CarCenterPoint[i].y);
                  if(LTemp > SlotLen) {
                          break;
                  }
                  Y2 = LTemp;
          }
          if((LTemp - SlotLen) > 300){

          }

  }
  */

  // SlotDepthRefObj: is the dis between outside of obj and curb.
  SlotDepthRefObj = SlotDepth - SlotDepthRefCarSide;

  if (SlotLen >= MinPSlotLen) {
  } else {
    return FALSE;
  }
  if (SlotDepth <= (SlotDepthRefCarSide + APACal.APASlotPMaxSlotDepth)) {
    // Curb detected.
    //
    // Xce should great than 0.!!!!!!!!!
    //

    bCurbFound = TRUE;
  } else {
    bCurbFound = FALSE;
  }

  // 3. Cal the new system coordinate original point O2 (relerative to current global coordinate:
  // Cal the slot system coordinate Y angle at the current global coordinate: AngO1O2.
  // And for the perpendicual slot, check if the slot width is great than APASlotPMaxSlotLengthWithInvalidObj2
  // (4m)? If yes, just regard the obj2 as invalid (if end pos park close to obj1). Or vice verser.

  // APA_PARKPROC_PARKING_MODE_PERPENDICULAR
  CarEndPosType = APACal.APAParkProcPCarEndPosition;
  // 3.1 Slot Head Obj2. end searching point.Y
  if ((DisCarToObj2ByPassingSlot == NO_OBJ_DISTANCE) ||
      ((DisCarToObj1ByPassingSlot != NO_OBJ_DISTANCE) && (SlotLen > APACal.APATrajCalPMaxSlotLengthForAGivenSlot) &&
       ((APACal.APAParkProcPCarEndPositionWithSlotLenGreatThanAGivenSlot == APA_PARKPROC_CAR_END_POSITION_CLOSE_TO_OBJ1) ||
        (pMainSlotPar->CarPassTheSlotEndPtDistance < APACal.APASlotPMinPathAfterSlotWithObj2)))) {
    CarEndPosType = APA_PARKPROC_CAR_END_POSITION_CLOSE_TO_OBJ1;
    // Regard the obj2 as invalid.
    DisCarToObj2ToCalSlot     = SlotDepthRefCarSide;
    DisCarToObj2ByPassingSlot = NO_OBJ_DISTANCE;
    Y2                        = pMainSlot->ObjPt[SlotStartIndex].y + APACal.APASlotPMinSmallSlotLen;
  } else {
    DisCarToObj2ToCalSlot = DisCarToObj2ByPassingSlot;
    Y2                    = pMainSlot->ObjPt[SlotEndIndex].y;
  }
  // 3.2 Slot Tail Obj1. start searching point.Y

  if ((DisCarToObj1ByPassingSlot == NO_OBJ_DISTANCE) ||
      ((DisCarToObj2ByPassingSlot != NO_OBJ_DISTANCE) && (SlotLen > APACal.APATrajCalPMaxSlotLengthForAGivenSlot) &&
       (APACal.APAParkProcPCarEndPositionWithSlotLenGreatThanAGivenSlot == APA_PARKPROC_CAR_END_POSITION_CLOSE_TO_OBJ2))) {
    // regard the obj1 as invalid.
    CarEndPosType             = APA_PARKPROC_CAR_END_POSITION_CLOSE_TO_OBJ2;
    DisCarToObj1ToCalSlot     = SlotDepthRefCarSide;
    DisCarToObj1ByPassingSlot = NO_OBJ_DISTANCE;
    Y1                        = pMainSlot->ObjPt[SlotEndIndex].y - APACal.APASlotPMinSmallSlotLen;
    // if(SlotLen < APACal.APASlotPDefSlotLenWithoutObj1){ // deleted by kjy, 2013 05 18
    //	SlotLen = APACal.APASlotPDefSlotLenWithoutObj1;
    //}
  } else {
    DisCarToObj1ToCalSlot = DisCarToObj1ByPassingSlot;
    Y1                    = pMainSlot->ObjPt[SlotStartIndex].y;
  }

  if (DisCarToObj1ByPassingSlot == NO_OBJ_DISTANCE) {
    USSPar.APACommonFlags.Bits.bSlotProcSlotObj1Exist = FALSE;
  } else {
    USSPar.APACommonFlags.Bits.bSlotProcSlotObj1Exist = TRUE;
  }
  if (DisCarToObj2ByPassingSlot == NO_OBJ_DISTANCE) {
    USSPar.APACommonFlags.Bits.bSlotProcSlotObj2Exist = FALSE;
  } else {
    USSPar.APACommonFlags.Bits.bSlotProcSlotObj2Exist = TRUE;
  }

  CarParkAtLeftOrRightSide = USSPar.TrajCalCarParkAtLeftOrRightSide;

  SlotStartCalIndex = SlotStartIndex;
  SlotEndCalIndex   = SlotEndIndex;
  for (i = SlotEndIndex; i < pMainSlot->ObjPtCnt; i++) {
    if (pMainSlot->CarCenterPoint[i].y > Y2) {
      break;
    }
    SlotEndCalIndex = i;
  }

  //	LTemp = (Y1 + Y2) / 2;
  //	Y1 = LTemp - (pMainSlot->CarCenterPoint[SlotEndCalIndex].y - LTemp);
  // 	||
  // 	\/

  LTemp = (Y1 + Y2);
  Y1    = LTemp - pMainSlot->CarCenterPoint[SlotEndCalIndex].y;

  for (i = SlotStartIndex; i < SlotEndIndex; i++) {
    if (pMainSlot->CarCenterPoint[i].y > Y1) {
      break;
    }
    SlotStartCalIndex = i;
  }

  LTemp /= 2;
  fDis  = (pMainSlot->CarCenterPoint[SlotEndCalIndex].y - LTemp);
  fDis2 = (LTemp - pMainSlot->CarCenterPoint[SlotStartCalIndex].y);
  fDis3 = fDis + fDis2;

  if ((fDis > 0) && (fDis2 > 0)) {
    fDis3    = fDis / fDis3;
    fDis4    = 1.0 - fDis3;
    Ang_o1o2 = (pMainSlot->CarAng[SlotStartCalIndex] * fDis3 + pMainSlot->CarAng[SlotEndCalIndex] * fDis4);
  } else {
    Ang_o1o2 = (pMainSlot->CarAng[SlotStartCalIndex] + pMainSlot->CarAng[SlotEndCalIndex]) / 2.0;
  }

  // 4. With different scenario, recalculate the Ang_o1o2 and new original center point O2
  bRecalSlotEndPt = FALSE;

  // Search the slot end point calculation car pos (x, y , ang).
  CarCenterPt.x     = pMainSlot->CarCenterPoint[SlotEndIndex].x;
  CarCenterPt.y     = pMainSlot->CarCenterPoint[SlotEndIndex].y;
  SlotEndCalIndex   = SlotEndIndex;
  SnsDetectedObjDis = DisCarToObj2ToCalSlot;
  if ((CarEndPosType == APA_PARKPROC_CAR_END_POSITION_CLOSE_TO_OBJ1) || (bObj2RegardAsInvalid == TRUE)) {

    // Check slot length.
    // Searching slot index to slot length:
    if (SlotLen < APACal.APASlotPDefSlotLenWithoutObj2) {
      // Y2 = SlotLen;
      // OK. do no need to research the end slot index.
      // bRecalSlotEndPt = FALSE;
    } else {
      bRecalSlotEndPt = TRUE;
      fDis2           = APACal.APASlotPDefSlotLenWithoutObj2;
    }

    if (bRecalSlotEndPt == TRUE) {
      fDis2 -= (pMainSlotPar->APASlotDetectionCompensateLengthTail);
      fDis = fDis2 * fDis2;
      for (i = SlotEndIndex; i > SlotStartIndex; i--) {
        fDis3           = (pMainSlot->CarCenterPoint[i].y - pMainSlot->CarCenterPoint[SlotStartIndex].y);
        fDis4           = (pMainSlot->CarCenterPoint[i].x - pMainSlot->CarCenterPoint[SlotStartIndex].x);
        fDis3           = fDis3 * fDis3 + fDis4 * fDis4;
        SlotEndCalIndex = i;
        if (fDis3 < fDis) {
          break;
        }
      }

      if (SlotEndCalIndex < SlotEndIndex) {
        fDis          = fDis2 - MATH_SQRT(fDis3);
        Ang1          = pMainSlot->CarAng[SlotEndCalIndex];
        CarCenterPt.x = pMainSlot->CarCenterPoint[SlotEndCalIndex].x + fDis * MATH_SIN(Ang1);
        CarCenterPt.y = pMainSlot->CarCenterPoint[SlotEndCalIndex].y + fDis * MATH_COS(Ang1);
      } else {
        bRecalSlotEndPt = FALSE;
      }

      // Ang_o1o2 need to be recalculated.
      // Research the car angle when the rear axis center passing the slot end pt.
      // re cal Ang_o1o2.
      // for(i = SlotStartIndex + 1; i <= SlotEndIndex; i ++) {
      //}
      // Ang_o1o2 = (pMainSlot->CarAng[SlotStartCalIndex]
      //            + pMainSlot->CarAng[SlotEndCalIndex]) / 2.0;
    }
  } else {
    if (DisCarToObj1ByPassingSlot < DisCarToObj2ByPassingSlot) {
      // Setup the system coordinate at the mid of obj1 and obj2 ??
      SnsDetectedObjDis = (DisCarToObj1ByPassingSlot + DisCarToObj2ByPassingSlot) / 2;
    }
  }

  PtTemp2 = APASlotProcCalSlotRelativeToCarCoordinateBySlotDisToCar(SnsDetectedObjDis, APASnsIndex);

  Pto2_c.x = APACal.HalfWidthOfCar + SnsDetectedObjDis; // DisCarToObj2ToCalSlot;

  Ang1     = pMainSlot->CarAng[SlotEndCalIndex] - Ang_o1o2;
  fDis     = (MATH_FABS(PtTemp2.x - Pto2_c.x)) * MATH_TAN(Ang1);
  Pto2_c.y = fDis + PtTemp2.y;

  Pto2 = APATrajCalPointPosWithAngAndCenterPt(Pto2_c, pMainSlot->CarAng[SlotEndCalIndex], CarCenterPt);
  // Recal slot len:
  if ((bRecalSlotEndPt == TRUE) || (bObj2RegardAsInvalid == TRUE)) {

    PtSlotStart   = APASlotProcCalSlotRelativeToCarCoordinateBySlotDisToCar(pMainSlotPar->SlotCalDisCarToObj1, APASnsIndex);
    CarCenterPt.x = pMainSlot->CarCenterPoint[SlotStartIndex].x;
    CarCenterPt.y = pMainSlot->CarCenterPoint[SlotStartIndex].y;

    PtSlotStart = APATrajCalPointPosWithAngAndCenterPt(PtSlotStart, pMainSlot->CarAng[SlotStartIndex], CarCenterPt);

    fDis    = APATrajCalGetTwoPointDisFloat(PtSlotStart, Pto2);
    SlotLen = (APA_DISTANCE_TYPE)fDis;
    SlotLen += (pMainSlotPar->APASlotDetectionCompensateLengthTail);
    //+ pMainSlotPar->APASlotDetectionCompensateLengthHead);
  }

  // Trajcal will use the SlotLen to calculate the trajectory.
  pMainSlotPar->SlotLength = SlotLen;
  pMainSlotPar->SlotDepth  = SlotDepth;

#ifdef PC_TRAJECTORY_DEBUG12
  if (cDlgDebug == 5) {
    CDlgTrajectoryDebug Dlg;
    Dlg.m_pSlotInfo       = &USSPar.Slot[USSPar.APARightSlotDataIndex];
    Dlg.m_pSubSlotInfo    = &USSPar.Slot[USSPar.APALeftSlotDataIndex];
    Dlg.m_pTrajectoryData = NULL;
    Dlg.m_CurCarAng       = pMainSlot->CarAng[SlotEndIndex];
    Dlg.m_CurCarPos.x     = pMainSlot->CarCenterPoint[SlotEndIndex].x;
    Dlg.m_CurCarPos.y     = pMainSlot->CarCenterPoint[SlotEndIndex].y;
    /*Dlg.m_CircleCenterPt[0] = CPoint(StepData[StepNum].CarTurningCenterPt.x, StepData[StepNum].CarTurningCenterPt.y);
    Dlg.m_CircleRadius[0] = StepData[StepNum].CarRearAxisCenterTurningRadius + APACal.APATrajCalMinRearAxisCenterTurningRadius;
    Dlg.m_CircleCenterPt[1] = CPoint(NextKeyPoint.Coordinate.x, NextKeyPoint.Coordinate.y);
    Dlg.m_CircleRadius[1] = APACal.APATrajCalMinRearAxisCenterTurningRadius;
    Dlg.m_CircleCenterPt[2] = CPoint(StepData[StepNum].CarTurningCenterPt.x, StepData[StepNum].CarTurningCenterPt.y);
    Dlg.m_CircleRadius[2] = StepData[StepNum].CarRearAxisCenterTurningRadius;
    Dlg.m_CircleNum = 3;*/

    Dlg.m_CircleCrossPt[0] = CPoint(Pto2.x, Pto2.y);
    Dlg.m_CircleCrossPt[1] = CPoint(pMainSlot->ObjPt[SlotEndIndex].x, pMainSlot->ObjPt[SlotEndIndex].y);
    Dlg.m_CircleCrossPtNum = 2;

    int ID = Dlg.DoModal();
  }
#endif

  // 5. Determine the car end position coordinate in the new O2 system (Xce, Yce):

  // USSPar.TrajCalCarParkingCurrentStepIndex = 0;
  //	bAPATrajCalCarParkAlongCurb = FALSE;

  // Perpendicular parking.
  // Step 1. get the Xce and Yce.
  X1    = (DisCarToObj1ByPassingSlot - DisCarToObj2ByPassingSlot);
  LTemp = (X1);
  if (LTemp < 0) {
    LTemp = -LTemp;
  }
  if (bCurbFound) {
    // Curb detected.
    if ((SlotDepth < APACal.APATrajCalPCarParkingAlongCurbMinSlotDepthRefObject) &&
        (APACal.APACalCommonFlags.Bits.bAPATrajCalPCarParkingAlongCurbIfCurbDetected == FALSE)) {
      // Park on curb.
      if ((USSPar.APACommonFlags.Bits.bSlotProcSlotObj1Exist == TRUE) && (USSPar.APACommonFlags.Bits.bSlotProcSlotObj2Exist == TRUE) &&
          (LTemp < APACal.APATrajCalPCalCarEndPosXWithMeanValueAllowObj1Obj2MaxOffsetDis)) {
        if (DisCarToObj1ByPassingSlot > DisCarToObj2ByPassingSlot) {
          // Park at the mean of Obj1 and Obj2 edge line.
          USSPar.TrajCalCarEndPos.Coordinate.x = /*X1 / 2
                                                                                                  +*/
                                                    APACal.LenBetweenRAxisAndFBumper +
                                                    APACal.APATrajCalPCarEndPositionOffsetX +
                                                    (DisCarToObj1ByPassingSlot - DisCarToObj2ByPassingSlot) / 2.0;
        } else {
          USSPar.TrajCalCarEndPos.Coordinate.x = /*X1 / 2
                                                                                                  +*/
                                                    APACal.LenBetweenRAxisAndFBumper +
                                                    APACal.APATrajCalPCarEndPositionOffsetX;
        }
      } else {
        USSPar.TrajCalCarEndPos.Coordinate.x = APACal.LenBetweenRAxisAndFBumper + APACal.APATrajCalPCarEndPositionOffsetX;
      }
    } else {
      // Park along curb
      //			bAPATrajCalCarParkAlongCurb = TRUE;
      USSPar.TrajCalCarEndPos.Coordinate.x = SlotDepthRefObj - APACal.LenBetweenRAxisAndRBumper - APACal.APATrajCalPCarEndPosDisToCurb;
    }
  } else {
    if ((USSPar.APACommonFlags.Bits.bSlotProcSlotObj1Exist == TRUE) && (USSPar.APACommonFlags.Bits.bSlotProcSlotObj2Exist == TRUE) &&
        (LTemp < APACal.APATrajCalPCalCarEndPosXWithMeanValueAllowObj1Obj2MaxOffsetDis)) {
      if (DisCarToObj1ByPassingSlot > DisCarToObj2ByPassingSlot) {
        // Park at the mean of Obj1 and Obj2 edge line.
        USSPar.TrajCalCarEndPos.Coordinate.x = /*X1 / 2
                                                                                                +*/
                                                  APACal.LenBetweenRAxisAndFBumper +
                                                  APACal.APATrajCalPCarEndPositionOffsetX +
                                                  (DisCarToObj1ByPassingSlot - DisCarToObj2ByPassingSlot) / 2.0;
      } else {
        // Park at the mean of Obj1 and Obj2 edge line.
        USSPar.TrajCalCarEndPos.Coordinate.x = /*X1 / 2
                                                                                                +*/
                                                  APACal.LenBetweenRAxisAndFBumper +
                                                  APACal.APATrajCalPCarEndPositionOffsetX;
      }
    } else {
      USSPar.TrajCalCarEndPos.Coordinate.x = APACal.LenBetweenRAxisAndFBumper + APACal.APATrajCalPCarEndPositionOffsetX;
    }
  }

  EndPosYCalMethod = 0; // Mid of obj2 and obj1;

  if (USSPar.APACommonFlags.Bits.bSlotProcSlotObj1Exist == FALSE) {
    // Close to obj2.
    EndPosYCalMethod = 2; // close to obj2.
  } else if (USSPar.APACommonFlags.Bits.bSlotProcSlotObj2Exist == FALSE) {
    EndPosYCalMethod = 1; // close to obj1.
  } else {
    if (SlotLen <= APACal.APATrajCalPMaxSlotLengthForAGivenSlot) {  //5m
      // One regular slot is found
      if (APACal.APAParkProcPCarEndPosition == APA_PARKPROC_CAR_END_POSITION_MID_BETWEEN_OBJ1_AND_OBJ2) {
        //  Mide of the left and right side line.
      } else if (APACal.APAParkProcPCarEndPosition == APA_PARKPROC_CAR_END_POSITION_CLOSE_TO_OBJ1) {
        EndPosYCalMethod = 1; // close to obj1.
      } else {
        EndPosYCalMethod = 2; // close to obj2.
      }
    } else {
      // slot length is great than one regular slot.

      // both obj1and obj2 are valid.
      if (APACal.APAParkProcPCarEndPositionWithSlotLenGreatThanAGivenSlot == APA_PARKPROC_CAR_END_POSITION_CLOSE_TO_OBJ2) {
        EndPosYCalMethod = 2; // close to obj2.
      } else {
        EndPosYCalMethod = 1; // close to obj1.
      }
    }
  }

  if (EndPosYCalMethod == 0) {
    USSPar.TrajCalCarEndPos.Coordinate.y = -SlotLen / 2;
  } else if (EndPosYCalMethod == 1) {
    Y1 = APACal.APATrajCalPCarEndPositionToObj1Dis * 2 + APACal.WidthOfCar;
    if (SlotLen < Y1) {
      USSPar.TrajCalCarEndPos.Coordinate.y = -SlotLen / 2;
    } else {
      USSPar.TrajCalCarEndPos.Coordinate.y = APACal.APATrajCalPCarEndPositionToObj1Dis + APACal.HalfWidthOfCar - SlotLen;
    }
  } else {
    Y1 = APACal.APATrajCalPCarEndPositionToObj2Dis * 2 + APACal.WidthOfCar;
    if (SlotLen < Y1) {
      USSPar.TrajCalCarEndPos.Coordinate.y = -SlotLen / 2;
    } else {
      USSPar.TrajCalCarEndPos.Coordinate.y = -APACal.APATrajCalPCarEndPositionToObj2Dis - APACal.HalfWidthOfCar;
    }
  }

  if (USSPar.APACommonFlags.Bits.bSlotProcSlotObj2Exist == FALSE) {
    // The object 2 does not exist. with the first drive backwards step.
    // Due to the slot detection has a min 30cm tolerance,
    // Hear we add a offset to the end pos.y (far away from the Obj2).
    // to have a better performance for the first drive backwards step (
    // Not hit the obj2 with the first step due to the slot detection tolerance).
    // This offset value can be removed by the slot correction algorithm during driving
    // into the slot.

    Obj2TypeGroupIndex = USSPar.Slot[USSPar.APARightSlotDataIndex].SlotPar[USSPar.TrajCalCurrentCalSlotIndex].Obj2Type;
    if (Obj2TypeGroupIndex == APA_SLOT_OBJ_TYPE_PER_CAR_WITH_SMALL_FLAT_BIG_WIDTH) {
      Obj2TypeGroupIndex = 0;
    } else if (Obj2TypeGroupIndex == APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_BIG_RISING_SHAPE) {
      Obj2TypeGroupIndex = 1;
    } else if (Obj2TypeGroupIndex == APA_SLOT_OBJ_TYPE_PARALLEL_CAR_WITH_VERY_BIG_RISING_SHAPE) {
      Obj2TypeGroupIndex = 2;
    } else {
      // Small edge.
      Obj2TypeGroupIndex = 3;
    }

    if (DisCarToObj2ByPassingSlot < APACal.APATrajCalPCarEndPositionOffsetDisWithoutObj2DevidedObj1Dis) {
      i = 0;
    } else {
      i = 1;
    }
    USSPar.TrajCalCarEndPos.Coordinate.y += APACal.APATrajCalPCarEndPositionOffsetDisWithoutObj2[i][Obj2TypeGroupIndex]; // 30cm.
  } else if (USSPar.APACommonFlags.Bits.bSlotProcSlotObj1Exist == FALSE) {
    // The object 1 does not exist. with the first drive backwards step.
    // Due to the slot detection has a min 30cm tolerance,
    // Hear we add a offset to the end pos.y (close to the Obj2).
    // to have a better performance for the first drive backwards step (
    // Not hit the obj2 with the first step due to the slot detection tolerance).
    // This offset value can be removed by the slot correction algorithm during driving
    // into the slot.
    USSPar.TrajCalCarEndPos.Coordinate.y += APACal.APATrajCalPCarEndPositionOffsetDisWithoutObj1; // 20cm.
  } else {
    if ((EndPosYCalMethod == 0) &&
        ((SlotLen > (APACal.WidthOfCar + 1200)) || ((SlotLen > (APACal.WidthOfCar + 800)) && (DisCarToObj2ByPassingSlot > 1200)))) {
      // big slot, use an offset to obj2.
      USSPar.TrajCalCarEndPos.Coordinate.y += APACal.APATrajCalPCarEndPositionOffsetDisWithObj12; // 20cm.
    }
  }

  if (SlotDepth != NO_OBJ_DISTANCE) {
    // Curb detected.
    // USSPar.TrajCalCarParkingTrajectoryOuterTurningCircleMaxX = SlotDepth;
  } else {
    // USSPar.TrajCalCarParkingTrajectoryOuterTurningCircleMaxX = APACal.APATrajCalPCarParkingTrajectoryOuterTurningCircleMaxX1;
  }
  USSPar.TrajCalCarEndPos.CarAng       = PI / 2;
  USSPar.TrajCalCarEndPosLine.A        = 0;
  USSPar.TrajCalCarEndPosLine.B        = 1.0;
  USSPar.TrajCalCarEndPosLine.C        = USSPar.TrajCalCarEndPos.Coordinate.y;
  USSPar.TrajCalCarEndPosLine.LineType = APALineIsHorizontal;

  Ang_o1o2 += APACal.APATrajCalPAPAParkingCoordinateYOffsetAngle[CarParkAtLeftOrRightSide];

#ifdef APA_SUPPORT_SLOT_POINT_COMPENSATE_ADJ
  Y1 = APACal.APATrajCalPAPAParkingCoordinateYOffsetDis;
#else
  if (USSPar.APACommonFlags.Bits.bSlotProcSlotObj2Exist == FALSE) {
    Y1 = APACal.APATrajCalPAPAParkingCoordinateYOffsetDis;
  } else {
    DisCarToObj2ByPassingSlot += APACal.APASlotCorPEndPosYCalObj2YSearchBkEndDeltaXDis;
    Y1 = pMainSlotPar->APASlotDetectionCompensateLengthHead + APACal.APATrajCalPAPAParkingCoordinateYOffsetDis;

    if ((pMainSlotPar->Obj2Type <= APA_SLOT_OBJ_TYPE_ROUND_OBJ_WITH_BIG_RISING_AND_FALLING_SHAPE) &&
        (pMainSlotPar->Obj2Type > APA_SLOT_OBJ_TYPE_UNKNOWN)) {
      i = SlotEndCalIndex - 1;
      j = 0x7e;
      while (i > 0 /*SlotStartIndex*/) {
        if (pMainSlot->DisFromCarToObj[i] > DisCarToObj2ByPassingSlot) {
          if (j == 0x7e) {
            j = i;
          }
        } else {
          j = 0x7e;
        }
        LTemp = APASlotProcCalTwoPtApproximateDisInt(pMainSlot->CarCenterPoint[SlotEndCalIndex], pMainSlot->CarCenterPoint[i]);
        if (LTemp > APACal.APATrajCalPAPAParkingCoordinateYSearchBkDis) {
          break;
        }
        i--;
      }
      j++;
      if (j >= SlotEndCalIndex) {
      } else {
        LTemp = APATrajCalGetTwoPointDisInt(pMainSlot->CarCenterPoint[SlotEndCalIndex].x,
                                            pMainSlot->CarCenterPoint[SlotEndCalIndex].y,
                                            pMainSlot->CarCenterPoint[j].x,
                                            pMainSlot->CarCenterPoint[j].y);
        if (LTemp < APACal.APATrajCalPAPAParkingCoordinateYSearchBkDis) {

        } else {
          LTemp = APACal.APATrajCalPAPAParkingCoordinateYSearchBkDis;
        }
        Y1 = Y1 - LTemp;
      }
    }
  }
  // When the car is turning around the obj2, to make sure it will not hit the obj2. use a more safety dis to the obj2.
  // Y1 = APACal.APATrajCalPAPAParkingCoordinateYOffsetDis;
#endif

  APATrajCalTransferCoordinateToNewWoldCoordinateSystem(
      3, Pto2, Ang_o1o2, Y1, CarEndPosType, SlotLen, &NewCarAngToBeTransfered, &NewCarCenterPtToBeTransfered);

#ifdef APA_SLOT_SUPPORT_DEBUG1
  if ((pMainSlotPar->Obj1Type != APA_SLOT_OBJ_TYPE_UNKNOWN) &&
      ((SlotStartIndex < (pMainSlotPar->Obj1EndPtIndex)) || ((SlotStartIndex) > (pMainSlotPar->Obj1StartPtIndex)))) {

    // Data error ??

    // cSlotDebug = 1;
  }
#endif

  APATrajCalDistanceBetweenOriginalPtAndObj2(1);

  return TRUE;
}

/*************************************************************************************************************************************************
** Syntax :  void USS(void)                                                                                                                     **
**                                                                                                                                              **
** Service ID:   : NA                                                                                                                           **
**                                                                                                                                              **
** Sync/Async:   : Synchronous                                                                                                                  **
**                                                                                                                                              **
** Reentrancy:   : Non Reentrant                                                                                                                **
**                                                                                                                                              **
** Parameters (in): none                                                                                                                        **
**                                                                                                                                              **
** Parameters (out): none                                                                                                                       **
**                                                                                                                                              **
** Return value: none                                                                                                                           **
**                                                                                                                                              **
** Description : ..                                                                                                                             **
*************************************************************************************************************************************************/
void APATrajCalParallelSetupSystemCoordinateAccordingToSlotDataCheckObj2StartEdge(void) {

  /*
          due to the system coordinate may setup above the obj2 start edge.
          we should offset down a little bit.

  */
  APA_INDEX_TYPE i, j;
  APASlotOutlineCoordinateDataType *pMainSlot;
  APASlotOutlineCoordinateDataType *pSubSlot;
  APASlotParameterType *pMainSlotPar;
  APACoordinateDataCalFloatType Pt1, Pt2;
  APA_DISTANCE_CAL_FLOAT_TYPE fDis;
  APA_DISTANCE_TYPE X1, Y1, Xo;
  APA_INDEX_TYPE SlotStartIndex, SlotEndIndex;
  APACoordinateDataType XLess20cmPt, XGreat20cmPt;
  APALineParameterABCType LinePar;
  BOOLEAN bCalResult;

  if (USSPar.APACommonFlags.Bits.bSlotProcSlotObj2Exist == FALSE) {
    return;
  }

  pMainSlot      = &USSPar.Slot[USSPar.APARightSlotDataIndex].SlotOutline.Lane;
  pMainSlotPar   = &USSPar.Slot[USSPar.APARightSlotDataIndex].SlotPar[USSPar.TrajCalCurrentCalSlotIndex];
  SlotStartIndex = pMainSlotPar->SlotStartIndex;
  SlotEndIndex   = pMainSlotPar->SlotEndIndex;
  if (pMainSlot->DisFromCarToObj[SlotEndIndex] == NO_OBJ_DISTANCE) {
    // Data error ??
    return;
  }

  Xo = 2000;

  for (i = SlotEndIndex + 1; i < pMainSlot->ObjPtCnt; i++) {
    if (pMainSlot->ObjPt[i].y > APACal.APATrajCalSystemCoordinateSetupObj2StartEdgeCheckMaxY) {
      break;
    }
    if ((pMainSlot->DisFromCarToObj[i] != NO_OBJ_DISTANCE) && (pMainSlot->ObjPt[i].x > -100)) {
      if (pMainSlot->ObjPt[i].x < Xo) {
        Xo = pMainSlot->ObjPt[i].x;
        if (Xo < 0) {
          break;
        }
      }
    }
  }

  if ((Xo == 2000) || (Xo < 30)) {
    Xo = 0;
  }

  XLess20cmPt.x  = 0;
  XLess20cmPt.y  = 0;
  XGreat20cmPt.x = 0;
  XGreat20cmPt.y = 0;

  if ((pMainSlot->ObjPt[SlotEndIndex].x - Xo) > APACal.APATrajCalSystemCoordinateSetupObj2StartEdgeCheckMaxX) { // 20cm.
    if (pMainSlot->ObjPt[SlotEndIndex].y > -30) {
      // OK.
      return;
    } else {
      XGreat20cmPt = pMainSlot->ObjPt[SlotEndIndex];
      for (i = SlotEndIndex + 1; i < pMainSlot->ObjPtCnt; i++) {
        if (pMainSlot->ObjPt[i].y > 0) {
          break;
        }
        if ((pMainSlot->DisFromCarToObj[i] != NO_OBJ_DISTANCE) && (pMainSlot->ObjPt[i].x > 0)) {
          if ((pMainSlot->ObjPt[i].x - Xo) < APACal.APATrajCalSystemCoordinateSetupObj2StartEdgeCheckMaxX) {
            XLess20cmPt = pMainSlot->ObjPt[i];
            break;
          }
          XGreat20cmPt = pMainSlot->ObjPt[i];
        }
      }
      // point found.
    }
  } else {
    if ((XLess20cmPt.x < pMainSlot->ObjPt[SlotEndIndex].x) && (XLess20cmPt.y > pMainSlot->ObjPt[SlotEndIndex].y)) {
      XLess20cmPt = pMainSlot->ObjPt[SlotEndIndex];
    }
    X1 = (APACal.APATrajCalSystemCoordinateSetupObj2StartEdgeCheckMaxX2);
    for (i = SlotEndIndex - 1; i > SlotStartIndex; i--) {
      if (pMainSlot->ObjPt[i].y < APACal.APATrajCalSystemCoordinateSetupObj2StartEdgeCheckMinY) {
        // < -60cm
        break;
      }
      if ((pMainSlot->DisFromCarToObj[i] != NO_OBJ_DISTANCE) && (pMainSlot->ObjPt[i].y < 0) && (pMainSlot->ObjPt[i].x > 0) &&
          (pMainSlot->ObjPt[i].x < X1)) {
        if ((pMainSlot->ObjPt[i].x - Xo) > APACal.APATrajCalSystemCoordinateSetupObj2StartEdgeCheckMaxX) {
          XGreat20cmPt = pMainSlot->ObjPt[i];
          break;
        }
        XLess20cmPt = pMainSlot->ObjPt[i];
      }
    }
    // point found.
  }

  if ((XGreat20cmPt.y > -30) || ((XGreat20cmPt.y - XLess20cmPt.y) > -30) || (XGreat20cmPt.x <= XLess20cmPt.x)) {
    if (XLess20cmPt.y > -30) {
      // within tolerance
      return;
    }
    Y1   = -XLess20cmPt.y;
    fDis = Y1;
  } else {
    Pt1.x = XLess20cmPt.x;
    Pt1.y = XLess20cmPt.y;

    Pt2.x      = XGreat20cmPt.x;
    Pt2.y      = XGreat20cmPt.y;
    bCalResult = APATrajCalLineParABCbyTwoPoints(Pt1, Pt2, &LinePar);
    if (bCalResult == FALSE) {
      return;
    }
    if ((LinePar.LineType == APALineIsVertical) || (LinePar.LineType == APALineIsHorizontal)) {
      Y1   = -XLess20cmPt.y;
      fDis = Y1;
    } else {
      fDis = APACal.APATrajCalSystemCoordinateSetupObj2StartEdgeCheckMaxX;
      fDis = -(LinePar.A * fDis + LinePar.C);
      Y1   = fDis;
    }
  }
  if (Y1 <= 30) {
    return;
  }

  if (Y1 > APACal.APATrajCalSystemCoordinateSetupObj2StartEdgeCheckCompMaxY) {
    // 40cm.
    Y1   = APACal.APATrajCalSystemCoordinateSetupObj2StartEdgeCheckCompMaxY;
    fDis = Y1;
  }

  USSPar.APACarCenterPt.Coordinate.y += fDis;
  USSPar.APACarCenterPtCaledByWheelCnt.Coordinate.y += fDis;

  for (i = USSPar.APASnsDtdObjDisInfoBufReadIndex; i < USSPar.APASnsDtdObjDisInfoBufWriteIndex; i++) {
    /* There is sns dtd dis need to be processed */
    USSPar.APASnsDtdObjDisInfoBuf[i].CarCenterPt.Coordinate.y += fDis;
  }

  for (j = 0; j < APA_SIDE_SENSOR_NUM; j++) {
    for (i = 0; i < APASnsDtdObjPtBuf[j].WrIndex; i++) {
      APASnsDtdObjPtBuf[j].ObjPtBuf[i].CarPos.Coordinate.y += Y1;
    }
  }

  for (i = 0; i < pMainSlot->ObjPtCnt; i++) {
    pMainSlot->ObjPt[i].y += Y1;
    pMainSlot->CarCenterPoint[i].y += Y1;
  }

  pSubSlot = &USSPar.Slot[USSPar.APALeftSlotDataIndex].SlotOutline.Lane;

  for (i = 0; i < pSubSlot->ObjPtCnt; i++) {
    pSubSlot->ObjPt[i].y += Y1;
    pSubSlot->CarCenterPoint[i].y += Y1;
  }

  for (j = 0; j < APA_SLOT_SUPPORT_SEARCHING_SLOT_SENSOR_NUM; j++) {
    for (i = 0; i < USSPar.Slot[j].SlotOutlineRearSideSnsDetected.LaneDetectedByRearSideSensor.ObjPtCntRSns; i++) {
      USSPar.Slot[j].SlotOutlineRearSideSnsDetected.LaneDetectedByRearSideSensor.ObjPtRSns[i].y += Y1;
      USSPar.Slot[j].SlotOutlineRearSideSnsDetected.LaneDetectedByRearSideSensor.CarCenterPointRSns[i].y += Y1;
    }
  }

#ifdef SUPPORT_SDG_FUNCTION
// transfer SDG Object Pt Coordinate. ???????????????
#if 0
	if(SDGState == SDG_OPERATION_MODE) {
		if(bSDGAPASlotDataIsMirrorChange == TRUE) { //dsh 20120227 sdg DONOT MIRROR CHANGE
			CenterPt.x = - CenterPt.x;
			CenterPt.y =  CenterPt.y;
			CarAng	   = - CarAng;
		}
		for(SnsIndex = 0; SnsIndex < SDG_SUPPORT_SDG_SNS_NUM; SnsIndex ++) {
			ObjCnt = SDGSnsDtdObjPtBuf[SnsIndex].WrIndex;
			for(i = 0; i < ObjCnt; i ++) {
				DstPt.x = SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[i].Pt.x;
				DstPt.y = SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[i].Pt.y;
				DstPt = APATrajCalPointPosWithAngAndCenterPt(DstPt, CarAng, CenterPt);
				nPtTemp.x = (SDG_DISTANCE_TYPE)(DstPt.x);
				nPtTemp.y = (SDG_DISTANCE_TYPE)(DstPt.y);
				SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[i].Pt.x = nPtTemp.x + APA_SLOT_CAR_CENTER_POINT_X_DEFAUT_VALUE;
				SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[i].Pt.y = nPtTemp.y + CarCenterPtDefY;

				DstPt.x = SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[i].CarPos.Coordinate.x;
				DstPt.y = SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[i].CarPos.Coordinate.y;
				DstPt = APATrajCalPointPosWithAngAndCenterPt(DstPt, CarAng, CenterPt);
				nPtTemp.x = (SDG_DISTANCE_TYPE)(DstPt.x);
				nPtTemp.y = (SDG_DISTANCE_TYPE)(DstPt.y);
				SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[i].CarPos.Coordinate.x = nPtTemp.x  + APA_SLOT_CAR_CENTER_POINT_X_DEFAUT_VALUE;
				SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[i].CarPos.Coordinate.y = nPtTemp.y  + CarCenterPtDefY;
				SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[i].CarPos.CarAng += CarAng;
			}
			ObjCnt = SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt;
			for(i = 0; i < ObjCnt; i ++) {
				/* There is sns dtd dis need to be processed */
				DstPt.x = SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[i].Pt.x;
				DstPt.y = SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[i].Pt.y;
				DstPt = APATrajCalPointPosWithAngAndCenterPt(DstPt, CarAng, CenterPt);
				nPtTemp.x = (SDG_DISTANCE_TYPE)(DstPt.x);
				nPtTemp.y = (SDG_DISTANCE_TYPE)(DstPt.y);

				CarCoor.x = SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[i].CarPos.Coordinate.x;
				CarCoor.y = SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[i].CarPos.Coordinate.y;
				CarCoor = APATrajCalPointPosWithAngAndCenterPt(CarCoor, CarAng, CenterPt);
				nCarCoor.x = (SDG_DISTANCE_TYPE)(CarCoor.x);
				nCarCoor.y = (SDG_DISTANCE_TYPE)(CarCoor.y);
				NewCarAng = SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[i].CarPos.CarAng + CarAng;

				// Check if the NewCarAng will overfollow?? - PI ~ PI.
				if(NewCarAng > PI) {
					NewCarAng -= 2 * PI;
				} else if(NewCarAng < - PI) {
					NewCarAng += 2 * PI;
				}

				SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[i].Pt.x = nPtTemp.x  + APA_SLOT_CAR_CENTER_POINT_X_DEFAUT_VALUE;
				SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[i].Pt.y = nPtTemp.y  + CarCenterPtDefY;
				SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[i].CarPos.Coordinate.x = nCarCoor.x  + APA_SLOT_CAR_CENTER_POINT_X_DEFAUT_VALUE;
				SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[i].CarPos.Coordinate.y = nCarCoor.y + CarCenterPtDefY;
				SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[i].CarPos.CarAng = NewCarAng;
			}
		}
	}
#endif
#endif
}

/*************************************************************************************************************************************************
** Syntax :  void USS(void)                                                                                                                     **
**                                                                                                                                              **
** Service ID:   : NA                                                                                                                           **
**                                                                                                                                              **
** Sync/Async:   : Synchronous                                                                                                                  **
**                                                                                                                                              **
** Reentrancy:   : Non Reentrant                                                                                                                **
**                                                                                                                                              **
** Parameters (in): none                                                                                                                        **
**                                                                                                                                              **
** Parameters (out): none                                                                                                                       **
**                                                                                                                                              **
** Return value: none                                                                                                                           **
**                                                                                                                                              **
** Description : ..                                                                                                                             **
*************************************************************************************************************************************************/
BOOLEAN APATrajCalPerpendCheckIfCurCarWillHitObj12OrSlotBorderLine(APACarCoordinateDataCalFloatType *pCurCarPos,
                                                                   BOOLEAN bCheckObj1,
                                                                   BOOLEAN bCheckObj2,
                                                                   BOOLEAN bCheckObj1BorderLine,
                                                                   BOOLEAN bCheckObj2BorderLine) {
  // return value:
  // bCarWillHitObj;

  // BOOLEAN bCarWillHitObj;
  APACoordinateDataCalFloatType Ptco[2], Ptcc[2];
  APALineParameterABCType CurCarPosLineD, CurCarPosLineC, SideLine;
  BOOLEAN bObj1Exist, bObj2Exist, bCarMayHitObj, bCheckCornerWillHitBdLine;
  APA_DISTANCE_CAL_FLOAT_TYPE CarRSideLineC, CarLSideLineC, CarFLineC, CarRLineC, dbTemp1;
  APA_DISTANCE_CAL_FLOAT_TYPE CrossPtX, CrossPtY, DeltaCarAng;
  APACoordinateDataCalFloatType CornerPtF, CornerPtR;
  APA_ENUM_TYPE PtPosIndex;

  bObj1Exist = USSPar.APACommonFlags.Bits.bSlotProcSlotObj1Exist;
  bObj2Exist = USSPar.APACommonFlags.Bits.bSlotProcSlotObj2Exist;

  CurCarPosLineD = APATrajCalLineParABCByCurrentCarPosition(pCurCarPos, 0);
  CurCarPosLineC = APATrajCalLineParABCByPerPendLineAndPointOnLine(pCurCarPos->Coordinate, &CurCarPosLineD);
  CarRSideLineC  = APACal.HalfWidthOfCar;
  CarLSideLineC  = -APACal.HalfWidthOfCar;
  if (CurCarPosLineC.LineType == APALineIsIncline) {
    if (CurCarPosLineC.A > 0) {
      CarRLineC = -APACal.LenBetweenRAxisAndRBumper;
      CarFLineC = APACal.LenBetweenRAxisAndFBumper;
    } else {
      CarRLineC = APACal.LenBetweenRAxisAndRBumper;
      CarFLineC = -APACal.LenBetweenRAxisAndFBumper;
    }
  } else if (CurCarPosLineC.LineType == APALineIsVertical) {
    CarRLineC = APACal.LenBetweenRAxisAndRBumper;
    CarFLineC = -APACal.LenBetweenRAxisAndFBumper;
  } else {
    // ?? Data error
    return TRUE;
  }

  CarRLineC     = APATrajCalLineParCByParallelLineAndDisToLine(CarRLineC, &CurCarPosLineC);
  CarFLineC     = APATrajCalLineParCByParallelLineAndDisToLine(CarFLineC, &CurCarPosLineC);
  CarRSideLineC = APATrajCalLineParCByParallelLineAndDisToLine(CarRSideLineC, &CurCarPosLineD);
  CarLSideLineC = APATrajCalLineParCByParallelLineAndDisToLine(CarLSideLineC, &CurCarPosLineD);

  // bCarWillHitObj = FALSE;

  DeltaCarAng = MATH_FABS(pCurCarPos->CarAng - USSPar.TrajCalCarEndPos.CarAng);
  if (DeltaCarAng < (2.0 * PI / 180.0)) {
    bCheckCornerWillHitBdLine = FALSE;
  } else {
    bCheckCornerWillHitBdLine = TRUE;
  }

  if (bObj2Exist == TRUE) {
    if (bCheckObj2BorderLine == TRUE) {
      // Cal cross point of Car R side line and Slot R side line.

      dbTemp1 = USSPar.TrajCalSlotRightSideLine.K - CurCarPosLineD.A;

      if (dbTemp1 == 0) {
        // two line is parallel.
        if (USSPar.TrajCalSlotRightSideLine.B < CarRSideLineC) {
          // Car will hit obj2 border line.
          return TRUE;
        }
      } else {

        // Cal car RR and FR corner point.
        if (CurCarPosLineC.LineType == APALineIsIncline) {
          CornerPtR.x = (CarRSideLineC - CarRLineC) / (CurCarPosLineC.A - CurCarPosLineD.A);
          CornerPtR.y = CurCarPosLineC.A * CornerPtR.x + CarRLineC;
          CornerPtF.x = (CarRSideLineC - CarFLineC) / (CurCarPosLineC.A - CurCarPosLineD.A);
          CornerPtF.y = CurCarPosLineC.A * CornerPtF.x + CarFLineC;
        } else {
          //(CurCarPosLineC.LineType == APALineIsVertical)
          CornerPtR.x = pCurCarPos->Coordinate.x + APACal.LenBetweenRAxisAndRBumper;
          CornerPtR.y = pCurCarPos->Coordinate.y + APACal.HalfWidthOfCar;
          CornerPtF.x = pCurCarPos->Coordinate.x - APACal.LenBetweenRAxisAndFBumper;
          CornerPtF.y = CornerPtR.y;
        }

        if (CornerPtR.x > USSPar.TrajCalObj2Pos.x) {
          // Car may hit obj2 border line.
          SideLine.A = USSPar.TrajCalSlotRightSideLine.K;
          SideLine.B = 1;
          SideLine.C = USSPar.TrajCalSlotRightSideLine.B;
          if (MATH_FABS(SideLine.A) < APACal.APATrajCalLineIsHMinK) {
            SideLine.LineType = APALineIsHorizontal; // Line Type.
          } else {
            SideLine.LineType = APALineIsIncline; // Line Type.
          }

          PtPosIndex = APATrajCalCheckIfThePointIsAtLeftOrRightSideOfALine(&SideLine, CornerPtR);

          /*
          APATrajCalPointIsAtAboveOfLine = 0, // Only used when line is horizontal.
          APATrajCalPointIsAtUnderOfLine, // Only used when line is horizontal.
          APATrajCalPointIsAtLeftOfLine, // Used when line is vertical or incline.
          APATrajCalPointIsAtRightOfLine, // Used when line is vertical or incline.
          APATrajCalPointIsOnLine, // Point is on line with a tollerance.
          */

          if (PtPosIndex == APATrajCalPointIsAtUnderOfLine) {
            // OK, Car will not hit the obj2.
          } else if ((PtPosIndex == APATrajCalPointIsAtAboveOfLine) || (PtPosIndex == APATrajCalPointIsOnLine)) {
            // OK, Car will hit the obj2.
            return TRUE;
          } else {
            if (SideLine.A > 0) {
              if (PtPosIndex == APATrajCalPointIsAtLeftOfLine) {
                return TRUE;
              }
            } else {
              if (PtPosIndex == APATrajCalPointIsAtRightOfLine) {
                return TRUE;
              }
            }
          }

          if (CornerPtF.x > USSPar.TrajCalObj2Pos.x) {

            PtPosIndex = APATrajCalCheckIfThePointIsAtLeftOrRightSideOfALine(&SideLine, CornerPtF);

            /*
            APATrajCalPointIsAtAboveOfLine = 0, // Only used when line is horizontal.
            APATrajCalPointIsAtUnderOfLine, // Only used when line is horizontal.
            APATrajCalPointIsAtLeftOfLine, // Used when line is vertical or incline.
            APATrajCalPointIsAtRightOfLine, // Used when line is vertical or incline.
            APATrajCalPointIsOnLine, // Point is on line with a tollerance.
            */

            if (PtPosIndex == APATrajCalPointIsAtUnderOfLine) {
              // OK, Car will not hit the obj2.
            } else if ((PtPosIndex == APATrajCalPointIsAtAboveOfLine) || (PtPosIndex == APATrajCalPointIsOnLine)) {
              // OK, Car will hit the obj2.
              return TRUE;
            } else {
              if (SideLine.A > 0) {
                if (PtPosIndex == APATrajCalPointIsAtLeftOfLine) {
                  return TRUE;
                }
              } else {
                if (PtPosIndex == APATrajCalPointIsAtRightOfLine) {
                  return TRUE;
                }
              }
            }
          } else {
            // Here we use the obj2pos to check.
            bCheckObj2 = TRUE;

#if 0
						// Cal cross Pt obj2.x and slot r side line.
						CornerPtF.x = USSPar.TrajCalObj2Pos.x + APA_TRAJCAL_PERPEND_CAR_HIT_OBJ_SIDE_CHECK_OBJX_OFFSET_DIS;
						CornerPtF.y = CornerPtF.x * USSPar.TrajCalSlotRightSideLine.K
						              + USSPar.TrajCalSlotRightSideLine.B;

						SideLine = CurCarPosLineD;
						SideLine.C = CarRSideLineC;
						PtPosIndex = APATrajCalCheckIfThePointIsAtLeftOrRightSideOfALine(&SideLine,
						                                                                 CornerPtF);

						/*
						APATrajCalPointIsAtAboveOfLine = 0, // Only used when line is horizontal.
						APATrajCalPointIsAtUnderOfLine, // Only used when line is horizontal.
						APATrajCalPointIsAtLeftOfLine, // Used when line is vertical or incline.
						APATrajCalPointIsAtRightOfLine, // Used when line is vertical or incline.
						APATrajCalPointIsOnLine, // Point is on line with a tollerance.
						*/

						if(PtPosIndex == APATrajCalPointIsAtAboveOfLine) {
							// OK, Car will not hit the obj2.
						} else if((PtPosIndex == APATrajCalPointIsAtUnderOfLine)
						          || (PtPosIndex == APATrajCalPointIsOnLine)) {
							// OK, Car will hit the obj2.
							return TRUE;
						} else {
							if(SideLine.A > 0) {
								if(PtPosIndex == APATrajCalPointIsAtRightOfLine) {
									return TRUE;
								}
							} else {
								if(PtPosIndex == APATrajCalPointIsAtLeftOfLine) {
									return TRUE;
								}
							}
						}
#endif
          }

        } else {
          // Out side of slot.
          // Car will not hit obj2.
        }
      }
    }
    if (bCheckObj2 == TRUE) {
      bCarMayHitObj = FALSE;
      if (pCurCarPos->CarAng > (PI / 2.0)) {
        // car ang is large than end pos
        if (USSPar.TrajCalObj2Pos.y < pCurCarPos->Coordinate.y) {
          // Car already hit obj
          bCarMayHitObj = TRUE;
        }
      } else {
        if (USSPar.TrajCalObj2Pos.y > pCurCarPos->Coordinate.y) {
          // Car already hit obj
          bCarMayHitObj = TRUE;
        }
      }
      if (bCarMayHitObj == FALSE) {
        dbTemp1 = APATrajCalGetPointToLineDis(USSPar.TrajCalObj2Pos, CurCarPosLineC);

        if (dbTemp1 < (APACal.LenBetweenRAxisAndRBumper + APACal.APATrajCalPSafetyDisToObj12AtRearBumper)) {
          // Car may hit obj2.
          bCarMayHitObj = TRUE;
        }
      }

      if (bCarMayHitObj == FALSE) {

      } else {
        SideLine   = CurCarPosLineD;
        SideLine.C = CarRSideLineC;
        PtPosIndex = APATrajCalCheckIfThePointIsAtLeftOrRightSideOfALine(&SideLine, USSPar.TrajCalObj2Pos);

        /*
        APATrajCalPointIsAtAboveOfLine = 0, // Only used when line is horizontal.
        APATrajCalPointIsAtUnderOfLine, // Only used when line is horizontal.
        APATrajCalPointIsAtLeftOfLine, // Used when line is vertical or incline.
        APATrajCalPointIsAtRightOfLine, // Used when line is vertical or incline.
        APATrajCalPointIsOnLine, // Point is on line with a tollerance.
        */

        if (PtPosIndex == APATrajCalPointIsAtAboveOfLine) {
          // OK, Car will not hit the obj2.
        } else if ((PtPosIndex == APATrajCalPointIsAtUnderOfLine) || (PtPosIndex == APATrajCalPointIsOnLine)) {
          // OK, Car will hit the obj2.
          return TRUE;
        } else {
          if (SideLine.A > 0) {
            if (PtPosIndex == APATrajCalPointIsAtRightOfLine) {
              return TRUE;
            }
          } else {
            if (PtPosIndex == APATrajCalPointIsAtLeftOfLine) {
              return TRUE;
            }
          }
        }

        dbTemp1 = APATrajCalGetPointToLineDis(USSPar.TrajCalObj2Pos, CurCarPosLineD);

        if (pCurCarPos->Coordinate.x > USSPar.TrajCalObj2Pos.x) {
          CrossPtX = (APACal.HalfWidthOfCar + APACal.APATrajCalPSafetyDisToObj2InStep3TurningCar0); // 10cm.
        } else {
          if (bCheckCornerWillHitBdLine == FALSE) {
            CrossPtX = (APACal.HalfWidthOfCar + APACal.APATrajCalPSafetyDisToObj2InStep3TurningCar1); // 20cm.
          } else {
            CrossPtX = (APACal.HalfWidthOfCar + APACal.APATrajCalPSafetyDisToObj2InStep3TurningCar2); // 35cm,
          }
        }

        if (dbTemp1 < CrossPtX) {
          // Car will hit obj2.
          return TRUE;
        }
      }
    }
  }

  if (bObj1Exist == TRUE) {

    if (bCheckObj1BorderLine == TRUE) {
      // Cal cross point of Car L side line and Slot L side line.

      dbTemp1 = USSPar.TrajCalSlotLeftSideLine.K - CurCarPosLineD.A;

      if (dbTemp1 == 0) {
        // two line is parallel.
        if (USSPar.TrajCalSlotLeftSideLine.B > CarLSideLineC) {
          // Car will hit obj2 border line.
          return TRUE;
        }
      } else {

        // Cal car RR and FR corner point.
        if (CurCarPosLineC.LineType == APALineIsIncline) {
          CornerPtR.x = (CarLSideLineC - CarRLineC) / (CurCarPosLineC.A - CurCarPosLineD.A);
          CornerPtR.y = CurCarPosLineC.A * CornerPtR.x + CarRLineC;
          CornerPtF.x = (CarLSideLineC - CarFLineC) / (CurCarPosLineC.A - CurCarPosLineD.A);
          CornerPtF.y = CurCarPosLineC.A * CornerPtF.x + CarFLineC;
        } else {
          //(CurCarPosLineC.LineType == APALineIsVertical)
          CornerPtR.x = pCurCarPos->Coordinate.x + APACal.LenBetweenRAxisAndRBumper;
          CornerPtR.y = pCurCarPos->Coordinate.y - APACal.HalfWidthOfCar;
          CornerPtF.x = pCurCarPos->Coordinate.x - APACal.LenBetweenRAxisAndFBumper;
          CornerPtF.y = CornerPtR.y;
        }

        if (CornerPtR.x > USSPar.TrajCalObj1Pos.x) {
          // Car may hit obj1 border line.
          SideLine.A = USSPar.TrajCalSlotLeftSideLine.K;
          SideLine.B = 1;
          SideLine.C = USSPar.TrajCalSlotLeftSideLine.B;
          if (MATH_FABS(SideLine.A) < APACal.APATrajCalLineIsHMinK) {
            SideLine.LineType = APALineIsHorizontal; // Line Type.
          } else {
            SideLine.LineType = APALineIsIncline; // Line Type.
          }

          PtPosIndex = APATrajCalCheckIfThePointIsAtLeftOrRightSideOfALine(&SideLine, CornerPtR);

          /*
          APATrajCalPointIsAtAboveOfLine = 0, // Only used when line is horizontal.
          APATrajCalPointIsAtUnderOfLine, // Only used when line is horizontal.
          APATrajCalPointIsAtLeftOfLine, // Used when line is vertical or incline.
          APATrajCalPointIsAtRightOfLine, // Used when line is vertical or incline.
          APATrajCalPointIsOnLine, // Point is on line with a tollerance.
          */

          if (PtPosIndex == APATrajCalPointIsAtAboveOfLine) {
            // OK, Car will not hit the obj2.
          } else if ((PtPosIndex == APATrajCalPointIsAtUnderOfLine) || (PtPosIndex == APATrajCalPointIsOnLine)) {
            // OK, Car will hit the obj2.
            return TRUE;
          } else {
            if (SideLine.A > 0) {
              if (PtPosIndex == APATrajCalPointIsAtRightOfLine) {
                return TRUE;
              }
            } else {
              if (PtPosIndex == APATrajCalPointIsAtLeftOfLine) {
                return TRUE;
              }
            }
          }

          if (CornerPtF.x > USSPar.TrajCalObj1Pos.x) {

            PtPosIndex = APATrajCalCheckIfThePointIsAtLeftOrRightSideOfALine(&SideLine, CornerPtF);

            /*
            APATrajCalPointIsAtAboveOfLine = 0, // Only used when line is horizontal.
            APATrajCalPointIsAtUnderOfLine, // Only used when line is horizontal.
            APATrajCalPointIsAtLeftOfLine, // Used when line is vertical or incline.
            APATrajCalPointIsAtRightOfLine, // Used when line is vertical or incline.
            APATrajCalPointIsOnLine, // Point is on line with a tollerance.
            */

            if (PtPosIndex == APATrajCalPointIsAtAboveOfLine) {
              // OK, Car will not hit the obj2.
            } else if ((PtPosIndex == APATrajCalPointIsAtUnderOfLine) || (PtPosIndex == APATrajCalPointIsOnLine)) {
              // OK, Car will hit the obj2.
              return TRUE;
            } else {
              if (SideLine.A > 0) {
                if (PtPosIndex == APATrajCalPointIsAtRightOfLine) {
                  return TRUE;
                }
              } else {
                if (PtPosIndex == APATrajCalPointIsAtLeftOfLine) {
                  return TRUE;
                }
              }
            }
          } else {
            // Here we use the obj1pos to check.
            bCheckObj1 = TRUE;

#if 0
						// Cal cross Pt obj2.x and slot r side line.
						CornerPtF.x = USSPar.TrajCalObj1Pos.x + APA_TRAJCAL_PERPEND_CAR_HIT_OBJ_SIDE_CHECK_OBJX_OFFSET_DIS;
						CornerPtF.y = CornerPtF.x * USSPar.TrajCalSlotLeftSideLine.K
						              + USSPar.TrajCalSlotLeftSideLine.B;

						SideLine = CurCarPosLineD;
						SideLine.C = CarRSideLineC;
						PtPosIndex = APATrajCalCheckIfThePointIsAtLeftOrRightSideOfALine(&SideLine,
						                                                                 CornerPtF);

						/*
						APATrajCalPointIsAtAboveOfLine = 0, // Only used when line is horizontal.
						APATrajCalPointIsAtUnderOfLine, // Only used when line is horizontal.
						APATrajCalPointIsAtLeftOfLine, // Used when line is vertical or incline.
						APATrajCalPointIsAtRightOfLine, // Used when line is vertical or incline.
						APATrajCalPointIsOnLine, // Point is on line with a tollerance.
						*/

						if(PtPosIndex == APATrajCalPointIsAtUnderOfLine) {
							// OK, Car will not hit the obj2.
						} else if((PtPosIndex == APATrajCalPointIsAtAboveOfLine)
						          || (PtPosIndex == APATrajCalPointIsOnLine)) {
							// OK, Car will hit the obj2.
							return TRUE;
						} else {
							if(SideLine.A > 0) {
								if(PtPosIndex == APATrajCalPointIsAtLeftOfLine) {
									return TRUE;
								}
							} else {
								if(PtPosIndex == APATrajCalPointIsAtRightOfLine) {
									return TRUE;
								}
							}
						}
#endif
          }

        } else {
          // Out side of slot.
          // Car will not hit obj1.
        }
      }
    }
    if (bCheckObj1 == TRUE) {
      bCarMayHitObj = FALSE;
      if (pCurCarPos->CarAng > (PI / 2.0)) {
        // car ang is large than 90deg.
        // don't check.
        if (USSPar.TrajCalObj1Pos.y < pCurCarPos->Coordinate.y) {
          // Car already hit obj
          bCarMayHitObj = TRUE;
        }
      } else {
        if (USSPar.TrajCalObj1Pos.y > pCurCarPos->Coordinate.y) {
          // Car already hit obj
          bCarMayHitObj = TRUE;
        }
      }
      if (bCarMayHitObj == FALSE) {
        dbTemp1 = APATrajCalGetPointToLineDis(USSPar.TrajCalObj1Pos, CurCarPosLineC);

        if (dbTemp1 < (APACal.LenBetweenRAxisAndRBumper + APACal.APATrajCalPSafetyDisToObj12AtRearBumper)) {
          // Car may hit obj2.
          bCarMayHitObj = TRUE;
        }
      }

      if (bCarMayHitObj == FALSE) {

      } else {
        SideLine   = CurCarPosLineD;
        SideLine.C = CarLSideLineC;
        PtPosIndex = APATrajCalCheckIfThePointIsAtLeftOrRightSideOfALine(&SideLine, USSPar.TrajCalObj1Pos);

        /*
        APATrajCalPointIsAtAboveOfLine = 0, // Only used when line is horizontal.
        APATrajCalPointIsAtUnderOfLine, // Only used when line is horizontal.
        APATrajCalPointIsAtLeftOfLine, // Used when line is vertical or incline.
        APATrajCalPointIsAtRightOfLine, // Used when line is vertical or incline.
        APATrajCalPointIsOnLine, // Point is on line with a tollerance.
        */

        if (PtPosIndex == APATrajCalPointIsAtUnderOfLine) {
          // OK, Car will not hit the obj1.
        } else if ((PtPosIndex == APATrajCalPointIsAtAboveOfLine) || (PtPosIndex == APATrajCalPointIsOnLine)) {
          // OK, Car will hit the obj1.
          return TRUE;
        } else {
          if (SideLine.A > 0) {
            if (PtPosIndex == APATrajCalPointIsAtLeftOfLine) {
              return TRUE;
            }
          } else {
            if (PtPosIndex == APATrajCalPointIsAtRightOfLine) {
              return TRUE;
            }
          }
        }

        dbTemp1 = APATrajCalGetPointToLineDis(USSPar.TrajCalObj1Pos, CurCarPosLineD);

        if (pCurCarPos->Coordinate.x > USSPar.TrajCalObj1Pos.x) {
          CrossPtX = (APACal.HalfWidthOfCar + APACal.APATrajCalPSafetyDisToObj2InStep3TurningCar0); // 10cm,
        } else {

          if (bCheckCornerWillHitBdLine == FALSE) {
            CrossPtX = (APACal.HalfWidthOfCar + APACal.APATrajCalPSafetyDisToObj2InStep3TurningCar1); // 20cm,

          } else {
            CrossPtX = (APACal.HalfWidthOfCar + APACal.APATrajCalPSafetyDisToObj2InStep3TurningCar2); // 35cm.
          }
        }
        if (dbTemp1 < CrossPtX) {
          // Car may hit obj1.
          return TRUE;
        }
      }
    }
  }
  return FALSE;
}
/*************************************************************************************************************************************************
** Syntax :  void USS(void)                                                                                                                     **
**                                                                                                                                              **
** Service ID:   : NA                                                                                                                           **
**                                                                                                                                              **
** Sync/Async:   : Synchronous                                                                                                                  **
**                                                                                                                                              **
** Reentrancy:   : Non Reentrant                                                                                                                **
**                                                                                                                                              **
** Parameters (in): none                                                                                                                        **
**                                                                                                                                              **
** Parameters (out): none                                                                                                                       **
**                                                                                                                                              **
** Return value: none                                                                                                                           **
**                                                                                                                                              **
** Description : ..                                                                                                                             **
*************************************************************************************************************************************************/
#if Debug_SW_PARKINFUNC
void SDGResetDetectedObj(void) {
  SDG_ENUM_TYPE eTemp1;

  for (eTemp1 = 0; eTemp1 < SDG_SUPPORT_SDG_SNS_DIS_NUM; eTemp1++) {
    SDGSnsDtdObjPtBuf[eTemp1].ObjType = SDG_OBJ_TYPE_UNKNOWN;
    ;
    SDGSnsDtdObjPtBuf[eTemp1].SnsDtLoopCnt  = 0;
    SDGSnsDtdObjPtBuf[eTemp1].WrIndex       = 0;
    SDGObjInfo.SnsObjPtBuf[eTemp1].ObjPtCnt = 0;
    SDGObjInfo.SnsObjPtBuf[eTemp1].WrIndex  = 0;
  }
  for (eTemp1 = 0; eTemp1 < SDG_SUPPORT_REGION_NUM; eTemp1++) {
    SDGParkAssistantLeftStatusLS.RegionNZone[eTemp1]  = SDG_NO_OBJ_ZONE;
    SDGParkAssistantRightStatusLS.RegionNZone[eTemp1] = SDG_NO_OBJ_ZONE;
  }
}
#endif
/*************************************************************************************************************************************************
** Syntax :  void USS(void)                                                                                                                     **
**                                                                                                                                              **
** Service ID:   : NA                                                                                                                           **
**                                                                                                                                              **
** Sync/Async:   : Synchronous                                                                                                                  **
**                                                                                                                                              **
** Reentrancy:   : Non Reentrant                                                                                                                **
**                                                                                                                                              **
** Parameters (in): none                                                                                                                        **
**                                                                                                                                              **
** Parameters (out): none                                                                                                                       **
**                                                                                                                                              **
** Return value: none                                                                                                                           **
**                                                                                                                                              **
** Description : ..                                                                                                                             **
*************************************************************************************************************************************************/
#if Debug_SW_PARKINFUNC
void SDGRemoveUselessObjPtFromSDGBuf(SDG_ENUM_TYPE SnsIndex, BOOLEAN bSDGCarIsRunningBackwards) {
  // Remove the nosise points from the SDG buffer

  SDG_ENUM_TYPE WrIndex, CheckStrIndex, CheckEndIndex, SearchBufIndex, PreSearchBufIndex, NextSearchBufIndex;
  SDG_ENUM_TYPE NoObjDtPtStartIndex, NoObjDtPtEndIndex, PrevNoObjDtPtIndex, FirstNoObjPtIndex, SlopeOutOfTolPtIndex;
  SDG_ENUM_TYPE ObjPtCnt, CalCntTemp;
  SDG_ENUM_TYPE CheckLoopCnt, SearchPtCnt, SlopeOutOfTolPtPosTemp;
  APA_ENUM_TYPE NoObjDtPtNum;
  APA_ENUM_TYPE ObjPtOutOfTolNum;
  APA_DISTANCE_TYPE MinSnsDtdDis, SecondMinSnsDtdDis;
  APA_INDEX_TYPE MinSnsDtdDisIndex, MinSnsDtdDisPreIndex, SecondMinSnsDtdDisIndex, SameObjPtCnt, g, h, i, j, k, m, n;
  APA_DISTANCE_CAL_INT_TYPE LTemp;
  APA_DISTANCE_TYPE Dis1, Dis2, Dis3;
  BOOLEAN bObjIsBigEnough, bPointFound;
  APA_SLOT_PT_SLOPE_TYPE PtSlope1, PtSlope2, Slope1;
  APA_DISTANCE_TYPE PointCanBeRemovedMinDis, PointCanBeRemovedMinDis2;

  // Check sensor index, only for rear side sensors?????????

  WrIndex     = SDGObjInfo.SnsObjPtBuf[SnsIndex].WrIndex;
  ObjPtCnt    = SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt;
  SearchPtCnt = 0;

  // key parameters check
  if (WrIndex >= SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE) {
    WrIndex  = SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE - 1;
    ObjPtCnt = SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE;
  } else if (WrIndex < 0) {
    WrIndex  = 0;
    ObjPtCnt = 1;
  }
  if (ObjPtCnt > SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE) {
    ObjPtCnt = SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE;
  } else if (ObjPtCnt <= 0) {
    ObjPtCnt = 1;
    WrIndex  = 0;
  }

  if (WrIndex >= ObjPtCnt) {
    ObjPtCnt = WrIndex + 1;
  }

  SDGObjInfo.SnsObjPtBuf[SnsIndex].WrIndex  = WrIndex;
  SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt = ObjPtCnt;

  CheckStrIndex = WrIndex;

  PointCanBeRemovedMinDis  = SDGPointCanBeRemovedContiguousPointMinDisP;     // 700
  PointCanBeRemovedMinDis2 = SDGPointCanBeRemovedContiguousPointMinDisP * 2; // 1400

  // StartIndex2 = StartIndex;

  for (j = 0; j < 3; j++) {
    // at most remove 3 points at the tail of the detected data every call

    if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt > 2) {

      // n = pSlot->ObjPtCnt - 1;
      // i = n - 1;
      // k = n - 2;
      PreSearchBufIndex = CheckStrIndex;
      if (bSDGCarIsRunningBackwards == TRUE) {
        // car is driving backwards
        SearchBufIndex     = PreSearchBufIndex + 1;
        NextSearchBufIndex = SearchBufIndex + 1;
        if (NextSearchBufIndex >= (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt)) {
          break;
        }
      } else {
        // car is driving forward
        SearchBufIndex     = PreSearchBufIndex - 1;
        NextSearchBufIndex = SearchBufIndex - 1;
        if (NextSearchBufIndex < 0) {
          break;
        }
      }

      LTemp = APASlotProcCalTwoPtApproximateDisInt(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[PreSearchBufIndex].CarPos.Coordinate,
                                                   SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[NextSearchBufIndex].CarPos.Coordinate);

      Dis1  = (APA_DISTANCE_TYPE)LTemp;
      LTemp = APASlotProcCalTwoPtApproximateDisInt(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].CarPos.Coordinate,
                                                   SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[NextSearchBufIndex].CarPos.Coordinate);
      Dis2  = (APA_DISTANCE_TYPE)LTemp;
      if ((Dis1 < PointCanBeRemovedMinDis2)      // 1400
          && (Dis2 < PointCanBeRemovedMinDis)) { // 700

        LTemp = MATH_ABS(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[PreSearchBufIndex].ObjDis -
                         SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[NextSearchBufIndex].ObjDis);
        Dis3  = (APA_DISTANCE_TYPE)LTemp;
        // APASlotSamplePointUpdateSmallDeltaLen < APASlotSamplePointUpdateSmallDeltaLen2
        if ((Dis3 < SDGSamplePointUpdateSmallDeltaLen)                      // 25
            || ((Dis3 < SDGSamplePointUpdateSmallDeltaLen2)                 // 200
                && (Dis2 < SDGPointCanBeRemovedContiguousPointMinDisP2))) { // 200
          if (((SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].ObjDis <=
                SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[NextSearchBufIndex].ObjDis) &&
               (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].ObjDis >=
                SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[PreSearchBufIndex].ObjDis)) ||
              ((SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].ObjDis >=
                SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[NextSearchBufIndex].ObjDis) &&
               (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].ObjDis <=
                SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[PreSearchBufIndex].ObjDis)) ||
              ((SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].ObjDis >=
                SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[NextSearchBufIndex].ObjDis) &&
               (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].ObjDis >=
                SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[PreSearchBufIndex].ObjDis)) // ???????????? is the judge strict enough/correct?
          ) {
            // get rid of SearchBufIndex;
            NextSearchBufIndex = SearchBufIndex + 1;
            for (; NextSearchBufIndex < SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt; NextSearchBufIndex++) {
              APATrajCalCopyMemory((UCHAR *)(&SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex]),
                                   (UCHAR *)(&SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[NextSearchBufIndex]),
                                   sizeof(SDGObjPointType));
              SearchBufIndex++;
            }
            SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt--;

            if (bSDGCarIsRunningBackwards == TRUE) {
              // write index will not change
              // car is driving backwards
            } else {
              // car is driving forward
              CheckStrIndex--;
            }
          } else {
            break;
          }
        } else {
          break;
        }
      } else {
        break;
      }
    } else {
      break;
    }
  }

  for (j = 0; j < 3; j++) {
    // at most remove 3 points at the tail of the detected data	every call

    if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt > 2) {

      // n = pSlot->ObjPtCnt - 1;
      // i = n - 1;
      // k = n - 2;

      PreSearchBufIndex = CheckStrIndex;
      if (bSDGCarIsRunningBackwards == TRUE) {
        // car is driving backwards
        SearchBufIndex     = PreSearchBufIndex + 1;
        NextSearchBufIndex = SearchBufIndex + 1;
        if (NextSearchBufIndex >= (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt)) {
          break;
        }
      } else {
        // car is driving forward
        SearchBufIndex     = PreSearchBufIndex - 1;
        NextSearchBufIndex = SearchBufIndex - 1;
        if (NextSearchBufIndex < 0) {
          break;
        }
      }

      LTemp = APASlotProcCalTwoPtApproximateDisInt(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[PreSearchBufIndex].CarPos.Coordinate,
                                                   SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[NextSearchBufIndex].CarPos.Coordinate);

      Dis1  = (APA_DISTANCE_TYPE)LTemp;
      LTemp = APASlotProcCalTwoPtApproximateDisInt(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].CarPos.Coordinate,
                                                   SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[NextSearchBufIndex].CarPos.Coordinate);
      Dis2  = (APA_DISTANCE_TYPE)LTemp;
      if ((Dis1 < PointCanBeRemovedMinDis2)      // 1400
          && (Dis2 < PointCanBeRemovedMinDis)) { // 700

        PtSlope1 = APASlotProcCalTwoObjPtSlope(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[PreSearchBufIndex].CarPos.Coordinate,
                                               SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].CarPos.Coordinate,
                                               SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[PreSearchBufIndex].ObjDis,
                                               SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].ObjDis);

        PtSlope2 = APASlotProcCalTwoObjPtSlope(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].CarPos.Coordinate,
                                               SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[NextSearchBufIndex].CarPos.Coordinate,
                                               SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].ObjDis,
                                               SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[NextSearchBufIndex].ObjDis);

        Dis1 = (APA_DISTANCE_TYPE)PtSlope1;
        Dis2 = (APA_DISTANCE_TYPE)PtSlope2;
        Dis1 -= Dis2;
        LTemp = MATH_ABS(Dis1);
        Dis1  = (APA_DISTANCE_TYPE)LTemp;

        if (Dis1 < SDGSamplePointCanBeRemovedMaxObjPtDeltaSlope) { // 1
          // get rid of SearchBufIndex;

          NextSearchBufIndex = SearchBufIndex + 1;
          for (; NextSearchBufIndex < SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt; NextSearchBufIndex++) {
            APATrajCalCopyMemory((UCHAR *)(&SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex]),
                                 (UCHAR *)(&SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[NextSearchBufIndex]),
                                 sizeof(SDGObjPointType));
            SearchBufIndex++;
          }
          SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt--;

          if (bSDGCarIsRunningBackwards == TRUE) {
            // write index will not change
            // car is driving backwards
          } else {
            // car is driving forward
            CheckStrIndex--;
          }
        } else {
          break;
        }
      } else {
        break;
      }
    } else {
      break;
    }
  }

  // SDGObjInfo.SnsObjPtBuf[SnsIndex].WrIndex = CheckStrIndex;

  if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt > 3) {

    for (CheckLoopCnt = 0; CheckLoopCnt < 3; CheckLoopCnt++) {

      if (bSDGCarIsRunningBackwards == TRUE) {
        // car is driving backwards
        // x of car pos is increasing
        CheckEndIndex = SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt - 1;

      } else {
        // car is driving forward
        // x of car pos is decreasing
        CheckEndIndex = 0;
      }

      SearchPtCnt = MATH_ABS(CheckStrIndex - CheckEndIndex);

      SearchBufIndex     = CheckStrIndex;
      NextSearchBufIndex = SearchBufIndex;
      bObjIsBigEnough    = FALSE;

      MinSnsDtdDisIndex = SearchBufIndex;

      MinSnsDtdDis            = SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[MinSnsDtdDisIndex].ObjDis;
      SecondMinSnsDtdDisIndex = MinSnsDtdDisIndex;
      SecondMinSnsDtdDis      = MinSnsDtdDis;

      NoObjDtPtNum        = 0;
      ObjPtOutOfTolNum    = 0;
      NoObjDtPtStartIndex = SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE;
      NoObjDtPtEndIndex   = SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE;
      PrevNoObjDtPtIndex  = SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE;

      FirstNoObjPtIndex    = SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE;
      SlopeOutOfTolPtIndex = SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE;

      while (SearchPtCnt >= 0) {
        PreSearchBufIndex = SearchBufIndex;
        if (bSDGCarIsRunningBackwards == TRUE) {
          // car is driving backwards
          SearchBufIndex++;
          NextSearchBufIndex = SearchBufIndex + 1;
          if (NextSearchBufIndex > CheckEndIndex) {
            NextSearchBufIndex = CheckEndIndex;
          }
        } else {
          // car is driving forward
          SearchBufIndex--;
          NextSearchBufIndex = SearchBufIndex - 1;
          if (NextSearchBufIndex < 0) {
            NextSearchBufIndex = 0;
          }
        }

        if ((SearchBufIndex < 0) || (SearchBufIndex >= (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt))) {
          break;
        }

        if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].ObjDis == NO_OBJ_DISTANCE) {
          // current check point is a no obj distance point
          if (PrevNoObjDtPtIndex < SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE) {
            if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[PreSearchBufIndex].ObjDis != NO_OBJ_DISTANCE) {
              LTemp = APASlotProcCalTwoPtApproximateDisInt(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[PrevNoObjDtPtIndex].CarPos.Coordinate,
                                                           SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[PreSearchBufIndex].CarPos.Coordinate);
              Dis1  = (APA_DISTANCE_TYPE)LTemp;

              if (Dis1 > SDGSamplePointNoisePtCanBeRemovedRegardAsNoiseMinObjWidth) { // 250
                // Obj detected.
                bObjIsBigEnough    = TRUE;
                PrevNoObjDtPtIndex = SearchBufIndex;
              }
            }
          } else {
          }
          if (FirstNoObjPtIndex == SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE) {
            FirstNoObjPtIndex = SearchBufIndex;
          }

        } else {
          // current check point is not a no obj distance point
          // search point which is regarded as a noise point and can be removed
          LTemp = APASlotProcCalTwoPtApproximateDisInt(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[CheckStrIndex].CarPos.Coordinate,
                                                       SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].CarPos.Coordinate);
          Dis1  = (APA_DISTANCE_TYPE)LTemp;

          if (Dis1 > SDGSamplePointNoisePtStartCheckBkObjWidth) { // 100cm
            SlopeOutOfTolPtPosTemp = 3;                           // default to no.
            if (SearchBufIndex != CheckEndIndex) {
              // ok, next search index exists.
              // rearch the contiguous 3 points

              if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[PreSearchBufIndex].ObjDis == NO_OBJ_DISTANCE) {
                // previous point is a no obj distance point
                if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[NextSearchBufIndex].ObjDis == NO_OBJ_DISTANCE) {
                  // next ponit is a no obj distance point either
                  // get rid off the current point.
                  /*
                                  - * -
                  */
                  SlopeOutOfTolPtIndex = SearchBufIndex;
                } else {
                  // next point is not a on obj distance point
                  if (bSDGCarIsRunningBackwards == TRUE) {
                    // car is driving backwards
                    g = PreSearchBufIndex - 1;
                    while (g > 0) {
                      if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[g].ObjDis != NO_OBJ_DISTANCE) {
                        break;
                      }
                      g--;
                    }

                  } else {
                    // car is driving forward
                    g = PreSearchBufIndex + 1;
                    while (g < (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt)) {
                      if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[g].ObjDis != NO_OBJ_DISTANCE) {
                        break;
                      }
                      g++;
                    }
                  }

                  LTemp = APASlotProcCalTwoPtApproximateDisInt(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[PreSearchBufIndex].CarPos.Coordinate,
                                                               SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[g].CarPos.Coordinate);
                  Dis3  = (APA_DISTANCE_TYPE)LTemp;

                  if (Dis3 > SDGSamplePointNoisePtCanBeRemovedCheckMinNoObjWidth) { // 500
                    // no obj distance > 500
                    // check the point slop
                    SlopeOutOfTolPtPosTemp = 2; // at the end of obj.
                  }
                }
              } else {
                // previous and current points are not no obj distance points

                if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[NextSearchBufIndex].ObjDis == NO_OBJ_DISTANCE) {
                  // next point is no obj distance point, but current and previous points are not no obj distance point
                  if (bSDGCarIsRunningBackwards == TRUE) {
                    // car is driving backwards
                    g = NextSearchBufIndex + 1;
                    while (g < (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt)) {
                      if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[g].ObjDis != NO_OBJ_DISTANCE) {
                        // find the next point which detected obj
                        break;
                      } else {
                        // keep searching
                      }
                      g++;
                    }

                  } else {
                    // car is driving forward
                    g = NextSearchBufIndex - 1;
                    while (g > 0) {
                      if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[g].ObjDis != NO_OBJ_DISTANCE) {
                        // find the next point which detected obj
                        break;
                      } else {
                        // keep searching
                      }
                      g--;
                    }
                  }
                  if (((bSDGCarIsRunningBackwards == TRUE) && (g >= CheckEndIndex)) ||
                      ((bSDGCarIsRunningBackwards == FALSE) && (g <= CheckEndIndex))) {
                    // need to distinguish driving backwards and driving forward???????????????????????????
                    SlopeOutOfTolPtPosTemp = 0; // at the start of obj.
                  } else {
                    // check the distance between the current point and the next point which detected obj
                    // if the distance is large enough that means
                    LTemp = APASlotProcCalTwoPtApproximateDisInt(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].CarPos.Coordinate,
                                                                 SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[g].CarPos.Coordinate);
                    Dis3  = (APA_DISTANCE_TYPE)LTemp;

                    if (Dis3 > SDGSamplePointNoisePtCanBeRemovedCheckMinNoObjWidth) { // 500
                      // No obj width > 50cm
                      // check the point slope.
                      // need to distinguish driving backwards and driving forward???????????????????????????
                      SlopeOutOfTolPtPosTemp = 0; // at the start of obj.
                    }
                  }
                } else if (NextSearchBufIndex != SearchBufIndex) {
                  // all of the previous, current and next points are not no obj distance point
                  SlopeOutOfTolPtPosTemp = 1; // in the mid of obj.
                }
              }
            } else {
              // that means current point is the oldest(first) point
              if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[PreSearchBufIndex].ObjDis == NO_OBJ_DISTANCE) {
                // unknown point
                // just get rid of it.

                SlopeOutOfTolPtIndex = SearchBufIndex;

              } else {
                SlopeOutOfTolPtPosTemp = 0; // at the start of obj.
              }
              NextSearchBufIndex = SearchBufIndex;
            }

            if (SlopeOutOfTolPtPosTemp < 3) {
              PtSlope1 = APASlotProcCalTwoObjPtSlope(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].CarPos.Coordinate,
                                                     SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[NextSearchBufIndex].CarPos.Coordinate,
                                                     SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].ObjDis,
                                                     SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[NextSearchBufIndex].ObjDis);

              PtSlope2 = APASlotProcCalTwoObjPtSlope(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[PreSearchBufIndex].CarPos.Coordinate,
                                                     SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].CarPos.Coordinate,
                                                     SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[PreSearchBufIndex].ObjDis,
                                                     SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].ObjDis);

              if (SlopeOutOfTolPtPosTemp == 0) {
                // at the start of obj
                if (PtSlope2 == APA_SLOT_OBJ_PT_SLOPE_ERROR_OBJ_WIDTH_TOO_SHORT) {
                  // ?? use
                  if (bSDGCarIsRunningBackwards == TRUE) {
                    // car is driving backwards
                    g = PreSearchBufIndex - 1;
                  } else {
                    // car is driving forward
                    g = PreSearchBufIndex + 1; // g = PreSearchBufIndex + 1 -> g = SearchBufIndex + 2
                  }
                  if ((((bSDGCarIsRunningBackwards == TRUE) && (g >= CheckStrIndex)) ||
                       ((bSDGCarIsRunningBackwards == FALSE) && (g <= CheckStrIndex)))) {
                    if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[g].ObjDis != NO_OBJ_DISTANCE) {

                      Dis1 = SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[PreSearchBufIndex].ObjDis -
                             SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].ObjDis;
                      if ((Dis1 > SDGSamplePointNoisePtCanBeRemovedHeadOrTailMaxDeltaObjDis) // 30 or 70
                          &&
                          ((SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[g].ObjDis - SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].ObjDis) >
                           SDGSamplePointNoisePtCanBeRemovedHeadOrTailMaxDeltaObjDis)) { // 30 or 70
                        // Noise point confirmed.
                        /*
i
                                * <- noise

* g
                                  * m

                        */
                        SlopeOutOfTolPtIndex = SearchBufIndex;
                      }
                    } else {
                      LTemp = APASlotProcCalTwoPtApproximateDisInt(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].CarPos.Coordinate,
                                                                   SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[g].CarPos.Coordinate);
                      Dis1  = (APA_DISTANCE_TYPE)LTemp;

                      if (Dis1 < SDGSamplePointNoisePtCanBeRemovedRegardAsNoiseMinObjWidth) { // 250
                        // Noise confirmed.  detected.
                        SlopeOutOfTolPtIndex = SearchBufIndex;
                      }
                    }
                  }
                } else if ((PtSlope2 > SDGSamplePointNoisePtCanBeRemovedHeadOrTailMaxSlope)       // 20deg, //30deg
                           || (PtSlope2 < SDGSamplePointNoisePtCanBeRemovedHeadOrTailMinSlope)) { // -45deg,// -66deg
                  // Ok, points can be removed.
                  // > 30deg or < -60deg.
                  /*
i
                          * <- noise         * m


                              * m          * <- noise
                                           i

                  */
                  SlopeOutOfTolPtIndex = SearchBufIndex;
                }
              } else if (SlopeOutOfTolPtPosTemp == 1) {
                // At mid of obj
                // Note
                // m = i + 1
                // h = i - 1

                Dis1 = SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[PreSearchBufIndex].ObjDis -
                       SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].ObjDis;
                if ((Dis1 > SDGSamplePointNoisePtCanBeRemovedHeadOrTailMaxDeltaObjDis) // 30 / 70
                    && ((SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[NextSearchBufIndex].ObjDis -
                         SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].ObjDis) >
                        SDGSamplePointNoisePtCanBeRemovedHeadOrTailMaxDeltaObjDis)) { // 30 / 70
                  if ((PtSlope1 == APA_SLOT_OBJ_PT_SLOPE_ERROR_OBJ_WIDTH_TOO_SHORT) ||
                      (PtSlope2 == APA_SLOT_OBJ_PT_SLOPE_ERROR_OBJ_WIDTH_TOO_SHORT)) {
                    // ?? use
                    // Noise point confirmed.
                    /*
i
                            * <- noise

* h
                              * m

                    */
                    SlopeOutOfTolPtIndex = SearchBufIndex;
                  } else {

                    Slope1 = (APA_SLOT_PT_SLOPE_CAL_TYPE)PtSlope1 - (APA_SLOT_PT_SLOPE_CAL_TYPE)PtSlope2;

                    if ((Slope1 < -SDGSamplePointAllowedMaxDeltaSlope)      // - 30 -> 45 deg
                        || (Slope1 > SDGSamplePointAllowedMaxDeltaSlope)) { // 30 -> 45 deg
                      /*
i      *
                              *   *
                                *
m
                      ***
                        h
                      */
                      SlopeOutOfTolPtIndex = SearchBufIndex;
                    }
                  }
                } else {
                  // not a noise.
                }
              } else {
                // at the end of obj.
                if (PtSlope1 == APA_SLOT_OBJ_PT_SLOPE_ERROR_OBJ_WIDTH_TOO_SHORT) {
                  // ?? use
                  if (bSDGCarIsRunningBackwards == TRUE) {
                    // car is driving backwards
                    g = NextSearchBufIndex + 1;
                  } else {
                    // car is driving forward
                    g = NextSearchBufIndex - 1; // g = h - 1 -> g = i - 2
                  }
                  if (((bSDGCarIsRunningBackwards == TRUE) && (g <= CheckEndIndex)) ||
                      ((bSDGCarIsRunningBackwards == FALSE) && (g >= CheckEndIndex))) {
                    if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[g].ObjDis != NO_OBJ_DISTANCE) {
                      Dis1 = SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[NextSearchBufIndex].ObjDis -
                             SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].ObjDis;
                      if ((Dis1 > SDGSamplePointNoisePtCanBeRemovedHeadOrTailMaxDeltaObjDis) // 30
                          &&
                          ((SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[g].ObjDis - SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].ObjDis) >
                           SDGSamplePointNoisePtCanBeRemovedHeadOrTailMaxDeltaObjDis)) { // 30
                        // Noise point confirmed.
                        /*
i
                                * <- noise

* g
                          * h

                        */
                        SlopeOutOfTolPtIndex = SearchBufIndex;
                      }
                    } else {
                      LTemp = APASlotProcCalTwoPtApproximateDisInt(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].CarPos.Coordinate,
                                                                   SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[g].CarPos.Coordinate);
                      Dis1  = (APA_DISTANCE_TYPE)LTemp;

                      if (Dis1 < SDGSamplePointNoisePtCanBeRemovedRegardAsNoiseMinObjWidth) { // 250
                        // Noise confirmed.  detected.
                        SlopeOutOfTolPtIndex = SearchBufIndex;
                      }
                    }
                  } else {

                    Dis1 = SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[NextSearchBufIndex].ObjDis -
                           SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].ObjDis;
                    if (Dis1 > SDGSamplePointNoisePtCanBeRemovedHeadOrTailMaxDeltaObjDis) // 30
                    {
                      // Noise point confirmed.
                      /*
i
                              * <- noise


                        * h

                      */
                      SlopeOutOfTolPtIndex = SearchBufIndex;
                    }
                  }
                } else if (((-PtSlope1) > SDGSamplePointNoisePtCanBeRemovedHeadOrTailMaxSlope)       // 17 -> 30deg
                           || ((-PtSlope1) < SDGSamplePointNoisePtCanBeRemovedHeadOrTailMinSlope)) { // -70 -> 66deg
                  // Ok, points can be removed.
                  // > 30deg or < -60deg.
                  /*
i
                          * <- noise         * m


                              * m          * <- noise
                                           i

                  */
                  SlopeOutOfTolPtIndex = SearchBufIndex;
                }
              }
            }

            if (SlopeOutOfTolPtIndex != SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE) {
              // remove it.
              j = SlopeOutOfTolPtIndex;
              for (g = SlopeOutOfTolPtIndex + 1; g < SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt; g++) {
                APATrajCalCopyMemory((UCHAR *)(&SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[j]),
                                     (UCHAR *)(&SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[g]),
                                     sizeof(SDGObjPointType));
                j++;
              }
              SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt--;

              if (CheckStrIndex > SlopeOutOfTolPtIndex) {
                CheckStrIndex--;
              }
              if (CheckStrIndex >= SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt) {
                CheckStrIndex = SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt - 1;
              }
              break;
            }
          }
        }
        if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].ObjDis <= MinSnsDtdDis) {
          MinSnsDtdDis      = SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].ObjDis;
          MinSnsDtdDisIndex = SearchBufIndex;
        }

        ObjPtOutOfTolNum++;
        if (bObjIsBigEnough == TRUE) {
          NoObjDtPtNum        = 0;
          ObjPtOutOfTolNum    = 0;
          NoObjDtPtStartIndex = SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE;
          NoObjDtPtEndIndex   = SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE;
        } else {
          if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].ObjDis == NO_OBJ_DISTANCE) {
            PrevNoObjDtPtIndex = SearchBufIndex;
            if (NoObjDtPtEndIndex == SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE) {
              NoObjDtPtEndIndex = SearchBufIndex;
            } else {
              NoObjDtPtStartIndex = SearchBufIndex;
            }
            NoObjDtPtNum++;
          }
        }

        SearchPtCnt--;
      }
      if ((SlopeOutOfTolPtIndex == SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE) || (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt < 4)) {
        break;
      }
    }

    // Note: That means no point is removed in previous step or i is the index which is far than 2500 from the last point
    // The following parts is to check if the MinSnsDtdDisIndex point is noise and if need to be deleted.
    if ((SlopeOutOfTolPtIndex == SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE) && (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt > 3) &&
        (MinSnsDtdDis != NO_OBJ_DISTANCE)) {
      // That means no point is removed in previous step
      // and means that i == -1 or i == pSlot->ObjPtCnt - 21
      // the third possibility is i is between i == pSlot->ObjPtCnt - 21 and pSlot->ObjPtCnt - 1
      // and the distance between i and pSlot->ObjPtCnt - 1 is greater than 2500

      // CheckStrIndex = SDGObjInfo.SnsObjPtBuf[SnsIndex].WrIndex;
      if (bSDGCarIsRunningBackwards == TRUE) {
        // car is driving backwards
        // x of car pos is increasing
        CheckEndIndex = SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt - 1;
        SearchBufIndex--; // so i == 0 or i == pSlot->ObjPtCnt - 20
        MinSnsDtdDisPreIndex = MinSnsDtdDisIndex - 1;
      } else {
        // car is driving forward
        // x of car pos is decreasing
        CheckEndIndex = 0;
        SearchBufIndex++; // so i == 0 or i == pSlot->ObjPtCnt - 20
        MinSnsDtdDisPreIndex = MinSnsDtdDisIndex + 1;
      }

      // i = Obj width End point.
      // n = latest point. CheckStrIndex
      // m = MinSnsDtdDisIndex + 1; MinSnsDtdDisPreIndex

      // if(((i < MinSnsDtdDisIndex) || (i == 0)) && (i >= 0) && (n > m)){

      if (((bSDGCarIsRunningBackwards == TRUE) && (((SearchBufIndex > MinSnsDtdDisIndex) || (SearchBufIndex == CheckEndIndex)) &&
                                                   (SearchBufIndex <= CheckEndIndex) && (CheckStrIndex < MinSnsDtdDisPreIndex))) ||
          ((bSDGCarIsRunningBackwards == FALSE) && (((SearchBufIndex < MinSnsDtdDisIndex) || (SearchBufIndex == CheckEndIndex)) &&
                                                    (SearchBufIndex >= CheckEndIndex) && (CheckStrIndex > MinSnsDtdDisPreIndex)))) {

        LTemp = APASlotProcCalTwoPtApproximateDisInt(
            SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[CheckStrIndex].CarPos.Coordinate,
            SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[MinSnsDtdDisPreIndex].CarPos.Coordinate); // m = MinSnsDtdDisIndex + 1, from m to CheckStrIndex
        Dis1  = (APA_DISTANCE_TYPE)LTemp;
        LTemp = APASlotProcCalTwoPtApproximateDisInt(
            SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[MinSnsDtdDisIndex].CarPos.Coordinate,
            SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].CarPos.Coordinate); // i < MinSnsDtdDisIndex
        Dis2        = (APA_DISTANCE_TYPE)LTemp;
        bPointFound = FALSE;
        LTemp       = APASlotProcCalTwoPtApproximateDisInt(
            SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[MinSnsDtdDisIndex].CarPos.Coordinate,
            SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[CheckEndIndex].CarPos.Coordinate); // CheckEndIndex <= i < MinSnsDtdDisIndex
        Dis3 = (APA_DISTANCE_TYPE)LTemp;

        if (Dis3 < SDGSamplePointNoisePtCanBeRemovedCheckStartHeadWidth) { // 500
          // Note
          // Distance between the first point(0) to the MinSnsDtdDisIndex point is less than 500
          // may be a noise at head.
          /*

          * <- first point may be a noise.

             ******
          */
          /*

   * <- first piont may be a noise.

        *****
      *
             -----

          */
          bPointFound = TRUE;
        } else {
          // Distance between the MinSnsDtdDisIndex and the first point stored in the buffer is greater than 500

          k = NoObjDtPtStartIndex;
          if (k == SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE) {
            k = NoObjDtPtEndIndex;
          }
          if (k < SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE) {

            if (((bSDGCarIsRunningBackwards == TRUE) && (k > MinSnsDtdDisIndex)) ||
                ((bSDGCarIsRunningBackwards == FALSE) && (k < MinSnsDtdDisIndex))) {

              j = k; // j = NoObjDtPtStartIndex
              if (bSDGCarIsRunningBackwards == TRUE) {
                // car is driving backwards
                while (k < CheckEndIndex) {
                  k++;
                  if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[k].ObjDis != NO_OBJ_DISTANCE) {
                    break;
                  }
                }

              } else {
                // car is driving forward
                while (k > CheckEndIndex) {
                  k--;
                  if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[k].ObjDis != NO_OBJ_DISTANCE) {
                    break;
                  }
                }
              }

              if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[k].ObjDis == NO_OBJ_DISTANCE) {
                /*

         * <- first piont may be a noise.
              *****
            *
                   -----

                */
                bPointFound = TRUE;
              } else {
                /*

         * <- first piont may be a noise.
  *            *****
            *
                    -----

                */

                if (bSDGCarIsRunningBackwards == TRUE) {
                  // car is driving backwards
                  k--;
                } else {
                  // car is driving forward
                  k++;
                }
                LTemp = APASlotProcCalTwoPtApproximateDisInt(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[j].CarPos.Coordinate,
                                                             SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[k + 1].CarPos.Coordinate);
                Dis2  = (APA_DISTANCE_TYPE)LTemp;

                if (Dis2 > SDGSamplePointNoisePtCanBeRemovedCheckStartHeadWidth) { // 500
                  // That means there is a space of no obj detected (at least as long as 500) in front of MinSnsDtdDisIndex
                  bPointFound = TRUE;
                }
              }
            }
          }
        }

        if ((Dis1 > SDGSamplePointNoisePtCanBeRemovedCheckStartHeadWidth)     // 500 // m-----n
            && ((Dis2 > SDGSamplePointNoisePtCanBeRemovedCheckStartHeadWidth) // 500 // i----MinSnsDtdDisIndex
                || (bPointFound == TRUE))) {
          // Search for the second minimal distance between point i and the last point detected by APA sensor
          if (bSDGCarIsRunningBackwards == TRUE) {
            // car is driving backwards
            j = SearchBufIndex - CheckStrIndex;
            k = CheckStrIndex + 1;
          } else {
            // car is driving forward
            j = CheckStrIndex - SearchBufIndex;
            k = CheckStrIndex - 1;
          }
          while (j > 0) {

            if ((SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[k].ObjDis < SecondMinSnsDtdDis) &&
                (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[k].ObjDis > MinSnsDtdDis)) {
              LTemp = APASlotProcCalTwoPtApproximateDisInt(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[k].CarPos.Coordinate,
                                                           SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[MinSnsDtdDisIndex].CarPos.Coordinate);
              Dis1  = (APA_DISTANCE_TYPE)LTemp;

              if (Dis1 > SDGSamplePointNoisePtCanBeRemovedCheckNoiseWidth) { // 400
                // SecondMinSnsDtdDisIndex is at least 500 far away from MinSnsDtdDisIndex
                SecondMinSnsDtdDis      = SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[k].ObjDis;
                SecondMinSnsDtdDisIndex = k;
              }
            }
            if (bSDGCarIsRunningBackwards == TRUE) {
              // car is driving backwards
              k++;
            } else {
              // car is driving forward
              k--;
            }
            j--;
          }

          if ((SecondMinSnsDtdDis != NO_OBJ_DISTANCE) && ((SecondMinSnsDtdDis - MinSnsDtdDis) > SDGSamplePointNoisePtCanBeRemovedMaxDis) // 300
          ) {
            // SecondMinSnsDtdDis is at least 300 deeper than MinSnsDtdDis

            // search for the start point of SecondMinSnsDtdDisIndex.
            // Note: The precondition is that SecondMinSnsDtdDisIndex object is continuous or the
            // following search is not correct enough??????????
            SameObjPtCnt = 0;
            j            = SecondMinSnsDtdDisIndex; // Obj width start point.

            if (bSDGCarIsRunningBackwards == TRUE) {
              // car is driving backwards
              for (g = SecondMinSnsDtdDisIndex; g <= SearchBufIndex; g++) {
                if ((SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[g].ObjDis >= SecondMinSnsDtdDis) &&
                    ((SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[g].ObjDis - SecondMinSnsDtdDis) <
                     SDGSamplePointNoisePtCanBeRemovedSameObjTol)) { // 250
                  SameObjPtCnt++;
                  j = g;
                }
              }

            } else {
              // car is driving forward
              for (g = SecondMinSnsDtdDisIndex; g >= SearchBufIndex; g--) {
                if ((SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[g].ObjDis >= SecondMinSnsDtdDis) &&
                    ((SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[g].ObjDis - SecondMinSnsDtdDis) <
                     SDGSamplePointNoisePtCanBeRemovedSameObjTol)) { // 250
                  SameObjPtCnt++;
                  j = g;
                }
              }
            }

            // bPointFound == TRUE means that there is a continuous space of no obj detected in front of MinSnsDtdDisIndex
            // j < SecondMinSnsDtdDisIndex
            if ((bPointFound == TRUE) ||
                (((bSDGCarIsRunningBackwards == TRUE) && (j > MinSnsDtdDisIndex)) ||
                 ((bSDGCarIsRunningBackwards == FALSE) && (j < MinSnsDtdDisIndex))) ||
                (((APA_DISTANCE_TYPE)(
                     APASlotProcCalTwoPtApproximateDisInt(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[j].CarPos.Coordinate,
                                                          SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[MinSnsDtdDisIndex].CarPos.Coordinate))) <
                 SDGSamplePointNoisePtCanBeRemovedCheckNoiseToObjWidth)) { // 500
              // OK,
              // search the end point
              bPointFound = FALSE;

              if ((FirstNoObjPtIndex < SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE) &&
                  (((bSDGCarIsRunningBackwards == TRUE) && (FirstNoObjPtIndex < MinSnsDtdDisIndex)) ||
                   ((bSDGCarIsRunningBackwards == FALSE) && (FirstNoObjPtIndex > MinSnsDtdDisIndex)))) {

                g = FirstNoObjPtIndex;

                while (((bSDGCarIsRunningBackwards == TRUE) && (g < MinSnsDtdDisIndex)) ||
                       ((bSDGCarIsRunningBackwards == FALSE) && (g > MinSnsDtdDisIndex))) {
                  if (bSDGCarIsRunningBackwards == TRUE) {
                    // car is driving backwards
                    g++;
                  } else {
                    // car is driving forward
                    g--;
                  }

                  if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[g].ObjDis != NO_OBJ_DISTANCE) {
                    break;
                  }
                }
                /*

         * <- end piont may be a noise.
  *****
           *
                              -----

                */

                if (bSDGCarIsRunningBackwards == TRUE) {
                  // car is driving backwards
                  g--;
                } else {
                  // car is driving forward
                  g++;
                }

                LTemp = APASlotProcCalTwoPtApproximateDisInt(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[g].CarPos.Coordinate,
                                                             SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[FirstNoObjPtIndex].CarPos.Coordinate);
                Dis1  = (APA_DISTANCE_TYPE)LTemp;

                if (Dis1 > SDGSamplePointNoisePtCanBeRemovedCheckStartHeadWidth) { // 500
                  // That means there is a space of no obj detected (at least as long as 500) after MinSnsDtdDisIndex
                  bPointFound = TRUE;
                }
              }

              // Search for the end point of SecondMinSnsDtdDisIndex
              // Note: The precondition is that SecondMinSnsDtdDisIndex object is continuous or the
              // following search is not correct enough??????????
              h = SecondMinSnsDtdDisIndex; // Obj width end poiont
              if (bSDGCarIsRunningBackwards == TRUE) {
                // car is driving backwards
                for (g = h; g >= CheckStrIndex; g--) {
                  if ((SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[g].ObjDis >= SecondMinSnsDtdDis) &&
                      ((SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[g].ObjDis - SecondMinSnsDtdDis) <
                       SDGSamplePointNoisePtCanBeRemovedSameObjTol)) { // 250
                    if (g != SecondMinSnsDtdDisIndex) {
                      SameObjPtCnt++;
                    }
                    h = g;
                  }
                }

              } else {
                // car is driving forward

                for (g = h; g <= CheckStrIndex; g++) {
                  if ((SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[g].ObjDis >= SecondMinSnsDtdDis) &&
                      ((SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[g].ObjDis - SecondMinSnsDtdDis) <
                       SDGSamplePointNoisePtCanBeRemovedSameObjTol)) { // 250
                    if (g != SecondMinSnsDtdDisIndex) {
                      SameObjPtCnt++;
                    }
                    h = g;
                  }
                }
              }

              // h > SecondMinSnsDtdDisIndex
              if (((((bSDGCarIsRunningBackwards == TRUE) && (h < MinSnsDtdDisIndex)) ||
                    ((bSDGCarIsRunningBackwards == FALSE) && (h > MinSnsDtdDisIndex))) ||
                   (bPointFound == TRUE) ||
                   (((APA_DISTANCE_TYPE)(
                        APASlotProcCalTwoPtApproximateDisInt(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[h].CarPos.Coordinate,
                                                             SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[MinSnsDtdDisIndex].CarPos.Coordinate))) <
                    SDGSamplePointNoisePtCanBeRemovedCheckNoiseToObjWidth)) // 500
                  && (((bSDGCarIsRunningBackwards == TRUE) && (h < j)) || ((bSDGCarIsRunningBackwards == FALSE) && (h > j))) &&
                  (SameObjPtCnt >= SDGSamplePointNoisePtCanBeRemovedMinSameObjPtNum)) { // 2
                // At least two points.
                // check obj width
                LTemp = APASlotProcCalTwoPtApproximateDisInt(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[h].CarPos.Coordinate,
                                                             SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[j].CarPos.Coordinate);
                Dis1  = (APA_DISTANCE_TYPE)LTemp;

                if (Dis1 > SDGSamplePointNoisePtCanBeRemovedMinObjWidth) { // 500
                  // Ok, Obj is wide enough.

                  LTemp = APASlotProcCalTwoPtApproximateDisInt(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[MinSnsDtdDisPreIndex].CarPos.Coordinate,
                                                               SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[MinSnsDtdDisIndex].CarPos.Coordinate);
                  Dis2  = (APA_DISTANCE_TYPE)LTemp;

                  Dis2 *= 100;
                  Dis2       = Dis2 / Dis1;
                  CalCntTemp = (APA_ENUM_TYPE)Dis2;
                  if ((CalCntTemp <= SDGSamplePointNoisePtCanBeRemovedMaxNoiseWidthPercentage) // 25
                      && (CalCntTemp >= 0)) {
                    // OK, Noise width < 25%.
                    // Can be removed.
                    // delete MinSnsDtdDisIndex

                    // APASlotProcDeletePointCheckSlotStartEndIndex(CurrentSlotIndex, MinSnsDtdDisIndex);
                    SlopeOutOfTolPtIndex = MinSnsDtdDisIndex;
                    j                    = MinSnsDtdDisIndex;
                    for (g = MinSnsDtdDisIndex + 1; g < SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt; g++) {
                      APATrajCalCopyMemory((UCHAR *)(&SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[j]),
                                           (UCHAR *)(&SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[g]),
                                           sizeof(SDGObjPointType));
                      j++;
                    }
                    SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt--;

                    if (CheckStrIndex > MinSnsDtdDisIndex) {
                      CheckStrIndex--;
                    }
                    if (CheckStrIndex >= SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt) {
                      CheckStrIndex = SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt - 1;
                    }
                  }
                }
              }
            }
          }
        }
      }

      if (SlopeOutOfTolPtIndex == SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE) {
        // No Obj point was removed.
        // check if the noise in the slot should be removed.
        if ((ObjPtOutOfTolNum >= SDGSamplePointNoisePtCanBeRemovedMinObjPtOutOfTolNum) // 6
            && (NoObjDtPtEndIndex < SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE) && (NoObjDtPtStartIndex < SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE) &&
            (MATH_ABS(NoObjDtPtEndIndex - NoObjDtPtStartIndex) >= SDGSamplePointNoisePtCanBeRemovedMinNoObjPtWitinNoiseNum) // 3
            && (NoObjDtPtNum >= SDGSamplePointNoisePtCanBeRemovedMinNoObjPtTotalNum)                                        // 4.
            && (((bSDGCarIsRunningBackwards == TRUE) && (NoObjDtPtEndIndex > (CheckStrIndex + 3))) ||
                ((bSDGCarIsRunningBackwards == FALSE) && (NoObjDtPtEndIndex < (CheckStrIndex - 3))))) {
          // may be noise found.
          /*
*** -> Noises
---       ----
          */

#if 0
					// Check the following case:
                    /*

                       ****    *** -> Not regarded as a noise.
                            --     -----
                    */

					m = NoObjDtPtStartIndex;
					k = 0;
					bObjIsBigEnough = FALSE;
					while(m > 0){
						m -- ;
						if(pDisFromCarToObj[m] == NO_OBJ_DISTANCE){
							// keep searching.
							k ++;
							if(k > 2){
								break;
							}
						} else {
							i = m + 1;
							g = NoObjDtPtStartIndex + 1;
							Dis1 = APASlotProcCalTwoPtApproximateDisInt(pCarCenterPointBuf[g], pCarCenterPointBuf[i]);
							if(Dis1 > APACal.APASlotSamplePointNoisePtRegardedAsSameObjMaxNoObjWidth){
								break;
							}
							if(pbObjIsBigEnough[m] != 0){
								bObjIsBigEnough = TRUE;
							}
							break;
						}
					}
					if(bObjIsBigEnough == FALSE)
#endif
          {
            // OK, points between the NoObjDtPtStartIndex and NoObjDtPtEndIndex can be removed.
            if (NoObjDtPtStartIndex > NoObjDtPtEndIndex) {
              g = NoObjDtPtStartIndex;
              j = NoObjDtPtEndIndex + 1;
            } else {
              g = NoObjDtPtEndIndex;
              j = NoObjDtPtStartIndex + 1;
            }
            if (CheckStrIndex >= g) {
              CheckStrIndex = j + CheckStrIndex - g;
            } else if (CheckStrIndex > j) {
              CheckStrIndex = j;
            }
            for (; g < SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt; g++) {
              APATrajCalCopyMemory((UCHAR *)(&SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[j]),
                                   (UCHAR *)(&SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[g]),
                                   sizeof(SDGObjPointType));
              j++;
            }
            SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt = j;
          }
        }
      }
    }
  }

  SDGObjInfo.SnsObjPtBuf[SnsIndex].WrIndex = CheckStrIndex;

#if 0
	for(j = 0; j < 3; j++){

		CheckStrIndex = SDGObjInfo.SnsObjPtBuf[SnsIndex].WrIndex;
		if(bSDGCarIsRunningBackwards == TRUE){
			// car is driving backwards
			// x of car pos is increasing
			CheckEndIndex = SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt - 1;

		} else {
			// car is driving forward
			// x of car pos is decreasing
			CheckEndIndex = 0;
		}

		SearchBufIndex = CheckStrIndex;
		//h = CheckStrIndex;

		if(MATH_ABS(CheckStrIndex - CheckEndIndex) > 2){
			if(bSDGCarIsRunningBackwards == TRUE){
				n = CheckStrIndex + j;
				k = n + 2;
			} else {
				n = CheckStrIndex - j;
				k = n - 2;
			}
			while(((bSDGCarIsRunningBackwards == TRUE) && (k < CheckEndIndex))
			|| ((bSDGCarIsRunningBackwards == FALSE) && (k > CheckEndIndex))){

				bPointFound = TRUE;

				if(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[k].ObjDis != NO_OBJ_DISTANCE){
					if(bSDGCarIsRunningBackwards == TRUE){
						// car is driving backwards
						m = k - 12;
						if(m < n){
							m = n;
						}
						SearchBufIndex = k - 1;
					} else {
						// car is driving forward
						m = k + 12;
						if(m > n){
							m = n;
						}
						SearchBufIndex = k + 1;
					}
/*
					if(bSDGCarIsRunningBackwards == TRUE){
						// car is driving backwards
						for(SearchBufIndex = k - 1; SearchBufIndex > m; SearchBufIndex--){
							Dis1 = SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].ObjDis - SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[k].ObjDis;
							if(Dis1 > SDGSlotSamplePointNoisePtRegardedAsSameObjMaxDeltaObjDis){			// 300
								break;
							}

						}

					} else {
						// car is driving forward
						for(SearchBufIndex = k + 1; SearchBufIndex < m; SearchBufIndex++){
							Dis1 = SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].ObjDis - SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[k].ObjDis;
							if(Dis1 > SDGSamplePointNoisePtRegardedAsSameObjMaxDeltaObjDis){			// 300
								break;
							}

						}

					}
*/
					while(((bSDGCarIsRunningBackwards == TRUE) && (SearchBufIndex > m))
					|| ((bSDGCarIsRunningBackwards == FALSE) && (SearchBufIndex < m))){

						Dis1 = SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].ObjDis - SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[k].ObjDis;
						if(Dis1 > SDGSamplePointNoisePtRegardedAsSameObjMaxDeltaObjDis){			// 300
							break;
						}
						if(bSDGCarIsRunningBackwards == TRUE){
							// car is driving backwards
							SearchBufIndex--;
						} else {
							// car is driving forward
							SearchBufIndex++;
						}

					}


					if(bSDGCarIsRunningBackwards == TRUE){
						// car is driving backwards
						m = k + 12;
						if(m > CheckEndIndex){
							m = CheckEndIndex;
						}
						h = k + 1;
					} else {
						// car is driving forward
						m = k - 12;
						if(m < CheckEndIndex){
							m = CheckEndIndex;
						}
						h = k - 1;
					}

/*
					if(bSDGCarIsRunningBackwards == TRUE){
						// car is driving backwards

						for(h = k + 1; h < m; h++){
							Dis1 = SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[h].ObjDis - SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[k].ObjDis;
							if(Dis1 > SDGSamplePointNoisePtRegardedAsSameObjMaxDeltaObjDis){			// 300
								break;
							}

						}

					} else {
						// car is driving forward
						for(h = k - 1; h > m; h--){
							Dis1 = SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[h].ObjDis - SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[k].ObjDis;
							if(Dis1 > SDGSamplePointNoisePtRegardedAsSameObjMaxDeltaObjDis){			// 300
								break;
							}

						}

					}
*/

					while(((bSDGCarIsRunningBackwards == TRUE) && (h < m))
					|| ((bSDGCarIsRunningBackwards == FALSE) && (h > m))){

						Dis1 = SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[h].ObjDis - SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[k].ObjDis;
						if(Dis1 > SDGSamplePointNoisePtRegardedAsSameObjMaxDeltaObjDis){			// 300
							break;
						}
						if(bSDGCarIsRunningBackwards == TRUE){
							h++;
						} else {
							h--;
						}
					}

					LTemp = APASlotProcCalTwoPtApproximateDisInt(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SearchBufIndex].CarPos.Coordinate,
							SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[h].CarPos.Coordinate);
					Dis1 = (APA_DISTANCE_TYPE)LTemp;

					if(Dis1 < SDGSamplePointNoisePtRegardedAsSameObjMinObjWidth){				// 500
						// Invalid obj width.
						// may be a noise.
						bPointFound = FALSE;
					}

				}

				if(bPointFound == TRUE){
					LTemp = APASlotProcCalTwoPtApproximateDisInt(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[n].CarPos.Coordinate,
					SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[k].CarPos.Coordinate);
					Dis1 = (APA_DISTANCE_TYPE)LTemp;
					if(Dis1 < PointCanBeRemovedMinDis) {// PointCanBeRemovedMinDis = SDGPointCanBeRemovedContiguousPointMinDisP;// 700


						LTemp = MATH_ABS(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[n].ObjDis - SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[k].ObjDis);		// k = n - 2
						Dis2 = (APA_DISTANCE_TYPE)LTemp;
						if(Dis2 < SDGSamplePointUpdateLongDeltaLen) {		// 1000
							if(bSDGCarIsRunningBackwards == TRUE){
								i = k - 1;
							} else {
								i = k + 1;
							}
							while(((bSDGCarIsRunningBackwards == TRUE) && (i > n))
							|| ((bSDGCarIsRunningBackwards == FALSE) && (i < n))){

								if((SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[n].ObjDis <= SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[i].ObjDis)
								&& (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[k].ObjDis <= SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[i].ObjDis)
								) {
									// ok,
								} else {
									break;
								}

								if(bSDGCarIsRunningBackwards == TRUE){
									// car is driving backwards
									i--;
								} else {
									// car is driving forward
									i++;
								}

							}
							if(i == n) {

								if(bSDGCarIsRunningBackwards == TRUE){
									m = k - 1;
								} else {
									m = k + 1;
								}

								if((SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[m].ObjDis - SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[k].ObjDis)
								> SDGSamplePointCanBeRemovedMaxObjDis){		// 8000
									// Keep point m.
									if(bSDGCarIsRunningBackwards == TRUE){
										// car is driving backwards
										m = k - 2;
									} else {
										// car is driving forward
										m = k + 2;
									}
								} else {
									// Ok, get rid of all the points.
								}

								//SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt
								if(bSDGCarIsRunningBackwards == TRUE){
									// car is driving backwards
									n = n + 1;
									for(; k <= CheckEndIndex; k++){
										APATrajCalCopyMemory((UCHAR *) (&SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[n]),
															 (UCHAR *) (&SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[k]),
															 sizeof(SDGObjPointType));
										n++;
										// writh index will not change
										//SDGObjInfo.SnsObjPtBuf[SnsIndex].WrIndex++;
										SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt--;
									}
								} else {
									// car is driving forward
									for(; n <= CheckStrIndex; n++){
										APATrajCalCopyMemory((UCHAR *) (&SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[m]),
															 (UCHAR *) (&SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[n]),
															 sizeof(SDGObjPointType));
										m++;
										SDGObjInfo.SnsObjPtBuf[SnsIndex].WrIndex--;
										SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt--;
									}

								}
								if(SDGObjInfo.SnsObjPtBuf[SnsIndex].WrIndex < 0){
									SDGObjInfo.SnsObjPtBuf[SnsIndex].WrIndex = 0;

								}
								if(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt <= 0){
									SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt = 1;
								}


							}


						}
					}



				}
				if(bSDGCarIsRunningBackwards == TRUE){
					k++;
				} else {
					k--;
				}

			}

		} else {
			break;
		}


	}

#endif
}
#endif
/*************************************************************************************************************************************************
** Syntax :  void USS(void)                                                                                                                     **
**                                                                                                                                              **
** Service ID:   : NA                                                                                                                           **
**                                                                                                                                              **
** Sync/Async:   : Synchronous                                                                                                                  **
**                                                                                                                                              **
** Reentrancy:   : Non Reentrant                                                                                                                **
**                                                                                                                                              **
** Parameters (in): none                                                                                                                        **
**                                                                                                                                              **
** Parameters (out): none                                                                                                                       **
**                                                                                                                                              **
** Return value: none                                                                                                                           **
**                                                                                                                                              **
** Description : ..                                                                                                                             **
*************************************************************************************************************************************************/
#if Debug_SW_PARKINFUNC
void SDGSaveObjPointToBuf(SDG_ENUM_TYPE SnsIndex, SDGObjPointType *pObjPt) {
  // Input Par:
  // pObjPt: Object Point which need to be saved to the Object Buffer outside this function.
  //
  // SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[0]: Tail of the obj pt (Eg: Y = 0)
  // SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjPtCnt]: Head of the obj pt (Eg: Y = 10000)

  SDG_ENUM_TYPE ObjIndex, ObjIndex2, ObjIndex3, ObjIndex4, ObjPtCnt, WrIndex;
  SDG_DISTANCE_TYPE SnsDtdDis, PointPosDeltaDis, PointPosDeltaDis2;
  SDG_DISTANCE_CAL_FLOAT_TYPE DeltaDis;
  SDGCoordinateDataCalFloatType Pt1, Pt2;
  SDG_ENUM_TYPE CarDriveDir;
  BOOLEAN bOverWriteCurPt, bObjPtFound;

  // Insert the current object point to the buffer.
  WrIndex = SDGObjInfo.SnsObjPtBuf[SnsIndex].WrIndex;
  if (WrIndex >= SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE) {
    WrIndex                                   = 0;
    ObjPtCnt                                  = 0;
    SDGObjInfo.SnsObjPtBuf[SnsIndex].WrIndex  = 0;
    SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt = 0;
  } else if (WrIndex < 0) {
    WrIndex                                   = 0;
    WrIndex                                   = 0;
    SDGObjInfo.SnsObjPtBuf[SnsIndex].WrIndex  = 0;
    SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt = 0;
  }

  ObjPtCnt = SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt;
  if (ObjPtCnt > SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE) {
    ObjPtCnt                                  = 0;
    WrIndex                                   = 0;
    SDGObjInfo.SnsObjPtBuf[SnsIndex].WrIndex  = 0;
    SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt = 0;
  } else if (ObjPtCnt < 0) {
    ObjPtCnt                                  = 0;
    WrIndex                                   = 0;
    SDGObjInfo.SnsObjPtBuf[SnsIndex].WrIndex  = 0;
    SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt = 0;
  }

  // kjy 2012 10 03 added.

  // Just use the car angle to distinguish the car pos.
  // The car angle is assumed in the range ( - PI, + PI).
  if ((pObjPt->CarPos.CarAng > (-0.75 * PI)) && (pObjPt->CarPos.CarAng < (-0.25 * PI))) { // (- 3 * PI / 4, - PI / 4)
    // Use X to compare. And X new should great than X old.
    CarDriveDir = 0;
  }
  if ((pObjPt->CarPos.CarAng >= (-0.25 * PI)) && (pObjPt->CarPos.CarAng < (0.25 * PI))) { // (- PI / 4, PI / 4)
    // Use Y to compare. And Y new should great than Y old.
    CarDriveDir = 1;
  } else if ((pObjPt->CarPos.CarAng >= (0.25 * PI)) && (pObjPt->CarPos.CarAng < (0.75 * PI))) { // (PI / 4, 3 * PI / 4)
    // Use X to compare. And X new should less than X old.
    CarDriveDir = 2;
  } else {
    // Use Y to compare. And Y new should less than Y old.
    CarDriveDir = 3;
  }

  if (SDGBooleanFlags.Bits.bSDGCarIsRunningBackwards == FALSE) {
    // drives forwards.
    // Save the current point after the WrIndex.

    // Check if the WrIndex points is the last point.
    if (ObjPtCnt > 0) {
      for (ObjIndex = WrIndex; ObjIndex > 0; ObjIndex--) {
        if (CarDriveDir == 0) {
          // Use X to compare. And X new should great than X old.
          if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.Coordinate.x <= pObjPt->CarPos.Coordinate.x) {
            break;
          }
        } else if (CarDriveDir == 1) {
          // Use Y to compare. And Y new should great than Y old.
          if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.Coordinate.y <= pObjPt->CarPos.Coordinate.y) {
            break;
          }
        } else if (CarDriveDir == 2) {
          // Use X to compare. And X new should less than X old.
          if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.Coordinate.x >= pObjPt->CarPos.Coordinate.x) {
            break;
          }
        } else {
          // Use Y to compare. And Y new should less than Y old.
          if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.Coordinate.y >= pObjPt->CarPos.Coordinate.y) {
            break;
          }
        }
      }
      WrIndex = ObjIndex;

      if (WrIndex >= (ObjPtCnt - 1)) {
        // OK, the last point, just insert the current object after the WrIndex.
        // check if the buffer is full or not?
        WrIndex         = ObjPtCnt - 1;
        ObjIndex        = WrIndex;
        bOverWriteCurPt = FALSE;
        if (CarDriveDir == 0) {
          // Use X to compare. And X new should great than X old.
          if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.Coordinate.x >= pObjPt->CarPos.Coordinate.x) {
            // OK, Insert current car pos into
            bOverWriteCurPt = TRUE;
          }
        } else if (CarDriveDir == 1) {
          // Use Y to compare. And Y new should great than Y old.
          if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.Coordinate.y >= pObjPt->CarPos.Coordinate.y) {
            // OK, Insert current car pos into
            bOverWriteCurPt = TRUE;
          }
        } else if (CarDriveDir == 2) {
          // Use X to compare. And X new should less than X old.
          if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.Coordinate.x <= pObjPt->CarPos.Coordinate.x) {
            // OK, Insert current car pos into
            bOverWriteCurPt = TRUE;
          }
        } else {
          // Use Y to compare. And Y new should less than Y old.
          if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.Coordinate.y <= pObjPt->CarPos.Coordinate.y) {
            // OK, Insert current car pos into
            bOverWriteCurPt = TRUE;
          }
        }

        if (bOverWriteCurPt == FALSE) {
          // Just remove the first object point.
          if (ObjPtCnt < SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE) {
            // Buffer is not full, just save the current point.
            WrIndex++;
            ObjPtCnt++;
          } else {
            WrIndex  = SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE - 1;
            ObjPtCnt = SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE;
            for (ObjIndex2 = 0; ObjIndex2 < SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE - 1; ObjIndex2++) {
              APATrajCalCopyMemory((UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2])),
                                   (UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2 + 1])),
                                   sizeof(SDGObjPointType));
            }
          }
        } else {
          // Keep the same WrIndex, ObjPtCnt.
        }
      } else {
        // WrIndex is not the last point.
        bOverWriteCurPt = FALSE;
        bObjPtFound     = FALSE;
        for (ObjIndex = WrIndex; ObjIndex < ObjPtCnt; ObjIndex++) {

          if (MATH_FABS(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.CarAng - pObjPt->CarPos.CarAng) >
              SDGCal.SDGDrvBkPtKeepMaxDeltaCarAng) { // 60deg
            // Just remove all the pts.
            break;
          }

          if (CarDriveDir == 0) {
            // Use X to compare. And X new should great than X old.
            if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.Coordinate.x == pObjPt->CarPos.Coordinate.x) {
              // Over write the cur pt
              bOverWriteCurPt = TRUE;
              break;
            } else if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.Coordinate.x > pObjPt->CarPos.Coordinate.x) {
              // OK, Insert current car pos into
              bObjPtFound = TRUE;
              break;
            }
          } else if (CarDriveDir == 1) {
            // Use Y to compare. And Y new should great than Y old.
            if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.Coordinate.y == pObjPt->CarPos.Coordinate.y) {
              // Over write the cur pt
              bOverWriteCurPt = TRUE;
              break;
            } else if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.Coordinate.y > pObjPt->CarPos.Coordinate.y) {
              // OK, Insert current car pos into
              bObjPtFound = TRUE;
              break;
            }
          } else if (CarDriveDir == 2) {
            // Use X to compare. And X new should less than X old.
            if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.Coordinate.x == pObjPt->CarPos.Coordinate.x) {
              // Over write the cur pt
              bOverWriteCurPt = TRUE;
              break;
            } else if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.Coordinate.x < pObjPt->CarPos.Coordinate.x) {
              // OK, Insert current car pos into
              bObjPtFound = TRUE;
              break;
            }
          } else {
            // Use Y to compare. And Y new should less than Y old.
            if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.Coordinate.y == pObjPt->CarPos.Coordinate.y) {
              // Over write the cur pt
              bOverWriteCurPt = TRUE;
              break;
            } else if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.Coordinate.y < pObjPt->CarPos.Coordinate.y) {
              // OK, Insert current car pos into
              bObjPtFound = TRUE;
              break;
            }
          }
        }

        if (ObjIndex >= ObjPtCnt) {
          ObjIndex = ObjPtCnt - 1;
        }
        // Just remove the points between the WrIndex and ObjIndex.
        if (bOverWriteCurPt == TRUE) {
          // Keep the same WrIndex and ObjPtCnt.
          WrIndex = ObjIndex;
        } else if (bObjPtFound == FALSE) {
          WrIndex++;
          ObjPtCnt = WrIndex + 1;
        } else if (ObjIndex == WrIndex) { // Note: for this branch, bOverWriteCurPt == FALSE && bObjPtFound == TRUE
          // In fact, this means ObjIndex == ObjPtCnt???????????????????????????????

          if (ObjPtCnt < SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE) {
            // Buffer is not full, just save the current point.
            ObjIndex2 = ObjPtCnt;
            ObjPtCnt++;
            // SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt = ObjPtCnt;
          } else {
            // Just remove the last object point.
            ObjIndex2 = SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE - 1;
            ObjPtCnt  = SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE;
            // SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt = SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE;
          }
          while (ObjIndex2 > ObjIndex) {
            APATrajCalCopyMemory((UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2])),
                                 (UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2 - 1])),
                                 sizeof(SDGObjPointType));
            ObjIndex2--;
          }
          // Save the current obj point to the cell of WrIndex.
        } else {
          // There is space to save the current point.
          ObjIndex2 = WrIndex + 2;
          if (ObjIndex2 < ObjIndex) {
            ObjIndex3 = ObjIndex;
            for (; ObjIndex3 < ObjPtCnt; ObjIndex3++) {
              APATrajCalCopyMemory((UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2])),
                                   (UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex3])),
                                   sizeof(SDGObjPointType));
              ObjIndex2++;
            }
            ObjPtCnt = ObjPtCnt - (ObjIndex - WrIndex - 2);
            // SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt = ObjPtCnt;
          } else if (ObjIndex2 == ObjIndex) {
            // Just save the cur pt to next point of cur WrIndex.
          } else {
            if (ObjPtCnt >= SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE) {
              // Just over write the next point of cur WrIndex.
            } else {
              // remove a space to save the cur obj pt.
              ObjIndex2 = ObjPtCnt;
              ObjPtCnt++;
              while (ObjIndex2 > ObjIndex) {
                APATrajCalCopyMemory((UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2])),
                                     (UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2 - 1])),
                                     sizeof(SDGObjPointType));
                ObjIndex2--;
              }
            }
          }
          // Save the current obj point to the next cell of WrIndex.
          WrIndex++;
        }
      }

      if (WrIndex >= SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE) {
        WrIndex  = SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE - 1;
        ObjPtCnt = SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE;
      } else if (WrIndex < 0) {
        WrIndex  = 0;
        ObjPtCnt = 1;
      }

      if (ObjPtCnt > SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE) {
        ObjPtCnt = SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE;
      } else if (ObjPtCnt <= 0) {
        ObjPtCnt = 1;
        WrIndex  = 0;
      }

      if (WrIndex >= ObjPtCnt) {
        ObjPtCnt = WrIndex + 1;
      }

      APATrajCalCopyMemory((UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[WrIndex])), (UCHAR *)(pObjPt), sizeof(SDGObjPointType));

#ifdef SDG_DEBUG_1
      for (ObjIndex4 = 1; ObjIndex4 < ObjPtCnt; ObjIndex4++) {

        if ((SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex4].CarPos.Coordinate.x >
             SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex4 - 1].CarPos.Coordinate.x) &&
            (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex4].CarPos.CarAng > (15.0 * PI / 180.0))) {

          if (cSDGDbg1 == 0) {
            cSDGDbg2 = 1;
          }
        }
      }

#endif

      // Remove obj point from the buffer.

      // 16. If the delta car angle between the head point and the current point is great than 180 deg, the head point will be removed.
      if ((WrIndex > 0) && MATH_FABS(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[WrIndex].CarPos.CarAng -
                                     SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[0].CarPos.CarAng) > PI) {
        // Remove the head point.
        ObjPtCnt--;
        WrIndex--;
        for (ObjIndex3 = 0; ObjIndex3 < (ObjPtCnt); ObjIndex3++) {
          APATrajCalCopyMemory((UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex3])),
                               (UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex3 + 1])),
                               sizeof(SDGObjPointType));
        }
      }

      // 17. If the delta car angle between the tail point and the current point is great than 180 deg, the tail point will be removed.
      ObjIndex = ObjPtCnt - 1;
      if ((ObjIndex > WrIndex) && MATH_FABS(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[WrIndex].CarPos.CarAng -
                                            SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.CarAng) > PI) {
        // Remove the head point.
        ObjPtCnt--;
      }

// for perpendicular parking slot correction filter 2014 08 21
#if 0
			// 11.	If the object distance within the two object points is great than both these two points,
			// this object points will be removed.
			// 13.	If the delta sensor detected distance between two object points is great than
			// SDG_KEEP_OBJECT_POINT_MIN_DELTA_DETECTED_DIS (def: 800mm) and the delta point distance is great than
			// SDG_KEEP_OBJECT_POINT_MIN_DELTA_POINT_DIS (def: 800mm), the object point should be stored.

			for(ObjIndex = WrIndex - 1; ObjIndex > 0; ObjIndex --) {
				PointPosDeltaDis = MATH_ABS(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].Pt.x -
				                            SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[WrIndex].Pt.x) +
				                   MATH_ABS(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].Pt.y -
				                            SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[WrIndex].Pt.y);
				PointPosDeltaDis2 = MATH_ABS(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].Pt.x -
				                            SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex - 1].Pt.x) +
				                   MATH_ABS(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].Pt.y -
				                            SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex - 1].Pt.y);
				if((SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].ObjDis == NO_OBJ_DISTANCE)
				&& (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex - 1].ObjDis == NO_OBJ_DISTANCE)
				&& (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex + 1].ObjDis == NO_OBJ_DISTANCE)){
					if(PointPosDeltaDis > 2 * SDGKeepNoObjPtDis) {		// 2 * 1500
						break;
					}
					if(PointPosDeltaDis2 > SDGKeepNoObjPtDis) {			// 1500
						break;
					}
				} else {
					if(PointPosDeltaDis > 2 * SDGKeepObjPtDis) {		// 2 * 400
						break;
					}
					if(PointPosDeltaDis2 > SDGKeepObjPtDis) {			// 400
						break;
					}
				}
				if((SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex + 1].ObjDis
				    <= SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].ObjDis)
				   && (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex - 1].ObjDis
				       <= SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].ObjDis)) {
					// Remove the ObjIndex.
					for(ObjIndex3 = ObjIndex; ObjIndex3 < (ObjPtCnt - 1); ObjIndex3 ++) {
						APATrajCalCopyMemory((UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex3])),
						                     (UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex3 + 1])), sizeof(SDGObjPointType));
					}
					WrIndex --;
					ObjPtCnt --;
					// SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt = ObjPtCnt;
				}
				if((ObjIndex > 0)
				&& (ObjIndex < (WrIndex))) {		// this criterion makes no sense
					if((SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex - 1].ObjDis != NO_OBJ_DISTANCE)
					&& (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex + 1].ObjDis != NO_OBJ_DISTANCE)
					&& ((SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex - 1].ObjDis
					< SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].ObjDis)
					|| (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex + 1].ObjDis
					< SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].ObjDis))) {
						PointPosDeltaDis = MATH_ABS(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex - 1].Pt.x -
						                            SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex + 1].Pt.x) +
						                   MATH_ABS(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex - 1].Pt.y -
						                            SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex + 1].Pt.y);
						if(PointPosDeltaDis < SDGKeepObjPtDis) {			// 400
							SnsDtdDis = MATH_ABS(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex - 1].ObjDis -
							                     SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex + 1].ObjDis);
							if(SnsDtdDis < SDGKeepObjPtMinDeltaDtdDis) {	// 500
								// OK, ObjIndex can be removed.
								// Remove the ObjIndex.
								for(ObjIndex3 = ObjIndex; ObjIndex3 < (ObjPtCnt - 1); ObjIndex3 ++) {
									APATrajCalCopyMemory((UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex3])),
									(UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex3 + 1])), sizeof(SDGObjPointType));
								}
								WrIndex --;
								ObjPtCnt --;
								// SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt = ObjPtCnt;
							}
						}
					}
				}
			}

#ifdef SDG_DEBUG_1
			for(ObjIndex4 = 1; ObjIndex4 < ObjPtCnt; ObjIndex4 ++){

				if((SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex4].CarPos.Coordinate.x
					> SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex4 - 1].CarPos.Coordinate.x)
				&& (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex4].CarPos.CarAng > (15.0 * PI / 180.0))){

					if(cSDGDbg2 == 0){
						cSDGDbg3 = 1;
					}
				}
			}

#endif
#endif

      // 6.	If no object is detected and previous cell of the buffer indicated no object is detected,
      // then the current no object position will be removed.
      if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[WrIndex].ObjDis == NO_OBJ_DISTANCE) {
        for (ObjIndex = WrIndex - 1; ObjIndex > 0; ObjIndex--) {
          if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].ObjDis != NO_OBJ_DISTANCE) {
            break;
          }
          PointPosDeltaDis =
              MATH_ABS(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].Pt.x - SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[WrIndex].Pt.x) +
              MATH_ABS(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].Pt.y - SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[WrIndex].Pt.y);
          if (PointPosDeltaDis > SDGKeepNoObjPtDis) { // 1500
            break;
          }
        }
        if (ObjIndex < (WrIndex - 2)) {
          // Remove the object between WrIndex and ObjIndex.
          ObjIndex2 = ObjPtCnt;
          ObjIndex4 = (WrIndex - ObjIndex - 2);
          ObjPtCnt  = ObjPtCnt - ObjIndex4;
          ObjIndex3 = WrIndex;
          WrIndex   = WrIndex - ObjIndex4;
          // SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt = ObjPtCnt;
          ObjIndex += 2;
          for (; ObjIndex3 < ObjIndex2; ObjIndex3++) {
            APATrajCalCopyMemory((UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex])),
                                 (UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex3])),
                                 sizeof(SDGObjPointType));
            ObjIndex++;
          }
        }
      }
      // 14.	Check the distance between the first object point and current point,
      // if the distance is great than SDGCal.SDGTRACKING_AREA_DD + SDG_KEEP_OBJECT_POINT_DIS,
      // the first point will be removed. If the next point is no object point it should also be removed.

      if (WrIndex >= 2) { // dsh 20120227
        Pt1.x = SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[0].Pt.x;
        Pt1.y = SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[0].Pt.y;
        Pt2.x = SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[WrIndex].Pt.x;
        Pt2.y = SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[WrIndex].Pt.y;

        DeltaDis = APATrajCalGetTwoPointDisFloat(Pt1, Pt2);
        if (DeltaDis > SDGCal.SDGTrackingAreaDrivingDirection) { // 12000
          // Remove the head point.
          WrIndex--;
          ObjPtCnt--;
          for (ObjIndex3 = 0; ObjIndex3 < (ObjPtCnt); ObjIndex3++) {
            APATrajCalCopyMemory((UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex3])),
                                 (UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex3 + 1])),
                                 sizeof(SDGObjPointType));
          }
        }
      }
    } else {
      WrIndex = 0;
      APATrajCalCopyMemory((UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[0])), (UCHAR *)(pObjPt), sizeof(SDGObjPointType));

      ObjPtCnt = 1;
      // Remove obj point from the buffer.
    }

  } else {
    // drives backwards

    if (ObjPtCnt > 0) {
      // Check if the WrIndex points is the last point.
      for (ObjIndex = WrIndex; ObjIndex < ObjPtCnt; ObjIndex++) {
        if (CarDriveDir == 0) {
          // Use X to compare. And X new should great than X old.
          if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.Coordinate.x >= pObjPt->CarPos.Coordinate.x) {
            // Over write the cur pt
            break;
          }
        } else if (CarDriveDir == 1) {
          // Use Y to compare. And Y new should great than Y old.
          if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.Coordinate.y >= pObjPt->CarPos.Coordinate.y) {
            // OK, Insert current car pos into
            break;
          }
        } else if (CarDriveDir == 2) {
          // Use X to compare. And X new should less than X old.
          if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.Coordinate.x <= pObjPt->CarPos.Coordinate.x) {
            // OK, Insert current car pos into
            break;
          }
        } else {
          // Use Y to compare. And Y new should less than Y old.
          if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.Coordinate.y <= pObjPt->CarPos.Coordinate.y) {
            // OK, Insert current car pos into
            break;
          }
        }
      }
      WrIndex = ObjIndex;
      if (WrIndex >= ObjPtCnt) {
        WrIndex = ObjPtCnt - 1;
      }

      if (WrIndex <= 0) {
        // OK, the first point, just insert the current object before the WrIndex.
        // check if the buffer is full or not?

        WrIndex         = 0;
        ObjIndex        = 0;
        bOverWriteCurPt = FALSE;
        if (CarDriveDir == 0) {
          // Use X to compare. And X new should great than X old.
          if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.Coordinate.x <= pObjPt->CarPos.Coordinate.x) {
            // OK, Insert current car pos into
            bOverWriteCurPt = TRUE;
          }
        } else if (CarDriveDir == 1) {
          // Use Y to compare. And Y new should great than Y old.
          if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.Coordinate.y <= pObjPt->CarPos.Coordinate.y) {
            // OK, Insert current car pos into
            bOverWriteCurPt = TRUE;
          }
        } else if (CarDriveDir == 2) {
          // Use X to compare. And X new should less than X old.
          if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.Coordinate.x >= pObjPt->CarPos.Coordinate.x) {
            // OK, Insert current car pos into
            bOverWriteCurPt = TRUE;
          }
        } else {
          // Use Y to compare. And Y new should less than Y old.
          if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.Coordinate.y >= pObjPt->CarPos.Coordinate.y) {
            // OK, Insert current car pos into
            bOverWriteCurPt = TRUE;
          }
        }

        if (bOverWriteCurPt == FALSE) {
          // Just remove the first object point.
          if (ObjPtCnt < SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE) {
            // Buffer is not full, just save the current point.
            ObjIndex2 = ObjPtCnt;
            ObjPtCnt++;
          } else {
            ObjPtCnt  = SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE;
            ObjIndex2 = SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE - 1;
          }

          while (ObjIndex2 > 0) {
            APATrajCalCopyMemory((UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2])),
                                 (UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2 - 1])),
                                 sizeof(SDGObjPointType));
            ObjIndex2--;
          }

        } else {
          // Keep the same WrIndex, ObjPtCnt.
        }

      } else {
        // WrIndex is not the first point.

        // kjy 2012 10 03 added
        bOverWriteCurPt = FALSE;
        bObjPtFound     = FALSE;
        for (ObjIndex = WrIndex; ObjIndex >= 0; ObjIndex--) {
          if (MATH_FABS(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.CarAng - pObjPt->CarPos.CarAng) >
              SDGCal.SDGDrvBkPtKeepMaxDeltaCarAng) {
            // Just remove all the pts.
            break;
          }
          if (CarDriveDir == 0) {
            // Use X to compare. And X new should great than X old.
            if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.Coordinate.x == pObjPt->CarPos.Coordinate.x) {
              // The car is static, just overwrite the cur pt. keep the same WrIndex, ObjPtCnt.
              bOverWriteCurPt = TRUE;
              break;
            } else if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.Coordinate.x < pObjPt->CarPos.Coordinate.x) {
              // OK, Insert current car pos into
              bObjPtFound = TRUE;
              break;
            }
          } else if (CarDriveDir == 1) {
            // Use Y to compare. And Y new should great than Y old.
            if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.Coordinate.y == pObjPt->CarPos.Coordinate.y) {
              // The car is static, just overwrite the cur pt. keep the same WrIndex, ObjPtCnt.
              bOverWriteCurPt = TRUE;
              break;
            } else if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.Coordinate.y < pObjPt->CarPos.Coordinate.y) {
              // OK, Insert current car pos into
              bObjPtFound = TRUE;
              break;
            }
          } else if (CarDriveDir == 2) {
            // Use X to compare. And X new should less than X old.
            if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.Coordinate.x == pObjPt->CarPos.Coordinate.x) {
              // The car is static, just overwrite the cur pt. keep the same WrIndex, ObjPtCnt.
              bOverWriteCurPt = TRUE;
              break;
            } else if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.Coordinate.x > pObjPt->CarPos.Coordinate.x) {
              // OK, Insert current car pos into
              bObjPtFound = TRUE;
              break;
            }
          } else {
            // Use Y to compare. And Y new should less than Y old.
            if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.Coordinate.y == pObjPt->CarPos.Coordinate.y) {
              // The car is static, just overwrite the cur pt. keep the same WrIndex, ObjPtCnt.
              bOverWriteCurPt = TRUE;
              break;
            } else if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.Coordinate.y > pObjPt->CarPos.Coordinate.y) {
              // OK, Insert current car pos into
              bObjPtFound = TRUE;
              break;
            }
          }
        }
        if (ObjIndex < 0) {
          ObjIndex = 0;
        }

        if (bOverWriteCurPt == TRUE) {
          // The car is static, just overwrite the cur pt. keep the same WrIndex, ObjPtCnt.
          WrIndex = ObjIndex;
        } else if (bObjPtFound == FALSE) {
          ObjIndex3 = WrIndex;
          ObjIndex2 = 1;
          for (; ObjIndex3 < ObjPtCnt; ObjIndex3++) {
            APATrajCalCopyMemory((UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2])),
                                 (UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex3])),
                                 sizeof(SDGObjPointType));
            ObjIndex2++;
          }
          ObjPtCnt = ObjPtCnt - WrIndex;
          WrIndex  = 0;
        } else if (ObjIndex == (WrIndex)) {
          if (ObjPtCnt < SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE) {
            // Buffer is not full, just save the current point.
            ObjIndex2 = ObjPtCnt;
            ObjPtCnt++;
            // SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt = ObjPtCnt;
          } else {
            // Just remove the last object point.
            ObjIndex2 = SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE - 1;
            ObjPtCnt  = SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE;
            // SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt = SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE;
          }
          ObjIndex3 = WrIndex + 1;
          while (ObjIndex2 > ObjIndex3) {
            APATrajCalCopyMemory((UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2])),
                                 (UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2 - 1])),
                                 sizeof(SDGObjPointType));
            ObjIndex2--;
          }
          WrIndex++;
          // Save the current obj point to the next cell of WrIndex.
        } else {
          // There is space to save the current point.
          ObjIndex2 = ObjIndex + 2;
          if (ObjIndex2 < WrIndex) {
            ObjIndex3 = WrIndex;
            for (; ObjIndex3 < ObjPtCnt; ObjIndex3++) {
              APATrajCalCopyMemory((UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2])),
                                   (UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex3])),
                                   sizeof(SDGObjPointType));
              ObjIndex2++;
            }
            ObjPtCnt = ObjPtCnt - (WrIndex - ObjIndex - 2);
            WrIndex  = ObjIndex + 1;
          } else if (ObjIndex2 == WrIndex) {
            // Just save the cur pt to Previous point of cur WrIndex.
            WrIndex = ObjIndex + 1;
          } else {
            if (ObjPtCnt >= SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE) {
              // Just over write the Previous point of cur WrIndex.
              WrIndex = ObjIndex;
            } else {
              // remove a space to save the cur obj pt.
              ObjIndex2 = ObjPtCnt;
              ObjPtCnt++;
              while (ObjIndex2 > WrIndex) {
                APATrajCalCopyMemory((UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2])),
                                     (UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2 - 1])),
                                     sizeof(SDGObjPointType));
                ObjIndex2--;
              }
            }
          }
        }
      }

      // Save the current obj point to the next cell of WrIndex.

      if (WrIndex >= SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE) {
        WrIndex  = SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE - 1;
        ObjPtCnt = SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE;
      } else if (WrIndex < 0) {
        WrIndex  = 0;
        ObjPtCnt = 1;
      }
      if (ObjPtCnt > SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE) {
        ObjPtCnt = SDG_MAX_SUPPORT_OBJ_POINT_BUF_SIZE;
      } else if (ObjPtCnt <= 0) {
        ObjPtCnt = 1;
        WrIndex  = 0;
      }

      if (WrIndex >= ObjPtCnt) {
        ObjPtCnt = WrIndex + 1;
      }

      APATrajCalCopyMemory((UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[WrIndex])), (UCHAR *)(pObjPt), sizeof(SDGObjPointType));

#ifdef SDG_DEBUG_1
      for (ObjIndex4 = 1; ObjIndex4 < ObjPtCnt; ObjIndex4++) {

        if ((SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex4].CarPos.Coordinate.x >
             SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex4 - 1].CarPos.Coordinate.x) &&
            (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex4].CarPos.CarAng > (15.0 * PI / 180.0))) {

          if (cSDGDbg3 == 0) {
            cSDGDbg4 = 1;
          }
        }
      }

#endif

      // Remove obj point from the buffer.

      // 16. If the delta car angle between the head point and the current point is great than 180 deg, the head point will be removed.
      if ((WrIndex > 0) && MATH_FABS(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[WrIndex].CarPos.CarAng -
                                     SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[0].CarPos.CarAng) > PI) {
        // Remove the head point.
        ObjPtCnt--;
        WrIndex--;
        for (ObjIndex3 = 0; ObjIndex3 < (ObjPtCnt); ObjIndex3++) {
          APATrajCalCopyMemory((UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex3])),
                               (UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex3 + 1])),
                               sizeof(SDGObjPointType));
        }
      }

      // 17. If the delta car angle between the tail point and the current point is great than 180 deg, the tail point will be removed.
      ObjIndex = ObjPtCnt - 1;
      if ((ObjIndex > WrIndex) && MATH_FABS(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[WrIndex].CarPos.CarAng -
                                            SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.CarAng) > PI) {
        // Remove the head point.
        ObjPtCnt--;
      }

// for perpendicular parking slot correction filter 2014 08 21
#if 0

			// 11.	If the object distance within the two object points is great than both these two points,
			// this object points will be removed.
			// 13.	If the delta sensor detected distance between two object points is great than
			// SDG_KEEP_OBJECT_POINT_MIN_DELTA_DETECTED_DIS (def: 800mm) and the delta point distance is great than
			// SDG_KEEP_OBJECT_POINT_MIN_DELTA_POINT_DIS (def: 800mm), the object point should be stored.
			ObjIndex2 = ObjPtCnt - 1;
			for(ObjIndex = WrIndex + 1; ObjIndex < ObjIndex2; ObjIndex ++) {
				PointPosDeltaDis = MATH_ABS(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].Pt.x -
				                            SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[WrIndex].Pt.x) +
				                   MATH_ABS(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].Pt.y -
				                            SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[WrIndex].Pt.y);
				PointPosDeltaDis2 = MATH_ABS(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].Pt.x -
				                            SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex + 1].Pt.x) +
				                   MATH_ABS(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].Pt.y -
				                            SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex + 1].Pt.y);
				if((SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].ObjDis == NO_OBJ_DISTANCE)
				&& (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex - 1].ObjDis == NO_OBJ_DISTANCE)
				&& (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex + 1].ObjDis == NO_OBJ_DISTANCE)){
					if(PointPosDeltaDis > 2 * SDGKeepNoObjPtDis) {
						break;
					}
					if(PointPosDeltaDis2 > SDGKeepNoObjPtDis) {
						break;
					}
				} else {
					if(PointPosDeltaDis > 2 * SDGKeepObjPtDis) {
						break;
					}
					if(PointPosDeltaDis2 > SDGKeepObjPtDis) {
						break;
					}
				}

				if((SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex - 1].ObjDis
				<= SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].ObjDis)
				&& (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex + 1].ObjDis
				<= SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].ObjDis)) {
					// Remove the ObjIndex.
					for(ObjIndex3 = ObjIndex; ObjIndex3 < ObjIndex2; ObjIndex3 ++) {
						APATrajCalCopyMemory((UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex3])),
						                     (UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex3 + 1])), sizeof(SDGObjPointType));
					}
					ObjPtCnt --;
					// SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt = ObjPtCnt;
					ObjIndex2 = ObjPtCnt - 1;
				}
				if((ObjIndex < ObjIndex2)
				   && (ObjIndex > (WrIndex))) {
					if((SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex - 1].ObjDis != NO_OBJ_DISTANCE)
					   && (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex + 1].ObjDis != NO_OBJ_DISTANCE)
					   && ((SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex - 1].ObjDis
					   			< SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].ObjDis)
					       || (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex + 1].ObjDis
					           	< SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].ObjDis))) {
						PointPosDeltaDis = MATH_ABS(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex - 1].Pt.x -
						                            SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex + 1].Pt.x) +
						                   MATH_ABS(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex - 1].Pt.y -
						                            SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex + 1].Pt.y);
						if(PointPosDeltaDis < SDGKeepObjPtDis) {
							SnsDtdDis = MATH_ABS(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex - 1].ObjDis -
							                     SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex + 1].ObjDis);
							if(SnsDtdDis < SDGKeepObjPtMinDeltaDtdDis) {
								// OK, ObjIndex can be removed.
								// Remove the ObjIndex.
								for(ObjIndex3 = ObjIndex; ObjIndex3 < ObjIndex2; ObjIndex3 ++) {
									APATrajCalCopyMemory((UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex3])),
									                     (UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex3 + 1])), sizeof(SDGObjPointType));
								}
								ObjPtCnt --;
								// SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt = ObjPtCnt;
								ObjIndex2 = ObjPtCnt - 1;
							}
						}
					}
				}
			}

#ifdef SDG_DEBUG_1
			for(ObjIndex4 = 1; ObjIndex4 < ObjPtCnt; ObjIndex4 ++){

				if((SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex4].CarPos.Coordinate.x
					> SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex4 - 1].CarPos.Coordinate.x)
				&& (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex4].CarPos.CarAng > (15.0 * PI / 180.0))){

					if(cSDGDbg2 == 0){
						cSDGDbg4 = 1;
					}
				}
			}

#endif

#endif

      // 6.	If no object is detected and previous cell of the buffer indicated no object is detected,
      // then the current no object position will be removed.

      // Note: Remove the continuous NoObjDis points

      if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[WrIndex].ObjDis == NO_OBJ_DISTANCE) {
        ObjIndex2 = ObjPtCnt - 1;
        for (ObjIndex = WrIndex + 1; ObjIndex < ObjIndex2; ObjIndex++) {
          if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].ObjDis != NO_OBJ_DISTANCE) {
            break;
          }
          PointPosDeltaDis =
              MATH_ABS(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].Pt.x - SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[WrIndex].Pt.x) +
              MATH_ABS(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].Pt.y - SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[WrIndex].Pt.y);
          if (PointPosDeltaDis > SDGKeepNoObjPtDis) { // 1500
            break;
          }
        }
        if (ObjIndex > (WrIndex + 2)) {
          // Remove the object between WrIndex and ObjIndex.
          ObjPtCnt = ObjPtCnt - (ObjIndex - WrIndex - 2);
          // SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt = ObjPtCnt;
          ObjIndex--;
          ObjIndex2++;
          for (ObjIndex3 = WrIndex + 1; ObjIndex < ObjIndex2; ObjIndex++) {
            APATrajCalCopyMemory((UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex3])),
                                 (UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex])),
                                 sizeof(SDGObjPointType));
            ObjIndex3++;
          }
        }
      }
      // 14.	Check the distance between the first object point and current point,
      // if the distance is great than SDGCal.SDGTRACKING_AREA_DD + SDG_KEEP_OBJECT_POINT_DIS,
      // the first point will be removed. If the next point is no object point it should also be removed.

      if (ObjPtCnt > (WrIndex + 1)) {
        Pt1.x = SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjPtCnt - 1].Pt.x;
        Pt1.y = SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[ObjPtCnt - 1].Pt.y;
        Pt2.x = SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[WrIndex].Pt.x;
        Pt2.y = SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[WrIndex].Pt.y;

        DeltaDis = APATrajCalGetTwoPointDisFloat(Pt1, Pt2);
        if (DeltaDis > SDGCal.SDGTrackingAreaDrivingDirection) { // 12000
          // Remove the head point.
          ObjPtCnt--;
        }
      }

    } else {
      WrIndex = 0;
      APATrajCalCopyMemory((UCHAR *)(&(SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[0])), (UCHAR *)(pObjPt), sizeof(SDGObjPointType));

      ObjPtCnt = 1;
      // Remove obj point from the buffer.
    }
  }

  SDGObjInfo.SnsObjPtBuf[SnsIndex].WrIndex  = WrIndex;
  SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt = ObjPtCnt;

  // Optimized the filter algothrim
  if (SDGBooleanFlags.Bits.bSDGCarIsRunningBackwards == TRUE) {
    // car is driving backwards
    SDGRemoveUselessObjPtFromSDGBuf(SnsIndex, TRUE);
  } else {
    // car is driving forward
    SDGRemoveUselessObjPtFromSDGBuf(SnsIndex, FALSE);
  }
}
#endif

/*************************************************************************************************************************************************
** Syntax :  void USS(void)                                                                                                                     **
**                                                                                                                                              **
** Service ID:   : NA                                                                                                                           **
**                                                                                                                                              **
** Sync/Async:   : Synchronous                                                                                                                  **
**                                                                                                                                              **
** Reentrancy:   : Non Reentrant                                                                                                                **
**                                                                                                                                              **
** Parameters (in): none                                                                                                                        **
**                                                                                                                                              **
** Parameters (out): none                                                                                                                       **
**                                                                                                                                              **
** Return value: none                                                                                                                           **
**                                                                                                                                              **
** Description : ..                                                                                                                             **
*************************************************************************************************************************************************/
APA_ANGLE_CAL_FLOAT_TYPE APASlotPCorSideSnsDisCompensatCalculation(APA_ENUM_TYPE DeltaAngIndex,
                                                                   APA_ENUM_TYPE ObjDisIndex,
                                                                   APA_ENUM_TYPE SideSnsIndex,
                                                                   APA_ANGLE_CAL_FLOAT_TYPE DeltaAng,
                                                                   APA_DISTANCE_TYPE ObjDis,
                                                                   APA_ENUM_TYPE CorOrSideSnsIndex,
                                                                   BOOLEAN bCompDisMethodFlag) {
  APA_ANGLE_CAL_FLOAT_TYPE X1, X2, Y1, Y2;
  APA_ANGLE_CAL_FLOAT_TYPE Y_D1, Y_D2, SideSnsDisCompensationAng;

  if (bCompDisMethodFlag == FALSE) {
    if (((DeltaAngIndex == 0) || (DeltaAngIndex == APACal.APASlotPCorSideSnsDeltaAngBetweenCurAngAndEndAng.APASlotPCorSideSnsDeltaAngZoneNum)) &&
        ((ObjDisIndex == 0) || (ObjDisIndex == (APA_SLOT_P_COR_RRS_RLS_SNS_DIS_DIV_NUM - 1)))) {
      SideSnsDisCompensationAng = APACal.APASlotPCorSideSnsCompensatAngByDeltaAngAndSnsDtObjDis[SideSnsIndex][DeltaAngIndex][ObjDisIndex];
    } else {
      if ((DeltaAngIndex == 0) || (DeltaAngIndex == APACal.APASlotPCorSideSnsDeltaAngBetweenCurAngAndEndAng.APASlotPCorSideSnsDeltaAngZoneNum)) {
        Y_D1                      = APACal.APASlotPCorSideSnsCompensatAngByDeltaAngAndSnsDtObjDis[SideSnsIndex][DeltaAngIndex][ObjDisIndex - 1];
        Y_D2                      = APACal.APASlotPCorSideSnsCompensatAngByDeltaAngAndSnsDtObjDis[SideSnsIndex][DeltaAngIndex][ObjDisIndex];
        X1                        = APACal.APASlotPCorCorOrSideSnsDisArray[CorOrSideSnsIndex][ObjDisIndex - 1];
        X2                        = APACal.APASlotPCorCorOrSideSnsDisArray[CorOrSideSnsIndex][ObjDisIndex];
        SideSnsDisCompensationAng = APATrajCalTwoPointInterpolationCalculation(Y_D1, Y_D2, X1, X2, ObjDis);
      } else {
        if ((ObjDisIndex == 0) || (ObjDisIndex == (APA_SLOT_P_COR_RRS_RLS_SNS_DIS_DIV_NUM - 1))) {
          Y_D1 = APACal.APASlotPCorSideSnsCompensatAngByDeltaAngAndSnsDtObjDis[SideSnsIndex][DeltaAngIndex - 1][ObjDisIndex];
          Y_D2 = APACal.APASlotPCorSideSnsCompensatAngByDeltaAngAndSnsDtObjDis[SideSnsIndex][DeltaAngIndex][ObjDisIndex];
        } else {
          Y1   = APACal.APASlotPCorSideSnsCompensatAngByDeltaAngAndSnsDtObjDis[SideSnsIndex][DeltaAngIndex][ObjDisIndex - 1];
          Y2   = APACal.APASlotPCorSideSnsCompensatAngByDeltaAngAndSnsDtObjDis[SideSnsIndex][DeltaAngIndex][ObjDisIndex];
          X1   = APACal.APASlotPCorCorOrSideSnsDisArray[CorOrSideSnsIndex][ObjDisIndex - 1];
          X2   = APACal.APASlotPCorCorOrSideSnsDisArray[CorOrSideSnsIndex][ObjDisIndex];
          Y_D1 = APATrajCalTwoPointInterpolationCalculation(Y1, Y2, X1, X2, ObjDis);
          Y1   = APACal.APASlotPCorSideSnsCompensatAngByDeltaAngAndSnsDtObjDis[SideSnsIndex][DeltaAngIndex - 1][ObjDisIndex - 1];
          Y2   = APACal.APASlotPCorSideSnsCompensatAngByDeltaAngAndSnsDtObjDis[SideSnsIndex][DeltaAngIndex - 1][ObjDisIndex];
          Y_D2 = APATrajCalTwoPointInterpolationCalculation(Y1, Y2, X1, X2, ObjDis);
        }
        X1                        = APACal.APASlotPCorSideSnsDeltaAngBetweenCurAngAndEndAng.APASlotPCorSideSnsDeltaAngArray[DeltaAngIndex - 1];
        X2                        = APACal.APASlotPCorSideSnsDeltaAngBetweenCurAngAndEndAng.APASlotPCorSideSnsDeltaAngArray[DeltaAngIndex];
        SideSnsDisCompensationAng = APATrajCalTwoPointInterpolationCalculation(Y_D1, Y_D2, X1, X2, DeltaAng);
      }
    }
  } else {
    if ((DeltaAngIndex == 0) || (DeltaAngIndex == APACal.APASlotPCorSideSnsDeltaAngBetweenCurAngAndEndAng.APASlotPCorSideSnsDeltaAngZoneNum)) {
      SideSnsDisCompensationAng = APACal.APASlotPCorSideSnsCompensatAngByDeltaAng[SideSnsIndex][DeltaAngIndex];
    } else {
      Y1                        = APACal.APASlotPCorSideSnsCompensatAngByDeltaAng[SideSnsIndex][DeltaAngIndex - 1];
      Y2                        = APACal.APASlotPCorSideSnsCompensatAngByDeltaAng[SideSnsIndex][DeltaAngIndex];
      X1                        = APACal.APASlotPCorSideSnsDeltaAngBetweenCurAngAndEndAng.APASlotPCorSideSnsDeltaAngArray[DeltaAngIndex - 1];
      X2                        = APACal.APASlotPCorSideSnsDeltaAngBetweenCurAngAndEndAng.APASlotPCorSideSnsDeltaAngArray[DeltaAngIndex];
      SideSnsDisCompensationAng = APATrajCalTwoPointInterpolationCalculation(Y1, Y2, X1, X2, DeltaAng);
    }
  }

  return SideSnsDisCompensationAng;
}
/*************************************************************************************************************************************************
** Syntax :  void USS(void)                                                                                                                     **
**                                                                                                                                              **
** Service ID:   : NA                                                                                                                           **
**                                                                                                                                              **
** Sync/Async:   : Synchronous                                                                                                                  **
**                                                                                                                                              **
** Reentrancy:   : Non Reentrant                                                                                                                **
**                                                                                                                                              **
** Parameters (in): none                                                                                                                        **
**                                                                                                                                              **
** Parameters (out): none                                                                                                                       **
**                                                                                                                                              **
** Return value: none                                                                                                                           **
**                                                                                                                                              **
** Description : ..                                                                                                                             **
*************************************************************************************************************************************************/
SDG_DISTANCE_TYPE SDGGetSensorHFOVWidthBySnsDis(SDG_DISTANCE_TYPE SnsDtdObjDis) {
  // Input Par:
  // SnsDtdObjDis: SDG sensor detected object dis, unit: mm.
  //
  // Output par:
  // Dis: SDG sensor HFOV width according to the object dis.
  SDG_DISTANCE_TYPE Dis;
  SDG_ENUM_TYPE Index;

  Dis   = SnsDtdObjDis / (SDG_SENSOR_HFOV_DIVIDED_SEG_DIS);
  Index = (SDG_ENUM_TYPE)Dis;
  if (Index < 0) {
    Index = 0;
  } else if (Index >= SDG_SENSOR_HFOV_DIVIDED_SEG_NUM) {
    Index = SDG_SENSOR_HFOV_DIVIDED_SEG_NUM - 1;
  }
  Dis = SDGCal.SDGHFOVWidthBySeg[Index];

  return Dis;
}
/*************************************************************************************************************************************************
** Syntax :  void USS(void)                                                                                                                     **
**                                                                                                                                              **
** Service ID:   : NA                                                                                                                           **
**                                                                                                                                              **
** Sync/Async:   : Synchronous                                                                                                                  **
**                                                                                                                                              **
** Reentrancy:   : Non Reentrant                                                                                                                **
**                                                                                                                                              **
** Parameters (in): none                                                                                                                        **
**                                                                                                                                              **
** Parameters (out): none                                                                                                                       **
**                                                                                                                                              **
** Return value: none                                                                                                                           **
**                                                                                                                                              **
** Description : ..                                                                                                                             **
*************************************************************************************************************************************************/
BOOLEAN SDGCheckIfObjPtIsWithinHFOV(SDGCarCoordinateDataCalFloatType *pCurCarPos, SDGSnsDtdObjPointType *pObjPt) {
  // Input Par:
  // pCurCarPos: current car position.
  // pObjPt: object point to be checked.
  //
  // Output Par:
  // bCheckResult: = TRUE: Object point is within the SDG Sensor detected HFOV.
  //				 = FALSE: Object point is not within the SDG Sensor detected HFOV.

  SDG_DISTANCE_TYPE Dis;
  SDGCoordinateDataCalFloatType Pt;
  SDG_DISTANCE_CAL_FLOAT_TYPE DeltaCarDis;

  Dis         = SDGGetSensorHFOVWidthBySnsDis(pObjPt->ObjDis);
  Pt.x        = (SDG_DISTANCE_CAL_FLOAT_TYPE)(pObjPt->CarPos.Coordinate.x);
  Pt.y        = (SDG_DISTANCE_CAL_FLOAT_TYPE)(pObjPt->CarPos.Coordinate.y);
  DeltaCarDis = APATrajCalGetTwoPointDisFloat(pCurCarPos->Coordinate, Pt);
  if (DeltaCarDis <= Dis) {
    return TRUE;
  }
  return FALSE;
}

/*************************************************************************************************************************************************
** Syntax :  void USS(void)                                                                                                                     **
**                                                                                                                                              **
** Service ID:   : NA                                                                                                                           **
**                                                                                                                                              **
** Sync/Async:   : Synchronous                                                                                                                  **
**                                                                                                                                              **
** Reentrancy:   : Non Reentrant                                                                                                                **
**                                                                                                                                              **
** Parameters (in): none                                                                                                                        **
**                                                                                                                                              **
** Parameters (out): none                                                                                                                       **
**                                                                                                                                              **
** Return value: none                                                                                                                           **
**                                                                                                                                              **
** Description : ..                                                                                                                             **
*************************************************************************************************************************************************/
SDG_TIMES_TYPE SDGGetNumberOfDetectionTimes(SDG_DISTANCE_TYPE SnsDtdObjDis, SDG_SPEED_CAL_FLOAT_TYPE VehSpd) {
  // Input par:
  // SnsDtdObjDis: SDG sensor detected object dis, unit: mm.
  // VehSpd: vehicle speed. unit: m/s
  //
  // Output par:
  // DtdTimes: SDG sensor detection times within the SDG sensor HFOV.
  //

  SDG_DISTANCE_TYPE Dis;
  SDG_TIMES_TYPE DtdTimes;
  SDG_CAL_FLOAT_TYPE fTemp;

  Dis = SDGGetSensorHFOVWidthBySnsDis(SnsDtdObjDis);
  if (VehSpd < SDG_NUMBER_OF_DT_TIMES_CAL_MIN_SPD) {
    fTemp = SDG_MAX_NUMBER_OF_DT_TIMES;
  } else {
    fTemp = VehSpd * (SDG_SENSOR_DT_ONE_LOOP_TIME_MS);
  }
  fTemp    = ((SDG_CAL_FLOAT_TYPE)(Dis) / fTemp);
  DtdTimes = (SDG_TIMES_TYPE)fTemp;
  return DtdTimes;
}
/*************************************************************************************************************************************************
** Syntax :  void USS(void)                                                                                                                     **
**                                                                                                                                              **
** Service ID:   : NA                                                                                                                           **
**                                                                                                                                              **
** Sync/Async:   : Synchronous                                                                                                                  **
**                                                                                                                                              **
** Reentrancy:   : Non Reentrant                                                                                                                **
**                                                                                                                                              **
** Parameters (in): none                                                                                                                        **
**                                                                                                                                              **
** Parameters (out): none                                                                                                                       **
**                                                                                                                                              **
** Return value: none                                                                                                                           **
**                                                                                                                                              **
** Description : ..                                                                                                                             **
*************************************************************************************************************************************************/
SDG_WEIGHT_COEFFICIENT_TYPE
SDGGetDeltaWeightCoefficient(SDG_DISTANCE_TYPE SnsDtdObjDis, SDG_SPEED_CAL_FLOAT_TYPE VehSpd, BOOLEAN bDeltaWeightCoeIncreasing) {
  // Input par:
  // SnsDtdObjDis: SDG sensor detected object dis, unit: mm.
  // VehSpd: vehicle speed. unit: m/s
  // bDeltaWeightCoeIncreasing: = TRUE: The delta weight coefficient for the object being detected
  //							  = FALSE: The delta weight coefficient for no object being detected
  // Output par:
  // DeltaWeightCoe: SDG sensor detection delta weight coefficient.
  //

  SDG_TIMES_TYPE DtdTimes;
  SDG_WEIGHT_COEFFICIENT_TYPE DeltaWeightCoe;

  DtdTimes = SDGGetNumberOfDetectionTimes(SnsDtdObjDis, VehSpd);
  if (bDeltaWeightCoeIncreasing == TRUE) {
    DeltaWeightCoe = ((SDG_OBJECT_MAX_WEIGHT_COEFFICIENT * 100) / SDGSnsDtObjProbalilityPercentage) / DtdTimes;
  } else {
    DeltaWeightCoe = (SDG_OBJECT_ACK_WEIGHT_COEFFICIENT) / DtdTimes;
  }
  if (DeltaWeightCoe <= 0) {
    DeltaWeightCoe = 1;
  } else if (DeltaWeightCoe > SDG_OBJECT_MAX_WEIGHT_COEFFICIENT) {
    DeltaWeightCoe = SDG_OBJECT_MAX_WEIGHT_COEFFICIENT;
  }
  return DeltaWeightCoe;
}
/*************************************************************************************************************************************************
** Syntax :  void USS(void)                                                                                                                     **
**                                                                                                                                              **
** Service ID:   : NA                                                                                                                           **
**                                                                                                                                              **
** Sync/Async:   : Synchronous                                                                                                                  **
**                                                                                                                                              **
** Reentrancy:   : Non Reentrant                                                                                                                **
**                                                                                                                                              **
** Parameters (in): none                                                                                                                        **
**                                                                                                                                              **
** Parameters (out): none                                                                                                                       **
**                                                                                                                                              **
** Return value: none                                                                                                                           **
**                                                                                                                                              **
** Description : ..                                                                                                                             **
*************************************************************************************************************************************************/
#if Debug_SW_PARKINFUNC
BOOLEAN SDGSaveSnsDtdObjDisToBuf(SDG_DISTANCE_TYPE SnsDtdObjDis,
                                 SDG_ENUM_TYPE SnsIndex,
                                 SDGCarCoordinateDataCalFloatType *pCurCarPos,
                                 SDG_SPEED_CAL_FLOAT_TYPE VehSpd,
                                 SDGObjPointType *pObjPt,
                                 SDG_ENUM_TYPE cProcessMode) {
  // Input Par:
  // SnsDtdObjDis: SDG Sensor detected object distance
  // pCurCarPos: current car position. car angle should be within (-PI, + PI)
  // VehSpd: current car speed.
  //
  // Output Par:
  // pObjPt: Object Point which need to be saved to the Object Buffer outside this function.
  // bSaveObjPtToObjBuf: = TRUE: pObjPt includes an object point need to be saved.
  // 					   = FALSE: No object point need to be saved.

  SDG_ENUM_TYPE ObjIndex, SysSnsIndex, ObjIndex2, ObjDtdCnt;
  SDG_DISTANCE_TYPE SnsDtdDisTemp, MinSnsDtdDis, MaxSnsDtdDis, SnsDtdDisBk;
  SDG_DISTANCE_CAL_FLOAT_TYPE DeltaDis1, DeltaDis2;
  SDGCoordinateDataCalFloatType SnsDtdObjPt;
  SDG_WEIGHT_COEFFICIENT_TYPE WeightCoe, dWCI, dWCD, WCTemp;
  SDGCarCoordinateDataCalFloatType CarPos1, CarPos2;
  BOOLEAN bFlag, bSaveObjPtToObjBuf;
  SDG_ENUM_TYPE CarDriveDir;
  // Added by lu zhi meng 2014 04 29
  APACarCoordinateDataCalFloatType CarCenterPt;
  APA_ANGLE_TYPE EndPosToCurCarPosDeltaAng;
  APA_DISTANCE_TYPE SlotObj1Or2X, SlotObj1Or2Y;
  APACoordinateDataCalFloatType Pt;
  APASlotCoordinateDataCalFloatType RRSOrRLSSnsPt;
  APA_ENUM_TYPE SideSnsXDisBiggerThanThresholdCnt;
  APA_ENUM_TYPE SDGBufDisIndex;
  APA_ANGLE_TYPE APASlotCorPCarMayHitObj1CorSideSnsMaxCompensateAng;
  APA_ENUM_TYPE SideSnsDisIndex, DeltaAngIndex;
  BOOLEAN bCompDisMethodFlag;

  ObjIndex = SDGSnsDtdObjPtBuf[SnsIndex].WrIndex;
  // bRemoveOnePoint = FALSE; // No object point should be removed from the SDGSnsDtdObjPtBuf[SnsIndex].ObjPt.
  bSaveObjPtToObjBuf = FALSE;
  if (ObjIndex < SDG_MAX_SUPPORT_SNS_DTD_OBJ_POINT_BUF_SIZE) {
    SDGSnsDtdObjPtBuf[SnsIndex].WrIndex++;
  } else {

    CarPos1.Coordinate.x = SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[SDG_MAX_SUPPORT_SNS_DTD_OBJ_POINT_BUF_SIZE - 1].CarPos.Coordinate.x;
    CarPos1.Coordinate.y = SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[SDG_MAX_SUPPORT_SNS_DTD_OBJ_POINT_BUF_SIZE - 1].CarPos.Coordinate.y;
    CarPos2.Coordinate.x = SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[0].CarPos.Coordinate.x;
    CarPos2.Coordinate.y = SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[0].CarPos.Coordinate.y;
    if (SDGBooleanFlags.Bits.bSDGCarIsRunningBackwards == FALSE) {
      // Remove the head object point.
      DeltaDis1 = APATrajCalGetTwoPointDisFloat(pCurCarPos->Coordinate, CarPos2.Coordinate);
      DeltaDis2 = APATrajCalGetTwoPointDisFloat(CarPos1.Coordinate, CarPos2.Coordinate);
      if (DeltaDis1 < DeltaDis2) {
        DeltaDis1 = DeltaDis2;
      }
    } else {
      // Remove the Tail object point.
      DeltaDis1 = APATrajCalGetTwoPointDisFloat(pCurCarPos->Coordinate, CarPos1.Coordinate);
      DeltaDis2 = APATrajCalGetTwoPointDisFloat(CarPos1.Coordinate, CarPos2.Coordinate);
      if (DeltaDis1 < DeltaDis2) {
        DeltaDis1 = DeltaDis2;
      }
    }
    if ((DeltaDis1 > SDGSnsDtObjRegionWidth) || (SDGSnsDtdObjPtBuf[SnsIndex].SnsDtLoopCnt > SDG_SENSOR_MAX_DETECT_LOOP_CNT_TO_CONFIRM_OBJECT)) {
      // remove the head / or tail object.
      SDGSnsDtdObjPtBuf[SnsIndex].SnsDtLoopCnt = 0;
      bSaveObjPtToObjBuf                       = TRUE;
    } else {
      // bRemoveOnePoint = TRUE; // should remove one point
    }
    ObjIndex                            = SDG_MAX_SUPPORT_SNS_DTD_OBJ_POINT_BUF_SIZE;
    SDGSnsDtdObjPtBuf[SnsIndex].WrIndex = SDG_MAX_SUPPORT_SNS_DTD_OBJ_POINT_BUF_SIZE;
  }

  // Sensor detected object weight coefficient process.
  SnsDtdDisTemp = SnsDtdObjDis;
  dWCD          = SDGGetDeltaWeightCoefficient(SnsDtdDisTemp, VehSpd, FALSE);
  dWCI          = SDGGetDeltaWeightCoefficient(SnsDtdDisTemp, VehSpd, TRUE);

  WeightCoe = 0;
  if (SnsDtdDisTemp != NO_OBJ_DISTANCE) {
    WeightCoe = dWCI;
    for (ObjIndex2 = 0; ObjIndex2 < ObjIndex; ObjIndex2++) {
      if (SDGCheckIfObjPtIsWithinHFOV(pCurCarPos, &SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2]) == TRUE) {
        // Obj Point is within the HFOV.
        WCTemp = SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2].WeightCoe;
        if ((MATH_ABS(SnsDtdDisTemp - SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2].ObjDis)) < SDGSnsDtObjRegardedAsSameObjTolDis) {
          // Obj distance is within the tollerance.
          if (WeightCoe < WCTemp) {
            WeightCoe = WCTemp;
          }
          WCTemp += dWCI;
        } else {
          WCTemp -= dWCD;
        }
        if (WCTemp > SDG_OBJECT_MAX_WEIGHT_COEFFICIENT) {
          WCTemp = SDG_OBJECT_MAX_WEIGHT_COEFFICIENT;
        } else if (WCTemp < 0) {
          WCTemp = 0;
        }
        SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2].WeightCoe = WCTemp;
      }
    }
  }

  bFlag = bSaveObjPtToObjBuf;

  // Move the point to the Object Point Buffer
  if (bSaveObjPtToObjBuf == TRUE) {
    if (SDGBooleanFlags.Bits.bSDGCarIsRunningBackwards == FALSE) {
      // remove the head object.
      if (SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[0].WeightCoe < SDG_OBJECT_ACK_WEIGHT_COEFFICIENT) {
        pObjPt->ObjDis = NO_OBJ_DISTANCE;
      } else {
        pObjPt->ObjDis = SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[0].ObjDis;
      }
      pObjPt->Pt.x                = SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[0].Pt.x;
      pObjPt->Pt.y                = SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[0].Pt.y;
      pObjPt->CarPos.Coordinate.x = SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[0].CarPos.Coordinate.x;
      pObjPt->CarPos.Coordinate.y = SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[0].CarPos.Coordinate.y;
      pObjPt->CarPos.CarAng       = SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[0].CarPos.CarAng;

      for (ObjIndex2 = 0; ObjIndex2 < SDG_MAX_SUPPORT_SNS_DTD_OBJ_POINT_BUF_SIZE - 1; ObjIndex2++) {
        APATrajCalCopyMemory((UCHAR *)(&(SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2])),
                             (UCHAR *)(&(SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2 + 1])),
                             sizeof(SDGSnsDtdObjPointType));
      }
    } else {
      // remove the tail object.
      if (SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[SDG_MAX_SUPPORT_SNS_DTD_OBJ_POINT_BUF_SIZE - 1].WeightCoe < SDG_OBJECT_ACK_WEIGHT_COEFFICIENT) {
        pObjPt->ObjDis = NO_OBJ_DISTANCE;
      } else {
        pObjPt->ObjDis = SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[SDG_MAX_SUPPORT_SNS_DTD_OBJ_POINT_BUF_SIZE - 1].ObjDis;
      }
      pObjPt->Pt.x                = SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[SDG_MAX_SUPPORT_SNS_DTD_OBJ_POINT_BUF_SIZE - 1].Pt.x;
      pObjPt->Pt.y                = SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[SDG_MAX_SUPPORT_SNS_DTD_OBJ_POINT_BUF_SIZE - 1].Pt.y;
      pObjPt->CarPos.Coordinate.x = SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[SDG_MAX_SUPPORT_SNS_DTD_OBJ_POINT_BUF_SIZE - 1].CarPos.Coordinate.x;
      pObjPt->CarPos.Coordinate.y = SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[SDG_MAX_SUPPORT_SNS_DTD_OBJ_POINT_BUF_SIZE - 1].CarPos.Coordinate.y;
      pObjPt->CarPos.CarAng       = SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[SDG_MAX_SUPPORT_SNS_DTD_OBJ_POINT_BUF_SIZE - 1].CarPos.CarAng;
    }

  } else if (ObjIndex == SDG_MAX_SUPPORT_SNS_DTD_OBJ_POINT_BUF_SIZE) {
    // remove one point in the SDGSnsDtdObjPtBuf.
    // Search the WeightCoe which is less than SDG_OBJECT_ACK_WEIGHT_COEFFICIENT,
    // and the previous and next WeightCoe is great than SDG_OBJECT_ACK_WEIGHT_COEFFICIENT.
    // Do we need to check the distance ???
    ObjIndex--;
    for (ObjIndex2 = 1; ObjIndex2 < ObjIndex; ObjIndex2++) {
      if ((SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2].WeightCoe < SDG_OBJECT_ACK_WEIGHT_COEFFICIENT) &&
          (SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2 - 1].WeightCoe > SDG_OBJECT_ACK_WEIGHT_COEFFICIENT) &&
          (SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2 + 1].WeightCoe > SDG_OBJECT_ACK_WEIGHT_COEFFICIENT)
          //&& (SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2].ObjDis >= SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2 - 1].ObjDis)
          //&& (SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2].ObjDis >= SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2 + 1].ObjDis)
      ) {
        // OK, remove ObjIndex2
        bFlag = TRUE; // Use to indicate if a point should be removed from SDGSnsDtdObjPtBuf.
        break;
      }
    }
    if (bFlag == FALSE) {
      // the point which is not in increasing or decreasing sequence will be removed
      for (ObjIndex2 = 1; ObjIndex2 < ObjIndex; ObjIndex2++) {
        if ((SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2].ObjDis >= SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2 - 1].ObjDis) &&
            (SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2].ObjDis >= SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2 + 1].ObjDis)) {
          // OK, remove ObjIndex2
          bFlag = TRUE;
          break;
        }
      }
    }

    if (bFlag == FALSE) {
      // the point which is not in increasing or decreasing sequence will be removed
      SnsDtdDisTemp = SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[1].ObjDis;
      SysSnsIndex   = 1;
      for (ObjIndex2 = 1; ObjIndex2 < ObjIndex; ObjIndex2++) {
        if (SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2].ObjDis < SnsDtdDisTemp) {
          // OK, remove ObjIndex2
          SnsDtdDisTemp = SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2].ObjDis;
          SysSnsIndex   = ObjIndex2;
        }
      }

      // Search up
      ObjIndex2 = SysSnsIndex + 2;
      while (ObjIndex2 < ObjIndex) {
        if (SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2].ObjDis != NO_OBJ_DISTANCE) {
          // OK, remove ObjIndex2 - 1;
          ObjIndex2--;
          bFlag = TRUE;
          break;
        }
        ObjIndex2++;
      }
      if (bFlag == FALSE) {
        // Search down
        ObjIndex2 = SysSnsIndex - 2;
        while (ObjIndex2 >= 0) {
          if (SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2].ObjDis != NO_OBJ_DISTANCE) {
            // OK, remove ObjIndex2 - 1;
            ObjIndex2++;
            bFlag = TRUE;
            break;
          }
          ObjIndex2--;
        }
      }
      if (bFlag == FALSE) {
        // Just remove the object point near the nearest object point
        bFlag     = TRUE;
        ObjIndex2 = SysSnsIndex + 1;
        if (ObjIndex2 < ObjIndex) {
        } else {
          // bFlag = TRUE;
          ObjIndex2 = SysSnsIndex - 1;
          if (ObjIndex2 > 0) {
          } else {
            // Code should never reach.
            ObjIndex2 = ObjIndex;
          }
        }
      }
    }
    while (ObjIndex > ObjIndex2) {
      APATrajCalCopyMemory((UCHAR *)(&(SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2])),
                           (UCHAR *)(&(SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2 + 1])),
                           sizeof(SDGSnsDtdObjPointType));

      ObjIndex2++;
    }
  }

#if 0 // kjy 2012 10 03 removed

	// Just use y to check where should the current object being inserted to
	for(ObjIndex2 = 0; ObjIndex2 < ObjIndex; ObjIndex2 ++) {
		if(SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2].CarPos.Coordinate.y > pCurCarPos->Coordinate.y) {
			// OK, Insert current car pos into
			ObjIndex = SDG_MAX_SUPPORT_SNS_DTD_OBJ_POINT_BUF_SIZE - 1;
			while(ObjIndex > ObjIndex2) {
				APATrajCalCopyMemory((UCHAR *)(&(SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex])),
				                     (UCHAR *)(&(SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex - 1])), sizeof(SDGSnsDtdObjPointType));

				ObjIndex --;
			}
			ObjIndex = ObjIndex2;
			break;
		}
	}

#else

  // kjy 2012 10 03 added.

  // Since it has only 5 points in the buffer and also, the delta car pos of the start point and end point is
  // limited in a short range (eg. 0.6m).
  // The car angle is almost the same within this range.
  // Just use the car angle to distinguish the car pos.
  // The car angle is assumed in the range ( - PI, + PI).
  bFlag = FALSE;
  if ((pCurCarPos->CarAng > (-0.75 * PI)) && (pCurCarPos->CarAng < (-0.25 * PI))) {
    // Use X to compare. And X new should great than X old.
    CarDriveDir = 0;
  }
  if ((pCurCarPos->CarAng >= (-0.25 * PI)) && (pCurCarPos->CarAng < (0.25 * PI))) {
    // Use Y to compare. And Y new should great than Y old.
    CarDriveDir = 1;
  } else if ((pCurCarPos->CarAng >= (0.25 * PI)) && (pCurCarPos->CarAng < (0.75 * PI))) {
    // Use X to compare. And X new should less than X old.
    CarDriveDir = 2;
  } else {
    // Use Y to compare. And Y new should less than Y old.
    CarDriveDir = 3;
  }
  for (ObjIndex2 = 0; ObjIndex2 < ObjIndex; ObjIndex2++) {
    if (CarDriveDir == 0) {
      // Use X to compare. And X new should great than X old.
      if (SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2].CarPos.Coordinate.x > pCurCarPos->Coordinate.x) {
        // OK, Insert current car pos into
        bFlag = TRUE;
      }
    } else if (CarDriveDir == 1) {
      // Use Y to compare. And Y new should great than Y old.
      if (SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2].CarPos.Coordinate.y > pCurCarPos->Coordinate.y) {
        // OK, Insert current car pos into
        bFlag = TRUE;
      }
    } else if (CarDriveDir == 2) {
      // Use X to compare. And X new should less than X old.
      if (SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2].CarPos.Coordinate.x < pCurCarPos->Coordinate.x) {
        // OK, Insert current car pos into
        bFlag = TRUE;
      }
    } else {
      // Use Y to compare. And Y new should less than Y old.
      if (SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2].CarPos.Coordinate.y < pCurCarPos->Coordinate.y) {
        // OK, Insert current car pos into
        bFlag = TRUE;
      }
    }
    if (bFlag == TRUE) {

      ObjIndex = SDG_MAX_SUPPORT_SNS_DTD_OBJ_POINT_BUF_SIZE - 1;
      while (ObjIndex > ObjIndex2) {
        APATrajCalCopyMemory((UCHAR *)(&(SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex])),
                             (UCHAR *)(&(SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex - 1])),
                             sizeof(SDGSnsDtdObjPointType));

        ObjIndex--;
      }
      ObjIndex = ObjIndex2;
      break;
    }
  }

#endif

  if (ObjIndex >= SDG_MAX_SUPPORT_SNS_DTD_OBJ_POINT_BUF_SIZE) {
    ObjIndex = SDG_MAX_SUPPORT_SNS_DTD_OBJ_POINT_BUF_SIZE - 1;
  }

  // Cal object point (x, y)
  SnsDtdDisTemp = SnsDtdObjDis;
  if (SnsDtdDisTemp == NO_OBJ_DISTANCE) {
    SysSnsIndex = ObjIndex;
    while (SysSnsIndex > 0) {
      SysSnsIndex--;
      if (SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[SysSnsIndex].ObjDis != NO_OBJ_DISTANCE) {
        // Use this dis to calculate.
        SnsDtdDisTemp = SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[SysSnsIndex].ObjDis;
        break;
      }
    }
    if ((SnsDtdDisTemp == NO_OBJ_DISTANCE)) {
      SysSnsIndex = ObjIndex + 1;
      while (SysSnsIndex < SDG_MAX_SUPPORT_SNS_DTD_OBJ_POINT_BUF_SIZE) {
        if (SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[SysSnsIndex].ObjDis != NO_OBJ_DISTANCE) {
          // Use this dis to calculate.
          SnsDtdDisTemp = SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[SysSnsIndex].ObjDis;
          break;
        }
        SysSnsIndex++;
      }
    }
  }

  SnsDtdDisBk                                        = SnsDtdDisTemp;
  APASlotCorPCarMayHitObj1CorSideSnsMaxCompensateAng = 0;
  if (cProcessMode == 2) {
    bCompDisMethodFlag = FALSE;
    if ((SnsIndex == SDG_RRS_SNS_INDEX) || (SnsIndex == SDG_RLS_SNS_INDEX)) {

      if (SnsIndex == SDG_RRS_SNS_INDEX) {
        SlotObj1Or2X = USSPar.TrajCalObj2Pos.x;
        SlotObj1Or2Y = USSPar.TrajCalObj2Pos.y;
        Pt.x         = APACal.SnsPos[APA_RRS_SNS_INDEX].x;
        Pt.y         = APACal.SnsPos[APA_RRS_SNS_INDEX].y;
      } else {
        SlotObj1Or2X = USSPar.TrajCalObj1Pos.x;
        SlotObj1Or2Y = USSPar.TrajCalObj1Pos.y;
        Pt.x         = APACal.SnsPos[APA_RLS_SNS_INDEX].x;
        Pt.y         = APACal.SnsPos[APA_RLS_SNS_INDEX].y;
      }

      CarCenterPt.Coordinate.x = pCurCarPos->Coordinate.x;
      CarCenterPt.Coordinate.y = pCurCarPos->Coordinate.y;
      CarCenterPt.CarAng       = pCurCarPos->CarAng;

      RRSOrRLSSnsPt.Coordinate = APATrajCalPointPosWithAngAndCenterPt(Pt, CarCenterPt.CarAng, CarCenterPt.Coordinate);

      if (RRSOrRLSSnsPt.Coordinate.y > (SlotObj1Or2Y + APACal.APASlotPCorMinDelYToCompDisByConstantValue[SnsIndex - 2])) {
        APASlotCorPCarMayHitObj1CorSideSnsMaxCompensateAng = APACal.APASlotPCorCompDisByConstantValue[SnsIndex - 2];
      } else {
        if (RRSOrRLSSnsPt.Coordinate.x < (SlotObj1Or2X + APACal.APASlotPCorMinDelPosXToCorObjByAngAndDis[SnsIndex])) {
          if (SnsDtdDisTemp > APACal.APASlotPCorMaxDisOfCorOrSideSnsDtIfCarInOutSideSlot[SnsIndex]) {
            SnsDtdDisTemp = NO_OBJ_DISTANCE;
          } else {
            SideSnsXDisBiggerThanThresholdCnt = 0;
            for (SDGBufDisIndex = 0; SDGBufDisIndex < SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtCnt; SDGBufDisIndex++) {
              if (SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SDGBufDisIndex].ObjDis != NO_OBJ_DISTANCE) {
                if ((SDGObjInfo.SnsObjPtBuf[SnsIndex].ObjPtBuf[SDGBufDisIndex].Pt.x - SlotObj1Or2X) >=
                    APACal.APASlotPCorMinDetXOfCorOrSideSnsDtOnCarBodyIfIngoreDisDtOnCarHead[SnsIndex]) {
                  SideSnsXDisBiggerThanThresholdCnt++;
                }
                if (SideSnsXDisBiggerThanThresholdCnt >= APACal.APASlotPCorMinCntOfCorOrSideSnsDtOnCarBodyIfIngoreDisDtOnCarHead[SnsIndex]) {
                  SnsDtdDisTemp = NO_OBJ_DISTANCE;
                  break;
                }
              }
            }
          }
          if (SnsDtdDisTemp != NO_OBJ_DISTANCE) {
            bCompDisMethodFlag = TRUE;
          }
        }
        if (SnsDtdDisTemp != NO_OBJ_DISTANCE) {
          for (SideSnsDisIndex = 0; SideSnsDisIndex < (APA_SLOT_P_COR_SNS_DIS_DIV_NUM - 1); SideSnsDisIndex++) {
            if (SideSnsDisIndex < APACal.APASlotPCorCorOrSideSnsDisArray[1][SideSnsDisIndex]) {
              break;
            }
          }

          // Added by lu zhimeng 2014 04 14
          EndPosToCurCarPosDeltaAng = USSPar.TrajCalCarEndPos.CarAng - CarCenterPt.CarAng;

          if (SnsIndex == SDG_RRS_SNS_INDEX) {
            if ((EndPosToCurCarPosDeltaAng >
                 (APACal.APASlotPCorSideSnsDeltaAngBetweenCurAngAndEndAng
                      .APASlotPCorSideSnsDeltaAngArray[APACal.APASlotPCorSideSnsDeltaAngBetweenCurAngAndEndAng.APASlotPCorSideSnsDeltaAngZoneNum] +
                  5.0 * PI / 180.0)) &&
                (CarCenterPt.Coordinate.y > (USSPar.TrajCalObj2Pos.y - 1000))) {
              // Angle is too big.
              // Delta Angle is very big.
              // Just default to 0 deg.
              EndPosToCurCarPosDeltaAng = 0;
            }
          }
          for (DeltaAngIndex = 0; DeltaAngIndex < APACal.APASlotPCorSideSnsDeltaAngBetweenCurAngAndEndAng.APASlotPCorSideSnsDeltaAngZoneNum;
               DeltaAngIndex++) {
            if (EndPosToCurCarPosDeltaAng <= APACal.APASlotPCorSideSnsDeltaAngBetweenCurAngAndEndAng.APASlotPCorSideSnsDeltaAngArray[DeltaAngIndex]) {
              break;
            }
          }
          APASlotCorPCarMayHitObj1CorSideSnsMaxCompensateAng = APASlotPCorSideSnsDisCompensatCalculation(
              DeltaAngIndex, SideSnsDisIndex, (SnsIndex - 2), EndPosToCurCarPosDeltaAng, SnsDtdDisTemp, 1, bCompDisMethodFlag);
        }
      }
    }
  }

  SysSnsIndex = SDGSnsIndexConvertToSysSnsIndex[SnsIndex];
#if 0
	SnsDtdObjPt = SDGCalObjPtRelativeToCarCoordinateBySnsDtdDis(
	                  SnsDtdDisTemp, SysSnsIndex);
#endif

#ifdef APA_SUPPORT_SENSOR_CAL_FOR_PERPENDICULAR_PARK_IN
  APASlotCorPCarMayHitObj1CorSideSnsMaxCompensateAng = APASlotCorPCarMayHitObj1CorSideSnsMaxCompensateAngCal[SnsIndex];
#endif

  SnsDtdObjPt = APASlotProcCalObjPtCoordinateBySnsDtdDis(SnsDtdDisTemp, APASlotCorPCarMayHitObj1CorSideSnsMaxCompensateAng, SysSnsIndex);

  SnsDtdObjPt = APATrajCalPointPosWithAngAndCenterPt(SnsDtdObjPt, pCurCarPos->CarAng, pCurCarPos->Coordinate);

  if (SnsDtdDisTemp == SnsDtdDisBk) {
    SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].ObjDis = SnsDtdObjDis;
  } else {
    SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].ObjDis = SnsDtdDisTemp;
  }

  SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.CarAng       = pCurCarPos->CarAng;
  SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.Coordinate.x = pCurCarPos->Coordinate.x;
  SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].CarPos.Coordinate.y = pCurCarPos->Coordinate.y;
  SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].Pt.x                = (SDG_DISTANCE_TYPE)SnsDtdObjPt.x;
  SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].Pt.y                = (SDG_DISTANCE_TYPE)SnsDtdObjPt.y;
  SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex].WeightCoe           = WeightCoe;
  SDGSnsDtdObjPtBuf[SnsIndex].SnsDtLoopCnt++;

  // Check Object type.

  if (SDGSnsDtdObjPtBuf[SnsIndex].WrIndex == SDG_MAX_SUPPORT_SNS_DTD_OBJ_POINT_BUF_SIZE) {
    // step 1. get the min object distance.
    MinSnsDtdDis = NO_OBJ_DISTANCE;
    MaxSnsDtdDis = 0;
    ObjIndex     = 0;
    ObjDtdCnt    = 0;
    for (ObjIndex2 = 0; ObjIndex2 < SDG_MAX_SUPPORT_SNS_DTD_OBJ_POINT_BUF_SIZE; ObjIndex2++) {
      if (SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2].WeightCoe >= SDG_OBJECT_ACK_WEIGHT_COEFFICIENT) {
        if (SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2].ObjDis < MinSnsDtdDis) {
          MinSnsDtdDis = SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2].ObjDis;
          ObjIndex     = ObjIndex2;
        }
        if (SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2].ObjDis > MaxSnsDtdDis) {
          MaxSnsDtdDis = SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2].ObjDis;
          // ObjIndex = ObjIndex2;
        }
        ObjDtdCnt++;
      }
    }
    SDGSnsDtdObjPtBuf[SnsIndex].ObjType = SDG_OBJ_TYPE_UNKNOWN;
    if (MinSnsDtdDis == NO_OBJ_DISTANCE) {
      // OK, no object exist
    } else {
      // 2. Check if it is round object.
      // 2.1 scenario 1
      //
      // ^
      // | ^
      // | | ^
      // | | | ^^^
      // | | | |||
      //
      // Search down from the min dis
      // ObjIndex is the min dis index.

      if (ObjIndex > 3) {
        // At least 4 points.

        bFlag = FALSE; // Indicate the object dis is in the decreasing sequence.

        for (ObjIndex2 = ObjIndex - 1; ObjIndex2 > 0; ObjIndex2--) {

          if ((SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2].WeightCoe >= SDG_OBJECT_ACK_WEIGHT_COEFFICIENT) &&
              (SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2 - 1].WeightCoe >= SDG_OBJECT_ACK_WEIGHT_COEFFICIENT)) {
            if (SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2].ObjDis > SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2 - 1].ObjDis) {
              // Obj1 < Obj2. Object is not in the descreasing sequence.
              bFlag = TRUE;
              break;
            }
          }
        }

        if (bFlag == FALSE) {
          SnsDtdDisTemp = SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[0].ObjDis;
          if ((SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[0].WeightCoe >= SDG_OBJECT_ACK_WEIGHT_COEFFICIENT)
              /*&& (SnsDtdDisTemp != NO_OBJ_DISTANCE)*/) {
            if ((SnsDtdDisTemp > (MinSnsDtdDis + SDGCal.SDGSnsDtRoundObjMinDeltaDis)) &&
                (SnsDtdDisTemp < (MinSnsDtdDis + SDGCal.SDGSnsDtRoundObjMaxDeltaDis))) {
              SysSnsIndex = ObjIndex / 2;
              if ((SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[SysSnsIndex].WeightCoe >= SDG_OBJECT_ACK_WEIGHT_COEFFICIENT)) {
                if ((SnsDtdDisTemp > SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[SysSnsIndex].ObjDis) &&
                    (MinSnsDtdDis < SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[SysSnsIndex].ObjDis)) {
                  // OK, regarded it as round object
                  SDGSnsDtdObjPtBuf[SnsIndex].ObjType = SDG_OBJ_TYPE_ROUND;
                }
              }
            }
          }
        }
      }

      // 2.2 scenario 2
      //
      //         ^
      //        ^|
      //      ^ ||
      // ^ ^ ^| ||
      // | | || ||
      //
      // Search up from the min dis
      // ObjIndex is the min dis index.

      if ((SDGSnsDtdObjPtBuf[SnsIndex].ObjType == SDG_OBJ_TYPE_UNKNOWN) && (ObjIndex < SDG_MAX_SUPPORT_SNS_DTD_OBJ_POINT_BUF_SIZE - 3)) {
        // At least 4 points.
        bFlag = FALSE; // Indicate the object dis is in the increasing sequence.

        for (ObjIndex2 = ObjIndex + 1; ObjIndex2 < (SDG_MAX_SUPPORT_SNS_DTD_OBJ_POINT_BUF_SIZE - 1); ObjIndex2++) {

          if ((SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2].WeightCoe >= SDG_OBJECT_ACK_WEIGHT_COEFFICIENT) &&
              (SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2 + 1].WeightCoe >= SDG_OBJECT_ACK_WEIGHT_COEFFICIENT)) {
            if (SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2].ObjDis > SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[ObjIndex2 + 1].ObjDis) {
              // Obj1 > Obj2. Object is not in the descreasing sequence.
              bFlag = TRUE;
              break;
            }
          }
        }

        if (bFlag == FALSE) {
          SnsDtdDisTemp = SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[SDG_MAX_SUPPORT_SNS_DTD_OBJ_POINT_BUF_SIZE - 1].ObjDis;
          if ((SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[SDG_MAX_SUPPORT_SNS_DTD_OBJ_POINT_BUF_SIZE - 1].WeightCoe >= SDG_OBJECT_ACK_WEIGHT_COEFFICIENT)
              /*&& (SnsDtdDisTemp != NO_OBJ_DISTANCE)*/) {
            if ((SnsDtdDisTemp > (MinSnsDtdDis + SDGCal.SDGSnsDtRoundObjMinDeltaDis)) &&
                (SnsDtdDisTemp < (MinSnsDtdDis + SDGCal.SDGSnsDtRoundObjMaxDeltaDis))) {
              SysSnsIndex = (SDG_MAX_SUPPORT_SNS_DTD_OBJ_POINT_BUF_SIZE - ObjIndex) / 2;
              if ((SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[SysSnsIndex].WeightCoe >= SDG_OBJECT_ACK_WEIGHT_COEFFICIENT)) {
                if ((SnsDtdDisTemp > SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[SysSnsIndex].ObjDis) &&
                    (MinSnsDtdDis < SDGSnsDtdObjPtBuf[SnsIndex].ObjPtBuf[SysSnsIndex].ObjDis)) {
                  // OK, regarded it as round object
                  SDGSnsDtdObjPtBuf[SnsIndex].ObjType = SDG_OBJ_TYPE_ROUND;
                }
              }
            }
          }
        }
      }

      // 3. Check if it is square object.
      // 3.1 scenario 1
      //
      //      ^
      // ^ ^ ^| ^^
      // | | || ||
      //
      // ObjIndex is the min dis index.
      if ((SDGSnsDtdObjPtBuf[SnsIndex].ObjType == SDG_OBJ_TYPE_UNKNOWN) && (ObjDtdCnt > 3) &&
          (MaxSnsDtdDis < (MinSnsDtdDis + SDGCal.SDGSnsDtSQuareObjMaxDeltaDis))) {
        // At least 4 points
        // OK, regarded it as square object
        SDGSnsDtdObjPtBuf[SnsIndex].ObjType = SDG_OBJ_TYPE_SQUARE;
      }
    }
  }

  // if(bSaveObjPtToObjBuf == TRUE){
  pObjPt->ObjType = SDGSnsDtdObjPtBuf[SnsIndex].ObjType;
  //}
  return bSaveObjPtToObjBuf;
}
#endif
/*************************************************************************************************************************************************
** Syntax :  void USS(void)                                                                                                                     **
**                                                                                                                                              **
** Service ID:   : NA                                                                                                                           **
**                                                                                                                                              **
** Sync/Async:   : Synchronous                                                                                                                  **
**                                                                                                                                              **
** Reentrancy:   : Non Reentrant                                                                                                                **
**                                                                                                                                              **
** Parameters (in): none                                                                                                                        **
**                                                                                                                                              **
** Parameters (out): none                                                                                                                       **
**                                                                                                                                              **
** Return value: none                                                                                                                           **
**                                                                                                                                              **
** Description : ..                                                                                                                             **
*************************************************************************************************************************************************/
#if Debug_SW_PARKINFUNC
void SDGSensorDtdObjectDisProcessTask(APA_ENUM_TYPE cProcessMode) {
  // cProcessMode == 0: Without Searching slot
  // cProcessMode == 1: During searching slot.
  // cProcessMode == 2: During parking in to slot.

  // SDG Sensor detected object distance process.

  SDG_ENUM_TYPE cSnsReadPointer, cSnsWritePointer, cProcessCnt, Index, SnsStartIndex;
  APA_ENUM_TYPE APAState;
  APA_ENUM_TYPE cSnsIndex[SDG_SUPPORT_SDG_SNS_NUM];
  SDGOperatingStateType SDGRunningState;
  SDG_DISTANCE_TYPE SDGSnsDtdObjDis[SDG_SUPPORT_SDG_SNS_NUM];
  SDGObjPointType ObjPt;
  APACarCoordinateDataCalFloatType CarCurPos; ////dsh 20120227

  if (cProcessMode == 0) {
    SDGRunningState = SDGState;
    APAState        = USSPar.APAState;

    if ((SDGRunningState != SDG_OPERATION_MODE) || (APAState != APA_STATE_DISABLE)) {
      return;
    }

    if (APAObjDisUpdateFlag.Byte == 0) {
      // APA sensor is detecting object, and it has not finished yet.
      return;
    }
    APAObjDisUpdateFlag.Byte = 0;
    // LeftSlotDepth = wProcessedObjBeingDtdDis_APA[1];
    // RightSlotDepth = wProcessedObjBeingDtdDis_APA[0]
  }

  cProcessCnt = APA_MAX_SUPPORT_SNS_DTD_OBJ_DIS_BUF_SIZE;

  while (cProcessCnt > 0) {
    cProcessCnt--;

    cSnsReadPointer  = USSPar.APASnsDtdObjDisInfoBufReadIndex;
    cSnsWritePointer = USSPar.APASnsDtdObjDisInfoBufWriteIndex;

    if ((cSnsReadPointer >= cSnsWritePointer) && ((cProcessMode == 0) || (cProcessMode == 2))) {
      USSPar.APASnsDtdObjDisInfoBufReadIndex  = 0;
      USSPar.APASnsDtdObjDisInfoBufWriteIndex = 0;
      break;
    } else {
      /* There is sns dtd dis need to be processed */
      /*if(cSnsReadPointer >= APA_MAX_SUPPORT_SNS_DTD_OBJ_DIS_BUF_SIZE){
          cSnsReadPointer = cSnsReadPointer % APA_MAX_SUPPORT_SNS_DTD_OBJ_DIS_BUF_SIZE;
      }*/

      CarCurPos.Coordinate.x                          = USSPar.APASnsDtdObjDisInfoBuf[cSnsReadPointer].CarCenterPt.Coordinate.x;
      CarCurPos.Coordinate.y                          = USSPar.APASnsDtdObjDisInfoBuf[cSnsReadPointer].CarCenterPt.Coordinate.y;
      CarCurPos.CarAng                                = USSPar.APASnsDtdObjDisInfoBuf[cSnsReadPointer].CarCenterPt.CarAng;
      SDGBooleanFlags.Bits.bAPASlotDataIsMirrorChange = USSPar.APACommonFlags.Bits.bSlotDataIsMirrorChanged;
      if (cProcessMode == 2) {
        // During parking into slot.
        // It may be at right side or left side slot.
        // But here we just mirror the left side slot to the right side.
        if (USSPar.APACarParkAtLeftOrRightSide == APA_CAR_PARK_AT_LEFT_SIDE) {
          cSnsIndex[SDG_FRS_SNS_INDEX] = SDG_FLS_SNS_INDEX;
          cSnsIndex[SDG_FLS_SNS_INDEX] = SDG_FRS_SNS_INDEX;
          cSnsIndex[SDG_RRS_SNS_INDEX] = SDG_RLS_SNS_INDEX;
          cSnsIndex[SDG_RLS_SNS_INDEX] = SDG_RRS_SNS_INDEX;
        } else {
          cSnsIndex[SDG_FRS_SNS_INDEX] = SDG_FRS_SNS_INDEX;
          cSnsIndex[SDG_FLS_SNS_INDEX] = SDG_FLS_SNS_INDEX;
          cSnsIndex[SDG_RRS_SNS_INDEX] = SDG_RRS_SNS_INDEX;
          cSnsIndex[SDG_RLS_SNS_INDEX] = SDG_RLS_SNS_INDEX;
        }

        for (Index = 0; Index < SDG_SUPPORT_SDG_SNS_NUM; Index++) {
          SDGSnsDtdObjDis[Index] = USSPar.APASnsDtdObjDisInfoBuf[cSnsReadPointer].APASnsDtdObjDis[cSnsIndex[Index]];
          if (SDGSnsDtdObjDis[Index] < 250) {
            SDGSnsDtdObjDis[Index] = NO_OBJ_DISTANCE;
          } else if ((SDGSnsDtdObjDis[Index] > APACal.APASlotPRSideSnsDtMaxObjDis) ||
                     (USSPar.APASnsDtdObjDisInfoBuf[cSnsReadPointer].CarCenterPt.Coordinate.x > USSPar.TrajCalCarEndPos.Coordinate.x)) {
            SDGSnsDtdObjDis[Index] = NO_OBJ_DISTANCE;
          } else {
            if (Index == SDG_RRS_SNS_INDEX) {
              // RRS SNS.
              if (USSPar.APASnsDtdObjDisInfoBuf[cSnsReadPointer].CarCenterPt.CarAng < (PI / 4.0)) {
                if (USSPar.APASnsDtdObjDisInfoBuf[cSnsReadPointer].CarCenterPt.Coordinate.x < APACal.APASlotPSDGBufRRSideSnsDtMinCarPosX) {
                  SDGSnsDtdObjDis[Index] = NO_OBJ_DISTANCE;
                }
              } else {
                // > PI / 4

                if (USSPar.APASnsDtdObjDisInfoBuf[cSnsReadPointer].CarCenterPt.Coordinate.x < APACal.APASlotPSDGBufRLSideSnsDtMinCarPosX) {
                  SDGSnsDtdObjDis[Index] = NO_OBJ_DISTANCE;
                }
              }
            } else {
              // RLS SNS.
              if (USSPar.APASnsDtdObjDisInfoBuf[cSnsReadPointer].CarCenterPt.Coordinate.x < APACal.APASlotPSDGBufRLSideSnsDtMinCarPosX) {
                SDGSnsDtdObjDis[Index] = NO_OBJ_DISTANCE;
              }
              if ((USSPar.APASnsDtdObjDisInfoBuf[cSnsReadPointer].CarCenterPt.Coordinate.x < -200) &&
                  (SDGSnsDtdObjDis[Index] > (APACal.APASlotPRSideSnsDtMaxObjDis / 2))) {
                SDGSnsDtdObjDis[Index] = NO_OBJ_DISTANCE;
              }
            }
          }
        }
        SnsStartIndex = SDG_RRS_SNS_INDEX;
      } else {

        if (SDGBooleanFlags.Bits.bAPASlotDataIsMirrorChange == TRUE) { // dsh 20120227
          CarCurPos.Coordinate.x = -CarCurPos.Coordinate.x;
          // CarCurPos.Coordinate.y = CarCurPos.Coordinate.y;
          CarCurPos.CarAng = -CarCurPos.CarAng;
        }
        for (Index = 0; Index < SDG_SUPPORT_SDG_SNS_NUM; Index++) {
          SDGSnsDtdObjDis[Index] = USSPar.APASnsDtdObjDisInfoBuf[cSnsReadPointer].APASnsDtdObjDis[Index];
          if (SDGSnsDtdObjDis[Index] < SDGCal.SDGDtObjMinDis) {
            SDGSnsDtdObjDis[Index] = NO_OBJ_DISTANCE;
          } else if (SDGSnsDtdObjDis[Index] > SDGCal.SDGDtObjMaxDis) {
            SDGSnsDtdObjDis[Index] = NO_OBJ_DISTANCE;
          }
        }
        SnsStartIndex = SDG_FRS_SNS_INDEX;
      }
      SDGVehicleSpeed                                = USSPar.APAVehicleSpeed;
      SDGBooleanFlags.Bits.bSDGCarIsRunningBackwards = USSPar.APACommonFlags.Bits.bCarIsDrivingBackwards;

      // Save SDG Sensor object distance to SDGSnsDtdObjPtBuf
      for (Index = SnsStartIndex; Index < SDG_SUPPORT_SDG_SNS_NUM; Index++) {
        if (SDGSaveSnsDtdObjDisToBuf(SDGSnsDtdObjDis[Index], Index, &(CarCurPos), SDGVehicleSpeed, &ObjPt, cProcessMode) == TRUE) {
          SDGSaveObjPointToBuf(Index, &ObjPt);
        }
      }
      if ((cProcessMode == 0) || (cProcessMode == 2)) {

        USSPar.APASnsDtdObjDisInfoBufReadIndex++;

      } else {
        break;
      }
    }
  }
}
#endif


#define ALG_STOP_SEC_CODE
#include "IS31_UserMemMap.h"
/*************************************************************************************************************************************************
**                                                     End of file                                                                              **
*************************************************************************************************************************************************/
