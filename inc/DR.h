/*
 * @Author: wsc
 * @Email: wsc0615@163.com
 * @Date: 2020-05-08 16:02:25
 * @LastEditTime: 2020-09-28 10:30:40
 * @LastEditors: wsc
 * @Description:  
 */ 
#ifndef _DR_H_
#define _DR_H_

#include "Platform_Types.h"
#include "APACommonType.h"

#ifndef _gDR_stOut_ST
#define _gDR_stOut_ST
typedef struct gDR_stOut_Tag{
	sint32 gDR_s32VehPosYMM;
	sint32 gDR_s32VehPosXMM;
	float32 gDR_f32VehPosARad;
	uint8 gDR_u8VehDircn;
}gDR_stOut_ST;
#endif

extern gDR_stOut_ST gDR_stOut;

#endif