# 互斥锁

互斥锁是使用最多的同步原语，任何时刻最多只能有一个线程在 mutex 划出的临界区活动。

- 使用 RAII 封装 mutex 创建、销毁、加锁和解锁操作
- 使用非递归 mutex（不能重复加锁）
- 不手动调用 lock() 和 unlock() 函数，由 Guard 对象的构造和析构函数负责
