/*************************************************************************************************************************************************
**                                                                                                                                              **
** Copyright (C) SAIC Technologies (2019)                                                                                                       **
**                                                                                                                                              **
** All rights reserved.                                                                                                                         **
**                                                                                                                                              **
** This document contains proprietary information belonging to SAIC                                                                             **
** Technologies. Passing on and copying of this document, and communication                                                                     **
** of its contents is not permitted without prior written authorization.                                                                        **
**                                                                                                                                              **
**************************************************************************************************************************************************
**                                                                                                                                              **
**  $FILENAME   : IS31_UserMemMap.h $                                                                                                           **
**                                                                                                                                              **
**  $CC VERSION : \main\94 $                                                                                                                    **
**                                                                                                                                              **
**  $DATE       : 2018-04-24 $                                                                                                                  **
**                                                                                                                                              **
**  AUTHOR      : SAIC - W.QC -Engineering                                                                                                      **
**                                                                                                                                              **
**  VENDOR      : SAIC Technologies                                                                                                             **
**                                                                                                                                              **
**  DESCRIPTION : This file contains                                                                                                            **
**                - Ultrasonic bottom data layer processing                 ..                                                                  **
**                                                                                                                                              **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                                                                                        **
**                                                                                                                                              **
*************************************************************************************************************************************************/
/*************************************************************************************************************************************************
**                                                              Module section mapping                                                          **
*************************************************************************************************************************************************/
/*
 * The symbol 'START_WITH_IF' is undefined.
 *
 * Thus, the preprocessor continues searching for defined symbols
 * This first #ifdef makes integration of delivered parts of MemMap.h
 * easier because every supplier starts with #elif
 */
#ifndef IS31_UserMemMap_H_
#define IS31_UserMemMap_H_

/* Mem Vendor ID */
#define MEM_USER_VENDOR_ID         ((uint16)17)

/* MEM SW Major Version */
#define MEM_USER_SW_MAJOR_VERSION  (1U)
/* MEM SW Minor Version */
#define MEM_USER_SW_MINOR_VERSION  (0)
/* MEM SW Patch Version */
#define MEM_USER_SW_PATCH_VERSION  (0)

/* MEM AR Major Version */
#define MEM_USER_AR_MAJOR_VERSION  (1U)
/* MEM AR Minor Version */
#define MEM_USER_AR_MINOR_VERSION  (0)
/* MEM AR Patch Version */
#define MEM_USER_AR_PATCH_VERSION  (13U)

#endif /* IS31_UserMemMap_H_ */

/*
  Identifier clash , upto 60 characters allowed
  MISRA Rule 92 violation : #undef should not be used.
  MemMap works with undefine and redefine principle.
*/
/*lint -idlen(60) -esym(961,92) */

/*lint -esym(960,19.6)   */  /* Allow usage of #undef */
#if defined (START_WITH_IF)

/*************************************************************************************************************************************************
**                                                                      ALG                                                                   **
*************************************************************************************************************************************************/

/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (ALG_START_SEC_CODE)
   #undef      ALG_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (ALG_STOP_SEC_CODE)
   #undef      ALG_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (ALG_START_SEC_VAR_NOINIT_8BIT)
   #undef      ALG_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_CORE0_PRIVATE
#elif defined (ALG_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      ALG_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_CORE0_PRIVATE


#elif defined (ALG_START_SEC_VAR_NOINIT_16BIT)
   #undef      ALG_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_CORE0_PRIVATE
#elif defined (ALG_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      ALG_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_CORE0_PRIVATE


#elif defined (ALG_START_SEC_VAR_NOINIT_32BIT)
   #undef      ALG_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE
#elif defined (ALG_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      ALG_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE


#elif defined (ALG_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      ALG_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE
#elif defined (ALG_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      ALG_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE


#elif defined (ALG_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      ALG_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_CORE0_PRIVATE
#elif defined (ALG_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      ALG_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_CORE0_PRIVATE


#elif defined (ALG_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      ALG_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_CORE0_PRIVATE
#elif defined (ALG_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      ALG_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_CORE0_PRIVATE


#elif defined (ALG_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      ALG_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_CORE0_PRIVATE
#elif defined (ALG_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      ALG_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_CORE0_PRIVATE


#elif defined (ALG_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      ALG_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE0_PRIVATE
#elif defined (ALG_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      ALG_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE0_PRIVATE


#elif defined (ALG_START_SEC_VAR_FAST_8BIT)
   #undef      ALG_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_CORE0_PRIVATE
#elif defined (ALG_STOP_SEC_VAR_FAST_8BIT)
   #undef      ALG_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_CORE0_PRIVATE


#elif defined (ALG_START_SEC_VAR_FAST_16BIT)
   #undef      ALG_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_CORE0_PRIVATE
#elif defined (ALG_STOP_SEC_VAR_FAST_16BIT)
   #undef      ALG_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_CORE0_PRIVATE


#elif defined (ALG_START_SEC_VAR_FAST_32BIT)
   #undef      ALG_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_CORE0_PRIVATE
#elif defined (ALG_STOP_SEC_VAR_FAST_32BIT)
   #undef      ALG_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_CORE0_PRIVATE


#elif defined (ALG_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      ALG_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_CORE0_PRIVATE
#elif defined (ALG_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      ALG_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_CORE0_PRIVATE


#elif defined (ALG_START_SEC_VAR_8BIT)
   #undef      ALG_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_CORE0_PRIVATE
#elif defined (ALG_STOP_SEC_VAR_8BIT)
   #undef      ALG_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_CORE0_PRIVATE


#elif defined (ALG_START_SEC_VAR_16BIT)
   #undef      ALG_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_CORE0_PRIVATE
#elif defined (ALG_STOP_SEC_VAR_16BIT)
   #undef      ALG_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_CORE0_PRIVATE


#elif defined (ALG_START_SEC_VAR_32BIT)
   #undef      ALG_START_SEC_VAR_32BIT
//   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
   #define   DEFAULT_START_SEC_VAR_32BIT_CORE0_PRIVATE
#elif defined (ALG_STOP_SEC_VAR_32BIT)
   #undef      ALG_STOP_SEC_VAR_32BIT
//   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED
   #define   DEFAULT_STOP_SEC_VAR_32BIT_CORE0_PRIVATE


#elif defined (ALG_START_SEC_VAR_UNSPECIFIED)
   #undef      ALG_START_SEC_VAR_UNSPECIFIED
//   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_CORE0_PRIVATE
#elif defined (ALG_STOP_SEC_VAR_UNSPECIFIED)
   #undef      ALG_STOP_SEC_VAR_UNSPECIFIED
//   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED
  #define   DEFAULT_STOP_SEC_VAR_UNSPECIFIED_CORE0_PRIVATE


#elif defined (ALG_START_SEC_CONST_8BIT)
   #undef      ALG_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_CORE0_PRIVATE
#elif defined (ALG_STOP_SEC_CONST_8BIT)
   #undef      ALG_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_CORE0_PRIVATE


#elif defined (ALG_START_SEC_CONST_16BIT)
   #undef      ALG_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_CORE0_PRIVATE
#elif defined (ALG_STOP_SEC_CONST_16BIT)
   #undef      ALG_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_CORE0_PRIVATE


#elif defined (ALG_START_SEC_CONST_32BIT)
   #undef      ALG_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_CORE0_PRIVATE
#elif defined (ALG_STOP_SEC_CONST_32BIT)
   #undef      ALG_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_CORE0_PRIVATE


#elif defined (ALG_START_SEC_CONST_UNSPECIFIED)
   #undef      ALG_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_CORE0_PRIVATE
#elif defined (ALG_STOP_SEC_CONST_UNSPECIFIED)
   #undef      ALG_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_CORE0_PRIVATE


#elif defined (ALG_START_SEC_ASIL0_CONST_8BIT)
   #undef      ALG_START_SEC_ASIL0_CONST_8BIT
   #define   DEFAULT_START_SEC_ASIL0_CONST_8BIT_CORE0_PRIVATE
#elif defined (ALG_STOP_SEC_ASIL0_CONST_8BIT)
   #undef      ALG_STOP_SEC_ASIL0_CONST_8BIT
   #define DEFAULT_STOP_SEC_ASIL0_CONST_8BIT_CORE0_PRIVATE


#elif defined (ALG_START_SEC_ASIL1_CONST_8BIT)
   #undef      ALG_START_SEC_ASIL1_CONST_8BIT
   #define   DEFAULT_START_SEC_ASIL1_CONST_8BIT_CORE0_PRIVATE
#elif defined (ALG_STOP_SEC_ASIL1_CONST_8BIT)
   #undef      ALG_STOP_SEC_ASIL1_CONST_8BIT
   #define DEFAULT_STOP_SEC_ASIL1_CONST_8BIT_CORE0_PRIVATE


#elif defined (ALG_START_SEC_ASIL0_VAR_UNSPECIFIED)
   #undef      ALG_START_SEC_ASIL0_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_ASIL0_VAR_UNSPECIFIED_CORE0_PRIVATE
#elif defined (ALG_STOP_SEC_ASIL0_VAR_UNSPECIFIED)
   #undef      ALG_STOP_SEC_ASIL0_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_ASIL0_VAR_UNSPECIFIED_CORE0_PRIVATE


#elif defined (ALG_START_SEC_ASIL1_VAR_UNSPECIFIED)
   #undef      ALG_START_SEC_ASIL1_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_ASIL1_VAR_UNSPECIFIED_CORE0_PRIVATE
#elif defined (ALG_STOP_SEC_ASIL1_VAR_UNSPECIFIED)
   #undef      ALG_STOP_SEC_ASIL1_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_ASIL1_VAR_UNSPECIFIED_CORE0_PRIVATE


#elif defined (ALG_START_SEC_POSTBUILDCFG)
   #undef      ALG_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_CORE0_PRIVATE
#elif defined (ALG_STOP_SEC_POSTBUILDCFG)
   #undef      ALG_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_CORE0_PRIVATE


/*************************************************************************************************************************************************
**                                                                      DR                                                                   **
*************************************************************************************************************************************************/

/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (DR_START_SEC_CODE)
   #undef      DR_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (DR_STOP_SEC_CODE)
   #undef      DR_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (DR_START_SEC_VAR_NOINIT_8BIT)
   #undef      DR_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_CORE0_PRIVATE
#elif defined (DR_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      DR_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_CORE0_PRIVATE


#elif defined (DR_START_SEC_VAR_NOINIT_16BIT)
   #undef      DR_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_CORE0_PRIVATE
#elif defined (DR_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      DR_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_CORE0_PRIVATE


#elif defined (DR_START_SEC_VAR_NOINIT_32BIT)
   #undef      DR_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE
#elif defined (DR_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      DR_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE


#elif defined (DR_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      DR_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE
#elif defined (DR_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      DR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE


#elif defined (DR_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      DR_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_CORE0_PRIVATE
#elif defined (DR_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      DR_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_CORE0_PRIVATE


#elif defined (DR_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      DR_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_CORE0_PRIVATE
#elif defined (DR_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      DR_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_CORE0_PRIVATE


#elif defined (DR_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      DR_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_CORE0_PRIVATE
#elif defined (DR_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      DR_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_CORE0_PRIVATE


#elif defined (DR_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      DR_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE0_PRIVATE
#elif defined (DR_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      DR_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE0_PRIVATE


#elif defined (DR_START_SEC_VAR_FAST_8BIT)
   #undef      DR_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_CORE0_PRIVATE
#elif defined (DR_STOP_SEC_VAR_FAST_8BIT)
   #undef      DR_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_CORE0_PRIVATE


#elif defined (DR_START_SEC_VAR_FAST_16BIT)
   #undef      DR_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_CORE0_PRIVATE
#elif defined (DR_STOP_SEC_VAR_FAST_16BIT)
   #undef      DR_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_CORE0_PRIVATE


#elif defined (DR_START_SEC_VAR_FAST_32BIT)
   #undef      DR_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_CORE0_PRIVATE
#elif defined (DR_STOP_SEC_VAR_FAST_32BIT)
   #undef      DR_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_CORE0_PRIVATE


#elif defined (DR_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      DR_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_CORE0_PRIVATE
#elif defined (DR_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      DR_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_CORE0_PRIVATE


#elif defined (DR_START_SEC_VAR_8BIT)
   #undef      DR_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_CORE0_PRIVATE
#elif defined (DR_STOP_SEC_VAR_8BIT)
   #undef      DR_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_CORE0_PRIVATE


#elif defined (DR_START_SEC_VAR_16BIT)
   #undef      DR_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_CORE0_PRIVATE
#elif defined (DR_STOP_SEC_VAR_16BIT)
   #undef      DR_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_CORE0_PRIVATE


#elif defined (DR_START_SEC_VAR_32BIT)
   #undef      DR_START_SEC_VAR_32BIT
//   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
   #define   DEFAULT_START_SEC_VAR_32BIT_CORE0_PRIVATE
#elif defined (DR_STOP_SEC_VAR_32BIT)
   #undef      DR_STOP_SEC_VAR_32BIT
//   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED
   #define   DEFAULT_STOP_SEC_VAR_32BIT_CORE0_PRIVATE


#elif defined (DR_START_SEC_VAR_UNSPECIFIED)
   #undef      DR_START_SEC_VAR_UNSPECIFIED
//   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_CORE0_PRIVATE
#elif defined (DR_STOP_SEC_VAR_UNSPECIFIED)
   #undef      DR_STOP_SEC_VAR_UNSPECIFIED
//   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED
  #define   DEFAULT_STOP_SEC_VAR_UNSPECIFIED_CORE0_PRIVATE


#elif defined (DR_START_SEC_CONST_8BIT)
   #undef      DR_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_CORE0_PRIVATE
#elif defined (DR_STOP_SEC_CONST_8BIT)
   #undef      DR_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_CORE0_PRIVATE


#elif defined (DR_START_SEC_CONST_16BIT)
   #undef      DR_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_CORE0_PRIVATE
#elif defined (DR_STOP_SEC_CONST_16BIT)
   #undef      DR_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_CORE0_PRIVATE


#elif defined (DR_START_SEC_CONST_32BIT)
   #undef      DR_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_CORE0_PRIVATE
#elif defined (DR_STOP_SEC_CONST_32BIT)
   #undef      DR_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_CORE0_PRIVATE


#elif defined (DR_START_SEC_CONST_UNSPECIFIED)
   #undef      DR_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_CORE0_PRIVATE
