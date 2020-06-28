/*
【发票统计】
来源: POJ
注意：总时间限制: 1000ms 内存限制: 65536kB
描述：有一个小型的报账系统，它有如下功能：
     （1）统计每个人所报发票的总钱数
     （2）统计每类发票的总钱数
      将此系统简化为如下：假设发票类别共有A、B、C三种;
      一共有三个人，ID分别为1、2、3。
输入：系统输入包含三行，每行第一个数为人员ID（整型，1或2或3），
      第二个数为发票总张数(张数不超过100)，
      之后是多个发票类别（字符型，A或B或C）和相应发票金额（单进度浮点型,不超过1000.0）。
输出：输出包含六行，前三行为每人（按ID由小到大输出）所报发票总钱数（保留两位小数），
      后三行为每类发票的总钱数（保留两位小数）。
*/
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    double ID[3]={0}, In[3]={0}, tmp; //ID存用户总数，In存不同发票总数
    int id, k;
    char type,name[3] = {'A','B','C'};
    for(int i=0;i<3;i++){
        cin>>id>>k;
        for(int j=0;j<k;j++){
            cin>>type>>tmp;
            switch(type){
                case 'A':
                    ID[id-1]+=tmp;
                    In[0]+=tmp;
                    break;
                case 'B':
                    ID[id-1]+=tmp;
                    In[1]+=tmp;
                    break;
                case 'C':
                    ID[id-1]+=tmp;
                    In[2]+=tmp;
                    break;
            }
        }
    }
    for(int i=0;i<3;i++){
        cout<<i+1<<" "<<fixed<<setprecision(2)<<ID[i]<<endl;
    }
    for(int i=0;i<3;i++){
        cout<<name[i]<<" "<<fixed<<setprecision(2)<<In[i]<<endl;
    }
    return 0;
}
