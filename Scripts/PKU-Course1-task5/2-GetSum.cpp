/*
��������͡�
��Դ: POJ
ע�⣺��ʱ������: 1000ms �ڴ�����: 65536kB
����������һ��������a���Լ������5���������������ǣ���5�������У�С��a�������ĺ��Ƕ��٣�
���룺����һ�У�ֻ����6��С��100�������������е�һ������������a��
��������һ�У�����һ������������5������С��a�����ĺ͡�
*/

#include<iostream>
using namespace std;
int GetSum(){
    // ��bestö����õĳ�
    int Max, a,sum=0;
    cin >> Max;
    for(int i=0;i<5;i++){
        cin >> a;
        if(a<Max)
            sum += a;
    }
    cout << sum << endl;
    return 0;
}
