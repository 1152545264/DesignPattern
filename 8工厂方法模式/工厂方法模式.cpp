#include <bits/stdc++.h>
using namespace std;

class ISplitter
{
public:
    virtual void split() = 0;
    virtual ~ISplitter() {}
};

// 具体类
class BinarySplitter : public ISplitter
{
public:
    virtual void split()
    {
    }
};

class TxtSplitter : public ISplitter
{
public:
    virtual void split()
    {
    }
};

class PictureSplitter : public ISplitter
{
public:
    virtual void split()
    {
    }
};

class VideoSplitter : public ISplitter
{
public:
    virtual void split()
    {
    }
};

class SplitterFactoy
{
public:
    // ISplitter *CreateSpliter()
    // {
    //     return new BinarySplitter(); // 依赖于具体类了
    // }
    virtual ISplitter *CreateSplitter() = 0;
    virtual ~SplitterFactoy() {}
};

class BinarySplitterFactor : public SplitterFactoy
{
public:
    virtual ISplitter *CreateSplitter()
    {
        return new BinarySplitter();
    }
};

class TxtSplitterFactor : public SplitterFactoy
{
public:
    virtual ISplitter *CreateSplitter()
    {
        return new TxtSplitter();
    }
};
class BinarySplitterFactor : public SplitterFactoy
{
public:
    virtual ISplitter *CreateSplitter()
    {
        return new BinarySplitter();
    }
};
class PictureSplitterFactor : public SplitterFactoy
{
public:
    virtual ISplitter *CreateSplitter()
    {
        return new PictureSplitter();
    }
};
class VideoSplitterFactor : public SplitterFactoy
{
public:
    virtual ISplitter *CreateSplitter()
    {
        return new VideoSplitter();
    }
};

class Form
{
};
class TextBox
{
};
class ProgressBar
{
};

class MainForm : public Form
{
    TextBox *txtFilePath;
    TextBox *txtFileNumber;
    ProgressBar *progressBar;

    SplitterFactoy *factory;

public:
    MainForm(SplitterFactoy *factory) : factory(factory) {} // 根据传进来的factor类型来创建splitter

    void Button1_Click()
    {

        // ISplitter *splitter =
        //     new BinarySplitter(); // 依赖具体类

        ISplitter *splitter = factory->CreateSplitter(); // 多态new
        splitter->split();
    }
};

int main()
{

    return 0;
}