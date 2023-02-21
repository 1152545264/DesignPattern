#include <bits/stdc++.h>
using namespace std;

class Subsystem1
{
public:
    Subsystem1() {}
    ~Subsystem1() {}
    void Operation()
    {
        cout << "子系统1的操作" << endl;
    }
};

class Subsystem2
{
public:
    Subsystem2() {}
    ~Subsystem2() {}
    void Operation()
    {
        cout << "子系统2的操作" << endl;
    }
};

class Facade
{
public:
    Facade()
    {
        sub1 = new Subsystem1();
        sub2 = new Subsystem2();
    }
    ~Facade()
    {
        delete sub1;
        delete sub2;
    }

    void OperationWrapper()
    {
        this->sub1->Operation();
        this->sub2->Operation();
    }

private:
    Subsystem1 *sub1;
    Subsystem2 *sub2;
};

int main()
{

    auto fa = new Facade();
    fa->OperationWrapper();
    return 0;
}