#elif defined (DR_STOP_SEC_CONST_UNSPECIFIED)
   #undef      DR_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_CORE0_PRIVATE


#elif defined (DR_START_SEC_ASIL0_CONST_8BIT)
   #undef      DR_START_SEC_ASIL0_CONST_8BIT
   #define   DEFAULT_START_SEC_ASIL0_CONST_8BIT_CORE0_PRIVATE
#elif defined (DR_STOP_SEC_ASIL0_CONST_8BIT)
   #undef      DR_STOP_SEC_ASIL0_CONST_8BIT
   #define DEFAULT_STOP_SEC_ASIL0_CONST_8BIT_CORE0_PRIVATE


#elif defined (DR_START_SEC_ASIL1_CONST_8BIT)
   #undef      DR_START_SEC_ASIL1_CONST_8BIT
   #define   DEFAULT_START_SEC_ASIL1_CONST_8BIT_CORE0_PRIVATE
#elif defined (DR_STOP_SEC_ASIL1_CONST_8BIT)
   #undef      DR_STOP_SEC_ASIL1_CONST_8BIT
   #define DEFAULT_STOP_SEC_ASIL1_CONST_8BIT_CORE0_PRIVATE


#elif defined (DR_START_SEC_ASIL0_VAR_UNSPECIFIED)
   #undef      DR_START_SEC_ASIL0_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_ASIL0_VAR_UNSPECIFIED_CORE0_PRIVATE
#elif defined (DR_STOP_SEC_ASIL0_VAR_UNSPECIFIED)
   #undef      DR_STOP_SEC_ASIL0_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_ASIL0_VAR_UNSPECIFIED_CORE0_PRIVATE


#elif defined (DR_START_SEC_ASIL1_VAR_UNSPECIFIED)
   #undef      DR_START_SEC_ASIL1_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_ASIL1_VAR_UNSPECIFIED_CORE0_PRIVATE
#elif defined (DR_STOP_SEC_ASIL1_VAR_UNSPECIFIED)
   #undef      DR_STOP_SEC_ASIL1_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_ASIL1_VAR_UNSPECIFIED_CORE0_PRIVATE


#elif defined (DR_START_SEC_POSTBUILDCFG)
   #undef      DR_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_CORE0_PRIVATE
#elif defined (DR_STOP_SEC_POSTBUILDCFG)
   #undef      DR_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_CORE0_PRIVATE

/*************************************************************************************************************************************************
**                                                                      FunctionLogic                                                                   **
*************************************************************************************************************************************************/

/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (FUNCLOGIC_START_SEC_CODE)
   #undef      FUNCLOGIC_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (FUNCLOGIC_STOP_SEC_CODE)
   #undef      FUNCLOGIC_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (FUNCLOGIC_START_SEC_VAR_NOINIT_8BIT)
   #undef      FUNCLOGIC_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_CORE0_PRIVATE
#elif defined (FUNCLOGIC_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      FUNCLOGIC_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_CORE0_PRIVATE


#elif defined (FUNCLOGIC_START_SEC_VAR_NOINIT_16BIT)
   #undef      FUNCLOGIC_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_CORE0_PRIVATE
#elif defined (FUNCLOGIC_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      FUNCLOGIC_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_CORE0_PRIVATE


#elif defined (FUNCLOGIC_START_SEC_VAR_NOINIT_32BIT)
   #undef      FUNCLOGIC_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE
#elif defined (FUNCLOGIC_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      FUNCLOGIC_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE


#elif defined (FUNCLOGIC_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      FUNCLOGIC_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE
#elif defined (FUNCLOGIC_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      FUNCLOGIC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE


#elif defined (FUNCLOGIC_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      FUNCLOGIC_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_CORE0_PRIVATE
#elif defined (FUNCLOGIC_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      FUNCLOGIC_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_CORE0_PRIVATE


#elif defined (FUNCLOGIC_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      FUNCLOGIC_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_CORE0_PRIVATE
#elif defined (FUNCLOGIC_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      FUNCLOGIC_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_CORE0_PRIVATE


#elif defined (FUNCLOGIC_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      FUNCLOGIC_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_CORE0_PRIVATE
#elif defined (FUNCLOGIC_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      FUNCLOGIC_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_CORE0_PRIVATE


#elif defined (FUNCLOGIC_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      FUNCLOGIC_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE0_PRIVATE
#elif defined (FUNCLOGIC_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      FUNCLOGIC_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE0_PRIVATE


#elif defined (FUNCLOGIC_START_SEC_VAR_FAST_8BIT)
   #undef      FUNCLOGIC_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_CORE0_PRIVATE
#elif defined (FUNCLOGIC_STOP_SEC_VAR_FAST_8BIT)
   #undef      FUNCLOGIC_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_CORE0_PRIVATE


#elif defined (FUNCLOGIC_START_SEC_VAR_FAST_16BIT)
   #undef      FUNCLOGIC_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_CORE0_PRIVATE
#elif defined (FUNCLOGIC_STOP_SEC_VAR_FAST_16BIT)
   #undef      FUNCLOGIC_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_CORE0_PRIVATE


#elif defined (FUNCLOGIC_START_SEC_VAR_FAST_32BIT)
   #undef      FUNCLOGIC_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_CORE0_PRIVATE
#elif defined (FUNCLOGIC_STOP_SEC_VAR_FAST_32BIT)
   #undef      FUNCLOGIC_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_CORE0_PRIVATE


#elif defined (FUNCLOGIC_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      FUNCLOGIC_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_CORE0_PRIVATE
#elif defined (FUNCLOGIC_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      FUNCLOGIC_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_CORE0_PRIVATE


#elif defined (FUNCLOGIC_START_SEC_VAR_8BIT)
   #undef      FUNCLOGIC_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_CORE0_PRIVATE
#elif defined (FUNCLOGIC_STOP_SEC_VAR_8BIT)
   #undef      FUNCLOGIC_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_CORE0_PRIVATE


#elif defined (FUNCLOGIC_START_SEC_VAR_16BIT)
   #undef      FUNCLOGIC_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_CORE0_PRIVATE
#elif defined (FUNCLOGIC_STOP_SEC_VAR_16BIT)
   #undef      FUNCLOGIC_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_CORE0_PRIVATE


#elif defined (FUNCLOGIC_START_SEC_VAR_32BIT)
   #undef      FUNCLOGIC_START_SEC_VAR_32BIT
//   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
   #define   DEFAULT_START_SEC_VAR_32BIT_CORE0_PRIVATE
#elif defined (FUNCLOGIC_STOP_SEC_VAR_32BIT)
   #undef      FUNCLOGIC_STOP_SEC_VAR_32BIT
//   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED
   #define   DEFAULT_STOP_SEC_VAR_32BIT_CORE0_PRIVATE


#elif defined (FUNCLOGIC_START_SEC_VAR_UNSPECIFIED)
   #undef      FUNCLOGIC_START_SEC_VAR_UNSPECIFIED
//   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_CORE0_PRIVATE
#elif defined (FUNCLOGIC_STOP_SEC_VAR_UNSPECIFIED)
   #undef      FUNCLOGIC_STOP_SEC_VAR_UNSPECIFIED
//   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED
  #define   DEFAULT_STOP_SEC_VAR_UNSPECIFIED_CORE0_PRIVATE


#elif defined (FUNCLOGIC_START_SEC_CONST_8BIT)
   #undef      FUNCLOGIC_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_CORE0_PRIVATE
#elif defined (FUNCLOGIC_STOP_SEC_CONST_8BIT)
   #undef      FUNCLOGIC_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_CORE0_PRIVATE


#elif defined (FUNCLOGIC_START_SEC_CONST_16BIT)
   #undef      FUNCLOGIC_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_CORE0_PRIVATE
#elif defined (FUNCLOGIC_STOP_SEC_CONST_16BIT)
   #undef      FUNCLOGIC_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_CORE0_PRIVATE


#elif defined (FUNCLOGIC_START_SEC_CONST_32BIT)
   #undef      FUNCLOGIC_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_CORE0_PRIVATE
#elif defined (FUNCLOGIC_STOP_SEC_CONST_32BIT)
   #undef      FUNCLOGIC_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_CORE0_PRIVATE


#elif defined (FUNCLOGIC_START_SEC_CONST_UNSPECIFIED)
   #undef      FUNCLOGIC_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_CORE0_PRIVATE
#elif defined (FUNCLOGIC_STOP_SEC_CONST_UNSPECIFIED)
   #undef      FUNCLOGIC_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_CORE0_PRIVATE


#elif defined (FUNCLOGIC_START_SEC_ASIL0_CONST_8BIT)
   #undef      FUNCLOGIC_START_SEC_ASIL0_CONST_8BIT
   #define   DEFAULT_START_SEC_ASIL0_CONST_8BIT_CORE0_PRIVATE
#elif defined (FUNCLOGIC_STOP_SEC_ASIL0_CONST_8BIT)
   #undef      FUNCLOGIC_STOP_SEC_ASIL0_CONST_8BIT
   #define DEFAULT_STOP_SEC_ASIL0_CONST_8BIT_CORE0_PRIVATE


#elif defined (FUNCLOGIC_START_SEC_ASIL1_CONST_8BIT)
   #undef      FUNCLOGIC_START_SEC_ASIL1_CONST_8BIT
   #define   DEFAULT_START_SEC_ASIL1_CONST_8BIT_CORE0_PRIVATE
#elif defined (FUNCLOGIC_STOP_SEC_ASIL1_CONST_8BIT)
   #undef      FUNCLOGIC_STOP_SEC_ASIL1_CONST_8BIT
   #define DEFAULT_STOP_SEC_ASIL1_CONST_8BIT_CORE0_PRIVATE


#elif defined (FUNCLOGIC_START_SEC_ASIL0_VAR_UNSPECIFIED)
   #undef      FUNCLOGIC_START_SEC_ASIL0_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_ASIL0_VAR_UNSPECIFIED_CORE0_PRIVATE
#elif defined (FUNCLOGIC_STOP_SEC_ASIL0_VAR_UNSPECIFIED)
   #undef      FUNCLOGIC_STOP_SEC_ASIL0_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_ASIL0_VAR_UNSPECIFIED_CORE0_PRIVATE


#elif defined (FUNCLOGIC_START_SEC_ASIL1_VAR_UNSPECIFIED)
   #undef      FUNCLOGIC_START_SEC_ASIL1_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_ASIL1_VAR_UNSPECIFIED_CORE0_PRIVATE
#elif defined (FUNCLOGIC_STOP_SEC_ASIL1_VAR_UNSPECIFIED)
   #undef      FUNCLOGIC_STOP_SEC_ASIL1_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_ASIL1_VAR_UNSPECIFIED_CORE0_PRIVATE


#elif defined (FUNCLOGIC_START_SEC_POSTBUILDCFG)
   #undef      FUNCLOGIC_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_CORE0_PRIVATE
#elif defined (FUNCLOGIC_STOP_SEC_POSTBUILDCFG)
   #undef      FUNCLOGIC_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_CORE0_PRIVATE

/*************************************************************************************************************************************************
**                                                                      SPIS                                                                   **
*************************************************************************************************************************************************/

/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (SPIS_START_SEC_CODE)
   #undef      SPIS_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (SPIS_STOP_SEC_CODE)
   #undef      SPIS_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (SPIS_START_SEC_VAR_NOINIT_8BIT)
   #undef      SPIS_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_CORE0_PRIVATE
#elif defined (SPIS_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      SPIS_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_CORE0_PRIVATE


#elif defined (SPIS_START_SEC_VAR_NOINIT_16BIT)
   #undef      SPIS_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_CORE0_PRIVATE
#elif defined (SPIS_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      SPIS_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_CORE0_PRIVATE


#elif defined (SPIS_START_SEC_VAR_NOINIT_32BIT)
   #undef      SPIS_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE
#elif defined (SPIS_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      SPIS_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE


#elif defined (SPIS_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      SPIS_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE
#elif defined (SPIS_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      SPIS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE


#elif defined (SPIS_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      SPIS_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_CORE0_PRIVATE
#elif defined (SPIS_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      SPIS_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_CORE0_PRIVATE


#elif defined (SPIS_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      SPIS_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_CORE0_PRIVATE
#elif defined (SPIS_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      SPIS_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_CORE0_PRIVATE


#elif defined (SPIS_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      SPIS_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_CORE0_PRIVATE
#elif defined (SPIS_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      SPIS_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_CORE0_PRIVATE


#elif defined (SPIS_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      SPIS_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE0_PRIVATE
#elif defined (SPIS_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      SPIS_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE0_PRIVATE


#elif defined (SPIS_START_SEC_VAR_FAST_8BIT)
   #undef      SPIS_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_CORE0_PRIVATE
#elif defined (SPIS_STOP_SEC_VAR_FAST_8BIT)
   #undef      SPIS_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_CORE0_PRIVATE


#elif defined (SPIS_START_SEC_VAR_FAST_16BIT)
   #undef      SPIS_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_CORE0_PRIVATE
#elif defined (SPIS_STOP_SEC_VAR_FAST_16BIT)
   #undef      SPIS_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_CORE0_PRIVATE


#elif defined (SPIS_START_SEC_VAR_FAST_32BIT)
   #undef      SPIS_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_CORE0_PRIVATE
#elif defined (SPIS_STOP_SEC_VAR_FAST_32BIT)
   #undef      SPIS_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_CORE0_PRIVATE


#elif defined (SPIS_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      SPIS_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_CORE0_PRIVATE
#elif defined (SPIS_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      SPIS_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_CORE0_PRIVATE


#elif defined (SPIS_START_SEC_VAR_8BIT)
   #undef      SPIS_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_CORE0_PRIVATE
#elif defined (SPIS_STOP_SEC_VAR_8BIT)
   #undef      SPIS_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_CORE0_PRIVATE


#elif defined (SPIS_START_SEC_VAR_16BIT)
   #undef      SPIS_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_CORE0_PRIVATE
#elif defined (SPIS_STOP_SEC_VAR_16BIT)
   #undef      SPIS_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_CORE0_PRIVATE


#elif defined (SPIS_START_SEC_VAR_32BIT)
   #undef      SPIS_START_SEC_VAR_32BIT
//   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
   #define   DEFAULT_START_SEC_VAR_32BIT_CORE0_PRIVATE
