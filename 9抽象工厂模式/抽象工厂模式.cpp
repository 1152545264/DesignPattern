#include <bits/stdc++.h>
using namespace std;

// 数据库访问的基类
class IDBConnection
{
public:
    virtual void ConnectionString(const string &str) = 0;
};

class IDBCommand
{
public:
    virtual void CommandText(const string &str) = 0;
    virtual IDBDataReader *ExcuteReader() = 0;
};

class IDBDataReader
{
public:
    virtual string Read() = 0;
};

/*-----------------------------------------------*/

// 支持SQLServer
class SqlConnection : public IDBConnection
{
public:
    void ConnectionString() {}

    virtual void ConnectionString(const string &str)
    {
        cout << str << endl;
    }
};

class SqlCommand : public IDBCommand
{
public:
    virtual IDBDataReader *ExcuteReader() { return nullptr; }
    virtual void CommandText(const string &str) {}
};

class SqlDataReader : public IDBDataReader
{
public:
    virtual string Read() { return ""; }
};

// 支持Oracle数据库
class OracleConnection : public IDBConnection
{
public:
    void ConnectionString() {}

    virtual void ConnectionString(const string &str)
    {
        cout << str << endl;
    }
};

class OracleCommand : public IDBCommand
{
public:
    virtual IDBDataReader *ExcuteReader() { return nullptr; }
    virtual void CommandText(const string &str) {}
};

class OracleDataReader : public IDBDataReader
{
public:
    virtual string Read() { return ""; }
};

namespace Pre // 使用设计模式之前
{

    class EmployeeDAO
    {
    public:
        vector<EmployeeDAO> GetEmployees()
        {
            SqlConnection *connection = new SqlConnection();
            connection->ConnectionString("....");

            SqlCommand *command = new SqlCommand();
            command->CommandText("....");

            IDBDataReader *reader = command->ExcuteReader();
            while (true)
            {
                auto s = reader->Read();
                if (s.size() == 0)
                    break;
            }
        }
    };
};

// 使用抽象工厂模式,针对的创建一系列相互依赖的类
namespace Designpattern
{
    class IDBFactory
    {
    public:
        virtual IDBConnection *CreateDBConnection() = 0;
        virtual IDBCommand *CreateDBCommand() = 0;
        virtual IDBDataReader *CreateDataReader() = 0;
    };

    class SqlDBfactory : public IDBFactory
    {
    public:
        virtual IDBConnection *CreateDBConnection() { return new SqlConnection(); }
        virtual IDBCommand *CreateDBCommand() { return new SqlCommand(); }
        virtual IDBDataReader *CreateDataReader() { return new SqlDataReader; }
    };

    class OracleDBfactory : public IDBFactory
    {
    public:
        virtual IDBConnection *CreateDBConnection() { return new OracleConnection(); }
        virtual IDBCommand *CreateDBCommand() { return new OracleCommand(); }
        virtual IDBDataReader *CreateDataReader() { return new OracleDataReader(); }
    };

    class EmployeeDAO
    {
        IDBFactory *dbfactory;

    public:
        EmployeeDAO(IDBFactory *idb) : dbfactory(idb) {}

        vector<EmployeeDAO> GetEmployees()
        {
            IDBConnection *connection = dbfactory->CreateDBConnection();
            connection->ConnectionString("....");

            IDBCommand *command = dbfactory->CreateDBCommand();
            command->CommandText("....");

            IDBDataReader *reader = command->ExcuteReader();
            while (true)
            {
                auto s = reader->Read();
                if (s.size() == 0)
                    break;
            }
        }
    };

};

int main()
{

    return 0;
}