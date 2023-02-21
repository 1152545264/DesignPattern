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

class FileSplitter
{
    string m_filepath;
    int m_number;

    ProgressBar *m_progressbar; // 违反了依赖倒置原则

public:
    FileSplitter(const string &filepath,
                 int number,
                 ProgressBar *pb) : m_filepath(filepath),
                                    m_number(number),
                                    m_progressbar(pb){

                                    };

    void split()
    {
        // 1读取文件

        // 2分批次想小文件中写入
        for (int i = 0; i < m_number; ++i)
        {
            //......
            if (m_progressbar != nullptr)
                m_progressbar->sertValue((i + 1) / m_number);
        }
    }
};

class TexBox
{
public:
    string getText() { return ""; }
};

class MainForm : public Form
{
    TexBox *textFilePath;
    TexBox *textFileNumber;

    ProgressBar *progressbar;

public:
    void Button1_click()
    {
        string filePath = textFilePath->getText();
        int number = atoi(textFileNumber->getText().c_str());
        FileSplitter splitter(filePath, number, progressbar);
        splitter.split();
    }
};

int main()
{

    return 0;
}