std::fstream 
http://blog.sina.com.cn/s/blog_6bdc48d90101j66k.html

流分类
fstream，ifstream，ofstream，iofstream
ifstream file2("c:\\pdos.def");//以输入方式打开文件，输入方式：读文档
ofstream file3("c:\\x.123");//以输出方式打开文件 ，输出方式：写文档，向文档输出内容
iostream是对屏幕上输入输出

打开方式，打开关闭，打开属性
fs.close();
if (fs.is_open())
fs.open ("test.txt", std::fstream::in | std::fstream::out | std::fstream::app);
ios::app // 从后面添加
ios::ate // 打开并找到文件尾
ios::binary // 二进制模式 I/O (与文本模式相对)
ios::in // 只读打开
ios::out // 写打开
ios::trunc // 将文件截为 0 长度

格式化输出
dec 格式化为十进制数值数据 输入和输出 
endl 输出一个换行符并刷新此流 输出 
ends 输出一个空字符 输出 
hex 格式化为十六进制数值数据 输入和输出 
oct 格式化为八进制数值数据 输入和输出 
setpxecision(int p) 设置浮点数的精度位数 输出 

读写
std::filebuf* inbuf  = src.rdbuf(); 读
char c = inbuf->sbumpc();  读
while (c != EOF)  检查结尾
outbuf->sputc (c);  写
foo.swap(bar);   交换
swap(foo,bar);   交换
file1.put('c');写
file2.get(x);读 
int get();读，到达文件尾，返回EOF
ifstream &get(char *buf,int num,char delim='\n')；读
使用getline(fstream &fs,string & str) 读
read(unsigned char *buf,int num);  读
write(const unsigned char *buf,int num);  写
int eof(); 文件到达末尾
flush（）  同步缓存

文件位置
seekg()  是设置读位置
seekp()  是设置写位置。
ios::beg：　　文件开头
ios::cur：　　文件当前位置
ios::end：　　文件结尾
