/*
����Զ���롿
��Դ: POJ
ע�⣺��ʱ������: 1000ms �ڴ�����: 65536kB
����������һ���(x,y)���������Զ��������֮��ľ��롣
���룺��һ���ǵ���n��n���ڵ���2��
      ����ÿһ�д���һ���㣬������������x y��ɡ�
��������һ������Զ����֮��ľ��롣
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
