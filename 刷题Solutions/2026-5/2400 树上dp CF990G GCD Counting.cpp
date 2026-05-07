#include <bits/stdc++.h>
using namespace std;
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> value(n + 1, 0), cnt(n + 1, 0);
    vector<vector<int>> road(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> value[i];
    }
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        road[x].push_back(y);
        road[y].push_back(x);
        cnt[x]++;
        cnt[y]++;
    }

    queue<int> q;
    map<int, long long> m;
    vector<map<int, long long>> father_map(n + 1);
    vector<bool> used(n + 1, false);
    used[0] = true;
    bool f = 0;
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] == 1)
        {
            if (!f)
            {
                f = 1;
                continue;
            }
            q.push(i);
            used[i] = true;
        }
    }
    while (!q.empty())
    {
        int now = q.front();
        // cout << "\n\nnow is :" << now << "\n"; ///////////////////////////
        father_map[now][value[now]]++;
        q.pop();
        for (auto fnow : father_map[now])
        {
            // cout << "[" << fnow.first << "] += " << fnow.second << "\n";
            m[fnow.first] += fnow.second;
        }
        for (int next : road[now])
        {
            if (!used[next])
            {
                for (auto chi : father_map[now])
                {
                    for (auto fa : father_map[next])
                    {
                        int addm = gcd(chi.first, fa.first);
                        m[addm] += chi.second * fa.second;
                        // cout << "*[" << addm << "] += " << chi.second * fa.second << "\n";
                    }
                }
                for (auto chi : father_map[now])
                {
                    father_map[next][gcd(value[next], chi.first)] += chi.second;
                }
            }
            cnt[next]--;
            if (!used[next] && cnt[next] <= 1)
            {
                q.push(next);
                used[next] = true;
            }
        }
        father_map[now].clear();
    }
    if (n == 1)
    {
        m[value[1]]++;
    }
    for (auto ans : m)
    {
        cout << ans.first << " " << ans.second << "\n";
    }
    system("pause");
    return 0;
}