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
**  $FILENAME   : can_net_com.h $                                                                                                               **
**                                                                                                                                              **
**  $CC VERSION :                                                              			                                                        **
**                                                                                                                                              **
**  $DATE       : 2020-04-25 $                                                                                                                  **
**                                                                                                                                              **
**  AUTHOR      : SAIC - W.JJ -Engineering                                                                                                      **
**                                                                                                                                              **
**  VENDOR      : SAIC Technologies                                                                                                             **
**                                                                                                                                              **
**  DESCRIPTION : This file contains                                                                                                            **
**                - The interface between CAN_app and mentor lib.                                                                               **
**                                                                                                                                              **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                                                                                        **
**                                                                                                                                              **
*************************************************************************************************************************************************/

/******************************************************************************
**                                                                           **
**  ChangeRecords:                                                           **
**                                                                           **
**  [20200916]      ADD extra tx msg 21-3A for uss                           **
**                  								                         **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Changes need to be recorded             **
**                                                                           **
**                                                                           **
**                                                                           **
******************************************************************************/

#ifndef _CAN_NET_COM_CAN3_H_
#define _CAN_NET_COM_CAN3_H_
typedef unsigned char uint8_t;
/*************************************************************************************************************************************************
**                                                              Includes                                                                        **
*************************************************************************************************************************************************/
// #include "reuse.h"

/*************************************************************************************************************************************************
**                                                             CAN0_secCAN                                                                     **
*************************************************************************************************************************************************/
typedef struct SECCAN_123_DATA {
    uint8_t u8_CAN_123_Rx_data[8];
} SecCan_123_data;

typedef struct SECCAN_124_DATA {
    uint8_t u8_CAN_124_Rx_data[8];
} SecCan_124_data;

typedef struct SECCAN_125_DATA {
    uint8_t u8_CAN_125_Rx_data[8];
} SecCan_125_data;

typedef struct SECCAN_126_DATA {
    uint8_t u8_CAN_126_Rx_data[8];
} SecCan_126_data;

typedef struct SECCAN_127_DATA {
    uint8_t u8_CAN_127_Rx_data[8];
} SecCan_127_data;

typedef struct SECCAN_122_DATA {
    uint8_t u8_CAN_122_Rx_data[8];
} SecCan_122_data;

typedef struct SECCAN_062_DATA {
    uint8_t u8_CAN_062_Rx_data[8];
} SecCan_062_data;

typedef struct SECCAN_063_DATA {
    uint8_t u8_CAN_063_Rx_data[8];
} SecCan_063_data;

typedef struct SECCAN_064_DATA {
    uint8_t u8_CAN_064_Rx_data[8];
} SecCan_064_data;

typedef struct SECCAN_065_DATA {
    uint8_t u8_CAN_065_Rx_data[8];
} SecCan_065_data;

typedef struct SECCAN_011_DATA {
    uint8_t u8_CAN_011_Tx_data[8];
} SecCan_011_data;

typedef struct SECCAN_012_DATA {
    uint8_t u8_CAN_012_Tx_data[8];
} SecCan_012_data;

typedef struct SECCAN_013_DATA {
    uint8_t u8_CAN_013_Tx_data[8];
} SecCan_013_data;

typedef struct SECCAN_014_DATA {
    uint8_t u8_CAN_014_Tx_data[8];
} SecCan_014_data;

typedef struct SECCAN_015_DATA {
    uint8_t u8_CAN_015_Tx_data[8];
} SecCan_015_data;

typedef struct SECCAN_016_DATA {
    uint8_t u8_CAN_016_Tx_data[8];
} SecCan_016_data;

typedef struct SECCAN_017_DATA {
    uint8_t u8_CAN_017_Tx_data[8];
} SecCan_017_data;

typedef struct SECCAN_018_DATA {
    uint8_t u8_CAN_018_Tx_data[8];
} SecCan_018_data;

typedef struct SECCAN_019_DATA {
    uint8_t u8_CAN_019_Tx_data[8];
} SecCan_019_data;

typedef struct SECCAN_01A_DATA {
    uint8_t u8_CAN_01A_Tx_data[8];
} SecCan_01A_data;

/* ADD extra 21-3A for uss */
#if 1
typedef struct SECCAN_021_DATA {
    uint8_t u8_CAN_021_Tx_data[8];
} SecCan_021_data;

typedef struct SECCAN_022_DATA {
    uint8_t u8_CAN_022_Tx_data[8];
} SecCan_022_data;

typedef struct SECCAN_023_DATA {
    uint8_t u8_CAN_023_Tx_data[8];
} SecCan_023_data;

typedef struct SECCAN_024_DATA {
    uint8_t u8_CAN_024_Tx_data[8];
} SecCan_024_data;

