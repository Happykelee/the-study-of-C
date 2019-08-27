/*
【奇偶排序01】
来源: POJ
注意：总时间限制: 1000ms 内存限制: 65536kB
描述：请输入十个整数，将十个整数按升序排列输出，并且奇数在前，偶数在后。
输入：输入十个整数。
输出：按照奇偶排序好的十个整数。
*/
#include <iostream>
using namespace std;

int OddEvenSort01() {
    int a[10];
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    // 首先，我们把奇数放到数组左边，偶数放到数组右边
    int l = 0, r = 9; //用左手和右手分别指向数组两端
    while (l <= r) {
        bool leftIsOdd = a[l] % 2 == 1;
        bool rightIsEven = a[r] % 2 == 0;
        if (leftIsOdd) {
            l++;
        } else if (rightIsEven) {
            r--;
        } else if (!leftIsOdd && !rightIsEven) {
            int temp = a[l];
            a[l] = a[r];
            a[r] = temp;
        }
    }
  // 对l左边（奇数部分）进行冒泡排序
    int start = 0, end = l;
    for (int i = start; i < end - 1; i++) {
        for (int j = start + 1; j < start + end - i; j++) {
            if (a[j - 1] > a[j]) {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }
  // 对l右边（偶数部分）进行冒泡排序
    start = l, end = 10;
    for (int i = start; i < end - 1; i++) {
        for (int j = start + 1; j < start + end - i; j++) {
            if (a[j - 1] > a[j]) {
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

