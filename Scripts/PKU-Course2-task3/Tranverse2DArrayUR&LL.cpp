/*
【二维数组右上左下遍历】
来源: POJ
注意：总时间限制: 1000ms 内存限制: 65536kB
描述：给定一个row行col列的整数数组array，要求从array[0][0]元素开始，
      按从左上到右下的对角线顺序遍历整个数组。
输入：输入的第一行上有两个整数，依次为row和col。
      余下有row行，每行包含col个整数，构成一个二维整数数组。
     （注：输入的row和col保证0 < row < 100, 0 < col < 100）
输出：按遍历顺序输出每个整数。每个整数占一行。
*/

#include <iostream>
using namespace std;

int main()
{
    int A[100][100];
    int row, col, r = 0, c = 0;
    cin >> row >> col;
    for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
        cin >> A[i][j];
    
    // 首先以第0行，列递增为起点遍历col次
    for (int j = 0; j < col; j++)
    {
        r = 0;
        c = j;
        while (r < row && c >= 0)
            cout << A[r++][c--] << endl;
    }
    // 然后以第col-1列，行递增为起点遍历row-1次
    for (int i = 1; i < row; i++)
    {
        r = i;
        c = col - 1;
        while (r < row && c >= 0)
            cout << A[r++][c--] << endl;
    }

     return 0;
}
