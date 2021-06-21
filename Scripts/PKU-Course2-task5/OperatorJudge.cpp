/*
【运算符判定】
来源: POJ
注意：总时间限制: 1000ms 内存限制: 65536kB
描述：两个整数a和b运算后得到结果c。表示为: a?b=c.
      其中，?可能是加法+，减法-，乘法*，整除/或取余%。
      请根据输入的 a,b,c 的值，确定运算符。
      如果某种运算成立，则输出相应的运算符，如果任何运算都不成立，则输出error.
        例如：

        输入：
        3,4,5
        输出：
        error

        若输入：
        3,4,3
        则输出：
        %

输入：a，b和c的值在一行内输入，以逗号间隔。
输出：五个运算符之一或 error.
*/

#include <iostream>
using namespace std;


int main()
{
    // Define
    int a, b, c;
    cin >> a; cin.get();
    cin >> b; cin.get();
    cin >> c; cin.get();
    if(a * b == c)
        cout << "*" << endl;
    else if(a / b == c)
        cout << "/" << endl;
    else if (a + b == c)
        cout << "+" << endl;
    else if (a - b == c)
        cout << "-" << endl;
    else if (a % b == c)
        cout << "%" << endl;
    else
        cout << "error" << endl;
    return 0;
}
