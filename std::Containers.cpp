-----------------------------------------------------
Containers  容器
http://www.cplusplus.com/reference/stl/
-----------------------------------------------------
array  固定大小的数组，代替c数组
vector  动态数组，不需要考虑数组大小；和操作一般数组一样很方便；但是插入删除效率低，在末尾插入删除效率高
deque   这是一个双端队列，可以在首尾两端插入和删除，效率和vector差不多；整体性能比vector略低，中间插入删除效率极低。
forward_list  单向链表。只支持单向顺序访问。在链表任何位置进行插入/删除操作速度都很快。
list    只支持双向顺序访问。在list中任何位置进行插入/删除操作速度都很快。
stack   栈，先进后出；
queue   队列，先进先出；
priority_queue   优先级队列，自定义结构需要重载 < 操作符；例如先出队大值
set    key集合，有序，key唯一；不能修改元素的值，只能增加删除元素。
multiset   和set的区别是key可以相同。
map   存储键值对，查找效率极高，原理是平滑二叉树
multimap  键值可以重复
unordered_set 基于哈希表，无序，所以速度极快
unordered_multiset  无序 可重复
unordered_map    无序
unordered_multimap  无序，可重复
-----------------------------------------------------
initializer_list 这是一个模板函数，定义一个列表，作为参数函数参数非常高效，因为它是不可修改的容器，相当于常数列表，不需要拷贝，数据传值类似指针和引用
http://www.cplusplus.com/reference/initializer_list/
-----------------------------------------------------
