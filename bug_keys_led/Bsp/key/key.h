/*
 * @Author: king jing
 * @Date: 2022-10-18 17:07:06
 * @LastEditTime: 2022-10-21 14:42:02
 * @Description: Do not edit
 */
#ifndef __KEY_H
#define __KEY_H

#include "reg52.h"
#include "Public.h"

#define KEY_PORT P1
#define GPIO_KEY P1
void handleKeyPress();
void KeyDown();
u8 getsmgNum(u8 keyNum);
#endif