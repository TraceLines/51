/*
 * @Author: king jing
 * @Date: 2022-11-01 15:32:15
 * @LastEditTime: 2022-11-01 17:10:02
 * @Description: Do not edit
 */
#include "reg52.h"
#include "rtx51tny.h"

sbit led0 = P2 ^ 0;
sbit led1 = P2 ^ 1;

/**
 * @description: 工程开始时首先创建一个任务0，不需要调用创建api，
 * 系统直接从0开始运行，在任务0里面我们一般放硬件初始化以及以及调
 * 用其他任务的创建声明，在最后调用删除API删除任务0，释放任务0资源
 * @return {*}
 */
void initial() _task_ 0
{
  os_create_task(1);
  os_create_task(2);
  // os_create_task(3);
  os_delete_task(0);
}

/**
 * @description: 任务都有必须有一个死循环，防止cpu彻底跳出任务体，引起系统崩溃，
 * @return {*}
 */
void task1(void) _task_ 1
{
  while (1)
  {
    led0 = !led0;
    os_wait2(K_IVL, 50);
  }
}

void task2(void) _task_ 2
{
  while (1)
  {
    led1 = !led1;
    os_wait2(K_IVL, 150);
  }
}