#elif defined (SPIS_STOP_SEC_VAR_32BIT)
   #undef      SPIS_STOP_SEC_VAR_32BIT
//   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED
   #define   DEFAULT_STOP_SEC_VAR_32BIT_CORE0_PRIVATE


#elif defined (SPIS_START_SEC_VAR_UNSPECIFIED)
   #undef      SPIS_START_SEC_VAR_UNSPECIFIED
//   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_CORE0_PRIVATE
#elif defined (SPIS_STOP_SEC_VAR_UNSPECIFIED)
   #undef      SPIS_STOP_SEC_VAR_UNSPECIFIED
//   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED
  #define   DEFAULT_STOP_SEC_VAR_UNSPECIFIED_CORE0_PRIVATE


#elif defined (SPIS_START_SEC_CONST_8BIT)
   #undef      SPIS_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_CORE0_PRIVATE
#elif defined (SPIS_STOP_SEC_CONST_8BIT)
   #undef      SPIS_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_CORE0_PRIVATE


#elif defined (SPIS_START_SEC_CONST_16BIT)
   #undef      SPIS_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_CORE0_PRIVATE
#elif defined (SPIS_STOP_SEC_CONST_16BIT)
   #undef      SPIS_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_CORE0_PRIVATE


#elif defined (SPIS_START_SEC_CONST_32BIT)
   #undef      SPIS_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_CORE0_PRIVATE
#elif defined (SPIS_STOP_SEC_CONST_32BIT)
   #undef      SPIS_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_CORE0_PRIVATE


#elif defined (SPIS_START_SEC_CONST_UNSPECIFIED)
   #undef      SPIS_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_CORE0_PRIVATE
#elif defined (SPIS_STOP_SEC_CONST_UNSPECIFIED)
   #undef      SPIS_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_CORE0_PRIVATE


#elif defined (SPIS_START_SEC_ASIL0_CONST_8BIT)
   #undef      SPIS_START_SEC_ASIL0_CONST_8BIT
   #define   DEFAULT_START_SEC_ASIL0_CONST_8BIT_CORE0_PRIVATE
#elif defined (SPIS_STOP_SEC_ASIL0_CONST_8BIT)
   #undef      SPIS_STOP_SEC_ASIL0_CONST_8BIT
   #define DEFAULT_STOP_SEC_ASIL0_CONST_8BIT_CORE0_PRIVATE


#elif defined (SPIS_START_SEC_ASIL1_CONST_8BIT)
   #undef      SPIS_START_SEC_ASIL1_CONST_8BIT
   #define   DEFAULT_START_SEC_ASIL1_CONST_8BIT_CORE0_PRIVATE
#elif defined (SPIS_STOP_SEC_ASIL1_CONST_8BIT)
   #undef      SPIS_STOP_SEC_ASIL1_CONST_8BIT
   #define DEFAULT_STOP_SEC_ASIL1_CONST_8BIT_CORE0_PRIVATE


#elif defined (SPIS_START_SEC_ASIL0_VAR_UNSPECIFIED)
   #undef      SPIS_START_SEC_ASIL0_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_ASIL0_VAR_UNSPECIFIED_CORE0_PRIVATE
#elif defined (SPIS_STOP_SEC_ASIL0_VAR_UNSPECIFIED)
   #undef      SPIS_STOP_SEC_ASIL0_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_ASIL0_VAR_UNSPECIFIED_CORE0_PRIVATE


#elif defined (SPIS_START_SEC_ASIL1_VAR_UNSPECIFIED)
   #undef      SPIS_START_SEC_ASIL1_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_ASIL1_VAR_UNSPECIFIED_CORE0_PRIVATE
#elif defined (SPIS_STOP_SEC_ASIL1_VAR_UNSPECIFIED)
   #undef      SPIS_STOP_SEC_ASIL1_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_ASIL1_VAR_UNSPECIFIED_CORE0_PRIVATE


#elif defined (SPIS_START_SEC_POSTBUILDCFG)
   #undef      SPIS_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_CORE0_PRIVATE
#elif defined (SPIS_STOP_SEC_POSTBUILDCFG)
   #undef      SPIS_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_CORE0_PRIVATE

/*************************************************************************************************************************************************
**                                                                      UARTS                                                                   **
*************************************************************************************************************************************************/

/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (UARTS_START_SEC_CODE)
   #undef      UARTS_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (UARTS_STOP_SEC_CODE)
   #undef      UARTS_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (UARTS_START_SEC_VAR_NOINIT_8BIT)
   #undef      UARTS_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_CORE0_PRIVATE
#elif defined (UARTS_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      UARTS_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_CORE0_PRIVATE


#elif defined (UARTS_START_SEC_VAR_NOINIT_16BIT)
   #undef      UARTS_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_CORE0_PRIVATE
#elif defined (UARTS_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      UARTS_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_CORE0_PRIVATE


#elif defined (UARTS_START_SEC_VAR_NOINIT_32BIT)
   #undef      UARTS_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE
#elif defined (UARTS_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      UARTS_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE


#elif defined (UARTS_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      UARTS_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE
#elif defined (UARTS_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      UARTS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE


#elif defined (UARTS_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      UARTS_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_CORE0_PRIVATE
#elif defined (UARTS_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      UARTS_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_CORE0_PRIVATE


#elif defined (UARTS_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      UARTS_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_CORE0_PRIVATE
#elif defined (UARTS_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      UARTS_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_CORE0_PRIVATE


#elif defined (UARTS_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      UARTS_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_CORE0_PRIVATE
#elif defined (UARTS_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      UARTS_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_CORE0_PRIVATE


#elif defined (UARTS_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      UARTS_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE0_PRIVATE
#elif defined (UARTS_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      UARTS_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE0_PRIVATE


#elif defined (UARTS_START_SEC_VAR_FAST_8BIT)
   #undef      UARTS_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_CORE0_PRIVATE
#elif defined (UARTS_STOP_SEC_VAR_FAST_8BIT)
   #undef      UARTS_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_CORE0_PRIVATE


#elif defined (UARTS_START_SEC_VAR_FAST_16BIT)
   #undef      UARTS_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_CORE0_PRIVATE
#elif defined (UARTS_STOP_SEC_VAR_FAST_16BIT)
   #undef      UARTS_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_CORE0_PRIVATE


#elif defined (UARTS_START_SEC_VAR_FAST_32BIT)
   #undef      UARTS_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_CORE0_PRIVATE
#elif defined (UARTS_STOP_SEC_VAR_FAST_32BIT)
   #undef      UARTS_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_CORE0_PRIVATE


#elif defined (UARTS_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      UARTS_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_CORE0_PRIVATE
#elif defined (UARTS_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      UARTS_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_CORE0_PRIVATE


#elif defined (UARTS_START_SEC_VAR_8BIT)
   #undef      UARTS_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_CORE0_PRIVATE
#elif defined (UARTS_STOP_SEC_VAR_8BIT)
   #undef      UARTS_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_CORE0_PRIVATE


#elif defined (UARTS_START_SEC_VAR_16BIT)
   #undef      UARTS_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_CORE0_PRIVATE
#elif defined (UARTS_STOP_SEC_VAR_16BIT)
   #undef      UARTS_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_CORE0_PRIVATE


#elif defined (UARTS_START_SEC_VAR_32BIT)
   #undef      UARTS_START_SEC_VAR_32BIT
//   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
   #define   DEFAULT_START_SEC_VAR_32BIT_CORE0_PRIVATE
#elif defined (UARTS_STOP_SEC_VAR_32BIT)
   #undef      UARTS_STOP_SEC_VAR_32BIT
//   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED
   #define   DEFAULT_STOP_SEC_VAR_32BIT_CORE0_PRIVATE


#elif defined (UARTS_START_SEC_VAR_UNSPECIFIED)
   #undef      UARTS_START_SEC_VAR_UNSPECIFIED
//   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_CORE0_PRIVATE
#elif defined (UARTS_STOP_SEC_VAR_UNSPECIFIED)
   #undef      UARTS_STOP_SEC_VAR_UNSPECIFIED
//   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED
  #define   DEFAULT_STOP_SEC_VAR_UNSPECIFIED_CORE0_PRIVATE


#elif defined (UARTS_START_SEC_CONST_8BIT)
   #undef      UARTS_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_CORE0_PRIVATE
#elif defined (UARTS_STOP_SEC_CONST_8BIT)
   #undef      UARTS_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_CORE0_PRIVATE


#elif defined (UARTS_START_SEC_CONST_16BIT)
   #undef      UARTS_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_CORE0_PRIVATE
#elif defined (UARTS_STOP_SEC_CONST_16BIT)
   #undef      UARTS_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_CORE0_PRIVATE


#elif defined (UARTS_START_SEC_CONST_32BIT)
   #undef      UARTS_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_CORE0_PRIVATE
#elif defined (UARTS_STOP_SEC_CONST_32BIT)
   #undef      UARTS_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_CORE0_PRIVATE


#elif defined (UARTS_START_SEC_CONST_UNSPECIFIED)
   #undef      UARTS_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_CORE0_PRIVATE
#elif defined (UARTS_STOP_SEC_CONST_UNSPECIFIED)
   #undef      UARTS_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_CORE0_PRIVATE


#elif defined (UARTS_START_SEC_ASIL0_CONST_8BIT)
   #undef      UARTS_START_SEC_ASIL0_CONST_8BIT
   #define   DEFAULT_START_SEC_ASIL0_CONST_8BIT_CORE0_PRIVATE
#elif defined (UARTS_STOP_SEC_ASIL0_CONST_8BIT)
   #undef      UARTS_STOP_SEC_ASIL0_CONST_8BIT
   #define DEFAULT_STOP_SEC_ASIL0_CONST_8BIT_CORE0_PRIVATE


#elif defined (UARTS_START_SEC_ASIL1_CONST_8BIT)
   #undef      UARTS_START_SEC_ASIL1_CONST_8BIT
   #define   DEFAULT_START_SEC_ASIL1_CONST_8BIT_CORE0_PRIVATE
#elif defined (UARTS_STOP_SEC_ASIL1_CONST_8BIT)
   #undef      UARTS_STOP_SEC_ASIL1_CONST_8BIT
   #define DEFAULT_STOP_SEC_ASIL1_CONST_8BIT_CORE0_PRIVATE


#elif defined (UARTS_START_SEC_ASIL0_VAR_UNSPECIFIED)
   #undef      UARTS_START_SEC_ASIL0_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_ASIL0_VAR_UNSPECIFIED_CORE0_PRIVATE
#elif defined (UARTS_STOP_SEC_ASIL0_VAR_UNSPECIFIED)
   #undef      UARTS_STOP_SEC_ASIL0_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_ASIL0_VAR_UNSPECIFIED_CORE0_PRIVATE


#elif defined (UARTS_START_SEC_ASIL1_VAR_UNSPECIFIED)
   #undef      UARTS_START_SEC_ASIL1_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_ASIL1_VAR_UNSPECIFIED_CORE0_PRIVATE
#elif defined (UARTS_STOP_SEC_ASIL1_VAR_UNSPECIFIED)
   #undef      UARTS_STOP_SEC_ASIL1_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_ASIL1_VAR_UNSPECIFIED_CORE0_PRIVATE


#elif defined (UARTS_START_SEC_POSTBUILDCFG)
   #undef      UARTS_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_CORE0_PRIVATE
#elif defined (UARTS_STOP_SEC_POSTBUILDCFG)
   #undef      UARTS_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_CORE0_PRIVATE
   /*************************************************************************************************************************************************
   **                                                                      CAN                                                                   **
   *************************************************************************************************************************************************/
   
   /*
    * To be used for mapping code to application block, boot block,
    * external flash etc
    */
#elif defined (CAN_START_SEC_CODE)
   #undef      CAN_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (CAN_STOP_SEC_CODE)
   #undef      CAN_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED
   
   
#elif defined (CAN_START_SEC_VAR_NOINIT_8BIT)
   #undef      CAN_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_CORE0_PRIVATE
#elif defined (CAN_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      CAN_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_CORE0_PRIVATE
   
   
#elif defined (CAN_START_SEC_VAR_NOINIT_16BIT)
   #undef      CAN_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_CORE0_PRIVATE
#elif defined (CAN_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      CAN_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_CORE0_PRIVATE
   
   
#elif defined (CAN_START_SEC_VAR_NOINIT_32BIT)
   #undef      CAN_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE
#elif defined (CAN_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      CAN_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE
   
   
#elif defined (CAN_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      CAN_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE
#elif defined (CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE
   
   
#elif defined (CAN_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      CAN_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_CORE0_PRIVATE
#elif defined (CAN_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      CAN_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_CORE0_PRIVATE
   
   
#elif defined (CAN_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      CAN_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_CORE0_PRIVATE
#elif defined (CAN_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      CAN_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_CORE0_PRIVATE
   
   
#elif defined (CAN_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      CAN_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_CORE0_PRIVATE
#elif defined (CAN_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      CAN_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_CORE0_PRIVATE
   
   
#elif defined (CAN_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      CAN_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE0_PRIVATE
#elif defined (CAN_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      CAN_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE0_PRIVATE
   
   
#elif defined (CAN_START_SEC_VAR_FAST_8BIT)
   #undef      CAN_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_CORE0_PRIVATE
#elif defined (CAN_STOP_SEC_VAR_FAST_8BIT)
   #undef      CAN_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_CORE0_PRIVATE
   
   
#elif defined (CAN_START_SEC_VAR_FAST_16BIT)
   #undef      CAN_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_CORE0_PRIVATE
#elif defined (CAN_STOP_SEC_VAR_FAST_16BIT)
   #undef      CAN_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_CORE0_PRIVATE
   
   
#elif defined (CAN_START_SEC_VAR_FAST_32BIT)
   #undef      CAN_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_CORE0_PRIVATE
#elif defined (CAN_STOP_SEC_VAR_FAST_32BIT)
   #undef      CAN_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_CORE0_PRIVATE
   
   
#elif defined (CAN_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      CAN_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_CORE0_PRIVATE
#elif defined (CAN_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      CAN_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_CORE0_PRIVATE
   
   
#elif defined (CAN_START_SEC_VAR_8BIT)
   #undef      CAN_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_CORE0_PRIVATE
#elif defined (CAN_STOP_SEC_VAR_8BIT)
   #undef      CAN_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_CORE0_PRIVATE
   
   
