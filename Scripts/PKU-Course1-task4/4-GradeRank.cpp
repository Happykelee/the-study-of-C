/*
���ɼ��жϡ�
��Դ: POJ
ע�⣺��ʱ������: 1000ms �ڴ�����: 65536kB
����������һ��0--100�ķ������жϷ�������ʲô�ȼ���
      95<=����<=100, ���1
      90<=����<95,���2
      85<=����<90,���3
      80<=����<85,���4
      70<=����<80,���5
      60<=����<70���6
      ���� < 60;���7.
���룺n
�����m
*/

#include <iostream>

using namespace std;

int GradeRank()
{
    int n;
    cin >> n;
    if (n >= 95 && n <= 100)
        cout << 1;
    else if(n >= 90 && n < 95)
        cout << 2;
    else if(n >= 85 && n < 90)
        cout << 3;
    else if(n >= 80 && n < 85)
        cout << 4;
    else if(n >= 70 && n < 80)
        cout << 5;
    else if(n >= 60 && n < 70)
        cout << 6;
    else
        cout << 7;
    return 0;
}
