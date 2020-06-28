/*
【扩号匹配问题】
来源: POJ
注意：总时间限制: 1000ms 内存限制: 65536kB
描述：在某个字符串（长度不超过100）中有左括号、右括号和大小写字母；规定（与常见的算数式子一样）任何一个左括号
      都从内到外与在它右边且距离最近的右括号匹配。写一个程序，找到无法匹配的左括号和右括号，输出原来字符串，
      并在下一行标出不能匹配的括号。不能匹配的左括号用"$"标注,不能匹配的右括号用"?"标注.
输入：输入包括多组数据，每组数据一行，包含一个字符串，只包含左右括号和大小写字母，字符串长度不超过100
输出：对每组输出数据，!!!输出两行，第一行包含原始输入字符!!!，第二行由"$","?"和空格组成，"$"和"?"表示与之对应
      的左括号和右括号不能匹配。
*/
#include <iostream>
#include <cstring>
using namespace std;

char str[101];
int level[101] = {0}, type[101] = {0};
int now, len;

void ExtensionMatch(int n)
{
      if(str[n] == ')' && n < len)
      {
            if(now==0)
                  type[n]=2;
            else
            {
                  now--;
                  type[level[now]] = 0;
                  level[now] = 0;
                  type[n] = 0;
            }
            ExtensionMatch(n+1);
      }
      else if (str[n] == '(' && n < len)
      {
            type[n] = 1;
            level[now] = n;
            now++;
            ExtensionMatch(n+1);
      }
      else if(n < len)
      {
            type[n] = 0;
            ExtensionMatch(n+1);
      }
}

int main()
{
      while(cin.getline(str,101))
      {
            len = strlen(str);
            now = 0;
            ExtensionMatch(0);
            for(int i=0; i<len; i++)
                  cout << str[i];
            cout << endl;
            for(int i=0; i<len; i++)
            {
                  switch (type[i])
                  {
                  case 0:
                        cout<<" ";
                        break;
                  case 1:
                        cout << "$";
                        break;
                  case 2:
                        cout << "?";
                        break;
                  default:
                        break;
                  }
            }
            cout << endl;
      }
      return 0;
}