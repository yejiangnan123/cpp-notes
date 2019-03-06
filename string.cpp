-------------------------------------------------------------
std::string
https://www.cnblogs.com/c1299401227/p/5370685.html
函数名	描述
begin	得到指向字符串开头的Iterator
end	得到指向字符串结尾的Iterator
rbegin	得到指向反向字符串开头的Iterator
rend	得到指向反向字符串结尾的Iterator
size	得到字符串的大小
length	和size函数功能相同
max_size	字符串可能的最大大小
capacity	在不重新分配内存的情况下，字符串可能的大小
empty	判断是否为空
operator[]	取第几个元素，相当于数组
c_str	取得C风格的const char* 字符串
data	取得字符串内容地址
operator=	赋值操作符
reserve	预留空间
swap	交换函数
insert	插入字符
append	追加字符
push_back	追加字符
operator+=	+= 操作符
erase	删除字符串
clear	清空字符容器中所有内容
resize	重新分配空间
assign	和赋值操作符一样
replace	替代
copy	字符串到空间
find	查找
rfind	反向查找
find_first_of	查找包含子串中的任何字符，返回第一个位置
find_first_not_of	查找不包含子串中的任何字符，返回第一个位置
find_last_of	查找包含子串中的任何字符，返回最后一个位置
find_last_not_of	查找不包含子串中的任何字符，返回最后一个位置
substr	得到字串
compare	比较字符串
operator+	字符串链接
operator==	判断是否相等
operator!=	判断是否不等于
operator<</td>	判断是否小于
operator>>	从输入流中读入字符串
operator<<	字符串写入输出流
getline	从输入流中读入一行
---------------------------------------------------------------

字符串
https://www.boost.org/doc/libs/1_61_0/doc/html/string_algo.html
https://blog.csdn.net/wangqiulin123456/article/details/79886994

