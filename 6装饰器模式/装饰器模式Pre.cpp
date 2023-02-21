#include <bits/stdc++.h>
using namespace std;

// 业务操作
class Stream
{
public:
    virtual char Read(int number) = 0;
    virtual void Seek(int number) = 0;
    virtual void Write(char data) = 0;

    virtual ~Stream() {}
};

// 主体类
class FileStream : public Stream
{
public:
    // 读文件流
    virtual char Read(int number) {}
    // 定位文件流
    virtual void Seek(int number) {}
    // 写文件流
    virtual void Write(char data) {}
};

// 网络流
class NetworkStream : public Stream
{
public:
    // 读文件流
    virtual char Read(int number) {}
    // 定位文件流
    virtual void Seek(int number) {}
    // 写文件流
    virtual void Write(char data) {}
};

// 内存流
class MemoryStream : public Stream
{
public:
    // 读文件流
    virtual char Read(int number) {}
    // 定位文件流
    virtual void Seek(int number) {}
    // 写文件流
    virtual void Write(char data) {}
};

// 扩展操作
class CryptoFileSTream : public FileStream
{
public:
    virtual char Read(int number)
    {

        // 额外的加密操作
        FileStream::Read(number); // 读文件流
    }

    virtual void Seek(int position)
    {
        // 额外的加密操作.......
        FileStream::Seek(position); // 定位文件流
        // 额外的解密操作.......
    }

    virtual void Write(char data)
    {
        // 额外的解密操作.......
        FileStream::Write(data);
        // 额外的解密操作.......
    }
};

// 扩展操作
class CryptoNetworkSTream : public NetworkStream
{
public:
    virtual char Read(int number)
    {

        // 额外的加密操作
        NetworkStream::Read(number); // 读文件流
    }

    virtual void Seek(int position)
    {
        // 额外的加密操作.......
        NetworkStream::Seek(position); // 定位文件流
        // 额外的解密操作.......
    }

    virtual void Write(char data)
    {
        // 额外的解密操作.......
        NetworkStream::Write(data);
        // 额外的解密操作.......
    }
};

class CryptoMemorySTream : public MemoryStream
{
public:
    virtual char Read(int number)
    {

        // 额外的加密操作
        MemoryStream::Read(number); // 读文件流
    }

    virtual void Seek(int position)
    {
        // 额外的加密操作.......
        MemoryStream::Seek(position); // 定位文件流
        // 额外的解密操作.......
    }

    virtual void Write(char data)
    {
        // 额外的解密操作.......
        MemoryStream::Write(data);
        // 额外的解密操作.......
    }
};