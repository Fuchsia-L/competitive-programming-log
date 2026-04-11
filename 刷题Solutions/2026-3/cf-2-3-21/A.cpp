#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        ll c, k, ams = 0;
        cin >> n >> c >> k;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a.begin() + 1, a.end());
        for (int i = 1; i <= n; i++)
        {
            if (a[i] > c)
            {
                break;
            }
            ll add = min(c - a[i], k);
            a[i] += add;
            c += a[i];
            k -= add;
        }
        cout << c << "\n\n";
    }
    return 0;
}