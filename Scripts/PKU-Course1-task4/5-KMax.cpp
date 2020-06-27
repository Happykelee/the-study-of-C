/*
【找出第k大的数】
来源: POJ
注意：总时间限制: 1000ms 内存限制: 65536kB
描述：用户输入N和K，然后接着输入N个正整数（无序的），程序在不对N个整数排序的情况下，找出第K大的数。
      注意，第K大的数意味着从大到小排在第K位的数。
输入：
      N
      K
      a1 a2 a3 a4 ..... aN
输出：b
*/

#include <iostream>

using namespace std;

int main()
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
        if(n-No==k){
            cout << a[i] << endl;
            break;
        }
    }
    return 0;
}

