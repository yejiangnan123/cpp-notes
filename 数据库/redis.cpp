------------------------------------------------------
教程：http://www.runoob.com/redis/redis-tutorial.html
特点：
数据保存在内存中，定时更新到文件中。速度极快，系统宕机后通过文件恢复。
适用于数据量小，但是更新频繁的数据。
支持丰富的数据类型，也叫数据结构数据库，支持：字符串、列表、集合、散列表、有序集合。
支持主从模式。
支持批量操作，且操作都是原子的。
支持各种语言的API。
每种数据类型都有自己的操作命令。
------------------------------------------------------
数据类型：
String（字符串）  键值对   每个value最大512MB。
Hash（哈希）   键值对集合。每个 hash 可以存储 232 -1 键值对（40多亿）。
List（列表）  Redis 列表是简单的字符串列表，按照插入顺序排序。你可以添加一个元素到列表的头部（左边）或者尾部（右边）。
Set（集合） Redis的Set是string类型的无序集合。集合是通过哈希表实现的，所以添加，删除，查找的复杂度都是O(1)。
zset(sorted set：有序集合)  不允许重复的成员。关联一个double分数来排序（升序），但是分数可以重复。
------------------------------------------------------
超级日志
发布订阅    Redis 发布订阅(pub/sub)是一种消息通信模式：发送者(pub)发送消息，订阅者(sub)接收消息。
事物        Redis 事务可以一次执行多个命令
脚本
连接        密码，切换数据库
服务器      管理客户端，客户端有名称，可以删除所有key，管理配置文件，同步数据到硬盘
数据备份与恢复
安全        密码管理
性能测试
客户端连接   可以设置最大连接数
管道技术
分区        可以构建更大的数据库
------------------------------------------------------
-------------------------------------------------------
-------------------------------------------------------
-------------------------------
安装
redis + hiredis
hiredis是c客户端API
-------------------------------
https://www.zybuluo.com/LIUHUAN/note/364481
/**连接数据库*/
redisContext *redisConnect(const char *ip, int port);
/**发送命令请求*/
void *redisCommand(redisContext *c, const char *format, ...);
void *redisCommandArgv(redisContext *c, int argc, const char **argv, const size_t *argvlen);
void redisAppendCommand(redisContext *c, const char *format, ...);
void redisAppendCommandArgv(redisContext *c, int argc, const char **argv, const size_t *argvlen);
/*释放资源*/
void freeReplyObject(void *reply);
void redisFree(redisContext *c);
----------------
数据库连接
redisContext *redisConnect(const char *ip, int port);   127.0.0.1  6379
----------------------------------------
命令功能
http://redisdoc.com/string/setnx.html
----------------------------------------
----------------
字符串
数据结构：key value   （键值对）
SET     设置key
SETNX   key不存在才设置
PSETEX  设置key，并设置生存时间，单位秒
PSETEX  设置key，并设置生成时间，单位毫秒
GET     获取key对应的字符串，只能是字符串类型
GETSET  返回旧值，设置新值
STRLEN  返回字符串长度
APPEND  追加字符串
SETRANGE 指定索引位置，覆盖字符串
GETRANGE  截取字符串，负数表示从末尾开始计数
INCR      加一
INCRBY    加上一个整数
INCRBYFLOAT   加上一个浮点数
DECR       减一
DECRBY    减一个整数
MSET      同时设置多个键
MSETNX    同时设置多个不存在的键
MGET       获取列表，同时获取多个键
----------------
哈希表   
数据结构： key  field  value    （key为表，field为域，value为值）
HSET     设置值
HSETNX   不存在才设置
HGET     获取值
HEXISTS  检查是否存在
HDEL     可以删除一个和多个
HLEN     域的数量
HSTRLEN  长度
HINCRBY  加一个数，这个数可以为负数
HINCRBYFLOAT 加上浮点数
HMSET     同时设置多个域值对
HMGET     同时获取多个值
HKEYS     所有域
HVALS     所有域的值
HGETALL   返回所有域值对
----------------
列表
数据结构： 字符串数组
LPUSH     左边插入值，可以同时插入多个
LPUSHX    存在才从左边插入
RPUSH     右边插入
RPUSHX    存在才从右边插入
LPOP      移除最左边值（弹出）
RPOP      移除最右边值（弹出）
RPOPLPUSH   弹出一个列表的最右值，插入到另一表的最左边
LREM      移除列表中一定数量的等于value的元素，可以从左开始，也可以从右开始，0表示移除所有等于value的元素
LLEN      长度
LINDEX    下标访问列表
LINSERT    在某个值之前或者之后插入一个元素
LSET       设置指定下标的值
LRANGE     返回指定区间的元素
LTRIM      修剪，只保留指定的区间
BLPOP      阻塞弹出第一个元素，可以指定多个列表去搜索，可以指定超时时间
BRPOP      阻塞弹出最后一个元素，可以指定多个列表，可以指定超时时间
BRPOPLPUSH  阻塞弹出第一个列表的最后一个元素，插入到第二个列表的第一个元素，可以设置超时时间
----------------
集合
SADD      添加新元素到集合，可以添加多个
SISMEMBER  查找元素是否在集合里
SPOP       随机移除一个元素
SRANDMEMBER   随机返回指定个数的元素，不移除，指定个数为负数，说明元素可以重复
SREM         移除多个元素
SMOVE        移动元素到新的集合
SCARD        集合的基数，也就是大小
SMEMBERS     返回集合所有元素
SINTER       交集
SINTERSTORE   交集保存到新集合
SUNION       并集
SUNIONSTORE   并集保存到新集合
SDIFF        差集
SDIFFSTORE   差集保存到新集合
----------------
有序集合
ZADD         添加元素，指定顺序
ZSCORE       返回指定值的序号
ZINCRBY      给某个元素的序号加个数
ZCARD        集合的基数，个数
ZCOUNT       返回指定序号区间的元素个数
ZRANGE       返回指定区间的元素，可以选择是否返回序号
ZREVRANGE    递减返回指定区间的元素
ZRANGEBYSCORE   根据序号的区间来返回元素
ZREVRANGEBYSCORE   返回序号的区间的元素，从大到小
ZRANK         返回元素的排名
ZREVRANK      返回元素的排名，从大到小
ZREM          移除元素
ZREMRANGEBYRANK   移除区间内的元素
ZREMRANGEBYSCORE   按序号，移除区间内的元素
ZRANGEBYLEX   按值排序，返回在区间内的元素
ZLEXCOUNT     按值排序，返回区间内的元素数量
ZREMRANGEBYLEX 按值排序，移除区间内的元素
ZUNIONSTORE    求并集，并且序号可以指定乘以一个因子，结果保存到新集合
ZINTERSTORE     求交集，默认序号相加，结果保存到新集合
----------------
超级日志  HyperLogLog 
PFADD  添加元素
PFCOUNT  统计元素数量
PFMERGE   合并到新集合
----------------
位图
SETBIT   设置指定位的值
GETBIT   获取指定位的值
BITCOUNT 统计区间值为1的数量
BITPOS   返回位图中第一个值为bit的二进制的位置，可以指定区间
BITOP     多个位图执行位运算，包括与，或，非，异或
----------------
数据库
EXISTS   检查key是否存在
TYPE     返回key的类型
RENAME    为key改名
RENAMENX  为key改名，newkey存在则不执行
MOVE      将key移动到别的数据库中
DEL       删除key
RANDOMKEY   随机返回一个key
DBSIZE     返回当前数据库key的数量
KEYS      匹配模式查找key
SCAN      迭代
SORT      排序
FLUSHDB   清空当前数据库所有key
FLUSHALL  清空所有数据库的所有key
SELECT    选择数据库
SWAPDB    交换2个数据库的数据
----------------
自动过期
EXPIRE    设置key的过期时间，单位为秒
EXPIREAT  设置key的过期时间，时间戳，秒，在指定时间过期
TTL       返回key剩余的生存时间，单位为秒
PERSIST   移除生存时间
PEXPIRE    设置生存时间，单位为毫秒
PEXPIREAT  设置过期时间，时间错，毫秒，在指定时间过期
PTTL      返回剩余的生存时间，单位为毫秒
-----------------
持久化
SAVE      保存数据到硬盘
BGSAVE    后台异步保存数据到硬盘
LASTSAVE  返回最近一次保存数据的时间，时间戳
-----------------

