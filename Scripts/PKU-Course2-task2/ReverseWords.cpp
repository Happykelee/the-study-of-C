/*
【单词翻转】
来源: POJ
注意：总时间限制: 1000ms 内存限制: 65536kB
描述：输入一个句子（一行），将句子中的每一个单词翻转后输出。
输入：只有一行，为一个字符串，不超过500个字符。单词之间以空格隔开。所谓单词指的是所有不包含空格的连续的字符。
      这道题请用cin.getline输入一行后再逐个单词递归处理。
输出：翻转每一个单词后的字符串，单词之间的空格需与原文一致。
*/

#include <iostream>
#include <cstring>
using namespace std;
bool flag = false;
int start = 0, len = 0;
char str[501];

int ReverseWords(int n)
{
    if (str[n] == ' ')
    {
        if(flag == true)
        {
            for(int i=n-1; i>=start; i--)
                cout << str[i];
        }
        flag = false;
        if(n < len-1) //因为最后一个是自己添加的空格，所以不用输出，直接返回
        {
            cout << str[n];
            ReverseWords(n+1);
        }
        else
        {
            return 0;
        }        
    }
    else
    {
        if(flag == false)
        {
            flag = true;
            start = n;
        }
        ReverseWords(n+1);
    }  
return -1; //没啥实际用处
}

int main()
{
    cin.getline(str, 501);
    strcat(str, " "); //首先在最初始的字符串最后加一个空格，不然最后一个就得单独判定。
    len = strlen(str);
    ReverseWords(0);
    return 0;
}