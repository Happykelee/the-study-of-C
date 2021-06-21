/*
【含k个3的数】
来源: POJ
注意：总时间限制: 1000ms 内存限制: 65536kB
描述：输入一串长度不超过500个符号的字符串，输出在串中出现第2多的英语字母(大小写字母认为相同)和次数
      （如果串中有其它符号，则忽略不考虑）。如果有多个字母的次数都是第2多，则按串中字母出现的顺序输出第1个。
      例 ab&dcAab&c9defgb
      这里，a 和 b都出现3次，c和d都出现2次，
      e、f 和 g 各出现1次，其中的符号&和9均忽略不考虑。
      因此，出现第2多的应该是 c 和 d，但是 d 开始出现的位置在 c 的前面，因此，输出为
      D+d:2
      (假定在字符串中，次数第2多的字母总存在)
输入：一个字符串
输出：大写字母+小写字母:个数
*/

#include <iostream>
using namespace std;

struct Letter
{
    int number=0;
    int rank=0;
};

int main()
{
    char string[501];
    cin.getline(string,501);

    Letter LetArray[26];
    int temp,Rank=1;
    for(int i=0;string[i]!='\0';i++)
    {
        string[i] = toupper(string[i]);
        if ((int)string[i] >= 0x41 && (int)string[i] <= 0x5A)
        {
            temp = (int)string[i] - 0x41;
            if((LetArray+temp)->number==0)
            {
                (LetArray + temp)->rank = Rank;
                Rank++;
                (LetArray + temp)->number++;
            }
            else
                (LetArray + temp)->number++;
        }
    }

    Letter MAX[2];
    int MAX_let[2]={0};
    for (int i=0;i<26;i++)
    {
        if(LetArray[i].number > MAX[0].number) //找最大
        {
            MAX[1] = MAX[0]; MAX_let[1] = MAX_let[0];
            MAX[0] = LetArray[i]; MAX_let[0] = i;
        }
        else if (LetArray[i].number > MAX[1].number && LetArray[i].number < MAX[0].number)
        // 比最大小但是比现在的第二大大，更新
        {
            MAX[1] = LetArray[i];
            MAX_let[1] = i;
        }
        else if (LetArray[i].number == MAX[1].number && LetArray[i].rank < MAX[1].rank)
        // 和第二大一样大，但是位置靠前，更新
        {
            MAX[1] = LetArray[i];
            MAX_let[1] = i;
        }
    }
    cout << char(MAX_let[1] + 0x41) << "+" << char(MAX_let[1] + 0x61) << ":" << MAX[1].number;

    return 0;
}
