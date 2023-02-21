#include <bits/stdc++.h>
using namespace std;

class House
{
public:
    House() {}                    // 默认构造函数
    House(const House &ot) {}     // 拷贝构造函数
    House operator=(House &ot) {} // 重载赋值运算符
};

class HouseBuilder
{
public:
    HouseBuilder(House *pHouse)
    {
        this->pHouse = pHouse;
    }

    virtual ~HouseBuilder()
    {
    }

    House *GetResult()
    {
        return pHouse;
    }

    virtual void BuildPart1() = 0;
    virtual void BuildPart2() = 0;
    virtual bool BuildPart3() = 0;
    virtual void BuildPart4() = 0;
    virtual void BuildPart5() = 0;

protected:
    House *pHouse;
};

class StoneHouse : public House
{
};

class StoneHouseBuilder : public HouseBuilder
{
public:
    // StoneHouseBuilder(House *pHouse) : House(pHouse) {}
    StoneHouseBuilder(House *pHouse) : HouseBuilder(pHouse) {}

    virtual void BuildPart1()
    {
        cout << "Buiild Stone House Part1" << endl;
    }
    virtual void BuildPart2() { cout << "Buiild Stone House Part2" << endl; }
    virtual bool BuildPart3()
    {
        cout << "Buiild Stone House Part3" << endl;
        return true;
    }
    virtual void BuildPart4() { cout << "Buiild Stone House Part4" << endl; }
    virtual void BuildPart5() { cout << "Buiild Stone House Part5" << endl; }
};

class HouseDirector // HouseBuilder的装饰器模式
{
public:
    HouseBuilder *pHouseBuilder;

    HouseDirector(HouseBuilder *pHouseBuilder) : pHouseBuilder(pHouseBuilder)
    {
    }

    House *Construct()
    {
        pHouseBuilder->BuildPart1();
        for (int i = 0; i < 4; ++i)
            pHouseBuilder->BuildPart2();
        bool flag = pHouseBuilder->BuildPart3();
        if (flag)
            pHouseBuilder->BuildPart4();
        pHouseBuilder->BuildPart5();

        return pHouseBuilder->GetResult();
    }
};

int main()
{
    auto pHouse = new StoneHouse();
    auto pBuilder = new StoneHouseBuilder(pHouse);
    auto pDirector = new HouseDirector(pBuilder);
    pDirector->Construct();

    return 0;
}