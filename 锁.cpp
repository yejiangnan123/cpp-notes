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
https://www.jianshu.com/p/56efa9d1500a
boost::interprocess::shared_memory_object：普通共享内存对象   共享字节数据
boost::interprocess::mamaged_shared_memory：自动托管的共享内存对象，共享对象数据
boost::interprocess::mapped_region：映射共享内存到当前进程地址空间的对象
boost::interprocess::allocator：共享内存分配器
boost::interprocess::named_mutex：命名互斥对象，存储在操作系统
boost::interprocess::interprocess_mutex：匿名互拆对象，存储在共享内存
boost::interprocess::named_condition：命名条件变量
boost::interprocess::interprocess_condition：匿名条件变量
boost::interprocess::named_semaphore：命名信号量
boost::interprocess::interprocess_semaphore：匿名信号量
boost::interprocess::file_lock：文件锁
---------------------
信号量
主要特点是计数
boost::interprocess::interprocess_semaphore m_semaphore(0);  初始化
post()一次,信号量加1 
wait(),try_wait() ,timed_wait(const boost::posix_time::ptime&abs_time). 信号量减1  
---------------------
消息队列
boost::interprocess::message_queue   消息队列，有名字
https://www.cnblogs.com/ltm5180/p/4334522.html
只是内存拷贝，数据必须序列化，不能直接发送对象
---------------------
