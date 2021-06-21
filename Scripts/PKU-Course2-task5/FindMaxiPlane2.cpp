/*
【寻找平面上的极大点】
来源: POJ
注意：总时间限制: 1000ms 内存限制: 65536kB
描述：在一个平面上，如果有两个点(x,y),(a,b),如果说(x,y)支配了(a,b)，这是指x>=a,y>=b;
      用图形来看就是(a,b)坐落在以(x,y)为右上角的一个无限的区域内。
      给定n个点的集合，一定存在若干个点，它们不会被集合中的任何一点所支配，这些点叫做极大值点。
      编程找出所有的极大点，按照x坐标由小到大，输出极大点的坐标。
      本题规定：n不超过100，并且不考虑点的坐标为负数的情况。
输入：输入包括两行，第一行是正整数n，表示是点数，第二行包含n个点的坐标，
      坐标值都是整数，坐标范围从0到100，输入数据中不存在坐标相同的点。
输出：按x轴坐标最小到大的顺序输出所有极大点。
      输出格式为:(x1,y1),(x2,y2),...(xk,yk)
      注意：输出的每个点之间有","分隔,最后一个点之后没有",",少输出和多输出都会被判错
*/

#include <stdio.h>
#include <algorithm>
using namespace std;
struct xiao
{
    int x, y;
};
xiao a[110], aa[110];

bool cmp(xiao a, xiao b)
{
    if (a.x == b.x)
        return a.y < b.y;
    else
        return a.x < b.x;
}

int main()
{
    int num = 0;
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i)
    {
        scanf("%d%d", &a[i].x, &a[i].y);
    }
    sort(a, a + T, cmp);
    int maxy = 0;
    for (int i = T - 1; i >= 0; --i)
    {
        if (a[i].y > maxy)
        {
            ++num;
            aa[num].x = a[i].x;
            aa[num].y = a[i].y;
            maxy = a[i].y;
        }
    }
    sort(aa + 1, aa + 1 + num, cmp);
    printf("(%d,%d)", aa[1].x, aa[1].y);
    for (int i = 2; i <= num; ++i)
    {
        printf(",(%d,%d)", aa[i].x, aa[i].y);
    }

    return 0;
}