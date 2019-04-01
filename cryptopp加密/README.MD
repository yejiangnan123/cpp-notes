
# 安装cryptopp-dev
## 方法1
sudo apt-get install libcryptopp-dev
## 方法2
```
sudo git clone https://github.com/weidai11/cryptopp.git  //克隆源码
make install //安装静态库，在当前目录也会生成libcryptopp.a
make libcryptopp.so //安装动态库，这里只是生成一个链接
ldconfig //使动态库链接生效
```
# 编译
## 1 cmake编译
```
cmake配置：添加cryptopp动态库
target_link_libraries(test ${Boost_LIBRARIES} pthread cryptopp)
cmake .
make
```
## 2 记得main函数要放在第一个，用动态库
```
g++ Cryptopp_test.cc -lcryptopp -lpthread  -o test
```
## 3 用静态库libcryptopp.a
```
g++ Cryptopp_test.cc /root/cryptopp/libcryptopp.a -lpthread -o test
```
## 其他命令
```
dpkg -l | grep crypt //查看安装包
```
# 测试案例
## aes
```cpp
#include <iostream>
#include <cryptopp/aes.h>
 
 #pragma comment( lib, "cryptlib.lib" )
 using namespace std; 
 using namespace CryptoPP;
int main()
{
  //AES中使用的固定参数是以类AES中定义的enum数据类型出现的，而不是成员函数或变量
  //因此需要用::符号来索引
  cout << "AES Parameters: " << endl;
  cout << "Algorithm name : " << AES::StaticAlgorithmName() << endl; 

  //Crypto++库中一般用字节数来表示长度，而不是常用的字节数
  cout << "Block size : " << AES::BLOCKSIZE * 8 << endl;
  cout << "Min key length : " << AES::MIN_KEYLENGTH * 8 << endl;
  cout << "Max key length : " << AES::MAX_KEYLENGTH * 8 << endl;

  //AES中只包含一些固定的数据，而加密解密的功能由AESEncryption和AESDecryption来完成
  //加密过程
  AESEncryption aesEncryptor; //加密器 

  unsigned char aesKey[AES::DEFAULT_KEYLENGTH]; //密钥
  unsigned char inBlock[AES::BLOCKSIZE] = "123456789"; //要加密的数据块
  unsigned char outBlock[AES::BLOCKSIZE]; //加密后的密文块
  unsigned char xorBlock[AES::BLOCKSIZE]; //必须设定为全零

  memset( xorBlock, 0, AES::BLOCKSIZE ); //置零

  aesEncryptor.SetKey( aesKey, AES::DEFAULT_KEYLENGTH ); //设定加密密钥
  aesEncryptor.ProcessAndXorBlock( inBlock, xorBlock, outBlock ); //加密

  //以16进制显示加密后的数据
  for( int i=0; i<16; i++ ) {
    cout << hex << (int)outBlock[i] << " ";
  }
  cout << endl;
  for( int i=0; i<16; i++ ){
    cout << inBlock[i];
  }
  cout << endl;
  //解密
  AESDecryption aesDecryptor;
  unsigned char plainText[AES::BLOCKSIZE];

  aesDecryptor.SetKey( aesKey, AES::DEFAULT_KEYLENGTH );
  //细心的朋友注意到这里的函数不是之前在DES中出现过的：ProcessBlock，
  //而是多了一个Xor。其实，ProcessAndXorBlock也有DES版本。用法跟AES版本差不多。
  //笔者分别在两份代码中列出这两个函数，有兴趣的朋友可以自己研究一下有何差异。
  aesDecryptor.ProcessAndXorBlock( outBlock, xorBlock, plainText );

  for( int i=0; i<16; i++ ) { 
    cout << plainText[i]; 
  }
  cout << endl;
  return 0;
}
```
