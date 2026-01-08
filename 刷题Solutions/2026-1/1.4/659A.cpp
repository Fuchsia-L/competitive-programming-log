#include <iostream>
using namespace std;
int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    b %= n;
    a += b;
    if (a <= 0)
        a += n;
    if (a > n)
        a -= n;
    cout << a;
    return 0;
}