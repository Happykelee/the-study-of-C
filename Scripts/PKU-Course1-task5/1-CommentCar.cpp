/*
������������
��Դ: POJ
ע�⣺��ʱ������: 1000ms �ڴ�����: 65536kB
������4��ר�Ҷ�4��������������
      1��A˵��2����������õģ�
      2��B˵��4����������õģ�
      3��C˵��3������������õģ�
      4��D˵�� B˵���ˡ�
      ��ʵ��ֻ��1��������ѣ���ֻ��1��ר��˵���ˣ�����3�˶�˵���ˡ�
���룺������
�����������С���һ�������ѳ��ĳ��ţ�1-4�е�ĳ�����֣����ڶ������˵�Ե�ר�ң�A-D�е�ĳ����ĸ��
*/

#include<iostream>
using namespace std;
int CommentCar(){
    // ��bestö����õĳ�
    int best;
    for(best = 1; best <= 4; best++){
        // a b c d��¼��λר�ҵĻ�
        bool a = (best == 2);
        bool b = (best == 4);
        bool c = !(best == 3);
        bool d = !b;
        if (a + b + c + d != 1)
            continue; // ������ֻ��1λר��˵�Ե�����

        // �����ѵĳ�
        cout << best << endl;
        // ����ж���ȷ��ר��
        if ( a == 1)
            cout << "A" << endl;
        else if ( b == 1)
            cout << "B" << endl;
        else  if ( c == 1)
            cout << "C" << endl;
        else
            cout << "D" << endl;
    }
    return 0;
}
