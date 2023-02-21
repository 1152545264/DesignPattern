#include <bits/stdc++.h>
using namespace std;

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
    virtual ~NetworkState();
};

class OpenState : public NetworkState
{
    static NetworkState *m_instance;

public:
    static NetworkState *GetInstance();

    virtual void Operation1();
    virtual void Operation2();
    virtual void Operation3();
};

class CloseState : public NetworkState
{
    static NetworkState *m_instance;

public:
    static NetworkState *GetInstance();

    virtual void Operation1();
    virtual void Operation2();
    virtual void Operation3();
};

class ConnectState : public NetworkState
{
    static NetworkState *m_instance;

public:
    static NetworkState *GetInstance();

    virtual void Operation1();
    virtual void Operation2();

    virtual void Operation3();
};

class NetWorkProcess
{
    NetworkState *pState;

public:
    NetWorkProcess(NetworkState *pState);

    void Operation1();
    void Operation2();
    void Operation3();
};