/**
 * @File Name: Condition.cpp
 * @brief : 条件变量
 * @Author : Fan6514 (lvfan6514@163.com)
 * @Version : 1.0
 * @Creat Date : 2022-11-20
 * 
 */

#include "Condition.h"

/**
 * @brief : Construct a new Condition:: Condition object
 * @param  mutex            互斥锁
 */
Condition::Condition(MutexLock& mutex) : mutex_(mutex) {
    pthread_cond_init(&pcond_, NULL);
}

/**
 * @brief : Destroy the Condition:: Condition object
 */
Condition::~Condition() {
    pthread_cond_destroy(&pcond_);
}

/**
 * @brief : 等待条件
 */
void Condition::wait() {
    pthread_cond_wait(&pcond_, mutex_.getPthreadMutex());
}

/**
 * @brief : signal通知
 */
void Condition::notify() {
    pthread_cond_signal(&pcond_);
}

/**
 * @brief : broadcast通知
 */
void Condition::notifyAll() {
    pthread_cond_broadcast(&pcond_);
}