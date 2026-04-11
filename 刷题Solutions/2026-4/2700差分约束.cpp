#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> road(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v, b;
        cin >> u >> v >> b;
        road[u].push_back({v, 1});
        if (b == 1)
        {
            road[v].push_back({u, -1});
        }
        else
        {
            road[v].push_back({u, 1});
        }
    }
    return 0;
}