#elif defined (CAN_START_SEC_VAR_16BIT)
   #undef      CAN_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_CORE0_PRIVATE
#elif defined (CAN_STOP_SEC_VAR_16BIT)
   #undef      CAN_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_CORE0_PRIVATE
   
   
#elif defined (CAN_START_SEC_VAR_32BIT)
   #undef      CAN_START_SEC_VAR_32BIT
   //   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
   #define   DEFAULT_START_SEC_VAR_32BIT_CORE0_PRIVATE
#elif defined (CAN_STOP_SEC_VAR_32BIT)
   #undef      CAN_STOP_SEC_VAR_32BIT
   //   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED
   #define   DEFAULT_STOP_SEC_VAR_32BIT_CORE0_PRIVATE
   
   
#elif defined (CAN_START_SEC_VAR_UNSPECIFIED)
   #undef      CAN_START_SEC_VAR_UNSPECIFIED
   //   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_CORE0_PRIVATE
#elif defined (CAN_STOP_SEC_VAR_UNSPECIFIED)
   #undef      CAN_STOP_SEC_VAR_UNSPECIFIED
   //   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED
  #define   DEFAULT_STOP_SEC_VAR_UNSPECIFIED_CORE0_PRIVATE
   
   
#elif defined (CAN_START_SEC_CONST_8BIT)
   #undef      CAN_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_CORE0_PRIVATE
#elif defined (CAN_STOP_SEC_CONST_8BIT)
   #undef      CAN_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_CORE0_PRIVATE
   
   
#elif defined (CAN_START_SEC_CONST_16BIT)
   #undef      CAN_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_CORE0_PRIVATE
#elif defined (CAN_STOP_SEC_CONST_16BIT)
   #undef      CAN_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_CORE0_PRIVATE
   
   
#elif defined (CAN_START_SEC_CONST_32BIT)
   #undef      CAN_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_CORE0_PRIVATE
#elif defined (CAN_STOP_SEC_CONST_32BIT)
   #undef      CAN_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_CORE0_PRIVATE
   
   
#elif defined (CAN_START_SEC_CONST_UNSPECIFIED)
   #undef      CAN_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_CORE0_PRIVATE
#elif defined (CAN_STOP_SEC_CONST_UNSPECIFIED)
   #undef      CAN_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_CORE0_PRIVATE
   
   
#elif defined (CAN_START_SEC_ASIL0_CONST_8BIT)
   #undef      CAN_START_SEC_ASIL0_CONST_8BIT
   #define   DEFAULT_START_SEC_ASIL0_CONST_8BIT_CORE0_PRIVATE
#elif defined (CAN_STOP_SEC_ASIL0_CONST_8BIT)
   #undef      CAN_STOP_SEC_ASIL0_CONST_8BIT
   #define DEFAULT_STOP_SEC_ASIL0_CONST_8BIT_CORE0_PRIVATE
   
   
#elif defined (CAN_START_SEC_ASIL1_CONST_8BIT)
   #undef      CAN_START_SEC_ASIL1_CONST_8BIT
   #define   DEFAULT_START_SEC_ASIL1_CONST_8BIT_CORE0_PRIVATE
#elif defined (CAN_STOP_SEC_ASIL1_CONST_8BIT)
   #undef      CAN_STOP_SEC_ASIL1_CONST_8BIT
   #define DEFAULT_STOP_SEC_ASIL1_CONST_8BIT_CORE0_PRIVATE
   
   
#elif defined (CAN_START_SEC_ASIL0_VAR_UNSPECIFIED)
   #undef      CAN_START_SEC_ASIL0_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_ASIL0_VAR_UNSPECIFIED_CORE0_PRIVATE
#elif defined (CAN_STOP_SEC_ASIL0_VAR_UNSPECIFIED)
   #undef      CAN_STOP_SEC_ASIL0_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_ASIL0_VAR_UNSPECIFIED_CORE0_PRIVATE
   
   
#elif defined (CAN_START_SEC_ASIL1_VAR_UNSPECIFIED)
   #undef      CAN_START_SEC_ASIL1_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_ASIL1_VAR_UNSPECIFIED_CORE0_PRIVATE
#elif defined (CAN_STOP_SEC_ASIL1_VAR_UNSPECIFIED)
   #undef      CAN_STOP_SEC_ASIL1_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_ASIL1_VAR_UNSPECIFIED_CORE0_PRIVATE
   
   
#elif defined (CAN_START_SEC_POSTBUILDCFG)
   #undef      CAN_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_CORE0_PRIVATE
#elif defined (CAN_STOP_SEC_POSTBUILDCFG)
   #undef      CAN_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_CORE0_PRIVATE

/*************************************************************************************************************************************************
**                                                                      ADC                                                                   **
*************************************************************************************************************************************************/

/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (ADC_START_SEC_CODE)
   #undef      ADC_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (ADC_STOP_SEC_CODE)
   #undef      ADC_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (ADC_START_SEC_VAR_NOINIT_8BIT)
   #undef      ADC_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_CORE0_PRIVATE
#elif defined (ADC_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      ADC_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_CORE0_PRIVATE


#elif defined (ADC_START_SEC_VAR_NOINIT_16BIT)
   #undef      ADC_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_CORE0_PRIVATE
#elif defined (ADC_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      ADC_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_CORE0_PRIVATE


#elif defined (ADC_START_SEC_VAR_NOINIT_32BIT)
   #undef      ADC_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE
#elif defined (ADC_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      ADC_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE


#elif defined (ADC_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      ADC_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE
#elif defined (ADC_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      ADC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE


#elif defined (ADC_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      ADC_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_CORE0_PRIVATE
#elif defined (ADC_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      ADC_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_CORE0_PRIVATE


#elif defined (ADC_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      ADC_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_CORE0_PRIVATE
#elif defined (ADC_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      ADC_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_CORE0_PRIVATE


#elif defined (ADC_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      ADC_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_CORE0_PRIVATE
#elif defined (ADC_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      ADC_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_CORE0_PRIVATE


#elif defined (ADC_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      ADC_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE0_PRIVATE
#elif defined (ADC_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      ADC_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE0_PRIVATE


#elif defined (ADC_START_SEC_VAR_FAST_8BIT)
   #undef      ADC_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_CORE0_PRIVATE
#elif defined (ADC_STOP_SEC_VAR_FAST_8BIT)
   #undef      ADC_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_CORE0_PRIVATE


#elif defined (ADC_START_SEC_VAR_FAST_16BIT)
   #undef      ADC_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_CORE0_PRIVATE
#elif defined (ADC_STOP_SEC_VAR_FAST_16BIT)
   #undef      ADC_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_CORE0_PRIVATE


#elif defined (ADC_START_SEC_VAR_FAST_32BIT)
   #undef      ADC_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_CORE0_PRIVATE
#elif defined (ADC_STOP_SEC_VAR_FAST_32BIT)
   #undef      ADC_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_CORE0_PRIVATE


#elif defined (ADC_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      ADC_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_CORE0_PRIVATE
#elif defined (ADC_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      ADC_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_CORE0_PRIVATE


#elif defined (ADC_START_SEC_VAR_8BIT)
   #undef      ADC_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_CORE0_PRIVATE
#elif defined (ADC_STOP_SEC_VAR_8BIT)
   #undef      ADC_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_CORE0_PRIVATE


#elif defined (ADC_START_SEC_VAR_16BIT)
   #undef      ADC_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_CORE0_PRIVATE
#elif defined (ADC_STOP_SEC_VAR_16BIT)
   #undef      ADC_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_CORE0_PRIVATE


#elif defined (ADC_START_SEC_VAR_32BIT)
   #undef      ADC_START_SEC_VAR_32BIT
//   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
   #define   DEFAULT_START_SEC_VAR_32BIT_CORE0_PRIVATE
#elif defined (ADC_STOP_SEC_VAR_32BIT)
   #undef      ADC_STOP_SEC_VAR_32BIT
//   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED
   #define   DEFAULT_STOP_SEC_VAR_32BIT_CORE0_PRIVATE


#elif defined (ADC_START_SEC_VAR_UNSPECIFIED)
   #undef      ADC_START_SEC_VAR_UNSPECIFIED
//   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_CORE0_PRIVATE
#elif defined (ADC_STOP_SEC_VAR_UNSPECIFIED)
   #undef      ADC_STOP_SEC_VAR_UNSPECIFIED
//   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED
  #define   DEFAULT_STOP_SEC_VAR_UNSPECIFIED_CORE0_PRIVATE


#elif defined (ADC_START_SEC_CONST_8BIT)
   #undef      ADC_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_CORE0_PRIVATE
#elif defined (ADC_STOP_SEC_CONST_8BIT)
   #undef      ADC_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_CORE0_PRIVATE


#elif defined (ADC_START_SEC_CONST_16BIT)
   #undef      ADC_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_CORE0_PRIVATE
#elif defined (ADC_STOP_SEC_CONST_16BIT)
   #undef      ADC_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_CORE0_PRIVATE


#elif defined (ADC_START_SEC_CONST_32BIT)
   #undef      ADC_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_CORE0_PRIVATE
#elif defined (ADC_STOP_SEC_CONST_32BIT)
   #undef      ADC_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_CORE0_PRIVATE


#elif defined (ADC_START_SEC_CONST_UNSPECIFIED)
   #undef      ADC_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_CORE0_PRIVATE
#elif defined (ADC_STOP_SEC_CONST_UNSPECIFIED)
   #undef      ADC_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_CORE0_PRIVATE


#elif defined (ADC_START_SEC_ASIL0_CONST_8BIT)
   #undef      ADC_START_SEC_ASIL0_CONST_8BIT
   #define   DEFAULT_START_SEC_ASIL0_CONST_8BIT_CORE0_PRIVATE
#elif defined (ADC_STOP_SEC_ASIL0_CONST_8BIT)
   #undef      ADC_STOP_SEC_ASIL0_CONST_8BIT
   #define DEFAULT_STOP_SEC_ASIL0_CONST_8BIT_CORE0_PRIVATE


#elif defined (ADC_START_SEC_ASIL1_CONST_8BIT)
   #undef      ADC_START_SEC_ASIL1_CONST_8BIT
   #define   DEFAULT_START_SEC_ASIL1_CONST_8BIT_CORE0_PRIVATE
#elif defined (ADC_STOP_SEC_ASIL1_CONST_8BIT)
   #undef      ADC_STOP_SEC_ASIL1_CONST_8BIT
   #define DEFAULT_STOP_SEC_ASIL1_CONST_8BIT_CORE0_PRIVATE


#elif defined (ADC_START_SEC_ASIL0_VAR_UNSPECIFIED)
   #undef      ADC_START_SEC_ASIL0_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_ASIL0_VAR_UNSPECIFIED_CORE0_PRIVATE
#elif defined (ADC_STOP_SEC_ASIL0_VAR_UNSPECIFIED)
   #undef      ADC_STOP_SEC_ASIL0_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_ASIL0_VAR_UNSPECIFIED_CORE0_PRIVATE


#elif defined (ADC_START_SEC_ASIL1_VAR_UNSPECIFIED)
   #undef      ADC_START_SEC_ASIL1_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_ASIL1_VAR_UNSPECIFIED_CORE0_PRIVATE
#elif defined (ADC_STOP_SEC_ASIL1_VAR_UNSPECIFIED)
   #undef      ADC_STOP_SEC_ASIL1_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_ASIL1_VAR_UNSPECIFIED_CORE0_PRIVATE


#elif defined (ADC_START_SEC_POSTBUILDCFG)
   #undef      ADC_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_CORE0_PRIVATE
#elif defined (ADC_STOP_SEC_POSTBUILDCFG)
   #undef      ADC_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_CORE0_PRIVATE


/*************************************************************************************************************************************************
**                                                                      RADAR                                                                   **
*************************************************************************************************************************************************/

/*
 * To be used for mapping code to application block, boot block,
 * external flash etc
 */
#elif defined (RADAR_START_SEC_CODE)
   #undef      RADAR_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_CORE1_PRIVATE
#elif defined (RADAR_STOP_SEC_CODE)
   #undef      RADAR_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_CORE1_PRIVATE


#elif defined (RADAR_START_SEC_VAR_NOINIT_8BIT)
   #undef      RADAR_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_CORE1_PRIVATE
#elif defined (RADAR_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      RADAR_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_CORE1_PRIVATE


#elif defined (RADAR_START_SEC_VAR_NOINIT_16BIT)
   #undef      RADAR_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_CORE1_PRIVATE
#elif defined (RADAR_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      RADAR_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_CORE1_PRIVATE


#elif defined (RADAR_START_SEC_VAR_NOINIT_32BIT)
   #undef      RADAR_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_CORE1_PRIVATE
#elif defined (RADAR_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      RADAR_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_CORE1_PRIVATE


#elif defined (RADAR_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      RADAR_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE1_PRIVATE
#elif defined (RADAR_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      RADAR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE1_PRIVATE


#elif defined (RADAR_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      RADAR_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_CORE1_PRIVATE
#elif defined (RADAR_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      RADAR_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_CORE1_PRIVATE


#elif defined (RADAR_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      RADAR_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_CORE1_PRIVATE
#elif defined (RADAR_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      RADAR_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_CORE1_PRIVATE


#elif defined (RADAR_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      RADAR_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_CORE1_PRIVATE
#elif defined (RADAR_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      RADAR_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_CORE1_PRIVATE


#elif defined (RADAR_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      RADAR_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE1_PRIVATE
#elif defined (RADAR_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      RADAR_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE1_PRIVATE


#elif defined (RADAR_START_SEC_VAR_FAST_8BIT)
   #undef      RADAR_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_CORE1_PRIVATE
#elif defined (RADAR_STOP_SEC_VAR_FAST_8BIT)
   #undef      RADAR_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_CORE1_PRIVATE


#elif defined (RADAR_START_SEC_VAR_FAST_16BIT)
   #undef      RADAR_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_CORE1_PRIVATE
#elif defined (RADAR_STOP_SEC_VAR_FAST_16BIT)
   #undef      RADAR_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_CORE1_PRIVATE


#elif defined (RADAR_START_SEC_VAR_FAST_32BIT)
   #undef      RADAR_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_CORE1_PRIVATE
#elif defined (RADAR_STOP_SEC_VAR_FAST_32BIT)
   #undef      RADAR_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_CORE1_PRIVATE


