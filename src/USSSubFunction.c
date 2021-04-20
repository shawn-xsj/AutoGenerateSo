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
**  $FILENAME   : USSSubFunction.c $                                                                                                            **
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
**                - USS sub function                           ..                                                                               **
**                                                                                                                                              **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                                                                                        **
**                                                                                                                                              **
*************************************************************************************************************************************************/

/*************************************************************************************************************************************************
**                                                     Includes
*************************************************************************************************************************************************/
#include "USSSubFunction.h"
#include "SlotProcess.h"
#include "SlotProcessSubFunction.h"
#include "USS.h"
#include "SIF.h"
#include "US_Driver.h"
#include "APACommonFunctions.h"
#include "APACalibration.h"
#include "DR.h"
#include "can_net_com_CAN3.h"
#include <stdio.h>
// #include "APAFLGlobalSignal.h"


/*************************************************************************************************************************************************
**                                                     Imported Compiler Switch Check                                                           **
*************************************************************************************************************************************************/
/**/

/*************************************************************************************************************************************************
**                                                     Private Macro Definitions                                                                **
*************************************************************************************************************************************************/
/**/

/*************************************************************************************************************************************************
**                                                     Private Type Definitions                                                                 **
*************************************************************************************************************************************************/
/**/

/*************************************************************************************************************************************************
**                                                     Private  Constant Definitions                                                            **
*************************************************************************************************************************************************/

#define ALG_START_SEC_CONST_32BIT
#include "IS31_UserMemMap.h"

// 20201114�� ���ݲɼ�ʱ��������ֵ�ر�
/* ˮƽ��λ����ֵ */
APA_DISTANCE_TYPE const EdgePosxCompTable_Distance[3] = {1000,1500,1750};
APA_SPEED_TYPE const EdgePosxCompTable_Speed[4] = {7.5,12.5,17.25,22.5};
APA_DISTANCE_TYPE const Edge0CompTablePosX[3][4] =
{
   {100,400,300,300}, //<1m
  {-50,-100,-100,-100}, //1~1.5m
  {-150,-200,-200,-200}, //>1.5m
};

APA_DISTANCE_TYPE const Edge1CompTablePosX[3][4] =
{
	{250,0,0,0}, //<1m
  {500,300,300,300}, //1~1.5m
  {620,400,400,400}, //>1.5m
};

/* ��ֱ��λ����ֵ */
APA_DISTANCE_TYPE const PerPostCompTableEdge0X_Distance[4] = {1270,1690,1850,2000};
APA_SPEED_TYPE const PerPostCompTableEdge0X_Speed[4] = {0,0,0,0};
APA_DISTANCE_TYPE const PerPostCompTableEdge0PosX[4][4] =
{
    {145,145,145,145},      //<1270
	{200,200,200,200},   //1270~1690
	{120,120,120,120},   //1690~2000
    {220,220,220,220},   //1690~2000
};


APA_DISTANCE_TYPE const PerPostCompTableEdge1X_Distance[4] = {860,1100,1700,2000};
APA_SPEED_TYPE const PerPostCompTableEdge1X_Speed[4] = {0,0,0,0};
APA_DISTANCE_TYPE const PerPostCompTableEdge1PosX[4][4] =
{
    {450,450,450,450},      //<1270
	{650,650,650,650},   //1270~1690
	{750,750,750,750},   //1690~2000
    {800,800,800,800},   //1690~2000
};

#define ALG_STOP_SEC_CONST_32BIT
#include "IS31_UserMemMap.h"
/*************************************************************************************************************************************************
**                                                     Private  Variable Definitions                                                            **
*************************************************************************************************************************************************/
#define ALG_START_SEC_VAR_32BIT
#include "IS31_UserMemMap.h"

uint8 u8USS_DataHandleSW = 0;
uint8 u8USS_OnStates = 0u;
uint8 LeftOrRight = 0;/* ����ı�����1��ת����߿�λ����ϵ�� 2��ת���ұ߿�λ����ϵ*/

APACoordinateDataCalFloatType SlotCoordinatePoint = {0.0, 0.0};  /* ��λ����ϵԭ����DR����ϵ�µ�����*/
APA_ANGLE_CAL_FLOAT_TYPE SlotCoordinateAng = 0.0;         /* ��λ����ϵ��DR����ϵ�ļн� */
APACoordinateDataCalFloatType TransCenterPt = {0.0, 0.0};
APACoordinateDataCalFloatType CenterPtBackup1 = {0.0, 0.0};
APA_ANGLE_CAL_FLOAT_TYPE TransCenterAng = 0.0;
APA_ANGLE_CAL_FLOAT_TYPE CenterAngBackup1 = 0.0;
static uint8 u8USS_USlotUpdateFlag[2] = {0};
static uint8 u8USS_UCurbUpdateFlag[2] = {0};
static uint8 u8SlotNumBackup[2] = { 0u };
static uint8 USSResetHistory = 0;
static uint8 SendOutLeftOrRight = 0;       /* Can ���ݷ�����߻����ұߵ����ݣ� 0: Ĭ��ֵ���ұߣ� 1�� ���  */
static uint8 SendOutHistory = 0;
static uint8 ResetTypeFlag = 0;            /* ����ϵ���õ����ͣ�0�������ã� 1�����õ�USS���������ϵ�� 2�����õ���λ����ϵ  */
static APA_SLOT_ID_TYPE s16VirtualSlotIDBackup[2] = { 0};
static APA_SLOT_ID_TYPE s16NewSlotIDBackup[2] = {0};
static APACoordinateDataType EdgePtBaseUSSCoordTemp0 = {0.0, 0.0},  EdgePtBaseUSSCoordTemp1 = {0.0, 0.0};
APA_ANGLE_CAL_FLOAT_TYPE CenterAngBackup2 = 0.0, CenterAngBackup3 = 0.0;
APACoordinateDataCalFloatType  CenterPtBackup2 = {0.0, 0.0},CenterPtBackup3 = {0.0, 0.0};
static APACarCoordinateDataCalFloatType CarPosCoordBackup = {0.0, 0.0};  //���뱸�ݣ�����ʹ�����뱸�ݵ�ȫ�ֶ���
APACoordinateDataCalFloatType Edge0BkInUSS[2] = {{MINNUMINSUBFUNCTION,MINNUMINSUBFUNCTION}, {MINNUMINSUBFUNCTION,MINNUMINSUBFUNCTION}};
APACoordinateDataCalFloatType Edge1BkInUSS[2] = {{MINNUMINSUBFUNCTION,MINNUMINSUBFUNCTION}, {MINNUMINSUBFUNCTION,MINNUMINSUBFUNCTION}};
APA_ANGLE_TYPE AngleBK[2] = {0,0};
uint8 EdgeTypeBk[2] = {EDGETYPEDEFAULT,EDGETYPEDEFAULT}; /*0��Ĭ��ֵ��1��edge0���⣬ 2��edge1���� 3����ʵ��λ*/
// APA_SLOT_ID_TYPE SlotIDBK[2] = {0,0};

static uint8 IsTransing = 1;  // ����ת���Ƿ���ɣ� 0�����ڽ�������ת���� 1��ת����ɣ�
SlotInfoTemp_ST SlotInfoToOutput[2];
// static uint8 LastTransStepSlotIndex = 0;
// static APA_INDEX_TYPE LastTransStepPtIndex = 0;
static uint8 HaveBeenTransCount = 0;
static uint8 HaveBeenTransCountCache2 = 0;
// static uint8 PtNumNeedToBeTrans = 0;
// static uint8 OneStepTransPtNum = 0;
APA_ANGLE_CAL_FLOAT_TYPE CenterAngBackup3ForOIC = 0.0;
APACoordinateDataCalFloatType CenterPtBackup3ForOIC = {0.0, 0.0};
uint8 RealTimeDRUpdateFlag = 0;
#if Debug_SW_PrivateCANForIntegration
static uint8 Test_RC_31 = 0;
static uint8 Test_RC_32 = 0;
static uint8 Test_RC_33 = 0;
static uint8 Test_RC_34 = 0;
static uint8 Test_RC_35 = 0;
#endif

#define ALG_STOP_SEC_VAR_32BIT
#include "IS31_UserMemMap.h"
/*************************************************************************************************************************************************
**                                                     Global Constant Definitions                                                              **
*************************************************************************************************************************************************/
/**/

/*************************************************************************************************************************************************
**                                                     Global Variable Definitions                                                              **
*************************************************************************************************************************************************/
#define ALG_START_SEC_VAR_32BIT
#include "IS31_UserMemMap.h"

uint8 u8SideSensorUpdateBackupFlag = 0;
uint8 TransCoordinateStep = 0;
APACarCoordinateDataCalFloatType CarPtForTransStep[5];
APA_SPEED_TYPE CarSpeedForTransStep[5];
uint8 u8OIC_DataHandleSW = 0;
#define ALG_STOP_SEC_VAR_32BIT
#include "IS31_UserMemMap.h"
/*************************************************************************************************************************************************
**                                                     Private Function Declarations                                                            **
*************************************************************************************************************************************************/
#define ALG_START_SEC_CODE
#include "IS31_UserMemMap.h"

APA_DISTANCE_TYPE GetSlotEdgeCompensateValuePosX(sint8 EdgeType, APA_DISTANCE_TYPE DistanceAtPassEdge, APA_SPEED_TYPE SpdAtPassEdge);
void USSCheckSlotDepth(uint8 u8SlotSide,
                       uint8 u8SlotNumCur,  
                       APA_DISTANCE_TYPE *SlotDepthFromUSS,
                       APA_INDEX_TYPE *CurbStartIndex,
                       APA_INDEX_TYPE *CurbEndIndex); //xsj 20210305 for  so

/*************************************************************************************************************************************************
** Syntax : APA_DISTANCE_TYPE GetParaSlotPostCompensateValuePosX(sint8 EdgeType, APA_DISTANCE_TYPE DistanceAtPassEdge, APA_SPEED_TYPE SpdAtPassEdge)**
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
** Description : ��ȡtask�����Ľ����������USS��������(ģ�����������u8USS_OnStates)������ǻ���DR����ϵ                                            **
*************************************************************************************************************************************************/
APA_DISTANCE_TYPE GetSlotCompensateValuePosXNew(sint8 EdgeType, uint8 u8SlotSideTemp, sint8 u8SlotNumTemp, APA_DISTANCE_TYPE DistanceAtPassEdge, uint8 *SlotTypePt, APA_SPEED_TYPE SpdAtPassEdge)
{
	uint8 u8DistanceIndex = 0;
	uint8 u8SpdIndex = 0;
	APA_DISTANCE_TYPE EdgeCompValue = 0;
    APA_DISTANCE_TYPE  SlotLengthTemp, SlotDepthTemp;
    APA_INDEX_TYPE CurbStartIndexTemp = 0;
    APA_INDEX_TYPE CurbEndIndexTemp = 0;
    APA_INDEX_TYPE  Obj1StartIndexTemp, Obj1EndIndexTemp, Obj2StartIndexTemp, Obj2EndIndexTemp;
    APA_DISTANCE_TYPE Obj1WidthTemp, Obj2WidthTemp;
    APA_DISTANCE_TYPE Obj1StartCarX, Obj1StartCarY,Obj2StartCarX, Obj2StartCarY;
    APA_DISTANCE_TYPE Obj1EndCarX, Obj1EndCarY,Obj2EndCarX, Obj2EndCarY;
/* У�˳�λ���� */
    SlotLengthTemp = USSPar.Slot[u8SlotSideTemp].SlotPar[u8SlotNumTemp - 1].SlotLengthTotal;
    if(SlotLengthTemp < 2500)
    {
        return 0;
    }
    SlotDepthTemp = USSPar.Slot[u8SlotSideTemp].SlotPar[u8SlotNumTemp-1].SlotDepth;

    if (SlotDepthTemp != NO_OBJ_DISTANCE)
    {

    }
    else
    {
        USSCheckSlotDepth(u8SlotSideTemp,u8SlotNumTemp,&SlotDepthTemp,&CurbStartIndexTemp,&CurbEndIndexTemp);
    }
    if(SlotDepthTemp > 3800)  /* ��ֱ��λ */
    {
        
        Obj1StartIndexTemp = USSPar.Slot[u8SlotSideTemp].SlotPar[u8SlotNumTemp - 1].Obj1StartPtIndex;
        Obj1EndIndexTemp = USSPar.Slot[u8SlotSideTemp].SlotPar[u8SlotNumTemp - 1].Obj1EndPtIndex;
        Obj2StartIndexTemp = USSPar.Slot[u8SlotSideTemp].SlotPar[u8SlotNumTemp - 1].Obj2StartPtIndex;
        Obj2EndIndexTemp = USSPar.Slot[u8SlotSideTemp].SlotPar[u8SlotNumTemp - 1].Obj2EndPtIndex;
        if(Obj1StartIndexTemp >=0 && Obj1EndIndexTemp >=0 && Obj2StartIndexTemp>=0 && Obj2EndIndexTemp >=0 && Obj1StartIndexTemp > Obj1EndIndexTemp && Obj2EndIndexTemp > Obj2StartIndexTemp)
        {
            Obj1StartCarX =  USSPar.Slot[u8SlotSideTemp].SlotOutline.Lane.CarCenterPoint[Obj1StartIndexTemp].x;
            Obj1StartCarY =  USSPar.Slot[u8SlotSideTemp].SlotOutline.Lane.CarCenterPoint[Obj1StartIndexTemp].y;
            Obj1EndCarX =  USSPar.Slot[u8SlotSideTemp].SlotOutline.Lane.CarCenterPoint[Obj1EndIndexTemp].x;
            Obj1EndCarY =  USSPar.Slot[u8SlotSideTemp].SlotOutline.Lane.CarCenterPoint[Obj1EndIndexTemp].y;
            Obj2StartCarX =  USSPar.Slot[u8SlotSideTemp].SlotOutline.Lane.CarCenterPoint[Obj2StartIndexTemp].x;
            Obj2StartCarY =  USSPar.Slot[u8SlotSideTemp].SlotOutline.Lane.CarCenterPoint[Obj2StartIndexTemp].y;
            Obj2EndCarX =  USSPar.Slot[u8SlotSideTemp].SlotOutline.Lane.CarCenterPoint[Obj2EndIndexTemp].x;
            Obj2EndCarY =  USSPar.Slot[u8SlotSideTemp].SlotOutline.Lane.CarCenterPoint[Obj2EndIndexTemp].y;
            Obj1WidthTemp = APATrajCalGetTwoPointDisInt(Obj1StartCarX, Obj1StartCarY, Obj1EndCarX, Obj1EndCarY);
            Obj2WidthTemp = APATrajCalGetTwoPointDisInt(Obj2StartCarX, Obj2StartCarY, Obj2EndCarX, Obj2EndCarY);
        }
        else
        {
            Obj1WidthTemp = 0;
            Obj2WidthTemp = 0;
        }
          
//        if(SlotLengthTemp > (APACal.LengthOfCar + 300) && (Obj1WidthTemp > 3500 || Obj2WidthTemp > 3500))
//        {
//             *SlotTypePt = PARA;
//        }
        if (SlotLengthTemp > (APACal.LengthOfCar + 300))
        {
            *SlotTypePt = UNKNOWN_SLOTTYPE;
        }
        else if (SlotLengthTemp > (APACal.WidthOfCar + 300))
        {
            *SlotTypePt = PERP;
        }
        else
        {
            /* code */
        }
    }
    else if (SlotLengthTemp>(APACal.LengthOfCar + 300))
    {
        *SlotTypePt = PARA;
    }
    else
    {
    }
            
	if(EdgeType == -1)
	{
	}
	else
	{
        if(*SlotTypePt == PARA)   /* ��ˮƽ��λ����*/
        {
            for(u8DistanceIndex= 0;u8DistanceIndex < POSXCOMPTABLESIZE_DISTANCE;u8DistanceIndex++)
		    {
                if(DistanceAtPassEdge < EdgePosxCompTable_Distance[u8DistanceIndex])
                {
                    break;
                }
		    }
            if(u8DistanceIndex ==POSXCOMPTABLESIZE_DISTANCE)
            {
                u8DistanceIndex = POSXCOMPTABLESIZE_DISTANCE-1;
            }

            // for(u8SpdIndex= 0;u8SpdIndex < EdgePosxCompTable_Speed;u8SpdIndex++)
            for(u8SpdIndex= 0;u8SpdIndex < 4;u8SpdIndex++)
            {
                if(SpdAtPassEdge < EdgePosxCompTable_Speed[u8SpdIndex])
                {
                    break;
                }
            }
            if(u8SpdIndex ==POSXCOMPTABLESIZE_SPEED)
            {
                u8SpdIndex = POSXCOMPTABLESIZE_SPEED-1;
            }
                
            if(EdgeType == 0)
            {
                EdgeCompValue = Edge0CompTablePosX[u8DistanceIndex][u8SpdIndex];
            }
            else if(EdgeType == 1)
            {
                EdgeCompValue = Edge1CompTablePosX[u8DistanceIndex][u8SpdIndex];
            }
            else
            {

            }
        }
        else if(*SlotTypePt == PERP || *SlotTypePt == UNKNOWN_SLOTTYPE)  /* ����ֱ��λ���� */
        {
            for(u8DistanceIndex= 0;u8DistanceIndex < PERPOSTCOMPTABLESIZE_DISTANCE;u8DistanceIndex++)
            {
                if(EdgeType == 0)
                {
                    if(DistanceAtPassEdge < PerPostCompTableEdge0X_Distance[u8DistanceIndex])
                    {
                        break;
                    }
                }
                else
                {
                    if(DistanceAtPassEdge < PerPostCompTableEdge1X_Distance[u8DistanceIndex])
                    {
                        break;
                    }
                }
    	
            }
            if(u8DistanceIndex == PERPOSTCOMPTABLESIZE_DISTANCE)
            {
                u8DistanceIndex = PERPOSTCOMPTABLESIZE_DISTANCE-1;
            }   
            for(u8SpdIndex= 0;u8SpdIndex < POSXCOMPTABLESIZE_SPEED;u8SpdIndex++)
            {
                if(EdgeType == 0)
                {
                    if(SpdAtPassEdge < PerPostCompTableEdge0X_Speed[u8SpdIndex])
                    {
                        break;
                    }
                }
                else
                {
                    if(SpdAtPassEdge <= PerPostCompTableEdge1X_Speed[u8SpdIndex])
                    {
                        break;
                    }
                }
                
            }
            if(u8SpdIndex ==POSXCOMPTABLESIZE_SPEED)
            {
                u8SpdIndex = POSXCOMPTABLESIZE_SPEED-1;
            }

            if(EdgeType == 0)
            {
                EdgeCompValue = PerPostCompTableEdge0PosX[u8DistanceIndex][u8SpdIndex];
            }
            else
            {
                EdgeCompValue = PerPostCompTableEdge1PosX[u8DistanceIndex][u8SpdIndex];

            }
        }
        else
        {
        }
                
    }
	return EdgeCompValue;
}
/*************************************************************************************************************************************************
** Syntax :  uint8 * DataTypeConvertFloatToInt(float InputData)                                                                                 **
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
uint8 * DataTypeConvertFloatToInt(float InputData)
{
    static uint8 Result[4];
    sint32 a = 0;

    a = (int)InputData;
    Result[3] = ((a&0xFF000000)>>24);
    Result[2] = ((a&0x00FF0000)>>16);
    Result[1] = ((a&0x0000FF00)>>8);
    Result[0] = ((a&0x000000FF)>>0);

    return  Result;
}

/*************************************************************************************************************************************************
** Syntax :  void ResetSystemCoordinateUSS(void)                                                                                                **
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
void ResetCoordinateNew(APACoordinateDataCalFloatType CenterPtIn, APA_ANGLE_CAL_FLOAT_TYPE CarAngleIn, uint8 LeftOrRightTem)
{
    APA_INDEX_TYPE i, j, ObjCnt, SnsIndex;
    APACoordinateDataCalFloatType CenterPt, DstPt, CarCoor;
    APA_ANGLE_TYPE CarAng, NewCarAng;
    APACoordinateDataType nPtTemp, nCarCoor;
    APA_DISTANCE_TYPE CarCenterPtDefY;
    APA_DISTANCE_CAL_FLOAT_TYPE fCarCenterPtDefY;
    BOOLEAN bSDGAPASlotDataIsMirrorChange;
    float CosAng = 0;
    float SinAng = 0;


    CenterPt = CenterPtIn; /*xsj ԭ����ϵԭ����������ϵ�е����� */
    CarAng = CarAngleIn; /*xsj ԭ����ϵ��������ϵ֮��ļнǣ� */

    CosAng = MATH_COS(CarAngleIn);
    SinAng = MATH_SIN(CarAngleIn);

    if(LeftOrRightTem == 0 || LeftOrRightTem ==2)
    {
    /* xsj �������� */
        for(j = 0; j < APA_SIDE_SENSOR_NUM; j++)
        {
            for(i = 0; i < APASnsDtdObjPtBuf[j].WrIndex; i ++)
            {

                DstPt.x = APASnsDtdObjPtBuf[j].ObjPtBuf[i].CarPos.Coordinate.x;
                DstPt.y = APASnsDtdObjPtBuf[j].ObjPtBuf[i].CarPos.Coordinate.y;
                APASnsDtdObjPtBuf[j].ObjPtBuf[i].CarPos.Coordinate.x = (APA_DISTANCE_TYPE)(DstPt.x * CosAng - DstPt.y * SinAng + CenterPt.x);
                APASnsDtdObjPtBuf[j].ObjPtBuf[i].CarPos.Coordinate.y = (APA_DISTANCE_TYPE)(DstPt.x * SinAng + DstPt.y * CosAng + CenterPt.y);
                APASnsDtdObjPtBuf[j].ObjPtBuf[i].CarPos.CarAng = APASnsDtdObjPtBuf[j].ObjPtBuf[i].CarPos.CarAng + CarAng;
            }
        }

    /* xsj �������� */
        for(j = 0; j < APA_SLOT_SUPPORT_SEARCHING_SLOT_SENSOR_NUM; j++) 
        {
            for(i = 0; i < USSPar.Slot[j].SlotOutline.Lane.ObjPtCnt; i ++) 
            {
                DstPt.x = USSPar.Slot[j].SlotOutline.Lane.CarCenterPoint[i].x;
                DstPt.y = USSPar.Slot[j].SlotOutline.Lane.CarCenterPoint[i].y;

                USSPar.Slot[j].SlotOutline.Lane.CarCenterPoint[i].x = (APA_DISTANCE_TYPE)(DstPt.x * CosAng - DstPt.y * SinAng + CenterPt.x);
                USSPar.Slot[j].SlotOutline.Lane.CarCenterPoint[i].y = (APA_DISTANCE_TYPE)(DstPt.x * SinAng + DstPt.y * CosAng + CenterPt.y);
                USSPar.Slot[j].SlotOutline.Lane.CarAng[i] = USSPar.Slot[j].SlotOutline.Lane.CarAng[i] + CarAng;

                DstPt.x = USSPar.Slot[j].SlotOutline.Lane.ObjPt[i].x;
                DstPt.y = USSPar.Slot[j].SlotOutline.Lane.ObjPt[i].y;

               
                USSPar.Slot[j].SlotOutline.Lane.ObjPt[i].x =  (APA_DISTANCE_TYPE)(DstPt.x * CosAng - DstPt.y * SinAng + CenterPt.x);
                USSPar.Slot[j].SlotOutline.Lane.ObjPt[i].y = (APA_DISTANCE_TYPE)(DstPt.x * SinAng + DstPt.y * CosAng + CenterPt.y);
            }        
        }

        if ((MATH_FABS(Edge0BkInUSS[0].x - MINNUMINSUBFUNCTION) > 0.01))/*�����MINNUMINSUBFUNCTION�Ͳ�ת*/
        {
            DstPt.x = Edge0BkInUSS[0].x;
            DstPt.y = Edge0BkInUSS[0].y;
            Edge0BkInUSS[0].x = DstPt.x * CosAng - DstPt.y * SinAng + CenterPt.x;
            Edge0BkInUSS[0].y = DstPt.x * SinAng + DstPt.y * CosAng + CenterPt.y;

            DstPt.x = Edge1BkInUSS[0].x;
            DstPt.y = Edge1BkInUSS[0].y;
            Edge1BkInUSS[0].x = DstPt.x * CosAng - DstPt.y * SinAng + CenterPt.x;
            Edge1BkInUSS[0].y = DstPt.x * SinAng + DstPt.y * CosAng + CenterPt.y;           
        }
        if ((MATH_FABS(Edge0BkInUSS[1].x - MINNUMINSUBFUNCTION) > 0.01))/*�����MINNUMINSUBFUNCTION�Ͳ�ת*/
        {
            DstPt.x = Edge0BkInUSS[1].x;
            DstPt.y = Edge0BkInUSS[1].y;
            Edge0BkInUSS[1].x = DstPt.x * CosAng - DstPt.y * SinAng + CenterPt.x;
            Edge0BkInUSS[1].y =  DstPt.x * SinAng + DstPt.y * CosAng + CenterPt.y;

            DstPt.x = Edge1BkInUSS[1].x;
            DstPt.y = Edge1BkInUSS[1].y;
            Edge1BkInUSS[1].x = DstPt.x * CosAng - DstPt.y * SinAng + CenterPt.x;
            Edge1BkInUSS[1].y = DstPt.x * SinAng + DstPt.y * CosAng + CenterPt.y;
        }
        CarCenterPtBackUp.Coordinate.x = CarCenterPtBackUp.Coordinate.x * CosAng -  CarCenterPtBackUp.Coordinate.y * SinAng + CenterPt.x;
        CarCenterPtBackUp.Coordinate.y = CarCenterPtBackUp.Coordinate.x * SinAng + CarCenterPtBackUp.Coordinate.y * CosAng + CenterPt.y;

        

    }
    else if(LeftOrRightTem == 1)
    {    /* TBD ת���м��������ϵ����η�ת����Ҫ����������ϵ�� */

    /* xsj �������� */
        for(j = 0; j < APA_SIDE_SENSOR_NUM; j++)
        {
            for(i = 0; i < APASnsDtdObjPtBuf[j].WrIndex; i ++)
            {
                DstPt.x = APASnsDtdObjPtBuf[j].ObjPtBuf[i].CarPos.Coordinate.x;
                DstPt.y = APASnsDtdObjPtBuf[j].ObjPtBuf[i].CarPos.Coordinate.y;
                APASnsDtdObjPtBuf[j].ObjPtBuf[i].CarPos.Coordinate.x = (APA_DISTANCE_TYPE)(DstPt.x * CosAng - DstPt.y * SinAng + CenterPt.x);
                APASnsDtdObjPtBuf[j].ObjPtBuf[i].CarPos.Coordinate.y = (APA_DISTANCE_TYPE)(DstPt.x * SinAng + DstPt.y * CosAng + CenterPt.y);
                APASnsDtdObjPtBuf[j].ObjPtBuf[i].CarPos.CarAng = APASnsDtdObjPtBuf[j].ObjPtBuf[i].CarPos.CarAng + CarAng;
            }
        }
        /* xsj �������� */
        for(j = 0; j < APA_SLOT_SUPPORT_SEARCHING_SLOT_SENSOR_NUM; j++)
        {
            for(i = 0; i < USSPar.Slot[j].SlotOutline.Lane.ObjPtCnt; i ++) 
            {
                DstPt.x = USSPar.Slot[j].SlotOutline.Lane.CarCenterPoint[i].x;
                DstPt.y = USSPar.Slot[j].SlotOutline.Lane.CarCenterPoint[i].y;

                USSPar.Slot[j].SlotOutline.Lane.CarCenterPoint[i].x = (APA_DISTANCE_TYPE)(DstPt.x * CosAng - DstPt.y * SinAng + CenterPt.x);
                USSPar.Slot[j].SlotOutline.Lane.CarCenterPoint[i].y = (APA_DISTANCE_TYPE)(DstPt.x * SinAng + DstPt.y * CosAng + CenterPt.y);
                USSPar.Slot[j].SlotOutline.Lane.CarAng[i] = USSPar.Slot[j].SlotOutline.Lane.CarAng[i] + CarAng;

                DstPt.x = USSPar.Slot[j].SlotOutline.Lane.ObjPt[i].x;
                DstPt.y = USSPar.Slot[j].SlotOutline.Lane.ObjPt[i].y;

                USSPar.Slot[j].SlotOutline.Lane.ObjPt[i].x = (APA_DISTANCE_TYPE)(DstPt.x * CosAng - DstPt.y * SinAng + CenterPt.x);
                USSPar.Slot[j].SlotOutline.Lane.ObjPt[i].y = (APA_DISTANCE_TYPE)(DstPt.x * SinAng + DstPt.y * CosAng + CenterPt.y);
            }
        }
    }
}

