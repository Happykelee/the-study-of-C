/*
【最远距离】
来源: POJ
注意：总时间限制: 1000ms 内存限制: 65536kB
描述：给定一组点(x,y)，求距离最远的两个点之间的距离。
输入：第一行是点数n（n大于等于2）
      接着每一行代表一个点，由两个浮点数x y组成。
输出：输出一行是最远两点之间的距离。
*/

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int FarthestDistance(){
    int n;
    double *x, *y, dis=0.0;
    cin>>n;
    x = new double[n];
    y = new double[n];
    for(int i=0;i<n;i++)
        cin>>x[i]>>y[i];
    for(int i=0;i<n-1;i++)
    for(int j=1;j<n;j++){
        if(pow(x[i]-x[j],2)+pow(y[i]-y[j],2) > pow(dis,2))
            dis = sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
    }
    cout<<fixed<<setprecision(4)<<dis<<endl;
    return 0;
}
