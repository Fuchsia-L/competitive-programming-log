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
        string s;
        cin >> n >> s;
        s = " " + s;
        ll ans = 0;
        map<ll, ll> p;
        vector<ll> pre(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            pre[i] = pre[i - 1] + s[i] - '1';
            ans += p[pre[i]];
            p[pre[i]]++;
        }
        ans += p[0];
        cout << ans << "\n\n";
    }
    return 0;
}