/*************************************************************************************************************************************************
** Syntax :  void TransCoordinate(uint8 ResetTypeFlag)                                                                                          **
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
 void TransCoordinate(uint8 ResetTypeFlag) 
 {
	 APACoordinateDataCalFloatType  DstPtTem, CenterPtTem;
	 APA_ANGLE_CAL_FLOAT_TYPE TransCurrentCarAngInUSS,  CarAngTem, CurrentCarAngInNewCoordinate;
	 APACoordinateDataCalFloatType TransCurrentPtInUSS;
	 signed int xTem, yTem;
	 APACoordinateDataCalFloatType  CurrentPtInNewCoordinate;
//	 static float DeltaAng;
//	 static float DeltaDisX;
//	 static float DeltaDisY;

	 xTem =  -gDR_stOut.gDR_s32VehPosYMM;
	 yTem =  gDR_stOut.gDR_s32VehPosXMM;
	 TransCurrentPtInUSS.x =  (float)xTem;
	 TransCurrentPtInUSS.y =  (float)yTem;
	 TransCurrentCarAngInUSS = gDR_stOut.gDR_f32VehPosARad;
	 CurrentPtInNewCoordinate = APATrajCalPointPosWithAngAndCenterPt(TransCurrentPtInUSS, CenterAngBackup1, CenterPtBackup1);
	 CurrentCarAngInNewCoordinate = TransCurrentCarAngInUSS + CenterAngBackup1;

    if(ResetTypeFlag ==1)
    { 
        if((USSResetHistory==0) &&(MATH_FABS(CurrentPtInNewCoordinate.x) < ResetCoordinateDisX) && 
        (MATH_FABS(CurrentPtInNewCoordinate.y) < ResetCoordinateDisY) && (MATH_FABS(CurrentCarAngInNewCoordinate*180.0/Math_PI)<ResetCoordinateAng))
        {
            CenterPtBackup2.x = 0; /* ��������������ת��������ϵʱ��ԭ������ԭ�㣨��һ������ϵԭ�㣩��������ϵ�µ����� */
            CenterPtBackup2.y = 0;
            CenterAngBackup2 = 0;
            CenterPtBackup1 = CenterPtBackup2;   /* ʵʱ����ת��������ϵʱ��ԭ����ϵԭ�㣨USS����ԭ�㣩��������ϵ�µ����� */
            CenterAngBackup1 = CenterAngBackup2;

            CenterPtBackup3 = CenterPtBackup1;
            CenterAngBackup3 = CenterAngBackup1;  /* ���µ�����ϵԭ����USS����ϵ�µ����� */
			CenterPtBackup3ForOIC = CenterPtBackup1;
            CenterAngBackup3ForOIC = CenterAngBackup1; 

            gUSS_stOut.gUSS_Coord0Pos.f32Xm = CenterPtBackup3.y / 1000.0;  // uss���USS����ϵ��DR����ϵ�е����ꣻ
            gUSS_stOut.gUSS_Coord0Pos.f32Ym = -CenterPtBackup3.x / 1000.0;
            gUSS_stOut.gUSS_Coord0Pos.Arad = CenterAngBackup3;

            USSResetHistory = 1;
        }
        else
        {
            if((MATH_FABS(CurrentPtInNewCoordinate.x) > ResetCoordinateDisX) 
                || (MATH_FABS(CurrentPtInNewCoordinate.y)>ResetCoordinateDisY) 
                || (MATH_FABS(CurrentCarAngInNewCoordinate* 180/Math_PI) > ResetCoordinateAng))
			{
                        /* ���㵱ǰ������һʱ������ϵ�е����� */
                if(USSResetHistory ==1 || USSResetHistory==0 ) /*xsj ��һ�ν��� */
                {
                    USSResetHistory =2;
                    /* ����DRԭ���ڵ�ǰ�㹹�ɵ�����ϵ�е����� */
                    CarAngTem = -TransCurrentCarAngInUSS;
                    CenterPtTem.x = 0;
                    CenterPtTem.y = 0;
                    DstPtTem = APATrajCalPointPosWithAngAndCenterPt(TransCurrentPtInUSS, CarAngTem, CenterPtTem);
                    CenterPtBackup2.x = -DstPtTem.x;
                    CenterPtBackup2.y = -DstPtTem.y;
                    CenterAngBackup2 = CarAngTem;
                    /* һ������ĵ㣨ʵʱ�㣩�Ͷ������������еĵ�ת��ʱ��CenterPtһ��*/
                    CenterPtBackup1 = CenterPtBackup2;
                    CenterAngBackup1 = CenterAngBackup2;
                    TransCenterPt = TransCurrentPtInUSS;
                    TransCenterAng = CenterAngBackup1;
                    /* ���ݵ�ǰ����ϵԭ����DR����ϵ�µ����� */
                    CenterPtBackup3 = TransCurrentPtInUSS;
                    CenterAngBackup3 = TransCurrentCarAngInUSS;
					CenterPtBackup3ForOIC = TransCurrentPtInUSS;
                    CenterAngBackup3ForOIC = TransCurrentCarAngInUSS;

                    gUSS_stOut.gUSS_Coord0Pos.f32Xm = CenterPtBackup3.y / 1000.0;  // uss���USS����ϵ��DR����ϵ�е����ꣻ
                    gUSS_stOut.gUSS_Coord0Pos.f32Ym = -CenterPtBackup3.x / 1000.0;
                    gUSS_stOut.gUSS_Coord0Pos.Arad = CenterAngBackup3;
                }
                else
                {
                    /* ����ǰ���USSת����һʱ�̵�����ϵ�� */
                    // DstPtTem =  APATrajCalPointPosWithAngAndCenterPt(CurrentPtInUSS,  CenterAngBackup1, CenterPtBackup1);
                    // CarAngTem =  CurrentCarAngInUSS + CenterAngBackup1;
                    /* ����һʱ������ϵԭ���ڵ�ǰ�㹹������ϵ�µ�����*/
                    CarAngTem =-CurrentCarAngInNewCoordinate;
                    CenterPtTem.x = 0;
                    CenterPtTem.y = 0;
                    DstPtTem = APATrajCalPointPosWithAngAndCenterPt(CurrentPtInNewCoordinate, CarAngTem, CenterPtTem);
                    CenterPtTem.x = -DstPtTem.x;
                    CenterPtTem.y = -DstPtTem.y;
                    CenterPtBackup2.x = CenterPtTem.x; /* ������������������*/
                    CenterPtBackup2.y = CenterPtTem.y;
                    CenterAngBackup2 = CarAngTem;
                    /* ���㵱ǰ�����ʼ����ϵԭ��֮��Ĺ�ϵ */
                    CarAngTem = -TransCurrentCarAngInUSS;
                    CenterPtTem.x = 0;
                    CenterPtTem.y = 0;
                    DstPtTem = APATrajCalPointPosWithAngAndCenterPt(TransCurrentPtInUSS, CarAngTem, CenterPtTem);
                    CenterPtBackup1.x = - DstPtTem.x;  /* ��ʵʱת���� */
                    CenterPtBackup1.y = - DstPtTem.y;
                    CenterAngBackup1 = CarAngTem;
                    /* ���ݵ�ǰ��������ϵԭ����USS����ϵ�µ����꣬��Edge���תʹ�� */
                    CenterPtBackup3 = TransCurrentPtInUSS;
                    CenterAngBackup3 = TransCurrentCarAngInUSS;
                    CenterPtBackup3ForOIC = CenterPtBackup3;
                    CenterAngBackup3ForOIC = CenterAngBackup3;                         
                    TransCenterPt = TransCurrentPtInUSS;
                    TransCenterAng = CenterAngBackup1;
                    gUSS_stOut.gUSS_Coord0Pos.f32Xm = CenterPtBackup3.y / 1000.0;  // uss���USS����ϵ��DR����ϵ�е����ꣻ
                    gUSS_stOut.gUSS_Coord0Pos.f32Ym = -CenterPtBackup3.x / 1000.0;
                    gUSS_stOut.gUSS_Coord0Pos.Arad = CenterAngBackup3;
                }
                /* ת�����������������*/
                gUSS_stOut.gUSS_u8ObjPtConvertFinishSts = 1u;  // δת����ɣ��������ֲܷ�ת��
                //ResetCoordinate(CenterPtBackup2,  CenterAngBackup2, 0);
                ResetCoordinateNew(CenterPtBackup2,  CenterAngBackup2, 0);
                gUSS_stOut.gUSS_u8ObjPtConvertFinishSts = 0u;   // ת����ɣ��ⲿģ�����ʹ����ص���Ϣ
                // USSResetHistory++;                     
            }
			/* תʵʱDR��Ϣ*/
			CurrentPtInNewCoordinate = APATrajCalPointPosWithAngAndCenterPt(TransCurrentPtInUSS, CenterAngBackup1, CenterPtBackup1);
			CurrentCarAngInNewCoordinate = TransCurrentCarAngInUSS + CenterAngBackup1;
			USSPar.APACarCenterPt.Coordinate.x = CurrentPtInNewCoordinate.x;
			USSPar.APACarCenterPt.Coordinate.y = CurrentPtInNewCoordinate.y;
			USSPar.APACarCenterPt.CarAng = CurrentCarAngInNewCoordinate;
			USSPar.APAVehicleSpeed = (APA_SPEED_TYPE)gUSD_stOut.gUSD_stSideObject.gUSD_u16VehSpdKPH/3.6;
		}
    }
    else if(ResetTypeFlag ==2)
    { /* ת����λ����ϵ*/

        if(LeftOrRight ==1)
        {
            SlotCoordinateAng = SlotCoordinateAng + (float)(90*Math_PI/180.0); /*  TBD ������������ϵ�ļн�*/
		}
			/* ����λ����ԭ���USS����ϵת����һʱ�̵�����ϵ�� */
            DstPtTem =  APATrajCalPointPosWithAngAndCenterPt(SlotCoordinatePoint,  CenterAngBackup1, CenterPtBackup1);
            CarAngTem =  TransCurrentCarAngInUSS + CenterAngBackup1;
            /* ����һʱ������ϵԭ���ڵ�ǰ�㹹������ϵ�µ�����*/
            CarAngTem =-CarAngTem;
            CenterPtTem.x = 0;
            CenterPtTem.y = 0;
            DstPtTem = APATrajCalPointPosWithAngAndCenterPt(DstPtTem, CarAngTem, CenterPtTem);
            CenterPtTem.x = -DstPtTem.x;
            CenterPtTem.y = -DstPtTem.y;

            CenterPtBackup2.x = CenterPtTem.x; /* ������������������*/
            CenterPtBackup2.y = CenterPtTem.y;
            CenterAngBackup2 = CarAngTem;
           
            CenterPtTem.x = 0;
            CenterPtTem.y = 0;
            CarAngTem = -SlotCoordinateAng;
            DstPtTem = APATrajCalPointPosWithAngAndCenterPt(SlotCoordinatePoint, CarAngTem, CenterPtTem);
            CenterPtBackup1.x = - DstPtTem.x;   /* ��תʵʱ���� */
            CenterPtBackup1.y = - DstPtTem.y;
            CenterAngBackup1 = CarAngTem;

           /* ת�����������������*/
            gUSS_stOut.gUSS_u8ObjPtConvertFinishSts = 1u;  // δת����ɣ��������ֲܷ�ת��
           // ResetCoordinate(CenterPtBackup2,  CenterAngBackup2, LeftOrRight);
            ResetCoordinateNew(CenterPtBackup2,  CenterAngBackup2, LeftOrRight);
            gUSS_stOut.gUSS_u8ObjPtConvertFinishSts = 0u;   // ת����ɣ��ⲿģ�����ʹ����ص���Ϣ

			/* תʵʱDR��Ϣ*/
			CurrentPtInNewCoordinate = APATrajCalPointPosWithAngAndCenterPt(TransCurrentPtInUSS, CenterAngBackup1, CenterPtBackup1);
			CurrentCarAngInNewCoordinate = TransCurrentCarAngInUSS + CenterAngBackup1;
			USSPar.APACarCenterPt.Coordinate.x = -CurrentPtInNewCoordinate.y;
			USSPar.APACarCenterPt.Coordinate.y = CurrentPtInNewCoordinate.x;
			USSPar.APACarCenterPt.CarAng = CurrentCarAngInNewCoordinate + CenterAngBackup1; /* TBD */
			USSPar.APAVehicleSpeed = (APA_SPEED_TYPE)gUSD_stOut.gUSD_stSideObject.gUSD_u16VehSpdKPH/3.6;
    }
    else
    {
        /* do nothing */
    }
}
/*************************************************************************************************************************************************
** Syntax :  void SaveAPASnsDtdRawData(void)                                                                                                            **
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
void SaveAPASnsDtdRawData(uint8 LeftOrRightTem)
{
    uint8 CarInfo_VehDir;
    sint32 CarCenterPt_DR_Coordinate_X;
    sint32 CarCenterPt_DR_Coordinate_y;
    sint32 CarCenterPt_DR_Ang;
    
    APACoordinateDataCalFloatType CurrentPtInUSS;
    APA_ANGLE_CAL_FLOAT_TYPE CurrentCarAngInUSS;
    APACoordinateDataCalFloatType DstPtTem;
    signed char WrIndex = 0;
    sint32 xTem0, yTem0;
    xTem0 =  -gUSD_stOut.gUSD_stSideObject.gUSD_s32VehPosYmm;
    yTem0 =   gUSD_stOut.gUSD_stSideObject.gUSD_s32VehPosXmm;
    CurrentPtInUSS.x =(float)xTem0;
    CurrentPtInUSS.y = (float)yTem0;
    CurrentCarAngInUSS = gUSD_stOut.gUSD_stSideObject.gUSD_f32VehYawRad;
    
    WrIndex = USSPar.APASnsDtdObjDisInfoBufWriteIndex;
#if Debug_SW_PrivateCANForIntegration
    APA_DISTANCE_TYPE FLSDis, FRSDis, RLSDis, RRSDis;
    sint32 CarCenterPt_Coord_X;
    sint32 CarCenterPt_Coord_y;
    sint32 CarCenterPt_CarAng;
    uint16 VehicleSpd;
    sint32 APAVehicleSpd;
    uint8 VehDir;
#endif

    if(WrIndex<APA_MAX_SUPPORT_SNS_DTD_OBJ_DIS_BUF_SIZE)
    {
        //do nothing
    }
    else
    {
        WrIndex = APA_MAX_SUPPORT_SNS_DTD_OBJ_DIS_BUF_SIZE - 1;
    }
/* ������ֵ����*/
    if(gUSD_stOut.gUSD_stSideObject.gUSD_u16FRSDist1MM<0x7FFF)
    {
        USSPar.APASnsDtdObjDisInfoBuf[WrIndex].APASnsDtdObjDis[0]= gUSD_stOut.gUSD_stSideObject.gUSD_u16FRSDist1MM;
    }
    else
    {
        USSPar.APASnsDtdObjDisInfoBuf[WrIndex].APASnsDtdObjDis[0]= 0x7FFF;
    }
    if(gUSD_stOut.gUSD_stSideObject.gUSD_u16FLSDist1MM<0x7FFF)
    {
        USSPar.APASnsDtdObjDisInfoBuf[WrIndex].APASnsDtdObjDis[1]= gUSD_stOut.gUSD_stSideObject.gUSD_u16FLSDist1MM;
    }
    else
    {
        USSPar.APASnsDtdObjDisInfoBuf[WrIndex].APASnsDtdObjDis[1]= 0x7FFF;
    }
    if(gUSD_stOut.gUSD_stSideObject.gUSD_u16RRSDist1MM<0x7FFF)
    {
        USSPar.APASnsDtdObjDisInfoBuf[WrIndex].APASnsDtdObjDis[2]= gUSD_stOut.gUSD_stSideObject.gUSD_u16RRSDist1MM;
    }
    else
    {
        USSPar.APASnsDtdObjDisInfoBuf[WrIndex].APASnsDtdObjDis[2]= 0x7FFF;
    }
    if(gUSD_stOut.gUSD_stSideObject.gUSD_u16RLSDist1MM<0x7FFF)
    {
        USSPar.APASnsDtdObjDisInfoBuf[WrIndex].APASnsDtdObjDis[3]= gUSD_stOut.gUSD_stSideObject.gUSD_u16RLSDist1MM;
    }
    else
    {
        USSPar.APASnsDtdObjDisInfoBuf[WrIndex].APASnsDtdObjDis[3]= 0x7FFF;
    }

#if Debug_SW_SmallObstacle
  /*small obj*/
  if(gUSD_stOut.gUSD_stSideObject.gUSD_u16FRSDist2MM<0x7FFF)
  {
   USSPar.APASnsDtdObjDisInfoBuf[WrIndex].APASnsDtdSmallObjDis[0] = gUSD_stOut.gUSD_stSideObject.gUSD_u16FRSDist2MM;
  }
  else
  {
   USSPar.APASnsDtdObjDisInfoBuf[WrIndex].APASnsDtdSmallObjDis[0] = 0x7FFF;
  }
  if(gUSD_stOut.gUSD_stSideObject.gUSD_u16FLSDist2MM<0x7FFF)
  {
   USSPar.APASnsDtdObjDisInfoBuf[WrIndex].APASnsDtdSmallObjDis[1] = gUSD_stOut.gUSD_stSideObject.gUSD_u16FLSDist2MM;
  }
  else
  {
   USSPar.APASnsDtdObjDisInfoBuf[WrIndex].APASnsDtdSmallObjDis[1] = 0x7FFF;
  }
  if(gUSD_stOut.gUSD_stSideObject.gUSD_u16RRSDist2MM<0x7FFF)
  {
   USSPar.APASnsDtdObjDisInfoBuf[WrIndex].APASnsDtdSmallObjDis[2] = gUSD_stOut.gUSD_stSideObject.gUSD_u16RRSDist2MM;
  }
  else
  {
   USSPar.APASnsDtdObjDisInfoBuf[WrIndex].APASnsDtdSmallObjDis[2] = 0x7FFF;
  }
  if(gUSD_stOut.gUSD_stSideObject.gUSD_u16RLSDist2MM<0x7FFF)
  {
   USSPar.APASnsDtdObjDisInfoBuf[WrIndex].APASnsDtdSmallObjDis[3] = gUSD_stOut.gUSD_stSideObject.gUSD_u16RLSDist2MM;
  }
  else
  {
   USSPar.APASnsDtdObjDisInfoBuf[WrIndex].APASnsDtdSmallObjDis[3] = 0x7FFF;
  }
#endif   
  /* ���뷽���ź� */
    if (gDR_stOut.gDR_u8VehDircn == 2)
    { 
        USSPar.APACommonFlags.Bits.bCarIsDrivingBackwards = 1;
    }
    else if(gDR_stOut.gDR_u8VehDircn==1) 
    { 
        USSPar.APACommonFlags.Bits.bCarIsDrivingBackwards = 0;
    }else{
        
    }

    /* ��һ�����������복������*/
    if(USSResetHistory == 0 || USSResetHistory == 1) /* û�����ù���ʱ��*/
    {
         
        USSPar.APASnsDtdObjDisInfoBuf[WrIndex].CarCenterPt.Coordinate.y = gUSD_stOut.gUSD_stSideObject.gUSD_s32VehPosXmm;
        USSPar.APASnsDtdObjDisInfoBuf[WrIndex].CarCenterPt.Coordinate.x = -gUSD_stOut.gUSD_stSideObject.gUSD_s32VehPosYmm;
        USSPar.APASnsDtdObjDisInfoBuf[WrIndex].CarCenterPt.CarAng = gUSD_stOut.gUSD_stSideObject.gUSD_f32VehYawRad;
        USSPar.APASnsDtdObjDisInfoBuf[WrIndex].VehicleSpd = (UCHAR)gUSD_stOut.gUSD_stSideObject.gUSD_u16VehSpdKPH;
        
    }
    else
    {
        /* �ѵ�ǰ��ֱ�Ӵ�DRת����ǰ����ϵ�£�Ȼ���ٴ��뵽һ�������� */
        if(LeftOrRightTem == 0 || LeftOrRightTem==2)
        {
            DstPtTem = APATrajCalPointPosWithAngAndCenterPt(CurrentPtInUSS, CenterAngBackup1, CenterPtBackup1);

            USSPar.APASnsDtdObjDisInfoBuf[WrIndex].CarCenterPt.Coordinate.y = DstPtTem.y;
            USSPar.APASnsDtdObjDisInfoBuf[WrIndex].CarCenterPt.Coordinate.x = DstPtTem.x;
            USSPar.APASnsDtdObjDisInfoBuf[WrIndex].CarCenterPt.CarAng = CurrentCarAngInUSS + CenterAngBackup1;
            USSPar.APASnsDtdObjDisInfoBuf[WrIndex].VehicleSpd = gUSD_stOut.gUSD_stSideObject.gUSD_u16VehSpdKPH;
        }
        else if(LeftOrRightTem ==1)
        { /* TBD �ӹ�������ϵ��תδ��*/
            DstPtTem = APATrajCalPointPosWithAngAndCenterPt(CurrentPtInUSS, CenterAngBackup1, CenterPtBackup1);

            USSPar.APASnsDtdObjDisInfoBuf[WrIndex].CarCenterPt.Coordinate.y = DstPtTem.y;
            USSPar.APASnsDtdObjDisInfoBuf[WrIndex].CarCenterPt.Coordinate.x = DstPtTem.x;
            USSPar.APASnsDtdObjDisInfoBuf[WrIndex].CarCenterPt.CarAng = CurrentCarAngInUSS + CenterAngBackup1;
            USSPar.APASnsDtdObjDisInfoBuf[WrIndex].VehicleSpd = gUSD_stOut.gUSD_stSideObject.gUSD_u16VehSpdKPH;
        }          
    }
#if Debug_SW_PrivateCANForIntegration
        /**************DBC_USS_test31****************/
        Test_RC_31 ^= 0x01;
        FLSDis = USSPar.APASnsDtdObjDisInfoBuf[WrIndex].APASnsDtdObjDis[1];
        FRSDis = USSPar.APASnsDtdObjDisInfoBuf[WrIndex].APASnsDtdObjDis[0];
        RLSDis = USSPar.APASnsDtdObjDisInfoBuf[WrIndex].APASnsDtdObjDis[3];
        RRSDis = USSPar.APASnsDtdObjDisInfoBuf[WrIndex].APASnsDtdObjDis[2];
        gSec_031_data.u8_CAN_031_Tx_data[0] = (FLSDis >> 5) & 0xFF;
        gSec_031_data.u8_CAN_031_Tx_data[1] = ((FLSDis & 0x1F) << 3) + ((FRSDis >> 10) & 0x07);
        gSec_031_data.u8_CAN_031_Tx_data[2] = (FRSDis >> 2) & 0xFF;
        gSec_031_data.u8_CAN_031_Tx_data[3] = ((FRSDis & 0x03) << 6) + ((Test_RC_31 & 0x07) << 3);
        gSec_031_data.u8_CAN_031_Tx_data[4] = (RLSDis >> 5) & 0xFF;
        gSec_031_data.u8_CAN_031_Tx_data[5] = ((RLSDis & 0x1F) << 3) + ((RRSDis >> 10) & 0x07);
        gSec_031_data.u8_CAN_031_Tx_data[6] = (RRSDis >> 2) & 0xFF;
        gSec_031_data.u8_CAN_031_Tx_data[7] = ((RRSDis & 0x03) << 6);
        /**************DBC_USS_test31****************/
        /**************DBC_USS_test32****************/
        Test_RC_32 = Test_RC_31;
        CarCenterPt_Coord_X = (sint32)gUSD_stOut.gUSD_stSideObject.gUSD_s32VehPosXmm;
        CarCenterPt_Coord_y = (sint32)gUSD_stOut.gUSD_stSideObject.gUSD_s32VehPosYmm;
        if (CarCenterPt_Coord_X >= 0)
        {
            gSec_032_data.u8_CAN_032_Tx_data[0] = (CarCenterPt_Coord_X >> 22) & 0x7F;
        }
        else
        {
            gSec_032_data.u8_CAN_032_Tx_data[0] = (0x01 << 7) + ((CarCenterPt_Coord_X >> 22) & 0x7F);
        }
        gSec_032_data.u8_CAN_032_Tx_data[1] = (CarCenterPt_Coord_X >> 14) & 0xFF;
        gSec_032_data.u8_CAN_032_Tx_data[2] = (CarCenterPt_Coord_X >> 6) & 0xFF;
        gSec_032_data.u8_CAN_032_Tx_data[3] = (CarCenterPt_Coord_X & 0x3F) << 2;
        if (CarCenterPt_Coord_y >= 0)
        {
            gSec_032_data.u8_CAN_032_Tx_data[4] = (CarCenterPt_Coord_y >> 22) & 0x7F;
        }
        else
        {
            gSec_032_data.u8_CAN_032_Tx_data[4] = (0x01 << 7) + ((CarCenterPt_Coord_y >> 22) & 0x7F);
        }
        gSec_032_data.u8_CAN_032_Tx_data[5] = (CarCenterPt_Coord_y >> 14) & 0xFF;
        gSec_032_data.u8_CAN_032_Tx_data[6] = (CarCenterPt_Coord_y >> 6) & 0xFF;
        gSec_032_data.u8_CAN_032_Tx_data[7] = ((CarCenterPt_Coord_y & 0x3F) << 2) + (Test_RC_32 & 0x03);
        /**************DBC_USS_test32****************/
        /**************DBC_USS_test33****************/
        Test_RC_33 = Test_RC_31;
        CarCenterPt_CarAng = (sint32)(gUSD_stOut.gUSD_stSideObject.gUSD_f32VehYawRad *180.0/PI*10000);
        VehicleSpd = gUSD_stOut.gUSD_stSideObject.gUSD_u16VehSpdKPH;
        APAVehicleSpd = (sint32)(USSPar.APAVehicleSpeed * 100);
        VehDir = gDR_stOut.gDR_u8VehDircn;

        if (CarCenterPt_CarAng >= 0)
        {
            gSec_033_data.u8_CAN_033_Tx_data[0] = (CarCenterPt_CarAng >> 16) & 0x7F;
        }
        else
        {
            gSec_033_data.u8_CAN_033_Tx_data[0] = (0x01 << 7) + ((CarCenterPt_CarAng >> 16) & 0x7F);
        }
        gSec_033_data.u8_CAN_033_Tx_data[1] = CarCenterPt_CarAng >> 8;
        gSec_033_data.u8_CAN_033_Tx_data[2] = CarCenterPt_CarAng & 0xFF;
        gSec_033_data.u8_CAN_033_Tx_data[3] = VehicleSpd & 0xFF;
        gSec_033_data.u8_CAN_033_Tx_data[4] = APAVehicleSpd >> 8;
        gSec_033_data.u8_CAN_033_Tx_data[5] = APAVehicleSpd & 0xFF;
        gSec_033_data.u8_CAN_033_Tx_data[6] = ((VehDir & 0x03) << 6) + ((Test_RC_33 & 0x07) << 3);
        // gSec_033_data.u8_CAN_033_Tx_data[7]
        /**************DBC_USS_test33****************/
#endif
#if 0//Debug_SW_InforCANOutput
/* xsj 20200408 add Test Can DATA*/
  /*id=11*/
    USS_Test_Rc_11 ^= 0xFF ;

    USS_Test_Data1_Temp1 = (USSPar.APASnsDtdObjDisInfoBuf[WrIndex].APASnsDtdObjDis[1] & 0x0F00) >> 8;
    USS_Test_Data1_Temp2 = (USS_Test_Rc_11 & 0x07) << 5;

    USS_Test_Data2_Temp1= USSPar.APASnsDtdObjDisInfoBuf[WrIndex].APASnsDtdObjDis[1] & 0x00FF;

    USS_Test_Data3_Temp1 = (USSPar.APASnsDtdObjDisInfoBuf[WrIndex].APASnsDtdObjDis[0]& 0x0F00) >> 8 ;
    USS_Test_Data4_Temp1 = USSPar.APASnsDtdObjDisInfoBuf[WrIndex].APASnsDtdObjDis[0] & 0x00FF;

    USS_Test_Data5_Temp1 = (USSPar.APASnsDtdObjDisInfoBuf[WrIndex].APASnsDtdObjDis[3] & 0x0F00) >> 8 ;
    USS_Test_Data6_Temp1 = USSPar.APASnsDtdObjDisInfoBuf[WrIndex].APASnsDtdObjDis[3] & 0x00FF;

    USS_Test_Data7_Temp1 = (USSPar.APASnsDtdObjDisInfoBuf[WrIndex].APASnsDtdObjDis[2] & 0x0F00) >>8 ;
    USS_Test_Data8_Temp1 = USSPar.APASnsDtdObjDisInfoBuf[WrIndex].APASnsDtdObjDis[2] & 0x00FF;
    
    gSec_011_data.u8_CAN_011_Tx_data[0] = USS_Test_Data1_Temp1 + USS_Test_Data1_Temp2;
    gSec_011_data.u8_CAN_011_Tx_data[1] = USS_Test_Data2_Temp1;
    gSec_011_data.u8_CAN_011_Tx_data[2] =  USS_Test_Data3_Temp1;
    gSec_011_data.u8_CAN_011_Tx_data[3] = USS_Test_Data4_Temp1;
    gSec_011_data.u8_CAN_011_Tx_data[4] = USS_Test_Data5_Temp1;
    gSec_011_data.u8_CAN_011_Tx_data[5] = USS_Test_Data6_Temp1;
    gSec_011_data.u8_CAN_011_Tx_data[6] = USS_Test_Data7_Temp1;
    gSec_011_data.u8_CAN_011_Tx_data[7] = USS_Test_Data8_Temp1;
    /**************DBC_USS_FilterIn_12_SmallObjDis****************/
    // USS_Test_Rc_701 ^=0x01;
    USS_Test_Rc_701 = USS_Test_Rc_11;
    CarInfo_VehDir = gDR_stOut.gDR_u8VehDircn;

    gSec_012_data.u8_CAN_012_Tx_data[0] = ((USS_Test_Rc_701 & 0x07) << 5);
    gSec_012_data.u8_CAN_012_Tx_data[1] = 0;
    gSec_012_data.u8_CAN_012_Tx_data[2] = ((CarInfo_VehDir & 0x03) << 6);
    gSec_012_data.u8_CAN_012_Tx_data[3] = 0;
    gSec_012_data.u8_CAN_012_Tx_data[4] = 0;
    gSec_012_data.u8_CAN_012_Tx_data[5] = 0;
    gSec_012_data.u8_CAN_012_Tx_data[6] = 0;
    gSec_012_data.u8_CAN_012_Tx_data[7] = 0;
 
    /**************DBC_USS_FilterIn_12_SmallObjDis****************/

    /* id =13*/
    // USS_Test_Rc_13 ^= 0xFF;
    USS_Test_Rc_13 = USS_Test_Rc_11;
//    CANTem3 = DataTypeConvertFloatToInt(USSPar.APASnsDtdObjDisInfoBuf[WrIndex].CarCenterPt.Coordinate.x);
    CANTem3 = DataTypeConvertFloatToInt(gUSD_stOut.gUSD_stSideObject.gUSD_s32VehPosXmm);
    CANTem4[0] = CANTem3[0];
    CANTem4[1] = CANTem3[1];
    CANTem4[2] = CANTem3[2];
    CANTem4[3] = CANTem3[3];
    gSec_013_data.u8_CAN_013_Tx_data[0] = (CANTem4[3]<<2) | (CANTem4[2]>>6);
    gSec_013_data.u8_CAN_013_Tx_data[1] =(CANTem4[2]<<2) | (CANTem4[1]>>6);
    gSec_013_data.u8_CAN_013_Tx_data[2] = (CANTem4[1]<<2) | (CANTem4[0]>>6);
    gSec_013_data.u8_CAN_013_Tx_data[3] = CANTem4[0] << 2;

//    CANTem5 = DataTypeConvertFloatToInt(USSPar.APASnsDtdObjDisInfoBuf[WrIndex].CarCenterPt.Coordinate.y);
    CANTem5 = DataTypeConvertFloatToInt(gUSD_stOut.gUSD_stSideObject.gUSD_s32VehPosYmm);
    CANTem6[0] = CANTem5[0];
    CANTem6[1] = CANTem5[1];
    CANTem6[2] = CANTem5[2];
    CANTem6[3] = CANTem5[3];
    gSec_013_data.u8_CAN_013_Tx_data[4] =(CANTem6[3]<<2) | (CANTem6[2]>>6);
    gSec_013_data.u8_CAN_013_Tx_data[5] = (CANTem6[2]<<2) | (CANTem6[1]>>6);
    gSec_013_data.u8_CAN_013_Tx_data[6] = (CANTem6[1]<<2) | (CANTem6[0]>>6);
    gSec_013_data.u8_CAN_013_Tx_data[7] = (CANTem6[0] << 2) + (USS_Test_Rc_13 & 0x03);
    /*id=14*/
    // USS_Test_Rc_14 ^= 0xFF;
    USS_Test_Rc_14 = USS_Test_Rc_11;
    CANTem5 = DataTypeConvertFloatToInt(gUSD_stOut.gUSD_stSideObject.gUSD_f32VehYawRad *180.0/PI*10000);
//    CANTem5 = DataTypeConvertFloatToInt(USSPar.APASnsDtdObjDisInfoBuf[WrIndex].CarCenterPt.CarAng *180.0/PI*10000);
    CANTem6[0] = CANTem5[0];
    CANTem6[1] = CANTem5[1];
    CANTem6[2] = CANTem5[2];
    CANTem6[3] = CANTem5[3];
    gSec_014_data.u8_CAN_014_Tx_data[0] = CANTem6[3];
    gSec_014_data.u8_CAN_014_Tx_data[1] = CANTem6[2];
    gSec_014_data.u8_CAN_014_Tx_data[2] = CANTem6[1];
    gSec_014_data.u8_CAN_014_Tx_data[3] = CANTem6[0];
    
   //USS_Test_ID14_Data5 = USSPar.APASnsDtdObjDisInfoBuf[WrIndex].VehicleSpd;
    u8CANTem14 = (uint8)gUSD_stOut.gUSD_stSideObject.gUSD_u16VehSpdKPH;
    CANTem15 = (sint32)(USSPar.APAVehicleSpeed *100);
    gSec_014_data.u8_CAN_014_Tx_data[4] = u8CANTem14;
    gSec_014_data.u8_CAN_014_Tx_data[5] = (CANTem15 & 0x0000FF00)>>8;
    gSec_014_data.u8_CAN_014_Tx_data[6] = CANTem15  & 0x0FF;
    gSec_014_data.u8_CAN_014_Tx_data[7] = USS_Test_Rc_14 & 0x7;

