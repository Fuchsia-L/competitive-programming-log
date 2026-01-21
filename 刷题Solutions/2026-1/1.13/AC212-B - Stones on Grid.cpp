#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, to;
    int f = 0;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> d(n + 1);
    vector<ll> cost;
    cost.resize(n + 1, -1);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for (int i = 1; i <= m; i++)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        d[u].push_back({c, v});
        if (i == 1)
        {
            pq.push({c, v});
            d[u].pop_back();
            to = u;
            if (u == v)
            {
                f = 1;
            }
        }
    }
    if (f)
    {

        cout << pq.top().first << "\n";
        return 0;
    }
    while (!pq.empty())
    {
        auto now = pq.top();
        pq.pop();
        if (now.second == to)
        {
            cout << cost[to] << '\n';
            return 0;
        }
        if (cost[now.second] != -1 && cost[now.second] < now.first)
            continue;
        for (auto next : d[now.second])
        {
            if (cost[next.second] == -1 || cost[next.second] > now.first + next.first)
            {
                pq.push({now.first + next.first, next.second});
                cost[next.second] = now.first + next.first;
            }
        }
    }
    cout << -1 << "\n";
    return 0;
}