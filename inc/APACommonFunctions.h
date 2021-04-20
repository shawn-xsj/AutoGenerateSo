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
**  $FILENAME   : APACommonFunctions.h $                                                                                                              **
**                                                                                                                                              **
**  $CC VERSION : \main\94 $                                                                                                                    **
**                                                                                                                                              **
**  $DATE       : 2020-08-18 $                                                                                                                  **
**                                                                                                                                              **
**  AUTHOR      : SAIC CH-Engineering                                                                                                      **
**                                                                                                                                              **
**  VENDOR      : SAIC Technologies                                                                                                             **
**                                                                                                                                              **
**  DESCRIPTION : This file contains                                                                                                            **
**                - Ultrasonic bottom data layer processing                 ..                                                                  **
**                                                                                                                                              **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                                                                                        **
**                                                                                                                                              **
*************************************************************************************************************************************************/
#ifndef APACOMMONFUNCTIONS_H_
#define APACOMMONFUNCTIONS_H_


/*************************************************************************************************************************************************
**                                                              Includes                                                                        **
*************************************************************************************************************************************************/
#include "APACommonType.h"

/*************************************************************************************************************************************************
**                                                              Global Macro Definitions                                                        **
*************************************************************************************************************************************************/

/*************************************************************************************************************************************************
**                                                              Global Type Definitions                                                         **
*************************************************************************************************************************************************/


/*************************************************************************************************************************************************
**                                                              Global Constant Declarations                                                    **
*************************************************************************************************************************************************/

/*************************************************************************************************************************************************
**                                                              Global Variable Declarations                                                    **
*************************************************************************************************************************************************/

/*************************************************************************************************************************************************
**                                                              Global Function Declarations                                                    **
*************************************************************************************************************************************************/
float32 ProtectedAsinf(float32 f32X);
float32 ProtectedAcosf(float32 f32X);
float32 ProtectedSqrtf(float32 f32X);
float32 ProtectedTanf(float32 f32AngularRad);
LineABC_ST CF_GetLineKnownPointOnLineAndParallelLline(Point_ST *stPointOnLinePtr,LineABC_ST *stParallelLineABCPtr);
float32 CalculateAngleBetweenTwoLines(float32 Vectorx1, float32 Vectory1, float32 Vectorx2, float32 Vectory2);
float32 CalculatePointToLineDistance(float32 Pointx,float32 Pointy,float32 LineA,float32 LineB,float32 LineC);
void CF_CrdTrnsPoseKnownNewOrgInOldCrd(float32 input_f32PoseInOldCrd_X_m,
                                       float32 input_f32PoseInOldCrd_Y_m,
                                       float32 input_f32PoseInOldCrd_A_rad,
                                       float32 input_f32NewCrdOrgInOldCrd_X_m,
                                       float32 input_f32NewCrdOrgInOldCrd_Y_m,
                                       float32 input_f32NewCrdOrgInOldCrd_A_rad,
                                       float32 *output_f32NewPoseInNewCrd_X_m,
                                       float32 *output_f32NewPoseInNewCrd_Y_m,
                                       float32 *output_f32NewPoseInNewCrd_A_rad);
void CF_CrdTrnsPoseKnownOldOrgInNewCrd(float32 input_f32PoseInOldCrd_X_m,
                                       float32 input_f32PoseInOldCrd_Y_m,
                                       float32 input_f32PoseInOldCrd_A_rad,
                                       float32 input_f32OldCrdOrgInMewCrd_X_m,
                                       float32 input_f32OldCrdOrgInMewCrd_Y_m,
                                       float32 input_f32OldCrdOrgInMewCrd_A_rad,
                                       float32 *output_f32NewPoseInNewCrd_X_m,
                                       float32 *output_f32NewPoseInNewCrd_Y_m,
                                       float32 *output_f32NewPoseInNewCrd_A_rad);
void CF_CrdTrnsPointKnownNewOrgInOldCrd(float32 input_f32PoseInOldCrd_X_m,
                                        float32 input_f32PoseInOldCrd_Y_m,
                                        float32 input_f32NewCrdOrgInOldCrd_X_m,
                                        float32 input_f32NewCrdOrgInOldCrd_Y_m,
                                        float32 input_f32NewCrdOrgInOldCrd_A_rad,
                                        float32 *output_f32NewPoseInNewCrd_X_m,
                                        float32 *output_f32NewPoseInNewCrd_Y_m);
