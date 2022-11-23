/**
 * @File Name: DeadLock.cpp
 * @brief : 死锁测试函数
 * @Author : Fan6514 (lvfan6514@163.com)
 * @Version : 1.0
 * @Creat Date : 2022-11-23
 * 
 */
#include <unistd.h>
#include <iostream>
#include <thread>
#include "MutexLock.h"
#include "DeadLock.h"

Inventory g_inventory;

Request::~Request() {
    MutexLockGuard lock(mutex_);
    sleep(1);
    g_inventory.remove(this);
}

void Request::process() {
    MutexLockGuard lock(mutex_);
    g_inventory.add(this);
}

void Request::print() {
    MutexLockGuard lock(mutex_);
}

void Inventory::add(Request* req) {
    MutexLockGuard lock(mutex_);
    requests_.insert(req);
}

void Inventory::remove(Request* req) {
    MutexLockGuard lock(mutex_);
    requests_.erase(req);
}

void Inventory::printAll() {
    MutexLockGuard lock(mutex_);
    sleep(1);
    for (std::set<Request*>::const_iterator it = requests_.begin();
        it != requests_.end(); ++it)
    {
        (*it)->print();
    }
    std::cout << "Inventory::printAll() unlocked\n";
}

void threadFunc()
{
    Request* req = new Request;
    req->process();
    delete req;
}

int main()
{
    std::thread mythread(threadFunc);
    usleep(500*1000);
    g_inventory.printAll();
    mythread.join();
}