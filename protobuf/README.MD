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
  string name = 1; // 1表示id，唯一标识一个字段
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
```
required 必要字段，序列化之前必须赋值
optional和repeated 一般用来定义数组，可以不赋值，默认为optional
enum  枚举
```
* 默认值
```
optional int32 result_per_page = 3 [default = 10]
```
* 枚举
* 类型对照表
```
.proto Type  C++ Type
double       double	 
float        float	
int32        int32	
int64        int64	 
uint32       uint32	 
uint64       uint64	 
sint32       int32	 
sint64       int64	 
fixed32      uint32	 
fixed64	     uint64	 
sfixed32     int32
sfixed64     int64
bool	     bool
string	     string
bytes	     string
```
* 配置Option
* 命令行编译工具
```
protoc --proto_path=IMPORT_PATH --cpp_out=DST_DIR --java_out=DST_DIR --python_out=DST_DIR path/to/file.proto
这里将给出上述命令的参数解释。
1. protoc为Protocol Buffer提供的命令行编译工具。
2. --proto_path等同于-I选项，主要用于指定待编译的.proto消息定义文件所在的目录，该选项可以被同时指定多个。
3. --cpp_out选项表示生成C++代码，--java_out表示生成Java代码，--python_out则表示生成Python代码，其后的目录为生成后的代码所存放的目录。
4. path/to/file.proto表示待编译的消息定义文件。
```


