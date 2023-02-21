#include <bits/stdc++.h>
using namespace std;

class Visitor;

class Element
{
public:
    virtual void accept(Visitor &visitor) = 0;
    virtual ~Element() {}
};

class ElementA;
class ElementB;

class Visitor
{
public:
    virtual void visitElementA(ElementA &element) = 0;
    virtual void visitElementB(ElementB &element) = 0;

    virtual ~Visitor() {}
};

class ElementA : public Element
{
public:
    void accept(Visitor &visitor) override
    {
        visitor.visitElementA(*this);
    }
};

class ElementB : public Element
{
public:
    virtual void accept(Visitor &visitor) override
    {
        visitor.visitElementB(*this); // 第二次形态辨析
    }
};

// 扩展1
class Visitor1 : public Visitor
{
public:
    virtual void visitElementA(ElementA &element) override
    {
        cout << "Visitor is processing the ElementA" << endl;
    }

    virtual void visitElementB(ElementB &element) override
    {
        cout << "Visitor is processing the ElementB" << endl;
    }
};

// 扩展2
class Visitor2 : public Visitor
{
public:
    virtual void visitElementA(ElementA &element) override
    {
        cout << "Visitor is processing the ElementA" << endl;
    }

    virtual void visitElementB(ElementB &element) override
    {
        cout << "Visitor is processing the ElementB" << endl;
    }
};

int main()
{
    Visitor1 visitor;

    ElementB elementB;
    elementB.accept(visitor); // 两次分发

    ElementA elementA;
    elementA.accept(visitor); // 两次分发

    return 0;
}