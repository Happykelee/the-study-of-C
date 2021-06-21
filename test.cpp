#include <iostream>
using namespace std;

struct student
{
    int id_num;
    student *next;
};

student *create()
{
    student *head, *temp;
    int num, n = 0;
    head = new student;
    temp = head;
    cin >> num;
    while (num != -1)
    {
        n++;
        temp->id_num = num;
        temp->next = new student;
        temp = temp->next;
        cin >> num;
    }
    if (n == 0)
        head = NULL;
    else
        temp->next = NULL;
    return head;
}

student *dele(student *head, int n)
{
    student *temp, *follow;
    temp = head;
    if (head == NULL)
    // head为空，空表的情况
    {
        cout << "NULL Struct" << endl;
        return (head);
    }

    if (head->id_num == n)
    // 第一个结点是要删除的目标
    {
        head = head->next;
        delete temp;
        return (head);
    }

    while (temp != NULL && temp->id_num != n)
    {
        follow = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        cout << "not found";
    else
    {
        follow->next = temp->next;
        delete temp;
    }
    return (head);
}

int main()
{
    student *header = create();
    student *pointer = header;
    while (pointer->next != NULL)
    {
        cout << pointer->id_num << endl;
        pointer = pointer->next;
    }
    student *temp;
    temp = dele(header,23);
    // pointer = header;
    while (pointer->next != NULL)
    {
        cout << pointer->id_num << endl;
        pointer = pointer->next;
    }

    return 0;
}