#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, x1, x2, k, ans = 0, dist = 0;
        cin >> n >> x1 >> x2 >> k;
        dist = min(abs(x1 - x2), n - abs(x1 - x2));

        ans = k + dist;
        if (n == 2 || n == 3)
            ans = 1;
        cout << ans << "\n\n";
    }
    system("pause");
    return 0;
}
