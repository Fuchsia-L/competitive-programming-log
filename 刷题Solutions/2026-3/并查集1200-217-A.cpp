#include <bits/stdc++.h>
using namespace std;
int fa[1009];
int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}
void con(int x, int y)
{
    fa[find(x)] = fa[find(y)];
}
int main()
{
    int n, d[109][2];
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        cin >> d[i][0] >> d[i][1];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (d[i][0] == d[j][0] || d[i][1] == d[j][1])
            {
                con(i, j);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (fa[i] == i)
            ans++;
    }
    cout << ans - 1;
    // system("pause");
    return 0;
}