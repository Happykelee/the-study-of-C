/*
【中位数】
来源: POJ
注意：总时间限制: 1000ms 内存限制: 65536kB
描述：中位数定义：一组数据按从小到大的顺序依次排列，处在中间位置的一个数或最中间两个数据的平均值
      （如果这组数的个数为奇数，则中位数为位于中间位置的那个数；
        如果这组数的个数为偶数，则中位数是位于中间位置的两个数的平均值）.
        给出一组无序整数，求出中位数，如果求最中间两个数的平均数，向下取整即可（不需要使用浮点数）
输入：该程序包含多组测试数据，每一组测试数据的第一行为N，代表该组测试数据包含的数据个数，1 <= N <= 15000.
      接着N行为N个数据的输入，N=0时结束输入
输出：输出中位数，每一组测试数据输出一行
*/

#include<iostream>
#include<iomanip>
using namespace std;
int Median2(){
    int n,*a, *m, cont=0, tmp[2]={0};
    while(cin>>n){
        if(n==0)
            break;
        else{
            a = new int[n];
            cont++;
        }

        for(int i=0;i<n;i++)
            cin>>a[i];

        if(n%2==0){
            tmp[0]=a[n/2];
            tmp[1]=a[n/2-1];
        }
        else if(n%2==1)
            tmp[0]=tmp[1]=a[(n-1)/2];

        if(cont==1)
            m = new int[100];
        *(m+cont-1)=(tmp[0]+tmp[1])/2;
    }

    for(int i=0;i<cont;i++)
        cout<<m[i]<<endl;
    return 0;
}


