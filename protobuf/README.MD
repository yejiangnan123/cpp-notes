# protobuf
* [原文博客](https://www.cnblogs.com/luoxn28/p/5303517.html)
# protobuf安装
* 1、下载protobuf代码 google/protobuf[源码](https://github.com/protocolbuffers/protobuf)
```
  git clone https://github.com/protocolbuffers/protobuf.git
```
* 2、安装protobuf
```
  tar -xvf protobuf
  cd protobuf
  ./configure --prefix=/usr/local/protobuf
  make
  make check
  make install
  至此安装完成^_^，下面是配置：
  如果不想生成动态protobuf库，则用命令./configure --disable-shared。
```
* (1) vim /etc/profile，添加
```
  export PATH=$PATH:/usr/local/protobuf/bin/
  export PKG_CONFIG_PATH=/usr/local/protobuf/lib/pkgconfig/
  保存执行，source /etc/profile。同时在~/.profile中添加上面两行代码，否则会出现登录用户找不到protoc命令。
```
* (2) 配置动态链接库
```
  vim /etc/ld.so.conf，在文件中添加/usr/local/protobuf/lib（注意: 在新行处添加），然后执行命令: ldconfig
```
* 编译
```
  protoc --cpp_out=./ addressbook.proto
  g++ addressbook.pb.cc test1.cpp -o write `pkg-config --cflags --libs protobuf`
```
# 举例
```
root@ubuntu:~/protobuf-test/example1# cat addressbook.proto 

syntax = "proto3";   // 这一行前面必须空一行
package tutorial;   //包名
message Person {
  string name = 1; //
  int32 id = 2;
  string email= 3;  //optional 默认
  enum PhoneType {   //枚举
    MOBILE = 0;
    HOME = 1;
    WORK = 2;
  }
  message PhoneNumber {
    string number = 1;
    PhoneType type = 2;  
  }
  PhoneNumber phone= 4;
} 
```
```
root@ubuntu:~/protobuf-test/example1# cat test1.cpp 
#include "addressbook.pb.h"
#include <stdio.h>
#include <assert.h>
#include <iostream>  //iostream
using namespace std;
using namespace tutorial;//导入包名，类似命名空间
int main() {
	char buf[1024];
	int buf_len = 0;
	Person  msg1;
	msg1.set_id(1001);
	msg1.set_name("name");
	msg1.set_email("email");
	msg1.SerializeToArray(buf, sizeof(buf));
	buf_len = msg1.ByteSize();
	Person msg2;
	msg2.ParseFromArray(buf, buf_len);
	assert(msg1.id() == msg2.id());
	cout << msg1.id() << " " << msg1.name() << " " << msg1.email() << "\n";
	cout << msg1.id() << " " << msg1.name() << " " << msg1.email() << "\n";
	return 0;
}
```
# 语法
* 数据类型
* 默认值
* 枚举
