/*
�����󽻻��С�
��Դ: POJ
ע�⣺��ʱ������: 1000ms �ڴ�����: 65536kB
��������main�����У� ����һ��5*5�ľ�������������ݣ�������n��m��ֵ��
      �ж�n��m�Ƿ������鷶Χ�ڣ�������ڣ������error��
      ����ڷ�Χ�ڣ���n�к�m�н������������n��m����¾���
���룺5*5��������ݣ��Լ�n��m��ֵ��
�����������ɽ����������error��
      ����ɽ�����������¾���
*/

#include<iostream>
#include<iomanip>
using namespace std;
int TransformRow(){
    while(true){
        int matrix[5][5],tmp=0,n,m;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                cin>>matrix[i][j];
            }
        }
        cin>>n>>m;
        if(n>=5||m>=5)
            cout<< "error" << endl;
        else{
            for(int i=0;i<5;i++){
                tmp = matrix[n][i];
                matrix[n][i] = matrix[m][i];
                matrix[m][i] = tmp;
            }
        }
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                cout<< setw(4)<<matrix[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}

