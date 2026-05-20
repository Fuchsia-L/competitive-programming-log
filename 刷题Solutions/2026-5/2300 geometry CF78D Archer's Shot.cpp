#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll k;
    cin >> k;
    k *= 2;
    ll max_edge;
    max_edge = (sqrt(1.000 * (k * k - 1) / 3) + 1) / 2;

    while (((max_edge + 1) * 2 - 1) * ((max_edge + 1) * 2 - 1) * 3 + 1 <= k * k)
    {
        max_edge++;
    }
    while ((max_edge * 2 - 1) * (max_edge * 2 - 1) * 3 + 1 > k * k)
    {
        max_edge--;
    }
    ll initial_max_edge = max_edge; // ← 新增
    ll ans_6 = (1 + max_edge) * max_edge / 2 - max_edge, cnt_ok = 1;
    ll x = 1, y = 2 * max_edge - 1;
    while ((cnt_ok <= max_edge / 2 + max_edge % 2) || (cnt_ok == max_edge))
    {
        ll y2 = y + 1, x2 = x + 3;
        while (x2 * x2 + 3 * y2 * y2 <= k * k)
        {
            ll ascended = max_edge - initial_max_edge; // ← 新增
            max_edge++;
            y = y2;
            x = x2;
            ans_6 += max_edge - 2 * (cnt_ok + ascended); // ← 改这里
            y2 += 1, x2 += 3;
        }
        x += 3;
        y -= 1;
        cnt_ok++;
    }
    ans_6 *= 6;
    ans_6++;
    cout << ans_6 << "\n";
    return 0;
}