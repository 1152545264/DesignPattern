#include "Iterator.h"

#include <bits/stdc++.h>
using namespace std;

namespace Oth
{
    Aggregate::Aggregate()
    {
    }
    Aggregate::~Aggregate()
    {
    }

    ConcreteAggregate::ConcreteAggregate()
    {
        for (int i = 0; i < SIZE; ++i)
        {
            m_boj[i] = i;
        }
    }
    ConcreteAggregate::~ConcreteAggregate()
    {
    }

    Iterator *ConcreteAggregate::CreateIterator()
    {
        return new ConcreteIterator(this);
    }
    Object ConcreteAggregate::GetItem(int idx)
    {
        if (idx < this->GetSize())
            return m_boj[idx];
        else
            return -1;
    }
    int ConcreteAggregate::GetSize()
    {
        return SIZE;
    }

    Iterator::Iterator() {}
    Iterator::~Iterator() {}

    ConcreteIterator::ConcreteIterator(Aggregate *ag, int idx)
    {
        this->m_ag = ag;
        this->m_idx = idx;
    }
    ConcreteIterator::~ConcreteIterator()
    {
    }
    void ConcreteIterator::First()
    {
        m_idx = 0;
    }
    void ConcreteIterator::Next()
    {
        if (m_idx < m_ag->GetSize())
            ++m_idx;
    }
    bool ConcreteIterator::IsDone()
    {
        return (m_idx == m_ag->GetSize());
    }
    Object ConcreteIterator::Current()
    {
        return m_ag->GetItem(m_idx);
    }

}

int main()
{
    using namespace Oth;
    Aggregate *ag = new ConcreteAggregate();
    Iterator *it = new ConcreteIterator(ag);
    for (; !(it->IsDone()); it->Next())
    {
        cout << it->Current() << endl;
    }

    return 0;
}