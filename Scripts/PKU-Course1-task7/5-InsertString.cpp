/*
【字符串插入】
来源: POJ
注意：总时间限制: 1000ms 内存限制: 65536kB
描述：有两个字符串str和substr，str的字符个数不超过10，substr的字符个数为3。
      （字符个数不包括字符串结尾处的'\0'。）
      将substr插入到str中ASCII码最大的那个字符后面，若有多个最大则只考虑第一个。
输入：输入包括若干行，每一行为一组测试数据，格式为
         str substr
输出：对于每一组测试数据，输出插入之后的字符串。
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

