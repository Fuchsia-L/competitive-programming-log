#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 676767677;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        ll ans = 0;
        ll c = max(x, y) - min(x, y);
        for (int i = 1; i * i <= c; i++)
        {
            if (c % i == 0)
            {
                ans++;
                if (c / i != i)
                    ans++;
            }
        }
        ans = ans % mod;
        if (ans == 0)
            ans++;
        cout << ans << "\n";
        for (int i = 1; i <= x; i++)
            cout << "1 ";
        for (int i = 1; i <= y; i++)
            cout << "-1 ";
        cout << "\n";
    }
    return 0;
}