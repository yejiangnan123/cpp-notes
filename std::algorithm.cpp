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
replace_if     把范围内，满足条件的元素替换成新元素
replace_copy   把容器复制到另一个容器，且替换旧元素为新元素
replace_copy_if 把容器复制到另一个容器，且替换满足条件的元素
fill            范围内填充元素
fill_n          范围内填充n个元素
generate        用函数返回值填充容器，每填充一个元素调用一次函数
generate_n      用函数返回值填充容器，调用n次，填充n个元素
remove          移除范围内某种元素，其他元素向前移动，重新排列
remove_if       移除范围内满足条件的元素，其他元素向前移动，重新排列
remove_copy     移除范围内元素，把结果拷贝到新容器
remove_copy_if  移除范围内满足条件的元素，把结果拷贝到新容器，
unique          去掉容器内连续重复的元素，连续的条件可以自定义
unique_copy     去掉容器内连续重复的元素，把结果拷贝到新容器
reverse         反序，把容器内元素倒过来
reverse_copy    反序，把容器内元素倒过来，结果拷贝到新容器
rotate          将范围内前一段元素移到后一段
rotate_copy     将容器内前一段元素移动到后一段，结果保存到新容器
random_shuffle  随机排序
shuffle        指定生成器，随机排序
--------------------------------------------
Partitions:   分区
is_partitioned  判断容器内的元素是否分区，条件自定义，例如奇数是否都在偶数前面
partition       对容器内元素进行分区，例如把奇数放到偶数前面
stable_partition  对容器进行分区，例如把奇数放在前面，稳定分区，保留元素相对位置
partition_copy    对容器进行分区，把结果保存到2个新的容器
partition_point   返回已经分区后半段的起始迭代器，例如奇数在前偶数在后，返回第一个偶数的迭代器位置
--------------------------------------------
Sorting:       排序
sort           升序排序
stable_sort    升序排序，升序条件可以自己定义
partial_sort   把小数放在前半段，并按升序排序，后半段不排序
partial_sort_copy 把排序结果拷贝到新容器
is_sorted       判断容器是否已经按升序排序
is_sorted_until 返回第一个不遵循升序元素的迭代器
nth_element     重新排序，第n个位置的元素排在第n位，也就是说，左边的元素都小于它，右边的元素都大于它
--------------------------------------------
Binary search：  二进制搜索
lower_bound      返回第一个大于等于指定值的元素位置
upper_bound      返回第一个大于指定值的元素位置
equal_range      返回2个迭代器，第一个大于等于该值的元素位置，第一个大于该值的元素位置
binary_search    搜索值，如果找到等效值返回true
--------------------------------------------
Merge       合并
merge       合并2个排序的容器，保存到新容器，新容器也排序
inplace_merge      就地合并，一个容器，前面一段和后面一段都已经排序过了，合并也是排序的
includes      2个容器都是排序过的，如果容器1包含容器2的所有元素，则返回true
set_union     合并2个已经排序的容器，去重复
set_intersection  合并2个已经排序的容器，求交集，可以重复
set_difference    合并2个已经排序的容器，去掉交集元素
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
