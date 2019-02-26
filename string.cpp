字符串
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
