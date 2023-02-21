#include <bits/stdc++.h>
using namespace std;

/*****************************
 * 一维多态看继承
 * 多维多态看桥接
 *
 * *************************/

class Image
{
};

class MessagerImp // 平台实现类，如安卓、Windows、ios等
{
public:
    virtual void PlaySound() = 0;
    virtual void DrawShape() = 0;
    virtual void WriteText() = 0;
    virtual void Connect() = 0;

    virtual ~MessagerImp() {}
};

class Messager // 应用版本类：如轻量版、完美版等
{
protected:
    MessagerImp *messagerImp; //...
public:
    Messager(MessagerImp *imp) : messagerImp(imp) {}

    virtual void Login(string username, string password) = 0;
    virtual void SendMessage(string message) = 0;
    virtual void SendPicture(Image image) = 0;

    virtual ~Messager() {}
};

// 电脑版本
class PCMessagerImp : public MessagerImp
{
public:
    virtual void PlaySound()
    {
        //**********
    }
    virtual void DrawShape()
    {
        //**********
    }
    virtual void WriteText()
    {
        //**********
    }
    virtual void Connect()
    {
        //**********
    }
};

// 手机版本
class MobileMessagerImp : public MessagerImp
{
public:
    virtual void PlaySound()
    {
        //==========
    }
    virtual void DrawShape()
    {
        //==========
    }
    virtual void WriteText()
    {
        //==========
    }
    virtual void Connect()
    {
        //==========
    }
};

// 业务抽象 m

// 普通应用
class MessagerLite : public Messager
{

public:
    virtual void Login(string username, string password)
    {

        messagerImp->Connect();
        //........
    }
    virtual void SendMessage(string message)
    {

        messagerImp->WriteText();
        //........
    }
    virtual void SendPicture(Image image)
    {

        messagerImp->DrawShape();
        //........
    }
};

// VIP等级应用
class MessagerPerfect : public Messager
{

public:
    MessagerPerfect(MessagerImp *mimp) : Messager(mimp) // 显示调用父类带参构造函数
    {
    }

    virtual void Login(string username, string password)
    {

        messagerImp->PlaySound();
        //********
        messagerImp->Connect();
        //........
    }
    virtual void SendMessage(string message)
    {

        messagerImp->PlaySound();
        //********
        messagerImp->WriteText();
        //........
    }
    virtual void SendPicture(Image image)
    {

        messagerImp->PlaySound();
        //********
        messagerImp->DrawShape();
        //........
    }
};

void Process()
{
    // 运行时装配
    MessagerImp *mImp = new PCMessagerImp();
    Messager *m = new MessagerPerfect(mImp);
}
