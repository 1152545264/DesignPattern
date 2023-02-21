#include <bits/stdc++.h>
#include <mutex>
using namespace std;

// 懒汉式1，适用于单线程
namespace Lazy1
{
    class Singleton
    {
    private:
        Singleton() {}
        Singleton(const Singleton &oth) = delete;
        static Singleton *m_instance; // 静态实例指针的声明,此处声明为私有也能正常工作，属实让我有点迷惑

    public:
        static Singleton *GetInstance();
        void Printinfo()
        {
            cout << "单线程版懒汉式单例模式" << endl;
        }
    };

    Singleton *Singleton::m_instance = nullptr; // 静态实例指针的初始化，此处竟能访问累的私有变量？？
    Singleton *Singleton::GetInstance()
    {
        if (m_instance == nullptr)
            m_instance = new Singleton;
        return m_instance;
    }
};

// 懒汉式2，线程安全版本，但是高并发场景性能会受损
namespace Lazy2
{
    // mutex mtx;
    class Singleton
    {
    private:
        Singleton() {}
        Singleton(const Singleton &oth) = delete;
        static mutex mtx;             // 声明静态锁
        static Singleton *m_instance; // 声明静态实例指针

    public:
        static Singleton *GetInstance();
    };

    Singleton *Singleton::m_instance = nullptr;
    std::mutex Singleton::mtx;

    Singleton *Singleton::GetInstance()
    {

        std::lock_guard<std::mutex> lock(mtx);
        if (m_instance == nullptr)
            m_instance = new Singleton();
        return m_instance;
    }
};

// 懒汉式3：双重检查锁，一般不建议这么使用，很大概率会因为指令重排序导致工作异常
namespace Lazy3
{
    class Singleton
    {
    private:
        Singleton() {}
        Singleton(const Singleton &oth) = delete;
        static mutex mtx;             // 声明静态锁
        static Singleton *m_instance; // 声明静态实例指针

    public:
        static Singleton *GetInstance();
    };

    Singleton *Singleton::m_instance = nullptr; // 初始化静态实例指针
    std::mutex Singleton::mtx;                  // 初始化静态局部锁
    Singleton *Singleton::GetInstance()
    {

        if (m_instance == nullptr) // 第一重检查
        {
            std::lock_guard<std::mutex> lock(mtx);
            if (m_instance == nullptr) // 第二重检查
                m_instance = new Singleton();
        }

        return m_instance;
    }
};

// 懒汉式4，适用于C++11及以后，使用内存屏障避免指令重排序，源自极客班C++设计模式课程
namespace Lazy4
{
    class Singleton
    {
    private:
        Singleton() {}
        Singleton(const Singleton &oth) = delete;
        static mutex mtx;                      // 声明静态锁
        static atomic<Singleton *> m_instance; // 声明静态实例指针

    public:
        static Singleton *GetInstance();
    };

    atomic<Singleton *> Singleton::m_instance = nullptr; // 初始化静态锁
    std::mutex Singleton::mtx;                           // 初始化静态实例指针

    Singleton *Singleton::GetInstance()
    {
        auto tmp = m_instance.load(std::memory_order_relaxed);
        std::atomic_thread_fence(std::memory_order_acquire); // 获取内存fence(即内存屏障)，避免指令重排序
        if (tmp == nullptr)
        {
            std::lock_guard<std::mutex> lock(mtx);
            tmp = m_instance.load(std::memory_order_relaxed);
            if (tmp == nullptr)
            {
                tmp = new Singleton;
                std::atomic_thread_fence(std::memory_order_release);
            }
            m_instance.store(tmp, std::memory_order_relaxed);
        }
        return m_instance;
    }
};

// 饿汉式，使用局部静态变量，参考自https://blog.csdn.net/weixin_39770712/article/details/110925745
namespace Hungry
{
    class Singleton
    {
    private:
        Singleton() { cout << "懒汉式单例模式之静态变量实现方式" << endl; }
        Singleton(const Singleton &oth) = delete;

    public:
        static Singleton &GetInstace();
        void PrintInfo()
        {
            cout << "测试成功" << endl;
        }
    };

    Singleton &Singleton::GetInstace()
    {
        static Singleton m_instance;
        return m_instance;
    }
};

int main()
{
    Hungry::Singleton &st = Hungry::Singleton::GetInstace();
    st.PrintInfo();

    auto st2 = Lazy1::Singleton::GetInstance();
    st2->Printinfo();

    return 0;
}