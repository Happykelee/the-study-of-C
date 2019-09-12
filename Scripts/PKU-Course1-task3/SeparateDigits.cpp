/*
【分离整数的各个数位】
来源: POJ
注意：总时间限制: 1000ms 内存限制: 65536kB
描述：从键盘输入一个任意的三位整数，
      要求正确地分离出它的百位、十位和个位数，并分别在屏幕上输出，输出采用每行输出一个数的方式，不带其它符号。
输入：一个任意的三位整数
输出：按百十个的顺序三行个位数
*/

#include <iostream>

using namespace std;

int SeparateDigits()
{
    int a,sep[3];
    cin >> a;
    for (int i=0; i<3; i++){
        sep[i] = a%10;
        a = a/10;
    }
    for (int i=2; i>=0; i--) cout << sep[i] << endl;
    return 0;
}
