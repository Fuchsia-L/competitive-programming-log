#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e5 + 1;
int n, k, a[maxn], p[maxn], pb, ps;
int maxb, maxs;

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        maxb = 0, maxs = 0;
        cin >> n >> k >> pb >> ps;
        for (int i = 1; i <= n; i++)
        {
            cin >> p[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        long long b = 0, s = 0, sb = 0, ss = 0;
        for (int i = 1; i <= min(k, n); i++)
        {
            sb += a[pb];
            ss += a[ps];
            b = max(b, sb + (long long)(k - i) * a[pb]);
            s = max(s, ss + (long long)(k - i) * a[ps]);
            pb = p[pb];
            ps = p[ps];
        }
        if (b == s)
        {
            cout << "Draw\n";
        }
        else if (b > s)
        {
            cout << "Bodya\n";
        }
        else
            cout << "Sasha\n";
    }
    // system("pause");
    return 0;
}