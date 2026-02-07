#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[200009] = {0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q, xi;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> xi;
        a[i] = a[i - 1] + xi;
    }
    for (int i = 1; i <= q; i++)
    {
        int z;
        cin >> z;
        if (z == 1)
        {
            int x;
            cin >> x;
            int ax = a[x] - a[x - 1], bx = a[x + 1] - a[x];
            a[x] = bx + a[x - 1];
            a[x + 1] = a[x] + ax;
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << a[r] - a[l - 1] << "\n";
        }
    }
    return 0;
}