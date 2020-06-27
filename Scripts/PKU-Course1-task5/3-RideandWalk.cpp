/*
【骑车与走路】
来源: POJ
注意：总时间限制: 1000ms 内存限制: 65536kB
描述：在北大校园里,没有自行车,上课办事会很不方便.
      但实际上,并非去办任何事情都是骑车快,因为骑车总要找车、开锁、停车、锁车等,这要耽误一些时间.
      假设找到自行车,开锁并车上自行车的时间为27秒;
      停车锁车的时间为23秒;步行每秒行走1.2米,骑车每秒行走3.0米.
      请判断走不同的距离去办事,是骑车快还是走路快.
输入：第一行为待处理的数据的数量n
      其后每一行整数为一次办事要行走的距离,单位为米.
输出：对应每个整数,如果骑车快,输出一行"Bike";如果走路快,输出一行"Walk";如果一样快,输出一行"All".
*/

#include<iostream>
using namespace std;
int main()
{
    int n, *a, *b;
    char trans[3][10] = {"Bike", "Walk", "All"};
    cin >> n;
    a = new int[n];
    b = new int[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        double walk_time = a[i]/1.2;
        double bike_time = 50 + a[i]/3.0;
        if (walk_time > bike_time)
            b[i] = 0;
        else if (walk_time < bike_time)
            b[i] = 1;
        else
            b[i] = 2;
    }
    for(int i=0;i<n;i++)
        cout<<trans[b[i]]<<endl;
    return 0;
}