typedef struct SECCAN_025_DATA {
    uint8_t u8_CAN_025_Tx_data[8];
} SecCan_025_data;

typedef struct SECCAN_026_DATA {
    uint8_t u8_CAN_026_Tx_data[8];
} SecCan_026_data;

typedef struct SECCAN_027_DATA {
    uint8_t u8_CAN_027_Tx_data[8];
} SecCan_027_data;

typedef struct SECCAN_028_DATA {
    uint8_t u8_CAN_028_Tx_data[8];
} SecCan_028_data;

typedef struct SECCAN_029_DATA {
    uint8_t u8_CAN_029_Tx_data[8];
} SecCan_029_data;

typedef struct SECCAN_02A_DATA {
    uint8_t u8_CAN_02A_Tx_data[8];
} SecCan_02A_data;

typedef struct SECCAN_031_DATA {
    uint8_t u8_CAN_031_Tx_data[8];
} SecCan_031_data;

typedef struct SECCAN_032_DATA {
    uint8_t u8_CAN_032_Tx_data[8];
} SecCan_032_data;

typedef struct SECCAN_033_DATA {
    uint8_t u8_CAN_033_Tx_data[8];
} SecCan_033_data;

typedef struct SECCAN_034_DATA {
    uint8_t u8_CAN_034_Tx_data[8];
} SecCan_034_data;

typedef struct SECCAN_035_DATA {
    uint8_t u8_CAN_035_Tx_data[8];
} SecCan_035_data;

typedef struct SECCAN_036_DATA {
    uint8_t u8_CAN_036_Tx_data[8];
} SecCan_036_data;

typedef struct SECCAN_037_DATA {
    uint8_t u8_CAN_037_Tx_data[8];
} SecCan_037_data;

typedef struct SECCAN_038_DATA {
    uint8_t u8_CAN_038_Tx_data[8];
} SecCan_038_data;

typedef struct SECCAN_039_DATA {
    uint8_t u8_CAN_039_Tx_data[8];
} SecCan_039_data;

typedef struct SECCAN_03A_DATA {
    uint8_t u8_CAN_03A_Tx_data[8];
} SecCan_03A_data;
#endif
/*************************************************************************************************************************************************
**                                                              Global Variable Declarations                                                    **
**                                                              INfo  CAN                                                                       **
*************************************************************************************************************************************************/
extern SecCan_122_data gSec_122_data;
extern SecCan_123_data gSec_123_data;
extern SecCan_124_data gSec_124_data;
extern SecCan_125_data gSec_125_data;
extern SecCan_126_data gSec_126_data;
extern SecCan_127_data gSec_127_data;
extern SecCan_062_data gSec_062_data;
extern SecCan_063_data gSec_063_data;
extern SecCan_064_data gSec_064_data;
extern SecCan_065_data gSec_065_data;

extern SecCan_011_data gSec_011_data;
extern SecCan_012_data gSec_012_data;
extern SecCan_013_data gSec_013_data;
extern SecCan_014_data gSec_014_data;
extern SecCan_015_data gSec_015_data;
extern SecCan_016_data gSec_016_data;
extern SecCan_017_data gSec_017_data;
extern SecCan_018_data gSec_018_data;
extern SecCan_019_data gSec_019_data;
extern SecCan_01A_data gSec_01A_data;

/* ADD extra 21-3A for uss */
#if 1
extern SecCan_021_data gSec_021_data;
extern SecCan_022_data gSec_022_data;
extern SecCan_023_data gSec_023_data;
extern SecCan_024_data gSec_024_data;
extern SecCan_025_data gSec_025_data;
extern SecCan_026_data gSec_026_data;
extern SecCan_027_data gSec_027_data;
extern SecCan_028_data gSec_028_data;
extern SecCan_029_data gSec_029_data;
extern SecCan_02A_data gSec_02A_data;

extern SecCan_031_data gSec_031_data;
extern SecCan_032_data gSec_032_data;
extern SecCan_033_data gSec_033_data;
extern SecCan_034_data gSec_034_data;
extern SecCan_035_data gSec_035_data;
extern SecCan_036_data gSec_036_data;
extern SecCan_037_data gSec_037_data;
extern SecCan_038_data gSec_038_data;
extern SecCan_039_data gSec_039_data;
extern SecCan_03A_data gSec_03A_data;

#endif

extern void CAN_net_Rx_CAN3_Update(void);
extern void CAN_net_Tx_CAN3_Update(void);

/*************************************************************************************************************************************************
**                                                              End of file                                                                     **
*************************************************************************************************************************************************/
#endif /* 03_BSW_BIOS_BIOS_CAN_COMIF_CAN_NET_COM_H_ */
