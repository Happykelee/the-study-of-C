/*
��������͡�
��Դ: POJ
ע�⣺��ʱ������: 1000ms �ڴ�����: 65536kB
����������������m��n(����m��n)֮������������ĺ͡����У�m������n����n������300.
      ����m=3,n=12,�����Ϊ��3+5+7+9+11=35.
���룺������m��n���������Կո���������0<=m <= n <= 300.
���������֮�͡�
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
