// 参考自：https://blog.csdn.net/wuzhekai1985/article/details/6673603
#include <bits/stdc++.h>
using namespace std;

class Mediator; // 中介类前置声明

// 抽象人
class Person
{
protected:
    Mediator *m_mediator; // 中介
public:
    virtual void SetMediator(Mediator *mediator) = 0; // 设置中介
    virtual void SendMessage(string message) = 0;     // 向中介发送信息
    virtual void GetMessage(string message) = 0;      // 从中介获取信息
};

// 抽象中介机构
class Mediator
{
public:
    virtual void Send(string message, Person *person) = 0; //前置声明类的API必须在使用之前完成声明，\
    否则会报错：invalid use of incomplete type ‘class Mediator’
    virtual void SetPair(Person *A, Person *B) = 0;

protected:
    unordered_map<Person *, Person *> mp;
};

// 租房者
class Renter : public Person
{
public:
    void SetMediator(Mediator *mediator) { m_mediator = mediator; }
    void SendMessage(string message) { m_mediator->Send(message, this); }
    void GetMessage(string message) { cout << "租房者收到信息" << message; }
};

// 房东
class Landlord : public Person
{
public:
    void SetMediator(Mediator *mediator) { m_mediator = mediator; }
    void SendMessage(string message) { m_mediator->Send(message, this); }
    void GetMessage(string message) { cout << "房东收到信息：" << message; }
};

// 房屋中介
class HouseMediator : public Mediator
{

public:
    HouseMediator() { mp = unordered_map<Person *, Person *>(); }
    void SetPair(Person *A, Person *B)
    {
        mp[A] = B;
        mp[B] = A;
    }

    void Send(string message, Person *person) // person发送消息，
    {
        mp[person]->GetMessage(message);
    }
};

// 测试案例
int main()
{
    Mediator *mediator = new HouseMediator();
    Person *person1 = new Renter();   // 租房者
    Person *person2 = new Landlord(); // 房东
    person1->SetMediator(mediator);
    person2->SetMediator(mediator);
    mediator->SetPair(person1, person2);

    person1->SendMessage("我想在南京路附近租套房子，价格800元一个月\n");
    person2->SendMessage("出租房子：南京路100号，70平米，1000元一个月\n");

    delete person1;
    delete person2;
    delete mediator;
    return 0;
}