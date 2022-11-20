/**
 * @File Name: MutexLock.h
 * @brief : 互斥锁类头文件
 * @Author : Fan6514 (lvfan6514@163.com)
 * @Version : 1.0
 * @Creat Date : 2022-11-19
 * 
 */
#ifndef MUTEX_LOCK_H
#define MUTEX_LOCK_H

#include <pthread.h>
#include <sys/types.h>

/** @brief 防止遗漏变量名 */
#define MutexLockGuard(x) static_assert(false, "missing mutex guard var name")

class MutexLock {
public:
    MutexLock();
    ~MutexLock();

    bool isLockedByThisThread();
    void assertLocked();

    /* 以下接口严禁用户调用 */
    void lock();
    void unlock();
    pthread_mutex_t* getPthreadMutex();
private:
    pthread_mutex_t mutex_;
    pid_t           holder_;
};

class MutexLockGuard {
public:
    explicit MutexLockGuard(MutexLock& mutex);
    ~MutexLockGuard();
private:
    MutexLock& mutex_;
};

#endif