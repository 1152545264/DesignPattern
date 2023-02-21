#include <bits/stdc++.h>
using namespace std;

class ITarget // 目标接口（新接口）
{
public:
    virtual void process() = 0;
};

class IAdaptee // 遗留接口(老接口)
{
public:
    virtual void foo(int data) = 0;
    virtual int bar() = 0;
};

// 遗留类型
class OldClass : public IAdaptee
{
public:
    virtual void foo(int data)
    {
        cout << "遗留类的foo接口: " << data << endl;
    }
    virtual int bar()
    {
        cout << "遗留类的bar接口" << endl;
        return 1;
    }
};

class Adapter : public ITarget // 继承
{
protected:
    IAdaptee *pAdptee; // 组合对象，称之为对象适配器，GOF还提出了另一种类适配器，但是不推荐使用类适配，\
    因为类适配器是通过多继承实现的且缺乏灵活性

public:
    Adapter(IAdaptee *adp)
    {
        this->pAdptee = adp;
    }
    virtual void process()
    {
        cout << "新接口类process函数被调用" << endl;
        int data = pAdptee->bar();
        pAdptee->foo(data);
    }
};

int main()
{
    IAdaptee *p = new OldClass();
    ITarget *ap = new Adapter(p);
    ap->process();
    return 0;
}