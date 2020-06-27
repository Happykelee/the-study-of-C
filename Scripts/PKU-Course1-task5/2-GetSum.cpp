/*
【数字求和】
来源: POJ
注意：总时间限制: 1000ms 内存限制: 65536kB
描述：给定一个正整数a，以及另外的5个正整数，问题是：这5个整数中，小于a的整数的和是多少？
输入：输入一行，只包括6个小于100的正整数，其中第一个正整数就是a。
输出：输出一行，给出一个正整数，是5个数中小于a的数的和。
*/

#include<iostream>
using namespace std;
int main()
{
    // 用best枚举最好的车
    int Max, a,sum=0;
    cin >> Max;
    for(int i=0;i<5;i++){
        cin >> a;
        if(a<Max)
            sum += a;
    }
    cout << sum << endl;
    return 0;
}
