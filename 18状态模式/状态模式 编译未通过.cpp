#include <bits/stdc++.h>
using namespace std;

namespace StatePre // 使用状态模式之前的写法
{
    enum NetWorkState
    {
        NetworkOpen,
        NetworkClose,
        NetworkConnect
    };

    class NetworkProcessor
    {
        NetWorkState state;

    public:
        void operation1()
        {
            if (state == NetworkOpen)
            {
                //.............做一些处理操作
                state = NetworkClose;
            }
            else if (state == NetworkClose)
            {
                //.............做一些处理操作
                state = NetworkConnect;
            }
            else if (state == NetworkConnect)
            {
                //.............做一些处理操作
                state = NetworkOpen;
            }
        }

        void operation2()
        {
            if (state == NetworkOpen)
            {
                //.............做一些处理操作
                state = NetworkConnect;
            }
            else if (state == NetworkClose)
            {
                //.............做一些处理操作
                state = NetworkConnect;
            }
            else if (state == NetworkConnect)
            {
                //.............做一些处理操作
                state = NetworkClose;
            }
        }

        void Operation3()
        {
        }
    };

} // namespace StatePre

namespace StatePattern // 使用状态对象来管理状态
{
    class NetWorkProcess;
    class NetworkState
    {
    protected:
        NetworkState *nextState;
        friend class NetWorkProcess;

    public:
        virtual void Operation1() = 0;
        virtual void Operation2() = 0;
        virtual void Operation3() = 0;
        virtual ~NetworkState() {}
    };

    class OpenState : public NetworkState
    {
        static NetworkState *m_instance;

    public:
        static NetworkState *GetInstance()
        {
            if (m_instance == nullptr)
            {
                m_instance = new OpenState();
            }
            return m_instance;
        }

        virtual void Operation1()
        {
            //.............做一些处理操作
            nextState = CloseState::GetInstance();
        }
        virtual void Operation2()
        {
            //.............做一些处理操作

            nextState = ConnectState::GetInstance();
        }

        virtual void Operation3()
        {
            //.............做一些处理操作
            nextState = OpenState::GetInstance();
        }
    };

    class CloseState : public NetworkState
    {
        static NetworkState *m_instance;

    public:
        static NetworkState *GetInstance()
        {
            if (m_instance == nullptr)
            {
                m_instance = new CloseState();
            }
            return m_instance;
        }

        virtual void Operation1()
        {
            //.............做一些处理操作

            nextState = OpenState::GetInstance();
        }

        virtual void Operation2()
        {
            //.............做一些处理操作
            nextState = ConnectState::GetInstance();
        }

        virtual void Operation3()
        {
            //.............做一些处理操作
            nextState = CloseState::GetInstance();
        }
    };

    class ConnectState : public NetworkState
    {
        static NetworkState *m_instance;

    public:
        static NetworkState *GetInstance()
        {
            if (m_instance == nullptr)
            {
                m_instance = new OpenState();
            }
            return m_instance;
        }

        virtual void Operation1()
        {
            //.............做一些处理操作
            nextState = CloseState::GetInstance();
        }
        virtual void Operation2()
        {
            //.............做一些处理操作
            nextState = OpenState::GetInstance();
        }

        virtual void Operation3()
        {
            //.............做一些处理操作
            nextState = ConnectState::GetInstance();
        }
    };

    class NetWorkProcess
    {
        NetworkState *pState;

    public:
        NetWorkProcess(NetworkState *pState)
        {
            this->pState = pState;
        }

        void Operation1()
        {
            pState->Operation1();
            pState = pState->nextState;
        }

        void Operation2()
        {
            pState->Operation2();
            pState = pState->nextState;
        }

        void Operation3()
        {
            pState->Operation3();
            pState = pState->nextState;
        }
    };
}

int main()
{

    return 0;
}