/*
����Ʊͳ�ơ�
��Դ: POJ
ע�⣺��ʱ������: 1000ms �ڴ�����: 65536kB
��������һ��С�͵ı���ϵͳ���������¹��ܣ�
     ��1��ͳ��ÿ����������Ʊ����Ǯ��
     ��2��ͳ��ÿ�෢Ʊ����Ǯ��
      ����ϵͳ��Ϊ���£����跢Ʊ�����A��B��C����;
      һ���������ˣ�ID�ֱ�Ϊ1��2��3��
���룺ϵͳ����������У�ÿ�е�һ����Ϊ��ԱID�����ͣ�1��2��3����
      �ڶ�����Ϊ��Ʊ������(����������100)��
      ֮���Ƕ����Ʊ����ַ��ͣ�A��B��C������Ӧ��Ʊ�������ȸ�����,������1000.0����
���������������У�ǰ����Ϊÿ�ˣ���ID��С���������������Ʊ��Ǯ����������λС������
      ������Ϊÿ�෢Ʊ����Ǯ����������λС������
*/
#include <iostream>
#include <iomanip>
using namespace std;
void InvoiceStats(){
    double ID[3]={0}, In[3]={0}, tmp; //ID���û�������In�治ͬ��Ʊ����
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

}
