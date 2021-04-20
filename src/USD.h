#ifndef _USD_H_
#define _USD_H_
#include "Platform_Types.h"

typedef struct 
{
    uint16 gUSD_u16FLCDistMM;
    uint16 gUSD_u16FLMDistMM;
    uint16 gUSD_u16FRMDistMM;
    uint16 gUSD_u16FRCDistMM;
    sint16 gUSD_s16FLCMPosXmm;
    sint16 gUSD_s16FLCMPosYmm;
    sint16 gUSD_s16FLMMPosXmm;
    sint16 gUSD_s16FLMMPosYmm;
    sint16 gUSD_s16FRCMPosXmm;
    sint16 gUSD_s16FRCMPosYmm;
    uint16 gUSD_u16RLCDistMM;
    uint16 gUSD_u16RLMDistMM;
    uint16 gUSD_u16RRMDistMM;
    uint16 gUSD_u16RRCDistMM;
    sint16 gUSD_s16RLCMPosXmm;
    sint16 gUSD_s16RLCMPosYmm;
    sint16 gUSD_s16RLMMPosXmm;
    sint16 gUSD_s16RLMMPosYmm;
    sint16 gUSD_s16RRCMPosXmm;
    sint16 gUSD_s16RRCMPosYmm;

}StructPDCObject;


typedef struct 
{
    uint8 gUSD_SideUpdFlag;
    uint16 gUSD_u16FLSDist1MM;
    uint16 gUSD_u16FRSDist1MM;
    uint16 gUSD_u16RLSDist1MM;
    uint16 gUSD_u16RRSDist1MM;
    uint16 gUSD_u16FLSDist2MM;
    uint16 gUSD_u16FRSDist2MM;
    uint16 gUSD_u16RLSDist2MM;
    uint16 gUSD_u16RRSDist2MM;
    uint16 gUSD_u16FLSEcho1WidthUS;
    uint16 gUSD_u16FRSEcho1WidthUS;
    uint16 gUSD_u16RLSEcho1WidthUS;
    uint16 gUSD_u16RRSEcho1WidthUS;
    uint16 gUSD_u16FLSEcho2WidthUS;
    uint16 gUSD_u16FRSEcho2WidthUS;
    uint16 gUSD_u16RLSEcho2WidthUS;
    uint16 gUSD_u16RRSEcho2WidthUS;
    sint32 gUSD_s32VehPosXmm;
    sint32 gUSD_s32VehPosYmm;
    float gUSD_f32VehYawRad;
    uint16 gUSD_u16VehSpdKPH;


}StructSideObject;


typedef struct 
{
    StructPDCObject gUSD_stPDCObject;
    StructSideObject gUSD_stSideObject;
   
} StructUSDOut;

void USD();

extern StructUSDOut gUSD_stOut;



#endif