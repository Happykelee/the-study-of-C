/*
���ַ������롿
��Դ: POJ
ע�⣺��ʱ������: 1000ms �ڴ�����: 65536kB
�������������ַ���str��substr��str���ַ�����������10��substr���ַ�����Ϊ3��
      ���ַ������������ַ�����β����'\0'����
      ��substr���뵽str��ASCII�������Ǹ��ַ����棬���ж�������ֻ���ǵ�һ����
���룺������������У�ÿһ��Ϊһ��������ݣ���ʽΪ
         str substr
���������ÿһ��������ݣ��������֮����ַ�����
*/

#include<iostream>
using namespace std;

int InsertString(){
    char str1[11], str2[4];
    int max_char = 0;
    while(cin.getline(str1,11,' ')&&cin.getline(str2,4,'\n')){
        for(int i=0;str1[i]!='\0';i++){
            if (str1[i]>str1[max_char])
                max_char=i;
        }
        for(int i=0;str1[i]!='\0';i++){
            cout<<str1[i];
            if(i==max_char)
                for(int j=0;str2[j]!='\0';j++)
                cout<<str2[j];
        }
        cout<<endl;
    }
    return 0;
}