#elif defined (RADAR_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      RADAR_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_CORE1_PRIVATE
#elif defined (RADAR_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      RADAR_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_CORE1_PRIVATE


#elif defined (RADAR_START_SEC_VAR_8BIT)
   #undef      RADAR_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_CORE1_PRIVATE
#elif defined (RADAR_STOP_SEC_VAR_8BIT)
   #undef      RADAR_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_CORE1_PRIVATE


#elif defined (RADAR_START_SEC_VAR_16BIT)
   #undef      RADAR_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_CORE1_PRIVATE
#elif defined (RADAR_STOP_SEC_VAR_16BIT)
   #undef      RADAR_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_CORE1_PRIVATE


#elif defined (RADAR_START_SEC_VAR_32BIT)
   #undef      RADAR_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_CORE1_PRIVATE
#elif defined (RADAR_STOP_SEC_VAR_32BIT)
   #undef      RADAR_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_CORE1_PRIVATE


#elif defined (RADAR_START_SEC_VAR_UNSPECIFIED)
   #undef      RADAR_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_CORE1_PRIVATE
#elif defined (RADAR_STOP_SEC_VAR_UNSPECIFIED)
   #undef      RADAR_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_CORE1_PRIVATE


#elif defined (RADAR_START_SEC_ASIL0_VAR_8BIT)
   #undef      RADAR_START_SEC_ASIL0_VAR_8BIT
   #define   DEFAULT_START_SEC_ASIL0_VAR_8BIT_CORE1_PRIVATE
#elif defined (RADAR_STOP_SEC_ASIL0_VAR_8BIT)
   #undef      RADAR_STOP_SEC_ASIL0_VAR_8BIT
   #define DEFAULT_STOP_SEC_ASIL0_VAR_8BIT_CORE1_PRIVATE


#elif defined (RADAR_START_SEC_CONST_8BIT)
   #undef      RADAR_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_CORE1_PRIVATE
#elif defined (RADAR_STOP_SEC_CONST_8BIT)
   #undef      RADAR_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_CORE1_PRIVATE


#elif defined (RADAR_START_SEC_CONST_16BIT)
   #undef      RADAR_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_CORE1_PRIVATE
#elif defined (RADAR_STOP_SEC_CONST_16BIT)
   #undef      RADAR_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_CORE1_PRIVATE


#elif defined (RADAR_START_SEC_CONST_32BIT)
   #undef      RADAR_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_CORE1_PRIVATE
#elif defined (RADAR_STOP_SEC_CONST_32BIT)
   #undef      RADAR_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_CORE1_PRIVATE


#elif defined (RADAR_START_SEC_CONST_UNSPECIFIED)
   #undef      RADAR_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_CORE1_PRIVATE
#elif defined (RADAR_STOP_SEC_CONST_UNSPECIFIED)
   #undef      RADAR_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_CORE1_PRIVATE


#elif defined (RADAR_START_SEC_POSTBUILDCFG)
   #undef      RADAR_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_CORE1_PRIVATE
#elif defined (RADAR_STOP_SEC_POSTBUILDCFG)
   #undef      RADAR_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_CORE1_PRIVATE
#else
  #error "IS31_UserMemMap.h: No valid section define found"

#endif
/*******************************************************************************
**                      Default section mapping                               **
*******************************************************************************/
/* general start of #elif chain whith #if                                     */
#if defined (START_WITH_IF)

/*****************************************************************************
**                                 ROM CONFIG DATA                          **
******************************************************************************/
/*
Memory Section of Post Build Configuration
*/

#elif defined (DEFAULT_START_SEC_POSTBUILDCFG_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_POSTBUILDCFG_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU0.Private.CONFIGURATION_PB"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU0.Private.CONFIGURATION_PB" a
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU0.Private.CONFIGURATION_PB" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_POSTBUILDCFG_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_POSTBUILDCFG_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_POSTBUILDCFG_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_POSTBUILDCFG_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU1.Private.CONFIGURATION_PB"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU1.Private.CONFIGURATION_PB" a
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU1.Private.CONFIGURATION_PB" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_POSTBUILDCFG_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_POSTBUILDCFG_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_POSTBUILDCFG_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_POSTBUILDCFG_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU2.Private.CONFIGURATION_PB"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU2.Private.CONFIGURATION_PB" a
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU2.Private.CONFIGURATION_PB" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_POSTBUILDCFG_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_POSTBUILDCFG_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_POSTBUILDCFG_SHARED)
   #undef      DEFAULT_START_SEC_POSTBUILDCFG_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="Shared.CONFIGURATION_PB"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.Shared.CONFIGURATION_PB" a
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.Shared.CONFIGURATION_PB" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED)
   #undef      DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (ECUM_START_SEC_POSTBUILDCFG_CORE0_PRIVATE)
   #undef      ECUM_START_SEC_POSTBUILDCFG_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU0.Private.CONFIGURATION_ECUM_PB"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU0.Private.CONFIGURATION_ECUM_PB" a
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU0.Private.CONFIGURATION_ECUM_PB" far-absolute R
   #endif
   #endif
#elif defined (ECUM_STOP_SEC_POSTBUILDCFG_CORE0_PRIVATE)
   #undef      ECUM_STOP_SEC_POSTBUILDCFG_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (ECUM_START_SEC_POSTBUILDCFG_CORE1_PRIVATE)
   #undef      ECUM_START_SEC_POSTBUILDCFG_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU1.Private.CONFIGURATION_ECUM_PB"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU1.Private.CONFIGURATION_ECUM_PB" a
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU1.Private.CONFIGURATION_ECUM_PB" far-absolute R
   #endif
   #endif
#elif defined (ECUM_STOP_SEC_POSTBUILDCFG_CORE1_PRIVATE)
   #undef      ECUM_STOP_SEC_POSTBUILDCFG_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (ECUM_START_SEC_POSTBUILDCFG_CORE2_PRIVATE)
   #undef      ECUM_START_SEC_POSTBUILDCFG_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU2.Private.CONFIGURATION_ECUM_PB"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU2.Private.CONFIGURATION_ECUM_PB" a
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU2.Private.CONFIGURATION_ECUM_PB" far-absolute R
   #endif
   #endif
#elif defined (ECUM_STOP_SEC_POSTBUILDCFG_CORE2_PRIVATE)
   #undef      ECUM_STOP_SEC_POSTBUILDCFG_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (ECUM_START_SEC_POSTBUILDCFG_SHARED)
   #undef      ECUM_START_SEC_POSTBUILDCFG_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="Shared.CONFIGURATION_ECUM_PB"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.Shared.CONFIGURATION_ECUM_PB" a
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.Shared.CONFIGURATION_ECUM_PB" far-absolute R
   #endif
   #endif
#elif defined (ECUM_STOP_SEC_POSTBUILDCFG_SHARED)
   #undef      ECUM_STOP_SEC_POSTBUILDCFG_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (MCAL_TRAP_START_SEC_TRAP_HANDLER_CPU0)
   #undef      MCAL_TRAP_START_SEC_TRAP_HANDLER_CPU0
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code="CPU0_TRAP_HANDLER_CODE_ROM"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.CPU0_TRAP_HANDLER_CODE_ROM" ax 32
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.CPU0_TRAP_HANDLER_CODE_ROM" RX
   #pragma align_functions 32
   #endif
   #endif
#elif defined (MCAL_TRAP_STOP_SEC_TRAP_HANDLER_CPU0)
   #undef      MCAL_TRAP_STOP_SEC_TRAP_HANDLER_CPU0
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
    #pragma section CODE RX
    #pragma align_functions
   #endif
   #endif


#elif defined (MCAL_TRAP_START_SEC_TRAP_HANDLER_CPU1)
   #undef      MCAL_TRAP_START_SEC_TRAP_HANDLER_CPU1
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code="CPU1_TRAP_HANDLER_CODE_ROM"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.CPU1_TRAP_HANDLER_CODE_ROM" ax 32
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   /* Memory section not defined since 32 byte alignment is not supported through #pragma */
   #endif
   #endif
#elif defined (MCAL_TRAP_STOP_SEC_TRAP_HANDLER_CPU1)
   #undef      MCAL_TRAP_STOP_SEC_TRAP_HANDLER_CPU1
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   /* Memory section not defined since 32 byte alignment is not supported through #pragma */
   #endif
   #endif


#elif defined (MCAL_TRAP_START_SEC_TRAP_HANDLER_CPU2)
   #undef      MCAL_TRAP_START_SEC_TRAP_HANDLER_CPU2
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code="CPU2_TRAP_HANDLER_CODE_ROM"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.CPU2_TRAP_HANDLER_CODE_ROM" ax 32
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   /* Memory section not defined since 32 byte alignment is not supported through #pragma */
   #endif
   #endif
#elif defined (MCAL_TRAP_STOP_SEC_TRAP_HANDLER_CPU2)
   #undef      MCAL_TRAP_STOP_SEC_TRAP_HANDLER_CPU2
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   /* Memory section not defined since 32 byte alignment is not supported through #pragma */
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CODE_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_CODE_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code="CPU0.Private.DEFAULT_CODE_ROM"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.CPU0.Private.DEFAULT_CODE_ROM" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.CPU0.Private.DEFAULT_CODE_ROM" RX
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CODE_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CODE_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CODE_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_CODE_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code="CPU1.Private.DEFAULT_CODE_ROM"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.CPU1.Private.DEFAULT_CODE_ROM" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.CPU1.Private.DEFAULT_CODE_ROM" RX
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CODE_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CODE_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CODE_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_CODE_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code="CPU2.Private.DEFAULT_CODE_ROM"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.CPU2.Private.DEFAULT_CODE_ROM" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.CPU2.Private.DEFAULT_CODE_ROM" RX
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CODE_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CODE_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CODE_SHARED)
   #undef      DEFAULT_START_SEC_CODE_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code="Shared.DEFAULT_CODE_ROM"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
//   #pragma section ".text.Shared.DEFAULT_CODE_ROM" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.Shared.DEFAULT_CODE_ROM" RX
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CODE_SHARED)
   #undef      DEFAULT_STOP_SEC_CODE_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
//   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif

#elif defined (DEFAULT_START_SEC_SAFETY_CODE_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_SAFETY_CODE_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code="CPU0.Private.DEFAULT_SAFETY_CODE_ROM"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.CPU0.Private.DEFAULT_SAFETY_CODE_ROM" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.CPU0.Private.DEFAULT_SAFETY_CODE_ROM" RX
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_SAFETY_CODE_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_SAFETY_CODE_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_SAFETY_CODE_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_SAFETY_CODE_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code="CPU1.Private.DEFAULT_SAFETY_CODE_ROM"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.CPU1.Private.DEFAULT_SAFETY_CODE_ROM" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.CPU1.Private.DEFAULT_SAFETY_CODE_ROM" RX
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_SAFETY_CODE_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_SAFETY_CODE_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_SAFETY_CODE_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_SAFETY_CODE_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code="CPU2.Private.DEFAULT_SAFETY_CODE_ROM"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.CPU2.Private.DEFAULT_SAFETY_CODE_ROM" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.CPU2.Private.DEFAULT_SAFETY_CODE_ROM" RX
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_SAFETY_CODE_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_SAFETY_CODE_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_SAFETY_CODE_SHARED)
   #undef      DEFAULT_START_SEC_SAFETY_CODE_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code="Shared.DEFAULT_SAFETY_CODE_ROM"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
//   #pragma section ".text.Shared.DEFAULT_SAFETY_CODE_ROM" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.Shared.DEFAULT_SAFETY_CODE_ROM" RX
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_SAFETY_CODE_SHARED)
   #undef      DEFAULT_STOP_SEC_SAFETY_CODE_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
