#include <iostream>
using namespace std;

void function()
{
    int a = 0;
    // (普通)动态局部变量a：有效范围在函数范围内（以前的版本前面可加可不加auto）
    static int b = 0;
    // 静态局部变量b：有效范围从定义开始一直持续到程序结束
    a = a + 1;
    b = b + 1;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}
int main()
{
    for (int i=0;i<5;i++)
    {
        function();
        cout << "Call Again!" << endl;
    }
    return 0;
}