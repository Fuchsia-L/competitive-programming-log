#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int m, n;
    cin >> n >> m;
    ll x1, xitv = 0, a1;
    cin >> x1;
    a1 = x1;
    for (int i = 2; i <= n; i++)
    {
        ll x2;
        cin >> x2;
        xitv = __gcd(xitv, x2 - x1);
        x1 = x2;
        // cout << xitv << " ";
    }
    int f = 1;
    for (int i = 1; i <= m && f; i++)
    {
        ll p;
        cin >> p;
        if (xitv >= p && xitv % p == 0)
        {
            cout << "YES\n"
                 << a1 << " " << i << "\n";
            f = 0;
        }
    }
    if (f)
    {
        cout << "NO\n";
    }
    return 0;
}