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

#include <iostream>
using namespace std;

struct Cord
{
    int x;
    int y;
    Cord *next;
};

Cord *Create(int n);
Cord *FindMax(Cord *head);

int main()
{
    // Define
    int n;
    cin >> n;
    Cord *head = Create(n); // 创建
    while(head)
        head = FindMax(head);
    return 0;
}

Cord *Create(int n)
{
    Cord *head, *temp;
    head = new Cord;
    temp = head;
    while(n)
    {
        cin >> temp->x >> temp->y;
        n--;
        if(n==0)
        {
            temp->next = NULL;
        }
        else
        {
            temp->next = new Cord;
            temp = temp->next;
        }
    }
    return (head);
}

Cord *FindMax(Cord *head)
{
    Cord *temp;
    // Find the cordinate of point with max_y
    int max_y = -1, max_x = 0;
    temp = head;
    while (temp)
    {
        if (temp->y > max_y)
        {
            max_y = temp->y;
            max_x = temp->x;
        }
        else if (temp->y == max_y && temp->x > max_x)
        {
            max_x = temp->x;
        }
        temp = temp->next;
    }

    // delete the points with the x <= max_x and y <= max_y
    Cord *follow;
    temp = head;
    while (temp)
    {
        if (temp->x <= max_x && temp->y <= max_y)
        {            
            if (temp == head)
            {
                head = head->next;
                delete temp;
                temp = head;
            }
            else
            {
                follow->next = temp->next;
                delete temp;
                temp = follow->next;
            }
        }
        else
        {
            follow = temp;
            temp = temp->next;
        }
    }
    if (head == NULL)
        cout << "(" << max_x << "," << max_y << ")" << endl;
    else
        cout << "(" << max_x << "," << max_y << "),";
    return (head);
}