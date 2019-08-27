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

int OddEvenSort02() {
    int a[10];
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    // 冒泡排序
    for (int i = 0; i < 9; i++) {
        for (int j = 1; j < 10 - i; j++) {
        // 与刚才的冒泡排序不同，我们不只是通过较数字的大小决定顺序
        // 如果左边的为偶数，右边的为奇数，那么顺序也需要颠倒
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
