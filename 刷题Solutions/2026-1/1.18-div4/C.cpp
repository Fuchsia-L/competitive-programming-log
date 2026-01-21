#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, a[3003];
    cin >> t;
    while (t--)
    {
        int n, maxn = 1, l = 1;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        for (int i = 2; i <= n; i++)
        {
            if (a[i] == a[i - 1])
                continue;
            if (a[i] == a[i - 1] + 1)
            {
                l++;
            }
            else
            {
                l = 1;
            }
            maxn = max(maxn, l);
        }
        cout << maxn << "\n";
    }
    return 0;
}