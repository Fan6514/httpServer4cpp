/**
 * @File Name: CurrentThread.h
 * @brief : 当前线程状态
 * @Author : Fan6514 (lvfan6514@163.com)
 * @Version : 1.0
 * @Creat Date : 2022-11-20
 * 
 */
#ifndef CURRENT_THREAD_H
#define CURRENT_THREAD_H

#include <pthread.h>
#include <sys/types.h>
#include "Util.h"

#define gettid()\
do {\
    syscall(SYS_gettid);\
} while(0)

namespace CurrentThread {
    extern int g_cachedTid;
    void cacheTid();

    inline int tid() {
        if (unlikely(g_cachedTid == 0)) {
            cacheTid();
        }
        return g_cachedTid;
    }
}

#endif
