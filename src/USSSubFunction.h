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
**  $FILENAME   : USSSubFunction.h $                                                                                                            **
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
**                - USS sub function declarations                          ..                                                                   **
**                                                                                                                                              **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                                                                                        **
**                                                                                                                                              **
*************************************************************************************************************************************************/
#ifndef USSSUBFUNCTION_H_
#define USSSUBFUNCTION_H_


/*************************************************************************************************************************************************
**                                                              Includes                                                                        **
*************************************************************************************************************************************************/
#include "Platform_Types.h"
#include "APACommonType.h"
#include <math.h>

/*************************************************************************************************************************************************
**                                                             Debug Switch                                                                     **
*************************************************************************************************************************************************/
#define Debug_SW_SmallObstacle               0
#define Debug_SW_ExeTimeTest                 0
#define Debug_SW_VSlotCurb                   0
#define Debug_SW_PARKINFUNC                  0
#define Debug_SW_COUNTLOOP                   0
#define Debug_SW_SendParasOutOnceEdgePtUpd   0
#define Debug_SW_InforCANOutput              0

#define Debug_SW_PrivateCANForIntegration    0
#define Debug_SW_PrivateCANForUSS            0

#define SPLITTASK                            1
#define YDevationCompeFunc_EdgeY             0
#define YDevationCompeFunc_FindMinDis        1
#define TransCoordinateStepSwitch            0

/*************************************************************************************************************************************************
**                                                              Global Macro Definitions                                                        **
*************************************************************************************************************************************************/
#define OFF                   0x0
#define ON                    0x1
#define PARKIN                0x1
#define SCAN                  0x2
#define USS_OFF               0x0
#define USS_ON                0x1
#define NOUPDATE              0x0
#define UPDATE                0x1
#define SLOT_UPDATE           0x1
#define CURB_UPDATE           0x2
#define RIGHT                 0x0
#define LEFT                  0x1
#define DEFAULT               0x0
#define PARA                  0x1
#define PERP                  0x2
#define SLASH                 0x3
#define UNKNOWN_SLOTTYPE      0x4
#define VIRTUAL               0x0
#define UNVIRTUAL             0x1
#define INVALID               0x0
#define VALID                 0x1
#define NEWSLOT               0x1
#define VIRTUALSLOT           0x2
#define USS_COORD             0x1
#define SLOT_COORD            0x2
#define SLOT_LEFT             0x1
#define SLOT_RIGHT            0x2
#define SLOT_FUSION           0x1
#define SLOT_USS              0x2
#define SLOT_PLD              0x3
#define UNKNOWN_OBJTYPE       0x0
#define DEFAULT               0x0
#define WAITSIFCONFIRM        0x1
#define EDGETYPE_VISUAL       -1
#define EDGETYPE_0            0
#define EDGETYPE_1            1

#define EDGETYPEDEFAULT       0X00
#define EDGE0ISVIRTUAL        0X01
#define EDGE1ISVIRTUAL        0X02
#define EDGE0_1_ISREAL        0X03

