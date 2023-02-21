#include <bits/stdc++.h>
using namespace std;

class Component
{
public:
    virtual void process() = 0;
    virtual ~Component() {}
};

// 树节点
class Composite : public Component
{
    string name;
    list<Component *> elememts;

public:
    Composite(const string &s) : name(s) {}

    void add(Component *element)
    {
        elememts.push_back(element);
    }

    void remove(Component *element)
    {
        elememts.remove(element);
    }

    void process()
    {
        // 处理当前节点
        cout << "当前树结点的name为: " << name << endl;

        // 处理其他节点
        for (auto &e : elememts)
        {
            e->process();
        }
    }
};

class Leaf : public Component
{
    string name;

public:
    Leaf(const string &s) : name(s)
    {
    }

    void process()
    {
        // 处理当前节点
        cout << "当前叶子结点的name为: " << name << endl;
    }
};

int main()
{
    Composite root("root");
    Composite Node1("Node1");
    Composite Node2("Node2");
    Composite Node3("Node3");
    Composite Node4("Node4");

    Leaf leaf1("Lef1");
    Leaf leaf2("Lef2");
    Leaf leaf3("Lef3");
    Leaf leaf4("Lef4");

    root.add(&Node1);
    Node1.add(&Node2);
    Node2.add(&leaf1);
    Node2.add(&Node3);
    Node2.add(&Node4);
    Node3.add(&leaf3);
    Node3.add(&leaf4);

    root.process();

    return 0;
}