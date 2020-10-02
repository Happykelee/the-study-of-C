/*
【分配病房】
来源: POJ
注意：总时间限制: 1000ms 内存限制: 65536kB
描述：某个科室的病房分为重症和普通，只有当病人的疾病严重程度超过了入住重症病房的最低严重值，
      才可以安排入住重症病房。现在要求设计一个程序，给病人安排好病房。疾病的严重程度用0到
      10来表示，0表示小毛病，10表示非常严重。
输入：第一行输入病人的个数m(m < 50)，以及安排住入重症病房的最低严重值a。
      紧接着m行，每行表示病人编号（三个位，用0补齐）及其疾病的严重程度（浮点数，1位小数）。
      每个病人的疾病严重程度都不一样。
输出：要求按照病人的严重程度输出住在重症病房里的病人的编号。
注意：如果当前所有病人的严重程度并不满足住在重症病房里，则输出“None.”（不包括引号）。
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int Num, len=0; double Min;
    int ID[50] = {0}; double Score[50] = {0.0};
    int Rank[50] = {0}; int *p = Rank;
    cin >> Num >> Min;

    // input
    for(int i=0;i<Num;i++)
    {
        cin >> ID[i] >> Score[i];
        if(Score[i] >= Min)
        {
            *p++ = i;
            len++;
        }
    }

    // Rank
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 1; j < len - i; j++)
        {
            if (*(Score+Rank[j - 1]) < *(Score+Rank[j]))
            {
                int temp = Rank[j];
                Rank[j] = Rank[j - 1];
                Rank[j - 1] = temp;
            }
        }
    }

    // output
    if (p == Rank)
    {
        cout << "None." << endl;
    }
    else
    {
        for (int i = 0; i < len; i++)
        {
            int Rem = *(ID + Rank[i]);
            for (int d = 2; d >= 0; d--)
            {
                cout << int(Rem/pow(10, d));
                Rem %= int(pow(10, d));
            }
            cout << " " << fixed << setprecision(1) << *(Score + Rank[i]) << endl;
        }
    }

    
    return 0;           
}
