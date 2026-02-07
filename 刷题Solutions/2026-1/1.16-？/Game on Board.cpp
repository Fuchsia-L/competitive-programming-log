#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, ans = 0;
    ll x, maxn = -1, d = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        maxn = max(maxn, x);
        d = __gcd(d, x);
    }
    ans = maxn / d - n;
    if (ans % 3 == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}