
# 安装cryptopp-dev
## 方法1
sudo apt-get install libcryptopp-dev
## 方法2
```
https://github.com/weidai11/cryptopp
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
## rsa
```cpp
#include <string>

#include <cryptopp/files.h>
#include <cryptopp/filters.h>
#include <cryptopp/hex.h>
#include <cryptopp/randpool.h>
#include <cryptopp/rsa.h>

#include <unistd.h>
#include <iostream>

using namespace std;
using namespace CryptoPP;

class CMyRSA
{
public:
    CMyRSA(void);
    virtual ~CMyRSA(void);

    //You must set the KeyLength 512, 1024, 2048 ...
    void GenerateKey(const unsigned int KeyLength, const char *Seed, RSAES_OAEP_SHA_Decryptor &Priv, RSAES_OAEP_SHA_Encryptor &Pub);
    void GenerateKey(const unsigned int KeyLength, const char *Seed, string &strPriv, string &strPub);
    
    //use public key to encrypt
    void EncryptString(const RSAES_OAEP_SHA_Encryptor &Pub, const char *Seed, const string &Plaintext, string &Ciphertext);
    void EncryptString(const string &strPub, const char *Seed, const string &Plaintext, string &Ciphertext);

    //use private key to decrypt
    void DecryptString(const RSAES_OAEP_SHA_Decryptor &Priv, const string &Ciphertext, string &Plaintext);
    void DecryptString(const string &strPriv, const string &Ciphertext, string &Plaintext);

private:
    static RandomPool & RNG(void);

private:
    static RandomPool m_sRandPool;
};
CMyRSA::CMyRSA()
{

}

CMyRSA::~CMyRSA(void)
{

}

void CMyRSA::GenerateKey(const unsigned int KeyLength, const char *Seed, RSAES_OAEP_SHA_Decryptor &Priv, RSAES_OAEP_SHA_Encryptor &Pub)
{
    RandomPool RandPool;
    RandPool.IncorporateEntropy((byte *)Seed, strlen(Seed));
    
    //generate private key
    Priv = RSAES_OAEP_SHA_Decryptor(RandPool, KeyLength);

    //generate public key using private key
    Pub = RSAES_OAEP_SHA_Encryptor(Priv);
}

void CMyRSA::GenerateKey(const unsigned int KeyLength, const char *Seed, string &strPriv, string &strPub)
{
    RandomPool RandPool;
    RandPool.IncorporateEntropy((byte *)Seed, strlen(Seed));

    //generate private key
    RSAES_OAEP_SHA_Decryptor Priv(RandPool, KeyLength);
    HexEncoder PrivateEncoder(new StringSink(strPriv));//本博客作者加：就为了这句代码整整找了1天！
    //Priv.DEREncode(PrivateEncoder);  //这里会报错
    PrivateEncoder.MessageEnd();               

    //generate public key using private key
    RSAES_OAEP_SHA_Encryptor Pub(Priv);
    HexEncoder PublicEncoder(new StringSink(strPub));
    //Pub.DEREncode(PublicEncoder);
    PublicEncoder.MessageEnd();
}

void CMyRSA::EncryptString(const RSAES_OAEP_SHA_Encryptor &Pub, const char *Seed, const string &Plaintext, string &Ciphertext)
{
    RandomPool RandPool;
    RandPool.IncorporateEntropy((byte *)Seed, strlen(Seed));

    int MaxMsgLength = Pub.FixedMaxPlaintextLength();
    for (int i = Plaintext.size(), j=0; i > 0; i -= MaxMsgLength, j += MaxMsgLength)
    {
        string PartPlaintext = Plaintext.substr(j, MaxMsgLength);
        string PartCiphertext;
        StringSource(PartPlaintext, true, new PK_EncryptorFilter(RandPool, Pub, new HexEncoder(new StringSink(PartCiphertext))));
        Ciphertext += PartCiphertext;                  
    }
}

void CMyRSA::EncryptString(const string &strPub, const char *Seed, const string &Plaintext, string &Ciphertext)
{
    StringSource PublicKey(strPub, true, new HexDecoder);
    RSAES_OAEP_SHA_Encryptor Pub(PublicKey);

    RandomPool RandPool;
    RandPool.IncorporateEntropy((byte *)Seed, strlen(Seed));

    int MaxMsgLength = Pub.FixedMaxPlaintextLength();
    for (int i = Plaintext.size(), j=0; i > 0; i -= MaxMsgLength, j += MaxMsgLength)
    {
        string PartPlaintext = Plaintext.substr(j, MaxMsgLength);
        string PartCiphertext;
        StringSource(PartPlaintext, true, new PK_EncryptorFilter(RandPool, Pub, new HexEncoder(new StringSink(PartCiphertext))));
        Ciphertext += PartCiphertext;                  
    }
}

