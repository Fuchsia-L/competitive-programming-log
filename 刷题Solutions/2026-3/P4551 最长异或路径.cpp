#include <bits/stdc++.h>
using namespace std;
int ch[33 * (int)(1e5)][2] = {0};
int main()
{
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> map(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        map[u].push_back({v, w});
        map[v].push_back({u, w});
    }
    vector<int> xorr(n + 1), book(n + 1, 0);
    book[1] = -1;
    queue<pair<int, int>> q;
    q.push({1, 0});
    while (!q.empty())
    {
        auto now = q.front();
        q.pop();
        for (auto next : map[now.first])
        {
            if (book[next.first] == 0)
            {
                q.push({next.first, next.second ^ now.second});
                xorr[next.first] = next.second ^ now.second;
                book[next.first] = 1;
            }
        }
    }
    //
    // for (int i = 0; i <= n; i++)
    // {
    //     cout << "i -> " << xorr[i] << "\n";
    // }
    //
    int u = 0, numu = 0;
    for (int i = 1; i <= n; i++)
    {
        u = 0;
        for (int j = 30; j >= 0; j--)
        {
            int t = (xorr[i] >> j) & 1;
            if (ch[u][t] == 0)
            {
                numu++;
                ch[u][t] = numu;
            }
            u = ch[u][t];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        // cout << "\n\n\nlook at num i=" << i << " --------\n"; //////
        int u = 0, maxx = 0;
        for (int j = 30; j >= 0; j--)
        {
            int t = (xorr[i] >> j) & 1;
            maxx *= 2;
            if (ch[u][!t] != 0)
            {
                // cout << "j= " << j << " ,ok!\n";
                u = ch[u][!t];
                maxx++;
            }
            else
            {
                // cout << "j= " << j << " ,-\n";
                u = ch[u][t];
            }
            // cout << "now maxx is " << maxx << "\n";
        }
        ans = max(ans, maxx);
    }
    cout << ans;
    return 0;
}