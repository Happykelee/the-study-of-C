/*
����ż����01��
��Դ: POJ
ע�⣺��ʱ������: 1000ms �ڴ�����: 65536kB
������������ʮ����������ʮ�������������������������������ǰ��ż���ں�
���룺����ʮ��������
�����������ż����õ�ʮ��������
*/
#include <iostream>
using namespace std;

int OddEvenSort02() {
    int a[10];
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    // ð������
    for (int i = 0; i < 9; i++) {
        for (int j = 1; j < 10 - i; j++) {
        // ��ղŵ�ð������ͬ�����ǲ�ֻ��ͨ�������ֵĴ�С����˳��
        // �����ߵ�Ϊż�����ұߵ�Ϊ��������ô˳��Ҳ��Ҫ�ߵ�
            bool leftIsEven = a[j - 1] % 2 == 0;
            bool rightIsEven = a[j] % 2 == 0;
            if ((leftIsEven && !rightIsEven) || (leftIsEven == rightIsEven && a[j - 1] > a[j])) {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}
