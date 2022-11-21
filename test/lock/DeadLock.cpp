#include <set>
#include "MutexLock.h"

class Request {
public:
    void process() {
        MutexLockGuard lock(mutex_);
        g_inventory.add(this);
    }

    ~Request() {
        MutexLockGuard lock(mutex_);
        sleep(1);
        g_inventory.remove(this);
    }

    void print() {
        MutexLockGuard lock(mutex_);
    }
private:
    MutexLock mutex_;
};

class Inventory {
public:
    void add(Request* req) {
        MutexLockGuard lock(mutex_);
        requests_.insert(req);
    }

    void remove(Request* req) {
        MutexLockGuard lock(mutex_);
        requests_.erase(req);
    }

    void printAll() const {
        MutexLockGuard lock(mutex_);
        sleep(1);
        for (std::set<Request*>::const_iterator it = requests_.begin();
            it != requests_.end(); ++it)
        {
            (*it)->print();
        }
        printf("Inventory::printAll() unlocked\n");
    }
private:
    MutexLock mutex_;
    std::set<Request*> requests_;
};

Inventory g_inventory;

int main()
{

}