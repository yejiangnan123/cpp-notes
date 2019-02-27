-----------------------------
tcp
https://blog.csdn.net/qq_15267341/article/details/79005986
boost::asio::ip::tcp;    tcp
boost::asio::ip::address;   address
boost::asio::io_service    异步服务
tcp::endpoint     tcp节点
async_connect    异步连接
boost::bind     绑定函数
shared_from_this()    共享本身
boost::asio::placeholders::error    错误
boost::system::error_code   错误
boost::system::errc::operation_canceled 错误
error.value()      错误值
boost::system::system_error(error).what() 错误内容
close()   关闭
tcp::no_delay option(true);   设置不延迟
set_option(option);   设置参数
boost::asio::async_write   异步写
boost::asio::buffer    buffer
boost::asio::placeholders::bytes_transferred   发送字节
boost::asio::async_read_until    异步读
tcp::socket     tcp套接字
boost::asio::streambuf   流buf
public boost::enable_shared_from_this<client>  继承
address::from_string("127.0.0.1")     地址字符串化
io_service.run();   启动异步服务
async_accept   异步接收连接
reset   重新设置
tcp::acceptor tcp接收器
tcp::v4()  本机tcp
-----------------------------
udp
https://blog.csdn.net/zzz_zou/article/details/8237542
boost::asio::ip::udp::socket
boost::asio::ip::udp::endpoint
open
protocol
bind
receive_from
boost::asio::buffer
send_to
https://blog.csdn.net/caimouse/article/details/10817031
async_receive_from
boost::asio::error::message_size
async_send_to
-----------------------------
