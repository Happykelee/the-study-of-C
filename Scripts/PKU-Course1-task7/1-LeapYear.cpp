/*
【判断闰年】
来源: POJ
注意：总时间限制: 1000ms 内存限制: 65536kB
描述：判断某年是否是闰年。
输入：输入只有一行，包含一个整数a(0 < a < 3000)
输出：一行，如果公元a年是闰年输出Y，否则输出N
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
