#include <bits/stdc++.h>
using namespace std;

class ISubject
{
public:
    virtual ~ISubject() {}
    virtual void Request() = 0;

protected:
    ISubject() {}
};

class ConcreteSubject : public ISubject
{
public:
    ConcreteSubject() {}
    virtual ~ConcreteSubject() {}
    virtual void Request() override
    {
        cout << "具体Subject类响应申请" << endl;
    }
};

//***********************************************

// class IProxy : public ISubject
// {
// public:
//     ~IProxy() {}

// protected:
//     IProxy() {}
// };

using IProxy = ISubject; // C++11的写法

//***********************************************

class Proxy : public IProxy // 此处搞个继承主要是为了实现多级代理，类似于装饰器模式中的多级装饰，Proxy同理
{
public:
    Proxy(ISubject *sub)
    {
        this->m_sub = sub;
    }

    virtual ~Proxy() {}
    virtual void Request() override
    {
        cout << "一级代理发起申请" << endl;
        this->m_sub->Request();
    }

private:
    ISubject *m_sub;
};

class Proxy2 : public IProxy
{
public:
    Proxy2(ISubject *sub)
    {
        this->m_sub = sub;
    }

    virtual ~Proxy2() {}
    virtual void Request() override
    {
        cout << "二级代理发起申请" << endl;
        this->m_sub->Request();
    }

private:
    ISubject *m_sub;
};

class Client
{
public:
    Client()
    {
    }
    ~Client()
    {
    }

    void Request(IProxy *pro)
    {
        cout << "客户端发起申请" << endl;
        pro->Request();
    }
};

int main()
{
    ISubject *sub = new ConcreteSubject();
    Proxy *pro = new Proxy(sub);
    Proxy2 *pro2 = new Proxy2(pro);

    auto cl = new Client();
    cl->Request(pro2);

    return 0;
}