//   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_QM_CODE_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_QM_CODE_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code="CPU0.Private.DEFAULT_QM_CODE_ROM"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.CPU0.Private.DEFAULT_QM_CODE_ROM" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.CPU0.Private.DEFAULT_QM_CODE_ROM" RX
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_QM_CODE_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_QM_CODE_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_QM_CODE_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_QM_CODE_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code="CPU1.Private.DEFAULT_QM_CODE_ROM"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.CPU1.Private.DEFAULT_QM_CODE_ROM" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.CPU1.Private.DEFAULT_QM_CODE_ROM" RX
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_QM_CODE_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_QM_CODE_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_QM_CODE_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_QM_CODE_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code="CPU2.Private.DEFAULT_QM_CODE_ROM"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.CPU2.Private.DEFAULT_QM_CODE_ROM" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.CPU2.Private.DEFAULT_QM_CODE_ROM" RX
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_QM_CODE_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_QM_CODE_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_QM_CODE_SHARED)
   #undef      DEFAULT_START_SEC_QM_CODE_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code="Shared.DEFAULT_QM_CODE_ROM"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.Shared.DEFAULT_QM_CODE_ROM" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.Shared.DEFAULT_QM_CODE_ROM" RX
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_QM_CODE_SHARED)
   #undef      DEFAULT_STOP_SEC_QM_CODE_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="CPU0.Private.DEFAULT_RAM_NOINIT_8BIT"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.CPU0.Private.DEFAULT_RAM_NOINIT_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_NOINIT_8BIT" ".bss.CPU0.Private.DEFAULT_RAM_NOINIT_8BIT" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="CPU1.Private.DEFAULT_RAM_NOINIT_8BIT"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.CPU1.Private.DEFAULT_RAM_NOINIT_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_NOINIT_8BIT" ".bss.CPU1.Private.DEFAULT_RAM_NOINIT_8BIT" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="CPU2.Private.DEFAULT_RAM_NOINIT_8BIT"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.CPU2.Private.DEFAULT_RAM_NOINIT_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_NOINIT_8BIT" ".bss.CPU2.Private.DEFAULT_RAM_NOINIT_8BIT" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="Shared.DEFAULT_RAM_NOINIT_8BIT"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.Shared.DEFAULT_RAM_NOINIT_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_NOINIT_8BIT" ".bss.Shared.DEFAULT_RAM_NOINIT_8BIT" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="CPU0.Private.DEFAULT_RAM_NOINIT_16BIT"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.CPU0.Private.DEFAULT_RAM_NOINIT_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_NOINIT_16BIT" ".bss.CPU0.Private.DEFAULT_RAM_NOINIT_16BIT" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_16BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_16BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="CPU1.Private.DEFAULT_RAM_NOINIT_16BIT"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.CPU1.Private.DEFAULT_RAM_NOINIT_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_NOINIT_16BIT" ".bss.CPU1.Private.DEFAULT_RAM_NOINIT_16BIT" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_16BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_16BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="CPU2.Private.DEFAULT_RAM_NOINIT_16BIT"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.CPU2.Private.DEFAULT_RAM_NOINIT_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_NOINIT_16BIT" ".bss.CPU2.Private.DEFAULT_RAM_NOINIT_16BIT" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="Shared.DEFAULT_RAM_NOINIT_16BIT"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.Shared.DEFAULT_RAM_NOINIT_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_NOINIT_16BIT" ".bss.Shared.DEFAULT_RAM_NOINIT_16BIT" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="CPU0.Private.DEFAULT_RAM_NOINIT_32BIT"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.CPU0.Private.DEFAULT_RAM_NOINIT_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_NOINIT_32BIT" ".bss.CPU0.Private.DEFAULT_RAM_NOINIT_32BIT" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="CPU1.Private.DEFAULT_RAM_NOINIT_32BIT"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.CPU1.Private.DEFAULT_RAM_NOINIT_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_NOINIT_32BIT" ".bss.CPU1.Private.DEFAULT_RAM_NOINIT_32BIT" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="CPU2.Private.DEFAULT_RAM_NOINIT_32BIT"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.CPU2.Private.DEFAULT_RAM_NOINIT_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_NOINIT_32BIT" ".bss.CPU2.Private.DEFAULT_RAM_NOINIT_32BIT" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="Shared.DEFAULT_RAM_NOINIT_32BIT"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.Shared.DEFAULT_RAM_NOINIT_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_NOINIT_32BIT" ".bss.Shared.DEFAULT_RAM_NOINIT_32BIT" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="CPU0.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.CPU0.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED" ".bss.CPU0.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="CPU1.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.CPU1.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED" ".bss.CPU1.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="CPU2.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.CPU2.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED" ".bss.CPU2.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="Shared.DEFAULT_RAM_NOINIT_UNSPECIFIED"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.Shared.DEFAULT_RAM_NOINIT_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_NOINIT_UNSPECIFIED" ".bss.Shared.DEFAULT_RAM_NOINIT_UNSPECIFIED" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_8BIT" ".bss.CPU0.Private.DEFAULT_RAM_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU1.Private.DEFAULT_RAM_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_8BIT" ".bss.CPU1.Private.DEFAULT_RAM_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU2.Private.DEFAULT_RAM_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_8BIT" ".bss.CPU2.Private.DEFAULT_RAM_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_8BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="Shared.DEFAULT_RAM_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_8BIT" ".bss.Shared.DEFAULT_RAM_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_8BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL0_VAR_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL0_VAR_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_ASIL0_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_ASIL0_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_ASIL0_8BIT" ".bss.CPU0.Private.DEFAULT_RAM_ASIL0_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL0_VAR_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL0_VAR_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL0_VAR_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL0_VAR_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU1.Private.DEFAULT_RAM_ASIL0_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_ASIL0_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_ASIL0_8BIT" ".bss.CPU1.Private.DEFAULT_RAM_ASIL0_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL0_VAR_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL0_VAR_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL0_VAR_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL0_VAR_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU2.Private.DEFAULT_RAM_ASIL0_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_ASIL0_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_ASIL0_8BIT" ".bss.CPU2.Private.DEFAULT_RAM_ASIL0_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL0_VAR_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL0_VAR_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL0_VAR_8BIT_SHARED)
   #undef      DEFAULT_START_SEC_ASIL0_VAR_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="Shared.DEFAULT_RAM_ASIL0_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_ASIL0_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_ASIL0_8BIT" ".bss.Shared.DEFAULT_RAM_ASIL0_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL0_VAR_8BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_ASIL0_VAR_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_VAR_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL1_VAR_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_ASIL1_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_ASIL1_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_ASIL1_8BIT" ".bss.CPU0.Private.DEFAULT_RAM_ASIL1_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_VAR_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL1_VAR_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_VAR_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL1_VAR_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU1.Private.DEFAULT_RAM_ASIL1_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_ASIL1_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_ASIL1_8BIT" ".bss.CPU1.Private.DEFAULT_RAM_ASIL1_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_VAR_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL1_VAR_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_VAR_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL1_VAR_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU2.Private.DEFAULT_RAM_ASIL1_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_ASIL1_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_ASIL1_8BIT" ".bss.CPU2.Private.DEFAULT_RAM_ASIL1_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_VAR_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL1_VAR_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_VAR_8BIT_SHARED)
   #undef      DEFAULT_START_SEC_ASIL1_VAR_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="Shared.DEFAULT_RAM_ASIL1_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_ASIL1_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_ASIL1_8BIT" ".bss.Shared.DEFAULT_RAM_ASIL1_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_VAR_8BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_ASIL1_VAR_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif



#elif defined (DEFAULT_START_SEC_BACKUP_VAR_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_BACKUP_VAR_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_BACKUP_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_BACKUP_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_BACKUP_8BIT" ".bss.CPU0.Private.DEFAULT_RAM_BACKUP_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_BACKUP_VAR_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_BACKUP_VAR_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_BACKUP_VAR_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_BACKUP_VAR_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU1.Private.DEFAULT_RAM_BACKUP_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_BACKUP_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_BACKUP_8BIT" ".bss.CPU1.Private.DEFAULT_RAM_BACKUP_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_BACKUP_VAR_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_BACKUP_VAR_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_BACKUP_VAR_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_BACKUP_VAR_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU2.Private.DEFAULT_RAM_BACKUP_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_BACKUP_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_BACKUP_8BIT" ".bss.CPU2.Private.DEFAULT_RAM_BACKUP_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_BACKUP_VAR_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_BACKUP_VAR_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_BACKUP_VAR_8BIT_SHARED)
   #undef      DEFAULT_START_SEC_BACKUP_VAR_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="Shared.DEFAULT_RAM_BACKUP_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_BACKUP_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_BACKUP_8BIT" ".bss.Shared.DEFAULT_RAM_BACKUP_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_BACKUP_VAR_8BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_BACKUP_VAR_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_16BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_16BIT" ".bss.CPU0.Private.DEFAULT_RAM_16BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_16BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_16BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU1.Private.DEFAULT_RAM_16BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_16BIT" ".bss.CPU1.Private.DEFAULT_RAM_16BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_16BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_16BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_16BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_16BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU2.Private.DEFAULT_RAM_16BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_16BIT" ".bss.CPU2.Private.DEFAULT_RAM_16BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_16BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_16BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_16BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_16BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="Shared.DEFAULT_RAM_16BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_16BIT" ".bss.Shared.DEFAULT_RAM_16BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_16BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_16BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_32BIT" ".bss.CPU0.Private.DEFAULT_RAM_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU1.Private.DEFAULT_RAM_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_32BIT" ".bss.CPU1.Private.DEFAULT_RAM_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU2.Private.DEFAULT_RAM_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_32BIT" ".bss.CPU2.Private.DEFAULT_RAM_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_32BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="Shared.DEFAULT_RAM_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_32BIT" ".bss.Shared.DEFAULT_RAM_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_32BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_SPL_VAR_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_SPL_VAR_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_32BIT" ".bss.CPU0.Private.DEFAULT_RAM_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_SPL_VAR_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_SPL_VAR_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_SPL_VAR_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_SPL_VAR_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU1.Private.DEFAULT_RAM_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_32BIT" ".bss.CPU1.Private.DEFAULT_RAM_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_SPL_VAR_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_SPL_VAR_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_SPL_VAR_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_SPL_VAR_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU2.Private.DEFAULT_RAM_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_32BIT" ".bss.CPU2.Private.DEFAULT_RAM_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_SPL_VAR_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_SPL_VAR_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_SPL_VAR_32BIT_SHARED)
   #undef      DEFAULT_START_SEC_SPL_VAR_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="Shared.DEFAULT_RAM_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_32BIT" ".bss.Shared.DEFAULT_RAM_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_SPL_VAR_32BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_SPL_VAR_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_INIT_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_INIT_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="CPU0.Private.DEFAULT_RAM_INIT_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_INIT_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_INIT_8BIT" ".bss.CPU0.Private.DEFAULT_RAM_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_INIT_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_INIT_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_INIT_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_INIT_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="CPU1.Private.DEFAULT_RAM_INIT_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_INIT_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_INIT_8BIT" ".bss.CPU1.Private.DEFAULT_RAM_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_INIT_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_INIT_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_INIT_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_INIT_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="CPU2.Private.DEFAULT_RAM_INIT_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_INIT_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_INIT_8BIT" ".bss.CPU2.Private.DEFAULT_RAM_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_INIT_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_INIT_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_INIT_8BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_INIT_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="Shared.DEFAULT_RAM_INIT_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_INIT_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_INIT_8BIT" ".bss.Shared.DEFAULT_RAM_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_INIT_8BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_INIT_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_BACKUP_VAR_INIT_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_BACKUP_VAR_INIT_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="CPU0.Private.DEFAULT_RAM_BACKUP_INIT_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_BACKUP_INIT_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_BACKUP_INIT_8BIT" ".bss.CPU0.Private.DEFAULT_RAM_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_BACKUP_VAR_INIT_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_BACKUP_VAR_INIT_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_BACKUP_VAR_INIT_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_BACKUP_VAR_INIT_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="CPU1.Private.DEFAULT_RAM_BACKUP_INIT_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_BACKUP_INIT_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_BACKUP_INIT_8BIT" ".bss.CPU1.Private.DEFAULT_RAM_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_BACKUP_VAR_INIT_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_BACKUP_VAR_INIT_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_BACKUP_VAR_INIT_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_BACKUP_VAR_INIT_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="CPU2.Private.DEFAULT_RAM_BACKUP_INIT_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_BACKUP_INIT_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_BACKUP_INIT_8BIT" ".bss.CPU2.Private.DEFAULT_RAM_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_BACKUP_VAR_INIT_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_BACKUP_VAR_INIT_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_BACKUP_VAR_INIT_8BIT_SHARED)
   #undef      DEFAULT_START_SEC_BACKUP_VAR_INIT_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="Shared.DEFAULT_RAM_BACKUP_INIT_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_BACKUP_INIT_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_BACKUP_INIT_8BIT" ".bss.Shared.DEFAULT_RAM_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_BACKUP_VAR_INIT_8BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_BACKUP_VAR_INIT_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_INIT_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_INIT_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="CPU0.Private.DEFAULT_RAM_INIT_16BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_INIT_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_INIT_16BIT" ".bss.CPU0.Private.DEFAULT_RAM_16BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_INIT_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_INIT_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_INIT_16BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_INIT_16BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="CPU1.Private.DEFAULT_RAM_INIT_16BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_INIT_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_INIT_16BIT" ".bss.CPU1.Private.DEFAULT_RAM_16BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_INIT_16BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_INIT_16BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_INIT_16BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_INIT_16BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="CPU2.Private.DEFAULT_RAM_INIT_16BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_INIT_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_INIT_16BIT" ".bss.CPU2.Private.DEFAULT_RAM_16BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_INIT_16BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_INIT_16BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_INIT_16BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_INIT_16BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="Shared.DEFAULT_RAM_INIT_16BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_INIT_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_INIT_16BIT" ".bss.Shared.DEFAULT_RAM_16BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_INIT_16BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_INIT_16BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_INIT_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_INIT_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="CPU0.Private.DEFAULT_RAM_INIT_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_INIT_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_INIT_32BIT" ".bss.CPU0.Private.DEFAULT_RAM_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_INIT_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_INIT_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_INIT_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_INIT_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="CPU1.Private.DEFAULT_RAM_INIT_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_INIT_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_INIT_32BIT" ".bss.CPU1.Private.DEFAULT_RAM_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_INIT_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_INIT_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_INIT_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_INIT_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="CPU2.Private.DEFAULT_RAM_INIT_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_INIT_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_INIT_32BIT" ".bss.CPU2.Private.DEFAULT_RAM_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_INIT_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_INIT_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_INIT_32BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_INIT_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="Shared.DEFAULT_RAM_INIT_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_INIT_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_INIT_32BIT" ".bss.Shared.DEFAULT_RAM_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_INIT_32BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_INIT_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL0_VAR_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL0_VAR_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_ASIL0_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_ASIL0_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_ASIL0_32BIT" ".bss.CPU0.Private.DEFAULT_RAM_ASIL0_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL0_VAR_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL0_VAR_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL0_VAR_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL0_VAR_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU1.Private.DEFAULT_RAM_ASIL0_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_ASIL0_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_ASIL0_32BIT" ".bss.CPU1.Private.DEFAULT_RAM_ASIL0_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL0_VAR_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL0_VAR_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL0_VAR_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL0_VAR_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU2.Private.DEFAULT_RAM_ASIL0_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_ASIL0_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_ASIL0_32BIT" ".bss.CPU2.Private.DEFAULT_RAM_ASIL0_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL0_VAR_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL0_VAR_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL0_VAR_32BIT_SHARED)
   #undef      DEFAULT_START_SEC_ASIL0_VAR_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="Shared.DEFAULT_RAM_ASIL0_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_ASIL0_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_ASIL0_32BIT" ".bss.Shared.DEFAULT_RAM_ASIL0_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL0_VAR_32BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_ASIL0_VAR_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif



#elif defined (DEFAULT_START_SEC_ASIL1_VAR_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL1_VAR_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_ASIL1_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_ASIL1_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_ASIL1_32BIT" ".bss.CPU0.Private.DEFAULT_RAM_ASIL1_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_VAR_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL1_VAR_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_VAR_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL1_VAR_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU1.Private.DEFAULT_RAM_ASIL1_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_ASIL1_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_ASIL1_32BIT" ".bss.CPU1.Private.DEFAULT_RAM_ASIL1_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_VAR_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL1_VAR_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_VAR_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL1_VAR_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU2.Private.DEFAULT_RAM_ASIL1_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_ASIL1_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_ASIL1_32BIT" ".bss.CPU2.Private.DEFAULT_RAM_ASIL1_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_VAR_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL1_VAR_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_VAR_32BIT_SHARED)
   #undef      DEFAULT_START_SEC_ASIL1_VAR_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="Shared.DEFAULT_RAM_ASIL1_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_ASIL1_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_ASIL1_32BIT" ".bss.Shared.DEFAULT_RAM_ASIL1_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_VAR_32BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_ASIL1_VAR_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif



