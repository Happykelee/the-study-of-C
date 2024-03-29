/*
【含k个3的数】
来源: POJ
注意：总时间限制: 1000ms 内存限制: 65536kB
描述：输入二个正整数m和k，其中1 < m < 100000，1 < k < 5 ，
      判断m 能否被19整除，且恰好含有k个3，如果满足条件，则输出YES，否则，输出NO。
      例如，输入：
        43833 3
        满足条件，输出YES
        如果输入
        39331 3
        尽管有3个3，但不能被19整除，也不满足条件，应输出NO
输入：m和k的值，空格间隔
输出：满足条件时输出 YES，不满足时输出 NO。
*/

#include <iostream>
using namespace std;


int main()
{
    // Define
    int m, k;
    cin >> m >> k;
    int temp, resid, count = 0;
    temp = m;
    while(temp)
    {
        resid = temp % 10;
        if(resid == 3)
        {
            count++;
            if(count > k)
            {
                cout << "NO" << endl;
                return 0;
            }

        }
        temp /= 10;
    }
    if(count==k && m%19==0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
