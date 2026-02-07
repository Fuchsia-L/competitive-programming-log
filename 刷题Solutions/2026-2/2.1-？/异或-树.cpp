#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<int> tree(n + 1, INT_MAX);
    vector<vector<pair<int, int>>> path(n + 1);
    for (int i = 1; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        path[x].push_back({y, z});
        path[y].push_back({x, z});
    }
    queue<int> q;
    q.push(1);
    tree[1] = 0;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (auto next : path[now])
        {
            int val = next.second ^ tree[now];
            int to = next.first;
            if (tree[to] == INT_MAX)
            {
                tree[to] = val;
                q.push(to);
            }
        }
    }
    int m;
    cin >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        cout << (tree[x] ^ tree[y]) << "\n";
    }
    return 0;
}