#endif

    if(USSPar.APASnsDtdObjDisInfoBufWriteIndex < APA_MAX_SUPPORT_SNS_DTD_OBJ_DIS_BUF_SIZE)
    {

        USSPar.APASnsDtdObjDisInfoBufWriteIndex++;

    }
}
/*************************************************************************************************************************************************
** Syntax :  void ResetSystemCoordinateUSS(void)                                                                                                **
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
 APA_DISTANCE_TYPE FindMinDis(APA_INDEX_TYPE StartIndexTem, APA_INDEX_TYPE EndIndexTem, uint8 u8SlotSide)
 {
     APA_INDEX_TYPE MinIndex, MaxIndex;
     APA_DISTANCE_TYPE MinDistance = 0x7FFF;
     uint8 f = 0u;
     if(StartIndexTem <= EndIndexTem)
     {
         MinIndex = StartIndexTem;
         MaxIndex = EndIndexTem;
     }
     else
     {
         MinIndex = EndIndexTem;
         MaxIndex = StartIndexTem;
     }
  
     for(f = MinIndex; f<= MaxIndex; f++)
     {
         if(USSPar.Slot[u8SlotSide].SlotOutline.Lane.DisFromCarToObj[f] < MinDistance)
         {
             MinDistance = USSPar.Slot[u8SlotSide].SlotOutline.Lane.DisFromCarToObj[f];
         }
     }
     return MinDistance;   
 }
 /*************************************************************************************************************************************************
** Syntax : uint8 FindInflectPt(APA_INDEX_TYPE StartIndexTem, APA_INDEX_TYPE EndIndexTem, uint8 u8SlotSide, uint8 ObjIndex,                     **
APACoordinateDataCalFloatType *FirstInflectPt)                                                                                                  **
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
sint8 FindInflectPt(APA_INDEX_TYPE StartIndexTem, APA_INDEX_TYPE EndIndexTem, uint8 u8SlotSide, uint8 ObjIndex, APACoordinateDataCalFloatType *FirstInflectPt)
{
    APASlotOutlineCoordinateDataType *pSlotOutlineTemp;
    
    APA_INDEX_TYPE MinIndex, MaxIndex;
    uint8 PointNumTem = 0;
    uint8 i = 0u;
    uint8 j = 0u;
    uint8 s = 0u;
    APACoordinateDataCalFloatType PointBaseUSSTem, PointBaseDR[INFLECTPTNUM], OriDataf32;
    APASlotOutlineCoordinateDataType OriData[INFLECTPTNUM];
    uint8 PtCnt = 0u;
    APA_DISTANCE_TYPE DisBaseDR[INFLECTPTNUM];
    uint8 ValidSlopeCnt = 0u;
    float ObjWidth, ObjDeltaDis, SlopeChangeSum, AverageSlope, SlopeSum, AverageChangeSlope;
    float Slope[INFLECTPTNUM] = {0.0};
    float SlopeChange[INFLECTPTNUM] = {0.0};
    uint8 ValidSlopeIndex[INFLECTPTNUM] = {0};
    APA_INDEX_TYPE OriIndex[INFLECTPTNUM] = {0};
    uint8 SlopeChangeCnt = 0u;
    uint8 AverageSlopeChangeCnt = 0u;
    uint8 AverageSlopeCnt = 0u;
    APA_INDEX_TYPE FirstInflectPointIndex = -1;
    APA_INDEX_TYPE FirstInflectPointIndex1 = -1;
    APA_INDEX_TYPE FirstInflectPointIndex2 = -1;
    APACoordinateDataCalFloatType FirstInflectPtTem;
    uint8 FirstPtFlag = 0;
    uint8 FirstPtFlag1 =0;
    uint8 FirstPtFlag2 = 0;
    uint8 FirstPtFlag3 = 0;
    sint8 ii = 0;
    pSlotOutlineTemp = &USSPar.Slot[u8SlotSide].SlotOutline.Lane;
    float TwoObjDisTem = 0;
    float DeltaX = 0;
    float DeltaY = 0;
     
    


    if(ObjIndex == 1)    
    {
    	 for (ii=StartIndexTem; ii>=(EndIndexTem+1); ii--)
		{
            if (ii <= 0) /*��ֹii-1Խ��*/
            {
                continue;
            }
			// OriDataf32.x = (float32)(pSlotOutlineTemp->CarCenterPoint[ii].x);
			// OriDataf32.y = (float32)(pSlotOutlineTemp->CarCenterPoint[ii].y);
			ObjWidth = sqrt( (pSlotOutlineTemp->CarCenterPoint[ii-1].x - pSlotOutlineTemp->CarCenterPoint[ii].x)* (pSlotOutlineTemp->CarCenterPoint[ii-1].x - pSlotOutlineTemp->CarCenterPoint[ii].x)+
								(pSlotOutlineTemp->CarCenterPoint[ii-1].y- pSlotOutlineTemp->CarCenterPoint[ii].y) * (pSlotOutlineTemp->CarCenterPoint[ii-1].y- pSlotOutlineTemp->CarCenterPoint[ii].y));
            TwoObjDisTem = sqrt((pSlotOutlineTemp->ObjPt[ii-1].x - pSlotOutlineTemp->ObjPt[ii].x) *(pSlotOutlineTemp->ObjPt[ii-1].x - pSlotOutlineTemp->ObjPt[ii].x) +
                                (pSlotOutlineTemp->ObjPt[ii-1].y - pSlotOutlineTemp->ObjPt[ii].y) *(pSlotOutlineTemp->ObjPt[ii-1].y - pSlotOutlineTemp->ObjPt[ii].y));

		   if((ii == StartIndexTem &&fabs(pSlotOutlineTemp->DisFromCarToObj[ii] - pSlotOutlineTemp->DisFromCarToObj[ii-1])<20)||
                (ii == StartIndexTem &&(pSlotOutlineTemp->DisFromCarToObj[ii] - pSlotOutlineTemp->DisFromCarToObj[ii-1])<0 ) ||
				((pSlotOutlineTemp->DisFromCarToObj[ii]==NO_OBJ_DISTANCE) ||(ObjWidth<10 || ObjWidth>5000)) ||
                    TwoObjDisTem < 70)
		   {
			   continue;
		   }
		   else
		   {
				OriDataf32.x = (float32)(pSlotOutlineTemp->ObjPt[ii].x);
				OriDataf32.y = (float32)(pSlotOutlineTemp->ObjPt[ii].y);

				PointBaseUSSTem = APATrajCalPointPosWithAngAndCenterPt(OriDataf32, CenterAngBackup3, CenterPtBackup3);
				// PointBaseDR[PtCnt] = PointBaseUSSTem;
                PointBaseDR[PtCnt].x = PointBaseUSSTem.y;
                PointBaseDR[PtCnt].y = -PointBaseUSSTem.x;
				DisBaseDR[PtCnt] = pSlotOutlineTemp->DisFromCarToObj[ii];
				OriIndex[PtCnt]  = ii;
				PtCnt = PtCnt +1;
                if (PtCnt >= INFLECTPTNUM)
                {
                    PtCnt--;
                    break; /*��ֹ����Խ�磬���������С�ĵ�����*/
                }
		   }

		}

        
    }
    else     // ObjIndex=2, ????object2
    {
    	for(ii=StartIndexTem;ii<=EndIndexTem-1;ii++)
		{
            if (ii >= APA_SLOT_SUPPORT_FRONT_SIDE_MAX_SAMPLE_POINT_NUM) /*��ֹii+1Խ��*/
            {
                continue;
            }
			// OriDataf32.x = (float32)(pSlotOutlineTemp->CarCenterPoint[ii].x);
			// OriDataf32.y = (float32)(pSlotOutlineTemp->CarCenterPoint[ii].y);
			ObjWidth = sqrt( (pSlotOutlineTemp->CarCenterPoint[ii+1].x - pSlotOutlineTemp->CarCenterPoint[ii].x)* (pSlotOutlineTemp->CarCenterPoint[ii+1].x - pSlotOutlineTemp->CarCenterPoint[ii].x)+
								(pSlotOutlineTemp->CarCenterPoint[ii+1].y- pSlotOutlineTemp->CarCenterPoint[ii].y) * (pSlotOutlineTemp->CarCenterPoint[ii+1].y- pSlotOutlineTemp->CarCenterPoint[ii].y));

            TwoObjDisTem = sqrt((pSlotOutlineTemp->ObjPt[ii+1].x - pSlotOutlineTemp->ObjPt[ii].x) *(pSlotOutlineTemp->ObjPt[ii+1].x - pSlotOutlineTemp->ObjPt[ii].x) +
                                (pSlotOutlineTemp->ObjPt[ii+1].y - pSlotOutlineTemp->ObjPt[ii].y) *(pSlotOutlineTemp->ObjPt[ii+1].y - pSlotOutlineTemp->ObjPt[ii].y));
			if(((ii == StartIndexTem &&fabs(pSlotOutlineTemp->DisFromCarToObj[ii] - pSlotOutlineTemp->DisFromCarToObj[ii+1])<20) ||
                (ii == StartIndexTem &&(pSlotOutlineTemp->DisFromCarToObj[ii] - pSlotOutlineTemp->DisFromCarToObj[ii+1])<0 ) ||
				  ((pSlotOutlineTemp->DisFromCarToObj[ii]==NO_OBJ_DISTANCE) || (ObjWidth<10 || ObjWidth>5000)) ||
                    TwoObjDisTem < 70))
		   {
			   continue;
		   }
		   else
		   {
				OriDataf32.x = (float32)(pSlotOutlineTemp->ObjPt[ii].x);
				OriDataf32.y = (float32)(pSlotOutlineTemp->ObjPt[ii].y);
				PointBaseUSSTem = APATrajCalPointPosWithAngAndCenterPt(OriDataf32, CenterAngBackup3, CenterPtBackup3);
				PointBaseDR[PtCnt].x = PointBaseUSSTem.y;
                PointBaseDR[PtCnt].y = -PointBaseUSSTem.x;
				DisBaseDR[PtCnt] = pSlotOutlineTemp->DisFromCarToObj[ii];
				OriIndex[PtCnt]  = ii;
				PtCnt = PtCnt +1;
                if (PtCnt >= INFLECTPTNUM)
                {
                    PtCnt--;
                    break; /*��ֹ����Խ�磬���������С�ĵ�����*/
                }
		   }
		}
    }
    

    ValidSlopeCnt = 0;
    for (i = 0;i<PtCnt-1;i++)
    {
    	//ObjWidth = sqrt( (PointBaseDR[i].x - PointBaseDR[i+1].x)* (PointBaseDR[i].x - PointBaseDR[i+1].x)+
		//					(PointBaseDR[i].y - PointBaseDR[i+1].y) * (PointBaseDR[i].y - PointBaseDR[i+1].y));
		// ObjDeltaDis = DisBaseDR[i+1] - DisBaseDR[i];
		// if(ObjWidth > 10 && ObjWidth<5000 )
		// {
		// 	Slope[ValidSlopeCnt] = ObjDeltaDis / ObjWidth;
		// 	ValidSlopeIndex[ValidSlopeCnt] = OriIndex[i+1];
		// 	ValidSlopeCnt = ValidSlopeCnt +1;
		// }
        DeltaX = PointBaseDR[i+1].x - PointBaseDR[i].x;
        DeltaY = PointBaseDR[i+1].y - PointBaseDR[i].y;
        if(fabs(DeltaX) >0.005)
        {
        	Slope[ValidSlopeCnt] = DeltaY / DeltaX;
			ValidSlopeIndex[ValidSlopeCnt] = OriIndex[i+1];
			ValidSlopeCnt = ValidSlopeCnt +1;
        }

    }

   
    SlopeChangeCnt = 0;
    for(j=0; j<ValidSlopeCnt-1; j++)
    {
        SlopeChange[SlopeChangeCnt] =  Slope[j+1] -Slope[j];
        SlopeChangeCnt = SlopeChangeCnt+1;
       
    }


    if(FirstPtFlag1 == 0)
    {
        for(s=0; s<SlopeChangeCnt-1; s++)
        {

            SlopeChangeSum = SlopeChangeSum + fabs(SlopeChange[s]);
            AverageSlopeChangeCnt = AverageSlopeChangeCnt +1;
            AverageChangeSlope = SlopeChangeSum / AverageSlopeChangeCnt;
            //  if ( (s!=0) &&(s+1)<=(ValidSlopeCnt-1)&& ((s+2)<= (PtCnt-1))&&
            //         (  (fabs(SlopeChange[s])>0.1 && fabs(SlopeChange[s+1]) >2.5*fabs(SlopeChange[s]) ||
            //             (fabs(SlopeChange[s])>0.02 && fabs(SlopeChange[s])<0.1 && fabs(SlopeChange[s+1]) >15*fabs(SlopeChange[s]))||
            //             (fabs(SlopeChange[s])>0.005 && fabs(SlopeChange[s])<0.02 && fabs(SlopeChange[s+1]) >20*fabs(SlopeChange[s]))||
            //             (fabs(SlopeChange[s])<0.005) && fabs(SlopeChange[s+1]) >50*fabs(SlopeChange[s])) ))
            // {
            //     FirstInflectPointIndex1 = s+2;
            //     FirstPtFlag1 = 1;
            //     break;
            // }
            // if ( ((s!=0) &&(s+1)<=(ValidSlopeCnt-1)&& ((s+2)<= (PtCnt-1))) &&
            //     ( (fabs(SlopeChange[s+1]) > 5*fabs(AverageChangeSlope)) || (fabs(SlopeChange[s+1] >4*fabs(SlopeChange[s])))))
             if ( ((s!=0) &&(s+1)<=(ValidSlopeCnt-1)&& (s+2)<= (PtCnt-1) )&&
                ( (fabs(SlopeChange[s+1]) > 5*fabs(AverageChangeSlope)) || (fabs(SlopeChange[s+1]) >4*fabs(SlopeChange[s]))))
            {
                FirstInflectPointIndex1 = s+2;
                FirstPtFlag1 = 1;
                break;
            }
            else if((s!=0) &&(s+1)<=(ValidSlopeCnt-1) &&  fabs(SlopeChange[s]) >(4*fabs(SlopeChange[s+1])))
            {
                FirstInflectPointIndex1 = s+1;
                FirstPtFlag1 = 1;
                break;
            } 
            else if((s!=0 && (s+1)<=(ValidSlopeCnt-1) && (s+2)<=ValidSlopeCnt-1) && fabs(fabs(SlopeChange[s+2]) - fabs(SlopeChange[s+1])) < 0.015 && fabs(SlopeChange[s]) > 2*fabs(SlopeChange[s+1]))
            {
                FirstInflectPointIndex1 = s+1;
                FirstPtFlag1 = 1;
                break;
            }
            else if((s-1)>=0 && s+1 <=(ValidSlopeCnt -1) && fabs(SlopeChange[s-1]) <0.08 && fabs(SlopeChange[s+1]) < 0.08 && fabs(SlopeChange[s]) > 0.25)
            {
                FirstInflectPointIndex1 = s+1;
                FirstPtFlag1 = 1;
                break;
            }
            else
            {

            } 
        }
    }

    if(FirstPtFlag1 == 0 || (FirstPtFlag1 == 1 && FirstInflectPointIndex1>=5))
    {
        if(ValidSlopeCnt-1 >1 && fabs(SlopeChange[0]) > 2*fabs(SlopeChange[1]) && fabs(SlopeChange[0]) >= 0.25)
        {
             FirstInflectPointIndex1 = 1;
             FirstPtFlag1 = 1;
             FirstPtFlag3 = 1;
        }
        else if(SlopeChangeCnt >= 2 && fabs(SlopeChange[0]) >=0.25 && fabs(SlopeChange[1]) >0.25)
        {
             FirstInflectPointIndex1 = 2;
             FirstPtFlag1 = 1;
             FirstPtFlag3 = 1;
        }
        else if(SlopeChangeCnt >= 1 && fabs(SlopeChange[0]) >= 0.25)
        {
             FirstInflectPointIndex1 = 1;
             FirstPtFlag1 = 1;
             FirstPtFlag3 = 1;
        }
        else
        {
        } 
    }
   if(FirstPtFlag2 == 0)
    { 
        for(s=0;s<ValidSlopeCnt-1; s++)
        {
            SlopeSum = SlopeSum + fabs(Slope[s]);
            AverageSlopeCnt = AverageSlopeCnt +1;
            AverageSlope  = SlopeSum / AverageSlopeCnt;
            if ((s!=0)&&((s+1)<=(ValidSlopeCnt-1)) &&
                ( AverageSlope > 6*fabs(Slope[s+1]) ||
                (fabs(Slope[s+1])> 6*AverageSlope ) ||
                 ( (s-1)>=0 &&(s+2)<=(ValidSlopeCnt-1)&& Slope[s]*Slope[s-1]>0 && Slope[s]*Slope[s+1]<0 && Slope[s]*Slope[s+2]<0)||
                 ((s-2)>=0 && Slope[s]*Slope[s-1]>0  && Slope[s]*Slope[s-2]>0 && Slope[s]*Slope[s+1]<0)))
              
            {
                FirstInflectPointIndex2 = s+1;
                FirstPtFlag2 = 1;
                break;
            }
            else
            {
               
            }
        }
    }
    if (FirstPtFlag1==1 && FirstPtFlag2==1)
    {
        if(FirstInflectPointIndex1 < FirstInflectPointIndex2 )
        {
            FirstInflectPointIndex = FirstInflectPointIndex1;
            FirstPtFlag = 1;
        }
        else if(FirstInflectPointIndex1 > FirstInflectPointIndex2 )
        {
            FirstInflectPointIndex = FirstInflectPointIndex2;
            FirstPtFlag = 1;
        }
        else
        {
            FirstInflectPointIndex = FirstInflectPointIndex1;
            FirstPtFlag = 1;
        }
        
    }
    else if(FirstPtFlag1==1 && FirstPtFlag2==0)
    {
        FirstInflectPointIndex = FirstInflectPointIndex1;
        FirstPtFlag = 1;
    }
    else if(FirstPtFlag1==0 && FirstPtFlag2==1)
    {
        FirstInflectPointIndex = FirstInflectPointIndex2;
        FirstPtFlag =1;
    }
    else
    {
        FirstPtFlag = 0;
    }

    if(ObjIndex ==1)
    {
        if(PtCnt <5)
        {
            // FirstInflectPointIndex = PtCnt-1;
            FirstInflectPointIndex = -1;
        }
        else if(FirstPtFlag == 1 && FirstPtFlag3 == 0)
        {
            if ( FirstInflectPointIndex  >5)
            {
                FirstInflectPointIndex  = FirstInflectPointIndex -1;              
            }
            else if(FirstInflectPointIndex > PtCnt/2)
            {
                FirstInflectPointIndex  = FirstInflectPointIndex -1;  
            }
            else if(StartIndexTem - OriIndex[FirstInflectPointIndex]   <= 1)
            {
                FirstInflectPointIndex  = FirstInflectPointIndex +1;
            }
        }
    }
    else
    {
        if(PtCnt <6)
        {
            // FirstInflectPointIndex = PtCnt-1;
            FirstInflectPointIndex = -1;
        }
        else if(FirstPtFlag == 1 && FirstPtFlag3 == 0)
        {
            if ( FirstInflectPointIndex   >5)
            {
                FirstInflectPointIndex  = FirstInflectPointIndex -1;              
            }
            else if(OriIndex[FirstInflectPointIndex] - StartIndexTem   <= 1)
            {
                FirstInflectPointIndex  = FirstInflectPointIndex +1;
            }
        }
    }
    
    if (FirstInflectPointIndex != -1)
    {
        FirstInflectPointIndex = OriIndex[FirstInflectPointIndex];

        OriDataf32.x = (float32)(pSlotOutlineTemp->ObjPt[FirstInflectPointIndex].x);
                OriDataf32.y = (float32)(pSlotOutlineTemp->ObjPt[FirstInflectPointIndex].y);
        FirstInflectPtTem = APATrajCalPointPosWithAngAndCenterPt(OriDataf32, CenterAngBackup3, CenterPtBackup3);
        FirstInflectPt->x = FirstInflectPtTem.y;
        FirstInflectPt->y = -FirstInflectPtTem.x;
    }
    return FirstInflectPointIndex;   
}

/*************************************************************************************************************************************************
** Syntax :  void USS_CoordTransforToDR(void)                                                                                                          **
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
** Description : ��ȡtask�����Ľ����������USS��������(ģ�����������u8USS_OnStates)������ǻ���DR����ϵ
        //       ���ݳ�λ������SIF֮����н���
        //       ���⳵λ�������7.2m�ĳ�λcase�ر�������·�������
        //       �ھ���edge1 3.2m֮����г�λ��Ϣ�����                                                                                                                             **
*************************************************************************************************************************************************/
APACoordinateDataCalFloatType USS_CoordTransforToDR(APACoordinateDataType ToBeTransforPtBaseCurrentCoord,
                                                    APA_ANGLE_TYPE Angle,
                                                    APACoordinateDataCalFloatType CenterPtBackup)
{
    APACoordinateDataCalFloatType PtAfterTransforBaseDR;
    APACoordinateDataCalFloatType ToBeTransforPt,AfterTransforPt;
    APACoordinateDataCalFloatType Coord0Pt;

    Coord0Pt.x       =  CenterPtBackup.x;
    Coord0Pt.y       =  CenterPtBackup.y;
    ToBeTransforPt.x = (float)(ToBeTransforPtBaseCurrentCoord.x);
    ToBeTransforPt.y = (float)(ToBeTransforPtBaseCurrentCoord.y);

    AfterTransforPt = APATrajCalPointPosWithAngAndCenterPt(ToBeTransforPt,Angle,Coord0Pt);

    PtAfterTransforBaseDR.x = AfterTransforPt.y;
    PtAfterTransforBaseDR.y = -AfterTransforPt.x;

    return PtAfterTransforBaseDR;
}

/*************************************************************************************************************************************************
** Syntax :  void SendParamtersOutOnceEdgePtUpdated()                                                                                           **
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
** Description : һ���ǵ���£�������о����ǵ��Ƿ���µĲ���������Debug                                                                            **
*************************************************************************************************************************************************/
void SendParamtersOutOnceEdgePtUpdated()
{
#if 0//Debug_SW_SendParasOutOnceEdgePtUpd
    /**************DBC_USS_FilterIn_29_DR_Ang****************/
    gSec_029_data.u8_CAN_029_Tx_data[4] = CarPassTheSlotEndPtDistance >> 8;
    gSec_029_data.u8_CAN_029_Tx_data[5] = CarPassTheSlotEndPtDistance & 0xFF;
    gSec_029_data.u8_CAN_029_Tx_data[6] = ObjPtCnt & 0xFF;
    /**************DBC_USS_FilterIn_29_DR_Ang****************/
    /*ֻ���ڲ��ԣ����ǵ�Debug�в����ĳ�λһ�㲻����200����ͬʱΪ�˽�ʡ���ģ�ÿ������ֵ��8λ�޷���*/
    /**************DBC_Debug_0x31****************/
    // gSec_031_data.u8_CAN_031_Tx_data[0] = (uint8)USSPar.Slot[RIGHT].SlotPar[0].SlotID;
    // gSec_031_data.u8_CAN_031_Tx_data[1] = (uint8)USSPar.Slot[RIGHT].SlotPar[1].SlotID;
    // gSec_031_data.u8_CAN_031_Tx_data[2] = (uint8)USSPar.Slot[RIGHT].SlotPar[2].SlotID;
    // gSec_031_data.u8_CAN_031_Tx_data[3] = (uint8)USSPar.Slot[LEFT].SlotPar[0].SlotID;
    // gSec_031_data.u8_CAN_031_Tx_data[4] = (uint8)USSPar.Slot[LEFT].SlotPar[1].SlotID;
    // gSec_031_data.u8_CAN_031_Tx_data[5] = (uint8)USSPar.Slot[LEFT].SlotPar[2].SlotID;
    // gSec_031_data.u8_CAN_031_Tx_data[6] = (uint8)s16NewSlotIDBackup[0];
    // gSec_031_data.u8_CAN_031_Tx_data[7] = (uint8)s16NewSlotIDBackup[1];
    /**************DBC_Debug_0x31****************/

    /**************DBC_Debug_0x32****************/
    // gSec_032_data.u8_CAN_032_Tx_data[0] = s16VirtualSlotIDBackup[0];
    // gSec_032_data.u8_CAN_032_Tx_data[1] = s16VirtualSlotIDBackup[1];
    // gSec_032_data.u8_CAN_032_Tx_data[2] = (uint8)USSPar.Slot[RIGHT].SlotNum;
    // gSec_032_data.u8_CAN_032_Tx_data[3] = (uint8)USSPar.Slot[LEFT].SlotNum;
    // gSec_032_data.u8_CAN_032_Tx_data[4] = (uint8)u8SlotNumBackup[0];
    // gSec_032_data.u8_CAN_032_Tx_data[5] = (uint8)u8SlotNumBackup[1];
    // gSec_032_data.u8_CAN_032_Tx_data[6] ;
    // gSec_032_data.u8_CAN_032_Tx_data[7] ;
    /**************DBC_Debug_0x32****************/

    /**************DBC_Debug_0x33****************/

    /**************DBC_Debug_0x33****************/
    /*
    u8SlotNumBackup[2]
    s16NewSlotIDBackup[2]
    s16VirtualSlotIDBackup[2]
    USSPar.Slot[RIGHT].SlotPar[u8SlotNumBackup[RIGHT]-1].SlotID*6
    USSPar.Slot[RIGHT].SlotPar[u8SlotNumBackup[RIGHT]-1].Slotnum*6
    */
#endif
}

/*************************************************************************************************************************************************
** Syntax :  void SaveSlotInfoToUSSstOut(SLOTINFO_ST* SlotInfoTemp, char slot_dir, char slot_index)                                             **
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
** Description : ��USS_stOut����ǵ���Ϣʱ����¼USSPar�е�������λ��Ϣ������GUI��ʾ�����߷���                                                        **
*************************************************************************************************************************************************/
void SaveSlotInfoToUSSstOut(SLOTINFO_ST* SlotInfoTemp, char slot_dir, char slot_index)
{
#if 0//Debug_SW_InforCANOutput
    sint8 slot_start_index = (sint8)USSPar.Slot[slot_dir].SlotPar[slot_index].SlotStartIndex;
    SlotInfoTemp->SlotStartInd_CarPos_X = (sint32)(USSPar.Slot[slot_dir].SlotOutline.Lane.CarCenterPoint[slot_start_index].x);
    SlotInfoTemp->SlotStartInd_CarPos_Y = (sint32)(USSPar.Slot[slot_dir].SlotOutline.Lane.CarCenterPoint[slot_start_index].y);
    sint8 slot_end_index = (sint8)USSPar.Slot[slot_dir].SlotPar[slot_index].SlotEndIndex;
    SlotInfoTemp->SlotEndInd_CarPos_X = (sint32)(USSPar.Slot[slot_dir].SlotOutline.Lane.CarCenterPoint[slot_end_index].x);
    SlotInfoTemp->SlotEndInd_CarPos_Y = (sint32)(USSPar.Slot[slot_dir].SlotOutline.Lane.CarCenterPoint[slot_end_index].y);
    SlotInfoTemp->SlotStartInd_PtPos_X = (sint32)(USSPar.Slot[slot_dir].SlotOutline.Lane.ObjPt[slot_start_index].x);
    SlotInfoTemp->SlotStartInd_PtPos_Y = (sint32)(USSPar.Slot[slot_dir].SlotOutline.Lane.ObjPt[slot_start_index].y);
    SlotInfoTemp->SlotEndInd_PtPos_X = (sint32)(USSPar.Slot[slot_dir].SlotOutline.Lane.ObjPt[slot_end_index].x);
    SlotInfoTemp->SlotEndInd_PtPos_Y = (sint32)(USSPar.Slot[slot_dir].SlotOutline.Lane.ObjPt[slot_end_index].y);
    SlotInfoTemp->SlotPar_SlotCalDisCarToObj1 = (sint16)USSPar.Slot[slot_dir].SlotPar[slot_index].SlotCalDisCarToObj1;
    SlotInfoTemp->SlotPar_SlotCalDisCarToObj2 = (sint16)USSPar.Slot[slot_dir].SlotPar[slot_index].SlotCalDisCarToObj2;
    SlotInfoTemp->SlotPar_Type = (sint8)USSPar.Slot[slot_dir].SlotPar[slot_index].SlotType;
    SlotInfoTemp->SlotPar_Obj1EndPtIndex = (sint8)USSPar.Slot[slot_dir].SlotPar[slot_index].Obj1EndPtIndex;
    SlotInfoTemp->SlotPar_Obj1StartPtIndex = (sint8)USSPar.Slot[slot_dir].SlotPar[slot_index].Obj1StartPtIndex;
    SlotInfoTemp->SlotPar_Obj1Type = (sint8)USSPar.Slot[slot_dir].SlotPar[slot_index].Obj1Type;
    SlotInfoTemp->SlotPar_Obj2Type = (sint8)USSPar.Slot[slot_dir].SlotPar[slot_index].Obj2Type;
    SlotInfoTemp->SlotPar_Obj2EndPtIndex = (sint8)USSPar.Slot[slot_dir].SlotPar[slot_index].Obj2EndPtIndex;
    SlotInfoTemp->SlotPar_Obj2StartPtIndex = (sint8)USSPar.Slot[slot_dir].SlotPar[slot_index].Obj2StartPtIndex;
    SlotInfoTemp->SlotPar_SlotEndIndex = (sint8)USSPar.Slot[slot_dir].SlotPar[slot_index].SlotEndIndex;
    SlotInfoTemp->SlotPar_SlotStartIndex = (sint8)USSPar.Slot[slot_dir].SlotPar[slot_index].SlotStartIndex;
    SlotInfoTemp->SlotPar_SlotCompeHead = (sint16)USSPar.Slot[slot_dir].SlotPar[slot_index].APASlotDetectionCompensateLengthHead;
    SlotInfoTemp->SlotPar_SlotCompeTail = (sint16)USSPar.Slot[slot_dir].SlotPar[slot_index].APASlotDetectionCompensateLengthTail;
    SlotInfoTemp->SlotPar_SlotDepth = (sint16)USSPar.Slot[slot_dir].SlotPar[slot_index].SlotDepth;
    SlotInfoTemp->SlotPar_SlotLengthTotal = (sint16)USSPar.Slot[slot_dir].SlotPar[slot_index].SlotLengthTotal;
    ObjPtCnt = USSPar.Slot[slot_dir].SlotOutline.Lane.ObjPtCnt;
    CarPassTheSlotEndPtDistance = USSPar.Slot[slot_dir].SlotPar[slot_index].CarPassTheSlotEndPtDistance;
#endif
}

/*************************************************************************************************************************************************
** Syntax :  void BackupSlotInfoToTempStruct(void)                                                                                              **
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
** Description : �ǵ�����򱸷�USSPar�еĹؼ���Ϣ��ͨ��Can����                                                                                     **
*************************************************************************************************************************************************/
#if Debug_SW_PrivateCANForIntegration
void BackupSlotInfoToTempStruct(char slot_dir, char slot_index)
{
    sint8 slot_start_index = (sint8)USSPar.Slot[slot_dir].SlotPar[slot_index].SlotStartIndex;
    SlotInfoToOutput[slot_dir].SlotStartInd_CarPos_X = (sint32)(USSPar.Slot[slot_dir].SlotOutline.Lane.CarCenterPoint[slot_start_index].x);
    SlotInfoToOutput[slot_dir].SlotStartInd_CarPos_Y = (sint32)(USSPar.Slot[slot_dir].SlotOutline.Lane.CarCenterPoint[slot_start_index].y);
    sint8 slot_end_index = (sint8)USSPar.Slot[slot_dir].SlotPar[slot_index].SlotEndIndex;
    SlotInfoToOutput[slot_dir].SlotEndInd_CarPos_X = (sint32)(USSPar.Slot[slot_dir].SlotOutline.Lane.CarCenterPoint[slot_end_index].x);
    SlotInfoToOutput[slot_dir].SlotEndInd_CarPos_Y = (sint32)(USSPar.Slot[slot_dir].SlotOutline.Lane.CarCenterPoint[slot_end_index].y);
    SlotInfoToOutput[slot_dir].SlotStartInd_PtPos_X = (sint32)(USSPar.Slot[slot_dir].SlotOutline.Lane.ObjPt[slot_start_index].x);
    SlotInfoToOutput[slot_dir].SlotStartInd_PtPos_Y = (sint32)(USSPar.Slot[slot_dir].SlotOutline.Lane.ObjPt[slot_start_index].y);
    SlotInfoToOutput[slot_dir].SlotEndInd_PtPos_X = (sint32)(USSPar.Slot[slot_dir].SlotOutline.Lane.ObjPt[slot_end_index].x);
    SlotInfoToOutput[slot_dir].SlotEndInd_PtPos_Y = (sint32)(USSPar.Slot[slot_dir].SlotOutline.Lane.ObjPt[slot_end_index].y);
    SlotInfoToOutput[slot_dir].SlotPar_SlotCalDisCarToObj1 = (sint16)USSPar.Slot[slot_dir].SlotPar[slot_index].SlotCalDisCarToObj1;
    SlotInfoToOutput[slot_dir].SlotPar_SlotCalDisCarToObj2 = (sint16)USSPar.Slot[slot_dir].SlotPar[slot_index].SlotCalDisCarToObj2;
    SlotInfoToOutput[slot_dir].SlotPar_Type = (sint8)USSPar.Slot[slot_dir].SlotPar[slot_index].SlotType;
    SlotInfoToOutput[slot_dir].SlotPar_Obj1EndPtIndex = (sint8)USSPar.Slot[slot_dir].SlotPar[slot_index].Obj1EndPtIndex;
    SlotInfoToOutput[slot_dir].SlotPar_Obj1StartPtIndex = (sint8)USSPar.Slot[slot_dir].SlotPar[slot_index].Obj1StartPtIndex;
    SlotInfoToOutput[slot_dir].SlotPar_Obj1Type = (sint8)USSPar.Slot[slot_dir].SlotPar[slot_index].Obj1Type;
    SlotInfoToOutput[slot_dir].SlotPar_Obj2Type = (sint8)USSPar.Slot[slot_dir].SlotPar[slot_index].Obj2Type;
    SlotInfoToOutput[slot_dir].SlotPar_Obj2EndPtIndex = (sint8)USSPar.Slot[slot_dir].SlotPar[slot_index].Obj2EndPtIndex;
    SlotInfoToOutput[slot_dir].SlotPar_Obj2StartPtIndex = (sint8)USSPar.Slot[slot_dir].SlotPar[slot_index].Obj2StartPtIndex;
    SlotInfoToOutput[slot_dir].SlotPar_SlotEndIndex = (sint8)USSPar.Slot[slot_dir].SlotPar[slot_index].SlotEndIndex;
    SlotInfoToOutput[slot_dir].SlotPar_SlotStartIndex = (sint8)USSPar.Slot[slot_dir].SlotPar[slot_index].SlotStartIndex;
    SlotInfoToOutput[slot_dir].SlotPar_SlotCompeHead = (sint16)USSPar.Slot[slot_dir].SlotPar[slot_index].APASlotDetectionCompensateLengthHead;
    SlotInfoToOutput[slot_dir].SlotPar_SlotCompeTail = (sint16)USSPar.Slot[slot_dir].SlotPar[slot_index].APASlotDetectionCompensateLengthTail;
    SlotInfoToOutput[slot_dir].SlotPar_SlotDepth = (sint16)USSPar.Slot[slot_dir].SlotPar[slot_index].SlotDepth;
    SlotInfoToOutput[slot_dir].SlotPar_SlotLengthTotal = (sint16)USSPar.Slot[slot_dir].SlotPar[slot_index].SlotLengthTotal;
    SlotInfoToOutput[slot_dir].ObjPtCnt = USSPar.Slot[slot_dir].SlotOutline.Lane.ObjPtCnt;
    SlotInfoToOutput[slot_dir].CarPassTheSlotEndPtDistance = USSPar.Slot[slot_dir].SlotPar[slot_index].CarPassTheSlotEndPtDistance;
}
#endif
/*************************************************************************************************************************************************
** Syntax : APA_DISTANCE_TYPE GetSlotEdgeCompensateValuePosX(sint8 EdgeType, APA_DISTANCE_TYPE DistanceAtPassEdge, APA_SPEED_TYPE SpdAtPassEdge)**
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
** Description : ��ȡtask�����Ľ����������USS��������(ģ�����������u8USS_OnStates)������ǻ���DR����ϵ                                            **
*************************************************************************************************************************************************/
APA_DISTANCE_TYPE GetSlotEdgeCompensateValuePosX(sint8 EdgeType, APA_DISTANCE_TYPE DistanceAtPassEdge, APA_SPEED_TYPE SpdAtPassEdge)
{
	uint8 u8DistanceIndex = 0;
	uint8 u8SpdIndex = 0;
	APA_DISTANCE_TYPE EdgeCompValue = 0;
	if(EdgeType == -1)
	{
	}
	else
	{
		for(u8DistanceIndex= 0;u8DistanceIndex < POSXCOMPTABLESIZE_DISTANCE;u8DistanceIndex++)
		{
			if(DistanceAtPassEdge < EdgePosxCompTable_Distance[u8DistanceIndex])
			{
				break;
			}
		}
        if(u8DistanceIndex ==POSXCOMPTABLESIZE_DISTANCE)
        {
            u8DistanceIndex = POSXCOMPTABLESIZE_DISTANCE-1;
        }

		for(u8SpdIndex= 0;u8SpdIndex < POSXCOMPTABLESIZE_SPEED;u8SpdIndex++)
		{
			if(SpdAtPassEdge < EdgePosxCompTable_Speed[u8SpdIndex])
			{
				break;
			}
		}
        if(u8SpdIndex ==POSXCOMPTABLESIZE_SPEED)
        {
            u8SpdIndex = POSXCOMPTABLESIZE_SPEED-1;
        }
                
		 if(EdgeType == 0)
		 {
			 EdgeCompValue = Edge0CompTablePosX[u8DistanceIndex][u8SpdIndex];
		 }
		 else if(EdgeType == 1)
		 {
			 EdgeCompValue = Edge1CompTablePosX[u8DistanceIndex][u8SpdIndex];
		 }
		 else
		 {

		 }
	}
	return EdgeCompValue;
}

/*************************************************************************************************************************************************
** Syntax :  BOOLEAN LineParCalBaseUSSCoord(APA_INDEX_TYPE StartIndex,APA_INDEX_TYPE EndIndex,APALineParameterABCType *pCurbLine)               **
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
** Description :                                                                                                                                **
*************************************************************************************************************************************************/
BOOLEAN LineParCalBaseUSSCoord(uint8 u8SlotSide,APA_INDEX_TYPE StartIndex,APA_INDEX_TYPE EndIndex,APALineParameterABCType *pCurbLine)
{
    APA_DISTANCE_CAL_FLOAT_TYPE mX, mY, mXX, mXY, fTemp, fDis1, fDis2;
    APA_DISTANCE_TYPE Dis1, Dis2, Dis3, ValidLineLen;
    APA_ANGLE_CAL_FLOAT_TYPE BorderLineAng;
    APA_INDEX_TYPE ObjPtCnt, d, g, h, m,i,j;
    BOOLEAN bLineIsHorizontal, bValidObjPtFound;
    APA_DISTANCE_TYPE ValidCurbObjDistance[APA_TRAJCAL_CURB_LINE_FIT_MAX_SUPPORT_OBJ_NUM];   // curb���г���15���ķ��գ������case
    APA_INDEX_TYPE TotalValidObjNum,ValidObjIndex[APA_TRAJCAL_CURB_LINE_FIT_MAX_SUPPORT_OBJ_NUM]; // curb ���г���15���ķ���
    APASlotOutlineCoordinateDataType *pMainSlot;
//step0: �ж�����յ�֮�������Ƿ��㹻
    if((EndIndex -StartIndex)<3)
    {
        return FALSE;
    }

    pMainSlot = &USSPar.Slot[u8SlotSide].SlotOutline.Lane;
//step1: ͳ�Ʒ���·�ؼ��������ĵ㣨���ϰ����Ҿ������2m���ٸ�����Ч���ж�ǰ����ϰ�������С��20cm����Ϊ�õ����·�ؼ���������
    j = 0;
    TotalValidObjNum = 0;
    for(i=StartIndex;i<=EndIndex;i++)
    {
        if((pMainSlot->DisFromCarToObj[i] != NO_OBJ_DISTANCE)
           &&(pMainSlot->DisFromCarToObj[i]>2000))
        {
            ValidCurbObjDistance[j] = pMainSlot->DisFromCarToObj[i];
            ValidObjIndex[j] = i;
            TotalValidObjNum++;
            j++;
            if(j >=15)
            {
                break;
            }
        }
    }

    if(TotalValidObjNum >= APACal.APASlotCurbLineFitAllowMinObjPt)
    {
         g = 0;
        for(i=0;i<TotalValidObjNum;i++)
        {
            if(((MATH_ABS(ValidCurbObjDistance[i]-ValidCurbObjDistance[i+1])<200)&&(i<14))
            ||((MATH_ABS(ValidCurbObjDistance[i]-ValidCurbObjDistance[i-1])<200)&&(i>=1)))
            {  //i��ǰ����ϰ�������ֵС��20cm���õ���Ч����������·������ϼ���
                g++;
            }
        }
    }
    else
    {
        return FALSE;
    }
    
//step2: �������·�ؼ���ĵ�֮��ľ���ͳ�λ֮������ռ�ȣ�ȷ���Ƿ���Խ���·�ؼ��㣨�ο�ԭ�棩
    if (g >= APACal.APASlotCurbLineFitAllowMinObjPt)  // 3
    { 
        ValidLineLen = APATrajCalGetTwoPointDisInt(pMainSlot->CarCenterPoint[StartIndex].x,
                                                   pMainSlot->CarCenterPoint[StartIndex].y,
                                                   pMainSlot->CarCenterPoint[EndIndex].x,
                                                   pMainSlot->CarCenterPoint[EndIndex].y);
        m    = ValidObjIndex[TotalValidObjNum - 1];                     // end point
        h    = ValidObjIndex[0];                                        // Start point
        Dis1 = APATrajCalGetTwoPointDisInt( pMainSlot->CarCenterPoint[h].x,
                                            pMainSlot->CarCenterPoint[h].y,
                                            pMainSlot->CarCenterPoint[m].x,
                                            pMainSlot->CarCenterPoint[m].y);
        ValidLineLen *= 6;
        ValidLineLen /= 10;
        if (ValidLineLen < APACal.APASlotCurbLineFitAllowMinCurbLength) // 1.5m
        { 
            ValidLineLen = APACal.APASlotCurbLineFitAllowMinCurbLength; // 1.5m
        }
        if ((Dis1 < 1000) 
            ||(MATH_FABS(pMainSlot->CarAng[h] - pMainSlot->CarAng[m]) > (PI/2.0))) 
        {// �޷������������������1.��Ч·�ؼ������β����С�ڳ�λ��β���60%������ 2.��Ч·����β�����֮��ĽǶȲ�ֵ����PI/2
            return FALSE;
        } 
    }
    else
    {
        return FALSE;
    }
    
//step3: ·������ϼ���
    mX  = 0;
    mY  = 0;
    mXX = 0;
    mXY = 0;

    for (g = 0; g < TotalValidObjNum; g++) 
    {
        d     = ValidObjIndex[g];
        fDis1 = (float)(pMainSlot->ObjPt[d].y/1000.0); // ********** Switch the X and Y coordinate due to the calculation accuracy of vertical line.
        fDis2 = (float)(pMainSlot->ObjPt[d].x/1000.0);
        mX += fDis1;
        mY += fDis2;
        mXX += fDis1 * fDis1;
        mXY += fDis1 * fDis2;
    }
    fTemp = TotalValidObjNum;
    fDis1 = mX * mX - mXX * fTemp;

    if (MATH_FABS(fDis1) < 0.0001) 
    {// Is it a horizontal line,
        bLineIsHorizontal = TRUE;
    } 
    else 
    {
        fDis2             = (mY * mX - mXY * fTemp) / fDis1; // Line: Y = KX + B => K,
        bLineIsHorizontal = FALSE;
    }

    if ((bLineIsHorizontal == TRUE) || (MATH_FABS(fDis2) < APACal.APATrajCalLineIsHMinK)) 
    {// Actually it is vertical line. due to we have switch the X Y coordinate.
        if (MATH_FABS(pMainSlot->CarAng[h]) > APACal.APASlotCurbLineFitAllowMaxDeltaCarAngAndCurbLineAng) 
        {// Data error
            return FALSE;
        }

        if(MATH_FABS(fTemp) > 0.0001)  // ���ӳ���������
        {
            pCurbLine->A         = 1;
            pCurbLine->B         = 0;
            pCurbLine->LineType  = APALineIsVertical;
            pCurbLine->C         = -mY / fTemp;
        }
        else
        {
            return FALSE;
        }
        
       
    } 
    else 
    {
        BorderLineAng = -MATH_ATAN(fDis2);

        if(MATH_FABS(fTemp) > 0.0001)      // ���ӳ���������
        {
            fDis1 = (mY - mX * fDis2) / fTemp; // Line: Y = KX + B => B,
        }
        else
        {
            return FALSE;
        }
      

        if(MATH_FABS(fDis2) >0.0001)      // ���ӳ���������
        {
            if ((MATH_FABS(BorderLineAng) < APACal.APASlotCurbLineFitAllowMaxCurbLineAndYAng) 
            &&(MATH_FABS(pMainSlot->CarAng[h] - (BorderLineAng)) < APACal.APASlotCurbLineFitAllowMaxDeltaCarAngAndCurbLineAng)
            &&(MATH_FABS(pMainSlot->CarAng[m] - (BorderLineAng)) < APACal.APASlotCurbLineFitAllowMaxDeltaCarAngAndCurbLineAng)) 
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
        }
        else
        {
            return FALSE;
        }
       
    }
    return TRUE;
}

