/*
【魔兽世界之一：备战】
来源: POJ
注意：总时间限制: 1000ms 内存限制: 65536kB
描述：
魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。
红司令部，City 1，City 2，……，City n，蓝司令部
两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。
每种武士都有编号、生命值、攻击力这三种属性。
双方的武士编号都是从1开始计算。红方制造出来的第n个武士，编号就是n。同样，蓝方制造出来的第n个武士，编号也是n。
武士在刚降生的时候有一个生命值。
在每个整点，双方的司令部中各有一个武士降生。
红方司令部按照iceman、lion、wolf、ninja、dragon的顺序循环制造武士。
蓝方司令部按照lion、dragon、ninja、iceman、wolf的顺序循环制造武士。
制造武士需要生命元。
制造一个初始生命值为m的武士，司令部中的生命元就要减少m个。
如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。
如果所有武士都不能制造了，则司令部停止制造武士。
给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止
制造武士为止的所有事件按顺序输出。
一共有两种事件，其对应的输出样例如下：

1) 武士降生
输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter
表示在4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5，降生后蓝魔司令部里共有2个lion武士。
（为简单起见，不考虑单词的复数形式）注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。
2) 司令部停止制造武士
输出样例： 010 red headquarter stops making warriors
表示在10点整，红方司令部停止制造武士
输出事件时：
首先按时间顺序输出；
同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。

输入：
第一行是一个整数，代表测试数据组数。
每组测试数据共两行。
第一行：一个整数M。其含义为， 每个司令部一开始都有M个生命元( 1 <= M <= 10000)。
第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000。

输出：
对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。
对每组测试数据，首先输出"Case:n" n是测试数据的编号，从1开始 。
接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。
*/

#include <iostream>
#include <iomanip>
using namespace std;

int (*GroupInitStren)[5], *MinInitStren;
int RedSeq[5] = {2, 3, 4, 1, 0};
int BlueSeq[5] = {3, 0, 1, 2, 4};
struct Node
{
    int num;
    Node *next;
};
Node * Create(int Seq[], int N=5)
{
    Node *head, *temp;
    head = new Node;
    temp = head;

    for (int i = 0; i < N; i++)
    {
        temp->num = *(Seq+i);
        if(i < N-1)
        {
            temp->next = new Node;
            temp = temp->next;
        }
        else
            temp->next = head;
    }
    return (head);
}
Node *RedSeqHead = Create(RedSeq);
Node *BlueSeqHead = Create(BlueSeq);

class warrior
{
private:
    static const char TotalWName[5][7]; // 武士名字定义为静态常量字符串数组
    int InitStrength;
    const char *WName;
    friend class headquarter;

public:
    inline void GetWInfo(int group, int WCode);
};
class headquarter
{
    private:
        char * HName;
        int TotalStrength;
        Node * SeqNode;
        int TotalNum;
        int WNum[5];
        warrior * HQWarriors;
    public:
        ~headquarter();
        void InitHQ(char *hn, int tolstren, Node *seqhead, int MaxNum);
        int making(int group);
};

const char warrior::TotalWName[5][7] = {"dragon", "ninja", "iceman", "lion", "wolf"};
void warrior::GetWInfo(int group, int WCode)
{
    WName = TotalWName[WCode];
    InitStrength = GroupInitStren[group][WCode];
}
headquarter::~headquarter()
{
    delete [] HQWarriors;
}
void headquarter::InitHQ(char *hn, int tolstren, Node *seqhead, int MaxNum)
{
    HName = hn;
    TotalStrength = tolstren;
    SeqNode = seqhead;
    TotalNum = 0;
    for (int j = 0; j < 5; j++)
    {
        WNum[j] = 0;
    }
    HQWarriors = new warrior[MaxNum];
}
int headquarter::making(int group)
{
    if (TotalStrength < MinInitStren[group])
    {
        cout << HName << " headquarter stops making warriors" << endl;
        return 0;
    }
    else
    {
        int WCode;
        for (int k = 0; k < 5; k++)
        {
            if (GroupInitStren[group][SeqNode->num] <= TotalStrength)
            {
                WCode = SeqNode->num;
                HQWarriors[TotalNum].GetWInfo(group,WCode);
                TotalStrength -= GroupInitStren[group][WCode];
                cout << HName << " " << HQWarriors[TotalNum].WName << " " << TotalNum + 1
                     << " born with strength " << HQWarriors[TotalNum].InitStrength << ","
                     << WNum[WCode] + 1 << " " << HQWarriors[TotalNum].WName << " in " 
                     << HName << " headquarter" << endl;
                TotalNum++;
                WNum[WCode]++;
                SeqNode = SeqNode->next;
                break;
            }
            else
                SeqNode = SeqNode->next;
        }
        return 1;
    }
}

int main()
{
    int group, TotalStrength, time, MaxNum;
    cin >> group;
    GroupInitStren = new int [group][5];
    MinInitStren = new int [group];
    for (int j=0; j<group; j++){MinInitStren[j]=10000;}
    headquarter *red = new headquarter[group];
    headquarter *blue = new headquarter[group];
    for (int i = 0; i < group; i++)
    {
        cin >> TotalStrength;
        for (int j = 0; j < 5; j++)
        {
            cin >> GroupInitStren[i][j];
            if (GroupInitStren[i][j] < MinInitStren[i])
                MinInitStren[i] = GroupInitStren[i][j];
        }
        MaxNum = TotalStrength / MinInitStren[i] + 1;
        red[i].InitHQ((char *)"red", TotalStrength, RedSeqHead, MaxNum);
        blue[i].InitHQ((char *)"blue", TotalStrength, BlueSeqHead, MaxNum);

        time = 0;
        cout << "Case:" << i + 1 << endl;
        int flag_red = 1, flag_blue = 1;
        while (flag_red || flag_blue)
        {
            if (flag_red)
            {
                cout << setfill('0') << setw(3) << time << " ";
                // cout << time / 100 << time / 10 << time / 1 << " ";
                flag_red = red[i].making(i);
            }
            if (flag_blue)
            {
                cout << setfill('0') << setw(3) << time << " ";
                flag_blue = blue[i].making(i);
            }
            time++;
        }
    }
    delete [] GroupInitStren;
    delete [] MinInitStren;
    return 0;
}