/*
�������2��
��Դ: POJ
ע�⣺��ʱ������: 1000ms �ڴ�����: 65536kB
������һ����'.'��β�ļ�Ӣ�ľ��ӣ�����֮���ÿո�ָ���û����д��ʽ������������ʽ
���룺һ����'.'��β�ļ�Ӣ�ľ��ӣ����Ȳ�����500��������֮���ÿո�ָ���û����д��ʽ������������ʽ.
������þ�������ĵ��ʡ��������һ�����������һ��.
*/

#include<iostream>
using namespace std;
int LongestChract(){
    char str[500];
    while(cin.getline(str,500,'.')){
        int i=0,start_num=0,end_num=0,count_num=0,flag=0;
        for(i=0;str[i]!='\0';i++){
                if(str[i]!=' '&&flag==0){
                    count_num++;
                    flag=1;
                }
                else if(str[i]==' '&&flag==1){
                    if(count_num>(end_num-start_num)){
                        end_num = i-1;
                        start_num = end_num-count_num+1;
                    }
                    flag=0;
                    count_num = 0;
                }
                else if(str[i]!=' '&&flag==1)
                    count_num++;
                else if(str[i]==' '&&flag==0)
                    continue;
            }

            if(count_num>(end_num-start_num)){ //�ж����һ������
                end_num = i-1;
                start_num = end_num-count_num+1;
            }
        for(int i=start_num;i<=end_num;i++)
            cout<<str[i];
        cout<<endl;
        }
    return 0;
}

