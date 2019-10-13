/*
【分数求和】
来源: POJ
注意：总时间限制: 1000ms 内存限制: 65536kB
描述：输入n个分数并对他们求和，用约分之后的最简形式表示。
输入：第一行的输入n,代表一共有几个分数需要求和，接下来的n行是分数。
输出：输出只有一行，即归约后的结果。
*/

#include <iostream>
#include <cmath>

using namespace std;

int FractionSum()
{
    int n;
    cin >> n;
    int sumn = 0, sumd = 1;//储存结果，sumn/sumd
    while (n--) {
    int num, deno;
    char slash;//专门用来吃掉/的
    cin >> num >> slash >> deno;
    //先相加 a/b + c/d = (a*d+c*b)/(b*d)
    sumn = sumn*deno + num*sumd;
    sumd = sumd*deno;
    }
    //后约分
    //先求最大公约数gcd，这里用的是欧几里得法
    int a = sumd, b = sumn, c;
    while (a != 0) {
    c = a; a = b%a; b = c;
    }
    int gcd = b;
    //分子分母同时除以gcd就可以完成约分
    sumd /= gcd;
    sumn /= gcd;
    if (sumd > 1)
    cout << sumn << '/' << sumd << endl;
    else
    cout << sumn << endl;
    return 0;
}




