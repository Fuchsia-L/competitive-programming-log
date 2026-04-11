#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node
{
    ll money, factor;
    bool operator<(const node &o) const
    {
        return money < o.money;
    }
};
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n;
    ll diff, ans = 0;
    cin >> n >> diff;
    vector<node> p(n);
    for (int i = 0; i < n; i++)
    {
        ll m, s;
        cin >> m >> s;
        p[i] = {m, s};
    }
    sort(p.begin(), p.end());
    ll now_ans = 0;
    for (int i = 0, j = 0; j < n; j++)
    {
        now_ans += p[j].factor;
        while (p[j].money - p[i].money >= diff && i <= j)
        {
            now_ans -= p[i].factor;
            i++;
        }
        ans = max(ans, now_ans);
    }
    cout << ans << "\n";
    system("pause");
    return 0;
}