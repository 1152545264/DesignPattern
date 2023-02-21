#include <bits/stdc++.h>
using namespace std;

class Form
{
};

class ProgressBar
{
public:
    void sertValue(int value)
    {
    }
};

class IProgress // 观察者基类
{
public:
    virtual void DoProgress(float value) = 0;
    virtual ~IProgress()
    {
    }
};

class FileSplitter // 被观察者
{
    string m_filepath;
    int m_number;

    // ProgressBar *m_progressbar; // 具体通知控件，但是违反了依赖倒置原则
    list<IProgress *> m_iprogresses; // 抽象的通知机制

public:
    FileSplitter(const string &filepath,
                 int number) : m_filepath(filepath),
                               m_number(number){

                               };

    void split()
    {
        // 1读取文件

        // 2分批次想小文件中写入
        for (int i = 0; i < m_number; ++i)
        {
            //......

            float pgv = (i + 1) / float(m_number);
            onProgress(pgv);
        }
    }

    void addProgress(IProgress *ipg)
    {
        m_iprogresses.push_back(ipg);
    }

    void removeProgress(IProgress *ipg)
    {
        // for (auto it = m_iprogresses.begin(); it != m_iprogresses.end();)
        // {
        //     if (*it == ipg)
        //         it = m_iprogresses.erase(it);
        //     else
        //         ++it;
        // }
        m_iprogresses.remove(ipg);
    }

protected:
    void onProgress(float value)
    {
        for (auto m : m_iprogresses)
        {
            if (m != nullptr)
                m->DoProgress(value); // 更新进度条
        }
    }
};

class TexBox
{
public:
    string getText() { return ""; }
};

class ConsoleNotifier : public IProgress
{
public:
    virtual void DoProgress(float value)
    {
        cout << ".";
    }
};

// C++推荐的唯一多继承方式：一个主继承，多个抽象类
class MainForm : public Form, public IProgress
{
    TexBox *textFilePath;
    TexBox *textFileNumber;

    ProgressBar *m_pb;

public:
    void Button1_click()
    {
        string filePath = textFilePath->getText();
        int number = atoi(textFileNumber->getText().c_str());
        FileSplitter splitter(filePath, number);

        splitter.addProgress(this);
        splitter.split();

        splitter.removeProgress(this);
    }

    virtual void DoProgress(float value)
    {
        m_pb->sertValue(value);
        cout << '.';
    }
};

int main()
{

    return 0;
}