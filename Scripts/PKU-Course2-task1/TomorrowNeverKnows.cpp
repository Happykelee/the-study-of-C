/*
【Tomorrow Never Knows】
来源: POJ
注意：总时间限制: 1000ms 内存限制: 65536kB
描述：甲壳虫的《A day in the life》和《Tomorrow never knows》脍炙人口，
      如果告诉你a day in the life，真的会是tomorrow never knows？
      相信学了计概之后这不会是难题，现在就来实现吧。

      读入一个格式为yyyy-mm-dd的日期（即年-月-日），输出这个日期下一天的日期。
      可以假定输入的日期不早于1600-01-01，也不晚于2999-12-30.
输入：输入仅一行，格式为yyyy-mm-dd的日期。
输出：输出也仅一行，格式为yyyy-mm-dd的日期。
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

int main(){
    char str[20];
    while(cin.getline(str,20)){
        int date[3]={0,0,0};
        getdate(str, date);
        CoutTomorrow(date);
    }
    return 0;
}
