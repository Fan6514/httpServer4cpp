/**
 * @File Name: MutexLock.cpp
 * @brief : 互斥锁类实现
 * @Author : Fan6514 (lvfan6514@163.com)
 * @Version : 1.0
 * @Creat Date : 2022-11-19
 * 
 */
#include <cassert>
#include "MutexLock.h"
#include "CurrentThread.h"

/**
 * @brief : Construct a new Mutex Lock:: Mutex Lock object
 */
MutexLock::MutexLock() : holder_(0) {
    pthread_mutex_init(&mutex_, NULL);
}

/**
 * @brief : Destroy the Mutex Lock:: Mutex Lock object
 */
MutexLock::~MutexLock() {
    assert(holder_ == 0);
    pthread_mutex_destroy(&mutex_);
}

/**
 * @brief : 当前线程是否已经获取锁
 * @return true             已经获取锁
 * @return false            没有获取锁
 */
bool MutexLock::isLockedByThisThread() {
    return holder_ == CurrentThread::tid();
}

/**
 * @brief : 锁断言
 */
void MutexLock::assertLocked() {
    assert(isLockedByThisThread());
}

/**
 * @brief : 加锁，仅供 MutexLockGuard 调用
 */
void MutexLock::lock() {
    pthread_mutex_lock(&mutex_);
    holder_ = CurrentThread::tid();
}

/**
 * @brief : 解锁，仅供 MutexLockGuard 调用
 */
void MutexLock::unlock() {
    holder_ = 0;
    pthread_mutex_unlock(&mutex_);
}

/**
 * @brief : 获取线程互斥锁
 * @return pthread_mutex_t* 互斥锁
 */
pthread_mutex_t* MutexLock::getPthreadMutex() {
    return &mutex_;
}

/**
 * @brief : Construct a new Mutex Lock Guard:: Mutex Lock Guard object
 * @param  mutex            MutexLock
 */
MutexLockGuard::MutexLockGuard(MutexLock& mutex) :mutex_(mutex) {
    mutex_.lock();
}

MutexLockGuard::~MutexLockGuard() {
    mutex_.unlock();
}