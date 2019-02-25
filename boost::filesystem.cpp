文件系统常用函数
boost::filesystem;
std::fstream


namespace fc=boost::filesystem;//简单别名
#define LOG_READ  (std::ios::in | std::ios::binary)
#define LOG_WRITE (std::ios::out | std::ios::binary | std::ios::app)
std::fstream             block_stream;
if (my->block_stream.is_open())
         my->block_stream.close();//判断文件是否打开
if (!fc::is_directory(data_dir))
         fc::create_directories(data_dir);判断目录是否存在
my->block_file = data_dir / "blocks.log";//文件名拼接
my->block_stream.open(my->block_file.generic_string().c_str(), LOG_WRITE);  //写模式打开文件
auto log_size = fc::file_size(my->block_file);   //计算文件大小
block_stream.close();关闭文件
block_stream.open(block_file.generic_string().c_str(), LOG_WRITE);打开文件
my->block_stream.exceptions(std::fstream::failbit | std::fstream::badbit);
my->block_stream.seekg( 0 );定位文件光标
my->block_stream.read( (char*)&my->version, sizeof(my->version) ); 读数据到变量
if (my->block_stream.tellg() <= sizeof(pos))   当前位置
my->block_stream.seekg(-sizeof(pos), std::ios::end);设置位置
fc::remove_all(my->index_file);移除文件
my->block_stream.write((char*)&pos, sizeof(pos));写数据
my->block_stream.flush();同步缓存
std::is_same 判断类型一致性
std::decay 退化修饰
fc::raw::unpack(old_block_stream, gs);
auto data = fc::raw::pack( gs );
std::exception_ptr     except_ptr;
uint64_t tmp_pos = std::numeric_limits<uint64_t>::max();
pos = new_block_stream.tellp();  光标位置
auto tail_path = blocks_dir / std::string("blocks-bad-tail-").append( now ).append(".log");
         if( !fc::exists(tail_path) && incomplete_block_data.size() > 0 )
