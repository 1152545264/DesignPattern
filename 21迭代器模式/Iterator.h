#include <bits/stdc++.h>
using namespace std;

namespace JIKE // 极客班的实现
{
    template <class T>
    class Iterator
    {
    public:
        virtual void first() = 0;
        virtual void next() = 0;
        virtual bool isDone() = 0;
        virtual T &current() = 0;
    };

    template <class T>
    class MyCollection
    {
    public:
        MyCollection()
        {
            m_it == nullptr;
        }

        Iterator<T> *GetIter()
        {
            return m_it;
        }

    private:
        Iterator<T> *m_it;
    };

    template <class T>
    class CollectionIterator : public Iterator<T>
    {
        MyCollection<T> mc;

    public:
        CollectionIterator(const MyCollection<T> &c) : mc(c) {}
        virtual void first() override
        {
        }
        virtual void next() override
        {
        }
        virtual bool isDone() override
        {
            return true;
        }
        virtual T &current() override
        {
        }
    };

    void Algorothm()
    {
        MyCollection<int> mc;
        Iterator<int> *it = mc.GetIter();

        for (it->first(); !(it->isDone()); it->next())
        {
            cout << it->current() << endl;
        }
    }
}

namespace Oth // 其他实现
{
    class Iterator;
    using Object = int;

    class Aggregate
    {
    public:
        virtual ~Aggregate();

        virtual Iterator *CreateIterator() = 0;
        virtual Object GetItem(int idx) = 0;
        virtual int GetSize() = 0;

    protected:
        Aggregate();
    };

    class ConcreteAggregate : public Aggregate
    {
    public:
        enum
        {
            SIZE = 3
        };

        ConcreteAggregate();
        ~ConcreteAggregate();

        Iterator *CreateIterator() override;
        Object GetItem(int idx) override;
        int GetSize() override;

    protected:
    private:
        Object m_boj[SIZE];
    };

    class Iterator
    {
    public:
        virtual ~Iterator() = 0;
        virtual void First() = 0;
        virtual void Next() = 0;
        virtual bool IsDone() = 0;
        virtual Object Current() = 0;

    protected:
        Iterator();
    };

    class ConcreteIterator : public Iterator
    {
    public:
        /*
        针对函数声明和实现分开的场景，形参默认值只能在声明时或者实现时带上，
        不能两者都加上，否则会报错：error: default argument given 
        for parameter 2 of ***
        参考自：https://blog.csdn.net/liu_feng_zi_/article/details/117442738
        */
        ConcreteIterator(Aggregate *ag, int idx=0);
        virtual ~ConcreteIterator();

        virtual void First() override;
        virtual void Next() override;
        virtual bool IsDone() override;
        virtual Object Current() override;

    protected:
    private:
        Aggregate *m_ag; // 容器类
        int m_idx;
    };
}