-------------------------
大小写转化
to_upper(); //字符串转化成大写形式
to_lower(); //字符串转换成小写形式
带后缀_copy的方法把输入转换后进行输出
-------------------------
判断式
lexicongraphical_compare(str1, str2)    //按照字典顺序判断字符串大小
starts_with(str1, str2)                 //判断字符串是否以另一个开始
ends_with(str1, str2)                   //判断字符串是否以另一个结束
contains(str1, str2)                    //判断字符串是否包含另一个
equals(str1, str2)                      //两个字符串是否相等
all(str, pred)                          //检测字符串中所有元素是否满足指定谓词
is_equal()(str1,str2)                   //函数对象，判断字符串是否相等
is_less()(str1, str2)                   //函数对象，判断字符串str1是否小于str2
is_not_greater()(str1,str2)             //函数对象，判断字符串str1是否不大于str2
-------------------------
分类
is_space()  // 字符是否为空格或制表符
is_alnum()  // 字符是否为字母或数字
is_alpha()  // 字符是否为字母
is_cntrl()  // 字符是否为控制字符
is_digit()  // 字符是否为十进制数字
is_graph()  // 字符是否为图形字符
is_lower()  // 字符是否为小写字符
is_print()  // 字符是否为可打印字符
is_punct()  // 字符是否为表点字符
is_upper()  // 字符是否为大写字符
is_xdigit() // 字符是否为十六进制字符
is_any_of() // 字符是否为字符序列中任意字符
if_from_range() // 字符是否位于指定区间中
-------------------------
修剪
trim_left()
trim_right()
trim()
该方法的_if版本可接收其他谓词对象
-------------------------
查找
以下方法返回一个迭代器的pair对象boost::iterator_range,其内部定义为：std::pair
find_first()    //查找字符串再输入中第一次出现的位置
find_last()     //查找字符串再输入中最后一次出现的位置
find_nth()      //查找字符串再输入中第N次出现的位置(其中N的索引从0开始)
find_head()     //取一个字符串的N个开头，和string的substr(0,N)取字串类似
find_tail()     //取一个字符串的末尾N个字符子串
find_iterator()
iterator_range<std::string::iterator> iter = ifind_first(s, "c++");
-------------------------
替换和删除
replace/erase_first()   // 替换/删除一个字符串再输入中第一次出现
replace/erase_last()    // 替换/删除一个字符串再输入中最后一次出现
replace/erase_nth()     // 替换/删除一个字符串再输入中第N次出现
replace/erase_all()     // 替换/删除一个字符串再输入中所有出现
replace/erase_head()    // 替换/删除输入的开头
replace/erase_tail()    // 替换/删除输入结尾
-------------------------
分割与合并
find_all()  分割
split()   分割
find_iterator()  迭代分割
split_iterator()  迭代分割
join()  合并
-------------------------
实例cat main.cpp 
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <vector>
using namespace std;
//using namespace boost;
int main()
{
    //-------------------------
    //大小写转换
    std::cout << "大小写转换\n";
    std::string str("The C++ Boost Libraries");
    std::cout << boost::to_upper_copy(str) << "\n";
    boost::to_lower(str);
    std::cout << str << "\n";
    //------------------------
    //比较2个字符串
    std::cout << "比较2个字符串\n";
    std::cout << boost::starts_with("abc","ab") << "\n";
    //------------------------
    //字符串分类
    std::cout << "字符串分类\n";
    std::cout << boost::all(" ",boost::is_space()) << "\n";
    //------------------------
    //修剪  去掉首尾空格
    std::cout << "修剪\n";
    std::string str3("  abc de f  ");
    boost::trim_left(str3);
    std::cout << str3 << "end\n";
    boost::trim_right(str3);
    std::cout << str3 << "end\n";
    boost::trim(str3);
    std::cout << str3 << "end\n"; 
    //------------------------
    //查找
    std::cout << "查找\n";
    char text[]="hello dolly!";
    boost::iterator_range<char*> result=boost::find_last(text,"ll");
    std::cout << result << "\n";
    if(boost::find_first(text, "dolly"))
    {
        std::cout << "Dolly is there" << "\n";
    }
    //------------------------
    //替换和删除
    std::cout << "替换和删除\n";
    std::string str5="Hello  Dolly,   Hello Dolly!";
    boost::replace_first(str5, "Dolly", "Jane");      // str1 == "Hello  Jane,   Hello Dolly!"
    std::cout << str5 << "\n";
    boost::replace_last(str5, "Hello", "Goodbye");    // str1 == "Hello  Jane,   Goodbye World!"
    std::cout << str5 << "\n";
    boost::erase_all(str5, " ");                      // str1 == "HelloJane,GoodbyeWorld!"
    std::cout << str5 << "\n";
    boost::erase_head(str5, 6);                       // str1 == "Jane,GoodbyeWorld!"
    std::cout << str5 << "\n";
    //-----------------------
    //切割与合并
    std::cout << "切割与合并\n";
    std::string str1("hello abc-*-ABC-*-aBc goodbye");
    typedef vector< boost::iterator_range<std::string::iterator> > find_vector_type;
    find_vector_type FindVec; // #1: Search for separators
    boost::ifind_all( FindVec, str1, "abc" ); // FindVec == { [abc],[ABC],[aBc] }
    for(find_vector_type::iterator iter=FindVec.begin();iter!=FindVec.end();iter++)
    {
        std::cout << *iter;
    }
    std::cout << "\n";
    typedef vector< std::string > split_vector_type;
    split_vector_type SplitVec; // #2: Search for tokens
    boost::split( SplitVec, str1, boost::is_any_of("-*"), boost::token_compress_on ); // SplitVec == { "hello abc","ABC","aBc goodbye" }
    for(split_vector_type::iterator iter=SplitVec.begin();iter!=SplitVec.end();iter++)
    {
        std::cout << *iter;
    }
    std::cout << "\n";
    //----------------------
    
    return 0;
}
------------------------------
cat CMakeLists.txt 
cmake_minimum_required(VERSION 2.8.3)
add_compile_options(-std=c++11)
project(test)
find_package(Boost REQUIRED COMPONENTS system thread)
include_directories(${Boost_INCLUDE_DIRS})
AUX_SOURCE_DIRECTORY(. SRC_DIR)
add_executable(test ${SRC_DIR} )
target_link_libraries(test ${Boost_LIBRARIES} pthread)
---------------------------------
