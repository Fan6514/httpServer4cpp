/**
 * @File Name: CountDownLatch.h
 * @brief : 倒计时
 * @Author : Fan6514 (lvfan6514@163.com)
 * @Version : 1.0
 * @Creat Date : 2022-11-24
 * @Note : 倒计时是一种常用的同步手段，主要用途
 *          1. 主线程发起多个子线程，等待子线程完成一定的任务后，主线程才开始执行。
 *              通常用于主线程等待多个子线程完成初始化
 *          2. 主线程发起多个子线程，子线程都等待主线程完成任务，然后通知子线程开始执行。
 *              通常用于多个子线程等待主线程发出“起跑”命令
 *
 */
#ifndef COUNT_DOWN_LATCH_H
#define COUNT_DOWN_LATCH_H

#include "MutexLock.h"
#include "Condition.h"

class CountDownLatch {
public:
    CountDownLatch(int count);  /** @brief 设置计数器值 */
    void wait();                /** @brief 等待计数器变成0 */
    void countDown();           /** @brief 计数减一 */
private:
    MutexLock mutex_;
    Condition condition_;
    int count_;
};

#endif