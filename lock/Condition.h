/**
 * @File Name: Condition.h
 * @brief : 条件变量
 * @Author : Fan6514 (lvfan6514@163.com)
 * @Version : 1.0
 * @Creat Date : 2022-11-20
 * 
 */
#ifndef CONDITION_H
#define CONDITION_H

#include <pthread.h>
#include "MutexLock.h"

class Condition {
public:
    explicit Condition(MutexLock& mutex);
    ~Condition();
    void wait();
    void notify();
    void notifyAll();
private:
    MutexLock& mutex_;
    pthread_cond_t pcond_;
};

#endif