-----------------------------------------------------
std::algorithm 算法函数
http://www.cplusplus.com/reference/algorithm/
-----------------------------------------------------
Non-modifying sequence operations: 不修改序列的操作
all_of     查找范围，所有元素都返回true，则为true
any_of     查找所有元素，任意元素返回true，则为true
none_of    范围中所有元素都返回false，则为true
for_each   范围中的元素，循环作为参数传递给函数
find       范围中查找元素
find_if    范围中查找，第一个使条件为true的元素
find_if_not 范围中查找，第一个使条件为false的元素
find_end    在一个范围中，查找另一个范围，返回最后一次满足条件的起始迭代器
find_first_of  在一个范围中，查找另一个范围，返回第一次满足条件的起始迭代器
adjacent_find  在范围内查找，第一次连续元素的起始位置，返回迭代器
count          在范围内，统计某个元素的数量
count_if       在范围内，统计满足条件的元素数量
mismatch       在一个范围内，查找另一个范围，查找第一个不相等的元素，返回键值对
equal          比较2个范围内的所有元素
is_permutation  比较2个范围内的所有元素，和顺序无关，就像比较2个集合一样
search          在一个范围内，查找另一个范围，返回第一个起始迭代器
search_n        在范围内查找某个元素连续n次出现的位置，返回迭代器
----------------------------------------------------
Modifying sequence operations:修改序列的操作
Copy        复制一个范围到另一个范围
copy_n      从一个范围内复制n个元素到另一个范围
copy_if     从一个范围内复制满足条件的元素到另一个范围
copy_backward 在同一个容器中，向后复制一部分元素
move       移动一个容器的元素到另一个容器
move_backward 同一个容器，向后移动一个范围
swap          交换，可以交换变量，也可以交换容器
swap_ranges    交换一段范围的元素
iter_swap      通过迭代器交换元素
transform      一个范围元素作为函数输入，输出到另一个范围
replace        范围替换
replace_if
replace_copy
replace_copy_if
fill
fill_n
generate
generate_n
remove
remove_if
remove_copy
remove_copy_if
unique
unique_copy
reverse
reverse_copy
rotate
rotate_copy
random_shuffle
shuffle 
--------------------------------------------
Partitions:   分区
is_partitioned 
partition
stable_partition
partition_copy 
partition_point 
--------------------------------------------
Sorting:       排序
sort
stable_sort
partial_sort
partial_sort_copy
is_sorted 
is_sorted_until 
nth_element
--------------------------------------------
Binary search：  二进制搜索
lower_bound
upper_bound
equal_range
binary_search
--------------------------------------------
Merge   合并
merge
inplace_merge
includes
set_union
set_intersection
set_difference
set_symmetric_difference
-----------------------------------------------
Heap:  堆
push_heap
pop_heap
make_heap
sort_heap
is_heap 
is_heap_until 
-----------------------------------------------
Min/max:   最小最大值
min
max
minmax 
min_element
max_element
minmax_element 
-----------------------------------------------
