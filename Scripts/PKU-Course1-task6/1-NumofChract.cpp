/*
������ĸ�ĸ�����
��Դ: POJ
ע�⣺��ʱ������: 1000ms �ڴ�����: 65536kB
��������һ���ַ������ҳ�Ԫ����ĸa,e,i,o,u���ֵĴ�����
���룺����һ���ַ������ַ����п����пո�
      ����cin.getline(s,counts)������һ���ַ������뵽�ַ�����s�У�����counts��s����󳤶ȣ�
      ������������ֱ��д80�������ַ�������С��80���ַ���
��������һ�У��������a,e,i,o,u�������ַ����г��ֵĴ���������֮���ÿո�ָ���
*/

#include<iostream>
using namespace std;
int NumofChract(){
    char str[80];
    int a[5]={0};
    while(cin.getline(str,80)){
        for(int i=0;str[i]!='\0';i++){
            switch(str[i]){
            case 'a': a[0]++;break;
            case 'e': a[1]++;break;
            case 'i': a[2]++;break;
            case 'o': a[3]++;break;
            case 'u': a[4]++;break;
            default: break;
            }
        }
        for(int i=0;i<5;i++){
            cout<<a[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
