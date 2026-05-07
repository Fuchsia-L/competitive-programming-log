#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> road(n + 1);
    vector<bool> used(n + 1, false);
    vector<int> cnt(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        road[u].push_back(v);
        road[v].push_back(u);
        cnt[u]++;
        cnt[v]++;
    }

    int left = n;
    queue<pair<int, int>> q; // level , value
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] == 1)
        {
            used[i] = true;
            q.push({1, i});
            left--;
            if (left <= k)
            {
                cout << 1 << "\n";
                // system("pause");
                return 0;
            }
        }
    }
    while (!q.empty())
    {
        auto now = q.front();
        q.pop();
        for (int next_idx : road[now.second])
        {
            if (!used[next_idx])
            {
                cnt[next_idx]--;
                if (cnt[next_idx] == 1)
                {
                    used[next_idx] = true;
                    q.push({now.first + 1, next_idx});
                    left--;
                    if (left <= k)
                    {
                        cout << now.first + 1 << "\n";
                        // system("pause");
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}
