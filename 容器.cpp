boost 容器
-------------------------------
boost::array    
当固定长度数组使用
front() back() swap() size() operator[] at()
https://blog.csdn.net/huang_xw/article/details/8248361
https://blog.csdn.net/shaozg168/article/details/6859584
---------------------------------
boost::unordered_set  无序，集合
boost::unordered_multiset 无序，可重复，集合
boost::unordered_map   无序，键值对
boost::unordered_multimap   无序，可重复，键值对
boost::multi_index::multi_index_container  多索引容器
boost::bimap   双向索引容器，键值对
---------------------------------
boost::unordered_set
散列集合，无序，查找速度快
https://blog.csdn.net/ooooo12345re/article/details/51649185
begin end cbegin cend empty size max_size emplace emplace_hint insert erase clear hash_function key_eq find count equal_range
load_factor max_load_factor rehash reverse
迭代器 添加 插入 删除 清空 查找
---------------------------------
list  双向链表   插入删除很快
forward_list 单向链表  只能++，不能--
array  定长数组
deque  双端队列  
queue  普通队列
priority_queue 优先队列
stack 栈，后进先出
map  key-value  按照key排序
multimap  key可以重复
unordered_map  无序map
unordered_multimap  无序，重复
set  集合，排序，唯一
multi-set 集合，排序，重复
unordered_set  无序
unordered_multiset 无序，重复
vector 动态数组
---------------------------------------------------------
实例
---------------------------------------------------------
boost::array
cat main.cpp 


#include <boost/array.hpp>
using boost::array;
 
#include <iostream>
#include <string>
using namespace std;
 
int main()
{
	// boost::array可以当作std::vector来用，只不过boost::array限定大小
	typedef boost::array<std::string, 3> StrArray;
 
	StrArray sa;
	sa[0] = "hello";
	sa.at(1) = ", ";
	*sa.rbegin() = "world.";
 
	// 输出
	for (StrArray::const_iterator it = sa.begin(); it != sa.end(); it ++)
	{
		cout<<*it;
	}
	cout<<endl;
 
	return 0;
}
-------------------------------------------------------------
