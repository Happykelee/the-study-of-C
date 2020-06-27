/*
【大象喝水】
来源: POJ
注意：总时间限制: 1000ms 内存限制: 65536kB
描述：一只大象口渴了，要喝20升水才能解渴，但现在只有一个深h厘米，底面半径为r厘米的小圆桶(h和r都是整数)。
      问大象至少要喝多少桶水才会解渴。
输入：包含两个整数，以一个空格分开，分别表示小圆桶的深h和底面半径r，单位都是厘米。
输出：输出一行，包含一个整数，表示大象至少要喝水的桶数。
*/

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int h,r;
    cin >> h >> r;
    float v = M_PI * r * r * h / 1000;
    cout << ceil(20/v) << endl;
    return 0;
}


