/*
����λ����
��Դ: POJ
ע�⣺��ʱ������: 1000ms �ڴ�����: 65536kB
��������λ�����壺һ�����ݰ���С�����˳���������У������м�λ�õ�һ���������м��������ݵ�ƽ��ֵ
      ������������ĸ���Ϊ����������λ��Ϊλ���м�λ�õ��Ǹ�����
        ����������ĸ���Ϊż��������λ����λ���м�λ�õ���������ƽ��ֵ��.
        ����һ�����������������λ������������м���������ƽ����������ȡ�����ɣ�����Ҫʹ�ø�������
���룺�ó����������������ݣ�ÿһ��������ݵĵ�һ��ΪN����������������ݰ��������ݸ�����1 <= N <= 15000.
      ����N��ΪN�����ݵ����룬N=0ʱ��������
����������λ����ÿһ������������һ��
*/

#include<iostream>
#include<iomanip>
using namespace std;
int Median(){
    int n,*a, *m, cont=0;
    while(cin>>n){
        if(n==0)
            break;
        else{
            a = new int[n];
            cont++;
        }

        for(int i=0;i<n;i++)
            cin>>a[i];
        // ð������
        for(int i=0;i<n-1;i++){
            for(int j=1;j<n-i;j++){
                if(a[j-1]>a[j]){
                    int temp = a[j];
                    a[j]=a[j-1];
                    a[j-1]=temp;
                }
            }
        }
        if(cont==1)
            m = new int[100];
        *(m+cont-1)=(a[n/2]+a[(n-1)/2])/2;
    }

    for(int i=0;i<cont;i++)
        cout<<m[i]<<endl;
    return 0;
}

