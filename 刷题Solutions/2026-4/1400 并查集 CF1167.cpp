#include <bits/stdc++.h>
int fa[500002], cnt[500008];
using namespace std;
int find_fa(int x)
{
    //   cout << "---" << x << " " << fa[x] << "\n";
    if (fa[x] == x)
    {
        return x;
    }
    return fa[x] = find_fa(fa[x]);
}
void connect(int x, int y)
{
    x = find_fa(x);
    y = find_fa(y);
    if (x == y)
        return;
    if (cnt[x] < cnt[y])
    {
        swap(x, y);
    }
    fa[y] = x;
    cnt[x] += cnt[y];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        cnt[i] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        int x, a, b;
        cin >> x;
        for (int j = 1; j <= x; j++)
        {
            cin >> a;
            if (j != 1)
            {
                connect(a, b);
            }
            b = a;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << cnt[find_fa(i)] << " ";
    // system("pause");
    return 0;
}