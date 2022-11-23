#ifndef DEAD_LOCK_H
#define DEAD_LOCK_H

#include <set>

class Request {
public:
    ~Request();

    void process();
    void print();
private:
    MutexLock mutex_;
};

class Inventory {
public:
    void add(Request* req);
    void remove(Request* req);
    void printAll();
private:
    MutexLock mutex_;
    std::set<Request*> requests_;
};

#endif