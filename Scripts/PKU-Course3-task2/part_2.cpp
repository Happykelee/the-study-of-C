#include <iostream>
using namespace std;
class Sample{
public:
    int v;
    Sample(int n):v(n) { }
// 在此处补充你的代码
    Sample(const Sample & a):v(a.v*2) { } // 考查复制构造函数（含引用/常引用）
};
int main() {
    Sample a(5);
    Sample b = a;
    cout << b.v;
    return 0;
}