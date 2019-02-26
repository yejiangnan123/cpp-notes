---------------------
互斥量列表
boost::mutex  独占
boost::shared_mutex  共享
boost::timed_mutex   允许超时，独占
boost::recursive_mutex  独占，递归（递归只能在同一线程）
boost::recursive_timed_mutex  递归，超时，独占
boost::unique_lock<T> 独占锁模板
boost::shared_lock<T> 共享所模板
---------------------
读写锁
typedefboost::shared_lock<boost::shared_mutex> readLock;   共享
typedef boost::unique_lock<boost::shared_mutex> writeLock; 独占
boost::shared_mutex rwmutex; 
--------------------- 
互斥锁：
typedef boost::unique_lock<boost::mutex> exclusiveLock; 独占
---------------------
智能锁
boost::mutex io_mutex;
boost::mutex::scoped_lock lock( io_mutex); 自动锁定，自动解锁
---------------------
条件变量
一个线程可以等待来自另一个线程的通知，从而知道一个特定条件已经成真。

boost::condition_variable cond;条件变量
boost::mutex mut; 互斥体
boost::unique_lock<boost::mutex> lock(mut); 独占
while(!data_ready)  条件
{
    cond.wait(lock);等待
}

{
    boost::lock_guard<boost::mutex> lock(mut);  上锁
    data_ready=true;
}   解锁
cond.notify_one();  唤醒一个等待的线程  cond.notify_all()

condition_variable要求传入的lock是boost::unique_lock<boost::mutex>
而condition_variable_any可以接受任意的锁、互斥量
condition_variable因此会有针对boost::unique_lock<boost::mutex>的优化
---------------------
共享内存
---------------------
信号量
文件锁
读写锁
智能锁
消息队列
