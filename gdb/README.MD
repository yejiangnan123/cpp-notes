# gdb配置
```
cmake 配置文件里添加：
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
```
# 运行
```
gdb test
```
# gdb命令
## 查看代码
```
list  l  显示多行源代码
```
## 断点
```
break b  设置断点,程序运行到断点的位置会停下来
delete breakpoints 1 表示删除1号断点
clear n  表示清除第n行的断点
disable/enable n   表示使得编号为n的断点暂时失效或有效
info breakpoints 
```
## 变量 打印
```
display  disp   跟踪查看某个变量,每次停下来都显示它的值
print p  打印内部变量值
whatis  变量名  查看变量的类型
set var name=v  设置变量的值
watch  监视变量值的变化
```
## 控制
```
run   r  开始运行程序
step  s  执行下一条语句,如果该语句为函数调用,则进入函数执行其中的第一条语句
next  n  执行下一条语句,如果该语句为函数调用,不会进入函数内部执行(即不会一步步地调试函数内部语句)
continue  c  继续程序的运行,直到遇到下一个断点
start  st  开始执行程序,在main函数的第一条语句前面停下来
kill  k  终止正在调试的程序
quit  q  退出GDB环境
finish  结束调试
```
## 堆栈信息
```
file   装入需要调试的程序
backtrace  bt  产看函数调用信息(堆栈)
frame  f  查看栈帧
```
## 多线程
```
info threads	显示当前可调试的所有线程，每个线程会有一个GDB为其分配的ID，后面操作线程的时候会用到这个ID。 前面有*的是当前调试的线程
thread ID(1,2,3…)	切换当前调试的线程为指定ID的线程
break thread_test.c:123 thread all（例：在相应函数的位置设置断点break pthread_run1）	在所有线程中相应的行上设置断点
thread apply ID1 ID2 command	让一个或者多个线程执行GDB命令command
thread apply all command	让所有被调试线程执行GDB命令command
set scheduler-locking 选项 command	设置线程是以什么方式来执行命令
set scheduler-locking off	不锁定任何线程，也就是所有线程都执行，这是默认值
set scheduler-locking on	只有当前被调试程序会执行
set scheduler-locking on step	在单步的时候，除了next过一个函数的情况(熟悉情况的人可能知道，这其实是一个设置断点然后continue的行为)以外，只有当前线程会执行
```
