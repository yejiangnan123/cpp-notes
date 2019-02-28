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

