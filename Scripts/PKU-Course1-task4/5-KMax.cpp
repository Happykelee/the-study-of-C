/*
���ҳ���k�������
��Դ: POJ
ע�⣺��ʱ������: 1000ms �ڴ�����: 65536kB
�������û�����N��K��Ȼ���������N��������������ģ��������ڲ���N���������������£��ҳ���K�������
      ע�⣬��K�������ζ�ŴӴ�С���ڵ�Kλ������
���룺
      N
      K
      a1 a2 a3 a4 ..... aN
�����b
*/

#include <iostream>

using namespace std;

int KMax()
{
    int n,k,*a;
    cin >> n;
    cin >> k;
    a = new int[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        int No = 0;
        for(int j=0;j<n;j++){
            if(a[i]>a[j])
                No++;
        }
        if(No==k){
            cout << a[i] << endl;
            break;
        }
    }
    return 0;
}

