#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, p = 0;
    cin >> n;
    vector<int> a, b, v(n + 1);
    vector<vector<int>> map(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            map[i].push_back(INT_MAX);
    }
    for (int i = 0; i <= n; i++)
        map[0].push_back(0);
    a.push_back(0);
    b.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        if (v[i] == 1)
        {
            p++;
            a.push_back(i);
        }
        else
        {
            b.push_back(i);
        }
    }
    map[1][1] = abs(a[1] - b[1]);
    for (int i = 1; i <= p; i++)
    {
        for (int j = max(i, 2); j <= n - p; j++)
        {
            map[i][j] = min(map[i][j - 1], map[i - 1][j - 1] + abs(a[i] - b[j]));
        }
    }
    cout << map[p][n - p];
    // system("pause");
    return 0;
}