#elif defined (DEFAULT_START_SEC_ASIL1_VAR_FAST_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL1_VAR_FAST_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="CPU0.Private.DEFAULT_RAM_ASIL1_32BIT"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.CPU0.Private.DEFAULT_RAM_ASIL1_32BIT" awBz 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.CPU0.Private.DEFAULT_RAM_ASIL1_32BIT" ".zbss.CPU0.Private.DEFAULT_RAM_ASIL1_32BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_VAR_FAST_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL1_VAR_FAST_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_VAR_FAST_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL1_VAR_FAST_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="CPU1.Private.DEFAULT_RAM_ASIL1_32BIT"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.CPU1.Private.DEFAULT_RAM_ASIL1_32BIT" awBz 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.CPU1.Private.DEFAULT_RAM_ASIL1_32BIT" ".zbss.CPU1.Private.DEFAULT_RAM_ASIL1_32BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_VAR_FAST_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL1_VAR_FAST_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory near
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_VAR_FAST_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL1_VAR_FAST_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="CPU2.Private.DEFAULT_RAM_ASIL1_32BIT"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.CPU2.Private.DEFAULT_RAM_ASIL1_32BIT" awBz 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.CPU2.Private.DEFAULT_RAM_ASIL1_32BIT" ".zbss.CPU2.Private.DEFAULT_RAM_ASIL1_32BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_VAR_FAST_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL1_VAR_FAST_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory near
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_VAR_FAST_32BIT_SHARED)
   #undef      DEFAULT_START_SEC_ASIL1_VAR_FAST_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="Shared.DEFAULT_RAM_ASIL1_32BIT"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.Shared.DEFAULT_RAM_ASIL1_32BIT" awBz 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.Shared.DEFAULT_RAM_ASIL1_32BIT" ".zbss.Shared.DEFAULT_RAM_ASIL1_32BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_VAR_FAST_32BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_ASIL1_VAR_FAST_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory near
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif



#elif defined (DEFAULT_START_SEC_VAR_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_UNSPECIFIED" ".bss.CPU0.Private.DEFAULT_RAM_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU1.Private.DEFAULT_RAM_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_UNSPECIFIED" ".bss.CPU1.Private.DEFAULT_RAM_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU2.Private.DEFAULT_RAM_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_UNSPECIFIED" ".bss.CPU2.Private.DEFAULT_RAM_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED)
   #undef      DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="Shared.DEFAULT_RAM_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_UNSPECIFIED" ".bss.Shared.DEFAULT_RAM_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL0_VAR_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL0_VAR_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_ASIL0_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_ASIL0_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_ASIL0_UNSPECIFIED" ".bss.CPU0.Private.DEFAULT_RAM_ASIL0_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL0_VAR_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL0_VAR_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL0_VAR_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL0_VAR_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU1.Private.DEFAULT_RAM_ASIL0_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_ASIL0_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_ASIL0_UNSPECIFIED" ".bss.CPU1.Private.DEFAULT_RAM_ASIL0_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL0_VAR_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL0_VAR_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL0_VAR_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL0_VAR_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU2.Private.DEFAULT_RAM_ASIL0_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_ASIL0_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_ASIL0_UNSPECIFIED" ".bss.CPU2.Private.DEFAULT_RAM_ASIL0_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL0_VAR_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL0_VAR_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL0_VAR_UNSPECIFIED_SHARED)
   #undef      DEFAULT_START_SEC_ASIL0_VAR_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="Shared.DEFAULT_RAM_ASIL0_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_ASIL0_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_ASIL0_UNSPECIFIED" ".bss.Shared.DEFAULT_RAM_ASIL0_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL0_VAR_UNSPECIFIED_SHARED)
   #undef      DEFAULT_STOP_SEC_ASIL0_VAR_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_VAR_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL1_VAR_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_ASIL1_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_ASIL1_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_ASIL1_UNSPECIFIED" ".bss.CPU0.Private.DEFAULT_RAM_ASIL1_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_VAR_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL1_VAR_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_VAR_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL1_VAR_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU1.Private.DEFAULT_RAM_ASIL1_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_ASIL1_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_ASIL1_UNSPECIFIED" ".bss.CPU1.Private.DEFAULT_RAM_ASIL1_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_VAR_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL1_VAR_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_VAR_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL1_VAR_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU2.Private.DEFAULT_RAM_ASIL1_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_ASIL1_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_ASIL1_UNSPECIFIED" ".bss.CPU2.Private.DEFAULT_RAM_ASIL1_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_VAR_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL1_VAR_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_VAR_UNSPECIFIED_SHARED)
   #undef      DEFAULT_START_SEC_ASIL1_VAR_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="Shared.DEFAULT_RAM_ASIL1_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_ASIL1_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_ASIL1_UNSPECIFIED" ".bss.Shared.DEFAULT_RAM_ASIL1_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_VAR_UNSPECIFIED_SHARED)
   #undef      DEFAULT_STOP_SEC_ASIL1_VAR_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="CPU0.Private.DEFAULT_RAM_FAST_8BIT"
   #pragma for_uninitialized_data_use_memory near
      #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.CPU0.Private.DEFAULT_RAM_FAST_8BIT" awBz 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.CPU0.Private.DEFAULT_RAM_FAST_8BIT" ".zbss.CPU0.Private.DEFAULT_RAM_FAST_8BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="CPU1.Private.DEFAULT_RAM_FAST_8BIT"
   #pragma for_uninitialized_data_use_memory near
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.CPU1.Private.DEFAULT_RAM_FAST_8BIT" awBz 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.CPU1.Private.DEFAULT_RAM_FAST_8BIT" ".zbss.CPU1.Private.DEFAULT_RAM_FAST_8BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="CPU2.Private.DEFAULT_RAM_FAST_8BIT"
   #pragma for_uninitialized_data_use_memory near
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.CPU2.Private.DEFAULT_RAM_FAST_8BIT" awBz 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.CPU2.Private.DEFAULT_RAM_FAST_8BIT" ".zbss.CPU2.Private.DEFAULT_RAM_FAST_8BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="Shared.DEFAULT_RAM_FAST_8BIT"
   #pragma for_uninitialized_data_use_memory near
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.Shared.DEFAULT_RAM_FAST_8BIT" awBz 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.Shared.DEFAULT_RAM_FAST_8BIT" ".zbss.Shared.DEFAULT_RAM_FAST_8BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="CPU0.Private.DEFAULT_RAM_FAST_16BIT"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.CPU0.Private.DEFAULT_RAM_FAST_16BIT" awBz 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.CPU0.Private.DEFAULT_RAM_FAST_16BIT" ".zbss.CPU0.Private.DEFAULT_RAM_FAST_16BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_16BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_16BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="CPU1.Private.DEFAULT_RAM_FAST_16BIT"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.CPU1.Private.DEFAULT_RAM_FAST_16BIT" awBz 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.CPU1.Private.DEFAULT_RAM_FAST_16BIT" ".zbss.CPU1.Private.DEFAULT_RAM_FAST_16BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_16BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_16BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_16BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_16BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="CPU2.Private.DEFAULT_RAM_FAST_16BIT"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.CPU2.Private.DEFAULT_RAM_FAST_16BIT" awBz 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.CPU2.Private.DEFAULT_RAM_FAST_16BIT" ".zbss.CPU2.Private.DEFAULT_RAM_FAST_16BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_16BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_16BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="Shared.DEFAULT_RAM_FAST_16BIT"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.Shared.DEFAULT_RAM_FAST_16BIT" awBz 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.Shared.DEFAULT_RAM_FAST_16BIT" ".zbss.Shared.DEFAULT_RAM_FAST_16BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="CPU0.Private.DEFAULT_RAM_FAST_32BIT"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.CPU0.Private.DEFAULT_RAM_FAST_32BIT" awBz 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.CPU0.Private.DEFAULT_RAM_FAST_32BIT" ".zbss.CPU0.Private.DEFAULT_RAM_FAST_32BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="CPU1.Private.DEFAULT_RAM_FAST_32BIT"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.CPU1.Private.DEFAULT_RAM_FAST_32BIT" awBz 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.CPU1.Private.DEFAULT_RAM_FAST_32BIT" ".zbss.CPU1.Private.DEFAULT_RAM_FAST_32BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="CPU2.Private.DEFAULT_RAM_FAST_32BIT"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.CPU2.Private.DEFAULT_RAM_FAST_32BIT" awBz 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.CPU2.Private.DEFAULT_RAM_FAST_32BIT" ".zbss.CPU2.Private.DEFAULT_RAM_FAST_32BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="Shared.DEFAULT_RAM_FAST_32BIT"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
//   #pragma section ".zbss.Shared.DEFAULT_RAM_FAST_32BIT" awBz 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.Shared.DEFAULT_RAM_FAST_32BIT" ".zbss.Shared.DEFAULT_RAM_FAST_32BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
//   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif

#elif defined (MCAL_TCLIB_START_SEC_VAR_NONZERO_INIT_32BIT)
   #undef      MCAL_TCLIB_START_SEC_VAR_NONZERO_INIT_32BIT
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="DEFAULT_RAM_32BIT_NONZERO_INIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.DEFAULT_RAM_32BIT_NONZERO_INIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.DEFAULT_RAM_NONZERO_32BIT" ".bss.DEFAULT_RAM_NONZERO_32BIT" RW
   #endif
   #endif
#elif defined (MCAL_TCLIB_STOP_SEC_VAR_NONZERO_INIT_32BIT)
   #undef      MCAL_TCLIB_STOP_SEC_VAR_NONZERO_INIT_32BIT
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif

#elif defined (DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="CPU0.Private.DEFAULT_RAM_FAST_UNSPECIFIED"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.CPU0.Private.DEFAULT_RAM_FAST_UNSPECIFIED" awBz 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.CPU0.Private.DEFAULT_RAM_FAST_UNSPECIFIED" ".zbss.CPU0.Private.DEFAULT_RAM_FAST_UNSPECIFIED" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="CPU1.Private.DEFAULT_RAM_FAST_UNSPECIFIED"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.CPU1.Private.DEFAULT_RAM_FAST_UNSPECIFIED" awBz 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.CPU1.Private.DEFAULT_RAM_FAST_UNSPECIFIED" ".zbss.CPU1.Private.DEFAULT_RAM_FAST_UNSPECIFIED" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="CPU2.Private.DEFAULT_RAM_FAST_UNSPECIFIED"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.CPU2.Private.DEFAULT_RAM_FAST_UNSPECIFIED" awBz 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.CPU2.Private.DEFAULT_RAM_FAST_UNSPECIFIED" ".zbss.CPU2.Private.DEFAULT_RAM_FAST_UNSPECIFIED" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED)
   #undef      DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="Shared.DEFAULT_RAM_FAST_UNSPECIFIED"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.Shared.DEFAULT_RAM_FAST_UNSPECIFIED" awBz 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.Shared.DEFAULT_RAM_FAST_UNSPECIFIED" ".zbss.Shared.DEFAULT_RAM_FAST_UNSPECIFIED" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT" ".bss.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT" ".bss.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT" ".bss.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="Shared.DEFAULT_RAM_POWER_ON_INIT_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_POWER_ON_INIT_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_POWER_ON_INIT_8BIT" ".bss.Shared.DEFAULT_RAM_POWER_ON_INIT_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT" ".bss.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT" ".bss.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT" ".bss.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="Shared.DEFAULT_RAM_POWER_ON_INIT_16BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_POWER_ON_INIT_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_POWER_ON_INIT_16BIT" ".bss.Shared.DEFAULT_RAM_POWER_ON_INIT_16BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT" ".bss.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT" ".bss.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT" ".bss.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="Shared.DEFAULT_RAM_POWER_ON_INIT_32BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_POWER_ON_INIT_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_POWER_ON_INIT_32BIT" ".bss.Shared.DEFAULT_RAM_POWER_ON_INIT_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" ".bss.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" ".bss.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" ".bss.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="Shared.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" ".bss.Shared.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CONST_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU0.Private.DEFAULT_CONST_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU0.Private.DEFAULT_CONST_8BIT" a 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU0.Private.DEFAULT_CONST_8BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CONST_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU1.Private.DEFAULT_CONST_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU1.Private.DEFAULT_CONST_8BIT" a 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU1.Private.DEFAULT_CONST_8BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CONST_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU2.Private.DEFAULT_CONST_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU2.Private.DEFAULT_CONST_8BIT" a 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU2.Private.DEFAULT_CONST_8BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CONST_8BIT_SHARED)
   #undef      DEFAULT_START_SEC_CONST_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="Shared.DEFAULT_CONST_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.Shared.DEFAULT_CONST_8BIT" a 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.Shared.DEFAULT_CONST_8BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_8BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_CONST_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL0_CONST_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL0_CONST_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU0.Private.DEFAULT_ASIL0_CONST_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU0.Private.DEFAULT_ASIL0_CONST_8BIT" a 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU0.Private.DEFAULT_ASIL0_CONST_8BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL0_CONST_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL0_CONST_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL0_CONST_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL0_CONST_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU1.Private.DEFAULT_ASIL0_CONST_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU1.Private.DEFAULT_ASIL0_CONST_8BIT" a 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU1.Private.DEFAULT_ASIL0_CONST_8BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL0_CONST_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL0_CONST_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL0_CONST_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL0_CONST_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU2.Private.DEFAULT_ASIL0_CONST_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU2.Private.DEFAULT_ASIL0_CONST_8BIT" a 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU2.Private.DEFAULT_ASIL0_CONST_8BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL0_CONST_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL0_CONST_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL0_CONST_8BIT_SHARED)
   #undef      DEFAULT_START_SEC_ASIL0_CONST_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="Shared.DEFAULT_ASIL0_CONST_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.Shared.DEFAULT_ASIL0_CONST_8BIT" a 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.Shared.DEFAULT_ASIL0_CONST_8BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL0_CONST_8BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_ASIL0_CONST_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_CONST_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL1_CONST_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU0.Private.DEFAULT_ASIL1_CONST_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU0.Private.DEFAULT_ASIL1_CONST_8BIT" a 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU0.Private.DEFAULT_ASIL1_CONST_8BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_CONST_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL1_CONST_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_CONST_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL1_CONST_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU1.Private.DEFAULT_ASIL1_CONST_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU1.Private.DEFAULT_ASIL1_CONST_8BIT" a 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU1.Private.DEFAULT_ASIL1_CONST_8BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_CONST_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL1_CONST_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_CONST_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL1_CONST_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU2.Private.DEFAULT_ASIL1_CONST_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU2.Private.DEFAULT_ASIL1_CONST_8BIT" a 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU2.Private.DEFAULT_ASIL1_CONST_8BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_CONST_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL1_CONST_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_CONST_8BIT_SHARED)
   #undef      DEFAULT_START_SEC_ASIL1_CONST_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="Shared.DEFAULT_ASIL1_CONST_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.Shared.DEFAULT_ASIL1_CONST_8BIT" a 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.Shared.DEFAULT_ASIL1_CONST_8BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_CONST_8BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_ASIL1_CONST_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CONST_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU0.Private.DEFAULT_CONST_16BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU0.Private.DEFAULT_CONST_16BIT" a 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU0.Private.DEFAULT_CONST_16BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CONST_16BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_16BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU1.Private.DEFAULT_CONST_16BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU1.Private.DEFAULT_CONST_16BIT" a 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU1.Private.DEFAULT_CONST_16BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_16BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_16BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CONST_16BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_16BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU2.Private.DEFAULT_CONST_16BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU2.Private.DEFAULT_CONST_16BIT" a 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU2.Private.DEFAULT_CONST_16BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_16BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_16BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CONST_16BIT_SHARED)
   #undef      DEFAULT_START_SEC_CONST_16BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="Shared.DEFAULT_CONST_16BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.Shared.DEFAULT_CONST_16BIT" a 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.Shared.DEFAULT_CONST_16BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_16BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_CONST_16BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CONST_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU0.Private.DEFAULT_CONST_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU0.Private.DEFAULT_CONST_32BIT" a 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU0.Private.DEFAULT_CONST_32BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CONST_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU1.Private.DEFAULT_CONST_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU1.Private.DEFAULT_CONST_32BIT" a 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU1.Private.DEFAULT_CONST_32BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CONST_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU2.Private.DEFAULT_CONST_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU2.Private.DEFAULT_CONST_32BIT" a 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU2.Private.DEFAULT_CONST_32BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CONST_32BIT_SHARED)
   #undef      DEFAULT_START_SEC_CONST_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="Shared.DEFAULT_CONST_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.Shared.DEFAULT_CONST_32BIT" a 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.Shared.DEFAULT_CONST_32BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_32BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_CONST_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CONST_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU0.Private.DEFAULT_CONST_FAR_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU0.Private.DEFAULT_CONST_FAR_UNSPECIFIED" a 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU0.Private.DEFAULT_CONST_FAR_UNSPECIFIED" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CONST_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU1.Private.DEFAULT_CONST_FAR_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU1.Private.DEFAULT_CONST_FAR_UNSPECIFIED" a 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU1.Private.DEFAULT_CONST_FAR_UNSPECIFIED" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CONST_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU2.Private.DEFAULT_CONST_FAR_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU2.Private.DEFAULT_CONST_FAR_UNSPECIFIED" a 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU2.Private.DEFAULT_CONST_FAR_UNSPECIFIED" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED)
   #undef      DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="Shared.DEFAULT_CONST_FAR_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.Shared.DEFAULT_CONST_FAR_UNSPECIFIED" a 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.Shared.DEFAULT_CONST_FAR_UNSPECIFIED" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED)
   #undef      DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif

