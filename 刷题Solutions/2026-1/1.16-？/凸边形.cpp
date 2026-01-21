#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin() + 1, a.end());
        vector<ll> b(n + 1, 0);
        b[1] = a[1];
        for (int i = 2; i <= n; i++)
        {
            b[i] = a[i] + b[i - 1];
        }
        if (n == 1)
        {
            cout << 0 << "\n";
            continue;
        }
        cout << "0 0 ";
        for (int l = 3; l <= n; l++) //<n?
        {
            ll sum = 0;
            bool f = true;
            for (int h = n; h >= l && f; h--)
            {
                if (a[h] < b[h - 1] - b[h - l])
                {
                    cout << b[h] - b[h - l] << " ";
                    f = false;
                }
            }
            if (f)
                cout << "0 ";
        }
        cout << "\n";
    }
    return 0;
}