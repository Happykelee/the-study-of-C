/*
�����ӡ�
��Դ: POJ
ע�⣺��ʱ������: 1000ms �ڴ�����: 65536kB
��������һ������Ϊn(n < 1000)�����������У��ж��Ƿ����ĳ����Ԫ��֮��Ϊk��
���룺��һ���������еĳ���n��k���ÿո�ֿ���
      �ڶ������������е�n���������ÿո�ֿ���
������������ĳ����Ԫ�صĺ�Ϊk�������yes���������no��
*/

#include<iostream>
#include<cmath>

using namespace std;
int SumasK(){
    int n,K,*a;
    cin>>n>>K;
    a = new int[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;j++){
            if(a[i]+a[j]==K)
                cout << "yes" << endl;
                return 0;
        }
        if(i==n-1)
            cout << "no" <<endl;
    }
    return 0;
}