/*************************************************************************************************************************************************
** Syntax :  uint8 USSCheckSlotDepth(uint8 SlotAddType,                                                                                           **
**                                 uint8 u8SlotSide,                                                                                            **
**                                 uint8 u8SlotNumBackup,                                                                                       **
**                                 uint8 u8SlotNumCur,                                                                                          **
**                                 APACarCoordinateDataCalFloatType CarCurPosCoord)                                                             **
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
** Description :                                             **
*************************************************************************************************************************************************/
void USSCheckSlotDepth(uint8 u8SlotSide,
                       uint8 u8SlotNumCur,  
                       APA_DISTANCE_TYPE *SlotDepthFromUSS,
                       APA_INDEX_TYPE *CurbStartIndex,
                       APA_INDEX_TYPE *CurbEndIndex)
{ 
    sint8 i = 0;
    uint8 u8EdgeSts = 0;  //0-default,1-edge0-actual/edge1-virtual,2-edge0-virtual/edge1-actual,3-edge0-actual/edge1-actual
    APA_INDEX_TYPE Obj1StartIndex = 0;
    APA_INDEX_TYPE Obj1EndIndex = 0;
    APA_INDEX_TYPE Obj2StartIndex = 0;
    APA_INDEX_TYPE Obj2EndIndex = 0;
    APA_INDEX_TYPE SlotStartIndex = 0;
    APA_INDEX_TYPE SlotEndIndex = 0;
    APA_INDEX_TYPE ObjPtCnt = 0 ;
    APA_INDEX_TYPE MinObj1DistanceIndex = 0;
    APA_INDEX_TYPE MinObj2DistanceIndex = 0;
    APA_DISTANCE_TYPE MinDisCarToObj1ByPassingSlot = NO_OBJ_DISTANCE;
    APA_DISTANCE_TYPE MinDisCarToObj2ByPassingSlot = NO_OBJ_DISTANCE;
    APA_DISTANCE_TYPE MinDisCarToObjByPassingSlotTem = NO_OBJ_DISTANCE;
    APA_DISTANCE_TYPE X1 = 0;
    APA_DISTANCE_CAL_INT_TYPE Dis1 = 0;
    APA_DISTANCE_CAL_FLOAT_TYPE Delta_X = 0.0;
    APA_DISTANCE_CAL_FLOAT_TYPE Delta_Y = 0.0;
    APA_DISTANCE_CAL_FLOAT_TYPE TanResult = 0.0;
    APASlotOutlineCoordinateDataType *pMainSlot;

    pMainSlot      = &USSPar.Slot[u8SlotSide].SlotOutline.Lane;
    ObjPtCnt = pMainSlot->ObjPtCnt;
    SlotStartIndex = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].SlotStartIndex;
    SlotEndIndex = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].SlotEndIndex;
    Obj1StartIndex = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].Obj1StartPtIndex;
    Obj1EndIndex   = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].Obj1EndPtIndex;
    Obj2StartIndex = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].Obj2StartPtIndex;
    Obj2EndIndex   = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].Obj2EndPtIndex;
//step 0:�ж���λ���ص�״̬���Ƿ��������
    if((Obj2StartIndex == Obj2EndIndex) 
       || ((Obj2StartIndex != Obj2EndIndex) && (Obj2EndIndex == ObjPtCnt)))
    {
        if(Obj1StartIndex == Obj1EndIndex)
        {
            u8EdgeSts = 0;  //û�г�λ��ʵ�ʲ����ܴﵽ
        }
        else
        {
            u8EdgeSts = 0x01;  //edge1����
        }
    }
    else
    {
        if(Obj1StartIndex == Obj1EndIndex)
        {
            u8EdgeSts = 0x02;  //edge0����
        }
        else
        {
            u8EdgeSts = 0x03;  //edge������ʵ��
        }
    }
    
//step 1:����obj1����Ч��׼��
    if(u8EdgeSts&0x01)  //edge0��ʵ��
    {
        for(i=SlotStartIndex;i>=Obj1EndIndex;i--)
        {
            if(pMainSlot->DisFromCarToObj[i] != NO_OBJ_DISTANCE && pMainSlot->DisFromCarToObj[i] <MinDisCarToObj1ByPassingSlot) //��slotstart�㵽obj1end֮����ҵ�һ����Ч����ĵ�
            {
                MinDisCarToObj1ByPassingSlot = pMainSlot->DisFromCarToObj[i];
                MinObj1DistanceIndex  = i;
                Dis1 = APATrajCalGetTwoPointDisInt(pMainSlot->CarCenterPoint[SlotStartIndex].x,
                                                    pMainSlot->CarCenterPoint[SlotStartIndex].y,
                                                    pMainSlot->CarCenterPoint[i].x,
                                                    pMainSlot->CarCenterPoint[i].y);
                if (Dis1 > 500)
                {
                    break;
                }
            }
            else
            {
            }
        }

        for(i=MinObj1DistanceIndex+1; i<=Obj2StartIndex-1; i++)
        {
            Delta_X = MATH_ABS(pMainSlot->ObjPt[i].x - pMainSlot->ObjPt[MinObj1DistanceIndex].x);
            Delta_Y = MATH_ABS(pMainSlot->ObjPt[i].y - pMainSlot->ObjPt[MinObj1DistanceIndex].y);
            if(fabs(Delta_X) > 0.0001)
            {
                TanResult = Delta_Y/Delta_X;
                if((pMainSlot->DisFromCarToObj[i]> MinDisCarToObj1ByPassingSlot)
                    &&(pMainSlot->DisFromCarToObj[i] != NO_OBJ_DISTANCE)
                    &&((pMainSlot->DisFromCarToObj[i] - MinDisCarToObj1ByPassingSlot)>1400)
                    &&(MATH_ATAN(TanResult) >(20*PI/180)))
                {
                    (*CurbStartIndex) = i;
                    break;
                }
            }
            else
            {
                /* code */
            }
        }
    }
    else
    {
        (*CurbStartIndex) = Obj1StartIndex; 
    }
//step 2:����obj2����Ч��׼��

    if(u8EdgeSts&0x02)
    {
        for(i=SlotEndIndex;i< Obj2EndIndex;i++)
        {
            if(pMainSlot->DisFromCarToObj[i] != NO_OBJ_DISTANCE && pMainSlot->DisFromCarToObj[i] <MinDisCarToObj2ByPassingSlot)
            {
                MinDisCarToObj2ByPassingSlot = pMainSlot->DisFromCarToObj[i];
                MinObj2DistanceIndex  = i;
                Dis1 = APATrajCalGetTwoPointDisInt(pMainSlot->CarCenterPoint[SlotEndIndex].x,
                                    pMainSlot->CarCenterPoint[SlotEndIndex].y,
                                    pMainSlot->CarCenterPoint[i].x,
                                    pMainSlot->CarCenterPoint[i].y);
                if (Dis1 > 500)
                {
                    break;
                }
            }
            else
            {
            }
        }
        for(i=MinObj2DistanceIndex-1; i>=Obj1StartIndex+1; i--)
        {
            Delta_X = MATH_ABS(pMainSlot->ObjPt[i].x - pMainSlot->ObjPt[MinObj2DistanceIndex].x);
            Delta_Y = MATH_ABS(pMainSlot->ObjPt[i].y - pMainSlot->ObjPt[MinObj2DistanceIndex].y);
            if(fabs(Delta_X) > 0.0001)
            {
                TanResult = Delta_Y/Delta_X;
                if((pMainSlot->DisFromCarToObj[i]> MinDisCarToObj2ByPassingSlot)
                    &&(pMainSlot->DisFromCarToObj[i] != NO_OBJ_DISTANCE)
                    &&((pMainSlot->DisFromCarToObj[i] - MinDisCarToObj2ByPassingSlot)>1400)
                    &&(MATH_ATAN(TanResult) >(20*PI/180)))
                {
                    (*CurbEndIndex) = i;
                    break;
                }
            }
            else
            {
                /* code */
            }
        }
    }
    else
    {
        (*CurbEndIndex) = Obj2StartIndex; 
    }

//step4����curb�����յ�֮����Ҽ����������ֵ
    if(MinDisCarToObj1ByPassingSlot < MinDisCarToObj2ByPassingSlot)
    {
        X1 = MinDisCarToObj1ByPassingSlot;
    }
    else
    {
        X1 = MinDisCarToObj2ByPassingSlot;
    }
    
    if(((*CurbEndIndex) > (*CurbStartIndex))
        &&(((*CurbEndIndex)-(*CurbStartIndex))>=2))
    {
        MinDisCarToObjByPassingSlotTem = NO_OBJ_DISTANCE;
        for(i = (*CurbStartIndex);i<=(*CurbEndIndex);i++)
        {
            if(pMainSlot->DisFromCarToObj[i] < MinDisCarToObjByPassingSlotTem 
                && (pMainSlot->DisFromCarToObj[i] - X1) > 1400 
                && pMainSlot->DisFromCarToObj[i] != NO_OBJ_DISTANCE )
            {
                MinDisCarToObjByPassingSlotTem = pMainSlot->DisFromCarToObj[i];
            }
        }
        (*SlotDepthFromUSS) = MinDisCarToObjByPassingSlotTem - X1;
    }
    else
    {
        (*SlotDepthFromUSS) = NO_OBJ_DISTANCE;
        (*CurbStartIndex) = 0;
        (*CurbEndIndex) = 0;
    }
}

// ����Ƕ�ƫ����������
#if 1
APACoordinateDataCalFloatType CalVirtualEdgeNew(uint8 u8SlotSide, sint8 VirtualType, APA_INDEX_TYPE *VirtualPtIndex, APA_INDEX_TYPE ObjEndIndex, APA_DISTANCE_TYPE* PEdgeCompendateTemp, APACoordinateDataCalFloatType* EdgeMaybeOutputInUSS)
{
    APACoordinateDataCalFloatType EdgeResult, EdgeBaseCar, CarPoseTem, EdgeBaseUSS, EdgePosBaseDR, EdgeTemp, CarPoseTem2, EdgeBaseUSS2, PtTem;
    APA_INDEX_TYPE SlotStartPosIndex = -1;
    APA_DISTANCE_TYPE SlotLengthTemp = 0;
    APA_DISTANCE_TYPE X01 = 0;
    APA_DISTANCE_TYPE Y01 = 0;
    APA_DISTANCE_TYPE X02 = 0;
    APA_DISTANCE_TYPE Y02 = 0;
    APA_DISTANCE_TYPE X1, AX, BX, CX, ACarCenterX;
    APA_DISTANCE_TYPE Y1, AY, BY, CY, ACarCenterY;
    sint8 SlotNumCur = 0;
    APA_INDEX_TYPE UnVirtualEdgeIndex, StartIndex, EndIndex;
    APA_DISTANCE_TYPE EdgeDistanceTemp, EdgeCompensate, Dis1, Dis2,Dis3;
    float Weight ;
    APA_DISTANCE_TYPE EdgeYTestTem = NO_OBJ_DISTANCE;
    APA_INDEX_TYPE SlotEdgeIndex;
    float DeltaY, DeltaX;
    float VirtualPtXInUSS = 0.0;
    float VirtualPtYInUSS = 0.0;

    sint8 i = 0; // ѭ����������

    EdgeResult.x = -1;
    EdgeResult.y = -1;
    (*VirtualPtIndex) = -1;
    SlotNumCur = USSPar.Slot[u8SlotSide].SlotNum;

    if(SlotNumCur <= 0 )
    {
    	return EdgeResult;
    }
    if (VirtualType == EDGETYPE_0) //Edge0 ����
    {
        StartIndex = USSPar.Slot[u8SlotSide].SlotPar[SlotNumCur - 1].SlotStartIndex;
        EndIndex  = USSPar.Slot[u8SlotSide].SlotPar[SlotNumCur - 1].SlotEndIndex;
        UnVirtualEdgeIndex = EndIndex;
        SlotEdgeIndex   = USSPar.Slot[u8SlotSide].SlotPar[SlotNumCur - 1].SlotEndIndex;
        EdgeDistanceTemp = USSPar.Slot[u8SlotSide].SlotPar[SlotNumCur-1].SlotCalDisCarToObj2;
        //EdgeDistanceTemp = USSPar.Slot[u8SlotSide].SlotPar[SlotNumCur-1].SlotCalDisCarToObj2;
    }
    else if (VirtualType == EDGETYPE_1) //Edge1 ����
    {
        StartIndex = USSPar.Slot[u8SlotSide].SlotPar[SlotNumCur - 1].SlotEndIndex;
        EndIndex  = USSPar.Slot[u8SlotSide].SlotPar[SlotNumCur - 1].SlotStartIndex;
        UnVirtualEdgeIndex = EndIndex;
        SlotEdgeIndex   = USSPar.Slot[u8SlotSide].SlotPar[SlotNumCur - 1].SlotStartIndex;
        EdgeDistanceTemp = USSPar.Slot[u8SlotSide].SlotPar[SlotNumCur-1].SlotCalDisCarToObj1;
        //EdgeDistanceTemp = USSPar.Slot[u8SlotSide].SlotPar[SlotNumCur-1].SlotCalDisCarToObj1;
    }
    else
    {
       
    }
    // EdgeCompensate = GetSlotEdgeCompensateValuePosX(VirtualType,EdgeDistanceTemp, 0);
    EdgeCompensate = (*PEdgeCompendateTemp);
    X1 = USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarCenterPoint[UnVirtualEdgeIndex].x;
    Y1 = USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarCenterPoint[UnVirtualEdgeIndex].y;
    ACarCenterX = X1;
    ACarCenterY = Y1 + EdgeCompensate;
    AY =  USSPar.Slot[u8SlotSide].SlotOutline.Lane.ObjPt[UnVirtualEdgeIndex].y + EdgeCompensate;
    EdgeYTestTem = FindMinDis(SlotEdgeIndex, ObjEndIndex, u8SlotSide);

#if YDevationCompeFunc_FindMinDis
        if(EdgeYTestTem != NO_OBJ_DISTANCE)
        {
            EdgePtBaseUSSCoordTemp0.x = EdgeYTestTem + APACal.HalfWidthOfCar;
        }
        else
        {
            EdgePtBaseUSSCoordTemp0.x = EdgeDistanceTemp + APACal.HalfWidthOfCar;
        }
#endif
        if(u8SlotSide == RIGHT)
        {
            EdgeBaseCar.x = EdgePtBaseUSSCoordTemp0.x;
            EdgeBaseCar.y = APACal.SnsPos[6].y;
        }
        else
        {
            EdgeBaseCar.x = -EdgePtBaseUSSCoordTemp0.x;
            EdgeBaseCar.y = APACal.SnsPos[11].y;
        }
     // �ӳ�������ϵת��USS����ϵ
        CarPoseTem.x = (float32)USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarCenterPoint[UnVirtualEdgeIndex].x;
        CarPoseTem.y = (float32)USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarCenterPoint[UnVirtualEdgeIndex].y;      
        PtTem = APATrajCalPointPosWithAngAndCenterPt(EdgeBaseCar, USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarAng[UnVirtualEdgeIndex], CarPoseTem);
    AX = PtTem.x;
    if(VirtualType == EDGETYPE_0)
    {
       
        for(i=StartIndex;i<EndIndex; i++)
        {
             // �ӳ�������ϵת��USS����ϵ
            CarPoseTem.x = (float32)USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarCenterPoint[i].x;
            CarPoseTem.y = (float32)USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarCenterPoint[i].y;      
            PtTem = APATrajCalPointPosWithAngAndCenterPt(EdgeBaseCar, USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarAng[i], CarPoseTem);

            X01 = PtTem.x;
            Y01 = USSPar.Slot[u8SlotSide].SlotOutline.Lane.ObjPt[i].y;
            SlotLengthTemp = APATrajCalGetTwoPointDisInt(X01, Y01, AX, AY);
            //if((SlotLengthTemp + EdgeCompensate) < 7200)
            if(SlotLengthTemp < 7200)
            {
                
                break;
            }
            else
            {
            }      
        }
    }
    else if(VirtualType == EDGETYPE_1)
    {
        for(i=StartIndex;i>EndIndex; i--)
        {
            if (i < 0)
            {
                return EdgeResult;
            }
               // �ӳ�������ϵת��USS����ϵ
            CarPoseTem.x = (float32)USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarCenterPoint[i].x;
            CarPoseTem.y = (float32)USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarCenterPoint[i].y;      
            PtTem = APATrajCalPointPosWithAngAndCenterPt(EdgeBaseCar, USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarAng[i], CarPoseTem);
            X01 = PtTem.x;
            Y01 = USSPar.Slot[u8SlotSide].SlotOutline.Lane.ObjPt[i].y;
            SlotLengthTemp = APATrajCalGetTwoPointDisInt(X01, Y01,AX, AY);
            //if((SlotLengthTemp + EdgeCompensate) < 7200)
            if(SlotLengthTemp  < 7200)
            {
                break;
            }
            else
            {
            }      
        }
    }
    else
    {
        
    }
    

    if(VirtualType == EDGETYPE_0)
    {
        if(i-1 >= 0)
        {
#if 1        
             // �ӳ�������ϵת��USS����ϵ
            CarPoseTem.x = (float32)USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarCenterPoint[i].x;
            CarPoseTem.y = (float32)USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarCenterPoint[i].y;      
            EdgeBaseUSS = APATrajCalPointPosWithAngAndCenterPt(EdgeBaseCar, USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarAng[i], CarPoseTem);
            CarPoseTem2.x = (float32)USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarCenterPoint[i-1].x;
            CarPoseTem2.y = (float32)USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarCenterPoint[i-1].y;      
            EdgeBaseUSS2 = APATrajCalPointPosWithAngAndCenterPt(EdgeBaseCar, USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarAng[i-1], CarPoseTem2);
            BY = USSPar.Slot[u8SlotSide].SlotOutline.Lane.ObjPt[i].y;
            BX = EdgeBaseUSS.x;
            CY = USSPar.Slot[u8SlotSide].SlotOutline.Lane.ObjPt[i-1].y;
            CX = EdgeBaseUSS2.x;

            // X01 = USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarCenterPoint[i].x;
            // Y01 = USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarCenterPoint[i].y;
            // Dis1 = APATrajCalGetTwoPointDisInt(ACarCenterX, ACarCenterY, X01, Y01);
            // X02 = USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarCenterPoint[i-1].x;
            // Y02 = USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarCenterPoint[i-1].y;
            // Dis2 = APATrajCalGetTwoPointDisInt(ACarCenterX, ACarCenterY, X02, Y02);

            Dis1 = APATrajCalGetTwoPointDisInt(AX, AY, BX, BY);
            Dis2 = APATrajCalGetTwoPointDisInt(AX, AY, CX, CY);
            Weight = (MATH_FABS(Dis1 - VIRTUALSLOTLENGTH)* 1.0) / (MATH_FABS(Dis1 - VIRTUALSLOTLENGTH) + MATH_FABS(Dis2 - VIRTUALSLOTLENGTH));
            VirtualPtXInUSS = BX*(1 - Weight) + Weight*CX;
            VirtualPtYInUSS = BY*(1 - Weight) + Weight*CY;
            (*VirtualPtIndex) = i - 1;
        }
        else
        {
            return EdgeResult;
        }

#endif
    }
    else if (VirtualType == EDGETYPE_1) //Edge1 ����
    {
        if(i+1 <= APA_SLOT_SUPPORT_FRONT_SIDE_MAX_SAMPLE_POINT_NUM - 1)
        {
#if 1        
             // �ӳ�������ϵת��USS����ϵ
            CarPoseTem.x = (float32)USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarCenterPoint[i].x;
            CarPoseTem.y = (float32)USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarCenterPoint[i].y;      
            EdgeBaseUSS = APATrajCalPointPosWithAngAndCenterPt(EdgeBaseCar, USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarAng[i], CarPoseTem);
            CarPoseTem2.x = (float32)USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarCenterPoint[i+1].x;
            CarPoseTem2.y = (float32)USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarCenterPoint[i+1].y;      
            EdgeBaseUSS2 = APATrajCalPointPosWithAngAndCenterPt(EdgeBaseCar, USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarAng[i+1], CarPoseTem2);
            BY = USSPar.Slot[u8SlotSide].SlotOutline.Lane.ObjPt[i].y;
            BX = EdgeBaseUSS.x;
            CY = USSPar.Slot[u8SlotSide].SlotOutline.Lane.ObjPt[i+1].y;
            CX = EdgeBaseUSS2.x;

            // X01 = USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarCenterPoint[i].x;
            // Y01 = USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarCenterPoint[i].y;
            // Dis1 = APATrajCalGetTwoPointDisInt(ACarCenterX, ACarCenterY, X01, Y01);
            // X02 = USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarCenterPoint[i+1].x;
            // Y02 = USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarCenterPoint[i+1].y;
            // Dis2 = APATrajCalGetTwoPointDisInt(ACarCenterX, ACarCenterY, X02, Y02);

            Dis1 = APATrajCalGetTwoPointDisInt(AX, AY, BX, BY);
            Dis2 = APATrajCalGetTwoPointDisInt(AX, AY, CX, CY);
            Weight = (MATH_FABS(Dis1 - VIRTUALSLOTLENGTH)* 1.0) / (MATH_FABS(Dis1 - VIRTUALSLOTLENGTH) + MATH_FABS(Dis2 - VIRTUALSLOTLENGTH));
            VirtualPtXInUSS = BX*(1 - Weight) + Weight*CX;
            VirtualPtYInUSS = BY*(1 - Weight) + Weight*CY;
            (*VirtualPtIndex) = i + 1;
        }
        else
        {
            return EdgeResult;
        }
#endif
    }
    else
    {
        /* code */
    }

    //EdgeCompensate = GetSlotEdgeCompensateValuePosX(Edge0OrEdge1,EdgeDistanceTemp, 0);

    /*edge0 calculate */
    // ��USS����ϵת��DR����ϵ
    EdgePtBaseUSSCoordTemp0.x = VirtualPtXInUSS;
    // EdgePtBaseUSSCoordTemp0.y = USSPar.Slot[u8SlotSide].SlotOutline.Lane.ObjPt[VirtualPtIndex].y;
    EdgePtBaseUSSCoordTemp0.y = VirtualPtYInUSS;
    EdgeTemp.x = EdgePtBaseUSSCoordTemp0.x;
    EdgeTemp.y = EdgePtBaseUSSCoordTemp0.y;
    (*EdgeMaybeOutputInUSS) = EdgeTemp;
    EdgePosBaseDR = USS_CoordTransforToDR(EdgePtBaseUSSCoordTemp0,CenterAngBackup3,CenterPtBackup3);
    EdgeResult.x = EdgePosBaseDR.x;
    EdgeResult.y = EdgePosBaseDR.y;
    return EdgeResult;         
}
#endif


APACoordinateDataCalFloatType CalEdge(uint8 u8SlotSide, sint8 Edge0OrEdge1,APA_INDEX_TYPE ObjEndIndex, APACoordinateDataCalFloatType* EdgeMaybeOutputInUSS, APA_DISTANCE_TYPE* PEdgeCompensateValue)
{
    sint8 u8SlotNumCur;
    APACoordinateDataCalFloatType EdgeResut;
    APACoordinateDataCalFloatType EdgeBaseCar, CarPoseTem, EdgeBaseUSS,EdgeTemp;
    APACoordinateDataCalFloatType EdgePosBaseDR;
    APA_INDEX_TYPE  FindMinSlotEdgeIndex, SlotEdgeIndex, FindMinObjIndex;;
    APA_DISTANCE_TYPE EdgeDistanceTemp, EdgeCompensate;
    APA_DISTANCE_TYPE EdgeYTestTem = NO_OBJ_DISTANCE;
    APA_INDEX_TYPE ObjStartIndexTemp, ObjEndIndexTemp, Obj2StartIndexTemp;
    APA_ENUM_TYPE ObjPtCnt;
    uint8 VirtualOrNot = 0;
    uint8 SlotTypeTemp = 0;

    EdgeResut.x = -1.0;
    EdgeResut.y = -1.0;
    u8SlotNumCur = USSPar.Slot[u8SlotSide].SlotNum;
    ObjPtCnt = USSPar.Slot[u8SlotSide].SlotOutline.Lane.ObjPtCnt;

    if (u8SlotNumCur <= 0)
    {
        return EdgeResut;
    }
    Obj2StartIndexTemp = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].Obj2StartPtIndex;
    if (Edge0OrEdge1 == 0)
    {
        ObjStartIndexTemp = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].Obj1StartPtIndex;
        ObjEndIndexTemp = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].Obj1EndPtIndex;
        if((ObjStartIndexTemp == ObjEndIndexTemp) && (ObjStartIndexTemp == 0u)) //���edge0������� TBD
        {   
            VirtualOrNot = 1;
            FindMinSlotEdgeIndex   = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].SlotEndIndex;
            FindMinObjIndex = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].Obj2EndPtIndex;
            EdgeDistanceTemp = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur-1].SlotCalDisCarToObj2;
        }
        else//���edge0����ʵ��
        {
            VirtualOrNot = 0;
            FindMinSlotEdgeIndex   = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].SlotStartIndex;
            FindMinObjIndex = ObjEndIndex;
            EdgeDistanceTemp = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur-1].SlotCalDisCarToObj1;
        }
        SlotEdgeIndex   = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].SlotStartIndex;
        //SlotEdgeIndex   = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].SlotStartIndex;
        //EdgeDistanceTemp = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur-1].SlotCalDisCarToObj1;
    }
    else if (Edge0OrEdge1 == 1)
    {

        ObjStartIndexTemp = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].Obj2StartPtIndex;
        ObjEndIndexTemp = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].Obj2EndPtIndex;
        if(((ObjStartIndexTemp == ObjEndIndexTemp)   
            || ((ObjStartIndexTemp != ObjEndIndexTemp) && (ObjEndIndexTemp == ObjPtCnt)))   )  // obj2 ����
        {
            VirtualOrNot = 1;
            FindMinSlotEdgeIndex   = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].SlotStartIndex;
            FindMinObjIndex = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].Obj1EndPtIndex;
            EdgeDistanceTemp = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur-1].SlotCalDisCarToObj1; //TBD
        }
        else                                                                                  // obj2 ��ʵ
        {
            VirtualOrNot = 0;
            FindMinSlotEdgeIndex   = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].SlotEndIndex;
            EdgeDistanceTemp = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur-1].SlotCalDisCarToObj2;
			FindMinObjIndex = ObjEndIndex;
        }
         SlotEdgeIndex   = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].SlotEndIndex;
        // SlotEdgeIndex   = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].SlotEndIndex;
        // EdgeDistanceTemp = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur-1].SlotCalDisCarToObj2;
    }
    // (*PEdgeCompensateValue) = GetSlotEdgeCompensateValuePosX(Edge0OrEdge1,EdgeDistanceTemp, 0);
     (*PEdgeCompensateValue) = GetSlotCompensateValuePosXNew(Edge0OrEdge1, u8SlotSide, u8SlotNumCur, EdgeDistanceTemp, &SlotTypeTemp, 0);
    /*edge0 calculate */
#if YDevationCompeFunc_FindMinDis
    EdgeYTestTem = FindMinDis(FindMinSlotEdgeIndex, FindMinObjIndex, u8SlotSide);
    if(EdgeYTestTem != NO_OBJ_DISTANCE)
    {
        EdgePtBaseUSSCoordTemp0.x = EdgeYTestTem + APACal.HalfWidthOfCar;
    }
    else
    {
        EdgePtBaseUSSCoordTemp0.x = EdgeDistanceTemp + APACal.HalfWidthOfCar;
    }
#endif
    if(u8SlotSide == RIGHT)
    {
        EdgeBaseCar.x = EdgePtBaseUSSCoordTemp0.x;
        EdgeBaseCar.y = APACal.SnsPos[6].y;
    }
    else
    {
        EdgeBaseCar.x = -EdgePtBaseUSSCoordTemp0.x;
        EdgeBaseCar.y = APACal.SnsPos[11].y;
    }
    // �ӳ�������ϵת��USS����ϵ
    CarPoseTem.x = (float32)USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarCenterPoint[SlotEdgeIndex].x;
    CarPoseTem.y = (float32)USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarCenterPoint[SlotEdgeIndex].y;      
    EdgeBaseUSS = APATrajCalPointPosWithAngAndCenterPt(EdgeBaseCar, USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarAng[SlotEdgeIndex], CarPoseTem);
    //(*EdgeMaybeOutputInUSS) = EdgeBaseUSS;

    // ��USS����ϵת��DR����ϵ
    EdgePtBaseUSSCoordTemp0.x = EdgeBaseUSS.x;
    if(VirtualOrNot == 0) //��ʵ�Ľǵ㣬�Ӳ���ֵ
    {
        if(Edge0OrEdge1 == 1 && (SlotTypeTemp == PERP || SlotTypeTemp == UNKNOWN_SLOTTYPE) )
        {
            EdgePtBaseUSSCoordTemp0.y = USSPar.Slot[u8SlotSide].SlotOutline.Lane.ObjPt[Obj2StartIndexTemp].y + (*PEdgeCompensateValue);
            
        }
        else 
        {
           EdgePtBaseUSSCoordTemp0.y = USSPar.Slot[u8SlotSide].SlotOutline.Lane.ObjPt[SlotEdgeIndex].y + (*PEdgeCompensateValue);
        }
 
    }
    else                  // ����Ĳ��Ӳ���ֵ
    {
        EdgePtBaseUSSCoordTemp0.y = USSPar.Slot[u8SlotSide].SlotOutline.Lane.ObjPt[SlotEdgeIndex].y;
    }
    
    EdgeTemp.x = EdgePtBaseUSSCoordTemp0.x;
    EdgeTemp.y = EdgePtBaseUSSCoordTemp0.y;
     (*EdgeMaybeOutputInUSS) = EdgeTemp;
    EdgePosBaseDR = USS_CoordTransforToDR(EdgePtBaseUSSCoordTemp0,CenterAngBackup3,CenterPtBackup3);
   
    EdgeResut.x = EdgePosBaseDR.x;
    EdgeResut.y = EdgePosBaseDR.y;
    return EdgeResut;         
}

