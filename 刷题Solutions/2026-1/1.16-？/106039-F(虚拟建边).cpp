#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<ll, int>>> rode(n + k + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        rode[v].push_back({c, u});
        rode[u].push_back({c, v});
    }
    for (int i = 1; i <= n; i++)
    {
        int t, u;
        ll c;
        cin >> t;
        while (t--)
        {
            cin >> u >> c;
            rode[i].push_back({c, n + u});
            rode[n + u].push_back({0, i});
        }
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    vector<ll> book(n + k + 1, LONG_LONG_MAX);
    book[1] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto now = pq.top();
        pq.pop();
        if (book[now.second] < now.first)
            continue;
        for (auto next : rode[now.second])
        {
            ll cn = next.first + now.first, to = next.second;
            if (book[to] > cn)
            {
                book[to] = cn;
                pq.push({cn, to});
                // cout << "更新，从" << now.second << "到" << to << "，总花费" << cn << "\n";
            }
        }
    }
    cout << book[n] << "\n";
    return 0;
}
/*
3 2 1
1 2 5
2 3 3
1
1 4
0
1
1 3



6 7 2
1 2 1
2 3 3
1 3 5
2 4 2
3 5 2
5 6 7
4 6 5
1
1 7
2
1 5
2 1
0
0
0
1
1 100

*/