迭代器
------------------------
https://www.cnblogs.com/maluning/p/8570717.html
------------------------
定义和初始化
vector<int>::iterator    iter;    //定义一个名为iter的变量
vector<int>    ivec;
vector<int>::iterator    iter1=ivec.bengin();    //将迭代器iter1初始化为指向ivec容器的第一个元素
vector<int>::iterator   iter2=ivec.end();    //将迭代器iter2初始化为指向ivec容器的最后一个元素的下一个位置
-------------------------
常用操作
*iter                //对iter进行解引用，返回迭代器iter指向的元素的引用
iter->men            //对iter进行解引用，获取指定元素中名为men的成员。等效于(*iter).men
++iter                //给iter加1，使其指向容器的下一个元素
iter++
--iter                //给iter减1，使其指向容器的前一个元素
iter--
iter1==iter2        //比较两个迭代器是否相等，当它们指向同一个容器的同一个元素或者都指向同同一个容器的超出末端的下一个位置时，它们相等 
iter1!=iter2
-------------------------
只读迭代器
for(vector<int>::const_iterator iter=ivec.begin();iter!=ivec.end();++iter)
     cout<<*iter<<endl;       //合法，读取容器中元素值
-------------------------