/*************************************************************************************************************************************************
** Syntax :  void CheckIfObj1OrObj2IsValid(uint8 u8SlotSide, APA_INDEX_TYPE ObjStartIndex, APA_INDEX_TYPE ObjEndIndex)                          **
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
** Description : ͳ��obj1/2�еĴ��ϰ�������ԣ����bObjIsBigEnough ��0/2�ı����ϴ󣬾���Ϊ��obj��Ч                                                  **
*************************************************************************************************************************************************/
uint8 CheckIfObj1OrObj2IsValid(uint8 u8SlotSide, APA_INDEX_TYPE ObjStartIndex, APA_INDEX_TYPE ObjEndIndex)
{
    APASlotOutlineCoordinateDataType *pMainSlot;
    uint8 SumInvalidPt, TotalPt;
    APA_INDEX_TYPE StartIndex, EndIndex, i;

    pMainSlot = &USSPar.Slot[u8SlotSide].SlotOutline.Lane;
    SumInvalidPt = 0;
    if (ObjStartIndex > ObjEndIndex)
    {
        StartIndex = ObjEndIndex;
        EndIndex = ObjStartIndex;
    }
    else
    {
        StartIndex = ObjStartIndex;
        EndIndex = ObjEndIndex;
    }
    TotalPt = EndIndex - StartIndex + 1;
    for (i = StartIndex; i <= EndIndex; i++)
    {
        if ((pMainSlot->bObjIsBigEnough[i] & APA_SLOT_OBJ_IS_BIG_ENOUGH_CHECK_OBJ_MASK) == 0)
        {
            SumInvalidPt++;
        }
        else
        {
        }
    }
    if (TotalPt == 0)
    {
        return 0;
    }
    else
    {
        if (((float32)SumInvalidPt / TotalPt) > 0.5)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}

/*************************************************************************************************************************************************
** Syntax :  void SlotInfoDataHandleNew(uint8 u8USSSts)                                                                                         **
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
** Description : ��ȡtask�����Ľ����������USS��������(ģ�����������u8USS_OnStates)������ǻ���DR����ϵ
        //       ȷ����λ�����޸���
        //        1��ȷ��USS����ԭ�����޸��£�USS�������ʱ�����±���������ݣ�
        //        2��ȷ�ϳ�λ��Ϣ���޸��£�
        //            case1����λ�����ޱ仯���޳�λʱ�޸��£�
        //            case2����λ�����ޱ仯���г�λʱ��ȷ�ϳ�λ���յ�pt��y�����Ƿ�ͱ��ݵģ���ת����������ϵ�£�һ�£�����edge1��case֮�������ʵ��egde1�跴������edge0����
        //            case3����λ�����б仯��3-1 �ٱ��ʱ����λ����
        //                                 3-2 �����ʱ����λ��ɾ������Ҫȷ�����£����ݵ��µĳ�λ�������ɣ�
        //        3������ȷ�Ϻõĳ�λ������SIF֮����н�������λ���ʱ�����£�
        //                objptcnt = obj2endindexʱ����carpassslotendindex 3.2m֮��(egde1����ʵ�ģ�edge0������ʵ������)
        //                objptcnt-obj2endindex��ֵ����һ����ֵ(egde1����ʵ�ģ�edge0������ʵ������)
        //                ��λ���ȴ���7.2m(edge1�������)                                                                                                                             **
*************************************************************************************************************************************************/
void SlotInfoDataHandleNew(uint8 u8USSSts)
{
    APA_ENUM_TYPE u8RightSlotNumTemp = 0u;
    APA_ENUM_TYPE u8LeftSlotNumTemp = 0u;
    APA_INDEX_TYPE s8RightSlotIndexTemp = 0;
    APA_INDEX_TYPE s8LeftSlotIndexTemp = 0;
    APA_SLOT_ID_TYPE s16RightNewSlotIDTemp = 0;
    APA_SLOT_ID_TYPE s16LeftNewSlotIDTemp = 0;
    // static APACoordinateDataCalFloatType ;
    // static APACoordinateDataCalFloatType Edge0Bk[2];
    // static APACoordinateDataCalFloatType Edge1Bk[2];
    APACoordinateDataCalFloatType Edge0Cur,Edge1Cur;
    uint8 u8SlotSide, bSlotFound;
    uint8 SlotType = 0;
    sint8 u8SlotNumCur;
    APA_INDEX_TYPE VirtualIndex = -1;
    APA_DISTANCE_CAL_FLOAT_TYPE Length;
    uint8 SlotCase = 0;
    APA_DISTANCE_TYPE SlotDepthTemp;
    APA_INDEX_TYPE CurbStartIndex = 0;
    APA_INDEX_TYPE CurbEndIndex = 0;
    APACoordinateDataCalFloatType Edge0MaybeOutput, Edge1MaybeOutput;
    APACoordinateDataCalFloatType Edge0CurInUSS, Edge1CurInUSS, Edge0MaybeOutputInUSS, Edge1MaybeOutputInUSS;
    APACoordinateDataCalFloatType VehPosBaseDR;
    APA_INDEX_TYPE Edge0MaybeOutputIndex, Edge1MaybeOutputIndex;
    APACoordinateDataType CarPosPtBaseUSSCoordTemp;
    APA_ENUM_TYPE ObjPtCnt;
    APA_INDEX_TYPE Obj1StartIndexTemp = 0;
    APA_INDEX_TYPE Obj1EndIndexTemp = 0;
    APA_INDEX_TYPE Obj2StartIndexTemp = 0;
    APA_INDEX_TYPE Obj2EndIndexTemp = 0;
    SLOTINFO_ST SlotInfoTemp;
    APA_ANGLE_TYPE AngleStart, AngleEnd;
    APA_DISTANCE_TYPE DisCarToObj1ByPassingSlot;                        // for parking out, it is the left object X coordinate.
	APA_DISTANCE_TYPE DisCarToObj2ByPassingSlot;
    APA_DISTANCE_TYPE SlotDepthTempForCurbLineCal = 0;
    uint8 IsCurbExist; 
    APASlotOutlineCoordinateDataType *pMainSlot;  //20200826
    APA_ANGLE_CAL_FLOAT_TYPE  CurbLineAngWithYTem, theta_NewToOldInUSS, AngleAtSlotEnd;  //20200826
    APALineParameterABCType CurbLineTem;  //20200826
    LineABC_ST CurbLineInUSSCoord;   //20200915
    LineABC_ST CurbLineInDRCoord;  //20200915
    Pose_ST USSCoor0PosInDR;  //20200915
    //APACarCoordinateDataCalFloatType CarCurPosCoord;
    float Dis, X_Trans, Y_Trans;
    APA_SLOT_ID_TYPE SlotID;
    APA_DISTANCE_TYPE Edge0CompensateValue, Edge1CompensateValue;

//step1: ���USS�������Ƿ������ù�
    if((MATH_FABS(CarPosCoordBackup.Coordinate.x - CenterPtBackup3.x)>0.001)
        ||(MATH_FABS(CarPosCoordBackup.Coordinate.y - CenterPtBackup3.y)>0.001)
        ||(MATH_FABS(CarPosCoordBackup.CarAng - CenterAngBackup3)>0.0001))
    {
        CarPosCoordBackup.Coordinate.x = CenterPtBackup3.x;
        CarPosCoordBackup.Coordinate.y = CenterPtBackup3.y;
        CarPosCoordBackup.CarAng = CenterAngBackup3;
    }
//step2: ȷ�ϳ�λ��Ϣ���޸���
    if(u8USSSts == PARKIN)
    {//��λ���½׶�
    }
    else if(u8USSSts == SCAN)
    {//��λɨ��׶�
        for (u8SlotSide = 0; u8SlotSide < 2; u8SlotSide++)
        {
            SlotType = 0;
            SlotCase = 0;
            bSlotFound = 0;
            Length = 0;
            memset(&SlotInfoTemp, 0, sizeof(SlotInfoTemp));
            // memset(&SlotInfoToOutput[u8SlotSide],0,sizeof(SlotInfoToOutput[u8SlotSide]));

            if ((MATH_FABS(gDR_stOut.gDR_f32VehPosARad - AngleBK[u8SlotSide]) >= 80 * Math_PI / 180)
                && (MATH_FABS(gDR_stOut.gDR_f32VehPosARad - AngleBK[u8SlotSide]) <= 280 * Math_PI / 180)) /*���ڳ�������ֱ����ʻʱ����ǰDRΪPI,���ݽǶ�Ϊ-PI���������ΪDR��Χ(-PI,PI)������ʱ��������*/
            {
                Edge0BkInUSS[u8SlotSide].x = MINNUMINSUBFUNCTION;
                Edge0BkInUSS[u8SlotSide].y = MINNUMINSUBFUNCTION;
                Edge1BkInUSS[u8SlotSide].x = MINNUMINSUBFUNCTION;
                Edge1BkInUSS[u8SlotSide].y = MINNUMINSUBFUNCTION;
                // AngleBK[u8SlotSide] = CenterAngBackup3;
                AngleBK[u8SlotSide] = gDR_stOut.gDR_f32VehPosARad;
                EdgeTypeBk[u8SlotSide] = EDGETYPEDEFAULT;
            }
            u8SlotNumCur = USSPar.Slot[u8SlotSide].SlotNum;
            if (u8SlotNumCur <= 0)
            {
                continue;
            }
            Obj1StartIndexTemp = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].Obj1StartPtIndex;
            Obj1EndIndexTemp   = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].Obj1EndPtIndex;
            Obj2StartIndexTemp = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].Obj2StartPtIndex;
            Obj2EndIndexTemp   = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].Obj2EndPtIndex;
            DisCarToObj1ByPassingSlot = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].DisCarToObj1ByPassingSlot;
            DisCarToObj2ByPassingSlot = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].DisCarToObj2ByPassingSlot;
            SlotID = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].SlotID;
            pMainSlot      = &USSPar.Slot[u8SlotSide].SlotOutline.Lane;
            ObjPtCnt = pMainSlot->ObjPtCnt;
            
            /*Edge0CurInUSS��Edge1CurInUSSû��Ҫ�����������ý���ת������Ϊÿ�ν����������¼���*/
            Edge0Cur = CalEdge(u8SlotSide, EDGETYPE_0, Obj1EndIndexTemp, &Edge0CurInUSS, &Edge0CompensateValue);
            Edge1Cur = CalEdge(u8SlotSide, EDGETYPE_1, Obj2EndIndexTemp, &Edge1CurInUSS, &Edge1CompensateValue);
        
            // // if ((MATH_FABS(Edge0Cur.x - Edge0Bk[u8SlotSide].x) < EDGETHRESHHOLD) && (MATH_FABS(Edge1Cur.x - Edge1Bk[u8SlotSide].x) < EDGETHRESHHOLD))
            // /*DR����ϵ��ֻ�Ƚ�x��׼ȷ��Ӧ��ת��USS����ϵ��ֻ�Ƚ�y����*/
            // if ((MATH_FABS(Edge0CurInUSS.y - Edge0BkInUSS[u8SlotSide].y) < EDGETHRESHHOLD) && (MATH_FABS(Edge1CurInUSS.y - Edge1BkInUSS[u8SlotSide].y) < EDGETHRESHHOLD))
            // {
            //     continue;
            // }
            /* PAR�� Edge0 ����*/
            if((Obj1StartIndexTemp == Obj1EndIndexTemp) && (Obj1StartIndexTemp == 0u)) 
            {
                if ((Obj2StartIndexTemp == Obj2EndIndexTemp)   /*PAR�� Edge1 ����*/
	            || ((Obj2StartIndexTemp != Obj2EndIndexTemp) && (Obj2EndIndexTemp == ObjPtCnt))
                || (MATH_ABS(Obj2EndIndexTemp - Obj2StartIndexTemp)<2))
	            {
	                continue;   /*PAR��Edge0 Edge1 �����⣬������(zp)*/
	            }
                /*�ص���SlotProcess.c��StartInex������10�����ƺ󣬻���ִ�λ�սӽ�obj2���౨�������������*/
                if (CheckIfObj1OrObj2IsValid(u8SlotSide,Obj2StartIndexTemp,Obj2EndIndexTemp) == 0)
                {
                    continue;
                }
                // if (MATH_FABS(Edge1Cur.x - Edge1Bk[u8SlotSide].x) < EDGETHRESHHOLD) // �뱸����ȣ��޸���
                if (MATH_FABS(Edge1CurInUSS.y - Edge1BkInUSS[u8SlotSide].y) < EDGETHRESHHOLD) // �뱸����ȣ��޸���
                {
                    SlotCase = 7;
                }
                else
                {
                    Length = APATrajCalGetTwoPointDisFloat(Edge0Cur, Edge1Cur);
                    if (Length > VIRTUALSLOTLENGTH)  /* edge0������ >7.2m */
                    { 
                        /*20201113 ĳЩcase�£��������һ������ĳ�λΪ�������⣬�������ⲻ�ɹ�������obj1��·��2m����һ����λ���������������⣬
                        ��obj1�Ա���һ�������ϰ����·�ؽ���1.3m,������Ȳ����㣬USSPar��û�г�λ��������һ����λ�޷������������⣩���������
                        �ñ�־����ǰ�������⳵λ�޷����.
                        �������Ϊ���������ڷ������⳵λ��edge1���������7.2m*/
                        if ((Edge1CurInUSS.y - Edge1BkInUSS[u8SlotSide].y) > EDGETHRESHHOLD)
                        {
                            EdgeTypeBk[u8SlotSide] = EDGETYPEDEFAULT;
                        }

                        if (EdgeTypeBk[u8SlotSide] == EDGE0ISVIRTUAL) /*�����һ����λҲ��edge0���⣬��˴β�����*/
                        {
                            continue;
                        }
                        SlotCase = 1;

                        Edge0MaybeOutput = CalVirtualEdgeNew(u8SlotSide, EDGETYPE_0, &VirtualIndex, Obj2EndIndexTemp,&Edge1CompensateValue, &Edge0MaybeOutputInUSS);

                        if (VirtualIndex == -1)
                        {
                            continue;
                        }
                        if(MATH_FABS(Edge0MaybeOutput.x + 1.0)< 0.01 && MATH_FABS(Edge0MaybeOutput.y + 1.0)< 0.01)
                        {
                            continue;
                        }
                        Edge1MaybeOutput = Edge1Cur; 
                        Edge1MaybeOutputInUSS = Edge1CurInUSS;
                        Edge0MaybeOutputIndex = VirtualIndex;
                        Edge1MaybeOutputIndex = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].SlotEndIndex;
                    }
                    else   /* edge0���� ��<7.2 */
                    {
                        if ((Edge1CurInUSS.y - Edge1BkInUSS[u8SlotSide].y) > EDGETHRESHHOLD)
                        {
                            EdgeTypeBk[u8SlotSide] = EDGETYPEDEFAULT;
                        }

                        if (EdgeTypeBk[u8SlotSide] == EDGE0ISVIRTUAL)
                        {
                            continue;
                        }
                        SlotCase = 2;
                        Edge0MaybeOutput = Edge0Cur; 
                        Edge1MaybeOutput = Edge1Cur;
                        Edge0MaybeOutputInUSS = Edge0CurInUSS;
                        Edge1MaybeOutputInUSS = Edge1CurInUSS;
                        Edge0MaybeOutputIndex = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].SlotStartIndex;
                        Edge1MaybeOutputIndex = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].SlotEndIndex;
                    }
                }
            }
            else if((Obj2StartIndexTemp == Obj2EndIndexTemp)   /*PAR�� Edge1 ����*/
            || ((Obj2StartIndexTemp != Obj2EndIndexTemp) && (Obj2EndIndexTemp == ObjPtCnt)))        
            {
                if (MATH_ABS(Obj1EndIndexTemp - Obj1StartIndexTemp)<2)
                {
                    continue;
                }
                /*�ص���SlotProcess.c��StartInex������10�����ƺ󣬻���ִ�λ�սӽ�obj2���౨�������������*/
                if (CheckIfObj1OrObj2IsValid(u8SlotSide,Obj1StartIndexTemp,Obj1EndIndexTemp) == 0)
                {
                    continue;
                }
                // if (MATH_FABS(Edge0Cur.x - Edge0Bk[u8SlotSide].x) < EDGETHRESHHOLD) // �뱸����ȣ��޸���
                if (MATH_FABS(Edge0CurInUSS.y - Edge0BkInUSS[u8SlotSide].y) < EDGETHRESHHOLD) // �뱸����ȣ��޸���
                {
                    SlotCase = 8;
                }
                else
                {
                    Length = APATrajCalGetTwoPointDisFloat(Edge0Cur, Edge1Cur);
                    if (Length > VIRTUALSLOTLENGTH)  /* edge1������ >7.2m */
                    { 
                        /*20201113 ĳЩcase�£��������һ������ĳ�λΪ�������⣬�������ⲻ�ɹ������粻����7.8m���������������ñ�־����ǰ�������⳵λ�޷����.
                        �������Ϊ�����������������⳵λ��edge0���������7.2m*/
                        if ((Edge0CurInUSS.y - Edge0BkInUSS[u8SlotSide].y) > EDGETHRESHHOLD)
                        {
                            EdgeTypeBk[u8SlotSide] = EDGETYPEDEFAULT;
                        }

                        if (EdgeTypeBk[u8SlotSide] == EDGE1ISVIRTUAL)
                        {
                            continue;
                        }
                        SlotCase = 3;
                        Edge0MaybeOutput = Edge0Cur; 

                        Edge1MaybeOutput = CalVirtualEdgeNew(u8SlotSide,EDGETYPE_1, &VirtualIndex, Obj1EndIndexTemp,  &Edge0CompensateValue, &Edge1MaybeOutputInUSS); 

                        if (VirtualIndex == -1)
                        {
                            continue;
                        }
                        if(MATH_FABS(Edge1MaybeOutput.x + 1.0)< 0.01 && MATH_FABS(Edge1MaybeOutput.y + 1.0)< 0.01)
                        {
                            continue;
                        }
                        Edge0MaybeOutputInUSS = Edge0CurInUSS;
                        Edge0MaybeOutputIndex = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].SlotStartIndex;
                        Edge1MaybeOutputIndex = VirtualIndex;
                    }
                    else   /* edge1���� ��<7.2 */
                    {
                        SlotCase = 9;
                    }
                }
                
            }
            else if((Obj2StartIndexTemp<Obj2EndIndexTemp)&&/* (MATH_ABS(Obj2EndIndexTemp - Obj2StartIndexTemp)>=2)&&*/
                    ((USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur-1].CarPassTheSlotEndPtDistance >= 3200)||(((ObjPtCnt-1-Obj2EndIndexTemp)>=3) && (MATH_ABS(Obj2EndIndexTemp - Obj2StartIndexTemp)>2))))
            {
                /*�ص���SlotProcess.c��StartInex������10�����ƺ󣬻���ִ�λ�սӽ�obj2���౨�������������*/
                if (CheckIfObj1OrObj2IsValid(u8SlotSide,Obj2StartIndexTemp,Obj2EndIndexTemp) == 0)
                {
                    continue;
                }
                Length = APATrajCalGetTwoPointDisFloat(Edge0Cur, Edge1Cur);
                /*USSPar�еķ����⳵λ���ǳ��ȣ�����7.2����Ҫ��������*/
                if (Length > VIRTUALSLOTLENGTH + 600)
                {
                    if ((Edge1CurInUSS.y - Edge1BkInUSS[u8SlotSide].y) > EDGETHRESHHOLD)
                    {
                        EdgeTypeBk[u8SlotSide] = EDGETYPEDEFAULT;
                    }

                    if (EdgeTypeBk[u8SlotSide] == EDGE0ISVIRTUAL)
                    {
                        continue;
                    }
                    SlotCase = 4; /*�������λ�ķ������⣬Edge0����*/

                    Edge0MaybeOutput = CalVirtualEdgeNew(u8SlotSide, EDGETYPE_0, &VirtualIndex, Obj2EndIndexTemp, &Edge1CompensateValue, &Edge0MaybeOutputInUSS);

                    if (VirtualIndex == -1)
                    {
                        continue;
                    }
                    if(MATH_FABS(Edge0MaybeOutput.x + 1.0)< 0.01 && MATH_FABS(Edge0MaybeOutput.y + 1.0)< 0.01)
                    {
                        continue;
                    } 
                    Edge1MaybeOutput = Edge1Cur; 
                    Edge1MaybeOutputInUSS = Edge1CurInUSS;
                    Edge0MaybeOutputIndex = VirtualIndex;
                    Edge1MaybeOutputIndex = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].SlotEndIndex;
                }
                else
                {
                    // if (MATH_FABS(Edge0Cur.x - Edge0Bk[u8SlotSide].x) < EDGETHRESHHOLD) // �뱸����ȣ��޸���
                    if (MATH_FABS(Edge0CurInUSS.y - Edge0BkInUSS[u8SlotSide].y) < EDGETHRESHHOLD) // �뱸����ȣ��޸���
                    {
                        // if (MATH_FABS(Edge1Cur.x - Edge1Bk[u8SlotSide].x) < EDGETHRESHHOLD)
                        if (MATH_FABS(Edge1CurInUSS.y - Edge1BkInUSS[u8SlotSide].y) < EDGETHRESHHOLD)
                        {
                            /* edge0 �� edge1 �����*/
                            EdgeTypeBk[u8SlotSide] = EDGETYPEDEFAULT;/*��Ȼ���������������£�������ó�λ���������⣬û�������⣬��ô��һ������������޷�����*/
                        }
                        else
                        {
                            if ((Edge1CurInUSS.y - Edge1BkInUSS[u8SlotSide].y) > EDGETHRESHHOLD)
                            {
                                EdgeTypeBk[u8SlotSide] = EDGETYPEDEFAULT;
                            }

                            if (EdgeTypeBk[u8SlotSide] == EDGE0ISVIRTUAL)
                            {
                                continue;
                            }
                            SlotCase = 5;

                            Edge0MaybeOutput = CalVirtualEdgeNew(u8SlotSide,EDGETYPE_0, &VirtualIndex, Obj2EndIndexTemp,  &Edge1CompensateValue, &Edge0MaybeOutputInUSS);
                            
                            if (VirtualIndex == -1)
                            {
                                continue;
                            }
                            if(MATH_FABS(Edge0MaybeOutput.x + 1.0)< 0.01 && MATH_FABS(Edge0MaybeOutput.y + 1.0)< 0.01)
                            {
                                continue;
                            } 
                            Edge1MaybeOutput = Edge1Cur; 
                            Edge1MaybeOutputInUSS = Edge1CurInUSS;
                            Edge0MaybeOutputIndex = VirtualIndex;
                            Edge1MaybeOutputIndex = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].SlotEndIndex;
                        }
                    }
                    else
                    {
                        if (MATH_FABS(Edge1CurInUSS.y - Edge1BkInUSS[u8SlotSide].y) < EDGETHRESHHOLD)
                        { // ���ܲ��ᷢ��
                            SlotCase = 10;
                        }
                        else  
                        {
                            SlotCase = 6;
                            Edge0MaybeOutput = Edge0Cur; 
                            Edge1MaybeOutput = Edge1Cur; 
                            Edge0MaybeOutputInUSS = Edge0CurInUSS;
                            Edge1MaybeOutputInUSS = Edge1CurInUSS;
                            Edge0MaybeOutputIndex = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].SlotStartIndex;
                            Edge1MaybeOutputIndex = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur - 1].SlotEndIndex;
                        }
                    }
                }
            }

            if( SlotCase > 6 || SlotCase == 0)
            {
                continue;
            }
            
            /*ֻҪ����7.2m�ķ����⳵λ��������ʱ������1.5m�����������糵λΪ7.3m��7.2m�������ˣ���7.3ʱӦ��Ҫ��������*/
            if (SlotCase != 4)
            {
                if (MATH_FABS(Edge1CurInUSS.y - Edge1BkInUSS[u8SlotSide].y) < EDGETHRESHHOLD)
                {
                    continue;
                }
            }
            else
            {
                if ((MATH_FABS(Edge1CurInUSS.y - Edge1BkInUSS[u8SlotSide].y) < 600))
                {
                    EdgeTypeBk[u8SlotSide] = EDGETYPEDEFAULT;/*��Ȼ���������������£�������ó�λ���������⣬û�������⣬��ô��һ������������޷�����*/
                    continue;
                }
            }
            /* ��λʱ�����ų���ǰ����obj1�ĵ��Խ��Խ�٣���obj1ֻ��1���㣨Ϊ����㣩��������������32767�ĵ�ʱ���������λ����obj1��㣬obj2��㣬slot���
            slot�յ㶼��·�ص��ϡ���ʵ�����λû��Ҫ�������Ϊ֮ǰ�Ѿ������������ */
            // if ((pMainSlot->DisFromCarToObj[Obj1StartIndexTemp] > 2500) && (pMainSlot->DisFromCarToObj[Obj2StartIndexTemp] > 2500))
            // {
            //     continue;
            // }
            /*�޸���������ɾ��һ�����task������ĳ�λ�����нϴ�仯�����½ǵ�����仯��ʹ�ýǵ������*/
            if ((MATH_FABS(Edge0BkInUSS[u8SlotSide].y) > 0.001)) /*����������ֵ�Ż�����Ƚ�*/
            {
                if (Edge0MaybeOutputInUSS.y < Edge0BkInUSS[u8SlotSide].y)
                {
                    continue; // ���Ҫ���µĽǵ����һ������Ļ�С�������
                }
            }
            /*���ת��ʱ�����λ�����⣬�Ƚ�Ҫ�����λ��edge0��edge1���ĽǶȣ�������ֵ����Ϊ��ת��*/
            if ((SlotCase == 1) || (SlotCase == 2) || (SlotCase == 3) || (SlotCase == 4) || (SlotCase == 5)) /*���⳵λ*/
            {
                if (MATH_FABS(USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarAng[Edge0MaybeOutputIndex] - 
                USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarAng[Edge1MaybeOutputIndex]) > 15 * Math_PI / 180)
                {
                    EdgeTypeBk[u8SlotSide] = EDGETYPEDEFAULT;
                    continue;
                }
            }
            
            // ���
            SlotDepthTemp = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur-1].SlotDepth;
            if (SlotDepthTemp != NO_OBJ_DISTANCE)
            {
            }
            else
            {
                USSCheckSlotDepth(u8SlotSide,u8SlotNumCur,&SlotDepthTemp,&CurbStartIndex,&CurbEndIndex);
            }
            Length = APATrajCalGetTwoPointDisFloat(Edge0MaybeOutput, Edge1MaybeOutput);
            if(SlotDepthTemp > 3800)
            {
                if (Length > (APACal.LengthOfCar + 300))
                {
                    SlotType = UNKNOWN_SLOTTYPE;
                    bSlotFound = 1;
                }
                else if (Length > (APACal.WidthOfCar + 300))
                {
                    SlotType = PERP;
                    bSlotFound = 1;
                }
                else
                {
                    /* code */
                }
            }
            else if (Length>(APACal.LengthOfCar + 300))
            {
                SlotType = PARA;
                bSlotFound = 1;
            }
            else
            {
                continue;
            }
            
            if (bSlotFound == 1)
            {
                bSlotFound = 0;
                SlotInfoTemp.gUSS_u8Type = SlotType;
                SlotInfoTemp.stEdge0Info.gUSS_f32PosX = Edge0MaybeOutput.x / 1000.0;
                SlotInfoTemp.stEdge0Info.gUSS_f32PosY = Edge0MaybeOutput.y / 1000.0;
                SlotInfoTemp.stEdge1Info.gUSS_f32PosX = Edge1MaybeOutput.x / 1000.0;
                SlotInfoTemp.stEdge1Info.gUSS_f32PosY = Edge1MaybeOutput.y / 1000.0;
                // SlotInfoTemp.gUSS_u8UpdState = SLOT_UPDATE;
                SlotInfoTemp.gUSS_u8ValidState = VALID;

                /* car pos @ edge0 */
                CarPosPtBaseUSSCoordTemp.x  = USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarCenterPoint[Edge0MaybeOutputIndex].x;
                CarPosPtBaseUSSCoordTemp.y  = USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarCenterPoint[Edge0MaybeOutputIndex].y;
                VehPosBaseDR = USS_CoordTransforToDR(CarPosPtBaseUSSCoordTemp,CenterAngBackup3,CenterPtBackup3);
                SlotInfoTemp.stEdge0Info.stVehPosInfo.f32XMtr = ((VehPosBaseDR.x)/1000.0);
                SlotInfoTemp.stEdge0Info.stVehPosInfo.f32YMtr = ((VehPosBaseDR.y)/1000.0);
                AngleStart     = USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarAng[Edge0MaybeOutputIndex];  
                SlotInfoTemp.stEdge0Info.stVehPosInfo.f32ARad = AngleStart + CenterAngBackup3;

                CarPosPtBaseUSSCoordTemp.x  = USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarCenterPoint[Edge1MaybeOutputIndex].x;
                CarPosPtBaseUSSCoordTemp.y  = USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarCenterPoint[Edge1MaybeOutputIndex].y;
                VehPosBaseDR = USS_CoordTransforToDR(CarPosPtBaseUSSCoordTemp,CenterAngBackup3,CenterPtBackup3);
                SlotInfoTemp.stEdge1Info.stVehPosInfo.f32XMtr = ((VehPosBaseDR.x)/1000.0);
                SlotInfoTemp.stEdge1Info.stVehPosInfo.f32YMtr = ((VehPosBaseDR.y)/1000.0);
                AngleEnd       = USSPar.Slot[u8SlotSide].SlotOutline.Lane.CarAng[Edge1MaybeOutputIndex];
                SlotInfoTemp.stEdge1Info.stVehPosInfo.f32ARad = AngleEnd + CenterAngBackup3;

                if(SlotType == PARA)
                {
                    printf("***************distance1********************************************\n");
                    if (CurbStartIndex == 0 && CurbEndIndex == 0)
                    {
                        if(DisCarToObj1ByPassingSlot > DisCarToObj2ByPassingSlot)  //20200915
                        {
                            SlotDepthTempForCurbLineCal = SlotDepthTemp + DisCarToObj2ByPassingSlot;
                        }
                        else
                        {
                            SlotDepthTempForCurbLineCal = SlotDepthTemp + DisCarToObj1ByPassingSlot;
                        }
                    
                        IsCurbExist = APATrajCalFitCurbLineAccordingToSlotData(pMainSlot,
                                                                        DisCarToObj2ByPassingSlot,
                                                                        Edge0MaybeOutputIndex,
                                                                        Edge1MaybeOutputIndex,
                                                                        SlotDepthTempForCurbLineCal,   /* to be check */
                                                                        &CurbLineAngWithYTem,
                                                                        &CurbLineTem);            
                    }
                    else
                    {
                        IsCurbExist = LineParCalBaseUSSCoord(u8SlotSide,CurbStartIndex,CurbEndIndex, &CurbLineTem);
                    }                
                    if(IsCurbExist ==1)  //20200915
                    {
                        
						Dis = MATH_SQRT(CarPosCoordBackup.Coordinate.x*CarPosCoordBackup.Coordinate.x+CarPosCoordBackup.Coordinate.y*CarPosCoordBackup.Coordinate.y);
                        if(fabs(CarPosCoordBackup.Coordinate.y) < 0.0001)
                        {
                            theta_NewToOldInUSS = 0;
                        }
                        else
                        {
                            theta_NewToOldInUSS = MATH_ATAN(CarPosCoordBackup.Coordinate.x/CarPosCoordBackup.Coordinate.y);
                        }							
                        // X_Trans = Dis*MATH_SIN(theta_NewToOldInUSS+CarPosCoordBackup.CarAng);
                        // Y_Trans = Dis*MATH_COS(theta_NewToOldInUSS+CarPosCoordBackup.CarAng);
                        // USSCoor0PosInDR.f32XMtr = -X_Trans/1000.0;
                        // USSCoor0PosInDR.f32YMtr = -Y_Trans/1000.0;
                        //  USSCoor0PosInDR.f32ARad = -CarPosCoordBackup.CarAng + PI/2;  //20200915 uss coord ang and dr ang deviation
                       
                        CurbLineInUSSCoord.f32A = CurbLineTem.A;
                        CurbLineInUSSCoord.f32B = -CurbLineTem.B;  //20200915PM
                        CurbLineInUSSCoord.f32C = CurbLineTem.C;
                        
                        #if 1  // xsj 20210408
                        USSCoor0PosInDR.f32XMtr = CenterPtBackup1.x/1000.0;
                        USSCoor0PosInDR.f32YMtr = CenterPtBackup1.y/1000.0;
                        USSCoor0PosInDR.f32ARad = CenterAngBackup1 + PI/2;  

                        #endif

                        CF_CrdTrnsLineABCKnownNewOrgInOldCrd(USSCoor0PosInDR,
                                                                CurbLineInUSSCoord,
                                                                &CurbLineInDRCoord);
                     
                        float distance3 = fabs(CurbLineInUSSCoord.f32A *Edge0MaybeOutputInUSS.x/1000 + CurbLineInUSSCoord.f32B *Edge0MaybeOutputInUSS.y/1000 +CurbLineInUSSCoord.f32C)/sqrt(CurbLineInUSSCoord.f32A*CurbLineInUSSCoord.f32A +CurbLineInUSSCoord.f32B*CurbLineInUSSCoord.f32B);
                         printf("***************distance3***************************8888888*********************: %10f\n", distance3);

                         float distance = fabs(CurbLineInDRCoord.f32A *Edge0MaybeOutput.x/1000 + CurbLineInDRCoord.f32B *Edge0MaybeOutput.y/1000 +CurbLineInDRCoord.f32C)/sqrt(CurbLineInDRCoord.f32A*CurbLineInDRCoord.f32A +CurbLineInDRCoord.f32B*CurbLineInDRCoord.f32B);
                         printf("***************distance2***************************9999999999999*********************: %10f\n", distance);
                    }
                    else
                    {
                        CurbLineInDRCoord.f32A = 0.0;
                        CurbLineInDRCoord.f32B = 0.0;
                        CurbLineInDRCoord.f32C = 0.0;
                    }   
                }
                else
                {
                    IsCurbExist = 0;
                    CurbLineInDRCoord.f32A = 0.0;
                    CurbLineInDRCoord.f32B = 0.0;
                    CurbLineInDRCoord.f32C = 0.0;
                }

                SlotInfoTemp.stCurbInfo.gUSS_s16CurbLineParaA = CurbLineInDRCoord.f32A;
                SlotInfoTemp.stCurbInfo.gUSS_s16CurbLineParaB = CurbLineInDRCoord.f32B;
                SlotInfoTemp.stCurbInfo.gUSS_s16CurbLineParaC = CurbLineInDRCoord.f32C;
                SlotInfoTemp.stCurbInfo.gUSS_u8CurbState = IsCurbExist;
                
                if ((SlotCase == 1) || (SlotCase == 2) || (SlotCase == 4) || (SlotCase == 5))
                {
                    SlotInfoTemp.stEdge0Info.gUSS_u8VirtualFlg = VIRTUAL;
                    SlotInfoTemp.stEdge0Info.ObjType = UNKNOWN_OBJTYPE;
                    SlotInfoTemp.stEdge1Info.gUSS_u8VirtualFlg = UNVIRTUAL;
                    SlotInfoTemp.stEdge1Info.ObjType = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur-1].Obj2Type;
                    EdgeTypeBk[u8SlotSide] = EDGE0ISVIRTUAL;
                }
                else if ((SlotCase == 6))
                {
                    SlotInfoTemp.stEdge0Info.gUSS_u8VirtualFlg  = UNVIRTUAL;
                    SlotInfoTemp.stEdge0Info.ObjType =  USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur-1].Obj1Type;
                    SlotInfoTemp.stEdge1Info.gUSS_u8VirtualFlg = UNVIRTUAL;
                    SlotInfoTemp.stEdge1Info.ObjType = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur-1].Obj2Type;
                    EdgeTypeBk[u8SlotSide] = EDGE0_1_ISREAL;
                }
                else if(SlotCase == 3)
                {
                    SlotInfoTemp.stEdge0Info.gUSS_u8VirtualFlg = UNVIRTUAL;
                    SlotInfoTemp.stEdge0Info.ObjType = USSPar.Slot[u8SlotSide].SlotPar[u8SlotNumCur-1].Obj1Type;
                    SlotInfoTemp.stEdge1Info.gUSS_u8VirtualFlg = VIRTUAL;
                    SlotInfoTemp.stEdge1Info.ObjType = UNKNOWN_OBJTYPE;
                    EdgeTypeBk[u8SlotSide] = EDGE1ISVIRTUAL;
                }
                else
                {

                }
#if Debug_SW_PrivateCANForIntegration
                BackupSlotInfoToTempStruct(u8SlotSide, u8SlotNumCur - 1);
                // SendParamtersOutOnceEdgePtUpdated();