void CF_CrdTrnsPointKnownOldOrgInNewCrd(float32 input_f32PoseInOldCrd_X_m,
                                        float32 input_f32PoseInOldCrd_Y_m,
                                        float32 input_f32OldCrdOrgInMewCrd_X_m,
                                        float32 input_f32OldCrdOrgInMewCrd_Y_m,
                                        float32 input_f32OldCrdOrgInMewCrd_A_rad,
                                        float32 *output_f32NewPoseInNewCrd_X_m,
                                        float32 *output_f32NewPoseInNewCrd_Y_m);
uint8 CF_CrdTrnsLineABCKnownNewOrgInOldCrd(Pose_ST stPoseNewOrgInOldCrd,
                                           LineABC_ST stOldLine,
                                           LineABC_ST *stNewLine);
void CF_GetLineABCByTwoPoint(Point_ST stPointA,
                             Point_ST stPointB,
                             LineABC_ST *stLine);
APA_DISTANCE_CAL_INT_TYPE APASlotProcCalTwoPtApproximateDisInt(
	                                                            APACoordinateDataType Pt1,
	                                                            APACoordinateDataType Pt2);
APACoordinateDataCalFloatType APASlotProcCalSlotRelativeToCarCoordinateBySlotDisToCar(
                                                                                        APA_DISTANCE_TYPE SlotDepth,
                                                                                        APA_INDEX_TYPE SnsIndex) ;
APA_CAL_FLOAT_TYPE APATrajCalMathSqrt(
                                        APA_CAL_FLOAT_TYPE X);
APA_CAL_FLOAT_TYPE APATrajCalMathAsin(
                                        APA_CAL_FLOAT_TYPE X);
APA_CAL_FLOAT_TYPE APATrajCalMathAcos(
                                        APA_CAL_FLOAT_TYPE X);
APA_CAL_FLOAT_TYPE APATrajCalMathTan(
                                        APA_CAL_FLOAT_TYPE X);
APALineIsVerticalOrHorizontalType APATrajCalCheckIfTheCarIsDrivingVerticallyOrHorizontally(
                                                                                            APA_ANGLE_TYPE CarAng);
APA_DISTANCE_CAL_FLOAT_TYPE APATrajCalGetPointToLineDis(
                                                            APACoordinateDataCalFloatType Pt,
                                                            APALineParameterABCType LinePar);
APA_CAL_FLOAT_TYPE APATrajCalTwoPointInterpolationCalculation(
                                                                APA_CAL_FLOAT_TYPE Y1, 
														        APA_CAL_FLOAT_TYPE Y2,
														        APA_CAL_FLOAT_TYPE X1,
														        APA_CAL_FLOAT_TYPE X2,
														        APA_CAL_FLOAT_TYPE X);
APA_DISTANCE_CAL_INT_TYPE APATrajCalGetTwoPointDisInt(
                                                        APA_DISTANCE_TYPE X1,
                                                        APA_DISTANCE_TYPE Y1,
                                                        APA_DISTANCE_TYPE X2,
                                                        APA_DISTANCE_TYPE Y2);
BOOLEAN APATrajCalLineParABCbyTwoPoints(
                                        APACoordinateDataCalFloatType Pt1,
                                        APACoordinateDataCalFloatType Pt2,
                                        APALineParameterABCType *pLinePar);
void APATrajCalCopyMemory(
                            UCHAR *  pDst,
                            UCHAR *  pSrc,
                            APA_INT_TYPE Size);	
APA_DISTANCE_CAL_FLOAT_TYPE APATrajCalGetTwoPointDisFloat(
                                                            APACoordinateDataCalFloatType Pt1,
                                                            APACoordinateDataCalFloatType Pt2);
APA_ENUM_TYPE APATrajCalCarDriveTrajectoryByTwoCarPos(
                                                        APACarCoordinateDataCalFloatType CarCurPt,
                                                        APACarCoordinateDataCalFloatType CarPrevPt,
                                                        APALineParameterABCType * pCarDrvLinePar,
                                                        APACoordinateDataCalFloatType *pCircleCenterPt,
                                                        APA_DISTANCE_CAL_FLOAT_TYPE *pRc);
