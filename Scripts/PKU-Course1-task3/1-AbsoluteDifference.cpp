/*
�������������Сż��֮��ľ���ֵ��
��Դ: POJ
ע�⣺��ʱ������: 1000ms �ڴ�����: 65536kB
����������6��������������6�������������ٴ���һ��������һ��ż����
      ����6������������������Ϊa����С��ż��Ϊb�����|a-b|��ֵ
���룺����Ϊһ�У�6��������,��6����������С��100��
      ���뱣֤��6���������ٴ���һ��������һ��ż����
��������Ϊһ�У����������������С��ż��֮��ľ���ֵ��
*/

#include <iostream>
#include <cmath>

using namespace std;

int AbsoluteDifference()
{
    int a[6],maxodd=0,mineven=100;
    for (int i=0; i<6; i++){
        cin >> a[i];
        if (a[i]%2==0 && a[i]<mineven) mineven=a[i];
        if (a[i]%2==1 && a[i]>maxodd) maxodd=a[i];
    }
    int AboDiff = abs(mineven-maxodd);
    cout << AboDiff << endl;
    return 0;
}



