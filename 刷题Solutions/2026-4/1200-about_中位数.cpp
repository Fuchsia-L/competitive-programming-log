#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n, s;
    cin >> n >> s;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin() + 1, a.end());
    ll ans = 0;
    for (int i = 1; i <= (n + 1) / 2; i++)
    {
        if (a[i] >= s)
        {
            ans += a[i] - s;
        }
    }

    for (int i = (n + 1) / 2; i <= n; i++)
    {
        if (a[i] <= s)
        {
            ans += s - a[i];
        }
    }
    cout << ans << "\n";
    return 0;
}