void CMyRSA::DecryptString(const RSAES_OAEP_SHA_Decryptor &Priv, const string &Ciphertext, string &Plaintext)
{
    //indicate the ciphertext in hexcode
    int CiphertextLength = Priv.FixedCiphertextLength() * 2;
    for (int i = Ciphertext.size(), j=0; i > 0; i -= CiphertextLength, j += CiphertextLength)
    {
            string PartCiphertext = Ciphertext.substr(j, CiphertextLength);
            string PartPlaintext;
            StringSource(PartCiphertext, true, new HexDecoder(new PK_DecryptorFilter(RNG(), Priv, new StringSink(PartPlaintext))));
            Plaintext += PartPlaintext;
    }
}

void CMyRSA::DecryptString(const string &strPriv, const string &Ciphertext, string &Plaintext)
{
    StringSource PrivKey(strPriv, true, new HexDecoder);
    RSAES_OAEP_SHA_Decryptor Priv(PrivKey);
    
    //indicate the ciphertext in hexcode
    int CiphertextLength = Priv.FixedCiphertextLength() * 2;
    for (int i = Ciphertext.size(), j=0; i > 0; i -= CiphertextLength, j += CiphertextLength)
    {
            string PartCiphertext = Ciphertext.substr(j, CiphertextLength);
            string PartPlaintext;
            StringSource(PartCiphertext, true, new HexDecoder(new PK_DecryptorFilter(RNG(), Priv, new StringSink(PartPlaintext))));
            Plaintext += PartPlaintext;
    }
}

RandomPool & CMyRSA::RNG(void)
{
    return m_sRandPool;
}

RandomPool CMyRSA::m_sRandPool;
static RSAES_OAEP_SHA_Encryptor g_Pub;
static RSAES_OAEP_SHA_Decryptor g_Priv;
static string g_strPub;
static string g_strPriv;

int main(int argc, char *argv[])
{
    try
    {
        char Seed[1024], Message[1024], MessageSeed[1024];
        unsigned int KeyLength;
        CMyRSA MyRSA;

        cout << "Key length in bits: ";
        cin >> KeyLength;   //  这里设置为1024，不能设置太小，否则FixedMaxPlaintextLength为0，将不能加密任何文本

        cout << "/nRandom Seed: ";
        ws(cin);
        cin.getline(Seed, 1024);

        cout << "/nMessage: ";
        ws(cin);    
        cin.getline(Message, 1024);    

        cout << "/nRandom Message Seed: ";
        ws(cin);
        cin.getline(MessageSeed, 1024);
        
        MyRSA.GenerateKey(KeyLength, Seed, g_Priv, g_Pub);
        //MyRSA.GenerateKey(KeyLength, Seed, g_strPriv, g_strPub);

        //If generate key in RSAES_OAEP_SHA_Encryptor and RSAES_OAEP_SHA_Decryptor, please note four lines below
        /*
        cout << "g_strPub = " << g_strPub << endl;
        cout << endl;
        cout << "g_strPriv = " << g_strPriv << endl;
        cout << endl;
        */
        
        string Plaintext(Message);
        string Ciphertext;
        MyRSA.EncryptString(g_Pub, MessageSeed, Plaintext, Ciphertext);
        //MyRSA.EncryptString(g_strPub, MessageSeed, Plaintext, Ciphertext);
        cout << "/nCiphertext: " << Ciphertext << endl;
        cout << endl;

        string Decrypted;
        MyRSA.DecryptString(g_Priv, Ciphertext, Decrypted);
        //MyRSA.DecryptString(g_strPriv, Ciphertext, Decrypted);
        cout << "/nDecrypted: " << Decrypted << endl;
        return 0;
    }
    catch(CryptoPP::Exception const &e)
    {
        cout << "/nCryptoPP::Exception caught: " << e.what() << endl;
        return -1;
    }
    catch(std::exception const &e)
    {
        cout << "/nstd::exception caught: " << e.what() << endl;
        return -2;
    }
    return -3;
}
```
