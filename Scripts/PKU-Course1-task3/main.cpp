#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a,sep[3];
    cin >> a;
    for (int i=0; i<3; i++){
        sep[i] = a%10;
        a = a/10;
    }
    for (int i=2; i>=0; i--) cout << sep[i] << endl;
    return 0;
}
