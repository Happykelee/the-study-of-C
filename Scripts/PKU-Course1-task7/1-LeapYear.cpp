/*
���ж����꡿
��Դ: POJ
ע�⣺��ʱ������: 1000ms �ڴ�����: 65536kB
�������ж�ĳ���Ƿ������ꡣ
���룺����ֻ��һ�У�����һ������a(0 < a < 3000)
�����һ�У������Ԫa�����������Y���������N
*/

#include<iostream>
using namespace std;
int LeapYear(){
    while(true){
        int a;
        cin>>a;
        if(a%100==0){
            if(a%3200==0)
                cout<<"N"<<endl;
            else if(a%400==0)
                cout<<"Y"<<endl;
            else
                cout<<"N"<<endl;
            }
        else if(a%4==0)
            cout<<"Y"<<endl;
        else
            cout<<"N"<<endl;
    }
    return 0;
}
