#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll ans[61] = {1};
    for (int i = 1; i <= 60; i++)
        ans[i] = ans[i - 1] * 2;
    int t;
    cin >> t;
    while (t--)
    {
        ll num_0 = 0, num_1 = 0, ai, n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> ai;
            if (!ai)
                num_0++;
            else if (ai == 1)
                num_1++;
        }
        cout << ans[num_0] * num_1 << "\n";
    }
    system("pause");
    return 0;
}