APALineParameterABCType APATrajCalLineParABCByCurrentCarPosition(
                                                                    APACarCoordinateDataCalFloatType *pCurCarPos,
                                                                    APA_ENUM_TYPE LineType);
BOOLEAN APATrajCalCircleRadiusAndCenterPointByTwoPointOnArcAndLineCrossCenterPt(
                                                                                APACoordinateDataCalFloatType Pt1,
                                                                                APACoordinateDataCalFloatType Pt2,
                                                                                APALineParameterABCType LC,
                                                                                APACoordinateDataCalFloatType *pCircleCenterPt,
                                                                                APA_DISTANCE_CAL_FLOAT_TYPE *pRadius);
APA_ENUM_TYPE APATrajCalCrossPointOfTwoCircles(
                                                APACoordinateDataCalFloatType Ptc0,
                                                APA_DISTANCE_CAL_FLOAT_TYPE R0,
                                                APACoordinateDataCalFloatType Ptc1,
                                                APA_DISTANCE_CAL_FLOAT_TYPE R1,
                                                APACoordinateDataCalFloatType *  pPtc2);
void APATrajCalCarPosByCarCenterPtAndPtOnCarSideLine(
                                                        APACoordinateDataCalFloatType PtOnSideLine,
                                                        APA_DISTANCE_CAL_FLOAT_TYPE DisBtCenterPtAndPtOnSideLine,
                                                        APA_DISTANCE_CAL_FLOAT_TYPE DisBtCenterPtAndSideLine,
                                                        APA_DISTANCE_CAL_FLOAT_TYPE TurningRadius,
                                                        APACoordinateDataCalFloatType CarCenterPt,
                                                        APA_ENUM_TYPE CarSideLineType,
                                                        BOOLEAN bDriveClockWise,
                                                        APACarCoordinateDataCalFloatType * pCarPos);
APA_ANGLE_CAL_FLOAT_TYPE APATrajCalGetChordAngle(
                                                    APACoordinateDataCalFloatType Pt1,
                                                    APACoordinateDataCalFloatType Ptc,
                                                    APA_DISTANCE_CAL_FLOAT_TYPE R);
APA_ANGLE_CAL_FLOAT_TYPE APATrajCalGetCarAngleByRAxisChordAngle(
                                                                    APA_ANGLE_CAL_FLOAT_TYPE RearAxisChordAngle,
                                                                    BOOLEAN bCarDrivingClockWise);
APACoordinateDataCalFloatType APATrajCalPointOnArcWithArcCenterPtAndAngle(
                                                                            APA_ANGLE_CAL_FLOAT_TYPE ArcAngle,
                                                                            APA_DISTANCE_CAL_FLOAT_TYPE Radius,
                                                                            APACoordinateDataCalFloatType CenterPt);
APALineParameterABCType APATrajCalLineParABCByPerPendLineAndPointOnLine(
                                                                        APACoordinateDataCalFloatType PtOnLine,
                                                                        APALineParameterABCType *pPerPendLine);
APACoordinateDataCalFloatType APATrajCalPointPosWithAngAndCenterPt(
                                                                    APACoordinateDataCalFloatType DstPt,
                                                                    APA_ANGLE_TYPE Angle,
                                                                    APACoordinateDataCalFloatType CenterPt);

APA_DISTANCE_CAL_FLOAT_TYPE APATrajCalLineParCByParallelLineAndDisToLine(APA_DISTANCE_CAL_FLOAT_TYPE DisToLine,
                                                                         APALineParameterABCType *pParallelLine); 

APA_ENUM_TYPE APATrajCalCheckIfTheLineIsVerticalOrHorizontalByTwoPoint(APACoordinateDataCalFloatType Pt1,
                                                                       APACoordinateDataCalFloatType Pt2,
                                                                       APA_DISTANCE_CAL_FLOAT_TYPE *pKLine) ;

APA_ENUM_TYPE APATrajCalCheckIfThePointIsAtLeftOrRightSideOfALine(APALineParameterABCType *pLine, APACoordinateDataCalFloatType Pt);  

APA_INT_TYPE IntegerAbs(APA_INT_TYPE x);

