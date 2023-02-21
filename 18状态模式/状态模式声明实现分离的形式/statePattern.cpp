#include "statePattern.h"

NetworkState::~NetworkState()
{
}

NetworkState *OpenState::GetInstance()
{
    if (m_instance == nullptr)
    {
        m_instance = new OpenState();
    }
    return m_instance;
}

void OpenState::Operation1()
{
    //.............做一些处理操作
    nextState = CloseState::GetInstance();
}

void OpenState::Operation2()
{
    //.............做一些处理操作

    nextState = ConnectState::GetInstance();
}

void OpenState::Operation3()
{
    //.............做一些处理操作
    nextState = OpenState::GetInstance();
}

NetworkState *CloseState::GetInstance()
{
    if (m_instance == nullptr)
    {
        m_instance = new CloseState();
    }
    return m_instance;
}

void CloseState::Operation1()
{
    //.............做一些处理操作

    nextState = OpenState::GetInstance();
}

void CloseState::Operation2()
{
    //.............做一些处理操作
    nextState = ConnectState::GetInstance();
}

void CloseState::Operation3()
{
    //.............做一些处理操作
    nextState = CloseState::GetInstance();
}

NetworkState *ConnectState::GetInstance()
{
    if (m_instance == nullptr)
    {
        m_instance = new OpenState();
    }
    return m_instance;
}

void ConnectState::Operation1()
{
    //.............做一些处理操作
    nextState = CloseState::GetInstance();
}

void ConnectState::Operation2()
{
    //.............做一些处理操作
    nextState = OpenState::GetInstance();
}

void ConnectState::Operation3()
{
    //.............做一些处理操作
    nextState = ConnectState::GetInstance();
}

NetWorkProcess::NetWorkProcess(NetworkState *pState)
{
    this->pState = pState;
}

void NetWorkProcess::Operation1()
{
    pState->Operation1();
    pState = pState->nextState;
}

void NetWorkProcess::Operation2()
{
    pState->Operation2();
    pState = pState->nextState;
}

void NetWorkProcess::Operation3()
{
    pState->Operation3();
    pState = pState->nextState;
}


