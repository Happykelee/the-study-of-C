/*
【文字排版】
来源: POJ
注意：总时间限制: 1000ms 内存限制: 65536kB
描述：给一段英文短文，单词之间以空格分隔（每个单词包括其前后紧邻的标点符号）。
      请将短文重新排版，要求如下：
      每行不超过80个字符；每个单词居于同一行上；
      在同一行的单词之间以一个空格分隔；行首和行尾都没有空格。
输入：第一行是一个整数n，表示英文短文中单词的数目. 其后是n个以空格分隔的英文单词
     （单词包括其前后紧邻的标点符号，且每个单词长度都不大于40个字母）。
输出：排版后的多行文本，每行文本字符数最多80个字符，
      单词之间以一个空格分隔，每行文本首尾都没有空格。
*/

#include <iostream>
using namespace std;

int main()
{
      int n=0,len[1000]={0};
      char A[1000][40], tmp;
      cin >> n;
      cin.get();
      for(int i=0;i<n;i++)
      for(int j=0;j<40;j++){
            cin.get(tmp);
            if (tmp != ' ' && tmp != '\n')
                  A[i][j] = tmp;
            else{
                  len[i] = j;
                  break;
            }
      }
      
      int line=0,p=0;
      for(int i=0;i<n;i++){
            line += (len[i] + 1);
            if (line <= 81 && i < n-1)
                  continue;
            else if(line > 81){
                  for(int j=p;j<i;j++){
                        if(j!=i-1)
                              cout<<A[j]<<' ';
                        else if(j==i-1)
                              cout<<A[j]<<endl;
                  }
                  p=i;
                  line = 0;
                  i--;
            }
            else if (i == n - 1)
            {
                  for (int j = p; j < n; j++)
                  {
                        if (j != n - 1)
                              cout << A[j] << ' ';
                        else if (j == n - 1)
                              cout << A[j] << endl;
                  }
            }
      }
      return 0;
}