#define MATH_ABS										IntegerAbs
#define MATH_FABS										fabsf
#define MATH_COS										cosf
#define MATH_SIN										sinf
#define MATH_ATAN										atanf
#define MATH_SQRT										APATrajCalMathSqrt
#define MATH_ASIN										APATrajCalMathAsin
#define MATH_ACOS										APATrajCalMathAcos
#define MATH_TAN										APATrajCalMathTan

#define _USEPROTECTEDMATH

#ifdef _USEPROTECTEDMATH
#define Math_cos  cosf
#define Math_sin  sinf
#define Math_acos ProtectedAcosf
#define Math_asin ProtectedAsinf
#define Math_atan atanf
#define Math_atan2 atan2f
#define Math_ceil  ceilf
#define Math_exp expf
#define Math_fabs fabsf
#define Math_floor floorf
#define Math_fmod fmodf
#define Math_frexp frexpf
#define Math_ldexp ldexpf
#define Math_mod modff
#define Math_pow powf
#define Math_sqrt ProtectedSqrtf
#define Math_tan tanf
#define Math_tanh tanhf
#define Math_hypot hypot
#else
#define Math_cos cosf
#define Math_sin sinf
#define Math_acos acosf
#define Math_asin asinf
#define Math_atan atanf
#define Math_atan2 atan2f
#define Math_ceil ceilf
#define Math_exp expf
#define Math_fabs fabsf
#define Math_floor floorf
#define Math_fmod fmodf
#define Math_frexp frexpf
#define Math_ldexp ldexpf
#define Math_mod modff
#define Math_pow powf
#define Math_sqrt sqrtf
#define Math_tan tanf
#define Math_tanh tanhf
#define Math_hypot hypot
#endif /*  _USEPROTECTEDMATH*/

#define APA_TRAJCAL_GET_CAR_TURNING_RADIUS_CENTER(CarFRAxisLength, SteeringWheelAng)	\
	(((APA_DISTANCE_CAL_FLOAT_TYPE)(CarFRAxisLength)) / MATH_TAN(MATH_FABS(SteeringWheelAng)))
					
#define APA_TRAJCAL_GET_CAR_TURNING_RADIUS_FOuterCircle(LenBetweenFBumperAndRAxis, HalfWidthOfCar, CarCenterTurningRadius)	\
	(MATH_SQRT(((APA_DISTANCE_CAL_FLOAT_TYPE)(LenBetweenFBumperAndRAxis)) * ((APA_DISTANCE_CAL_FLOAT_TYPE)(LenBetweenFBumperAndRAxis)) \
	+ ((HalfWidthOfCar) + (CarCenterTurningRadius)) * ((HalfWidthOfCar) + (CarCenterTurningRadius))))
					
#define APA_TRAJCAL_GET_CAR_TURNING_RADIUS_FInnerCircle(LenBetweenFBumperAndRAxis, HalfWidthOfCar, CarCenterTurningRadius)	\
	(MATH_SQRT(((APA_DISTANCE_CAL_FLOAT_TYPE)(LenBetweenFBumperAndRAxis)) * ((APA_DISTANCE_CAL_FLOAT_TYPE)(LenBetweenFBumperAndRAxis)) \
	+ ((CarCenterTurningRadius) - (HalfWidthOfCar)) * ((CarCenterTurningRadius) - (HalfWidthOfCar))))
	
#define APA_TRAJCAL_GET_CAR_TURNING_RADIUS_ROuterCircle(LenBetweenRBumperAndRAxis, HalfWidthOfCar, CarCenterTurningRadius)	\
	(MATH_SQRT(((APA_DISTANCE_CAL_FLOAT_TYPE)(LenBetweenRBumperAndRAxis)) * (LenBetweenRBumperAndRAxis) \
	+ ((HalfWidthOfCar) + (CarCenterTurningRadius)) * ((HalfWidthOfCar) + ((APA_DISTANCE_CAL_FLOAT_TYPE)(CarCenterTurningRadius)))))
					
