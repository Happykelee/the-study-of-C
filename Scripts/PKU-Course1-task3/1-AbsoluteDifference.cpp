/*
【最大奇数与最小偶数之差的绝对值】
来源: POJ
注意：总时间限制: 1000ms 内存限制: 65536kB
描述：输入6个正整数，且这6个正整数中至少存在一个奇数和一个偶数。
      设这6个正整数中最大的奇数为a，最小的偶数为b，求出|a-b|的值
输入：输入为一行，6个正整数,且6个正整数都小于100。
      输入保证这6个数中至少存在一个奇数和一个偶数。
输出：输出为一行，输出最大的奇数与最小的偶数之差的绝对值。
*/

#include <iostream>
#include <cmath>

using namespace std;

int AbsoluteDifference()
{
    int a[6],maxodd=0,mineven=100;
    for (int i=0; i<6; i++){
        cin >> a[i];
        if (a[i]%2==0 && a[i]<mineven) mineven=a[i];
        if (a[i]%2==1 && a[i]>maxodd) maxodd=a[i];
    }
    int AboDiff = abs(mineven-maxodd);
    cout << AboDiff << endl;
    return 0;
}



