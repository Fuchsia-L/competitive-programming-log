#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int sum = n;
        k = min(k, n);
        vector<vector<int>> node(n + 1);
        queue<int> q;
        vector<int> cnt(n + 1, 0);
        for (int i = 1; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            node[x].push_back(y);
            node[y].push_back(x);
        }
        for (int i = 1; i <= n; i++)
        {
            cnt[i] = node[i].size();
            if (cnt[i] == 1 || cnt[i] == 0)
            {
                q.push(i);
            }
        }
        // cout << "ok";
        while (k--)
        {
            queue<int> q2;
            while (!q.empty())
            {
                int now = q.front();
                q.pop();
                sum--;
                for (int next : node[now])
                {
                    cnt[next]--;
                    if (cnt[next] == 1)
                    {
                        q2.push(next);
                    }
                }
            }
            q = q2;
        }
        cout << sum << "\n";
    }
    system("pause");
    return 0;
}