#define APA_TRAJCAL_GET_CAR_TURNING_RADIUS_RInnerCircle(LenBetweenRBumperAndRAxis, HalfWidthOfCar, CarCenterTurningRadius)	\
	(MATH_SQRT(((APA_DISTANCE_CAL_FLOAT_TYPE)(LenBetweenRBumperAndRAxis)) * ((APA_DISTANCE_CAL_FLOAT_TYPE)(LenBetweenRBumperAndRAxis)) \
	+ ((CarCenterTurningRadius) - (HalfWidthOfCar)) * ((CarCenterTurningRadius) - (HalfWidthOfCar))))
	
#define APA_TRAJCAL_GET_CAR_TURNING_RADIUS_SQUARE_FOuterCircle(LenBetweenFBumperAndRAxis, HalfWidthOfCar, CarCenterTurningRadius)	\
	(((APA_DISTANCE_CAL_FLOAT_TYPE)(LenBetweenFBumperAndRAxis)) * ((APA_DISTANCE_CAL_FLOAT_TYPE)(LenBetweenFBumperAndRAxis)) \
	+ ((HalfWidthOfCar) + (CarCenterTurningRadius)) * ((HalfWidthOfCar) + (CarCenterTurningRadius)))
					
#define APA_TRAJCAL_GET_CAR_TURNING_RADIUS_SQUARE_FInnerCircle(LenBetweenFBumperAndRAxis, HalfWidthOfCar, CarCenterTurningRadius)	\
	(((APA_DISTANCE_CAL_FLOAT_TYPE)(LenBetweenFBumperAndRAxis)) * ((APA_DISTANCE_CAL_FLOAT_TYPE)(LenBetweenFBumperAndRAxis)) \
	+ ((CarCenterTurningRadius) - (HalfWidthOfCar)) * ((CarCenterTurningRadius) - (HalfWidthOfCar)))
	
#define APA_TRAJCAL_GET_CAR_TURNING_RADIUS_SQUARE_ROuterCircle(LenBetweenRBumperAndRAxis, HalfWidthOfCar, CarCenterTurningRadius)	\
	(((APA_DISTANCE_CAL_FLOAT_TYPE)(LenBetweenRBumperAndRAxis)) * ((APA_DISTANCE_CAL_FLOAT_TYPE)(LenBetweenRBumperAndRAxis)) \
	+ ((HalfWidthOfCar) + (CarCenterTurningRadius)) * ((HalfWidthOfCar) + (CarCenterTurningRadius)))
					
#define APA_TRAJCAL_GET_CAR_TURNING_RADIUS_SQUARE_RInnerCircle(LenBetweenRBumperAndRAxis, HalfWidthOfCar, CarCenterTurningRadius)	\
	(((APA_DISTANCE_CAL_FLOAT_TYPE)(LenBetweenRBumperAndRAxis)) * ((APA_DISTANCE_CAL_FLOAT_TYPE)(LenBetweenRBumperAndRAxis)) \
	+ ((CarCenterTurningRadius) - (HalfWidthOfCar)) * ((CarCenterTurningRadius) - (HalfWidthOfCar)))

#define APA_TRAJCAL_CHECK_IF_CAR_IS_DRIVING_STRAIGHTLY(SteeringAng) \
	(MATH_FABS(SteeringAng) <= (APACal.APAParkProcCarDriveStraightlyMinSteeringWheelAng))

#define APA_TRAJCAL_CHECK_IF_CAR_IS_NOT_DRIVING_STRAIGHTLY(SteeringAng) \
	(MATH_FABS(SteeringAng) > (APACal.APAParkProcCarDriveStraightlyMinSteeringWheelAng))
	
#define APA_TRAJCAL_GET_CAR_STEERING_ANGLE_BY_TURNING_RADIUS(Radius, CarFRAxisLength)	\
	(MATH_ATAN(((APA_DISTANCE_CAL_FLOAT_TYPE)(CarFRAxisLength))/(Radius)))

#define APA_TRAJCAL_GET_CAR_STEERING_ANGLE_TAN_BY_TURNING_RADIUS(Radius, CarFRAxisLength)	\
	(((APA_DISTANCE_CAL_FLOAT_TYPE)(CarFRAxisLength))/(Radius))

/*************************************************************************************************************************************************
**                                                              Global Inline Function Definitions                                              **
*************************************************************************************************************************************************/


/*************************************************************************************************************************************************
**                                                              End of file                                                                     **
*************************************************************************************************************************************************/

#endif /* APACOMMONFUNCTIONS_H_ */

