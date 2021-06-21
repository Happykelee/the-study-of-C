/*
描述
写一个二维数组类 Array2,使得下面程序的输出结果是：
0,1,2,3,
4,5,6,7,
8,9,10,11,

next
0,1,2,3,
4,5,6,7,
8,9,10,11,
*/
#include <iostream>
#include <cstring>
using namespace std;
// 在此处补充你的代码
class Array2
{
    private:
        int row, col;
        int **a_2d;
    public:
        Array2(int r=0, int c=0);
        ~Array2();
        int * & operator[] (const int &);
        int & operator()(const int &, int const &);
        Array2 & operator=(const Array2 &);
};
Array2::Array2(int r, int c):row(r),col(c)
{
    if(row==0||col==0)
    {
        a_2d = NULL;
    }
    else
    {
        a_2d = new int *[row];
        for (int i = 0; i < row; i++)
            a_2d[i] = new int[col];
    }
}
Array2::~Array2()
{
    if(a_2d) delete [] a_2d;
}
// 二维数组要求的[]重载
int * & Array2::operator[](const int & k)
{
    return a_2d[k];
}
// []重载
int & Array2::operator()(const int & r, const int & c)
{
    return a_2d[r][c];
}
// =重载
Array2 & Array2::operator=(const Array2 & A)
{
    if(a_2d == A.a_2d)
        return *this;
    if(A.a_2d == NULL)
    {
        if (a_2d) delete[] a_2d;
        a_2d = NULL;
        row = 0;
        col = 0;
        return *this;
    }
    else
    {
        if (a_2d) delete[] a_2d;
        row = A.row;
        col = A.col;
        a_2d = new int *[row];
        for (int i = 0; i < row; i++)
        {
            a_2d[i] = new int[col];
            memcpy(a_2d[i], A.a_2d[i], sizeof(int)*col);
        }
        return *this;
    }
}
int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;
    b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}