文件系统常用函数
boost::filesystem;
my->block_stream.open(my->block_file.generic_string().c_str(), LOG_WRITE);  //写模式打开文件

std::is_same 判断类型一致性
std::decay 退化修饰

const std::string& string( )： 字符串化
std::string root_directory( )：  根目录
std::string root_name( )：根目录名
std::string leaf( )：绝对路径
std::string branch_path( )：路径名
bool empty( )：空
boost::filesystem::path::iterator：路径迭代器
boost::filesystem::rename(path, path2);  重命名
catch(boost::filesystem::filesystem_error e) {   错误，异常 
uintmax_t file_size(const path&)：文件大小
boost::filesystem::space_info space(const path&)：磁盘空间
std::time_t last_write_time(const path&)：最后修改时间。
void last_write_time(const path&, std::time_t new_time)：最后修改时间。
const path& current_path( )：当前工作目录的完整路径
bool create_directory(const path&)：创建目录
bool create_directories(const path&)：创建目录树
bool create_hard_link (const path& frompath, const path& topath)：创建硬链接。
bool create_symlink(const path& frompath, const path& topath)：创建符号（软）链接。
void copy_file(const path& frompath, const path& topath)：复制
void rename(const path& frompath, const path& topath)：重命名
bool remove(const path& p)：删除
unsigned long remove_all(const path& p)：删除
bool exists(const path&)：检查文件的扩展名
bool is_directory(const path&)：检查目录
bool is_regular(const path&)：检查普通文件
bool is_other(const path&)：检查设备文件
bool is_empty(const path&)：检查是否为空
bool equivalent(const path1& p1, const path2& p2)：比较路径
path system_complete(const path&)：绝对路径
std::string extension(const path&)：扩展名
std::string basename(const path&)：文件名，不带扩展名
std::string change_extension(const path& oldpath, const std::string new_extension)：修改扩展名
