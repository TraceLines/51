/*
 * @Author: king jing
 * @Date: 2022-10-31 17:36:54
 * @LastEditTime: 2022-11-01 14:03:01
 * @Description: Do not edit
 */
#ifndef __BSP_IRED_H__
#define __BSP_IRED_H__

void iRed_init();
unsigned char IR_getDataFlag();
unsigned char IR_getAddress();
unsigned char IR_getRepeat();
unsigned char IR_getCommand();
#endif