#endif
                // SaveSlotInfoToUSSstOut(&SlotInfoTemp, u8SlotSide, u8SlotNumCur - 1);
                /*������SaveSlotInfoToUSSstOut֮����ã���2����������SaveSlotInfoToUSSstOut�и�ֵ*/
                // SendParamtersOutOnceEdgePtUpdated();
                if (u8SlotSide == 0)
                {
                    gUSS_stOut.stRightSideSlot = SlotInfoTemp;
                    Edge0BkInUSS[u8SlotSide] = Edge0MaybeOutputInUSS;
                    Edge1BkInUSS[u8SlotSide] = Edge1MaybeOutputInUSS;
                     /*���������λʱ�̵�DR����ϵ�µĽǶ�*/
                    AngleBK[u8SlotSide] = gDR_stOut.gDR_f32VehPosARad;
                    u8USS_USlotUpdateFlag[u8SlotSide] = UPDATE;
                }
                else
                {
                    gUSS_stOut.stLeftSideSlot = SlotInfoTemp;
                    Edge0BkInUSS[u8SlotSide] = Edge0MaybeOutputInUSS;
                    Edge1BkInUSS[u8SlotSide] = Edge1MaybeOutputInUSS;
                    AngleBK[u8SlotSide] = gDR_stOut.gDR_f32VehPosARad;
                    u8USS_USlotUpdateFlag[u8SlotSide] = UPDATE;
                }
                /*���ڲ�������ͷ������⳵λ�ĳ����Ƿ���7200mm����*/
                // if ((SlotCase == 1) || (SlotCase == 3) || (SlotCase == 4) || (SlotCase == 5))
                // {
                //     Length = APATrajCalGetTwoPointDisFloat(Edge0MaybeOutput, Edge1MaybeOutput);
                //     if (Length > 8000 || Length < 6200)
                //     {
                //         int a=0;
                //     }
                // }
            }
            else
            {
            }
        } /*Loop For*/
    }
    else
    {// ��ɨ��Ϳ�λ�����������������ʵ�ʲ�����ִ�е�
    }
}
/*************************************************************************************************************************************************
** Syntax :  void USSDataInitialize(void)                                                                                                       **
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
** Description : USS offʱ���ݳ�ʼ��                                                                                                             **
**                                                                                                                                              **
*************************************************************************************************************************************************/
void USSDataInitialize(void)    //20200826
{
    sint8 i;
    gUSS_stOut.gUSS_u8ObjPtConvertFinishSts = 0u;
    CenterAngBackup1 = 0.0;
    CenterAngBackup2 = 0.0;
    CenterAngBackup3 = 0.0;
    USSResetHistory = 0;
    memset(&CenterPtBackup1, 0, sizeof(CenterPtBackup1));
    memset(&CenterPtBackup2, 0, sizeof(CenterPtBackup2));
    memset(&CenterPtBackup3, 0, sizeof(CenterPtBackup3));
    memset(&CarPosCoordBackup, 0, sizeof(CarPosCoordBackup));
    memset(&gUSS_stOut.gUSS_Coord0Pos, 0, sizeof(gUSS_stOut.gUSS_Coord0Pos));
    memset(&gUSS_stOut.stLeftSideSlot, 0, sizeof(gUSS_stOut.stLeftSideSlot));
    memset(&gUSS_stOut.stRightSideSlot, 0, sizeof(gUSS_stOut.stRightSideSlot));
    memset(&gUSS_stOut, 0, sizeof(gUSS_stOut));   // 20201008
    memset(&SlotInfoToOutput,0,sizeof(SlotInfoToOutput));
    /*20201026 ������Ҫ���SlotInfoDataHandleNew���ȫ�ֱ�����ע�������SlotInfoDataHandleNew
    �ﱸ�ݵ�ȫ�ֱ��������ı䣬һ��Ҫ�����������������Ӱ�쳵λ���*/
    for (i = 0; i < 2; i++)
    {
        Edge0BkInUSS[i].x = MINNUMINSUBFUNCTION;
        Edge0BkInUSS[i].y = MINNUMINSUBFUNCTION;
        Edge1BkInUSS[i].x = MINNUMINSUBFUNCTION;
        Edge1BkInUSS[i].y = MINNUMINSUBFUNCTION;
        AngleBK[i] = gDR_stOut.gDR_f32VehPosARad;
        EdgeTypeBk[i] = EDGETYPEDEFAULT;
        // SlotIDBK[i] = 0;
    }
}
/*************************************************************************************************************************************************
** Syntax :  sint8 ObjPtIndexCalForVSlot(APACoordinateDataCalFloatType stSlotEdgePos,uint8 u8SlotSide,uint8 u8EdgeType)                         **
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
** Description :                   edge1������� TBD                                                                                                       **
*************************************************************************************************************************************************/
sint8 ObjPtIndexCalForVSlot(APACoordinateDataCalFloatType stSlotEdgePos,uint8 u8SlotSide)
{
    sint8 s8IndexResult = -1;  //20200929
    sint8 i = 0;
    uint8 ObjPtCnt = 0;
    APA_INT_TYPE PosXDevation = 0;
    APACoordinateDataType stEdgePosTemp;

    APASlotOutlineCoordinateDataType *pSlotOutlineTemp;

    pSlotOutlineTemp = &USSPar.Slot[u8SlotSide].SlotOutline.Lane;
    ObjPtCnt = pSlotOutlineTemp->ObjPtCnt;
    stEdgePosTemp.x = (APA_DISTANCE_TYPE)(1000.0*stSlotEdgePos.x);
    stEdgePosTemp.y = (APA_DISTANCE_TYPE)(1000.0*stSlotEdgePos.y);

    for(i = 0;i<ObjPtCnt;i++)
    {
        if(pSlotOutlineTemp->ObjPt[i].y > stEdgePosTemp.y)
        {
            PosXDevation = pSlotOutlineTemp->ObjPt[i].x - stEdgePosTemp.x;  //TBD
            if((PosXDevation> 1400)
               &&(PosXDevation< 3000))// ·�ص��x������Ӿ���λ��x�����ķ�Χ�� 1.4m~3m
            {
                s8IndexResult = i;  //20200929
                break;
            }
        }
    }
    return s8IndexResult;  //20200929
}

/*************************************************************************************************************************************************
** Syntax :  void CheckCurbForVSlot(void)                                                                                                       **
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
** Description :                                                                                                                                **
            //       ���µ㳵��ǰ������������PLD��S1���Ӧ����С1.5m���ϲ�����·�ؼ��㣬
            //       step1: ����SIF�г�λ�����ͳ�λ����ȷ���Ƿ���Ҫ����·�����
            //       step2����Ҫ���ʱ����S0��S1������ת����USS�����£�
            //       step3: ����S0��S1�������·�����λ������index�Ĳ��ң�
            //       step4: ����·����ϼ��㺯������·�������
            //       step5��ת��DR����ϵ�½������
*************************************************************************************************************************************************/
void CheckCurbForVSlot(void)
{
    static APACoordinateDataCalFloatType stVSlotS1PosInDRBackupRight;
    static APACoordinateDataCalFloatType stVSlotS1PosInDRBackupLeft;
    static uint8 u8SIFLeftSlotNumBackup = 0u;
    static uint8 u8SIFRightSlotNumBackup = 0u;
    APACoordinateDataCalFloatType stVSlotS0PosInDRCoordTemp;
    APACoordinateDataCalFloatType stVSlotS1PosInDRCoordTemp;
    APACoordinateDataCalFloatType stVSlotS0PosInUSSCoordTemp;
    APACoordinateDataCalFloatType stVSlotS1PosInUSSCoordTemp;
    APALineParameterABCType pCurbLine;
    LineABC_ST CurbLineInUSSCoordForVSlot;   //20200915
    LineABC_ST CurbLineInDRCoordForVSlot;  //20200915
    Pose_ST USSCoor0PosInDRForVSlot;  //20200915
    float X_Trans; //20200928zp 
	float Y_Trans; //20200928zp
	float Dis; //20200928zp
    APA_ANGLE_CAL_FLOAT_TYPE theta_NewToOldInUSS; //20200928zp

    sint8 u8CurbCalStartIndexTemp = -1;
    sint8 u8CurbCalEndIndexTemp = -1;
    uint8 u8CurrentSIFSlotNumLeftTemp = 0;
    uint8 u8CurrentSIFSlotNumRightTemp = 0;
    float32 f32VSlotS1PosXDevationMtrTemp = 0.0;
    float32 f32VSlotS1PosYDevationMtrTemp = 0.0;

#if Debug_SW_VSlotCurb 
    u8CurrentSIFSlotNumRightTemp = 1;
    u8CurrentSIFSlotNumLeftTemp = 0;
    gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumRightTemp-1].u8Source  = SLOT_PLD;
    gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumRightTemp-1].stS0.Point.f32XMtr = 1.31;
    gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumRightTemp-1].stS0.Point.f32YMtr = 0.02;
    gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumRightTemp-1].stS1.Point.f32XMtr = 1.31;
    gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumRightTemp-1].stS1.Point.f32YMtr = 6.4;
#else
    u8CurrentSIFSlotNumRightTemp = gSIF_stOut.gSIF_stSlotPool.u8RAvblNum;
    u8CurrentSIFSlotNumLeftTemp = gSIF_stOut.gSIF_stSlotPool.u8LAvblNum;
#endif
    
    if(u8CurrentSIFSlotNumRightTemp != 0u)
    {
        if(u8CurrentSIFSlotNumRightTemp > u8SIFRightSlotNumBackup)
        {// �ұ����µ�SIF��λ
            if(gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumRightTemp-1].u8Source == SLOT_PLD)
            {//����SIF��λ���߳�λ
                if(u8CurrentSIFSlotNumRightTemp == 4)
                {//�����ǰSIF��λ������4ʱ����Ҫ�����߳�λS1����
                    stVSlotS1PosInDRBackupRight.x = gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumRightTemp-1].stS1.Point.f32XMtr;
                    stVSlotS1PosInDRBackupRight.y = gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumRightTemp-1].stS1.Point.f32YMtr;
                }
                stVSlotS0PosInDRCoordTemp.x = gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumRightTemp-1].stS0.Point.f32XMtr;
                stVSlotS0PosInDRCoordTemp.y = gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumRightTemp-1].stS0.Point.f32YMtr;
                stVSlotS0PosInUSSCoordTemp = APATrajCalPointPosWithAngAndCenterPt(stVSlotS0PosInDRCoordTemp, CenterAngBackup1, CenterPtBackup1);  //ת����USS�����½��бȽ�
                u8CurbCalStartIndexTemp =  ObjPtIndexCalForVSlot(stVSlotS0PosInUSSCoordTemp,RIGHT);

                stVSlotS1PosInDRCoordTemp.x = gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumRightTemp-1].stS1.Point.f32XMtr;
                stVSlotS1PosInDRCoordTemp.y = gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumRightTemp-1].stS1.Point.f32YMtr;
                stVSlotS1PosInUSSCoordTemp = APATrajCalPointPosWithAngAndCenterPt(stVSlotS1PosInDRCoordTemp, CenterAngBackup1, CenterPtBackup1);  //ת����USS�����½��бȽ�
                u8CurbCalEndIndexTemp =  ObjPtIndexCalForVSlot(stVSlotS1PosInUSSCoordTemp,RIGHT);

                if(LineParCalBaseUSSCoord(RIGHT,u8CurbCalStartIndexTemp,u8CurbCalEndIndexTemp,&pCurbLine) ==TRUE)
                {//·����ϼ���ɹ�������н�����ݵ�USS out�������SIF
                    //ֱ�߷�����ת����DR����ϵ�½������  tbd
                    u8USS_UCurbUpdateFlag[RIGHT] = UPDATE;
                    gUSS_stOut.stRightSideSlot.stCurbInfoForVSS.u8CurbForVSSUpdateFlag = UPDATE;
                    gUSS_stOut.stRightSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_u8CurbState = VALID;
                    gUSS_stOut.stRightSideSlot.stCurbInfoForVSS.gUSS_u8VSlotSource = u8CurrentSIFSlotNumRightTemp;
                   //20200915 
                    // 20200928zp
                    Dis = MATH_SQRT(CenterPtBackup3.x*CenterPtBackup3.x+CenterPtBackup3.y*CenterPtBackup3.y);
                    if (fabs(CenterPtBackup3.y) < 0.0001)
                    {
                    	theta_NewToOldInUSS = 0;
                    }
                    else
                    {
                    	theta_NewToOldInUSS = MATH_ATAN(CenterPtBackup3.x/CenterPtBackup3.y);
                    }
                    X_Trans = Dis*MATH_SIN(theta_NewToOldInUSS+CenterAngBackup3);
                    Y_Trans = Dis*MATH_COS(theta_NewToOldInUSS+CenterAngBackup3);
                    
                    USSCoor0PosInDRForVSlot.f32XMtr =  -X_Trans;
                    USSCoor0PosInDRForVSlot.f32YMtr =  -Y_Trans;
                    USSCoor0PosInDRForVSlot.f32ARad = -CenterAngBackup3 + PI/2;  
                    CurbLineInUSSCoordForVSlot.f32A = pCurbLine.A;
                    CurbLineInUSSCoordForVSlot.f32B = pCurbLine.B;
                    CurbLineInUSSCoordForVSlot.f32C = pCurbLine.C;

                    CF_CrdTrnsLineABCKnownNewOrgInOldCrd(USSCoor0PosInDRForVSlot,
                                                        CurbLineInUSSCoordForVSlot,
                                                        &CurbLineInDRCoordForVSlot);

                    gUSS_stOut.stRightSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_s16CurbLineParaA = CurbLineInDRCoordForVSlot.f32A;
                    gUSS_stOut.stRightSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_s16CurbLineParaB = CurbLineInDRCoordForVSlot.f32B;
                    gUSS_stOut.stRightSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_s16CurbLineParaC = CurbLineInDRCoordForVSlot.f32C;
                    //20200915 
                }
                else
                {
                    u8USS_UCurbUpdateFlag[RIGHT] = NOUPDATE;
                    gUSS_stOut.stRightSideSlot.stCurbInfoForVSS.u8CurbForVSSUpdateFlag = NOUPDATE;
                    gUSS_stOut.stRightSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_u8CurbState = INVALID;
                    //20200915 
                    gUSS_stOut.stRightSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_s16CurbLineParaA = 0.0;
                    gUSS_stOut.stRightSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_s16CurbLineParaB = 0.0;
                    gUSS_stOut.stRightSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_s16CurbLineParaC = 0.0;  
                    //20200915
                }
            }
            else
            {
                u8USS_UCurbUpdateFlag[RIGHT] = NOUPDATE;
            }
        }
        else if(u8CurrentSIFSlotNumRightTemp == u8SIFRightSlotNumBackup) 
        {
            if(u8CurrentSIFSlotNumRightTemp == 4u)
            {//��λ���ˣ�ֻȷ���µĿ�λ�Ƿ����߳�λ,�߳�λʱ����Ҫ�ͱ��ݵ�����ȶ��Ƿ��б仯���б仯ʱ����·������ж���ͬʱ���±��ݵ��߳�λS1���ꣻ�����߳�λʱ������ݵ��߳�λ��Ϣ
                if(gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumRightTemp-1].u8Source == SLOT_PLD)
                {
                    f32VSlotS1PosXDevationMtrTemp = stVSlotS1PosInDRBackupRight.x - gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumRightTemp-1].stS1.Point.f32XMtr;
                    f32VSlotS1PosYDevationMtrTemp = stVSlotS1PosInDRBackupRight.y - gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumRightTemp-1].stS1.Point.f32YMtr;
                    if((MATH_FABS(f32VSlotS1PosXDevationMtrTemp)> 0.5)
                       ||(MATH_FABS(f32VSlotS1PosYDevationMtrTemp)> 0.5))  //20200929
                    {   //SIF�����³�λ���߳�λ���Һͱ��ݵ��߳�λ���ݲ�һ�£��������������߳�λ����Ҫ��������ж���ͬʱ���ó�λ�����걸������
                        stVSlotS1PosInDRBackupRight.x = gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumRightTemp-1].stS1.Point.f32XMtr;
                        stVSlotS1PosInDRBackupRight.y = gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumRightTemp-1].stS1.Point.f32YMtr;

                        stVSlotS0PosInDRCoordTemp.x = gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumRightTemp-1].stS0.Point.f32XMtr;
                        stVSlotS0PosInDRCoordTemp.y = gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumRightTemp-1].stS0.Point.f32YMtr;
                        stVSlotS0PosInUSSCoordTemp = APATrajCalPointPosWithAngAndCenterPt(stVSlotS0PosInDRCoordTemp, CenterAngBackup1, CenterPtBackup1);  //ת����USS�����½��бȽ�
                        u8CurbCalStartIndexTemp =  ObjPtIndexCalForVSlot(stVSlotS0PosInUSSCoordTemp,RIGHT);

                        stVSlotS1PosInDRCoordTemp.x = gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumRightTemp-1].stS1.Point.f32XMtr;
                        stVSlotS1PosInDRCoordTemp.y = gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumRightTemp-1].stS1.Point.f32YMtr;
                        stVSlotS1PosInUSSCoordTemp = APATrajCalPointPosWithAngAndCenterPt(stVSlotS1PosInDRCoordTemp, CenterAngBackup1, CenterPtBackup1);  //ת����USS�����½��бȽ�
                        u8CurbCalEndIndexTemp =  ObjPtIndexCalForVSlot(stVSlotS1PosInUSSCoordTemp,RIGHT);

                        if(LineParCalBaseUSSCoord(RIGHT,u8CurbCalStartIndexTemp,u8CurbCalEndIndexTemp,&pCurbLine) ==TRUE)
                        {//·����ϼ���ɹ�������н�����ݵ�USS out�������SIF��
                            //ֱ�߷�����ת����DR����ϵ�½��������TBD
                            u8USS_UCurbUpdateFlag[RIGHT] = UPDATE;
                            gUSS_stOut.stRightSideSlot.stCurbInfoForVSS.u8CurbForVSSUpdateFlag = UPDATE;
                            gUSS_stOut.stRightSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_u8CurbState = VALID;
                            gUSS_stOut.stRightSideSlot.stCurbInfoForVSS.gUSS_u8VSlotSource = u8CurrentSIFSlotNumRightTemp;
                            //20200915 

                            Dis = MATH_SQRT(CenterPtBackup3.x*CenterPtBackup3.x+CenterPtBackup3.y*CenterPtBackup3.y);
                            if (fabs(CenterPtBackup3.y) < 0.0001)
                            {
                                theta_NewToOldInUSS = 0;
                            }
                            else
                            {
                                theta_NewToOldInUSS = MATH_ATAN(CenterPtBackup3.x/CenterPtBackup3.y);
                            }
                            X_Trans = Dis*MATH_SIN(theta_NewToOldInUSS+CenterAngBackup3);
                            Y_Trans = Dis*MATH_COS(theta_NewToOldInUSS+CenterAngBackup3);
                            
                            USSCoor0PosInDRForVSlot.f32XMtr =  -X_Trans;
                            USSCoor0PosInDRForVSlot.f32YMtr =  -Y_Trans;
                            USSCoor0PosInDRForVSlot.f32ARad = -CenterAngBackup3 + PI/2;  
                            CurbLineInUSSCoordForVSlot.f32A = pCurbLine.A;
                            CurbLineInUSSCoordForVSlot.f32B = pCurbLine.B;
                            CurbLineInUSSCoordForVSlot.f32C = pCurbLine.C;

                            CF_CrdTrnsLineABCKnownNewOrgInOldCrd(USSCoor0PosInDRForVSlot,
                                                                CurbLineInUSSCoordForVSlot,
                                                                &CurbLineInDRCoordForVSlot);

                            gUSS_stOut.stRightSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_s16CurbLineParaA = CurbLineInDRCoordForVSlot.f32A;
                            gUSS_stOut.stRightSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_s16CurbLineParaB = CurbLineInDRCoordForVSlot.f32B;
                            gUSS_stOut.stRightSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_s16CurbLineParaC = CurbLineInDRCoordForVSlot.f32C;
                            //20200915
                        }
                        else
                        {
                            u8USS_UCurbUpdateFlag[RIGHT] = NOUPDATE;
                            gUSS_stOut.stRightSideSlot.stCurbInfoForVSS.u8CurbForVSSUpdateFlag = NOUPDATE;
                            gUSS_stOut.stRightSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_u8CurbState = INVALID;
                            //20200915 
                            gUSS_stOut.stRightSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_s16CurbLineParaA = 0.0;
                            gUSS_stOut.stRightSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_s16CurbLineParaB = 0.0;
                            gUSS_stOut.stRightSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_s16CurbLineParaC = 0.0;  
                            //20200915
                        }
                    }
                }
            }
            else
            {
                u8USS_UCurbUpdateFlag[RIGHT] = NOUPDATE;
            }
        }
        else
        {
            u8USS_UCurbUpdateFlag[RIGHT] = NOUPDATE;
        }
#if Debug_SW_VSlotCurb 

#else
        u8SIFRightSlotNumBackup = u8CurrentSIFSlotNumRightTemp;  //�������µ�SIF�г�λ��Ϣ
#endif
    }
    else
    {
        u8USS_UCurbUpdateFlag[RIGHT] = NOUPDATE;
         //20200915 
        gUSS_stOut.stRightSideSlot.stCurbInfoForVSS.u8CurbForVSSUpdateFlag = NOUPDATE;
        gUSS_stOut.stRightSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_u8CurbState = INVALID;
        gUSS_stOut.stRightSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_s16CurbLineParaA = 0.0;
        gUSS_stOut.stRightSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_s16CurbLineParaB = 0.0;
        gUSS_stOut.stRightSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_s16CurbLineParaC = 0.0;  
        //20200915
    }
    // ���SIF��λ��Ϣȷ��
    if(u8CurrentSIFSlotNumLeftTemp != 0u)
    {
        if(u8CurrentSIFSlotNumLeftTemp > u8SIFLeftSlotNumBackup)
        {// �ұ����µ�SIF��λ
            if(gSIF_stOut.gSIF_stSlotPool.stLSlotList[u8CurrentSIFSlotNumLeftTemp-1].u8Source == SLOT_PLD)
            {//����SIF��λ���߳�λ
                if(u8CurrentSIFSlotNumLeftTemp == 4)
                {//�����ǰSIF��λ������4ʱ����Ҫ�����߳�λS1����
                    stVSlotS1PosInDRBackupLeft.x = gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumLeftTemp-1].stS1.Point.f32XMtr;
                    stVSlotS1PosInDRBackupLeft.y = gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumLeftTemp-1].stS1.Point.f32YMtr;
                }
                stVSlotS0PosInDRCoordTemp.x = gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumLeftTemp-1].stS0.Point.f32XMtr;
                stVSlotS0PosInDRCoordTemp.y = gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumLeftTemp-1].stS0.Point.f32YMtr;
                stVSlotS0PosInUSSCoordTemp = APATrajCalPointPosWithAngAndCenterPt(stVSlotS0PosInDRCoordTemp, CenterAngBackup1, CenterPtBackup1);  //ת����USS�����½��бȽ�
                u8CurbCalStartIndexTemp =  ObjPtIndexCalForVSlot(stVSlotS0PosInUSSCoordTemp,LEFT);  //20200929

                stVSlotS1PosInDRCoordTemp.x = gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumLeftTemp-1].stS1.Point.f32XMtr;
                stVSlotS1PosInDRCoordTemp.y = gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumLeftTemp-1].stS1.Point.f32YMtr;
                stVSlotS1PosInUSSCoordTemp = APATrajCalPointPosWithAngAndCenterPt(stVSlotS1PosInDRCoordTemp, CenterAngBackup1, CenterPtBackup1);  //ת����USS�����½��бȽ�
                u8CurbCalEndIndexTemp =  ObjPtIndexCalForVSlot(stVSlotS1PosInUSSCoordTemp,LEFT);  //20200929

                if(LineParCalBaseUSSCoord(LEFT,u8CurbCalStartIndexTemp,u8CurbCalEndIndexTemp,&pCurbLine) ==TRUE)
                {//·����ϼ���ɹ�������н�����ݵ�USS out�������SIF
                    //ֱ�߷�����ת����DR����ϵ�½������  tbd
                    u8USS_UCurbUpdateFlag[LEFT] = UPDATE;
                    gUSS_stOut.stLeftSideSlot.stCurbInfoForVSS.u8CurbForVSSUpdateFlag = UPDATE;
                    gUSS_stOut.stLeftSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_u8CurbState = VALID;
                    gUSS_stOut.stLeftSideSlot.stCurbInfoForVSS.gUSS_u8VSlotSource = u8CurrentSIFSlotNumLeftTemp;
                    //20200915 

                    Dis = MATH_SQRT(CenterPtBackup3.x*CenterPtBackup3.x+CenterPtBackup3.y*CenterPtBackup3.y);
                    if (fabs(CenterPtBackup3.y) < 0.0001)
                    {
                    	theta_NewToOldInUSS = 0;
                    }
                    else
                    {
                    	theta_NewToOldInUSS = MATH_ATAN(CenterPtBackup3.x/CenterPtBackup3.y);
                    }
                    X_Trans = Dis*MATH_SIN(theta_NewToOldInUSS+CenterAngBackup3);
                    Y_Trans = Dis*MATH_COS(theta_NewToOldInUSS+CenterAngBackup3);
                    
                    USSCoor0PosInDRForVSlot.f32XMtr =  -X_Trans;
                    USSCoor0PosInDRForVSlot.f32YMtr =  -Y_Trans;
                    USSCoor0PosInDRForVSlot.f32ARad = -CenterAngBackup3 + PI/2;
                    CurbLineInUSSCoordForVSlot.f32A = pCurbLine.A;
                    CurbLineInUSSCoordForVSlot.f32B = pCurbLine.B;
                    CurbLineInUSSCoordForVSlot.f32C = pCurbLine.C;

                    CF_CrdTrnsLineABCKnownNewOrgInOldCrd(USSCoor0PosInDRForVSlot,
                                                        CurbLineInUSSCoordForVSlot,
                                                        &CurbLineInDRCoordForVSlot);

                    gUSS_stOut.stLeftSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_s16CurbLineParaA = CurbLineInDRCoordForVSlot.f32A;
                    gUSS_stOut.stLeftSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_s16CurbLineParaB = CurbLineInDRCoordForVSlot.f32B;
                    gUSS_stOut.stLeftSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_s16CurbLineParaC = CurbLineInDRCoordForVSlot.f32C;  
                    //20200915
                }
                else
                {
                    gUSS_stOut.stLeftSideSlot.stCurbInfoForVSS.u8CurbForVSSUpdateFlag = NOUPDATE;
                    gUSS_stOut.stLeftSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_u8CurbState = INVALID;
                    //20200915 
                    gUSS_stOut.stLeftSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_s16CurbLineParaA = 0.0;
                    gUSS_stOut.stLeftSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_s16CurbLineParaB = 0.0;
                    gUSS_stOut.stLeftSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_s16CurbLineParaC = 0.0;  
                    //20200915
                }
            }
            else
            {
                u8USS_UCurbUpdateFlag[LEFT] = NOUPDATE;
            }
        }
        else if(u8CurrentSIFSlotNumLeftTemp == u8SIFLeftSlotNumBackup) 
        {
            if(u8CurrentSIFSlotNumLeftTemp == 4u)
            {//��λ���ˣ�ֻȷ���µĿ�λ�Ƿ����߳�λ,�߳�λʱ����Ҫ�ͱ��ݵ�����ȶ��Ƿ��б仯���б仯ʱ����·������ж���ͬʱ���±��ݵ��߳�λS1���ꣻ�����߳�λʱ������ݵ��߳�λ��Ϣ
                if(gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumLeftTemp-1].u8Source == SLOT_PLD)
                {
                    f32VSlotS1PosXDevationMtrTemp = stVSlotS1PosInDRBackupLeft.x - gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumLeftTemp-1].stS1.Point.f32XMtr;
                    f32VSlotS1PosYDevationMtrTemp = stVSlotS1PosInDRBackupLeft.y - gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumLeftTemp-1].stS1.Point.f32YMtr;
                    if((MATH_FABS(f32VSlotS1PosXDevationMtrTemp)> 0.5)
                       &&(MATH_FABS(f32VSlotS1PosYDevationMtrTemp)> 0.5))
                    {   //SIF�����³�λ���߳�λ���Һͱ��ݵ��߳�λ���ݲ�һ�£��������������߳�λ����Ҫ��������ж���ͬʱ���ó�λ�����걸������
                        stVSlotS1PosInDRBackupLeft.x = gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumLeftTemp-1].stS1.Point.f32XMtr;
                        stVSlotS1PosInDRBackupLeft.y = gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumLeftTemp-1].stS1.Point.f32YMtr;

                        stVSlotS0PosInDRCoordTemp.x = gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumLeftTemp-1].stS0.Point.f32XMtr;
                        stVSlotS0PosInDRCoordTemp.y = gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumLeftTemp-1].stS0.Point.f32YMtr;
                        stVSlotS0PosInUSSCoordTemp = APATrajCalPointPosWithAngAndCenterPt(stVSlotS0PosInDRCoordTemp, CenterAngBackup1, CenterPtBackup1);  //ת����USS�����½��бȽ�
                        u8CurbCalStartIndexTemp =  ObjPtIndexCalForVSlot(stVSlotS0PosInUSSCoordTemp,RIGHT);

                        stVSlotS1PosInDRCoordTemp.x = gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumLeftTemp-1].stS1.Point.f32XMtr;
                        stVSlotS1PosInDRCoordTemp.y = gSIF_stOut.gSIF_stSlotPool.stRSlotList[u8CurrentSIFSlotNumLeftTemp-1].stS1.Point.f32YMtr;
                        stVSlotS1PosInUSSCoordTemp = APATrajCalPointPosWithAngAndCenterPt(stVSlotS1PosInDRCoordTemp, CenterAngBackup1, CenterPtBackup1);  //ת����USS�����½��бȽ�
                        u8CurbCalEndIndexTemp =  ObjPtIndexCalForVSlot(stVSlotS1PosInUSSCoordTemp,RIGHT);

                        if(LineParCalBaseUSSCoord(LEFT,u8CurbCalStartIndexTemp,u8CurbCalEndIndexTemp,&pCurbLine) ==TRUE)
                        {//·����ϼ���ɹ�������н�����ݵ�USS out�������SIF��
                            //ֱ�߷�����ת����DR����ϵ�½��������TBD
                            u8USS_UCurbUpdateFlag[LEFT] = UPDATE;
                            gUSS_stOut.stLeftSideSlot.stCurbInfoForVSS.u8CurbForVSSUpdateFlag = UPDATE;
                            gUSS_stOut.stLeftSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_u8CurbState = VALID;
                            gUSS_stOut.stLeftSideSlot.stCurbInfoForVSS.gUSS_u8VSlotSource = u8CurrentSIFSlotNumLeftTemp;
                            //20200915 

                            Dis = MATH_SQRT(CenterPtBackup3.x*CenterPtBackup3.x+CenterPtBackup3.y*CenterPtBackup3.y);
                            if (fabs(CenterPtBackup3.y) < 0.0001)
                            {
                                theta_NewToOldInUSS = 0;
                            }
                            else
                            {
                                theta_NewToOldInUSS = MATH_ATAN(CenterPtBackup3.x/CenterPtBackup3.y);
                            }
                            X_Trans = Dis*MATH_SIN(theta_NewToOldInUSS+CenterAngBackup3);
                            Y_Trans = Dis*MATH_COS(theta_NewToOldInUSS+CenterAngBackup3);
                            
                            USSCoor0PosInDRForVSlot.f32XMtr =  -X_Trans;
                            USSCoor0PosInDRForVSlot.f32YMtr =  -Y_Trans;
                            USSCoor0PosInDRForVSlot.f32ARad = -CenterAngBackup3 + PI/2; 
                            CurbLineInUSSCoordForVSlot.f32A = pCurbLine.A;
                            CurbLineInUSSCoordForVSlot.f32B = pCurbLine.B;
                            CurbLineInUSSCoordForVSlot.f32C = pCurbLine.C;

                            CF_CrdTrnsLineABCKnownNewOrgInOldCrd(USSCoor0PosInDRForVSlot,
                                                                CurbLineInUSSCoordForVSlot,
                                                                &CurbLineInDRCoordForVSlot);

                            gUSS_stOut.stLeftSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_s16CurbLineParaA = CurbLineInDRCoordForVSlot.f32A;
                            gUSS_stOut.stLeftSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_s16CurbLineParaB = CurbLineInDRCoordForVSlot.f32B;
                            gUSS_stOut.stLeftSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_s16CurbLineParaC = CurbLineInDRCoordForVSlot.f32C;  
                            //20200915
                        }
                        else
                        {
                            u8USS_UCurbUpdateFlag[LEFT] = NOUPDATE;
                            gUSS_stOut.stLeftSideSlot.stCurbInfoForVSS.u8CurbForVSSUpdateFlag = NOUPDATE;
                            gUSS_stOut.stLeftSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_u8CurbState = INVALID;
                            //20200915 
                            gUSS_stOut.stLeftSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_s16CurbLineParaA = 0.0;
                            gUSS_stOut.stLeftSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_s16CurbLineParaB = 0.0;
                            gUSS_stOut.stLeftSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_s16CurbLineParaC = 0.0;
                            //20200915
                        }
                    }
                }
            }
            else
            {
                u8USS_UCurbUpdateFlag[LEFT] = NOUPDATE;
            }
        }
        else
        {
            u8USS_UCurbUpdateFlag[LEFT] = NOUPDATE;
        }
        u8SIFLeftSlotNumBackup = u8CurrentSIFSlotNumLeftTemp;  //�������µ�SIF�г�λ��Ϣ
    }
    else
    {
        u8USS_UCurbUpdateFlag[LEFT] = NOUPDATE;
        //20200915 
        gUSS_stOut.stLeftSideSlot.stCurbInfoForVSS.u8CurbForVSSUpdateFlag = NOUPDATE;
        gUSS_stOut.stLeftSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_u8CurbState = INVALID;
        gUSS_stOut.stLeftSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_s16CurbLineParaA = 0.0;
        gUSS_stOut.stLeftSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_s16CurbLineParaB = 0.0;
        gUSS_stOut.stLeftSideSlot.stCurbInfoForVSS.stCurbParForVSS.gUSS_s16CurbLineParaC = 0.0;  
        //20200915
    }
}
/*************************************************************************************************************************************************
** Syntax :  void CheckUpdateFlag(void)                                                                                                         **
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
** Description : ����USS�ĳ�λ��Ϣ���߳�λ��·�����״̬������Ӧ��������¼���SIF֮��Ľ���                                                           **
**                                                                                                                                              **
*************************************************************************************************************************************************/
void CheckUpdateFlag(void)
{
    static uint8 u8USSUpdateFlag[2] = {0};
    static uint8 u8WaitConfirmTimeOutCnt[2] = {0};

//right side
    if((u8USS_USlotUpdateFlag[RIGHT] == UPDATE)
       ||(u8USS_UCurbUpdateFlag[RIGHT] == UPDATE) 
       ||(u8USSUpdateFlag[RIGHT] == WAITSIFCONFIRM))
    {
        u8WaitConfirmTimeOutCnt[RIGHT]++;
        if(u8USSUpdateFlag[RIGHT] == DEFAULT)
        {
            u8USSUpdateFlag[RIGHT] = WAITSIFCONFIRM;
            if(u8USS_USlotUpdateFlag[RIGHT] == UPDATE)
            {
                u8WaitConfirmTimeOutCnt[RIGHT] = 0u;
                gUSS_stOut.stRightSideSlot.gUSS_u8UpdState = SLOT_UPDATE;
                u8USS_USlotUpdateFlag[RIGHT] = DEFAULT;
            }
            else if(u8USS_UCurbUpdateFlag[RIGHT] == UPDATE)
            {
                u8WaitConfirmTimeOutCnt[RIGHT] = 0u;
                gUSS_stOut.stRightSideSlot.gUSS_u8UpdState = CURB_UPDATE;
                u8USS_UCurbUpdateFlag[RIGHT] = DEFAULT;
            }
            else
            {// �Ҳ೵λ���߳�λ��·�ض��޸���
            } 
        }
        if((gSIF_stOut.gSIF_u8UslotConfirmR == 1)
           ||(u8WaitConfirmTimeOutCnt[RIGHT] >=10u))
        {
            u8WaitConfirmTimeOutCnt[RIGHT] = 0;
            u8USSUpdateFlag[RIGHT] = DEFAULT;
            gUSS_stOut.stRightSideSlot.gUSS_u8UpdState = NOUPDATE; 
            // memset(&gUSS_stOut.stRightSideSlot, 0, sizeof(gUSS_stOut.stRightSideSlot));  //20200826

        }
    }
    else
    {
        u8USSUpdateFlag[RIGHT] = DEFAULT;
        gUSS_stOut.stRightSideSlot.gUSS_u8UpdState = NOUPDATE;
    }
//left side
    if((u8USS_USlotUpdateFlag[LEFT] == UPDATE)
       ||(u8USS_UCurbUpdateFlag[LEFT] == UPDATE) 
       ||(u8USSUpdateFlag[LEFT] == WAITSIFCONFIRM))
    {
        u8WaitConfirmTimeOutCnt[LEFT]++;
        if(u8USSUpdateFlag[LEFT] == DEFAULT)
        {
            u8USSUpdateFlag[LEFT] = WAITSIFCONFIRM;
            if(u8USS_USlotUpdateFlag[LEFT] == UPDATE)
            {
                u8WaitConfirmTimeOutCnt[LEFT] = 0u;
                gUSS_stOut.stLeftSideSlot.gUSS_u8UpdState = SLOT_UPDATE;
                u8USS_USlotUpdateFlag[LEFT] = DEFAULT;
            }
            else if(u8USS_UCurbUpdateFlag[LEFT] == UPDATE)
            {
                u8WaitConfirmTimeOutCnt[LEFT] = 0u;
                gUSS_stOut.stLeftSideSlot.gUSS_u8UpdState = CURB_UPDATE;
                u8USS_UCurbUpdateFlag[LEFT] = DEFAULT;
            }
            else
            {// ��೵λ���߳�λ��·�ض��޸���
            } 
        }
        if((gSIF_stOut.gSIF_u8UslotConfirmL == 1)
           ||(u8WaitConfirmTimeOutCnt[LEFT] >=10u))
        {
            u8WaitConfirmTimeOutCnt[LEFT] = 0;
            u8USSUpdateFlag[LEFT] = DEFAULT;
            gUSS_stOut.stLeftSideSlot.gUSS_u8UpdState = NOUPDATE; 
            // memset(&gUSS_stOut.stLeftSideSlot, 0, sizeof(gUSS_stOut.stLeftSideSlot));   //20200826
        }
    }
    else
    {
        u8USSUpdateFlag[LEFT] = DEFAULT;
        gUSS_stOut.stLeftSideSlot.gUSS_u8UpdState = NOUPDATE;
    }
}

