-----------------------------------------------------
std::mutex   锁 
http://www.cplusplus.com/reference/mutex/
-----------------------------------------------------
mutex  这是一个类，互斥锁
recursive_mutex   这是一个递归互斥锁，同一个线程可以多次上锁不会死锁
timed_mutex   有时间限制的互斥锁
recursive_timed_mutex  这是一个可递归的，可以设置超时的互斥锁
lock_guard   这是一个模板类，用于管理互斥锁，定义的时候等于上锁，销毁时等解锁，这是一个独占的智能锁，性能更高
unique_lock   这是一个只能锁，独占，互斥，性能略低，但灵活性更好
call_once   执行一次呼叫
-----------------------------------------------------
