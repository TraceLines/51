/*
 * @Author: king jing
 * @Date: 2022-10-25 20:27:16
 * @LastEditTime: 2022-10-25 21:42:18
 * @Description:简易电子密码锁
 */
#ifndef __BSP_LOCK_H__
#define __BSP_LOCK_H__

// 密码位保存
// unsigned char password[4] = {
//     0,
//     0,
//     0,
// };
// unsigned char inputLocal;
// the Declare of function
void locker_confirmSet();
void locker_cancelSet();
void locker_deleteSetBit();
void locker_checkPassword();
void locker_init();

void handleLockerStatus();

// unsigned char getsmgNum(unsigned char keyPosition);

#endif