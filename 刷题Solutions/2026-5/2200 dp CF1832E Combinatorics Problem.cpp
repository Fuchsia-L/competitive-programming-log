#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = 998244353;
int main()
{
    ll n, a, xa, ya, m, k;
    ll c = 0, b = 0, fk = 0;
    ll sum = 0;
    cin >> n >> a >> xa >> ya >> m >> k;
    vector<ll> ans(n + 1, 0), f(7, 0);
    ans[1] = a;
    for (int i = 2; i <= n; i++)
    {
        ans[i] = (ans[i - 1] * xa % m + ya) % m;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = k; j >= 1; j--)
        {
            f[j] = (f[j] + f[j - 1]) % MOD;
            if (j == 1)
                f[j] += ans[i];
        }
        f[0] += ans[i];
        f[0] %= MOD;
        f[1] %= MOD;
        sum = sum xor (f[k] * i);
    }
    cout << sum << "\n";
    // system("pause");
    return 0;
}