/*
 * @Author: wsc
 * @Email: wsc0615@163.com
 * @Date: 2020-05-07 16:09:52
 * @LastEditTime: 2020-05-08 14:00:07
 * @LastEditors: wsc
 * @Description:  
 */
#ifndef _STM_H_
#define _STM_H_

// #include "Platform_Types.h"
#include "USD.h" // 为了保证process.c与嵌入式完全相同，挪到这

uint32 Stm_ReadTimerValue(uint8 ModuleNumber,uint8 TimerNumber);

#endif