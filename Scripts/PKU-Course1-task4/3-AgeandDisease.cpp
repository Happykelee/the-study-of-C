/*
【年龄与疾病】
来源: POJ
注意：总时间限制: 1000ms 内存限制: 65536kB
描述：某医院想统计一下某项疾病的获得与否与年龄是否有关，需要对以前的诊断记录进行整理。
输入：共2行，第一行为过往病人的数目n（0 < n <= 100)，第二行为每个病人患病时的年龄。
输出：每个年龄段（分四段：18以下，19-35，36-60，大于60注意看样例输出的格式）的患病人数占总患病人数的比例，
      以百分比的形式输出，精确到小数点后两位（double）。
      关于c++的格式化的输入输出，请参考：http://www.cplusplus.com/reference/iomanip。
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
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