#define ResetCoordinateAng          30  /*xsj ��������ϵ�ĽǶ���ֵ����λΪ�� */
#define ResetCoordinateDeltaAng     0.2 /* xsj ��������ϵ�ĽǶȲ���ֵ����λΪ��*/
#define ResetCoordinateDisX         20000  /*  ��������ϵʱX����ĵľ�����ֵ����λΪmm */
#define ResetCoordinateDisY         20000  /*  ��������ϵʱY����ĵľ�����ֵ����λΪmm */
#define ResetCoordinateDeltaDis     100  /* ��������ϵʱ�ľ������ֵ����λΪmm*/
#define OBJCALPOINTNUM              8
#define POSXCOMPTABLESIZE_DISTANCE  3
#define PERPOSTCOMPTABLESIZE_DISTANCE 4 /* ��ֱ��λ�����벹��ʱ�Ķ���*/
#define POSXCOMPTABLESIZE_SPEED     4
#define INFLECTPTNUM                30
#define MINNUMINSUBFUNCTION         -999999.0
#define EDGETHRESHHOLD              1500 /*�ǵ�x����Ƚϣ�С�ڸ�ֵ����Ϊͬһ�ǵ㣬��λΪmm*/
#define VIRTUALSLOTLENGTH           7200 /*���⳵λ������ֵ����λmm*/
/*************************************************************************************************************************************************
**                                                              Global Type Definitions                                                         **
*************************************************************************************************************************************************/
typedef struct
{
	sint32 SlotStartInd_CarPos_X;
    sint32 SlotStartInd_CarPos_Y;
    sint32 SlotEndInd_CarPos_X;
    sint32 SlotEndInd_CarPos_Y;
    sint32 SlotStartInd_PtPos_X;
    sint32 SlotStartInd_PtPos_Y;
    sint32 SlotEndInd_PtPos_X;
    sint32 SlotEndInd_PtPos_Y;
    sint16 SlotPar_SlotCalDisCarToObj1;
    sint16 SlotPar_SlotCalDisCarToObj2;
    sint8 SlotPar_Type;
    sint8 SlotPar_Obj1EndPtIndex;
    sint8 SlotPar_Obj1StartPtIndex;
    sint8 SlotPar_Obj1Type;
    sint8 SlotPar_Obj2Type;
    sint8 SlotPar_Obj2EndPtIndex;
    sint8 SlotPar_Obj2StartPtIndex;
    sint8 SlotPar_SlotEndIndex;
    sint8 SlotPar_SlotStartIndex;
    sint16 SlotPar_SlotCompeHead;
    sint16 SlotPar_SlotCompeTail;
    sint16 SlotPar_SlotDepth;
    sint16 SlotPar_SlotLengthTotal;
	APA_DISTANCE_TYPE CarPassTheSlotEndPtDistance;
	APA_ENUM_TYPE ObjPtCnt; 
}SlotInfoTemp_ST;

/*************************************************************************************************************************************************
**                                                              Global Constant Declarations                                                    **
*************************************************************************************************************************************************/

/*************************************************************************************************************************************************
**                                                              Global Variable Declarations                                                    **
*************************************************************************************************************************************************/
extern uint8 u8SideSensorUpdateBackupFlag;
extern uint8 TransCoordinateStep;
extern APACoordinateDataCalFloatType CenterPtBackup1;
extern APA_ANGLE_CAL_FLOAT_TYPE CenterAngBackup1;
extern APA_ANGLE_CAL_FLOAT_TYPE CenterAngBackup3ForOIC;
extern APACoordinateDataCalFloatType CenterPtBackup3ForOIC;
extern uint8 u8OIC_DataHandleSW;
extern APACarCoordinateDataCalFloatType CarPtForTransStep[5];
extern APA_SPEED_TYPE CarSpeedForTransStep[5];
extern uint8 RealTimeDRUpdateFlag;
extern SlotInfoTemp_ST SlotInfoToOutput[2];
/*************************************************************************************************************************************************
**                                                              Global Function Declarations                                                    **
*************************************************************************************************************************************************/
APACoordinateDataCalFloatType USS_CoordTransforToDR(APACoordinateDataType ToBeTransforPtBaseCurrentCoord,
                                                    APA_ANGLE_TYPE Angle,
                                                    APACoordinateDataCalFloatType CenterPtBackup);
void USS_ModeCheck(void);
void USS_DataHandle(void);

#if Debug_SW_InforCANOutput
void SendUSSOutput(uint8 UpdateFlag);
void SendRealTimeDROut(void);
#endif

#if Debug_SW_PrivateCANForIntegration
void SendCanInfoOutForIntegration(void);
#endif
#if Debug_SW_PrivateCANForUSS
void SendCanInfoOutForUss(void);
#endif
/*************************************************************************************************************************************************
**                                                              Global Inline Function Definitions                                              **
*************************************************************************************************************************************************/


/*************************************************************************************************************************************************
**                                                              End of file                                                                     **
*************************************************************************************************************************************************/

#endif /* USSSUBFUNCTION_H_ */

