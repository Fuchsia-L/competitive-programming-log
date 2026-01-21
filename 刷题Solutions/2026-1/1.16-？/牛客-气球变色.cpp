#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    ll n, m, k;
    string s;
    while (t--)
    {
        cin >> n >> m >> k >> s;
        ll r = 0, y = 0, w = 0, maxn = 0, ans = 1e9;

        for (int l = 0, ri = 0; ri < n; ri++)
        {
            if (s[ri] == 'r')
                r++;
            else if (s[ri] == 'y')
                y++;
            else
                w++;
            maxn = max(r * 2 + y, y * 2 + r) + 2 * min(w, m);
            while ((maxn >= k) && (l <= r))
            {
                ans = min(ans, (long long)(ri - l + 1));
                if (s[l] == 'r')
                    r--;
                else if (s[l] == 'y')
                    y--;
                else
                    w--;
                maxn = max(r * 2 + y, y * 2 + r) + 2 * min(w, m);
                l++;
            }
        }
        if (ans != 1e9)
            cout << ans << "\n";
        else
            cout << "-1\n";
    }
    return 0;
}