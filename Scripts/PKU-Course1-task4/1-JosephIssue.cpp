/*
��Լɪ�����⡿
��Դ: POJ
ע�⣺��ʱ������: 1000ms �ڴ�����: 65536kB
�������У�ֻ���ӣ���˳ʱ�뷽��Χ��һȦѡ��������Ŵӣ������
      �ӵڣ��ſ�ʼ������һֱ������������ĺ����˳�Ȧ�⣬
      ʣ�µĺ����ٽ��Ŵ�1��ʼ������
      ��������ֱ��Ȧ��ֻʣ��һֻ����ʱ��������Ӿ��Ǻ�����
      ����������������������ı�š�
���룺ÿ�����ÿո�ֿ���������������һ���� n, �ڶ����� m ( 0 < m,n <=300)�����һ���ǣ�0 0
���������ÿ���������ݣ����һ�г���)���������Ҳ��һ�У����������ı�š�
*/

#include <iostream>
#include <cmath>

using namespace std;

//һ�������300ֻ����
int succedent[300]; //����������ڱ���һ�����Ӻ�һλ��˭��
                    //���硰next[5]��ֵ��7������˵5�ź��ӵ���һλ��7�ź��ӣ�6�ź����Ѿ���֮ǰ�˳��ˡ�
int precedent[300]; //����������ڱ���һ������ǰһλ��˭���÷�����������ơ�

int JosephIssue()
{
    int n, m;
    while(true){
    cin >> n >> m;
    if(n == 0 && m == 0) break;
    for(int i = 0; i < n - 1; i++){
        succedent[i] = i + 1;
        precedent[i + 1] = i;
    }
    succedent[n - 1] = 0;
    precedent[0] = n - 1;

    int current = 0;
    while(true){
    //���һ��Ҫ��m�κţ���ôȡm-1��succedent֮�������Ҫ�˳�����ֻ����
        for(int count = 0; count < m-1; count++)
            current = succedent[current];

        int pre = precedent[current];
        int suc = succedent[current];
        //��current�ź����˳��ܼ򵥣����ǰ�ǰһλ�ġ���һλ��ָ��current����һλ��
        //��һλ�ġ�ǰһλ��ָ��current��ǰһλ�ͺ���
        succedent[pre] = suc;
        precedent[suc] = pre;
        if (pre == suc) {
        //���ֻʣ�������ˣ���ôÿ���˵�ǰλ�ͺ�λ����ͬһ���ˡ�
        //current���˳��ģ���ô��һ������ʣ�µġ�
        //���ǵ�����Ǵ�0��ŵģ����ʱҪ��һ
        cout << pre+1 << endl;
        break;
        }
        current = suc;
        }
    }
    return 0;
}



