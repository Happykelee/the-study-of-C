/*
【忽略大小写比较字符串大小】
来源: POJ
注意：总时间限制: 1000ms 内存限制: 65536kB
描述：一般我们用strcmp可比较两个字符串的大小，比较方法为对两个字符串从前往后逐个字符相比较（按ASCII码值大小比较），
      直到出现不同的字符或遇到'\0'为止。如果全部字符都相同，则认为相同；
      如果出现不相同的字符，则以第一个不相同的字符的比较结果为准。
      但在有些时候，我们比较字符串的大小时，希望忽略字母的大小，
      例如"Hello"和"hello"在忽略字母大小写时是相等的。
      请写一个程序，实现对两个字符串进行忽略字母大小写的大小比较。
输入：输入为两行，每行一个字符串，共两个字符串。
     （请用cin.getline(s,80)录入每行字符串）（每个字符串长度都小于80）
输出：如果第一个字符串比第二个字符串小，输出一个字符"<"
      如果第一个字符串比第二个字符串大，输出一个字符">"
      如果两个字符串相等，输出一个字符"="
*/

#include<iostream>
using namespace std;
int main(){
    char str1[80],str2[80];
    while(cin.getline(str1,80)&&cin.getline(str2,80)){
        for(int i=0;i<80;i++){
            if(str1[i]>=0x40&&str1[i]<=0x61) str1[i] += 0x20;
            if(str2[i]>=0x40&&str2[i]<=0x61) str2[i] += 0x20;
            if(str1[i]>str2[i]){
                cout<<'>'<<endl;
                break;
            }
            else if(str1[i]<str2[i]){
                cout<<'<'<<endl;
                break;
            }
            else if(str1[i]==str2[i]&&(str1[i+1]!='\0'||str2[i+1]!='\0'))
                continue;
            else{
                cout<<'='<<endl;
                break;
            }
        }
    }
    return 0;
}

