#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a[4] = {0, 0, 0};
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            a[x]++;
        }
        int ans = a[0] + min(a[1], a[2]);
        int m = min(a[1], a[2]);
        a[1] -= m;
        a[2] -= m;
        ans += a[1] / 3;
        ans += a[2] / 3;
        cout << ans << "\n";
    }
    system("pause");
    return 0;
}
