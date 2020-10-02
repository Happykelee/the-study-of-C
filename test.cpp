#include <iostream>
using namespace std;

struct Node
{
    int num;
    Node *next;
    Node *ahead;
};

Node *Create(int N);
Node *Search(Node *head, int P);
Node *Release(Node *head, int M);

int main()
{
    int N,P,M; // N-起使结点数，P-开始结点数
    cin >> N >> P >> M;
    Node *head = Create(N); // 创建
    head = Search(head,P); // 找到第P个结点
    while(head->next!=head)
    // 不断始放第M个元素，直至只剩一个元素
    {
        head = Release(head, M);
    }
    cout << "*" << head->num <<endl;
    return 0;
}

Node *Create(int N)
{
    Node *head, *temp, *unit;
    head = new Node;
    head->num = 1;
    temp = head;

    for(int i=2;i<=N;i++)
    {
        unit = new Node;
        unit->num = i;
        unit->ahead = temp;
        temp->next = unit;
        temp = temp->next;
    }
    // 尾结点处理
    unit->next = head;
    head->ahead = unit;
    return (head);
    }

Node *Search(Node *head, int P)
{
    P = P - 1;
    for(int i=0;i<P;i++)
        head = head->next;
    return(head);
}

Node *Release(Node *head, int M)
{
    Node *temp = head;
    for(int i=1;i<M;i++)
        temp = temp->next; // 找到第M个位置指针
    temp->ahead->next = temp->next;
    temp->next->ahead = temp->ahead;
    cout << temp->num << endl;
    head = temp->next;
    delete temp;
    return(head);
}