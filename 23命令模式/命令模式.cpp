//
// Created by Administrator on 2023/2/20.
//
#include<bits/stdc++.h>

using namespace std; //这个模式极其绕。需要多看几遍

namespace JIKE {
    class Command {
    public:
        virtual void Execute() = 0;
    };

    class ConcreteCommand1 : public Command {
        string args;
    public:
        ConcreteCommand1(const string &a) : args(a) {}

        virtual void Execute() override {
            cout << "#1 process ....." << args << endl;
        }
    };

    class ConcreteCommand2 : public Command {
        string args;
    public:
        ConcreteCommand2(const string &a) : args(a) {}

        virtual void Execute() override {
            cout << "#2 process ....." << args << endl;
        }
    };

    class MacroCommand : public Command {
        vector<Command *> commands;
    public:
        void addCommand(Command *c) {
            commands.push_back(c);
        }

        virtual void Execute() override {
            for (auto &c: commands) {
                c->Execute();
            }
        }
    };


    void Function() {
        ConcreteCommand1 c1("Args ####");
        ConcreteCommand2 c2("Args $$$$");

        MacroCommand macro;
        macro.addCommand(&c1);
        macro.addCommand(&c2);

        macro.Execute();
    }
}

namespace OTH { //命令模式的其他实现方式
    class Reciever {
    public:
        Reciever() {

        }

        ~Reciever() {

        }


        void Action() {
            cout << "Reciever action ........." << endl;
        }
    };

    class Command {
    public:
        virtual ~Command() {}

        virtual void Execute() = 0;

    protected:
        Command() {}
    };

    class ConcreteCommand : public Command {
    public:
        ConcreteCommand(Reciever *rev) {
            this->m_rev = rev;
        }

        virtual ~ConcreteCommand() {
            delete this->m_rev;
        }

        virtual void Execute() override {
            m_rev->Action();
            cout << "ConcreteCommand....." << endl;
        }

    protected:
        Reciever *m_rev;
    };

    class Invoker {
    public:
        Invoker(Command *cmd) {
            this->m_cmd = cmd;
        }

        ~Invoker() {
            delete m_cmd;
        }

        void Invoke() {
            this->m_cmd->Execute();
        }

    private:
        Command *m_cmd;
    };

    void Function() {
        Reciever *rev = new Reciever();
        Command *cmd = new ConcreteCommand(rev);
        Invoker *inv = new Invoker(cmd);
        inv->Invoke();
    }
}

int main() {

//    JIKE::Function();
    OTH::Function();
    return 0;
}