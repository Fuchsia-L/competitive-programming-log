#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, numj = 0;
    cin >> n;
    vector<vector<int>> tree(n + 3);
    vector<bool> used(n + 1, false);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    queue<pair<int, int>> q;
    q.push({1, 1});
    used[1] = true;

    while (!q.empty())
    {
        auto now = q.front();
        q.pop();
        if (now.second % 2 == 1)
        {
            numj++;
        }
        for (int next : tree[now.first])
        {
            if (!used[next])
            {
                used[next] = true;
                q.push({next, now.second + 1});
            }
        }
    }
    // cout << "---\n";
    long long sum = 0, ans = 0;
    sum = n - numj;
    ans = numj * sum - (n - 1);
    // cout << "奇数点：" << numj << "  总链接：" << cntj << "\n";
    cout << ans << "\n";
    // system("pause");
    return 0;
}