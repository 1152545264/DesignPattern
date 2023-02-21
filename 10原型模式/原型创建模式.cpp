#include <bits/stdc++.h>
using namespace std;

namespace Pre
{
    // 抽象类
    class ISplitter
    {
    public:
        virtual void split() = 0;
        virtual ~ISplitter() {}
    };

    // 工厂基类
    class SplitterFactory
    {
    public:
        virtual ISplitter *CreateSplitter() = 0l;
        virtual ~SplitterFactory() {}
    };

};

namespace DesignPattern
{
    // 抽象类
    class ISplitter
    {
    public:
        virtual void split() = 0;
        virtual ISplitter *clone() = 0; // 通过克隆自己来创建对象

        virtual ~ISplitter() {}
    };

    // 具体类
    class BinarySplitter : public ISplitter
    {
    public:
        virtual ISplitter *clone()
        {
            return new BinarySplitter(*this);
        }

        virtual void split()
        {
        }
    };

    class TextSplitter : public ISplitter
    {
    public:
        virtual ISplitter *clone()
        {
            return new TextSplitter(*this);
        }

        virtual void split()
        {
        }
    };

    class PictureSplitter : public ISplitter
    {
    public:
        virtual ISplitter *clone()
        {
            return new PictureSplitter(*this);
        }

        virtual void split()
        {
        }
    };

    class MainForm
    {
    public:
        ISplitter *prototype; // 保存原型对象的指针
        MainForm(ISplitter *isp) : prototype(isp) {}

        void ButtonClick()
        {
            ISplitter *spliter = this->prototype->clone(); // 克隆原型对象，不能直接使用原型对象，只能经过克隆之后使用
            spliter->split();
        }
    };

};

int main(void)
{

    return 0;
}