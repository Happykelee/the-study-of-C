/*
���򵥼�������
��Դ: POJ
ע�⣺��ʱ������: 1000ms �ڴ�����: 65536kB
������һ����򵥵ļ�������֧��+, -, *, / �������㡣
      ���迼���������Ϊ��������������ݺ����������ᳬ��int��ʾ�ķ�Χ��
���룺����ֻ��һ�У������������������е�1��2������Ϊ��������3������Ϊ��������+,-,*,/����
��������ֻ��һ�У�һ��������Ϊ��������Ȼ����
      1. ������ֳ���Ϊ0��������������Divided by zero!
      2. ���������Ч�Ĳ�����(����Ϊ +, -, *, / ֮һ�����������Invalid operator!
*/

#include<iostream>
#include<cmath>
using namespace std;

int SimpleCalculator(){
    while(true){
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
    }
    return 0;
}

