/*
 * @Author: wsc
 * @Email: wsc0615@163.com
 * @Date: 2020-04-28 12:33:16
 * @LastEditTime: 2020-09-28 10:30:52
 * @LastEditors: wsc
 * @Description:  
 */
#ifndef _SIF_H_
#define _SIF_H_

#include "Platform_Types.h"
#include "APACommonType.h"
#include "USD.h"
#include "DR.h"

#define SIF_USlotUpdFlag_NO 0
#define SIF_USlotUpdFlag_YES 1
#define SIF_USlotConfirmFlag_YES 1
#define SIF_USlotConfirmFlag_NO 0


#define F_MAX_NUM               5          

#ifndef _EDGEPOINT_ST
#define _EDGEPOINT_ST
typedef struct EdgePoint_Tag{
	Point_ST stPoint;
	uint8 u8VirtualFlg;       
	LineABC_ST stLineABC;  
	uint8 u8LineValidFlg;
    Pose_ST stEgoPose;
}EdgePoint_ST;
#endif

#ifndef _TAGSLOTPOINT_ST
#define _TAGSLOTPOINT_ST
typedef struct TAGSlotPoint_ST{
	Point_ST Point;
	uint8 u8ValidFlg;
}SlotPoint_ST;
#endif

#ifndef _USCURB_ST
#define _USCURB_ST
typedef struct USCurb_Tag{
    LineABC_ST stCurbLine;
	uint8 u8CurbSts; 
}USCurb_ST;
#endif

#ifndef _VIEWCURB_ST
#define _VIEWCURB_ST
typedef struct VSCurb_Tag{
    Point_ST stCurbPoint[2];
	uint8 u8CurbSts; 
}VSCurb_ST;
#endif

#ifndef _VIEWBLOCK_ST
#define _VIEWBLOCK_ST
typedef struct VSBlock_Tag{
    Point_ST stPoint[2];
	uint8 u8ValidFlg; 
}VSBlock_ST;
#endif

#ifndef _FSLOTINFO_ST
#define _FSLOTINFO_ST
typedef struct FslotInfo_Tag{
	uint8 u8VacantFlg;     /*FALSE, if the slot is valid*/ 
	uint8 u8Type;          /*LH Modified uint8 u8Type;*/
    uint8 u8Mode;
    uint8 u8Source;
	uint8 u8DirectCnt;
    uint8 u8Direction;
	uint8 u8OccupidFlg;
	uint8 u8PrePPFlg;
    float32 f32DistRCRearWhlMtrVS;
    float32 f32DistRCRearWhlMtrUS;
	LineABC_ST stDelBorder[2];
	LineABC_ST stCurbLine;
    LineABC_ST stObsBorder[2];
	uint8 u8CurbSts; 
	Point_ST stCenterPtVS;
	uint8 u8InhibitFlg;
    Point_ST stCenterPt;
	EdgePoint_ST stEdge[2];
    SlotPoint_ST stS0;
    SlotPoint_ST stS1;
    SlotPoint_ST stS2;
    SlotPoint_ST stS3;
    USCurb_ST stUSCurb;
    VSCurb_ST stViewCurb[3];
    VSBlock_ST stViewBlockLineSegment[2];
    float32 f32SlotDepthMtr;
    uint8 u8Uid;
    uint8 u8Vid;
    float32 f32Angle; /* vslot angle */
    float32 f32Confidence;
    Pose_ST stSCrdOriginPoseInDRCrd[2];
    Pose_ST stEndPoseSCrd[2];
    uint8 stBlocklinenum;//�Ӿ��������ֵ���״̬�ϲ�
	uint8 stCurblinenum;//�Ӿ�������·�ص�״̬�ϲ�
    //uint8 gPLD_u8STS;
}FslotInfo_ST;
#endif

#ifndef _SLOTPOOL_ST
#define _SLOTPOOL_ST
typedef struct SlotPool_Tag {
    FslotInfo_ST stLSlotList[F_MAX_NUM];
    FslotInfo_ST stRSlotList[F_MAX_NUM];
    uint8 u8LOrderList[F_MAX_NUM];
    uint8 u8ROrderList[F_MAX_NUM];
	uint8 u8LAvblNum;    /*Effective quantity of Left Slot*/
	uint8 u8RAvblNum;	 
}SlotPool_ST;
#endif

#ifndef _GSIF_STOUT_ST
#define _GSIF_STOUT_ST
typedef struct gSIF_stOut_Tag{
	SlotPool_ST gSIF_stSlotPool;
	uint8 gSIF_u8MdlRunSts;
	uint8 gSIF_u8USSEnbl;
    uint8 gSIF_u8PLDEnbl;
	uint8 gSIF_u8UslotConfirmL;
	uint8 gSIF_u8UslotConfirmR;
    uint8 gSIF_u8LckedSlotUpdFlag;
    uint8 gSIF_u8VSSUpdateID;
}gSIF_stOut_ST;
#endif

typedef struct gMMC_stOut_Tag{
	uint8 gMMC_u8MdlRunng;
}gMMC_stOut_ST;

extern gSIF_stOut_ST gSIF_stOut;
extern gMMC_stOut_ST gMMC_stOut;

#endif