/*****************************************************************************
**                                 EXTRAS                                   **
******************************************************************************/

#elif defined (LIN_17_ASCLIN_START_LOADABLECFG)
   #undef   LIN_17_ASCLIN_START_LOADABLECFG
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="Shared.LIN_LOADABLE_CHANCFG"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.Shared.LIN_LOADABLE_CHANCFG" a
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.Shared.LIN_LOADABLE_CHANCFG" far-absolute R
   #endif
   #endif
#elif defined (LIN_17_ASCLIN_STOP_LOADABLECFG)
   #undef   LIN_17_ASCLIN_STOP_LOADABLECFG
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif

#elif defined (DEFAULT_START_SEC_IVT_CODE)
   #undef      DEFAULT_START_SEC_IVT_CODE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code "inttab"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".inttab" ax 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".inttab" X
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_IVT_CODE)
   #undef      DEFAULT_STOP_SEC_IVT_CODE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE X
   #endif
   #endif

#elif defined (PWM_17_GTM_START_SEC_NOTIFICATION)
   #undef      PWM_17_GTM_START_SEC_NOTIFICATION
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code "PWM_NOTIFICATION"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.PWM_NOTIFICATION" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.PWM_NOTIFICATION" RX
   #endif
   #endif
#elif defined (PWM_17_GTM_STOP_SEC_NOTIFICATION)
   #undef      PWM_17_GTM_STOP_SEC_NOTIFICATION
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif

#elif defined (ICU_17_GTMCCU6_START_SEC_NOTIFICATION)
   #undef      ICU_17_GTMCCU6_START_SEC_NOTIFICATION
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code "ICU_NOTIFICATION"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.ICU_NOTIFICATION" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.ICU_NOTIFICATION" RX
   #endif
   #endif
#elif defined (ICU_17_GTMCCU6_STOP_SEC_NOTIFICATION)
   #undef      ICU_17_GTMCCU6_STOP_SEC_NOTIFICATION
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif

#elif defined (WDG_17_SCU_START_SEC_NOTIFICATION)
   #undef      WDG_17_SCU_START_SEC_NOTIFICATION
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code "WDG_NOTIFICATION"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.WDG_NOTIFICATION" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.WDG_NOTIFICATION" RX
   #endif
   #endif
#elif defined (WDG_17_SCU_STOP_SEC_NOTIFICATION)
   #undef      WDG_17_SCU_STOP_SEC_NOTIFICATION
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif

#elif defined (STM_START_SEC_NOTIFICATION)
   #undef      STM_START_SEC_NOTIFICATION
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code "STM_NOTIFICATION"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.STM_NOTIFICATION" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.STM_NOTIFICATION" RX
   #endif
   #endif
#elif defined (STM_STOP_SEC_NOTIFICATION)
   #undef      STM_STOP_SEC_NOTIFICATION
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif

#elif defined (GPT_START_SEC_NOTIFICATION)
   #undef      GPT_START_SEC_NOTIFICATION
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code "GPT_NOTIFICATION"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.GPT_NOTIFICATION" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.GPT_NOTIFICATION" RX
   #endif
   #endif
#elif defined (GPT_STOP_SEC_NOTIFICATION)
   #undef      GPT_STOP_SEC_NOTIFICATION
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif

/* ---The following sections attempt to locate FLS Write and Erase command-----
   ---Cycles in an order. It is essential to enforce the correct sequence------
   ---so that the FLS driver can perform as requird.-------------------------*/
#elif defined (FLS_17_PMU_START_SEC_SPL_CODE_WRITECMD_BEGIN_API)
   #undef     FLS_17_PMU_START_SEC_SPL_CODE_WRITECMD_BEGIN_API
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code "FLS_AC_WRITE_SOURCE"
   #pragma optimize R
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.FLS_AC_WRITE_SOURCE" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".FLS_AC_WRITE_SOURCE" far-absolute RX
   #endif
   #endif

#elif defined (FLS_17_PMU_STOP_SEC_SPL_CODE_WRITECMD_BEGIN_API)
   #undef     FLS_17_PMU_STOP_SEC_SPL_CODE_WRITECMD_BEGIN_API
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #pragma endoptimize
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif

#elif defined (FLS_17_PMU_START_SEC_SPL_CODE_ERASECMD_BEGIN_API)
   #undef     FLS_17_PMU_START_SEC_SPL_CODE_ERASECMD_BEGIN_API
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code "FLS_AC_ERASE_SOURCE"
   #pragma optimize R
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.FLS_AC_ERASE_SOURCE" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".FLS_AC_ERASE_SOURCE" far-absolute RX
   #endif
   #endif

#elif defined (FLS_17_PMU_STOP_SEC_SPL_CODE_ERASECMD_BEGIN_API)
   #undef     FLS_17_PMU_STOP_SEC_SPL_CODE_ERASECMD_BEGIN_API
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #pragma endoptimize
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif

#elif defined (FEE_START_JOBENDNOTIF)
   #undef   FEE_START_JOBENDNOTIF
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code "FEE_JOBENDNOTIF_CODE"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.FEE_JOBENDNOTIF_CODE" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".FEE_JOBENDNOTIF_CODE" RX
   #endif
   #endif
#elif defined (FEE_STOP_JOBENDNOTIF)
   #undef   FEE_STOP_JOBENDNOTIF
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif

#elif defined (FEE_START_JOBERRNOTIF)
   #undef   FEE_START_JOBERRNOTIF
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code "FEE_JOBERRNOTIF_CODE"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.FEE_JOBERRNOTIF_CODE" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".FEE_JOBERRNOTIF_CODE" RX
   #endif
   #endif
#elif defined (FEE_STOP_JOBERRNOTIF)
   #undef   FEE_STOP_JOBERRNOTIF
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif

#elif defined (FEE_START_ILLEGALNOTIF)
   #undef   FEE_START_ILLEGALNOTIF
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code "FEE_ILLEGALNOTIF_CODE"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.FEE_ILLEGALNOTIF_CODE" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".FEE_ILLEGALNOTIF_CODE" RX
   #endif
   #endif
#elif defined (FEE_STOP_ILLEGALNOTIF)
   #undef   FEE_STOP_ILLEGALNOTIF
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif


#elif defined (FLS_17_PMU_START_CONFIG)
   #undef      FLS_17_PMU_START_CONFIG
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="FLS_RESERVED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.FLS_RESERVED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".FLS_RESERVED" far-absolute RW
   #endif
   #endif
#elif defined (FLS_17_PMU_STOP_CONFIG)
   #undef      FLS_17_PMU_STOP_CONFIG
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif

#elif defined (ETH_17_ETHMAC_RES_START_SEC_VAR_FAST_8BIT)
   #undef      ETH_17_ETHMAC_RES_START_SEC_VAR_FAST_8BIT
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="ETH_RAM_FAST_8BIT"
   #pragma for_uninitialized_data_use_memory near
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.ETH_RAM_FAST_8BIT" awB 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".error" ".ETH_RAM_FAST_8BIT" RW
   #endif
   #endif
#elif defined (ETH_17_ETHMAC_RES_STOP_SEC_VAR_FAST_8BIT)
   #undef      ETH_17_ETHMAC_RES_STOP_SEC_VAR_FAST_8BIT
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif

#elif defined (ETH_17_ETHMAC_RES_START_SEC_VAR_FAST_32BIT)
   #undef      ETH_17_ETHMAC_RES_START_SEC_VAR_FAST_32BIT
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="ETH_RAM_FAST_32BIT"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.ETH_RAM_FAST_32BIT" awB 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".error" ".ETH_RAM_FAST_32BIT" RW
   #endif
   #endif
#elif defined (ETH_17_ETHMAC_RES_STOP_SEC_VAR_FAST_32BIT)
   #undef      ETH_17_ETHMAC_RES_STOP_SEC_VAR_FAST_32BIT
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif

 #elif defined (ADC_DMA_START_SEC_EMUXSCAN_BUFFER)
   #undef      ADC_DMA_START_SEC_EMUXSCAN_BUFFER
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="ADC_DMA_EMUXSCAN_RAM_16BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.ADC_DMA_EMUXSCAN_RAM_16BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".ADC_DMA_EMUXSCAN_RAM_16BIT" far-absolute RW
   #endif
   #endif
#elif defined (ADC_DMA_STOP_SEC_EMUXSCAN_BUFFER)
   #undef      ADC_DMA_STOP_SEC_EMUXSCAN_BUFFER
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif

#elif defined (FLSLOADER_START_SEC_RAMCODE)
   #undef      FLSLOADER_START_SEC_RAMCODE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code="FLSLOADERRAMCODE"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".FLSLOADERRAMCODE" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".FLSLOADERRAMCODE" far-absolute RX
   #endif
   #endif
#elif defined (FLSLOADER_STOP_SEC_RAMCODE)
   #undef      FLSLOADER_STOP_SEC_RAMCODE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif

#elif defined (BMD_HDR_START_SEC_BMI_HEADER)
   #undef      BMD_HDR_START_SEC_BMI_HEADER
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="BMD_HDR_CONST_FAR_UNSPECIFIED"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.BMD_HDR_CONST_FAR_UNSPECIFIED" a
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".BMD_HDR_CONST_FAR_UNSPECIFIED" far-absolute R
   #endif
   #endif
#elif defined (BMD_HDR_STOP_SEC_BMI_HEADER)
   #undef      BMD_HDR_STOP_SEC_BMI_HEADER
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif

#elif defined (SPI_START_SEC_VAR_FAST_32BIT)
   #undef      SPI_START_SEC_VAR_FAST_32BIT
   #pragma section DATA ".error" ".SPI_RAM_FAST_32BIT" RW
#elif defined (SPI_STOP_SEC_VAR_FAST_32BIT)
   #undef      SPI_STOP_SEC_VAR_FAST_32BIT
   #pragma section DATA RW

/* -------------------------------------------------------------------------- */
/* End of default section mapping                                             */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/* Begin alignment mapping                                                    */
/* -------------------------------------------------------------------------- */

#elif defined (DEFAULT_START_VAR_ALIGN_16_BIT)
   #undef      DEFAULT_START_VAR_ALIGN_16_BIT
   #pragma align 4
#elif defined (DEFAULT_STOP_VAR_ALIGN_16_BIT)
   #undef      DEFAULT_STOP_VAR_ALIGN_16_BIT
   #pragma align restore
/* -------------------------------------------------------------------------- */
/* End of alignment mapping                                                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/* Begin Packing                                                              */
/* -------------------------------------------------------------------------- */

#elif defined (DEFAULT_START_VAR_PACK_2)
   #undef      DEFAULT_START_VAR_PACK_2
   #pragma pack 2
#elif defined (DEFAULT_STOP_VAR_PACK_2)
   #undef      DEFAULT_STOP_VAR_PACK_2
   #pragma pack 0
/* -------------------------------------------------------------------------- */
/* End of Packing                                                             */
/* -------------------------------------------------------------------------- */

/*lint +idlen(60) +esym(961,92) */
/*lint +esym(960,19.6)   */  /* Allow usage of #undef */

#endif  /* START_WITH_IF */


/*************************************************************************************************************************************************
**                                                              End of file                                                                     **
*************************************************************************************************************************************************/




