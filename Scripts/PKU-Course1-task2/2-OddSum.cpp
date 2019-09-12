/*
【奇数求和】
来源: POJ
注意：总时间限制: 1000ms 内存限制: 65536kB
描述：计算正整数m到n(包括m和n)之间的所有奇数的和。其中，m不大于n，且n不大于300.
      例如m=3,n=12,其和则为：3+5+7+9+11=35.
输入：两个数m和n，两个数以空格间隔，其中0<=m <= n <= 300.
输出：奇数之和。
*/
#include <iostream>
using namespace std;

int OddSum(){
    int m,n,sum=0;
    cin>>m>>n;
    if(m%2==0) m=m+1;
    if(n%2==0) n=n-1;
    sum=(m+n)*((n-m)/2+1)/2;
    cout<<"OddSum("<<m<<"-"<<n<<"):"<<sum<<endl;
    return 0;
}

