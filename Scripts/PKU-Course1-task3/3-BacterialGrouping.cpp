/*
【细菌实验分组】
来源: POJ
注意：总时间限制: 1000ms 内存限制: 65536kB
描述：有一种细菌分为A、B两个亚种，它们的外在特征几乎完全相同，
      仅仅在繁殖能力上有显著差别，A亚种繁殖能力非常强，B亚种的繁殖能力很弱。
      在一次为时一个小时的细菌繁殖实验中，实验员由于疏忽把细菌培养皿搞乱了，
      请你编写一个程序，根据实验结果，把两个亚种的培养皿重新分成两组。
      细菌繁殖能力（繁殖率）的量化标准为一个小时内细菌数量增长的比例（繁殖率 = 一小时后细菌数量 / 原本细菌数量）。
      两个亚种繁殖能力差异很大，
      这意味着对于任意两个同种细菌培养皿的繁殖率的测量值之间的差异要小于任意两个异种细菌培养皿繁殖率的测量值之间的差异。
输入：输入有多行，第一行为整数n（n≤100），表示有n个培养皿。
      其余n行，每行有三个整数，分别代表培养皿编号，试验前细菌数量，试验后细菌数量。假设试验没有误差。
输出：输出有多行：
      第一行输出A亚种培养皿的数量，其后每行输出A亚种培养皿的编号，按繁殖率升序排列。
      然后一行输出B亚种培养皿的数量，其后每行输出B亚种培养皿的编号，也按繁殖率升序排列。
提示：亚种内部，细菌繁殖能力差异远远小于亚种之间细菌繁殖能力的差异。
      也就是说，亚种间任何两组细菌的繁殖率之差都比亚种内部两组细菌的繁殖率之差大。
*/

#include <iostream>

using namespace std;
//BacterialGrouping
int main()
{
    int n; // n为细菌的数量
    int id[100]; // id记录细菌的编号
    double rate[100]; // rate记录细菌的繁殖率
    // 第i个细菌对应id[i]和rate[i]

    cin >> n;
    for (int i = 0; i < n; i++) {
        int initial, final;
        cin >> id[i] >> initial >> final;
        rate[i] = (double)final / initial;
    }

    // 对整个细菌排序（冒泡排序）
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (rate[j + 1] > rate[j]) {
            int tmpId = id[j];
            id[j] = id[j + 1];
            id[j + 1] = tmpId;
            double tmpRate = rate[j];
            rate[j] = rate[j + 1];
            rate[j + 1] = tmpRate;
            }
        }
    }

    double maxDiff = 0; // 记录最大的差
    int maxDiffIndex = 0; // 和最大差的下标
    for (int i = 0; i < n - 1; i++) {
        double diff = rate[i] - rate[i + 1];
        if (maxDiff < diff) {
            maxDiff = diff;
            maxDiffIndex = i;
        }
    }

    //输出繁殖率较大的那组细菌
    cout << maxDiffIndex + 1 << endl;
    for (int i = maxDiffIndex; i >= 0; i--) {
        cout << id[i] << endl;
    }
    //输出繁殖率较小的那组细菌
    cout << n - maxDiffIndex - 1 << endl;
    for (int i = n - 1; i >= maxDiffIndex + 1; i--) {
        cout << id[i] << endl;
    }

    return 0;
}
