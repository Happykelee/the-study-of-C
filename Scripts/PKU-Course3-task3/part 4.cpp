/*
【描述】
给出两个正整数以及四则运算操作符（+ - * /），求运算结果。

输入
第一行：正整数a，长度不超过100
第二行：四则运算符o，o是“+”，“-”，“*”，“/”中的某一个
第三行：正整数b，长度不超过100
保证输入不含多余的空格或其它字符

输出
一行：表达式“a o b”的值。
补充说明：
1. 减法结果有可能为负数
2. 除法结果向下取整
3. 输出符合日常书写习惯，不能有多余的0、空格或其它字符
*/
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class LongNum
{
    private:
        int size;
        int num[300];
    public:
        LongNum();
        friend istream & operator >> (istream & is, LongNum & lnum);
        void operator + (const LongNum &);
        void operator - (const LongNum &);
        void operator * (const LongNum &);
        void operator / (const LongNum &);
};

LongNum::LongNum()
{
    size = 0;
    memset(num, 0, sizeof(num));
}
istream & operator >> (istream & is, LongNum & lnum)
{
    string s;
    is >> s;
    lnum.size = s.length();
    for(int i=0; i< lnum.size; i++)
        lnum.num[i] = atoi(s.substr(lnum.size-1-i,1).c_str());
    return is;
}
void LongNum::operator + (const LongNum & lnum2)
{
    int maxlen, SumSize;
    int *SumNum;
    if (lnum2.size > size)
        maxlen = lnum2.size;
    else
        maxlen = size;
    SumNum = new int[maxlen+1];
    memset(SumNum, 0, sizeof(SumNum) * (maxlen + 1));
    for (int i=0; i<maxlen; i++)
    {
        SumNum[i] += num[i]+lnum2.num[i];
        if (SumNum[i] >= 10)
        {
            SumNum[i] -= 10;
            SumNum[i+1] += 1;
        }
    }
    
    // 输出
    SumSize = SumNum[maxlen]==0?(maxlen):(maxlen+1);
    bool start_flag = true;
    for (int i = 0; i < SumSize; i++)
    {
        if (i == SumSize - 1 && SumNum[SumSize - 1 - i] == 0 && start_flag)
            // 最后一个数即使是0也要输出
            cout << SumNum[SumSize - 1 - i];
        if (SumNum[SumSize - 1 - i] == 0 && start_flag)
            continue;
        else
        {
            cout << SumNum[SumSize - 1 - i];
            start_flag = false;
        }
    }
    cout << endl;
}
void LongNum::operator - (const LongNum & lnum2)
{
    int pos_flag = 1, SubSize;
    int *SubNum;

    // 先判断大小
    if (size > lnum2.size)
        pos_flag = 1;
    else if (size == lnum2.size)
    {
        for (int i=0; i < size; i++)
        {
            if (num[size-1-i] == lnum2.num[size-1-i])
                continue;
            else if (num[size-1-i] > lnum2.num[size-1-i])
            {
                pos_flag = 1;
                break;
            }
            else if (num[size-1-i] < lnum2.num[size-1-i])
            {
                pos_flag = 0;
                break;
            }
        }
    }
    else
        pos_flag = 0;

    // 正式运算
    if(pos_flag)
    {
        SubSize = size;
        SubNum = new int[SubSize];
        memset(SubNum, 0, sizeof(SubNum) * SubSize);
        for (int i = 0; i < SubSize; i++)
        {
            SubNum[i] += num[i];
            if (SubNum[i] < lnum2.num[i])
            {
                SubNum[i] += 10 - lnum2.num[i];
                SubNum[i + 1] -= 1;
            }
            else
                SubNum[i] -= lnum2.num[i]; 
        }
    }
    else
    {
        SubSize = lnum2.size;
        SubNum = new int[SubSize];
        memset(SubNum, 0, sizeof(SubNum) * SubSize);
        for (int i = 0; i < SubSize; i++)
        {
            SubNum[i] += lnum2.num[i];
            if (SubNum[i] < num[i])
            {
                SubNum[i] += 10 - num[i];
                SubNum[i + 1] -= 1;
            }
            else
                SubNum[i] -= num[i];
        }
    }

    // 结果输出
    if(!pos_flag) cout << '-';
    bool start_flag = true;
    for (int i = 0; i < SubSize; i++)
    {
        if (i == SubSize - 1 && SubNum[SubSize-1-i] == 0  && start_flag) 
        // 最后一个数即使是0也要输出
            cout << SubNum[SubSize - 1 - i];
        if (SubNum[SubSize-1-i] == 0 && start_flag)
            continue;
        else
        {
            cout << SubNum[SubSize - 1 - i];
            start_flag = false;
        }
    }
    cout << endl;
}
void LongNum::operator * (const LongNum & lnum2)
{
    int MulSize;
    int *MulNum;
    MulSize = size + lnum2.size;
    MulNum = new int[MulSize];
    memset(MulNum, 0, sizeof(MulNum) * MulSize);
    for (int i=0; i<size; i++)
    {
        for (int j=0; j<lnum2.size; j++)
        {
            MulNum[i+j] += num[i] * lnum2.num[j];
            if (MulNum[i+j] >= 10)
            {
                MulNum[i + j + 1] += MulNum[i + j] / 10;
                MulNum[i+j] %= 10;
            }
        }
    }

    // 输出
    bool start_flag = true;
    for (int i = 0; i < MulSize; i++)
    {
        if (i == MulSize - 1 && MulNum[MulSize - 1 - i] == 0 && start_flag)
            // 最后一个数即使是0也要输出
            cout << MulNum[MulSize - 1 - i];
        if (MulNum[MulSize - 1 - i] == 0 && start_flag)
            continue;
        else
        {
            cout << MulNum[MulSize - 1 - i];
            start_flag = false;
        }
    }
    cout << endl;
}
void LongNum::operator / (const LongNum & lnum2)
{
    int DivSize,length;
    int * DivNum, * tmp;
    if (size < lnum2.size)
    // 被除数比除数小
        cout << 0 << endl;
    else
    // 被除数不比除数小
    {
        DivSize = size-lnum2.size+1;
        DivNum = new int[DivSize];
        memset(DivNum, 0, sizeof(DivNum) * DivSize);

        // num拷贝一份给tmp，后面被除数用tmp
        tmp = new int[size]; 
        for (int i=0; i<size; i++)
            tmp[i] = num[i];
        
        // 计算过程
        for (int i=0; i<DivSize; i++)
        {
            int tmp_start = size - lnum2.size - i;
            bool tmp_flag = false;
            // 用于计算第i位商的被除数长度
            length = lnum2.size+i;
            // 原始长度
            int j=0;
            for(j=0; j<length; j++)
            {
                if(tmp[size-1-j] != 0) break;
                else continue;
            }
            length -= j;
            // 因为最前面可能是零，所以实际用于减的长度

            // 判断大小以及反复减
            if(length < lnum2.size)
            // 如果暂时的被除部分长度短，说明比较小，商位为0
            {
                DivNum[DivSize-1-i] = 0;
                continue;
            }
            if(length == lnum2.size)
            {
                for (int k = 0; k < length; k++)
                {
                    if (k == length-1 && tmp[tmp_start+length-1-k] == lnum2.num[length-1-k])
                        tmp_flag =true;
                    if (tmp[tmp_start+length-1-k] == lnum2.num[length-1-k])
                        continue;
                    if (tmp[tmp_start+length-1-k] < lnum2.num[length-1-k])
                    // 同样长度，但是暂时的被除部分还是比较小，商位为0
                    {
                        DivNum[DivSize-1-i] = 0;
                        break;
                    }
                    if (tmp[tmp_start+length-1-k] > lnum2.num[length-1-k])
                    {   
                        tmp_flag = true;
                        break;
                    }
                }
            }
            if (length > lnum2.size || tmp_flag)
            {
            // 多数情况要反复减除数，最多九次
                for(int time=1; time < 10; time++)
                {
                    // 减完一次
                    for (int k = 0; k < length; k++)
                        {
                            if (tmp[size-lnum2.size-i+k] < lnum2.num[k])
                            {
                                tmp[size-lnum2.size-i+k] += 10 - lnum2.num[k];
                                tmp[size-lnum2.size-i+k+1] -= 1;
                            }
                            else
                                tmp[size-lnum2.size-i+k] -= lnum2.num[k];
                        }
                    
                    // 每减一次要判断余下的被除数是否比除数小
                    // 第一步获取余下的被减数长度
                    int tmplen = length;
                    for (tmplen; tmplen > 0 ; tmplen--)
                    {
                        if (tmp[tmp_start+tmplen-1] != 0) break;
                        else continue;
                    }
                    // 第二步判断长度
                    bool tmp_bigger_flag = true;
                    if (tmplen > lnum2.size) continue;
                    if (tmplen < lnum2.size)
                    {
                        DivNum[DivSize-1-i] = time;
                        break;
                    }
                    if (tmplen == lnum2.size)
                    {
                        for (int k = 0; k < tmplen; k++)
                        {
                            if (tmp[tmp_start+tmplen-1-k] == lnum2.num[tmplen-1-k])
                                continue;
                            if (tmp[tmp_start+tmplen-1-k] < lnum2.num[tmplen-1-k])
                            {
                                DivNum[DivSize-1-i] = time;
                                tmp_bigger_flag = false;
                                break;
                            }
                            if (tmp[tmp_start+tmplen-1-k] > lnum2.num[tmplen-1-k])
                                break;
                        }
                    }
                    if(tmp_bigger_flag) continue;
                    else break;
                }
            }
        }

        // 输出
        bool start_flag = true;
        for (int i = 0; i < DivSize; i++)
        {
            if (i == DivSize - 1 && DivNum[DivSize - 1 - i] == 0 && start_flag)
                // 最后一个数即使是0也要输出
                cout << DivNum[DivSize - 1 - i];
            if (DivNum[DivSize - 1 - i] == 0 && start_flag)
                continue;
            else
            {
                cout << DivNum[DivSize - 1 - i];
                start_flag = false;
            }
        }
        cout << endl;
    }
}

int main()
{
    LongNum a, b;
    char c;
    cin >> a >> c >> b;
    switch (c)
    {
    case '+':
        a + b;
        break;
    case '-':
        a - b;
        break;
    case '*':
        a * b;
        break;
    case '/':
        a / b;
        break;
    default:
        break;
    }
    return 0;
}