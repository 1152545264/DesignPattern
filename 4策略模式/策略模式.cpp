#include <bits/stdc++.h>
using namespace std;

class Strategy
{
public:
    Strategy() {}
    virtual ~Strategy()
    {
        cout << "~Strategy" << endl;
    }

    virtual void AlgorithmInterface() {}
};

class ConCreteStrategyA : public Strategy
{
public:
    ConCreteStrategyA() {}
    virtual ~ConCreteStrategyA()
    {
        cout << "~ConCreteStrategyA" << endl;
    }

    virtual void AlgorithmInterface() override
    {
        cout << " Test the function of AlgorithmInterface ConCreteStrategyA" << endl;
    }
};

class ConCreteStrategyB : public Strategy
{
public:
    ConCreteStrategyB() {}
    virtual ~ConCreteStrategyB()
    {
        cout << "~ConCreteStrategyB" << endl;
    }

    virtual void AlgorithmInterface() override
    {
        cout << " Test the function of AlgorithmInterface ConCreteStrategyB" << endl;
    }
};

class Context
{
public:
    Context(Strategy *stg)
    {
        this->m_stg = stg;
    }
    ~Context()
    {
        if (m_stg != nullptr)
        {
            delete m_stg;
        }
        cout << "~Context" << endl;
    }

    void Reset(Strategy *stg)
    {
        if (m_stg != nullptr)
        {
            delete m_stg;
        }
        m_stg = stg;
    }

    void doAction()
    {
        m_stg->AlgorithmInterface();
    }

private:
    Strategy *m_stg;
};

int main()
{
    Strategy *s1 = new ConCreteStrategyA();
    Context *c = new Context(s1);
    c->doAction();

    c->Reset(new ConCreteStrategyB());
    c->doAction();

    delete c;

    return 0;
}