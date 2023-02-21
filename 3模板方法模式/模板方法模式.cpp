
#include <bits/stdc++.h>
using namespace std;

class AbstractClass
{
public:
    virtual ~AbstractClass() {}

    void TemplateMethod()
    {
        this->PrimitiveOperation1();
        this->PrimitiveOperation2();
    }

protected:
    virtual void PrimitiveOperation1() = 0;
    virtual void PrimitiveOperation2() = 0;

    AbstractClass() {}
};

class ConcreteClass1 : public AbstractClass
{
public:
    ConcreteClass1() {}
    ~ConcreteClass1() {}

protected:
    virtual void PrimitiveOperation1() override
    {
        cout << "ConcreteClass1.......PrimitiveOperation1" << endl;
    }
    virtual void PrimitiveOperation2() override
    {
        cout << "ConcreteClass1.......PrimitiveOperation2" << endl;
    }
};

class ConcreteClass2 : public AbstractClass
{
public:
    ConcreteClass2() {}
    ~ConcreteClass2() {}

protected:
    virtual void PrimitiveOperation1() override
    {
        cout << "ConcreteClass2.......PrimitiveOperation1" << endl;
    }
    virtual void PrimitiveOperation2() override
    {
        cout << "ConcreteClass2.......PrimitiveOperation2" << endl;
    }
};

class ConcreteClass3 : public AbstractClass
{
public:
    ConcreteClass3() {}
    ~ConcreteClass3() {}

protected:
    virtual void PrimitiveOperation1() override
    {
        cout << "ConcreteClass3.......PrimitiveOperation1" << endl;
    }
    virtual void PrimitiveOperation2() override
    {
        cout << "ConcreteClass3.......PrimitiveOperation2" << endl;
    }
};

class ConcreteClass4 : public AbstractClass
{
public:
    ConcreteClass4() {}
    ~ConcreteClass4() {}

protected:
    virtual void PrimitiveOperation1() override
    {
        cout << "ConcreteClass4.......PrimitiveOperation1" << endl;
    }
    virtual void PrimitiveOperation2() override
    {
        cout << "ConcreteClass4.......PrimitiveOperation2" << endl;
    }
};

int main()
{
    AbstractClass *a1 = new ConcreteClass1();
    AbstractClass *a2 = new ConcreteClass2();
    AbstractClass *a3 = new ConcreteClass3();
    AbstractClass *a4 = new ConcreteClass4();

    vector<AbstractClass *> vec;

    vec.emplace_back(a1);
    vec.emplace_back(a2);
    vec.emplace_back(a3);
    vec.emplace_back(a4);

    for (const auto &c : vec)
    {
        c->TemplateMethod(); // 通过统一的接口实现多态
    }
    return 0;
}