#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, wi;
    ll w[125005] = {0}, item[505][2], ans = 0, hi, bi, wsum = 0, l = 0;
    ll k = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> wi >> hi >> bi;
        item[i][0] = wi;
        wsum += wi;
        item[i][1] = hi - bi;
        l += bi;
    }
    for (int i = 1; i <= n; i++)
    {
        for (ll j = wsum / 2; j >= item[i][0]; j--)
        {
            w[j] = max(w[j], w[j - item[i][0]] + item[i][1]);
            ans = max(ans, w[j]);
        }
    }
    cout << ans + l;
    return 0;
}