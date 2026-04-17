// CF 919D Substring
// https://codeforces.com/problemset/problem/919/D
//
// 有向图 n 点 m 边，每个点有一个小写字母。
// 求任意一条路径上出现次数最多的同一字母的最大出现次数。
// 若图中有环（路径可无限长）→ 输出 -1。
//
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    string s;
    cin >> n >> m >> s;
    s = " " + s;
    vector<vector<int>> node(n + 1);
    vector<vector<int>> ans(n + 1);
    vector<int> cnt(n + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        node[x].push_back(y);
        cnt[y]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 30; j++)
        {
            ans[i].push_back(0);
        }
        if (cnt[i] == 0)
        {
            q.push(i);
            ans[i][s[i] - 'a']++;
        }
    }
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int next : node[now])
        {
            for (int i = 0; i <= 28; i++)
            {
                ans[next][i] = max(ans[next][i], ans[now][i] + ((i == s[next] - 'a') ? 1 : 0));
            }
            cnt[next]--;
            if (cnt[next] == 0)
            {
                q.push(next);
            }
        }
    }
    int maxx = 0, f = 0;
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] > 0)
            f = 1;
        for (int j = 0; j <= 28; j++)
        {
            maxx = max(maxx, ans[i][j]);
        }
    }
    if (f)
        maxx = -1;
    cout << maxx;
    // system("pause");
    return 0;
}