/*************************************************************************************************************************************************
**                                                     Global Function Definitions                                                              **
*************************************************************************************************************************************************/
/*************************************************************************************************************************************************
** Syntax :  void USS_ModeCheck(void)                                                                                                           **
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
void USS_ModeCheck(void)
{
    //static uint8 u8ParkINSts = 0u;//20200915PM
    static uint8 u8BackwardCnt = 0u;
    gSIF_stOut.gSIF_u8USSEnbl = USS_ON;
    gDR_stOut.gDR_u8VehDircn=1;
    if(gSIF_stOut.gSIF_u8USSEnbl == USS_ON )
    {
        gUSS_stOut.gUSS_u8State = ON;
        if (gDR_stOut.gDR_u8VehDircn == 2)   	//backward 20200826 start
        {
        	if(u8BackwardCnt<10)
        	{
        		u8BackwardCnt++;
        	}
        	else
        	{
                u8USS_DataHandleSW = OFF;
                u8OIC_DataHandleSW = OFF;
                u8USS_OnStates = OFF;
                USSPar.APAState = APA_STATE_DISABLE;
        	}
        }
        else if(gDR_stOut.gDR_u8VehDircn==1)    //forward
        {
            u8USS_DataHandleSW = ON;
            u8OIC_DataHandleSW = ON;
        	u8BackwardCnt = 0u;
            USSPar.APAState = APA_STATE_ENABLE;
            u8USS_OnStates = SCAN;
        }else
        {
        }    										//20200826 end       
    }
    else
    {
        gUSS_stOut.gUSS_u8State = OFF;
        //u8ParkINSts  = 0u;  //20200915PM
        u8USS_DataHandleSW = OFF;
        u8OIC_DataHandleSW = OFF;
        u8USS_OnStates = OFF;
        USSPar.APAState = APA_STATE_DISABLE;
    } 
}

/*************************************************************************************************************************************************
** Syntax :  void USS_DataHandle(void)                                                                                                          **
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
** Description : ����mode check�и��µ�flag������ص����ݴ�������Ҫ����ʱ����ģʽ������ɨ�軹�ǿ�λ���£�����Ҫ����ʱ��ʼ��������ݣ�                    **
**               ������Ҫ����ʱ�������½���                                                                                                       **
**                 Step1: ȷ�������Ƿ���Ҫת����USS���������жϺͲ��������ת������λ�����£�                                                         **
**                 Step2��ȷ�ϲ೬���Ƿ��и��£��и���ʱ����������ݸ��£�DR����ϵ������ת����USS�����£�                                              **
**                 Step3����ȡtaskִ�н���������ݽ������USS��ص��������                                                                         **
**                 Step4: ��ȡSIF�߳�λ��Ϣ�������߳�λ����·���ߵ�������                                                                         **
**                 Step5�����ݳ�λ���߳�λ��·����Ϣ����SIF���������Ϣ���µĽ�������                                                                **
*************************************************************************************************************************************************/
void USS_DataHandle(void)
{
    static uint8 u8ExcuteFirstTimeFlag = 0;
    //uint8 u8DRCheckResult = 0u;  20200915pm
    u8USS_DataHandleSW = ON;
    if(u8USS_DataHandleSW == ON)
    {
        
        u8ExcuteFirstTimeFlag = 0;
        if(u8USS_OnStates == SCAN)   // ģ��1��DR������USS����ԭ��ĶԱ��ж�������USS����(ģ�����������u8USS_OnStates��USS����ȷ�������� or ��λ����ϵ)��������º�����е��ת���ҽ��е�y���������
        {
            TransCoordinate(USS_COORD);     // ������ת��USSȷ��������ϵ��
        }
        else if(u8USS_OnStates == PARKIN)
        {
			TransCoordinate(SLOT_COORD);    // ������ϵת����λ����ϵ��
		}
        else
        { // ��ת��
		}
// ɾ����ģ��TBD

       if(gUSD_stOut.gUSD_stSideObject.gUSD_SideUpdFlag != u8SideSensorUpdateBackupFlag)  //for hightec
        {   
            u8USS_CutSteps = 1;
            u8SideSensorUpdateBackupFlag = gUSD_stOut.gUSD_stSideObject.gUSD_SideUpdFlag;  //for hightec

            if(u8USS_OnStates == SCAN)
            {

                SaveAPASnsDtdRawData(0);  // ģ��2�� �����״����ݸ��µ�USS��������뵽һ��������,����ʱ����ǰ���ϰ�����Ϣ
            }
            else if(u8USS_OnStates==PARKIN)
            {
                SaveAPASnsDtdRawData(SLOT_LEFT);   // left,������SIF����ȷ��Ҫ����ķ���  TBD
                SaveAPASnsDtdRawData(SLOT_RIGHT);  // right,������SIF����ȷ��Ҫ����ķ���  TBD
            }
            else
            { // ��ת��
            }
        }
        else
        {// ��������δ����
        }

        if(u8USS_OnStates == SCAN)
        {
#if SPLITTASK
            if (u8USS_CutSteps == 4)
            {
#endif
                SlotInfoDataHandleNew(SCAN); // ģ��3����ȡtask�����Ľ����������USS��������(ģ�����������u8USS_OnStates)������ǻ���DR����ϵ
                                                //       ���ݳ�λ������SIF֮����н���
                                                //       ���⳵λ�������7.2m�ĳ�λcase�ر�����
                                                //       �ھ���edge1 3.2m֮����г�λ��Ϣ�����
                                                //       ·������� curb ����ο�APATrajCalFitCurbLineAccordingToSlotData

                CheckCurbForVSlot();     // ģ��4����ȡSIF���߳�λ��Ϣ��ȷ���Ƿ���Ҫ����·����Ϲ��ܣ���ȷ���߳�λ��·����ϵĽ��,�߳�λ��·����ռ䳵λ��·�ز�����

                CheckUpdateFlag();       // ģ��5�����ݳ�λ���Ӿ���λ��·����Ϣ��SIF������ȷ����Ϣ����λ�������Ӧ��updateflag
#if SPLITTASK
            }
#endif
        }
        else if(u8USS_OnStates == PARKIN)
        {
#if SPLITTASK
            if (u8USS_CutSteps == 4)
            {
#endif
                SlotInfoDataHandleNew(PARKIN);
#if SPLITTASK
            }
#endif
        }
        else
        {//�쳣�������������������ִ�е�
        }
    }
    else   
    {
        if(u8ExcuteFirstTimeFlag != 1u)
        {
            u8ExcuteFirstTimeFlag = 1u;
            USSDataInitialize();     //ģ��5���������ݳ�ʼ����������ʼ������USS������ͱ�����Ϣ, //20200826
        }
    } 
}

/*************************************************************************************************************************************************
** Syntax :  void SendCanInfoOutForIntegration(void)                                                                                            **
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
** Description : ���ݴ󼯳ɰ汾��DBC��������Ϣ                                                                                                    **
*************************************************************************************************************************************************/
#if Debug_SW_PrivateCANForIntegration
void SendCanInfoOutForIntegration(void)
{
    sint32 SlotPar_Edge0_X, SlotPar_Edge0_Y, SlotPar_Edge1_X, SlotPar_Edge1_Y;
    sint8 SlotPar_Obj1StartPtIndex, SlotPar_Obj1EndPtIndex, SlotPar_Obj2EndPtIndex, SlotPar_Obj2StartPtIndex;
    sint8 SlotPar_SlotEndIndex, SlotPar_SlotStartIndex, SlotPar_Obj1Type, SlotPar_Obj2Type;
    uint8 Edge0_VirtualSts, Edge1_VirtualSts, SlotInfo_Side;
    sint16 SlotPar_SlotDepth, SlotPar_SlotLengthTotal;
    sint32 CurbLine_C, CurbLine_A, CurbLine_B, CarCenterPt_DR_Coordinate_X, CarCenterPt_DR_Coordinate_y, CarCenterPt_DR_CarAng;
    APACoordinateDataCalFloatType CurrentPtInNewCoordinate;
    APA_DISTANCE_TYPE CarPassSlotEndPtDis;
    APA_ENUM_TYPE ObjPtCnt, SlotNum_Right, SlotNum_Left;

    if (u8USS_CutSteps == 4)
    {
        SendOutLeftOrRight ^= 0x01;
    }
    else
    {

    }
    /**************DBC_USS_test15****************/
    if(SendOutLeftOrRight == 0)
    {
        SlotPar_Edge0_X = (sint32)(gUSS_stOut.stRightSideSlot.stEdge0Info.gUSS_f32PosX * 1000.0);
	    SlotPar_Edge0_Y = (sint32)(gUSS_stOut.stRightSideSlot.stEdge0Info.gUSS_f32PosY * 1000.0);
    }
    else
    {
        SlotPar_Edge0_X = (sint32)(gUSS_stOut.stLeftSideSlot.stEdge0Info.gUSS_f32PosX * 1000.0);
	    SlotPar_Edge0_Y = (sint32)(gUSS_stOut.stLeftSideSlot.stEdge0Info.gUSS_f32PosY * 1000.0);
    }
	
    gSec_015_data.u8_CAN_015_Tx_data[0] = SlotPar_Edge0_X >> 24;
    gSec_015_data.u8_CAN_015_Tx_data[1] = SlotPar_Edge0_X >> 16;
    gSec_015_data.u8_CAN_015_Tx_data[2] = SlotPar_Edge0_X >> 8;
    gSec_015_data.u8_CAN_015_Tx_data[3] = SlotPar_Edge0_X & 0xFF;
    gSec_015_data.u8_CAN_015_Tx_data[4] = SlotPar_Edge0_Y >> 24;
    gSec_015_data.u8_CAN_015_Tx_data[5] = SlotPar_Edge0_Y >> 16;
    gSec_015_data.u8_CAN_015_Tx_data[6] = SlotPar_Edge0_Y >> 8;
    gSec_015_data.u8_CAN_015_Tx_data[7] = SlotPar_Edge0_Y & 0xFF;
	/**************DBC_USS_test15****************/
	/**************DBC_USS_test16****************/
    if(SendOutLeftOrRight == 0)
    {
        SlotPar_Edge1_X = (sint32)(gUSS_stOut.stRightSideSlot.stEdge1Info.gUSS_f32PosX * 1000.0);
	    SlotPar_Edge1_Y = (sint32)(gUSS_stOut.stRightSideSlot.stEdge1Info.gUSS_f32PosY * 1000.0);

    }else
    {
        SlotPar_Edge1_X = (sint32)(gUSS_stOut.stLeftSideSlot.stEdge1Info.gUSS_f32PosX * 1000.0);
	    SlotPar_Edge1_Y = (sint32)(gUSS_stOut.stLeftSideSlot.stEdge1Info.gUSS_f32PosY * 1000.0);
    }

	gSec_016_data.u8_CAN_016_Tx_data[0] = SlotPar_Edge1_X >> 24;
    gSec_016_data.u8_CAN_016_Tx_data[1] = SlotPar_Edge1_X >> 16;
    gSec_016_data.u8_CAN_016_Tx_data[2] = SlotPar_Edge1_X >> 8;
    gSec_016_data.u8_CAN_016_Tx_data[3] = SlotPar_Edge1_X & 0xFF;
    gSec_016_data.u8_CAN_016_Tx_data[4] = SlotPar_Edge1_Y >> 24;
    gSec_016_data.u8_CAN_016_Tx_data[5] = SlotPar_Edge1_Y >> 16;
    gSec_016_data.u8_CAN_016_Tx_data[6] = SlotPar_Edge1_Y >> 8;
    gSec_016_data.u8_CAN_016_Tx_data[7] = SlotPar_Edge1_Y & 0xFF;
    /**************DBC_USS_test16****************/
    /**************DBC_USS_test17****************/
    if (SendOutLeftOrRight == 0)
    {
        SlotPar_Obj1StartPtIndex = SlotInfoToOutput[0].SlotPar_Obj1StartPtIndex;
        SlotPar_Obj1EndPtIndex = SlotInfoToOutput[0].SlotPar_Obj1EndPtIndex;
        SlotPar_Obj2StartPtIndex = SlotInfoToOutput[0].SlotPar_Obj2StartPtIndex;
        SlotPar_Obj2EndPtIndex = SlotInfoToOutput[0].SlotPar_Obj2EndPtIndex;
        SlotPar_SlotStartIndex = SlotInfoToOutput[0].SlotPar_SlotStartIndex;
        SlotPar_SlotEndIndex = SlotInfoToOutput[0].SlotPar_SlotEndIndex;
        SlotPar_Obj1Type = SlotInfoToOutput[0].SlotPar_Obj1Type;
        SlotPar_Obj2Type = SlotInfoToOutput[0].SlotPar_Obj2Type;
        Edge0_VirtualSts = gUSS_stOut.stRightSideSlot.stEdge0Info.gUSS_u8VirtualFlg;
        Edge1_VirtualSts = gUSS_stOut.stRightSideSlot.stEdge1Info.gUSS_u8VirtualFlg;
        SlotInfo_Side = SendOutLeftOrRight;
    }
    else
    {
        SlotPar_Obj1StartPtIndex = SlotInfoToOutput[1].SlotPar_Obj1StartPtIndex;
        SlotPar_Obj1EndPtIndex = SlotInfoToOutput[1].SlotPar_Obj1EndPtIndex;
        SlotPar_Obj2StartPtIndex = SlotInfoToOutput[1].SlotPar_Obj2StartPtIndex;
        SlotPar_Obj2EndPtIndex = SlotInfoToOutput[1].SlotPar_Obj2EndPtIndex;
        SlotPar_SlotStartIndex = SlotInfoToOutput[1].SlotPar_SlotStartIndex;
        SlotPar_SlotEndIndex = SlotInfoToOutput[1].SlotPar_SlotEndIndex;
        SlotPar_Obj1Type = SlotInfoToOutput[1].SlotPar_Obj1Type;
        SlotPar_Obj2Type = SlotInfoToOutput[1].SlotPar_Obj2Type;
        Edge0_VirtualSts = gUSS_stOut.stLeftSideSlot.stEdge0Info.gUSS_u8VirtualFlg;
        Edge1_VirtualSts = gUSS_stOut.stLeftSideSlot.stEdge1Info.gUSS_u8VirtualFlg;
        SlotInfo_Side = SendOutLeftOrRight;
    }

    gSec_017_data.u8_CAN_017_Tx_data[0] = SlotPar_Obj1StartPtIndex;
    gSec_017_data.u8_CAN_017_Tx_data[1] = SlotPar_Obj1EndPtIndex;
    gSec_017_data.u8_CAN_017_Tx_data[2] = SlotPar_Obj2StartPtIndex;
    gSec_017_data.u8_CAN_017_Tx_data[3] = SlotPar_Obj2EndPtIndex;
    gSec_017_data.u8_CAN_017_Tx_data[4] = ((SlotPar_Obj1Type & 0x3F) << 2) + ((Edge1_VirtualSts & 0x01) << 1) + (SlotInfo_Side & 0x01);
    gSec_017_data.u8_CAN_017_Tx_data[5] = ((SlotPar_Obj2Type  & 0x3F) << 2) + (Edge0_VirtualSts & 0x01);
    gSec_017_data.u8_CAN_017_Tx_data[6] = SlotPar_SlotStartIndex;
    gSec_017_data.u8_CAN_017_Tx_data[7] = SlotPar_SlotEndIndex;
    /**************DBC_USS_test17****************/
    /**************DBC_USS_test18****************/
    if (SendOutLeftOrRight == 0)
    {
        SlotPar_SlotDepth = SlotInfoToOutput[0].SlotPar_SlotDepth;
        SlotPar_SlotLengthTotal = SlotInfoToOutput[0].SlotPar_SlotLengthTotal;
        CurbLine_C = (sint32)(gUSS_stOut.stRightSideSlot.stCurbInfo.gUSS_s16CurbLineParaC * 10000.0);
    }
    else
    {
        SlotPar_SlotDepth = SlotInfoToOutput[1].SlotPar_SlotDepth;
        SlotPar_SlotLengthTotal = SlotInfoToOutput[1].SlotPar_SlotLengthTotal;
        CurbLine_C = (sint32)(gUSS_stOut.stLeftSideSlot.stCurbInfo.gUSS_s16CurbLineParaC * 10000.0);
    }
    gSec_018_data.u8_CAN_018_Tx_data[0] = SlotPar_SlotDepth >> 8;
    gSec_018_data.u8_CAN_018_Tx_data[1] = SlotPar_SlotDepth & 0xFF;
    gSec_018_data.u8_CAN_018_Tx_data[2] = SlotPar_SlotLengthTotal >> 8;
    gSec_018_data.u8_CAN_018_Tx_data[3] = SlotPar_SlotLengthTotal & 0xFF;
    gSec_018_data.u8_CAN_018_Tx_data[4] = CurbLine_C >> 24;
    gSec_018_data.u8_CAN_018_Tx_data[5] = CurbLine_C >> 16;
    gSec_018_data.u8_CAN_018_Tx_data[6] = CurbLine_C >> 8;
    gSec_018_data.u8_CAN_018_Tx_data[7] = CurbLine_C & 0xFF;
    /**************DBC_USS_test18****************/
    /**************DBC_USS_test19****************/
    if (SendOutLeftOrRight == 0)
    {
        CurbLine_A = (sint32)(gUSS_stOut.stRightSideSlot.stCurbInfo.gUSS_s16CurbLineParaA * 10000.0);
        CurbLine_B = (sint32)(gUSS_stOut.stRightSideSlot.stCurbInfo.gUSS_s16CurbLineParaB * 10000.0);
    }
    else
    {
        CurbLine_A = (sint32)(gUSS_stOut.stLeftSideSlot.stCurbInfo.gUSS_s16CurbLineParaA * 10000.0);
        CurbLine_B = (sint32)(gUSS_stOut.stLeftSideSlot.stCurbInfo.gUSS_s16CurbLineParaB * 10000.0);
    }
    gSec_019_data.u8_CAN_019_Tx_data[0] = CurbLine_A >> 24;
    gSec_019_data.u8_CAN_019_Tx_data[1] = CurbLine_A >> 16;
    gSec_019_data.u8_CAN_019_Tx_data[2] = CurbLine_A >> 8;
    gSec_019_data.u8_CAN_019_Tx_data[3] = CurbLine_A & 0xFF;
    gSec_019_data.u8_CAN_019_Tx_data[4] = CurbLine_B >> 24;
    gSec_019_data.u8_CAN_019_Tx_data[5] = CurbLine_B >> 16;
    gSec_019_data.u8_CAN_019_Tx_data[6] = CurbLine_B >> 8;
    gSec_019_data.u8_CAN_019_Tx_data[7] = CurbLine_B & 0xFF;
    /**************DBC_USS_test19****************/
    /* 0x1A is in UOD.c;0x31-0x33 is in SaveAPASnsDtdRawData */
    if (u8USS_CutSteps == 2)
    {
        /**************DBC_USS_test34****************/
        /*�ҵ����ݵ�task���õ���APACarPar��DR����*/
        CurrentPtInNewCoordinate = APATrajCalPointPosWithAngAndCenterPt(CarCenterPtBackUp.Coordinate, CenterAngBackup3, CenterPtBackup3);
        Test_RC_34 = Test_RC_31;
        /*ת��DR����ϵ*/
        CarCenterPt_DR_Coordinate_X = (sint32)CurrentPtInNewCoordinate.y;
        CarCenterPt_DR_Coordinate_y = (sint32)(-CurrentPtInNewCoordinate.x);
        if (CarCenterPt_DR_Coordinate_X >= 0)
        {
            gSec_034_data.u8_CAN_034_Tx_data[0] = (CarCenterPt_DR_Coordinate_X >> 22) & 0x7F;
        }
        else
        {
            gSec_034_data.u8_CAN_034_Tx_data[0] = (0x01 << 7) + ((CarCenterPt_DR_Coordinate_X >> 22) & 0x7F);
        }
        gSec_034_data.u8_CAN_034_Tx_data[1] = (CarCenterPt_DR_Coordinate_X >> 14) & 0xFF;
        gSec_034_data.u8_CAN_034_Tx_data[2] = (CarCenterPt_DR_Coordinate_X >> 6) & 0xFF;
        gSec_034_data.u8_CAN_034_Tx_data[3] = ((CarCenterPt_DR_Coordinate_X & 0x3F) << 2) + (Test_RC_34 & 0x03);
        if (CarCenterPt_DR_Coordinate_y >= 0)
        {
            gSec_034_data.u8_CAN_034_Tx_data[4] = (CarCenterPt_DR_Coordinate_y >> 22) & 0x7F;
        }
        else
        {
            gSec_034_data.u8_CAN_034_Tx_data[4] = (0x01 << 7) + ((CarCenterPt_DR_Coordinate_y >> 22) & 0x7F);
        }
        gSec_034_data.u8_CAN_034_Tx_data[5] = (CarCenterPt_DR_Coordinate_y >> 14) & 0xFF;
        gSec_034_data.u8_CAN_034_Tx_data[6] = (CarCenterPt_DR_Coordinate_y >> 6) & 0xFF;
        gSec_034_data.u8_CAN_034_Tx_data[7] = (CarCenterPt_DR_Coordinate_y & 0x3F) << 2;
        /**************DBC_USS_test34****************/
        /**************DBC_USS_test35****************/
        Test_RC_35 = Test_RC_31;
        CarCenterPt_DR_CarAng = (sint32)((CarCenterPtBackUp.CarAng+CenterAngBackup3)*180.0/PI*10000.0);
        if (SendOutLeftOrRight == 0)
        {
            CarPassSlotEndPtDis = SlotInfoToOutput[0].CarPassTheSlotEndPtDistance;
            ObjPtCnt = SlotInfoToOutput[0].ObjPtCnt;
        }
        else
        {
            CarPassSlotEndPtDis = SlotInfoToOutput[1].CarPassTheSlotEndPtDistance;
            ObjPtCnt = SlotInfoToOutput[1].ObjPtCnt;
        }
        SlotNum_Right = USSPar.Slot[0].SlotNum;;
        SlotNum_Left = USSPar.Slot[1].SlotNum;

        gSec_035_data.u8_CAN_035_Tx_data[0] = CarCenterPt_DR_CarAng >> 24;
        gSec_035_data.u8_CAN_035_Tx_data[1] = CarCenterPt_DR_CarAng >> 16;
        gSec_035_data.u8_CAN_035_Tx_data[2] = CarCenterPt_DR_CarAng >> 8;
        gSec_035_data.u8_CAN_035_Tx_data[3] = CarCenterPt_DR_CarAng & 0xFF;
        gSec_035_data.u8_CAN_035_Tx_data[4] = CarPassSlotEndPtDis >> 8;
        gSec_035_data.u8_CAN_035_Tx_data[5] = CarPassSlotEndPtDis & 0xFF;
        gSec_035_data.u8_CAN_035_Tx_data[6] = ((SlotNum_Left & 0x03) << 6) + ((SlotNum_Right & 0x03) << 4) + ((Test_RC_35 & 0x03) << 2);
        gSec_035_data.u8_CAN_035_Tx_data[7] = ObjPtCnt;
        /**************DBC_USS_test36****************/
    }
    else
    {

    }
}
#endif

/*************************************************************************************************************************************************
** Syntax :  void SendCanInfoOutForUss(void)                                                                                                    **
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
** Description : ���ڴ󼯳ɰ汾��DBC�޸ģ�����USS�ڲ�����GUI��ʾ����Ϣ                                                                              **
*************************************************************************************************************************************************/
#if Debug_SW_PrivateCANForUSS
void SendCanInfoOutForUss(void)
{
    sint16 SlotCompeHead, SlotCompeTail, SlotCalDisCarToObj1, SlotCalDisCarToObj2;
    if (SendOutLeftOrRight == 0)
    {
        SlotCompeHead = SlotInfoToOutput[0].SlotPar_SlotCompeHead;
        SlotCompeTail = SlotInfoToOutput[0].SlotPar_SlotCompeTail;
        SlotCalDisCarToObj1 = SlotInfoToOutput[0].SlotPar_SlotCalDisCarToObj1;
        SlotCalDisCarToObj2 = SlotInfoToOutput[0].SlotPar_SlotCalDisCarToObj2;
    }
    else
    {
        SlotCompeHead = SlotInfoToOutput[1].SlotPar_SlotCompeHead;
        SlotCompeTail = SlotInfoToOutput[1].SlotPar_SlotCompeTail;
        SlotCalDisCarToObj1 = SlotInfoToOutput[1].SlotPar_SlotCalDisCarToObj1;
        SlotCalDisCarToObj2 = SlotInfoToOutput[1].SlotPar_SlotCalDisCarToObj2;
    }

    gSec_036_data.u8_CAN_036_Tx_data[0] = (SlotCompeHead >> 8) & 0xFF;
    gSec_036_data.u8_CAN_036_Tx_data[1] = SlotCompeHead & 0xFF;
    gSec_036_data.u8_CAN_036_Tx_data[2] = (SlotCompeTail >> 8) & 0xFF;
    gSec_036_data.u8_CAN_036_Tx_data[3] = SlotCompeTail & 0xFF;
    gSec_036_data.u8_CAN_036_Tx_data[4] = (SlotCalDisCarToObj1 >> 8) & 0xFF;
    gSec_036_data.u8_CAN_036_Tx_data[5] = SlotCalDisCarToObj1 & 0xFF;
    gSec_036_data.u8_CAN_036_Tx_data[6] = (SlotCalDisCarToObj2 >> 8) & 0xFF;
    gSec_036_data.u8_CAN_036_Tx_data[7] = SlotCalDisCarToObj2 & 0xFF;
}
#endif

