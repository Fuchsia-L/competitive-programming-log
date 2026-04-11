#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n + 1);
    vector<bool> path(n + 1);
    int a, b;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
        path[i] = false;
    }
    int f = 1;
    for (int i = 1; i <= n; i++)
    {
        if (path[i])
        {
            continue;
        }
        path[i] = true;
    }

    if (n == f)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}