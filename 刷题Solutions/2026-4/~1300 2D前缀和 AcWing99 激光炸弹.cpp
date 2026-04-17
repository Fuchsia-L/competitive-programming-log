#include <bits/stdc++.h>
using namespace std;
int v[5009][5009], ans = 0;
int main()
{
    int n = 0, m, r;
    cin >> m >> r;
    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        v[x + 1][y + 1] += w;
        n = max(n, max(x, y));
    }
    n++;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            v[i][j] += v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
        }
    }
    r = min(r, n);
    for (int i = n; i - r >= 0; i--)
    {
        for (int j = n; j - r >= 0; j--)
        {
            ans = max(ans, v[i][j] + v[i - r][j - r] - v[i - r][j] - v[i][j - r]);
        }
    }
    cout << ans;
    return 0;
}