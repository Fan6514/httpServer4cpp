/**
 * @File Name: CurrentThread.cpp
 * @brief : 当前线程状态
 * @Author : Fan6514 (lvfan6514@163.com)
 * @Version : 1.0
 * @Creat Date : 2022-11-20
 * 
 */

#include "CurrentThread.h"

namespace CurrentThread {
    int g_cachedTid;

    void cachedTid() {
        if (0 == g_cachedTid) {
            g_cachedTid = static_cast<pid_t>(syscall(SYS_gettid));
        }
    }
}