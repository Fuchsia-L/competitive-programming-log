#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool solve(int m, int n, int f)
{
    return m * n >= f;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, s;
        cin >> n >> m >> s;
        if (m > n)
            swap(n, m);
        int fenshu = n * m / s;
        if (n * m % s != 0)
            fenshu++;
        int ans;
        if (m * m >= fenshu)
        {
            int l = 1, r = m;
            int mid;
            while (l <= r)
            {
                mid = (l + r) / 2;
                if (solve(mid, mid, fenshu))
                {
                    ans = mid;
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }
            cout << "mid=" << mid << "  ans=" << ans << "  --"; ////
            if (solve(ans, ans - 1, fenshu))
                ans = 2 * ans - 3;
            else
                ans = ans * 2 - 2;
        }
        else
        {
            int l = m, r = n;
            int mid;
            while (l <= r)
            {
                mid = (l + r) / 2;
                if (solve(m, mid, fenshu))
                {
                    ans = mid + m - 2;
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}