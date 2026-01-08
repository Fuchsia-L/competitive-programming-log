#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
ll n, m;
vector<ll> t1, t2;
void add(vector<ll> &t, int index, ll v)
{
    for (; index <= n; index += index & -index)
        t[index] += v;
}
ll sum(vector<ll> &t, int index)
{
    ll res = 0;
    for (; index >= 1; index -= index & -index)
        res += t[index];
    return res;
}
int main()
{
    cin >> n >> m;
    t1.resize(n + 2);
    t2.resize(n + 2);
    ll x1 = 0, x2;
    for (int i = 1; i <= n; i++)
    {
        cin >> x2;
        add(t1, i, x2 - x1);
        add(t2, i, (x2 - x1) * i);
        x1 = x2;
    }
    for (int i = 1; i <= m; i++)
    {
        int f, l, r;
        cin >> f;
        if (f == 1) // add
        {
            ll v;
            cin >> l >> r >> v;
            add(t1, l, v);
            add(t1, r + 1, -v);
            add(t2, l, l * v);
            add(t2, r + 1, -(r + 1) * v);
        }
        else
        { // sum
            cin >> l >> r;
            l -= 1;
            ll xl = sum(t1, l) * (l + 1) - sum(t2, l);
            ll xr = sum(t1, r) * (r + 1) - sum(t2, r);
            cout << xr - xl << "\n";
        }
    }
    return 0;
}