/*************************************************************************************************************************************************
** Syntax :  void SendUSSOutput(uint8 UpdateFlag)                                                                                               **
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
** Description : ����mode check�и��µ�flag������ص����ݴ�������Ҫ����ʱ����ģʽ������ɨ�軹�ǿ�λ���£�����Ҫ����ʱ��ʼ��������ݣ�                    **
**               ������Ҫ����ʱ�������½���                                                                                                       **
**                 Step1: ȷ�������Ƿ���Ҫת����USS���������жϺͲ��������ת������λ�����£�                                                         **
**                 Step2��ȷ�ϲ೬���Ƿ��и��£��и���ʱ����������ݸ��£�DR����ϵ������ת����USS�����£�                                              **
**                 Step3����ȡtaskִ�н���������ݽ������USS��ص��������                                                                         **
**                 Step4: ��ȡSIF�߳�λ��Ϣ�������߳�λ����·���ߵ�������                                                                         **
**                 Step5�����ݳ�λ���߳�λ��·����Ϣ����SIF���������Ϣ���µĽ�������                                                                **
*************************************************************************************************************************************************/
#if 0//Debug_SW_InforCANOutput /* wsc 20200805 Debug_SW_ExeTimeTest->Debug_SW_InforCANOutput*/
void SendUSSOutput(uint8 UpdateFlag)
{
    static uint8  u8SideSnsUpdateFlag_bak = 0u;
    APA_ENUM_TYPE CurrentSlotNumTem =0u;

    static uint8 USS_Test_RC_707 = 0u;
    // SlotLane_ObjPtCnt;
    // SlotLane_ChangeCnt1;
    // SlotLane_ChangeEndIndex1;
    // SlotLane_ChangeStartIndex1;
    // SlotLane_ChangeCnt2;
    // SlotLane_ChangeEndIndex2;
    // SlotLane_ChangeStartIndex2;

    static uint8 USS_Test_RC_708 = 0u;
    uchar SlotDir;
    schar SlotNum_Right;
    schar SlotNum_Left;
    sint16 SlotPar_DisCarToObj1ByPassingSlot;
    sint16 SlotPar_DisCarToObj2ByPassingSlot;
    schar SlotPar_Type;

    static uint8 USS_Test_RC_709 = 0u;
    schar SlotPar_Obj1EndPtIndex;
    schar SlotPar_Obj1StartPtIndex;
    schar SlotPar_Obj1Type;
    schar SlotPar_Obj2Type;
    schar SlotPar_Obj2EndPtIndex;
    schar SlotPar_Obj2StartPtIndex;
    schar SlotPar_SlotEndIndex;
    schar SlotPar_SlotStartIndex;

    // static uint8 USS_Test_RC_70A = 0u;
    // sint32 SlotPar_Edge0_X;
    // sint32 SlotPar_Edge0_Y;

    // static uint8 USS_Test_RC_70B = 0u;
    // sint32 SlotPar_Edge1_X;
    // sint32 SlotPar_Edge1_Y;

    static uint8 USS_Test_RC_70C = 0u;
    sint16 SlotPar_SlotCompeHead;
    sint16 SlotPar_SlotCompeTail;
    sint16 SlotPar_SlotDepth;
    sint16 SlotPar_SlotLengthTotal;

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

	if(u8SideSnsUpdateFlag_bak==UpdateFlag)  /*�ж����޸��£��޸���ʱ���������� */
	{
	    return;  //no update
	}
	u8SideSnsUpdateFlag_bak = UpdateFlag;

    if(SendOutHistory == 0)
    {
    	SendOutHistory = SendOutHistory + 1;
    }
    CurrentSlotNumTem= USSPar.Slot[SendOutLeftOrRight].SlotNum;
    if(CurrentSlotNumTem > 0)
    {
        CurrentSlotNumTem = CurrentSlotNumTem - 1;
    }
    

	/**************DBC_USS_ObjPt_15_CarPos****************/
	// USS_Test_Rc_15 ^=0x01;
    USS_Test_Rc_15 = USS_Test_Rc_11;
	// APA_INDEX_TYPE slot_start_index = USSPar.Slot[SendOutLeftOrRight].SlotPar[CurrentSlotNumTem].SlotStartIndex;
	// SlotStartInd_CarPos_X = (sint32)(USSPar.Slot[SendOutLeftOrRight].SlotOutline.Lane.CarCenterPoint[slot_start_index].x);
	// SlotStartInd_CarPos_Y = (sint32)(USSPar.Slot[SendOutLeftOrRight].SlotOutline.Lane.CarCenterPoint[slot_start_index].y);
    if (SendOutLeftOrRight == 0)
    {
        SlotStartInd_CarPos_X = gUSS_stOut.stRightSideSlot.SlotStartInd_CarPos_X;
        SlotStartInd_CarPos_Y = gUSS_stOut.stRightSideSlot.SlotStartInd_CarPos_Y;
    }
    else
    {
        SlotStartInd_CarPos_X = gUSS_stOut.stLeftSideSlot.SlotStartInd_CarPos_X;
        SlotStartInd_CarPos_Y = gUSS_stOut.stLeftSideSlot.SlotStartInd_CarPos_Y;
    }

	if (SlotStartInd_CarPos_X >= 0)
	{
        gSec_015_data.u8_CAN_015_Tx_data[0] = (SlotStartInd_CarPos_X >> 22) & 0x7F;
	}
	else 
	{
        gSec_015_data.u8_CAN_015_Tx_data[0] =(0x01 << 7) + ((SlotStartInd_CarPos_X >> 22) & 0x7F);
	}
    gSec_015_data.u8_CAN_015_Tx_data[1] = SlotStartInd_CarPos_X >> 14;
	gSec_015_data.u8_CAN_015_Tx_data[2] = SlotStartInd_CarPos_X >> 6;

	if (SlotStartInd_CarPos_Y >= 0)
	{
        gSec_015_data.u8_CAN_015_Tx_data[3] = (SlotStartInd_CarPos_X & 0x3F) << 2;
	}
	else 
	{
        gSec_015_data.u8_CAN_015_Tx_data[3] = ((SlotStartInd_CarPos_X & 0x3F) << 2) + 0x01;
	}
    gSec_015_data.u8_CAN_015_Tx_data[4] = SlotStartInd_CarPos_Y >> 21;
	gSec_015_data.u8_CAN_015_Tx_data[5] = SlotStartInd_CarPos_Y >> 13;
	gSec_015_data.u8_CAN_015_Tx_data[6] = SlotStartInd_CarPos_Y >> 5;
	gSec_015_data.u8_CAN_015_Tx_data[7] = ((SlotStartInd_CarPos_Y & 0x1F) << 3) + (USS_Test_Rc_15 & 0x07);
	/**************DBC_USS_ObjPt_15_CarPos****************/

	/**************DBC_USS_ObjPt_16_PtPos****************/
	// USS_Test_Rc_16 ^=0x01;
    USS_Test_Rc_16 = USS_Test_Rc_11;
	// APA_INDEX_TYPE slot_end_index = USSPar.Slot[SendOutLeftOrRight].SlotPar[CurrentSlotNumTem].SlotEndIndex;
	// SlotEndInd_CarPos_X = (sint32)(USSPar.Slot[SendOutLeftOrRight].SlotOutline.Lane.CarCenterPoint[slot_end_index].x);
	// SlotEndInd_CarPos_Y = (sint32)(USSPar.Slot[SendOutLeftOrRight].SlotOutline.Lane.CarCenterPoint[slot_end_index].y);
    if (SendOutLeftOrRight == 0)
    {
        SlotEndInd_CarPos_X = gUSS_stOut.stRightSideSlot.SlotEndInd_CarPos_X;
        SlotEndInd_CarPos_Y = gUSS_stOut.stRightSideSlot.SlotEndInd_CarPos_Y;
    }
    else
    {
        SlotEndInd_CarPos_X = gUSS_stOut.stLeftSideSlot.SlotEndInd_CarPos_X;
        SlotEndInd_CarPos_Y = gUSS_stOut.stLeftSideSlot.SlotEndInd_CarPos_Y;
    }

	if (SlotEndInd_CarPos_X >= 0)
	{
        gSec_016_data.u8_CAN_016_Tx_data[0] = (SlotEndInd_CarPos_X >> 22) & 0x7F;
	}
	else 
	{
        gSec_016_data.u8_CAN_016_Tx_data[0] =(0x01 << 7) + ((SlotEndInd_CarPos_X >> 22) & 0x7F);
	}
    gSec_016_data.u8_CAN_016_Tx_data[1] = SlotEndInd_CarPos_X >> 14;
	gSec_016_data.u8_CAN_016_Tx_data[2] = SlotEndInd_CarPos_X >> 6;

	if (SlotEndInd_CarPos_Y >= 0)
	{
        gSec_016_data.u8_CAN_016_Tx_data[3] = (SlotEndInd_CarPos_X & 0x3F) << 2;
	}
	else 
	{
        gSec_016_data.u8_CAN_016_Tx_data[3] = ((SlotEndInd_CarPos_X & 0x3F) << 2) + 0x01;
	}
    gSec_016_data.u8_CAN_016_Tx_data[4] = SlotEndInd_CarPos_Y >> 21;
	gSec_016_data.u8_CAN_016_Tx_data[5] = SlotEndInd_CarPos_Y >> 13;
	gSec_016_data.u8_CAN_016_Tx_data[6] = SlotEndInd_CarPos_Y >> 5;
	gSec_016_data.u8_CAN_016_Tx_data[7] = ((SlotEndInd_CarPos_Y & 0x1F) << 3) + (USS_Test_Rc_16 & 0x07);
	/**************DBC_USS_ObjPt_16_PtPos****************/

	/**************DBC_USS_ObjPt_17_AngDis****************/
	// USS_Test_Rc_17 ^=0x01;
    USS_Test_Rc_17 = USS_Test_Rc_11;
	// SlotStartInd_PtPos_X = (sint32)(USSPar.Slot[SendOutLeftOrRight].SlotOutline.Lane.ObjPt[slot_start_index].x);
	// SlotStartInd_PtPos_Y = (sint32)(USSPar.Slot[SendOutLeftOrRight].SlotOutline.Lane.ObjPt[slot_start_index].y);
    if (SendOutLeftOrRight == 0)
    {
        SlotStartInd_PtPos_X = gUSS_stOut.stRightSideSlot.SlotStartInd_PtPos_X;
        SlotStartInd_PtPos_Y = gUSS_stOut.stRightSideSlot.SlotStartInd_PtPos_Y;
    }
    else
    {
        SlotStartInd_PtPos_X = gUSS_stOut.stLeftSideSlot.SlotStartInd_PtPos_X;
        SlotStartInd_PtPos_Y = gUSS_stOut.stLeftSideSlot.SlotStartInd_PtPos_Y;
    }

	if (SlotStartInd_PtPos_X >= 0)
	{
        gSec_017_data.u8_CAN_017_Tx_data[0] = (SlotStartInd_PtPos_X >> 22) & 0x7F;
	}
	else 
	{
        gSec_017_data.u8_CAN_017_Tx_data[0] =(0x01 << 7) + ((SlotStartInd_PtPos_X >> 22) & 0x7F);
	}
    gSec_017_data.u8_CAN_017_Tx_data[1] = SlotStartInd_PtPos_X >> 14;
	gSec_017_data.u8_CAN_017_Tx_data[2] = SlotStartInd_PtPos_X >> 6;

	if (SlotStartInd_PtPos_Y >= 0)
	{
        gSec_017_data.u8_CAN_017_Tx_data[3] = (SlotStartInd_PtPos_X & 0x3F) << 2;
	}
	else 
	{
        gSec_017_data.u8_CAN_017_Tx_data[3] = ((SlotStartInd_PtPos_X & 0x3F) << 2) + 0x01;
	}
    gSec_017_data.u8_CAN_017_Tx_data[4] = SlotStartInd_PtPos_Y >> 21;
	gSec_017_data.u8_CAN_017_Tx_data[5] = SlotStartInd_PtPos_Y >> 13;
	gSec_017_data.u8_CAN_017_Tx_data[6] = SlotStartInd_PtPos_Y >> 5;
	gSec_017_data.u8_CAN_017_Tx_data[7] = ((SlotStartInd_PtPos_Y & 0x1F) << 3) + (USS_Test_Rc_17 & 0x07);
	/**************DBC_USS_ObjPt_17_AngDis****************/

	/**************DBC_USS_ObjPt_18_Index****************/
	// USS_Test_Rc_18 ^=0x01;
    USS_Test_Rc_18 = USS_Test_Rc_11;
	// SlotEndInd_PtPos_X = (sint32)(USSPar.Slot[SendOutLeftOrRight].SlotOutline.Lane.ObjPt[slot_end_index].x);
	// SlotEndInd_PtPos_Y = (sint32)(USSPar.Slot[SendOutLeftOrRight].SlotOutline.Lane.ObjPt[slot_end_index].y);
    if (SendOutLeftOrRight == 0)
    {
        SlotEndInd_PtPos_X = gUSS_stOut.stRightSideSlot.SlotEndInd_PtPos_X;
        SlotEndInd_PtPos_Y = gUSS_stOut.stRightSideSlot.SlotEndInd_PtPos_Y;
    }
    else
    {
        SlotEndInd_PtPos_X = gUSS_stOut.stLeftSideSlot.SlotEndInd_PtPos_X;
        SlotEndInd_PtPos_Y = gUSS_stOut.stLeftSideSlot.SlotEndInd_PtPos_Y;
    }

	if (SlotEndInd_PtPos_X >= 0)
	{
        gSec_018_data.u8_CAN_018_Tx_data[0] = (SlotEndInd_PtPos_X >> 22) & 0x7F;
	}
	else 
	{
        gSec_018_data.u8_CAN_018_Tx_data[0] =(0x01 << 7) + ((SlotEndInd_PtPos_X >> 22) & 0x7F);
	}
    gSec_018_data.u8_CAN_018_Tx_data[1] = SlotEndInd_PtPos_X >> 14;
	gSec_018_data.u8_CAN_018_Tx_data[2] = SlotEndInd_PtPos_X >> 6;

	if (SlotEndInd_PtPos_Y >= 0)
	{
        gSec_018_data.u8_CAN_018_Tx_data[3] = (SlotEndInd_PtPos_X & 0x3F) << 2;
	}
	else 
	{
        gSec_018_data.u8_CAN_018_Tx_data[3] = ((SlotEndInd_PtPos_X & 0x3F) << 2) + 0x01;
	}
    gSec_018_data.u8_CAN_018_Tx_data[4] = SlotEndInd_PtPos_Y >> 21;
	gSec_018_data.u8_CAN_018_Tx_data[5] = SlotEndInd_PtPos_Y >> 13;
	gSec_018_data.u8_CAN_018_Tx_data[6] = SlotEndInd_PtPos_Y >> 5;
	gSec_018_data.u8_CAN_018_Tx_data[7] = ((SlotEndInd_PtPos_Y & 0x1F) << 3) + (USS_Test_Rc_18 & 0x07);
	/**************DBC_USS_ObjPt_18_Index****************/

	/**************DBC_USS_Slot_19_GeneralInfo****************/
	// USS_Test_RC_708 ^=0x01;
    USS_Test_RC_708 = USS_Test_Rc_11;
	SlotDir = SendOutLeftOrRight ;
	SlotNum_Right = USSPar.Slot[0].SlotNum;
	SlotNum_Left = USSPar.Slot[1].SlotNum;
    if (SendOutLeftOrRight == 0)
    {
        SlotPar_SlotCalDisCarToObj1 = gUSS_stOut.stRightSideSlot.SlotPar_SlotCalDisCarToObj1;
        SlotPar_SlotCalDisCarToObj2 = gUSS_stOut.stRightSideSlot.SlotPar_SlotCalDisCarToObj2;
        SlotPar_Type = gUSS_stOut.stRightSideSlot.SlotPar_Type;
    }
    else
    {
        SlotPar_SlotCalDisCarToObj1 = gUSS_stOut.stLeftSideSlot.SlotPar_SlotCalDisCarToObj1;
        SlotPar_SlotCalDisCarToObj2 = gUSS_stOut.stLeftSideSlot.SlotPar_SlotCalDisCarToObj2;
        SlotPar_Type = gUSS_stOut.stLeftSideSlot.SlotPar_Type;
    }

    gSec_019_data.u8_CAN_019_Tx_data[0] = ((SlotDir & 0x03)<<4) +((SlotNum_Right & 0x03) << 2) + (SlotNum_Left & 0x03);
	gSec_019_data.u8_CAN_019_Tx_data[1] = SlotPar_SlotCalDisCarToObj1 >> 8;
	gSec_019_data.u8_CAN_019_Tx_data[2] = SlotPar_SlotCalDisCarToObj1 & 0xFF;
	gSec_019_data.u8_CAN_019_Tx_data[3] = SlotPar_SlotCalDisCarToObj2 >> 8;
	gSec_019_data.u8_CAN_019_Tx_data[4] = SlotPar_SlotCalDisCarToObj2 & 0xFF;
	gSec_019_data.u8_CAN_019_Tx_data[5] = SlotPar_Type & 0xFF;
	gSec_019_data.u8_CAN_019_Tx_data[6] = USS_Test_RC_708 & 0x07;
	gSec_019_data.u8_CAN_019_Tx_data[7] = 0x00;
    /**************DBC_USS_Slot_19_GeneralInfo****************/

    /**************DBC_USS_Slot_1A_ObjInfo****************/
    // USS_Test_RC_709 ^=0x01;
    USS_Test_RC_709 = USS_Test_Rc_11;
    // SlotPar_Obj1EndPtIndex = USSPar.Slot[SendOutLeftOrRight].SlotPar[CurrentSlotNumTem].Obj1EndPtIndex; // cm,max 3276.7=3276 12bits
    // SlotPar_Obj1StartPtIndex = USSPar.Slot[SendOutLeftOrRight].SlotPar[CurrentSlotNumTem].Obj1StartPtIndex;
    // SlotPar_Obj1Type = USSPar.Slot[SendOutLeftOrRight].SlotPar[CurrentSlotNumTem].Obj1Type;
    // SlotPar_Obj2Type = USSPar.Slot[SendOutLeftOrRight].SlotPar[CurrentSlotNumTem].Obj2Type;
    // SlotPar_Obj2EndPtIndex = USSPar.Slot[SendOutLeftOrRight].SlotPar[CurrentSlotNumTem].Obj2EndPtIndex;
    // SlotPar_Obj2StartPtIndex = USSPar.Slot[SendOutLeftOrRight].SlotPar[CurrentSlotNumTem].Obj2StartPtIndex;
    // SlotPar_SlotEndIndex = USSPar.Slot[SendOutLeftOrRight].SlotPar[CurrentSlotNumTem].SlotEndIndex;
    // SlotPar_SlotStartIndex = USSPar.Slot[SendOutLeftOrRight].SlotPar[CurrentSlotNumTem].SlotStartIndex;
    if (SendOutLeftOrRight == 0)
    {
        SlotPar_Obj1EndPtIndex = gUSS_stOut.stRightSideSlot.SlotPar_Obj1EndPtIndex;
        SlotPar_Obj1StartPtIndex = gUSS_stOut.stRightSideSlot.SlotPar_Obj1StartPtIndex;
        SlotPar_Obj1Type = gUSS_stOut.stRightSideSlot.SlotPar_Obj1Type;
        SlotPar_Obj2Type = gUSS_stOut.stRightSideSlot.SlotPar_Obj2Type;
        SlotPar_Obj2EndPtIndex = gUSS_stOut.stRightSideSlot.SlotPar_Obj2EndPtIndex;
        SlotPar_Obj2StartPtIndex = gUSS_stOut.stRightSideSlot.SlotPar_Obj2StartPtIndex;
        SlotPar_SlotEndIndex = gUSS_stOut.stRightSideSlot.SlotPar_SlotEndIndex;
        SlotPar_SlotStartIndex = gUSS_stOut.stRightSideSlot.SlotPar_SlotStartIndex;
    }
    else
    {
        SlotPar_Obj1EndPtIndex = gUSS_stOut.stLeftSideSlot.SlotPar_Obj1EndPtIndex;
        SlotPar_Obj1StartPtIndex = gUSS_stOut.stLeftSideSlot.SlotPar_Obj1StartPtIndex;
        SlotPar_Obj1Type = gUSS_stOut.stLeftSideSlot.SlotPar_Obj1Type;
        SlotPar_Obj2Type = gUSS_stOut.stLeftSideSlot.SlotPar_Obj2Type;
        SlotPar_Obj2EndPtIndex = gUSS_stOut.stLeftSideSlot.SlotPar_Obj2EndPtIndex;
        SlotPar_Obj2StartPtIndex = gUSS_stOut.stLeftSideSlot.SlotPar_Obj2StartPtIndex;
        SlotPar_SlotEndIndex = gUSS_stOut.stLeftSideSlot.SlotPar_SlotEndIndex;
        SlotPar_SlotStartIndex = gUSS_stOut.stLeftSideSlot.SlotPar_SlotStartIndex; 
    }

    gSec_01A_data.u8_CAN_01A_Tx_data[0] = SlotPar_Obj1EndPtIndex & 0xFF;
    gSec_01A_data.u8_CAN_01A_Tx_data[1] = SlotPar_Obj1StartPtIndex & 0xFF;
    if (SlotPar_Obj1Type >= 0)
    {
        gSec_01A_data.u8_CAN_01A_Tx_data[2] = ((SlotPar_Obj1Type & 0x1F) << 2) + ((USS_Test_RC_709 >> 1) & 0x03);
    }
    else
    {
        gSec_01A_data.u8_CAN_01A_Tx_data[2] = (0x01 << 7) + ((SlotPar_Obj1Type & 0x1F) << 2) + ((USS_Test_RC_709 >> 1) & 0x03);
    }
    if (SlotPar_Obj2Type >= 0)
    {
        gSec_01A_data.u8_CAN_01A_Tx_data[3] = ((USS_Test_RC_709 & 0x01) << 7) + (SlotPar_Obj2Type & 0x1F);
    }
    else
    {
        gSec_01A_data.u8_CAN_01A_Tx_data[3] = ((USS_Test_RC_709 & 0x01) << 7) + (0x01 << 5) + (SlotPar_Obj2Type & 0x1F);
    }
    gSec_01A_data.u8_CAN_01A_Tx_data[4] = SlotPar_Obj2EndPtIndex & 0xFF;
    gSec_01A_data.u8_CAN_01A_Tx_data[5] = SlotPar_Obj2StartPtIndex & 0xFF;
    gSec_01A_data.u8_CAN_01A_Tx_data[6] = SlotPar_SlotEndIndex & 0xFF;
    gSec_01A_data.u8_CAN_01A_Tx_data[7] = SlotPar_SlotStartIndex & 0xFF;
    /**************DBC_USS_Slot_1A_ObjInfo****************/

	// /**************DBC_USS_Slot_21_Edge0****************/
	// // USS_Test_RC_70A ^=0x01;
    // USS_Test_RC_70A = USS_Test_Rc_11;
    // if(SendOutLeftOrRight == 0)
    // {
    //     SlotPar_Edge0_X = (sint32)(gUSS_stOut.stRightSideSlot.stEdge0Info.gUSS_f32PosX * 1000);
	//     SlotPar_Edge0_Y = (sint32)(gUSS_stOut.stRightSideSlot.stEdge0Info.gUSS_f32PosY * 1000);
    // }else{
    //     SlotPar_Edge0_X = (sint32)(gUSS_stOut.stLeftSideSlot.stEdge0Info.gUSS_f32PosX * 1000);
	//     SlotPar_Edge0_Y = (sint32)(gUSS_stOut.stLeftSideSlot.stEdge0Info.gUSS_f32PosY * 1000);
    // }
	
	// if (SlotPar_Edge0_X >= 0)
	// {
    //     gSec_021_data.u8_CAN_021_Tx_data[0] = (SlotPar_Edge0_X >> 22) & 0x7F;
	// }
	// else 
	// {
    //     gSec_021_data.u8_CAN_021_Tx_data[0] =(0x01 << 7) + ((SlotPar_Edge0_X >> 22) & 0x7F);
	// }
    // gSec_021_data.u8_CAN_021_Tx_data[1] = SlotPar_Edge0_X >> 14;
	// gSec_021_data.u8_CAN_021_Tx_data[2] = SlotPar_Edge0_X >> 6;

	// if (SlotPar_Edge0_Y >= 0)
	// {
    //     gSec_021_data.u8_CAN_021_Tx_data[3] = (SlotPar_Edge0_X & 0x3F) << 2;
	// }
	// else 
	// {
    //     gSec_021_data.u8_CAN_021_Tx_data[3] = ((SlotPar_Edge0_X & 0x3F) << 2) + 0x01;
	// }
    // gSec_021_data.u8_CAN_021_Tx_data[4] = SlotPar_Edge0_Y >> 21;
	// gSec_021_data.u8_CAN_021_Tx_data[5] = SlotPar_Edge0_Y >> 13;
	// gSec_021_data.u8_CAN_021_Tx_data[6] = SlotPar_Edge0_Y >> 5;
	// gSec_021_data.u8_CAN_021_Tx_data[7] = ((SlotPar_Edge0_Y & 0x1F) << 3) + (USS_Test_RC_70A & 0x07);
	// /**************DBC_USS_Slot_21_Edge0****************/

	// /**************DBC_USS_Slot_22_Edge1****************/
	// // USS_Test_RC_70B ^=0x01;
    // USS_Test_RC_70B = USS_Test_Rc_11;
    // if(SendOutLeftOrRight == 0)
    // {
    //     SlotPar_Edge1_X = (sint32)(gUSS_stOut.stRightSideSlot.stEdge1Info.gUSS_f32PosX * 1000);
	//     SlotPar_Edge1_Y = (sint32)(gUSS_stOut.stRightSideSlot.stEdge1Info.gUSS_f32PosY * 1000);

    // }else{
    //     SlotPar_Edge1_X = (sint32)(gUSS_stOut.stLeftSideSlot.stEdge1Info.gUSS_f32PosX * 1000);
	//     SlotPar_Edge1_Y = (sint32)(gUSS_stOut.stLeftSideSlot.stEdge1Info.gUSS_f32PosY * 1000);
    // }
	
	
	// if (SlotPar_Edge1_X >= 0)
	// {
    //     gSec_022_data.u8_CAN_022_Tx_data[0] = (SlotPar_Edge1_X >> 22) & 0x7F;
	// }
	// else 
	// {
    //     gSec_022_data.u8_CAN_022_Tx_data[0] =(0x01 << 7) + ((SlotPar_Edge1_X >> 22) & 0x7F);
	// }
    // gSec_022_data.u8_CAN_022_Tx_data[1] = SlotPar_Edge1_X >> 14;
	// gSec_022_data.u8_CAN_022_Tx_data[2] = SlotPar_Edge1_X >> 6;

    // if (SlotPar_Edge1_Y >= 0)
    // {
    //     gSec_022_data.u8_CAN_022_Tx_data[3] = (SlotPar_Edge1_X & 0x3F) << 2;
    // }
    // else 
    // {
    //     gSec_022_data.u8_CAN_022_Tx_data[3] = ((SlotPar_Edge1_X & 0x3F) << 2) + 0x01;
    // }
    // gSec_022_data.u8_CAN_022_Tx_data[4] = SlotPar_Edge1_Y >> 21;
    // gSec_022_data.u8_CAN_022_Tx_data[5] = SlotPar_Edge1_Y >> 13;
    // gSec_022_data.u8_CAN_022_Tx_data[6] = SlotPar_Edge1_Y >> 5;
    // gSec_022_data.u8_CAN_022_Tx_data[7] = ((SlotPar_Edge1_Y & 0x1F) << 3) + (USS_Test_RC_70B & 0x07);
    // /**************DBC_USS_Slot_22_Edge1****************/

    /**************DBC_USS_Slot_23_SlotInfo****************/
    // USS_Test_RC_70C ^=0x01;
    USS_Test_RC_70C = USS_Test_Rc_11;
    // SlotPar_SlotCompeHead = USSPar.Slot[SendOutLeftOrRight].SlotPar[CurrentSlotNumTem].APASlotDetectionCompensateLengthHead; // cm,max 3276.7=3276 12bits
    // SlotPar_SlotCompeTail = USSPar.Slot[SendOutLeftOrRight].SlotPar[CurrentSlotNumTem].APASlotDetectionCompensateLengthTail;
    // SlotPar_SlotDepth = USSPar.Slot[SendOutLeftOrRight].SlotPar[CurrentSlotNumTem].SlotDepth;
    // SlotPar_SlotLengthTotal = USSPar.Slot[SendOutLeftOrRight].SlotPar[CurrentSlotNumTem].SlotLengthTotal;
    if (SendOutLeftOrRight == 0)
    {
        SlotPar_SlotCompeHead = gUSS_stOut.stRightSideSlot.SlotPar_SlotCompeHead;
        SlotPar_SlotCompeTail = gUSS_stOut.stRightSideSlot.SlotPar_SlotCompeTail;
        SlotPar_SlotDepth = gUSS_stOut.stRightSideSlot.SlotPar_SlotDepth;
        SlotPar_SlotLengthTotal = gUSS_stOut.stRightSideSlot.SlotPar_SlotLengthTotal;
    }
    else
    {
        SlotPar_SlotCompeHead = gUSS_stOut.stLeftSideSlot.SlotPar_SlotCompeHead;
        SlotPar_SlotCompeTail = gUSS_stOut.stLeftSideSlot.SlotPar_SlotCompeTail;
        SlotPar_SlotDepth = gUSS_stOut.stLeftSideSlot.SlotPar_SlotDepth;
        SlotPar_SlotLengthTotal = gUSS_stOut.stLeftSideSlot.SlotPar_SlotLengthTotal;
    }

    if (SlotPar_SlotCompeHead >= 0)
    {
        gSec_023_data.u8_CAN_023_Tx_data[0] = ((USS_Test_RC_70C & 0x07) << 5) + ((SlotPar_SlotCompeHead >> 10) & 0x07);
    }
    else
    {
        gSec_023_data.u8_CAN_023_Tx_data[0] = ((USS_Test_RC_70C & 0x07) << 5) + (0x01 << 3) + ((SlotPar_SlotCompeHead >> 10) & 0x07);
    }
    gSec_023_data.u8_CAN_023_Tx_data[1] = (SlotPar_SlotCompeHead >> 2) & 0xFF;

    if (SlotPar_SlotCompeTail >= 0)
	{
        gSec_023_data.u8_CAN_023_Tx_data[2] = ((SlotPar_SlotCompeHead & 0x03) << 6) + ((SlotPar_SlotCompeTail >> 8) & 0x1F);
	}
	else
	{
        gSec_023_data.u8_CAN_023_Tx_data[2] = ((SlotPar_SlotCompeHead & 0x03) << 6) + (0x01 << 5) + ((SlotPar_SlotCompeTail >> 8) & 0x1F);
	}

    gSec_023_data.u8_CAN_023_Tx_data[3] = SlotPar_SlotCompeTail & 0xFF;
    gSec_023_data.u8_CAN_023_Tx_data[4] = SlotPar_SlotDepth >> 8;
    gSec_023_data.u8_CAN_023_Tx_data[5] = SlotPar_SlotDepth & 0xFF;
    gSec_023_data.u8_CAN_023_Tx_data[6] = SlotPar_SlotLengthTotal >> 8;
    gSec_023_data.u8_CAN_023_Tx_data[7] = SlotPar_SlotLengthTotal & 0xFF;
    /**************DBC_USS_Slot_23_SlotInfo****************/
}

void SendTimeOut(void)
{
    static uint8 USS_Test_RC_70A = 0u;
    sint32 SlotPar_Edge0_X;
    sint32 SlotPar_Edge0_Y;

    static uint8 USS_Test_RC_70B = 0u;
    sint32 SlotPar_Edge1_X;
    sint32 SlotPar_Edge1_Y;

    /**************DBC_USS_Slot_21_Edge0****************/
	// USS_Test_RC_70A ^=0x01;
    USS_Test_RC_70A = USS_Test_Rc_11;
    if(SendOutLeftOrRight == 0)
    {
        SlotPar_Edge0_X = (sint32)(gUSS_stOut.stRightSideSlot.stEdge0Info.gUSS_f32PosX * 1000);
	    SlotPar_Edge0_Y = (sint32)(gUSS_stOut.stRightSideSlot.stEdge0Info.gUSS_f32PosY * 1000);
    }else{
        SlotPar_Edge0_X = (sint32)(gUSS_stOut.stLeftSideSlot.stEdge0Info.gUSS_f32PosX * 1000);
	    SlotPar_Edge0_Y = (sint32)(gUSS_stOut.stLeftSideSlot.stEdge0Info.gUSS_f32PosY * 1000);
    }
	
	if (SlotPar_Edge0_X >= 0)
	{
        gSec_021_data.u8_CAN_021_Tx_data[0] = (SlotPar_Edge0_X >> 22) & 0x7F;
	}
	else 
	{
        gSec_021_data.u8_CAN_021_Tx_data[0] =(0x01 << 7) + ((SlotPar_Edge0_X >> 22) & 0x7F);
	}
    gSec_021_data.u8_CAN_021_Tx_data[1] = SlotPar_Edge0_X >> 14;
	gSec_021_data.u8_CAN_021_Tx_data[2] = SlotPar_Edge0_X >> 6;

	if (SlotPar_Edge0_Y >= 0)
	{
        gSec_021_data.u8_CAN_021_Tx_data[3] = (SlotPar_Edge0_X & 0x3F) << 2;
	}
	else 
	{
        gSec_021_data.u8_CAN_021_Tx_data[3] = ((SlotPar_Edge0_X & 0x3F) << 2) + 0x01;
	}
    gSec_021_data.u8_CAN_021_Tx_data[4] = SlotPar_Edge0_Y >> 21;
	gSec_021_data.u8_CAN_021_Tx_data[5] = SlotPar_Edge0_Y >> 13;
	gSec_021_data.u8_CAN_021_Tx_data[6] = SlotPar_Edge0_Y >> 5;
	gSec_021_data.u8_CAN_021_Tx_data[7] = ((SlotPar_Edge0_Y & 0x1F) << 3) + (USS_Test_RC_70A & 0x07);
	/**************DBC_USS_Slot_21_Edge0****************/

	/**************DBC_USS_Slot_22_Edge1****************/
	// USS_Test_RC_70B ^=0x01;
    USS_Test_RC_70B = USS_Test_Rc_11;
    if(SendOutLeftOrRight == 0)
    {
        SlotPar_Edge1_X = (sint32)(gUSS_stOut.stRightSideSlot.stEdge1Info.gUSS_f32PosX * 1000);
	    SlotPar_Edge1_Y = (sint32)(gUSS_stOut.stRightSideSlot.stEdge1Info.gUSS_f32PosY * 1000);

    }else{
        SlotPar_Edge1_X = (sint32)(gUSS_stOut.stLeftSideSlot.stEdge1Info.gUSS_f32PosX * 1000);
	    SlotPar_Edge1_Y = (sint32)(gUSS_stOut.stLeftSideSlot.stEdge1Info.gUSS_f32PosY * 1000);
    }
	
	
	if (SlotPar_Edge1_X >= 0)
	{
        gSec_022_data.u8_CAN_022_Tx_data[0] = (SlotPar_Edge1_X >> 22) & 0x7F;
	}
	else 
	{
        gSec_022_data.u8_CAN_022_Tx_data[0] =(0x01 << 7) + ((SlotPar_Edge1_X >> 22) & 0x7F);
	}
    gSec_022_data.u8_CAN_022_Tx_data[1] = SlotPar_Edge1_X >> 14;
	gSec_022_data.u8_CAN_022_Tx_data[2] = SlotPar_Edge1_X >> 6;

    if (SlotPar_Edge1_Y >= 0)
    {
        gSec_022_data.u8_CAN_022_Tx_data[3] = (SlotPar_Edge1_X & 0x3F) << 2;
    }
    else 
    {
        gSec_022_data.u8_CAN_022_Tx_data[3] = ((SlotPar_Edge1_X & 0x3F) << 2) + 0x01;
    }
    gSec_022_data.u8_CAN_022_Tx_data[4] = SlotPar_Edge1_Y >> 21;
    gSec_022_data.u8_CAN_022_Tx_data[5] = SlotPar_Edge1_Y >> 13;
    gSec_022_data.u8_CAN_022_Tx_data[6] = SlotPar_Edge1_Y >> 5;
    gSec_022_data.u8_CAN_022_Tx_data[7] = ((SlotPar_Edge1_Y & 0x1F) << 3) + (USS_Test_RC_70B & 0x07);
    /**************DBC_USS_Slot_22_Edge1****************/
}

void SendRealTimeDROut(void)
{
    sint32 CarCenterPt_DR_Coordinate_X;
    sint32 CarCenterPt_DR_Coordinate_y;
    sint32 CarCenterPt_DR_Ang;
    APACoordinateDataCalFloatType CurrentPtInNewCoordinate;

#if SPLITTASK
    if (2 != u8USS_CutSteps)
    {
        return;
    }
#endif
    /*�ҵ����ݵ�task���õ���APACarPar��DR����*/
    CurrentPtInNewCoordinate = APATrajCalPointPosWithAngAndCenterPt(CarCenterPtBackUp.Coordinate, CenterAngBackup3, CenterPtBackup3);
    /**************DBC_USS_FilterIn_28_DR_CoordXY****************/
    /*u8USS_CutSteps:   2           ->3         ->4         ->1
    process:            uss.c save  ->task save ->checkslot ->nothing
    */
    // USS_Test_Rc_70F ^=0x01;
    USS_Test_Rc_70F = USS_Test_Rc_11;
    /*ת��DR����ϵ*/
   CarCenterPt_DR_Coordinate_X = (sint32)CurrentPtInNewCoordinate.y;
   CarCenterPt_DR_Coordinate_y = (sint32)(-CurrentPtInNewCoordinate.x);

    if (CarCenterPt_DR_Coordinate_X >= 0)
    {
        gSec_028_data.u8_CAN_028_Tx_data[0] = (CarCenterPt_DR_Coordinate_X >> 22 & 0x7F);
    }
    else
    {
        gSec_028_data.u8_CAN_028_Tx_data[0] = (0x01 << 7) + (CarCenterPt_DR_Coordinate_X >> 22 & 0x7F);
    }
    gSec_028_data.u8_CAN_028_Tx_data[1] = (CarCenterPt_DR_Coordinate_X >> 14 & 0xFF);
    gSec_028_data.u8_CAN_028_Tx_data[2] = (CarCenterPt_DR_Coordinate_X >> 6 & 0xFF);
    gSec_028_data.u8_CAN_028_Tx_data[3] = ((CarCenterPt_DR_Coordinate_X &  0x3F) << 2);
    if (CarCenterPt_DR_Coordinate_y >= 0)
    {
        gSec_028_data.u8_CAN_028_Tx_data[4] = (CarCenterPt_DR_Coordinate_y >> 22 & 0x7F);
    }
    else
    {
        gSec_028_data.u8_CAN_028_Tx_data[4] = (0x01 << 7) + (CarCenterPt_DR_Coordinate_y >> 22 & 0x7F);
    }
    gSec_028_data.u8_CAN_028_Tx_data[5] = (CarCenterPt_DR_Coordinate_y >> 14 & 0xFF);
    gSec_028_data.u8_CAN_028_Tx_data[6] = (CarCenterPt_DR_Coordinate_y >> 6 & 0xFF);
    gSec_028_data.u8_CAN_028_Tx_data[7] = ((CarCenterPt_DR_Coordinate_y &  0x3F) << 2) + (USS_Test_Rc_70F & 0x03);
    /**************DBC_USS_FilterIn_28_DR_CoordXY****************/

    /**************DBC_USS_FilterIn_29_DR_Ang****************/
    // USS_Test_Rc_710 ^=0x01;
    USS_Test_Rc_710 = USS_Test_Rc_11;
    CarCenterPt_DR_Ang = (sint32)((CarCenterPtBackUp.CarAng+CenterAngBackup3)*180.0/PI*10000);

    if (CarCenterPt_DR_Ang >= 0)
    {
        gSec_029_data.u8_CAN_029_Tx_data[0] = (CarCenterPt_DR_Ang >> 22 & 0x7F);
    }
    else
    {
        gSec_029_data.u8_CAN_029_Tx_data[0] = (0x01 << 7) + (CarCenterPt_DR_Ang >> 22 & 0x7F);
    }
    gSec_029_data.u8_CAN_029_Tx_data[1] = (CarCenterPt_DR_Ang >> 14 & 0xFF);
    gSec_029_data.u8_CAN_029_Tx_data[2] = (CarCenterPt_DR_Ang >> 6 & 0xFF);
    gSec_029_data.u8_CAN_029_Tx_data[3] = ((CarCenterPt_DR_Ang &  0x3F) << 2) + (USS_Test_Rc_710 & 0x03);
    /**************DBC_USS_FilterIn_29_DR_Ang****************/
}
#endif


#define ALG_STOP_SEC_CODE
#include "IS31_UserMemMap.h"
/*************************************************************************************************************************************************
**                                                     End of file                                                                              **
*************************************************************************************************************************************************/






