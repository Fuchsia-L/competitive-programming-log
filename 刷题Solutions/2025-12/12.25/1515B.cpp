#include <iostream>
#include <cmath>
using namespace std;
bool isSqrt(long long k)
{
    long long r = llround(sqrt(k));
    if (r * r == k)
        return true;
    return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x;
        cin >> x;
        if ((x % 2 == 0 && isSqrt(x / 2)) || (x % 4 == 0 && isSqrt(x / 4)))
        {
            cout << "Yes\n";
        }
        else
            cout << "No\n";
    }
    return 0;
}
/*
    while (x > 2)
            x /= 2;
        if (x == 2)
        {
            cout << "Yes , cas1\n";
            continue;
        }
*/