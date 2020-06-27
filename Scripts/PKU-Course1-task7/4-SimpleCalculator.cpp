/*
【简单计算器】
来源: POJ
注意：总时间限制: 1000ms 内存限制: 65536kB
描述：一个最简单的计算器，支持+, -, *, / 四种运算。
      仅需考虑输入输出为整数的情况，数据和运算结果不会超过int表示的范围。
输入：输入只有一行，共有三个参数，其中第1、2个参数为整数，第3个参数为操作符（+,-,*,/）。
输出：输出只有一行，一个整数，为运算结果。然而：
      1. 如果出现除数为0的情况，则输出：Divided by zero!
      2. 如果出现无效的操作符(即不为 +, -, *, / 之一），则输出：Invalid operator!
*/

#include<iostream>
#include<cmath>
using namespace std;

int main(){
    // while(true){
        int n,m;
        char oper;
        cin>>n>>m>>oper;
        if(oper!='+'&&oper!='-'&&oper!='*'&&oper!='/')
            cout<<"Invalid operator!"<<endl;
        else if(oper=='+')
            cout<<n+m<<endl;
        else if(oper=='-')
            cout<<n-m<<endl;
        else if(oper=='*')
            cout<<n*m<<endl;
        else if(oper=='/'){
            if(m==0)
                cout<<"Divided by zero!"<<endl;
            else
                cout<<n/m<<endl;
        }
    // }
    return 0;
}

