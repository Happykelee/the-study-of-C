/*
�������뼲����
��Դ: POJ
ע�⣺��ʱ������: 1000ms �ڴ�����: 65536kB
������ĳҽԺ��ͳ��һ��ĳ����Ļ������������Ƿ��йأ���Ҫ����ǰ����ϼ�¼��������
���룺��2�У���һ��Ϊ�������˵���Ŀn��0 < n <= 100)���ڶ���Ϊÿ�����˻���ʱ�����䡣
�����ÿ������Σ����ĶΣ�18���£�19-35��36-60������60ע�⿴��������ĸ�ʽ���Ļ�������ռ�ܻ��������ı�����
      �԰ٷֱȵ���ʽ�������ȷ��С�������λ��double����
      ����c++�ĸ�ʽ���������������ο���http://www.cplusplus.com/reference/iomanip��
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int AgeandDisease()
{
    int n, age;
    double range[4];
    cin >> n;
    for(int i=0;i<4;i++){ //initialization
        range[i]=0;
    }
    for(int i=0;i<n;i++){
        cin >> age;
        if (age <=18)
            {range[0]++;}
        else if(age >=19 && age <=35)
            {range[1]++;}
        else if(age >=36 && age <=60)
            {range[2]++;}
        else
            {range[3]++;}
    }
    for(int i=0;i<4;i++){ //ratio
        range[i]=range[i]/n*100;
    }
        cout << "1-18: " << fixed << setprecision(2) << range[0] <<'%'<<endl;
        cout << "19-35: " << range[1] <<'%'<<endl;
        cout << "36-60: " << range[2] <<'%'<<endl;
        cout << "60-: " << range[3] <<'%'<<endl;

    return 0;
}
