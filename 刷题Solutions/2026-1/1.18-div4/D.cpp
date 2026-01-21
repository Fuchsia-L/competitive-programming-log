#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[200009], ans[200009], crash[200005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, cri = 0;
    cin >> t;
    while (t--)
    {
        int n, m, bi;
        ll h, ci;
        cin >> n >> m >> h;
        memset(ans, 0, sizeof(ans));
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= m; i++)
        {
            cin >> bi >> ci;
            if (crash[bi] < cri)
            {
                crash[bi] = cri;
                ans[bi] = 0;
            }
            ans[bi] += ci;
            if (ans[bi] + a[bi] > h)
            {
                crash[bi]++;
                cri = crash[bi];
                ans[bi] = 0;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (crash[i] < cri)
                ans[i] = 0;
            cout << a[i] + ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}