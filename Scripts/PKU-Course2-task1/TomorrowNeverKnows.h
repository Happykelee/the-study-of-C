/*
��Tomorrow Never Knows��
��Դ: POJ
ע�⣺��ʱ������: 1000ms �ڴ�����: 65536kB
�������׿ǳ�ġ�A day in the life���͡�Tomorrow never knows�������˿ڣ�
      ���������a day in the life����Ļ���tomorrow never knows��
      ����ѧ�˼Ƹ�֮���ⲻ�������⣬���ھ���ʵ�ְɡ�

      ����һ����ʽΪyyyy-mm-dd�����ڣ�����-��-�գ���������������һ������ڡ�
      ���Լٶ���������ڲ�����1600-01-01��Ҳ������2999-12-30.
���룺�����һ�У���ʽΪyyyy-mm-dd�����ڡ�
��������Ҳ��һ�У���ʽΪyyyy-mm-dd�����ڡ�
*/
#include <iostream>
#include<cmath>
using namespace std;

void getdate(char str[], int date[]){
    int flag=0,phase[3]={3,1,1};
    for(int i=0;str[i]!='\0';i++){
        if(str[i]!='-'){
            date[flag] += ((int)str[i]-48)*pow(10,phase[flag]);
            phase[flag] -= 1;
        }
        else
            flag += 1;
    }
}
void CoutTomorrow(int date[]){
  int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  int leap_year=(date[0]%4==0&&date[0]%100!=0||date[0]%400==0);
  if(leap_year) month[1]=29;
  if(date[2] == month[date[1]-1]){
    date[2] = 1;
    date[1] += 1;
    if(date[1]>12){
        date[1] -= 12;
        date[0] += 1;
    }
  }
  else
    date[2] += 1;

  cout<<date[0]<<"-";
  if(date[1]<10) cout<<"0";
  cout<<date[1]<<"-";
  if(date[2]<10) cout<<"0";
  cout<<date[2]<<endl;
}

void TomorrowNeverKnows(){
    char str[20];
    while(cin.getline(str,20)){
        int date[3]={0,0,0};
        getdate(str, date);
        CoutTomorrow(date);
    }
}
