// #include <iostream>
// #include <cstring>
// #include <cstdlib>
// using namespace std;
// class Complex {
// private:
//     double r,i;
// public:
//     void Print() {
//         cout << r << "+" << i << "i" << endl;
//     }
// 在此处补充你的代码
void operator=(const char *s)
{
    r = atof(s);
    i = atof(s + 2);
}
// };
// int main() {
//     Complex a;
//     a = "3+4i"; a.Print();
//     a = "5+6i"; a.Print();
//     return 0;
// }