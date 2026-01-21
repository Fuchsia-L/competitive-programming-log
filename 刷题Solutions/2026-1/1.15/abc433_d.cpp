#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m, a[int(2 * 1e5 + 9)], ans = 0;
vector<ll> book[14];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        int j = 0;
        for (ll k = a[i]; j <= 11; k = (k % m) * (10 % m), j++)
        {
            ll wdnmd = k % m;
            book[j].push_back(wdnmd);
        }
    }
    for (int i = 0; i <= 11; i++)
        sort(book[i].begin(), book[i].end());
    for (ll i = 1; i <= n; i++)
    {
        ll t = a[i], l = 0;
        while (t)
        {
            t /= 10;
            l++;
        }
        ll tmd = m - a[i] % m;
        if (tmd == m)
            tmd = 0;
        auto r = equal_range(book[l].begin(), book[l].end(), tmd);
        ans += (r.second - r.first);
    }
    cout << ans << "\n";
    return 0;
}