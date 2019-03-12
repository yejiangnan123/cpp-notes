---------------------------------------------------------------
std::string
http://www.cplusplus.com/reference/string/
---------------------------------------------------------------
模板类
basic_string  通用字符串类
char_traits   性格特征类

实例化类
string     typedef basic_string<char> string;
u16string  typedef basic_string<char16_t> u16string;
u32string  typedef basic_string<char32_t> u32string;
wstring    typedef basic_string<wchar_t> wstring;

字符串转换类型函数
支持 int,long int,long long,unsigend long long,float,double,long double
stoi  Convert string to integer (function template )
stol  Convert string to long int (function template )
stoul Convert string to unsigned integer (function template )
stoll Convert string to long long (function template )
stoull Convert string to unsigned long long (function template )
stof Convert string to float (function template )
stod Convert string to double (function template )
stold Convert string to long double (function template )

其他类型转字符串
to_string Convert numerical value to string (function )
to_wstring Convert numerical value to wide string (function )
 
迭代器，访问  
begin Iterator to beginning (function template )
end Iterator to end (function template )
---------------------------------------------------------------
string 实例   http://www.cplusplus.com/reference/string/string/
(constructor)  构造函数
(destructor)   析构函数
operator=      字符串赋值

Iterators:   迭代器
begin end rbegin rend cbegin cend crbegin crend 

Capacity: 容量
size
length
max_size
resize   重新设置大小
capacity
reserve  重新设置空间
clear
empty
shrink_to_fit 缩减字符串空间，把没用的空间释放掉

Element access: 元素访问
operator[]
at
back 最后一个字符
front 第一个字符

Modifiers: 修饰符
operator+=  追加
append      添加
push_back   添加
assign      分配
insert      插入
erase       删除
replace     替换
swap        交换
pop_back    删除最后一个字符

String operations:字符串操作
c_str
data
get_allocator
copy
find
rfind               反向查找
find_first_of       查找第一个
find_last_of        查找最后一个
find_first_not_of   第一个不匹配
find_last_not_of    最后一个不匹配
substr
compare             比较

Member constants：成员常数
npos

Non-member function overloads：重载的非成员函数
operator+    连接字符串
relational operators  其他操作符重载
swap   交换
operator>>   从流获取
operator<<   插入流
getline   从流获取行
-----------------------------------------------------------
