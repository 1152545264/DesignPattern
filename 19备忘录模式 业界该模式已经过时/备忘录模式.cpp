#include <bits/stdc++.h>
using namespace std;

class Memento
{
    string state;

public:
    Memento(const string &s) : state(s)
    {
    }
    string GetState() const
    {
        return state;
    }
    void SetState(const string &s)
    {
        state = s;
    }
};

class Originator
{
    string state;

public:
    Originator() {}
    Memento CreateMementor()
    {
        Memento m(state);
        return m;
    }

    void SetMenmtor(const Memento &m)
    {
        state = m.GetState();
    }
};

int main()
{
    Originator org;
    // 捕获对象状态
    Memento mem = org.CreateMementor();

    // 改变org对象的状态

    // 恢复org的状态
    org.SetMenmtor(mem);

    return 0;
}