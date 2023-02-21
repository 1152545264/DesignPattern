#include <bits/stdc++.h>
using namespace std;

enum class RequestTYpe
{
    REQ_HANDLER1,
    REQ_HANDLER2,
    REQ_HANDLER3
};

class Request
{
    string description;
    RequestTYpe reqType;

public:
    Request(const string &desc, RequestTYpe type) : description(desc), reqType(type) {}
    RequestTYpe GetReqType() const { return reqType; }
    const string &GetDescription() const { return description; }
};

class ChainHandler
{
    ChainHandler *nextChain;
    void SenRequestToNextHandler(const Request &req)
    {
        if (nextChain != nullptr)
        {
            nextChain->handle(req);
        }
    }

protected:
    virtual bool canHandleRequest(const Request &req) = 0;
    virtual void processRequest(const Request &req) = 0;

public:
    ChainHandler() { nextChain = nullptr; }
    void setNextChain(ChainHandler *next) { nextChain = next; }

    void handle(const Request &req)
    {
        if (canHandleRequest(req))
        {
            processRequest(req);
        }
        else
        {
            SenRequestToNextHandler(req);
        }
    }
};

class Handler1 : public ChainHandler
{
protected:
    bool canHandleRequest(const Request &req)
    {
        return req.GetReqType() == RequestTYpe::REQ_HANDLER1;
    }
    void processRequest(const Request &req)
    {
        cout << "Handle1 is handleRequest: " << req.GetDescription() << endl;
    }
};

class Handler2 : public ChainHandler
{
protected:
    bool canHandleRequest(const Request &req)
    {
        return req.GetReqType() == RequestTYpe::REQ_HANDLER2;
    }
    void processRequest(const Request &req)
    {
        cout << "Handle2 is handleRequest: " << req.GetDescription() << endl;
    }
};

class Handler3 : public ChainHandler
{
protected:
    bool canHandleRequest(const Request &req)
    {
        return req.GetReqType() == RequestTYpe::REQ_HANDLER3;
    }
    void processRequest(const Request &req)
    {
        cout << "Handle3 is handleRequest: " << req.GetDescription() << endl;
    }
};

int main()
{
    Handler1 h1;
    Handler2 h2;
    Handler3 h3;

    h1.setNextChain(&h2);
    h2.setNextChain(&h3);

    Request req1("precess task....", RequestTYpe::REQ_HANDLER2);
    Request req2("precess task....", RequestTYpe::REQ_HANDLER1);
    Request req3("precess task....", RequestTYpe::REQ_HANDLER3);

    h1.handle(req1);
    h1.handle(req2);
    h1.handle(req3);

    return 0;
}