/*
【最长单词2】
来源: POJ
注意：总时间限制: 1000ms 内存限制: 65536kB
描述：一个以'.'结尾的简单英文句子，单词之间用空格分隔，没有缩写形式和其它特殊形式
输入：一个以'.'结尾的简单英文句子（长度不超过500），单词之间用空格分隔，没有缩写形式和其它特殊形式.
输出：该句子中最长的单词。如果多于一个，则输出第一个.
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

            if(count_num>(end_num-start_num)){ //判断最后一个单词
                end_num = i-1;
                start_num = end_num-count_num+1;
            }
        for(int i=start_num;i<=end_num;i++)
            cout<<str[i];
        cout<<endl;
        }
    return 0;
}

