#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct monster
{
    ll x, y, ra, id;
    int ff;
    bool operator<(const monster &other) const
    {
        if (x == 0)
    }
};
int book[200009] = {0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<monster> m(n + 1), m2(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> m[i].x >> m[i].y;
        m[i].id = i;
        m2[i] = m[i];
    }
    for (int i = 1; i <= q; i++)
    {
        int a, b, ans = 0;
        cin >> a >> b;
        if (m[a].ra > m[b].ra)
            ans = 2;
    }
    return 0;
}