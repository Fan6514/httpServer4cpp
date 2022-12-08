/**
 * @File Name: CountDownLatch.cpp
 * @brief : 倒计时
 * @Author : Fan6514 (lvfan6514@163.com)
 * @Version : 1.0
 * @Creat Date : 2022-11-24
 * 
 */
#include "CountDownLatch.h"

CountDownLatch::CountDownLatch(int count) : mutex_(), condition_(mutex_), count_(count) {
}

void CountDownLatch::wait() {
    MutexLockGuard lock(mutex_);
    while (count_ > 0) {
        condition_.wait();
    }
}

void CountDownLatch::countDown() {
    MutexLockGuard lock(mutex_);
    --count_;
    if (count_ == 0) {
        condition_.notifyAll();
    }
}